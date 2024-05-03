/**
	 \file       Notification.h

	\brief   Notification Manager interfaces

	\introduced_in  System 7.5
	\avaliable_from Universal Interfaces 3.4.1

	\copyright © 1989-2001 by Apple Computer, Inc., all rights reserved

	\ingroup Managers

	For bug reports, consult the following page on
				 the World Wide Web:

					 http://developer.apple.com/bugreporter/

*/
#ifndef __NOTIFICATION__
#define __NOTIFICATION__

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

	typedef struct NMRec NMRec;
	typedef NMRec *NMRecPtr;
	typedef CALLBACK_API(void, NMProcPtr)(NMRecPtr nmReqPtr);
	typedef STACK_UPP_TYPE(NMProcPtr) NMUPP;
	/**
	<pre>
	 * \note <pre>To set up a notification request, you need to fill in the fields qType,
	nmMark, nmIcon, nmSound , nmStr, nmResp, and nmRefCon . The
	remaining fields of this record are used internally by the
	Notification Manager or are reserved for use by Apple.
	Note: In system software version 6.0, the field nmIcon is named
	nmSIcon and should contain a handle to a small icon (a 16-by-16
	bitmap, often stored as an 'SICN' resource).
	<table><tbody>
	<tr>
		<td>qLink</td>
		<td><pre>Points to the next element in the queue. This field is
	internally by the Notification Manager .
		</pre></td>
	</tr>

	<tr>
		<td>qType</td>
		<td><pre>Indicates the type of operating-system queue. You
	set this field to the value ORD(nmType), which
	8.
		</pre></td>
	</tr>

	<tr>
		<td>nmFlags</td>
		<td><pre>Reserved for use by Apple.
		</pre></td>
	</tr>

	<tr>
		<td>nmPrivate</td>
		<td><pre>Reserved for use by Apple.
		</pre></td>
	</tr>

	<tr>
		<td>nmReserved</td>
		<td><pre>Reserved for use by Apple.
		</pre></td>
	</tr>

	<tr>
		<td>nmMark</td>
		<td><pre>Indicates whether to place a diamond-shaped mark
	to the name of the application in the Application
	If nmMark is 0, no such mark appears. If
	is 1, the mark appears next to the name of the
	application. If nmMark is neither 0 nor 1, it is
	as the reference number of a desk
	An application should pass 1, a desk
	should pass its own reference number, and a
	Reference © 1991-1992 Symantec Corporation
		</pre></td>
	</tr>
	</tbody></table>*/
	struct NMRec
	{
		QElemPtr qLink;	  /**< Address of next element in the queue*/
		short qType;	  /**< Type of data: =nmType*/
		short nmFlags;	  /**< (reserved)*/
		long nmPrivate;	  /**< (reserved)*/
		short nmReserved; /**< (reserved)*/
		short nmMark;	  /**< DA or Application to identify with  symbol*/
		Handle nmIcon;	  /**< Handle to Small Icon;/**< rotate with   on */
		Handle nmSound;	  /**< Handle to sound record*/
		StringPtr nmStr;  /**< Pointer to string you want to appear in the*/
		NMProcPtr nmResp; /**< Pointer to response routine*/
		long nmRefCon;	  /**< Available for your application's use*/
	} NMRec;			  /**< */

	/**
	 *  NewNMUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        in CarbonLib 1.0 and later
	 *    \mac_os_x         in version 10.0 and later
	 */
	NMUPP
	NewNMUPP(NMProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppNMProcInfo = 0x000000C0
	}; /** pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
	inline NMUPP NewNMUPP(NMProcPtr userRoutine)
	{
		return (NMUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppNMProcInfo,
										   GetCurrentArchitecture());
	}
#else
#define NewNMUPP(userRoutine)                                           \
	(NMUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppNMProcInfo, \
								 GetCurrentArchitecture())
#endif
#endif

	/**
	 *  DisposeNMUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        in CarbonLib 1.0 and later
	 *    \mac_os_x         in version 10.0 and later
	 */
	void
	DisposeNMUPP(NMUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeNMUPP(NMUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposeNMUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  InvokeNMUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        in CarbonLib 1.0 and later
	 *    \mac_os_x         in version 10.0 and later
	 */
	void
	InvokeNMUPP(NMRecPtr nmReqPtr, NMUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void InvokeNMUPP(NMRecPtr nmReqPtr, NMUPP userUPP)
	{
		CALL_ONE_PARAMETER_UPP(userUPP, uppNMProcInfo, nmReqPtr);
	}
#else
#define InvokeNMUPP(nmReqPtr, userUPP) \
	CALL_ONE_PARAMETER_UPP((userUPP), uppNMProcInfo, (nmReqPtr))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewNMProc(userRoutine) NewNMUPP(userRoutine)
#define CallNMProc(userRoutine, nmReqPtr) InvokeNMUPP(nmReqPtr, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

	/**
	\brief Add a notification request to the notification queue

	<pre>NMInstall adds a notification request to the notification queue.
nmReqPtr is a pointer to an NMRec data structure.
</pre>
* \returns <pre>an error code. It will be one of:
noErr(0) No error
nmTypErr (-299)Wrong qType (must be 8)
</pre>
* \note <pre>NMInstall neither moves nor purges memory and you can call it from
completion routines, interrupt handlers, the main body of an application
program and from the response procedure of a notification request
The system automatically initializes the Notification Manager when it
boots. You call NMInstall when you want to add a request to the queue.
However, before calling NMInstall , you need to see if your application is
running in the background. If it is, make this call to install the notification
event.
err = NMInstall (( NMRecPtr ) &myNote);
If your application is in the foreground, Notification Manager generally
isn't needed.
If NMInstall returns an error, you can't install the notification event.
Wait for the user to switch your application to the foreground before
proceeding with anything else. If you installed the notification successfully,
make sure you remove it with code like this when your application is
switched back into the foreground:
err = NMRemove (( QElemPtr ) &myNote);
Glue for the Notification Manager is available in System 6.0 and later.
If you do not yet have glue for NMInstall , you can use the following:
Pascal
FUNCTION NMInstall (nmReqPtr: QElemPtr) : OSErr;
NLINE 0x205F, 0xA05E, 0x3E80;
C
pascal OSErr NMInstall (QElemPtr nmReqPtr) = {0x205F, 0xA05E,
0x3E80};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 NMInstall(__A0)
#endif
	OSErr
	NMInstall(NMRecPtr nmReqPtr);

	/**
	\brief Remove a notification request from the notification queue

	<pre>NMRemove removes a notification request procedure from the notification
queue.
nmReqPtr is a pointer to the NMRec that you want to remove.
</pre>
* \returns <pre>an error code. It will be one of:
noErr(0) No error
qErr (-1) Not in queue
nmTypErr (-299)Wrong qType (must be ORD(nmType))
</pre>
* \note <pre>NMRemove neither moves nor purges memory and you can call it from
completion routines, interrupt handlers, the main body of an application
program and from the response procedure of a notification request
If you do not yet have glue for NMRemove , you can use the following:
Pascal
FUNCTION NMRemove (nmReqPtr: QElemPtr) : OSErr;
INLINE 0x205F, 0xA05F, 0x3E80;
C
pascal OSErr NMRemove (QElemPtr nmReqPtr)
= {0x205F, 0xA05F, 0x3E80};
Also note that qType must be set to ORD(nmType), which is 8.
See NMInstall for a code example using the Notification Manager .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 NMRemove(__A0)
#endif
	OSErr
	NMRemove(NMRecPtr nmReqPtr);

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

#endif /** __NOTIFICATION__ */
*/*/