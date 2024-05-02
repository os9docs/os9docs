/**
     \file       CGAffineTransform.h

    \brief   xxx put contents here xxx

    \introduced_in  from CoreGraphics-70.root
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 2000-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup CoreGraphics
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CGAFFINETRANSFORM__
#define __CGAFFINETRANSFORM__

#ifndef __CGBASE__
#include <CGBase.h>
#endif

#ifndef __CGGEOMETRY__
#include <CGGeometry.h>
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

struct CGAffineTransform {
  float a;
  float b;
  float c;
  float d;
  float tx;
  float ty;
};
typedef struct CGAffineTransform CGAffineTransform;
/** The identity transform: [ 1 0 0 1 0 0 ]. */
/**
 *  CGAffineTransformIdentity
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
extern const CGAffineTransform CGAffineTransformIdentity;
/** Return the transform [ a b c d tx ty ]. */
/**
 *  CGAffineTransformMake()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGAffineTransform
CGAffineTransformMake(float a, float b, float c, float d, float tx, float ty);

/** Return a transform which translates by `(tx, ty)':
 *   t' = [ 1 0 0 1 tx ty ] */
/**
 *  CGAffineTransformMakeTranslation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGAffineTransform
CGAffineTransformMakeTranslation(float tx, float ty);

/** Return a transform which scales by `(sx, sy)':
 *   t' = [ sx 0 0 sy 0 0 ] */
/**
 *  CGAffineTransformMakeScale()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGAffineTransform
CGAffineTransformMakeScale(float sx, float sy);

/** Return a transform which rotates by `angle' radians:
 *   t' = [ cos(angle) sin(angle) -sin(angle) cos(angle) 0 0 ] */
/**
 *  CGAffineTransformMakeRotation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGAffineTransform
CGAffineTransformMakeRotation(float angle);

/** Translate `t' by `(tx, ty)' and return the result:
 *   t' = [ 1 0 0 1 tx ty ] * t */
/**
 *  CGAffineTransformTranslate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGAffineTransform
CGAffineTransformTranslate(CGAffineTransform t, float tx, float ty);

/** Scale `t' by `(sx, sy)' and return the result:
 *   t' = [ sx 0 0 sy 0 0 ] * t */
/**
 *  CGAffineTransformScale()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGAffineTransform
CGAffineTransformScale(CGAffineTransform t, float sx, float sy);

/** Rotate `t' by `angle' radians and return the result:
 *   t' =  [ cos(angle) sin(angle) -sin(angle) cos(angle) 0 0 ] * t */
/**
 *  CGAffineTransformRotate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGAffineTransform
CGAffineTransformRotate(CGAffineTransform t, float angle);

/** Invert `t' and return the result.  If `t' has zero determinant, then `t'
 * is returned unchanged. */
/**
 *  CGAffineTransformInvert()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGAffineTransform
CGAffineTransformInvert(CGAffineTransform t);

/** Concatenate `t2' to `t1' and returne the result:
 *   t' = t1 * t2 */
/**
 *  CGAffineTransformConcat()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGAffineTransform
CGAffineTransformConcat(CGAffineTransform t1, CGAffineTransform t2);

/** Transform `point' by `t' and return the result:
 *   p' = p * t
 * where p = [ x y 1 ]. */
/**
 *  CGPointApplyAffineTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGPoint
CGPointApplyAffineTransform(CGPoint point, CGAffineTransform t);

/** Transform `size' by `t' and return the result:
 *   s' = s * t
 * where s = [ width height 0 ]. */
/**
 *  CGSizeApplyAffineTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGSize
CGSizeApplyAffineTransform(CGSize size, CGAffineTransform t);

#ifdef __MWERKS__
CG_INLINE CGAffineTransform __CGAffineTransformMake(float a, float b, float c,
                                                    float d, float tx,
                                                    float ty) {
  CGAffineTransform t;
  t.a = a;
  t.b = b;
  t.c = c;
  t.d = d;
  t.tx = tx;
  t.ty = ty;
  return t;
}
#define CGAffineTransformMake __CGAffineTransformMake

CG_INLINE CGPoint __CGPointApplyAffineTransform(CGPoint point,
                                                CGAffineTransform t) {
  CGPoint p;

  p.x = t.a * point.x + t.c * point.y + t.tx;
  p.y = t.b * point.x + t.d * point.y + t.ty;
  return p;
}
#define CGPointApplyAffineTransform __CGPointApplyAffineTransform

CG_INLINE CGSize __CGSizeApplyAffineTransform(CGSize size,
                                              CGAffineTransform t) {
  CGSize s;

  s.width = t.a * size.width + t.c * size.height;
  s.height = t.b * size.width + t.d * size.height;
  return s;
}
#define CGSizeApplyAffineTransform __CGSizeApplyAffineTransform

#endif /** __MWERKS__ */

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

#endif /** __CGAFFINETRANSFORM__ */
