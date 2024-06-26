/**
     \file       GXEnvironment.h

    \brief   QuickDraw GX environment constants and interfaces

    \introduced_in  Quickdraw GX 1.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup QuickDraw

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __GXENVIRONMENT__
#define __GXENVIRONMENT__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __GXTYPES__
#include <GXTypes.h>
#endif

#ifndef __CMAPPLICATION__
#include <CMApplication.h>
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

  /** old header = graphics macintosh */

  enum
  {
    defaultPollingHandlerFlags = 0x00,
    okToSwitchDuringPollFlag = 0x00,
    dontSwitchDuringPollFlag = 0x01
  };

  typedef long gxPollingHandlerFlags;
  typedef CALLBACK_API_C(void,
                         gxPollingHandlerProcPtr)(long reference,
                                                  gxPollingHandlerFlags flags);
  typedef STACK_UPP_TYPE(gxPollingHandlerProcPtr) gxPollingHandlerUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewgxPollingHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxPollingHandlerUPP
  NewgxPollingHandlerUPP(gxPollingHandlerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppgxPollingHandlerProcInfo = 0x000003C1
  }; /** no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline gxPollingHandlerUPP
  NewgxPollingHandlerUPP(gxPollingHandlerProcPtr userRoutine)
  {
    return (gxPollingHandlerUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                     uppgxPollingHandlerProcInfo,
                                                     GetCurrentArchitecture());
  }
#else
#define NewgxPollingHandlerUPP(userRoutine)                               \
  (gxPollingHandlerUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),      \
                                             uppgxPollingHandlerProcInfo, \
                                             GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposegxPollingHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposegxPollingHandlerUPP(gxPollingHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposegxPollingHandlerUPP(gxPollingHandlerUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposegxPollingHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokegxPollingHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokegxPollingHandlerUPP(long reference, gxPollingHandlerFlags flags,
                            gxPollingHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokegxPollingHandlerUPP(long reference,
                                        gxPollingHandlerFlags flags,
                                        gxPollingHandlerUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppgxPollingHandlerProcInfo, reference,
                           flags);
  }
#else
#define InvokegxPollingHandlerUPP(reference, flags, userUPP)                  \
  CALL_TWO_PARAMETER_UPP((userUPP), uppgxPollingHandlerProcInfo, (reference), \
                         (flags))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewgxPollingHandlerProc(userRoutine) NewgxPollingHandlerUPP(userRoutine)
#define CallgxPollingHandlerProc(userRoutine, reference, flags) \
  InvokegxPollingHandlerUPP(reference, flags, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
  /**
   *  GXGetGraphicsPollingHandler()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxPollingHandlerUPP
  GXGetGraphicsPollingHandler(long *reference);

  /**
   *  GXSetGraphicsPollingHandler()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  GXSetGraphicsPollingHandler(gxPollingHandlerUPP handler, long reference);

/** old header = graphics toolbox */

/** QD to QD GX Translator typedefs */
#endif /** CALL_NOT_IN_CARBON */

  enum
  {
    gxDefaultOptionsTranslation = 0x0000,
    gxOptimizedTranslation = 0x0001,
    gxReplaceLineWidthTranslation = 0x0002,
    gxSimpleScalingTranslation = 0x0004,
    gxSimpleGeometryTranslation = 0x0008, /** implies simple scaling */
    gxSimpleLinesTranslation = 0x000C,    /** implies simple geometry & scaling */
    gxLayoutTextTranslation = 0x0010,     /** turn on gxLine layout (normally off) */
    gxRasterTargetTranslation = 0x0020,
    gxPostScriptTargetTranslation = 0x0040,
    gxVectorTargetTranslation = 0x0080,
    gxPDDTargetTranslation = 0x0100,
    gxDontConvertPatternsTranslation = 0x1000,
    gxDontSplitBitmapsTranslation = 0x2000
  };

  typedef long gxTranslationOption;
  enum
  {
    gxContainsFormsBegin = 0x0001,
    gxContainsFormsEnd = 0x0002,
    gxContainsPostScript = 0x0004,
    gxContainsEmptyPostScript = 0x0008
  };

  typedef long gxTranslationStatistic;
  enum
  {
    gxQuickDrawPictTag = FOUR_CHAR_CODE('pict')
  };

  struct gxQuickDrawPict
  {
    /** translator inputs */
    gxTranslationOption options;
    Rect srcRect;
    Point styleStretch;

    /** size of quickdraw picture data */
    unsigned long dataLength;

    /** file alias */
    gxBitmapDataSourceAlias alias;
  };
  typedef struct gxQuickDrawPict gxQuickDrawPict;
/** WindowRecord utilities */
#if CALL_NOT_IN_CARBON
  /**
   *  GXNewWindowViewPort()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxViewPort
  GXNewWindowViewPort(WindowRef qdWindow);

  /**
   *  GXGetWindowViewPort()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxViewPort
  GXGetWindowViewPort(WindowRef qdWindow);

  /**
   *  GXGetViewPortWindow()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  WindowRef
  GXGetViewPortWindow(gxViewPort portOrder);

  /** GDevice utilities */
  /**
   *  GXGetViewDeviceGDevice()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  GDHandle
  GXGetViewDeviceGDevice(gxViewDevice theDevice);

  /**
   *  GXGetGDeviceViewDevice()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxViewDevice
  GXGetGDeviceViewDevice(GDHandle qdGDevice);

  /** gxPoint utilities */
  /**
   *  GXConvertQDPoint()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  GXConvertQDPoint(const Point *shortPt, gxViewPort portOrder, gxPoint *fixedPt);

#endif /** CALL_NOT_IN_CARBON */

  typedef CALLBACK_API_C(OSErr, gxShapeSpoolProcPtr)(gxShape toSpool,
                                                     long refCon);
  /** printing utilities typedef */
  typedef CALLBACK_API_C(void, gxUserViewPortFilterProcPtr)(gxShape toFilter,
                                                            gxViewPort portOrder,
                                                            long refCon);
  typedef CALLBACK_API_C(long, gxConvertQDFontProcPtr)(gxStyle dst, long txFont,
                                                       long txFace);
  typedef STACK_UPP_TYPE(gxShapeSpoolProcPtr) gxShapeSpoolUPP;
  typedef STACK_UPP_TYPE(gxUserViewPortFilterProcPtr) gxUserViewPortFilterUPP;
  typedef STACK_UPP_TYPE(gxConvertQDFontProcPtr) gxConvertQDFontUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewgxShapeSpoolUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxShapeSpoolUPP
  NewgxShapeSpoolUPP(gxShapeSpoolProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppgxShapeSpoolProcInfo = 0x000003E1
  }; /** 2_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline gxShapeSpoolUPP NewgxShapeSpoolUPP(gxShapeSpoolProcPtr userRoutine)
  {
    return (gxShapeSpoolUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppgxShapeSpoolProcInfo,
                                                 GetCurrentArchitecture());
  }
#else
#define NewgxShapeSpoolUPP(userRoutine)                                     \
  (gxShapeSpoolUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppgxShapeSpoolProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewgxUserViewPortFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxUserViewPortFilterUPP
  NewgxUserViewPortFilterUPP(gxUserViewPortFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppgxUserViewPortFilterProcInfo = 0x00000FC1
  }; /** no_return_value Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline gxUserViewPortFilterUPP
  NewgxUserViewPortFilterUPP(gxUserViewPortFilterProcPtr userRoutine)
  {
    return (gxUserViewPortFilterUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppgxUserViewPortFilterProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewgxUserViewPortFilterUPP(userRoutine)                \
  (gxUserViewPortFilterUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppgxUserViewPortFilterProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewgxConvertQDFontUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxConvertQDFontUPP
  NewgxConvertQDFontUPP(gxConvertQDFontProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppgxConvertQDFontProcInfo = 0x00000FF1
  }; /** 4_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline gxConvertQDFontUPP
  NewgxConvertQDFontUPP(gxConvertQDFontProcPtr userRoutine)
  {
    return (gxConvertQDFontUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    uppgxConvertQDFontProcInfo,
                                                    GetCurrentArchitecture());
  }
#else
#define NewgxConvertQDFontUPP(userRoutine)                                     \
  (gxConvertQDFontUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppgxConvertQDFontProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposegxShapeSpoolUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposegxShapeSpoolUPP(gxShapeSpoolUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposegxShapeSpoolUPP(gxShapeSpoolUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposegxShapeSpoolUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposegxUserViewPortFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposegxUserViewPortFilterUPP(gxUserViewPortFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposegxUserViewPortFilterUPP(gxUserViewPortFilterUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposegxUserViewPortFilterUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposegxConvertQDFontUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposegxConvertQDFontUPP(gxConvertQDFontUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposegxConvertQDFontUPP(gxConvertQDFontUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposegxConvertQDFontUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokegxShapeSpoolUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  InvokegxShapeSpoolUPP(gxShape toSpool, long refCon, gxShapeSpoolUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokegxShapeSpoolUPP(gxShape toSpool, long refCon,
                                     gxShapeSpoolUPP userUPP)
  {
    return (OSErr)CALL_TWO_PARAMETER_UPP(userUPP, uppgxShapeSpoolProcInfo,
                                         toSpool, refCon);
  }
#else
#define InvokegxShapeSpoolUPP(toSpool, refCon, userUPP)              \
  (OSErr) CALL_TWO_PARAMETER_UPP((userUPP), uppgxShapeSpoolProcInfo, \
                                 (toSpool), (refCon))
#endif
#endif

  /**
   *  InvokegxUserViewPortFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokegxUserViewPortFilterUPP(gxShape toFilter, gxViewPort portOrder,
                                long refCon, gxUserViewPortFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokegxUserViewPortFilterUPP(gxShape toFilter,
                                            gxViewPort portOrder, long refCon,
                                            gxUserViewPortFilterUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppgxUserViewPortFilterProcInfo, toFilter,
                             portOrder, refCon);
  }
#else
#define InvokegxUserViewPortFilterUPP(toFilter, portOrder, refCon, userUPP) \
  CALL_THREE_PARAMETER_UPP((userUPP), uppgxUserViewPortFilterProcInfo,      \
                           (toFilter), (portOrder), (refCon))
#endif
#endif

  /**
   *  InvokegxConvertQDFontUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long
  InvokegxConvertQDFontUPP(gxStyle dst, long txFont, long txFace,
                           gxConvertQDFontUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline long InvokegxConvertQDFontUPP(gxStyle dst, long txFont, long txFace,
                                       gxConvertQDFontUPP userUPP)
  {
    return (long)CALL_THREE_PARAMETER_UPP(userUPP, uppgxConvertQDFontProcInfo,
                                          dst, txFont, txFace);
  }
#else
#define InvokegxConvertQDFontUPP(dst, txFont, txFace, userUPP)                 \
  (long)CALL_THREE_PARAMETER_UPP((userUPP), uppgxConvertQDFontProcInfo, (dst), \
                                 (txFont), (txFace))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewgxShapeSpoolProc(userRoutine) NewgxShapeSpoolUPP(userRoutine)
#define NewgxUserViewPortFilterProc(userRoutine) \
  NewgxUserViewPortFilterUPP(userRoutine)
#define NewgxConvertQDFontProc(userRoutine) NewgxConvertQDFontUPP(userRoutine)
#define CallgxShapeSpoolProc(userRoutine, toSpool, refCon) \
  InvokegxShapeSpoolUPP(toSpool, refCon, userRoutine)
#define CallgxUserViewPortFilterProc(userRoutine, toFilter, portOrder, refCon) \
  InvokegxUserViewPortFilterUPP(toFilter, portOrder, refCon, userRoutine)
#define CallgxConvertQDFontProc(userRoutine, dst, txFont, txFace) \
  InvokegxConvertQDFontUPP(dst, txFont, txFace, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  typedef gxShapeSpoolProcPtr gxShapeSpoolFunction;
  typedef gxUserViewPortFilterProcPtr gxUserViewPortFilter;
  typedef gxConvertQDFontProcPtr gxConvertQDFontFunction;
/** mouse utilities */
/** return mouse location in fixed-gxPoint global space */
#if CALL_NOT_IN_CARBON
  /**
   *  GXGetGlobalMouse()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  GXGetGlobalMouse(gxPoint *globalPt);

  /** return fixed-gxPoint local mouse (gxViewPort == 0 --> default) */
  /**
   *  GXGetViewPortMouse()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  GXGetViewPortMouse(gxViewPort portOrder, gxPoint *localPt);

  /** printing utilities */
  /**
   *  GXGetViewPortFilter()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxUserViewPortFilterUPP
  GXGetViewPortFilter(gxViewPort portOrder, long *refCon);

  /**
   *  GXSetViewPortFilter()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  GXSetViewPortFilter(gxViewPort portOrder, gxUserViewPortFilterUPP filter,
                      long refCon);

  /** QD to QD GX Translator functions */
  /**
   *  GXInstallQDTranslator()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  GXInstallQDTranslator(GrafPtr port, gxTranslationOption options,
                        const Rect *srcRect, const Rect *dstRect,
                        Point styleStrech, gxShapeSpoolUPP userFunction,
                        void *reference);

  /**
   *  GXRemoveQDTranslator()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxTranslationStatistic
  GXRemoveQDTranslator(GrafPtr port, gxTranslationStatistic *statistic);

  /**
   *  GXConvertPICTToShape()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxShape
  GXConvertPICTToShape(PicHandle pict, gxTranslationOption options,
                       const Rect *srcRect, const Rect *dstRect,
                       Point styleStretch, gxShape destination,
                       gxTranslationStatistic *stats);

  /** Find the best GX style given a QD font and face. Called by the QD->GX
   * translator */
  /**
   *  GXConvertQDFont()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long
  GXConvertQDFont(gxStyle theStyle, long txFont, long txFace);

  /**
   *  GXGetConvertQDFont()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  gxConvertQDFontUPP
  GXGetConvertQDFont(void);

  /**
   *  GXSetConvertQDFont()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  GXSetConvertQDFont(gxConvertQDFontUPP userFunction);

#endif /** CALL_NOT_IN_CARBON */

  typedef unsigned long gxProfilePoolAttributes;
  struct gxFlatProfileListItem
  {
    gxProfilePoolAttributes
        attributes;          /** information about this particular profile's source*/
    CMProfileRef profileRef; /** reference to profile, only valid before shape is
                                disposed*/
    CMProfileIdentifier
        identifier; /** information on how to find the profile upon unflattening*/
  };
  typedef struct gxFlatProfileListItem gxFlatProfileListItem;

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

#endif /** __GXENVIRONMENT__ */
