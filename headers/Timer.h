/**
     \file       Timer.h

    \brief   Time Manager interfaces.

    \introduced_in  Mac OS 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __TIMER__
#define __TIMER__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __OSUTILS__
#include <OSUtils.h>
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

enum {
  /* high bit of qType is set if task is active */
  kTMTaskActive = (1L << 15)
};

typedef struct TMTask TMTask;
typedef TMTask *TMTaskPtr;
typedef CALLBACK_API_REGISTER68K(void, TimerProcPtr, (TMTaskPtr tmTaskPtr));
typedef REGISTER_UPP_TYPE(TimerProcPtr) TimerUPP;
struct TMTask {
  QElemPtr qLink;
  short qType;
  TimerUPP tmAddr;
  long tmCount;
  long tmWakeUp;
  long tmReserved;
};

/**
 *  InsTime()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InsTime(__A0)
#endif
EXTERN_API(void)
InsTime(QElemPtr tmTaskPtr) ONEWORDINLINE(0xA058);

/**
 *  InsXTime()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InsXTime(__A0)
#endif
EXTERN_API(void)
InsXTime(QElemPtr tmTaskPtr) ONEWORDINLINE(0xA458);

/**
 *  PrimeTime()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PrimeTime(__A0, __D0)
#endif
EXTERN_API(void)
PrimeTime(QElemPtr tmTaskPtr, long count) ONEWORDINLINE(0xA05A);

/**
 *  RmvTime()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter RmvTime(__A0)
#endif
EXTERN_API(void)
RmvTime(QElemPtr tmTaskPtr) ONEWORDINLINE(0xA059);

/* InstallTimeTask, InstallXTimeTask, PrimeTimeTask and RemoveTimeTask work */
/* just like InsTime, InsXTime, PrimeTime, and RmvTime except that they */
/* return an OSErr result. */
/**
 *  InstallTimeTask()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InstallTimeTask(__A0)
#endif
EXTERN_API(OSErr)
InstallTimeTask(QElemPtr tmTaskPtr) ONEWORDINLINE(0xA058);

/**
 *  InstallXTimeTask()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InstallXTimeTask(__A0)
#endif
EXTERN_API(OSErr)
InstallXTimeTask(QElemPtr tmTaskPtr) ONEWORDINLINE(0xA458);

/**
 *  PrimeTimeTask()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PrimeTimeTask(__A0, __D0)
#endif
EXTERN_API(OSErr)
PrimeTimeTask(QElemPtr tmTaskPtr, long count) ONEWORDINLINE(0xA05A);

/**
 *  RemoveTimeTask()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 RemoveTimeTask(__A0)
#endif
EXTERN_API(OSErr)
RemoveTimeTask(QElemPtr tmTaskPtr) ONEWORDINLINE(0xA059);

/**
 *  Microseconds()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
Microseconds(UnsignedWide *microTickCount)
    FOURWORDINLINE(0xA193, 0x225F, 0x22C8, 0x2280);

/**
 *  NewTimerUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(TimerUPP)
NewTimerUPP(TimerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppTimerProcInfo = 0x0000B802
}; /* register no_return_value Func(4_bytes:A1) */
#ifdef __cplusplus
inline TimerUPP NewTimerUPP(TimerProcPtr userRoutine) {
  return (TimerUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppTimerProcInfo, GetCurrentArchitecture());
}
#else
#define NewTimerUPP(userRoutine)                                               \
  (TimerUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppTimerProcInfo,    \
                                  GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeTimerUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposeTimerUPP(TimerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeTimerUPP(TimerUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeTimerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeTimerUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeTimerUPP(__A1, __A0)
#endif
EXTERN_API_C(void)
InvokeTimerUPP(TMTaskPtr tmTaskPtr, TimerUPP userUPP) ONEWORDINLINE(0x4E90);
#if !OPAQUE_UPP_TYPES &&                                                       \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
inline void InvokeTimerUPP(TMTaskPtr tmTaskPtr, TimerUPP userUPP) {
  CALL_ONE_PARAMETER_UPP(userUPP, uppTimerProcInfo, tmTaskPtr);
}
#else
#define InvokeTimerUPP(tmTaskPtr, userUPP)                                     \
  CALL_ONE_PARAMETER_UPP((userUPP), uppTimerProcInfo, (tmTaskPtr))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewTimerProc(userRoutine) NewTimerUPP(userRoutine)
#define CallTimerProc(userRoutine, tmTaskPtr)                                  \
  InvokeTimerUPP(tmTaskPtr, userRoutine)
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

#endif /* __TIMER__ */
