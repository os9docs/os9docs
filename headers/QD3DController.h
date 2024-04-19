/**
     \file       QD3DController.h

    \brief   Q3Controller methods

    \introduced_in  Quickdraw 3D 1.6
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1995-2001 by Apple Computer, Inc., all rights reserved.

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QD3DCONTROLLER__
#define __QD3DCONTROLLER__

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
#define __QD3DCONTROLLER__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __QD3DCONTROLLER__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

/******************************************************************************
 **                                                                          **
 **                             Type Definitions                             **
 **                                                                          **
 *****************************************************************************/
#define kQ3ControllerSetChannelMaxDataSize 256
typedef CALLBACK_API_C(TQ3Status,
                       TQ3ChannelGetMethod)(TQ3ControllerRef controllerRef,
                                            unsigned long channel, void *data,
                                            unsigned long *dataSize);
typedef CALLBACK_API_C(TQ3Status,
                       TQ3ChannelSetMethod)(TQ3ControllerRef controllerRef,
                                            unsigned long channel,
                                            const void *data,
                                            unsigned long dataSize);
struct TQ3ControllerData {
  char *signature;
  unsigned long valueCount;
  unsigned long channelCount;
  TQ3ChannelGetMethod channelGetMethod;
  TQ3ChannelSetMethod channelSetMethod;
};
typedef struct TQ3ControllerData TQ3ControllerData;
/******************************************************************************
 **                                                                          **
 **                                  Routines                                **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
/**
 *  Q3Controller_GetListChanged()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_GetListChanged(TQ3Boolean *listChanged,
                            unsigned long *serialNumber);

/**
 *  Q3Controller_Next()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_Next(TQ3ControllerRef controllerRef,
                  TQ3ControllerRef *nextControllerRef);

/**
 *  Q3Controller_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3ControllerRef)
Q3Controller_New(const TQ3ControllerData *controllerData);

/**
 *  Q3Controller_Decommission()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_Decommission(TQ3ControllerRef controllerRef);

/**
 *  Q3Controller_SetActivation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_SetActivation(TQ3ControllerRef controllerRef, TQ3Boolean active);

/**
 *  Q3Controller_GetActivation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_GetActivation(TQ3ControllerRef controllerRef, TQ3Boolean *active);

/**
 *  Q3Controller_GetSignature()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_GetSignature(TQ3ControllerRef controllerRef, char *signature,
                          unsigned long numChars);

/**
 *  Q3Controller_SetChannel()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_SetChannel(TQ3ControllerRef controllerRef, unsigned long channel,
                        const void *data, unsigned long dataSize);

/**
 *  Q3Controller_GetChannel()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_GetChannel(TQ3ControllerRef controllerRef, unsigned long channel,
                        void *data, unsigned long *dataSize);

/**
 *  Q3Controller_GetValueCount()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_GetValueCount(TQ3ControllerRef controllerRef,
                           unsigned long *valueCount);

/**
 *  Q3Controller_SetTracker()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_SetTracker(TQ3ControllerRef controllerRef,
                        TQ3TrackerObject tracker);

/**
 *  Q3Controller_HasTracker()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_HasTracker(TQ3ControllerRef controllerRef, TQ3Boolean *hasTracker);

/**
 *  Q3Controller_Track2DCursor()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_Track2DCursor(TQ3ControllerRef controllerRef,
                           TQ3Boolean *track2DCursor);

/**
 *  Q3Controller_Track3DCursor()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_Track3DCursor(TQ3ControllerRef controllerRef,
                           TQ3Boolean *track3DCursor);

/**
 *  Q3Controller_GetButtons()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_GetButtons(TQ3ControllerRef controllerRef, unsigned long *buttons);

/**
 *  Q3Controller_SetButtons()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_SetButtons(TQ3ControllerRef controllerRef, unsigned long buttons);

/**
 *  Q3Controller_GetTrackerPosition()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_GetTrackerPosition(TQ3ControllerRef controllerRef,
                                TQ3Point3D *position);

/**
 *  Q3Controller_SetTrackerPosition()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_SetTrackerPosition(TQ3ControllerRef controllerRef,
                                const TQ3Point3D *position);

/**
 *  Q3Controller_MoveTrackerPosition()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_MoveTrackerPosition(TQ3ControllerRef controllerRef,
                                 const TQ3Vector3D *delta);

/**
 *  Q3Controller_GetTrackerOrientation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_GetTrackerOrientation(TQ3ControllerRef controllerRef,
                                   TQ3Quaternion *orientation);

/**
 *  Q3Controller_SetTrackerOrientation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_SetTrackerOrientation(TQ3ControllerRef controllerRef,
                                   const TQ3Quaternion *orientation);

/**
 *  Q3Controller_MoveTrackerOrientation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_MoveTrackerOrientation(TQ3ControllerRef controllerRef,
                                    const TQ3Quaternion *delta);

/**
 *  Q3Controller_GetValues()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_GetValues(TQ3ControllerRef controllerRef, unsigned long valueCount,
                       float *values, TQ3Boolean *changed,
                       unsigned long *serialNumber);

/**
 *  Q3Controller_SetValues()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Controller_SetValues(TQ3ControllerRef controllerRef, const float *values,
                       unsigned long valueCount);

/******************************************************************************
 **                                                                          **
 **                                  Routines                                **
 **                                                                          **
 *****************************************************************************/
/**
 *  Q3ControllerState_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3ControllerStateObject)
Q3ControllerState_New(TQ3ControllerRef controllerRef);

/**
 *  Q3ControllerState_SaveAndReset()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3ControllerState_SaveAndReset(TQ3ControllerStateObject controllerStateObject);

/**
 *  Q3ControllerState_Restore()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3ControllerState_Restore(TQ3ControllerStateObject controllerStateObject);

/******************************************************************************
 **                                                                          **
 **                             Type Definitions                             **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

typedef CALLBACK_API_C(TQ3Status,
                       TQ3TrackerNotifyFunc)(TQ3TrackerObject trackerObject,
                                             TQ3ControllerRef controllerRef);
/******************************************************************************
 **                                                                          **
 **                                  Routines                                **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
/**
 *  Q3Tracker_New()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3TrackerObject)
Q3Tracker_New(TQ3TrackerNotifyFunc notifyFunc);

/**
 *  Q3Tracker_SetNotifyThresholds()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_SetNotifyThresholds(TQ3TrackerObject trackerObject,
                              float positionThresh, float orientationThresh);

/**
 *  Q3Tracker_GetNotifyThresholds()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_GetNotifyThresholds(TQ3TrackerObject trackerObject,
                              float *positionThresh, float *orientationThresh);

/**
 *  Q3Tracker_SetActivation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_SetActivation(TQ3TrackerObject trackerObject, TQ3Boolean active);

/**
 *  Q3Tracker_GetActivation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_GetActivation(TQ3TrackerObject trackerObject, TQ3Boolean *active);

/**
 *  Q3Tracker_GetButtons()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_GetButtons(TQ3TrackerObject trackerObject, unsigned long *buttons);

/**
 *  Q3Tracker_ChangeButtons()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_ChangeButtons(TQ3TrackerObject trackerObject,
                        TQ3ControllerRef controllerRef, unsigned long buttons,
                        unsigned long buttonMask);

/**
 *  Q3Tracker_GetPosition()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_GetPosition(TQ3TrackerObject trackerObject, TQ3Point3D *position,
                      TQ3Vector3D *delta, TQ3Boolean *changed,
                      unsigned long *serialNumber);

/**
 *  Q3Tracker_SetPosition()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_SetPosition(TQ3TrackerObject trackerObject,
                      TQ3ControllerRef controllerRef,
                      const TQ3Point3D *position);

/**
 *  Q3Tracker_MovePosition()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_MovePosition(TQ3TrackerObject trackerObject,
                       TQ3ControllerRef controllerRef,
                       const TQ3Vector3D *delta);

/**
 *  Q3Tracker_GetOrientation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_GetOrientation(TQ3TrackerObject trackerObject,
                         TQ3Quaternion *orientation, TQ3Quaternion *delta,
                         TQ3Boolean *changed, unsigned long *serialNumber);

/**
 *  Q3Tracker_SetOrientation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_SetOrientation(TQ3TrackerObject trackerObject,
                         TQ3ControllerRef controllerRef,
                         const TQ3Quaternion *orientation);

/**
 *  Q3Tracker_MoveOrientation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_MoveOrientation(TQ3TrackerObject trackerObject,
                          TQ3ControllerRef controllerRef,
                          const TQ3Quaternion *delta);

/**
 *  Q3Tracker_SetEventCoordinates()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_SetEventCoordinates(TQ3TrackerObject trackerObject,
                              unsigned long timeStamp, unsigned long buttons,
                              const TQ3Point3D *position,
                              const TQ3Quaternion *orientation);

/**
 *  Q3Tracker_GetEventCoordinates()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3Tracker_GetEventCoordinates(TQ3TrackerObject trackerObject,
                              unsigned long timeStamp, unsigned long *buttons,
                              TQ3Point3D *position, TQ3Quaternion *orientation);

/******************************************************************************
 **                                                                          **
 **                              Types                                       **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

typedef CALLBACK_API_C(void, TQ3CursorTrackerNotifyFunc)(void);
/******************************************************************************
 **                                                                          **
 **                              Routines                                    **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
/**
 *  Q3CursorTracker_PrepareTracking()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3CursorTracker_PrepareTracking(void);

/**
 *  Q3CursorTracker_SetTrackDeltas()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3CursorTracker_SetTrackDeltas(TQ3Boolean trackDeltas);

/**
 *  Q3CursorTracker_GetAndClearDeltas()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3CursorTracker_GetAndClearDeltas(float *depth, TQ3Quaternion *orientation,
                                  TQ3Boolean *hasOrientation,
                                  TQ3Boolean *changed,
                                  unsigned long *serialNumber);

/**
 *  Q3CursorTracker_SetNotifyFunc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3CursorTracker_SetNotifyFunc(TQ3CursorTrackerNotifyFunc notifyFunc);

/**
 *  Q3CursorTracker_GetNotifyFunc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(TQ3Status)
Q3CursorTracker_GetNotifyFunc(TQ3CursorTrackerNotifyFunc *notifyFunc);

#endif /* CALL_NOT_IN_CARBON */

#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __QD3DCONTROLLER__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__QD3DCONTROLLER__RESTORE_PACKED_ENUMS)
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

#endif /* __QD3DCONTROLLER__ */
