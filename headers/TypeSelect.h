/**
     \file       TypeSelect.h

    \brief   TypeSelect Utilties

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 2000-2001 by Apple Computer, Inc., all rights reserved.

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __TYPESELECT__
#define __TYPESELECT__

#ifndef __EVENTS__
#include <Events.h>
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

  typedef SInt16 TSCode;
  enum
  {
    tsPreviousSelectMode = -1,
    tsNormalSelectMode = 0,
    tsNextSelectMode = 1
  };

  struct TypeSelectRecord
  {
    unsigned long tsrLastKeyTime;
    ScriptCode tsrScript;
    Str63 tsrKeyStrokes;
  };
  typedef struct TypeSelectRecord TypeSelectRecord;
  typedef CALLBACK_API(Boolean, IndexToStringProcPtr)(short item,
                                                      ScriptCode *itemsScript,
                                                      StringPtr *itemsStringPtr,
                                                      void *yourDataPtr);
  typedef STACK_UPP_TYPE(IndexToStringProcPtr) IndexToStringUPP;
  /**
   *  TypeSelectClear()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TypeSelectClear(TypeSelectRecord *tsr);

  /**
          Long ago the implementation of TypeSelectNewKey had a bug that
          required the high word of D0 to be zero or the function did not work.
          Although fixed now, we are continuing to clear the high word
          just in case someone tries to run on an older system.
      */
  /**
   *  TypeSelectNewKey()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  TypeSelectNewKey(const EventRecord *theEvent, TypeSelectRecord *tsr);

  /**
   *  TypeSelectFindItem()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  TypeSelectFindItem(const TypeSelectRecord *tsr, short listSize,
                     TSCode selectMode, IndexToStringUPP getStringProc,
                     void *yourDataPtr);

  /**
   *  TypeSelectCompare()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  TypeSelectCompare(const TypeSelectRecord *tsr, ScriptCode testStringScript,
                    StringPtr testStringPtr);

  /**
   *  NewIndexToStringUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  IndexToStringUPP
  NewIndexToStringUPP(IndexToStringProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppIndexToStringProcInfo = 0x00003F90
  }; /* pascal 1_byte Func(2_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline IndexToStringUPP NewIndexToStringUPP(IndexToStringProcPtr userRoutine)
  {
    return (IndexToStringUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppIndexToStringProcInfo,
                                                  GetCurrentArchitecture());
  }
#else
#define NewIndexToStringUPP(userRoutine)                                     \
  (IndexToStringUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppIndexToStringProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeIndexToStringUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeIndexToStringUPP(IndexToStringUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeIndexToStringUPP(IndexToStringUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeIndexToStringUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeIndexToStringUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeIndexToStringUPP(short item, ScriptCode *itemsScript,
                         StringPtr *itemsStringPtr, void *yourDataPtr,
                         IndexToStringUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeIndexToStringUPP(short item, ScriptCode *itemsScript,
                                        StringPtr *itemsStringPtr,
                                        void *yourDataPtr,
                                        IndexToStringUPP userUPP)
  {
    return (Boolean)CALL_FOUR_PARAMETER_UPP(userUPP, uppIndexToStringProcInfo,
                                            item, itemsScript, itemsStringPtr,
                                            yourDataPtr);
  }
#else
#define InvokeIndexToStringUPP(item, itemsScript, itemsStringPtr, yourDataPtr, \
                               userUPP)                                        \
  (Boolean)                                                                    \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppIndexToStringProcInfo, (item),     \
                              (itemsScript), (itemsStringPtr), (yourDataPtr))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewIndexToStringProc(userRoutine) NewIndexToStringUPP(userRoutine)
#define CallIndexToStringProc(userRoutine, item, itemsScript, itemsStringPtr, \
                              yourDataPtr)                                    \
  InvokeIndexToStringUPP(item, itemsScript, itemsStringPtr, yourDataPtr,      \
                         userRoutine)
#endif /* CALL_NOT_IN_CARBON */

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

#endif /* __TYPESELECT__ */
