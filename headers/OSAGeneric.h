/**
     \file       OSAGeneric.h

    \brief   AppleScript Generic Component Interfaces.

    \introduced_in  AppleScript 1.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1992-2001 by Apple Computer, Inc., all rights reserved

    \ingroup OpenScriptingArchitecture

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __OSAGENERIC__
#define __OSAGENERIC__

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __APPLEEVENTS__
#include <AppleEvents.h>
#endif

#ifndef __OSA__
#include <OSA.h>
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

  /*    NOTE:   This interface defines a "generic scripting component."
              The Generic Scripting Component allows automatic dispatch to a
              specific scripting component that conforms to the OSA interface.
              This component supports OSA, by calling AppleScript or some other
              scripting component.  Additionally it provides access to the default
              and the user-prefered scripting component.
  */

  enum
  {
    /* Component version this header file describes */
    kGenericComponentVersion = 0x0100
  };

  enum
  {
    kGSSSelectGetDefaultScriptingComponent = 0x1001,
    kGSSSelectSetDefaultScriptingComponent = 0x1002,
    kGSSSelectGetScriptingComponent = 0x1003,
    kGSSSelectGetScriptingComponentFromStored = 0x1004,
    kGSSSelectGenericToRealID = 0x1005,
    kGSSSelectRealToGenericID = 0x1006,
    kGSSSelectOutOfRange = 0x1007
  };

  typedef OSType ScriptingComponentSelector;
  typedef OSAID GenericID;
  /* get and set the default scripting component */
  /**
   *  OSAGetDefaultScriptingComponent()
   *

   *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSAError
  OSAGetDefaultScriptingComponent(ComponentInstance genericScriptingComponent,
                                  ScriptingComponentSelector *scriptingSubType)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x1001, 0x7000, 0xA82A);

  /**
   *  OSASetDefaultScriptingComponent()
   *

   *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSAError
  OSASetDefaultScriptingComponent(ComponentInstance genericScriptingComponent,
                                  ScriptingComponentSelector scriptingSubType)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x1002, 0x7000, 0xA82A);

  /* get a scripting component instance from its subtype code */
  /**
   *  OSAGetScriptingComponent()
   *

   *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSAError
  OSAGetScriptingComponent(ComponentInstance genericScriptingComponent,
                           ScriptingComponentSelector scriptingSubType,
                           ComponentInstance *scriptingInstance)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x1003, 0x7000, 0xA82A);

  /* get a scripting component selector (subType) from a stored script */
  /**
   *  OSAGetScriptingComponentFromStored()
   *

   *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSAError
  OSAGetScriptingComponentFromStored(ComponentInstance genericScriptingComponent,
                                     const AEDesc *scriptData,
                                     ScriptingComponentSelector *scriptingSubType)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x1004, 0x7000, 0xA82A);

  /* get a real component instance and script id from a generic id */
  /**
   *  OSAGenericToRealID()
   *

   *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSAError
  OSAGenericToRealID(ComponentInstance genericScriptingComponent,
                     OSAID *theScriptID, ComponentInstance *theExactComponent)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x1005, 0x7000, 0xA82A);

  /* get a generic id from a real component instance and script id */
  /**
   *  OSARealToGenericID()
   *

   *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSAError
  OSARealToGenericID(ComponentInstance genericScriptingComponent,
                     OSAID *theScriptID, ComponentInstance theExactComponent)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x1006, 0x7000, 0xA82A);

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

#endif /* __OSAGENERIC__ */
