/**
     \file       ControlStrip.h

    \brief   Control Strip (for Powerbooks and Duos) Interfaces.

    \introduced_in  ControlStrip 1.4
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1992-2001 by Apple Computer, Inc. All rights reserved.

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CONTROLSTRIP__
#define __CONTROLSTRIP__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MENUS__
#include <Menus.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
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

    /**********************************************************************************************

        messages passed to the modules

    *********************************************************************************************/
    enum
    {
        sdevInitModule = 0,      /** initialize the module*/
        sdevCloseModule = 1,     /** clean up before being closed*/
        sdevFeatures = 2,        /** return feature bits*/
        sdevGetDisplayWidth = 3, /** returns the width of the module's display*/
        sdevPeriodicTickle = 4,  /** periodic tickle when nothing else is happening*/
        sdevDrawStatus = 5,      /** update the interface in the Control Strip*/
        sdevMouseClick =
            6, /** user clicked on the module's display area in the Control Strip*/
        sdevSaveSettings =
            7, /** saved any changed settings in module's preferences file*/
        sdevShowBalloonHelp =
            8 /** puts up a help balloon, if the module has one to display*/
    };

    /**********************************************************************************************

        Features supported by the module.  If a bit is set, it means that feature is
    supported. All undefined bits are reserved for future use by Apple, and should
    be set to zero.

    *********************************************************************************************/
    enum
    {
        sdevWantMouseClicks = 0, /** notify the module of mouseDown events*/
        sdevDontAutoTrack = 1,   /** call the module to do mouse tracking*/
        sdevHasCustomHelp = 2,   /** module provides its own help messages*/
        sdevKeepModuleLocked = 3 /** module needs to be locked in the heap*/
    };

    /**********************************************************************************************

        Result values returned by the sdevPeriodicTickle and sdevIconMouseClick
    selectors. If a bit is set, the module can request that a specific function is
    performed by the Control Strip.  A result of zero will do nothing.  All
    undefined bits are reserved for future use by Apple, and should be set to zero.

    *********************************************************************************************/
    enum
    {
        sdevResizeDisplay = 0, /** resize the module's display*/
        sdevNeedToSave = 1,    /** need to save changed settings, when convenient*/
        sdevHelpStateChange =
            2,           /** need to update the help message because of a state change*/
        sdevCloseNow = 3 /** close a module because it doesn't want to stay around*/
    };

    /**********************************************************************************************

        miscellaneous

    *********************************************************************************************/
    enum
    {
        sdevFileType = FOUR_CHAR_CODE('sdev') /** module's file type*/
    };

    enum
    {
        sdevMenuItemMark = 0xA5 /** ԥ©: ©checkmark© to use in popup menus*/
    };

    /**  direction values for SBDrawBarGraph*/

    enum
    {
        BarGraphSlopeLeft = -1, /** max end of sloping bar graph is on the left*/
        BarGraphFlatRight = 0,  /** max end of flat bar graph is on the right*/
        BarGraphSlopeRight = 1  /** max end of sloping bar graph is on the right*/
    };

/**********************************************************************************************

    utility routines to provide standard interface elements and support for
common functions

*********************************************************************************************/
#if CALL_NOT_IN_CARBON
    /**
     *  SBIsControlStripVisible()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    SBIsControlStripVisible(void);

    /**
     *  SBShowHideControlStrip()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    SBShowHideControlStrip(Boolean showIt);

    /**
     *  SBSafeToAccessStartupDisk()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    SBSafeToAccessStartupDisk(void);

    /**
     *  SBOpenModuleResourceFile()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    SBOpenModuleResourceFile(OSType fileCreator);

    /**
     *  SBLoadPreferences()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBLoadPreferences(ConstStr255Param prefsResourceName, Handle *preferences);

    /**
     *  SBSavePreferences()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBSavePreferences(ConstStr255Param prefsResourceName, Handle preferences);

    /**
     *  SBGetDetachedIndString()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    SBGetDetachedIndString(StringPtr theString, Handle stringList,
                           short whichString);

    /**
     *  SBGetDetachIconSuite()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBGetDetachIconSuite(Handle *theIconSuite, short theResID,
                         unsigned long selector);

    /**
     *  SBTrackPopupMenu()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    SBTrackPopupMenu(const Rect *moduleRect, MenuRef theMenu);

    /**
     *  SBTrackSlider()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    SBTrackSlider(const Rect *moduleRect, short ticksOnSlider, short initialValue);

    /**
     *  SBShowHelpString()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBShowHelpString(const Rect *moduleRect, StringPtr helpString);

    /**
     *  SBGetBarGraphWidth()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    SBGetBarGraphWidth(short barCount);

    /**
     *  SBDrawBarGraph()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    SBDrawBarGraph(short level, short barCount, short direction,
                   Point barGraphTopLeft);

    /**
     *  SBModalDialogInContext()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    SBModalDialogInContext(ModalFilterUPP filterProc, short *itemHit);

    /** The following routines are available in Control Strip 1.2 and later. */
    /**
     *  SBGetControlStripFontID()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.2 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBGetControlStripFontID(short *fontID);

    /**
     *  SBSetControlStripFontID()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.2 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBSetControlStripFontID(short fontID);

    /**
     *  SBGetControlStripFontSize()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.2 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBGetControlStripFontSize(short *fontSize);

    /**
     *  SBSetControlStripFontSize()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.2 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBSetControlStripFontSize(short fontSize);

    /**
     *  SBGetShowHideHotKey()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.2 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBGetShowHideHotKey(short *modifiers, unsigned char *keyCode);

    /**
     *  SBSetShowHideHotKey()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.2 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBSetShowHideHotKey(short modifiers, unsigned char keyCode);

    /**
     *  SBIsShowHideHotKeyEnabled()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.2 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBIsShowHideHotKeyEnabled(Boolean *enabled);

    /**
     *  SBEnableShowHideHotKey()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.2 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SBEnableShowHideHotKey(Boolean enabled);

    /** The following routines are available in Control Strip 1.4 and later. */
    /**
     *  SBHitTrackSlider()
     *

     *    \non_carbon_cfm   in ControlStripLib 1.4 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    SBHitTrackSlider(const Rect *moduleRect, short ticksOnSlider,
                     short initialValue, Boolean *hit);

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

#endif /** __CONTROLSTRIP__ */
