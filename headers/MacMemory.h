/**
     \file       MacMemory.h

    \brief   Memory Manager Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System
    
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
/**
<pre>
 * \note <pre>Several Memory manager calls require (or return) a THz (pointer to
Zone), including:
GetZone SystemZone HandleZone
SetZone ApplicZone PtrZone
The global variable TheZone (at 0x0118) contains the address of the Zone
structure at the start of the current heap zone.
The gzProc field is set when you call InitZone or SetGrowZone . Set it to
NIL (0) if you don't care. This proc will be called when more space is
needed, as explained in SetGrowZone .
The zcbFree field contains the total number of free bytes in the zone. If the
zone is fragmented in the least, you won't be able allocate this much
memory in one block.
You can install a custom "purge warning procedure" by storing its address
in purgeProc. Note that purgeProc gets overwritten whenever you call
SetResPurge (TRUE).
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct Zone {
	Ptr bkLim ;/**< Block limit;/**< addr of byte after last in zone*/
	Ptr purgePtr ;/**< (used internally)*/
	Ptr hFstFree ;/**< First free master pointer*/
	long zcbFree ;/**< Number of free bytes*/
	ProcPtr gzProc ;/**< Address of grow zone proc ( SetGrowZone )*/
	short moreMast ;/**< Number of master ptrs to allocate at a time*/
	short flags ;/**< (used internally)*/
	short cntRel ;/**< (not used)*/
	short maxRel ;/**< (not used)*/
	short cntNRel ;/**< (not used)*/
	short maxNRel ;/**< (not used)*/
	short cntEmpty ;/**< (not used)*/
	short cntHandles ;/**< (not used)*/
	long minCBFree ;/**< (not used)*/
	ProcPtr purgeProc ;/**< Address of purge warning procedure*/
	Ptr sparePtr ;/**< (used internally)*/
	Ptr allocPtr ;/**< (used internally)*/
	short heapData ;/**< First byte of data in the zone*/
	} Zone;/**<  (size of this zone-prefix information)*/

typedef struct Zone Zone;
typedef Zone *THz;
typedef THz *THzPtr;
/**
<pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct MemoryBlock  {
	void *address;/**<  start of block*/
	unsigned long count;/**<  size of block*/
	} MemoryBlock ;/**< */

typedef struct MemoryBlock MemoryBlock;
/**
<pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct LogicalToPhysicalTable  {
	MemoryBlock logical;/**< logical block*/
	MemoryBlock physical[ defaultphysicalEntryCount ];/**<equivalent*/
	}LogicalToPhysicalTable  ;/**< */

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
			\brief Obtain current application heap limit 
			
			<pre>GetApplLimit returns the address of the end of the application heap zone.
</pre>
 * \returns <pre>a Ptr; the address of the end (top) of the application heap +1.
</pre>
 * \note <pre>You can get this same information by reading the global variable ApplLimit
(at 0x0130).
You might call GetApplLimit before reducing or expanding the
application zone size via SetApplLimit .
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Ptr)
GetApplLimit(void) TWOWORDINLINE(0x2EB8, 0x0130);


			/** 
			\brief Get address of the start of the system heap zone 
			
			<pre>SystemZone returns the address of the start of the Zone structure of the
system heap. This is the same as the value stored in the global variable
SysZone (at 0x02A6).
</pre>
 * \returns <pre>a pointer to a Zone structure; the address of the start of the system
heap zone.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Get handle to data to not move during zone growth 
			
			<pre>root" should NOT be moved. GZSaveHnd returns a handle leading to that data.
</pre>
 * \returns <pre>a generic Handle; it leads to data that should not be moved, unlocked,
purged, etc.
</pre>
 * \note <pre>GZSaveHnd should be used by applications that have a custom heap-zone
grow function (see SetGrowZone ). That function should take care to avoid
moving, unlocking, or purging the data led to by the returned  handle.
The global variable GZRootHnd (at 0x0328) contains this handle.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Handle)
GZSaveHnd(void) TWOWORDINLINE(0x2EB8, 0x0328);


			/** 
			\brief Get address of end of RAM 
			
			<pre>TopMem returns a pointer to the first byte beyond the end of physical RAM,
or to the end of memory available for applications.
</pre>
 * \returns <pre>a Ptr; the highest RAM address accessible.
</pre>
 * \note <pre>The global variable MemTop (at 0x0108) carries this same information.
The Environs and SysEnvirons functions provide a lot of information
about the equipment you are running.
Other Memory Manager global variables include:
MemTop 0x108 Address of end of RAM
BufPtr 0x10C Address of end of jump table
HeapEnd 0x114 Address of end of application heap zone
TheZone 0x118 Address of current heap zone
ApplLimit 0x130 Application heap limit
SysZone 0x2A6 Address of system heap zone
ApplZone 0x2AA Address of application heap zone
ROMBase 0x2AE Address of start of ROM
RAMBase 0x2B2 Trap dispatch base for RAM routines
ScrnBase 0x824 Address of main screen buffer
CurrentA5 0x904 Start of application globals
CurStackBase 0x908 Address of the base of the stack
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Ptr)
TopMem(void) TWOWORDINLINE(0x2EB8, 0x0108);


			/** 
			\brief Return error code of last Memory Manager  function 
			
			<pre>MemError returns the OSErr code of the most recent call to a Memory
Manager function.
</pre>
 * \returns <pre>an OSErr (a.k.a. short). Common Error/Return Code returns:
noErr(0) No error
memFullErr (-108) No room in heap
nilHandleErr (-109) Illegal operation on a NIL handle
memWZErr (-111) Illegal operation on a free block
memPurErr (-112) Illegal operation on a locked block
memLockedErr (-117) Can't move a locked block
</pre>
 * \note <pre>Before returning to an application, the Memory Manager stores an
error/return code into a global variable. If you call MemError , you get a
copy of that value.  Note that this value is affected only by calls made
directly by the application (and not errors made indirectly; e.g. via a
toolbox function that calls the Memory Manager indirectly).
C programmers may access the global variable MemErr (at 0x0220)
directly. For instance:
HPurge ( myHandle );
if ( MemError () ) { . . . process the error . . . }
/* faster alternative . . . */
if ( MemErr ) { . . . process the error . . . }
ASM programs can check for return code values in the low word of the D0
register (with some exceptions).
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
MemError(void) TWOWORDINLINE(0x3EB8, 0x0220);

#if CALL_NOT_IN_CARBON

			/** 
			\brief Get address of the current heap zone 
			
			<pre>GetZone returns the address of the start of the current heap zone.
</pre>
 * \returns <pre>a 4-byte pointer; the address of a 62-byte Zone record for that
current active heap zone.
</pre>
 * \note <pre>Another method is to access the global variable TheZone (at 0x0118). For
instance, to change the number of master pointers to be allocated via
MoreMasters (i.e., modify a field of the current Zone structure), you
could use:
void MyMoreMasters( numMastPtrs )
short numMastPtrs;
{
shortoldMoreMast; /* saved value of moreMast */
oldMoreMast = TheZone -> moreMast;  /* get old value of moreMast */
TheZone -> moreMast = numMastPtrs; /* put the value we want in */
/* zone header */
MoreMasters (); /* allocate the master pointers */
TheZone -> moreMast = oldMoreMast;/* restore old val of moreMast */
}
Use SetZone to make a different zone active.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Find which heap zone owns relocatable block 
			
			<pre>HandleZone returns the address of the Zone structure at the base of the heap
zone that owns a specified relocatable memory block.
theHandle is a handle leading to a relocatable memory block; e.g., a value
obtained via NewHandle .
</pre>
 * \returns <pre>the address of a Zone structure. It identifies the heap zone that
contains the relocatable block addressed by theHandle .  Use
MemError to see if this return value is meaningful; it will return
an Error Code of:
noErr(0) No error
memWZErr (-111) Illegal operation on a free block
</pre>
 * \note <pre>If theHandle  is an empty handle (i.e., it points to a NIL master pointer),
then HandleZone will return a pointer to the current heap zone.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Find which heap zone owns a nonrelocatable block 
			\param    thePtr address of a nonrelocatable memory block
			<pre>Given the address of a nonrelocatable memory block, PtrZone tells you in
which heap zone that block resides.
thePtris the address of a nonrelocatable memory block; i.e., the value
obtained from a prior call to NewPtr .
</pre>
 * \returns <pre>the address of a Zone structure. It identifies the heap zone that
contains the relocatable block addressed by thePtr.  Use MemError
to see if this return value is meaningful; it will return an
Error Code of:
noErr(0) No error
memWZErr (-111) Illegal operation on a free block
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Get size of largest block (without compacting) 
			
			<pre>MaxBlock returns the size of the largest block that would be available if
heap compaction were to be performed, but does not actually perform the
time-consuming compaction.
</pre>
 * \returns <pre>a long integer; the size of largest block available after compaction.
</pre>
 * \note <pre>There is another routine, MaxBlockSys , which performs the equivalent
operation to MaxBlock , but in the System heap zone. It takes the same
parameters as MaxBlock .
This works a little like CompactMem , except that it does not actually
force heap compaction (compaction will be performed, if needed, when the
handle gets allocated anyway).
Use this before attempting an operation that will require allocation of
large blocks of memory. Note that a block larger than returned  may be
available; i.e., if a memory purge takes place.
If MaxBlock does not yield a large enough value, you could try
PurgeMem , (another fast operation), followed by MaxBlock and check
the result.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Obtain amount of unused space in the stack 
			
			<pre>StackSpace checks how close your application is to peril. It can also be used
before creating a heap zone in the stack (to squeeze a few extra bytes out of the
system). The return value is transient - the stack can grow a lot very
quickly.
</pre>
 * \returns <pre>a long integer; the amount of space between the base of the stack and
the current value of the stack pointer.
</pre>
 * \note <pre>One trick for getting some additional memory is to carve a zone out of the
bottom of the stack (at a place where the stack is not being used). The
default stack is about 8K, and it is best to leave at least 4K to 6K there. So
at most you can create about a 2K heap zone. Of course you should use
StackSpace beforehand, to check if this is a feasible approach.
One instance where you might need a temporary zone is in a routine to
handle a serious memory-full crunch. For instance, creating an alert or
dialog window takes some heap space. See InitZone for details of creating a
zone.
The global variables CurStackBase (at 0x0908) and MemTop (at 0x0108)
may be of some help.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Lock a handle's data area (keep it from moving) 
			
			<pre>HLock sets the lock attribute of a relocatable block, preventing it from being
moved during heap compaction. You should lock a handle before you dereference
it in order to access its data.
theHandle is a handle leading to a relocatable allocation block. It is typically a
value obtained via NewHandle .
</pre>
 * \returns <pre>none; the MemError function may return one of:
noErr(0) No error
nilHandleErr (-109) Illegal operation on an empty handle
memWZErr (-111) Illegal operation on a free block
</pre>
 * \note <pre>Many Toolbox functions end up compacting the heap, causing data to be
moved around. See About the Moves Memory Icon for more on
determining when memory may move. By default, new handles are not
locked and must be explicitly locked if you must prevent the data from being
moved. Thus, before accessing a handle's data area, be sure to lock the
handle; e.g.:
HandlemyHandle;
structmyStruct *msp;
short x;
Rect r;
myHandle = NewHandle ( sizeof(myStruct) );
HLock( myHandle );
msp = *myHandle; /* msp points to the data, but...*/
FrameRect ( &r ); /* this may move unlocked data...*/
x = msp->myField; /* making msp invalid */
HUnlock ( myHandle );
In the example above, the FrameRect function could cause a heap
compaction, so the value of msp (a pointer to the myHandle data area) could
become invalid. By surrounding the sequence with HLock and HUnlock ,
you ensure that all pointers to a handle's data area remain valid.
If you are certain that no heap manipulation will take place, or if you make
an effort to adjust for it, you need not lock the handle. For instance, in the
following sequence, the values of x and y are assigned via double
indirection, so even if FrameRect causes the data to move, it will be found
by both assignment statements.
myHandle = NewHandle ( sizeof(myStruct) );
x = (*myHandle)->myX; /* double indirection is valid even */
FrameRect ( &r );
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Unlock a handle's data (allowing it to be moved) 
			
			<pre>HUnlock undoes the effect of HLock. It removes the relocation lock on a
handle. In the event of a memory crunch, the Memory Manager will be able to
move the handle's data to make room for other allocation blocks.
theHandle is a handle leading to a relocatable memory block. It is typically a
value obtained from NewHandle .
</pre>
 * \returns <pre>none; the MemError function may return an Error Code of:
noErr(0) No error
nilHandleErr (-109) Illegal operation on an empty handle
memWZErr (-111) Illegal operation on a free block
</pre>
 * \note <pre>To avoid heap fragmentation (i.e., to keep as much of the heap available as
possible), use HUnlock as soon as possible after locking it via HLock. If
you expect the handle to be locked for a long time, use MoveHHi to place it
at the top of the heap, or use ResrvMem before allocating the handle to
place it near the bottom of the heap.
If the block is already unlocked (its default state upon allocation),
HUnlock does nothing.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Make a relocatable block purgeable 
			
			<pre>HPurge sets the purge attribute of a relocatable memory block so that in a
subsequent heap compaction, its data can be purged.
theHandle is a handle leading to a relocatable memory block. It is typically a
value obtained from NewHandle .
</pre>
 * \returns <pre>none; the MemError function may return an Error Code of:
noErr(0) No error
nilHandleErr (-109) Illegal operation on an empty handle
memWZErr (-111) Illegal operation on a free block
</pre>
 * \note <pre>If theHandle  is currently locked (see HLock), it will remain locked and
HPurge will have no effect until the handle is unlocked via HUnlock .
Thereafter, theHandle  will purged by the next general purge.
After a purge, all handles marked as purgeable will point to NIL master
pointers and their data area will be lost. Be very careful to check for such
empty handles before accessing the data, e.g.:
HandlemyHandle;
myHandle = NewHandle ( 1000 ); /* allocate space */
HPurge ( myHandle ); /* allow purge */
.
:
if ( *myHandle == 0 ) { /* data has been purged */
ReallocHandle ( myHandle, 1000 ); /* get some storage */
.
./* regenerate lost data; load resource, etc. */
.
}
HNoPurge ( myHandle ); /* don't allow purge now */
.
:
Use HNoPurge to undo the effect of this function (first be sure that the
handle hasn't been purged!).
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Disallow purging of relocatable data block 
			
			<pre>HNoPurge tags a handle as unpurgeable. If the handle is already unpurgeable
(the default for newly-allocated handles), this function has no effect.
theHandle is a handle leading to a relocatable memory block. It is typically a
value obtained from NewHandle .
</pre>
 * \returns <pre>none; the MemError function may return and Error Code of:
noErr(0) No error
nilHandleErr (-109) Illegal operation on an empty handle
memWZErr (-111) Illegal operation on a free block
</pre>
 * \note <pre>Use HNoPurge to reverse the effect of a previous call to HPurge . Take
care to check that theHandle  has not already been purged before calling this
function, e.g.:
HPurge ( myHandle ); /* allow purge */
.
:
if ( *myHandle == 0 ) { /* it got purged */
ReallocHandle ( myHandle, MYH_SIZE );
... regenerate the handle's data ...
}
HNoPurge ( myHandle );
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Allocate a new relocatable block of temporary memory 
			
			<pre>You use TempNewHandle to allocate a new relocatable block of temporary
memory. TempNewHandle returns a handle to a block of size Size. The first
parameter indicates how many bytes you wish the block to contain. The second
parameter contains the result code from the function call.
The resultCode parameter will return one of the following error codes:
noErr(0)No error
memFullErr (-108)Not enough memory
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Handle)
TempNewHandle(Size logicalSize, OSErr *resultCode)
    THREEWORDINLINE(0x3F3C, 0x001D, 0xA88F);


			/** 
			\brief Find the largest contiguous block available 
			
			<pre>TempMaxMem compacts the heap zone and returns the size of the largest
contiguous block available for temporary allocation.
growalways contains 0 after the function call because the temporary
memory does not come from the application's heap.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Size)
TempMaxMem(Size *grow) THREEWORDINLINE(0x3F3C, 0x0015, 0xA88F);


			/** 
			\brief Find out how much temporary memory is available 
			
			<pre>The TempFreeMem function returns the state of a page of logical memory.
Returns: the total amount of free memory available for temporary allocation
using TempNewHandle . The returned value is a long integer that
indicates the total number of bytes free.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Select a heap zone as the "current zone" 
			
			<pre>SetZone activates (makes current) a desired heap zone. Most Memory
Manager functions operate on the current heap zone.
heapZone is the address of a 64-byte Zone structure. It is either the
application zone (global variable ApplZone at 0x02AA), the system
heap (global variable SysZone at 0x02A6) or a value used as the
startPtr parameter in a previous call to InitZone .
</pre>
 * \returns <pre>none (call MemError to check for an error)
</pre>
 * \note <pre>As an expedient alternative to SetZone , you can simply store a THz
(pointer to a Zone structure) in the global variable TheZone (at 0x0118).
SetZone is needed by applications that maintain multiple heap zones, or in
the rare case where you may want to allocate an object in the system heap.
You may use SystemZone , or ApplicZone (or access the global variables
SysZone or ApplZone ) to obtain a valid value for heapZone . You can use
HandleZone or PtrZone to learn which zone owns a particular handle or
pointer.
For instance, to allocate some data in the system heap (which is guaranteed
to be there on a subsequent invocation of your application), you might use
the following sequence:
SetZone ( SystemZone () ); /*make system heap current*/
myHandle = (myType) NewHandle ( sizeof( myType) );
SetZone ( ApplicZone () ); /* application heap current */
(*myHandle)->myField = myValue; /* store a value in system heap */
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Install custom heap zone growing procedure 
			
			<pre>SetGrowZone installs a custom procedure that will be called after
exhausting all other avenues available for obtaining a requested block of
memory. This affects the current heap zone.
growProc is the address of a Pascal-style function in the format described
below. It can be as simple as displaying a message indicating "out of
memory" or complex, as in swapping data to disk and releasing
memory.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>This function does NOT set the grow zone - it sets the address of a function
into Zone.gzProc of the current heap zone.
The custom grow procedure should expect a Size (a.k.a. long) type
parameter on entry and should return a 32-bit long. It should be in the
following format:
pascal long MyGrowFn( Size bytesNeeded )
{
HandlesaveHandle;
saveHandle = GZSaveHnd ( ); /* always call this */
.
.Attempt to free or unlock memory . . .
.. . . but don't alter saveHandle
.
return( 0 ); /* zero if unable to free or unlock any memory */
return( 1 ); /* non-zero if able to make some progress */
}
/* Early in the program, install this procedure as follows */
SetZone ( whateverZone ); /* make desired zone current */
SetGrowZone ( MyGrowFn );
On entry, bytesNeeded  is the required amount of memory, including the
block header (i.e., the actual amount needed). The custom function should
attempt to find places where the application can economize; e.g., it can call
EmptyHandle to purge transient data or it can write important data to a
disk file (for later recovery) and mark the block as purgeable (see
HPurge ). It can also unlock ( HUnlock ) blocks, in the hope that this will
unfragment the heap, thus freeing a larger block.
Note: a single handle, the "grow zone root" handle should not be disturbed
by your function. See GZSaveHnd .
On exit, the grow-zone function should return 0 if it was unable to free or
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Obtain the size of a nonrelocatable memory block 
			\param    thePtr address of a nonrelocatable memory block
			<pre>GetPtrSize returns the size, in bytes of a specified nonrelocatable memory
block.
thePtris the address of a nonrelocatable memory block; i.e., the value
obtained from a prior call to NewPtr .
</pre>
 * \returns <pre>a 32-bit long; the current size of the memory block. This will
always be less than 8MB (a 24-bit value).
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Get the size of a Handle's data area 
			
			<pre>GetHandleSize returns the size, in bytes of a relocatable block of memory.
theHandle is a Handle, leading to a relocatable block of memory.
</pre>
 * \returns <pre>the size of the data led to by a Handle (a 32-bit long), 0 may
indicate an error occurred. The MemError function may return an
Error Code of:
noErr(0) No error
nilHandleErr (-109) Illegal operation on empty handle
memWZErr (-111) Illegal operation on a free block
</pre>
 * \note <pre>You can use GetHandleSize to determine the size of objects (such as
pictures) that may exceed the 64K or 32K maximum value of their
historically-defined size.
The returned value is the size of the allocated area available for data
storage. The actual memory used by a Handle includes a block header and up
to 12 bytes of filler.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Tag block for treatment as a resource 
			
			<pre>HSetRBit sets bit 7 of the tag byte of a master pointer. This is normally
used internally by the Resource Manager, to mark the block for special
treatment as a resource.
theHandle is a handle leading to a relocatable memory block.
</pre>
 * \returns <pre>none; the MemError function may return an Error Code of:
noErr(0) No error
nilHandleErr (-109) theHandle has a NIL master pointer
memWZErr (-111) Illegal operation on a free block
</pre>
 * \note <pre>Rather than manipulating the high byte (the tag byte) of a master pointer,
it is wise to use Memory Manager functions such as HLock and HPurge .
Failure to use these routines virtually guarantees incompatibilities with
future System Software.
If you need to manipulate the tag byte, you should use HGetState and
HSetState to save and restore the original tag values.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Clear relocatable block's resource tag 
			
			<pre>HClrRBit clears bit 7 of the tag byte of a master pointer. This is normally
used internally by the Resource Manager, to indicate that the block should not
receive special treatment as a resource.
theHandle is a handle leading to a relocatable memory block.
</pre>
 * \returns <pre>none; the MemError function may return one of:
noErr(0) No error
nilHandleErr (-109) theHandle  has a NIL master pointer
memWZErr (-111) Illegal operation on a free block
</pre>
 * \note <pre>Rather than manipulating the high byte (the tag byte) of a master pointer,
it is wise to use Memory Manager functions such as HLock and HPurge .
If you need to manipulate the tag byte, you should use HGetState and
HSetState to save and restore the original tag values.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Obtain the value of a relocatable block's tag byte 
			
			<pre>HGetState lets you examine or save the current value of a relocatable block's
master pointer tag byte. It includes the lock, purge, and resource attributes of
the block.
theHandle is a handle leading to a relocatable memory block.
</pre>
 * \returns <pre>a byte; the current tag settings for theHandle  (as with all C char
return values, this is actually a 16-bit value, with the low 8 bits
significant).  See HSetState for the bit layouts. The MemError
function may return an Error Code of:
noErr(0) No error
nilHandleErr (-109) theHandle  has a NIL master pointer
memWZErr (-111) Illegal operation on a free block
</pre>
 * \note <pre>Rather than manipulating the high byte (the tag byte) of a master pointer,
it is wise to use Memory Manager functions such as HLock and HPurge .
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Copy memory from one place to another 
			\param    srcPtr address of data to move
	\param    destPtr address to move it to
			<pre>BlockMove copies a block of memory from one place to another. It works
correctly, even if the source and destination overlap.
srcPtris the address of the beginning of the block to copy.
destPtris the address at which to copy the block.
byteCount specifies the length of the block to copy. As a Size data type, it
should be positive and less than 8MB (a 24-bit value).
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>This is a generalized block-move or block-copy operation that, for
medium to large blocks, is much faster than writing a loop in C. Also,
BlockMove can handle overlapping data areas.
For instance, the following example inserts one byte into the front of a
30-byte buffer:
chartheBuf[30];
BlockMove ( &theBuf[0], &theBuf[1], 29 );
theBuf[0]='A';
Several higher-level tools exist for copying specific types of data:
HandToHand create handle and copy handle data to it
PtrToHand create handle and copy arbitrary data to it
PtrToXHand copy arbitrary data to an existing handle
HandAndHand concatenate handle data to another handle
PtrAndHand concatenate arbitrary data to end of handle
SetString copy handle data to a pascal-style string
PackBits move and compress binary data
Munger insert/replace data (usually text)
GetScrap copy data from the scrap to a handle
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Expand application heap to largest possible value 
			
			<pre>MaxApplZone expands the application heap zone to include all available heap
memory. It does not purge any current blocks in the application heap.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>MaxApplZone is commonly called early in the application, followed by a
call to MoreMasters (if necessary).
If you are using multiple heap zones, be sure to call InitZone to create
these zones before calling MaxApplZone .
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Change the size of the application heap zone 
			
			<pre>SetApplLimit sets the size of the application heap by selecting the address
beyond which it may not expand.
limitPtr is an address. It specifies an address one byte beyond the desired end
of the application heap zone. If the heap has already grown beyond
this limit, the current size is used instead.
</pre>
 * \returns <pre>none; the MemError function may return an Error Code of:
noErr(0) No error
memFullErr (-108) Can't expand that far
</pre>
 * \note <pre>SetApplLimit expands/contracts only the application heap zone (not any
additional zones created via InitZone ). The new limit is stored in the
global variable ApplLimit (at 0x0130).
You might call GetApplLimit before making this call, then add a specified
amount to the return value. e.g., to increase the current size by 16K, use:
SetApplLimit ( GetApplLimit () - 16384 );
Note that you need to subtract (not add) to increase the size of the stack. A
more common operation is to call MaxApplZone early in your program to
provide the largest possible size for the application heap.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Lock a specified relocatable block of temporary memory 
			
			<pre>You can use TempHLock to lock a specified relocatable block of temporary
memory, thereby preventing it from being moved within the heap zone.
The resultCode parameter will return one of the following error codes:
noErr(0)No error
nilHandleErr (-109)Nil master pointer
memWZErr (-111)Attempt to operate on a free block
</pre>
 * \note <pre> In system 7.0, you can use the Memory Manager routine HLock to lock
temporary memory blocks.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
TempHLock(Handle h, OSErr *resultCode) THREEWORDINLINE(0x3F3C, 0x001E, 0xA88F);


			/** 
			\brief Unlock a block of temporary memory 
			
			<pre>You can use TempHUnlock to unlock a block of temporary memory. Once it
is unlocked, that block is allowed to move memory locations as needed to
compact the heap.
The resultCode parameter will return one of the following error codes:
noErr(0)No error
nilHandleErr (-109)Nil master pointer
memWZErr (-111)Attempt to operate on a free block
</pre>
 * \note <pre> Under system 7.0, you can use the Memory Manager routine HUnlock
to unlock temporary memory blocks.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
TempHUnlock(Handle h, OSErr *resultCode)
    THREEWORDINLINE(0x3F3C, 0x001F, 0xA88F);


			/** 
			\brief TempDisposeHandle Release the memory occupied by a temporary block 
			
			<pre>You can use TempDisposeHandle to release the memory occupied by a
relocatable temporary memory block.
The resultCode parameter will return one of the following error codes:
noErr(0)No error
memWZErr (-111)Attempt to operate on a free block
</pre>
 * \note <pre> In system 7.0, you can use the Memory Manager routine
DisposHandle to free temporary memory blocks.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
TempDisposeHandle(Handle h, OSErr *resultCode)
    THREEWORDINLINE(0x3F3C, 0x0020, 0xA88F);


			/** 
			\brief Get address of top of application's memory partition 
			
			<pre>TempTopMem returns a pointer to the top of your application's memory
partition. Don't use this call to calculate the size of your application's memory
partition.
</pre>
 * \returns <pre>pointer to top of application memory.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Ptr)
TempTopMem(void) THREEWORDINLINE(0x3F3C, 0x0016, 0xA88F);


			/** 
			\brief Make part of the address space resident in memory 
			
			<pre>The HoldMemory function makes a portion of the address space resident in
physical memory and ineligible for paging.
address is the start address of the range of memory that is to be held
in RAM
count is the size in bytes of that range.
Returns: an operating system Error Code .
noErr(0)No error
paramErr (-50)Error in parameter list
notEnoughMemoryErr (-620)Insufficient physical memory
interruptsMaskedErr (-624)Called with interrupts masked
</pre>
 * \note <pre>If the starting address parameter supplied to the HoldMemory function is
not on a page boundary, then it is rounded down to the nearest page
boundary. Similarly, if the specified range does not end on a page boundary,
the count parameter is rounded up so that the entire range of memory is
held.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Make part of the address space eligible for paging 
			
			<pre>The UnholdMemory function makes eligible for paging again a portion of the
address space that is currently held. This function reverses the effects of
HoldMemory .
address is the start address of the range of memory that is to be let
go.
count is the size in bytes of that range.
Returns: an operating system Error Code .
noErr(0)No error
paramErr (-50)Error in parameter list
notHeldErr (-621)Specified range of memory is not held
interruptsMaskedErr (-624)Called with interrupts masked
</pre>
 * \note <pre>If the starting address parameter supplied to the UnholdMemory
function is not on a page boundary, then it is rounded down to the nearest
page boundary. Similarly, if the specified range does not end on a page
boundary, the count parameter is rounded up so that the entire range of
memory is let go.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Make part of the address space immovable 
			
			<pre>The LockMemory function makes a portion of the address space immovable
in physical memory and ineligible for paging.
address is the start address of the range that is to be locked in RAM
count is the size in bytes of that range.
Returns: an operating system Error Code .
noErr(0)No error
paramErr (-50)Error in parameter list
notEnoughMemoryErr (-620)Insufficient physical memory
interruptsMaskedErr (-624)Called with interrupts masked
</pre>
 * \note <pre>If the starting address parameter supplied to the LockMemory function is
not on a page boundary, then it is rounded down to the nearest page
boundary. Similarly, if the specified range does not end on a page boundary,
the count parameter is rounded up so that the entire range of memory is
locked. Locked pages are marked noncacheable by the CPU.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief LockMemoryContiguous Make a contiguous block of the address space immovable 
			
			<pre>The LockMemoryContiguous function is exactly like the LockMemory
function, except that it attempts to obtain a contiguous block of physical
memory associated with the logical address range specified.
address is the start address of the range that is to be locked in RAM
count is the size in bytes of that range.
Returns: an operating system Error Code .
noErr (0) No error
paramErr (-50) Error in parameter list
notEnoughMemoryErr (-620) Insufficient physical memory
cannotMakeContiguousErr (-622) Cannot make specified range contiguous
interruptsMaskedErr (-624) Called with interrupts masked
</pre>
 * \note <pre>If the starting address parameter supplied to the
LockMemoryContiguous function is not on a page boundary, then it is
rounded down to the nearest page boundary. Similarly, if the specified range
does not end on a page boundary, the count parameter is rounded up so that
the entire range of memory is locked. Locked pages are marked noncacheable
by the CPU.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Make a block of the address space movable 
			
			<pre>The UnlockMemory function makes a portion of the address space movable
in real memory and eligible for paging again. It undoes the effects of both
LockMemory and LockMemoryContiguous .
address is the start address of the range that is to be unlocked
count is the size in bytes of that range.
Returns: an operating system Error Code .
noErr (0) No error
paramErr (-50) Error in parameter list
notLockedErr (-623) Specified range of memory is not locked
interruptsMaskedErr (-624) Called with interrupts masked
</pre>
 * \note <pre>If the specified address is not on a page boundary, it is rounded down to the
nearest page boundary. Similarly, if the specified range does not end on a
page boundary, the length parameter is rounded up so that the entire range
of memory is unlocked..
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Translate logical addresses to physical ones 
			
			<pre>The GetPhysical function translates logical addresses into their
corresponding physical addresses.
addresses is a translation table, that is, an array of ordered pairs
(address and count).
physicalEntryCount specifies the number of physical entries to translate.
Returns: an operating system Error Code .
noErr (0) No error
paramErr (-50) Error in parameter list
notLockedErr (-623) Specified range of memory is not locked
interruptsMaskedErr (-624) Called with interrupts masked
</pre>
 * \note <pre>GetPhysical translates up to the size of the table or until the translation
is completed, whichever comes first. If GetPhysical is called with a table
size of 0, the number of table entries needed to translate the entire address
range is returned. On exit from this function, the virtual information is
updated to indicate the next virtual address and the number of bytes left to
translate. The logical address range must be locked to ensure validity of the
translation data.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Can code that might cause page faults be called safely? 
			
			<pre>You can use the DeferUserFn function to determine whether code that might
cause page faults can safely be called immediately. If the code can be called
safely, then it is called. If a page fault is in progress, however, the routine
address and its parameter are saved, and the routine is deferred until page
faults are again permitted.
userFunction is the address of the routine that you want to run
argument is a pointer to the argument to pass to the specified
routine.
Returns: an operating system Error Code .
noErr (0) No error
cannotDeferErr (-625)Unable to defer additional user functions
</pre>
 * \note <pre>The specified routine is called with register A0 containing the value of the
argument parameter to the DeferUserFn call. Note that the routine can be
called immediately (before returning to the caller of DeferUserFn ).
Deferred functions must follow the register conventions used by interrupt
handlers: they may use registers A0-A3 and D0-D3, and must restore all
other registers used.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Get the highest function number supported 
			
			<pre>The DebuggerGetMax function returns a long integer indicating the highest
function number supported by the DebugUtil trap.
</pre>
 * \note <pre>The returned value is the highest selector number of the debugger
functions that are defined in terms of the DebugUtil trap. See the section,
Debugger Support Under Virtual Memory for a complete list of
these numbers.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Enter the debugger state 
			
			<pre>The two procedures DebuggerEnter and DebuggerExit allow you to enter
and exit the debugger state. These calls allow the DebugUtil trap to make
preparations for subsequent debugging calls and to clean up after all debugging
calls are completed.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
DebuggerEnter(void) TWOWORDINLINE(0x7001, 0xA08D);


			/** 
			\brief Exit the debugger state 
			
			<pre>The two procedures DebuggerEnter and DebuggerExit allow you to enter
and exit the debugger state. These calls allow the DebugUtil trap to make
preparations for subsequent debugging calls and to clean up after all debugging
calls are completed.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
DebuggerExit(void) TWOWORDINLINE(0x7002, 0xA08D);


			/** 
			\brief Poll for keyboard input 
			
			<pre>A debugger can use the DebuggerPoll procedure to poll for keyboard
input.The DebuggerPoll procedure can be used even if interrupts are
disabled.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
DebuggerPoll(void) TWOWORDINLINE(0x7003, 0xA08D);


			/** 
			\brief Get the state of a page of logical memory 
			
			<pre>The GetPageState function returns the state of a page of logical memory.
address specifies an address in the page whose state you want to
determine.
Returns: a constant:
kPageInMemory //page is in RAM
kPageOnDisk //page is on disk
kNotPaged //address is not paged
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Capture all bus errors? 
			
			<pre>A debugger can use the PageFaultFatal function to determine whether it
should capture all bus errors or whether it is safe to allow them to flow
through to virtual memory. When paging is safe, the debugger can allow
virtual memory to continue to service page faults, thus allowing the user to
view all of memory.
</pre>
 * \note <pre>If this function returns TRUE, then the debugger should not allow the
virtual memory's bus error handler to detect any page faults.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief DebuggerLockMemory Make part of the address space immovable 
			
			<pre>The DebuggerLockMemory function performs the same operations as
LockMemory , except that it leaves data caching enabled on the affected
pages.
address is the start address of the range that is to be locked in RAM
countis the size in bytes of that range
Returns: an operating system Error Code .
noErr (0) No error
paramErr (-50)Error in parameter list
notEnoughMemoryErr (-620)Insufficient physical memory
</pre>
 * \note <pre>If the starting address parameter supplied to the DebuggerLockMemory
function is not on a page boundary, then it is rounded down to the nearest
page boundary. Similarly, if the specified range does not end on a page
boundary, the length parameter is rounded up so that the entire range of
memory is locked.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief DebuggerUnlockMemory Make part of the address space movable 
			
			<pre>The DebuggerUnlockMemory function reverses the effects of
DebuggerLockMemory .
address is the start address of the range that is to be unlocked in
RAM
countis the size in bytes of that range
Returns: an operating system Error Code .
noErr (0) No error
paramErr (-50)Error in parameter list
notLockedErr (-623)Specified range of memory is not locked
</pre>
 * \note <pre>DebuggerUnlockMemory makes the portion of the address space
starting with address and continuing for count bytes movable in physical
memory and eligible for paging again. Unlocking is applied to whole pages of
the virtual address space. Unlocked pages are marked as cacheable.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief EnterSupervisorMode Switch caller into supervisor mode 
			
			<pre>accomplish this with EnterSupervisorMode .
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Strip the high order byte off an address if running in 24 bit mode 
			
			<pre>StripAddress will clear the high order byte of an address if the machine is
running in 24 bit mode. This action is identical in function to the global
variable Lo3Bytes . However, if the machine is running in 32 bit mode, the
address is returned unchanged.
addressthe address to be stripped.
</pre>
 * \returns <pre>the new, stripped address.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Translate 24-bit addresses into the 32-bit address space 
			
			<pre>You can use the Translate24To32 function to translate 24-bit addresses
into the 32-bit address space.
Unlike the StripAddress function, this function does not necessarily return
an address that is meaningful to the 24-bit
Memory Manager .
addr24the address to be translated.
</pre>
 * \returns <pre>the new, translated address.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
			\brief Create new Handle and copy Handle data to it 
			
			<pre>HandToHand creates a new Handle (see NewHandle ) and copies data from an
existing Handle into the new one.
theHandle is the address of an existing Handle. On entry, it is a Handle leading
to data you wish to copy. On return, it is overwritten by a
newly-created Handle that leads to a relocatable block containing a
copy of the data.
</pre>
 * \returns <pre>an OSErr; an integer Error Code . It will be one of:
noErr(0) No error
memFullErr (-108) Not enough room in heap for new Handle
nilHandleErr (-109) theHandle was invalid on entry
memWZErr (-111) Attempt to operate on a free block
</pre>
 * \note <pre>Since HandToHand cleverly overwrites the original value of theHandle ,
the normal technique is to make a copy of the original before the call; e.g:
HandlesrcHandle, destHandle;
srcHandle= GetResource ( 'CURS', watchCursor );
destHandle = srcHandle;
if ( HandToHand ( &destHandle ) ) {
. . . an error occurred . . .
}. . . else, a copy of watchCursor is now in destHandle . . .
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
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
*/ter
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
*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/