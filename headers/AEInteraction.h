/**
     \file       AEInteraction.h

    \brief   AppleEvent functions that deal with Events and interacting with
   user

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 2000-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup AppleEvent

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __AEINTERACTION__
#define __AEINTERACTION__

#ifndef __AEDATAMODEL__
#include <AEDataModel.h>
#endif

#ifndef __NOTIFICATION__
#include <Notification.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
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
    AppleEvent callbacks.
  **************************************************************************/
  typedef CALLBACK_API(Boolean, AEIdleProcPtr)(EventRecord *theEvent,
                                               long *sleepTime,
                                               RgnHandle *mouseRgn);
  typedef CALLBACK_API(Boolean, AEFilterProcPtr)(EventRecord *theEvent,
                                                 long returnID,
                                                 long transactionID,
                                                 const AEAddressDesc *sender);
  typedef STACK_UPP_TYPE(AEIdleProcPtr) AEIdleUPP;
  typedef STACK_UPP_TYPE(AEFilterProcPtr) AEFilterUPP;

  /**************************************************************************
    The next couple of calls are basic routines used to create, send,
    and process AppleEvents.
  **************************************************************************/
  /**
   *  AESend()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AESend(const AppleEvent *theAppleEvent, AppleEvent *reply, AESendMode sendMode,
         AESendPriority sendPriority, long timeOutInTicks,
         AEIdleUPP idleProc, /* can be NULL */
         AEFilterUPP filterProc) /* can be NULL */ THREEWORDINLINE(0x303C, 0x0D17,
                                                                   0xA816);

  /**
   *  AEProcessAppleEvent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AEProcessAppleEvent(const EventRecord *theEventRecord)
      THREEWORDINLINE(0x303C, 0x021B, 0xA816);

  /**
   Note: during event processing, an event handler may realize that it is likely
   to exceed the client's timeout limit. Passing the reply to this
   routine causes a wait event to be generated that asks the client
   for more time.
  */
  /**
   *  AEResetTimer()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AEResetTimer(const AppleEvent *reply) THREEWORDINLINE(0x303C, 0x0219, 0xA816);

  /**************************************************************************
    The following three calls are used to allow applications to behave
    courteously when a user interaction such as a dialog box is needed.
  **************************************************************************/

  typedef SInt8 AEInteractAllowed;
  enum
  {
    kAEInteractWithSelf = 0,
    kAEInteractWithLocal = 1,
    kAEInteractWithAll = 2
  };

  /**
  \brief AEGetInteractionAllowed Get user interaction preferences

  <pre>You can use the AEGetInteractionAllowed function to get the current user
interaction preferences for responding to an Apple event.
The AEGetInteractionAllowed function returns a value in the level
paramter that indicates the user interaction preferences for responding to an
Apple event.
The value returned is the interaction level set by a previous call to
AESetInteractionAllowed . The default value of kAEInteractWithLocal is
returned if your application has not used AESetInteractionAllowed to
explicitly set the interaction level.
The level parameter returns one of the following flags: kAEInteractWithSelf ,
kAEInteractWithLocal , or kAEInteractWithAll .
The kAEInteractWithSelf flag indicates that the server application may
interact with the user in response to an Apple event only when the client
application and server application are the same-that is, only when the
application is sending the Apple event to itself.
The kAEInteractWithLocal flag indicates that the server application may
interact with the user in response to an Apple event only if the client
application is on the same computer as the server application. This is the
default if your application has not used the AESetInteractionAllowed
function to explicitly set the interaction level.
The kAEInteractWithAll flag indicates that the server application may
interact with the user in response to an Apple event sent from any client
Result codes
noErr (0)No error
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  AEGetInteractionAllowed(AEInteractAllowed *level)
      THREEWORDINLINE(0x303C, 0x021D, 0xA816);

  /**
   *  AESetInteractionAllowed()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AESetInteractionAllowed(AEInteractAllowed level)
      THREEWORDINLINE(0x303C, 0x011E, 0xA816);

  /**
   *  AEInteractWithUser()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AEInteractWithUser(long timeOutInTicks, NMRecPtr nmReqPtr, AEIdleUPP idleProc)
      THREEWORDINLINE(0x303C, 0x061C, 0xA816);

  /**************************************************************************
   The following four calls are available for applications which need more
   sophisticated control over when and how events are processed. Applications
   which implement multi-session servers or which implement their own
   internal event queueing will probably be the major clients of these
   routines. They can be called from within a handler to prevent the AEM from
   disposing of the AppleEvent when the handler returns. They can be used to
   asynchronously process the event (as MacApp does).
  **************************************************************************/

  /**
  \brief AESuspendTheCurrentEvent Suspend Apple Event processing

  <pre>You can use the AESuspendTheCurrentEvent function to suspend the
processing of an Apple event that is currently being handled.
The AESuspendTheCurrentEvent function suspends the processing of the
Apple event that is currently being handled.
The parameter theAppleEvent is the Apple event whose handling is to be
suspended. Although the Apple Event Manager doesn't need the parameter
theAppleEvent to identify the Apple event currently being handled, providing
this parameter is a safeguard that ensures that you are suspending the correct
Apple event.
After a server application makes a successful call to the function
AESuspendTheCurrentEvent , it is no longer required to return a result
or a reply for the Apple event that was being handled. It can, however, return a
result if it later calls the AEResumeTheCurrentEvent function to resume
event processing.
The Apple Event Manager does not automatically dispose of Apple events
that have been suspended or of their default replies. (The Apple Event
Manager does, however, automatically dispose of a previously suspended Apple
event and its default reply if the server later resumes processing of the Apple
event by calling the AEResumeTheCurrentEvent function.) If your server
application does not resume processing of a suspended
Apple event, it is responsible for using the AEDisposeDesc function to
dispose of both the Apple event and its default reply when you are finished with
them.
Result codes
noErr(0)No error
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  AESuspendTheCurrentEvent(const AppleEvent *theAppleEvent)
      THREEWORDINLINE(0x303C, 0x022B, 0xA816);

  /**
   Note: The following routine tells the AppleEvent manager that processing
   is either about to resume or has been completed on a previously suspended
   event. The procPtr passed in as the dispatcher parameter will be called to
   attempt to redispatch the event. Several constants for the dispatcher
   parameter allow special behavior. They are:
      - kAEUseStandardDispatch means redispatch as if the event was just
        received, using the standard AppleEvent dispatch mechanism.
      - kAENoDispatch means ignore the parameter.
        Use this in the case where the event has been handled and no
        redispatch is needed.
      - non nil means call the routine which the dispatcher points to.
  */
  /* Constants for Refcon in AEResumeTheCurrentEvent with kAEUseStandardDispatch
   */
  enum
  {
    kAEDoNotIgnoreHandler = 0x00000000,
    kAEIgnoreAppPhacHandler =
        0x00000001, /* available only in vers 1.0.1 and greater */
    kAEIgnoreAppEventHandler =
        0x00000002, /* available only in vers 1.0.1 and greater */
    kAEIgnoreSysPhacHandler =
        0x00000004, /* available only in vers 1.0.1 and greater */
    kAEIgnoreSysEventHandler =
        0x00000008, /* available only in vers 1.0.1 and greater */
    kAEIngoreBuiltInEventHandler =
        0x00000010, /* available only in vers 1.0.1 and greater */
    kAEDontDisposeOnResume =
        (long)0x80000000 /* available only in vers 1.0.1 and greater */
  };

  /* Constants for AEResumeTheCurrentEvent */
  enum
  {
    kAENoDispatch = 0, /* dispatch parameter to AEResumeTheCurrentEvent takes a
                          pointer to a dispatch */
    kAEUseStandardDispatch =
        (long)0xFFFFFFFF /* table, or one of these two constants */
  };

  /**
   *  AEResumeTheCurrentEvent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AEResumeTheCurrentEvent(const AppleEvent *theAppleEvent,
                          const AppleEvent *reply,
                          AEEventHandlerUPP dispatcher, /* can be NULL */
                          long handlerRefcon)
      THREEWORDINLINE(0x303C, 0x0818, 0xA816);

  /**
  \brief AEGetTheCurrentEvent Return the Apple Event currently being handled

  <pre>You can use the AEGetTheCurrentEvent function to get the Apple event that
is currently being handled.
The AEGetTheCurrentEvent function returns the Apple event that is
currently being handled. In many applications, the handling of an
Apple event involves one or more long chains of calls to routines within the
application. The AEGetTheCurrentEvent function makes it unnecessary for
these calls to include the current Apple event as a parameter; the routines can
simply call AEGetTheCurrentEvent to get the current Apple event when it
is needed.
You can also use the AEGetTheCurrentEvent function to make sure that no
Apple event is currently being handled. For example, if your application
always uses an application-defined routine to delete a file, that routine can
determine whether an Apple event is currently being handled by calling
AEGetTheCurrentEvent , and delete the file only if
AEGetTheCurrentEvent returns a null descriptor record, indicating that
no Apple event is currently being handled.
This function returns the Apple event that is currently being handled in the
parameter theAppleEvent .
Result codes
noErr(0)No error
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  AEGetTheCurrentEvent(AppleEvent *theAppleEvent)
      THREEWORDINLINE(0x303C, 0x021A, 0xA816);

  /**
  \brief AESetTheCurrentEvent Specify Apple Event to be handled

  <pre>You can use the AESetTheCurrentEvent function to specify the Apple event
to be handled.
The AESetTheCurrentEvent function specifies the Apple event to be
handled. There is generally no reason for your application to use this function.
Instead of calling this function, your application should let the
Apple Event Manager go through the dispatch tables to set the current
Apple event.
The parameter theAppleEvent is the Apple event that is to be handled.
The AESetTheCurrentEvent function is used only to avoid going through
the dispatch tables, and is used only in the following way:
1.An application suspends handling of an Apple event by calling the
AESuspendTheCurrentEvent function.
2.The application calls the AESetTheCurrentEvent function to
inform the Apple Event Manager that it is handling the Apple event that
was previously suspended. It thereby makes the identity of the Apple event
currently being handled available to routines that call the
AEGetTheCurrentEvent function.
3.The application handles the Apple event. When it is finished, it calls
the AEResumeTheCurrentEvent function with the value kAENoDispatch to
tell the Apple Event Manager that the processing of the event is complete
and that the Apple event does not need to be dispatched.
Result codes
noErr(0)No error
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  AESetTheCurrentEvent(const AppleEvent *theAppleEvent)
      THREEWORDINLINE(0x303C, 0x022C, 0xA816);

  /**************************************************************************
    AppleEvent callbacks.
  **************************************************************************/
  /**
   *  NewAEIdleUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AEIdleUPP
  NewAEIdleUPP(AEIdleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppAEIdleProcInfo = 0x00000FD0
  }; /* pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline AEIdleUPP NewAEIdleUPP(AEIdleProcPtr userRoutine)
  {
    return (AEIdleUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppAEIdleProcInfo, GetCurrentArchitecture());
  }
#else
#define NewAEIdleUPP(userRoutine)                                             \
  (AEIdleUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppAEIdleProcInfo, \
                                   GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewAEFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AEFilterUPP
  NewAEFilterUPP(AEFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppAEFilterProcInfo = 0x00003FD0
  }; /* pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline AEFilterUPP NewAEFilterUPP(AEFilterProcPtr userRoutine)
  {
    return (AEFilterUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppAEFilterProcInfo, GetCurrentArchitecture());
  }
#else
#define NewAEFilterUPP(userRoutine)   \
  (AEFilterUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppAEFilterProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeAEIdleUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeAEIdleUPP(AEIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeAEIdleUPP(AEIdleUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeAEIdleUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeAEFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeAEFilterUPP(AEFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeAEFilterUPP(AEFilterUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeAEFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeAEIdleUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeAEIdleUPP(EventRecord *theEvent, long *sleepTime, RgnHandle *mouseRgn,
                  AEIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeAEIdleUPP(EventRecord *theEvent, long *sleepTime,
                                 RgnHandle *mouseRgn, AEIdleUPP userUPP)
  {
    return (Boolean)CALL_THREE_PARAMETER_UPP(userUPP, uppAEIdleProcInfo, theEvent,
                                             sleepTime, mouseRgn);
  }
#else
#define InvokeAEIdleUPP(theEvent, sleepTime, mouseRgn, userUPP)                \
  (Boolean) CALL_THREE_PARAMETER_UPP((userUPP), uppAEIdleProcInfo, (theEvent), \
                                     (sleepTime), (mouseRgn))
#endif
#endif

  /**
   *  InvokeAEFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeAEFilterUPP(EventRecord *theEvent, long returnID, long transactionID,
                    const AEAddressDesc *sender, AEFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeAEFilterUPP(EventRecord *theEvent, long returnID,
                                   long transactionID,
                                   const AEAddressDesc *sender,
                                   AEFilterUPP userUPP)
  {
    return (Boolean)CALL_FOUR_PARAMETER_UPP(
        userUPP, uppAEFilterProcInfo, theEvent, returnID, transactionID, sender);
  }
#else
#define InvokeAEFilterUPP(theEvent, returnID, transactionID, sender, userUPP) \
  (Boolean)                                                                   \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppAEFilterProcInfo, (theEvent),     \
                              (returnID), (transactionID), (sender))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewAEIdleProc(userRoutine) NewAEIdleUPP(userRoutine)
#define NewAEFilterProc(userRoutine) NewAEFilterUPP(userRoutine)
#define CallAEIdleProc(userRoutine, theEvent, sleepTime, mouseRgn) \
  InvokeAEIdleUPP(theEvent, sleepTime, mouseRgn, userRoutine)
#define CallAEFilterProc(userRoutine, theEvent, returnID, transactionID, \
                         sender)                                         \
  InvokeAEFilterUPP(theEvent, returnID, transactionID, sender, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

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

#endif /* __AEINTERACTION__ */
* /*/*/ * /