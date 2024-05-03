/**
	 \file       OSUtils.h

	\brief   OS Utilities Interfaces.

	\introduced_in  Mac OS 9
	\avaliable_from Universal Interfaces 3.4.1

	\copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

	\ingroup System

	For bug reports, consult the following page on
				 the World Wide Web:

					 http://developer.apple.com/bugreporter/

*/
#ifndef __OSUTILS__
#define __OSUTILS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

//  HandToHand and other memory utilties were moved to MacMemory.h #ifndef __MACMEMORY__
#include <MacMemory.h>
#endif

//  GetTrapAddress and other trap table utilties were moved to Patches.h #ifndef __PATCHES__
//  GetTrapAddress and other trap table utilties were moved to Patches.h
#endif

//  Date and Time utilties were moved to DateTimeUtils.h #ifndef __DATETIMEUTILS__
#include <DateTimeUtils.h>
//  Date and Time utilties were moved to DateTimeUtils.h

#ifndef __CFSTRING__
#include <CFString.h>
#endif

#if !TARGET_OS_MAC
#ifndef __ENDIAN__
#include <Endian.h>
#endif

#endif // !TARGET_OS_MAC
#if PRAGMA_ONCE
#pragma once
#endif // !TARGET_OS_MAC

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
		useFree = 0,
		useATalk = 1,
		useAsync = 2,
		useExtClk = 3, // Externally clocked
		useMIDI = 4
	};

	enum
	{
		false32b = 0, // 24 bit addressing error
		true32b = 1	  // 32 bit addressing error
	};

	enum
	{
		 /** types */
for RelString Call 		sortsBefore  =  -1 // first string < second string
		sortsEqual = 0, // first string = second string
		sortsAfter = 1	// first string > second string
	};
	// result types for RelString Call
	enum
	{
		dummyType = 0,
		vType = 1,
		ioQType = 2,
		drvQType = 3,
		evType = 4,
		fsQType = 5,
		sIQType = 6,
		dtQType = 7,
		nmType = 8
	};

	typedef SignedByte QTypes;
	/**
	<pre>
	 * \note <pre>This structure is a global variable named SysParam (at 0x01F8), which
	address is returned when you call GetSysPPtr . Data from this structure
	is written to the CMOS memory when you call WriteParam . It echos the
	data found in the "Parameter RAM", which is the battery-powered storage
	in the CMOS clock chip. Each of the fields also has a unique name and may be
	accessed individually:
	The valid field ( SPValid, at 0x01F8) gets tested at system startup. If the
	parameter RAM was read or written correctly, this field gets set to 0xA8.
	The aTalkA and aTalkB fields ( SPATalkA at 0x01F9 and SPATalkB at
	0x01FA) identify whether a port is in use and how:
	The config field ( SPConfig , at 0x01FB) indicates how the ports are
	currently configured. The high nibble (4 bits) is for Port A and the low
	nibble is for port B.  one of the usage codes 0 (free), 1 (AppleTalk), or 2
	(serial) is in each nibble.
	The portA and portB fields ( SPPortA at 0x01FC and SPPortB at 0x01FE)
	identify the current serial protocol in use for the ports. The 16-bit value
	is formatted as:
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct SysParmType
	{
		char valid;		/**< Validity status xA=successful write*/
		char aTalkA;	/**< Used by AppleTalk Manager*/
		char aTalkB;	/**< Used by AppleTalk Manager*/
		char config;	/**< Bit fields tell how each port is used*/
		short portA;	/**< Baud rate, stop bits, etc*/
		short portB;	/**< Baud rate, stop bits, etc*/
		long alarm;		/**< Alarm setting (seconds since*/
		short font;		/**< Application font number -*/
		short kbdPrint; /**< Printer connection, key delay, key rate*/
		short volClik;	/**< Carat blink, dble-click interval, spkr*/
		short misc;		/**< menu blink, startup disk, mouse scaling*/
	} SysParmType;		/**< */

	typedef struct SysParmType SysParmType;
	typedef SysParmType *SysPPtr;
	/**
	<pre>
	 * \note <pre>For queues created and maintained by an application, use any code you like
	for the qType field. See Enqueue and Dequeue . System-defined queue
	elements use various structures, depending upon qType, as indicated above.
	All standard Operating System queues have a QHdr structure which
	contains a pointer to the first queue element. Each element points to the
	next, and the final element has a qLink value of 0.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct QElem
	{
		QElemPtr qLink; /**<  Address of next element in the queue*/
		short qType;	/**<  Type of data:*/
		char qData[];	/**< n Data starts here, length varies*/
	} QElem;			/**< +n*/

	typedef struct QElem QElem;
	typedef QElem *QElemPtr;
#if TARGET_OS_MAC
	/**
	<pre>
	 * \note <pre>All standard Operating System queues have a QHdr structure which
	contains pointers to the first and last queue elements. Use Enqueue and
	Dequeue to manipulate queues created by your application. The various
	managers handle their queues internally. The following calls return a
	QHdrPtr:
	GetDrvQHdr Drive queue elements are DrvQEl structures
	GetEvQHdr Event queue elements are EvQEl structures
	GetFSQHdr I/O queue elements are ParamBlockRec (et al.) structs
	GetVBLQHdr Vertical retrace tasks are VBLTask structures
	GetVCBQHdr Volume control blocks are VCB structures
	The qFlags field is largely undocumented. We are told that in the vertical
	retrace queue header, if qFlags bit 6 is set, a task is currently being
	executed.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct QHdr
	{
		short qFlags;	/**< Various flags, differs per queue type*/
		QElemPtr qHead; /**< Address of first queue element*/
		QElemPtr qTail; /**< Address of last queue element*/
	} QHdr;				/**< */

	typedef struct QHdr QHdr;
	typedef QHdr *QHdrPtr;
#else
	/**
	   QuickTime 3.0
	   this version of QHdr contains the Mutex necessary for
	   non-mac non-interrupt code
	*/
	struct QHdr
	{
		volatile short qFlags;
		short pad;
		long MutexID;
		volatile QElemPtr qHead;
		volatile QElemPtr qTail;
	};
	typedef struct QHdr QHdr;
	typedef QHdr *QHdrPtr;
#endif // TARGET_OS_MAC
	typedef CALLBACK_API_REGISTER68K(void, DeferredTaskProcPtr, (long dtParam));
	typedef REGISTER_UPP_TYPE(DeferredTaskProcPtr) DeferredTaskUPP;
	/**
	 *  NewDeferredTaskUPP()
	 * \non_carbon_cfm available as macro/inline
	 * \carbon_lib in CarbonLib 1.0 and later
	 * \mac_os_x in version 10.0 and later */
	DeferredTaskUPP
	NewDeferredTaskUPP(DeferredTaskProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppDeferredTaskProcInfo = 0x0000B802
	}; // register no_return_value Func(4_bytes:A1) #ifdef __cplusplus
	inline DeferredTaskUPP NewDeferredTaskUPP(DeferredTaskProcPtr userRoutine)
	{
		return (DeferredTaskUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
													 uppDeferredTaskProcInfo,
													 GetCurrentArchitecture());
	} // register no_return_value Func(4_bytes:A1)
#else
#define NewDeferredTaskUPP(userRoutine)                                       \
	(DeferredTaskUPP)                                                         \
		NewRoutineDescriptor((ProcPtr)(userRoutine), uppDeferredTaskProcInfo, \
							 GetCurrentArchitecture())
#endif
#endif

	/**
	 *  DisposeDeferredTaskUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        in CarbonLib 1.0 and later
	 *    \mac_os_x         in version 10.0 and later
	 */
	void
	DisposeDeferredTaskUPP(DeferredTaskUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeDeferredTaskUPP(DeferredTaskUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposeDeferredTaskUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeDeferredTaskUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeDeferredTaskUPP(__A1, __A0)
#endif
	void
	InvokeDeferredTaskUPP(long dtParam, DeferredTaskUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
	(!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
	inline void InvokeDeferredTaskUPP(long dtParam, DeferredTaskUPP userUPP)
	{
		CALL_ONE_PARAMETER_UPP(userUPP, uppDeferredTaskProcInfo, dtParam);
	}
#else
#define InvokeDeferredTaskUPP(dtParam, userUPP) \
	CALL_ONE_PARAMETER_UPP((userUPP), uppDeferredTaskProcInfo, (dtParam))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewDeferredTaskProc(userRoutine) NewDeferredTaskUPP(userRoutine)
#define CallDeferredTaskProc(userRoutine, dtParam) \
	InvokeDeferredTaskUPP(dtParam, userRoutine)
#endif // CALL_NOT_IN_CARBON
	/**
	<pre>
	 * \note <pre>The Deferred Task Manager lets you put off the execution of lengthy
// support for pre-Carbon UPP routines: New...Proc and Call...Proc
	These tasks are executed with interrupts enabled, but are subject to the
	same restrictions regarding moving memory and preserving registers as
	interrupt routines.By calling DTInstall , you can set up a queue, place the
	inform// CALL_NOT_IN_CARBON
	run when the processor would otherwise be idle.
	In the DeferredTask structure, QLink points to the next enqueued item,
	while QType is always a dtQType, a standard Operating System queue. The
	dtParm field is there to let you pass an optional parameter in assembly
	language. The parameter would be loaded into register A1 immediately
	prior to task execution.
	This structure is currently not declared in Apple header files. You can
	either declare the structure yourself or access the fields via a QElemPtr
	using assembly language.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct DeferredTask
	{
		QElemPtr qLink;	 /**< Address of next queue element*/
		short qType;	 /**< Always dtQType*/
		short dtFlags;	 /**< (not used)*/
		ProcPtr dtAddr;	 /**< Task's address*/
		long dtParm;	 /**< Optional parameter*/
		long dtReserved; /**< (not used;/**< set to )*/
	} DeferredTask;		 /**< */

	typedef struct DeferredTask DeferredTask;
	typedef DeferredTask *DeferredTaskPtr;
#if TARGET_OS_MAC
	struct MachineLocation
	{
		Fract latitude;
		Fract longitude;
		union
		{
			SInt8 dlsDelta; // signed byte; daylight savings delta 			long gmtDelta;	// use low 24-bits only 		} u;
		};
		typedef struct MachineLocation MachineLocation;
#else
	/**
		QuickTime 3.0:
		Alignment of MachineLocation is weird. The union above used for delta
		tends not to work on non-Mac compilers.
	*/
	struct MachineLocat // signed byte; daylight savings delta
	{					// use low 24-bits only
		Fract latitude;
		Fract longitude;
		BigEndianLong
			delta; // high byte is daylight savings delta, low 24-bits is GMT delta
	};
	typedef struct MachineLocation MachineLocation;
#endif // TARGET_OS_MAC
		/**
		 *  IsMetric()
		 *

		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
		 *    \carbon_lib        in CarbonLib 1.0 and later
		 *    \mac_os_x         in version 10.0 and later
		 */
		Boolean // high byte is daylight savings delta, low 24-bits is GMT delta
		IsMetric(void);

		/**
			\brief Get address of start of Parameter RAM data
			<pre>
				GetSysPPtr returns the address at which the Parameter RAM has been copied;
		i.e., a SysParmType structure such information as the default speaker volume, printer port configuration, etc.</pre>

		\returns <pre> a SysPPtr; the address of a 20-byte SysParmType structure. This always returns 0x01F8. </pre>
		\copyright THINK Reference © 1991 - 1992 Symantec Corporation
		\non_carbon_cfm in InterfaceLib 7.1 and later
		\carbon_lib in CarbonLib 1.0 and later
		\mac_os_x in version 10.0 and later*/
		SysPPtr
		GetSysPPtr(void);

		/**
			NOTE: SysBeep() has been moved to Sound.h.
				  We could not automatically #include Sound.h in this file
				  because Sound.h indirectly #include's OSUtils.h which
				  would make a circular include.
		*/

		/**
		\brief Add a task to the deferred task queue

		<pre>DTInstall adds a task identified by a pointer to the deferred task queue.
	dtTaskPtr is a pointer leading to data to be enqueued.
	</pre>
	* \returns <pre>an OSErr; an integer Error Code . It will be one of:
	noErr(0) No error
	vTypeErr (-2) Invalid queue element
	</pre>
	* \note <pre>DTInstall adds a lengthy task to a deferred task queue so that it can be
	executed when all interrupts at the current interrupt level have been
	serviced. These tasks are executed with interrupts enabled, but are subject
	to the same restrictions regarding moving memory and preserving
	registers as interrupt routines. The QElemPtr referenced by the dtTaskPtr
	points to a DeferredTask record, which itself contains a pointer to the
	task you want to add to the queue.
	Most of the long tasks for which this call is best suited are initiated by
	add-in cards. You would generally need this call, therefore, only if your
	program has to deal with these kinds of interrupts.
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	*    \carbon_lib        in CarbonLib 1.0 and later
	*    \mac_os_x         in version 10.0 and later
	*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 DTInstall(__A0)
#endif
		OSErr
		DTInstall(DeferredTaskPtr dtTaskPtr);

#if TARGET_CPU_PPC || !TARGET_OS_MAC
#define GetMMUMode() ((SInt8)true32b)
#define SwapMMUMode(x) (*(SInt8 *)(x) = true32b)
#else
#if CALL_NOT_IN_CARBON

	/**
	\brief Get the current address translation mode

	<pre>GetMMUMode are false32b and true32b.
	</pre>
	* \note <pre> Gestalt can be used with the gestaltAddressingModeAttr selector to determine
	the current addressing mode as well.
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   not available
	*    \carbon_lib        not available
	*    \mac_os_x         not available
	*/
	SInt8 GetMMUMode(void);

#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON

	/**
	\brief Set the address translation mode

	<pre>SwapMMUMode . You should use the values
	false32b or true32b for the mode parameter.
	</pre>
	* \returns <pre>none
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   not available
	*    \c// CALL_NOT_IN_CARBON
	*    \mac_os_x         not available
	*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SwapMMUMode(__A0)
#endif
	void SwapMMUMode(SInt8 *mode);

#endif // CALL_NOT_IN_CARBON
#endif

		/**
		\brief Pause execution for a specified interval

		<pre>Delay enables interrupts and keeps control until a specified interval in ticks
	(1/60-th second units) has elapsed.
	duration specifies the desired duration of the delay, in 1/60-th second
	(16.6 ms) units. For instance, if duration = 60, the delay will
	last approx. 1 second.
	finalTicks is the address of a 32-bit long. Upon return, it will contain the
	value of Ticks (the number of ticks since system startup) as it was
	when Delay returned control.
	</pre>// CALL_NOT_IN_CARBON
	* \returns <pre>none
	</pre>
	* \note <pre>Because of the possibility of interrupts being disabled or overridden for
	short periods, Delay may last one or more ticks longer than you requested
	in duration.  Thus, you should not rely on pinpoint accuracy here.
	The finalTicks  parameter can be used as an accuracy gauge to see if you did
	lose a tick or two.
	The global variable Ticks is updated upon every vertical retrace. See
	VInstall for related information.
	Ticks are generally referred to as 1/60th of a second. It is actually
	1/60.15 seconds. However, if you need this kind of accuracy, you should not
	be using functions like TickCount and Delay.
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	*    \carbon_lib        in CarbonLib 1.0 and later
	*    \mac_os_x         in version 10.0 and later
	*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter Delay(__A0, __A1)
#endif
		void
		Delay(unsigned long numTicks, unsigned long *finalTicks);

		/**
		\brief Write Parameter RAM data to non-volatile RAM

		<pre>WriteParam copies the 20 bytes of data starting at SysParam into the
	non-volatile clock-chip memory. This can be used after modifying one or
	more system parameters (such as the default speaker volume) to make those
	parameters "permanent".
	</pre>
	* \returns <pre>an OSErr; an integer Error Code . It will be one of:
	noErr(0) No error
	prWrErr (-87) Couldn't verify the write
	</pre>
	* \note <pre>You can use GetSysPPtr and the SysParmType structure to modify
	system parameters in memory, then use WriteParam to make those
	values "permanent".
	It is possible to alter the contents of the Parameter RAM so much that the
	Mac won't start next time you boot. In that case, you can reset the
	Parameter RAM by pulling the battery for about 5 minutes.
	To zap the PRAM, hold down the cmd, shift and option keys and select the
	Control Panel from the Apple menu.
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	*    \carbon_lib        in CarbonLib 1.0 and later
	*    \mac_os_x         in version 10.0 and later
	*/
		OSErr
		WriteParam(void);

		/**
		\brief Add an element to the end of a queue

		<pre>Enqueue adds an element to the end of a linked list known as a queue. The
	element itself (and not a copy) is hooked into the queue.
	qEntryis the address of a variable-length QElem structure whose size and
	contents depend upon the type of queue. This packet contains a place
	for the queue linkage, the queue type, and the data of the queue
	element itself.
	theQueue is the address of a 10-byte QHdr structure. This structure contains
	information about the queue - some type-specific flags and pointers
	to the first and last element in the queue.
	</pre>
	* \returns <pre>none
	</pre>
	* \note <pre>The Macintosh Operating System uses queues to store and track such items
	as keyboard and mouse events, vertical retrace tasks, file I/O requests, and
	so forth.
	Enqueue causes theQueue ->qTail and the previously-last queue element's
	qlink field to be updated to point to qEntry. The effect is that if you trace the
	queue links from start to finish, you will see all queue elements, including
	the newly-added element.
	The Enqueue routine turns off interrupts for critical sections of its code.
	This makes it ideal for queue management for interrupt-driven programs
	which need to be concerned about simultaneous execution and deadlock.
	For system-defined queues such as the event queue and vertical retrace
	task queue, qEntry must be one of the following predefined data types:
	Struct Name constant value Description
	VBLTask vType 1vertical retrace task queue
	ParamBlockRec ioQType 2file I/O or driver I/O queue
	DrvQEl drvQType 3drive queue
	EvQElevType 4event queue
	VCBfsQType 5volume control-block queue
	For custom queues, the queue element structure must begin with 10 bytes
	- space for a "next element" pointer and a type code. Otherwise, the size and
	contents of the queue element are user-defined.
	The following example uses Enqueue and Dequeue to manage a list of
	"bullets" in an arcade-style game.  It initializes a queue header, adds some
	bullets to the queue, and repeatedly calls a routine that goes down the list,
	updating the screen positions of the bullets. When a bullet goes off-screen,
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	*    \carbon_lib        in CarbonLib 1.0 and later
	*    \mac_os_x         in version 10.0 and later
	*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter Enqueue(__A0, __A1)
#endif
		void
		Enqueue(QElemPtr qElement, QHdrPtr qHeader);

		/**
		\brief Remove an element from a queue

		<pre>Dequeue removes an element from a queue, adjusting the queue links to
	bypass the element. The element itself is not deallocated.
	qEntryis the address of a variable-length QElem structure whose size and
	contents depend upon the type of queue. This must be the same as a
	qEntry value used in a previous call to Enqueue .
	theQueue is the address of a 10-byte QHdr structure. This structure contains
	information about the queue-some type-specific flags and pointers to
	the first and last element in the queue.
	</pre>
	* \returns <pre>an OSErr; an integer Error Code . It will be one of:
	noErr(0) No error
	qErr(-1) Entry not in specified queue
	</pre>
	* \note <pre>Dequeue is used to remove any element from a queue. The caller is
	responsible for deallocating the space used by the queue element (if that
	memory needs to be freed).
	The Dequeue routine turns off interrupts for critical sections of its code.
	This makes it ideal for queue management for interrupt-driven programs
	which need to be concerned about simultaneous execution and deadlock.
	An example of queue usage is contained in Enqueue .
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	*    \carbon_lib        in CarbonLib 1.0 and later
	*    \mac_os_x         in version 10.0 and later
	*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 Dequeue(__A0, __A1)
#endif
		OSErr
		Dequeue(QElemPtr qElement, QHdrPtr qHeader);

		/**
		\brief Get the current value of A5.

		<pre>Use SetCurrentA5 to get the current value of the system global variable
	CurrentA5 .
	The SetCurrentA5 function does two things: First, it gets your application's
	A5 and returns it to your application. Second, SetCurrentA5 sets register A5
	to the value of the application's low-memory global variable CurrentA5 .
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	*    \carbon_lib        in CarbonLib 1.0 and later
	*    \mac_os_x         in version 10.0 and later
	*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SetCurrentA5
#endif
		long
		SetCurrentA5(void);

		/**
		\brief Set the current value of A5

		<pre>Use the SetA5 function to set the A5 register to the application's A5.
	Calling SetA5 performs two tasks: It sets the A5 register to the address
	specified as newA5, and it returns the address that is in register A5 before the
	SetA5 is called.
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	*    \carbon_lib        in CarbonLib 1.0 and later
	*    \mac_os_x         in version 10.0 and later
	*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SetA5(__D0)
#endif
		long
		SetA5(long newA5);

		/**
		\brief Copy Parameter RAM to low-memory variables

		<pre>InitUtil reads the non-volatile RAM (Parameter RAM) and copies it to the
	data area starting at SysParam (at 0x01F8). It also stores the "raw" seconds
	into the variable Time (at 0x020C).
	</pre>
	* \returns <pre>an OSErr; an integer Error Code . It will be one of:
	noErr(0) No error
	prInitErr (-88) Validity status was not 0xA8
	</pre>
	* \note <pre>This function is called at system startup and will normally not be used by
	application programs.
	See SysParmType for the layout of the area to which the Parameter RAM is
	copied.
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	*    \carbon_lib        in CarbonLib 1.0 and later
	*    \mac_os_x         in version 10.0 and later
	*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InitUtil
#endif
		OSErr
		InitUtil(void);

#if !TARGET_CPU_68K
		/**
		 *  MakeDataExecutable()
		 *

		 *    \non_carbon_cfm   in InterfaceLib 7.5 and later
		 *    \carbon_lib        in CarbonLib 1.0 and later
		 *    \mac_os_x         in version 10.0 and later
		 */
		void
		MakeDataExecutable(void *baseAddress, unsigned long length);

#endif // !TARGET_CPU_68K
#if TARGET_CPU_68K
#if CALL_NOT_IN_CARBON

		/**
		\brief SwapInstructionCache Enable or disable the instruction cache

		<pre>The SwapInstructionCache function enables or disables the instruction
	cache, depending on whether the cacheEnable parameter is set to TRUE or
	FALSE. SwapDataCache returns the previous state of the instruction cache.
	</pre>
	* \note <pre>Be sure to check that the trap _HWPriv is implemented before calling this
	routine. See Using the Gestalt Manager for sample code that shows how
	to determine whether a trap is implemented. If you call this routine and
	_HWPriv is not implemented, you application will crash.
	The MC6// !TARGET_CPU_68K
	instruction caches.
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   not available
	*    \carbon_lib        not available
	*    \mac_os_x         not available
	*/
		Boolean
		SwapInstructionCache(Boolean cacheEnable);

		/**
		\brief Enable or disable the data cache

		<pre>The SwapDataCache function enables or disables the data cache, depending
	on whether the cacheEnable parameter is set to TRUE or FALSE.
	SwapDataCache returns the previous state of the data cache.
	</pre>
	* \note <pre>Be sure to check that the trap _HWPriv is implemented before calling this
	routine. See Using the Gestalt Manager for sample code that shows how
	to determine whether a trap is implemented. If you call this routine and
	_HWPriv is not implemented, you application will crash.
	The MC68030 and MC68040 microprocessors have data caches.
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   not available
	*    \carbon_lib        not available
	*    \mac_os_x         not available
	*/
		Boolean
		SwapDataCache(Boolean cacheEnable);

#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON

		/**
		\brief FlushInstructionCache Flush the instruction cache

		<pre>The FlushInstructionCache function flushes the current contents of the
	instruction cache. Because flushing this cache degrades performance of the
	CPU, this routine should be called only when absolutely necessary.
	</pre>
	* \note <pre>Be sure to check that the trap _HWPriv is implemented before calling this
	routine. See Using the Gestalt Manager for sample code that shows how
	to determine whether a trap is implemented. If you call this routine and
	_HWPriv is not implemented, you application will crash.
	The MC68020, MC68030 and MC68040 microprocessors have
	instruction caches.
	Any tim// CALL_NOT_IN_CARBON
	instructions in the instruction cache. A microprocessor that contains an
	instruction cache store the most recently executed instructions in its
	internal instruction cache, separate from main memory. Whenever your
	code modifies itself or any data in memory that contains executable code,
	there is a possibility that a copy of the modified instructions will be in the
	instruction cache. If so, attempting to execute the modified instructions
	actually results in the execution of the cached instructions, which are stale.
	Stale instructions can be avoided by flushing the instruction cache every
	time you modify executable instructions in memory. Flushing the cache
	invalidates all entries in it and forces the processor to refill the cache from
	main memory.
	If you want to flush the instruction cache of a processor with a copy-back
	data cache, such as the MC68040 processor, you may want to write your
	own routine that calls the _CacheFlush trap in assembly language. This
	trap flushes the data cache before it flushes the instruction cache to insure
	that any instructions subsequently copied to the instructions cache are not
	copied from stale RAM.
	// FlushCache
	// Flush the CPU cache(s). This is required on the 68040 after modifying
	// code.
	#define _CacheFlushTrap 0xA0BD
	void FlushCache(void)
	{
	if (TrapAvailable( _CacheFlushTrap))
	asm
	{
	dc.w _CacheFlushTrap
	}
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   not available
	*    \carbon_lib        not available
	*    \mac_os_x         not available
	*/
		void
		FlushInstructionCache(void);

		/**
		\brief Flush the data cache

		<pre>The FlushDataCache function flushes the current contents of the data cache.
	Because flushing this cache degrades performance of the CPU, this routine
	should be called only when absolutely necessary.
	</pre>
	* \note <pre>Be sure to check that the trap _HWPriv is implemented before calling this
	routine. See Using the Gestalt Manager for sample code that shows how
	to determine whether a trap is implemented. If you call this routine and
	_HWPriv is not implemented, you application will crash.
	A cache may contain stale data whenever information in main memory is
	changed and that information is already cached in the microprocessor's data
	cache. The MC68030 has a write-through cache. This means that any
	data written to the cache is immediately written out to main memory. You
	need to flush a write-through cache if you write directly to main memory.
	This can cause the information in the data cache to become stale.
	The MC68040 has a copy-back cache. Any data written to the cache is
	written to main memory only when necessary to make room in the cache for
	data accessed more recently or when the cache is explicitly flushed. A
	copy-back cache needs to be flushed if you write data that is to be read by
	non-CPU devices that access RAM directly. A copy-back cache can also
	lead to use of invalid instructions if the stale data in RAM contains
	executable code. When fetching instructions, the CPU looks in the
	instruction cache and, if necessary, in main memory, but not in the data
	cache. See FlushInstructionCache for a code example that flushes first
	the data cache and then the instruction cache of a processor with a
	copy-back cache, such as the MC68040. This operation should be
	performed whenever self-modifying code is used.
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   not available
	*    \carbon_lib        not available
	*    \mac_os_x         not available
	*/
		void
		FlushDataCache(void);

		/**
		 *  FlushCodeCache()
		 *

		 *    \non_carbon_cfm   not available
		 *    \carbon_lib        not available
		 *    \mac_os_x         not available
		 */
		void
		FlushCodeCache(void);

#endif // CALL_NOT_IN_CARBON
#endif // TARGET_CPU_68K
#if CALL_NOT_IN_CARBON
/**
 *  FlushCodeCacheRange()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 FlushCodeCacheRange(__A0, __A1)
#endif
		OSErr
		FlushCodeCacheRange(void *address, unsigned long count);
// CALL_NOT_IN_CARBON
#endif	// CALL_NOT_IN_CARBON
		/**  TARGET_CPU_68K
	\brief Where is this Macintosh and what time is it ?

													 <pre>
														 ReadLocation accesses the stored geographic location of the Macintosh and
															 the time zone information from the parameter RAM For more information see,
			Macintosh Worldwide Development : Guide to System Software.</ pre>
			\copyright THINK Reference © 1991 - 1992 Symantec Corporation
			\non_carbon_cfm in InterfaceLib 7.1 and later
			\carbon_lib in CarbonLib 1.0 and later
			\mac_os_x in version 10.0 and later */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter ReadLocation(__A0)
#endif
		void ReadLocation(MachineLocation *loc);
		// CALL_NOT_IN_CARBON
		/**
		\brief Store machine's location and time zone data in RAM

		<pre>WriteLocation function stores the geographic location of the Macintosh and
	the time zone information in parameter RAM For more information see,
	Macintosh Worldwide Development: Guide to System Software.
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	*    \carbon_lib        in CarbonLib 1.0 and later
	*    \mac_os_x         in version 10.0 and later
	*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter WriteLocation(__A0)
#endif
		void
		WriteLocation(const MachineLocation *loc);

		/**
		 *  TickCount()
		 *

		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
		 *    \carbon_lib        in CarbonLib 1.0 and later
		 *    \mac_os_x         in version 10.0 and later
		 */
		UInt32
		TickCount(void);

		/**
		 *  CSCopyUserName()
		 *

		 *    \non_carbon_cfm   not available
		 *    \carbon_lib        in CarbonLib 1.5 and later
		 *    \mac_os_x         in version 10.0 and later
		 */
		CFStringRef
		CSCopyUserName(Boolean useShortName);

		/**
		 *  CSCopyMachineName()
		 *

		 *    \non_carbon_cfm   not available
		 *    \carbon_lib        in CarbonLib 1.5 and later
		 *    \mac_os_x         in version 10.0 and later
		 */
		CFStringRef
		CSCopyMachineName(void);

#if OLDROUTINENAMES
#define IUMetric() IsMetric()
#endif // OLDROUTINENAMES
		/**
			NOTE: SysEnvirons is obsolete.  You should be using Gestalt.
		*/
		// Environs Equates 	enum
		{
			curSysEnvVers = 2 // Updated to equal latest SysEnvirons version
		};

		/**
		<pre>
		 * \note <pre>This structure is obtained via a call to SysEnvirons . Its size may
		increase in the future and new constants may be returned in any of the
		fields. For this reason, your appplication should be prepared to handle
		unexpected values if it calls SysEnvirons . This topic discusses the data
		returned by version 1 of the structure; ie, when you call SysEnvirons (
		1,... ).
		Machine Type
		The machineType field will hold one of the following:
		envXL -2Mac XL / Lisa
		envMac// OLDROUTINENAMES
		envMachUnknown 0Some Mac newer than Mac II
		env512KE 1Mac 512K Enhanced
		envMacPlus 2Mac Plus
		envSE 3Mac SE
		// Environs Equates
		envMacIIx 5Mac IIx
		envMacIIcx 6Mac IIcx
		envSE30 7Mac SE30
		envPortable 8Mac Portable
		envMacIIci 9Mac IIci
		envMacIIfx 11Mac IIfx
		envMacClassic 15Mac Classic
		envMacIIsi 16Mac IIsi
		envMacLC 17Mac LC
		envMacQuadra900 18Mac Quadra 900
		envMacPowerBook170 19Mac PowerBook 170
		envMacQuadra700 20Mac Quadra 700
		envMacClassicII 21Mac Classic II
		envMacPowerBook100 22Mac PowerBook 100
		</pre>
		 * \copyright THINK Reference © 1991-1992 Symantec Corporation
		*/
		struct SysEnvRec
		{
			short environsVersion; /**< version of this structure*/
			short machineType;	   /**< Macintosh type code, -... (see below)*/
			short systemVersion;   /**< hiByte= major, lowByte= minor;/**< =*/
			short processor;	   /**< =K, =, =;/**< =newer*/
			Boolean hasFPU;		   /**< TRUE = has MC numeric coprocessor*/
			Boolean hasColorQD;	   /**< TRUE = supports color Quickdraw functions*/
			short keyboardType;	   /**< Keyboard type code (see below)*/
			short atDrvrVersNum;   /**< AppleTalk version if open (else, )*/
			short sysVRefNum;	   /**< Volume ID (or working dir) of open System*/
		} SysEnvRec;			   /**< */

		typedef struct SysEnvRec SysEnvRec;
		enum
		{
			/** Types */
			envMac = -1 envXL = -2,
			envMachUnknown = 0,
			env512KE = 1,
			envMacPlus = 2,
			envSE = 3,
			envMacII = 4,
			envMacIIx = 5,
			envMacIIcx = 6,
			envSE30 = 7,
			envPortable = 8,
			envMacIIci = 9,
			envMacIIfx = 11
		};

		enum
		{
			/** types */
			envCPUUnknown = 0 env68000 = 1,
			env68010 = 2,
			env68020 = 3,
			env68030 = 4,
			// Machine Types
		};

		enum
		{
			/** types */
			envUnknownKbd = 0 envMacKbd = 1,
			envMacAndPad = 2,
			envMacPlusKbd = 3,
			envAExtendKbd = 4,
			envStandADBKbd = 5,
			envPrtblADBKbd = 6,
			envPrtblISOKbd = 7,
			envStdISOADBKbd = 8,
			envExtISOADBKbd = 9
		};

#if CALL_NOT_IN_CARBON
		// CPU types
		/**
		\brief Get ROM version, machine type, system version, etc.

		<pre>SysEnvirons is no longer a recommended way of obtaining information
	about the environment in which your code will run. Gestalt is now available
	as glue in development environments so that there is no need to call Environs
	or SysEnvirons , regardless of what machine or operating system you are
	running on.
	SysEnvirons fills a structure with information about the computer and
	system on which the caller is executing.
	ve// Keyboard types
	the constant curSysEnvVers (currently version 2) to obtain the
	basic 18-byte version described in the SysEnvRec topic.
	theSysEnv is the address of an 18-byte SysEnvRec structure. Upon return, it
	contains all the system environment information. See SysEnvRec for
	details of the return values.
	</pre>
	* \returns <pre>an OSErr; an integer Error Code . It will be one of:
	noErr(0) No error
	envNotPresent (-5500) _SysEnvirons trap not present
	envBadVers (-5501) negative number used in verReqNo
	envVersTooBig (-5502) verReqNo version not handled by this system
	</pre>
	* \note <pre>SysEnvirons obtains the ROM version number, such as the CPU type,
	whether or not color Quickdraw is present, keyboard type, and so forth.
	Macintosh Technote #129 warns that values may be added to the acceptable
	set of values for any field of the SysEnvRec without warning. Therefore, if
	you are calling SysEnvirons you should be prepared to handle unexpected
	values.
	The constant curSysEnvVers contains the current version of
	SysEnvirons . By using this constant rather than a hard coded version
	number you can reduce the changes that may need to be made to your source
	as SysEnvirons evolves. However, you should be prepared to handle
	unexpected values and not make assumptions about functionality based on
	current expectations. It is much safer to test for specific functionality with
	Gestalt than rely on the future contents of SysEnvirons .
	In future systems, the SysEnvRec structure may get longer, so the
	following mechanism can be used to get the most up-to-date version of this
	record:
	•Set verReqNo to a value greater than curSysEnvVers (the SysEnvRec
	version number you suspect might not be available).
	•Set theSysEnv to point to the larger structure (i.e., some future
	</pre>
	* \copyright THINK Reference © 1991-1992 Symantec Corporation
		 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	*    \carbon_lib        not available
	*    \mac_os_x         not available
	*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SysEnvirons(__D0, __A0)
#endif
		OSErr
		SysEnvirons(short versionRequested, SysEnvRec *theWorld);

#endif // CALL_NOT_IN_CARBON
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

#endif // __OSUTILS__ *      /*/*/// CALL_NOT_IN_CARBON
	   // __OSUTILS__
