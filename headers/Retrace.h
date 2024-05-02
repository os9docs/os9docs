/**
	 \file       Retrace.h

	\brief   Vertical Retrace Interfaces.

	\introduced_in  System 7.5
	\avaliable_from Universal Interfaces 3.4.1

	\copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

	\ingroup Misc

	For bug reports, consult the following page on
				 the World Wide Web:

					 http://developer.apple.com/bugreporter/

*/
#ifndef __RETRACE__
#define __RETRACE__

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

	typedef struct VBLTask VBLTask;
	typedef VBLTask *VBLTaskPtr;
	typedef CALLBACK_API_REGISTER68K(void, VBLProcPtr, (VBLTaskPtr vblTaskPtr));
	typedef REGISTER_UPP_TYPE(VBLProcPtr) VBLUPP;
	/**
	<pre>
	 * \note <pre>The VBLTask structure is used in calls to VInstall and VRemove .
	The vblAddr field is the address of a routine to be called during the vertical
	retrace blanking interrupt. See VInstall for guidelines in writing such a
	routine.
	The vblCount value is the number of ticks to skip between calls to the
	routine whose address is in vblAddr. Each 16.66 ms (1/60-th of a
	second), this field is decremented. When it reaches 0, the VBL task routine
	is called. The task routine is responsible for setting this back to a non-zero
	value to restart the timing cycle. If left at 0, the task is removed from the
	queue.
	In the event that you add more than one VBL task at the same time, and both
	have the same vblCount interval, you may want them to to be executed on
	different ticks (so as not to load up the system too much). In that case, set
	vblPhase to some non-zero value (but less than vblCount) in the second and
	subsequent VBLTasks which you install.
	A call to GetVBLQHdr returns the address of a QHdr which contains a
	pointer to the first of the VBLTask structures in the vertical retrace task
	queue. Or you can simply examine the global variable VBLQueue (at
	0x0160).
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct VBLTask
	{
		QElemPtr qLink;	 /**<  Address of next item in VBL task list*/
		short qType;	 /**<  Queue type (always vType = )*/
		ProcPtr vblAddr; /**<  Address of routine to process the*/
		short vblCount;	 /**<  Number of /th-sec ticks*/
		short vblPhase;	 /**<  Phase offset for multiple tasks*/
	} VBLTask;			 /**< */

#if CALL_NOT_IN_CARBON
	/**
	 *  NewVBLUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	VBLUPP
	NewVBLUPP(VBLProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppVBLProcInfo = 0x00009802
	}; /* register no_return_value Func(4_bytes:A0) */
#ifdef __cplusplus
	inline VBLUPP NewVBLUPP(VBLProcPtr userRoutine)
	{
		return (VBLUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppVBLProcInfo,
											GetCurrentArchitecture());
	}
#else
#define NewVBLUPP(userRoutine)                                            \
	(VBLUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppVBLProcInfo, \
								  GetCurrentArchitecture())
#endif
#endif

	/**
	 *  DisposeVBLUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposeVBLUPP(VBLUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeVBLUPP(VBLUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposeVBLUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeVBLUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeVBLUPP(__A0, __A1)
#endif
	void
	InvokeVBLUPP(VBLTaskPtr vblTaskPtr, VBLUPP userUPP) ONEWORDINLINE(0x4E91);
#if !OPAQUE_UPP_TYPES && \
	(!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
	inline void InvokeVBLUPP(VBLTaskPtr vblTaskPtr, VBLUPP userUPP)
	{
		CALL_ONE_PARAMETER_UPP(userUPP, uppVBLProcInfo, vblTaskPtr);
	}
#else
#define InvokeVBLUPP(vblTaskPtr, userUPP) \
	CALL_ONE_PARAMETER_UPP((userUPP), uppVBLProcInfo, (vblTaskPtr))
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewVBLProc(userRoutine) NewVBLUPP(userRoutine)
#define CallVBLProc(userRoutine, vblTaskPtr) \
	InvokeVBLUPP(vblTaskPtr, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON

	/**
	\brief Get the address of the VBL queue header

	<pre>Use GetVBLQHdr if you want to examine the queue of vertical retrace tasks.
</pre>
* \returns <pre>a 32-bit QHdrPtr (the address of a 10-byte QHdr structure). The
qHead field of that structure points to a VBL queue element (a
VBLTask structure).
</pre>
* \note <pre>C programmers may prefer to access the global variable VBLQueue (at
0x0160).
Apple tells us that bit 6 of the VBLTask.qFlags is set if any of the VBL tasks
are currently executing. Thus:
VBLTask *qep;
printf( "a VBL task %s executing\n",
(VBLQueue .qHead & 0x40) ? "IS" : "IS NOT");
qep = (VBLTask *)VBLQueue .qHead; /* get global variable */
	while (qep != 0)
	{
		printf("Task at %lx has %d ticks to go\n", qep, qep->vblCount);
		qep = qep->qLink;
	}
	</ pre>
				* \copyright THINK Reference © 1991 - 1992 Symantec Corporation
														  *    \non_carbon_cfm in InterfaceLib 7.1 and
		later
				*    \carbon_lib not available *    \mac_os_x not available *
			/
			QHdrPtr
			GetVBLQHdr(void) THREEWORDINLINE(0x2EBC, 0x0000, 0x0160);

	/**
	\brief Install vertical retrace interrupt task for a slot

	<pre>SlotVInstall sets up to perform a task periodically. It installs an element
into the vertical retrace task queue of a particular slot. The task will be
executed whenever that device's vertical retrace interrupt occurs.
vblTaskPtr is the address of a 14-byte VBLTask structure. You must initialize
the fields of the structure before making the call.
theSlotis the slot number of the slot whose queue the task should be
installed in. You can use the Slot Manager routine SGetSRsrc to
index through all the slots on a particular machine.
</pre>
* \returns <pre>an error return code indicating success or failure of the function. It
will be one of:
noErr(0) No error
vTypErr (-2) Invalid queue element
slotNumErr (-360) Invalid slot number
</pre>
* \note <pre>Instead of maintaining a single vertical retrace queue, the
Vertical Retrace Manager maintains a separate queue for each video
device; associated with that queue is the rate at which the device's vertical
retrace interrupt occurs. When interrupts occur for a particular video
slot, the Vertical Retrace Manager executes any tasks in the queue for
that slot.
See VInstall for more information on writing tasks that need to execute
periodically and a code example which demonstrates the installation of a VBL
Task.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SlotVInstall(__A0, __D0)
#endif
	OSErr
	SlotVInstall(QElemPtr vblBlockPtr, short theSlot) ONEWORDINLINE(0xA06F);

	/**
	\brief Remove vertical retrace interrupt task for a slot

	<pre>SlotVRemove removes a previously-installed vertical retrace task from the
VBL queue for a particular slot and stops the task from being executed on
subsequent retrace interrupts.
vblTaskPtr is the address of a 14-byte VBLTask structure you installed
previously via SlotVInstall .
theSlotis the slot number of the slot whose queue the task should be
removed from. You can use the Slot Manager routine SGetSRsrc
to index through all the slots on a particular machine.
</pre>
* \returns <pre>an Error Code indicating success or failure of the function. It will
be one of:
noErr(0) no error
qErr(-1) Invalid queue element
slotNumErr (-360) Invalid slot number
</pre>
* \note <pre>Instead of maintaining a single vertical retrace queue, the
Vertical Retrace Manager maintains a separate queue for each video
device; associated with that queue is the rate at which the device's vertical
retrace interrupt occurs. When interrupts occur for a particular video
slot, the Vertical Retrace Manager executes any tasks in the queue for
that slot.
It is probably NOT wise to remove tasks you did not install.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SlotVRemove(__A0, __D0)
#endif
	OSErr
	SlotVRemove(QElemPtr vblBlockPtr, short theSlot) ONEWORDINLINE(0xA070);

	/**
	\brief Make specified slot the primary video slot

	<pre>AttachVBL makes theSlot the primary video slot, allowing correct cursor
updating.
theSlotis the slot number of the slot to be made the primary video slot.
You can use the Slot Manager routine SGetSRsrc to index through
all the slots on a particular machine.
</pre>
* \returns <pre>an Error Code indicating success or failure of the function. It will
be one of:
noErr(0) no error
slotNumErr (-360) Invalid slot number
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 AttachVBL(__D0)
#endif
	OSErr
	AttachVBL(short theSlot) ONEWORDINLINE(0xA071);

	/**
	\brief Execute VBL tasks in the queue for a specified slot

	<pre>DoVBLTask causes any VBL tasks in the queue for a specified slot to be
executed. If the specified slot is the primary video slot, the position of the
cursor will also be updated.
theSlotis the slot number of the slot whose tasks should be executed. You
can use the Slot Manager routine SGetSRsrc to index through all
the slots on a particular machine.
</pre>
* \returns <pre>an Error Code indicating success or failure of the function. It will
be one of:
noErr(0) no error
slotNumErr (-360) Invalid slot number
</pre>
* \note <pre>Instead of maintaining a single verticle retrace queue, the
Vertical Retrace Manager maintains a separate queue for each video
device; associated with that queue is the rate at which the device's vertical
retrace interrupt occurs. When interrupts occur for a particular video
slot, the Vertical Retrace Manager executes any tasks in the queue for
that slot.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 DoVBLTask(__D0)
#endif
	OSErr
	DoVBLTask(short theSlot) ONEWORDINLINE(0xA072);

	/**
	\brief Install vertical retrace interrupt task

	<pre>VInstall sets up to perform a task periodically. It installs an element into
the vertical retrace task queue that will be executed as often as 60 times per
second.
vblTaskPtr is the address of a 14-byte VBLTask structure. You must initialize
the fields of the structure before making the call.
</pre>
* \returns <pre>an error return code indicating success or failure of the function. It
will be one of:
noErr(0) No error
vTypErr (-2) VBLTask.qType must be vType
</pre>
* \note <pre>The VBL (Vertical BLanking) interrupt occurs 60.15 times per second.
Orginally, on the Macintosh Plus, this corresponded to the period when the
video display beam was sweeping back up to the top of the screen after each
refresh of the screen image. This 1/60-th second interval is often called a
"tick" and occurs once every 16.66 ms.
With the advent of slots, a variety of screens are available, each with a
potentially vertical retrace period. A slot-specific version of VInstall ,
SlotVInstall is now available. You should use SlotVInstall if you are
trying to synchronize the execution of a task with the refresh rate of a
particular device. VInstall is still useful as a way of performing periodic
tasks based on ticks, though. A special system-generated interrupt that
occurs 60.15 times per second handle the execution of tasks installed via
VInstall .
The system initially installs its own set of VBL tasks, including code to
move the mouse cursor, post disk-insert events, and the task that updates
the Ticks variable. (Note that if you wait until this variable changes, and
then take action quickly, you can draw smooth animation on the screen).
Before calling VInstall , you must prepare all fields of the VBLTask
structure except for the qLink field:
qType Set this to vType (defined as 1 in OSUtil.h)
vblAddr Address of the routine to be executed.
vblCount Number of 1/60-th second (16.66ms) intervals to pass
between calls. ( Note: This gets decremented to 0 before your
VBL task gets called. If you want to get another timeslice, you
must set this back each time.)
vblPhase Ticks to skip before installing this task (usually 0). This is
needed if you install several tasks and wish them to take place at
different ticks (to avoid overloading the system).
The code of the task is executed at interrupt time , and so must be
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 VInstall(__A0)
#endif
	OSErr
	VInstall(QElemPtr vblTaskPtr) ONEWORDINLINE(0xA033);

	/**
	\brief Remove vertical retrace interrupt task

	<pre>VRemove removes a previously-installed vertical retrace task from the VBL
queue and stops the task from being executed on subsequent retrace interrupts.
vblTaskPtr is the address of a 14-byte VBLTask structure you installed
previously via VInstall .
</pre>
* \returns <pre>an Error Code indicating success or failure of the function. It will
be one of:
noErr(0) no error
qErr(-1) No such task exists
vTypErr (-2) VBLTask.qType must be vType
</pre>
* \note <pre>It is probably NOT wise to remove tasks you did not install.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 VRemove(__A0)
#endif
	OSErr
	VRemove(QElemPtr vblTaskPtr) ONEWORDINLINE(0xA034);

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

#endif /* __RETRACE__ */
* /*/*/ * /*/*/ * /