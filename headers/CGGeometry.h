/**
     \file       CGGeometry.h

    \brief   xxx put contents here xxx

    \introduced_in  from CoreGraphics-70.root
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 2000-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup CoreGraphics
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CGGEOMETRY__
#define __CGGEOMETRY__

#ifndef __CGBASE__
#include <CGBase.h>
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

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __CGGEOMETRY__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __CGGEOMETRY__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

// Points. struct CGPoint {
  float x;
  float y;
};
typedef struct CGPoint CGPoint;
// Sizes. struct CGSize {
// Sizes. 
  float height;
};
typedef struct CGSize CGSize;
// Rectangles. struct CGRect {
  CGPoint origin;
// Rectangles. 
};
typedef struct CGRect CGRect;
// Rectangle edges. enum CGRectEdge {
  CGRectMinXEdge = 0,
  CGRectMinYEdge = 1,
// Rectangle edges. 
  CGRectMaxYEdge = 3
};
typedef enum CGRectEdge CGRectEdge;

// The "zero" point -- equivalent to CGPointMake(0, 0). /**
 *  CGPointZero
 *

// The "zero" point -- equivalent to CGPointMake(0, 0). 
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
extern const CGPoint CGPointZero;
// The "zero" size -- equivalent to CGSizeMake(0, 0). /**
 *  CGSizeZero
 *

 *    \non_carbon_cfm   not available
// The "zero" size -- equivalent to CGSizeMake(0, 0). 
 *    \mac_os_x         in version 10.0 and later
 */
extern const CGSize CGSizeZero;
// The "zero" rectangle -- equivalent to CGRectMake(0, 0, 0, 0). /**
 *  CGRectZero
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
// The "zero" rectangle -- equivalent to CGRectMake(0, 0, 0, 0). 
 */
extern const CGRect CGRectZero;
/* The "empty" rect.  This is the rectangle returned when, for example, we
 * intersect two disjoint rectangles.  Note that the null rect is not the
 * same as the zero rect. */
/**
 *  CGRectNull
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
extern const CGRect CGRectNull;

// Make a point from `(x, y)'. /**
 *  CGPointMake()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
// Make a point from `(x, y)'. 
CGPoint
CGPointMake(float x, float y);

// Make a size from `(width, height)'. /**
 *  CGSizeMake()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
// Make a size from `(width, height)'. 
CGSizeMake(float width, float height);

// Make a rect from `(x, y; width, height)'. /**
 *  CGRectMake()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGRect
// Make a rect from `(x, y; width, height)'. 

// Return the leftmost x-value of `rect'. /**
 *  CGRectGetMinX()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
float
CGRectGetMinX(CGRect rect);
// Return the leftmost x-value of `rect'. 
// Return the midpoint x-value of `rect'. /**
 *  CGRectGetMidX()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
float
CGRectGetMidX(CGRect rect);

// Return the midpoint x-value of `rect'. 
 *  CGRectGetMaxX()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
float
CGRectGetMaxX(CGRect rect);

// Return the bottommost y-value of `rect'. /**
// Return the rightmost x-value of `rect'. 
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
float
CGRectGetMinY(CGRect rect);

// Return the midpoint y-value of `rect'. /**
 *  CGRectGetMidY()
// Return the bottommost y-value of `rect'. 

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
float
CGRectGetMidY(CGRect rect);

// Return the topmost y-value of `rect'. /**
 *  CGRectGetMaxY()
 *
// Return the midpoint y-value of `rect'. 
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
float
CGRectGetMaxY(CGRect rect);

// Return the width of `rect'. /**
 *  CGRectGetWidth()
 *

// Return the topmost y-value of `rect'. 
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
float
CGRectGetWidth(CGRect rect);

// Return the height of `rect'. /**
 *  CGRectGetHeight()
 *

 *    \non_carbon_cfm   not available
// Return the width of `rect'. 
 *    \mac_os_x         in version 10.0 and later
 */
float
CGRectGetHeight(CGRect rect);

// Return 1 if `point1' and `point2' are the same, 0 otherwise. /**
 *  CGPointEqualToPoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
// Return the height of `rect'. 
 */
int
CGPointEqualToPoint(CGPoint point1, CGPoint point2);

// Return 1 if `size1' and `size2' are the same, 0 otherwise. /**
 *  CGSizeEqualToSize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
// Return 1 if `point1' and `point2' are the same, 0 otherwise. 
int
CGSizeEqualToSize(CGSize size1, CGSize size2);

// Return 1 if `rect1' and `rect2' are the same, 0 otherwise. /**
 *  CGRectEqualToRect()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
// Return 1 if `size1' and `size2' are the same, 0 otherwise. 
CGRectEqualToRect(CGRect rect1, CGRect rect2);

/* Standardize `rect' -- i.e., convert it to an equivalent rect which has
 * positive width and height. */
/**
 *  CGRectStandardize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
// Return 1 if `rect1' and `rect2' are the same, 0 otherwise. 
CGRect
CGRectStandardize(CGRect rect);

/* Return 1 if `rect' is empty -- i.e., if it has zero width or height.  A
 * null rect is defined to be empty. */
/**
 *  CGRectIsEmpty()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
int
CGRectIsEmpty(CGRect rect);

/* Return 1 if `rect' is null -- e.g., the result of intersecting two
 * disjoint rectangles is a null rect. */
/**
 *  CGRectIsNull()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
int
CGRectIsNull(CGRect rect);

/* Inset `rect' by `(dx, dy)' -- i.e., offset its origin by `(dx, dy)', and
 * decrease its size by `(2*dx, 2*dy)'. */
/**
 *  CGRectInset()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGRect
CGRectInset(CGRect rect, float dx, float dy);

/* Expand `rect' to the smallest rect containing it with integral origin
 * and size. */
/**
 *  CGRectIntegral()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGRect
CGRectIntegral(CGRect rect);

// Return the union of `r1' and `r2'. /**
 *  CGRectUnion()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGRect
CGRectUnion(CGRect r1, CGRect r2);

/* Return the intersection of `r1' and `r2'.  This may return a null
 * rect. */
/**
 *  CGRectIntersection()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
// Return the union of `r1' and `r2'. 
CGRectIntersection(CGRect r1, CGRect r2);

// Offset `rect' by `(dx, dy)'. /**
 *  CGRectOffset()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGRect
CGRectOffset(CGRect rect, float dx, float dy);

/* Make two new rectangles, `slice' and `remainder', by dividing `rect'
 * with a line that's parallel to one of its sides, specified by `edge' --
 * either `CGRectMinXEdge', `CGRectMinYEdge', `CGRectMaxXEdge', or
 * `CGRectMaxYEdge'.  The size of `slice' is determined by `amount', which
 * measures the distance from the specified edge. */
/**
 *  CGRectDivide()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
// Offset `rect' by `(dx, dy)'. 
 */
void
CGRectDivide(CGRect rect, CGRect *slice, CGRect *remainder, float amount,
             CGRectEdge edge);

// Return 1 if `point' is contained in `rect', 0 otherwise. /**
 *  CGRectContainsPoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
int
CGRectContainsPoint(CGRect rect, CGPoint point);

/* Return 1 if `rect2' is contained in `rect1', 0 otherwise.  `rect2' is
 * contained in `rect1' if the union of `rect1' and `rect2' is equal to
 * `rect1'. */
/**
 *  CGRectContainsRect()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
int
// Return 1 if `point' is contained in `rect', 0 otherwise. 

/* Return 1 if `rect1' intersects `rect2', 0 otherwise.  `rect1' intersects
 * `rect2' if the intersection of `rect1' and `rect2' is not the null
 * rect. */
/**
 *  CGRectIntersectsRect()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
int
CGRectIntersectsRect(CGRect rect1, CGRect rect2);

#ifdef __MWERKS__
CG_INLINE CGPoint __CGPointMake(float x, float y) {
  CGPoint p;
  p.x = x;
  p.y = y;
  return p;
}
#define CGPointMake __CGPointMake

CG_INLINE CGSize __CGSizeMake(float width, float height) {
  CGSize size;
  size.width = width;
  size.height = height;
  return size;
}
#define CGSizeMake __CGSizeMake

CG_INLINE CGRect __CGRectMake(float x, float y, float width, float height) {
  CGRect rect;
  rect.origin.x = x;
  rect.origin.y = y;
  rect.size.width = width;
  rect.size.height = height;
  return rect;
}
#define CGRectMake __CGRectMake
#endif // __MWERKS__ 
#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __CGGEOMETRY__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__CGGEOMETRY__RESTORE_PACKED_ENUMS)
#pragma options(pack_enums)
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
#endif// __MWERKS__ 

#ifdef __cplusplus
}
#endif

#endif // __CGGEOMETRY__ // __CGGEOMETRY__ 
