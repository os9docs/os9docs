/**
     \file       ShutDown.h

    \brief   Shutdown Manager Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1987-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __SHUTDOWN__
#define __SHUTDOWN__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
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
  sdOnPowerOff = 1,        /**call procedure before power off.*/
  sdOnRestart = 2,         /**call procedure before restart.*/
  sdOnUnmount = 4,         /**call procedure before unmounting.*/
  sdOnDrivers = 8,         /**call procedure before closing drivers.*/
  sdOnBootVolUnmount = 16, /**call procedure before unmounting boot volume and
                              VM volume but after unmounting all other volumes*/
  sdRestartOrPower = 3     /**call before either power off or restart.*/
};

typedef CALLBACK_API_REGISTER68K(void, ShutDwnProcPtr, (short shutDownStage));
typedef REGISTER_UPP_TYPE(ShutDwnProcPtr) ShutDwnUPP;
#if CALL_NOT_IN_CARBON
/**
 *  NewShutDwnUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(ShutDwnUPP)
NewShutDwnUPP(ShutDwnProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppShutDwnProcInfo = 0x00001002
}; /** register no_return_value Func(2_bytes:D0) */
#ifdef __cplusplus
inline ShutDwnUPP NewShutDwnUPP(ShutDwnProcPtr userRoutine) {
  return (ShutDwnUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppShutDwnProcInfo, GetCurrentArchitecture());
}
#else
#define NewShutDwnUPP(userRoutine)                                             \
  (ShutDwnUPP) NewRoutineDescriptor(                                           \
      (ProcPtr)(userRoutine), uppShutDwnProcInfo, GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeShutDwnUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(void)
DisposeShutDwnUPP(ShutDwnUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeShutDwnUPP(ShutDwnUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeShutDwnUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeShutDwnUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeShutDwnUPP(__D0, __A0)
#endif
EXTERN_API_C(void)
InvokeShutDwnUPP(short shutDownStage, ShutDwnUPP userUPP) ONEWORDINLINE(0x4E90);
#if !OPAQUE_UPP_TYPES &&                                                       \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
inline void InvokeShutDwnUPP(short shutDownStage, ShutDwnUPP userUPP) {
  CALL_ONE_PARAMETER_UPP(userUPP, uppShutDwnProcInfo, shutDownStage);
}
#else
#define InvokeShutDwnUPP(shutDownStage, userUPP)                               \
  CALL_ONE_PARAMETER_UPP((userUPP), uppShutDwnProcInfo, (shutDownStage))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewShutDwnProc(userRoutine) NewShutDwnUPP(userRoutine)
#define CallShutDwnProc(userRoutine, shutDownStage)                            \
  InvokeShutDwnUPP(shutDownStage, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  ShutDwnPower()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
ShutDwnPower(void) THREEWORDINLINE(0x3F3C, 0x0001, 0xA895);

/**
 *  ShutDwnStart()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
ShutDwnStart(void) THREEWORDINLINE(0x3F3C, 0x0002, 0xA895);

/**
 *  ShutDwnInstall()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
ShutDwnInstall(ShutDwnUPP shutDownProc, short flags)
    THREEWORDINLINE(0x3F3C, 0x0003, 0xA895);

/**
 *  ShutDwnRemove()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
ShutDwnRemove(ShutDwnUPP shutDownProc) THREEWORDINLINE(0x3F3C, 0x0004, 0xA895);

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

#endif /** __SHUTDOWN__ */
