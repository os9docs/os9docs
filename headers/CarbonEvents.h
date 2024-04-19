/**
     \file       CarbonEvents.h

    \brief   Carbon Event Manager

    \introduced_in  CarbonLib 1.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1999-2001 by Apple Computer, Inc., all rights reserved.
    
    \ingroup System
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
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
extern "C" {
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
/*  EVENT COMMON */
/*======================================================================================*/

/**
 *  Discussion:
 *    The following are all errors which can be returned from the
 *    routines contained in this file.
 */
enum {

  /**
   * This is returned from PostEventToQueue if the event in question is
   * already in the queue you are posting it to (or any other queue).
   */
  eventAlreadyPostedErr = -9860,

  /**
   * You are attemtping to modify a target that is currently in use,
   * such as when dispatching.
   */
  eventTargetBusyErr = -9861,

  /**
   * This is obsolete and will be removed.
   */
  eventClassInvalidErr = -9862,

  /**
   * This is obsolete and will be removed.
   */
  eventClassIncorrectErr = -9864,

  /**
   * Returned from InstallEventHandler if the handler proc you pass is
   * already installed for a given event type you are trying to
   * register.
   */
  eventHandlerAlreadyInstalledErr = -9866,

  /**
   * A generic error.
   */
  eventInternalErr = -9868,

  /**
   * This is obsolete and will be removed.
   */
  eventKindIncorrectErr = -9869,

  /**
   * The piece of data you are requesting from an event is not present.
   */
  eventParameterNotFoundErr = -9870,

  /**
   * This is what you should return from an event handler when your
   * handler has received an event it doesn't currently want to (or
   * isn't able to) handle. If you handle an event, you should return
   * noErr from your event handler.
   */
  eventNotHandledErr = -9874,

  /**
   * The event loop has timed out. This can be returned from calls to
   * ReceiveNextEvent or RunCurrentEventLoop.
   */
  eventLoopTimedOutErr = -9875,

  /**
   * The event loop was quit, probably by a call to QuitEventLoop. This
   * can be returned from ReceiveNextEvent or RunCurrentEventLoop.
   */
  eventLoopQuitErr = -9876,

  /**
   * Returned from RemoveEventFromQueue when trying to remove an event
   * that's not in any queue.
   */
  eventNotInQueueErr = -9877,
  eventHotKeyExistsErr = -9878,
  eventHotKeyInvalidErr = -9879
};

/*======================================================================================*/
/*  EVENT CORE */
/*======================================================================================*/
/*��������������������������������������������������������������������������������������*/
/*  � Event Flags, options */
/*��������������������������������������������������������������������������������������*/

/**
 *  EventPriority
 *
 *  Discussion:
 *    These values define the relative priority of an event, and are
 *    used when posting events with PostEventToQueue. In general events
 *    are pulled from the queue in order of first posted to last
 *    posted. These priorities are a way to alter that when posting
 *    events. You can post a standard priority event and then a high
 *    priority event and the high priority event will be pulled from
 *    the queue first.
 */
typedef SInt16 EventPriority;
enum {

  /**
   * Lowest priority. Currently only window update events are posted at
   * this priority.
   */
  kEventPriorityLow = 0,

  /**
   * Normal priority of events. Most events are standard priority.
   */
  kEventPriorityStandard = 1,

  /**
   * Highest priority.
   */
  kEventPriorityHigh = 2
};

enum { kEventLeaveInQueue = false, kEventRemoveFromQueue = true };

/*��������������������������������������������������������������������������������������*/
/* � Event Times */
/*                                                                                      */
/* EventTime is in seconds since boot. Use the constants to make life easy. */
/*��������������������������������������������������������������������������������������*/
typedef double EventTime;
typedef EventTime EventTimeout;
typedef EventTime EventTimerInterval;
#define kEventDurationSecond ((EventTime)1.0)
#define kEventDurationMillisecond ((EventTime)(kEventDurationSecond / 1000))
#define kEventDurationMicrosecond ((EventTime)(kEventDurationSecond / 1000000))
#define kEventDurationNanosecond                                               \
  ((EventTime)(kEventDurationSecond / 1000000000))
#define kEventDurationMinute ((EventTime)(kEventDurationSecond * 60))
#define kEventDurationHour ((EventTime)(kEventDurationMinute * 60))
#define kEventDurationDay ((EventTime)(kEventDurationHour * 24))
#define kEventDurationNoWait ((EventTime)0.0)
#define kEventDurationForever ((EventTime)(-1.0))

/* Helpful doodads to convert to and from ticks and event times*/
#ifdef __cplusplus
inline EventTime TicksToEventTime(UInt32 t) { return ((t) / 60.0); }
inline UInt32 EventTimeToTicks(EventTime t) {
  return (UInt32)(((t) * 60) + 0.5);
}
#else
#define TicksToEventTime(t) ((EventTime)((t) / 60.0))
#define EventTimeToTicks(t) ((UInt32)(((t) * 60) + 0.5))
#endif /* defined(__cplusplus) */

/*��������������������������������������������������������������������������������������*/
/* EventTypeSpec structure */
/*                                                                                      */
/* This structure is used in many routines to pass a list of event types to a
 * function. */
/* You typically would declare a const array of these types to pass in. */
/*��������������������������������������������������������������������������������������*/

/**
 *  EventTypeSpec
 *
 *  Discussion:
 *    This structure is used to specify an event. Typically, a static
 *    array of EventTypeSpecs are passed into functions such as
 *    InstallEventHandler, as well as routines such as
 *    FlushEventsMatchingListFromQueue.
 */
struct EventTypeSpec {
  UInt32 eventClass;
  UInt32 eventKind;
};
typedef struct EventTypeSpec EventTypeSpec;
/*A helpful macro for dealing with EventTypeSpecs */
#define GetEventTypeCount(t) (sizeof((t)) / sizeof(EventTypeSpec))

/**
 *  Discussion:
 *    These are returned from calls to TrackMouseLocation and
 *    TrackMouseRegion. Those routines are designed as replacements to
 *    calls such as StillDown and WaitMouseUp. The advantage over those
 *    routines is that TrackMouseLocation and TrackMouseRegion will
 *    block if the user is not moving the mouse, whereas mouse tracking
 *    loops based on StillDown and WaitMouseUp will spin, chewing up
 *    valuable CPU time that could be better spent elsewhere. It is
 *    highly recommended that any tracking loops in your application
 *    stop using StillDown and WaitMouseUp and start using
 *    TrackMouseLocation/Region. See the notes on those routines for
 *    more information.
 */
enum { kTrackMouseLocationOptionDontConsumeMouseUp = (1 << 0) };

typedef UInt16 MouseTrackingResult;
enum {
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
/*  � EventLoop */
/*��������������������������������������������������������������������������������������*/

/**
 *  EventLoopRef
 *
 *  Discussion:
 *    An EventLoopRef represents an 'event loop', which is the
 *    conceptual entity that you 'run' to fetch events from hardware
 *    and other sources and also fires timers that might be installed
 *    with InstallEventLoopTimer. The term 'run' is a bit of a
 *    misnomer, as the event loop's goal is to stay as blocked as
 *    possible to minimize CPU usage for the current application. The
 *    event loop is run implicitly thru APIs like ReceiveNextEvent,
 *    RunApplicationEventLoop, or even WaitNextEvent. It can also be
 *    run explicitly thru a call to RunCurrentEventLoop. Each
 *    preemptive thread can have an event loop. Cooperative threads
 *    share the main thread's event loop.
 */
typedef struct OpaqueEventLoopRef *EventLoopRef;
/**
 *  GetCurrentEventLoop()
 *
 *  Discussion:
 *    Returns the current event loop for the current thread. If the
 *    current thread is a cooperative thread, the main event loop is
 *    returned.
 *
 *  Result:
 *    An event loop reference.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventLoopRef)
GetCurrentEventLoop(void);

/**
 *  GetMainEventLoop()
 *
 *  Discussion:
 *    Returns the event loop object for the main application thread.
 *
 *  Result:
 *    An event loop reference.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventLoopRef)
GetMainEventLoop(void);

/**
 *  RunCurrentEventLoop()
 *
 *  Discussion:
 *    This routine 'runs' the event loop, returning only if aborted or
 *    the timeout specified is reached. The event loop is mostly
 *    blocked while in this function, occasionally waking up to fire
 *    timers or pick up events. The typical use of this function is to
 *    cause the current thread to wait for some operation to complete,
 *    most likely on another thread of execution.
 *
 *  Parameters:
 *
 *    inTimeout:
 *      The time to wait until returning (can be kEventDurationForever).
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
RunCurrentEventLoop(EventTimeout inTimeout);

/**
 *  QuitEventLoop()
 *
 *  Discussion:
 *    Causes a specific event loop to terminate. Usage of this is
 *    similar to WakeUpProcess, in that it causes the eventloop
 *    specified to return immediately (as opposed to timing out).
 *    Typically this call is used in conjunction with
 *    RunCurrentEventLoop.
 *
 *  Parameters:
 *
 *    inEventLoop:
 *      The event loop to terminate.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
QuitEventLoop(EventLoopRef inEventLoop);

/**
 *  GetCFRunLoopFromEventLoop()
 *
 *  Discussion:
 *    Returns the corresponding CFRunLoopRef for the given EventLoop.
 *    This is not necessarily a one-to-one mapping, hence the need for
 *    this function. In Carbon, all cooperative threads use the same
 *    run loop under the covers, so using CFRunLoopGetCurrent might
 *    yield the wrong result. In general, you would only need to use
 *    this function if you wished to add your own sources to the run
 *    loop. If you don't know what I'm talking about, then you probably
 *    don't need to use this.
 *
 *  Parameters:
 *
 *    inEventLoop:
 *      The event loop to get the CFRunLoop for.
 *
 *  Result:
 *    The CFRunLoopRef for inEventLoop.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.1 and later \mac_os_x         in version 10.1 and later
 */
EXTERN_API_C(CFTypeRef)
GetCFRunLoopFromEventLoop(EventLoopRef inEventLoop);

/*��������������������������������������������������������������������������������������*/
/*  � Low-level event fetching */
/*��������������������������������������������������������������������������������������*/
/**
 *  ReceiveNextEvent()
 *
 *  Discussion:
 *    This routine tries to fetch the next event of a specified type.
 *    If no events in the event queue match, this routine will run the
 *    current event loop until an event that matches arrives, or the
 *    timeout expires. Except for timers firing, your application is
 *    blocked waiting for events to arrive when inside this function.
 *
 *  Parameters:
 *
 *    inNumTypes:
 *      The number of event types we are waiting for (0 if any event
 *      should cause this routine to return).
 *
 *    inList:
 *      The list of event types we are waiting for (pass NULL if any
 *      event should cause this routine to return).
 *
 *    inTimeout:
 *      The time to wait (passing kEventDurationForever is preferred).
 *
 *    inPullEvent:
 *      Pass true for this parameter to actually remove the next
 *      matching event from the queue.
 *
 *    outEvent:
 *      The next event that matches the list passed in. If inPullEvent
 *      is true, the event is owned by you, and you will need to
 *      release it when done.
 *
 *  Result:
 *    A result indicating whether an event was received, the timeout
 *    expired, or the current event loop was quit.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
ReceiveNextEvent(UInt32 inNumTypes, const EventTypeSpec *inList,
                 EventTimeout inTimeout, Boolean inPullEvent,
                 EventRef *outEvent);

/*��������������������������������������������������������������������������������������*/
/*  � Core event lifetime APIs */
/*��������������������������������������������������������������������������������������*/
typedef UInt32 EventAttributes;
enum { kEventAttributeNone = 0, kEventAttributeUserEvent = (1 << 0) };

/**
 *  [Mac]CreateEvent()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacCreateEvent CreateEvent
#endif
EXTERN_API(OSStatus)
MacCreateEvent(CFAllocatorRef inAllocator, /* can be NULL */
               UInt32 inClassID, UInt32 kind, EventTime when,
               EventAttributes flags, EventRef *outEvent);

/**
 *  CopyEvent()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventRef)
CopyEvent(EventRef inOther);

/**
 *  RetainEvent()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventRef)
RetainEvent(EventRef inEvent);

/**
 *  GetEventRetainCount()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(UInt32)
GetEventRetainCount(EventRef inEvent);

/**
 *  ReleaseEvent()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
ReleaseEvent(EventRef inEvent);

/**
 *  SetEventParameter()
 *
 *  Discussion:
 *    Sets a piece of data for the given event.
 *
 *  Parameters:
 *
 *    inEvent:
 *      The event to set the data for.
 *
 *    inName:
 *      The symbolic name of the parameter.
 *
 *    inType:
 *      The symbolic type of the parameter.
 *
 *    inSize:
 *      The size of the parameter data.
 *
 *    inDataPtr:
 *      The pointer to the parameter data.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
SetEventParameter(EventRef inEvent, EventParamName inName,
                  EventParamType inType, UInt32 inSize, const void *inDataPtr);

/**
 *  GetEventParameter()
 *
 *  Discussion:
 *    Gets a piece of data from the given event, if it exists.
 *
 *  Parameters:
 *
 *    inEvent:
 *      The event to get the parameter from.
 *
 *    inName:
 *      The symbolic name of the parameter.
 *
 *    inDesiredType:
 *      The desired type of the parameter. At present we do not support
 *      coercion, so this parameter must be the actual type of data
 *      stored in the event, or an error will be returned.
 *
 *    outActualType:
 *      The actual type of the parameter, can be NULL if you are not
 *      interested in receiving this information.
 *
 *    inBufferSize:
 *      The size of the output buffer specified by ioBuffer.
 *
 *    outActualSize:
 *      The actual size of the data, or NULL if you don't want this
 *      information.
 *
 *    outData:
 *      The pointer to the buffer which will receive the parameter data.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
GetEventParameter(EventRef inEvent, EventParamName inName,
                  EventParamType inDesiredType,
                  EventParamType *outActualType,              /* can be NULL */
                  UInt32 inBufferSize, UInt32 *outActualSize, /* can be NULL */
                  void *outData);

/*��������������������������������������������������������������������������������������*/
/*  � Getters for 'base-class' event info */
/*��������������������������������������������������������������������������������������*/
/**
 *  GetEventClass()
 *
 *  Discussion:
 *    Returns the class of the given event, such as mouse, keyboard,
 *    etc.
 *
 *  Parameters:
 *
 *    inEvent:
 *      The event in question.
 *
 *  Result:
 *    The class ID of the event.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(UInt32)
GetEventClass(EventRef inEvent);

/**
 *  GetEventKind()
 *
 *  Discussion:
 *    Returns the kind of the given event (mousedown, etc.). Event
 *    kinds overlap between event classes, e.g. kEventMouseDown and
 *    kEventAppActivated have the same value (1). The combination of
 *    class and kind is what determines an event signature.
 *
 *  Parameters:
 *
 *    inEvent:
 *      The event in question.
 *
 *  Result:
 *    The kind of the event.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(UInt32)
GetEventKind(EventRef inEvent);

/**
 *  GetEventTime()
 *
 *  Discussion:
 *    Returns the time the event specified occurred, specified in
 *    EventTime, which is a floating point number representing seconds
 *    since the last system startup.
 *
 *  Parameters:
 *
 *    inEvent:
 *      The event in question.
 *
 *  Result:
 *    The time the event occurred.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventTime)
GetEventTime(EventRef inEvent);

/*��������������������������������������������������������������������������������������*/
/*  � Setters for 'base-class' event info */
/*��������������������������������������������������������������������������������������*/

/**
 *  SetEventTime()
 *
 *  Discussion:
 *    This routine allows you to set the time of a given event, if you
 *    so desire. In general, you would never use this routine, except
 *    for those special cases where you reuse an event from time to
 *    time instead of creating a new event each time.
 *
 *  Parameters:
 *
 *    inEvent:
 *      The event in question.
 *
 *    inTime:
 *      The new time.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
SetEventTime(EventRef inEvent, EventTime inTime);

/*��������������������������������������������������������������������������������������*/
/*  � Event Queue routines (posting, finding, flushing) */
/*��������������������������������������������������������������������������������������*/

typedef struct OpaqueEventQueueRef *EventQueueRef;
/**
 *  GetCurrentEventQueue()
 *
 *  Discussion:
 *    Returns the current event queue for the current thread. If the
 *    current thread is a cooperative thread, the main event queue is
 *    returned.
 *
 *  Result:
 *    An event queue reference.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventQueueRef)
GetCurrentEventQueue(void);

/**
 *  GetMainEventQueue()
 *
 *  Discussion:
 *    Returns the event queue object for the main application thread.
 *
 *  Result:
 *    An event queue reference.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventQueueRef)
GetMainEventQueue(void);

/**
 *  EventComparatorProcPtr
 *
 *  Discussion:
 *    Type of a callback function used by queue searches.
 *
 *  Parameters:
 *
 *    inEvent:
 *      The event to compare.
 *
 *    inCompareData:
 *      The data used to compare the event.
 *
 *  Result:
 *    A boolean value indicating whether the event matches (true) or
 *    not (false).
 */
typedef CALLBACK_API(Boolean, EventComparatorProcPtr)(EventRef inEvent,
                                                      void *inCompareData);
typedef STACK_UPP_TYPE(EventComparatorProcPtr) EventComparatorUPP;
/**
 *  NewEventComparatorUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(EventComparatorUPP)
NewEventComparatorUPP(EventComparatorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppEventComparatorProcInfo = 0x000003D0
}; /* pascal 1_byte Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
inline EventComparatorUPP
NewEventComparatorUPP(EventComparatorProcPtr userRoutine) {
  return (EventComparatorUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppEventComparatorProcInfo,
                                                  GetCurrentArchitecture());
}
#else
#define NewEventComparatorUPP(userRoutine)                                     \
  (EventComparatorUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppEventComparatorProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeEventComparatorUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposeEventComparatorUPP(EventComparatorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeEventComparatorUPP(EventComparatorUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeEventComparatorUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeEventComparatorUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
InvokeEventComparatorUPP(EventRef inEvent, void *inCompareData,
                         EventComparatorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline Boolean InvokeEventComparatorUPP(EventRef inEvent, void *inCompareData,
                                        EventComparatorUPP userUPP) {
  return (Boolean)CALL_TWO_PARAMETER_UPP(userUPP, uppEventComparatorProcInfo,
                                         inEvent, inCompareData);
}
#else
#define InvokeEventComparatorUPP(inEvent, inCompareData, userUPP)              \
  (Boolean) CALL_TWO_PARAMETER_UPP((userUPP), uppEventComparatorProcInfo,      \
                                   (inEvent), (inCompareData))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewEventComparatorProc(userRoutine) NewEventComparatorUPP(userRoutine)
#define CallEventComparatorProc(userRoutine, inEvent, inCompareData)           \
  InvokeEventComparatorUPP(inEvent, inCompareData, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

/**
 *  PostEventToQueue()
 *
 *  Discussion:
 *    Posts an event to the queue specified. This automatically wakes
 *    up the event loop of the thread the queue belongs to. After
 *    posting the event, you should release the event. The event queue
 *    retains it.
 *
 *  Parameters:
 *
 *    inQueue:
 *      The event queue to post the event onto.
 *
 *    inEvent:
 *      The event to post.
 *
 *    inPriority:
 *      The priority of the event.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PostEventToQueue(EventQueueRef inQueue, EventRef inEvent,
                 EventPriority inPriority);

/**
 *  FlushEventsMatchingListFromQueue()
 *
 *  Discussion:
 *    Flushes events matching a specified list of classes and kinds
 *    from an event queue.
 *
 *  Parameters:
 *
 *    inQueue:
 *      The event queue to flush events from.
 *
 *    inNumTypes:
 *      The number of event kinds to flush.
 *
 *    inList:
 *      The list of event classes and kinds to flush from the queue.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
FlushEventsMatchingListFromQueue(EventQueueRef inQueue, UInt32 inNumTypes,
                                 const EventTypeSpec *inList);

/**
 *  FlushSpecificEventsFromQueue()
 *
 *  Discussion:
 *    Flushes events that match a comparator function.
 *
 *  Parameters:
 *
 *    inQueue:
 *      The event queue to flush events from.
 *
 *    inComparator:
 *      The comparison function to invoke for each event in the queue.
 *
 *    inCompareData:
 *      The data you wish to pass to your comparison function.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
FlushSpecificEventsFromQueue(EventQueueRef inQueue,
                             EventComparatorUPP inComparator,
                             void *inCompareData);

/**
 *  FlushEventQueue()
 *
 *  Discussion:
 *    Flushes all events from an event queue.
 *
 *  Parameters:
 *
 *    inQueue:
 *      The event queue to flush.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
FlushEventQueue(EventQueueRef inQueue);

/**
 *  FindSpecificEventInQueue()
 *
 *  Discussion:
 *    Returns the first event that matches a comparator function, or
 *    NULL if no events match.
 *
 *  Parameters:
 *
 *    inQueue:
 *      The event queue to search.
 *
 *    inComparator:
 *      The comparison function to invoke for each event in the queue.
 *
 *    inCompareData:
 *      The data you wish to pass to your comparison function.
 *
 *  Result:
 *    An event reference.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventRef)
FindSpecificEventInQueue(EventQueueRef inQueue, EventComparatorUPP inComparator,
                         void *inCompareData);

/**
 *  GetNumEventsInQueue()
 *
 *  Discussion:
 *    Returns the number of events in an event queue.
 *
 *  Parameters:
 *
 *    inQueue:
 *      The event queue to query.
 *
 *  Result:
 *    The number of items in the queue.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(UInt32)
GetNumEventsInQueue(EventQueueRef inQueue);

/**
 *  RemoveEventFromQueue()
 *
 *  Discussion:
 *    Removes the given event from the queue which it was posted. When
 *    you call this function, the event ownership is transferred to
 *    you, the caller, at no charge. You must release the event when
 *    you are through with it.
 *
 *  Parameters:
 *
 *    inQueue:
 *      The queue to remove the event from.
 *
 *    inEvent:
 *      The event to remove.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
RemoveEventFromQueue(EventQueueRef inQueue, EventRef inEvent);

/**
 *  IsEventInQueue()
 *
 *  Discussion:
 *    Returns true if the specified event is posted to a queue.
 *
 *  Parameters:
 *
 *    inQueue:
 *      The queue to check.
 *
 *    inEvent:
 *      The event in question.
 *
 *  Result:
 *    A boolean value.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
IsEventInQueue(EventQueueRef inQueue, EventRef inEvent);

/*��������������������������������������������������������������������������������������*/
/*  � Helpful utilities */
/*��������������������������������������������������������������������������������������*/

/**
 *  GetCurrentEventTime()
 *
 *  Discussion:
 *    Returns the current time since last system startup in seconds.
 *
 *  Result:
 *    EventTime.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventTime)
GetCurrentEventTime(void);

/**
 *  IsUserCancelEventRef()
 *
 *  Discussion:
 *    Tests the event given to see whether the event represents a 'user
 *    cancel' event. Currently this is defined to be either the escape
 *    key being pressed, or command-period being pressed.
 *
 *  Result:
 *    A boolean value indicating whether the event is a user cancel
 *    event.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
IsUserCancelEventRef(EventRef event);

/**
 *  TrackMouseLocation()
 *
 *  Discussion:
 *    Once entered, this routine waits for certain mouse events (move,
 *    mouse down, mouse up). When one of these events occurs, the
 *    function returns and tells the caller what happened and where the
 *    mouse is currently located. While there is no activity, the
 *    current event loop is run, effectively blocking the current
 *    thread (save for any timers that fire). This helps to minimize
 *    CPU usage when there is nothing going on.
 *
 *  Parameters:
 *
 *    inPort:
 *      The grafport to consider for mouse coordinates. You can pass
 *      NULL for this parameter to indicate the current port. The mouse
 *      location is returned in terms of local coordinates of this port.
 *
 *    outPt:
 *      On exit, this parameter receives the mouse location from the
 *      last mouse event that caused this function to exit.
 *
 *    outResult:
 *      On exit, this parameter receives a value representing what kind
 *      of event was received that cause the function to exit, such as
 *      kMouseTrackingMouseReleased.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
TrackMouseLocation(GrafPtr inPort, /* can be NULL */
                   Point *outPt, MouseTrackingResult *outResult);

/**
 *  TrackMouseLocationWithOptions()
 *
 *  Discussion:
 *    Once entered, this routine waits for certain mouse events (move,
 *    mouse down, mouse up). When one of these events occurs, the
 *    function returns and tells the caller what happened and where the
 *    mouse is currently located. While there is no activity, the
 *    current event loop is run, effectively blocking the current
 *    thread (save for any timers that fire). This helps to minimize
 *    CPU usage when there is nothing going on.
 *
 *  Parameters:
 *
 *    inPort:
 *      The grafport to consider for mouse coordinates. You can pass
 *      NULL for this parameter to indicate the current port. The mouse
 *      location is returned in terms of local coordinates of this port.
 *
 *    inOptions:
 *      The only option supported by this routine at present is the
 *      option to have the toolbox leave mouse up events in the queue,
 *      rather than pulling them (which is the default).
 *
 *    inTimeout:
 *      The amount of time to wait for an event. If no events arrive
 *      within this time, kMouseTrackingTimedOut is returned in
 *      outResult.
 *
 *    outPt:
 *      On exit, this parameter receives the mouse location from the
 *      last mouse event that caused this function to exit. If a
 *      timeout or key modifiers changed event caused this function to
 *      exit, the current mouse position at the time is returned.
 *
 *    outModifiers:
 *      On exit, this parameter receives the most recent state of the
 *      keyboard modifiers.
 *
 *    outResult:
 *      On exit, this parameter receives a value representing what kind
 *      of event was received that cause the function to exit, such as
 *      kMouseTrackingMouseReleased.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(OSStatus)
TrackMouseLocationWithOptions(GrafPtr inPort, /* can be NULL */
                              OptionBits inOptions, EventTimeout inTimeout,
                              Point *outPt,
                              UInt32 *outModifiers, /* can be NULL */
                              MouseTrackingResult *outResult);

/**
 *  TrackMouseRegion()
 *
 *  Discussion:
 *    This routine is largely identical to TrackMouseLocation. Please
 *    read the notes on that function as well. The difference between
 *    TrackMouseLocation and TrackMouseRegion is that TrackMouseRegion
 *    only returns when the mouse enters or exits a specified region
 *    that you pass in to the function, as opposed to whenever the
 *    mouse moves (it also returns for mouse up/down events). This is
 *    useful if you don't need to know intermediate mouse events, but
 *    rather just if the mouse enters or leaves an area.
 *
 *  Parameters:
 *
 *    inPort:
 *      The grafport to consider for mouse coordinates. You can pass
 *      NULL for this parameter to indicate the current port.
 *
 *    inRegion:
 *      The region to consider. This should be in the coordinates of
 *      the port you passed to inPort.
 *
 *    ioWasInRgn:
 *      On enter, this parameter should be set to true if the mouse is
 *      currently inside the region passed in inRegion, or false if the
 *      mouse is currently outside the region. On exit, this parameter
 *      is updated to reflect the current reality, e.g. if the
 *      outResult parameter returns kMouseTrackingMouseExited,
 *      ioWasInRgn will be set to false when this function exits.
 *      Because it is updated from within, you should only need to set
 *      this yourself before the first call to this function in your
 *      tracking loop.
 *
 *    outResult:
 *      On exit, this parameter receives a value representing what kind
 *      of event was received that cause the function to exit, such as
 *      kMouseTrackingMouseEntered.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
TrackMouseRegion(GrafPtr inPort, /* can be NULL */
                 RgnHandle inRegion, Boolean *ioWasInRgn,
                 MouseTrackingResult *outResult);

/**
 *  ConvertEventRefToEventRecord()
 *
 *  Discussion:
 *    This is a convenience routine to help you if there are places in
 *    your application where you need an EventRecord and all you have
 *    is an EventRef. If the event can be converted, outEvent is filled
 *    in and the function returns true. If not, false is returned and
 *    outEvent will contain a nullEvent.
 *
 *  Parameters:
 *
 *    inEvent:
 *      The EventRef to convert into an EventRecord.
 *
 *    outEvent:
 *      The EventRecord to fill out.
 *
 *  Result:
 *    A boolean indicating if the conversion was successful (true) or
 *    not (false).
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
ConvertEventRefToEventRecord(EventRef inEvent, EventRecord *outEvent);

/**
 *  IsEventInMask()
 *
 *  Discussion:
 *    This is a companion function for ConvertEventRefToEventRecord,
 *    and is provided as a convenience routine to help you if there are
 *    places in your application where you want to check an EventRef to
 *    see if it matches a classic EventMask bitfield. If the event
 *    matches, the function returns true.
 *
 *  Parameters:
 *
 *    inEvent:
 *      The EventRef to convert into an EventRecord.
 *
 *    inMask:
 *      The mask to consider.
 *
 *  Result:
 *    A boolean indicating if the event was considered to be in the
 *    mask provided.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
IsEventInMask(EventRef inEvent, EventMask inMask);

/**
 *  GetLastUserEventTime()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventTime)
GetLastUserEventTime(void);

/*��������������������������������������������������������������������������������������*/
/*  � Mouse Coalescing */
/*��������������������������������������������������������������������������������������*/
/**
 *  IsMouseCoalescingEnabled()
 *
 *  Discussion:
 *    Returns true if mouse coalescing is current enabled. When
 *    enabled, we coalesce mouse moved and mouse dragged events. By
 *    default, coalescing is on, but you can use
 *    SetMouseCoalescingEnabled to disable it if you want finer-grained
 *    mouse movement events, which is useful for drawing with tablets.
 *
 *  Result:
 *    A boolean indicating if coalescing is enabled.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.1 and later \mac_os_x         in version 10.1 and later
 */
EXTERN_API_C(Boolean)
IsMouseCoalescingEnabled(void);

/**
 *  SetMouseCoalescingEnabled()
 *
 *  Discussion:
 *    Allows you to set mouse move/drag event coalescing on or off. By
 *    default, coalescing is on, but you can use this function to
 *    disable it if you want finer-grained mouse movement events, which
 *    is useful for drawing with tablets.
 *
 *  Parameters:
 *
 *    inNewState:
 *      A boolean indicating if coalescing should be enabled (true) or
 *      disabled (false).
 *
 *    outOldState:
 *      A boolean which receives the prior state of mouse coalescing
 *      for restoration later. You can pass NULL for this parameter if
 *      you don't care.
 *
 *  Result:
 *    An operating system status result.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.1 and later \mac_os_x         in version 10.1 and later
 */
EXTERN_API_C(OSStatus)
SetMouseCoalescingEnabled(Boolean inNewState,
                          Boolean *outOldState); /* can be NULL */

/*��������������������������������������������������������������������������������������*/
/*  � Timers */
/*��������������������������������������������������������������������������������������*/

/**
 *  EventLoopTimerRef
 *
 *  Discussion:
 *    An EventLoopTimerRef represents what we term a 'timer'. A timer
 *    is a function that is called either once or at regular intervals.
 *    It executes at task level and should not be confused with Time
 *    Manager Tasks or any other interrupt-level callback. This means
 *    you can call Toolbox routines, allocate memory and draw. When a
 *    timer 'fires', it calls a callback that you specify when the
 *    timer is installed. Timers in general have two uses - as a
 *    timeout mechanism and as a periodic task. An everyday example of
 *    using a timer for a timeout might be a light that goes out if no
 *    motion is detected in a room for 5 minutes. For this, you might
 *    install a timer which will fire in 5 minutes. If motion is
 *    detected, you would reset the timer fire time and let the clock
 *    start over. If no motion is detected for the full 5 minutes, the
 *    timer will fire and you could power off the light. A periodic
 *    timer is one that fires at regular intervals (say every second or
 *    so). You might use such a timer to blink the insertion point in
 *    your editor, etc. One advantage of timers is that you can install
 *    the timer right from the code that wants the time. For example,
 *    the standard Toolbox Edit Text control can install a timer to
 *    blink the cursor when it's active, meaning that IdleControls is a
 *    no-op for that control and doesn't need to be called. When the
 *    control is inactive, it removes its timer and doesn't waste CPU
 *    time in that state. NOTE: Currently, if you do decide to draw
 *    when your timer is called, be sure to save and restore the
 *    current port so that calling your timer doesn't inadvertently
 *    change the port out from under someone.
 */
typedef struct OpaqueEventLoopTimerRef *EventLoopTimerRef;

/**
 *  EventLoopTimerProcPtr
 *
 *  Discussion:
 *    Called when a timer fires.
 *
 *  Parameters:
 *
 *    inTimer:
 *      The timer that fired.
 *
 *    inUserData:
 *      The data passed into InstallEventLoopTimer.
 */
typedef CALLBACK_API(void, EventLoopTimerProcPtr)(EventLoopTimerRef inTimer,
                                                  void *inUserData);
typedef STACK_UPP_TYPE(EventLoopTimerProcPtr) EventLoopTimerUPP;
/**
 *  NewEventLoopTimerUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(EventLoopTimerUPP)
NewEventLoopTimerUPP(EventLoopTimerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppEventLoopTimerProcInfo = 0x000003C0
}; /* pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
inline EventLoopTimerUPP
NewEventLoopTimerUPP(EventLoopTimerProcPtr userRoutine) {
  return (EventLoopTimerUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppEventLoopTimerProcInfo,
                                                 GetCurrentArchitecture());
}
#else
#define NewEventLoopTimerUPP(userRoutine)                                      \
  (EventLoopTimerUPP)                                                          \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppEventLoopTimerProcInfo,  \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeEventLoopTimerUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposeEventLoopTimerUPP(EventLoopTimerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeEventLoopTimerUPP(EventLoopTimerUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeEventLoopTimerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeEventLoopTimerUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
InvokeEventLoopTimerUPP(EventLoopTimerRef inTimer, void *inUserData,
                        EventLoopTimerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void InvokeEventLoopTimerUPP(EventLoopTimerRef inTimer, void *inUserData,
                                    EventLoopTimerUPP userUPP) {
  CALL_TWO_PARAMETER_UPP(userUPP, uppEventLoopTimerProcInfo, inTimer,
                         inUserData);
}
#else
#define InvokeEventLoopTimerUPP(inTimer, inUserData, userUPP)                  \
  CALL_TWO_PARAMETER_UPP((userUPP), uppEventLoopTimerProcInfo, (inTimer),      \
                         (inUserData))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewEventLoopTimerProc(userRoutine) NewEventLoopTimerUPP(userRoutine)
#define CallEventLoopTimerProc(userRoutine, inTimer, inUserData)               \
  InvokeEventLoopTimerUPP(inTimer, inUserData, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

/**
 *  InstallEventLoopTimer()
 *
 *  Discussion:
 *    Installs a timer onto the event loop specified. The timer can
 *    either fire once or repeatedly at a specified interval depending
 *    on the parameters passed to this function.
 *
 *  Parameters:
 *
 *    inEventLoop:
 *      The event loop to add the timer.
 *
 *    inFireDelay:
 *      The delay before first firing this timer (can be 0, to request
 *      that the timer be fired as soon as control returns to your
 *      event loop). In Mac OS X and CarbonLib 1.5 and later, you may
 *      pass kEventDurationForever to stop the timer from firing at all
 *      until SetEventLoopTimerNextFireTime is used to start it; in
 *      earlier CarbonLibs, to achieve the same effect, just pass zero
 *      and then immediately call SetEventLoopTimerNextFireTime( timer,
 *      kEventDurationForever ) before returning control to your event
 *      loop.
 *
 *    inInterval:
 *      The timer interval (pass 0 for a one-shot timer, which executes
 *      once but does not repeat). In Mac OS X and CarbonLib 1.5 and
 *      later, you may also pass kEventDurationForever to create a
 *      one-shot timer.
 *
 *    inTimerProc:
 *      The routine to call when the timer fires.
 *
 *    inTimerData:
 *      Data to pass to the timer proc when called.
 *
 *    outTimer:
 *      A reference to the newly installed timer.
 *
 *  Result:
 *    An operating system status code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
InstallEventLoopTimer(EventLoopRef inEventLoop, EventTimerInterval inFireDelay,
                      EventTimerInterval inInterval,
                      EventLoopTimerUPP inTimerProc, void *inTimerData,
                      EventLoopTimerRef *outTimer);

/**
 *  RemoveEventLoopTimer()
 *
 *  Discussion:
 *    Removes a timer that was previously installed by a call to
 *    InstallEventLoopTimer. You call this function when you are done
 *    using a timer.
 *
 *  Parameters:
 *
 *    inTimer:
 *      The timer to remove.
 *
 *  Result:
 *    An operating system status code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
RemoveEventLoopTimer(EventLoopTimerRef inTimer);

/**
 *  SetEventLoopTimerNextFireTime()
 *
 *  Discussion:
 *    This routine is used to 'reset' a timer. It controls the next
 *    time the timer fires. This will override any interval you might
 *    have set. For example, if you have a timer that fires every
 *    second, and you call this function setting the next time to five
 *    seconds from now, the timer will sleep for five seconds, then
 *    fire. It will then resume its one-second interval after that. It
 *    is as if you removed the timer and reinstalled it with a new
 *    first-fire delay.
 *
 *  Parameters:
 *
 *    inTimer:
 *      The timer to adjust
 *
 *    inNextFire:
 *      The interval from the current time to wait until firing the
 *      timer again. You may pass kEventDurationForever to stop the
 *      timer from firing at all.
 *
 *  Result:
 *    An operating system status code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
SetEventLoopTimerNextFireTime(EventLoopTimerRef inTimer,
                              EventTimerInterval inNextFire);

/*======================================================================================*/
/*  EVENT CLASSES */
/*======================================================================================*/

/**
 *  Discussion:
 *    Event classes
 */
enum {

  /**
   * Events related to the mouse (mouse down/up/moved).
   */
  kEventClassMouse = FOUR_CHAR_CODE('mous'),

  /**
   * Events related to the keyboard.
   */
  kEventClassKeyboard = FOUR_CHAR_CODE('keyb'),

  /**
   * Events related to text input (by keyboard, or by input method).
   */
  kEventClassTextInput = FOUR_CHAR_CODE('text'),

  /**
   * Application-level events (launch, quit, etc.).
   */
  kEventClassApplication = FOUR_CHAR_CODE('appl'),

  /**
   * Apple Events.
   */
  kEventClassAppleEvent = FOUR_CHAR_CODE('eppc'),

  /**
   * Menu-related events.
   */
  kEventClassMenu = FOUR_CHAR_CODE('menu'),

  /**
   * Window-related events.
   */
  kEventClassWindow = FOUR_CHAR_CODE('wind'),

  /**
   * Control-related events.
   */
  kEventClassControl = FOUR_CHAR_CODE('cntl'),

  /**
   * Command events (HICommands).
   */
  kEventClassCommand = FOUR_CHAR_CODE('cmds'),

  /**
   * Events related to tablets.
   */
  kEventClassTablet = FOUR_CHAR_CODE('tblt'),

  /**
   * Events related to File Manager volumes.
   */
  kEventClassVolume = FOUR_CHAR_CODE('vol '),

  /**
   * Events related to the Appearance Manager.
   */
  kEventClassAppearance = FOUR_CHAR_CODE('appm'),

  /**
   * Events related to the Services Manager.
   */
  kEventClassService = FOUR_CHAR_CODE('serv')
};

/*��������������������������������������������������������������������������������������*/
/* Mouse Events */
/*��������������������������������������������������������������������������������������*/
/* Mouse Events */

/**
 *  Discussion:
 *    Mouse events (kEventClassMouse)
 */
enum {

  /**
   * A mouse button was pressed.
   */
  kEventMouseDown = 1,

  /**
   * A mouse button was released.
   */
  kEventMouseUp = 2,

  /**
   * The mouse was moved.
   */
  kEventMouseMoved = 5,

  /**
   * The mouse was moved, and a button was down.
   */
  kEventMouseDragged = 6,

  /**
   * The mouse wheel was moved. (Mac OS X only)
   */
  kEventMouseWheelMoved = 10
};

/**
 *  HIPoint
 *
 *  Discussion:
 *    HIPoint is a new, floating point-based type to help express
 *    coordinates in a much richer fashion than the classic QuickDraw
 *    points. It will, in time, be more heavily used throughout the
 *    Toolbox. For now, it is replacing our use of typeQDPoint in mouse
 *    events. This is to better support sub-pixel tablet coordinates.
 *    If you ask for a mouse location with typeQDPoint, and the point
 *    is actually stored as typeHIPoint, it will automatically be
 *    coerced to typeQDPoint for you, so this change should be largely
 *    transparent to applications. HIPoints are in screen space, i.e.
 *    the top left of the screen is 0, 0.
 */
struct HIPoint {

  /**
   * The horizontal coordinate of the point.
   */
  float x;

  /**
   * The vertical coordinate of the point.
   */
  float y;
};
typedef struct HIPoint HIPoint;
/**
    Parameters for mouse events:

    kEventMouseDown
        -->     kEventParamMouseLocation    typeHIPoint
        -->     kEventParamKeyModifiers     typeUInt32
        -->     kEventParamMouseButton      typeMouseButton
        -->     kEventParamClickCount       typeUInt32
        -->     kEventParamMouseChord       typeUInt32  (Mac OS X only)
        -->     kEventParamTabletEventType  typeUInt32  (Mac OS X 10.1,
   CarbonLib 1.5, and later)
        -->     kEventParamTabletPointRec   typeTabletPointRec          (if
   kEventParamTabletEventType is kEventTabletPoint)
        -->     kEventParamTabletProximityRec typeTabletProximityRec    (if
   kEventParamTabletEventType is kEventTabletProximity)

    kEventMouseUp
        -->     kEventParamMouseLocation    typeHIPoint
        -->     kEventParamKeyModifiers     typeUInt32
        -->     kEventParamMouseButton      typeMouseButton
        -->     kEventParamClickCount       typeUInt32
        -->     kEventParamMouseChord       typeUInt32  (Mac OS X only)
        -->     kEventParamTabletEventType  typeUInt32  (Mac OS X 10.1,
   CarbonLib 1.5, and later)
        -->     kEventParamTabletPointRec   typeTabletPointRec          (if
   kEventParamTabletEventType is kEventTabletPoint)
        -->     kEventParamTabletProximityRec typeTabletProximityRec    (if
   kEventParamTabletEventType is kEventTabletProximity)

    kEventMouseMoved
        -->     kEventParamMouseLocation    typeHIPoint
        -->     kEventParamMouseDelta       typeHIPoint (Mac OS X only)
        -->     kEventParamKeyModifiers     typeUInt32
        -->     kEventParamTabletEventType  typeUInt32  (Mac OS X 10.1,
   CarbonLib 1.5, and later)
        -->     kEventParamTabletPointRec   typeTabletPointRec          (if
   kEventParamTabletEventType is kEventTabletPoint)
        -->     kEventParamTabletProximityRec typeTabletProximityRec    (if
   kEventParamTabletEventType is kEventTabletProximity)

    kEventMouseDragged
        -->     kEventParamMouseLocation    typeHIPoint
        -->     kEventParamMouseDelta       typeHIPoint (Mac OS X only)
        -->     kEventParamKeyModifiers     typeUInt32
        -->     kEventParamMouseButton      typeMouseButton
        -->     kEventParamMouseChord       typeUInt32  (Mac OS X only)
        -->     kEventParamTabletEventType  typeUInt32  (Mac OS X 10.1,
   CarbonLib 1.5, and later)
        -->     kEventParamTabletPointRec   typeTabletPointRec          (if
   kEventParamTabletEventType is kEventTabletPoint)
        -->     kEventParamTabletProximityRec typeTabletProximityRec    (if
   kEventParamTabletEventType is kEventTabletProximity)

    kEventMouseWheelMoved
        -->     kEventParamMouseLocation    typeHIPoint
        -->     kEventParamKeyModifiers     typeUInt32
        -->     kEventParamMouseWheelAxis   typeMouseWheelAxis
        -->     kEventParamMouseWheelDelta  typeLongInteger
*/

/**
 *  EventMouseButton
 *
 */
typedef UInt16 EventMouseButton;
enum {

  /**
   * Only button for a one-button mouse (usually left button for
   * multi-button mouse)
   */
  kEventMouseButtonPrimary = 1,

  /**
   * Usually right button for a multi-button mouse
   */
  kEventMouseButtonSecondary = 2,

  /**
   * Usually middle button for a three-button mouse
   */
  kEventMouseButtonTertiary = 3
};

/**
 *  EventMouseWheelAxis
 *
 */
typedef UInt16 EventMouseWheelAxis;
enum {

  /**
   * The X axis (left or right)
   */
  kEventMouseWheelAxisX = 0,

  /**
   * The Y axis (up or down)
   */
  kEventMouseWheelAxisY = 1
};

/*��������������������������������������������������������������������������������������*/
/* Text Input Events */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Text input events (kEventClassTextInput)
 *
 *  Discussion:
 *    The following TextInput events reimplement the AppleEvents
 *    defined in Inside Mac Text - Text Services Manager, and provide
 *    the benefits of Carbon Event targeting, dispatching and
 *    propagation to applications that have formerly handled the TSM
 *    suite of AppleEvents. TextInput handlers may be installed on
 *    controls, windows, or the application event target (equivalent to
 *    AppleEvent-based handling). In all cases, if a given TextInput
 *    handler is not installed, TSM will convert that TextInput to an
 *    AppleEvent and redispatch via AESend to the current process,
 *    making adoption as gradual as is desired.
 */
enum {

  /**
   * Tells the application/text engine to initiate/terminate or manage
   * the content of inline input session.
   */
  kEventTextInputUpdateActiveInputArea = 1,

  /**
   * Unicode text resulting from a key event originated by TSM (not by
   * an input method).  A client need not be fully TSM-aware to process
   * or receive this event, which has become the standard way of
   * getting Unicode text from key events.  You can also get Mac
   * encoding characters from the raw keyboard event contained in this
   * event.  If no UnicodeForKeyEvent handler is installed, and no
   * kUnicodeNotFromInputMethod AppleEvent handler is installed (or the
   * application has not created a Unicode TSMDocument), the Mac
   * encoding charCodes (if these can be converted from the Unicodes)
   * are provided to WaitNextEvent.
   */
  kEventTextInputUnicodeForKeyEvent = 2,

  /**
   * Convert from inline session text offset to global QD Point.  This
   * event is typically be produced by an Input Method so that it can
   * best position a palette "near" the text being operated on by the
   * user.
   */
  kEventTextInputOffsetToPos = 3,

  /**
   * Convert from global QD point to inline session text offset.  This
   * event is typically produced by an input method to perform proper
   * cursor management as the cursor moves over various subranges, or
   * clauses of text (or the boundaries between these) in the inline
   * input session.
   */
  kEventTextInputPosToOffset = 4,

  /**
   * Show/Hide the bottom line input window.  This event is produced by
   * Input Methods to control the Text Services Manager bottom-line
   * input window, and is not normally handled by an application.
   */
  kEventTextInputShowHideBottomWindow = 5,

  /**
   * Get the text selected (or character before/after insertion point
   * based on leadingEdge parameter) from the application's text engine.
   */
  kEventTextInputGetSelectedText = 6
};

/**
    Parameters for TextInput events:

    kEventTextInputUpdateActiveInputArea
        Required parameters:
        -->     kEventParamTextInputSendComponentInstance typeComponentInstance
        -->     kEventParamTextInputSendRefCon typeLongInteger
        -->     kEventParamTextInputSendSLRec typeIntlWritingCode
        -->     kEventParamTextInputSendFixLen typeLongInteger
        -->     kEventParamTextInputSendText typeUnicodeText, typeChar (data
   type depends on TSMDocument type created via NewTSMDocument... typeChar for
   kTextService document, typeUnicodeText for kUnicodeDocument)

        Optional parameters:
        -->     kEventParamTextInputSendUpdateRng typeTextRangeArray
        -->     kEventParamTextInputSendHiliteRng typeTextRangeArray
        -->     kEventParamTextInputSendClauseRng typeOffsetArray
        -->     kEventParamTextInputSendPinRng typeTextRange
        -->     kEventParamTextInputSendPinRng typeTextRange
        -->     kEventParamTextInputSendTextServiceEncoding         typeUInt32
        -->     kEventParamTextInputSendTextServiceMacEncoding      typeUInt32

    kEventTextInputUnicodeForKeyEvent
        Required parameters:
        -->     kEventParamTextInputSendComponentInstance typeComponentInstance
        -->     kEventParamTextInputSendRefCon typeLongInteger
        -->     kEventParamTextInputSendSLRec typeIntlWritingCode
        -->     kEventParamTextInputSendText typeUnicodeText
        -->     kEventParamTextInputSendKeyboardEvent               typeEventRef
                    (This parameter is the original raw keyboard event that
   produced the text.  It enables access to kEventParamKeyModifiers and
                     kEventParamKeyCode parameters.
                     You can also extract from this event either Unicodes or Mac
   encoding characters as follows: kEventParamKeyUnicodes typeUnicodeText
                            kEventParamKeyMacCharCodes          typeChar (if
   available) The kEventParamKeyUnicodes parameter of the raw keyboard event is
                     identical to the TextInput event's
   kEventParamTextInputSendText parameter.  Note that when contents of TSM's
   bottom-line input window (i.e. during typing Chinese, Korean, or Japanese)
   are confirmed, the raw keyboard event's keyCode and modifiers are set to
   default values.)

    kEventTextInputOffsetToPos
        Required parameters:
        -->     kEventParamTextInputSendComponentInstance typeComponentInstance
        -->     kEventParamTextInputSendRefCon typeLongInteger
        -->     kEventParamTextInputSendTextOffset typeLongInteger
        <--     kEventParamTextInputReplyPoint                      typeQDPoint

        Optional parameters:
        -->     kEventParamTextInputSendSLRec typeIntlWritingCode
        -->     kEventParamTextInputSendLeadingEdge                 typeBoolean
        <--     kEventParamTextInputReplySLRec typeIntlWritingCode
        <--     kEventParamTextInputReplyFont typeLongInteger
        <--     kEventParamTextInputReplyFMFont                     typeUInt32
        <--     kEventParamTextInputReplyPointSize                  typeFixed
        <--     kEventParamTextInputReplyLineHeight typeShortInteger
        <--     kEventParamTextInputReplyLineAscent typeShortInteger
        <--     kEventParamTextInputReplyTextAngle                  typeFixed

    kEventTextInputPosToOffset
        Required parameters:
        -->     kEventParamTextInputSendComponentInstance typeComponentInstance
        -->     kEventParamTextInputSendRefCon typeLongInteger
        -->     kEventParamTextInputSendCurrentPoint                typeQDPoint
        <--     kEventParamTextInputReplyRegionClass typeLongInteger
        <--     kEventParamTextInputReplyTextOffset typeLongInteger (required if
   the position is inside the document's body)

        Optional parameters:
        -->     kEventParamTextInputSendDraggingMode                typeBoolean
        <--     kEventParamTextInputReplyLeadingEdge                typeBoolean
        <--     kEventParamTextInputReplySLRec typeIntlWritingCode

    kEventTextInputShowHideBottomWindow
        Required parameters:
        -->     kEventParamTextInputSendComponentInstance typeComponentInstance
        -->     kEventParamTextInputSendRefCon typeLongInteger

        Optional parameters:
        -->     kEventParamTextInputSendShowHide                    typeBoolean
        <--     kEventParamTextInputReplyShowHide                   typeBoolean

    kEventTextInputGetSelectedText
        Required parameters:
        -->     kEventParamTextInputSendComponentInstance typeComponentInstance
        -->     kEventParamTextInputSendRefCon typeLongInteger

        Optional parameters:
        -->     kEventParamTextInputSendLeadingEdge                 typeBoolean
        -->     kEventParamTextInputSendTextServiceEncoding         typeUInt32
        -->     kEventParamTextInputSendTextServiceMacEncoding      typeUInt32
        <--     kEventParamTextInputReplyText typeUnicodeText, typeChar (data
   type depends on TSMDocument.  See kEventTextInputUpdateActiveInputArea Notes)
        <--     kEventParamTextInputReplySLRec typeIntlWritingCode
*/
/*��������������������������������������������������������������������������������������*/
/* Raw Keyboard Events */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Keyboard events (kEventClassKeyboard)
 *
 *  Discussion:
 *    These events are the lowest-level keyboard events.
 */
enum {

  /**
   * A key was pressed.
   */
  kEventRawKeyDown = 1, /* hardware-level events*/

  /**
   * Sent periodically as a key is held down by the user.
   */
  kEventRawKeyRepeat = 2,

  /**
   * A key was released.
   */
  kEventRawKeyUp = 3,

  /**
   * The keyboard modifiers (bucky bits) have changed.
   */
  kEventRawKeyModifiersChanged = 4,

  /**
   * A registered Hot Key was pressed.
   */
  kEventHotKeyPressed = 5,

  /**
   * A registered Hot Key was released (this is only sent on Mac OS X).
   */
  kEventHotKeyReleased = 6 /* Mac OS X only*/
};

/**
 *  Summary:
 *    Key modifier change event bits and masks
 *
 *  Discussion:
 *    From bit 8, cmdKeyBit, to bit 15, rightControlKeyBit, are
 *    compatible with Event Manager modifiers.
 */
enum {

  /**
   * The Num Lock state bit (Mac OS X only).
   */
  kEventKeyModifierNumLockBit = 16, /* Num Lock is on? (Mac OS X only)*/

  /**
   * The Fn key state bit (Mac OS X only).
   */
  kEventKeyModifierFnBit = 17 /* Fn key is down? (Mac OS X only)*/
};

enum {
  kEventKeyModifierNumLockMask = 1L << kEventKeyModifierNumLockBit,
  kEventKeyModifierFnMask = 1L << kEventKeyModifierFnBit
};

/**
    Parameters for keyboard events:

    kEventRawKeyDown
        -->     kEventParamKeyMacCharCodes  typeChar
        -->     kEventParamKeyCode          typeUInt32
        -->     kEventParamKeyModifiers     typeUInt32
        -->     kEventParamKeyboardType     typeUInt32

    kEventRawKeyRepeat
        -->     kEventParamKeyMacCharCodes  typeChar
        -->     kEventParamKeyCode          typeUInt32
        -->     kEventParamKeyModifiers     typeUInt32
        -->     kEventParamKeyboardType     typeUInt32

    kEventRawKeyUp
        -->     kEventParamKeyMacCharCodes  typeChar
        -->     kEventParamKeyCode          typeUInt32
        -->     kEventParamKeyModifiers     typeUInt32
        -->     kEventParamKeyboardType     typeUInt32

    kEventRawKeyModifiersChanged
        -->     kEventParamKeyModifiers     typeUInt32

    kEventHotKeyPressed
        -->     kEventParamDirectObject     typeEventHotKeyID

    kEventHotKeyReleased
        -->     kEventParamDirectObject     typeEventHotKeyID
*/

/*��������������������������������������������������������������������������������������*/
/* Application Events */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Application events (kEventClassApplication)
 */
enum {

  /**
   * The current app has been activated (resume event). May optionally
   * contain a kEventParamWindowRef parameter if a click on an
   * application window was the cause of the app activation.
   */
  kEventAppActivated = 1,

  /**
   * The current app has just been deactivated (suspend event).
   */
  kEventAppDeactivated = 2,

  /**
   * Request to quit. Sent by QuitApplicationEventLoop to the
   * application target. In response, the event handler installed by
   * RunApplicationEventLoop will cause RunApplicationEventLoop to
   * exit. Most applications will not need to handle this event;
   * instead, an application should install an AppleEvent handler for
   * the kAEQuitApplication event handler if it needs to check for
   * unsaved documents or do other cleanup before quitting.
   */
  kEventAppQuit = 3,

  /**
   * An async launch request response. This event is received when you
   * use LaunchServices to launch a process asynchronously. It is only
   * received on Mac OS X.
   */
  kEventAppLaunchNotification = 4,

  /**
   * Another app was launched. Available on Mac OS X and CarbonLib
   * 1.3.1 and later.
   */
  kEventAppLaunched = 5,

  /**
   * Another app terminated. Available on Mac OS X and CarbonLib 1.3.1
   * and later.
   */
  kEventAppTerminated = 6,

  /**
   * The front (active) application has changed. Available on Mac OS X
   * and CarbonLib 1.3.1 and later.
   */
  kEventAppFrontSwitched = 7,

  /**
   * A request for a menu to be displayed by the application's dock
   * tile. The default handler will return the menu, if any, that was
   * provided by the SetApplicationDockTileMenu API. The sender of this
   * event will release the menu after the Dock has displayed it, so if
   * you return a permanently allocated MenuRef, you should call
   * RetainMenu on it before returning from your event handler. For
   * most applications, it will be easier to use the
   * SetApplicationDockTileMenu API directly rather than installing a
   * handler for this event. Available after Mac OS X 10.0.x.
   */
  kEventAppGetDockTileMenu = 20
};

/**
    Parameters for application events:

    kEventAppActivated
        -->     kEventParamWindowRef    typeWindowRef

    kEventAppDeactivated
        (no parameters)

    kEventAppQuit
        (no parameters)

    kEventAppLaunchNotification
        -->     kEventParamProcessID    typeProcessSerialNumber
        -->     kEventParamLaunchRefCon typeUInt32
        -->     kEventParamLaunchErr    typeOSStatus

    kEventAppLaunched
        -->     kEventParamProcessID    typeProcessSerialNumber

    kEventAppTerminated
        -->     kEventParamProcessID    typeProcessSerialNumber

    kEventAppFrontSwitched
        -->     kEventParamProcessID    typeProcessSerialNumber

    kEventAppGetDockTileMenu
        <--     kEventParamMenuRef      typeMenuRef
*/
/*��������������������������������������������������������������������������������������*/
/*  Apple Events */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Apple events (kEventClassAppleEvent)
 */
enum {

  /**
   * Sent when a high-level event is received. The default handler will
   * call AEProcessAppleEvent.
   */
  kEventAppleEvent = 1
};

/**
    Parameters for Apple events:

    kEventAppleEvent
        -->     kEventParamAEEventClass     typeType        // the eventClass of
   the Apple event
        -->     kEventParamAEEventID        typeType        // the eventID of
   the Apple event
*/
/*��������������������������������������������������������������������������������������*/
/*  Window Events */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Window refresh events (kEventClassWindow)
 *
 *  Discussion:
 *    Events related to drawing a window's content.
 */
enum {

  /**
   * Low-level update event. Sent to any window that needs updating
   * regardless of whether the window has the standard handler
   * installed. You must call BeginUpdate, call SetPort, draw your
   * window content, and then call EndUpdate.
   */
  kEventWindowUpdate = 1,

  /**
   * Only sent to windows with the standard handler installed.
   * BeginUpdate, SetPort, and EndUpdate are called for you; all you do
   * is draw. No, really.
   */
  kEventWindowDrawContent = 2
};

/**
    Parameters for window refresh events:

    kEventWindowUpdate
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowDrawContent
        -->     kEventParamDirectObject     typeWindowRef
*/

/**
 *  Summary:
 *    Window activation events (kEventClassWindow)
 *
 *  Discussion:
 *    Events related to activating and deactivating a window.
 */
enum {

  /**
   * The window is active now. Sent to any window that is activated,
   * regardless of whether the window has the standard handler
   * installed.
   */
  kEventWindowActivated = 5,

  /**
   * The window is inactive now. Sent to any window that is
   * deactivated, regardless of whether the window has the standard
   * handler installed.
   */
  kEventWindowDeactivated = 6,

  /**
   * Sent when a click occurs in a background window. Only sent to
   * windows with the standard handler installed. The default behavior
   * is to bring the window forward and eat the click. You have the
   * option of overriding the behavior to support click-thru or
   * select-and-click.
   */
  kEventWindowGetClickActivation = 7
};

/**
    Parameters for window activation events:

    kEventWindowActivated
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowDeactivated
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowGetClickActivation
        -->     kEventParamDirectObject     typeWindowRef
        -->     kEventParamMouseLocation    typeQDPoint
        -->     kEventParamKeyModifiers     typeUInt32
        -->     kEventParamWindowDefPart    typeWindowDefPartCode
        -->     kEventParamControlRef       typeControlRef (only present if the
   click was on a control)
        <--     kEventParamClickActivation  typeClickActivationResult
*/

/**
 *  Summary:
 *    Window state change events (kEventClassWindow)
 *
 *  Discussion:
 *    Events that notify of a change in the window's state. These
 *    events are sent to all windows, regardless of whether the window
 *    has the standard handler installed.
 */
enum {

  /**
   * A window is being shown. This is sent inside ShowHide.
   */
  kEventWindowShowing = 22,

  /**
   * A window is being hidden. This is sent inside ShowHide.
   */
  kEventWindowHiding = 23,

  /**
   * Indicates that the window has been shown.
   */
  kEventWindowShown = 24,

  /**
   * Indicates that the window has been hidden.
   */
  kEventWindowHidden = 25,

  /**
   * Sent during DragWindow or ResizeWindow, before the window is
   * actually moved or resized. Alter the current bounds
   * (kEventParamCurrentBounds) in the event to change the eventual
   * location of the window. You may change the size, origin, or both
   * of the window's bounds. Do not, however, call SizeWindow or
   * SetWindowBounds yourself from inside a handler for this event. In
   * Mac OS X 10.1 and later, kEventWindowBoundsChanging is sent before
   * all changes to a window's bounds, regardless of whether the change
   * is initiated by the user or by a direct call to a Window Manager
   * API. Applications may intercept the event and modify the bounds.
   * When the event is sent because of a direct call to the Window
   * Manager, the kWindowBoundsChangeUserDrag/Resize attribute bits
   * will not be set.
   */
  kEventWindowBoundsChanging = 26,

  /**
   * Indicates that the window has been moved or resized (or both). Do
   * not call SizeWindow or SetWindowBounds from inside a handler for
   * this event; if you need to enforce a certain window bounds,
   * install a kEventWindowBoundsChanging handler instead.
   */
  kEventWindowBoundsChanged = 27,

  /**
   * Indicates that the user has just started to resize a window.
   */
  kEventWindowResizeStarted = 28,

  /**
   * Indicates that the user has just finished resizing a window.
   */
  kEventWindowResizeCompleted = 29,

  /**
   * Indicates that the user has just started to drag a window.
   */
  kEventWindowDragStarted = 30,

  /**
   * Indicates that the user has just finished dragging a window.
   */
  kEventWindowDragCompleted = 31
};

/**
 *  Summary:
 *    Window bounds change event attributes
 *
 *  Discussion:
 *    When the toolbox sends out a kEventWindowBoundsChanging or
 *    kEventWindowBoundsChanged event, it also sends along a parameter
 *    containing attributes of the event. These attributes can be used
 *    to determine what aspect of the window changed (origin, size, or
 *    both), and whether or not some user action is driving the change
 *    (drag or resize).
 */
enum {

  /**
   * The bounds is changing because the user is dragging the window
   * around.
   */
  kWindowBoundsChangeUserDrag = (1 << 0),

  /**
   * The bounds is changing because the user is resizing the window.
   */
  kWindowBoundsChangeUserResize = (1 << 1),

  /**
   * The dimensions of the window (width and height) are changing.
   */
  kWindowBoundsChangeSizeChanged = (1 << 2),

  /**
   * The top left corner (origin) is changing.
   */
  kWindowBoundsChangeOriginChanged = (1 << 3)
};

/**
    Parameters for window state change events:

    kEventWindowShowing
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowHiding
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowShown
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowHidden
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowBoundsChanging
        -->     kEventParamDirectObject     typeWindowRef
        -->     kEventParamAttributes       typeUInt32
        -->     kEventParamOriginalBounds   typeQDRectangle
        -->     kEventParamPreviousBounds   typeQDRectangle
        <->     kEventParamCurrentBounds    typeQDRectangle

    kEventWindowBoundsChanged
        -->     kEventParamDirectObject     typeWindowRef
        -->     kEventParamAttributes       typeUInt32
        -->     kEventParamOriginalBounds   typeQDRectangle
        -->     kEventParamPreviousBounds   typeQDRectangle
        -->     kEventParamCurrentBounds    typeQDRectangle

    kEventWindowResizeStarted
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowResizeCompleted
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowDragStarted
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowDragCompleted
        -->     kEventParamDirectObject     typeWindowRef
*/

/**
 *  Summary:
 *    Window click events (kEventClassWindow)
 *
 *  Discussion:
 *    Low-level events which generate higher-level �action� events.
 *    These events are only generated for windows with the standard
 *    window handler installed. Most clients should allow the standard
 *    handler to implement these events. Window click events are
 *    generated from lower-level kEventMouseDown events by copying the
 *    mouse event and changing the class and kind, so window click
 *    events will have all of the parameters of the mouse down event,
 *    in addition to those parameters documented here that are specific
 *    to the window events.
 */
enum {

  /**
   * Sent when the mouse is down in the drag region. The standard
   * handler calls DragWindow.
   */
  kEventWindowClickDragRgn = 32,

  /**
   * Sent when the mouse is down in the resize area. The standard
   * handler calls ResizeWindow.
   */
  kEventWindowClickResizeRgn = 33,

  /**
   * Sent when the mouse is down in the collapse widget. The standard
   * handler calls CollapseWindow, and then generates
   * kEventWindowExpand or kEventWindowCollapse (whichever is the
   * opposite of the window�s original collapse state).
   */
  kEventWindowClickCollapseRgn = 34,

  /**
   * Sent when the mouse is down in the close widget. The standard
   * handler calls TrackGoAway, and then generates kEventWindowClose.
   */
  kEventWindowClickCloseRgn = 35,

  /**
   * Sent when the mouse is down in the zoom widget. The standard
   * handler calls TrackBox, and then generates kEventWindowZoom.
   */
  kEventWindowClickZoomRgn = 36,

  /**
   * Sent when the mouse is down in the content region. The standard
   * handler checks for contextual menu clicks and clicks on controls,
   * and sends kEventWindowContextualMenuSelect, kEventControlClick,
   * and kEventWindowHandleContentClick events as appropriate.
   */
  kEventWindowClickContentRgn = 37,

  /**
   * Sent when the mouse is down in the proxy icon. The standard
   * handler handles proxy icon dragging, and generates proxy icon
   * events.
   */
  kEventWindowClickProxyIconRgn = 38,

  /**
   * Sent when the mouse is down in the toolbar button. The standard
   * handler calls TrackBox, and then generates
   * kEventWindowToolbarSwitchMode. (Mac OS X only)
   */
  kEventWindowClickToolbarButtonRgn = 41,

  /**
   * Sent when the mouse is down in some part of the window structure
   * other than the window widgets, drag region, or resize region.
   */
  kEventWindowClickStructureRgn = 42
};

/**
 *  Summary:
 *    Window cursor change events (kEventClassWindow)
 */
enum {

  /**
   * Sent when the mouse is moving over the content region. Available
   * in Mac OS X and in CarbonLib 1.5 and later. This event is used to
   * manage ownership of the cursor.  You should only change the cursor
   * if you receive this event; otherwise, someone else needed to
   * adjust the cursor and handled the event (e.g., a TSM Input Method
   * when the mouse is over an inline input region). This event is only
   * sent to the window itself; it is not propagated to controls in the
   * window.
   */
  kEventWindowCursorChange = 40
};

/**
    Parameters for window cursor change events:

    kEventWindowCursorChange
        -->     kEventParamDirectObject     typeWindowRef
        -->     kEventParamMouseLocation    typeQDPoint
        -->     kEventParamKeyModifiers     typeUInt32
*/

/**
 *  Summary:
 *    Window action events
 *
 *  Discussion:
 *    Events which indicate that certain changes have been made to the
 *    window. These events have greater semantic meaning than the
 *    low-level window click events and are usually prefered for
 *    overriding.
 */
enum {

  /**
   * If the window is not collapsed, this event is sent by the standard
   * window handler after it has received kEventWindowClickCollapseRgn
   * and received true from a call to TrackBox.  Standard window
   * handler calls CollapseWindow and then sends kEventWindowCollapsed
   * if no error is received from CollapseWindow.
   */
  kEventWindowCollapse = 66,

  /**
   * Notification that the object has successfully collapsed.
   */
  kEventWindowCollapsed = 67,

  /**
   * Sent by the standard window handler (when the option key is down)
   * after it has received kEventWindowClickCollapseRgn and then
   * received true from a call to TrackBox.  The standard window
   * handler's response is to send each window of the same class as the
   * clicked window a kEventWindowCollapse event.
   */
  kEventWindowCollapseAll = 68,

  /**
   * If the window is collapsed, this event is sent by the standard
   * window handler after it has received kEventWindowClickCollapseRgn
   * and received true from a call to TrackBox.  The standard window
   * handler's response is to call CollapseWindow, then send
   * kEventWindowExpanded. Note that you will not receive this event
   * before a window is expanded from the dock, since minimized windows
   * in the dock don't uses collapse boxes to unminimize.
   */
  kEventWindowExpand = 69,

  /**
   * Notification that the window has successfully expanded.
   */
  kEventWindowExpanded = 70,

  /**
   * Sent by the standard window handler (when the option key is down)
   * after it has received kEventWindowClickCollapseRgn and then
   * received true from a call to TrackBox.  The standard window
   * handler's response is to send each window of the same class as the
   * clicked window a kEventWindowExpand event.
   */
  kEventWindowExpandAll = 71,

  /**
   * Sent by the standard window handler after it has received
   * kEventWindowClickCloseRgn and successfully called TrackBox. Your
   * application might intercept this event to check if the document is
   * dirty, and display a Save/Don'tSave/Cancel alert.
   */
  kEventWindowClose = 72,

  /**
   * Dispatched by DisposeWindow before the object is disposed.
   */
  kEventWindowClosed = 73,

  /**
   * Sent by the standard window handler (when the option key is down)
   * after it has received kEventWindowClickCloseRgn and received true
   * from a call to TrackGoAway.  The standard window handler's
   * response is to send each window with the same class as the clicked
   * window a kEventWindowClose event.
   */
  kEventWindowCloseAll = 74,

  /**
   * Sent by the standard window handler upon receiving
   * kEventWindowClickZoomRgn and then receiving true from a call to
   * TrackBox.  The standard window handler's response is to zoom the
   * window using ZoomWindowIdeal. Upon successful zoom,
   * kEventWindowZoomed is sent.
   */
  kEventWindowZoom = 75,

  /**
   * Notification that the window has been successfully zoomed.
   */
  kEventWindowZoomed = 76,

  /**
   * Sent by the standard window handler (when the option key is down)
   * after it has received kEventObjectClickZoomRgn and received true
   * from a call to TrackBox.  The standard window handler's response
   * is to send each window with the same class as the clicked window a
   * kEventObjectZoom event and then to reposition all zoomed windows
   * using the kWindowCascadeOnParentWindowScreen positioning method.
   */
  kEventWindowZoomAll = 77,

  /**
   * Sent when either the right mouse button is pressed, or the control
   * key is held down and the left mouse button is pressed, or the left
   * mouse button is held down for more than 1/4th of a second (and
   * nothing else is handling the generated mouse tracking events). The
   * standard window handler ignores this event.
   */
  kEventWindowContextualMenuSelect = 78,

  /**
   * Sent when IsWindowPathSelectClick would return true.  Set the
   * MenuRef in the event if you wish to customize the menu passed to
   * WindowPathSelect.
   */
  kEventWindowPathSelect = 79,

  /**
   * Sent by the standard window handler to determine the standard
   * state for zooming.
   */
  kEventWindowGetIdealSize = 80,

  /**
   * Sent by the standard window handler to determine the minimum size
   * of the window (used during window resizing).
   */
  kEventWindowGetMinimumSize = 81,

  /**
   * Sent by the standard window handler to determine the maximum size
   * of the window (used during window resizing).
   */
  kEventWindowGetMaximumSize = 82,

  /**
   * Sent by the Window Manager to warn of a change in the available
   * window positioning bounds on the window (i.e., screen resolution
   * or Dock size change). Available only in Mac OS X. In Mac OS
   * 10.0.x, the standard window handler always constrains the window
   * to the rect returned by GetAvailableWindowPositioningBounds for
   * the window's device. In Mac OS 10.1 and later, event handlers may
   * change the rect in the kEventParamAvailableBounds parameter, and
   * the standard window handler will constrain the window to that
   * rectangle. In Mac OS X after 10.1, this event may optionally
   * contain a kEventParamAttributes parameter; if present, this
   * parameter should be formed from constants in the
   * WindowConstrainOptions enumeration. The standard window handler
   * will pass these attributes to ConstrainWindowToScreen. If this
   * event parameter is not present, the standard window handler passes
   * kWindowConstrainMoveRegardlessOfFit to ConstrainWindowToScreen in
   * 10.0.x, and kWindowConstrainMoveRegardlessOfFit |
   * kWindowConstrainAllowPartial in Mac OS 10.1 and later. In Mac OS X
   * after 10.1, this event may optionally contain a
   * kEventParamWindowRegionCode parameter; if present, this parameter
   * should be a WindowRegionCode. The standard window handler will
   * pass this code to ConstrainWindowToScreen. If this event parameter
   * is not present, the standard window handler passes kWindowDragRgn
   * to ContrainWindowToScreen. In Mac OS X after 10.1, this event may
   * optionally contain a kEventParamRgnHandle parameter; if present,
   * this parameter is a RgnHandle containing the GrayRgn before a
   * GDevice configuration change. An event handler may compare this
   * region with the current GrayRgn to more intelligently determine
   * whether the window should be constrained to current GrayRgn. The
   * standard window handler in Mac OS X after 10.1 will not constrain
   * windows that were not onscreen before the device configuration
   * change.
   */
  kEventWindowConstrain = 83,

  /**
   * Sent by the standard window handler in response to
   * kEventWindowClickContentRgn when a mouse click is in the content
   * region but is not a contextual menu invocation or a click on a
   * control. Available starting with Mac OS X and CarbonLib 1.3.1.
   */
  kEventWindowHandleContentClick = 85,

  /**
   * Sent before a proxy icon drag; you can attach data to the DragRef
   * in the event.
   */
  kEventWindowProxyBeginDrag = 128,

  /**
   * Sent after the proxy icon drag is complete, whether successful or
   * not.
   */
  kEventWindowProxyEndDrag = 129,

  /**
   * Sent by the standard window handler in response to
   * kEventWindowClickToolbarButtonRgn and then receiving true from a
   * call to TrackBox. You actually DO NOT need to use the standard
   * window event handler to receive this event. Any window with the
   * toolbar button will receive this event if the toolbar button is
   * clicked. The Toolbox does not track the state of the toolbar. We
   * only report that the button was clicked. The application should
   * react accordingly. (Mac OS X only)
   */
  kEventWindowToolbarSwitchMode = 150
};

/**
    Parameters for window action events:

    kEventWindowCollapse
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowCollapsed
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowCollapseAll
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowExpand
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowExpanded
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowExpandAll
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowClose
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowClosed
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowCloseAll
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowZoom
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowZoomed
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowZoomAll
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowContextualMenuSelect
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowPathSelect
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowGetIdealSize
        --> kEventParamDirectObject     typeWindowRef
        <-- kEventParamDimensions       typeQDPoint

    kEventWindowGetMinimumSize
        --> kEventParamDirectObject     typeWindowRef
        <-- kEventParamDimensions       typeQDPoint

    kEventWindowGetMaximumSize
        --> kEventParamDirectObject     typeWindowRef
        <-- kEventParamDimensions       typeQDPoint

    kEventWindowConstrain
        --> kEventParamDirectObject     typeWindowRef
        --> kEventParamAvailableBounds  typeQDRectangle
        --> kEventParamAttributes       typeUInt32 (optional; available in Mac
   OS X after 10.1)
        --> kEventParamWindowRegionCode typeWindowRegionCode (optional;
   available in Mac OS X after 10.1)
        --> kEventParamRgnHandle        typeQDRgnHandle (optional; available in
   Mac OS X after 10.1)

    kEventWindowHandleContentClick
        --> kEventParamDirectObject     typeWindowRef
        --> [other parameters from kEventMouseDown]

    kEventWindowProxyBeginDrag
        --> kEventParamDirectObject     typeWindowRef

    kEventWindowProxyEndDrag
        --> kEventParamDirectObject     typeWindowRef
*/

/**
 *  Summary:
 *    Window focus events (kEventClassWindow)
 *
 *  Discussion:
 *    Events related to focus changes between windows. These events are
 *    generated by SetUserFocusWindow; since that API is only called by
 *    default by the standard window handler, these events are normally
 *    only sent to windows with the standard handler installed.
 */
enum {

  /**
   * The user (or some other action) has caused the focus to shift to
   * your window. In response to this, you should focus any control
   * that might need to be focused. The standard window handler calls
   * SetKeyboardFocus to hilite the first control in the window.
   */
  kEventWindowFocusAcquired = 200,

  /**
   * The toolbox is notifying you of a focus change. You should make
   * sure to unhilite the focus, etc. The standard window handler
   * clears the current keyboard focus.
   */
  kEventWindowFocusRelinquish = 201
};

/**
    Parameters for window focus events:

    kEventWindowFocusAcquire
        -->     kEventParamDirectObject     typeWindowRef

    kEventWindowFocusRelinquish
        -->     kEventParamDirectObject     typeWindowRef
*/

/**
 *  Summary:
 *    Window definition events (kEventClassWindow)
 *
 *  Discussion:
 *    Events that correspond to WDEF messages. Sent to all windows,
 *    regardless of whether they have the standard window handler
 *    installed.
 */
enum {

  /**
   * Sent by the Window Manager when it's time to draw a window's
   * structure. This is the replacement to the old wDraw defProc
   * message (though it is a special case of the 0 part code indicating
   * to draw the entire window frame).
   */
  kEventWindowDrawFrame = 1000,

  /**
   * Sent by the Window Manager when it's time to draw a specific part
   * of a window's structure, such as the close box. This is typically
   * sent during window tracking.
   */
  kEventWindowDrawPart = 1001,

  /**
   * Sent by the Window Manager when it needs to get a specific region
   * from a window, or when the GetWindowRegion API is called. The
   * region you should modify is sent in the kEventParamRgnHandle
   * parameter.
   */
  kEventWindowGetRegion = 1002,

  /**
   * Sent when the Window Manager needs to determine what part of a
   * window would be 'hit' with a given mouse location in global
   * coordinates. If you handle this event, you should set the
   * kEventParamWindowDefPart parameter to reflect the part code hit.
   */
  kEventWindowHitTest = 1003,

  /**
   * Sent by the Window Manager when the window is being created. This
   * is a hook to allow you to do any initialization you might need to
   * do.
   */
  kEventWindowInit = 1004,

  /**
   * Sent by the Window Manager when the window is being disposed.
   */
  kEventWindowDispose = 1005,

  /**
   * Sent by the Window Manager when it is time to draw/erase any drag
   * hilite in the window structure. This is typically sent from within
   * HiliteWindowFrameForDrag.
   */
  kEventWindowDragHilite = 1006,

  /**
   * Sent by the Window Manager when it is time to redraw window
   * structure to account for a change in the document modified state.
   * This is typically sent from within SetWindowModified.
   */
  kEventWindowModified = 1007,

  /**
   * Sent by the Window Manager when it is time to generate a drag
   * image for the window proxy. This is typically sent from within
   * BeginWindowProxyDrag.
   */
  kEventWindowSetupProxyDragImage = 1008,

  /**
   * Sent by the Window Manager when a particular window state changes.
   * See the state-change flags in MacWindows.h.
   */
  kEventWindowStateChanged = 1009,

  /**
   * Sent when the Window Manager needs to know how much space the
   * window's title area takes up.
   */
  kEventWindowMeasureTitle = 1010,

  /**
   * This is a compatibility event harkening back to the old days
   * before Mac OS 8. Not very useful these days. When the DrawGrowIcon
   * API is called, this event is sent to the window to tell it to draw
   * the grow box. This is only really needed for windows that do not
   * have the grow box integrated into the window frame. Scroll bar
   * delimiter lines are also drawn.
   */
  kEventWindowDrawGrowBox = 1011,

  /**
   * This is a special way for a window to override the standard resize
   * outline for windows that do not do live resizing. As the user
   * resizes the window, this event is sent with the current size the
   * user has chosen expressed as a rectangle. You should calculate
   * your window outline and modify the kEventParamRgnHandle parameter
   * to reflect your desired outline.
   */
  kEventWindowGetGrowImageRegion = 1012,

  /**
   * When the Window Manager needs to paint a window (e.g, when a
   * window is first displayed), the kEventWindowPaint event is sent to
   * allow the window to control all aspect of painting, including the
   * window frame. If a window does not respond to this event, the
   * Window Manager ends up sending kEventWindowDrawFrame and then
   * erasing the window to the window content color as usual. This is
   * mostly used for specialty windows, such as help tags or appliance
   * apps might have. (Mac OS X only)
   */
  kEventWindowPaint = 1013
};

/**
    Parameters for window definition events:

    kEventWindowDrawFrame
        -->     kEventParamDirectObject     typeWindowRef               the
   window

    kEventWindowDrawPart
        -->     kEventParamDirectObject     typeWindowRef               the
   window
        -->     kEventParamWindowDefPart    typeWindowDefPartCode       the part
   to draw

    kEventWindowGetRegion
        -->     kEventParamDirectObject     typeWindowRef               the
   window
        -->     kEventParamWindowRegionCode typeWindowRegionCode        the
   region to get
        -->     kEventParamRgnHandle        typeQDRgnHandle             the
   region to munge

    kEventWindowHitTest
        -->     kEventParamDirectObject     typeWindowRef               the
   window
        -->     kEventParamMouseLocation    typeQDPoint                 the
   mouse location
        <--     kEventParamWindowDefPart    typeWindowDefPartCode       the part
   hit

    kEventWindowInit
        -->     kEventParamDirectObject     typeWindowRef               the
   window
        <--     kEventParamWindowFeatures   typeUInt32                  the
   window features

    kEventWindowDispose
        -->     kEventParamDirectObject     typeWindowRef               the
   window

    kEventWindowDragHilite
        -->     kEventParamDirectObject             typeWindowRef       the
   window
        -->     kEventParamWindowDragHiliteFlag     typeBoolean         whether
   to draw (true) or erase (false) the hilite

    kEventWindowModified
        -->     kEventParamDirectObject             typeWindowRef       the
   window
        -->     kEventParamWindowModifiedFlag       typeBoolean         the new
   modified state

    kEventWindowSetupProxyDragImage
        -->     kEventParamDirectObject             typeWindowRef       the
   window
        -->     kEventParamWindowProxyImageRgn      typeQDRgnHandle     the
   region you modify to contain the clip region for the GWorld.
        -->     kEventParamWindowProxyOutlineRgn    typeQDRgnHandle     the
   region you modify to contain the drag outline used when the GWorld cannot be
   used.
        <--     kEventParamWindowProxyGWorldPtr     typeGWorldPtr       a GWorld
   you allocate which contains the drag image.

    kEventWindowStateChanged
        -->     kEventParamDirectObject             typeWindowRef       the
   window
        -->     kEventParamWindowStateChangedFlags  typeUInt32          the
   state change flags

    kEventWindowMeasureTitle
        -->     kEventParamDirectObject             typeWindowRef       the
   window
        <--     kEventParamWindowTitleFullWidth     typeSInt16          the
   length of the whole title area
        <--     kEventParamWindowTitleTextWidth     typeSInt16          the
   length just the title text

    kEventWindowDrawGrowBox
        -->     kEventParamDirectObject     typeWindowRef               the
   window

    kEventWindowGetGrowImageRegion
        -->     kEventParamDirectObject     typeWindowRef               the
   window
        -->     kEventParamWindowGrowRect   typeQDRectangle             the
   global rect
        -->     kEventParamRgnHandle        typeQDRgnHandle             the
   region to modify

    kEventWindowPaint
        -->     kEventParamDirectObject     typeWindowRef               the
   window
*/
/*��������������������������������������������������������������������������������������*/
/*  Menu Events */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Menu events (kEventClassMenu)
 */
enum {

  /**
   * The user has begun tracking the menubar or a pop-up menu. The
   * direct object parameter is a valid MenuRef if tracking a pop-up
   * menu, or NULL if tracking the menubar. The
   * kEventParamCurrentMenuTrackingMode parameter indicates whether the
   * user is tracking the menus using the mouse or the keyboard. The
   * handler may return userCanceledErr to stop menu tracking.
   */
  kEventMenuBeginTracking = 1,

  /**
   * The user has finished tracking the menubar or a pop-up menu.
   */
  kEventMenuEndTracking = 2,

  /**
   * The user has switched from selecting a menu with the mouse to
   * selecting with the keyboard, or from selecting with the keyboard
   * to selecting with the mouse. Only available on post-10.0.x
   * versions of Mac OS X.
   */
  kEventMenuChangeTrackingMode = 3,

  /**
   * A menu is opening. This event is sent each time that the menu is
   * opened (i.e., more than once during a given tracking session if
   * the user opens the menu multiple times). It is sent before the
   * menu is actually drawn, so you can update the menu contents
   * (including making changes that will alter the menu size) and the
   * new contents will be drawn correctly. The kEventParamMenuFirstOpen
   * parameter indicates whether this is the first time this menu has
   * been opened during this menu tracking session. The handler may
   * return userCanceledErr to prevent this menu from opening (Mac OS X
   * only).
   */
  kEventMenuOpening = 4,

  /**
   * A menu has been closed. Sent after the menu is hidden.
   */
  kEventMenuClosed = 5,

  /**
   * The mouse is moving over a particular menu item. This event is
   * sent for both enabled and disabled items.
   */
  kEventMenuTargetItem = 6,

  /**
   * A menu is about to be examined for items that match a command key
   * event. A handler for this event may perform its own command key
   * matching and override the Menu Manager's default matching
   * algorithms. Returning noErr from your handler indicates that you
   * have found a match. The handler for this event should not examine
   * submenus of this menu for a match; a separate event will be sent
   * for each submenu. Handlers for this event must be installed
   * directly on the menu containing the item to be matched. To improve
   * performance of command key matching, the Menu Manager only sends
   * this event if the menu itself has a handler; if a handler for this
   * event is installed on any other event target, it will not be sent
   * the event. When called from IsMenuKeyEvent, the
   * kEventParamEventRef parameter contains the EventRef that was
   * passed to IsMenuKeyEvent, for your handler to examine; when called
   * from MenuKey or MenuEvent, the EventRef parameter contains an
   * event created from the information passed to MenuKey or MenuEvent.
   * Note that in the MenuKey case, no virtual keycode
   * (kEventParamKeyCode) or key modifiers (kEventParamKeyModifiers)
   * will be available. The kEventParamMenuEventOptions parameter
   * contains a copy of the options that were passed to IsMenuKeyEvent,
   * or 0 if called from MenuKey or MenuEvent. The only option that
   * your handler will need to obey is kMenuEventIncludeDisabledItems.
   * If your handler finds a match, it should set the
   * kEventParamMenuItemIndex parameter to contain the item index of
   * the matching item, and return noErr. If it does not find a match,
   * it should return menuItemNotFoundErr. Any other return value will
   * cause the Menu Manager to use its default command key matching
   * algorithm for this menu. This event is sent after
   * kEventMenuEnableItems.
   */
  kEventMenuMatchKey = 7,

  /**
   * A request that the items in the menu be properly enabled or
   * disabled according to the current state of the application. This
   * event is sent from inside MenuKey, MenuEvent, and IsMenuKeyEvent
   * before those APIs examine the menu for an item that matches a
   * keyboard event. It is also sent during menu tracking before a menu
   * is first made visible; it is sent right after kEventMenuOpening,
   * once per menu per menu tracking session. It is also sent to the
   * top-level menus in the menubar when the application is idle after
   * user input has occurred, to allow the menu titles to be enabled or
   * disabled appropriately according to the current user focus. You
   * can distinquish between all these cases by examining the contents
   * of the kEventParamMenuContext parameter. If you install an event
   * handler for kEventProcessCommand, you should also install a
   * handler for either kEventMenuEnableItems or
   * kEventCommandUpdateStatus This is necessary because the Carbon
   * event system will attempt to match command keys against the
   * available menus before returning the keyboard event to your
   * application via WaitNextEvent. If you have menu command event
   * handlers installed for your menu items, your handlers will be
   * called without your ever receiving the keyboard event or calling
   * MenuKey/MenuEvent/IsMenuKeyEvent yourself. Therefore, you have no
   * opportunity to enable your menu items properly other than from a
   * kEventMenuEnableItems or kEventCommandUpdateStatus handler. It is
   * not necessary to handle this event if you do not install
   * kEventProcessCommand handlers for your menu items; in that case,
   * the command key event will be returned from WaitNextEvent or
   * ReceiveNextEvent as normal, and you can set up your menus before
   * calling MenuKey/MenuEvent/ IsMenuKeyEvent. The
   * kEventParamEnableMenuForKeyEvent parameter indicates whether this
   * menu should be enabled for key event matching (true) or because
   * the menu itself is about to become visible (false). If true, only
   * the item enable state, command key, command key modifiers, and
   * (optionally) the command key glyph need to be correct. If false,
   * the entire menu item contents must be correct. This may be useful
   * if you have custom menu content that is expensive to prepare.
   */
  kEventMenuEnableItems = 8,

  /**
   * kEventMenuPopulate is intended to be handled by applications that
   * dynamically create their menu contents just-in-time before the
   * menu is displayed. Previously, kEventMenuOpening was recommended
   * for this purpose. kEventMenuPopulate is now recommended because it
   * will be sent by the Menu Manager before it searches a menu for a
   * matching command key, to allow a handler to dynamically add menu
   * items that may have command key equivalents to the menu;
   * kEventMenuOpening is only sent before the menu is displayed.
   * kEventMenuPopulate is also sent just before kEventMenuOpening as a
   * menu is being displayed. Finally, kEventMenuPopulate is only sent
   * once per menu tracking session for a given menu, even if that menu
   * is closed and opened multiple times by the user; kEventMenuOpening
   * is sent each time that the menu is displayed. You can distinguish
   * the command-key case from the menu-being-displayed case by
   * examining the contents of the kEventParamMenuContext parameter;
   * the kMenuContextKeyMatching flag will be set if the event is sent
   * during command key matching, and either the
   * kMenuContextMenuBarTracking or kMenuContextPopUpTracking flags
   * will be sent if the event is sent before actual display of the
   * menu. kEventMenuPopulate is available on Mac OS X 10.1 and later,
   * and in CarbonLib 1.5 and later.
   */
  kEventMenuPopulate = 9,

  /**
   * Sent by the standard menu definition when a menu item has the
   * kMenuItemAttrCustomDraw attribute. Handlers for this event should
   * be installed directly on the menu. A handler for this event may
   * respond by providing a customized width for the menu item. If no
   * handler is installed, the standard menu definition provides a
   * default handler that will return the standard width for the item.
   */
  kEventMenuMeasureItemWidth = 100,

  /**
   * Sent by the standard menu definition when a menu item has the
   * kMenuItemAttrCustomDraw attribute. Handlers for this event should
   * be installed directly on the menu. A handler for this event may
   * respond by providing a customized height for the menu item. If no
   * handler is installed, the standard menu definition provides a
   * default handler that will return the standard height for the item.
   */
  kEventMenuMeasureItemHeight = 101,
  kEventMenuDrawItem = 102,
  kEventMenuDrawItemContent = 103,

  /**
   * Sent when the menu is being destroyed.
   */
  kEventMenuDispose = 1001
};

/**
 *  Discussion:
 *    Menu context flags indicate the context or usage of a
 *    menu-related Carbon event.
 */
enum {
  /* menu location*/

  /**
   * Indicates that this menu is inserted in the menubar, or is a
   * (directly or indirectly) a submenu of a menu that is inserted in
   * the menubar.
   */
  kMenuContextMenuBar = 1 << 0, /* menu type*/

  /**
   * Indicates that this menu is a pull-down menu inserted in the
   * menubar.
   */
  kMenuContextPullDown = 1 << 8,

  /**
   * Indicates that this menu is a popup menu being displayed by
   * PopUpMenuSelect.
   */
  kMenuContextPopUp = 1 << 9,

  /**
   * Indicates that this menu is a submenu of some other pull-down or
   * popup menu.
   */
  kMenuContextSubmenu = 1 << 10, /* menu usage*/

  /**
   * Indicates that this Carbon event has been sent during a menubar
   * tracking session.
   */
  kMenuContextMenuBarTracking = 1 << 16,

  /**
   * Indicates that this Carbon event has been sent during a popup menu
   * tracking session.
   */
  kMenuContextPopUpTracking = 1 << 17,

  /**
   * Indicates that this Carbon event has been sent during command key
   * matching.
   */
  kMenuContextKeyMatching = 1 << 18,

  /**
   * Indicates that this Carbon event has been sent at idle time to
   * update the enabled state of the menus. Available on Mac OS X 10.1
   * and later, and in CarbonLib 1.5 and later; on earlier releases,
   * the kMenuContextKeyMatching flag is set when an event is sent
   * during menu enabling.
   */
  kMenuContextMenuEnabling = 1 << 19
};

/**
    Parameters for menu events:

    kEventMenuBeginTracking
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamCurrentMenuTrackingMode  typeMenuTrackingMode
        -->     kEventParamMenuContext              typeUInt32 (on Mac OS X 10.1
   and later, and CarbonLib 1.5 and later)

    kEventMenuEndTracking
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamMenuContext              typeUInt32 (on Mac OS X 10.1
   and later, and CarbonLib 1.5 and later)

    kEventMenuChangeTrackingMode
        -->     kEventParamCurrentMenuTrackingMode  typeMenuTrackingMode
        -->     kEventParamNewMenuTrackingMode      typeMenuTrackingMode
        -->     kEventParamMenuContext              typeUInt32

    kEventMenuOpening
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamMenuFirstOpen            typeBoolean
        -->     kEventParamMenuContext              typeUInt32 (in CarbonLib 1.5
   and later)

    kEventMenuClosed
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamMenuContext              typeUInt32 (on Mac OS X 10.1
   and later, and CarbonLib 1.5 and later)

    kEventMenuTargetItem
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamMenuItemIndex            typeMenuItemIndex
        -->     kEventParamMenuCommand              typeMenuCommand
        -->     kEventParamMenuContext              typeUInt32 (on Mac OS X 10.1
   and later, and CarbonLib 1.5 and later)

    kEventMenuMatchKey
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamEventRef                 typeEventRef
        -->     kEventParamMenuEventOptions         typeMenuEventOptions
        -->     kEventParamMenuContext              typeUInt32 (on Mac OS X 10.1
   and later, and CarbonLib 1.5 and later)
        <--     kEventParamMenuItemIndex            typeMenuItemIndex

    kEventMenuEnableItems
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamEnableMenuForKeyEvent    typeBoolean
        -->     kEventParamMenuContext              typeUInt32 (in
   CarbonLib 1.3.1 and later)

    kEventMenuPopulate (on Mac OS X 10.1 and later, and CarbonLib 1.5 and later)
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamMenuContext              typeUInt32

    kEventMenuMeasureItemWidth (on Mac OS X 10.1 and later, and CarbonLib 1.5
   and later)
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamMenuItemIndex            typeMenuItemIndex
        <--     kEventParamMenuItemWidth            typeShortInteger

    kEventMenuMeasureItemHeight (on Mac OS X 10.1 and later, and CarbonLib 1.5
   and later)
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamMenuItemIndex            typeMenuItemIndex
        <--     kEventParamMenuItemHeight           typeShortInteger

    kEventMenuDrawItem (on Mac OS X 10.1 and later, and CarbonLib 1.5 and later)
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamCurrentBounds            typeQDRectangle
        -->     kEventParamMenuItemIndex            typeMenuItemIndex
        -->     kEventParamMenuItemBounds           typeQDRectangle
        -->     kEventParamMenuVirtualTop           typeLongInteger
        -->     kEventParamMenuVirtualBottom        typeLongInteger
        -->     kEventParamMenuDrawState            typeThemeMenuState
        -->     kEventParamMenuItemType             typeThemeMenuItemType
        -->     kEventParamCGContextRef             typeCGContextRef
        <--     kEventParamMenuMarkBounds           typeQDRectangle (added to
   event by the default event handler)
        <--     kEventParamMenuIconBounds           typeQDRectangle (added to
   event by the default event handler)
        <--     kEventParamMenuTextBounds           typeQDRectangle (added to
   event by the default event handler)
        <--     kEventParamMenuTextBaseline         typeShortInteger (added to
   event by the default event handler)
        <--     kEventParamMenuCommandKeyBounds     typeQDRectangle (added to
   event by the default event handler)

    kEventMenuDrawItemContent (on Mac OS X 10.1 and later, and CarbonLib 1.5 and
   later)
        -->     kEventParamDirectObject             typeMenuRef
        -->     kEventParamMenuItemIndex            typeMenuItemIndex
        -->     kEventParamMenuItemBounds           typeQDRectangle
        -->     kEventParamDeviceDepth              typeShortInteger
        -->     kEventParamDeviceColor              typeBoolean
        -->     kEventParamCGContextRef             typeCGContextRef
        <--     kEventParamMenuMarkBounds           typeQDRectangle (added to
   event by the default event handler)
        <--     kEventParamMenuIconBounds           typeQDRectangle (added to
   event by the default event handler)
        <--     kEventParamMenuTextBounds           typeQDRectangle (added to
   event by the default event handler)
        <--     kEventParamMenuTextBaseline         typeShortInteger (added to
   event by the default event handler)
        <--     kEventParamMenuCommandKeyBounds     typeQDRectangle (added to
   event by the default event handler)

    kEventMenuDispose
        -->     kEventParamDirectObject             typeMenuRef
*/
/*��������������������������������������������������������������������������������������*/
/*  Command Events */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Command events (kEventClassCommand)
 */
enum {
  kEventProcessCommand = 1,

  /**
   * A command has been invoked and the application should handle it.
   * This event is sent when the user chooses a menu item or a control
   * with a command is pressed. Some senders of this event will also
   * include the modifier keys that were pressed by the user when the
   * command was invoked, but this parameter is optional.
   */
  kEventCommandProcess = 1,

  /**
   * The status of a command is in question. When you receive this
   * event, you should update the necessary UI elements in your
   * application to reflect the current status of the command. For
   * example, if the command has the kHICommandFromMenu bit set), you
   * should update the menu item state, text, etc. to reflect the
   * current reality in your application.
   */
  kEventCommandUpdateStatus = 2
};

/**
    Parameters for command events:

    kEventCommandProcess
        -->     kEventParamDirectObject     typeHICommand
        -->     kEventParamKeyModifiers     typeUInt32 (optional)

    kEventCommandUpdateStatus
        -->     kEventParamDirectObject     typeHICommand
        -->     kEventParamMenuContext      typeUInt32
*/
/* HI Commands */

/**
 *  Summary:
 *    Common command IDs
 */
enum {

  /**
   * The OK button in a dialog or alert.
   */
  kHICommandOK = FOUR_CHAR_CODE('ok  '),

  /**
   * The Cancel button in a dialog or alert.
   */
  kHICommandCancel = FOUR_CHAR_CODE('not!'),

  /**
   * The application should quit.
   */
  kHICommandQuit = FOUR_CHAR_CODE('quit'),

  /**
   * The last editing operation should be undone.
   */
  kHICommandUndo = FOUR_CHAR_CODE('undo'),

  /**
   * The last editing operation should be redone.
   */
  kHICommandRedo = FOUR_CHAR_CODE('redo'),

  /**
   * The selected items should be cut.
   */
  kHICommandCut = FOUR_CHAR_CODE('cut '),

  /**
   * The selected items should be copied.
   */
  kHICommandCopy = FOUR_CHAR_CODE('copy'),

  /**
   * The contents of the clipboard should be pasted.
   */
  kHICommandPaste = FOUR_CHAR_CODE('past'),

  /**
   * The selected items should be deleted.
   */
  kHICommandClear = FOUR_CHAR_CODE('clea'),

  /**
   * All items in the active window should be selected.
   */
  kHICommandSelectAll = FOUR_CHAR_CODE('sall'),

  /**
   * The application should be hidden. The Menu Manager will respond to
   * this command automatically; your application does not need to
   * handle it.
   */
  kHICommandHide = FOUR_CHAR_CODE('hide'),

  /**
   * Other applications should be hidden. The Menu Manager will respond
   * to this command automatically; your application does not need to
   * handle it.
   */
  kHICommandHideOthers = FOUR_CHAR_CODE('hido'),

  /**
   * All applications should become visible. The Menu Manager will
   * respond to this command automatically; your application does not
   * need to handle it.
   */
  kHICommandShowAll = FOUR_CHAR_CODE('shal'),

  /**
   * The Preferences menu item has been selected.
   */
  kHICommandPreferences = FOUR_CHAR_CODE('pref'),

  /**
   * The active window should be zoomed in or out. The Window Manager
   * will respond to this event automatically; your application does
   * not need to handle it, but you may want to install a Carbon event
   * handler for kEventWindowGetIdealSize to return the ideal size for
   * your document windows.
   */
  kHICommandZoomWindow = FOUR_CHAR_CODE('zoom'),

  /**
   * The active window should be minimized. The Window Manager will
   * respond to this event automatically; your application does not
   * need to handle it.
   */
  kHICommandMinimizeWindow = FOUR_CHAR_CODE('mini'),

  /**
   * All windows of the same class as the active window that have
   * collapse boxes should be minimized. The Window Manager will
   * respond to this event automatically; your application does not
   * need to handle it.
   */
  kHICommandMinimizeAll = FOUR_CHAR_CODE('mina'),

  /**
   * The active window should be maximized. Only sent on Mac OS 9. The
   * Window Manager will respond to this event automatically; your
   * application does not need to handle it.
   */
  kHICommandMaximizeWindow = FOUR_CHAR_CODE('maxi'),

  /**
   * All windows of the same class as the active window that have
   * collapse boxes should be maximized. The Window Manager will
   * respond to this event automatically; your application does not
   * need to handle it.
   */
  kHICommandMaximizeAll = FOUR_CHAR_CODE('maxa'),

  /**
   * All document-class windows should be arranged in a stack. The
   * Window Manager will respond to this event automatically; your
   * application does not need to handle it.
   */
  kHICommandArrangeInFront = FOUR_CHAR_CODE('frnt'),

  /**
   * All windows of this application should be brought in front of
   * windows from other applications. Only sent on Mac OS X. The Window
   * Manager will respond to this event automatically; your application
   * does not need to handle it.
   */
  kHICommandBringAllToFront = FOUR_CHAR_CODE('bfrt'),

  /**
   * This command ID is used as a placeholder to mark the separator
   * item dividing the Zoom/Minimize/Maximize/Arrange menu items in the
   * standard Window menu from the menu items listing the visible
   * windows. If you need to add your own menu items to the standard
   * Window menu before the window list section, you can look for the
   * menu item with this command ID using GetIndMenuItemWithCommandID,
   * and insert your menu items before the item with this ID.
   */
  kHICommandWindowListSeparator = FOUR_CHAR_CODE('wldv'),

  /**
   * This command ID is used as a placeholder to mark the end of the
   * window list section of the standard Window menu. If you need to
   * add your own menu items to the standard Window menu after the
   * window list section, you can look for the menu item with this
   * command ID using GetIndMenuItemWithCommandID, and insert your
   * items after the item with this ID.
   */
  kHICommandWindowListTerminator = FOUR_CHAR_CODE('wlst'),

  /**
   * A window in the standard Window menu has been selected and should
   * be activated. The Window Manager will respond to this event
   * automatically; your application does not need to handle it.
   */
  kHICommandSelectWindow = FOUR_CHAR_CODE('swin'),

  /**
   * The About menu item has been selected.
   */
  kHICommandAbout = FOUR_CHAR_CODE('abou'),

  /**
   * A new document or item should be created.
   */
  kHICommandNew = FOUR_CHAR_CODE('new '),

  /**
   * The user wants to open an existing document.
   */
  kHICommandOpen = FOUR_CHAR_CODE('open'),

  /**
   * The active window should be closed.
   */
  kHICommandClose = FOUR_CHAR_CODE('clos'),

  /**
   * The active document should be saved.
   */
  kHICommandSave = FOUR_CHAR_CODE('save'),

  /**
   * The user wants to save the active document under a new name.
   */
  kHICommandSaveAs = FOUR_CHAR_CODE('svas'),

  /**
   * The contents of the active document should be reverted to the last
   * saved version.
   */
  kHICommandRevert = FOUR_CHAR_CODE('rvrt'),

  /**
   * The active window should be printed.
   */
  kHICommandPrint = FOUR_CHAR_CODE('prnt'),

  /**
   * The user wants to configure the current page margins, formatting,
   * and print options.
   */
  kHICommandPageSetup = FOUR_CHAR_CODE('page'),

  /**
   * The application's help book should be displayed. Used by the Help
   * Manager when it adds the "<AppName> Help" menu item to the Help
   * menu. The Help Manager will respond to this event automatically;
   * your application does not need to handle it.
   */
  kHICommandAppHelp = FOUR_CHAR_CODE('ahlp')
};

enum { kHICommandFromMenu = (1L << 0) };

struct HICommand {
  UInt32 attributes;
  UInt32 commandID;
  struct {
    MenuRef menuRef;
    MenuItemIndex menuItemIndex;
  } menu;
};
typedef struct HICommand HICommand;
/*��������������������������������������������������������������������������������������*/
/*  Control Events */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Control events (kEventClassControl)
 */
enum {

  /**
   * Allows the control to initialize private data.
   */
  kEventControlInitialize = 1000,

  /**
   * Allows the control to dispose of private data.
   */
  kEventControlDispose = 1001,

  /**
   * Allows the control to report its best size and its text baseline
   * based on its current settings. You should set the
   * kEventParamControlOptimalBounds parameter to an appropriate
   * rectangle. You should also set the
   * kEventParamControlOptimalBaselineOffset parameter to be the offset
   * from the top of your optimal bounds of a text baseline, if any.
   * (Mac OS X only)
   */
  kEventControlGetOptimalBounds = 1003,
  kEventControlDefInitialize = kEventControlInitialize,
  kEventControlDefDispose = kEventControlDispose,

  /**
   * Sent by TrackControl and HandleControlClick after handling a click
   * in a control.
   */
  kEventControlHit = 1,

  /**
   * Sent when your control should simulate a click in response to some
   * other action, such as a return key for a default button. (Mac OS X
   * only)
   */
  kEventControlSimulateHit = 2,

  /**
   * Sent when someone wants to find out what part of your control is
   * at a given point in local coordinates. You should set the
   * kEventParamControlPart parameter to the appropriate part. (Mac OS
   * X only)
   */
  kEventControlHitTest = 3,

  /**
   * Sent when your control should draw itself. The event can
   * optionally contain a port in which to draw and a part to constrain
   * drawing to. (Mac OS X only)
   */
  kEventControlDraw = 4,

  /**
   * Sent when your control should apply its background color/pattern
   * to the port specified so the subcontrol can properly erase. The
   * port is optional; if it does not exist you should apply the
   * background to the current port. (Mac OS X only)
   */
  kEventControlApplyBackground = 5,

  /**
   * Sent when your control should apply a color/pattern to the
   * specified port and context so a subcontrol can draw text which
   * looks appropriate for your control's background. The port is
   * optional; if it does not exist, you should apply the text color to
   * the current port. The context context is also optional. (Mac OS X
   * only)
   */
  kEventControlApplyTextColor = 6,

  /**
   * Sent when your control is gaining, losing, or changing the focus.
   * Set the kEventParamControlPart param to the resulting focused
   * part. (Mac OS X only)
   */
  kEventControlSetFocusPart = 7,

  /**
   * Sent when your the Control Manager wants to know what part of your
   * control is currently focused. Set the kEventParamControlPart param
   * to your currently focused part. (Mac OS X only)
   */
  kEventControlGetFocusPart = 8,

  /**
   * Sent when your control becomes active as a result of a call to
   * ActivateControl. (Mac OS X only)
   */
  kEventControlActivate = 9,

  /**
   * Sent when your control becomes inactive as a result of a call to
   * DeactivateControl. (Mac OS X only)
   */
  kEventControlDeactivate = 10,

  /**
   * Sent when your control is asked to change the cursor as a result
   * of a call to HandleControlSetCursor. (Mac OS X only)
   */
  kEventControlSetCursor = 11,

  /**
   * Sent when your control is asked to display a contextual menu as a
   * result of a call to HandleControlContextualMenuClick. (Mac OS X
   * only)
   */
  kEventControlContextualMenuClick = 12,

  /**
   * A mouse down occurred in a control. The standard window handler
   * sets the keyboard focus to the control if it takes focus on
   * clicks, and calls HandleControlClick. Available on Mac OS X and
   * CarbonLib 1.3.1 and later.
   */
  kEventControlClick = 13,

  /**
   * Sent to allow your control to completely replace the normal
   * tracking that is part of a call to TrackControl or
   * HandleControlClick. Set the kEventParamControlPart to the part hit
   * during tracking. (Mac OS X only)
   */
  kEventControlTrack = 51,

  /**
   * Sent so your control can support Scroll To Here behavior during
   * tracking. Set the kEventParamMouseLocation parameter to the mouse
   * location in local coordinates which represents where a click would
   * have needed to be to cause your indicator to be dragged to the
   * incoming mouse location. (Mac OS X only)
   */
  kEventControlGetScrollToHereStartPoint = 52,

  /**
   * Sent so your control can constrain the movement of its indicator
   * during tracking. Set the kEventParamControlIndicatorDragConstraint
   * parameter to the appropriate constraint. (Mac OS X only)
   */
  kEventControlGetIndicatorDragConstraint = 53,

  /**
   * Sent during live-tracking of the indicator so your control can
   * update its value based on the new indicator position. During
   * non-live tracking, this event lets you redraw the indicator ghost
   * at the appropriate place. (Mac OS X only)
   */
  kEventControlIndicatorMoved = 54,

  /**
   * Sent at the end of non-live indicator tracking so your control can
   * update its value based on the final ghost location. (Mac OS X only)
   */
  kEventControlGhostingFinished = 55,

  /**
   * Sent during tracking so your control can alter the part that is
   * passed to its action proc based on modifier keys, etc. Set the
   * kEventParamControlPart to the part you want to have sent. (Mac OS
   * X only)
   */
  kEventControlGetActionProcPart = 56,

  /**
   * Sent when a client wants to get a particular region of your
   * control. See the GetControlRegion API. The
   * kEventParamControlRegion contains a region for you to modify. (Mac
   * OS X only)
   */
  kEventControlGetPartRegion = 101,

  /**
   * Sent when a client wants to get a particular rectangle of your
   * control when it may be more efficient than asking for a region.
   * Set the kEventParamControlPartBounds parameter to the appropriate
   * rectangle. (Mac OS X only)
   */
  kEventControlGetPartBounds = 102,

  /**
   * Sent when a client wants to change an arbitrary setting of your
   * control. See the SetControlData API. (Mac OS X only)
   */
  kEventControlSetData = 103,

  /**
   * Sent when a client wants to get an arbitrary setting of your
   * control. See the GetControlData API. (Mac OS X only)
   */
  kEventControlGetData = 104,

  /**
   * Sent when your control's value, min, max, or view size has
   * changed. Useful so other entities can watch for your control's
   * value to change. (Mac OS X only)
   */
  kEventControlValueFieldChanged = 151,

  /**
   * Sent when a control was embedded within your control. (Mac OS X
   * only)
   */
  kEventControlAddedSubControl = 152,

  /**
   * Sent when one of your child controls will be removed from your
   * control. (Mac OS X only)
   */
  kEventControlRemovingSubControl = 153,

  /**
   * Sent when one your control's bounding rectangle has changed. (Mac
   * OS X only)
   */
  kEventControlBoundsChanged = 154,

  /**
   * Sent when one your control's owning window has changed.  Useful to
   * udpate any dependencies that your control has on its owning
   * window. (Mac OS X only)
   */
  kEventControlOwningWindowChanged = 159,

  /**
   * Sent when someone is trying to send an old-style CDEF message to
   * your control. (Mac OS X only)
   */
  kEventControlArbitraryMessage = 201
};

/**
 *  Summary:
 *    Control bounds change event attributes
 *
 *  Discussion:
 *    When the toolbox sends out a kEventControlBoundsChanged event, it
 *    also sends along a parameter containing attributes of the event.
 *    These attributes can be used to determine what aspect of the
 *    control changed (position, size, or both).
 */
enum {

  /**
   * The dimensions of the control (width and height) changed.
   */
  kControlBoundsChangeSizeChanged = (1 << 2),

  /**
   * The top left corner (position) changed.
   */
  kControlBoundsChangePositionChanged = (1 << 3)
};

/**
    Parameters for control events:

    kEventControlInitialize
        -->     kEventParamDirectObject     typeControlRef
        -->     kEventParamInitCollection   typeCollection
        <--     kEventParamControlFeatures  typeUInt32

    kEventControlDispose
        -->     kEventParamDirectObject     typeControlRef

    kEventControlGetOptimalBounds
        Required parameters:
        -->     kEventParamDirectObject                     typeControlRef
        <--     kEventParamControlOptimalBounds             typeQDRectangle

        Optional parameters:
        <--     kEventParamControlOptimalBaselineOffset     typeShortInteger
   (optional)

    kEventControlHit
        -->     kEventParamDirectObject     typeControlRef
        -->     kEventParamControlPart      typeControlPartCode
        -->     kEventParamKeyModifiers     typeUInt32

    kEventControlSimulateHit
        -->     kEventParamDirectObject     typeControlRef

    kEventControlHitTest
        -->     kEventParamDirectObject     typeControlRef
        -->     kEventParamMouseLocation    typeQDPoint
        <--     kEventParamControlPart      typeControlPartCode

    kEventControlDraw
        Required parameters:
        -->     kEventParamDirectObject     typeControlRef

        Optional parameters:
        -->     kEventParamControlPart      typeControlPartCode
                    (draw the entire control if kEventParamControlPart is not
   present)
        -->     kEventParamGrafPort         typeGrafPtr
                    (draw into the current port if kEventParamGrafPort is not
   present)

    kEventControlApplyBackground
        Required parameters:
        -->     kEventParamDirectObject         typeControlRef
        -->     kEventParamControlSubControl    typeControlRef
        -->     kEventParamControlDrawDepth     typeShortInteger
        -->     kEventParamControlDrawInColor   typeBoolean

        Optional parameters:
        -->     kEventParamGrafPort             typeGrafPtr
                    (apply to the current port if kEventParamGrafPort is not
   present)

    kEventControlApplyTextColor
        Required parameters:
        -->     kEventParamDirectObject         typeControlRef
        -->     kEventParamControlSubControl    typeControlRef
        -->     kEventParamControlDrawDepth     typeShortInteger
        -->     kEventParamControlDrawInColor   typeBoolean

        Optional parameters:
        -->     kEventParamCGContextRef         typeCGContextRef
        -->     kEventParamGrafPort             typeGrafPtr
                    (apply to the current port if kEventParamGrafPort is not
   present)

    kEventControlSetFocusPart
        -->     kEventParamDirectObject     typeControlRef
        <->     kEventParamControlPart      typeControlPartCode

    kEventControlGetFocusPart
        -->     kEventParamDirectObject     typeControlRef
        <--     kEventParamControlPart      typeControlPartCode

    kEventControlActivate
        -->     kEventParamDirectObject     typeControlRef

    kEventControlDeactivate
        -->     kEventParamDirectObject     typeControlRef

    kEventControlSetCursor
        -->     kEventParamDirectObject     typeControlRef
        -->     kEventParamMouseLocation    typeQDPoint
        -->     kEventParamKeyModifiers     typeUInt32

    kEventControlContextualMenuClick
        -->     kEventParamDirectObject     typeControlRef
        -->     kEventParamMouseLocation    typeQDPoint

    kEventControlClick
        -->     kEventParamDirectObject     typeControlRef
        -->     [other parameters from kEventMouseDown]

    kEventControlTrack
        -->     kEventParamDirectObject     typeControlRef
        -->     kEventParamMouseLocation    typeQDPoint
        <->     kEventParamKeyModifiers     typeUInt32
        -->     kEventParamControlAction    typeControlActionUPP
        <--     kEventParamControlPart      typeControlPartCode

    kEventControlGetScrollToHereStartPoint
        -->     kEventParamDirectObject     typeControlRef
        <->     kEventParamMouseLocation    typeQDPoint
        -->     kEventParamKeyModifiers     typeUInt32

    kEventControlGetIndicatorDragConstraint
        -->     kEventParamDirectObject                     typeControlRef
        -->     kEventParamMouseLocation                    typeQDPoint
        -->     kEventParamKeyModifiers                     typeUInt32
        <--     kEventParamControlIndicatorDragConstraint
   typeIndicatorDragConstraint

    kEventControlIndicatorMoved
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamControlIndicatorRegion   typeQDRgnHandle
        -->     kEventParamControlIsGhosting        typeBoolean

    kEventControlGhostingFinished
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamControlIndicatorOffset   typeQDPoint

    kEventControlGetActionProcPart
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamKeyModifiers             typeUInt32
        <->     kEventParamControlPart              typeControlPartCode

    kEventControlGetPartRegion
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamControlPart              typeControlPartCode
        -->     kEventParamControlRegion            typeQDRgnHandle

    kEventControlGetPartBounds
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamControlPart              typeControlPartCode
        <--     kEventParamControlPartBounds        typeQDRectangle

    kEventControlSetData
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamControlPart              typeControlPartCode
        -->     kEventParamControlDataTag           typeEnumeration
        -->     kEventParamControlDataBuffer        typePtr
        -->     kEventParamControlDataBufferSize    typeLongInteger

    kEventControlGetData
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamControlPart              typeControlPartCode
        -->     kEventParamControlDataTag           typeEnumeration
        -->     kEventParamControlDataBuffer        typePtr
        <->     kEventParamControlDataBufferSize    typeLongInteger

    kEventControlValueFieldChanged
        -->     kEventParamDirectObject             typeControlRef

    kEventControlAddedSubControl
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamControlSubControl        typeControlRef

    kEventControlRemovingSubControl
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamControlSubControl        typeControlRef

    kEventControlBoundsChanged
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamAttributes               typeUInt32
        -->     kEventParamOriginalBounds           typeQDRectangle
        -->     kEventParamPreviousBounds           typeQDRectangle
        -->     kEventParamCurrentBounds            typeQDRectangle

    kEventControlOwningWindowChanged
        -->     kEventParamDirectObject                 typeControlRef
        -->     kEventParamAttributes                   typeUInt32
        -->     kEventParamControlOriginalOwningWindow  typeWindowRef
        -->     kEventParamControlCurrentOwningWindow   typeWindowRef

    kEventControlArbitraryMessage
        -->     kEventParamDirectObject             typeControlRef
        -->     kEventParamControlMessage           typeShortInteger
        -->     kEventParamControlParam             typeLongInteger
        <--     kEventParamControlResult            typeLongInteger
*/
/*��������������������������������������������������������������������������������������*/
/*  Tablet Events (and tablet data in mouse events) */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Tablet events (kEventClassTablet)
 */
enum {

  /**
   * Indicates that the pen has moved on or near a tablet. Same as
   * deprecated kEventTabletPointer. Available in Mac OS X only.
   */
  kEventTabletPoint = 1,

  /**
   * Indicates that the pen has entered or exited proximity of a
   * tablet. Available in Mac OS X only.
   */
  kEventTabletProximity = 2,
  kEventTabletPointer =
      1 /* deprecated form for compatibility only, use kEventTabletPoint*/
};

struct TabletPointRec {
  SInt32 absX;    /* absolute x coordinate in tablet space at full tablet
                     resolution */
  SInt32 absY;    /* absolute y coordinate in tablet space at full tablet
                     resolution */
  SInt32 absZ;    /* absolute z coordinate in tablet space at full tablet
                     resolution */
  UInt16 buttons; /* one bit per button - bit 0 is first button - 1 = closed */
  UInt16
      pressure; /* scaled pressure value; MAXPRESSURE=(2^16)-1, MINPRESSURE=0 */
  SInt16 tiltX; /* scaled tilt x value; range is -((2^15)-1) to (2^15)-1 (-32767
                   to 32767) */
  SInt16 tiltY; /* scaled tilt y value; range is -((2^15)-1) to (2^15)-1 (-32767
                   to 32767) */
  UInt16 rotation; /* Fixed-point representation of device rotation in a 10.6
                      format */
  SInt16 tangentialPressure; /* tangential pressure on the device; range same as
                                tilt */
  UInt16 deviceID; /* system-assigned unique device ID - matches to deviceID
                      field in proximity event */
  SInt16 vendor1;  /* vendor-defined signed 16-bit integer */
  SInt16 vendor2;  /* vendor-defined signed 16-bit integer */
  SInt16 vendor3;  /* vendor-defined signed 16-bit integer */
};
typedef struct TabletPointRec TabletPointRec;
typedef TabletPointRec TabletPointerRec;
struct TabletProximityRec {
  UInt16 vendorID;  /* vendor-defined ID - typically will be USB vendor ID */
  UInt16 tabletID;  /* vendor-defined tablet ID - typically will be USB product
                       ID for the tablet */
  UInt16 pointerID; /* vendor-defined ID of the specific pointing device */
  UInt16 deviceID;  /* system-assigned unique device ID - matches to deviceID
                       field in tablet event */
  UInt16 systemTabletID;      /* system-assigned unique tablet ID */
  UInt16 vendorPointerType;   /* vendor-defined pointer type */
  UInt32 pointerSerialNumber; /* vendor-defined serial number of the specific
                                 pointing device */
  UInt64 uniqueID;            /* vendor-defined unique ID for this pointer */
  UInt32 capabilityMask; /* mask representing the capabilities of the device */
  UInt8 pointerType;     /* type of pointing device - enum to be defined */
  UInt8 enterProximity;  /* non-zero = entering; zero = leaving */
};
typedef struct TabletProximityRec TabletProximityRec;
/*��������������������������������������������������������������������������������������*/
/* Volume Events */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Volume events (kEventClassVolume)
 */
enum {

  /**
   * A new volume has been mounted (or new media inserted). Available
   * on Mac OS X and CarbonLib 1.3.1 and later.
   */
  kEventVolumeMounted = 1, /* new volume mounted*/

  /**
   * An existing volume has been unmounted (or media ejected).
   * Available on Mac OS X and CarbonLib 1.3.1 and later.
   */
  kEventVolumeUnmounted = 2 /* volume has been ejected or unmounted*/
};

/**
    Parameters for volume events:

    kEventVolumeMounted
        -->     kEventParamDirectObject     typeFSVolumeRefNum

    kEventVolumeUnmounted
        -->     kEventParamDirectObject     typeFSVolumeRefNum
*/

/* types for volume events*/

enum {
  typeFSVolumeRefNum = FOUR_CHAR_CODE('voln') /* FSVolumeRefNum*/
};

/*��������������������������������������������������������������������������������������*/
/* Appearance Events */
/*��������������������������������������������������������������������������������������*/
/* Appearance Events */

/**
 *  Discussion:
 *    Appearance events (kEventClassAppearance)
 */
enum {

  /**
   * The scroll bar variant has changed. Available on Mac OS X 10.1 and
   * later.
   */
  kEventAppearanceScrollBarVariantChanged = 1
};

/**
    Parameters for appearance events:

    kEventAppearanceScrollBarVariantChanged
        -->     kEventParamNewScrollBarVariant      typeShortInteger
*/
/*��������������������������������������������������������������������������������������*/
/*  Services Events */
/*��������������������������������������������������������������������������������������*/

/**
 *  Summary:
 *    Services events (kEventClassService)
 *
 *  Discussion:
 *    Services are a feature by which applications can communicate with
 *    one another to request and provide services. This communication
 *    happens through the Scrap Manager. When an event is sent that
 *    requires communication for processing or servicing a request, you
 *    will need to use the scrap that is given in the
 *    kEventParamScrapRef parameter of the event in order to
 *    communicate. When your app requests a service, it is usually
 *    acting on data that is currently selected or in focus. Therefore
 *    all of the Services events are sent to the UserFocus event
 *    target. Service events are available on Mac OS X 10.1 and later.
 */
enum {

  /**
   * The user has invoked a service that requires the application to
   * update the given scrap in the kEventParamScrapRef parameter with
   * appropriate data from the focus.
   */
  kEventServiceCopy = 1,

  /**
   * The user has invoked a service that requires the application to
   * update the current focus with data from the scrap that is given in
   * the kEventParamScrapRef parameter.
   */
  kEventServicePaste = 2,

  /**
   * The Services Manager needs to know what types of data the
   * application can copy and paste to and from the scrap in order to
   * update the Services menu to enable items that the user can select.
   * This event sends two CFMutableArrayRefs for the application to add
   * the types to: the kEventParamServiceCopyTypes and the
   * kEventParamServicePasteTypes parameters. The types that are added
   * are CFStringRefs. There is a convenience function,
   * CreateTypeStringWithOSType(), which takes an OSType and will
   * create a CFStringRef that you can add to the array(s).
   */
  kEventServiceGetTypes = 3,

  /**
   * If the application is a service provider, this event will get sent
   * when a Service is requested of the app. The scrap that should be
   * used to send and receive data from the requester is provided in
   * the kEventParamScrapRef parameter. The
   * kEventParamServiceMessageName parameter contains a CFStringRef
   * that indicates which advertised service was invoked.
   */
  kEventServicePerform = 4
};

/**
    Parameters for service events:

    kEventServiceCopy
        -->     kEventParamScrapRef                 typeScrapRef

    kEventServicePaste
        -->     kEventParamScrapRef                 typeScrapRef

    kEventServiceGetTypes
        -->     kEventParamServiceCopyTypes         typeCFMutableArrayRef of
   CFStringRefs
        -->     kEventParamServicePasteTypes        typeCFMutableArrayRef of
   CFStringRefs

    kEventServicePerform
        -->     kEventParamScrapRef                 typeScrapRef
        -->     kEventParamServiceMessageName       typeCFStringRef
        -->     kEventParamServiceUserData          typeCFStringRef
*/
/**
 *  CreateTypeStringWithOSType()
 *
 *  Discussion:
 *    This routine is used to convert an OSType to a CFStringRef that
 *    Services will understand.
 *
 *  Parameters:
 *
 *    inType:
 *      The OSType that needs to be converted to a CFString.
 *
 *  Result:
 *    A CFStringRef that contains the string that corresponds to the
 *    given OSType. This follows CoreFoundation semantics in that it
 *    will return NULL for failure, and because it is a "Create"
 *    function you will need to CFRelease() this string when it is no
 *    longer needed.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.1 and later \mac_os_x         in version 10.1 and later
 */
EXTERN_API(CFStringRef)
CreateTypeStringWithOSType(OSType inType);

/*��������������������������������������������������������������������������������������*/
/* Parameter names and types */
/*��������������������������������������������������������������������������������������*/
enum {
  kEventParamDirectObject =
      FOUR_CHAR_CODE('----') /* type varies depending on event*/
};

/* Generic toolbox parameters and types*/

enum {
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

enum {
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

enum {
  kEventParamKeyCode = FOUR_CHAR_CODE('kcod'),         /* typeUInt32*/
  kEventParamKeyMacCharCodes = FOUR_CHAR_CODE('kchr'), /* typeChar*/
  kEventParamKeyModifiers = FOUR_CHAR_CODE('kmod'),    /* typeUInt32*/
  kEventParamKeyUnicodes = FOUR_CHAR_CODE('kuni'),     /* typeUnicodeText*/
  kEventParamKeyboardType = FOUR_CHAR_CODE('kbdt'),    /* typeUInt32*/
  typeEventHotKeyID = FOUR_CHAR_CODE('hkid')           /* EventHotKeyID*/
};

/* TextInput event parameters*/

enum {
  kEventParamTextInputSendRefCon =
      FOUR_CHAR_CODE('tsrc'), /*    typeLongInteger*/
  kEventParamTextInputSendComponentInstance =
      FOUR_CHAR_CODE('tsci'), /*    typeComponentInstance*/
  kEventParamTextInputSendSLRec =
      FOUR_CHAR_CODE('tssl'), /*    typeIntlWritingCode*/
  kEventParamTextInputReplySLRec =
      FOUR_CHAR_CODE('trsl'), /*    typeIntlWritingCode*/
  kEventParamTextInputSendText =
      FOUR_CHAR_CODE('tstx'), /*    typeUnicodeText (if TSMDocument is Unicode),
                                 otherwise typeChar*/
  kEventParamTextInputReplyText =
      FOUR_CHAR_CODE('trtx'), /*    typeUnicodeText (if TSMDocument is Unicode),
                                 otherwise typeChar*/
  kEventParamTextInputSendUpdateRng =
      FOUR_CHAR_CODE('tsup'), /*    typeTextRangeArray*/
  kEventParamTextInputSendHiliteRng =
      FOUR_CHAR_CODE('tshi'), /*    typeTextRangeArray*/
  kEventParamTextInputSendClauseRng =
      FOUR_CHAR_CODE('tscl'), /*    typeOffsetArray*/
  kEventParamTextInputSendPinRng = FOUR_CHAR_CODE('tspn'), /*    typeTextRange*/
  kEventParamTextInputSendFixLen =
      FOUR_CHAR_CODE('tsfx'), /*    typeLongInteger*/
  kEventParamTextInputSendLeadingEdge =
      FOUR_CHAR_CODE('tsle'), /*    typeBoolean*/
  kEventParamTextInputReplyLeadingEdge =
      FOUR_CHAR_CODE('trle'), /*    typeBoolean*/
  kEventParamTextInputSendTextOffset =
      FOUR_CHAR_CODE('tsto'), /*    typeLongInteger*/
  kEventParamTextInputReplyTextOffset =
      FOUR_CHAR_CODE('trto'), /*    typeLongInteger*/
  kEventParamTextInputReplyRegionClass =
      FOUR_CHAR_CODE('trrg'), /*    typeLongInteger*/
  kEventParamTextInputSendCurrentPoint =
      FOUR_CHAR_CODE('tscp'), /*    typeQDPoint*/
  kEventParamTextInputSendDraggingMode =
      FOUR_CHAR_CODE('tsdm'),                              /*    typeBoolean*/
  kEventParamTextInputReplyPoint = FOUR_CHAR_CODE('trpt'), /*    typeQDPoint*/
  kEventParamTextInputReplyFont =
      FOUR_CHAR_CODE('trft'), /*    typeLongInteger*/
  kEventParamTextInputReplyFMFont = FOUR_CHAR_CODE('trfm'), /*    typeUInt32*/
  kEventParamTextInputReplyPointSize = FOUR_CHAR_CODE('trpz'), /*    typeFixed*/
  kEventParamTextInputReplyLineHeight =
      FOUR_CHAR_CODE('trlh'), /*    typeShortInteger*/
  kEventParamTextInputReplyLineAscent =
      FOUR_CHAR_CODE('trla'), /*    typeShortInteger*/
  kEventParamTextInputReplyTextAngle = FOUR_CHAR_CODE('trta'), /*    typeFixed*/
  kEventParamTextInputSendShowHide = FOUR_CHAR_CODE('tssh'), /*    typeBoolean*/
  kEventParamTextInputReplyShowHide =
      FOUR_CHAR_CODE('trsh'), /*    typeBoolean*/
  kEventParamTextInputSendKeyboardEvent =
      FOUR_CHAR_CODE('tske'), /*    typeEventRef*/
  kEventParamTextInputSendTextServiceEncoding =
      FOUR_CHAR_CODE('tsse'), /*    typeUInt32*/
  kEventParamTextInputSendTextServiceMacEncoding =
      FOUR_CHAR_CODE('tssm') /*    typeUInt32*/
};

/* Command event parameters and types*/

enum {
  kEventParamHICommand = FOUR_CHAR_CODE('hcmd'), /* typeHICommand*/
  typeHICommand = FOUR_CHAR_CODE('hcmd')         /* HICommand*/
};

/* Window event parameters and types*/

enum {
  kEventParamWindowFeatures = FOUR_CHAR_CODE('wftr'), /* typeUInt32*/
  kEventParamWindowDefPart = FOUR_CHAR_CODE('wdpc'),  /* typeWindowDefPartCode*/
  kEventParamCurrentBounds = FOUR_CHAR_CODE('crct'),  /* typeQDRectangle*/
  kEventParamOriginalBounds = FOUR_CHAR_CODE('orct'), /* typeQDRectangle*/
  kEventParamPreviousBounds = FOUR_CHAR_CODE('prct'), /* typeQDRectangle*/
  kEventParamClickActivation =
      FOUR_CHAR_CODE('clac'), /* typeClickActivationResult*/
  kEventParamWindowRegionCode =
      FOUR_CHAR_CODE('wshp'), /* typeWindowRegionCode*/
  kEventParamWindowDragHiliteFlag = FOUR_CHAR_CODE('wdhf'), /* typeBoolean*/
  kEventParamWindowModifiedFlag = FOUR_CHAR_CODE('wmff'),   /* typeBoolean*/
  kEventParamWindowProxyGWorldPtr = FOUR_CHAR_CODE('wpgw'), /* typeGWorldPtr*/
  kEventParamWindowProxyImageRgn = FOUR_CHAR_CODE('wpir'),  /* typeQDRgnHandle*/
  kEventParamWindowProxyOutlineRgn =
      FOUR_CHAR_CODE('wpor'), /* typeQDRgnHandle*/
  kEventParamWindowStateChangedFlags = FOUR_CHAR_CODE('wscf'), /* typeUInt32 */
  kEventParamWindowTitleFullWidth = FOUR_CHAR_CODE('wtfw'),    /* typeSInt16*/
  kEventParamWindowTitleTextWidth = FOUR_CHAR_CODE('wttw'),    /* typeSInt16*/
  kEventParamWindowGrowRect = FOUR_CHAR_CODE('grct'), /* typeQDRectangle*/
  kEventParamAttributes = FOUR_CHAR_CODE('attr'),     /* typeUInt32*/
  typeWindowRegionCode = FOUR_CHAR_CODE('wshp'),      /* WindowRegionCode*/
  typeWindowDefPartCode = FOUR_CHAR_CODE('wdpt'),     /* WindowDefPartCode*/
  typeClickActivationResult = FOUR_CHAR_CODE('clac')  /* ClickActivationResult*/
};

/* Control event parameters and types*/

enum {
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
      FOUR_CHAR_CODE('cirn'),                            /* typeQDRgnHandle*/
  kEventParamControlIsGhosting = FOUR_CHAR_CODE('cgst'), /* typeBoolean*/
  kEventParamControlIndicatorOffset = FOUR_CHAR_CODE('ciof'), /* typeQDPoint*/
  kEventParamControlClickActivationResult =
      FOUR_CHAR_CODE('ccar'), /* typeClickActivationResult*/
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

enum {
  kEventParamCurrentMenuTrackingMode =
      FOUR_CHAR_CODE('cmtm'), /* typeMenuTrackingMode*/
  kEventParamNewMenuTrackingMode =
      FOUR_CHAR_CODE('nmtm'),                        /* typeMenuTrackingMode*/
  kEventParamMenuFirstOpen = FOUR_CHAR_CODE('1sto'), /* typeBoolean*/
  kEventParamMenuItemIndex = FOUR_CHAR_CODE('item'), /* typeMenuItemIndex*/
  kEventParamMenuCommand = FOUR_CHAR_CODE('mcmd'),   /* typeMenuCommand*/
  kEventParamEnableMenuForKeyEvent = FOUR_CHAR_CODE('fork'), /* typeBoolean*/
  kEventParamMenuEventOptions =
      FOUR_CHAR_CODE('meop'),                         /* typeMenuEventOptions*/
  kEventParamMenuContext = FOUR_CHAR_CODE('mctx'),    /* typeUInt32*/
  kEventParamMenuItemBounds = FOUR_CHAR_CODE('mitb'), /* typeQDRectangle*/
  kEventParamMenuMarkBounds = FOUR_CHAR_CODE('mmkb'), /* typeQDRectangle*/
  kEventParamMenuIconBounds = FOUR_CHAR_CODE('micb'), /* typeQDRectangle*/
  kEventParamMenuTextBounds = FOUR_CHAR_CODE('mtxb'), /* typeQDRectangle*/
  kEventParamMenuTextBaseline = FOUR_CHAR_CODE('mtbl'), /* typeShortInteger*/
  kEventParamMenuCommandKeyBounds = FOUR_CHAR_CODE('mcmb'), /* typeQDRectangle*/
  kEventParamMenuVirtualTop = FOUR_CHAR_CODE('mvrt'),       /* typeLongInteger*/
  kEventParamMenuVirtualBottom = FOUR_CHAR_CODE('mvrb'),    /* typeLongInteger*/
  kEventParamMenuDrawState = FOUR_CHAR_CODE('mdrs'),  /* typeThemeDrawState*/
  kEventParamMenuItemType = FOUR_CHAR_CODE('mitp'),   /* typeThemeMenuItemType*/
  kEventParamMenuItemWidth = FOUR_CHAR_CODE('mitw'),  /* typeShortInteger*/
  kEventParamMenuItemHeight = FOUR_CHAR_CODE('mith'), /* typeShortInteger*/
  typeMenuItemIndex = FOUR_CHAR_CODE('midx'),         /* MenuItemIndex*/
  typeMenuCommand = FOUR_CHAR_CODE('mcmd'),           /* MenuCommand*/
  typeMenuTrackingMode = FOUR_CHAR_CODE('mtmd'),      /* MenuTrackingMode*/
  typeMenuEventOptions = FOUR_CHAR_CODE('meop'),      /* MenuEventOptions*/
  typeThemeMenuState = FOUR_CHAR_CODE('tmns'),        /* ThemeMenuState*/
  typeThemeMenuItemType = FOUR_CHAR_CODE('tmit')      /* ThemeMenuItemType*/
};

/* Application event parameters*/

enum {
  kEventParamProcessID = FOUR_CHAR_CODE('psn '),    /* typeProcessSerialNumber*/
  kEventParamLaunchRefCon = FOUR_CHAR_CODE('lref'), /* typeUInt32*/
  kEventParamLaunchErr = FOUR_CHAR_CODE('err ')     /* typeOSStatus*/
};

/* Tablet event parameters and types*/

enum {
  kEventParamTabletPointRec = FOUR_CHAR_CODE('tbrc'), /* typeTabletPointRec*/
  kEventParamTabletProximityRec =
      FOUR_CHAR_CODE('tbpx'),                  /* typeTabletProximityRec*/
  typeTabletPointRec = FOUR_CHAR_CODE('tbrc'), /* kEventParamTabletPointRec*/
  typeTabletProximityRec =
      FOUR_CHAR_CODE('tbpx'), /* kEventParamTabletProximityRec*/
  kEventParamTabletPointerRec =
      FOUR_CHAR_CODE('tbrc'), /* typeTabletPointerRec      -- deprecated, for
                                 compatibility only*/
  typeTabletPointerRec =
      FOUR_CHAR_CODE('tbrc') /* kEventParamTabletPointerRec    -- deprecated,
                                for compatibility only*/
};

/* Appearance event parameters*/

enum {
  kEventParamNewScrollBarVariant = FOUR_CHAR_CODE('nsbv') /* typeShortInteger*/
};

/* Service event parameters*/

enum {
  kEventParamScrapRef = FOUR_CHAR_CODE('scrp'), /*    typeScrapRef*/
  kEventParamServiceCopyTypes =
      FOUR_CHAR_CODE('svsd'), /*    typeCFMutableArrayRef*/
  kEventParamServicePasteTypes =
      FOUR_CHAR_CODE('svpt'), /*    typeCFMutableArrayRef*/
  kEventParamServiceMessageName =
      FOUR_CHAR_CODE('svmg'),                          /*    typeCFStringRef*/
  kEventParamServiceUserData = FOUR_CHAR_CODE('svud'), /*    typeCFStringRef*/
  typeScrapRef = FOUR_CHAR_CODE('scrp'),               /*    ScrapRef*/
  typeCFMutableArrayRef = FOUR_CHAR_CODE('cfma')       /*    CFMutableArrayRef*/
};

/*======================================================================================*/
/*  EVENT HANDLERS */
/*======================================================================================*/

typedef struct OpaqueEventHandlerRef *EventHandlerRef;
typedef struct OpaqueEventHandlerCallRef *EventHandlerCallRef;

/*��������������������������������������������������������������������������������������*/
/*  � EventHandler specification */
/*��������������������������������������������������������������������������������������*/

/**
 *  EventHandlerProcPtr
 *
 *  Discussion:
 *    Callback for receiving events sent to a target this callback is
 *    installed on.
 *
 *  Parameters:
 *
 *    inHandlerCallRef:
 *      A reference to the current handler call chain. This is sent to
 *      your handler so that you can call CallNextEventHandler if you
 *      need to.
 *
 *    inEvent:
 *      The Event.
 *
 *    inUserData:
 *      The app-specified data you passed in a call to
 *      InstallEventHandler.
 *
 *  Result:
 *    An operating system result code. Returning noErr indicates you
 *    handled the event. Returning eventNotHandledErr indicates you did
 *    not handle the event and perhaps the toolbox should take other
 *    action.
 */
typedef CALLBACK_API(OSStatus,
                     EventHandlerProcPtr)(EventHandlerCallRef inHandlerCallRef,
                                          EventRef inEvent, void *inUserData);
typedef STACK_UPP_TYPE(EventHandlerProcPtr) EventHandlerUPP;
/**
 *  NewEventHandlerUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(EventHandlerUPP)
NewEventHandlerUPP(EventHandlerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppEventHandlerProcInfo = 0x00000FF0
}; /* pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
inline EventHandlerUPP NewEventHandlerUPP(EventHandlerProcPtr userRoutine) {
  return (EventHandlerUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                               uppEventHandlerProcInfo,
                                               GetCurrentArchitecture());
}
#else
#define NewEventHandlerUPP(userRoutine)                                        \
  (EventHandlerUPP)                                                            \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppEventHandlerProcInfo,    \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeEventHandlerUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposeEventHandlerUPP(EventHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeEventHandlerUPP(EventHandlerUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeEventHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeEventHandlerUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(OSStatus)
InvokeEventHandlerUPP(EventHandlerCallRef inHandlerCallRef, EventRef inEvent,
                      void *inUserData, EventHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline OSStatus InvokeEventHandlerUPP(EventHandlerCallRef inHandlerCallRef,
                                      EventRef inEvent, void *inUserData,
                                      EventHandlerUPP userUPP) {
  return (OSStatus)CALL_THREE_PARAMETER_UPP(
      userUPP, uppEventHandlerProcInfo, inHandlerCallRef, inEvent, inUserData);
}
#else
#define InvokeEventHandlerUPP(inHandlerCallRef, inEvent, inUserData, userUPP)  \
  (OSStatus)                                                                   \
      CALL_THREE_PARAMETER_UPP((userUPP), uppEventHandlerProcInfo,             \
                               (inHandlerCallRef), (inEvent), (inUserData))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewEventHandlerProc(userRoutine) NewEventHandlerUPP(userRoutine)
#define CallEventHandlerProc(userRoutine, inHandlerCallRef, inEvent,           \
                             inUserData)                                       \
  InvokeEventHandlerUPP(inHandlerCallRef, inEvent, inUserData, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

/*��������������������������������������������������������������������������������������*/
/*  � Installing Event Handlers */
/*                                                                                      */
/* Use these routines to install event handlers for a specific toolbox object.
 * You may  */
/* pass zero for inNumTypes and NULL for inList if you need to be in a situation
 * where  */
/* you know you will be receiving events, but not exactly which ones at the time
 * you    */
/* are installing the handler. Later, your application can call the Add/Remove
 * routines */
/* listed below this section. */
/*                                                                                      */
/* You can only install a specific handler once. The combination of inHandler
 * and       */
/* inUserData is considered the 'signature' of a handler. Any attempt to install
 * a new  */
/* handler with the same proc and user data as an already-installed handler will
 * result */
/* in eventHandlerAlreadyInstalledErr. Installing the same proc and user data on
 * a      */
/* different object is legal. */
/*                                                                                      */
/* Upon successful completion of this routine, you are returned an
 * EventHandlerRef,     */
/* which you can use in various other calls, and is passed to your event
 * handler. You   */
/* use it to extract information about the handler, such as the target (window,
 * etc.)   */
/* if you have the same handler installed for different objects and need to
 * perform     */
/* actions on the current target (say, call a window manager function). */
/*��������������������������������������������������������������������������������������*/
typedef struct OpaqueEventTargetRef *EventTargetRef;
/**
 *  GetWindowEventTarget()
 *
 *  Discussion:
 *    Returns the EventTargetRef for the specified window. Once you
 *    obtain this reference, you can send events to the target and
 *    install an event handler on it.
 *
 *  Parameters:
 *
 *    inWindow:
 *      The window to return the target for.
 *
 *  Result:
 *    An EventTargetRef.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventTargetRef)
GetWindowEventTarget(WindowRef inWindow);

/**
 *  GetControlEventTarget()
 *
 *  Discussion:
 *    Returns the EventTargetRef for the specified control. Once you
 *    obtain this reference, you can send events to the target and
 *    install event handler on it.
 *
 *  Parameters:
 *
 *    inControl:
 *      The control to return the target for.
 *
 *  Result:
 *    An EventTargetRef.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventTargetRef)
GetControlEventTarget(ControlRef inControl);

/**
 *  GetMenuEventTarget()
 *
 *  Discussion:
 *    Returns the EventTargetRef for the specified menu. Once you
 *    obtain this reference, you can send events to the target and
 *    install event handler on it.
 *
 *  Parameters:
 *
 *    inMenu:
 *      The menu to return the target for.
 *
 *  Result:
 *    An EventTargetRef.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventTargetRef)
GetMenuEventTarget(MenuRef inMenu);

/**
 *  GetApplicationEventTarget()
 *
 *  Discussion:
 *    Returns the EventTargetRef for the application. Once you obtain
 *    this reference, you can send events to the target and install
 *    event handler on it.
 *
 *  Result:
 *    An EventTargetRef.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventTargetRef)
GetApplicationEventTarget(void);

/**
 *  GetUserFocusEventTarget()
 *
 *  Discussion:
 *    Returns the EventTargetRef for the current user focus at the time
 *    of the call. Keyboard events are always sent to this target.
 *
 *  Result:
 *    An EventTargetRef.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(EventTargetRef)
GetUserFocusEventTarget(void);

/**
 *  GetEventDispatcherTarget()
 *
 *  Discussion:
 *    Returns the EventTargetRef for the standard toolbox dispatcher.
 *    You typically would never need to use this, but there are some
 *    exotic apps that need to pick events off the event queue and call
 *    the dispatcher themselves. This allows you to do just that
 *    instead of calling RunApplicationEventLoop to handle it all.
 *
 *  Result:
 *    An EventTargetRef.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(EventTargetRef)
GetEventDispatcherTarget(void);

/**
 *  InstallEventHandler()
 *
 *  Discussion:
 *    Installs an event handler on a specified target. Your handler
 *    proc will be called with the events you registered with when an
 *    event of the corresponding type and class are send to the target
 *    you are installing your handler on.
 *
 *  Parameters:
 *
 *    inTarget:
 *      The target to register your handler with.
 *
 *    inHandler:
 *      A pointer to your handler function.
 *
 *    inNumTypes:
 *      The number of events you are registering for.
 *
 *    inList:
 *      A pointer to an array of EventTypeSpec entries representing the
 *      events you are interested in.
 *
 *    inUserData:
 *      The value passed in this parameter is passed on to your event
 *      handler proc when it is called.
 *
 *    outRef:
 *      Receives an EventHandlerRef, which you can use later to remove
 *      the handler. You can pass null if you don't want the reference
 *      - when the target is disposed, the handler will be disposed as
 *      well.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
InstallEventHandler(EventTargetRef inTarget, EventHandlerUPP inHandler,
                    UInt32 inNumTypes, const EventTypeSpec *inList,
                    void *inUserData,
                    EventHandlerRef *outRef); /* can be NULL */

/**
 *  InstallStandardEventHandler()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
InstallStandardEventHandler(EventTargetRef inTarget);

#define InstallApplicationEventHandler(h, n, l, u, r)                          \
  InstallEventHandler(GetApplicationEventTarget(), (h), (n), (l), (u), (r))

#define InstallWindowEventHandler(t, h, n, l, u, r)                            \
  InstallEventHandler(GetWindowEventTarget(t), (h), (n), (l), (u), (r))

#define InstallControlEventHandler(t, h, n, l, u, r)                           \
  InstallEventHandler(GetControlEventTarget(t), (h), (n), (l), (u), (r))

#define InstallMenuEventHandler(t, h, n, l, u, r)                              \
  InstallEventHandler(GetMenuEventTarget(t), (h), (n), (l), (u), (r))

/**
    You can use the following macro in your code to allow you to set up an
 event handler lazily. You pass the name of your event handler in. You should
   use this with caution on Mac OS 9 systems since it could cause heap
 fragmentation.
*/
#define DEFINE_ONE_SHOT_HANDLER_GETTER(x)                                      \
  EventHandlerUPP Get##x##UPP() {                                              \
    static EventHandlerUPP sHandler = NULL;                                    \
                                                                               \
    if (sHandler == NULL)                                                      \
      sHandler = NewEventHandlerUPP(x);                                        \
                                                                               \
    return sHandler;                                                           \
  }

/**
 *  RemoveEventHandler()
 *
 *  Discussion:
 *    Removes an event handler from the target it was bound to.
 *
 *  Parameters:
 *
 *    inHandlerRef:
 *      The handler ref to remove (returned in a call to
 *      InstallEventHandler). After you call this function, the handler
 *      ref is considered to be invalid and can no longer be used.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
RemoveEventHandler(EventHandlerRef inHandlerRef);

/*��������������������������������������������������������������������������������������*/
/*  � Adjusting set of event types after a handler is created */
/*                                                                                      */
/* After installing a handler with the routine above, you can adjust the event
 * type     */
/* list telling the toolbox what events to send to that handler by calling the
 * two      */
/* routines below. If you add an event type twice for the same handler, your
 * handler    */
/* will only be called once, but it will take two RemoveEventType calls to stop
 * your    */
/* handler from being called with that event type. In other words, the install
 * count    */
/* for each event type is maintained by the toolbox. This might allow you, for
 * example  */
/* to have subclasses of a window object register for types without caring if
 * the base  */
/* class has already registered for that type. When the subclass removes its
 * types, it  */
/* can successfully do so without affecting the base class's reception of its
 * event     */
/* types, yielding eternal bliss. */
/*��������������������������������������������������������������������������������������*/

/**
 *  AddEventTypesToHandler()
 *
 *  Discussion:
 *    Adds additional events to an event handler that has already been
 *    installed.
 *
 *  Parameters:
 *
 *    inHandlerRef:
 *      The event handler to add the additional events to.
 *
 *    inNumTypes:
 *      The number of events to add.
 *
 *    inList:
 *      A pointer to an array of EventTypeSpec entries.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
AddEventTypesToHandler(EventHandlerRef inHandlerRef, UInt32 inNumTypes,
                       const EventTypeSpec *inList);

/**
 *  RemoveEventTypesFromHandler()
 *
 *  Discussion:
 *    Removes events from an event handler that has already been
 *    installed.
 *
 *  Parameters:
 *
 *    inHandlerRef:
 *      The event handler to remove the events from.
 *
 *    inNumTypes:
 *      The number of events to remove.
 *
 *    inList:
 *      A pointer to an array of EventTypeSpec entries.
 *
 *  Result:
 *    An operating system status code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
RemoveEventTypesFromHandler(EventHandlerRef inHandlerRef, UInt32 inNumTypes,
                            const EventTypeSpec *inList);

/*��������������������������������������������������������������������������������������*/
/*  � Explicit Propogation */
/*                                                                                      */
/*  CallNextEventHandler can be used to call thru to all handlers below the
 * current     */
/*  handler being called. You pass the EventHandlerCallRef passed to your
 * EventHandler  */
/*  into this call so that we know how to properly forward the event. The result
 * of     */
/*  this function should normally be the result of your own handler that you
 * called     */
/*  this API from. The typical use of this routine would be to allow the toolbox
 * to do  */
/*  its standard processing and then follow up with some type of embellishment.
 */
/*��������������������������������������������������������������������������������������*/

/**
 *  CallNextEventHandler()
 *
 *  Discussion:
 *    Calls thru to the event handlers below you in the event handler
 *    stack of the target to which your handler is bound. You might use
 *    this to call thru to the default toolbox handling in order to
 *    post-process the event. You can only call this routine from
 *    within an event handler.
 *
 *  Parameters:
 *
 *    inCallRef:
 *      The event handler call ref passed into your event handler.
 *
 *    inEvent:
 *      The event to pass thru.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
CallNextEventHandler(EventHandlerCallRef inCallRef, EventRef inEvent);

/*��������������������������������������������������������������������������������������*/
/*  � Sending Events */
/*��������������������������������������������������������������������������������������*/
/**
 *  SendEventToEventTarget()
 *
 *  Discussion:
 *    Sends an event to the specified event target.
 *
 *  Parameters:
 *
 *    inEvent:
 *      The event to send.
 *
 *    inTarget:
 *      The target to send it to.
 *
 *  Result:
 *    An operating system result code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
SendEventToEventTarget(EventRef inEvent, EventTargetRef inTarget);

#define SendEventToApplication(e)                                              \
  SendEventToEventTarget((e), GetApplicationEventTarget())

#define SendEventToWindow(e, t)                                                \
  SendEventToEventTarget((e), GetWindowEventTarget(t))

#define SendEventToControl(e, t)                                               \
  SendEventToEventTarget((e), GetControlEventTarget(t))

#define SendEventToMenu(e, t) SendEventToEventTarget((e), GetMenuEventTarget(t))

#define SendEventToUserFocus(e)                                                \
  SendEventToEventTarget((e), GetUserFocusEventTarget())

/*======================================================================================*/
/*  EVENT-BASED OBJECT CLASSES */
/*                                                                                      */
/*  Here it is - the replacement for classic defprocs. This is also a convenient
 * way    */
/*  to create toolbox objects (windows, etc.) that have a specific behavior
 * without     */
/*  installing handlers on each instance of the object. With a toolbox object
 * class,    */
/*  you register your class, then use special creation routines to create
 * objects of    */
/*  that class. The event handlers are automatically installed and ready to go.
 */
/*======================================================================================*/

typedef struct OpaqueToolboxObjectClassRef *ToolboxObjectClassRef;

/**
 *  RegisterToolboxObjectClass()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
RegisterToolboxObjectClass(CFStringRef inClassID,
                           ToolboxObjectClassRef inBaseClass, /* can be NULL */
                           UInt32 inNumEvents, const EventTypeSpec *inEventList,
                           EventHandlerUPP inEventHandler,
                           void *inEventHandlerData,
                           ToolboxObjectClassRef *outClassRef);

/**
 *  UnregisterToolboxObjectClass()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
UnregisterToolboxObjectClass(ToolboxObjectClassRef inClassRef);

/*======================================================================================*/
/*  � Command Routines */
/*======================================================================================*/

/**
 *  ProcessHICommand()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
ProcessHICommand(const HICommand *inCommand);

/*��������������������������������������������������������������������������������������*/
/*  � Event Loop Routines */
/*��������������������������������������������������������������������������������������*/

/**
 *  RunApplicationEventLoop()
 *
 *  Discussion:
 *    This routine is used as the main event loop for a Carbon
 *    Event-based application. Once entered, this function waits for
 *    events to arrive and dispatches them to your event handlers
 *    automatically.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
RunApplicationEventLoop(void);

/**
 *  QuitApplicationEventLoop()
 *
 *  Discussion:
 *    This routine is used to quit the RunApplicationEventLoop
 *    function. Typically, your application doesn't need to call this.
 *    If your application has the Quit menu item tagged with the
 *    kHICommandQuit Menu Command ID, the toolbox will automatically
 *    call this for your application, automatically terminating your
 *    event loop. If your application wants to do pre-processing before
 *    the event loop exits, it should intercept either the
 *    kHICommandQuit menu command, or the kEventApplicationQuit event.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
QuitApplicationEventLoop(void);

/*��������������������������������������������������������������������������������������*/
/*  � Event Modality routines */
/*��������������������������������������������������������������������������������������*/

/**
 *  RunAppModalLoopForWindow()
 *
 *  Discussion:
 *    This routine is used as a replacement to ModalDialog to drive a
 *    Carbon Event-based modal dialog. Once called, this routine will
 *    not exit until QuitAppModalLoopForWindow is called. In Mac OS X
 *    10.0.x, RunAppModalLoopForWindow will fail to re-enable the
 *    menubar before exiting if you dispose of the window during the
 *    modal loop (for example, from a Carbon event handler). You can
 *    work around this bug by retaining the window before calling
 *    RunAppModalLoopForWindow, and releasing it afterwards.
 *
 *  Parameters:
 *
 *    inWindow:
 *      The window you wish to behave modally.
 *
 *  Result:
 *    An operating system status code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(OSStatus)
RunAppModalLoopForWindow(WindowRef inWindow);

/**
 *  QuitAppModalLoopForWindow()
 *
 *  Discussion:
 *    This routine is used to quit a currently running call to
 *    RunAppModalLoopForWindow, i.e. it terminates a modal loop.
 *    Typically this would be called from a handler you have installed
 *    on the modal window in question when the user clicks the
 *    appropriate button, etc.
 *
 *  Parameters:
 *
 *    inWindow:
 *      The window for which to quit the modal state.
 *
 *  Result:
 *    An operating system status code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(OSStatus)
QuitAppModalLoopForWindow(WindowRef inWindow);

/**
 *  BeginAppModalStateForWindow()
 *
 *  Discussion:
 *    This routine is a lower level routine than
 *    RunAppModalLoopForWindow. It can be used if you wish to enter an
 *    app modal state for a window, but need to control the event loop
 *    yourself for whatever reason. In most cases, you would use
 *    RunAppModalLoopForWindow. Once you begin your app modal state,
 *    the menu bar will disable and prepare for the modal situation.
 *    The window must be visible when calling
 *    BeginAppModalStateForWindow; otherwise, windowWrongStateErr is
 *    returned. In Mac OS 10.0.x and CarbonLib 1.3.1,
 *    BeginAppModalStateForWindow can only be called on a window once;
 *    future calls will return an error. This bug is fixed in Mac OS
 *    10.1 and CarbonLib 1.4.
 *
 *  Parameters:
 *
 *    inWindow:
 *      The window you wish to behave modally.
 *
 *  Result:
 *    An operating system status code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(OSStatus)
BeginAppModalStateForWindow(WindowRef inWindow);

/**
 *  EndAppModalStateForWindow()
 *
 *  Discussion:
 *    This routine ends an app modal state started with
 *    BeginAppModalStateForWindow.
 *
 *  Parameters:
 *
 *    inWindow:
 *      The window you wish to stop acting as app modal.
 *
 *  Result:
 *    An operating system status code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(OSStatus)
EndAppModalStateForWindow(WindowRef inWindow);

/*��������������������������������������������������������������������������������������*/
/*  � User Focus */
/*                                                                                      */
/* The 'user focus' is where keyboard input goes. We also use the term 'key'
 * applied    */
/* to windows to mean this. The user focus window is normally the active
 * non-floating   */
/* window or dialog. It is possible to make a floater get the focus, however, by
 * calling*/
/* SetUserFocusWindow. After that call, the event model will automatically route
 * key    */
/* input to the active keyboard focus of that window, if any. Passing
 * kUserFocusAuto    */
/* into the window parameter tells the toolbox to pick what it considers to be
 * the best */
/* candidate for focus. You should call this to restore focus, rather than
 * getting the  */
/* focus, setting it to a special window, and then restoring to the saved focus.
 * There  */
/* are cases, however, when you might want to restore to an explicit window, but
 * the    */
/* typical usage should just be to restore to the kUserFocusAuto focus. */
/*                                                                                      */
/* Keep in mind that setting the focus will only last until you restore focus,
 * or the   */
/* user starts clicking in other windows. When that happens, the toolbox will
 * auto-     */
/* redirect the user focus to a newly selected window. */
/*��������������������������������������������������������������������������������������*/
enum { kUserFocusAuto = -1 };

/**
 *  SetUserFocusWindow()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
SetUserFocusWindow(WindowRef inWindow);

/**
 *  GetUserFocusWindow()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(WindowRef)
GetUserFocusWindow(void);

/*��������������������������������������������������������������������������������������*/
/*  � Default/Cancel buttons */
/*                                                                                      */
/* In our quest to eliminate the need for dialogs when using the new event
 * model, we    */
/* have added the following routines which add dialog-like button control to
 * normal     */
/* windows. With these routines, you can set the default and cancel buttons for
 * a       */
/* window; these work just like the corresponding concepts in dialogs, and when
 */
/* present, the standard toolbox handlers will handle keyboard input mapping to
 * these   */
/* buttons. This means that pressing return or enter will 'press' the default
 * button    */
/* and escape or command-period will 'press' the cancel button. */
/*��������������������������������������������������������������������������������������*/

/**
 *  SetWindowDefaultButton()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
SetWindowDefaultButton(WindowRef inWindow,
                       ControlRef inControl); /* can be NULL */

/**
 *  SetWindowCancelButton()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
SetWindowCancelButton(WindowRef inWindow,
                      ControlRef inControl); /* can be NULL */

/**
 *  GetWindowDefaultButton()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
GetWindowDefaultButton(WindowRef inWindow, ControlRef *outControl);

/**
 *  GetWindowCancelButton()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
GetWindowCancelButton(WindowRef inWindow, ControlRef *outControl);

/*��������������������������������������������������������������������������������������*/
/*  � Global HotKey API */
/*��������������������������������������������������������������������������������������*/
struct EventHotKeyID {
  OSType signature;
  UInt32 id;
};
typedef struct EventHotKeyID EventHotKeyID;
typedef struct OpaqueEventHotKeyRef *EventHotKeyRef;
/**
 *  RegisterEventHotKey()
 *
 *  Discussion:
 *    Registers a global hot key based on the virtual key code and
 *    modifiers you pass in. Only one such combination can exist for
 *    the current application, i.e. multiple entities in the same
 *    application cannot register for the same hot key combination. The
 *    same hot key can, however, be registered by multiple
 *    applications. This means that multiple applications can
 *    potentially be notified when a particular hot key is requested.
 *    This might not necessarily be desirable, but it is how it works
 *    at present.
 *
 *  Parameters:
 *
 *    inHotKeyCode:
 *      The virtual key code of the key to watch
 *
 *    inHotKeyModifiers:
 *      The keyboard modifiers to look for. There must be a modifier
 *      specified, or this function will return paramErr.
 *
 *    inHotKeyID:
 *      The application-specified hot key ID. You will receive this in
 *      the kEventHotKeyPressed event as the direct object parameter.
 *
 *    inTarget:
 *      The target to notify when the hot key is pressed.
 *
 *    inOptions:
 *      Currently unused. Pass 0 or face the consequences.
 *
 *    outRef:
 *      The EventHotKeyRef that represents your new, shiny hot key. You
 *      need this if you later wish to unregister it.
 *
 *  Result:
 *    An operating system status code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(OSStatus)
RegisterEventHotKey(UInt32 inHotKeyCode, UInt32 inHotKeyModifiers,
                    EventHotKeyID inHotKeyID, EventTargetRef inTarget,
                    OptionBits inOptions, EventHotKeyRef *outRef);

/**
 *  UnregisterEventHotKey()
 *
 *  Discussion:
 *    Unregisters a global hot key that was previously registered with
 *    the RegisterEventHotKey API. You do not need to unregister a hot
 *    key when your application terminates, the system will take care
 *    of that for you. This would be used if the user changes a hot key
 *    for something in your application - you would unregister the
 *    previous key and register your new key.
 *
 *  Parameters:
 *
 *    inHotKey:
 *      The EventHotKeyRef to unregister.
 *
 *  Result:
 *    An operating system status code.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(OSStatus)
UnregisterEventHotKey(EventHotKeyRef inHotKey);

/* OBSOLETE CONSTANTS*/

enum {
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
