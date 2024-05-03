/**
     \file       TextServices.h

    \brief   Text Services Manager Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1991-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Font

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __TEXTSERVICES__
#define __TEXTSERVICES__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __MENUS__
#include <Menus.h>
#endif

#ifndef __AEDATAMODEL__
#include <AEDataModel.h>
#endif

#ifndef __AEREGISTRY__
#include <AERegistry.h>
#endif

#ifndef __AEINTERACTION__
#include <AEInteraction.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __CARBONEVENTS__
#include <CarbonEvents.h>
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
        kTextService = FOUR_CHAR_CODE(
            'tsvc'), /** component type for the component description */
        kInputMethodService = FOUR_CHAR_CODE(
            'inpm'),         /** component subtype for the component description */
        kTSMVersion = 0x0150 /** Version of the Text Services Manager is 1.5 */
    };

    enum
    {
        kUnicodeDocument = FOUR_CHAR_CODE(
            'udoc'), /** TSM Document type for Unicode-savvy application */
        kUnicodeTextService =
            FOUR_CHAR_CODE('utsv') /** Component type for Unicode Text Service */
    };

    /** Language and Script constants*/
    enum
    {
        kUnknownLanguage = 0xFFFF,
        kUnknownScript = 0xFFFF,
        kNeutralScript = 0xFFFF
    };

    enum
    {
        /** Component Flags in ComponentDescription */
        bTakeActiveEvent = 15,                            /** bit set if the component takes active event */
        bHandleAERecording = 16,                          /** bit set if the component takes care of recording
                                                             Apple Events <new in vers2.0> */
        bScriptMask = 0x00007F00,                         /** bit 8 - 14 */
        bLanguageMask = 0x000000FF,                       /** bit 0 - 7  */
        bScriptLanguageMask = bScriptMask + bLanguageMask /** bit 0 - 14  */
    };

    enum
    {
        /** Typing method property constants for Input Methods */
        kIMJaTypingMethodProperty = FOUR_CHAR_CODE(
            'jtyp'),                                     /** Typing method property for Japanese input methods*/
        kIMJaTypingMethodRoman = FOUR_CHAR_CODE('roma'), /** Roman typing*/
        kIMJaTypingMethodKana = FOUR_CHAR_CODE('kana')   /** Kana typing*/
    };

    enum
    {
        /** Low level routines which are dispatched directly to the Component Manager
         */
        kCMGetScriptLangSupport = 0x0001,   /** Component Manager call selector 1 */
        kCMInitiateTextService = 0x0002,    /** Component Manager call selector 2 */
        kCMTerminateTextService = 0x0003,   /** Component Manager call selector 3 */
        kCMActivateTextService = 0x0004,    /** Component Manager call selector 4 */
        kCMDeactivateTextService = 0x0005,  /** Component Manager call selector 5 */
        kCMTextServiceEvent = 0x0006,       /** Component Manager call selector 6 */
        kCMGetTextServiceMenu = 0x0007,     /** Component Manager call selector 7 */
        kCMTextServiceMenuSelect = 0x0008,  /** Component Manager call selector 8 */
        kCMFixTextService = 0x0009,         /** Component Manager call selector 9 */
        kCMSetTextServiceCursor = 0x000A,   /** Component Manager call selector 10 */
        kCMHidePaletteWindows = 0x000B,     /** Component Manager call selector 11 */
        kCMGetTextServiceProperty = 0x000C, /** Component Manager call selector 12 */
        kCMSetTextServiceProperty = 0x000D  /** Component Manager call selector 13 */
    };

    enum
    {
        /** New low level routines which are dispatched directly to the Component
           Manager */
        kCMUCTextServiceEvent = 0x000E /** Component Manager call selector 14 */
    };

/** extract Script/Language code from Component flag ... */
#define mGetScriptCode(cdRec) \
    ((ScriptCode)((cdRec.componentFlags & bScriptMask) >> 8))
#define mGetLanguageCode(cdRec) ((LangCode)cdRec.componentFlags & bLanguageMask)

    /** New opaque definitions for types */
    typedef struct OpaqueTSMDocumentID *TSMDocumentID;
    typedef OSType InterfaceTypeList[1];

    /** Text Service Info List */
    struct TextServiceInfo
    {
        Component fComponent;
        Str255 fItemName;
    };
    typedef struct TextServiceInfo TextServiceInfo;
    typedef TextServiceInfo *TextServiceInfoPtr;
    struct TextServiceList
    {
        short fTextServiceCount; /** number of entries in the 'fServices' array */
        TextServiceInfo
            fServices[1]; /** Note: array of 'TextServiceInfo' records follows */
    };
    typedef struct TextServiceList TextServiceList;
    typedef TextServiceList *TextServiceListPtr;
    typedef TextServiceListPtr *TextServiceListHandle;
    struct ScriptLanguageRecord
    {
        ScriptCode fScript;
        LangCode fLanguage;
    };
    typedef struct ScriptLanguageRecord ScriptLanguageRecord;
    struct ScriptLanguageSupport
    {
        short fScriptLanguageCount; /** number of entries in the
                                       'fScriptLanguageArray' array */
        ScriptLanguageRecord
            fScriptLanguageArray[1]; /** Note: array of 'ScriptLanguageRecord' records
                                        follows */
    };
    typedef struct ScriptLanguageSupport ScriptLanguageSupport;
    typedef ScriptLanguageSupport *ScriptLanguageSupportPtr;
    typedef ScriptLanguageSupportPtr *ScriptLanguageSupportHandle;
    /** High level TSM Doucment routines */
    /**
     *  NewTSMDocument()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    NewTSMDocument(short numOfInterface, InterfaceTypeList supportedInterfaceTypes,
                   TSMDocumentID *idocID, long refcon);

    /**
     *  DeleteTSMDocument()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    DeleteTSMDocument(TSMDocumentID idocID);

    /**
     *  ActivateTSMDocument()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    ActivateTSMDocument(TSMDocumentID idocID);

    /**
     *  DeactivateTSMDocument()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    DeactivateTSMDocument(TSMDocumentID idocID);

    /**
     *  FixTSMDocument()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FixTSMDocument(TSMDocumentID idocID);

    /**
     *  GetServiceList()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    GetServiceList(short numOfInterface, OSType *supportedInterfaceTypes,
                   TextServiceListHandle *serviceInfo, long *seedValue);

    /**
     *  OpenTextService()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    OpenTextService(TSMDocumentID idocID, Component aComponent,
                    ComponentInstance *aComponentInstance);

    /**
     *  CloseTextService()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    CloseTextService(TSMDocumentID idocID, ComponentInstance aComponentInstance);

    /**
     *  SendAEFromTSMComponent()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SendAEFromTSMComponent(const AppleEvent *theAppleEvent, AppleEvent *reply,
                           AESendMode sendMode, AESendPriority sendPriority,
                           long timeOutInTicks, AEIdleUPP idleProc,
                           AEFilterUPP filterProc);

    /**
     *  SendTextInputEvent()
     *
     *  Discussion:
     *    This API replaces SendAEFromTSMComponent on Mac OS X only. Input
     *    Methods on Mac OS X are Carbon Event based instead of AppleEvent
     *    based.  The Carbon TextInput events which they generate are
     *    provided to TSM for dispatching via this API.
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib N.e.v.e.r and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSStatus
    SendTextInputEvent(EventRef inEvent);

    /**
     *  SetDefaultInputMethod()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SetDefaultInputMethod(Component ts, ScriptLanguageRecord *slRecordPtr);

    /**
     *  GetDefaultInputMethod()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    GetDefaultInputMethod(Component *ts, ScriptLanguageRecord *slRecordPtr);

    /**
     *  SetTextServiceLanguage()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SetTextServiceLanguage(ScriptLanguageRecord *slRecordPtr);

    /**
     *  GetTextServiceLanguage()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    GetTextServiceLanguage(ScriptLanguageRecord *slRecordPtr);

    /**
     *  UseInputWindow()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    UseInputWindow(TSMDocumentID idocID, Boolean useWindow);

    /**
     *  TSMSetInlineInputRegion()
     *
     *  Discussion:
     *    Tell TSM about the region occupied by an inline input session. If
     *    the location of certain mouse events (clicks, mouse moved) occur
     *    within the specified inline input region, TSM will forward these
     *    events to the current Input Method so that it can interact with
     *    the user. Note: If you do not specify this information, TSM will
     *    need to intercept mouse events in the entire content region as
     *    the default, when an input method is active, in order to ensure
     *    that input methods can manage user interaction properly.
     *
     *  Parameters:
     *
     *    inTSMDocument:
     *      The document.
     *
     *    inWindow:
     *      The window that contains the inline input session. You can pass
     *      NULL for this parameter to indicate the user focus window.
     *
     *    inRegion:
     *      The region occupied by the current inline input region. This
     *      should be in the coordinates of the port associated with the
     *      window you passed to inPort. It will need to be recomputed when
     *      the text content of the inline input session content changes
     *      (i.e. due to Update Active Input Area events) and when the
     *      region moves for other reasons, such as window resized,
     *      scrolling, etc. If you pass a NULL region for this parameter,
     *      TSM will default to intercept mouse events in the focus
     *      window's content region.
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSStatus
    TSMSetInlineInputRegion(TSMDocumentID inTSMDocument, WindowRef inWindow,
                            RgnHandle inRegion);

/** Following calls from Classic event loops not needed for Carbon clients. */
#if CALL_NOT_IN_CARBON
    /**
     *  TSMEvent()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    TSMEvent(EventRecord *event);

    /**
     *  TSMMenuSelect()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    TSMMenuSelect(long menuResult);

    /**
     *  SetTSMCursor()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    SetTSMCursor(Point mousePos);

    /** Following ServiceWindow API replaced by Window Manager API in Carbon. */
    /**
     *  NewServiceWindow()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    NewServiceWindow(void *wStorage, const Rect *boundsRect, ConstStr255Param title,
                     Boolean visible, short theProc, WindowRef behind,
                     Boolean goAwayFlag, ComponentInstance ts, WindowRef *window);

    /**
     *  CloseServiceWindow()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    CloseServiceWindow(WindowRef window);

    /**
     *  GetFrontServiceWindow()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    GetFrontServiceWindow(WindowRef *window);

    /**
     *  FindServiceWindow()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    FindServiceWindow(Point thePoint, WindowRef *theWindow);

    /**
     *  NewCServiceWindow()
     *

     *    \non_carbon_cfm   in InterfaceLib 8.5 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    NewCServiceWindow(void *wStorage, const Rect *boundsRect,
                      ConstStr255Param title, Boolean visible, short theProc,
                      WindowRef behind, Boolean goAwayFlag, ComponentInstance ts,
                      WindowRef *window);

    /** Explicit initialization not needed for Carbon clients, since TSM is */
    /** instanciated per-context. */
    /**
     *  InitTSMAwareApplication()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    InitTSMAwareApplication(void);

    /**
     *  CloseTSMAwareApplication()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    CloseTSMAwareApplication(void);

/** Component Manager Interfaces to Input Methods */
#endif /** CALL_NOT_IN_CARBON */

    /**
     *  GetScriptLanguageSupport()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    GetScriptLanguageSupport(ComponentInstance ts,
                             ScriptLanguageSupportHandle *scriptHdl);

    /**
     *  InitiateTextService()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InitiateTextService(ComponentInstance ts);

    /**
     *  TerminateTextService()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    TerminateTextService(ComponentInstance ts);

    /**
     *  ActivateTextService()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    ActivateTextService(ComponentInstance ts);

    /**
     *  DeactivateTextService()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    DeactivateTextService(ComponentInstance ts);

    /**
     *  GetTextServiceMenu()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    GetTextServiceMenu(ComponentInstance ts, MenuRef *serviceMenu);

    /** New Text Service call in Carbon. */
    /** Note: Only Raw Key and Mouse-flavored events are passed to Text Services on
     * MacOS X. */
    /**
     *  TextServiceEventRef()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    TextServiceEventRef(ComponentInstance ts, EventRef event);

#if CALL_NOT_IN_CARBON
    /**
     *  TextServiceEvent()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    TextServiceEvent(ComponentInstance ts, short numOfEvents, EventRecord *event);

    /**
     *  UCTextServiceEvent()
     *

     *    \non_carbon_cfm   in InterfaceLib 8.5 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    UCTextServiceEvent(ComponentInstance ts, short numOfEvents, EventRecord *event,
                       UniChar unicodeString[], UniCharCount unicodeStrLength);

    /**
     *  TextServiceMenuSelect()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    TextServiceMenuSelect(ComponentInstance ts, MenuRef serviceMenu, short item);

    /**
     *  SetTextServiceCursor()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    SetTextServiceCursor(ComponentInstance ts, Point mousePos);

#endif /** CALL_NOT_IN_CARBON */

    /**
     *  FixTextService()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    FixTextService(ComponentInstance ts);

    /**
     *  HidePaletteWindows()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    HidePaletteWindows(ComponentInstance ts);

    /**
     *  GetTextServiceProperty()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    GetTextServiceProperty(ComponentInstance ts, OSType propertySelector,
                           SInt32 *result);

    /**
     *  SetTextServiceProperty()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SetTextServiceProperty(ComponentInstance ts, OSType propertySelector,
                           SInt32 value);

    /** Get the active TSMDocument in the current application context.       */
    /** If TSM has enabled bottom line input mode because no TSMDocument     */
    /** is active, NULL will be returned.                                    */
    /**
     *  TSMGetActiveDocument()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    TSMDocumentID
    TSMGetActiveDocument(void);

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

#endif /** __TEXTSERVICES__ */
