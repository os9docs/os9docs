/**
     \file       fp.h

    \brief   FPCE Floating-Point Definitions and Declarations.

    \introduced_in  MathLib v2
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1987-2001 by Apple Computer, Inc., all rights reserved.

    \defgroup Misc

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FP__
#define __FP__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

/********************************************************************************
 *                                                                               *
 *    A collection of numerical functions designed to facilitate a wide * range
 *of numerical programming as required by C9X.                         *
 *                                                                               *
 *    The <fp.h> declares many functions in support of numerical programming. *
 *    It provides a superset of <math.h> and <SANE.h> functions.  Some *
 *    functionality previously found in <SANE.h> and not in the FPCE <fp.h> *
 *    can be found in this <fp.h> under the heading "__NOEXTENSIONS__". *
 *                                                                               *
 *    All of these functions are IEEE 754 aware and treat exceptions, NaNs, *
 *    positive and negative zero and infinity consistent with the floating- *
 *    point standard. *
 *                                                                               *
 ********************************************************************************/

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

/********************************************************************************
 *                                                                               *
 *                            Efficient types *
 *                                                                               *
 *    float_t         Most efficient type at least as wide as float * double_t
 *Most efficient type at least as wide as double             *
 *                                                                               *
 *      CPU            float_t(bits)                double_t(bits) *
 *    --------        -----------------            ----------------- * PowerPC
 *float(32)                    double(64)                   * 68K long
 *double(80/96)           long double(80/96)           * x86 double(64)
 *double(64)                   *
 *                                                                               *
 ********************************************************************************/
#if defined(__MWERKS__) && defined(__cmath__)
/* these types were already defined in MSL's math.h */
#else
#if TARGET_CPU_PPC
typedef float float_t;
typedef double double_t;
#elif TARGET_CPU_68K
typedef long double float_t;
typedef long double double_t;
#elif TARGET_CPU_X86
typedef double float_t;
typedef double double_t;
#elif TARGET_CPU_MIPS
typedef double float_t;
typedef double double_t;
#elif TARGET_CPU_ALPHA
typedef double float_t;
typedef double double_t;
#elif TARGET_CPU_SPARC
typedef double float_t;
typedef double double_t;
#else
#error unsupported CPU
#endif /*  */

/********************************************************************************
 *                                                                               *
 *                              Define some constants. *
 *                                                                               *
 *    HUGE_VAL            IEEE 754 value of infinity. * INFINITY            IEEE
 *754 value of infinity.                            * NAN                 A
 *generic NaN (Not A Number).                          * DECIMAL_DIG Satisfies
 *the constraint that the conversion from      * double to decimal and back is
 *the identity function.   *
 *                                                                               *
 ********************************************************************************/
#if TARGET_OS_MAC
#if TARGET_RT_MAC_MACHO
#define HUGE_VAL 1e500 /* compatible with bsd math.h */
#else
#define HUGE_VAL __inf()
#endif
#define INFINITY __inf()
#define NAN nan("255")
#else
#define NAN sqrt(-1)
#endif

#if TARGET_CPU_PPC
#define DECIMAL_DIG 17 /* does not exist for double-double */
#elif TARGET_CPU_68K
#define DECIMAL_DIG 21
#endif
#endif /* __MWERKS__ && __cmath__ */
#if TARGET_OS_MAC
/* MSL already defines these */
#if !defined(__MWERKS__) || !defined(__cmath__)
  /********************************************************************************
   *                                                                               *
   *                            Trigonometric functions *
   *                                                                               *
   *   acos        result is in [0,pi]. * asin        result is in [-pi/2,pi/2]. *
   *   atan        result is in [-pi/2,pi/2]. * atan2       Computes the arc
   *tangent of y/x in [-pi,pi] using the sign of   * both arguments to determine
   *the quadrant of the computed value. *
   *                                                                               *
   ********************************************************************************/
  /**
   *  cos()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t cos(double_t x);

  /**
   *  sin()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t sin(double_t x);

  /**
   *  tan()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t tan(double_t x);

  /**
   *  acos()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t acos(double_t x);

  /**
   *  asin()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t asin(double_t x);

  /**
   *  atan()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t atan(double_t x);

  /**
   *  atan2()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t atan2(double_t y, double_t x);

  /********************************************************************************
   *                                                                               *
   *                              Hyperbolic functions *
   *                                                                               *
   ********************************************************************************/
  /**
   *  cosh()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t cosh(double_t x);

  /**
   *  sinh()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t sinh(double_t x);

  /**
   *  tanh()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t tanh(double_t x);

  /**
   *  acosh()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t acosh(double_t x);

  /**
   *  asinh()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t asinh(double_t x);

  /**
   *  atanh()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t atanh(double_t x);

  /********************************************************************************
   *                                                                               *
   *                              Exponential functions *
   *                                                                               *
   *   expm1       expm1(x) = exp(x) - 1.  But, for small enough arguments, *
   *               expm1(x) is expected to be more accurate than exp(x) - 1. *
   *   frexp       Breaks a floating-point number into a normalized fraction * and
   *an integral power of 2.  It stores the integer in the       * object pointed
   *by *exponent.                                    * ldexp       Multiplies a
   *floating-point number by an integer power of 2.    * log1p       log1p = log(1
   *+ x). But, for small enough arguments,            * log1p is expected to be
   *more accurate than log(1 + x).          * logb        Extracts the exponent of
   *its argument, as a signed integral     * value. A subnormal argument is
   *treated as though it were first  * normalized. Thus: * 1   <=   x *
   *2^(-logb(x))   <   2            * modf        Returns fractional part of x as
   *function result and returns     * integral part of x via iptr. Note C9X uses
   *double not double_t. * scalb       Computes x * 2^n efficently.  This is not
   *normally done by      * computing 2^n explicitly. *
   *                                                                               *
   ********************************************************************************/
  /**
   *  exp()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t exp(double_t x);

  /**
   *  expm1()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t expm1(double_t x);

  /**
   *  exp2()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t exp2(double_t x);

  /**
   *  frexp()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t frexp(double_t x, int *exponent);

  /**
   *  ldexp()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t ldexp(double_t x, int n);

  /**
   *  log()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t log(double_t x);

  /**
   *  log2()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t log2(double_t x);

  /**
   *  log1p()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t log1p(double_t x);

  /**
   *  log10()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t log10(double_t x);

  /**
   *  logb()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t logb(double_t x);

#if !TYPE_LONGDOUBLE_IS_DOUBLE
  /**
   *  modfl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double modfl(long double x, long double *iptrl);

#endif /* !TYPE_LONGDOUBLE_IS_DOUBLE */

  /**
   *  modf()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t modf(double_t x, double_t *iptr);

  /**
   *  modff()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  float modff(float x, float *iptrf);

  /**
      Note: For compatiblity scalb(x,n) has n of type
              int  on Mac OS X
              long on Mac OS
  */
  typedef long _scalb_n_type;
  /**
   *  scalb()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t scalb(double_t x, _scalb_n_type n);

  /********************************************************************************
   *                                                                               *
   *                     Power and absolute value functions *
   *                                                                               *
   *   hypot       Computes the square root of the sum of the squares of its *
   *               arguments, without undue overflow or underflow. * pow Returns x
   *raised to the power of y.  Result is more accurate    * than using
   *exp(log(x)*y).                                       *
   *                                                                               *
   ********************************************************************************/
  /**
   *  fabs()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t fabs(double_t x);

  /**
   *  hypot()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t hypot(double_t x, double_t y);

  /**
   *  pow()
   *

   *    \non_carbon_cfm   in MathLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t pow(double_t x, double_t y);

  /**
   *  sqrt()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t sqrt(double_t x);

  /********************************************************************************
   *                                                                               *
   *                        Gamma and Error functions *
   *                                                                               *
   *   erf         The error function. * erfc        Complementary error function.
   ** gamma       The gamma function. * lgamma      Computes the base-e logarithm
   *of the absolute value of          * gamma of its argument x, for x > 0. *
   *                                                                               *
   ********************************************************************************/
  /**
   *  erf()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t erf(double_t x);

  /**
   *  erfc()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t erfc(double_t x);

  /**
   *  gamma()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t gamma(double_t x);

  /**
   *  lgamma()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t lgamma(double_t x);

  /********************************************************************************
   *                                                                               *
   *                        Nearest integer functions *
   *                                                                               *
   *   rint        Rounds its argument to an integral value in floating point *
   *               format, honoring the current rounding direction. *
   *                                                                               *
   *   nearbyint   Differs from rint only in that it does not raise the inexact *
   *               exception. It is the nearbyint function recommended by the *
   *               IEEE floating-point standard 854. *
   *                                                                               *
   *   rinttol     Rounds its argument to the nearest long int using the current *
   *               rounding direction.  NOTE: if the rounded value is outside *
   *               the range of long int, then the result is undefined. *
   *                                                                               *
   *   round       Rounds the argument to the nearest integral value in floating *
   *               point format similar to the Fortran "anint" function. That is:
   ** add half to the magnitude and chop.                             *
   *                                                                               *
   *   roundtol    Similar to the Fortran function nint or to the Pascal round. *
   *               NOTE: if the rounded value is outside the range of long int, *
   *               then the result is undefined. *
   *                                                                               *
   *   trunc       Computes the integral value, in floating format, nearest to *
   *               but no larger in magnitude than its argument.   NOTE: on 68K *
   *               compilers when using -elems881, trunc must return an int *
   *                                                                               *
   ********************************************************************************/
  /**
   *  ceil()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t ceil(double_t x);

  /**
   *  floor()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t floor(double_t x);

  /**
   *  rint()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t rint(double_t x);

  /**
   *  nearbyint()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t nearbyint(double_t x);

  /**
   *  rinttol()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long rinttol(double_t x);

  /**
   *  round()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t round(double_t x);

  /**
   *  roundtol()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long roundtol(double_t round);

/**
    Note: For compatiblity trunc(x) has a return type of
            int       for classic 68K with FPU enabled
            double_t  everywhere else
*/
#if TARGET_RT_MAC_68881
  typedef int _trunc_return_type;
#else
  typedef double_t _trunc_return_type;
#endif /* TARGET_RT_MAC_68881 */

  /**
   *  trunc()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  _trunc_return_type trunc(double_t x);

  /********************************************************************************
   *                                                                               *
   *                            Remainder functions *
   *                                                                               *
   *   remainder       IEEE 754 floating point standard for remainder. * remquo
   *SANE remainder.  It stores into 'quotient' the 7 low-order  * bits of the
   *integer quotient x/y, such that:                * -127 <= quotient <= 127. *
   *                                                                               *
   ********************************************************************************/
  /**
   *  fmod()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t fmod(double_t x, double_t y);

  /**
   *  remainder()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t remainder(double_t x, double_t y);

  /**
   *  remquo()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t remquo(double_t x, double_t y, int *quo);

  /********************************************************************************
   *                                                                               *
   *                             Auxiliary functions *
   *                                                                               *
   *   copysign        Produces a value with the magnitude of its first argument *
   *                   and sign of its second argument.  NOTE: the order of the *
   *                   arguments matches the recommendation of the IEEE 754 *
   *                   floating point standard,  which is opposite from the SANE *
   *                   copysign function. *
   *                                                                               *
   *   nan             The call 'nan("n-char-sequence")' returns a quiet NaN *
   *                   with content indicated through tagp in the selected * data
   *type format.                                           *
   *                                                                               *
   *   nextafter       Computes the next representable value after 'x' in the *
   *                   direction of 'y'.  if x == y, then y is returned. *
   *                                                                               *
   ********************************************************************************/
  /**
   *  copysign()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t copysign(double_t x, double_t y);

  /**
   *  nan()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double nan(const char *tagp);

  /**
   *  nanf()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  float nanf(const char *tagp);

  /**
   *  nanl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double nanl(const char *tagp);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double nanl(const char *tagp) { return (long double)nan(tagp); }
#else
#define nanl(tagp) ((long double)nan(tagp))
#endif
#endif

  /**
   *  nextafterd()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double nextafterd(double x, double y);

  /**
   *  nextafterf()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  float nextafterf(float x, float y);

  /**
   *  nextafterl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double nextafterl(long double x, long double y);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double nextafterl(long double x, long double y)
  {
    return (long double)nextafterd((double)(x), (double)(y));
  }
#else
#define nextafterl(x, y) ((long double)nextafterd((double)(x), (double)(y)))
#endif
#endif

  /**
   *  __fpclassifyd()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long __fpclassifyd(double x);

  /**
   *  __fpclassifyf()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long __fpclassifyf(float x);

  /**
   *  __fpclassify()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long __fpclassify(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long __fpclassify(long double x) { return __fpclassifyd((double)(x)); }
#else
#define __fpclassify(x) (__fpclassifyd((double)(x)))
#endif
#endif

  /**
   *  __isnormald()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long __isnormald(double x);

  /**
   *  __isnormalf()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long __isnormalf(float x);

  /**
   *  __isnormal()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long __isnormal(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long __isnormal(long double x) { return __isnormald((double)(x)); }
#else
#define __isnormal(x) (__isnormald((double)(x)))
#endif
#endif

  /**
   *  __isfinited()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long __isfinited(double x);

  /**
   *  __isfinitef()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long __isfinitef(float x);

  /**
   *  __isfinite()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long __isfinite(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long __isfinite(long double x) { return __isfinited((double)(x)); }
#else
#define __isfinite(x) (__isfinited((double)(x)))
#endif
#endif

  /**
   *  __isnand()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long __isnand(double x);

  /**
   *  __isnanf()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long __isnanf(float x);

  /**
   *  __isnan()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long __isnan(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long __isnan(long double x) { return __isnand((double)(x)); }
#else
#define __isnan(x) (__isnand((double)(x)))
#endif
#endif

  /**
   *  __signbitd()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long __signbitd(double x);

  /**
   *  __signbitf()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long __signbitf(float x);

  /**
   *  __signbit()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long __signbit(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long __signbit(long double x) { return __signbitd((double)(x)); }
#else
#define __signbit(x) (__signbitd((double)(x)))
#endif
#endif

  /**
   *  __inf()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t __inf(void);

  /********************************************************************************
   *                                                                               *
   *                              Inquiry macros *
   *                                                                               *
   *   fpclassify      Returns one of the FP_� values. * isnormal        Non-zero
   *if and only if the argument x is normalized.       * isfinite        Non-zero
   *if and only if the argument x is finite.           * isnan           Non-zero
   *if and only if the argument x is a NaN.            * signbit         Non-zero
   *if and only if the sign of the argument x is       * negative.  This includes,
   *NaNs, infinities and zeros.       *
   *                                                                               *
   ********************************************************************************/
  enum
  {
    FP_SNAN = 0,     /*      signaling NaN                         */
    FP_QNAN = 1,     /*      quiet NaN                             */
    FP_INFINITE = 2, /*      + or - infinity                       */
    FP_ZERO = 3,     /*      + or - zero                           */
    FP_NORMAL = 4,   /*      all normal numbers                    */
    FP_SUBNORMAL = 5 /*      denormal numbers                      */
  };

#define fpclassify(x)                                \
  ((sizeof(x) == sizeof(double))  ? __fpclassifyd(x) \
   : (sizeof(x) == sizeof(float)) ? __fpclassifyf(x) \
                                  : __fpclassify(x))
#define isnormal(x)                                \
  ((sizeof(x) == sizeof(double))  ? __isnormald(x) \
   : (sizeof(x) == sizeof(float)) ? __isnormalf(x) \
                                  : __isnormal(x))
#define isfinite(x)                                \
  ((sizeof(x) == sizeof(double))  ? __isfinited(x) \
   : (sizeof(x) == sizeof(float)) ? __isfinitef(x) \
                                  : __isfinite(x))
#define isnan(x)                                \
  ((sizeof(x) == sizeof(double))  ? __isnand(x) \
   : (sizeof(x) == sizeof(float)) ? __isnanf(x) \
                                  : __isnan(x))
#define signbit(x)                                \
  ((sizeof(x) == sizeof(double))  ? __signbitd(x) \
   : (sizeof(x) == sizeof(float)) ? __signbitf(x) \
                                  : __signbit(x))

  /********************************************************************************
   *                                                                               *
   *                      Max, Min and Positive Difference *
   *                                                                               *
   *   fdim        Determines the 'positive difference' between its arguments: *
   *               { x - y, if x > y }, { +0, if x <= y }.  If one argument is *
   *               NaN, then fdim returns that NaN.  if both arguments are NaNs, *
   *               then fdim returns the first argument. *
   *                                                                               *
   *   fmax        Returns the maximum of the two arguments.  Corresponds to the *
   *               max function in FORTRAN.  NaN arguments are treated as missing
   ** data.  If one argument is NaN and the other is a number, then   * the number
   *is returned.  If both are NaNs then the first        * argument is returned. *
   *                                                                               *
   *   fmin        Returns the minimum of the two arguments.  Corresponds to the *
   *               min function in FORTRAN.  NaN arguments are treated as missing
   ** data.  If one argument is NaN and the other is a number, then   * the number
   *is returned.  If both are NaNs then the first        * argument is returned. *
   *                                                                               *
   ********************************************************************************/
  /**
   *  fdim()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t fdim(double_t x, double_t y);

  /**
   *  fmax()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t fmax(double_t x, double_t y);

  /**
   *  fmin()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t fmin(double_t x, double_t y);

#endif /* !defined(__MWERKS__) || !defined(__cmath__) */

  /*******************************************************************************
   *                                Constants *
   *******************************************************************************/
  /**
   *  pi
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  extern const double_t pi;
/********************************************************************************
 *                                                                               *
 *                              Non NCEG extensions *
 *                                                                               *
 ********************************************************************************/
#ifndef __NOEXTENSIONS__
  /********************************************************************************
   *                                                                               *
   *                              Financial functions *
   *                                                                               *
   *   compound        Computes the compound interest factor "(1 + rate)^periods"
   ** more accurately than the straightforward computation with   * the Power
   *function.  This is SANE's compound function.      *
   *                                                                               *
   *   annuity         Computes the present value factor for an annuity *
   *                   "(1 - (1 + rate)^(-periods)) /rate" more accurately than *
   *                   the straightforward computation with the Power function. *
   *                   This is SANE's annuity function. *
   *                                                                               *
   ********************************************************************************/
  /**
   *  compound()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t compound(double_t rate, double_t periods);

  /**
   *  annuity()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t annuity(double_t rate, double_t periods);

  /********************************************************************************
   *                                                                               *
   *                              Random function *
   *                                                                               *
   *   randomx         A pseudorandom number generator.  It uses the iteration: *
   *                               (7^5*x)mod(2^31-1) *
   *                                                                               *
   ********************************************************************************/
  /**
   *  randomx()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t randomx(double_t *x);

  /*******************************************************************************
   *                              Relational operator *
   *******************************************************************************/
  /*      relational operator      */
  typedef short relop;
  enum
  {
    GREATERTHAN = 0,
    LESSTHAN = 1,
    EQUALTO = 2,
    UNORDERED = 3
  };

#if !defined(__MWERKS__) || !defined(__cmath__)
  /**
   *  relation()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  relop relation(double_t x, double_t y);

#endif /* !defined(__MWERKS__) || !defined(__cmath__) */

/********************************************************************************
 *                                                                               *
 *                         Binary to decimal conversions *
 *                                                                               *
 *   SIGDIGLEN   Significant decimal digits. *
 *                                                                               *
 *   decimal     A record which provides an intermediate unpacked form for *
 *               programmers who wish to do their own parsing of numeric input *
 *               or formatting of numeric output. *
 *                                                                               *
 *   decform     Controls each conversion to a decimal string.  The style field
 ** is either FLOATDECIMAL or FIXEDDECIMAL. If FLOATDECIMAL, the    * value of
 *the field digits is the number of significant digits.  * If FIXEDDECIMAL value
 *of the field digits is the number of      * digits to the right of the decimal
 *point.                       *
 *                                                                               *
 *   num2dec     Converts a double_t to a decimal record using a decform. *
 *   dec2num     Converts a decimal record d to a double_t value. * dec2str
 *Converts a decform and decimal to a string using a decform.     * str2dec
 *Converts a string to a decimal struct.                          * dec2d
 *Similar to dec2num except a double is returned (68k only).      * dec2f
 *Similar to dec2num except a float is returned.                  * dec2s
 *Similar to dec2num except a short is returned.                  * dec2l
 *Similar to dec2num except a long is returned.                   *
 *                                                                               *
 ********************************************************************************/
#if TARGET_CPU_PPC
#define SIGDIGLEN 36
#elif TARGET_CPU_68K
#define SIGDIGLEN 20
#elif TARGET_CPU_X86
#define SIGDIGLEN 20
#endif
#define DECSTROUTLEN 80 /* max length for dec2str output */
#define FLOATDECIMAL ((char)(0))
#define FIXEDDECIMAL ((char)(1))
  struct decimal
  {
    char sgn; /* sign 0 for +, 1 for - */
    char unused;
    short exp; /* decimal exponent */
    struct
    {
      unsigned char length;
      unsigned char text[SIGDIGLEN]; /* significant digits */
      unsigned char unused;
    } sig;
  };
  typedef struct decimal decimal;

  struct decform
  {
    char style; /*  FLOATDECIMAL or FIXEDDECIMAL */
    char unused;
    short digits;
  };
  typedef struct decform decform;
  /**
   *  num2dec()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void num2dec(const decform *f, double_t x, decimal *d);

  /**
   *  dec2num()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double_t dec2num(const decimal *d);

  /**
   *  dec2str()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void dec2str(const decform *f, const decimal *d, char *s);

  /**
   *  str2dec()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void str2dec(const char *s, short *ix, decimal *d, short *vp);

#if TARGET_CPU_68K
#if CALL_NOT_IN_CARBON
  /**
   *  dec2d()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  double dec2d(const decimal *d);

#endif /* CALL_NOT_IN_CARBON */

#endif /* TARGET_CPU_68K */

  /**
   *  dec2f()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  float dec2f(const decimal *d);

  /**
   *  dec2s()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short dec2s(const decimal *d);

  /**
   *  dec2l()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long dec2l(const decimal *d);

/********************************************************************************
 *                                                                               *
 *                         68k-only Transfer Function Prototypes *
 *                                                                               *
 ********************************************************************************/
#if TARGET_CPU_68K
#if CALL_NOT_IN_CARBON
  /**
   *  x96tox80()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void x96tox80(const extended96 *x, extended80 *x80);

  /**
   *  x80tox96()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void x80tox96(const extended80 *x80, extended96 *x);

#endif /* CALL_NOT_IN_CARBON */

#endif /* TARGET_CPU_68K */

#endif /* !defined(__NOEXTENSIONS__) */

  /********************************************************************************
   *                                                                               *
   *                         PowerPC-only Function Prototypes *
   *                                                                               *
   ********************************************************************************/

#if TARGET_CPU_PPC
#ifndef __MWERKS__ /* Metrowerks does not support double double */

  /**
   *  cosl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double cosl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double cosl(long double x) { return (long double)cos((double)(x)); }
#else
#define cosl(x) ((long double)cos((double)(x)))
#endif
#endif

  /**
   *  sinl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double sinl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double sinl(long double x) { return (long double)sin((double)(x)); }
#else
#define sinl(x) ((long double)sin((double)(x)))
#endif
#endif

  /**
   *  tanl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double tanl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double tanl(long double x) { return (long double)tan((double)(x)); }
#else
#define tanl(x) ((long double)tan((double)(x)))
#endif
#endif

  /**
   *  acosl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double acosl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double acosl(long double x)
  {
    return (long double)acos((double)(x));
  }
#else
#define acosl(x) ((long double)acos((double)(x)))
#endif
#endif

  /**
   *  asinl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double asinl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double asinl(long double x)
  {
    return (long double)asin((double)(x));
  }
#else
#define asinl(x) ((long double)asin((double)(x)))
#endif
#endif

  /**
   *  atanl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double atanl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double atanl(long double x)
  {
    return (long double)atan((double)(x));
  }
#else
#define atanl(x) ((long double)atan((double)(x)))
#endif
#endif

  /**
   *  atan2l()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double atan2l(long double y, long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double atan2l(long double y, long double x)
  {
    return (long double)atan2((double)(y), (double)(x));
  }
#else
#define atan2l(y, x) ((long double)atan2((double)(y), (double)(x)))
#endif
#endif

  /**
   *  coshl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double coshl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double coshl(long double x)
  {
    return (long double)cosh((double)(x));
  }
#else
#define coshl(x) ((long double)cosh((double)(x)))
#endif
#endif

  /**
   *  sinhl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double sinhl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double sinhl(long double x)
  {
    return (long double)sinh((double)(x));
  }
#else
#define sinhl(x) ((long double)sinh((double)(x)))
#endif
#endif

  /**
   *  tanhl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double tanhl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double tanhl(long double x)
  {
    return (long double)tanh((double)(x));
  }
#else
#define tanhl(x) ((long double)tanh((double)(x)))
#endif
#endif

  /**
   *  acoshl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double acoshl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double acoshl(long double x)
  {
    return (long double)acosh((double)(x));
  }
#else
#define acoshl(x) ((long double)acosh((double)(x)))
#endif
#endif

  /**
   *  asinhl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double asinhl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double asinhl(long double x)
  {
    return (long double)asinh((double)(x));
  }
#else
#define asinhl(x) ((long double)asinh((double)(x)))
#endif
#endif

  /**
   *  atanhl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double atanhl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double atanhl(long double x)
  {
    return (long double)atanh((double)(x));
  }
#else
#define atanhl(x) ((long double)atanh((double)(x)))
#endif
#endif

  /**
   *  expl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double expl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double expl(long double x) { return (long double)exp((double)(x)); }
#else
#define expl(x) ((long double)exp((double)(x)))
#endif
#endif

  /**
   *  expm1l()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double expm1l(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double expm1l(long double x)
  {
    return (long double)expm1((double)(x));
  }
#else
#define expm1l(x) ((long double)expm1((double)(x)))
#endif
#endif

  /**
   *  exp2l()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double exp2l(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double exp2l(long double x)
  {
    return (long double)exp2((double)(x));
  }
#else
#define exp2l(x) ((long double)exp2((double)(x)))
#endif
#endif

  /**
   *  frexpl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double frexpl(long double x, int *exponent);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double frexpl(long double x, int *exponent)
  {
    return (long double)frexp((double)(x), (exponent));
  }
#else
#define frexpl(x, exponent) ((long double)frexp((double)(x), (exponent)))
#endif
#endif

  /**
   *  ldexpl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double ldexpl(long double x, int n);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double ldexpl(long double x, int n)
  {
    return (long double)ldexp((double)(x), (n));
  }
#else
#define ldexpl(x, n) ((long double)ldexp((double)(x), (n)))
#endif
#endif

  /**
   *  logl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double logl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double logl(long double x) { return (long double)log((double)(x)); }
#else
#define logl(x) ((long double)log((double)(x)))
#endif
#endif

  /**
   *  log1pl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double log1pl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double log1pl(long double x)
  {
    return (long double)log1p((double)(x));
  }
#else
#define log1pl(x) ((long double)log1p((double)(x)))
#endif
#endif

  /**
   *  log10l()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double log10l(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double log10l(long double x)
  {
    return (long double)log10((double)(x));
  }
#else
#define log10l(x) ((long double)log10((double)(x)))
#endif
#endif

  /**
   *  log2l()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double log2l(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double log2l(long double x)
  {
    return (long double)log2((double)(x));
  }
#else
#define log2l(x) ((long double)log2((double)(x)))
#endif
#endif

  /**
   *  logbl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double logbl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double logbl(long double x)
  {
    return (long double)logb((double)(x));
  }
#else
#define logbl(x) ((long double)logb((double)(x)))
#endif
#endif

  /**
   *  scalbl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double scalbl(long double x, long n);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double scalbl(long double x, long n)
  {
    return (long double)scalb((double)(x), (n));
  }
#else
#define scalbl(x, n) ((long double)scalb((double)(x), (n)))
#endif
#endif

  /**
   *  fabsl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double fabsl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double fabsl(long double x)
  {
    return (long double)fabs((double)(x));
  }
#else
#define fabsl(x) ((long double)fabs((double)(x)))
#endif
#endif

  /**
   *  hypotl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double hypotl(long double x, long double y);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double hypotl(long double x, long double y)
  {
    return (long double)hypot((double)(x), (double)(y));
  }
#else
#define hypotl(x, y) ((long double)hypot((double)(x), (double)(y)))
#endif
#endif

  /**
   *  powl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double powl(long double x, long double y);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double powl(long double x, long double y)
  {
    return (long double)pow((double)(x), (double)(y));
  }
#else
#define powl(x, y) ((long double)pow((double)(x), (double)(y)))
#endif
#endif

  /**
   *  sqrtl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double sqrtl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double sqrtl(long double x)
  {
    return (long double)sqrt((double)(x));
  }
#else
#define sqrtl(x) ((long double)sqrt((double)(x)))
#endif
#endif

  /**
   *  erfl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double erfl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double erfl(long double x) { return (long double)erf((double)(x)); }
#else
#define erfl(x) ((long double)erf((double)(x)))
#endif
#endif

  /**
   *  erfcl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double erfcl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double erfcl(long double x)
  {
    return (long double)erfc((double)(x));
  }
#else
#define erfcl(x) ((long double)erfc((double)(x)))
#endif
#endif

  /**
   *  gammal()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double gammal(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double gammal(long double x)
  {
    return (long double)gamma((double)(x));
  }
#else
#define gammal(x) ((long double)gamma((double)(x)))
#endif
#endif

  /**
   *  lgammal()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double lgammal(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double lgammal(long double x)
  {
    return (long double)lgamma((double)(x));
  }
#else
#define lgammal(x) ((long double)lgamma((double)(x)))
#endif
#endif

  /**
   *  ceill()
   *

   *    \non_carbon_cfm   in MathLib 2.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double ceill(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double ceill(long double x)
  {
    return (long double)ceil((double)(x));
  }
#else
#define ceill(x) ((long double)ceil((double)(x)))
#endif
#endif

  /**
   *  floorl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double floorl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double floorl(long double x)
  {
    return (long double)floor((double)(x));
  }
#else
#define floorl(x) ((long double)floor((double)(x)))
#endif
#endif

  /**
   *  rintl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double rintl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double rintl(long double x)
  {
    return (long double)rint((double)(x));
  }
#else
#define rintl(x) ((long double)rint((double)(x)))
#endif
#endif

  /**
   *  nearbyintl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double nearbyintl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double nearbyintl(long double x)
  {
    return (long double)nearbyint((double)(x));
  }
#else
#define nearbyintl(x) ((long double)nearbyint((double)(x)))
#endif
#endif

  /**
   *  rinttoll()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long rinttoll(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long rinttoll(long double x) { return rinttol((double)(x)); }
#else
#define rinttoll(x) (rinttol((double)(x)))
#endif
#endif

  /**
   *  roundl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double roundl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double roundl(long double x)
  {
    return (long double)round((double)(x));
  }
#else
#define roundl(x) ((long double)round((double)(x)))
#endif
#endif

  /**
   *  roundtoll()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long roundtoll(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long roundtoll(long double x) { return roundtol((double)(x)); }
#else
#define roundtoll(x) (roundtol((double)(x)))
#endif
#endif

  /**
   *  truncl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double truncl(long double x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double truncl(long double x)
  {
    return (long double)trunc((double)(x));
  }
#else
#define truncl(x) ((long double)trunc((double)(x)))
#endif
#endif

  /**
   *  remainderl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double remainderl(long double x, long double y);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double remainderl(long double x, long double y)
  {
    return (long double)remainder((double)(x), (double)(y));
  }
#else
#define remainderl(x, y) ((long double)remainder((double)(x), (double)(y)))
#endif
#endif

  /**
   *  remquol()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double remquol(long double x, long double y, int *quo);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double remquol(long double x, long double y, int *quo)
  {
    return (long double)remquo((double)(x), (double)(y), (quo));
  }
#else
#define remquol(x, y, quo) \
  ((long double)remquo((double)(x), (double)(y), (quo)))
#endif
#endif

  /**
   *  copysignl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double copysignl(long double x, long double y);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double copysignl(long double x, long double y)
  {
    return (long double)copysign((double)(x), (double)(y));
  }
#else
#define copysignl(x, y) ((long double)copysign((double)(x), (double)(y)))
#endif
#endif

  /**
   *  fdiml()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double fdiml(long double x, long double y);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double fdiml(long double x, long double y)
  {
    return (long double)fdim((double)(x), (double)(y));
  }
#else
#define fdiml(x, y) ((long double)fdim((double)(x), (double)(y)))
#endif
#endif

  /**
   *  fmaxl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double fmaxl(long double x, long double y);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double fmaxl(long double x, long double y)
  {
    return (long double)fmax((double)(x), (double)(y));
  }
#else
#define fmaxl(x, y) ((long double)fmax((double)(x), (double)(y)))
#endif
#endif

  /**
   *  fminl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double fminl(long double x, long double y);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double fminl(long double x, long double y)
  {
    return (long double)fmin((double)(x), (double)(y));
  }
#else
#define fminl(x, y) ((long double)fmin((double)(x), (double)(y)))
#endif
#endif

#endif /* __MWERKS__ */
#ifndef __NOEXTENSIONS__
  /**
   *  relationl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  relop relationl(long double x, long double y);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline relop relationl(long double x, long double y)
  {
    return relation((double)(x), (double)(y));
  }
#else
#define relationl(x, y) (relation((double)(x), (double)(y)))
#endif
#endif

  /**
   *  num2decl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  void num2decl(const decform *f, long double x, decimal *d);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline void num2decl(const decform *f, long double x, decimal *d)
  {
    num2dec((f), (double)(x), (d));
  }
#else
#define num2decl(f, x, d) (num2dec((f), (double)(x), (d)))
#endif
#endif

  /**
   *  dec2numl()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  long double dec2numl(const decimal *d);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline long double dec2numl(const decimal *d)
  {
    return (long double)dec2num(d);
  }
#else
#define dec2numl(d) ((long double)dec2num(d))
#endif
#endif

#endif /* !defined(__NOEXTENSIONS__) */

#endif /* TARGET_CPU_PPC */

#endif /* TARGET_OS_MAC */

#ifndef __NOEXTENSIONS__
  /**
          MathLib v2 has two new transfer functions: x80tod and dtox80.  They can
          be used to directly transform 68k 80-bit extended data types to double
          and back for PowerPC based machines without using the functions
          x80told or ldtox80.  Double rounding may occur.
      */
  /**
   *  x80tod()
   *

   *    \non_carbon_cfm   in MathLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  double x80tod(const extended80 *x80);

  /**
   *  dtox80()
   *

   *    \non_carbon_cfm   in MathLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void dtox80(const double *x, extended80 *x80);

  /**
   *  x80told()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  void x80told(const extended80 *x80, long double *x);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline void x80told(const extended80 *x80, long double *x)
  {
    *(x) = (long double)x80tod(x80);
  }
#else
#define x80told(x80, x) (*(x) = (long double)x80tod(x80))
#endif
#endif

  /**
   *  ldtox80()
   *

   *    \non_carbon_cfm   in MathLib 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         not available
   */
  void ldtox80(const long double *x, extended80 *x80);
#if TYPE_LONGDOUBLE_IS_DOUBLE
#ifdef __cplusplus
  inline void ldtox80(const long double *x, extended80 *x80)
  {
    double d = (double)*(x);
    dtox80(&d, (x80));
  }
#else
#define ldtox80(x, x80)      \
  do                         \
  {                          \
    double d = (double)*(x); \
    dtox80(&d, (x80));       \
  } while (false)
#endif
#endif

#endif /* !defined(__NOEXTENSIONS__) */

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

#endif /* __FP__ */
