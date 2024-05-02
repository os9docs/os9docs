/**
     \file       Threads.h

    \brief   Thread Manager Interfaces.

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1991-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __THREADS__
#define __THREADS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
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

  /* Thread states*/
  typedef UInt16 ThreadState;
  enum
  {
    kReadyThreadState = 0,
    kStoppedThreadState = 1,
    kRunningThreadState = 2
  };

  /* Error codes have been moved to Errors.(pah)*/

  /* Thread environment characteristics*/
  typedef void *ThreadTaskRef;
  /* Thread characteristics*/
  typedef UInt32 ThreadStyle;
  enum
  {
    kCooperativeThread = 1L << 0,
    kPreemptiveThread = 1L << 1
  };

  /* Thread identifiers*/
  typedef UInt32 ThreadID;
  enum
  {
    kNoThreadID = 0,
    kCurrentThreadID = 1,
    kApplicationThreadID = 2
  };

  /* Options when creating a thread*/
  typedef UInt32 ThreadOptions;
  enum
  {
    kNewSuspend = (1 << 0),
    kUsePremadeThread = (1 << 1),
    kCreateIfNeeded = (1 << 2),
    kFPUNotNeeded = (1 << 3),
    kExactMatchThread = (1 << 4)
  };

  /* Information supplied to the custom scheduler*/
  struct SchedulerInfoRec
  {
    UInt32 InfoRecSize;
    ThreadID CurrentThreadID;
    ThreadID SuggestedThreadID;
    ThreadID InterruptedCoopThreadID;
  };
  typedef struct SchedulerInfoRec SchedulerInfoRec;
  typedef SchedulerInfoRec *SchedulerInfoRecPtr;

  /**
      The following ProcPtrs cannot be interchanged with UniversalProcPtrs because
      of differences between 680x0 and PowerPC runtime architectures with regard
     to the implementation of the Thread Manager.
   */
  typedef void *voidPtr;
  /* Prototype for thread's entry (main) routine*/
  typedef CALLBACK_API(voidPtr, ThreadEntryProcPtr)(void *threadParam);
  /* Prototype for custom thread scheduler routine*/
  typedef CALLBACK_API(ThreadID,
                       ThreadSchedulerProcPtr)(SchedulerInfoRecPtr schedulerInfo);
  /* Prototype for custom thread switcher routine*/
  typedef CALLBACK_API(void, ThreadSwitchProcPtr)(ThreadID threadBeingSwitched,
                                                  void *switchProcParam);
  /* Prototype for thread termination notification routine*/
  typedef CALLBACK_API(void,
                       ThreadTerminationProcPtr)(ThreadID threadTerminated,
                                                 void *terminationProcParam);
  /* Prototype for debugger NewThread notification*/
  typedef CALLBACK_API(void, DebuggerNewThreadProcPtr)(ThreadID threadCreated);
  /* Prototype for debugger DisposeThread notification*/
  typedef CALLBACK_API(void,
                       DebuggerDisposeThreadProcPtr)(ThreadID threadDeleted);
  /* Prototype for debugger schedule notification*/
  typedef CALLBACK_API(ThreadID, DebuggerThreadSchedulerProcPtr)(
      SchedulerInfoRecPtr schedulerInfo);
  typedef TVECTOR_UPP_TYPE(ThreadEntryProcPtr) ThreadEntryUPP;
  typedef TVECTOR_UPP_TYPE(ThreadSchedulerProcPtr) ThreadSchedulerUPP;
  typedef TVECTOR_UPP_TYPE(ThreadSwitchProcPtr) ThreadSwitchUPP;
  typedef TVECTOR_UPP_TYPE(ThreadTerminationProcPtr) ThreadTerminationUPP;
  typedef TVECTOR_UPP_TYPE(DebuggerNewThreadProcPtr) DebuggerNewThreadUPP;
  typedef TVECTOR_UPP_TYPE(DebuggerDisposeThreadProcPtr) DebuggerDisposeThreadUPP;
  typedef TVECTOR_UPP_TYPE(DebuggerThreadSchedulerProcPtr)
      DebuggerThreadSchedulerUPP;
  /**
   *  NewThreadEntryUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ThreadEntryUPP
  NewThreadEntryUPP(ThreadEntryProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppThreadEntryProcInfo = 0x000000F0
  }; /* pascal 4_bytes Func(4_bytes) */
#ifdef __cplusplus
  inline ThreadEntryUPP NewThreadEntryUPP(ThreadEntryProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewThreadEntryUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
   *  NewThreadSchedulerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ThreadSchedulerUPP
  NewThreadSchedulerUPP(ThreadSchedulerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppThreadSchedulerProcInfo = 0x000000F0
  }; /* pascal 4_bytes Func(4_bytes) */
#ifdef __cplusplus
  inline ThreadSchedulerUPP
  NewThreadSchedulerUPP(ThreadSchedulerProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewThreadSchedulerUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
   *  NewThreadSwitchUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ThreadSwitchUPP
  NewThreadSwitchUPP(ThreadSwitchProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppThreadSwitchProcInfo = 0x000003C0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ThreadSwitchUPP NewThreadSwitchUPP(ThreadSwitchProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewThreadSwitchUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
   *  NewThreadTerminationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ThreadTerminationUPP
  NewThreadTerminationUPP(ThreadTerminationProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppThreadTerminationProcInfo = 0x000003C0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ThreadTerminationUPP
  NewThreadTerminationUPP(ThreadTerminationProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewThreadTerminationUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
   *  NewDebuggerNewThreadUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DebuggerNewThreadUPP
  NewDebuggerNewThreadUPP(DebuggerNewThreadProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDebuggerNewThreadProcInfo = 0x000000C0
  }; /* pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
  inline DebuggerNewThreadUPP
  NewDebuggerNewThreadUPP(DebuggerNewThreadProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewDebuggerNewThreadUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
   *  NewDebuggerDisposeThreadUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DebuggerDisposeThreadUPP
  NewDebuggerDisposeThreadUPP(DebuggerDisposeThreadProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDebuggerDisposeThreadProcInfo = 0x000000C0
  }; /* pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
  inline DebuggerDisposeThreadUPP
  NewDebuggerDisposeThreadUPP(DebuggerDisposeThreadProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewDebuggerDisposeThreadUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
   *  NewDebuggerThreadSchedulerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DebuggerThreadSchedulerUPP
  NewDebuggerThreadSchedulerUPP(DebuggerThreadSchedulerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDebuggerThreadSchedulerProcInfo = 0x000000F0
  }; /* pascal 4_bytes Func(4_bytes) */
#ifdef __cplusplus
  inline DebuggerThreadSchedulerUPP
  NewDebuggerThreadSchedulerUPP(DebuggerThreadSchedulerProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewDebuggerThreadSchedulerUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
   *  DisposeThreadEntryUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeThreadEntryUPP(ThreadEntryUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeThreadEntryUPP(ThreadEntryUPP) {}
#else
#define DisposeThreadEntryUPP(userUPP)
#endif
#endif

  /**
   *  DisposeThreadSchedulerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeThreadSchedulerUPP(ThreadSchedulerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeThreadSchedulerUPP(ThreadSchedulerUPP) {}
#else
#define DisposeThreadSchedulerUPP(userUPP)
#endif
#endif

  /**
   *  DisposeThreadSwitchUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeThreadSwitchUPP(ThreadSwitchUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeThreadSwitchUPP(ThreadSwitchUPP) {}
#else
#define DisposeThreadSwitchUPP(userUPP)
#endif
#endif

  /**
   *  DisposeThreadTerminationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeThreadTerminationUPP(ThreadTerminationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeThreadTerminationUPP(ThreadTerminationUPP) {}
#else
#define DisposeThreadTerminationUPP(userUPP)
#endif
#endif

  /**
   *  DisposeDebuggerNewThreadUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDebuggerNewThreadUPP(DebuggerNewThreadUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDebuggerNewThreadUPP(DebuggerNewThreadUPP) {}
#else
#define DisposeDebuggerNewThreadUPP(userUPP)
#endif
#endif

  /**
   *  DisposeDebuggerDisposeThreadUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDebuggerDisposeThreadUPP(DebuggerDisposeThreadUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDebuggerDisposeThreadUPP(DebuggerDisposeThreadUPP) {}
#else
#define DisposeDebuggerDisposeThreadUPP(userUPP)
#endif
#endif

  /**
   *  DisposeDebuggerThreadSchedulerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDebuggerThreadSchedulerUPP(DebuggerThreadSchedulerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDebuggerThreadSchedulerUPP(DebuggerThreadSchedulerUPP) {}
#else
#define DisposeDebuggerThreadSchedulerUPP(userUPP)
#endif
#endif

  /**
   *  InvokeThreadEntryUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  voidPtr
  InvokeThreadEntryUPP(void *threadParam, ThreadEntryUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline voidPtr InvokeThreadEntryUPP(void *threadParam, ThreadEntryUPP userUPP)
  {
    return (*userUPP)(threadParam);
  }
#else
#define InvokeThreadEntryUPP(threadParam, userUPP) (*userUPP)(threadParam)
#endif
#endif

  /**
   *  InvokeThreadSchedulerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ThreadID
  InvokeThreadSchedulerUPP(SchedulerInfoRecPtr schedulerInfo,
                           ThreadSchedulerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline ThreadID InvokeThreadSchedulerUPP(SchedulerInfoRecPtr schedulerInfo,
                                           ThreadSchedulerUPP userUPP)
  {
    return (*userUPP)(schedulerInfo);
  }
#else
#define InvokeThreadSchedulerUPP(schedulerInfo, userUPP) \
  (*userUPP)(schedulerInfo)
#endif
#endif

  /**
   *  InvokeThreadSwitchUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeThreadSwitchUPP(ThreadID threadBeingSwitched, void *switchProcParam,
                        ThreadSwitchUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeThreadSwitchUPP(ThreadID threadBeingSwitched,
                                    void *switchProcParam,
                                    ThreadSwitchUPP userUPP)
  {
    (*userUPP)(threadBeingSwitched, switchProcParam);
  }
#else
#define InvokeThreadSwitchUPP(threadBeingSwitched, switchProcParam, userUPP) \
  (*userUPP)(threadBeingSwitched, switchProcParam)
#endif
#endif

  /**
   *  InvokeThreadTerminationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeThreadTerminationUPP(ThreadID threadTerminated,
                             void *terminationProcParam,
                             ThreadTerminationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeThreadTerminationUPP(ThreadID threadTerminated,
                                         void *terminationProcParam,
                                         ThreadTerminationUPP userUPP)
  {
    (*userUPP)(threadTerminated, terminationProcParam);
  }
#else
#define InvokeThreadTerminationUPP(threadTerminated, terminationProcParam, \
                                   userUPP)                                \
  (*userUPP)(threadTerminated, terminationProcParam)
#endif
#endif

  /**
   *  InvokeDebuggerNewThreadUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDebuggerNewThreadUPP(ThreadID threadCreated,
                             DebuggerNewThreadUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeDebuggerNewThreadUPP(ThreadID threadCreated,
                                         DebuggerNewThreadUPP userUPP)
  {
    (*userUPP)(threadCreated);
  }
#else
#define InvokeDebuggerNewThreadUPP(threadCreated, userUPP) \
  (*userUPP)(threadCreated)
#endif
#endif

  /**
   *  InvokeDebuggerDisposeThreadUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDebuggerDisposeThreadUPP(ThreadID threadDeleted,
                                 DebuggerDisposeThreadUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeDebuggerDisposeThreadUPP(ThreadID threadDeleted,
                                             DebuggerDisposeThreadUPP userUPP)
  {
    (*userUPP)(threadDeleted);
  }
#else
#define InvokeDebuggerDisposeThreadUPP(threadDeleted, userUPP) \
  (*userUPP)(threadDeleted)
#endif
#endif

  /**
   *  InvokeDebuggerThreadSchedulerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ThreadID
  InvokeDebuggerThreadSchedulerUPP(SchedulerInfoRecPtr schedulerInfo,
                                   DebuggerThreadSchedulerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline ThreadID
  InvokeDebuggerThreadSchedulerUPP(SchedulerInfoRecPtr schedulerInfo,
                                   DebuggerThreadSchedulerUPP userUPP)
  {
    return (*userUPP)(schedulerInfo);
  }
#else
#define InvokeDebuggerThreadSchedulerUPP(schedulerInfo, userUPP) \
  (*userUPP)(schedulerInfo)
#endif
#endif

  /**
     Thread Manager function pointers (TPP):
     on classic 68k use raw function pointers (same as UPP's)
     on classic PowerPC, use raw function pointers
     on classic PowerPC with OPAQUE_UPP_TYPES=1, use UPP's
     on CFM-68K, use UPP's
     on Carbon, use UPP's
  */

#if TARGET_OS_MAC && TARGET_CPU_PPC && !OPAQUE_UPP_TYPES
  /* use raw function pointers*/
  typedef ThreadEntryProcPtr ThreadEntryTPP;
  typedef ThreadSchedulerProcPtr ThreadSchedulerTPP;
  typedef ThreadSwitchProcPtr ThreadSwitchTPP;
  typedef ThreadTerminationProcPtr ThreadTerminationTPP;
  typedef DebuggerNewThreadProcPtr DebuggerNewThreadTPP;
  typedef DebuggerDisposeThreadProcPtr DebuggerDisposeThreadTPP;
  typedef DebuggerThreadSchedulerProcPtr DebuggerThreadSchedulerTPP;
#else
/* use UPP's*/
typedef ThreadEntryUPP ThreadEntryTPP;
typedef ThreadSchedulerUPP ThreadSchedulerTPP;
typedef ThreadSwitchUPP ThreadSwitchTPP;
typedef ThreadTerminationUPP ThreadTerminationTPP;
typedef DebuggerNewThreadUPP DebuggerNewThreadTPP;
typedef DebuggerDisposeThreadUPP DebuggerDisposeThreadTPP;
typedef DebuggerThreadSchedulerUPP DebuggerThreadSchedulerTPP;
#endif /* TARGET_OS_MAC && TARGET_CPU_PPC && !OPAQUE_UPP_TYPES */

  /**
   *  NewThread()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  NewThread(ThreadStyle threadStyle, ThreadEntryTPP threadEntry,
            void *threadParam, Size stackSize, ThreadOptions options,
            void **threadResult, /* can be NULL */
            ThreadID *threadMade) THREEWORDINLINE(0x303C, 0x0E03, 0xABF2);

  /**
   *  SetThreadScheduler()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetThreadScheduler(ThreadSchedulerTPP threadScheduler)
      THREEWORDINLINE(0x303C, 0x0209, 0xABF2);

  /**
   *  SetThreadSwitcher()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetThreadSwitcher(ThreadID thread, ThreadSwitchTPP threadSwitcher,
                    void *switchProcParam, Boolean inOrOut)
      THREEWORDINLINE(0x303C, 0x070A, 0xABF2);

  /**
   *  SetThreadTerminator()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetThreadTerminator(ThreadID thread, ThreadTerminationTPP threadTerminator,
                      void *terminationProcParam)
      THREEWORDINLINE(0x303C, 0x0611, 0xABF2);

  /**
   *  SetDebuggerNotificationProcs()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetDebuggerNotificationProcs(DebuggerNewThreadTPP notifyNewThread,
                               DebuggerDisposeThreadTPP notifyDisposeThread,
                               DebuggerThreadSchedulerTPP notifyThreadScheduler)
      THREEWORDINLINE(0x303C, 0x060D, 0xABF2);

  /**
   *  CreateThreadPool()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  CreateThreadPool(ThreadStyle threadStyle, SInt16 numToCreate, Size stackSize)
      THREEWORDINLINE(0x303C, 0x0501, 0xABF2);

  /**
   *  GetFreeThreadCount()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetFreeThreadCount(ThreadStyle threadStyle, SInt16 *freeCount)
      THREEWORDINLINE(0x303C, 0x0402, 0xABF2);

  /**
   *  GetSpecificFreeThreadCount()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetSpecificFreeThreadCount(ThreadStyle threadStyle, Size stackSize,
                             SInt16 *freeCount)
      THREEWORDINLINE(0x303C, 0x0615, 0xABF2);

  /**
   *  GetDefaultThreadStackSize()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetDefaultThreadStackSize(ThreadStyle threadStyle, Size *stackSize)
      THREEWORDINLINE(0x303C, 0x0413, 0xABF2);

  /**
   *  ThreadCurrentStackSpace()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ThreadCurrentStackSpace(ThreadID thread, UInt32 *freeStack)
      THREEWORDINLINE(0x303C, 0x0414, 0xABF2);

  /**
   *  DisposeThread()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DisposeThread(ThreadID threadToDump, void *threadResult, Boolean recycleThread)
      THREEWORDINLINE(0x303C, 0x0504, 0xABF2);

  /**
   *  YieldToThread()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  YieldToThread(ThreadID suggestedThread) THREEWORDINLINE(0x303C, 0x0205, 0xABF2);

  /**
   *  YieldToAnyThread()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  YieldToAnyThread(void) FOURWORDINLINE(0x42A7, 0x303C, 0x0205, 0xABF2);

/**
 *  [Mac]GetCurrentThread()
 *

 *    \non_carbon_cfm   in ThreadsLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacGetCurrentThread GetCurrentThread
#endif
  OSErr
  MacGetCurrentThread(ThreadID *currentThreadID)
      THREEWORDINLINE(0x303C, 0x0206, 0xABF2);

  /**
   *  GetThreadState()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetThreadState(ThreadID threadToGet, ThreadState *threadState)
      THREEWORDINLINE(0x303C, 0x0407, 0xABF2);

  /**
   *  SetThreadState()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetThreadState(ThreadID threadToSet, ThreadState newState,
                 ThreadID suggestedThread)
      THREEWORDINLINE(0x303C, 0x0508, 0xABF2);

  /**
   *  SetThreadStateEndCritical()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetThreadStateEndCritical(ThreadID threadToSet, ThreadState newState,
                            ThreadID suggestedThread)
      THREEWORDINLINE(0x303C, 0x0512, 0xABF2);

  /**
   *  ThreadBeginCritical()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ThreadBeginCritical(void) THREEWORDINLINE(0x303C, 0x000B, 0xABF2);

  /**
   *  ThreadEndCritical()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ThreadEndCritical(void) THREEWORDINLINE(0x303C, 0x000C, 0xABF2);

  /**
   *  GetThreadCurrentTaskRef()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetThreadCurrentTaskRef(ThreadTaskRef *threadTRef)
      THREEWORDINLINE(0x303C, 0x020E, 0xABF2);

  /**
   *  GetThreadStateGivenTaskRef()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetThreadStateGivenTaskRef(ThreadTaskRef threadTRef, ThreadID threadToGet,
                             ThreadState *threadState)
      THREEWORDINLINE(0x303C, 0x060F, 0xABF2);

  /**
   *  SetThreadReadyGivenTaskRef()
   *

   *    \non_carbon_cfm   in ThreadsLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetThreadReadyGivenTaskRef(ThreadTaskRef threadTRef, ThreadID threadToSet)
      THREEWORDINLINE(0x303C, 0x0410, 0xABF2);

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

#endif /* __THREADS__ */
