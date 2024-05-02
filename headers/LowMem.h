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
  Ptr LMGetMemTop(void) TWOWORDINLINE(0x2EB8, 0x0108);

  /**
   *  LMSetMemTop()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetMemTop(Ptr value) TWOWORDINLINE(0x21DF, 0x0108);

  /**
   *  LMGetBufPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetBufPtr(void) TWOWORDINLINE(0x2EB8, 0x010C);

  /**
   *  LMSetBufPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBufPtr(Ptr value) TWOWORDINLINE(0x21DF, 0x010C);

  /**
   *  LMGetHeapEnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetHeapEnd(void) TWOWORDINLINE(0x2EB8, 0x0114);

  /**
   *  LMSetHeapEnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetHeapEnd(Ptr value) TWOWORDINLINE(0x21DF, 0x0114);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetTheZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  THz LMGetTheZone(void) TWOWORDINLINE(0x2EB8, 0x0118);

  /**
   *  LMSetTheZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTheZone(THz value) TWOWORDINLINE(0x21DF, 0x0118);

  /**
   *  LMGetUTableBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetUTableBase(void) TWOWORDINLINE(0x2EB8, 0x011C);

  /**
   *  LMSetUTableBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetUTableBase(Ptr value) TWOWORDINLINE(0x21DF, 0x011C);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetCPUFlag()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetCPUFlag(void) TWOWORDINLINE(0x1EB8, 0x012F);

  /**
   *  LMSetCPUFlag()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetCPUFlag(UInt8 value) TWOWORDINLINE(0x11DF, 0x012F);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetApplLimit()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetApplLimit(void) TWOWORDINLINE(0x2EB8, 0x0130);

  /**
   *  LMSetApplLimit()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetApplLimit(Ptr value) TWOWORDINLINE(0x21DF, 0x0130);

  /**
   *  LMGetSysEvtMask()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSysEvtMask(void) TWOWORDINLINE(0x3EB8, 0x0144);

  /** Carbon Usage: use SetEventMask*/
  /**
   *  LMSetSysEvtMask()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSysEvtMask(SInt16 value) TWOWORDINLINE(0x31DF, 0x0144);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetRndSeed()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetRndSeed(void) TWOWORDINLINE(0x2EB8, 0x0156);

  /**
   *  LMSetRndSeed()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetRndSeed(SInt32 value) TWOWORDINLINE(0x21DF, 0x0156);

  /**
   *  LMGetSEvtEnb()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetSEvtEnb(void) TWOWORDINLINE(0x1EB8, 0x015C);

  /**
   *  LMSetSEvtEnb()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSEvtEnb(UInt8 value) TWOWORDINLINE(0x11DF, 0x015C);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetTicks()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32 LMGetTicks(void) TWOWORDINLINE(0x2EB8, 0x016A);

  /**
   *  LMSetTicks()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTicks(UInt32 value) TWOWORDINLINE(0x21DF, 0x016A);

  /**
   *  LMGetVIA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetVIA(void) TWOWORDINLINE(0x2EB8, 0x01D4);

  /**
   *  LMSetVIA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetVIA(Ptr value) TWOWORDINLINE(0x21DF, 0x01D4);

  /**
   *  LMGetSCCRd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetSCCRd(void) TWOWORDINLINE(0x2EB8, 0x01D8);

  /**
   *  LMSetSCCRd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSCCRd(Ptr value) TWOWORDINLINE(0x21DF, 0x01D8);

  /**
   *  LMGetSCCWr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetSCCWr(void) TWOWORDINLINE(0x2EB8, 0x01DC);

  /**
   *  LMSetSCCWr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSCCWr(Ptr value) TWOWORDINLINE(0x21DF, 0x01DC);

  /**
   *  LMGetSPValid()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPValid(void) TWOWORDINLINE(0x1EB8, 0x01F8);

  /**
   *  LMSetSPValid()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPValid(UInt8 value) TWOWORDINLINE(0x11DF, 0x01F8);

  /**
   *  LMGetSPATalkA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPATalkA(void) TWOWORDINLINE(0x1EB8, 0x01F9);

  /**
   *  LMSetSPATalkA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPATalkA(UInt8 value) TWOWORDINLINE(0x11DF, 0x01F9);

  /**
   *  LMGetSPATalkB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPATalkB(void) TWOWORDINLINE(0x1EB8, 0x01FA);

  /**
   *  LMSetSPATalkB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPATalkB(UInt8 value) TWOWORDINLINE(0x11DF, 0x01FA);

  /**
   *  LMGetSPConfig()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPConfig(void) TWOWORDINLINE(0x1EB8, 0x01FB);

  /**
   *  LMSetSPConfig()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPConfig(UInt8 value) TWOWORDINLINE(0x11DF, 0x01FB);

  /**
   *  LMGetSPPortA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSPPortA(void) TWOWORDINLINE(0x3EB8, 0x01FC);

  /**
   *  LMSetSPPortA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPPortA(SInt16 value) TWOWORDINLINE(0x31DF, 0x01FC);

  /**
   *  LMGetSPPortB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSPPortB(void) TWOWORDINLINE(0x3EB8, 0x01FE);

  /**
   *  LMSetSPPortB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPPortB(SInt16 value) TWOWORDINLINE(0x31DF, 0x01FE);

  /**
   *  LMGetSPAlarm()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetSPAlarm(void) TWOWORDINLINE(0x2EB8, 0x0200);

  /**
   *  LMSetSPAlarm()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPAlarm(SInt32 value) TWOWORDINLINE(0x21DF, 0x0200);

  /**
   *  LMGetSPFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSPFont(void) TWOWORDINLINE(0x3EB8, 0x0204);

  /**
   *  LMSetSPFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPFont(SInt16 value) TWOWORDINLINE(0x31DF, 0x0204);

  /**
   *  LMGetSPKbd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPKbd(void) TWOWORDINLINE(0x1EB8, 0x0206);

  /**
   *  LMSetSPKbd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPKbd(UInt8 value) TWOWORDINLINE(0x11DF, 0x0206);

  /**
   *  LMGetSPPrint()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPPrint(void) TWOWORDINLINE(0x1EB8, 0x0207);

  /**
   *  LMSetSPPrint()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPPrint(UInt8 value) TWOWORDINLINE(0x11DF, 0x0207);

  /**
   *  LMGetSPVolCtl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPVolCtl(void) TWOWORDINLINE(0x1EB8, 0x0208);

  /**
   *  LMSetSPVolCtl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPVolCtl(UInt8 value) TWOWORDINLINE(0x11DF, 0x0208);

  /**
   *  LMGetSPClikCaret()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPClikCaret(void) TWOWORDINLINE(0x1EB8, 0x0209);

  /**
   *  LMSetSPClikCaret()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPClikCaret(UInt8 value) TWOWORDINLINE(0x11DF, 0x0209);

  /**
   *  LMGetSPMisc2()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetSPMisc2(void) TWOWORDINLINE(0x1EB8, 0x020B);

  /**
   *  LMSetSPMisc2()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSPMisc2(UInt8 value) TWOWORDINLINE(0x11DF, 0x020B);

  /** Carbon Usage: use GetDateTime*/
  /**
   *  LMGetTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetTime(void) TWOWORDINLINE(0x2EB8, 0x020C);

  /** Carbon Usage: use SetDateTime*/
  /**
   *  LMSetTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTime(SInt32 value) TWOWORDINLINE(0x21DF, 0x020C);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetBootDrive()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetBootDrive(void) TWOWORDINLINE(0x3EB8, 0x0210);

  /**
   *  LMSetBootDrive()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBootDrive(SInt16 value) TWOWORDINLINE(0x31DF, 0x0210);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetSFSaveDisk()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSFSaveDisk(void) TWOWORDINLINE(0x3EB8, 0x0214);

  /**
   *  LMSetSFSaveDisk()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSFSaveDisk(SInt16 value) TWOWORDINLINE(0x31DF, 0x0214);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetMemErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetMemErr(void) TWOWORDINLINE(0x3EB8, 0x0220);

  /**
   *  LMSetMemErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetMemErr(SInt16 value) TWOWORDINLINE(0x31DF, 0x0220);

  /**
   *  LMGetSdVolume()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetSdVolume(void) TWOWORDINLINE(0x1EB8, 0x0260);

  /**
   *  LMSetSdVolume()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSdVolume(UInt8 value) TWOWORDINLINE(0x11DF, 0x0260);

  /**
   *  LMGetSoundPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetSoundPtr(void) TWOWORDINLINE(0x2EB8, 0x0262);

  /**
   *  LMSetSoundPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSoundPtr(Ptr value) TWOWORDINLINE(0x21DF, 0x0262);

  /**
   *  LMGetSoundBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetSoundBase(void) TWOWORDINLINE(0x2EB8, 0x0266);

  /**
   *  LMSetSoundBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSoundBase(Ptr value) TWOWORDINLINE(0x21DF, 0x0266);

  /**
   *  LMGetSoundLevel()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetSoundLevel(void) TWOWORDINLINE(0x1EB8, 0x027F);

  /**
   *  LMSetSoundLevel()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSoundLevel(UInt8 value) TWOWORDINLINE(0x11DF, 0x027F);

  /**
   *  LMGetCurPitch()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetCurPitch(void) TWOWORDINLINE(0x3EB8, 0x0280);

  /**
   *  LMSetCurPitch()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetCurPitch(SInt16 value) TWOWORDINLINE(0x31DF, 0x0280);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetROM85()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetROM85(void) TWOWORDINLINE(0x3EB8, 0x028E);

  /**
   *  LMSetROM85()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetROM85(SInt16 value) TWOWORDINLINE(0x31DF, 0x028E);

  /**
   *  LMGetPortBUse()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetPortBUse(void) TWOWORDINLINE(0x1EB8, 0x0291);

  /**
   *  LMSetPortBUse()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetPortBUse(UInt8 value) TWOWORDINLINE(0x11DF, 0x0291);

  /**
   *  LMGetGNEFilter()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  GetNextEventFilterUPP
  LMGetGNEFilter(void) TWOWORDINLINE(0x2EB8, 0x029A);

  /**
   *  LMSetGNEFilter()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetGNEFilter(GetNextEventFilterUPP value) TWOWORDINLINE(0x21DF, 0x029A);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetSysZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  THz LMGetSysZone(void) TWOWORDINLINE(0x2EB8, 0x02A6);

  /**
   *  LMSetSysZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSysZone(THz value) TWOWORDINLINE(0x21DF, 0x02A6);

  /**
   *  LMGetApplZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  THz LMGetApplZone(void) TWOWORDINLINE(0x2EB8, 0x02AA);

  /**
   *  LMSetApplZone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetApplZone(THz value) TWOWORDINLINE(0x21DF, 0x02AA);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetROMBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetROMBase(void) TWOWORDINLINE(0x2EB8, 0x02AE);

  /**
   *  LMSetROMBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetROMBase(Ptr value) TWOWORDINLINE(0x21DF, 0x02AE);

  /**
   *  LMGetRAMBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetRAMBase(void) TWOWORDINLINE(0x2EB8, 0x02B2);

  /**
   *  LMSetRAMBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetRAMBase(Ptr value) TWOWORDINLINE(0x21DF, 0x02B2);

  /**
   *  LMGetDSAlertTab()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetDSAlertTab(void) TWOWORDINLINE(0x2EB8, 0x02BA);

  /**
   *  LMSetDSAlertTab()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetDSAlertTab(Ptr value) TWOWORDINLINE(0x21DF, 0x02BA);

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
  Ptr LMGetABusGlobals(void) TWOWORDINLINE(0x2EB8, 0x02D8);

  /**
   *  LMGetABusDCE()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetABusDCE(void) TWOWORDINLINE(0x2EB8, 0x02DC);

  /**
   *  LMSetABusGlobals()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetABusGlobals(Ptr value) TWOWORDINLINE(0x21DF, 0x02D8);

  /**
   *  LMSetABusDCE()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetABusDCE(Ptr value) TWOWORDINLINE(0x21DF, 0x02DC);

  /** Carbon Usage: use GetDblTime*/
  /**
   *  LMGetDoubleTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32 LMGetDoubleTime(void) TWOWORDINLINE(0x2EB8, 0x02F0);

  /**
   *  LMSetDoubleTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetDoubleTime(UInt32 value) TWOWORDINLINE(0x21DF, 0x02F0);

  /** Carbon Usage: use GetCaretTime*/
  /**
   *  LMGetCaretTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32 LMGetCaretTime(void) TWOWORDINLINE(0x2EB8, 0x02F4);

  /**
   *  LMSetCaretTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCaretTime(UInt32 value) TWOWORDINLINE(0x21DF, 0x02F4);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetScrDmpEnb()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetScrDmpEnb(void) TWOWORDINLINE(0x1EB8, 0x02F8);

  /**
   *  LMSetScrDmpEnb()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetScrDmpEnb(UInt8 value) TWOWORDINLINE(0x11DF, 0x02F8);

  /**
   *  LMGetBufTgFNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetBufTgFNum(void) TWOWORDINLINE(0x2EB8, 0x02FC);

  /**
   *  LMSetBufTgFNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBufTgFNum(SInt32 value) TWOWORDINLINE(0x21DF, 0x02FC);

  /**
   *  LMGetBufTgFFlg()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetBufTgFFlg(void) TWOWORDINLINE(0x3EB8, 0x0300);

  /**
   *  LMSetBufTgFFlg()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBufTgFFlg(SInt16 value) TWOWORDINLINE(0x31DF, 0x0300);

  /**
   *  LMGetBufTgFBkNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetBufTgFBkNum(void) TWOWORDINLINE(0x3EB8, 0x0302);

  /**
   *  LMSetBufTgFBkNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBufTgFBkNum(SInt16 value) TWOWORDINLINE(0x31DF, 0x0302);

  /**
   *  LMGetBufTgDate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetBufTgDate(void) TWOWORDINLINE(0x2EB8, 0x0304);

  /**
   *  LMSetBufTgDate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetBufTgDate(SInt32 value) TWOWORDINLINE(0x21DF, 0x0304);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetLo3Bytes()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetLo3Bytes(void) TWOWORDINLINE(0x2EB8, 0x031A);

  /**
   *  LMSetLo3Bytes()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetLo3Bytes(SInt32 value) TWOWORDINLINE(0x21DF, 0x031A);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetMinStack()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetMinStack(void) TWOWORDINLINE(0x2EB8, 0x031E);

  /**
   *  LMSetMinStack()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetMinStack(SInt32 value) TWOWORDINLINE(0x21DF, 0x031E);

  /**
   *  LMGetDefltStack()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetDefltStack(void) TWOWORDINLINE(0x2EB8, 0x0322);

  /**
   *  LMSetDefltStack()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetDefltStack(SInt32 value) TWOWORDINLINE(0x21DF, 0x0322);

  /**
   *  LMGetGZRootHnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Handle LMGetGZRootHnd(void) TWOWORDINLINE(0x2EB8, 0x0328);

  /**
   *  LMSetGZRootHnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetGZRootHnd(Handle value) TWOWORDINLINE(0x21DF, 0x0328);

  /**
   *  LMGetGZMoveHnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Handle LMGetGZMoveHnd(void) TWOWORDINLINE(0x2EB8, 0x0330);

  /**
   *  LMSetGZMoveHnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetGZMoveHnd(Handle value) TWOWORDINLINE(0x21DF, 0x0330);

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
  Ptr LMGetFCBSPtr(void) TWOWORDINLINE(0x2EB8, 0x034E);

  /**
   *  LMSetFCBSPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetFCBSPtr(Ptr value) TWOWORDINLINE(0x21DF, 0x034E);

  /**
   *  LMSetFSFCBLen()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetFSFCBLen(SInt16 value) TWOWORDINLINE(0x31DF, 0x03F6);

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
  SInt16 LMGetFSFCBLen(void) TWOWORDINLINE(0x3EB8, 0x03F6);

  /**
   *  LMGetDefVCBPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetDefVCBPtr(void) TWOWORDINLINE(0x2EB8, 0x0352);

  /**
   *  LMSetDefVCBPtr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetDefVCBPtr(Ptr value) TWOWORDINLINE(0x21DF, 0x0352);

  /**
   *  LMGetCurDirStore()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetCurDirStore(void) TWOWORDINLINE(0x2EB8, 0x0398);

  /**
   *  LMSetCurDirStore()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCurDirStore(SInt32 value) TWOWORDINLINE(0x21DF, 0x0398);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetToExtFS()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UniversalProcPtr LMGetToExtFS(void) TWOWORDINLINE(0x2EB8, 0x03F2);

  /**
   *  LMSetToExtFS()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  LMSetToExtFS(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x03F2);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetScrnBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetScrnBase(void) TWOWORDINLINE(0x2EB8, 0x0824);

  /**
   *  LMSetScrnBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrnBase(Ptr value) TWOWORDINLINE(0x21DF, 0x0824);

  /**
   *  LMGetCrsrBusy()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetCrsrBusy(void) TWOWORDINLINE(0x1EB8, 0x08CD);

  /**
   *  LMSetCrsrBusy()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCrsrBusy(UInt8 value) TWOWORDINLINE(0x11DF, 0x08CD);

  /**
   *  LMGetJournalRef()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetJournalRef(void) TWOWORDINLINE(0x3EB8, 0x08E8);

  /**
   *  LMSetJournalRef()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetJournalRef(SInt16 value) TWOWORDINLINE(0x31DF, 0x08E8);

  /**
   *  LMGetCrsrThresh()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetCrsrThresh(void) TWOWORDINLINE(0x3EB8, 0x08EC);

  /**
   *  LMSetCrsrThresh()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCrsrThresh(SInt16 value) TWOWORDINLINE(0x31DF, 0x08EC);

  /**
   *  LMGetJFetch()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetJFetch(void) TWOWORDINLINE(0x2EB8, 0x08F4);

  /**
   *  LMSetJFetch()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetJFetch(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x08F4);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetJStash()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UniversalProcPtr LMGetJStash(void) TWOWORDINLINE(0x2EB8, 0x08F8);

  /**
   *  LMSetJStash()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  LMSetJStash(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x08F8);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetJIODone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetJIODone(void) TWOWORDINLINE(0x2EB8, 0x08FC);

  /**
   *  LMSetJIODone()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetJIODone(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x08FC);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetCurApRefNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetCurApRefNum(void) TWOWORDINLINE(0x3EB8, 0x0900);

  /**
   *  LMSetCurApRefNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetCurApRefNum(SInt16 value) TWOWORDINLINE(0x31DF, 0x0900);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetCurrentA5()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetCurrentA5(void) TWOWORDINLINE(0x2EB8, 0x0904);

  /**
   *  LMSetCurrentA5()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCurrentA5(Ptr value) TWOWORDINLINE(0x21DF, 0x0904);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetCurStackBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetCurStackBase(void) TWOWORDINLINE(0x2EB8, 0x0908);

  /**
   *  LMSetCurStackBase()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetCurStackBase(Ptr value) TWOWORDINLINE(0x21DF, 0x0908);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetCurJTOffset()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetCurJTOffset(void) TWOWORDINLINE(0x3EB8, 0x0934);

  /**
   *  LMSetCurJTOffset()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCurJTOffset(SInt16 value) TWOWORDINLINE(0x31DF, 0x0934);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetCurPageOption()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetCurPageOption(void) TWOWORDINLINE(0x3EB8, 0x0936);

  /**
   *  LMSetCurPageOption()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetCurPageOption(SInt16 value) TWOWORDINLINE(0x31DF, 0x0936);

  /**
   *  LMGetPrintErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetPrintErr(void) TWOWORDINLINE(0x3EB8, 0x0944);

  /**
   *  LMSetPrintErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetPrintErr(SInt16 value) TWOWORDINLINE(0x31DF, 0x0944);

  /**  Carbon Scrap Manager does not support low memory.*/

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetScrapSize()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetScrapSize(void) TWOWORDINLINE(0x2EB8, 0x0960);

  /**
   *  LMSetScrapSize()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrapSize(SInt32 value) TWOWORDINLINE(0x21DF, 0x0960);

  /**
   *  LMGetScrapHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetScrapHandle(void) TWOWORDINLINE(0x2EB8, 0x0964);

  /**
   *  LMSetScrapHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrapHandle(Handle value) TWOWORDINLINE(0x21DF, 0x0964);

  /**
   *  LMGetScrapCount()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetScrapCount(void) TWOWORDINLINE(0x3EB8, 0x0968);

  /**
   *  LMSetScrapCount()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrapCount(SInt16 value) TWOWORDINLINE(0x31DF, 0x0968);

  /**
   *  LMGetScrapState()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetScrapState(void) TWOWORDINLINE(0x3EB8, 0x096A);

  /**
   *  LMSetScrapState()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrapState(SInt16 value) TWOWORDINLINE(0x31DF, 0x096A);

  /**
   *  LMGetScrapName()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  StringPtr LMGetScrapName(void) TWOWORDINLINE(0x2EB8, 0x096C);

  /**
   *  LMSetScrapName()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetScrapName(StringPtr value) TWOWORDINLINE(0x21DF, 0x096C);

  /**
   *  LMGetROMFont0()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetROMFont0(void) TWOWORDINLINE(0x2EB8, 0x0980);

  /**
   *  LMSetROMFont0()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetROMFont0(Handle value) TWOWORDINLINE(0x21DF, 0x0980);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetApFontID()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetApFontID(void) TWOWORDINLINE(0x3EB8, 0x0984);

  /**
   *  LMSetApFontID()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetApFontID(SInt16 value) TWOWORDINLINE(0x31DF, 0x0984);

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
  WindowRef LMGetWindowList(void) TWOWORDINLINE(0x2EB8, 0x09D6);

  /**
   *  LMGetSaveUpdate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetSaveUpdate(void) TWOWORDINLINE(0x3EB8, 0x09DA);

  /**
   *  LMSetSaveUpdate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSaveUpdate(SInt16 value) TWOWORDINLINE(0x31DF, 0x09DA);

  /**
   *  LMGetPaintWhite()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetPaintWhite(void) TWOWORDINLINE(0x3EB8, 0x09DC);

  /** Carbon Usage : use InstallWindowContentPaintProc*/
  /**
   *  LMSetPaintWhite()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetPaintWhite(SInt16 value) TWOWORDINLINE(0x31DF, 0x09DC);

  /**
   *  LMGetWMgrPort()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  GrafPtr LMGetWMgrPort(void) TWOWORDINLINE(0x2EB8, 0x09DE);

  /**
   *  LMSetWMgrPort()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetWMgrPort(GrafPtr value) TWOWORDINLINE(0x21DF, 0x09DE);

  /** Carbon Usage: use GetGrayRgn*/
  /**
   *  LMGetGrayRgn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  RgnHandle LMGetGrayRgn(void) TWOWORDINLINE(0x2EB8, 0x09EE);

  /**
   *  LMGetDragHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  DragGrayRgnUPP LMGetDragHook(void) TWOWORDINLINE(0x2EB8, 0x09F6);

  /**
   *  LMSetDragHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetDragHook(DragGrayRgnUPP value) TWOWORDINLINE(0x21DF, 0x09F6);

  /**
   *  LMSetWindowList()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetWindowList(WindowRef value) TWOWORDINLINE(0x21DF, 0x09D6);

  /**
   *  LMGetGhostWindow()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  WindowRef LMGetGhostWindow(void) TWOWORDINLINE(0x2EB8, 0x0A84);

  /**
   *  LMSetGhostWindow()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetGhostWindow(WindowRef value) TWOWORDINLINE(0x21DF, 0x0A84);

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
  AuxWinHandle LMGetAuxWinHead(void) TWOWORDINLINE(0x2EB8, 0x0CD0);

  /**
   *  LMSetAuxWinHead()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetAuxWinHead(AuxWinHandle value) TWOWORDINLINE(0x21DF, 0x0CD0);

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
  WindowRef LMGetCurActivate(void) TWOWORDINLINE(0x2EB8, 0x0A64);

  /**
   *  LMSetCurActivate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetCurActivate(WindowRef value) TWOWORDINLINE(0x21DF, 0x0A64);

  /**
   *  LMGetCurDeactive()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  WindowRef LMGetCurDeactive(void) TWOWORDINLINE(0x2EB8, 0x0A68);

  /**
   *  LMSetCurDeactive()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetCurDeactive(WindowRef value) TWOWORDINLINE(0x21DF, 0x0A68);

  /**
   *  LMGetOldStructure()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  RgnHandle LMGetOldStructure(void) TWOWORDINLINE(0x2EB8, 0x09E6);

  /**
   *  LMSetOldStructure()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetOldStructure(RgnHandle value) TWOWORDINLINE(0x21DF, 0x09E6);

  /**
   *  LMGetOldContent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  RgnHandle LMGetOldContent(void) TWOWORDINLINE(0x2EB8, 0x09EA);

  /**
   *  LMSetOldContent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetOldContent(RgnHandle value) TWOWORDINLINE(0x21DF, 0x09EA);

  /**
   *  LMSetGrayRgn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetGrayRgn(RgnHandle value) TWOWORDINLINE(0x21DF, 0x09EE);

  /**
   *  LMGetSaveVisRgn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  RgnHandle LMGetSaveVisRgn(void) TWOWORDINLINE(0x2EB8, 0x09F2);

  /**
   *  LMSetSaveVisRgn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSaveVisRgn(RgnHandle value) TWOWORDINLINE(0x21DF, 0x09F2);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetOneOne()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetOneOne(void) TWOWORDINLINE(0x2EB8, 0x0A02);

  /**
   *  LMSetOneOne()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetOneOne(SInt32 value) TWOWORDINLINE(0x21DF, 0x0A02);

  /**
   *  LMGetMinusOne()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32 LMGetMinusOne(void) TWOWORDINLINE(0x2EB8, 0x0A06);

  /**
   *  LMSetMinusOne()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetMinusOne(SInt32 value) TWOWORDINLINE(0x21DF, 0x0A06);

/** Carbon Usage: use GetMenuTrackingData*/
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetTopMenuItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetTopMenuItem(void) TWOWORDINLINE(0x3EB8, 0x0A0A);

  /** Carbon Usage: replaced by MDEF messages and GetMenuTrackingData API*/
  /**
   *  LMSetTopMenuItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTopMenuItem(SInt16 value) TWOWORDINLINE(0x31DF, 0x0A0A);

  /** Carbon Usage: use GetMenuTrackingData*/
  /**
   *  LMGetAtMenuBottom()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetAtMenuBottom(void) TWOWORDINLINE(0x3EB8, 0x0A0C);

  /** Carbon Usage: replaced by MDEF messages and GetMenuTrackingData API*/
  /**
   *  LMSetAtMenuBottom()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetAtMenuBottom(SInt16 value) TWOWORDINLINE(0x31DF, 0x0A0C);

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
  Handle LMGetMenuList(void) TWOWORDINLINE(0x2EB8, 0x0A1C);

  /**
   *  LMSetMenuList()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMenuList(Handle value) TWOWORDINLINE(0x21DF, 0x0A1C);

  /** Carbon usage: no replacement*/
  /**
   *  LMGetMBarEnable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetMBarEnable(void) TWOWORDINLINE(0x3EB8, 0x0A20);

  /**
   *  LMSetMBarEnable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMBarEnable(SInt16 value) TWOWORDINLINE(0x31DF, 0x0A20);

  /** Carbon usage: no replacement*/
  /**
   *  LMGetMenuFlash()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetMenuFlash(void) TWOWORDINLINE(0x3EB8, 0x0A24);

  /**
   *  LMSetMenuFlash()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMenuFlash(SInt16 value) TWOWORDINLINE(0x31DF, 0x0A24);

  /** LMGetTheMenu() moved to Menus.h */
  /**
   *  LMSetTheMenu()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTheMenu(SInt16 value) TWOWORDINLINE(0x31DF, 0x0A26);

  /**
   *  LMGetMBarHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MBarHookUPP LMGetMBarHook(void) TWOWORDINLINE(0x2EB8, 0x0A2C);

  /**
   *  LMSetMBarHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMBarHook(MBarHookUPP value) TWOWORDINLINE(0x21DF, 0x0A2C);

  /**
   *  LMGetMenuHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MenuHookUPP LMGetMenuHook(void) TWOWORDINLINE(0x2EB8, 0x0A30);

  /**
   *  LMSetMenuHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMenuHook(MenuHookUPP value) TWOWORDINLINE(0x21DF, 0x0A30);

  /**
   *  LMGetTopMapHndl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetTopMapHndl(void) TWOWORDINLINE(0x2EB8, 0x0A50);

  /**
   *  LMSetTopMapHndl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTopMapHndl(Handle value) TWOWORDINLINE(0x21DF, 0x0A50);

  /**
   *  LMGetSysMapHndl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetSysMapHndl(void) TWOWORDINLINE(0x2EB8, 0x0A54);

  /**
   *  LMSetSysMapHndl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSysMapHndl(Handle value) TWOWORDINLINE(0x21DF, 0x0A54);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetSysMap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetSysMap(void) TWOWORDINLINE(0x3EB8, 0x0A58);

  /**
   *  LMSetSysMap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSysMap(SInt16 value) TWOWORDINLINE(0x31DF, 0x0A58);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetCurMap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetCurMap(void) TWOWORDINLINE(0x3EB8, 0x0A5A);

  /**
   *  LMSetCurMap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetCurMap(SInt16 value) TWOWORDINLINE(0x31DF, 0x0A5A);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetResLoad()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetResLoad(void) TWOWORDINLINE(0x1EB8, 0x0A5E);

  /**
   *  LMSetResLoad()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetResLoad(UInt8 value) TWOWORDINLINE(0x11DF, 0x0A5E);

  /**
   *  LMGetResErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetResErr(void) TWOWORDINLINE(0x3EB8, 0x0A60);

  /**
   *  LMSetResErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetResErr(SInt16 value) TWOWORDINLINE(0x31DF, 0x0A60);

#if CALL_NOT_IN_CARBON
  /**
   *  LMGetFScaleDisable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetFScaleDisable(void) TWOWORDINLINE(0x1EB8, 0x0A63);

  /**
   *  LMSetFScaleDisable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetFScaleDisable(UInt8 value) TWOWORDINLINE(0x11DF, 0x0A63);

  /**
   *  LMGetDeskHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetDeskHook(void) TWOWORDINLINE(0x2EB8, 0x0A6C);

  /**
   *  LMSetDeskHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetDeskHook(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x0A6C);

  /** Carbon Usage: Use TEGetDoTextHook.*/
  /**
   *  LMGetTEDoText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetTEDoText(void) TWOWORDINLINE(0x2EB8, 0x0A70);

  /** Carbon Usage: Use TESetDoTextHook.*/
  /**
   *  LMSetTEDoText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetTEDoText(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x0A70);

  /** Carbon Usage: Use TEGetRecalcHook.*/
  /**
   *  LMGetTERecal()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetTERecal(void) TWOWORDINLINE(0x2EB8, 0x0A74);

  /** Carbon Usage: Use TESetRecalcHook.*/
  /**
   *  LMSetTERecal()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetTERecal(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x0A74);

  /**
   *  LMGetResumeProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr
  LMGetResumeProc(void) TWOWORDINLINE(0x2EB8, 0x0A8C);

  /**
   *  LMSetResumeProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetResumeProc(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x0A8C);

  /**
   *  LMGetANumber()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetANumber(void) TWOWORDINLINE(0x3EB8, 0x0A98);

  /**
   *  LMSetANumber()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetANumber(SInt16 value) TWOWORDINLINE(0x31DF, 0x0A98);

  /** Carbon Usage: Use GetAlertStage.*/
  /**
   *  LMGetACount()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetACount(void) TWOWORDINLINE(0x3EB8, 0x0A9A);

  /** Carbon Usage: Use ResetAlertStage.*/
  /**
   *  LMSetACount()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetACount(SInt16 value) TWOWORDINLINE(0x31DF, 0x0A9A);

  /**
   *  LMGetDABeeper()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetDABeeper(void) TWOWORDINLINE(0x2EB8, 0x0A9C);

  /**
   *  LMSetDABeeper()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetDABeeper(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x0A9C);

  /** Carbon Usage: use TEGetScrapLength*/
  /**
   *  LMGetTEScrpLength()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt16 LMGetTEScrpLength(void) TWOWORDINLINE(0x3EB8, 0x0AB0);

  /** Carbon Usage: use TESetScrapLength*/
  /**
   *  LMSetTEScrpLength()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTEScrpLength(UInt16 value) TWOWORDINLINE(0x31DF, 0x0AB0);

  /** Carbon Usage: use TEGetScrapHandle*/
  /**
   *  LMGetTEScrpHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetTEScrpHandle(void) TWOWORDINLINE(0x2EB8, 0x0AB4);

  /** Carbon Usage: use TESetScrapHandle*/
  /**
   *  LMSetTEScrpHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTEScrpHandle(Handle value) TWOWORDINLINE(0x21DF, 0x0AB4);

  /**
   *  LMGetAppParmHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetAppParmHandle(void) TWOWORDINLINE(0x2EB8, 0x0AEC);

  /**
   *  LMSetAppParmHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetAppParmHandle(Handle value) TWOWORDINLINE(0x21DF, 0x0AEC);

  /**
   *  LMGetDSErrCode()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetDSErrCode(void) TWOWORDINLINE(0x3EB8, 0x0AF0);

  /**
   *  LMSetDSErrCode()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetDSErrCode(SInt16 value) TWOWORDINLINE(0x31DF, 0x0AF0);

  /**
   *  LMGetResErrProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ResErrUPP LMGetResErrProc(void) TWOWORDINLINE(0x2EB8, 0x0AF2);

  /**
   *  LMSetResErrProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetResErrProc(ResErrUPP value) TWOWORDINLINE(0x21DF, 0x0AF2);

  /**
   *  LMGetDlgFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetDlgFont(void) TWOWORDINLINE(0x3EB8, 0x0AFA);

  /** Carbon Usage: use SetDialogFont*/
  /**
   *  LMSetDlgFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetDlgFont(SInt16 value) TWOWORDINLINE(0x31DF, 0x0AFA);

  /**
   *  LMGetATalkHk2()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr LMGetATalkHk2(void) TWOWORDINLINE(0x2EB8, 0x0B18);

  /**
   *  LMSetATalkHk2()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetATalkHk2(Ptr value) TWOWORDINLINE(0x21DF, 0x0B18);

  /**
   *  LMGetHWCfgFlags()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetHWCfgFlags(void) TWOWORDINLINE(0x3EB8, 0x0B22);

  /**
   *  LMSetHWCfgFlags()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetHWCfgFlags(SInt16 value) TWOWORDINLINE(0x31DF, 0x0B22);

  /** Carbon Usage: use GetMenuTrackingData*/
  /**
   *  LMGetMenuDisable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt32 LMGetMenuDisable(void) TWOWORDINLINE(0x2EB8, 0x0B54);

  /** Carbon Usage: use new MDEF messages*/
  /**
   *  LMSetMenuDisable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMenuDisable(SInt32 value) TWOWORDINLINE(0x21DF, 0x0B54);

  /**
   *  LMGetROMMapInsert()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetROMMapInsert(void) TWOWORDINLINE(0x1EB8, 0x0B9E);

  /**
   *  LMSetROMMapInsert()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetROMMapInsert(UInt8 value) TWOWORDINLINE(0x11DF, 0x0B9E);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetTmpResLoad()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt8 LMGetTmpResLoad(void) TWOWORDINLINE(0x1EB8, 0x0B9F);

  /**
   *  LMSetTmpResLoad()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetTmpResLoad(UInt8 value) TWOWORDINLINE(0x11DF, 0x0B9F);

  /**
   *  LMGetIntlSpec()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetIntlSpec(void) TWOWORDINLINE(0x2EB8, 0x0BA0);

  /**
   *  LMSetIntlSpec()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetIntlSpec(Ptr value) TWOWORDINLINE(0x21DF, 0x0BA0);

  /** LMGetWordRedraw and LMSetWordRedraw moved to TextEdit.h */
  /**
   *  LMGetSysFontFam()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetSysFontFam(void) TWOWORDINLINE(0x3EB8, 0x0BA6);

  /**
   *  LMSetSysFontFam()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSysFontFam(SInt16 value) TWOWORDINLINE(0x31DF, 0x0BA6);

  /**
   *  LMGetSysFontSize()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16 LMGetSysFontSize(void) TWOWORDINLINE(0x3EB8, 0x0BA8);

  /**
   *  LMSetSysFontSize()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetSysFontSize(SInt16 value) TWOWORDINLINE(0x31DF, 0x0BA8);

/** Carbon Usge: use GetMBarHeight*/
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetMBarHeight()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetMBarHeight(void) TWOWORDINLINE(0x3EB8, 0x0BAA);

  /** Carbon Usage: use Hide/ShowMenuBar*/
  /**
   *  LMSetMBarHeight()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMBarHeight(SInt16 value) TWOWORDINLINE(0x31DF, 0x0BAA);

  /**
   *  LMGetTESysJust()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetTESysJust(void) TWOWORDINLINE(0x3EB8, 0x0BAC);

  /**
   *  LMSetTESysJust()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTESysJust(SInt16 value) TWOWORDINLINE(0x31DF, 0x0BAC);

  /**
   *  LMGetMMU32Bit()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetMMU32Bit(void) TWOWORDINLINE(0x1EB8, 0x0CB2);

  /**
   *  LMSetMMU32Bit()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMMU32Bit(UInt8 value) TWOWORDINLINE(0x11DF, 0x0CB2);

  /**
   *  LMGetDeskCPat()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  PixPatHandle LMGetDeskCPat(void) TWOWORDINLINE(0x2EB8, 0x0CD8);

  /**
   *  LMSetDeskCPat()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetDeskCPat(PixPatHandle value) TWOWORDINLINE(0x21DF, 0x0CD8);

  /**
   *  LMGetTimeDBRA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetTimeDBRA(void) TWOWORDINLINE(0x3EB8, 0x0D00);

  /**
   *  LMSetTimeDBRA()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTimeDBRA(SInt16 value) TWOWORDINLINE(0x31DF, 0x0D00);

  /**
   *  LMGetTimeSCCDB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetTimeSCCDB(void) TWOWORDINLINE(0x3EB8, 0x0D02);

  /**
   *  LMSetTimeSCCDB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTimeSCCDB(SInt16 value) TWOWORDINLINE(0x31DF, 0x0D02);

  /**
   *  LMGetJVBLTask()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr LMGetJVBLTask(void) TWOWORDINLINE(0x2EB8, 0x0D28);

  /**
   *  LMSetJVBLTask()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetJVBLTask(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x0D28);

  /**
   *  LMGetSynListHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetSynListHandle(void) TWOWORDINLINE(0x2EB8, 0x0D32);

  /**
   *  LMSetSynListHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetSynListHandle(Handle value) TWOWORDINLINE(0x21DF, 0x0D32);

  /**
   *  LMGetMenuCInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MCTableHandle LMGetMenuCInfo(void) TWOWORDINLINE(0x2EB8, 0x0D50);

  /**
   *  LMSetMenuCInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetMenuCInfo(MCTableHandle value) TWOWORDINLINE(0x21DF, 0x0D50);

  /**
   *  LMGetJDTInstall()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UniversalProcPtr
  LMGetJDTInstall(void) TWOWORDINLINE(0x2EB8, 0x0D9C);

  /**
   *  LMSetJDTInstall()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetJDTInstall(UniversalProcPtr value) TWOWORDINLINE(0x21DF, 0x0D9C);

  /**
   *  LMGetTimeSCSIDB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16 LMGetTimeSCSIDB(void) TWOWORDINLINE(0x3EB8, 0x0B24);

  /**
   *  LMSetTimeSCSIDB()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetTimeSCSIDB(SInt16 value) TWOWORDINLINE(0x31DF, 0x0B24);

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
  void LMSetMouseTemp(Point value) TWOWORDINLINE(0x21DF, 0x0828);

  /** accesses "MTemp"*/
  /**
   *  LMGetMouseTemp()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Point LMGetMouseTemp(void) TWOWORDINLINE(0x2EB8, 0x0828);

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
  UInt8 LMGetMouseButtonState(void) TWOWORDINLINE(0x1EB8, 0x0172);

  /**
   *  LMSetMouseButtonState()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetMouseButtonState(UInt8 value) TWOWORDINLINE(0x11DF, 0x0172);

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
  Point LMGetRawMouseLocation(void) TWOWORDINLINE(0x2EB8, 0x082C);

  /** Carbon Usage: use GetGlobalMouse*/
  /**
   *  LMSetRawMouseLocation()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetRawMouseLocation(Point value) TWOWORDINLINE(0x21DF, 0x082C);

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
  Point LMGetMouseLocation(void) TWOWORDINLINE(0x2EB8, 0x0830);

  /**
   *  LMSetMouseLocation()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMouseLocation(Point value) TWOWORDINLINE(0x21DF, 0x0830);

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
  Ptr LMGetHighHeapMark(void) TWOWORDINLINE(0x2EB8, 0x0BAE);

  /**
   *  LMSetHighHeapMark()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetHighHeapMark(Ptr value) TWOWORDINLINE(0x21DF, 0x0BAE);

  /** accesses "StkLowPt"*/
  /**
   *  LMGetStackLowPoint()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetStackLowPoint(void) TWOWORDINLINE(0x2EB8, 0x0110);

  /**
   *  LMSetStackLowPoint()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetStackLowPoint(Ptr value) TWOWORDINLINE(0x21DF, 0x0110);

/** accesses "ROMMapHndl"*/
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetROMMapHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle LMGetROMMapHandle(void) TWOWORDINLINE(0x2EB8, 0x0B06);

  /**
   *  LMSetROMMapHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetROMMapHandle(Handle value) TWOWORDINLINE(0x21DF, 0x0B06);

  /** accesses "UnitNtryCnt"*/
  /**
   *  LMGetUnitTableEntryCount()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short LMGetUnitTableEntryCount(void) TWOWORDINLINE(0x3EB8, 0x01D2);

  /**
   *  LMSetUnitTableEntryCount()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LMSetUnitTableEntryCount(short value) TWOWORDINLINE(0x31DF, 0x01D2);

/** accesses "FmtDefaults"*/
#endif /** CALL_NOT_IN_CARBON */

  /**
   *  LMGetDiskFormatingHFSDefaults()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Ptr LMGetDiskFormatingHFSDefaults(void) TWOWORDINLINE(0x2EB8, 0x039E);

  /**
   *  LMSetDiskFormatingHFSDefaults()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  LMSetDiskFormatingHFSDefaults(Ptr value) TWOWORDINLINE(0x21DF, 0x039E);

/** accesses "PortAUse"*/
#if CALL_NOT_IN_CARBON
  /**
   *  LMGetPortAInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8 LMGetPortAInfo(void) TWOWORDINLINE(0x1EB8, 0x0290);

  /**
   *  LMSetPortAInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetPortAInfo(UInt8 value) TWOWORDINLINE(0x11DF, 0x0290);

  /**
   *  LMGetMBTicks()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long LMGetMBTicks(void) TWOWORDINLINE(0x2EB8, 0x016E);

  /**
   *  LMSetMBTicks()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetMBTicks(long value) TWOWORDINLINE(0x21DF, 0x016E);

  /**
   *  LMGetKeyTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long LMGetKeyTime(void) TWOWORDINLINE(0x2EB8, 0x0186);

  /**
   *  LMSetKeyTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void LMSetKeyTime(long value) TWOWORDINLINE(0x21DF, 0x0186);

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
