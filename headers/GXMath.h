/**
     \file       GXMath.h

    \brief   QuickDraw GX math routine interfaces.

    \introduced_in  Quickdraw GX 1.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup QuickDraw

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __GXMATH__
#define __GXMATH__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FIXMATH__
#include <FixMath.h>
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

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma push
#pragma pointers_in_D0
#endif

    struct gxPoint
    {
        Fixed x;
        Fixed y;
    };
    typedef struct gxPoint gxPoint;

    typedef unsigned short gxColorValue;
    struct gxPolar
    {
        Fixed radius;
        Fixed angle;
    };
    typedef struct gxPolar gxPolar;
    struct gxMapping
    {
        Fixed map[3][3];
    };
    typedef struct gxMapping gxMapping;
#define gxColorValue1 ((gxColorValue)0x0000FFFF)
#define gxPositiveInfinity ((long)0x7FFFFFFFL)
#define gxNegativeInfinity ((long)0x80000000L)

#if CALL_NOT_IN_CARBON
    /**
     *  CopyToMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    CopyToMapping(gxMapping *target, const gxMapping *source);

    /**
     *  InvertMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    InvertMapping(gxMapping *target, const gxMapping *source);

    /**
     *  MapMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    MapMapping(gxMapping *target, const gxMapping *source);

    /**
     *  MoveMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    MoveMapping(gxMapping *target, Fixed hOffset, Fixed vOffset);

    /**
     *  MoveMappingTo()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    MoveMappingTo(gxMapping *target, Fixed hPosition, Fixed vPosition);

    /**
     *  NormalizeMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    NormalizeMapping(gxMapping *target);

    /**
     *  RotateMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    RotateMapping(gxMapping *target, Fixed angle, Fixed xCenter, Fixed yCenter);

    /**
     *  ScaleMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    ScaleMapping(gxMapping *target, Fixed hFactor, Fixed vFactor, Fixed xCenter,
                 Fixed yCenter);

    /**
     *  ResetMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    ResetMapping(gxMapping *target);

    /**
     *  SkewMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    SkewMapping(gxMapping *target, Fixed skewX, Fixed skewY, Fixed xCenter,
                Fixed yCenter);

    /**
     *  MapPoints()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    MapPoints(const gxMapping *source, long count, gxPoint theVector[]);

    /**
     *  FirstBit()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    FirstBit(unsigned long x);

    /**
     *  WideScale()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    WideScale(const wide *source);

    /**
     *  LinearRoot()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    LinearRoot(Fixed first, Fixed last, Fract t[]);

    /**
     *  QuadraticRoot()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    QuadraticRoot(Fixed first, Fixed control, Fixed last, Fract t[]);

    /**
     *  PolarToPoint()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxPoint *
    PolarToPoint(const gxPolar *ra, gxPoint *xy);

    /**
     *  PointToPolar()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxPolar *
    PointToPolar(const gxPoint *xy, gxPolar *ra);

    /**
     *  FractCubeRoot()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fract
    FractCubeRoot(Fract source);

    /**
     *  FractDivide()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fract
    FractDivide(Fract dividend, Fract divisor);

    /**
     *  FractMultiply()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fract
    FractMultiply(Fract multiplicand, Fract multiplier);

    /**
     *  FractSineCosine()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fract
    FractSineCosine(Fixed degrees, Fract *cosine);

    /**
     *  FractSquareRoot()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fract
    FractSquareRoot(Fract source);

    /**
     *  FixedDivide()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    FixedDivide(Fixed dividend, Fixed divisor);

    /**
     *  FixedMultiply()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    FixedMultiply(Fixed multiplicand, Fixed multiplier);

    /** This next call is (source * multiplier / divisor) -- it avoids underflow,
     * overflow by using wides */
    /**
     *  MultiplyDivide()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    MultiplyDivide(long source, long multiplier, long divisor);

    /**
     *  Magnitude()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    unsigned long
    Magnitude(long deltaX, long deltaY);

    /**
     *  VectorMultiplyDivide()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    VectorMultiplyDivide(long count, const long *vector1, long step1,
                         const long *vector2, long step2, long divisor);

/** wide operations are defined within FixMath.h for PowerPC */
#endif /** CALL_NOT_IN_CARBON */

#if TARGET_OS_MAC && TARGET_CPU_68K
#if CALL_NOT_IN_CARBON
    /**
     *  WideAdd()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    wide *
    WideAdd(wide *target, const wide *source);

    /**
     *  WideCompare()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    short
    WideCompare(const wide *target, const wide *source);

    /**
     *  WideNegate()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    wide *
    WideNegate(wide *target);

    /**
     *  WideShift()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    wide *
    WideShift(wide *target, long shift);

    /**
     *  WideSquareRoot()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    unsigned long
    WideSquareRoot(const wide *source);

    /**
     *  WideSubtract()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    wide *
    WideSubtract(wide *target, const wide *source);

    /**
     *  WideMultiply()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    wide *
    WideMultiply(long multiplicand, long multiplier, wide *target);

    /** returns the quotient */
    /**
     *  WideDivide()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    WideDivide(const wide *dividend, long divisor, long *remainder);

    /** quotient replaces dividend */
    /**
     *  WideWideDivide()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    wide *
    WideWideDivide(wide *dividend, long divisor, long *remainder);

#endif /** CALL_NOT_IN_CARBON */

#endif /** TARGET_OS_MAC && TARGET_CPU_68K */

#if CALL_NOT_IN_CARBON
    /**
     *  VectorMultiply()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    wide *
    VectorMultiply(long count, const long *vector1, long step1, const long *vector2,
                   long step2, wide *dot);

    /**
     *  RandomBits()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    unsigned long
    RandomBits(long count, long focus);

    /**
     *  SetRandomSeed()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    SetRandomSeed(const wide *seed);

    /**
     *  GetRandomSeed()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    wide *
    GetRandomSeed(wide *seed);

#endif /** CALL_NOT_IN_CARBON */

#define FixedRound(a) ((short)((Fixed)(a) + fixed1 / 2 >> 16))
#define FixedSquareRoot(a) ((Fixed)FractSquareRoot(a) + 64 >> 7)
#define FixedTruncate(a) ((short)((Fixed)(a) >> 16))
#define FixedToFract(a) ((Fract)(a) << 14)
#define FractToFixed(a) (((Fixed)(a) + 8192L) >> 14)
#define FixedToInt(a) ((short)(((Fixed)(a) + fixed1 / 2) >> 16))
#define IntToFixed(a) ((Fixed)(a) << 16)
#define FixedToFloat(a) ((float)(a) / fixed1)
#define FloatToFixed(a) ((Fixed)((float)(a) * fixed1))
#define FractToFloat(a) ((float)(a) / fract1)
#define FloatToFract(a) ((Fract)((float)(a) * fract1))
#define ColorToFract(a) (((Fract)(a) << 14) + ((Fract)(a) + 2 >> 2))
#define FractToColor(a) ((gxColorValue)((a) - ((a) >> 16) + 8191 >> 14))
#ifndef ff /** ff is already defined on some platforms */
#define ff(a) IntToFixed(a)
#define fl(a) FloatToFixed(a)
#endif

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma pop
#endif

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

#endif /** __GXMATH__ */
