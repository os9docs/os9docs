/**
     \file       LowMem.h

    \brief   Low Memory Accessor Interfaces.

    \introduced_in  Mac OS 8.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1993-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __LOWMEM__
#define __LOWMEM__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __MACMEMORY__
#include <MacMemory.h>
#endif

#ifndef __OSUTILS__
#include <OSUtils.h>
#endif

#ifndef __RESOURCES__
#include <Resources.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __CONTROLS__
#include <Controls.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __MENUS__
#include <Menus.h>
#endif

#ifndef __FONTS__
#include <Fonts.h>
#endif

#if !OPAQUE_TOOLBOX_STRUCTS
#ifndef __MACWINDOWS__
#include <MacWindows.h>
#endif

#endif /** !OPAQUE_TOOLBOX_STRUCTS */

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

  /***************************************************************************************

      SIMPLE LOWMEM ACCESSORS

  **************************************************************************************/
  /**
      The following functions were moved to Quickdraw.h:

          LMSetDeviceList
          LMSetLastSPExtra
          LMGetWidthListHand
          LMSetWidthListHand
          LMGetScrHRes
          LMSetScrHRes
          LMSetScrVRes
          LMGetScrVRes
          LMGetHiliteMode
          LMSetHiliteMode
          LMGetMainDevice
          LMSetMainDevice
          LMGetDeviceList
          LMGetQDColors
          LMSetQDColors
          LMGetWidthPtr
          LMSetWidthPtr
          LMGetWidthTabHandle
          LMSetWidthTabHandle
          LMGetLastSPExtra
          LMGetLastFOND
          LMSetLastFOND
          LMGetFractEnable
          LMSetFractEnable
          LMGetTheGDevice
          LMSetTheGDevice
          LMGetCursorNew
          LMSetCursorNew
          LMGetHiliteRGB
          LMSetHiliteRGB

      The following functions were moved to TextEdit.h:

          LMGetWordRedraw
          LMSetWordRedraw

      The following functions were moved to Menus.h:

          LMGetTheMenu

      The following functions were moved to Events.h:

          LMGetKeyRepThresh
          LMSetKeyRepThresh
          LMGetKeyThresh
          LMSetKeyRepThresh
          LMGetKbdLast
          LMSetKbdLast
          LMGetKbdType
          LMSetKbdType

  */

  /**
   *  LMGetMemTop()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetMemTop(void);

  /**
   *  LMSetMemTop()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetMemTop(Ptr value);

  /**
   *  LMGetBufPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetBufPtr(void);

  /**
   *  LMSetBufPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBufPtr(Ptr value);

  /**
   *  LMGetHeapEnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetHeapEnd(void);

  /**
   *  LMSetHeapEnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetHeapEnd(Ptr value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetTheZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  THz LMGetTheZone(void);

  /**
   *  LMSetTheZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTheZone(THz value);

  /**
   *  LMGetUTableBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetUTableBase(void);

  /**
   *  LMSetUTableBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetUTableBase(Ptr value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetCPUFlag()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetCPUFlag(void);

  /**
   *  LMSetCPUFlag()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetCPUFlag(UInt8 value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetApplLimit()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetApplLimit(void);

  /**
   *  LMSetApplLimit()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetApplLimit(Ptr value);

  /**
   *  LMGetSysEvtMask()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSysEvtMask(void);

  /** Carbon Usage: use SetEventMask*/
  /**
   *  LMSetSysEvtMask()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSysEvtMask(SInt16 value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetRndSeed()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetRndSeed(void);

  /**
   *  LMSetRndSeed()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetRndSeed(SInt32 value);

  /**
   *  LMGetSEvtEnb()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetSEvtEnb(void);

  /**
   *  LMSetSEvtEnb()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSEvtEnb(UInt8 value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetTicks()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32 LMGetTicks(void);

  /**
   *  LMSetTicks()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTicks(UInt32 value);

  /**
   *  LMGetVIA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetVIA(void);

  /**
   *  LMSetVIA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetVIA(Ptr value);

  /**
   *  LMGetSCCRd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetSCCRd(void);

  /**
   *  LMSetSCCRd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSCCRd(Ptr value);

  /**
   *  LMGetSCCWr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetSCCWr(void);

  /**
   *  LMSetSCCWr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSCCWr(Ptr value);

  /**
   *  LMGetSPValid()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPValid(void);

  /**
   *  LMSetSPValid()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPValid(UInt8 value);

  /**
   *  LMGetSPATalkA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPATalkA(void);

  /**
   *  LMSetSPATalkA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPATalkA(UInt8 value);

  /**
   *  LMGetSPATalkB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPATalkB(void);

  /**
   *  LMSetSPATalkB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPATalkB(UInt8 value);

  /**
   *  LMGetSPConfig()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPConfig(void);

  /**
   *  LMSetSPConfig()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPConfig(UInt8 value);

  /**
   *  LMGetSPPortA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSPPortA(void);

  /**
   *  LMSetSPPortA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPPortA(SInt16 value);

  /**
   *  LMGetSPPortB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSPPortB(void);

  /**
   *  LMSetSPPortB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPPortB(SInt16 value);

  /**
   *  LMGetSPAlarm()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetSPAlarm(void);

  /**
   *  LMSetSPAlarm()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPAlarm(SInt32 value);

  /**
   *  LMGetSPFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSPFont(void);

  /**
   *  LMSetSPFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPFont(SInt16 value);

  /**
   *  LMGetSPKbd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPKbd(void);

  /**
   *  LMSetSPKbd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPKbd(UInt8 value);

  /**
   *  LMGetSPPrint()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPPrint(void);

  /**
   *  LMSetSPPrint()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPPrint(UInt8 value);

  /**
   *  LMGetSPVolCtl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPVolCtl(void);

  /**
   *  LMSetSPVolCtl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPVolCtl(UInt8 value);

  /**
   *  LMGetSPClikCaret()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPClikCaret(void);

  /**
   *  LMSetSPClikCaret()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPClikCaret(UInt8 value);

  /**
   *  LMGetSPMisc2()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPMisc2(void);

  /**
   *  LMSetSPMisc2()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPMisc2(UInt8 value);

  /** Carbon Usage: use GetDateTime*/
  /**
   *  LMGetTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetTime(void);

  /** Carbon Usage: use SetDateTime*/
  /**
   *  LMSetTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTime(SInt32 value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetBootDrive()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetBootDrive(void);

  /**
   *  LMSetBootDrive()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBootDrive(SInt16 value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetSFSaveDisk()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSFSaveDisk(void);

  /**
   *  LMSetSFSaveDisk()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSFSaveDisk(SInt16 value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetMemErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetMemErr(void);

  /**
   *  LMSetMemErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetMemErr(SInt16 value);

  /**
   *  LMGetSdVolume()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetSdVolume(void);

  /**
   *  LMSetSdVolume()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSdVolume(UInt8 value);

  /**
   *  LMGetSoundPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetSoundPtr(void);

  /**
   *  LMSetSoundPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSoundPtr(Ptr value);

  /**
   *  LMGetSoundBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetSoundBase(void);

  /**
   *  LMSetSoundBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSoundBase(Ptr value);

  /**
   *  LMGetSoundLevel()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetSoundLevel(void);

  /**
   *  LMSetSoundLevel()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSoundLevel(UInt8 value);

  /**
   *  LMGetCurPitch()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetCurPitch(void);

  /**
   *  LMSetCurPitch()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetCurPitch(SInt16 value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetROM85()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetROM85(void);

  /**
   *  LMSetROM85()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetROM85(SInt16 value);

  /**
   *  LMGetPortBUse()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetPortBUse(void);

  /**
   *  LMSetPortBUse()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetPortBUse(UInt8 value);

  /**
   *  LMGetGNEFilter()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  GetNextEventFilterUPP
  LMGetGNEFilter(void);

  /**
   *  LMSetGNEFilter()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetGNEFilter(GetNextEventFilterUPP value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetSysZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  THz LMGetSysZone(void);

  /**
   *  LMSetSysZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSysZone(THz value);

  /**
   *  LMGetApplZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  THz LMGetApplZone(void);

  /**
   *  LMSetApplZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetApplZone(THz value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetROMBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetROMBase(void);

  /**
   *  LMSetROMBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetROMBase(Ptr value);

  /**
   *  LMGetRAMBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetRAMBase(void);

  /**
   *  LMSetRAMBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetRAMBase(Ptr value);

  /**
   *  LMGetDSAlertTab()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetDSAlertTab(void);

  /**
   *  LMSetDSAlertTab()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetDSAlertTab(Ptr value);

  /**
      NOTE:   LMGetABusVars and LMSetABusVars have been removed.
              Their implememtation in InterfaceLib was inconsistent
              with their prototypes here.  In InterfaceLib LMSetABusVars
              would copy eight bytes and LMGetABusVars would return the
              value 0x02D8 instead of the long at that location.

              Use LMGetABusGlobals/LMSetABusGlobals to get/set the
              long at location 0x02D8 which is a pointer to the AppleTalk
              globals.  Use LMGetABusDCE/LMSetABusDCE to get/set the
              long at location 0x02DC which is the .MPP driver
              Device Control Entry.

  */
  /**
   *  LMGetABusGlobals()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetABusGlobals(void);

  /**
   *  LMGetABusDCE()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetABusDCE(void);

  /**
   *  LMSetABusGlobals()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetABusGlobals(Ptr value);

  /**
   *  LMSetABusDCE()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetABusDCE(Ptr value);

  /** Carbon Usage: use GetDblTime*/
  /**
   *  LMGetDoubleTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32 LMGetDoubleTime(void);

  /**
   *  LMSetDoubleTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetDoubleTime(UInt32 value);

  /** Carbon Usage: use GetCaretTime*/
  /**
   *  LMGetCaretTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32 LMGetCaretTime(void);

  /**
   *  LMSetCaretTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCaretTime(UInt32 value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetScrDmpEnb()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetScrDmpEnb(void);

  /**
   *  LMSetScrDmpEnb()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetScrDmpEnb(UInt8 value);

  /**
   *  LMGetBufTgFNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetBufTgFNum(void);

  /**
   *  LMSetBufTgFNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBufTgFNum(SInt32 value);

  /**
   *  LMGetBufTgFFlg()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetBufTgFFlg(void);

  /**
   *  LMSetBufTgFFlg()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBufTgFFlg(SInt16 value);

  /**
   *  LMGetBufTgFBkNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetBufTgFBkNum(void);

  /**
   *  LMSetBufTgFBkNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBufTgFBkNum(SInt16 value);

  /**
   *  LMGetBufTgDate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetBufTgDate(void);

  /**
   *  LMSetBufTgDate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBufTgDate(SInt32 value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetLo3Bytes()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetLo3Bytes(void);

  /**
   *  LMSetLo3Bytes()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetLo3Bytes(SInt32 value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetMinStack()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetMinStack(void);

  /**
   *  LMSetMinStack()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetMinStack(SInt32 value);

  /**
   *  LMGetDefltStack()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetDefltStack(void);

  /**
   *  LMSetDefltStack()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetDefltStack(SInt32 value);

  /**
   *  LMGetGZRootHnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Handle LMGetGZRootHnd(void);

  /**
   *  LMSetGZRootHnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetGZRootHnd(Handle value);

  /**
   *  LMGetGZMoveHnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Handle LMGetGZMoveHnd(void);

  /**
   *  LMSetGZMoveHnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetGZMoveHnd(Handle value);

/**
   LMGetFCBSPtr, LMSetFCBSPtr and LMSetFSFCBLen are not supported with Mac OS 9
   and later. Access to information in File Control Blocks or Fork Control
   Blocks (FCBs) should, if at all possible, be made with the GetFCBInfo or
   GetForkCBInfo routines. See the Technote "FCBs, Now and Forever" or the
   Technical Q&A "Accessing File Control Blocks" for complete information on
   this subject. Direct access to FCBs is not allowed by Carbon. Non-Carbon
   programs that require direct access to FCBs should use the File System
   Manager (FSM) FCB accessor functions if FSM is available (use the Gestalt
   selector gestaltFSAttr to determine this). Non-Carbon programs needing direct
   access to FCBs when FSM is not available can define ENABLE_FCB_ARRAY_ACCESS
   to be true when compiling.
*/
#ifndef ENABLE_FCB_ARRAY_ACCESS
#define ENABLE_FCB_ARRAY_ACCESS 0
#endif /** !defined(ENABLE_FCB_ARRAY_ACCESS) */

#if ENABLE_FCB_ARRAY_ACCESS
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetFCBSPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetFCBSPtr(void);

  /**
   *  LMSetFCBSPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetFCBSPtr(Ptr value);

  /**
   *  LMSetFSFCBLen()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetFSFCBLen(SInt16 value);

#endif /** CALL_NOT_IN_CARBON */

#endif /** ENABLE_FCB_ARRAY_ACCESS */

/**
   LMGetFSFCBLen is supported only for the purpose of determining that the HFS
   file system is available as documented in developer Technotes (the HFS file
   system is available in System 3.2 and later). There is no documented use of
   FSFCBLen other than testing it for a positive value.
*/
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetFSFCBLen()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetFSFCBLen(void);

  /**
   *  LMGetDefVCBPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetDefVCBPtr(void);

  /**
   *  LMSetDefVCBPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetDefVCBPtr(Ptr value);

  /**
   *  LMGetCurDirStore()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetCurDirStore(void);

  /**
   *  LMSetCurDirStore()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCurDirStore(SInt32 value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetToExtFS()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UniversalProcPtr LMGetToExtFS(void);

  /**
   *  LMSetToExtFS()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  LMSetToExtFS(UniversalProcPtr value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetScrnBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetScrnBase(void);

  /**
   *  LMSetScrnBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrnBase(Ptr value);

  /**
   *  LMGetCrsrBusy()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetCrsrBusy(void);

  /**
   *  LMSetCrsrBusy()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCrsrBusy(UInt8 value);

  /**
   *  LMGetJournalRef()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetJournalRef(void);

  /**
   *  LMSetJournalRef()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetJournalRef(SInt16 value);

  /**
   *  LMGetCrsrThresh()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetCrsrThresh(void);

  /**
   *  LMSetCrsrThresh()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCrsrThresh(SInt16 value);

  /**
   *  LMGetJFetch()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetJFetch(void);

  /**
   *  LMSetJFetch()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetJFetch(UniversalProcPtr value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetJStash()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UniversalProcPtr LMGetJStash(void);

  /**
   *  LMSetJStash()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  LMSetJStash(UniversalProcPtr value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetJIODone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetJIODone(void);

  /**
   *  LMSetJIODone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetJIODone(UniversalProcPtr value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetCurApRefNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetCurApRefNum(void);

  /**
   *  LMSetCurApRefNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetCurApRefNum(SInt16 value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetCurrentA5()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetCurrentA5(void);

  /**
   *  LMSetCurrentA5()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCurrentA5(Ptr value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetCurStackBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetCurStackBase(void);

  /**
   *  LMSetCurStackBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetCurStackBase(Ptr value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetCurJTOffset()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetCurJTOffset(void);

  /**
   *  LMSetCurJTOffset()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCurJTOffset(SInt16 value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetCurPageOption()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetCurPageOption(void);

  /**
   *  LMSetCurPageOption()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetCurPageOption(SInt16 value);

  /**
   *  LMGetPrintErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetPrintErr(void);

  /**
   *  LMSetPrintErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetPrintErr(SInt16 value);

  /**  Carbon Scrap Manager does not support low memory.*/

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetScrapSize()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetScrapSize(void);

  /**
   *  LMSetScrapSize()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrapSize(SInt32 value);

  /**
   *  LMGetScrapHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetScrapHandle(void);

  /**
   *  LMSetScrapHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrapHandle(Handle value);

  /**
   *  LMGetScrapCount()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetScrapCount(void);

  /**
   *  LMSetScrapCount()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrapCount(SInt16 value);

  /**
   *  LMGetScrapState()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetScrapState(void);

  /**
   *  LMSetScrapState()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrapState(SInt16 value);

  /**
   *  LMGetScrapName()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  StringPtr LMGetScrapName(void);

  /**
   *  LMSetScrapName()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrapName(StringPtr value);

  /**
   *  LMGetROMFont0()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetROMFont0(void);

  /**
   *  LMSetROMFont0()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetROMFont0(Handle value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetApFontID()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetApFontID(void);

  /**
   *  LMSetApFontID()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetApFontID(SInt16 value);

/** Carbon versions of the Window Manager do not support LowMem. */
/** Carbon Usage: use GetWindowList*/
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetWindowList()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  WindowRef LMGetWindowList(void);

  /**
   *  LMGetSaveUpdate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSaveUpdate(void);

  /**
   *  LMSetSaveUpdate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSaveUpdate(SInt16 value);

  /**
   *  LMGetPaintWhite()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetPaintWhite(void);

  /** Carbon Usage : use InstallWindowContentPaintProc*/
  /**
   *  LMSetPaintWhite()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetPaintWhite(SInt16 value);

  /**
   *  LMGetWMgrPort()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  GrafPtr LMGetWMgrPort(void);

  /**
   *  LMSetWMgrPort()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetWMgrPort(GrafPtr value);

  /** Carbon Usage: use GetGrayRgn*/
  /**
   *  LMGetGrayRgn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  RgnHandle LMGetGrayRgn(void);

  /**
   *  LMGetDragHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  DragGrayRgnUPP LMGetDragHook(void);

  /**
   *  LMSetDragHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetDragHook(DragGrayRgnUPP value);

  /**
   *  LMSetWindowList()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetWindowList(WindowRef value);

  /**
   *  LMGetGhostWindow()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  WindowRef LMGetGhostWindow(void);

  /**
   *  LMSetGhostWindow()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetGhostWindow(WindowRef value);

#endif /** CALL_NOT_IN_CARBON */

#if !OPAQUE_TOOLBOX_STRUCTS
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetAuxWinHead()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  AuxWinHandle LMGetAuxWinHead(void);

  /**
   *  LMSetAuxWinHead()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetAuxWinHead(AuxWinHandle value);

#endif /** CALL_NOT_IN_CARBON */

#endif /** !OPAQUE_TOOLBOX_STRUCTS */

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetCurActivate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  WindowRef LMGetCurActivate(void);

  /**
   *  LMSetCurActivate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetCurActivate(WindowRef value);

  /**
   *  LMGetCurDeactive()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  WindowRef LMGetCurDeactive(void);

  /**
   *  LMSetCurDeactive()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetCurDeactive(WindowRef value);

  /**
   *  LMGetOldStructure()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  RgnHandle LMGetOldStructure(void);

  /**
   *  LMSetOldStructure()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetOldStructure(RgnHandle value);

  /**
   *  LMGetOldContent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  RgnHandle LMGetOldContent(void);

  /**
   *  LMSetOldContent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetOldContent(RgnHandle value);

  /**
   *  LMSetGrayRgn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetGrayRgn(RgnHandle value);

  /**
   *  LMGetSaveVisRgn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  RgnHandle LMGetSaveVisRgn(void);

  /**
   *  LMSetSaveVisRgn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSaveVisRgn(RgnHandle value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetOneOne()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetOneOne(void);

  /**
   *  LMSetOneOne()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetOneOne(SInt32 value);

  /**
   *  LMGetMinusOne()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetMinusOne(void);

  /**
   *  LMSetMinusOne()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetMinusOne(SInt32 value);

/** Carbon Usage: use GetMenuTrackingData*/
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetTopMenuItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetTopMenuItem(void);

  /** Carbon Usage: replaced by MDEF messages and GetMenuTrackingData API*/
  /**
   *  LMSetTopMenuItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTopMenuItem(SInt16 value);

  /** Carbon Usage: use GetMenuTrackingData*/
  /**
   *  LMGetAtMenuBottom()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetAtMenuBottom(void);

  /** Carbon Usage: replaced by MDEF messages and GetMenuTrackingData API*/
  /**
   *  LMSetAtMenuBottom()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetAtMenuBottom(SInt16 value);

  /**
     Carbon usage: use GetMenuBar (which returns a newly allocated handle in
     the same format as that returned by LMGetMenuList; dispose with
     DisposeMenuBar) or GetRootMenu.
  */
  /**
   *  LMGetMenuList()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetMenuList(void);

  /**
   *  LMSetMenuList()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMenuList(Handle value);

  /** Carbon usage: no replacement*/
  /**
   *  LMGetMBarEnable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetMBarEnable(void);

  /**
   *  LMSetMBarEnable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMBarEnable(SInt16 value);

  /** Carbon usage: no replacement*/
  /**
   *  LMGetMenuFlash()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetMenuFlash(void);

  /**
   *  LMSetMenuFlash()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMenuFlash(SInt16 value);

  /** LMGetTheMenu() moved to Menus.h */
  /**
   *  LMSetTheMenu()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTheMenu(SInt16 value);

  /**
   *  LMGetMBarHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MBarHookUPP LMGetMBarHook(void);

  /**
   *  LMSetMBarHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMBarHook(MBarHookUPP value);

  /**
   *  LMGetMenuHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MenuHookUPP LMGetMenuHook(void);

  /**
   *  LMSetMenuHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMenuHook(MenuHookUPP value);

  /**
   *  LMGetTopMapHndl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetTopMapHndl(void);

  /**
   *  LMSetTopMapHndl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTopMapHndl(Handle value);

  /**
   *  LMGetSysMapHndl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetSysMapHndl(void);

  /**
   *  LMSetSysMapHndl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSysMapHndl(Handle value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetSysMap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetSysMap(void);

  /**
   *  LMSetSysMap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSysMap(SInt16 value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetCurMap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetCurMap(void);

  /**
   *  LMSetCurMap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCurMap(SInt16 value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetResLoad()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetResLoad(void);

  /**
   *  LMSetResLoad()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetResLoad(UInt8 value);

  /**
   *  LMGetResErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetResErr(void);

  /**
   *  LMSetResErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetResErr(SInt16 value);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetFScaleDisable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetFScaleDisable(void);

  /**
   *  LMSetFScaleDisable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetFScaleDisable(UInt8 value);

  /**
   *  LMGetDeskHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetDeskHook(void);

  /**
   *  LMSetDeskHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetDeskHook(UniversalProcPtr value);

  /** Carbon Usage: Use TEGetDoTextHook.*/
  /**
   *  LMGetTEDoText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetTEDoText(void);

  /** Carbon Usage: Use TESetDoTextHook.*/
  /**
   *  LMSetTEDoText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetTEDoText(UniversalProcPtr value);

  /** Carbon Usage: Use TEGetRecalcHook.*/
  /**
   *  LMGetTERecal()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetTERecal(void);

  /** Carbon Usage: Use TESetRecalcHook.*/
  /**
   *  LMSetTERecal()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetTERecal(UniversalProcPtr value);

  /**
   *  LMGetResumeProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr
  LMGetResumeProc(void);

  /**
   *  LMSetResumeProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetResumeProc(UniversalProcPtr value);

  /**
   *  LMGetANumber()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetANumber(void);

  /**
   *  LMSetANumber()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetANumber(SInt16 value);

  /** Carbon Usage: Use GetAlertStage.*/
  /**
   *  LMGetACount()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetACount(void);

  /** Carbon Usage: Use ResetAlertStage.*/
  /**
   *  LMSetACount()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetACount(SInt16 value);

  /**
   *  LMGetDABeeper()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetDABeeper(void);

  /**
   *  LMSetDABeeper()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetDABeeper(UniversalProcPtr value);

  /** Carbon Usage: use TEGetScrapLength*/
  /**
   *  LMGetTEScrpLength()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt16 LMGetTEScrpLength(void);

  /** Carbon Usage: use TESetScrapLength*/
  /**
   *  LMSetTEScrpLength()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTEScrpLength(UInt16 value);

  /** Carbon Usage: use TEGetScrapHandle*/
  /**
   *  LMGetTEScrpHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetTEScrpHandle(void);

  /** Carbon Usage: use TESetScrapHandle*/
  /**
   *  LMSetTEScrpHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTEScrpHandle(Handle value);

  /**
   *  LMGetAppParmHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetAppParmHandle(void);

  /**
   *  LMSetAppParmHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetAppParmHandle(Handle value);

  /**
   *  LMGetDSErrCode()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetDSErrCode(void);

  /**
   *  LMSetDSErrCode()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetDSErrCode(SInt16 value);

  /**
   *  LMGetResErrProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ResErrUPP LMGetResErrProc(void);

  /**
   *  LMSetResErrProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetResErrProc(ResErrUPP value);

  /**
   *  LMGetDlgFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetDlgFont(void);

  /** Carbon Usage: use SetDialogFont*/
  /**
   *  LMSetDlgFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetDlgFont(SInt16 value);

  /**
   *  LMGetATalkHk2()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetATalkHk2(void);

  /**
   *  LMSetATalkHk2()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetATalkHk2(Ptr value);

  /**
   *  LMGetHWCfgFlags()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetHWCfgFlags(void);

  /**
   *  LMSetHWCfgFlags()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetHWCfgFlags(SInt16 value);

  /** Carbon Usage: use GetMenuTrackingData*/
  /**
   *  LMGetMenuDisable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetMenuDisable(void);

  /** Carbon Usage: use new MDEF messages*/
  /**
   *  LMSetMenuDisable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMenuDisable(SInt32 value);

  /**
   *  LMGetROMMapInsert()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetROMMapInsert(void);

  /**
   *  LMSetROMMapInsert()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetROMMapInsert(UInt8 value);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetTmpResLoad()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetTmpResLoad(void);

  /**
   *  LMSetTmpResLoad()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetTmpResLoad(UInt8 value);

  /**
   *  LMGetIntlSpec()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetIntlSpec(void);

  /**
   *  LMSetIntlSpec()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetIntlSpec(Ptr value);

  /** LMGetWordRedraw and LMSetWordRedraw moved to TextEdit.h */
  /**
   *  LMGetSysFontFam()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetSysFontFam(void);

  /**
   *  LMSetSysFontFam()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSysFontFam(SInt16 value);

  /**
   *  LMGetSysFontSize()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetSysFontSize(void);

  /**
   *  LMSetSysFontSize()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSysFontSize(SInt16 value);

/** Carbon Usge: use GetMBarHeight*/
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetMBarHeight()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetMBarHeight(void);

  /** Carbon Usage: use Hide/ShowMenuBar*/
  /**
   *  LMSetMBarHeight()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMBarHeight(SInt16 value);

  /**
   *  LMGetTESysJust()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetTESysJust(void);

  /**
   *  LMSetTESysJust()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTESysJust(SInt16 value);

  /**
   *  LMGetMMU32Bit()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetMMU32Bit(void);

  /**
   *  LMSetMMU32Bit()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMMU32Bit(UInt8 value);

  /**
   *  LMGetDeskCPat()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  PixPatHandle LMGetDeskCPat(void);

  /**
   *  LMSetDeskCPat()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetDeskCPat(PixPatHandle value);

  /**
   *  LMGetTimeDBRA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetTimeDBRA(void);

  /**
   *  LMSetTimeDBRA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTimeDBRA(SInt16 value);

  /**
   *  LMGetTimeSCCDB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetTimeSCCDB(void);

  /**
   *  LMSetTimeSCCDB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTimeSCCDB(SInt16 value);

  /**
   *  LMGetJVBLTask()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetJVBLTask(void);

  /**
   *  LMSetJVBLTask()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetJVBLTask(UniversalProcPtr value);

  /**
   *  LMGetSynListHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetSynListHandle(void);

  /**
   *  LMSetSynListHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSynListHandle(Handle value);

  /**
   *  LMGetMenuCInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MCTableHandle LMGetMenuCInfo(void);

  /**
   *  LMSetMenuCInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetMenuCInfo(MCTableHandle value);

  /**
   *  LMGetJDTInstall()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr
  LMGetJDTInstall(void);

  /**
   *  LMSetJDTInstall()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetJDTInstall(UniversalProcPtr value);

  /**
   *  LMGetTimeSCSIDB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetTimeSCSIDB(void);

  /**
   *  LMSetTimeSCSIDB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTimeSCSIDB(SInt16 value);

/***************************************************************************************

    MORE COMPLEX LOWMEM ACCESSORS

**************************************************************************************/
#endif /** CALL_NOT_IN_CARBON */

#if TARGET_CPU_68K && !TARGET_RT_MAC_CFM
/***************************************************************************************
    "BIG DATA"

        These lowmem accessors access big (> 4 bytes) values.
**************************************************************************************/
#define LMGetDSAlertRect(dsAlertRectValue) \
  (*(dsAlertRectValue) = *(Rect *)0x03F8)
#define LMSetDSAlertRect(dsAlertRectValue) \
  ((*(Rect *)0x03F8) = *(dsAlertRectValue))
#define LMGetDragPattern(dragPatternValue) \
  (*(dragPatternValue) = *(Pattern *)0x0A34)
#define LMSetDragPattern(dragPatternValue) \
  ((*(Pattern *)0x0A34) = *(dragPatternValue))
#define LMGetDeskPattern(deskPatternValue) \
  (*(deskPatternValue) = *(Pattern *)0x0A3C)
#define LMSetDeskPattern(deskPatternValue) \
  ((*(Pattern *)0x0A3C) = *(deskPatternValue))
#define LMGetEventQueue() ((QHdrPtr)0x014A)
#define LMSetEventQueue(eventQueueValue) \
  ((*(QHdrPtr)0x014A) = *(QHdrPtr)(eventQueueValue))
#define LMGetVBLQueue() ((QHdrPtr)0x0160)
#define LMSetVBLQueue(vblQueueValue) \
  ((*(QHdrPtr)0x0160) = *(QHdrPtr)(vblQueueValue))
#define LMGetDrvQHdr() ((QHdrPtr)0x0308)
#define LMSetDrvQHdr(drvQHdrValue) \
  ((*(QHdrPtr)0x0308) = *(QHdrPtr)(drvQHdrValue))
#define LMGetVCBQHdr() ((QHdrPtr)0x0356)
#define LMSetVCBQHdr(vcbQHdrValue) \
  ((*(QHdrPtr)0x0356) = *(QHdrPtr)(vcbQHdrValue))
#define LMGetDTQueue() ((QHdrPtr)0x0D92)
#define LMSetDTQueue(dtQueueValue) \
  ((*(QHdrPtr)0x0D92) = *(QHdrPtr)(dtQueueValue))
#define LMGetFSQHdr() ((QHdrPtr)0x0360)
/***************************************************************************************
    "BLOCKMOVE ACCESSORS"

        These lowmem accessors use the BlockMove to set
**************************************************************************************/
#define LMGetCurApName() ((StringPtr)0x0910)
#define LMSetCurApName(curApNameValue) \
  (BlockMoveData((Ptr)(curApNameValue), (Ptr)0x0910, sizeof(Str31)))
#define LMGetSysResName() ((StringPtr)0x0AD8)
#define LMSetSysResName(sysResNameValue) \
  (BlockMoveData((Ptr)(sysResNameValue), (Ptr)0x0AD8, sizeof(Str15)))
#define LMGetFinderName() ((StringPtr)0x02E0)
#define LMSetFinderName(finderName) \
  (BlockMoveData((Ptr)(finderName), (Ptr)0x02E0, sizeof(Str15)))
#define LMGetScratch20() ((Ptr)0x01E4)
#define LMSetScratch20(scratch20Value) \
  (BlockMoveData((Ptr)(scratch20Value), (Ptr)0x01E4, 20))
#define LMGetToolScratch() ((Ptr)0x09CE)
#define LMSetToolScratch(toolScratchValue) \
  (BlockMoveData((Ptr)(toolScratchValue), (Ptr)0x09CE, 8))
#define LMGetApplScratch() ((Ptr)0x0A78)
#define LMSetApplScratch(applScratchValue) \
  (BlockMoveData((Ptr)(applScratchValue), (Ptr)0x0A78, 12))
/***************************************************************************************
    "INDEXED ACCESSORS"

        These lowmem accessors take an index parameter to get/set an indexed
        lowmem global.
**************************************************************************************/
/**************************************************************************************
    The DAString accessors are gone with Carbon. Please use ParamText and
    GetParamText instead.
**************************************************************************************/
#define LMGetDAStrings(whichString) (((StringHandle *)0x0AA0)[whichString])
#define LMSetDAStrings(stringsValue, whichString) \
  (((StringHandle *)0x0AA0)[whichString] = (stringsValue))
#define LMGetLvl2DT(vectorNumber) (((UniversalProcPtr *)0x01B2)[vectorNumber])
#define LMSetLvl2DT(lvl2DTValue, vectorNumber) \
  (((UniversalProcPtr *)0x01B2)[vectorNumber] = (lvl2DTValue))
#define LMGetExtStsDT(vectorNumber) (((UniversalProcPtr *)0x02BE)[vectorNumber])
#define LMSetExtStsDT(extStsDTValue, vectorNumber) \
  (((UniversalProcPtr *)0x02BE)[vectorNumber] = (extStsDTValue))

#else
/***************************************************************************************
    "BIG DATA"

        These lowmem accessors access big (> 4 bytes) values.
**************************************************************************************/

#if CALL_NOT_IN_CARBON
/**
 *  LMGetDSAlertRect()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMGetDSAlertRect(Rect *dsAlertRectValue);

/**
 *  LMSetDSAlertRect()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetDSAlertRect(const Rect *dsAlertRectValue);

/**
 *  LMGetDragPattern()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMGetDragPattern(Pattern *dragPatternValue);

/**
 *  LMSetDragPattern()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetDragPattern(const Pattern *dragPatternValue);

/**
 *  LMGetDeskPattern()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMGetDeskPattern(Pattern *deskPatternValue);

/**
 *  LMSetDeskPattern()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetDeskPattern(const Pattern *deskPatternValue);

/**
 *  LMGetEventQueue()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
QHdrPtr LMGetEventQueue(void);

/**
 *  LMSetEventQueue()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetEventQueue(QHdrPtr eventQueueValue);

/**
 *  LMGetVBLQueue()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
QHdrPtr LMGetVBLQueue(void);

/**
 *  LMSetVBLQueue()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetVBLQueue(QHdrPtr vblQueueValue);

/**
 *  LMGetDrvQHdr()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
QHdrPtr LMGetDrvQHdr(void);

/**
 *  LMSetDrvQHdr()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetDrvQHdr(QHdrPtr drvQHdrValue);

/**
 *  LMGetVCBQHdr()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
QHdrPtr LMGetVCBQHdr(void);

/**
 *  LMSetVCBQHdr()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetVCBQHdr(QHdrPtr vcbQHdrValue);

/**
 *  LMGetDTQueue()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
QHdrPtr LMGetDTQueue(void);

/**
 *  LMSetDTQueue()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetDTQueue(QHdrPtr dtQueueValue);

/**
 *  LMGetFSQHdr()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
QHdrPtr LMGetFSQHdr(void);

/***************************************************************************************
    "BLOCKMOVE ACCESSORS"

        These lowmem accessors use the BlockMove to set
**************************************************************************************/
#endif /** CALL_NOT_IN_CARBON */

/**
 *  LMGetCurApName()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
StringPtr LMGetCurApName(void);

/**
 *  LMSetCurApName()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetCurApName(ConstStr31Param curApNameValue);

/**
 *  LMGetSysResName()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
StringPtr LMGetSysResName(void);

/**
 *  LMSetSysResName()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetSysResName(ConstStr15Param sysResNameValue);

/**
 *  LMGetFinderName()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
StringPtr LMGetFinderName(void);

/**
 *  LMSetFinderName()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetFinderName(ConstStr15Param finderNameValue);

#if CALL_NOT_IN_CARBON
/**
 *  LMGetScratch20()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Ptr LMGetScratch20(void);

/**
 *  LMSetScratch20()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetScratch20(const void *scratch20Value);

#endif /** CALL_NOT_IN_CARBON */

/**
 *  LMGetToolScratch()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Ptr LMGetToolScratch(void);

/**
 *  LMSetToolScratch()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetToolScratch(const void *toolScratchValue);

#if CALL_NOT_IN_CARBON
/**
 *  LMGetApplScratch()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Ptr LMGetApplScratch(void);

/**
 *  LMSetApplScratch()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetApplScratch(const void *applScratchValue);

/***************************************************************************************
    "INDEXED ACCESSORS"

        These lowmem accessors take an index parameter to get/set an indexed
        lowmem global.
**************************************************************************************/

/** Carbon Usage: use GetParamText*/
/**
 *  LMGetDAStrings()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
StringHandle LMGetDAStrings(short whichString);

/** Carbon Usage: use ParamText*/
/**
 *  LMSetDAStrings()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetDAStrings(StringHandle stringsValue, short whichString);

#endif /** CALL_NOT_IN_CARBON */

/**
 *  LMGetLvl2DT()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
UniversalProcPtr LMGetLvl2DT(short vectorNumber);

/**
 *  LMSetLvl2DT()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetLvl2DT(UniversalProcPtr Lvl2DTValue, short vectorNumber);

#if CALL_NOT_IN_CARBON
/**
 *  LMGetExtStsDT()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
UniversalProcPtr LMGetExtStsDT(short vectorNumber);

/**
 *  LMSetExtStsDT()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LMSetExtStsDT(UniversalProcPtr ExtStsDTValue, short vectorNumber);

#endif /** CALL_NOT_IN_CARBON */

#endif /** TARGET_CPU_68K && !TARGET_RT_MAC_CFM */

  /***************************************************************************************
      "Missing Accessors"

          These lowmem accessors are not in the original InterfaceLib.  They were
          added to InterfaceLib in Mac OS 8.5.  In Universal Interfaces 3.2 they
          were defined via a macro. In you want to use these functions on a
  pre-8.5 systems, you must write your own macros to override the function
  prototype or write your own implementation.

  **************************************************************************************/

#if CALL_NOT_IN_CARBON
  /**
   *  LMSetMouseTemp()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMouseTemp(Point value);

  /** accesses "MTemp"*/
  /**
   *  LMGetMouseTemp()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Point LMGetMouseTemp(void);

  /**
     accesses "MBState"
     Carbon Usage: use Button()
  */
  /**
   *  LMGetMouseButtonState()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetMouseButtonState(void);

  /**
   *  LMSetMouseButtonState()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetMouseButtonState(UInt8 value);

  /**
     accesses "RawMouse"
     Carbon Usage: use GetGlobalMouse
  */
  /**
   *  LMGetRawMouseLocation()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Point LMGetRawMouseLocation(void);

  /** Carbon Usage: use GetGlobalMouse*/
  /**
   *  LMSetRawMouseLocation()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetRawMouseLocation(Point value);

  /**
     accesses "Mouse"
     Carbon Usage: use GetGlobalMouse
  */
  /**
   *  LMGetMouseLocation()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Point LMGetMouseLocation(void);

  /**
   *  LMSetMouseLocation()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMouseLocation(Point value);

  /** accesses "TheCrsr"*/
  /**
   *  LMGetTheCursor()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMGetTheCursor(Cursor *currentCursor);

  /**
   *  LMSetTheCursor()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTheCursor(const Cursor *newCursor);

/** accesses "HiHeapMark"*/
#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetHighHeapMark()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetHighHeapMark(void);

  /**
   *  LMSetHighHeapMark()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetHighHeapMark(Ptr value);

  /** accesses "StkLowPt"*/
  /**
   *  LMGetStackLowPoint()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetStackLowPoint(void);

  /**
   *  LMSetStackLowPoint()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetStackLowPoint(Ptr value);

/** accesses "ROMMapHndl"*/
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetROMMapHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetROMMapHandle(void);

  /**
   *  LMSetROMMapHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetROMMapHandle(Handle value);

  /** accesses "UnitNtryCnt"*/
  /**
   *  LMGetUnitTableEntryCount()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short LMGetUnitTableEntryCount(void);

  /**
   *  LMSetUnitTableEntryCount()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetUnitTableEntryCount(short value);

/** accesses "FmtDefaults"*/
#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetDiskFormatingHFSDefaults()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetDiskFormatingHFSDefaults(void);

  /**
   *  LMSetDiskFormatingHFSDefaults()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  LMSetDiskFormatingHFSDefaults(Ptr value);

/** accesses "PortAUse"*/
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetPortAInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetPortAInfo(void);

  /**
   *  LMSetPortAInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetPortAInfo(UInt8 value);

  /**
   *  LMGetMBTicks()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long LMGetMBTicks(void);

  /**
   *  LMSetMBTicks()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMBTicks(long value);

  /**
   *  LMGetKeyTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long LMGetKeyTime(void);

  /**
   *  LMSetKeyTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetKeyTime(long value);

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

#endif /** __LOWMEM__ */
