
#ifndef __CARBONEVENTS__
#define __CARBONEVENTS__

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __MENUS__
#include <Menus.h>
#endif

#ifndef __CONTROLS__
#include <Controls.h>
#endif

#ifndef __MACWINDOWS__
#include <MacWindows.h>
#endif

#ifndef __CFSTRING__
#include <CFString.h>
#endif

#ifndef __AEREGISTRY__
#include <AERegistry.h>
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

    /*======================================================================================*/
    /* EVENT COMMON */
    /*======================================================================================*/

    enum
    {

        eventAlreadyPostedErr = -9860,

        eventTargetBusyErr = -9861,

        eventClassInvalidErr = -9862,

        eventClassIncorrectErr = -9864,

        eventHandlerAlreadyInstalledErr = -9866,

        eventInternalErr = -9868,

        eventKindIncorrectErr = -9869,

        eventParameterNotFoundErr = -9870,

        eventNotHandledErr = -9874,

        eventLoopTimedOutErr = -9875,

        eventLoopQuitErr = -9876,

        eventNotInQueueErr = -9877,
        eventHotKeyExistsErr = -9878,
        eventHotKeyInvalidErr = -9879
    };

    /*======================================================================================*/
    /* EVENT CORE */
    /*======================================================================================*/
    /*��������������������������������������������������������������������������������������*/
    /* � Event Flags, options */
    /*��������������������������������������������������������������������������������������*/

    typedef SInt16 EventPriority;
    enum
    {

        kEventPriorityLow = 0,

        kEventPriorityStandard = 1,

        kEventPriorityHigh = 2
    };

    enum
    {
        kEventLeaveInQueue = false,
        kEventRemoveFromQueue = true
    };

    /*��������������������������������������������������������������������������������������*/
    /* � Event Times */
    /* */
    /* EventTime is in seconds since boot. Use the constants to make life easy. */
    /*��������������������������������������������������������������������������������������*/
    typedef double EventTime;
    typedef EventTime EventTimeout;
    typedef EventTime EventTimerInterval;
#define kEventDurationSecond ((EventTime)1.0)
#define kEventDurationMillisecond ((EventTime)(kEventDurationSecond / 1000))
#define kEventDurationMicrosecond ((EventTime)(kEventDurationSecond / 1000000))
#define kEventDurationNanosecond \
    ((EventTime)(kEventDurationSecond / 1000000000))
#define kEventDurationMinute ((EventTime)(kEventDurationSecond * 60))
#define kEventDurationHour ((EventTime)(kEventDurationMinute * 60))
#define kEventDurationDay ((EventTime)(kEventDurationHour * 24))
#define kEventDurationNoWait ((EventTime)0.0)
#define kEventDurationForever ((EventTime)(-1.0))

/* Helpful doodads to convert to and from ticks and event times*/
#ifdef __cplusplus
    inline EventTime TicksToEventTime(UInt32 t) { return ((t) / 60.0); }
    inline UInt32 EventTimeToTicks(EventTime t)
    {
        return (UInt32)(((t) * 60) + 0.5);
    }
#else
#define TicksToEventTime(t) ((EventTime)((t) / 60.0))
#define EventTimeToTicks(t) ((UInt32)(((t) * 60) + 0.5))
#endif /* defined(__cplusplus) */

    /*��������������������������������������������������������������������������������������*/
    /* EventTypeSpec structure */
    /* */
    /* This structure is used in many routines to pass a list of event types to a
     * function. */
    /* You typically would declare a const array of these types to pass in. */
    /*��������������������������������������������������������������������������������������*/

    struct EventTypeSpec
    {
        UInt32 eventClass;
        UInt32 eventKind;
    };
    typedef struct EventTypeSpec EventTypeSpec;
/*A helpful macro for dealing with EventTypeSpecs */
#define GetEventTypeCount(t) (sizeof((t)) / sizeof(EventTypeSpec))

    enum
    {
        kTrackMouseLocationOptionDontConsumeMouseUp = (1 << 0)
    };

    typedef UInt16 MouseTrackingResult;
    enum
    {
        kMouseTrackingMouseDown = 1,
        kMouseTrackingMouseUp = 2,
        kMouseTrackingMouseExited = 3,
        kMouseTrackingMouseEntered = 4,
        kMouseTrackingMouseDragged = 5,
        kMouseTrackingKeyModifiersChanged = 6,
        kMouseTrackingUserCancelled = 7,
        kMouseTrackingTimedOut = 8
    };

    typedef OSType EventParamName;
    typedef OSType EventParamType;
    /*��������������������������������������������������������������������������������������*/
    /* � EventLoop */
    /*��������������������������������������������������������������������������������������*/

    typedef struct OpaqueEventLoopRef *EventLoopRef;
    EXTERN_API(EventLoopRef)
    GetCurrentEventLoop(void);

    EXTERN_API(EventLoopRef)
    GetMainEventLoop(void);

    EXTERN_API(OSStatus)
    RunCurrentEventLoop(EventTimeout inTimeout);

    EXTERN_API(OSStatus)
    QuitEventLoop(EventLoopRef inEventLoop);

    EXTERN_API_C(CFTypeRef)
    GetCFRunLoopFromEventLoop(EventLoopRef inEventLoop);

    /*��������������������������������������������������������������������������������������*/
    /* � Low-level event fetching */
    /*��������������������������������������������������������������������������������������*/
    EXTERN_API(OSStatus)
    ReceiveNextEvent(UInt32 inNumTypes, const EventTypeSpec *inList,
                     EventTimeout inTimeout, Boolean inPullEvent,
                     EventRef *outEvent);

    /*��������������������������������������������������������������������������������������*/
    /* � Core event lifetime APIs */
    /*��������������������������������������������������������������������������������������*/
    typedef UInt32 EventAttributes;
    enum
    {
        kEventAttributeNone = 0,
        kEventAttributeUserEvent = (1 << 0)
    };

#if TARGET_OS_MAC
#define MacCreateEvent CreateEvent
#endif
    EXTERN_API(OSStatus)
    MacCreateEvent(CFAllocatorRef inAllocator, /* can be NULL */
                   UInt32 inClassID, UInt32 kind, EventTime when,
                   EventAttributes flags, EventRef *outEvent);

    EXTERN_API(EventRef)
    CopyEvent(EventRef inOther);

    EXTERN_API(EventRef)
    RetainEvent(EventRef inEvent);

    EXTERN_API(UInt32)
    GetEventRetainCount(EventRef inEvent);

    EXTERN_API(void)
    ReleaseEvent(EventRef inEvent);

    EXTERN_API(OSStatus)
    SetEventParameter(EventRef inEvent, EventParamName inName,
                      EventParamType inType, UInt32 inSize, const void *inDataPtr);

    EXTERN_API(OSStatus)
    GetEventParameter(EventRef inEvent, EventParamName inName,
                      EventParamType inDesiredType,
                      EventParamType *outActualType,              /* can be NULL */
                      UInt32 inBufferSize, UInt32 *outActualSize, /* can be NULL */
                      void *outData);

    /*��������������������������������������������������������������������������������������*/
    /* � Getters for 'base-class' event info */
    /*��������������������������������������������������������������������������������������*/
    EXTERN_API(UInt32)
    GetEventClass(EventRef inEvent);

    EXTERN_API(UInt32)
    GetEventKind(EventRef inEvent);

    EXTERN_API(EventTime)
    GetEventTime(EventRef inEvent);

    /*��������������������������������������������������������������������������������������*/
    /* � Setters for 'base-class' event info */
    /*��������������������������������������������������������������������������������������*/

    EXTERN_API(OSStatus)
    SetEventTime(EventRef inEvent, EventTime inTime);

    /*��������������������������������������������������������������������������������������*/
    /* � Event Queue routines (posting, finding, flushing) */
    /*��������������������������������������������������������������������������������������*/

    typedef struct OpaqueEventQueueRef *EventQueueRef;
    EXTERN_API(EventQueueRef)
    GetCurrentEventQueue(void);

    EXTERN_API(EventQueueRef)
    GetMainEventQueue(void);

    typedef CALLBACK_API(Boolean, EventComparatorProcPtr)(EventRef inEvent,
                                                          void *inCompareData);
    typedef STACK_UPP_TYPE(EventComparatorProcPtr) EventComparatorUPP;
    EXTERN_API_C(EventComparatorUPP)
    NewEventComparatorUPP(EventComparatorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppEventComparatorProcInfo = 0x000003D0
    }; /* pascal 1_byte Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline EventComparatorUPP
    NewEventComparatorUPP(EventComparatorProcPtr userRoutine)
    {
        return (EventComparatorUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                        uppEventComparatorProcInfo,
                                                        GetCurrentArchitecture());
    }
#else
#define NewEventComparatorUPP(userRoutine)                                       \
    (EventComparatorUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppEventComparatorProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    EXTERN_API_C(void)
    DisposeEventComparatorUPP(EventComparatorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeEventComparatorUPP(EventComparatorUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeEventComparatorUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    EXTERN_API_C(Boolean)
    InvokeEventComparatorUPP(EventRef inEvent, void *inCompareData,
                             EventComparatorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline Boolean InvokeEventComparatorUPP(EventRef inEvent, void *inCompareData,
                                            EventComparatorUPP userUPP)
    {
        return (Boolean)CALL_TWO_PARAMETER_UPP(userUPP, uppEventComparatorProcInfo,
                                               inEvent, inCompareData);
    }
#else
#define InvokeEventComparatorUPP(inEvent, inCompareData, userUPP)           \
    (Boolean) CALL_TWO_PARAMETER_UPP((userUPP), uppEventComparatorProcInfo, \
                                     (inEvent), (inCompareData))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewEventComparatorProc(userRoutine) NewEventComparatorUPP(userRoutine)
#define CallEventComparatorProc(userRoutine, inEvent, inCompareData) \
    InvokeEventComparatorUPP(inEvent, inCompareData, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

    EXTERN_API(OSStatus)
    PostEventToQueue(EventQueueRef inQueue, EventRef inEvent,
                     EventPriority inPriority);

    EXTERN_API(OSStatus)
    FlushEventsMatchingListFromQueue(EventQueueRef inQueue, UInt32 inNumTypes,
                                     const EventTypeSpec *inList);

    EXTERN_API(OSStatus)
    FlushSpecificEventsFromQueue(EventQueueRef inQueue,
                                 EventComparatorUPP inComparator,
                                 void *inCompareData);

    EXTERN_API(OSStatus)
    FlushEventQueue(EventQueueRef inQueue);

    EXTERN_API(EventRef)
    FindSpecificEventInQueue(EventQueueRef inQueue, EventComparatorUPP inComparator,
                             void *inCompareData);

    EXTERN_API(UInt32)
    GetNumEventsInQueue(EventQueueRef inQueue);

    EXTERN_API(OSStatus)
    RemoveEventFromQueue(EventQueueRef inQueue, EventRef inEvent);

    EXTERN_API(Boolean)
    IsEventInQueue(EventQueueRef inQueue, EventRef inEvent);

    /*��������������������������������������������������������������������������������������*/
    /* � Helpful utilities */
    /*��������������������������������������������������������������������������������������*/

    EXTERN_API(EventTime)
    GetCurrentEventTime(void);

    EXTERN_API(Boolean)
    IsUserCancelEventRef(EventRef event);

    EXTERN_API(OSStatus)
    TrackMouseLocation(GrafPtr inPort, /* can be NULL */
                       Point *outPt, MouseTrackingResult *outResult);

    EXTERN_API_C(OSStatus)
    TrackMouseLocationWithOptions(GrafPtr inPort, /* can be NULL */
                                  OptionBits inOptions, EventTimeout inTimeout,
                                  Point *outPt,
                                  UInt32 *outModifiers, /* can be NULL */
                                  MouseTrackingResult *outResult);

    EXTERN_API(OSStatus)
    TrackMouseRegion(GrafPtr inPort, /* can be NULL */
                     RgnHandle inRegion, Boolean *ioWasInRgn,
                     MouseTrackingResult *outResult);

    EXTERN_API(Boolean)
    ConvertEventRefToEventRecord(EventRef inEvent, EventRecord *outEvent);

    EXTERN_API(Boolean)
    IsEventInMask(EventRef inEvent, EventMask inMask);

    EXTERN_API(EventTime)
    GetLastUserEventTime(void);

    /*��������������������������������������������������������������������������������������*/
    /* � Mouse Coalescing */
    /*��������������������������������������������������������������������������������������*/
    EXTERN_API_C(Boolean)
    IsMouseCoalescingEnabled(void);

    EXTERN_API_C(OSStatus)
    SetMouseCoalescingEnabled(Boolean inNewState,
                              Boolean *outOldState); /* can be NULL */

    /*��������������������������������������������������������������������������������������*/
    /* � Timers */
    /*��������������������������������������������������������������������������������������*/

    typedef struct OpaqueEventLoopTimerRef *EventLoopTimerRef;

    typedef CALLBACK_API(void, EventLoopTimerProcPtr)(EventLoopTimerRef inTimer,
                                                      void *inUserData);
    typedef STACK_UPP_TYPE(EventLoopTimerProcPtr) EventLoopTimerUPP;
    EXTERN_API_C(EventLoopTimerUPP)
    NewEventLoopTimerUPP(EventLoopTimerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppEventLoopTimerProcInfo = 0x000003C0
    }; /* pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline EventLoopTimerUPP
    NewEventLoopTimerUPP(EventLoopTimerProcPtr userRoutine)
    {
        return (EventLoopTimerUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                       uppEventLoopTimerProcInfo,
                                                       GetCurrentArchitecture());
    }
#else
#define NewEventLoopTimerUPP(userRoutine)                                       \
    (EventLoopTimerUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppEventLoopTimerProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    EXTERN_API_C(void)
    DisposeEventLoopTimerUPP(EventLoopTimerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeEventLoopTimerUPP(EventLoopTimerUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeEventLoopTimerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    EXTERN_API_C(void)
    InvokeEventLoopTimerUPP(EventLoopTimerRef inTimer, void *inUserData,
                            EventLoopTimerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeEventLoopTimerUPP(EventLoopTimerRef inTimer, void *inUserData,
                                        EventLoopTimerUPP userUPP)
    {
        CALL_TWO_PARAMETER_UPP(userUPP, uppEventLoopTimerProcInfo, inTimer,
                               inUserData);
    }
#else
#define InvokeEventLoopTimerUPP(inTimer, inUserData, userUPP)               \
    CALL_TWO_PARAMETER_UPP((userUPP), uppEventLoopTimerProcInfo, (inTimer), \
                           (inUserData))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewEventLoopTimerProc(userRoutine) NewEventLoopTimerUPP(userRoutine)
#define CallEventLoopTimerProc(userRoutine, inTimer, inUserData) \
    InvokeEventLoopTimerUPP(inTimer, inUserData, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

    EXTERN_API(OSStatus)
    InstallEventLoopTimer(EventLoopRef inEventLoop, EventTimerInterval inFireDelay,
                          EventTimerInterval inInterval,
                          EventLoopTimerUPP inTimerProc, void *inTimerData,
                          EventLoopTimerRef *outTimer);

    EXTERN_API(OSStatus)
    RemoveEventLoopTimer(EventLoopTimerRef inTimer);

    EXTERN_API(OSStatus)
    SetEventLoopTimerNextFireTime(EventLoopTimerRef inTimer,
                                  EventTimerInterval inNextFire);

    /*======================================================================================*/
    /* EVENT CLASSES */
    /*======================================================================================*/

    enum
    {

        kEventClassMouse = FOUR_CHAR_CODE('mous'),

        kEventClassKeyboard = FOUR_CHAR_CODE('keyb'),

        kEventClassTextInput = FOUR_CHAR_CODE('text'),

        kEventClassApplication = FOUR_CHAR_CODE('appl'),

        kEventClassAppleEvent = FOUR_CHAR_CODE('eppc'),

        kEventClassMenu = FOUR_CHAR_CODE('menu'),

        kEventClassWindow = FOUR_CHAR_CODE('wind'),

        kEventClassControl = FOUR_CHAR_CODE('cntl'),

        kEventClassCommand = FOUR_CHAR_CODE('cmds'),

        kEventClassTablet = FOUR_CHAR_CODE('tblt'),

        kEventClassVolume = FOUR_CHAR_CODE('vol '),

        kEventClassAppearance = FOUR_CHAR_CODE('appm'),

        kEventClassService = FOUR_CHAR_CODE('serv')
    };

    /*��������������������������������������������������������������������������������������*/
    /* Mouse Events */
    /*��������������������������������������������������������������������������������������*/
    /* Mouse Events */

    enum
    {

        kEventMouseDown = 1,

        kEventMouseUp = 2,

        kEventMouseMoved = 5,

        kEventMouseDragged = 6,

        kEventMouseWheelMoved = 10
    };

    struct HIPoint
    {

        float x;

        float y;
    };
    typedef struct HIPoint HIPoint;
    typedef UInt16 EventMouseButton;
    enum
    {

        kEventMouseButtonPrimary = 1,

        kEventMouseButtonSecondary = 2,

        kEventMouseButtonTertiary = 3
    };

    typedef UInt16 EventMouseWheelAxis;
    enum
    {

        kEventMouseWheelAxisX = 0,

        kEventMouseWheelAxisY = 1
    };

    /*��������������������������������������������������������������������������������������*/
    /* Text Input Events */
    /*��������������������������������������������������������������������������������������*/

    enum
    {

        kEventTextInputUpdateActiveInputArea = 1,

        kEventTextInputUnicodeForKeyEvent = 2,

        kEventTextInputOffsetToPos = 3,

        kEventTextInputPosToOffset = 4,

        kEventTextInputShowHideBottomWindow = 5,

        kEventTextInputGetSelectedText = 6
    };

    /*��������������������������������������������������������������������������������������*/
    /* Raw Keyboard Events */
    /*��������������������������������������������������������������������������������������*/

    enum
    {

        kEventRawKeyDown = 1, /* hardware-level events*/

        kEventRawKeyRepeat = 2,

        kEventRawKeyUp = 3,

        kEventRawKeyModifiersChanged = 4,

        kEventHotKeyPressed = 5,

        kEventHotKeyReleased = 6 /* Mac OS X only*/
    };

    enum
    {

        kEventKeyModifierNumLockBit = 16, /* Num Lock is on? (Mac OS X only)*/

        kEventKeyModifierFnBit = 17 /* Fn key is down? (Mac OS X only)*/
    };

    enum
    {
        kEventKeyModifierNumLockMask = 1L << kEventKeyModifierNumLockBit,
        kEventKeyModifierFnMask = 1L << kEventKeyModifierFnBit
    };

    /*��������������������������������������������������������������������������������������*/
    /* Application Events */
    /*��������������������������������������������������������������������������������������*/

    enum
    {

        kEventAppActivated = 1,

        kEventAppDeactivated = 2,

        kEventAppQuit = 3,

        kEventAppLaunchNotification = 4,

        kEventAppLaunched = 5,

        kEventAppTerminated = 6,

        kEventAppFrontSwitched = 7,

        kEventAppGetDockTileMenu = 20
    };

    /*��������������������������������������������������������������������������������������*/
    /* Apple Events */
    /*��������������������������������������������������������������������������������������*/

    enum
    {

        kEventAppleEvent = 1
    };

    /*��������������������������������������������������������������������������������������*/
    /* Window Events */
    /*��������������������������������������������������������������������������������������*/

    enum
    {

        kEventWindowUpdate = 1,

        kEventWindowDrawContent = 2
    };

    enum
    {

        kEventWindowActivated = 5,

        kEventWindowDeactivated = 6,

        kEventWindowGetClickActivation = 7
    };

    enum
    {

        kEventWindowShowing = 22,

        kEventWindowHiding = 23,

        kEventWindowShown = 24,

        kEventWindowHidden = 25,

        kEventWindowBoundsChanging = 26,

        kEventWindowBoundsChanged = 27,

        kEventWindowResizeStarted = 28,

        kEventWindowResizeCompleted = 29,

        kEventWindowDragStarted = 30,

        kEventWindowDragCompleted = 31
    };

    enum
    {

        kWindowBoundsChangeUserDrag = (1 << 0),

        kWindowBoundsChangeUserResize = (1 << 1),

        kWindowBoundsChangeSizeChanged = (1 << 2),

        kWindowBoundsChangeOriginChanged = (1 << 3)
    };

    enum
    {

        kEventWindowClickDragRgn = 32,

        kEventWindowClickResizeRgn = 33,

        kEventWindowClickCollapseRgn = 34,

        kEventWindowClickCloseRgn = 35,

        kEventWindowClickZoomRgn = 36,

        kEventWindowClickContentRgn = 37,

        kEventWindowClickProxyIconRgn = 38,

        kEventWindowClickToolbarButtonRgn = 41,

        kEventWindowClickStructureRgn = 42
    };

    enum
    {

        kEventWindowCursorChange = 40
    };

    enum
    {

        kEventWindowCollapse = 66,

        kEventWindowCollapsed = 67,

        kEventWindowCollapseAll = 68,

        kEventWindowExpand = 69,

        kEventWindowExpanded = 70,

        kEventWindowExpandAll = 71,

        kEventWindowClose = 72,

        kEventWindowClosed = 73,

        kEventWindowCloseAll = 74,

        kEventWindowZoom = 75,

        kEventWindowZoomed = 76,

        kEventWindowZoomAll = 77,

        kEventWindowContextualMenuSelect = 78,

        kEventWindowPathSelect = 79,

        kEventWindowGetIdealSize = 80,

        kEventWindowGetMinimumSize = 81,

        kEventWindowGetMaximumSize = 82,

        kEventWindowConstrain = 83,

        kEventWindowHandleContentClick = 85,

        kEventWindowProxyBeginDrag = 128,

        kEventWindowProxyEndDrag = 129,

        kEventWindowToolbarSwitchMode = 150
    };

    enum
    {

        kEventWindowFocusAcquired = 200,

        kEventWindowFocusRelinquish = 201
    };

    enum
    {

        kEventWindowDrawFrame = 1000,

        kEventWindowDrawPart = 1001,

        kEventWindowGetRegion = 1002,

        kEventWindowHitTest = 1003,

        kEventWindowInit = 1004,

        kEventWindowDispose = 1005,

        kEventWindowDragHilite = 1006,

        kEventWindowModified = 1007,

        kEventWindowSetupProxyDragImage = 1008,

        kEventWindowStateChanged = 1009,

        kEventWindowMeasureTitle = 1010,

        kEventWindowDrawGrowBox = 1011,

        kEventWindowGetGrowImageRegion = 1012,

        kEventWindowPaint = 1013
    };

    /*��������������������������������������������������������������������������������������*/
    /* Menu Events */
    /*��������������������������������������������������������������������������������������*/

    enum
    {

        kEventMenuBeginTracking = 1,

        kEventMenuEndTracking = 2,

        kEventMenuChangeTrackingMode = 3,

        kEventMenuOpening = 4,

        kEventMenuClosed = 5,

        kEventMenuTargetItem = 6,

        kEventMenuMatchKey = 7,

        kEventMenuEnableItems = 8,

        kEventMenuPopulate = 9,

        kEventMenuMeasureItemWidth = 100,

        kEventMenuMeasureItemHeight = 101,
        kEventMenuDrawItem = 102,
        kEventMenuDrawItemContent = 103,

        kEventMenuDispose = 1001
    };

    enum
    {
        /* menu location*/

        kMenuContextMenuBar = 1 << 0, /* menu type*/

        kMenuContextPullDown = 1 << 8,

        kMenuContextPopUp = 1 << 9,

        kMenuContextSubmenu = 1 << 10, /* menu usage*/

        kMenuContextMenuBarTracking = 1 << 16,

        kMenuContextPopUpTracking = 1 << 17,

        kMenuContextKeyMatching = 1 << 18,

        kMenuContextMenuEnabling = 1 << 19
    };

    /*��������������������������������������������������������������������������������������*/
    /* Command Events */
    /*��������������������������������������������������������������������������������������*/

    enum
    {
        kEventProcessCommand = 1,

        kEventCommandProcess = 1,

        kEventCommandUpdateStatus = 2
    };

    /* HI Commands */

    enum
    {

        kHICommandOK = FOUR_CHAR_CODE('ok '),

        kHICommandCancel = FOUR_CHAR_CODE('not!'),

        kHICommandQuit = FOUR_CHAR_CODE('quit'),

        kHICommandUndo = FOUR_CHAR_CODE('undo'),

        kHICommandRedo = FOUR_CHAR_CODE('redo'),

        kHICommandCut = FOUR_CHAR_CODE('cut '),

        kHICommandCopy = FOUR_CHAR_CODE('copy'),

        kHICommandPaste = FOUR_CHAR_CODE('past'),

        kHICommandClear = FOUR_CHAR_CODE('clea'),

        kHICommandSelectAll = FOUR_CHAR_CODE('sall'),

        kHICommandHide = FOUR_CHAR_CODE('hide'),

        kHICommandHideOthers = FOUR_CHAR_CODE('hido'),

        kHICommandShowAll = FOUR_CHAR_CODE('shal'),

        kHICommandPreferences = FOUR_CHAR_CODE('pref'),

        kHICommandZoomWindow = FOUR_CHAR_CODE('zoom'),

        kHICommandMinimizeWindow = FOUR_CHAR_CODE('mini'),

        kHICommandMinimizeAll = FOUR_CHAR_CODE('mina'),

        kHICommandMaximizeWindow = FOUR_CHAR_CODE('maxi'),

        kHICommandMaximizeAll = FOUR_CHAR_CODE('maxa'),

        kHICommandArrangeInFront = FOUR_CHAR_CODE('frnt'),

        kHICommandBringAllToFront = FOUR_CHAR_CODE('bfrt'),

        kHICommandWindowListSeparator = FOUR_CHAR_CODE('wldv'),

        kHICommandWindowListTerminator = FOUR_CHAR_CODE('wlst'),

        kHICommandSelectWindow = FOUR_CHAR_CODE('swin'),

        kHICommandAbout = FOUR_CHAR_CODE('abou'),

        kHICommandNew = FOUR_CHAR_CODE('new '),

        kHICommandOpen = FOUR_CHAR_CODE('open'),

        kHICommandClose = FOUR_CHAR_CODE('clos'),

        kHICommandSave = FOUR_CHAR_CODE('save'),

        kHICommandSaveAs = FOUR_CHAR_CODE('svas'),

        kHICommandRevert = FOUR_CHAR_CODE('rvrt'),

        kHICommandPrint = FOUR_CHAR_CODE('prnt'),

        kHICommandPageSetup = FOUR_CHAR_CODE('page'),

        kHICommandAppHelp = FOUR_CHAR_CODE('ahlp')
    };

    enum
    {
        kHICommandFromMenu = (1L << 0)
    };

    struct HICommand
    {
        UInt32 attributes;
        UInt32 commandID;
        struct
        {
            MenuRef menuRef;
            MenuItemIndex menuItemIndex;
        } menu;
    };
    typedef struct HICommand HICommand;
    /*��������������������������������������������������������������������������������������*/
    /* Control Events */
    /*��������������������������������������������������������������������������������������*/

    enum
    {

        kEventControlInitialize = 1000,

        kEventControlDispose = 1001,

        kEventControlGetOptimalBounds = 1003,
        kEventControlDefInitialize = kEventControlInitialize,
        kEventControlDefDispose = kEventControlDispose,

        kEventControlHit = 1,

        kEventControlSimulateHit = 2,

        kEventControlHitTest = 3,

        kEventControlDraw = 4,

        kEventControlApplyBackground = 5,

        kEventControlApplyTextColor = 6,

        kEventControlSetFocusPart = 7,

        kEventControlGetFocusPart = 8,

        kEventControlActivate = 9,

        kEventControlDeactivate = 10,

        kEventControlSetCursor = 11,

        kEventControlContextualMenuClick = 12,

        kEventControlClick = 13,

        kEventControlTrack = 51,

        kEventControlGetScrollToHereStartPoint = 52,

        kEventControlGetIndicatorDragConstraint = 53,

        kEventControlIndicatorMoved = 54,

        kEventControlGhostingFinished = 55,

        kEventControlGetActionProcPart = 56,

        kEventControlGetPartRegion = 101,

        kEventControlGetPartBounds = 102,

        kEventControlSetData = 103,

        kEventControlGetData = 104,

        kEventControlValueFieldChanged = 151,

        kEventControlAddedSubControl = 152,

        kEventControlRemovingSubControl = 153,

        kEventControlBoundsChanged = 154,

        kEventControlOwningWindowChanged = 159,

        kEventControlArbitraryMessage = 201
    };

    enum
    {

        kControlBoundsChangeSizeChanged = (1 << 2),

        kControlBoundsChangePositionChanged = (1 << 3)
    };

    /*��������������������������������������������������������������������������������������*/
    /* Tablet Events (and tablet data in mouse events) */
    /*��������������������������������������������������������������������������������������*/

    enum
    {

        kEventTabletPoint = 1,

        kEventTabletProximity = 2,
        kEventTabletPointer =
            1 /* deprecated form for compatibility only, use kEventTabletPoint*/
    };

    struct TabletPointRec
    {
        SInt32 absX;    /* absolute x coordinate in tablet space at full tablet
           resolution */
        SInt32 absY;    /* absolute y coordinate in tablet space at full tablet
           resolution */
        SInt32 absZ;    /* absolute z coordinate in tablet space at full tablet
           resolution */
        UInt16 buttons; /* one bit per button - bit 0 is first button - 1 = closed */
        UInt16
            pressure;              /* scaled pressure value; MAXPRESSURE=(2^16)-1, MINPRESSURE=0 */
        SInt16 tiltX;              /* scaled tilt x value; range is -((2^15)-1) to (2^15)-1 (-32767
                     to 32767) */
        SInt16 tiltY;              /* scaled tilt y value; range is -((2^15)-1) to (2^15)-1 (-32767
                     to 32767) */
        UInt16 rotation;           /* Fixed-point representation of device rotation in a 10.6
                  format */
        SInt16 tangentialPressure; /* tangential pressure on the device; range same as
        tilt */
        UInt16 deviceID;           /* system-assigned unique device ID - matches to deviceID
                  field in proximity event */
        SInt16 vendor1;            /* vendor-defined signed 16-bit integer */
        SInt16 vendor2;            /* vendor-defined signed 16-bit integer */
        SInt16 vendor3;            /* vendor-defined signed 16-bit integer */
    };
    typedef struct TabletPointRec TabletPointRec;
    typedef TabletPointRec TabletPointerRec;
    struct TabletProximityRec
    {
        UInt16 vendorID;            /* vendor-defined ID - typically will be USB vendor ID */
        UInt16 tabletID;            /* vendor-defined tablet ID - typically will be USB product
                   ID for the tablet */
        UInt16 pointerID;           /* vendor-defined ID of the specific pointing device */
        UInt16 deviceID;            /* system-assigned unique device ID - matches to deviceID
                   field in tablet event */
        UInt16 systemTabletID;      /* system-assigned unique tablet ID */
        UInt16 vendorPointerType;   /* vendor-defined pointer type */
        UInt32 pointerSerialNumber; /* vendor-defined serial number of the specific
        pointing device */
        UInt64 uniqueID;            /* vendor-defined unique ID for this pointer */
        UInt32 capabilityMask;      /* mask representing the capabilities of the device */
        UInt8 pointerType;          /* type of pointing device - enum to be defined */
        UInt8 enterProximity;       /* non-zero = entering; zero = leaving */
    };
    typedef struct TabletProximityRec TabletProximityRec;
    /*��������������������������������������������������������������������������������������*/
    /* Volume Events */
    /*��������������������������������������������������������������������������������������*/

    enum
    {

        kEventVolumeMounted = 1, /* new volume mounted*/

        kEventVolumeUnmounted = 2 /* volume has been ejected or unmounted*/
    };

    /* types for volume events*/

    enum
    {
        typeFSVolumeRefNum = FOUR_CHAR_CODE('voln') /* FSVolumeRefNum*/
    };

    /*��������������������������������������������������������������������������������������*/
    /* Appearance Events */
    /*��������������������������������������������������������������������������������������*/
    /* Appearance Events */

    enum
    {

        kEventAppearanceScrollBarVariantChanged = 1
    };

    /*��������������������������������������������������������������������������������������*/
    /* Services Events */
    /*��������������������������������������������������������������������������������������*/

    enum
    {

        kEventServiceCopy = 1,

        kEventServicePaste = 2,

        kEventServiceGetTypes = 3,

        kEventServicePerform = 4
    };

    EXTERN_API(CFStringRef)
    CreateTypeStringWithOSType(OSType inType);

    /*��������������������������������������������������������������������������������������*/
    /* Parameter names and types */
    /*��������������������������������������������������������������������������������������*/
    enum
    {
        kEventParamDirectObject =
            FOUR_CHAR_CODE('----') /* type varies depending on event*/
    };

    /* Generic toolbox parameters and types*/

    enum
    {
        kEventParamWindowRef = FOUR_CHAR_CODE('wind'),       /* typeWindowRef*/
        kEventParamGrafPort = FOUR_CHAR_CODE('graf'),        /* typeGrafPtr*/
        kEventParamDragRef = FOUR_CHAR_CODE('drag'),         /* typeDragRef*/
        kEventParamMenuRef = FOUR_CHAR_CODE('menu'),         /* typeMenuRef*/
        kEventParamEventRef = FOUR_CHAR_CODE('evnt'),        /* typeEventRef*/
        kEventParamControlRef = FOUR_CHAR_CODE('ctrl'),      /* typeControlRef*/
        kEventParamRgnHandle = FOUR_CHAR_CODE('rgnh'),       /* typeQDRgnHandle*/
        kEventParamEnabled = FOUR_CHAR_CODE('enab'),         /* typeBoolean*/
        kEventParamDimensions = FOUR_CHAR_CODE('dims'),      /* typeQDPoint*/
        kEventParamAvailableBounds = FOUR_CHAR_CODE('avlb'), /* typeQDRectangle*/
        kEventParamAEEventID = keyAEEventID,                 /* typeType*/
        kEventParamAEEventClass = keyAEEventClass,           /* typeType*/
        kEventParamCGContextRef = FOUR_CHAR_CODE('cntx'),    /* typeCGContextRef*/
        kEventParamDeviceDepth = FOUR_CHAR_CODE('devd'),     /* typeShortInteger*/
        kEventParamDeviceColor = FOUR_CHAR_CODE('devc'),     /* typeBoolean*/
        typeWindowRef = FOUR_CHAR_CODE('wind'),              /* WindowRef*/
        typeGrafPtr = FOUR_CHAR_CODE('graf'),                /* CGrafPtr*/
        typeGWorldPtr = FOUR_CHAR_CODE('gwld'),              /* GWorldPtr*/
        typeDragRef = FOUR_CHAR_CODE('drag'),                /* DragRef*/
        typeMenuRef = FOUR_CHAR_CODE('menu'),                /* MenuRef*/
        typeControlRef = FOUR_CHAR_CODE('ctrl'),             /* ControlRef*/
        typeCollection = FOUR_CHAR_CODE('cltn'),             /* Collection*/
        typeQDRgnHandle = FOUR_CHAR_CODE('rgnh'),            /* RgnHandle*/
        typeOSStatus = FOUR_CHAR_CODE('osst'),               /* OSStatus*/
        typeCFStringRef = FOUR_CHAR_CODE('cfst'),            /* CFStringRef*/
        typeCGContextRef = FOUR_CHAR_CODE('cntx'),           /* CGContextRef*/
        typeHIPoint = FOUR_CHAR_CODE('hipt')                 /* HIPoint*/
    };

    /* Mouse event parameters and types*/

    enum
    {
        kEventParamMouseLocation = FOUR_CHAR_CODE('mloc'),   /* typeQDPoint*/
        kEventParamMouseButton = FOUR_CHAR_CODE('mbtn'),     /* typeMouseButton*/
        kEventParamClickCount = FOUR_CHAR_CODE('ccnt'),      /* typeUInt32*/
        kEventParamMouseWheelAxis = FOUR_CHAR_CODE('mwax'),  /* typeMouseWheelAxis*/
        kEventParamMouseWheelDelta = FOUR_CHAR_CODE('mwdl'), /* typeSInt32*/
        kEventParamMouseDelta = FOUR_CHAR_CODE('mdta'),      /* typeQDPoint*/
        kEventParamMouseChord = FOUR_CHAR_CODE('chor'),      /* typeUInt32*/
        kEventParamTabletEventType = FOUR_CHAR_CODE('tblt'), /* typeUInt32*/
        typeMouseButton = FOUR_CHAR_CODE('mbtn'),            /* EventMouseButton*/
        typeMouseWheelAxis = FOUR_CHAR_CODE('mwax')          /* EventMouseWheelAxis*/
    };

    /* Keyboard event parameter and types*/

    enum
    {
        kEventParamKeyCode = FOUR_CHAR_CODE('kcod'),         /* typeUInt32*/
        kEventParamKeyMacCharCodes = FOUR_CHAR_CODE('kchr'), /* typeChar*/
        kEventParamKeyModifiers = FOUR_CHAR_CODE('kmod'),    /* typeUInt32*/
        kEventParamKeyUnicodes = FOUR_CHAR_CODE('kuni'),     /* typeUnicodeText*/
        kEventParamKeyboardType = FOUR_CHAR_CODE('kbdt'),    /* typeUInt32*/
        typeEventHotKeyID = FOUR_CHAR_CODE('hkid')           /* EventHotKeyID*/
    };

    /* TextInput event parameters*/

    enum
    {
        kEventParamTextInputSendRefCon =
            FOUR_CHAR_CODE('tsrc'), /* typeLongInteger*/
        kEventParamTextInputSendComponentInstance =
            FOUR_CHAR_CODE('tsci'), /* typeComponentInstance*/
        kEventParamTextInputSendSLRec =
            FOUR_CHAR_CODE('tssl'), /* typeIntlWritingCode*/
        kEventParamTextInputReplySLRec =
            FOUR_CHAR_CODE('trsl'), /* typeIntlWritingCode*/
        kEventParamTextInputSendText =
            FOUR_CHAR_CODE('tstx'), /* typeUnicodeText (if TSMDocument is Unicode),
            otherwise typeChar*/
        kEventParamTextInputReplyText =
            FOUR_CHAR_CODE('trtx'), /* typeUnicodeText (if TSMDocument is Unicode),
            otherwise typeChar*/
        kEventParamTextInputSendUpdateRng =
            FOUR_CHAR_CODE('tsup'), /* typeTextRangeArray*/
        kEventParamTextInputSendHiliteRng =
            FOUR_CHAR_CODE('tshi'), /* typeTextRangeArray*/
        kEventParamTextInputSendClauseRng =
            FOUR_CHAR_CODE('tscl'),                              /* typeOffsetArray*/
        kEventParamTextInputSendPinRng = FOUR_CHAR_CODE('tspn'), /* typeTextRange*/
        kEventParamTextInputSendFixLen =
            FOUR_CHAR_CODE('tsfx'), /* typeLongInteger*/
        kEventParamTextInputSendLeadingEdge =
            FOUR_CHAR_CODE('tsle'), /* typeBoolean*/
        kEventParamTextInputReplyLeadingEdge =
            FOUR_CHAR_CODE('trle'), /* typeBoolean*/
        kEventParamTextInputSendTextOffset =
            FOUR_CHAR_CODE('tsto'), /* typeLongInteger*/
        kEventParamTextInputReplyTextOffset =
            FOUR_CHAR_CODE('trto'), /* typeLongInteger*/
        kEventParamTextInputReplyRegionClass =
            FOUR_CHAR_CODE('trrg'), /* typeLongInteger*/
        kEventParamTextInputSendCurrentPoint =
            FOUR_CHAR_CODE('tscp'), /* typeQDPoint*/
        kEventParamTextInputSendDraggingMode =
            FOUR_CHAR_CODE('tsdm'),                              /* typeBoolean*/
        kEventParamTextInputReplyPoint = FOUR_CHAR_CODE('trpt'), /* typeQDPoint*/
        kEventParamTextInputReplyFont =
            FOUR_CHAR_CODE('trft'),                                  /* typeLongInteger*/
        kEventParamTextInputReplyFMFont = FOUR_CHAR_CODE('trfm'),    /* typeUInt32*/
        kEventParamTextInputReplyPointSize = FOUR_CHAR_CODE('trpz'), /* typeFixed*/
        kEventParamTextInputReplyLineHeight =
            FOUR_CHAR_CODE('trlh'), /* typeShortInteger*/
        kEventParamTextInputReplyLineAscent =
            FOUR_CHAR_CODE('trla'),                                  /* typeShortInteger*/
        kEventParamTextInputReplyTextAngle = FOUR_CHAR_CODE('trta'), /* typeFixed*/
        kEventParamTextInputSendShowHide = FOUR_CHAR_CODE('tssh'),   /* typeBoolean*/
        kEventParamTextInputReplyShowHide =
            FOUR_CHAR_CODE('trsh'), /* typeBoolean*/
        kEventParamTextInputSendKeyboardEvent =
            FOUR_CHAR_CODE('tske'), /* typeEventRef*/
        kEventParamTextInputSendTextServiceEncoding =
            FOUR_CHAR_CODE('tsse'), /* typeUInt32*/
        kEventParamTextInputSendTextServiceMacEncoding =
            FOUR_CHAR_CODE('tssm') /* typeUInt32*/
    };

    /* Command event parameters and types*/

    enum
    {
        kEventParamHICommand = FOUR_CHAR_CODE('hcmd'), /* typeHICommand*/
        typeHICommand = FOUR_CHAR_CODE('hcmd')         /* HICommand*/
    };

    /* Window event parameters and types*/

    enum
    {
        kEventParamWindowFeatures = FOUR_CHAR_CODE('wftr'), /* typeUInt32*/
        kEventParamWindowDefPart = FOUR_CHAR_CODE('wdpc'),  /* typeWindowDefPartCode*/
        kEventParamCurrentBounds = FOUR_CHAR_CODE('crct'),  /* typeQDRectangle*/
        kEventParamOriginalBounds = FOUR_CHAR_CODE('orct'), /* typeQDRectangle*/
        kEventParamPreviousBounds = FOUR_CHAR_CODE('prct'), /* typeQDRectangle*/
        kEventParamClickActivation =
            FOUR_CHAR_CODE('clac'), /* typeClickActivationResult*/
        kEventParamWindowRegionCode =
            FOUR_CHAR_CODE('wshp'),                               /* typeWindowRegionCode*/
        kEventParamWindowDragHiliteFlag = FOUR_CHAR_CODE('wdhf'), /* typeBoolean*/
        kEventParamWindowModifiedFlag = FOUR_CHAR_CODE('wmff'),   /* typeBoolean*/
        kEventParamWindowProxyGWorldPtr = FOUR_CHAR_CODE('wpgw'), /* typeGWorldPtr*/
        kEventParamWindowProxyImageRgn = FOUR_CHAR_CODE('wpir'),  /* typeQDRgnHandle*/
        kEventParamWindowProxyOutlineRgn =
            FOUR_CHAR_CODE('wpor'),                                  /* typeQDRgnHandle*/
        kEventParamWindowStateChangedFlags = FOUR_CHAR_CODE('wscf'), /* typeUInt32 */
        kEventParamWindowTitleFullWidth = FOUR_CHAR_CODE('wtfw'),    /* typeSInt16*/
        kEventParamWindowTitleTextWidth = FOUR_CHAR_CODE('wttw'),    /* typeSInt16*/
        kEventParamWindowGrowRect = FOUR_CHAR_CODE('grct'),          /* typeQDRectangle*/
        kEventParamAttributes = FOUR_CHAR_CODE('attr'),              /* typeUInt32*/
        typeWindowRegionCode = FOUR_CHAR_CODE('wshp'),               /* WindowRegionCode*/
        typeWindowDefPartCode = FOUR_CHAR_CODE('wdpt'),              /* WindowDefPartCode*/
        typeClickActivationResult = FOUR_CHAR_CODE('clac')           /* ClickActivationResult*/
    };

    /* Control event parameters and types*/

    enum
    {
        kEventParamControlPart = FOUR_CHAR_CODE('cprt'),    /* typeControlPartCode*/
        kEventParamInitCollection = FOUR_CHAR_CODE('icol'), /* typeCollection*/
        kEventParamControlMessage = FOUR_CHAR_CODE('cmsg'), /* typeShortInteger*/
        kEventParamControlParam = FOUR_CHAR_CODE('cprm'),   /* typeLongInteger*/
        kEventParamControlResult = FOUR_CHAR_CODE('crsl'),  /* typeLongInteger*/
        kEventParamControlRegion = FOUR_CHAR_CODE('crgn'),  /* typeQDRgnHandle*/
        kEventParamControlAction = FOUR_CHAR_CODE('caup'),  /* typeControlActionUPP*/
        kEventParamControlIndicatorDragConstraint =
            FOUR_CHAR_CODE('cidc'), /* typeIndicatorDragConstraint*/
        kEventParamControlIndicatorRegion =
            FOUR_CHAR_CODE('cirn'),                                 /* typeQDRgnHandle*/
        kEventParamControlIsGhosting = FOUR_CHAR_CODE('cgst'),      /* typeBoolean*/
        kEventParamControlIndicatorOffset = FOUR_CHAR_CODE('ciof'), /* typeQDPoint*/
        kEventParamControlClickActivationResult =
            FOUR_CHAR_CODE('ccar'),                               /* typeClickActivationResult*/
        kEventParamControlSubControl = FOUR_CHAR_CODE('csub'),    /* typeControlRef*/
        kEventParamControlOptimalBounds = FOUR_CHAR_CODE('cobn'), /* typeQDRectangle*/
        kEventParamControlOptimalBaselineOffset =
            FOUR_CHAR_CODE('cobo'),                            /* typeShortInteger*/
        kEventParamControlDataTag = FOUR_CHAR_CODE('cdtg'),    /* typeEnumeration*/
        kEventParamControlDataBuffer = FOUR_CHAR_CODE('cdbf'), /* typePtr*/
        kEventParamControlDataBufferSize =
            FOUR_CHAR_CODE('cdbs'),                             /* typeLongInteger*/
        kEventParamControlDrawDepth = FOUR_CHAR_CODE('cddp'),   /* typeShortInteger*/
        kEventParamControlDrawInColor = FOUR_CHAR_CODE('cdic'), /* typeBoolean*/
        kEventParamControlFeatures = FOUR_CHAR_CODE('cftr'),    /* typeUInt32*/
        kEventParamControlPartBounds = FOUR_CHAR_CODE('cpbd'),  /* typeQDRectangle*/
        kEventParamControlOriginalOwningWindow =
            FOUR_CHAR_CODE('coow'), /* typeWindowRef*/
        kEventParamControlCurrentOwningWindow =
            FOUR_CHAR_CODE('ccow'),                    /* typeWindowRef*/
        typeControlActionUPP = FOUR_CHAR_CODE('caup'), /* ControlActionUPP*/
        typeIndicatorDragConstraint =
            FOUR_CHAR_CODE('cidc'),                  /* IndicatorDragConstraint*/
        typeControlPartCode = FOUR_CHAR_CODE('cprt') /* ControlPartCode*/
    };

    /* Menu event parameters and types*/

    enum
    {
        kEventParamCurrentMenuTrackingMode =
            FOUR_CHAR_CODE('cmtm'), /* typeMenuTrackingMode*/
        kEventParamNewMenuTrackingMode =
            FOUR_CHAR_CODE('nmtm'),                                /* typeMenuTrackingMode*/
        kEventParamMenuFirstOpen = FOUR_CHAR_CODE('1sto'),         /* typeBoolean*/
        kEventParamMenuItemIndex = FOUR_CHAR_CODE('item'),         /* typeMenuItemIndex*/
        kEventParamMenuCommand = FOUR_CHAR_CODE('mcmd'),           /* typeMenuCommand*/
        kEventParamEnableMenuForKeyEvent = FOUR_CHAR_CODE('fork'), /* typeBoolean*/
        kEventParamMenuEventOptions =
            FOUR_CHAR_CODE('meop'),                               /* typeMenuEventOptions*/
        kEventParamMenuContext = FOUR_CHAR_CODE('mctx'),          /* typeUInt32*/
        kEventParamMenuItemBounds = FOUR_CHAR_CODE('mitb'),       /* typeQDRectangle*/
        kEventParamMenuMarkBounds = FOUR_CHAR_CODE('mmkb'),       /* typeQDRectangle*/
        kEventParamMenuIconBounds = FOUR_CHAR_CODE('micb'),       /* typeQDRectangle*/
        kEventParamMenuTextBounds = FOUR_CHAR_CODE('mtxb'),       /* typeQDRectangle*/
        kEventParamMenuTextBaseline = FOUR_CHAR_CODE('mtbl'),     /* typeShortInteger*/
        kEventParamMenuCommandKeyBounds = FOUR_CHAR_CODE('mcmb'), /* typeQDRectangle*/
        kEventParamMenuVirtualTop = FOUR_CHAR_CODE('mvrt'),       /* typeLongInteger*/
        kEventParamMenuVirtualBottom = FOUR_CHAR_CODE('mvrb'),    /* typeLongInteger*/
        kEventParamMenuDrawState = FOUR_CHAR_CODE('mdrs'),        /* typeThemeDrawState*/
        kEventParamMenuItemType = FOUR_CHAR_CODE('mitp'),         /* typeThemeMenuItemType*/
        kEventParamMenuItemWidth = FOUR_CHAR_CODE('mitw'),        /* typeShortInteger*/
        kEventParamMenuItemHeight = FOUR_CHAR_CODE('mith'),       /* typeShortInteger*/
        typeMenuItemIndex = FOUR_CHAR_CODE('midx'),               /* MenuItemIndex*/
        typeMenuCommand = FOUR_CHAR_CODE('mcmd'),                 /* MenuCommand*/
        typeMenuTrackingMode = FOUR_CHAR_CODE('mtmd'),            /* MenuTrackingMode*/
        typeMenuEventOptions = FOUR_CHAR_CODE('meop'),            /* MenuEventOptions*/
        typeThemeMenuState = FOUR_CHAR_CODE('tmns'),              /* ThemeMenuState*/
        typeThemeMenuItemType = FOUR_CHAR_CODE('tmit')            /* ThemeMenuItemType*/
    };

    /* Application event parameters*/

    enum
    {
        kEventParamProcessID = FOUR_CHAR_CODE('psn '),    /* typeProcessSerialNumber*/
        kEventParamLaunchRefCon = FOUR_CHAR_CODE('lref'), /* typeUInt32*/
        kEventParamLaunchErr = FOUR_CHAR_CODE('err ')     /* typeOSStatus*/
    };

    /* Tablet event parameters and types*/

    enum
    {
        kEventParamTabletPointRec = FOUR_CHAR_CODE('tbrc'), /* typeTabletPointRec*/
        kEventParamTabletProximityRec =
            FOUR_CHAR_CODE('tbpx'),                  /* typeTabletProximityRec*/
        typeTabletPointRec = FOUR_CHAR_CODE('tbrc'), /* kEventParamTabletPointRec*/
        typeTabletProximityRec =
            FOUR_CHAR_CODE('tbpx'), /* kEventParamTabletProximityRec*/
        kEventParamTabletPointerRec =
            FOUR_CHAR_CODE('tbrc'), /* typeTabletPointerRec -- deprecated, for
            compatibility only*/
        typeTabletPointerRec =
            FOUR_CHAR_CODE('tbrc') /* kEventParamTabletPointerRec -- deprecated,
            for compatibility only*/
    };

    /* Appearance event parameters*/

    enum
    {
        kEventParamNewScrollBarVariant = FOUR_CHAR_CODE('nsbv') /* typeShortInteger*/
    };

    /* Service event parameters*/

    enum
    {
        kEventParamScrapRef = FOUR_CHAR_CODE('scrp'), /* typeScrapRef*/
        kEventParamServiceCopyTypes =
            FOUR_CHAR_CODE('svsd'), /* typeCFMutableArrayRef*/
        kEventParamServicePasteTypes =
            FOUR_CHAR_CODE('svpt'), /* typeCFMutableArrayRef*/
        kEventParamServiceMessageName =
            FOUR_CHAR_CODE('svmg'),                          /* typeCFStringRef*/
        kEventParamServiceUserData = FOUR_CHAR_CODE('svud'), /* typeCFStringRef*/
        typeScrapRef = FOUR_CHAR_CODE('scrp'),               /* ScrapRef*/
        typeCFMutableArrayRef = FOUR_CHAR_CODE('cfma')       /* CFMutableArrayRef*/
    };

    /*======================================================================================*/
    /* EVENT HANDLERS */
    /*======================================================================================*/

    typedef struct OpaqueEventHandlerRef *EventHandlerRef;
    typedef struct OpaqueEventHandlerCallRef *EventHandlerCallRef;

    /*��������������������������������������������������������������������������������������*/
    /* � EventHandler specification */
    /*��������������������������������������������������������������������������������������*/

    typedef CALLBACK_API(OSStatus,
                         EventHandlerProcPtr)(EventHandlerCallRef inHandlerCallRef,
                                              EventRef inEvent, void *inUserData);
    typedef STACK_UPP_TYPE(EventHandlerProcPtr) EventHandlerUPP;
    EXTERN_API_C(EventHandlerUPP)
    NewEventHandlerUPP(EventHandlerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppEventHandlerProcInfo = 0x00000FF0
    }; /* pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline EventHandlerUPP NewEventHandlerUPP(EventHandlerProcPtr userRoutine)
    {
        return (EventHandlerUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                     uppEventHandlerProcInfo,
                                                     GetCurrentArchitecture());
    }
#else
#define NewEventHandlerUPP(userRoutine)                                       \
    (EventHandlerUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppEventHandlerProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    EXTERN_API_C(void)
    DisposeEventHandlerUPP(EventHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeEventHandlerUPP(EventHandlerUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeEventHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    EXTERN_API_C(OSStatus)
    InvokeEventHandlerUPP(EventHandlerCallRef inHandlerCallRef, EventRef inEvent,
                          void *inUserData, EventHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSStatus InvokeEventHandlerUPP(EventHandlerCallRef inHandlerCallRef,
                                          EventRef inEvent, void *inUserData,
                                          EventHandlerUPP userUPP)
    {
        return (OSStatus)CALL_THREE_PARAMETER_UPP(
            userUPP, uppEventHandlerProcInfo, inHandlerCallRef, inEvent, inUserData);
    }
#else
#define InvokeEventHandlerUPP(inHandlerCallRef, inEvent, inUserData, userUPP) \
    (OSStatus)                                                                \
        CALL_THREE_PARAMETER_UPP((userUPP), uppEventHandlerProcInfo,          \
                                 (inHandlerCallRef), (inEvent), (inUserData))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewEventHandlerProc(userRoutine) NewEventHandlerUPP(userRoutine)
#define CallEventHandlerProc(userRoutine, inHandlerCallRef, inEvent, \
                             inUserData)                             \
    InvokeEventHandlerUPP(inHandlerCallRef, inEvent, inUserData, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

    /*��������������������������������������������������������������������������������������*/
    /* � Installing Event Handlers */
    /* */
    /* Use these routines to install event handlers for a specific toolbox object.
     * You may */
    /* pass zero for inNumTypes and NULL for inList if you need to be in a situation
     * where */
    /* you know you will be receiving events, but not exactly which ones at the time
     * you */
    /* are installing the handler. Later, your application can call the Add/Remove
     * routines */
    /* listed below this section. */
    /* */
    /* You can only install a specific handler once. The combination of inHandler
     * and */
    /* inUserData is considered the 'signature' of a handler. Any attempt to install
     * a new */
    /* handler with the same proc and user data as an already-installed handler will
     * result */
    /* in eventHandlerAlreadyInstalledErr. Installing the same proc and user data on
     * a */
    /* different object is legal. */
    /* */
    /* Upon successful completion of this routine, you are returned an
     * EventHandlerRef, */
    /* which you can use in various other calls, and is passed to your event
     * handler. You */
    /* use it to extract information about the handler, such as the target (window,
     * etc.) */
    /* if you have the same handler installed for different objects and need to
     * perform */
    /* actions on the current target (say, call a window manager function). */
    /*��������������������������������������������������������������������������������������*/
    typedef struct OpaqueEventTargetRef *EventTargetRef;
    EXTERN_API(EventTargetRef)
    GetWindowEventTarget(WindowRef inWindow);

    EXTERN_API(EventTargetRef)
    GetControlEventTarget(ControlRef inControl);

    EXTERN_API(EventTargetRef)
    GetMenuEventTarget(MenuRef inMenu);

    EXTERN_API(EventTargetRef)
    GetApplicationEventTarget(void);

    EXTERN_API(EventTargetRef)
    GetUserFocusEventTarget(void);

    EXTERN_API_C(EventTargetRef)
    GetEventDispatcherTarget(void);

    EXTERN_API(OSStatus)
    InstallEventHandler(EventTargetRef inTarget, EventHandlerUPP inHandler,
                        UInt32 inNumTypes, const EventTypeSpec *inList,
                        void *inUserData,
                        EventHandlerRef *outRef); /* can be NULL */

    EXTERN_API(OSStatus)
    InstallStandardEventHandler(EventTargetRef inTarget);

#define InstallApplicationEventHandler(h, n, l, u, r) \
    InstallEventHandler(GetApplicationEventTarget(), (h), (n), (l), (u), (r))

#define InstallWindowEventHandler(t, h, n, l, u, r) \
    InstallEventHandler(GetWindowEventTarget(t), (h), (n), (l), (u), (r))

#define InstallControlEventHandler(t, h, n, l, u, r) \
    InstallEventHandler(GetControlEventTarget(t), (h), (n), (l), (u), (r))

#define InstallMenuEventHandler(t, h, n, l, u, r) \
    InstallEventHandler(GetMenuEventTarget(t), (h), (n), (l), (u), (r))

#define DEFINE_ONE_SHOT_HANDLER_GETTER(x)       \
    EventHandlerUPP Get##x##UPP()               \
    {                                           \
        static EventHandlerUPP sHandler = NULL; \
                                                \
        if (sHandler == NULL)                   \
            sHandler = NewEventHandlerUPP(x);   \
                                                \
        return sHandler;                        \
    }

    EXTERN_API(OSStatus)
    RemoveEventHandler(EventHandlerRef inHandlerRef);

    /*��������������������������������������������������������������������������������������*/
    /* � Adjusting set of event types after a handler is created */
    /* */
    /* After installing a handler with the routine above, you can adjust the event
     * type */
    /* list telling the toolbox what events to send to that handler by calling the
     * two */
    /* routines below. If you add an event type twice for the same handler, your
     * handler */
    /* will only be called once, but it will take two RemoveEventType calls to stop
     * your */
    /* handler from being called with that event type. In other words, the install
     * count */
    /* for each event type is maintained by the toolbox. This might allow you, for
     * example */
    /* to have subclasses of a window object register for types without caring if
     * the base */
    /* class has already registered for that type. When the subclass removes its
     * types, it */
    /* can successfully do so without affecting the base class's reception of its
     * event */
    /* types, yielding eternal bliss. */
    /*��������������������������������������������������������������������������������������*/

    EXTERN_API(OSStatus)
    AddEventTypesToHandler(EventHandlerRef inHandlerRef, UInt32 inNumTypes,
                           const EventTypeSpec *inList);

    EXTERN_API(OSStatus)
    RemoveEventTypesFromHandler(EventHandlerRef inHandlerRef, UInt32 inNumTypes,
                                const EventTypeSpec *inList);

    /*��������������������������������������������������������������������������������������*/
    /* � Explicit Propogation */
    /* */
    /* CallNextEventHandler can be used to call thru to all handlers below the
     * current */
    /* handler being called. You pass the EventHandlerCallRef passed to your
     * EventHandler */
    /* into this call so that we know how to properly forward the event. The result
     * of */
    /* this function should normally be the result of your own handler that you
     * called */
    /* this API from. The typical use of this routine would be to allow the toolbox
     * to do */
    /* its standard processing and then follow up with some type of embellishment.
     */
    /*��������������������������������������������������������������������������������������*/

    EXTERN_API(OSStatus)
    CallNextEventHandler(EventHandlerCallRef inCallRef, EventRef inEvent);

    /*��������������������������������������������������������������������������������������*/
    /* � Sending Events */
    /*��������������������������������������������������������������������������������������*/
    EXTERN_API(OSStatus)
    SendEventToEventTarget(EventRef inEvent, EventTargetRef inTarget);

#define SendEventToApplication(e) \
    SendEventToEventTarget((e), GetApplicationEventTarget())

#define SendEventToWindow(e, t) \
    SendEventToEventTarget((e), GetWindowEventTarget(t))

#define SendEventToControl(e, t) \
    SendEventToEventTarget((e), GetControlEventTarget(t))

#define SendEventToMenu(e, t) SendEventToEventTarget((e), GetMenuEventTarget(t))

#define SendEventToUserFocus(e) \
    SendEventToEventTarget((e), GetUserFocusEventTarget())

    /*======================================================================================*/
    /* EVENT-BASED OBJECT CLASSES */
    /* */
    /* Here it is - the replacement for classic defprocs. This is also a convenient
     * way */
    /* to create toolbox objects (windows, etc.) that have a specific behavior
     * without */
    /* installing handlers on each instance of the object. With a toolbox object
     * class, */
    /* you register your class, then use special creation routines to create
     * objects of */
    /* that class. The event handlers are automatically installed and ready to go.
     */
    /*======================================================================================*/

    typedef struct OpaqueToolboxObjectClassRef *ToolboxObjectClassRef;

    EXTERN_API(OSStatus)
    RegisterToolboxObjectClass(CFStringRef inClassID,
                               ToolboxObjectClassRef inBaseClass, /* can be NULL */
                               UInt32 inNumEvents, const EventTypeSpec *inEventList,
                               EventHandlerUPP inEventHandler,
                               void *inEventHandlerData,
                               ToolboxObjectClassRef *outClassRef);

    EXTERN_API(OSStatus)
    UnregisterToolboxObjectClass(ToolboxObjectClassRef inClassRef);

    /*======================================================================================*/
    /* � Command Routines */
    /*======================================================================================*/

    EXTERN_API(OSStatus)
    ProcessHICommand(const HICommand *inCommand);

    /*��������������������������������������������������������������������������������������*/
    /* � Event Loop Routines */
    /*��������������������������������������������������������������������������������������*/

    EXTERN_API(void)
    RunApplicationEventLoop(void);

    EXTERN_API(void)
    QuitApplicationEventLoop(void);

    /*��������������������������������������������������������������������������������������*/
    /* � Event Modality routines */
    /*��������������������������������������������������������������������������������������*/

    EXTERN_API_C(OSStatus)
    RunAppModalLoopForWindow(WindowRef inWindow);

    EXTERN_API_C(OSStatus)
    QuitAppModalLoopForWindow(WindowRef inWindow);

    EXTERN_API_C(OSStatus)
    BeginAppModalStateForWindow(WindowRef inWindow);

    EXTERN_API_C(OSStatus)
    EndAppModalStateForWindow(WindowRef inWindow);

    /*��������������������������������������������������������������������������������������*/
    /* � User Focus */
    /* */
    /* The 'user focus' is where keyboard input goes. We also use the term 'key'
     * applied */
    /* to windows to mean this. The user focus window is normally the active
     * non-floating */
    /* window or dialog. It is possible to make a floater get the focus, however, by
     * calling*/
    /* SetUserFocusWindow. After that call, the event model will automatically route
     * key */
    /* input to the active keyboard focus of that window, if any. Passing
     * kUserFocusAuto */
    /* into the window parameter tells the toolbox to pick what it considers to be
     * the best */
    /* candidate for focus. You should call this to restore focus, rather than
     * getting the */
    /* focus, setting it to a special window, and then restoring to the saved focus.
     * There */
    /* are cases, however, when you might want to restore to an explicit window, but
     * the */
    /* typical usage should just be to restore to the kUserFocusAuto focus. */
    /* */
    /* Keep in mind that setting the focus will only last until you restore focus,
     * or the */
    /* user starts clicking in other windows. When that happens, the toolbox will
     * auto- */
    /* redirect the user focus to a newly selected window. */
    /*��������������������������������������������������������������������������������������*/
    enum
    {
        kUserFocusAuto = -1
    };

    EXTERN_API(OSStatus)
    SetUserFocusWindow(WindowRef inWindow);

    EXTERN_API(WindowRef)
    GetUserFocusWindow(void);

    /*��������������������������������������������������������������������������������������*/
    /* � Default/Cancel buttons */
    /* */
    /* In our quest to eliminate the need for dialogs when using the new event
     * model, we */
    /* have added the following routines which add dialog-like button control to
     * normal */
    /* windows. With these routines, you can set the default and cancel buttons for
     * a */
    /* window; these work just like the corresponding concepts in dialogs, and when
     */
    /* present, the standard toolbox handlers will handle keyboard input mapping to
     * these */
    /* buttons. This means that pressing return or enter will 'press' the default
     * button */
    /* and escape or command-period will 'press' the cancel button. */
    /*��������������������������������������������������������������������������������������*/

    EXTERN_API(OSStatus)
    SetWindowDefaultButton(WindowRef inWindow,
                           ControlRef inControl); /* can be NULL */

    EXTERN_API(OSStatus)
    SetWindowCancelButton(WindowRef inWindow,
                          ControlRef inControl); /* can be NULL */

    EXTERN_API(OSStatus)
    GetWindowDefaultButton(WindowRef inWindow, ControlRef *outControl);

    EXTERN_API(OSStatus)
    GetWindowCancelButton(WindowRef inWindow, ControlRef *outControl);

    /*��������������������������������������������������������������������������������������*/
    /* � Global HotKey API */
    /*��������������������������������������������������������������������������������������*/
    struct EventHotKeyID
    {
        OSType signature;
        UInt32 id;
    };
    typedef struct EventHotKeyID EventHotKeyID;
    typedef struct OpaqueEventHotKeyRef *EventHotKeyRef;
    EXTERN_API_C(OSStatus)
    RegisterEventHotKey(UInt32 inHotKeyCode, UInt32 inHotKeyModifiers,
                        EventHotKeyID inHotKeyID, EventTargetRef inTarget,
                        OptionBits inOptions, EventHotKeyRef *outRef);

    EXTERN_API_C(OSStatus)
    UnregisterEventHotKey(EventHotKeyRef inHotKey);

    /* OBSOLETE CONSTANTS*/

    enum
    {
        kMouseTrackingMousePressed = kMouseTrackingMouseDown,
        kMouseTrackingMouseReleased = kMouseTrackingMouseUp,
        kMouseTrackingMouseMoved = kMouseTrackingMouseDragged
    };

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

#endif /* __CARBONEVENTS__ */