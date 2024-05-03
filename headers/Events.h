/**
     \file       Events.h

    \brief   Event Manager Interfaces.

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup AppleEvent

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __EVENTS__
#define __EVENTS__

#ifndef __OSUTILS__
#include <OSUtils.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#if !TARGET_OS_MAC || !TARGET_API_MAC_OS8
#ifndef __ENDIAN__
#include <Endian.h>
#endif

#endif /** !TARGET_OS_MAC || !TARGET_API_MAC_OS8 */

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

  typedef UInt16 EventKind;
  typedef UInt16 EventMask;
  enum
  {
    nullEvent = 0,
    mouseDown = 1,
    mouseUp = 2,
    keyDown = 3,
    keyUp = 4,
    autoKey = 5,
    updateEvt = 6,
    diskEvt = 7, /** Not sent in Carbon. See kEventClassVolume in CarbonEvents.h*/
    activateEvt = 8,
    osEvt = 15,
    kHighLevelEvent = 23
  };

  enum
  {
    mDownMask = 1 << mouseDown,   /** mouse button pressed*/
    mUpMask = 1 << mouseUp,       /** mouse button released*/
    keyDownMask = 1 << keyDown,   /** key pressed*/
    keyUpMask = 1 << keyUp,       /** key released*/
    autoKeyMask = 1 << autoKey,   /** key repeatedly held down*/
    updateMask = 1 << updateEvt,  /** window needs updating*/
    diskMask = 1 << diskEvt,      /** disk inserted*/
    activMask = 1 << activateEvt, /** activate/deactivate window*/
    highLevelEventMask = 0x0400,  /** high-level events (includes AppleEvents)*/
    osMask = 1 << osEvt,          /** operating system events (suspend, resume)*/
    everyEvent = 0xFFFF           /** all of the above*/
  };

  enum
  {
    charCodeMask = 0x000000FF,
    keyCodeMask = 0x0000FF00,
    adbAddrMask = 0x00FF0000,
    osEvtMessageMask = (unsigned long)0xFF000000
  };

  enum
  {
    /** OS event messages.  Event (sub)code is in the high byte of the message
       field.*/
    mouseMovedMessage = 0x00FA,
    suspendResumeMessage = 0x0001
  };

  enum
  {
    resumeFlag = 1 /** Bit 0 of message indicates resume vs suspend*/
  };

#if CALL_NOT_IN_CARBON
  /**  convertClipboardFlag is not ever set under Carbon. This is because scrap
   * conversion is  */
  /**  not tied to suspend/resume events any longer. Your application should
   * instead use the   */
  /**  scrap promise mechanism and fulfill scrap requests only when your promise
   * keeper proc   */
  /**  is called. If you need to know if the scrap has changed, you can cache the
   * last         */
  /**  ScrapRef you received and compare it with the current ScrapRef */
  enum
  {
    convertClipboardFlag =
        2 /** Bit 1 in resume message indicates clipboard change*/
  };

#endif /** CALL_NOT_IN_CARBON */

  /**
      CARBON ALERT! BATTLESTATIONS!

      The EventModifiers bits defined here are also used in the newer Carbon Event
      key modifiers parameters. There are two main differences:

      1)  The Carbon key modifiers parameter is a UInt32, not a UInt16. Never try
     to extract the key modifiers parameter from a Carbon Event into an
     EventModifiers type. You will probably get your stack trashed. 2)  The Carbon
     key modifiers is just that: key modifiers. That parameter will never contain
     the button state bit.
  */
  typedef UInt16 EventModifiers;
  enum
  {
    /** modifiers */
    activeFlagBit = 0,      /** activate? (activateEvt and mouseDown)*/
    btnStateBit = 7,        /** state of button?*/
    cmdKeyBit = 8,          /** command key down?*/
    shiftKeyBit = 9,        /** shift key down?*/
    alphaLockBit = 10,      /** alpha lock down?*/
    optionKeyBit = 11,      /** option key down?*/
    controlKeyBit = 12,     /** control key down?*/
    rightShiftKeyBit = 13,  /** right shift key down?*/
    rightOptionKeyBit = 14, /** right Option key down?*/
    rightControlKeyBit = 15 /** right Control key down?*/
  };

  enum
  {
    activeFlag = 1 << activeFlagBit,
    btnState = 1 << btnStateBit,
    cmdKey = 1 << cmdKeyBit,
    shiftKey = 1 << shiftKeyBit,
    alphaLock = 1 << alphaLockBit,
    optionKey = 1 << optionKeyBit,
    controlKey = 1 << controlKeyBit,
    rightShiftKey = 1 << rightShiftKeyBit,
    rightOptionKey = 1 << rightOptionKeyBit,
    rightControlKey = 1 << rightControlKeyBit
  };

  /** MacRoman character codes*/
  enum
  {
    kNullCharCode = 0,
    kHomeCharCode = 1,
    kEnterCharCode = 3,
    kEndCharCode = 4,
    kHelpCharCode = 5,
    kBellCharCode = 7,
    kBackspaceCharCode = 8,
    kTabCharCode = 9,
    kLineFeedCharCode = 10,
    kVerticalTabCharCode = 11,
    kPageUpCharCode = 11,
    kFormFeedCharCode = 12,
    kPageDownCharCode = 12,
    kReturnCharCode = 13,
    kFunctionKeyCharCode = 16,
    kCommandCharCode = 17,   /** glyph available only in system fonts*/
    kCheckCharCode = 18,     /** glyph available only in system fonts*/
    kDiamondCharCode = 19,   /** glyph available only in system fonts*/
    kAppleLogoCharCode = 20, /** glyph available only in system fonts*/
    kEscapeCharCode = 27,
    kClearCharCode = 27,
    kLeftArrowCharCode = 28,
    kRightArrowCharCode = 29,
    kUpArrowCharCode = 30,
    kDownArrowCharCode = 31,
    kSpaceCharCode = 32,
    kDeleteCharCode = 127,
    kBulletCharCode = 165,
    kNonBreakingSpaceCharCode = 202
  };

  /** useful Unicode code points*/
  enum
  {
    kShiftUnicode = 0x21E7,    /** Unicode UPWARDS WHITE ARROW*/
    kControlUnicode = 0x2303,  /** Unicode UP ARROWHEAD*/
    kOptionUnicode = 0x2325,   /** Unicode OPTION KEY*/
    kCommandUnicode = 0x2318,  /** Unicode PLACE OF INTEREST SIGN*/
    kPencilUnicode = 0x270E,   /** Unicode LOWER RIGHT PENCIL*/
    kCheckUnicode = 0x2713,    /** Unicode CHECK MARK*/
    kDiamondUnicode = 0x25C6,  /** Unicode BLACK DIAMOND*/
    kBulletUnicode = 0x2022,   /** Unicode BULLET*/
    kAppleLogoUnicode = 0xF8FF /** Unicode APPLE LOGO*/
  };

  struct EventRecord
  {
    EventKind what;
    UInt32 message;
    UInt32 when;
    Point where;
    EventModifiers modifiers;
  };
  typedef struct EventRecord EventRecord;
  typedef CALLBACK_API(void, FKEYProcPtr)(void);
  typedef STACK_UPP_TYPE(FKEYProcPtr) FKEYUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewFKEYUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  FKEYUPP
  NewFKEYUPP(FKEYProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppFKEYProcInfo = 0x00000000
  }; /** pascal no_return_value Func() */
#ifdef __cplusplus
  inline FKEYUPP NewFKEYUPP(FKEYProcPtr userRoutine)
  {
    return (FKEYUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppFKEYProcInfo,
                                         GetCurrentArchitecture());
  }
#else
#define NewFKEYUPP(userRoutine)                                           \
  (FKEYUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppFKEYProcInfo, \
                                 GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeFKEYUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeFKEYUPP(FKEYUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeFKEYUPP(FKEYUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeFKEYUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeFKEYUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeFKEYUPP(FKEYUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeFKEYUPP(FKEYUPP userUPP)
  {
    CALL_ZERO_PARAMETER_UPP(userUPP, uppFKEYProcInfo);
  }
#else
#define InvokeFKEYUPP(userUPP) \
  CALL_ZERO_PARAMETER_UPP((userUPP), uppFKEYProcInfo)
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewFKEYProc(userRoutine) NewFKEYUPP(userRoutine)
#define CallFKEYProc(userRoutine) InvokeFKEYUPP(userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  /**
   *  GetMouse()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  GetMouse(Point *mouseLoc);

  /**
   *  Button()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  Button(void);

  /**
   *  StillDown()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  StillDown(void);

  /**
   *  WaitMouseUp()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  WaitMouseUp(void);

  /**
   *  KeyTranslate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt32
  KeyTranslate(const void *transData, UInt16 keycode, UInt32 *state);

  /**
  \brief Obtain insertion-point cursor blink interval

  <pre>GetCaretTime returns the amount of time, in 1/60-th second ( 16.66 ms)
ticks, between blinks of the text-editing insertion point caret (normally a
vertical bar).
</pre>
* \returns <pre>a 32-bit long; the caret blink interval, as set by the user via the
Control Panel DA.
</pre>
* \note <pre>Another way to access this information is by reading the global variable
CaretTime (at 0x02F4).
If you use TextEdit, the caret blinking is automatic (if you call TEIdle
appropriately). Otherwise, you should check the elapsed ticks at each pass
through your main event loop, and toggle the display on or off as each
CaretTime -tick interval elapses.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  UInt32
  GetCaretTime(void);

/**
    QuickTime 3.0 supports GetKeys() on unix and win32
    But, on little endian machines you will have to be
    careful about bit numberings and/or use a KeyMapByteArray
    instead.
*/
#if TARGET_OS_MAC && TARGET_API_MAC_OS8

  typedef UInt32 KeyMap[4];
#else
typedef BigEndianLong KeyMap[4];
#endif /** TARGET_OS_MAC && TARGET_API_MAC_OS8 */

  typedef UInt8 KeyMapByteArray[16];
  /**
   *  GetKeys()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  GetKeys(KeyMap theKeys);

  /** Obsolete event types & masks */
  enum
  {
    networkEvt = 10,
    driverEvt = 11,
    app1Evt = 12,
    app2Evt = 13,
    app3Evt = 14,
    app4Evt = 15,
    networkMask = 0x0400,
    driverMask = 0x0800,
    app1Mask = 0x1000,
    app2Mask = 0x2000,
    app3Mask = 0x4000,
    app4Mask = 0x8000
  };

  struct EvQEl
  {
    QElemPtr qLink;
    SInt16 qType;
    EventKind evtQWhat; /** this part is identical to the EventRecord as defined
                           above */
    UInt32 evtQMessage;
    UInt32 evtQWhen;
    Point evtQWhere;
    EventModifiers evtQModifiers;
  };
  typedef struct EvQEl EvQEl;
  typedef EvQEl *EvQElPtr;
  typedef CALLBACK_API_REGISTER68K(void, GetNextEventFilterProcPtr,
                                   (EventRecord * theEvent, Boolean *result));
  typedef REGISTER_UPP_TYPE(GetNextEventFilterProcPtr) GetNextEventFilterUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewGetNextEventFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  GetNextEventFilterUPP
  NewGetNextEventFilterUPP(GetNextEventFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppGetNextEventFilterProcInfo = 0x000000BF
  }; /** SPECIAL_CASE_PROCINFO(11) */
#ifdef __cplusplus
  inline GetNextEventFilterUPP
  NewGetNextEventFilterUPP(GetNextEventFilterProcPtr userRoutine)
  {
    return (GetNextEventFilterUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppGetNextEventFilterProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewGetNextEventFilterUPP(userRoutine)                                 \
  (GetNextEventFilterUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),        \
                                               uppGetNextEventFilterProcInfo, \
                                               GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeGetNextEventFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeGetNextEventFilterUPP(GetNextEventFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeGetNextEventFilterUPP(GetNextEventFilterUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeGetNextEventFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeGetNextEventFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeGetNextEventFilterUPP(EventRecord *theEvent, Boolean *result,
                              GetNextEventFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeGetNextEventFilterUPP(EventRecord *theEvent, Boolean *result,
                                          GetNextEventFilterUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppGetNextEventFilterProcInfo, theEvent,
                           result);
  }
#else
#define InvokeGetNextEventFilterUPP(theEvent, result, userUPP)                 \
  CALL_TWO_PARAMETER_UPP((userUPP), uppGetNextEventFilterProcInfo, (theEvent), \
                         (result))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewGetNextEventFilterProc(userRoutine) \
  NewGetNextEventFilterUPP(userRoutine)
#define CallGetNextEventFilterProc(userRoutine, theEvent, result) \
  InvokeGetNextEventFilterUPP(theEvent, result, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  typedef GetNextEventFilterUPP GNEFilterUPP;

  /**
  \brief Find max delay between clicks of a double click

  <pre>GetDblTime returns an interval of time, in ticks. If two mouseDown events
occur within this interval and are close together, the combined events should
be considered a double click.
</pre>
* \returns <pre>a 32-bit long; the suggested maximum interval, in 1/60th-second
ticks, between a mouse up and the following mouseDown , that should
constitute a double click.
</pre>
* \note <pre>Another way to get this information is to access the global variable
DoubleTime directly.  The interval is adjustable by the user via the
Control Panel DA.
If you compare the EventRecord .when and the EventRecord .where of any
two mouseDown events and the second is less than DoubleTime ticks older
than the first and the points of occurrence are within 5 pixels, it should be
considered a double click. The following example illustrates how to detect a
double click.
Example
#include < Events.h>
#include <stdlib.h>
void DoDoubleClick ( EventRecord *theEvent);
long lastWhen = 0;
Point lastWhere = {0,0};
EventRecord theEvent;
while (TRUE) {
GetNextEvent ( everyEvent , &theEvent );
if ( theEvent.what == mouseDown ) {
if ( ( (theEvent.when - lastWhen) < DoubleTime )
&& ( abs(theEvent.where.h-lastWhere.h) < 5 )
&& ( abs(theEvent.where.v-lastWhere.v) < 5 ) ) {
DoDoubleClick( &theEvent ); // process the double click
}
lastWhen = theEvent.when;
lastWhere = theEvent.where;
/* ... handle other mouseDown events ... */
}
if (theEvent.what == keyDown)
{
  </ pre>
              * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                        *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
          *    \carbon_lib in CarbonLib 1.0 and
      later
          *    \mac_os_x in version 10.0 and
      later
              * /
          UInt32
              GetDblTime(void);

  /**
  \brief Set the system event mask

  <pre>SetEventMask sets the low-level mask used by the system to determine
which events it should post to the event queue.
eventMask is a 16-bit binary mask describing which events to include or
exclude. The normal value is 0xFFEF (which excludes only keyUp
events). Use eventMask =everyEvent (defined in Events.h as 0xFFFF)
to include all events. See Event Mask for named constants you can
use in this value.
</pre>
* \returns <pre>none
</pre>
* \note <pre>The preferred way to access the system event mask is by reading or storing
the global variable SysEvtMask (at 0x0144).
Indiscriminately changing this mask can cause problems. The only
legitimate use is to allow enqueuing of keyUp events, i.e.:
SetEventMask ( everyEvent ); // or SysEvtMask |= keyUpMask
Applications making this call during initialization must save the event
mask prior to calling SetEventMask and restore the event mask when
quitting.
If, under Finder, an application fails to restore the event mask before
quitting and it was set to mask out mouseUp events, all mouseUp events
would continue to be masked out. The user would then notice that the Finder
no longer recognizes double clicks. There are other anomalies associated
with MultiFinder ; to get a summary of these see the entry
About MultiFinder .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  SetEventMask(EventMask value);

#if CALL_NOT_IN_CARBON

  /**
  \brief Get address of event queue header

  <pre>GetEvQHdr returns the address of the event queue header. This gives you
direct access to the event queue, in case you want more complete control than
provided by PostEvent and GetNextEvent .
</pre>
* \returns <pre>a QHdrPtr; the address of the queue header of the system event
queue.
</pre>
* \note <pre>This simply returns the value 0x014A - the address of the global variable
EventQueue .
See Enqueue and Dequeue for information on how to access elements of a
queue.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
  QHdrPtr
  GetEvQHdr(void);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON

  /**
  \brief Enqueue an event and get its address

  <pre>PPostEvent works like PostEvent (it stores an entry into the
event queue) except that it returns, via its third parameter, the physical
address of the stored queue element. This provides access so you can modify the
contents of that element.
eventWhat specifies which type of event should be posted. It should be one of
the event types listed in GetNextEvent .
eventMsg specifies the value to be placed in the message field of the
EventRecord . It should correspond in type to the meaning of
eventWhat .
qElPtris the address of an EvQElPtr . Upon return, it contains the address
of a 22-byte evQEl structure. See Notes, below for an example of
how to access that record.
</pre>
* \returns <pre>an Error Code . The following are possible:
noErr(0)worked without error
evtNotEnb (1)eventWhat  is currently disabled. See SetEventMask
</pre>
* \note <pre>The less-flexible PostEvent function lets you specify values for only two
of the five EventRecord fields. By using PPostEvent , you can follow up by
changing the where, when, and modifiers fields.
For instance, you could use PPostEvent to enqueue a command-key
shifted mouseDown event with selected coordinates as follows:
EvQEl*myQElPtr;
PPostEvent ( mouseDown , 0, &myQElPtr );
myQElPtr-> evtQModifiers = cmdKey;
SetPt( &(myQElPtr->evtQWhere), 100,100);
See EvQEl for the layout of event queue elements.
It is also possible to build a queue element from scratch and use Enqueue
to insert it into the event queue. See GetEvQHdr .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPostEvent(__A0, __D0, __A1)
#endif
  OSErr
  PPostEvent(EventKind eventCode, UInt32 eventMsg, EvQElPtr * qEl);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  GetNextEvent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  GetNextEvent(EventMask eventMask, EventRecord * theEvent);

  /**
   *  WaitNextEvent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  WaitNextEvent(EventMask eventMask, EventRecord * theEvent, UInt32 sleep,
                RgnHandle mouseRgn) /** can be NULL */;

  /**
   *  EventAvail()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  EventAvail(EventMask eventMask, EventRecord * theEvent);

  /**
  \brief Place an EventRecord in the event queue

  <pre>PostEvent stores an EventRecord into the event queue where it can be read
via GetNextEvent , EventAvail or WaitNextEvent .
eventWhat specifies which type of event should be posted. It should be one of
the event types listed in Event Types . Typically, this will be the
app3Evt event
eventMsg specifies the value to be placed in the message field of the
EventRecord . It should correspond in type to the meaning of
eventWhat . For instance, in keyUp and keyDown events, the high
word is 0, and the low word is a scan code and character code. For
application-defined events, this can be any 32-bit value, such as a
handle to a bunch of data.
</pre>
* \returns <pre>a System Error Code . The following are possible:
noErr(0)worked without error
evtNotEnb (1)eventWhat  is disabled. See SetEventMask
</pre>
* \note <pre>PostEvent creates the EventRecord using the current time, modifiers ,
and mouse position. If you need to control these values, you may have to
modify the queue itself. See PPostEvent for a way to alter the EventRecord
after it is enqueued and see GetEvQHdr for additional information.
It is probably unwise to post window update and activate events ( updateEvt
or activateEvt ) since these are actually generated by the Event Manager
at the time of the GetNextEvent request, and are never actually stored in
the queue.
An example of usage might be to post a menu-changing event. For instance,
define an app3Evt to be one that causes a window name to be added or
removed from your application's Window menu. You could use
PostEvent (app3Evt, windowID ) whenever the user opens or closes a
document window. That way, you can handle all window-related menu
manipulation as a function of your main event loop . Note: This is not
necessarily a better way to do it, just an alternative.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PostEvent(__A0, __D0)
#endif
  OSErr
  PostEvent(EventKind eventNum, UInt32 eventMsg);

  /**
      For Carbon, use EventAvail, TickCount, GetGlobalMouse,
      GetKeys, or GetCurrentKeyModifiers instead of
      OSEventAvail, and use GetNextEvent or WaitNextEvent
      instead of GetOSEvent.
  */

#if CALL_NOT_IN_CARBON

  /**
  \brief Low-level read event without dequeuing it

  <pre>OSEventAvail is identical to GetOSEvent except that it does not remove the
event from the event queue. This lets you check for the occurrence of a
specific event (or any event) but leave it in the queue for later processing.
eventMask is a 16-bit binary mask describing which events to
include/exclude. Use eventMask =everyEvent (defined as -1) to
include all events. See Event Mask for the layout.
Some events (e.g., keyUp events) may never make it into the event
queue. See SetEventMask .
theEvent is the address of a 16-byte EventRecord . Upon return, it is filled
with an event description. See GetNextEvent .
</pre>
* \returns <pre>a Boolean value; it identifies whether a requested event was found.
It will be one of:
FALSEThis is a null event or one you did not request. Ignore it.
TRUEThis event is intended for you. Examine and respond.
</pre>
* \note <pre>In a busy system, it is possible that an event read via this call will be
discarded before it can be processed. The Event Manager usually keeps
only 20 events, scrapping the oldest unread events to make room for new
ones.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OSEventAvail(__D0, __A0)
#endif
  Boolean
  OSEventAvail(EventMask mask, EventRecord * theEvent);

  /**
  \brief Low-level read event and remove event from event queue

  <pre>GetOSEvent is identical to OSEventAvail except that removes the event
from the event queue. Unlike GetNextEvent or WaitNextEvent ,
GetOSEvent doesn't call the Desk Manager to see if the system wants to
intercept and respond to the event, nor does it perform GetNextEvent 's or
WaitNextEvent 's processing of the alarm and Command-Shift-number
combinations.
eventMask is a 16-bit binary mask describing which events to
include/exclude. Use eventMask =everyEvent (defined as -1) to
include all events. See GetNextEvent for the layout.
Some events (e.g., keyUp events) may never make it into the
event queue. See SetEventMask .
theEvent is the address of a 16-byte EventRecord . Upon return, it is filled
with an event description. See GetNextEvent or WaitNextEvent .
</pre>
* \returns <pre>a Boolean value; it identifies whether a requested event was found.
It will be one of:
FALSEThis is a null event or one you did not request. Ignore it.
TRUEThis event is intended for you. Examine and respond.
</pre>
* \note <pre>The Event Manager usually keeps only 20 events, scrapping the oldest
unread events to make room for new ones.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetOSEvent(__D0, __A0)
#endif
  Boolean
  GetOSEvent(EventMask mask, EventRecord * theEvent);

#endif /** CALL_NOT_IN_CARBON */

  /**
  \brief Discard all or selected events from event queue

  <pre>FlushEvents discards all (or selected) events chronologically, until it hits
a specified event type . It is often used at the beginning of a program to empty
the event queue of spurious keystrokes or clicks left over from the Finder.
eventMask specifies which event(s) should be flushed. It is a 16-bit binary
mask where a 1 elects to flush an event and a 0 keeps the event. The
most common usage is to use eventMask =everyEvent , defined in
Events.h as 0xFFFF. See Event Mask for details.
stopMask specifies which events (if any) should stop the flushing process.
For instance, if you want to discard all events up to the next
keystroke, use stopMask = keyDown . A value of 0 means to keep
flushing to the end of the queue.
</pre>
* \returns <pre>none
</pre>
* \note <pre>To purge all events from the queue, use:
FlushEvents ( everyEvent , 0 );
Note: FlushEvents will not remove pending highLevelEvents.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  FlushEvents(EventMask whichMask, EventMask stopMask);

#if CALL_NOT_IN_CARBON
  /**
   *  SystemClick()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  SystemClick(const EventRecord *theEvent, WindowRef theWindow);

  /**
  \brief Give DAs a chance to perform periodic actions

  <pre>Call SystemTask at least once each time through your event loop. It lets the
Desk Manager process such periodic DA events as updating the display of a
clock.
</pre>
* \returns <pre>none
</pre>
* \note <pre>SystemTask should be called at least once every 17ms (1/60-th of a
second).  Normal usage is to put it inside a part of the event loop that
always gets executed:
main()
{
InitGraf ();
.
.... initialize other stuff ...
.
while (TRUE) /* Loop forever; terminate via */
  EventLoop(); /* ExitToShell elsewhere */
}
EventLoop()
{
  MaintainCursor();
  MaintainMenus();
  SystemTask();
  if (GetNextEvent(everyEvent, &theEvent))
  {
    .....process events...
        .
  }
}
DAs wanting a timeslice every so often should set bit 5 of the drvrFlags
    word and a tick count in drvrDelay in the driver header.You should not depend on any particular accuracy,
    since an application may fail to call
        SystemTask often
        enough(e.g., when saving a file)
            .To receive periodic
    timeslices with more accuracy,
    install a vertical retrace task via VInstall
        or a timer interrupt task via InsTime.</ pre>
                       * \copyright THINK Reference © 1991 -
                   1992 Symantec Corporation
                       *    \non_carbon_cfm in InterfaceLib 7.1 and
               later
                       *    \carbon_lib not available
                   *    \mac_os_x not available
                   * /
                   void
                       SystemTask(void);

/**
\brief Used internally by Event Manager

<pre>SystemEvent is called by the Event Manager as a way to watch for certain
events and pass some of them directly to DAs, without bothering your
application. This function should not be called by applications.
theEvent is the address of a 16-byte EventRecord . It contains information
received from a previous call to GetNextEvent .
</pre>
* \returns <pre>A Boolean; it identifies whether the event should be handled by an
application or a DA. It is one of:
FALSE (0)This event should be passed to the application. It may be a
system event the application should handle by calling
SystemClick .
TRUE (1)This event should be handled by the system (i.e., a DA). It will
not be forwarded to the application.
</pre>
* \note <pre>SystemEvent is called internally by the GetNextEvent function. The
idea is to avoid clogging up your event loop; let the system handle such
events as keystrokes, mouse-ups, updates, and activate events occuring in a
DA window.
If you want to get a look at all events, you can store a 0 in the 1-byte
global variable SEvtEnb (at 0x015c). This will cause GetNextEvent to
forward all unmasked events to you.
When a DA creates a window (including a modeless dialog) it must set the
windowKind to its refnum, which is a negative number. When the
application calls GetNextEvent , as explained above, the Event Manager
calls SystemEvent . If it returns TRUE then your DA gets the event. Since
your window is a modeless dialog you would call IsDialogEvent , which
returns FALSE What is going on is that IsDialogEvent (like
SystemEvent) checks the windowKind looking for a value of 2 (for
dialogs). Since your dialog's windowKind is a negative number, the DA's
refnum, IsDialogEvent does nothing. The solution is to change the
windowKind of your window to 2 before calling IsDialogEvent . This
allows the Dialog Manager to recognize and handle the event properly. Be
sure to restore the windowKind to its former value before returning to
SystemEvent . That way, when the application calls the Dialog Manager
with the same event (it should pass all events to the Dialog Manager if it has
any modeless dialogs), the Dialog Manager will ignore it.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
Boolean
SystemEvent(const EventRecord *theEvent);

#endif /** CALL_NOT_IN_CARBON */

#if OLDROUTINENAMES
#define KeyTrans(transData, keycode, state) \
  KeyTranslate(transData, keycode, state)
#endif /** OLDROUTINENAMES */

/**
    GetGlobalMouse, GetCurrentKeyModifiers, and CheckEventQueueForUserCancel
    are only available as part of the Carbon API.
*/

/**
 *  GetGlobalMouse()
 *
 *  Summary:
 *    Returns the position of the mouse in global coordinates.
 *
 *  Parameters:
 *
 *    globalMouse:
 *      On exit, contains the mouse position in global coordinates.
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
GetGlobalMouse(Point *globalMouse);

/**
 *  GetCurrentKeyModifiers()
 *
 *  Summary:
 *    Returns the current state of the keyboard modifier keys.
 *
 *  Discussion:
 *    The format of the return value is the same as the modifiers field
 *    of the EventRecord.
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
UInt32
GetCurrentKeyModifiers(void);

/**
 *  CheckEventQueueForUserCancel()
 *
 *  Summary:
 *    Determines if there is a cancel event in the event queue.
 *
 *  Discussion:
 *    This API supports two cancel events: Escape and Cmd-Period. Mouse
 *    or keyboard events in front of the cancel event in the event
 *    queue will be removed.
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
CheckEventQueueForUserCancel(void);

/**
    The core data structure for the Carbon event system. It is declared here
   instead of in CarbonEvents.h to avoid recursive include problems.
*/
typedef struct OpaqueEventRef *EventRef;
/**
 *  KeyScript()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
KeyScript(short code);

/**
 *  IsCmdChar()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
IsCmdChar(const EventRecord *event, short test);

/**
    LowMem accessor functions previously in LowMem.h
*/
/**
 *  LMGetKeyThresh()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt16
LMGetKeyThresh(void);

/**
 *  LMSetKeyThresh()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LMSetKeyThresh(SInt16 value);

/**
 *  LMGetKeyRepThresh()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt16
LMGetKeyRepThresh(void);

/**
 *  LMSetKeyRepThresh()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LMSetKeyRepThresh(SInt16 value);

/**
 *  LMGetKbdLast()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
UInt8
LMGetKbdLast(void);

/**
 *  LMSetKbdLast()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LMSetKbdLast(UInt8 value);

/**
 *  LMGetKbdType()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
UInt8
LMGetKbdType(void);

/**
 *  LMSetKbdType()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LMSetKbdType(UInt8 value);

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

#endif /** __EVENTS__ */
* /*/*/ * /*/*/ * /*/*/ */*/