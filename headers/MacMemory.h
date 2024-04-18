/**
     \file       MacMemory.h

    \brief   Memory Manager Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __MACMEMORY__
#define __MACMEMORY__

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
  maxSize = 0x7FFFFFF0 /*the largest block possible*/
};

enum { defaultPhysicalEntryCount = 8 };

enum {
  /* values returned from the GetPageState function */
  kPageInMemory = 0,
  kPageOnDisk = 1,
  kNotPaged = 2
};

enum {
  /* masks for Zone->heapType field */
  k32BitHeap = 1,    /* valid in all Memory Managers */
  kNewStyleHeap = 2, /* true if new Heap Manager is present */
  kNewDebugHeap =
      4 /* true if new Heap Manager is running in debug mode on this heap */
};

/* bits for use with HGetState/HSetState*/
enum {
  kHandleIsResourceBit = 5,
  kHandlePurgeableBit = 6,
  kHandleLockedBit = 7
};

/* masks for use with HGetState/HSetState*/
enum {
  kHandleIsResourceMask = 0x20,
  kHandlePurgeableMask = 0x40,
  kHandleLockedMask = 0x80
};

typedef CALLBACK_API(long, GrowZoneProcPtr)(Size cbNeeded);
typedef CALLBACK_API(void, PurgeProcPtr)(Handle blockToPurge);
typedef CALLBACK_API_REGISTER68K(void, UserFnProcPtr, (void *parameter));
typedef STACK_UPP_TYPE(GrowZoneProcPtr) GrowZoneUPP;
typedef STACK_UPP_TYPE(PurgeProcPtr) PurgeUPP;
typedef REGISTER_UPP_TYPE(UserFnProcPtr) UserFnUPP;
struct Zone {
  Ptr bkLim;
  Ptr purgePtr;
  Ptr hFstFree;
  long zcbFree;
  GrowZoneUPP gzProc;
  short moreMast;
  short flags;
  short cntRel;
  short maxRel;
  short cntNRel;
  SInt8 heapType; /* previously "maxNRel", now holds flags (e.g. k32BitHeap)*/
  SInt8 unused;
  short cntEmpty;
  short cntHandles;
  long minCBFree;
  PurgeUPP purgeProc;
  Ptr sparePtr;
  Ptr allocPtr;
  short heapData;
};
typedef struct Zone Zone;
typedef Zone *THz;
typedef THz *THzPtr;
struct MemoryBlock {
  void *address;
  unsigned long count;
};
typedef struct MemoryBlock MemoryBlock;
struct LogicalToPhysicalTable {
  MemoryBlock logical;
  MemoryBlock physical[8];
};
typedef struct LogicalToPhysicalTable LogicalToPhysicalTable;

typedef short PageState;
typedef short StatusRegisterContents;
enum {
  kVolumeVirtualMemoryInfoVersion1 =
      1 /* first version of VolumeVirtualMemoryInfo*/
};

struct VolumeVirtualMemoryInfo {
  PBVersion
      version; /* Input: Version of the VolumeVirtualMemoryInfo structure*/
  SInt16 volumeRefNum; /* Input: volume reference number*/
  Boolean inUse; /* output: true if volume is currently used for file mapping*/
  UInt8 _fill;
  UInt32 vmOptions; /* output: tells what volume can support (same as
                       DriverGestaltVMOptionsResponse vmOptions bits in
                       DriverGestalt)*/
                    /* end of kVolumeVirtualMemoryInfoVersion1 structure*/
};
typedef struct VolumeVirtualMemoryInfo VolumeVirtualMemoryInfo;
typedef VolumeVirtualMemoryInfo *VolumeVirtualMemoryInfoPtr;
/**
 *  NewGrowZoneUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(GrowZoneUPP)
NewGrowZoneUPP(GrowZoneProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum { uppGrowZoneProcInfo = 0x000000F0 }; /* pascal 4_bytes Func(4_bytes) */
#ifdef __cplusplus
inline GrowZoneUPP NewGrowZoneUPP(GrowZoneProcPtr userRoutine) {
  return (GrowZoneUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppGrowZoneProcInfo, GetCurrentArchitecture());
}
#else
#define NewGrowZoneUPP(userRoutine)                                            \
  (GrowZoneUPP) NewRoutineDescriptor(                                          \
      (ProcPtr)(userRoutine), uppGrowZoneProcInfo, GetCurrentArchitecture())
#endif
#endif

/**
 *  NewPurgeUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(PurgeUPP)
NewPurgeUPP(PurgeProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppPurgeProcInfo = 0x000000C0
}; /* pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
inline PurgeUPP NewPurgeUPP(PurgeProcPtr userRoutine) {
  return (PurgeUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppPurgeProcInfo, GetCurrentArchitecture());
}
#else
#define NewPurgeUPP(userRoutine)                                               \
  (PurgeUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppPurgeProcInfo,    \
                                  GetCurrentArchitecture())
#endif
#endif

/**
 *  NewUserFnUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UserFnUPP)
NewUserFnUPP(UserFnProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppUserFnProcInfo = 0x00009802
}; /* register no_return_value Func(4_bytes:A0) */
#ifdef __cplusplus
inline UserFnUPP NewUserFnUPP(UserFnProcPtr userRoutine) {
  return (UserFnUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppUserFnProcInfo, GetCurrentArchitecture());
}
#else
#define NewUserFnUPP(userRoutine)                                              \
  (UserFnUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppUserFnProcInfo,  \
                                   GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeGrowZoneUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposeGrowZoneUPP(GrowZoneUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeGrowZoneUPP(GrowZoneUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeGrowZoneUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposePurgeUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposePurgeUPP(PurgeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposePurgeUPP(PurgeUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposePurgeUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeUserFnUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposeUserFnUPP(UserFnUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeUserFnUPP(UserFnUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeUserFnUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeGrowZoneUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(long)
InvokeGrowZoneUPP(Size cbNeeded, GrowZoneUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline long InvokeGrowZoneUPP(Size cbNeeded, GrowZoneUPP userUPP) {
  return (long)CALL_ONE_PARAMETER_UPP(userUPP, uppGrowZoneProcInfo, cbNeeded);
}
#else
#define InvokeGrowZoneUPP(cbNeeded, userUPP)                                   \
  (long)CALL_ONE_PARAMETER_UPP((userUPP), uppGrowZoneProcInfo, (cbNeeded))
#endif
#endif

/**
 *  InvokePurgeUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
InvokePurgeUPP(Handle blockToPurge, PurgeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void InvokePurgeUPP(Handle blockToPurge, PurgeUPP userUPP) {
  CALL_ONE_PARAMETER_UPP(userUPP, uppPurgeProcInfo, blockToPurge);
}
#else
#define InvokePurgeUPP(blockToPurge, userUPP)                                  \
  CALL_ONE_PARAMETER_UPP((userUPP), uppPurgeProcInfo, (blockToPurge))
#endif
#endif

/**
 *  InvokeUserFnUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeUserFnUPP(__A0, __A1)
#endif
EXTERN_API_C(void)
InvokeUserFnUPP(void *parameter, UserFnUPP userUPP) ONEWORDINLINE(0x4E91);
#if !OPAQUE_UPP_TYPES &&                                                       \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
inline void InvokeUserFnUPP(void *parameter, UserFnUPP userUPP) {
  CALL_ONE_PARAMETER_UPP(userUPP, uppUserFnProcInfo, parameter);
}
#else
#define InvokeUserFnUPP(parameter, userUPP)                                    \
  CALL_ONE_PARAMETER_UPP((userUPP), uppUserFnProcInfo, (parameter))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewGrowZoneProc(userRoutine) NewGrowZoneUPP(userRoutine)
#define NewPurgeProc(userRoutine) NewPurgeUPP(userRoutine)
#define NewUserFnProc(userRoutine) NewUserFnUPP(userRoutine)
#define CallGrowZoneProc(userRoutine, cbNeeded)                                \
  InvokeGrowZoneUPP(cbNeeded, userRoutine)
#define CallPurgeProc(userRoutine, blockToPurge)                               \
  InvokePurgeUPP(blockToPurge, userRoutine)
#define CallUserFnProc(userRoutine, parameter)                                 \
  InvokeUserFnUPP(parameter, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  GetApplLimit()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Ptr)
GetApplLimit(void) TWOWORDINLINE(0x2EB8, 0x0130);

/**
 *  SystemZone()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(THz)
SystemZone(void) TWOWORDINLINE(0x2EB8, 0x02A6);

/**
 *  ApplicationZone()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(THz)
ApplicationZone(void) TWOWORDINLINE(0x2EB8, 0x02AA);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  GZSaveHnd()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Handle)
GZSaveHnd(void) TWOWORDINLINE(0x2EB8, 0x0328);

/**
 *  TopMem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Ptr)
TopMem(void) TWOWORDINLINE(0x2EB8, 0x0108);

/**
 *  MemError()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
MemError(void) TWOWORDINLINE(0x3EB8, 0x0220);

#if CALL_NOT_IN_CARBON
/**
 *  GetZone()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 GetZone
#endif
EXTERN_API(THz)
GetZone(void) ONEWORDINLINE(0xA11A);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  NewHandle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 NewHandle(__D0)
#endif
EXTERN_API(Handle)
NewHandle(Size byteCount) ONEWORDINLINE(0xA122);

#if CALL_NOT_IN_CARBON
/**
 *  NewHandleSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 NewHandleSys(__D0)
#endif
EXTERN_API(Handle)
NewHandleSys(Size byteCount) ONEWORDINLINE(0xA522);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  NewHandleClear()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 NewHandleClear(__D0)
#endif
EXTERN_API(Handle)
NewHandleClear(Size byteCount) ONEWORDINLINE(0xA322);

#if CALL_NOT_IN_CARBON
/**
 *  NewHandleSysClear()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 NewHandleSysClear(__D0)
#endif
EXTERN_API(Handle)
NewHandleSysClear(Size byteCount) ONEWORDINLINE(0xA722);

/**
 *  HandleZone()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 HandleZone(__A0)
#endif
EXTERN_API(THz)
HandleZone(Handle h) ONEWORDINLINE(0xA126);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  RecoverHandle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 RecoverHandle(__A0)
#endif
EXTERN_API(Handle)
RecoverHandle(Ptr p) ONEWORDINLINE(0xA128);

#if CALL_NOT_IN_CARBON
/**
 *  RecoverHandleSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 RecoverHandleSys(__A0)
#endif
EXTERN_API(Handle)
RecoverHandleSys(Ptr p) ONEWORDINLINE(0xA528);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  NewPtr()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 NewPtr(__D0)
#endif
EXTERN_API(Ptr)
NewPtr(Size byteCount) ONEWORDINLINE(0xA11E);

#if CALL_NOT_IN_CARBON
/**
 *  NewPtrSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 NewPtrSys(__D0)
#endif
EXTERN_API(Ptr)
NewPtrSys(Size byteCount) ONEWORDINLINE(0xA51E);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  NewPtrClear()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 NewPtrClear(__D0)
#endif
EXTERN_API(Ptr)
NewPtrClear(Size byteCount) ONEWORDINLINE(0xA31E);

#if CALL_NOT_IN_CARBON
/**
 *  NewPtrSysClear()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 NewPtrSysClear(__D0)
#endif
EXTERN_API(Ptr)
NewPtrSysClear(Size byteCount) ONEWORDINLINE(0xA71E);

/**
 *  PtrZone()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 PtrZone(__A0)
#endif
EXTERN_API(THz)
PtrZone(Ptr p) ONEWORDINLINE(0xA148);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  MaxBlock()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 MaxBlock
#endif
EXTERN_API(long)
MaxBlock(void) ONEWORDINLINE(0xA061);

#if CALL_NOT_IN_CARBON
/**
 *  MaxBlockSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 MaxBlockSys
#endif
EXTERN_API(long)
MaxBlockSys(void) ONEWORDINLINE(0xA461);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  StackSpace()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 StackSpace
#endif
EXTERN_API(long)
StackSpace(void) ONEWORDINLINE(0xA065);

/**
 *  NewEmptyHandle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 NewEmptyHandle
#endif
EXTERN_API(Handle)
NewEmptyHandle(void) ONEWORDINLINE(0xA166);

#if CALL_NOT_IN_CARBON
/**
 *  NewEmptyHandleSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 NewEmptyHandleSys
#endif
EXTERN_API(Handle)
NewEmptyHandleSys(void) ONEWORDINLINE(0xA566);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  HLock()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter HLock(__A0)
#endif
EXTERN_API(void)
HLock(Handle h) ONEWORDINLINE(0xA029);

/**
 *  HUnlock()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter HUnlock(__A0)
#endif
EXTERN_API(void)
HUnlock(Handle h) ONEWORDINLINE(0xA02A);

/**
 *  HPurge()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter HPurge(__A0)
#endif
EXTERN_API(void)
HPurge(Handle h) ONEWORDINLINE(0xA049);

/**
 *  HNoPurge()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter HNoPurge(__A0)
#endif
EXTERN_API(void)
HNoPurge(Handle h) ONEWORDINLINE(0xA04A);

/**
 *  HLockHi()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter HLockHi(__A0)
#endif
EXTERN_API(void)
HLockHi(Handle h) TWOWORDINLINE(0xA064, 0xA029);

/**
 *  TempNewHandle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Handle)
TempNewHandle(Size logicalSize, OSErr *resultCode)
    THREEWORDINLINE(0x3F3C, 0x001D, 0xA88F);

/**
 *  TempMaxMem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Size)
TempMaxMem(Size *grow) THREEWORDINLINE(0x3F3C, 0x0015, 0xA88F);

/**
 *  TempFreeMem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(long)
TempFreeMem(void) THREEWORDINLINE(0x3F3C, 0x0018, 0xA88F);

#if CALL_NOT_IN_CARBON
/**
 *  InitZone()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
InitZone(GrowZoneUPP pgrowZone, short cmoreMasters, void *limitPtr,
         void *startPtr);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  SetZone()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetZone(__A0)
#endif
EXTERN_API(void)
SetZone(THz hz) ONEWORDINLINE(0xA01B);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  CompactMem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 CompactMem(__D0)
#endif
EXTERN_API(Size)
CompactMem(Size cbNeeded) ONEWORDINLINE(0xA04C);

#if CALL_NOT_IN_CARBON
/**
 *  CompactMemSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 CompactMemSys(__D0)
#endif
EXTERN_API(Size)
CompactMemSys(Size cbNeeded) ONEWORDINLINE(0xA44C);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  PurgeMem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PurgeMem(__D0)
#endif
EXTERN_API(void)
PurgeMem(Size cbNeeded) ONEWORDINLINE(0xA04D);

#if CALL_NOT_IN_CARBON
/**
 *  PurgeMemSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PurgeMemSys(__D0)
#endif
EXTERN_API(void)
PurgeMemSys(Size cbNeeded) ONEWORDINLINE(0xA44D);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  FreeMem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 FreeMem
#endif
EXTERN_API(long)
FreeMem(void) ONEWORDINLINE(0xA01C);

#if CALL_NOT_IN_CARBON
/**
 *  FreeMemSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 FreeMemSys
#endif
EXTERN_API(long)
FreeMemSys(void) ONEWORDINLINE(0xA41C);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  ReserveMem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter ReserveMem(__D0)
#endif
EXTERN_API(void)
ReserveMem(Size cbNeeded) ONEWORDINLINE(0xA040);

#if CALL_NOT_IN_CARBON
/**
 *  ReserveMemSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter ReserveMemSys(__D0)
#endif
EXTERN_API(void)
ReserveMemSys(Size cbNeeded) ONEWORDINLINE(0xA440);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  MaxMem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 MaxMem(__A1)
#endif
EXTERN_API(Size)
MaxMem(Size *grow) TWOWORDINLINE(0xA11D, 0x2288);

#if CALL_NOT_IN_CARBON
/**
 *  MaxMemSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 MaxMemSys(__A1)
#endif
EXTERN_API(Size)
MaxMemSys(Size *grow) TWOWORDINLINE(0xA51D, 0x2288);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  SetGrowZone()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetGrowZone(__A0)
#endif
EXTERN_API(void)
SetGrowZone(GrowZoneUPP growZone) ONEWORDINLINE(0xA04B);

/**
 *  GetGrowZone()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(GrowZoneUPP)
GetGrowZone(void);

/**
 *  MoveHHi()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter MoveHHi(__A0)
#endif
EXTERN_API(void)
MoveHHi(Handle h) ONEWORDINLINE(0xA064);

/**
 *  DisposePtr()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter DisposePtr(__A0)
#endif
EXTERN_API(void)
DisposePtr(Ptr p) ONEWORDINLINE(0xA01F);

/**
 *  GetPtrSize()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Size)
GetPtrSize(Ptr p);

/**
 *  SetPtrSize()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetPtrSize(__A0, __D0)
#endif
EXTERN_API(void)
SetPtrSize(Ptr p, Size newSize) ONEWORDINLINE(0xA020);

/**
 *  DisposeHandle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter DisposeHandle(__A0)
#endif
EXTERN_API(void)
DisposeHandle(Handle h) ONEWORDINLINE(0xA023);

/**
 *  SetHandleSize()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetHandleSize(__A0, __D0)
#endif
EXTERN_API(void)
SetHandleSize(Handle h, Size newSize) ONEWORDINLINE(0xA024);

/**
    NOTE

    GetHandleSize and GetPtrSize are documented in Inside Mac as returning 0
    in case of an error, but the traps actually return an error code in D0.
    The glue sets D0 to 0 if an error occurred.
*/
/**
 *  GetHandleSize()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Size)
GetHandleSize(Handle h);

#if CALL_NOT_IN_CARBON
/**
 *  InlineGetHandleSize()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InlineGetHandleSize(__A0)
#endif
EXTERN_API(Size)
InlineGetHandleSize(Handle h) ONEWORDINLINE(0xA025);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  ReallocateHandle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter ReallocateHandle(__A0, __D0)
#endif
EXTERN_API(void)
ReallocateHandle(Handle h, Size byteCount) ONEWORDINLINE(0xA027);

#if CALL_NOT_IN_CARBON
/**
 *  ReallocateHandleSys()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter ReallocateHandleSys(__A0, __D0)
#endif
EXTERN_API(void)
ReallocateHandleSys(Handle h, Size byteCount) ONEWORDINLINE(0xA427);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  EmptyHandle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter EmptyHandle(__A0)
#endif
EXTERN_API(void)
EmptyHandle(Handle h) ONEWORDINLINE(0xA02B);

/**
 *  HSetRBit()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter HSetRBit(__A0)
#endif
EXTERN_API(void)
HSetRBit(Handle h) ONEWORDINLINE(0xA067);

/**
 *  HClrRBit()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter HClrRBit(__A0)
#endif
EXTERN_API(void)
HClrRBit(Handle h) ONEWORDINLINE(0xA068);

/**
 *  HGetState()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 HGetState(__A0)
#endif
EXTERN_API(SInt8)
HGetState(Handle h) ONEWORDINLINE(0xA069);

/**
 *  HSetState()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter HSetState(__A0, __D0)
#endif
EXTERN_API(void)
HSetState(Handle h, SInt8 flags) ONEWORDINLINE(0xA06A);

/**
 *  PurgeSpace()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
PurgeSpace(long *total, long *contig);

/**
    PurgeSpaceTotal and PurgeSpaceContiguous are currently only implement
    on classic 68K.  The are the same as PurgeSpace() but return just
    one value (either total space purgable or contiguous space purgable).
    Begining in Mac OS 8.5 they are available in InterfaceLib.
*/
/**
 *  PurgeSpaceTotal()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 PurgeSpaceTotal
#endif
EXTERN_API(long)
PurgeSpaceTotal(void) ONEWORDINLINE(0xA062);

/**
 *  PurgeSpaceContiguous()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PurgeSpaceContiguous
#endif
EXTERN_API(long)
PurgeSpaceContiguous(void) ONEWORDINLINE(0xA062);

#if CALL_NOT_IN_CARBON
/**
 *  PurgeSpaceSysTotal()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 PurgeSpaceSysTotal
#endif
EXTERN_API(long)
PurgeSpaceSysTotal(void) ONEWORDINLINE(0xA562);

/**
 *  PurgeSpaceSysContiguous()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PurgeSpaceSysContiguous
#endif
EXTERN_API(long)
PurgeSpaceSysContiguous(void) ONEWORDINLINE(0xA562);

/*****************************************************************************

    The routines:

        BlockMoveUncached, BlockMoveDataUncached
        BlockZero, BlockZeroUncached

    were first created for developers writing drivers. Originally they only
    existed in DriverServicesLib.  Later they were added to InterfaceLib
    in PCI based PowerMacs.  MacOS 8.5 provides these routines in InterfaceLib
    on all supported machines.

*****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

/**
 *  BlockMove()
 *

 *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter BlockMove(__A0, __A1, __D0)
#endif
EXTERN_API(void)
BlockMove(const void *srcPtr, void *destPtr, Size byteCount)
    ONEWORDINLINE(0xA02E);

/**
 *  BlockMoveData()
 *

 *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter BlockMoveData(__A0, __A1, __D0)
#endif
EXTERN_API(void)
BlockMoveData(const void *srcPtr, void *destPtr, Size byteCount)
    ONEWORDINLINE(0xA22E);

/**
 *  BlockMoveUncached()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
BlockMoveUncached(const void *srcPtr, void *destPtr, Size byteCount);

/**
 *  BlockMoveDataUncached()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
BlockMoveDataUncached(const void *srcPtr, void *destPtr, Size byteCount);

/**
 *  BlockZero()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
BlockZero(void *destPtr, Size byteCount);

/**
 *  BlockZeroUncached()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
BlockZeroUncached(void *destPtr, Size byteCount);

#if CALL_NOT_IN_CARBON
/**
 *  MaxApplZone()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
MaxApplZone(void) ONEWORDINLINE(0xA063);

/**
 *  SetApplBase()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetApplBase(__A0)
#endif
EXTERN_API(void)
SetApplBase(void *startPtr) ONEWORDINLINE(0xA057);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  MoreMasters()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
MoreMasters(void) ONEWORDINLINE(0xA036);

/**
 *  MoreMasterPointers()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
MoreMasterPointers(UInt32 inCount);

#if CALL_NOT_IN_CARBON
/**
 *  SetApplLimit()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetApplLimit(__A0)
#endif
EXTERN_API(void)
SetApplLimit(void *zoneLimit) ONEWORDINLINE(0xA02D);

/**
 *  InitApplZone()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
InitApplZone(void) ONEWORDINLINE(0xA02C);

/*  Temporary Memory routines renamed, but obsolete, in System 7.0 and later. */
#endif /* CALL_NOT_IN_CARBON */

/**
 *  TempHLock()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
TempHLock(Handle h, OSErr *resultCode) THREEWORDINLINE(0x3F3C, 0x001E, 0xA88F);

/**
 *  TempHUnlock()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
TempHUnlock(Handle h, OSErr *resultCode)
    THREEWORDINLINE(0x3F3C, 0x001F, 0xA88F);

/**
 *  TempDisposeHandle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
TempDisposeHandle(Handle h, OSErr *resultCode)
    THREEWORDINLINE(0x3F3C, 0x0020, 0xA88F);

/**
 *  TempTopMem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Ptr)
TempTopMem(void) THREEWORDINLINE(0x3F3C, 0x0016, 0xA88F);

/**
 *  HoldMemory()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 HoldMemory(__A0, __A1)
#endif
EXTERN_API(OSErr)
HoldMemory(void *address, unsigned long count) TWOWORDINLINE(0x7000, 0xA05C);

/**
 *  UnholdMemory()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 UnholdMemory(__A0, __A1)
#endif
EXTERN_API(OSErr)
UnholdMemory(void *address, unsigned long count) TWOWORDINLINE(0x7001, 0xA05C);

#if CALL_NOT_IN_CARBON
/**
 *  LockMemory()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 LockMemory(__A0, __A1)
#endif
EXTERN_API(OSErr)
LockMemory(void *address, unsigned long count) TWOWORDINLINE(0x7002, 0xA05C);

/**
 *  LockMemoryForOutput()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 LockMemoryForOutput(__A0, __A1)
#endif
EXTERN_API(OSErr)
LockMemoryForOutput(void *address, unsigned long count)
    TWOWORDINLINE(0x700A, 0xA05C);

/**
 *  LockMemoryContiguous()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 LockMemoryContiguous(__A0, __A1)
#endif
EXTERN_API(OSErr)
LockMemoryContiguous(void *address, unsigned long count)
    TWOWORDINLINE(0x7004, 0xA05C);

/**
 *  UnlockMemory()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 UnlockMemory(__A0, __A1)
#endif
EXTERN_API(OSErr)
UnlockMemory(void *address, unsigned long count) TWOWORDINLINE(0x7003, 0xA05C);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  MakeMemoryResident()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 MakeMemoryResident(__A0, __A1)
#endif
EXTERN_API(OSErr)
MakeMemoryResident(void *address, unsigned long count)
    TWOWORDINLINE(0x700B, 0xA05C);

/**
 *  ReleaseMemoryData()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 ReleaseMemoryData(__A0, __A1)
#endif
EXTERN_API(OSErr)
ReleaseMemoryData(void *address, unsigned long count)
    TWOWORDINLINE(0x700C, 0xA05C);

/**
 *  MakeMemoryNonResident()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 MakeMemoryNonResident(__A0, __A1)
#endif
EXTERN_API(OSErr)
MakeMemoryNonResident(void *address, unsigned long count)
    TWOWORDINLINE(0x700D, 0xA05C);

/**
 *  FlushMemory()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 FlushMemory(__A0, __A1)
#endif
EXTERN_API(OSErr)
FlushMemory(void *address, unsigned long count) TWOWORDINLINE(0x700E, 0xA05C);

#if CALL_NOT_IN_CARBON
/**
 *  GetPhysical()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetPhysical(__A0, __A1)
#endif
EXTERN_API(OSErr)
GetPhysical(LogicalToPhysicalTable *addresses,
            unsigned long *physicalEntryCount)
    SIXWORDINLINE(0x2209, 0x2251, 0x7005, 0xA15C, 0x2241, 0x2288);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  GetVolumeVirtualMemoryInfo()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetVolumeVirtualMemoryInfo(__A0)
#endif
EXTERN_API(OSErr)
GetVolumeVirtualMemoryInfo(VolumeVirtualMemoryInfoPtr volVMInfo)
    TWOWORDINLINE(0x700F, 0xA05C);

/**
 *  DeferUserFn()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 DeferUserFn(__A0, __D0)
#endif
EXTERN_API(OSErr)
DeferUserFn(UserFnUPP userFunction, void *argument) ONEWORDINLINE(0xA08F);

/**
 *  DebuggerGetMax()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 DebuggerGetMax
#endif
EXTERN_API(long)
DebuggerGetMax(void) TWOWORDINLINE(0x7000, 0xA08D);

/**
 *  DebuggerEnter()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
DebuggerEnter(void) TWOWORDINLINE(0x7001, 0xA08D);

/**
 *  DebuggerExit()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
DebuggerExit(void) TWOWORDINLINE(0x7002, 0xA08D);

/**
 *  DebuggerPoll()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
DebuggerPoll(void) TWOWORDINLINE(0x7003, 0xA08D);

/**
 *  GetPageState()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetPageState(__A0)
#endif
EXTERN_API(PageState)
GetPageState(const void *address) TWOWORDINLINE(0x7004, 0xA08D);

/**
 *  PageFaultFatal()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PageFaultFatal
#endif
EXTERN_API(Boolean)
PageFaultFatal(void) TWOWORDINLINE(0x7005, 0xA08D);

/**
 *  DebuggerLockMemory()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 DebuggerLockMemory(__A0, __A1)
#endif
EXTERN_API(OSErr)
DebuggerLockMemory(void *address, unsigned long count)
    TWOWORDINLINE(0x7006, 0xA08D);

/**
 *  DebuggerUnlockMemory()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 DebuggerUnlockMemory(__A0, __A1)
#endif
EXTERN_API(OSErr)
DebuggerUnlockMemory(void *address, unsigned long count)
    TWOWORDINLINE(0x7007, 0xA08D);

/**
 *  EnterSupervisorMode()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 EnterSupervisorMode
#endif
EXTERN_API(StatusRegisterContents)
EnterSupervisorMode(void) TWOWORDINLINE(0x7008, 0xA08D);

/**
 *  StripAddress()
 *
 *  Summary:
 *    A trap on classic 68K, and the identity function for pre-carbon
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 StripAddress(__D0)
#endif
EXTERN_API(Ptr)
StripAddress(void *theAddress) ONEWORDINLINE(0xA055);
#if !TARGET_OS_MAC || !TARGET_CPU_68K
#ifdef __cplusplus
inline DEFINE_API(Ptr) StripAddress(void *theAddress) {
  return (Ptr)theAddress;
}
#else
#define StripAddress(theAddress) ((Ptr)theAddress)
#endif
#endif

/**
 *  Translate24To32()
 *
 *  Summary:
 *    A trap on classic 68K, and the identity function for pre-carbon
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 Translate24To32(__D0)
#endif
EXTERN_API(Ptr)
Translate24To32(void *addr24) ONEWORDINLINE(0xA091);
#if !TARGET_OS_MAC || !TARGET_CPU_68K
#ifdef __cplusplus
inline DEFINE_API(Ptr) Translate24To32(void *addr24) { return (Ptr)addr24; }
#else
#define Translate24To32(addr24) ((Ptr)addr24)
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

/**
 *  HandToHand()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
HandToHand(Handle *theHndl);

/**
 *  PtrToXHand()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PtrToXHand(__A0, __A1, __D0)
#endif
EXTERN_API(OSErr)
PtrToXHand(const void *srcPtr, Handle dstHndl, long size) ONEWORDINLINE(0xA9E2);

/**
 *  PtrToHand()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
PtrToHand(const void *srcPtr, Handle *dstHndl, long size);

/**
 *  HandAndHand()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 HandAndHand(__A0, __A1)
#endif
EXTERN_API(OSErr)
HandAndHand(Handle hand1, Handle hand2) ONEWORDINLINE(0xA9E4);

/**
 *  PtrAndHand()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PtrAndHand(__A0, __A1, __D0)
#endif
EXTERN_API(OSErr)
PtrAndHand(const void *ptr1, Handle hand2, long size) ONEWORDINLINE(0xA9EF);

/* Carbon routines to aid in debugging. */
/* Checks all applicable heaps for validity */
/**
 *  CheckAllHeaps()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
CheckAllHeaps(void);

/* Checks the application heap for validity */
/**
 *  IsHeapValid()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
IsHeapValid(void);

/* It is invalid to pass a NULL or an empty Handle to IsHandleValid */
/**
 *  IsHandleValid()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
IsHandleValid(Handle h);

/* It is invalid to pass a NULL Pointer to IsPointerValid */
/**
 *  IsPointerValid()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
IsPointerValid(Ptr p);

#if OLDROUTINENAMES
#define ApplicZone() ApplicationZone()
#define MFTempNewHandle(logicalSize, resultCode)                               \
  TempNewHandle(logicalSize, resultCode)
#define MFMaxMem(grow) TempMaxMem(grow)
#define MFFreeMem() TempFreeMem()
#define MFTempHLock(h, resultCode) TempHLock(h, resultCode)
#define MFTempHUnlock(h, resultCode) TempHUnlock(h, resultCode)
#define MFTempDisposHandle(h, resultCode) TempDisposeHandle(h, resultCode)
#define MFTopMem() TempTopMem()
#define ResrvMem(cbNeeded) ReserveMem(cbNeeded)
#define DisposPtr(p) DisposePtr(p)
#define DisposHandle(h) DisposeHandle(h)
#define ReallocHandle(h, byteCount) ReallocateHandle(h, byteCount)
#endif /* OLDROUTINENAMES */

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

#endif /* __MACMEMORY__ */
