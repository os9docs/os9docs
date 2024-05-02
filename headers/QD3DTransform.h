/**
     \file       QD3DTransform.h

    \brief   Q3Transform routines

    \introduced_in  Quickdraw 3D 1.6
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1995-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Quickdraw3D

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QD3DTRANSFORM__
#define __QD3DTRANSFORM__

#ifndef __QD3D__
#include <QD3D.h>
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
#pragma options align = power
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __QD3DTRANSFORM__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __QD3DTRANSFORM__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

/*******************************************************************************
 **                                                                          **
 **                         Transform Routines                               **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
/**
 *  Q3Transform_GetType()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3ObjectType
Q3Transform_GetType(TQ3TransformObject transform);

/**
 *  Q3Transform_GetMatrix()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Matrix4x4 *
Q3Transform_GetMatrix(TQ3TransformObject transform, TQ3Matrix4x4 *matrix);

/**
 *  Q3Transform_Submit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Transform_Submit(TQ3TransformObject transform, TQ3ViewObject view);

/*******************************************************************************
 **                                                                          **
 **                         MatrixTransform Routines                         **
 **                                                                          **
 *****************************************************************************/
/**
 *  Q3MatrixTransform_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3TransformObject
Q3MatrixTransform_New(const TQ3Matrix4x4 *matrix);

/**
 *  Q3MatrixTransform_Submit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3MatrixTransform_Submit(const TQ3Matrix4x4 *matrix, TQ3ViewObject view);

/**
 *  Q3MatrixTransform_Set()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3MatrixTransform_Set(TQ3TransformObject transform, const TQ3Matrix4x4 *matrix);

/**
 *  Q3MatrixTransform_Get()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3MatrixTransform_Get(TQ3TransformObject transform, TQ3Matrix4x4 *matrix);

/*******************************************************************************
 **                                                                          **
 **                         RotateTransform Data                             **
 **                                                                          **
 *****************************************************************************/
#endif /** CALL_NOT_IN_CARBON */

struct TQ3RotateTransformData {
  TQ3Axis axis;
  float radians;
};
typedef struct TQ3RotateTransformData TQ3RotateTransformData;
/*******************************************************************************
 **                                                                          **
 **                         RotateTransform Routines                         **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
/**
 *  Q3RotateTransform_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3TransformObject
Q3RotateTransform_New(const TQ3RotateTransformData *data);

/**
 *  Q3RotateTransform_Submit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateTransform_Submit(const TQ3RotateTransformData *data,
                         TQ3ViewObject view);

/**
 *  Q3RotateTransform_SetData()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateTransform_SetData(TQ3TransformObject transform,
                          const TQ3RotateTransformData *data);

/**
 *  Q3RotateTransform_GetData()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateTransform_GetData(TQ3TransformObject transform,
                          TQ3RotateTransformData *data);

/**
 *  Q3RotateTransform_SetAxis()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateTransform_SetAxis(TQ3TransformObject transform, TQ3Axis axis);

/**
 *  Q3RotateTransform_SetAngle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateTransform_SetAngle(TQ3TransformObject transform, float radians);

/**
 *  Q3RotateTransform_GetAxis()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateTransform_GetAxis(TQ3TransformObject renderable, TQ3Axis *axis);

/**
 *  Q3RotateTransform_GetAngle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateTransform_GetAngle(TQ3TransformObject transform, float *radians);

/*******************************************************************************
 **                                                                          **
 **                 RotateAboutPointTransform Data                           **
 **                                                                          **
 *****************************************************************************/
#endif /** CALL_NOT_IN_CARBON */

struct TQ3RotateAboutPointTransformData {
  TQ3Axis axis;
  float radians;
  TQ3Point3D about;
};
typedef struct TQ3RotateAboutPointTransformData
    TQ3RotateAboutPointTransformData;
/*******************************************************************************
 **                                                                          **
 **                 RotateAboutPointTransform Routines                       **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
/**
 *  Q3RotateAboutPointTransform_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3TransformObject
Q3RotateAboutPointTransform_New(const TQ3RotateAboutPointTransformData *data);

/**
 *  Q3RotateAboutPointTransform_Submit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutPointTransform_Submit(const TQ3RotateAboutPointTransformData *data,
                                   TQ3ViewObject view);

/**
 *  Q3RotateAboutPointTransform_SetData()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutPointTransform_SetData(
    TQ3TransformObject transform, const TQ3RotateAboutPointTransformData *data);

/**
 *  Q3RotateAboutPointTransform_GetData()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutPointTransform_GetData(TQ3TransformObject transform,
                                    TQ3RotateAboutPointTransformData *data);

/**
 *  Q3RotateAboutPointTransform_SetAxis()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutPointTransform_SetAxis(TQ3TransformObject transform, TQ3Axis axis);

/**
 *  Q3RotateAboutPointTransform_GetAxis()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutPointTransform_GetAxis(TQ3TransformObject transform,
                                    TQ3Axis *axis);

/**
 *  Q3RotateAboutPointTransform_SetAngle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutPointTransform_SetAngle(TQ3TransformObject transform,
                                     float radians);

/**
 *  Q3RotateAboutPointTransform_GetAngle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutPointTransform_GetAngle(TQ3TransformObject transform,
                                     float *radians);

/**
 *  Q3RotateAboutPointTransform_SetAboutPoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutPointTransform_SetAboutPoint(TQ3TransformObject transform,
                                          const TQ3Point3D *about);

/**
 *  Q3RotateAboutPointTransform_GetAboutPoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutPointTransform_GetAboutPoint(TQ3TransformObject transform,
                                          TQ3Point3D *about);

/*******************************************************************************
 **                                                                          **
 **                 RotateAboutAxisTransform Data                            **
 **                                                                          **
 *****************************************************************************/
#endif /** CALL_NOT_IN_CARBON */

struct TQ3RotateAboutAxisTransformData {
  TQ3Point3D origin;
  TQ3Vector3D orientation;
  float radians;
};
typedef struct TQ3RotateAboutAxisTransformData TQ3RotateAboutAxisTransformData;
/*******************************************************************************
 **                                                                          **
 **                 RotateAboutAxisTransform Routines                        **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
/**
 *  Q3RotateAboutAxisTransform_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3TransformObject
Q3RotateAboutAxisTransform_New(const TQ3RotateAboutAxisTransformData *data);

/**
 *  Q3RotateAboutAxisTransform_Submit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutAxisTransform_Submit(const TQ3RotateAboutAxisTransformData *data,
                                  TQ3ViewObject view);

/**
 *  Q3RotateAboutAxisTransform_SetData()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutAxisTransform_SetData(TQ3TransformObject transform,
                                   const TQ3RotateAboutAxisTransformData *data);

/**
 *  Q3RotateAboutAxisTransform_GetData()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutAxisTransform_GetData(TQ3TransformObject transform,
                                   TQ3RotateAboutAxisTransformData *data);

/**
 *  Q3RotateAboutAxisTransform_SetOrientation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutAxisTransform_SetOrientation(TQ3TransformObject transform,
                                          const TQ3Vector3D *axis);

/**
 *  Q3RotateAboutAxisTransform_GetOrientation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutAxisTransform_GetOrientation(TQ3TransformObject transform,
                                          TQ3Vector3D *axis);

/**
 *  Q3RotateAboutAxisTransform_SetAngle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutAxisTransform_SetAngle(TQ3TransformObject transform,
                                    float radians);

/**
 *  Q3RotateAboutAxisTransform_GetAngle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutAxisTransform_GetAngle(TQ3TransformObject transform,
                                    float *radians);

/**
 *  Q3RotateAboutAxisTransform_SetOrigin()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutAxisTransform_SetOrigin(TQ3TransformObject transform,
                                     const TQ3Point3D *origin);

/**
 *  Q3RotateAboutAxisTransform_GetOrigin()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3RotateAboutAxisTransform_GetOrigin(TQ3TransformObject transform,
                                     TQ3Point3D *origin);

/*******************************************************************************
 **                                                                          **
 **                         ScaleTransform Routines                          **
 **                                                                          **
 *****************************************************************************/
/**
 *  Q3ScaleTransform_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3TransformObject
Q3ScaleTransform_New(const TQ3Vector3D *scale);

/**
 *  Q3ScaleTransform_Submit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3ScaleTransform_Submit(const TQ3Vector3D *scale, TQ3ViewObject view);

/**
 *  Q3ScaleTransform_Set()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3ScaleTransform_Set(TQ3TransformObject transform, const TQ3Vector3D *scale);

/**
 *  Q3ScaleTransform_Get()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3ScaleTransform_Get(TQ3TransformObject transform, TQ3Vector3D *scale);

/*******************************************************************************
 **                                                                          **
 **                         TranslateTransform Routines                      **
 **                                                                          **
 *****************************************************************************/
/**
 *  Q3TranslateTransform_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3TransformObject
Q3TranslateTransform_New(const TQ3Vector3D *translate);

/**
 *  Q3TranslateTransform_Submit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3TranslateTransform_Submit(const TQ3Vector3D *translate, TQ3ViewObject view);

/**
 *  Q3TranslateTransform_Set()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3TranslateTransform_Set(TQ3TransformObject transform,
                         const TQ3Vector3D *translate);

/**
 *  Q3TranslateTransform_Get()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3TranslateTransform_Get(TQ3TransformObject transform, TQ3Vector3D *translate);

/*******************************************************************************
 **                                                                          **
 **                         QuaternionTransform Routines                     **
 **                                                                          **
 *****************************************************************************/
/**
 *  Q3QuaternionTransform_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3TransformObject
Q3QuaternionTransform_New(const TQ3Quaternion *quaternion);

/**
 *  Q3QuaternionTransform_Submit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3QuaternionTransform_Submit(const TQ3Quaternion *quaternion,
                             TQ3ViewObject view);

/**
 *  Q3QuaternionTransform_Set()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3QuaternionTransform_Set(TQ3TransformObject transform,
                          const TQ3Quaternion *quaternion);

/**
 *  Q3QuaternionTransform_Get()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3QuaternionTransform_Get(TQ3TransformObject transform,
                          TQ3Quaternion *quaternion);

/*******************************************************************************
 **                                                                          **
 **                         ResetTransform Routines                          **
 **                                                                          **
 *****************************************************************************/
/**
 *  Q3ResetTransform_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3TransformObject
Q3ResetTransform_New(void);

/**
 *  Q3ResetTransform_Submit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3ResetTransform_Submit(TQ3ViewObject view);

#endif /** CALL_NOT_IN_CARBON */

#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __QD3DTRANSFORM__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__QD3DTRANSFORM__RESTORE_PACKED_ENUMS)
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
#endif

#ifdef __cplusplus
}
#endif

#endif /** __QD3DTRANSFORM__ */
