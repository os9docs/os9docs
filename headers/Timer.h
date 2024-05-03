/**
	 \file       Timer.h

	\brief   Time Manager interfaces.

	\introduced_in  Mac OS 8.5
	\avaliable_from Universal Interfaces 3.4.1

	\copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

	\ingroup System

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

	enum
	{
		// high bit of qType is set if task is active 		kTMTaskActive = (1L << 15)
	};

	typedef struct TMTask TMTask;
	typedef TMTask *TMTaskPtr;
	typedef CALLBACK_API_REGISTER68K(void, TimerProcPtr, (TMTaskPtr tmTaskPtr));
	typedef REGISTER_UPP_TYPE(TimerProcPtr) TimerUPP;
	/**
	<pre>
	 * \note <pre>The TMTask structure is used in calls to InsTime , PrimeTime , and
	RmvTime .
	Time Manager tasks are stored in a standard Operating System queue
	The qType field is undefined and apparently remains unchanged from its
	setting when you call InsTime .
	The tmAddr field is the address of the routine which will get control after
	the interval specified in a call to PrimeTime . Refer to that function for
	information on the various requirements you must follow when writing a
	Time Manager task routine.
	The tmCount field is set in the PrimeTime call and is decremented every
	millisecond (1/1000 second) thereafter, until it reaches 0-at which time
	the routine whose address is in tmAddr is called.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TMTask
	{
		QElemPtr qLink;	 /**< Address of next element in the queue*/
		short qType;	 /**< Queue Type (value is undocumented)*/
		ProcPtr tmAddr;	 /**< Addr of routine to get control at requested*/
		short tmCount;	 /**< Time in milliseconds until end of interval*/
		long tmWakeUp;	 /**< */
		long tmReserved; /**< */
	} TMTask;			 /**< */

	/**
	\brief Install timer task

	<pre>Trap macro _InsTime
On entry A0:address of TMTask record
On exit D0:result code
InsTime adds the Time Manager task record specified by tmTaskPtr to the
Time Manager queue. Your application should fill in the tmAddr field of the
task record and should set the remaining fields to 0. The tmTaskPtr parameter
must point to an original Time Manager task record.
With the revised and extended Time Managers, you can set tmAddr to NIL if
you do not want a task to execute when the delay passed to PrimeTime
expires. Also, calling InsTime with the revised Time Manager causes the
high-order bit of the qType field to be reset to 0.
InsTime enqueues a data structure in preparation for a subsequent call to
PrimeTime , which starts the clock ticking on a timer-alarm triggered task.
After the alarm goes off, your task is still in the Time Manager queue, but it
is no longer primed.
Use the InsXTime procedure if you want to take advantage of the drift-free,
fixed-frequency timing services of the extended
Time Manager .
tmTaskPtr is the address of a 12-byte TMTask structure. You must set the
tmAddr field of this structure to point to the code you wish executed
when the alarm is triggered. Other fields are set automatically.
</pre>
* \returns <pre>none
</pre>
* \note <pre> Time Manager alarms have resolution of 1ms (1/1000th of
a second). You may enqueue any number of these "wakeup" requests. None
takes effect until you call PrimeTime and the specified interval elapses.
The code of the timer task is executed at interrupt time, so it must be
written with the following constraints:
•It must not call Memory Manager functions directly or indirectly .
You cannot call any Toolbox routine that may move or purge
memory.Note: it is OK to call PrimeTime to set up for another alarm.
•It must not depend on handles of unlocked memory blocks to be valid.
•It must preserve the values of all registers except A0-A3 and D0-D3.
•If it accesses application globals, it must be sure that the A5 register
is valid.
The latter requirement is important. At interrupt time, you cannot depend
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InsTime(__A0)
#endif
	void
	InsTime(QElemPtr tmTaskPtr);

	/**
	\brief Install extended Time Manager  task

	<pre>Trap macro _InsXTime
On entry A0:address of TMTask record
On exit D0:result code
InsXTime adds the Time Manager task record specified by tmTaskPtr to
the Time Manager queue. The tmTaskPtr parameter must point to an
extended Time Manager task record. Your application must fill in the tmAddr
field of that task. You should set the tmWakeUp and tmReserved fields to 0 the
first time you call InsXTime .
With the extended Time Manager , you can set tmAddr to NIL if you do not
want a task to execute when the delay passed to PrimeTime expires. Also,
InsXTime resets the high-order bit of the qType field to 0.
The PrimeTime procedure schedules the routine specified by the tmAddr
field of tmTaskPtr for execution after the delay specified by the count
parameter has elapsed.
</pre>
* \returns <pre>none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InsXTime(__A0)
#endif
	void
	InsXTime(QElemPtr tmTaskPtr);

	/**
	\brief Set interval for timer and start it ticking

	<pre>Trap macro _PrimeTime
On entry A0:address of TMTask record
D0:specified delay time (long)
On exit D0:result code
PrimeTime starts the clock ticking on a timer-alarm triggered task
previously prepared by means of a call to InsTime .
If the count parameter is a positive value, it is interpreted in milliseconds. If
count is a negative value, it is interpreted in negated microseconds.
(Microsecond delays are allowable only in the revised and extended Time
Managers.) The task record specified by tmTaskPtr must already be inserted
into the queue (by a previous call to InsTime or InsXTime ) before your
application calls the PrimeTime procedure. The PrimeTime procedure
returns immediately, and the specified routine is executed after the specified
delay has elapsed. If you call PrimeTime with a time delay of 0, the
procedure runs as soon as interrupts are enabled.
In the revised and extended Time Managers, PrimeTime sets the high-order
bit of the qType field to 1. In addition, any value of the count parameter that
exceeds the maximum millisecond delay is reduced to the maximum. If you
pause an unexpired task (with RmvTime ) and then reinstall it (with
InsXTime ), you can continue the previous delay by calling PrimeTime
with the count parameter set to 0.
tmTaskPtr is the address of a 12-byte TMTask structure previously used in a
call to InsTime .
msCount specifies how long, in milliseconds, to wait before calling your
wakeup routine.
</pre>
* \returns <pre>none
</pre>
* \note <pre> PrimeTime may be called more than once for any previously
installed Time Manager task (see InsTime ). Secondary calls override
the previously set interval. Thus, you can use this as a "watchdog" timer to
be called before you start some event that is prone to getting locked into a
loop.
PrimeTime does not make any demands on the Memory Manager , so it
can be called from inside your alarm handling routine in order to set a new
interval for that routine.
See InsTime for an example of usage.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PrimeTime(__A0, __D0)
#endif
	void
	PrimeTime(QElemPtr tmTaskPtr, long count);

	/**
	\brief Remove task from Time Manager queue

	<pre>Trap macro _RmvTime
On entry A0:address of TMTask record
On exit D0:result code
RmvTime removes a previously installed element from the
Time Manager queue. If the clock was ticking on that timer, it
is stopped and its alarm handling routine will not be called.
The RmvTime procedure removes the Time Manager task record specified
by tmTaskPtr from the Time Manager queue. In both the revised and extended
Time Managers, if the specified task record is active (that is, it has been
activated but the specified time has not yet elapsed), the tmCount field of the
task record returns the amount of time remaining. To provide the greatest
accuracy, the unused time is reported as negated microseconds if that value is
small enough to fit into the tmCount field (even if the delay was originally
specified in milliseconds); otherwise, the unused time is reported in positive
milliseconds. If the time has already expired, tmCount contains 0.
In the revised and extended Time Managers, PrimeTime sets the high-order
bit of the qType field to 0.
tmTaskPtr is the address of a 12-byte TMTask structure previously used in a
call to InsTime .
</pre>
* \returns <pre>none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter RmvTime(__A0)
#endif
	void
	RmvTime(QElemPtr tmTaskPtr);

	/**
	 * \non_carbon_cfm in InterfaceLib 9.1 and later
	 * \carbon_lib in CarbonLib 1.0.2 and later
	 * \mac_os_x in version 10.0 and later
	 * \note InstallTimeTask, InstallXTimeTask, PrimeTimeTask and RemoveTimeTask work just like InsTime, InsXTime, PrimeTime, and RmvTime except that they return an OSErr result.
	 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InstallTimeTask(__A0)
#endif
	OSErr InstallTimeTask(QElemPtr tmTaskPtr);

	/**
	 *  InstallXTimeTask()
	 *
	 * \note InstallTimeTask, InstallXTimeTask, PrimeTimeTask and RemoveTimeTask work just like InsTime, InsXTime, PrimeTime, and RmvTime except that they return an OSErr result.

	 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
	 *    \carbon_lib        in CarbonLib 1.0.2 and later
	 *    \mac_os_x         in version 10.0 and later
	 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InstallXTimeTask(__A0)
#endif
	OSErr
	InstallXTimeTask(QElemPtr tmTaskPtr);

/**
 *  PrimeTimeTask()
 * \note InstallTimeTask, InstallXTimeTask, PrimeTimeTask and RemoveTimeTask work just like InsTime, InsXTime, PrimeTime, and RmvTime except that they return an OSErr result.

 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PrimeTimeTask(__A0, __D0)
#endif
	OSErr
	PrimeTimeTask(QElemPtr tmTaskPtr, long count);

/**
 *  RemoveTimeTask()
 * \note InstallTimeTask, InstallXTimeTask, PrimeTimeTask and RemoveTimeTask work just like InsTime, InsXTime, PrimeTime, and RmvTime except that they return an OSErr result.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 RemoveTimeTask(__A0)
#endif
	OSErr
	RemoveTimeTask(QElemPtr tmTaskPtr);

	/**
	 *  Microseconds()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        in CarbonLib 1.0 and later
	 *    \mac_os_x         in version 10.0 and later
	 */
	void
	Microseconds(UnsignedWide *microTickCount);

	/**
	 *  NewTimerUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        in CarbonLib 1.0 and later
	 *    \mac_os_x         in version 10.0 and later
	 */
	TimerUPP
	NewTimerUPP(TimerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppTimerProcInfo = 0x0000B802
	}; // register no_return_value Func(4_bytes:A1) #ifdef __cplusplus
	inline TimerUPP NewTimerUPP(TimerProcPtr userRoutine)
	{
		return (TimerUPP)NewRoutineDescriptor(
			(// register no_return_value Func(4_bytes:A1)
	}
#else
#define NewTimerUPP(userRoutine)                                              \
	(TimerUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppTimerProcInfo, \
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
	void
	DisposeTimerUPP(TimerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeTimerUPP(TimerUPP userUPP)
	{
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
	void
	InvokeTimerUPP(TMTaskPtr tmTaskPtr, TimerUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
	(!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
	inline void InvokeTimerUPP(TMTaskPtr tmTaskPtr, TimerUPP userUPP)
	{
		CALL_ONE_PARAMETER_UPP(userUPP, uppTimerProcInfo, tmTaskPtr);
	}
#else
#define InvokeTimerUPP(tmTaskPtr, userUPP) \
	CALL_ONE_PARAMETER_UPP((userUPP), uppTimerProcInfo, (tmTaskPtr))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewTimerProc(userRoutine) NewTimerUPP(userRoutine)
#define CallTimerProc(userRoutine, tmTaskPtr) \
	InvokeTimerUPP(tmTaskPtr, userRoutine)
#endif // CALL_NOT_IN_CARBON
#if PRAGMA_STRUCT_ALIGN
// support for pre-Carbon UPP routines: New...Proc and Call...Proc
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma // CALL_NOT_IN_CARBON
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __TIMER__ *  /// __TIMER__
