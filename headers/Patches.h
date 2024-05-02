/**
	 \file       Patches.h

	\brief   Patch Manager Interfaces.

	\introduced_in  System 8
	\avaliable_from Universal Interfaces 3.4.1

	\copyright © 1994-2001 by Apple Computer, Inc., all rights reserved

	\ingroup Managers

	For bug reports, consult the following page on
				 the World Wide Web:

					 http://developer.apple.com/bugreporter/

*/

#ifndef __PATCHES__
#define __PATCHES__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

#if CALL_NOT_IN_CARBON
	enum
	{
		kOSTrapType = 0,
		kToolboxTrapType = 1
	};

	typedef SignedByte TrapType;
	enum
	{
		OSTrap = kOSTrapType,		/** old name */
		ToolTrap = kToolboxTrapType /** old name */
	};

#endif /** CALL_NOT_IN_CARBON */

/**
	GetTrapAddress and SetTrapAddress are obsolete and should not
	be used. Always use NGetTrapAddress and NSetTrapAddress instead.
	The old routines will not be supported for PowerPC apps.
*/
#if TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#if CALL_NOT_IN_CARBON

	/**
	\brief Obtain address of code executing system functions

	<pre>GetTrapAddress returns the address of a system routine - an element of the
trap dispatch table. This can be used to intercept or patch ROM routines. Use
NGetTrapAddress , GetToolTrapAddress or GetOSTrapAddress if you
know you are running on 128K ROMs or later (see About Compatibility for
more information).
trapNum identifies the ROM routine whose address you want.
</pre>
* \returns <pre>a 32-bit value; the address of the system routine that corresponds
to trapNum .
</pre>
* \note <pre>GetTrapAddress can help you to speed up your program. Also, if you
know what you're doing, its possible to intercept OS or Toolbox calls and
perform pre- or post-processing, or even replace the function altogether.
Note: If a ROM routine has already been patched, you should NOT do any
post-processing. And in any case, you must preserve the registers and
maintain the stack. Check the return value of GetTrapAddress against the
global variable ROMBase to see if the trap has already been redirected to a
RAM address (lower in memory than ROM).
If you call a ROM or OS routine directly instead of using a trap or glue, you
lose one level of register saves. Be aware that registers A2-A6 and D3-D7
will be preserved, but all others may be modified.
The trap dispatcher changed between the 64K and 128K ROMs. Before
using GetTrapAddress or NGetTrapAddress , see
About Compatibility to check the ROM version and be aware that the
value of trapNum  must be correct for that version of the ROM.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   not available
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 GetTrapAddress(__D0)
#endif
	UniversalProcPtr
	GetTrapAddress(UInt16 trapNum) ONEWORDINLINE(0xA146);

	/**
	\brief Install custom code to replace a system routine

	<pre>SetTrapAddress changes an element of the trap dispatch table so that
subsequent invocations of that trap will cause execution to go to a specified
address. Use NSetTrapAddress , SetToolTrapAddress or
SetOSTrapAddress if you know you are running on a 128K ROM or later.
trapAddr is the address of code to handle execution of an Operating System or
Toolbox function. For the 64K ROMs, this value must be less than
64K (you can allocate a 6-byte record in the system heap and fill it
with a jump to your code).
trapNum identifies the ROM routine you wish to replace. See TrapWords for a
list.
</pre>
* \returns <pre>none
</pre>
* \note <pre>Be sure not to depend on register A5 within your patch. This is because you
may have intercepted a trap used by a desk accessory. Use SetCurrentA5
and SetA5 to be sure you do it right.
Note: Be sure to change all traps back to their original addresses before
your application exits!
The trap dispatcher changed between the 64K and 128K ROMs. For more
information, see About Compatibility .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   not available
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetTrapAddress(__A0, __D0)
#endif
	void
	SetTrapAddress(UniversalProcPtr trapAddr, UInt16 trapNum) ONEWORDINLINE(0xA047);

#endif /** CALL_NOT_IN_CARBON */

#endif /** TARGET_CPU_68K && !TARGET_RT_MAC_CFM */

#if CALL_NOT_IN_CARBON

	/**
	\brief Obtain address of system functions

	<pre>NGetTrapAddress returns the address of a system routine - an element of
the trap dispatch table. Starting with the 128K ROMs, the Toolbox routines
have a trap dispatch table separate from the Operating System routines. You
must use this function (and not GetTrapAddress ) if you are running with
128K ROMs or later (see About Compatibility ).
trapNum identifies the ROM routine whose address you want. See TrapWords
for a list.
trapType differentiates between traps by type, since the 128K ROMs uses
two separate trap dispatch tables. This must be one of:
OSTrap (0)Operating System trap
ToolTrap (1)Toolbox trap
</pre>
* \returns <pre>a 32-bit value; the address of the system routine that corresponds
to trapNum .
</pre>
* \note <pre>There is a new interface to this routine, consisting of the calls
GetToolTrapAddress and GetOSTrapAddress . These calls do not
require the specification of the trap type as a parameter.
It is possible to intercept OS or Toolbox calls and perform pre- or
post-processing, or even replace the function altogether. This sort of
custom patching is normally written in assembly language.
There is a great deal of overhead involved in the Macintosh trap dispatch
mechanism. In time-critical situations, you may save a significant amount
of time by calling the system routine directly, rather than using the normal
invocation of a trap.
The trap dispatcher changed between the 64K and 128K ROMs.See
About Compatibility for more information.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	UniversalProcPtr
	NGetTrapAddress(UInt16 trapNum, TrapType tTyp);

	/**
	\brief Install custom code to replace a system routine

	<pre>NSetTrapAddress changes an element of the trap dispatch table so that
subsequent invocations of that trap will cause execution to go to a specified
address. Use this function (and not SetTrapAddress ) if your application
will run in a Mac equipped with a ROM version later than the 64K ROMs (see
About Compatibility ).
trapAddr is the address of some code to handle execution of an Operating
System or Toolbox function.
trapNum identifies the ROM routine you wish to replace. See TrapWords for a
list.
trapType differentiates between traps by type, since the 128K ROMs use two
separate trap dispatch tables. This must be one of:
OSTrap (0)Operating System trap
ToolTrap (1)Toolbox trap
</pre>
* \returns <pre>none
</pre>
* \note <pre>There is a new interface to this routine, consisting of the calls
SetToolTrapAddress and SetOSTrapAddress . These calls do not
require the specification of the trap type as a parameter.
NSetTrapAddress is used mostly by assembly-language programers . It
is most often used in device drivers of INIT code, rather an by an
application.
Note: Be sure to change all traps back to their original addresses before
your application exits!
The trap dispatcher changed between the 64K and 128K ROMs. For more
information see About Compatibility .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	void
	NSetTrapAddress(UniversalProcPtr trapAddr, UInt16 trapNum, TrapType tTyp);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON

	/**
	\brief GetOSTrapAddress Obtain address of operating system function

	<pre>GetOSTrapAddress returns the address of a system routine - an element of
the operating system trap dispatch table. Starting with the 128K ROMs, the
Toolbox routines have a trap dispatch table separate from the Operating System
routines. You must use this function (and not GetTrapAddress ) if you are
running with 128K ROMs or later (see About Compatibility ).
trapNum identifies the ROM routine whose address you want. See TrapWords
for a list.
</pre>
* \returns <pre>a 32-bit value; the address of the system routine that corresponds
to trapNum .
</pre>
* \note <pre>GetOSTrapAddress is part of a new interface to the routine
NGetTrapAddress . GetOSTrapAddress does not require the
specification of the trap type as a parameter as NGetTrapAddress does.
Instead, either GetToolTrapAddress or GetOSTrapAddress should be
called, depending on which trap dispatch table you wish to modify. It is
recommended that you use one of these routines in place of
NGetTrapAddress . See About Compatibility for more information on
tool traps and OS traps.
It is possible to intercept OS or Toolbox calls and perform pre- or
post-processing, or even replace the function altogether. This sort of
custom patching is normally written in assembly language.
There is a great deal of overhead involved in the Macintosh trap dispatch
mechanism. In time-critical situations, you may save a significant amount
of time by calling the system routine directly, rather than using the normal
invocation of a trap.
The trap dispatcher changed between the 64K and 128K ROMs.See
About Compatibility for more information.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 GetOSTrapAddress(__D0)
#endif
	UniversalProcPtr
	GetOSTrapAddress(UInt16 trapNum) ONEWORDINLINE(0xA346);

	/**
	\brief SetOSTrapAddress Install custom code to replace an operating system routine

	<pre>SetOSTrapAddress changes an element of the operating system trap
dispatch table so that subsequent invocations of that trap will cause execution
to go to a specified address. Use this function (and not SetTrapAddress ) if
your application will run in a Mac equipped with a ROM version later than the
64K ROMs (see About Compatibility ).
trapAddr is the address of some code to handle execution of a operating system
function.
trapNum identifies the ROM routine you wish to replace. See TrapWords for a
list.
</pre>
* \returns <pre>none
</pre>
* \note <pre>SetOSTrapAddress is part of a new interface to the routine
NSetTrapAddress . SetOSTrapAddress does not require the
specification of the trap type as a parameter as NSetTrapAddress does.
Instead, either SetToolTrapAddress or SetOSTrapAddress should be
called, depending on which trap dispatch table you wish to modify. It is
recommended that you use one of these routines in place of
NSetTrapAddress . See About Compatibility for more information on
tool traps and OS traps.
SetOSTrapAddress is used mostly by assembly-language programers .
It is most often used in device drivers of INIT code, rather an by an
application.
Note: Be sure to change all traps back to their original addresses before
your application exits!
The trap dispatcher changed between the 64K and 128K ROMs. For more
information see About Compatibility .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetOSTrapAddress(__A0, __D0)
#endif
	void
	SetOSTrapAddress(UniversalProcPtr trapAddr, UInt16 trapNum)
		ONEWORDINLINE(0xA247);

	/**
	\brief GetToolTrapAddress Obtain address of toolbox function

	<pre>GetToolTrapAddress returns the address of a system routine - an element
of the toolbox trap dispatch table. Starting with the 128K ROMs, the Toolbox
routines have a trap dispatch table separate from the Operating System
routines. You must use this function (and not GetTrapAddress ) if you are
running with 128K ROMs or later (see About Compatibility ).
trapNum identifies the ROM routine whose address you want. See TrapWords
for a list.
</pre>
* \returns <pre>a 32-bit value; the address of the system routine that corresponds
to trapNum .
</pre>
* \note <pre>GetToolTrapAddress is part of a new interface to the routine
NGetTrapAddress . GetToolTrapAddress does not require the
specification of the trap type as a parameter as NGetTrapAddress does.
Instead, either GetToolTrapAddress or GetOSTrapAddress should be
called, depending on which trap dispatch table you wish to modify. It is
recommended that you use one of these routines in place of
NGetTrapAddress . See About Compatibility for more information on
tool traps and OS traps.
It is possible to intercept OS or Toolbox calls and perform pre- or
post-processing, or even replace the function altogether. This sort of
custom patching is normally written in assembly language.
There is a great deal of overhead involved in the Macintosh trap dispatch
mechanism. In time-critical situations, you may save a significant amount
of time by calling the system routine directly, rather than using the normal
invocation of a trap.
The trap dispatcher changed between the 64K and 128K ROMs.See
About Compatibility for more information.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 GetToolTrapAddress(__D0)
#endif
	UniversalProcPtr
	GetToolTrapAddress(UInt16 trapNum) ONEWORDINLINE(0xA746);

	/**
	\brief SetToolTrapAddress Install custom code to replace an operating system routine

	<pre>SetToolTrapAddress changes an element of the toolbox trap dispatch table
so that subsequent invocations of that trap will cause execution to go to a
specified address. Use this function (and not SetTrapAddress ) if your
application will run in a Mac equipped with a ROM version later than the 64K
ROMs (see About Compatibility ).
trapAddr is the address of some code to handle execution of a Toolbox function.
trapNum identifies the ROM routine you wish to replace. See TrapWords for a
list.
</pre>
* \returns <pre>none
</pre>
* \note <pre>SetToolTrapAddress is part of a new interface to the routine
NSetTrapAddress . SetToolTrapAddress does not require the
specification of the trap type as a parameter as NSetTrapAddress does.
Instead, either SetToolTrapAddress or SetOSTrapAddress should be
called, depending on which trap dispatch table you wish to modify. It is
recommended that you use one of these routines in place of
NSetTrapAddress . See About Compatibility for more information on
tool traps and OS traps.
SetToolTrapAddress is used mostly by assembly-language programers .
It is most often used in device drivers of INIT code, rather an by an
application.
Note: Be sure to change all traps back to their original addresses before
your application exits!
The trap dispatcher changed between the 64K and 128K ROMs. For more
information see About Compatibility .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetToolTrapAddress(__A0, __D0)
#endif
	void
	SetToolTrapAddress(UniversalProcPtr trapAddr, UInt16 trapNum)
		ONEWORDINLINE(0xA647);

/**
 *  GetToolboxTrapAddress()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 GetToolboxTrapAddress(__D0)
#endif
	UniversalProcPtr
	GetToolboxTrapAddress(UInt16 trapNum) ONEWORDINLINE(0xA746);

/**
 *  SetToolboxTrapAddress()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetToolboxTrapAddress(__A0, __D0)
#endif
	void
	SetToolboxTrapAddress(UniversalProcPtr trapAddr, UInt16 trapNum)
		ONEWORDINLINE(0xA647);

#endif /** CALL_NOT_IN_CARBON */

#if TARGET_CPU_PPC
#if CALL_NOT_IN_CARBON
	/**
	 *  GetTrapVector()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	UniversalProcHandle
	GetTrapVector(UInt16 trapNumber);

#endif /** CALL_NOT_IN_CARBON */

#endif /** TARGET_CPU_PPC */

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

#endif /** __PATCHES__ */
* /*/*/ * /*/*/ */*/