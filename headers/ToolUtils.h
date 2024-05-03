/**
	 \file       ToolUtils.h

	\brief   Toolbox Utilities Interfaces.

	\introduced_in  System 7.5
	\avaliable_from Universal Interfaces 3.4.1

	\copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

	\ingroup CommunicationsToolbox

	For bug reports, consult the following page on
				 the World Wide Web:

					 http://developer.apple.com/bugreporter/

*/
#ifndef __TOOLUTILS__
#define __TOOLUTILS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FIXMATH__
#include <FixMath.h>
#endif

#ifndef __TEXTUTILS__
#include <TextUtils.h>
#endif

#ifndef __ICONS__
#include <Icons.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
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

	/**
	©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
		Note:

		The following routines that used to be in this header file, have moved to
		more appropriate headers.

			FixMath.h:      FixMul
							FixRatio
							FixRound

			Icons.h:        GetIcon
							PlotIcon

			Quickdraw.h:    AngleFromSlope
							DeltaPoint
							GetCursor
							GetIndPattern
							GetPattern
							GetPicture
							PackBits
							ScreenRes
							ShieldCursor
							SlopeFromAngle
							UnpackBits

			TextUtils.h:    Munger
							GetIndString
							GetString
							NewString
							SetString
	©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
	*/

	/**
	\brief Determine state of a bit in a bit string

	<pre>Any bit in the bit string can be accessed individually via BitTst, BitSet,
and BitClr. Other Toolbox BitXxx functions apply to bitwise operations
between long integers and not relevant for C programmers.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
	Boolean
	BitTst(const void *bytePtr, long bitNum);

	/**
	\brief Set a specified bit in a bit string to a 1


	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
	void
	BitSet(void *bytePtr, long bitNum);

	/**
	\brief Clear a specified bit in a bit string to a 0

	<pre>BitClr clears a specified bit in a bit string to a 0.
bytePtr is the address of the first byte of a sequence of bytes.
bitNumidentifies the bit to clear. It is a positive offset from the first bit in
the byte addressed by bytePtr. Bits are identified by a logical
mapping (matching that used for screen pixels), rather than the
normal high-to-low numbering used in CPU operations. See BitTst
for details.
</pre>
* \returns <pre>none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
	void
	BitClr(void *bytePtr, long bitNum);

	/**
	\brief Obtain bitwise AND of two 32-bit longs
	\param    op1 32-bit value to be masked
\param    op2 32-bit mask to apply
	<pre>BitAnd returns the logical product (a bitwise AND) of two 32-bit values.
The operands are not changed.
op1and . . .
op2are 32-bit long operands. The bit pattern of op1 is masked by the
bits of op2.
</pre>
* \returns <pre>a long integer; the result of ( op1 & op2 ).
</pre>
* \note <pre>Bits in op1 that are also set in op2 are set to 1 in the result. All other
bits of the result are cleared to 0. Note that op1 and op2 can be in either
order without affecting the result.
This capability is native to the CPU and can be performed much faster
using the C & (bitwise AND) operator.
longx, op1, op2;
x = BitAnd( op1, op2); // is equivalent to . . . 	x = op1 & op2; // . . . and this is MUCH faster 	</ pre>
				* \copyright THINK Reference © 1991 - 1992 Symantec Corporation
														  *    \non_carbon_cfm in InterfaceLib 7.1 and
		later
			*    \carbon_lib in CarbonLib 1.0 and
		later
			*    \mac_os_x in version 10.0 and
		later*/
	long
	BitAnd(long value1, long value2);

	/**
	\brief Obtain bitwise OR of two 32-bit longs
	\param    op1 32-bit values . . .
\param    op2 . . . to be ORed
	<pre>BitOr returns the logical sum (a bitwise OR) of two 32-bit values. The
operands are not changed.
op1and . . .
op2are 32-bit long operands.
</pre>
* \returns <pre>a long integer; the result of ( op1 | op2 ).
</pre>
* \note <pre>Bits that are set in either op1 or op2 are set to 1 in the result. All other
bits of the result are cleared to 0.
This capability is native to the CPU and can be performed much faster
using the C | (bitwise OR) operator or the Assembler OR or ORI opcode.
longx, op1, op2;
x = BitOr( op1, op2); // is equivalent to . . . 	x = op1 | op2; // . . . and this is MUCH faster 	</ pre>
				* \copyright THINK Reference © 1991 - 1992 Symantec Corporation
														  *    \non_carbon_cfm in InterfaceLib 7.1 and
		later
			*    \carbon_lib in CarbonLib 1.0 and
		later
			*    \mac_os_x in version 10.0 and
		later*/
	long
	BitOr(long value1, long value2);

	/**
	\brief Obtain bitwise XOR of two 32-bit longs
	\param    op1 32-bit values . . .
\param    op2 . . . to be XORed
	<pre>BitXor returns the exclusive OR (a bitwise XOR) of two 32-bit values. The
operands are not changed.
op1and . . .
op2are 32-bit long operands.
</pre>
* \returns <pre>a long integer; the result of ( op1 ^ op2 ).
</pre>
* \note <pre>A bit in the result is set to 1 when bits of op1 and op2 contain opposite
values; other bits are cleared.  Alternative explanation: the bits of op2
"toggle" the bits of op1 .
This capability is native to the CPU and can be performed much faster
using the C ^ (bitwise XOR) operator.
longx, op1, op2;
x = BitXor( op1, op2); // is equivalent to . . . 	x = op1 ^ op2; // . . . and this is MUCH faster 	</ pre>
				* \copyright THINK Reference © 1991 - 1992 Symantec Corporation
														  *    \non_carbon_cfm in InterfaceLib 7.1 and
		later
			*    \carbon_lib in CarbonLib 1.0 and
		later
			*    \mac_os_x in version 10.0 and
		later*/
	long
	BitXor(long value1, long value2);

	/**
	\brief Obtain bitwise NOT (complement) of two longs

	<pre>BitNot returns the complement (a bitwise NOT) of a 32-bit operand.
operand is a 32-bit long operand.
</pre>
* \returns <pre>a long integer; the result of ~operand.
</pre>
* \note <pre>Bits of operand that are 0 are set to 1 in the result; all other bits of the
result are cleared to 0.
This capability is native to the CPU and can be performed much faster
using the C ~ (bitwise NOT) operator.
longx, operand;
x = BitNot( operand); // is equivalent to . . . 	x = ~operand; // . . . and this is MUCH faster 	</ pre>
				* \copyright THINK Reference © 1991 - 1992 Symantec Corporation
														  *    \non_carbon_cfm in InterfaceLib 7.1 and
		later
			*    \carbon_lib in CarbonLib 1.0 and
		later
			*    \mac_os_x in version 10.0 and
		later*/
	long
	BitNot(long value);

	/**
	\brief Obtain result of left- or right-shifted 32-bit value
	\param    op 32-bit values to be shifted
	<pre>BitShift returns the value of bit-shifted a 32-bit operand. Bit shifting can
be used for fast multiplication and division by a power of 2.
opis a 32-bit long operand.
countspecifies the direction and extent of the shift operation. The bits are
shifted ABS( count ) positions. count is always treated MOD 32
(should range from -31 to +31).
<0(negative values) shift to the right
>0(positive values) shift to the left
0Nothing happens
</pre>
* \returns <pre>a long integer; the result of ( op << count ) or (op >> (-count )).
</pre>
* \note <pre>Bits of op are shifted either right or left, depending on the sign of count .
Bits shifted off the end are lost and the vacated positions are cleared to 0.
Note that a left shift is the same as an unsigned multiplication by 2, 4, 8,
etc.  A right shift is the same as unsigned division by 2, 4, 8, etc.
This capability is native to the CPU and can be performed much faster
using the C >> and << (bitwise shift) operators or the assembler LSL or
LSR opcodes.
longx, operand;
shortcount;
x = BitShift ( operand, count ); // is equivalent to . . .
x = operand << count;	 // if count is positive or . . .
x = operand >> (-count); // if count is negative 	</ pre>
				* \copyright THINK Reference © 1991 - 1992 Symantec Corporation
														  *    \non_carbon_cfm in InterfaceLib 7.1 and
		later
			*    \carbon_lib in CarbonLib 1.0 and
		later
			*    \mac_os_x in version 10.0 and
		later*/
	long
	BitShift(long value, short count);

#if TARGET_CPU_68K
	/**
	<pre>
	 * \note <pre>The Int64Bit structure is used in calls to LongMul .
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct Int64Bit
	{
		longhiLong; /**<  Most significant -bits of -bit value*/
		longloLong; /**<  Least significant -bits of -bit value*/
	} IntBit;		/**< */

	typedef struct Int64Bit Int64Bit;
#if CALL_NOT_IN_CARBON

	/**
	\brief Obtain 64-bit product of two 32-bit longs

	<pre>LongMul performs 32-bit signed multiplication, storing the 64-bit signed
product into a specified structure.
a32and . . .
b32are any two 32-bit longs.
dest64is the address of an 8-byte Int64Bit structure. Upon return, it will
contain the signed 64-bit product of ( a32 * b32 ).
</pre>
* \returns <pre>none
</pre>
* \note <pre>The multiplicand range (i.e., the range of any signed long) is
±2,147,483,647 (i.e., ±2G).
The toolbox provides no corresponding 64-bit division function.
Use FixMul to multiply fixed-point values.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   not available
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	void
	LongMul(long a, long b, Int64Bit *result);

#else
#define LongMul(a, b, result) ((void)WideMultiply((a), (b), (wide *)(result)))
#endif // CALL_NOT_IN_CARBON
#endif // TARGET_CPU_68K
#define HiWord(x) ((short)((long)(x) >> 16))
#define LoWord(x) ((short)(x))

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

#endif // __TOOLUTILS__ *   /*/*/