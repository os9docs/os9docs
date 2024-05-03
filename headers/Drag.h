/**
     \file       Drag.h

    \brief   Drag and Drop Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1992-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DRAG__
#define __DRAG__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __APPLEEVENTS__
#include <AppleEvents.h>
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
    _________________________________________________________________________________________________________

     © DRAG MANAGER DATA TYPES
    _________________________________________________________________________________________________________
  */

  typedef struct OpaqueDragRef *DragRef;
  typedef UInt32 DragItemRef;
  typedef OSType FlavorType;
  /**
    _________________________________________________________________________________________________________

     © DRAG ATTRIBUTES
    _________________________________________________________________________________________________________
  */
  typedef UInt32 DragAttributes;
  enum
  {
    kDragHasLeftSenderWindow =
        (1L << 0), /** drag has left the source window since TrackDrag*/
    kDragInsideSenderApplication =
        (1L << 1), /** drag is occurring within the sender application*/
    kDragInsideSenderWindow =
        (1L << 2) /** drag is occurring within the sender window*/
  };

  /**
    _________________________________________________________________________________________________________

     © DRAG BEHAVIORS
    _________________________________________________________________________________________________________
  */
  typedef UInt32 DragBehaviors;
  enum
  {
    kDragBehaviorNone = 0,
    kDragBehaviorZoomBackAnimation =
        (1L << 0) /** do zoomback animation for failed drags (normally enabled).*/
  };

  /**
    _________________________________________________________________________________________________________

     © DRAG IMAGE FLAGS
    _________________________________________________________________________________________________________
  */
  typedef UInt32 DragImageFlags;
  enum
  {
    kDragRegionAndImage = (1L << 4) /** drag region and image*/
  };

  /**
    _________________________________________________________________________________________________________

     © DRAG IMAGE TRANSLUCENCY LEVELS
    _________________________________________________________________________________________________________
  */

  enum
  {
    kDragStandardTranslucency = 0L, /** 65% image translucency (standard)*/
    kDragDarkTranslucency = 1L,     /** 50% image translucency*/
    kDragDarkerTranslucency = 2L,   /** 25% image translucency*/
    kDragOpaqueTranslucency = 3L    /** 0% image translucency (opaque)*/
  };

  /**
    _________________________________________________________________________________________________________

     © DRAG DRAWING PROCEDURE MESSAGES
    _________________________________________________________________________________________________________
  */

  typedef SInt16 DragRegionMessage;
  enum
  {
    kDragRegionBegin = 1, /** initialize drawing*/
    kDragRegionDraw = 2,  /** draw drag feedback*/
    kDragRegionHide = 3,  /** hide drag feedback*/
    kDragRegionIdle = 4,  /** drag feedback idle time*/
    kDragRegionEnd = 5    /** end of drawing*/
  };

  /**
    _________________________________________________________________________________________________________

     © ZOOM ACCELERATION
    _________________________________________________________________________________________________________
  */

  typedef SInt16 ZoomAcceleration;
  enum
  {
    kZoomNoAcceleration = 0, /** use linear interpolation*/
    kZoomAccelerate = 1,     /** ramp up step size*/
    kZoomDecelerate = 2      /** ramp down step size*/
  };

  /**
    _________________________________________________________________________________________________________

     © FLAVOR FLAGS
    _________________________________________________________________________________________________________
  */

  typedef UInt32 FlavorFlags;
  enum
  {
    flavorSenderOnly = (1 << 0),       /** flavor is available to sender only*/
    flavorSenderTranslated = (1 << 1), /** flavor is translated by sender*/
    flavorNotSaved = (1 << 2),         /** flavor should not be saved*/
    flavorSystemTranslated = (1 << 8), /** flavor is translated by system*/
    flavorDataPromised = (1 << 9)      /** flavor data is promised by sender*/
  };

  /**
    _________________________________________________________________________________________________________

     © FILE SYSTEM CONSTANTS
    _________________________________________________________________________________________________________
  */

  enum
  {
    kDragFlavorTypeHFS = FOUR_CHAR_CODE('hfs '), /** flavor type for HFS data*/
    kDragFlavorTypePromiseHFS =
        FOUR_CHAR_CODE('phfs'),                      /** flavor type for promised HFS data*/
    flavorTypeHFS = kDragFlavorTypeHFS,              /** old name*/
    flavorTypePromiseHFS = kDragFlavorTypePromiseHFS /** old name*/
  };

  enum
  {
    kDragPromisedFlavorFindFile =
        FOUR_CHAR_CODE('rWm1'), /** promisedFlavor value for Find File*/
    kDragPromisedFlavor =
        FOUR_CHAR_CODE('fssP') /** promisedFlavor value for everything else*/
  };

  enum
  {
    kDragPseudoCreatorVolumeOrDirectory =
        FOUR_CHAR_CODE('MACS'), /** "creator code" for volume or directory*/
    kDragPseudoFileTypeVolume =
        FOUR_CHAR_CODE('disk'), /** "file type" for volume*/
    kDragPseudoFileTypeDirectory =
        FOUR_CHAR_CODE('fold') /** "file type" for directory*/
  };

  /**
    _________________________________________________________________________________________________________

     © SPECIAL FLAVORS
    _________________________________________________________________________________________________________
  */

  enum
  {
    flavorTypeDirectory =
        FOUR_CHAR_CODE('diry') /** flavor type for AOCE directories*/
  };

  /**
    _________________________________________________________________________________________________________

     © FLAVORS FOR FINDER 8.0 AND LATER
    _________________________________________________________________________________________________________
  */

  enum
  {
    kFlavorTypeClippingName = FOUR_CHAR_CODE(
        'clnm'), /** name hint for clipping file (preferred over 'clfn')*/
    kFlavorTypeClippingFilename =
        FOUR_CHAR_CODE('clfn'), /** name for clipping file*/
    kFlavorTypeDragToTrashOnly =
        FOUR_CHAR_CODE('fdtt'), /** for apps that want to allow dragging private
                                   data to the trash*/
    kFlavorTypeFinderNoTrackingBehavior = FOUR_CHAR_CODE(
        'fntb') /** Finder completely ignores any drag containing this flavor*/
  };

  /**
    _________________________________________________________________________________________________________

     © DRAG TRACKING HANDLER MESSAGES
    _________________________________________________________________________________________________________
  */

  typedef SInt16 DragTrackingMessage;
  enum
  {
    kDragTrackingEnterHandler = 1, /** drag has entered handler*/
    kDragTrackingEnterWindow = 2,  /** drag has entered window*/
    kDragTrackingInWindow = 3,     /** drag is moving within window*/
    kDragTrackingLeaveWindow = 4,  /** drag has exited window*/
    kDragTrackingLeaveHandler = 5  /** drag has exited handler*/
  };

  /**
    _________________________________________________________________________________________________________

     © DRAG ACTIONS
    _________________________________________________________________________________________________________
  */

  enum
  {
    kDragActionNothing = 0L,
    kDragActionCopy = 1L,
    kDragActionAlias = (1L << 1),
    kDragActionGeneric = (1L << 2),
    kDragActionPrivate = (1L << 3),
    kDragActionMove = (1L << 4),
    kDragActionDelete = (1L << 5),
    kDragActionAll = (long)0xFFFFFFFF
  };

  typedef UInt32 DragActions;
  /**
    _________________________________________________________________________________________________________

     © HFS FLAVORS
    _________________________________________________________________________________________________________
  */
  struct HFSFlavor
  {
    OSType fileType;    /** file type */
    OSType fileCreator; /** file creator */
    UInt16 fdFlags;     /** Finder flags */
    FSSpec fileSpec;    /** file system specification */
  };
  typedef struct HFSFlavor HFSFlavor;
  struct PromiseHFSFlavor
  {
    OSType fileType;           /** file type */
    OSType fileCreator;        /** file creator */
    UInt16 fdFlags;            /** Finder flags */
    FlavorType promisedFlavor; /** promised flavor containing an FSSpec */
  };
  typedef struct PromiseHFSFlavor PromiseHFSFlavor;
  /**
    _________________________________________________________________________________________________________

     © APPLICATION-DEFINED DRAG HANDLER ROUTINES
    _________________________________________________________________________________________________________
  */
  typedef CALLBACK_API(OSErr,
                       DragTrackingHandlerProcPtr)(DragTrackingMessage message,
                                                   WindowRef theWindow,
                                                   void *handlerRefCon,
                                                   DragRef theDrag);
  typedef CALLBACK_API(OSErr, DragReceiveHandlerProcPtr)(WindowRef theWindow,
                                                         void *handlerRefCon,
                                                         DragRef theDrag);
  typedef STACK_UPP_TYPE(DragTrackingHandlerProcPtr) DragTrackingHandlerUPP;
  typedef STACK_UPP_TYPE(DragReceiveHandlerProcPtr) DragReceiveHandlerUPP;
  /**
   *  NewDragTrackingHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DragTrackingHandlerUPP
  NewDragTrackingHandlerUPP(DragTrackingHandlerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDragTrackingHandlerProcInfo = 0x00003FA0
  }; /** pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DragTrackingHandlerUPP
  NewDragTrackingHandlerUPP(DragTrackingHandlerProcPtr userRoutine)
  {
    return (DragTrackingHandlerUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDragTrackingHandlerProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewDragTrackingHandlerUPP(userRoutine)                \
  (DragTrackingHandlerUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppDragTrackingHandlerProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDragReceiveHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DragReceiveHandlerUPP
  NewDragReceiveHandlerUPP(DragReceiveHandlerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDragReceiveHandlerProcInfo = 0x00000FE0
  }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DragReceiveHandlerUPP
  NewDragReceiveHandlerUPP(DragReceiveHandlerProcPtr userRoutine)
  {
    return (DragReceiveHandlerUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDragReceiveHandlerProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewDragReceiveHandlerUPP(userRoutine)                                 \
  (DragReceiveHandlerUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),        \
                                               uppDragReceiveHandlerProcInfo, \
                                               GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeDragTrackingHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDragTrackingHandlerUPP(DragTrackingHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDragTrackingHandlerUPP(DragTrackingHandlerUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDragTrackingHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDragReceiveHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDragReceiveHandlerUPP(DragReceiveHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDragReceiveHandlerUPP(DragReceiveHandlerUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDragReceiveHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeDragTrackingHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeDragTrackingHandlerUPP(DragTrackingMessage message, WindowRef theWindow,
                               void *handlerRefCon, DragRef theDrag,
                               DragTrackingHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeDragTrackingHandlerUPP(DragTrackingMessage message,
                                            WindowRef theWindow,
                                            void *handlerRefCon, DragRef theDrag,
                                            DragTrackingHandlerUPP userUPP)
  {
    return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppDragTrackingHandlerProcInfo,
                                          message, theWindow, handlerRefCon,
                                          theDrag);
  }
#else
#define InvokeDragTrackingHandlerUPP(message, theWindow, handlerRefCon,      \
                                     theDrag, userUPP)                       \
  (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP), uppDragTrackingHandlerProcInfo, \
                                  (message), (theWindow), (handlerRefCon),   \
                                  (theDrag))
#endif
#endif

  /**
   *  InvokeDragReceiveHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeDragReceiveHandlerUPP(WindowRef theWindow, void *handlerRefCon,
                              DragRef theDrag, DragReceiveHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeDragReceiveHandlerUPP(WindowRef theWindow,
                                           void *handlerRefCon, DragRef theDrag,
                                           DragReceiveHandlerUPP userUPP)
  {
    return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppDragReceiveHandlerProcInfo,
                                           theWindow, handlerRefCon, theDrag);
  }
#else
#define InvokeDragReceiveHandlerUPP(theWindow, handlerRefCon, theDrag,       \
                                    userUPP)                                 \
  (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppDragReceiveHandlerProcInfo, \
                                   (theWindow), (handlerRefCon), (theDrag))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewDragTrackingHandlerProc(userRoutine) \
  NewDragTrackingHandlerUPP(userRoutine)
#define NewDragReceiveHandlerProc(userRoutine) \
  NewDragReceiveHandlerUPP(userRoutine)
#define CallDragTrackingHandlerProc(userRoutine, message, theWindow,       \
                                    handlerRefCon, theDrag)                \
  InvokeDragTrackingHandlerUPP(message, theWindow, handlerRefCon, theDrag, \
                               userRoutine)
#define CallDragReceiveHandlerProc(userRoutine, theWindow, handlerRefCon, \
                                   theDrag)                               \
  InvokeDragReceiveHandlerUPP(theWindow, handlerRefCon, theDrag, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  /**
    _________________________________________________________________________________________________________

     © APPLICATION-DEFINED ROUTINES
    _________________________________________________________________________________________________________
  */
  typedef CALLBACK_API(OSErr, DragSendDataProcPtr)(FlavorType theType,
                                                   void *dragSendRefCon,
                                                   DragItemRef theItemRef,
                                                   DragRef theDrag);
  typedef CALLBACK_API(OSErr, DragInputProcPtr)(Point *mouse, SInt16 *modifiers,
                                                void *dragInputRefCon,
                                                DragRef theDrag);
  typedef CALLBACK_API(OSErr,
                       DragDrawingProcPtr)(DragRegionMessage message,
                                           RgnHandle showRegion, Point showOrigin,
                                           RgnHandle hideRegion, Point hideOrigin,
                                           void *dragDrawingRefCon,
                                           DragRef theDrag);
  typedef STACK_UPP_TYPE(DragSendDataProcPtr) DragSendDataUPP;
  typedef STACK_UPP_TYPE(DragInputProcPtr) DragInputUPP;
  typedef STACK_UPP_TYPE(DragDrawingProcPtr) DragDrawingUPP;
  /**
   *  NewDragSendDataUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DragSendDataUPP
  NewDragSendDataUPP(DragSendDataProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDragSendDataProcInfo = 0x00003FE0
  }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DragSendDataUPP NewDragSendDataUPP(DragSendDataProcPtr userRoutine)
  {
    return (DragSendDataUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppDragSendDataProcInfo,
                                                 GetCurrentArchitecture());
  }
#else
#define NewDragSendDataUPP(userRoutine)                                     \
  (DragSendDataUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppDragSendDataProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDragInputUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DragInputUPP
  NewDragInputUPP(DragInputProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDragInputProcInfo = 0x00003FE0
  }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DragInputUPP NewDragInputUPP(DragInputProcPtr userRoutine)
  {
    return (DragInputUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDragInputProcInfo, GetCurrentArchitecture());
  }
#else
#define NewDragInputUPP(userRoutine)   \
  (DragInputUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppDragInputProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDragDrawingUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DragDrawingUPP
  NewDragDrawingUPP(DragDrawingProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDragDrawingProcInfo = 0x000FFFA0
  }; /** pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes,
        4_bytes) */
#ifdef __cplusplus
  inline DragDrawingUPP NewDragDrawingUPP(DragDrawingProcPtr userRoutine)
  {
    return (DragDrawingUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDragDrawingProcInfo, GetCurrentArchitecture());
  }
#else
#define NewDragDrawingUPP(userRoutine)                                     \
  (DragDrawingUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppDragDrawingProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeDragSendDataUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDragSendDataUPP(DragSendDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDragSendDataUPP(DragSendDataUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDragSendDataUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDragInputUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDragInputUPP(DragInputUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDragInputUPP(DragInputUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDragInputUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDragDrawingUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDragDrawingUPP(DragDrawingUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDragDrawingUPP(DragDrawingUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDragDrawingUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeDragSendDataUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeDragSendDataUPP(FlavorType theType, void *dragSendRefCon,
                        DragItemRef theItemRef, DragRef theDrag,
                        DragSendDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeDragSendDataUPP(FlavorType theType, void *dragSendRefCon,
                                     DragItemRef theItemRef, DragRef theDrag,
                                     DragSendDataUPP userUPP)
  {
    return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppDragSendDataProcInfo,
                                          theType, dragSendRefCon, theItemRef,
                                          theDrag);
  }
#else
#define InvokeDragSendDataUPP(theType, dragSendRefCon, theItemRef, theDrag,  \
                              userUPP)                                       \
  (OSErr)                                                                    \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppDragSendDataProcInfo, (theType), \
                              (dragSendRefCon), (theItemRef), (theDrag))
#endif
#endif

  /**
   *  InvokeDragInputUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeDragInputUPP(Point *mouse, SInt16 *modifiers, void *dragInputRefCon,
                     DragRef theDrag, DragInputUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeDragInputUPP(Point *mouse, SInt16 *modifiers,
                                  void *dragInputRefCon, DragRef theDrag,
                                  DragInputUPP userUPP)
  {
    return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppDragInputProcInfo, mouse,
                                          modifiers, dragInputRefCon, theDrag);
  }
#else
#define InvokeDragInputUPP(mouse, modifiers, dragInputRefCon, theDrag,      \
                           userUPP)                                         \
  (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP), uppDragInputProcInfo, (mouse), \
                                  (modifiers), (dragInputRefCon), (theDrag))
#endif
#endif

  /**
   *  InvokeDragDrawingUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeDragDrawingUPP(DragRegionMessage message, RgnHandle showRegion,
                       Point showOrigin, RgnHandle hideRegion, Point hideOrigin,
                       void *dragDrawingRefCon, DragRef theDrag,
                       DragDrawingUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeDragDrawingUPP(DragRegionMessage message,
                                    RgnHandle showRegion, Point showOrigin,
                                    RgnHandle hideRegion, Point hideOrigin,
                                    void *dragDrawingRefCon, DragRef theDrag,
                                    DragDrawingUPP userUPP)
  {
    return (OSErr)CALL_SEVEN_PARAMETER_UPP(
        userUPP, uppDragDrawingProcInfo, message, showRegion, showOrigin,
        hideRegion, hideOrigin, dragDrawingRefCon, theDrag);
  }
#else
#define InvokeDragDrawingUPP(message, showRegion, showOrigin, hideRegion,     \
                             hideOrigin, dragDrawingRefCon, theDrag, userUPP) \
  (OSErr)                                                                     \
      CALL_SEVEN_PARAMETER_UPP((userUPP), uppDragDrawingProcInfo, (message),  \
                               (showRegion), (showOrigin), (hideRegion),      \
                               (hideOrigin), (dragDrawingRefCon), (theDrag))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewDragSendDataProc(userRoutine) NewDragSendDataUPP(userRoutine)
#define NewDragInputProc(userRoutine) NewDragInputUPP(userRoutine)
#define NewDragDrawingProc(userRoutine) NewDragDrawingUPP(userRoutine)
#define CallDragSendDataProc(userRoutine, theType, dragSendRefCon, theItemRef, \
                             theDrag)                                          \
  InvokeDragSendDataUPP(theType, dragSendRefCon, theItemRef, theDrag,          \
                        userRoutine)
#define CallDragInputProc(userRoutine, mouse, modifiers, dragInputRefCon, \
                          theDrag)                                        \
  InvokeDragInputUPP(mouse, modifiers, dragInputRefCon, theDrag, userRoutine)
#define CallDragDrawingProc(userRoutine, message, showRegion, showOrigin, \
                            hideRegion, hideOrigin, dragDrawingRefCon,    \
                            theDrag)                                      \
  InvokeDragDrawingUPP(message, showRegion, showOrigin, hideRegion,       \
                       hideOrigin, dragDrawingRefCon, theDrag, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  /**
    _________________________________________________________________________________________________________

     © INSTALLING AND REMOVING HANDLERS API'S
    _________________________________________________________________________________________________________
  */

  /**
   *  InstallTrackingHandler()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InstallTrackingHandler(DragTrackingHandlerUPP trackingHandler,
                         WindowRef theWindow, void *handlerRefCon);

  /**
   *  InstallReceiveHandler()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InstallReceiveHandler(DragReceiveHandlerUPP receiveHandler, WindowRef theWindow,
                        void *handlerRefCon);

  /**
   *  RemoveTrackingHandler()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RemoveTrackingHandler(DragTrackingHandlerUPP trackingHandler,
                        WindowRef theWindow);

  /**
   *  RemoveReceiveHandler()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RemoveReceiveHandler(DragReceiveHandlerUPP receiveHandler, WindowRef theWindow);

  /**
    _________________________________________________________________________________________________________

     © CREATING & DISPOSING
    _________________________________________________________________________________________________________
  */

  /**
   *  NewDrag()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  NewDrag(DragRef *theDrag);

  /**
   *  DisposeDrag()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DisposeDrag(DragRef theDrag);

  /**
    _________________________________________________________________________________________________________

     © ADDING DRAG ITEM FLAVORS
    _________________________________________________________________________________________________________
  */

  /**
      The method for setting Drag Manager promises differs from that for Scrap
     Manger promises.  This chart describes the method for setting drag promises
     via AddDragItemFlavor().

          dataPtr         dataSize                                result
       pointer value  actual data size    The data of size dataSize pointed to by
     dataPtr is added to the drag. NULL             ignored        A promise is
     placed on the drag.
  */
  /**
   *  AddDragItemFlavor()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AddDragItemFlavor(DragRef theDrag, DragItemRef theItemRef, FlavorType theType,
                    const void *dataPtr, Size dataSize, FlavorFlags theFlags);

  /**
   *  SetDragItemFlavorData()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetDragItemFlavorData(DragRef theDrag, DragItemRef theItemRef,
                        FlavorType theType, const void *dataPtr, Size dataSize,
                        UInt32 dataOffset);

  /**
    _________________________________________________________________________________________________________

     © PROVIDING CALLBACK PROCEDURES
    _________________________________________________________________________________________________________
  */

  /**
   *  SetDragSendProc()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetDragSendProc(DragRef theDrag, DragSendDataUPP sendProc, void *dragSendRefCon);

  /**
   *  SetDragInputProc()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetDragInputProc(DragRef theDrag, DragInputUPP inputProc, void *dragInputRefCon);

  /**
   *  SetDragDrawingProc()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetDragDrawingProc(DragRef theDrag, DragDrawingUPP drawingProc,
                     void *dragDrawingRefCon);

  /**
    _________________________________________________________________________________________________________

     © SETTING THE DRAG IMAGE
    _________________________________________________________________________________________________________
  */

  /**
   *  SetDragImage()
   *

   *    \non_carbon_cfm   in DragLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetDragImage(DragRef theDrag, PixMapHandle imagePixMap, RgnHandle imageRgn,
               Point imageOffsetPt, DragImageFlags theImageFlags);

  /**
    _________________________________________________________________________________________________________

     © ALTERING THE BEHAVIOR OF A DRAG
    _________________________________________________________________________________________________________
  */
  /**
   *  ChangeDragBehaviors()
   *

   *    \non_carbon_cfm   in DragLib 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ChangeDragBehaviors(DragRef theDrag, DragBehaviors inBehaviorsToSet,
                      DragBehaviors inBehaviorsToClear);

  /**
    _________________________________________________________________________________________________________

     © PERFORMING A DRAG
    _________________________________________________________________________________________________________
  */
  /**
   *  TrackDrag()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  TrackDrag(DragRef theDrag, const EventRecord *theEvent, RgnHandle theRegion);

  /**
    _________________________________________________________________________________________________________

     © GETTING DRAG ITEM INFORMATION
    _________________________________________________________________________________________________________
  */

  /**
   *  CountDragItems()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  CountDragItems(DragRef theDrag, UInt16 *numItems);

  /**
   *  GetDragItemReferenceNumber()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetDragItemReferenceNumber(DragRef theDrag, UInt16 index,
                             DragItemRef *theItemRef);

  /**
   *  CountDragItemFlavors()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  CountDragItemFlavors(DragRef theDrag, DragItemRef theItemRef,
                       UInt16 *numFlavors);

  /**
   *  GetFlavorType()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetFlavorType(DragRef theDrag, DragItemRef theItemRef, UInt16 index,
                FlavorType *theType);

  /**
   *  GetFlavorFlags()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetFlavorFlags(DragRef theDrag, DragItemRef theItemRef, FlavorType theType,
                 FlavorFlags *theFlags);

  /**
   *  GetFlavorDataSize()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetFlavorDataSize(DragRef theDrag, DragItemRef theItemRef, FlavorType theType,
                    Size *dataSize);

  /**
   *  GetFlavorData()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetFlavorData(DragRef theDrag, DragItemRef theItemRef, FlavorType theType,
                void *dataPtr, Size *dataSize, UInt32 dataOffset);

  /**
    _________________________________________________________________________________________________________

     © DRAG ITEM BOUNDS
    _________________________________________________________________________________________________________
  */

  /**
   *  GetDragItemBounds()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetDragItemBounds(DragRef theDrag, DragItemRef theItemRef, Rect *itemBounds);

  /**
   *  SetDragItemBounds()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetDragItemBounds(DragRef theDrag, DragItemRef theItemRef,
                    const Rect *itemBounds);

  /**
    _________________________________________________________________________________________________________

     © DROP LOCATIONS
    _________________________________________________________________________________________________________
  */

  /**
   *  GetDropLocation()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetDropLocation(DragRef theDrag, AEDesc *dropLocation);

  /**
   *  SetDropLocation()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetDropLocation(DragRef theDrag, const AEDesc *dropLocation);

  /**
    _________________________________________________________________________________________________________

     © GETTING INFORMATION ABOUT A DRAG
    _________________________________________________________________________________________________________
  */

  /**
   *  GetDragAttributes()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetDragAttributes(DragRef theDrag, DragAttributes *flags);

  /**
   *  GetDragMouse()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetDragMouse(DragRef theDrag, Point *mouse, Point *globalPinnedMouse);

  /**
   *  SetDragMouse()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetDragMouse(DragRef theDrag, Point globalPinnedMouse);

  /**
   *  GetDragOrigin()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetDragOrigin(DragRef theDrag, Point *globalInitialMouse);

  /**
   *  GetDragModifiers()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetDragModifiers(DragRef theDrag, SInt16 *modifiers, SInt16 *mouseDownModifiers,
                   SInt16 *mouseUpModifiers);

  /**
    _________________________________________________________________________________________________________

     © ACCESSING DRAG ACTIONS
    _________________________________________________________________________________________________________
  */

  /**
   *  GetDragAllowableActions()
   *
   *  Discussion:
   *    Gets the actions the drag sender has allowed the receiver to
   *    perform. These are not requirements, but they highly suggested
   *    actions which allows the drag receiver to improve harmony across
   *    the system.  The allowable actions received are always those
   *    local to the caller's process.
   *
   *  Parameters:
   *
   *    theDrag:
   *      The drag reference from which to retreive the allowable drag
   *      actions.
   *
   *    outActions:
   *      A pointer to receive the field of allowable drag actions.
   *
   *  Result:
   *    An operating system result code.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSStatus
  GetDragAllowableActions(DragRef theDrag, DragActions *outActions);

  /**
   *  SetDragAllowableActions()
   *
   *  Discussion:
   *    Sets the actions the receiver of the drag is allowed to perform.
   *    These are not requirements, but they highly suggested actions
   *    which allows the drag receiver to improve harmony across the
   *    system.  The caller may select wether these drag actions apply to
   *    a local or remote process.
   *
   *  Parameters:
   *
   *    theDrag:
   *      The drag reference in which to set the allowable drag actions.
   *
   *    inActions:
   *      A field of allowable drag actions to be set.
   *
   *    isLocal:
   *      A boolean value allowing the drag sender to distinguish between
   *      those drag actions allowable by the local receiver versus a
   *      remote one.
   *
   *  Result:
   *    An operating system result code.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSStatus
  SetDragAllowableActions(DragRef theDrag, DragActions inActions,
                          Boolean isLocal);

  /**
   *  GetDragDropAction()
   *
   *  Discussion:
   *    Gets the action performed by the receiver of the drag.  More than
   *    one action may have been performed.
   *
   *  Parameters:
   *
   *    theDrag:
   *      The drag reference from which to retreive the performed drop
   *      action.
   *
   *    outAction:
   *      A pointer to receive the drag action performed.
   *
   *  Result:
   *    An operating system result code.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSStatus
  GetDragDropAction(DragRef theDrag, DragActions *outAction);

  /**
   *  SetDragDropAction()
   *
   *  Discussion:
   *    Sets the action performed by the receiver of the drag.  More than
   *    one action may be performed.
   *
   *  Parameters:
   *
   *    theDrag:
   *      The drag reference in which to set the performed drop action.
   *
   *    inAction:
   *      The drop action performed.
   *
   *  Result:
   *    An operating system result code.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSStatus
  SetDragDropAction(DragRef theDrag, DragActions inAction);

  /**
    _________________________________________________________________________________________________________

     © DRAG HIGHLIGHTING
    _________________________________________________________________________________________________________
  */

  /**
   *  ShowDragHilite()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ShowDragHilite(DragRef theDrag, RgnHandle hiliteFrame, Boolean inside);

  /**
   *  HideDragHilite()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  HideDragHilite(DragRef theDrag);

  /**
   *  DragPreScroll()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DragPreScroll(DragRef theDrag, SInt16 dH, SInt16 dV);

  /**
   *  DragPostScroll()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DragPostScroll(DragRef theDrag);

  /**
   *  UpdateDragHilite()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  UpdateDragHilite(DragRef theDrag, RgnHandle updateRgn);

  /**
   *  GetDragHiliteColor()
   *

   *    \non_carbon_cfm   in DragLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetDragHiliteColor(WindowRef window, RGBColor *color);

  /**
    _________________________________________________________________________________________________________

     © UTILITIES
    _________________________________________________________________________________________________________
  */

  /**
   *  WaitMouseMoved()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  WaitMouseMoved(Point initialMouse);

  /**
   *  ZoomRects()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ZoomRects(const Rect *fromRect, const Rect *toRect, SInt16 zoomSteps,
            ZoomAcceleration acceleration);

  /**
   *  ZoomRegion()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ZoomRegion(RgnHandle region, Point zoomDistance, SInt16 zoomSteps,
             ZoomAcceleration acceleration);

  /**
    _________________________________________________________________________________________________________
     © OLD NAMES
       These are provided for compatiblity with older source bases.  It is
    recommended to not use them since they may removed from this interface file at
    any time.
    _________________________________________________________________________________________________________
  */

  typedef DragRef DragReference;
  typedef DragItemRef ItemReference;
#if OLDROUTINENAMES
  enum
  {
    dragHasLeftSenderWindow =
        kDragHasLeftSenderWindow, /** drag has left the source window since
                                     TrackDrag */
    dragInsideSenderApplication =
        kDragInsideSenderApplication, /** drag is occurring within the sender
                                         application */
    dragInsideSenderWindow =
        kDragInsideSenderWindow /** drag is occurring within the sender window */
  };

  enum
  {
    dragTrackingEnterHandler =
        kDragTrackingEnterHandler, /** drag has entered handler */
    dragTrackingEnterWindow =
        kDragTrackingEnterWindow, /** drag has entered window */
    dragTrackingInWindow =
        kDragTrackingInWindow, /** drag is moving within window */
    dragTrackingLeaveWindow =
        kDragTrackingLeaveWindow, /** drag has exited window */
    dragTrackingLeaveHandler =
        kDragTrackingLeaveHandler /** drag has exited handler */
  };

  enum
  {
    dragRegionBegin = kDragRegionBegin, /** initialize drawing */
    dragRegionDraw = kDragRegionDraw,   /** draw drag feedback */
    dragRegionHide = kDragRegionHide,   /** hide drag feedback */
    dragRegionIdle = kDragRegionIdle,   /** drag feedback idle time */
    dragRegionEnd = kDragRegionEnd      /** end of drawing */
  };

  enum
  {
    zoomNoAcceleration = kZoomNoAcceleration, /** use linear interpolation */
    zoomAccelerate = kZoomAccelerate,         /** ramp up step size */
    zoomDecelerate = kZoomDecelerate          /** ramp down step size */
  };

  enum
  {
    kDragStandardImage =
        kDragStandardTranslucency,              /** 65% image translucency (standard)*/
    kDragDarkImage = kDragDarkTranslucency,     /** 50% image translucency*/
    kDragDarkerImage = kDragDarkerTranslucency, /** 25% image translucency*/
    kDragOpaqueImage =
        kDragOpaqueTranslucency /** 0% image translucency (opaque)*/
  };

#endif /** OLDROUTINENAMES */

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

#endif /** __DRAG__ */
