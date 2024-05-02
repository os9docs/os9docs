/**
     \file       FixMath.h

    \brief   Fixed Math Interfaces.

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved
    
    \ingroup Math
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FIXMATH__
#define __FIXMATH__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

#define fixed1 ((Fixed)0x00010000L)
#define fract1 ((Fract)0x40000000L)
#define positiveInfinity ((long)0x7FFFFFFFL)
#define negativeInfinity ((long)0x80000000L)
/**
    FixRatio, FixMul, and FixRound were previously in ToolUtils.h
*/

			/** 
			\brief Get fixed-point quotient of two integers 
			
			<pre>FixRatio performs fixed-point division on two integers, returning the
quotient as a 32-bit Fixed data type.
numerand . . .
denomare 16-bit signed integers, in the range -32767 to 32767
</pre>
 * \returns <pre>a 32-bit Fixed value. The high 16 bits are the integer portion; the
low word is the fractional portion.
</pre>
 * \note <pre>This function will happily divide by 0;  if denom is 0, this returns
0x7FFFFFFF when numer is positive or 0x8000001 when numer is
negative.
This is handy for calculating the spacing needed for drawing justified text
(see SpaceExtra ).
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fixed)
FixRatio(short numer, short denom) ONEWORDINLINE(0xA869);


			/** 
			\brief Get fixed-point product of two integers 
			\param    a integers to . .
	\param    b . . . multiply
			<pre>FixMul performs fixed-point multiplication on two Fixed values, returning
the signed product (MOD 65536) as a 32-bit Fixed data type. Use this to
format the result as a Fixed data type, in case you need that type for
subsequent operations.
aand . . .
bare Fixed values, in the range -32769 to 32767. xxxx
xxxx is 1- (1/65536)
</pre>
 * \returns <pre>a 32-bit Fixed value. The high 16 bits are the integer portion; the
low word is always 0.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fixed)
FixMul(Fixed a, Fixed b) ONEWORDINLINE(0xA868);


			/** 
			\brief Get nearest short integer to a fixed-point value 
			
			<pre>FixRound rounds a positive fixed-point number, returning the value of the
nearest short integer.
fixedNum is a 4-byte fixed-point value.The function rounds correctly for
positive values only. See Notes, below
</pre>
 * \returns <pre>a 16-bit signed integer; the nearest integer to fixedNum . If the
fractional part of fixedNum  is .5, the return value is rounded up to
the next higher integer.
</pre>
 * \note <pre>To round a negative fixed-point number correctly (i.e., a larger fraction
being more negative), you should first negate fixedNum , call FixRound ,
then negate the returned integer; e.g.:
FixedunRounded;
shortrounded;
if (unRounded < 0 )
rounded = - FixRound ( -unRounded );
else
rounded = FixRound ( unRounded );
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
FixRound(Fixed x) ONEWORDINLINE(0xA86C);


			/** 
			\brief Convert a Fixed to a Fract data type 
			
			<pre>Fix2Frac returns its Fixed argument, converted into a Fract data type.
argis a 32-bit Fixed value.
</pre>
 * \returns <pre>a 32-bit Fract value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fract)
Fix2Frac(Fixed x) ONEWORDINLINE(0xA841);


			/** 
			\brief Convert a Fixed to a long data type 
			
			<pre>Fix2Long returns its Fixed argument, converted into a long data type.
argis a 32-bit Fixed value.
</pre>
 * \returns <pre>a 32-bit long value, equivalent to arg to the best precision possible
for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(long)
Fix2Long(Fixed x) ONEWORDINLINE(0xA840);


			/** 
			\brief Convert a long to a Fixed data type 
			
			<pre>Long2Fix returns its long integer argument, converted into a Fixed data
type.
argis a 32-bit long value.
</pre>
 * \returns <pre>a 32-bit Fixed value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fixed)
Long2Fix(long x) ONEWORDINLINE(0xA83F);


			/** 
			\brief Convert a Fract to a Fixed data type 
			
			<pre>Frac2Fix returns its Fract argument, converted into a Fixed data type.
argis a 32-bit Fract value.
</pre>
 * \returns <pre>a 32-bit Fixed value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fixed)
Frac2Fix(Fract x) ONEWORDINLINE(0xA842);


			/** 
			\brief Multiply Fract by Fract, long,  or Fixed 
			\param    opA multiplicand
	\param    opB multiplier
			<pre>FracMul returns the product of opA * opB.
opAand...
opBare two 32-bit values. At least one of them should be formatted as a
Fract data type.
</pre>
 * \returns <pre>a 32-bit value, whose format depends on that of the input
parameters:
opA opB returned
Fract*Fract=Fract
long*Fract=long
Fract*long=long
Fixed*Fract=Fixed
Fract*Fixed=Fixed
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fract)
FracMul(Fract x, Fract y) ONEWORDINLINE(0xA84A);


			/** 
			\brief Divide  one 32-bit quantity by another 
			\param    opA dividend
	\param    opB divisor
			<pre>FixDiv returns the quotient of opA / opB.
opAand...
opBare two 32-bit values, formatted as any of the data types long,
Fixed, or Fract.
</pre>
 * \returns <pre>a 32-bit value whose format depends on that of the input
parameters:
opA opB returned
Fixed/Fixed=Fixed
long/long=Fixed
Fract/Fract=Fixed
long/Fixed=long
Fract/Fixed=Fract
</pre>
 * \note <pre>Division by 0 yields 0x7FFFFFFF if opA is positive or 0 and 0x80000000
if opA is negative. Division overflow yields 0x7FFFFFFF for positive
results and 0x80000000 for negative results.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fixed)
FixDiv(Fixed x, Fixed y) ONEWORDINLINE(0xA84D);


			/** 
			\brief Divide one 32-bit quantity by another 
			\param    opA dividend
	\param    opB divisor
			<pre>FracDiv returns the quotient of fracA / fracB.
opAand...
opBare two 32-bit values, formatted as any of the data types long,
Fixed, or Fract.
</pre>
 * \returns <pre>a 32-bit value, whose format depends on that of the input
parameters:
opA opB returned
Fract/Fract=Fract
long/long=Fract
Fixed/Fixed=Fract
long/Fract=long
Fixed/Fract=Fixed
</pre>
 * \note <pre>Division by 0 yields 0x7FFFFFFF if opA is positive or 0 and 0x80000000
if opA is negative. Division overflow yields 0x7FFFFFFF for positive
results and 0x8000000 for negative results.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fract)
FracDiv(Fract x, Fract y) ONEWORDINLINE(0xA84B);


			/** 
			\brief Extract square root of a Fract, returning a Fract 
			\param    arg treated as an unsigned Fract, 0...4-(2^-30);
			<pre>FracSqrt returns the square root of its positive, fractional argument.
argis a 32-bit unsigned Fract data type.
</pre>
 * \returns <pre>a 32-bit Fract value, the square root of arg.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fract)
FracSqrt(Fract x) ONEWORDINLINE(0xA849);


			/** 
			\brief Extract sine of a Fixed, returning a Fract 
			
			<pre>FracSin returns the sine of its radian argument.
argis a 32-bit Fixed data type, expressed in radians.
</pre>
 * \returns <pre>a 32-bit Fract value, the sine of arg.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fract)
FracSin(Fixed x) ONEWORDINLINE(0xA848);


			/** 
			\brief Extract cosine of a Fixed, returning a Fract 
			
			<pre>FracCos returns the cosine of its radian argument.
argis a 32-bit Fixed data type, expressed in radians.
</pre>
 * \returns <pre>a 32-bit Fract value, the cosine of arg.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fract)
FracCos(Fixed x) ONEWORDINLINE(0xA847);


			/** 
			\brief Extract arctangent of the quotient of two 32-bit values 
			
			<pre>FixATan2 returns the arctangent quotient of opA / opB in radians.
opAand...
opBare two 32-bit values. Both should be the same data type; either
long, Fixed, or Fract.
</pre>
 * \returns <pre>a 32-bit Fixed value; the arctangent of opA / opB, expressed in
radians.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fixed)
FixATan2(long x, long y) ONEWORDINLINE(0xA818);

/**
    Frac2X, Fix2X, X2Fix, and X2Frac translate to and from
    the floating point type "extended" (that's what the X is for).
    On the original Mac this was 80-bits and the functions could be
    accessed via A-Traps.  When the 68881 co-processor was added,
    it used 96-bit floating point types, so the A-Traps could not
    be used.  When PowerPC was added, it used 64-bit floating point
    types, so yet another prototype was added.
*/
#if TARGET_CPU_68K
#if TARGET_RT_MAC_68881
#if CALL_NOT_IN_CARBON

			/** 
			\brief Convert a Fract to an Extended data type 
			
			<pre>Frac2X returns its Fract argument, converted into an Extended data type.
argis a 32-bit Fract value.
</pre>
 * \returns <pre>a 64-bit double value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(long double)
Frac2X(Fract x);


			/** 
			\brief Convert a Fixed to an Extended data type 
			
			<pre>Fix2X returns its Fixed argument, converted into an Extended data type.
argis a 32-bit Fixed value.
</pre>
 * \returns <pre>a 64-bit double value, equivalent to arg.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(long double)
Fix2X(Fixed x);


			/** 
			\brief Convert an Extended to a Fixed data type 
			
			<pre>X2Fix returns its Extended argument, converted into a Fixed data type.
argis an 80-bit or 96-bit Extended value.
</pre>
 * \returns <pre>a 32-bit Fixed value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Fixed)
X2Fix(long double x);


			/** 
			\brief Convert an Extended to a Fract data type 
			
			<pre>X2Frac returns its Extended argument, converted into a Fract data type.
argis an 80-bit or 96-bit Extended value.
</pre>
 * \returns <pre>a 32-bit Fract value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Fract)
X2Frac(long double x);

#endif /** CALL_NOT_IN_CARBON */

#else
#if CALL_NOT_IN_CARBON

			/** 
			\brief Convert a Fract to an Extended data type 
			
			<pre>Frac2X returns its Fract argument, converted into an Extended data type.
argis a 32-bit Fract value.
</pre>
 * \returns <pre>a 64-bit double value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(long double)
Frac2X(Fract x) ONEWORDINLINE(0xA845);


			/** 
			\brief Convert a Fixed to an Extended data type 
			
			<pre>Fix2X returns its Fixed argument, converted into an Extended data type.
argis a 32-bit Fixed value.
</pre>
 * \returns <pre>a 64-bit double value, equivalent to arg.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(long double)
Fix2X(Fixed x) ONEWORDINLINE(0xA843);


			/** 
			\brief Convert an Extended to a Fixed data type 
			
			<pre>X2Fix returns its Extended argument, converted into a Fixed data type.
argis an 80-bit or 96-bit Extended value.
</pre>
 * \returns <pre>a 32-bit Fixed value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Fixed)
X2Fix(long double x) ONEWORDINLINE(0xA844);


			/** 
			\brief Convert an Extended to a Fract data type 
			
			<pre>X2Frac returns its Extended argument, converted into a Fract data type.
argis an 80-bit or 96-bit Extended value.
</pre>
 * \returns <pre>a 32-bit Fract value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Fract)
X2Frac(long double x) ONEWORDINLINE(0xA846);

#endif /** CALL_NOT_IN_CARBON */

#endif /** TARGET_RT_MAC_68881 */

#else

			/** 
			\brief Convert a Fract to an Extended data type 
			
			<pre>Frac2X returns its Fract argument, converted into an Extended data type.
argis a 32-bit Fract value.
</pre>
 * \returns <pre>a 64-bit double value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(double)
Frac2X(Fract x);


			/** 
			\brief Convert a Fixed to an Extended data type 
			
			<pre>Fix2X returns its Fixed argument, converted into an Extended data type.
argis a 32-bit Fixed value.
</pre>
 * \returns <pre>a 64-bit double value, equivalent to arg.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(double)
Fix2X(Fixed x);


			/** 
			\brief Convert an Extended to a Fixed data type 
			
			<pre>X2Fix returns its Extended argument, converted into a Fixed data type.
argis an 80-bit or 96-bit Extended value.
</pre>
 * \returns <pre>a 32-bit Fixed value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fixed)
X2Fix(double x);


			/** 
			\brief Convert an Extended to a Fract data type 
			
			<pre>X2Frac returns its Extended argument, converted into a Fract data type.
argis an 80-bit or 96-bit Extended value.
</pre>
 * \returns <pre>a 32-bit Fract value, equivalent to arg to the best precision
possible for the data type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fract)
X2Frac(double x);

#endif /** TARGET_CPU_68K */

/** QuickTime 3.0 makes these Wide routines available on other platforms*/
#if TARGET_CPU_PPC || !TARGET_OS_MAC
/**
 *  WideCompare()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(short)
WideCompare(const wide *target, const wide *source);

/**
 *  WideAdd()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(wide *)
WideAdd(wide *target, const wide *source);

/**
 *  WideSubtract()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(wide *)
WideSubtract(wide *target, const wide *source);

/**
 *  WideNegate()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(wide *)
WideNegate(wide *target);

/**
 *  WideShift()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(wide *)
WideShift(wide *target, long shift);

/**
 *  WideSquareRoot()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(unsigned long)
WideSquareRoot(const wide *source);

/**
 *  WideMultiply()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(wide *)
WideMultiply(long multiplicand, long multiplier, wide *target);

/** returns the quotient */
/**
 *  WideDivide()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(long)
WideDivide(const wide *dividend, long divisor, long *remainder);

/** quotient replaces dividend */
/**
 *  WideWideDivide()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(wide *)
WideWideDivide(wide *dividend, long divisor, long *remainder);

/**
 *  WideBitShift()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(wide *)
WideBitShift(wide *src, long shift);

#endif /** TARGET_CPU_PPC || !TARGET_OS_MAC */

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

#endif /** __FIXMATH__ */
*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/