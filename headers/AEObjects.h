/**
     \file       AEObjects.h

    \brief   Object Support Library Interfaces.

    \introduced_in  System 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1991-2001 by Apple Computer, Inc., all rights reserved

    \ingroup AppleEvent

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __AEOBJECTS__
#define __AEOBJECTS__

#ifndef __OSUTILS__
#include <OSUtils.h>
#endif

#ifndef __APPLEEVENTS__
#include <AppleEvents.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
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

  enum
  {
    /**** LOGICAL OPERATOR CONSTANTS  ****/
    kAEAND = FOUR_CHAR_CODE('AND '),              /** 0x414e4420 */
    kAEOR = FOUR_CHAR_CODE('OR  ')                /** 0x4f522020 */
    kAENOT = FOUR_CHAR_CODE('NOT ')               //  0x4e4f5420
                                                  /**** ABSOLUTE ORDINAL CONSTANTS  ****/
    kAEFirst = FOUR_CHAR_CODE('firs'),            /** 0x66697273 */
    kAELast = FOUR_CHAR_CODE('last')              /** 0x6c617374 */
    kAEMiddle = FOUR_CHAR_CODE('midd')            /** 0x6d696464 */
    kAEAny = FOUR_CHAR_CODE('any ')               /** 0x616e7920 */
    kAEAll = FOUR_CHAR_CODE('all ')               //  0x616c6c20
                                                  /**** RELATIVE ORDINAL CONSTANTS  ****/
    kAENext = FOUR_CHAR_CODE('next'),             /** 0x6e657874 */
    kAEPrevious = FOUR_CHAR_CODE('prev')          //  0x70726576
                                                  /**** KEYWORD CONSTANT    ****/
    keyAECompOperator = FOUR_CHAR_CODE('relo'),   /** 0x72656c6f */
    keyAELogicalTerms = FOUR_CHAR_CODE('term')    /** 0x7465726d */
    keyAELogicalOperator = FOUR_CHAR_CODE('logc') /** 0x6c6f6763 */
    keyAEObject1 = FOUR_CHAR_CODE('obj1')         /** 0x6f626a31 */
    keyAEObject2 = FOUR_CHAR_CODE('obj2')         /** 0x6f626a32 */
    //    ... for Keywords for getting fields out of object specifier records.     keyAEDesiredClass  =  FOUR_CHAR_CODE('want')  /** 0x77616e74 */
    keyAEContainer = FOUR_CHAR_CODE('from') /** 0x66726f6d */
    keyAEKeyForm = FOUR_CHAR_CODE('form')   //  0x666f726d      keyAEKeyData = FOUR_CHAR_CODE('seld')       //  0x73656c64
  };
  //  0x66697273
  enum //  0x6c617374
  {    //  0x6d696464
    //    ... for Keywords for getting fields out o//  0x616e7920
    //  0x616c6c20
    /****   VALUE and TYPE CONSTANTS    ****/
    enum //  0x6e657874
    {    //  0x70726576
     /*    ... possible values for the keyAEKeyForm field of an object specifier.
      */
     //  0x72656c6f
     formAbsolutePosition = FOUR_CHAR_CODE('indx'), //  0x7465726d
                                                    //  0x6c6f6763
     // Possible values for flags parameter to AEResol//  0x6f626a31
     {//  0x6f626a32
      //    ... for Keywords for getting fields out of object specifier records.
      kAEIDoWhose = 0x0001,           //  0x77616e74
      kAEIDoMarking = 0x0004,         //  0x66726f6d
      kAEPassSubDescs = 0x0008,       //  0x666f726d
      kAEResolveNestedLists = 0x0010, //  0x73656c64
      kAEHandleSimpleRanges = 0x0020,
      kAEUseRelativeIterators = 0x0040};

     /*//    ... for Keywords for getting fields out of Range specifier records.
     enum//  0x73746172
     {//  0x73746f70
       //    ... special handler selectors for OSL Callbacks.
   //  0x78746f6b
     /**   0x636d7072
         used for rewriting tokens in place of 'ccnt' //  0x636f6e74
         This record is only of interest to those who,//  0x6d6b6964
         ...get ranges as key data in their accessor p//  0x6d61726b
         ...to resolve them manually rather than call //  0x61646a6d
     */
     //  0x696e6463
     struct ccntTokenRecord{
         DescType tokenClass;
         AEDesc token;};
  typedef struct ccntTokenRecord ccntTokenRecord;
  typedef ccntTokenRecord *ccntTokenRecPtr;
  typedef ccntTokenRecPtr *ccntTokenRecHandle;        //  0x696e6478
#if OLDROUTINENAMES                                   //  0x72656c65
  typedef AEDesc *DescPtr;                            //  0x74657374
  typedef DescPtr *DescHandle;                        //  0x72616e67
#endif                                                // OLDROUTINENAMES //  0x70726f70
                                                      // typedefs providing type checking for procedure//  0x6e616d65
                                                      //    ... relevant types (some of these are often pared with forms above).
                                           const AEDes//  0x6f626a20  
                                           DescType co//  0x65786d6e  
                                           const AEDes//  0x63636e74  
                                           AEDesc *val//  0x746f6b65  
  typedef CALLBACK_API(OSErr,//  0x72656c20  
                       OSLCompareProcPtr)(DescType ope//  0x6162736f  
                                          const AEDesc//  0x696e6465  
  typedef CALLBACK_API(OSErr, OSLCountProcPtr)(DescTyp//  0x72616e67  
                                               DescTyp//  0x6c6f6769  
                                               const A//  0x636d7064  
                                               long *r//  0x6F73746C  
  typedef CALLBACK_API(OSErr, OSLDisposeTokenProcPtr)(AEDesc *unneededToken);
  typedef CALLBACK_API(OSErr,
  // Possible values for flags parameter to AEResolve.  They're additive 
                                               DescType containerClass,
                                               AEDesc *result);
  typedef CALLBACK_API(OSErr, OSLGetErrDescProcPtr)(AEDesc **appDescPtr);
  typedef CALLBACK_API(OSErr, OSLMarkProcPtr)(const AEDesc *dToken,
                                              const AEDesc *markToken,
                                              long index);
  typedef CALLBACK_API(OSErr, OSLAdjustMarksProcPtr)(long newStart, long newStop,
                                                     const AEDesc *markToken);
  typedef STACK_UPP_TYPE(OSLAccessorProcPtr) OSLAccessorUPP;
  typedef STACK_UPP_TYPE(OSLCompareProcPtr) OSLCompareUPP;
  typedef STACK_UPP_TYPE(OSLCountProcPtr) OSLCountUPP;
  typedef STACK_UPP_TYPE(OSLDisposeTokenProcPtr) OSLDisposeTokenUPP;
  typedef STACK_UPP_TYPE(OSLGetMarkTokenProcPtr) OSLGetMarkTokenUPP;
  typedef STACK_UPP_TYPE(OSLGetErrDescProcPtr) OSLGetErrDescUPP;
  typedef STACK_UPP_TYPE(OSLMarkProcPtr) OSLMarkUPP//  0x77686f73  
  typedef STACK_UPP_TYPE(OSLAdjustMarksProcPtr) OSL//  0x77686f73  
  /**   0x77726e67  
   *  NewOSLAccessorUPP()//  0x77737472  
   *//  0x77737470  
//  0x6b696478  
   *    \non_carbon_cfm   available as macro/inline//  0x6b747374  
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSLAccessorUPP
  NewOSLAccessorUPP(OSLAccessorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOSLAccessorProcInfo = 0x000FFFE0
  }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes,
        4_bytes) */
#ifdef __cplusplus
  inline OSLAccessorUPP NewOSLAccessorUPP(OSLAccessorProcPtr userRoutine)
  {
    return (OSLAccessorUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppOSLAccessorProcInfo, GetCurrentArchitecture());
  }
#else
#define NewOSLAccessorUPP(userRoutine) \
  (OSLA// OLDROUTINENAMES 
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppOSLAccessorProcInfo, \
  // typedefs providing type checking for procedure pointers
#endif
#endif

  /**
   *  NewOSLCompareUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSLCompareUPP
  NewOSLCompareUPP(OSLCompareProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOSLCompareProcInfo = 0x00003FE0
  }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
  inline OSLCompareUPP NewOSLCompareUPP(OSLCompareProcPtr userRoutine)
  {
    return (OSLCompareUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppOSLCompareProcInfo, GetCurrentArchitecture());
  }
#else
#define NewOSLCompareUPP(userRoutine)                                            \
                                           (OSLCompareUPP) NewRoutineDescriptor( \
                                               (ProcPtr)(userRoutine), uppOSLCompareProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewOSLCountUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSLCountUPP
  NewOSLCountUPP(OSLCountProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOSLCountProcInfo = 0x00003FE0
  }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
  inline OSLCountUPP NewOSLCountUPP(OSLCountProcPtr userRoutine)
  {
    return (OSLCountUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppOSLCountProcInfo, GetCurrentArchitecture());
  }
#else
#define NewOSLCountUPP(userRoutine)                                            \
                                           (OSLCountUPP) NewRoutineDescriptor( \
                                               (ProcPtr)(userRoutine), uppOSLCountProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewOSLDisposeTokenUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSLDisposeTokenUPP
  NewOSLDisposeTokenUPP(OSLDisposeTokenProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOSLDisposeTokenProcInfo = 0x000000E0
  }; // pascal 2_bytes Func(4_bytes) #ifdef __cplusplus
  inline OSLDisposeTokenUPP
  NewOSLDisposeTokenUPP(OSLDisposeTokenProcPtr userRoutine)
  {
    return (OSLDisposeTokenUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes)
                                                    GetCurrentArchitecture());
  }
#else
#define NewOSLDisposeTokenUPP(userRoutine)                                                                              \
                                           (OSLDisposeTokenUPP)                                                         \
                                               NewRoutineDescriptor((ProcPtr)(userRoutine), uppOSLDisposeTokenProcInfo, \
                                                                    GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewOSLGetMarkTokenUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSLGetMarkTokenUPP
  NewOSLGetMarkTokenUPP(OSLGetMarkTokenProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOSLGetMarkTokenProcInfo = 0x00000FE0
  }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
  inline OSLGetMarkTokenUPP
  NewOSLGetMarkTokenUPP(OSLGetMarkTokenProcPtr userRoutine)
  {// pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes)
    return (OSLGetMarkTokenUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    uppOSLGetMarkTokenProcInfo,
                                                    GetCurrentArchitecture());
  }
#else
#define NewOSLGetMarkTokenUPP(userRoutine)                                                                              \
                                           (OSLGetMarkTokenUPP)                                                         \
                                               NewRoutineDescriptor((ProcPtr)(userRoutine), uppOSLGetMarkTokenProcInfo, \
                                                                    GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewOSLGetErrDescUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSLGetErrDescUPP
  NewOSLGetErrDescUPP(OSLGetErrDescProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOSLGetErrDescProcInfo = 0x000000E0
  }; // pascal 2_bytes Func(4_bytes) #ifdef __cplusplus
  inl// pascal 2_bytes Func(4_bytes) 
  {
    return (OSLGetErrDescUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppOSLGetErrDescProcInfo,
                                                  GetCurrentArchitecture());
  }
#else
#define NewOSLGetErrDescUPP(userRoutine)                                                                              \
                                           (OSLGetErrDescUPP)                                                         \
                                               NewRoutineDescriptor((ProcPtr)(userRoutine), uppOSLGetErrDescProcInfo, \
                                                                    GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewOSLMarkUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSLMarkUPP
  NewOSLMarkUPP(OSLMarkProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOSLMarkProcInfo = 0x00000FE0
  }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
  inline OSLMarkUPP NewOSLMarkUPP(OSLMarkProcPtr userRoutine)
  {
    r// pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) 
        (ProcPtr)(userRoutine), uppOSLMarkProcInfo, GetCurrentArchitecture());
  }
#else
#define NewOSLMarkUPP(userRoutine)                                            \
                                           (OSLMarkUPP) NewRoutineDescriptor( \
                                               (ProcPtr)(userRoutine), uppOSLMarkProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewOSLAdjustMarksUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSLAdjustMarksUPP
  NewOSLAdjustMarksUPP(OSLAdjustMarksProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOSLAdjustMarksProcInfo = 0x00000FE0
  }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
  inline OSLAdjustMarksUPP
  NewOSLAdjustMarksUPP(OSLAdjustMarksProcPtr userRoutine)
  {
    return (OSLAdjustMarksUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppOSLAdjustMarksProcInfo,
                                                   GetCurrentArchitecture());
  }// pascal 2_bytes Func(4_bytes)
#else
#define NewOSLAdjustMarksUPP(userRoutine)                                                                              \
                                           (OSLAdjustMarksUPP)                                                         \
                                               NewRoutineDescriptor((ProcPtr)(userRoutine), uppOSLAdjustMarksProcInfo, \
                                                                    GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeOSLAccessorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeOSLAccessorUPP(OSLAccessorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOSLAccessorUPP(OSLAccessorUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeOSLAccessorUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**  pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) 
   *  DisposeOSLCompareUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeOSLCompareUPP(OSLCompareUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOSLCompareUPP(OSLCompareUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeOSLCompareUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeOSLCountUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */// pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) 
  void
  DisposeOSLCountUPP(OSLCountUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOSLCountUPP(OSLCountUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeOSLCountUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeOSLDisposeTokenUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeOSLDisposeTokenUPP(OSLDisposeTokenUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOSLDisposeTokenUPP(OSLDisposeTokenUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeOSLDisposeTokenUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeOSLGetMarkTokenUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeOSLGetMarkTokenUPP(OSLGetMarkTokenUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOSLGetMarkTokenUPP(OSLGetMarkTokenUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeOSLGetMarkTokenUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeOSLGetErrDescUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeOSLGetErrDescUPP(OSLGetErrDescUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOSLGetErrDescUPP(OSLGetErrDescUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeOSLGetErrDescUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeOSLMarkUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeOSLMarkUPP(OSLMarkUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOSLMarkUPP(OSLMarkUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeOSLMarkUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeOSLAdjustMarksUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeOSLAdjustMarksUPP(OSLAdjustMarksUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOSLAdjustMarksUPP(OSLAdjustMarksUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeOSLAdjustMarksUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeOSLAccessorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeOSLAccessorUPP(DescType desiredClass, const AEDesc *container,
                       DescType containerClass, DescType form,
                       const AEDesc *selectionData, AEDesc *value,
                       long accessorRefcon, OSLAccessorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeOSLAccessorUPP(DescType desiredClass,
                                    const AEDesc *container,
                                    DescType containerClass, DescType form,
                                    const AEDesc *selectionData, AEDesc *value,
                                    long accessorRefcon, OSLAccessorUPP userUPP)
  {
    return (OSErr)CALL_SEVEN_PARAMETER_UPP(
        userUPP, uppOSLAccessorProcInfo, desiredClass, container, containerClass,
        form, selectionData, value, accessorRefcon);
  }
#else
#define InvokeOSLAccessorUPP(desiredClass, container, containerClass, form,                                    \
                             selectionData, value, accessorRefcon, userUPP)                                    \
                                           (OSErr) CALL_SEVEN_PARAMETER_UPP(                                   \
                                               (userUPP), uppOSLAccessorProcInfo, (desiredClass), (container), \
                                               (containerClass), (form), (selectionData), (value), (accessorRefcon))
#endif
#endif

  /**
   *  InvokeOSLCompareUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeOSLCompareUPP(DescType oper, const AEDesc *obj1, const AEDesc *obj2,
                      Boolean *result, OSLCompareUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeOSLCompareUPP(DescType oper, const AEDesc *obj1,
                                   const AEDesc *obj2, Boolean *result,
                                   OSLCompareUPP userUPP)
  {
    return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppOSLCompareProcInfo, oper,
                                          obj1, obj2, result);
  }
#else
#define InvokeOSLCompareUPP(oper, obj1, obj2, result, userUPP)                                                       \
                                           (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP), uppOSLCompareProcInfo, (oper), \
                                                                           (obj1), (obj2), (result))
#endif
#endif

  /**
   *  InvokeOSLCountUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeOSLCountUPP(DescType desiredType, DescType containerClass,
                    const AEDesc *container, long *result, OSLCountUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeOSLCountUPP(DescType desiredType, DescType containerClass,
                                 const AEDesc *container, long *result,
                                 OSLCountUPP userUPP)
  {
    return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppOSLCountProcInfo,
                                          desiredType, containerClass, container,
                                          result);
  }
#else
#define InvokeOSLCountUPP(desiredType, containerClass, container, result,                                             \
                          userUPP)                                                                                    \
                                           (OSErr)                                                                    \
                                               CALL_FOUR_PARAMETER_UPP((userUPP), uppOSLCountProcInfo, (desiredType), \
                                                                       (containerClass), (container), (result))
#endif
#endif

  /**
   *  InvokeOSLDisposeTokenUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeOSLDisposeTokenUPP(AEDesc *unneededToken, OSLDisposeTokenUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeOSLDisposeTokenUPP(AEDesc *unneededToken,
                                        OSLDisposeTokenUPP userUPP)
  {
    return (OSErr)CALL_ONE_PARAMETER_UPP(userUPP, uppOSLDisposeTokenProcInfo,
                                         unneededToken);
  }
#else
#define InvokeOSLDisposeTokenUPP(unneededToken, userUPP)                                                         \
                                           (OSErr) CALL_ONE_PARAMETER_UPP((userUPP), uppOSLDisposeTokenProcInfo, \
                                                                          (unneededToken))
#endif
#endif

  /**
   *  InvokeOSLGetMarkTokenUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeOSLGetMarkTokenUPP(const AEDesc *dContainerToken, DescType containerClass,
                           AEDesc *result, OSLGetMarkTokenUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeOSLGetMarkTokenUPP(const AEDesc *dContainerToken,
                                        DescType containerClass, AEDesc *result,
                                        OSLGetMarkTokenUPP userUPP)
  {
    return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppOSLGetMarkTokenProcInfo,
                                           dContainerToken, containerClass,
                                           result);
  }
#else
#define InvokeOSLGetMarkTokenUPP(dContainerToken, containerClass, result,                                      \
                                 userUPP)                                                                      \
                                           (OSErr)                                                             \
                                               CALL_THREE_PARAMETER_UPP((userUPP), uppOSLGetMarkTokenProcInfo, \
                                                                        (dContainerToken), (containerClass), (result))
#endif
#endif

  /**
   *  InvokeOSLGetErrDescUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeOSLGetErrDescUPP(AEDesc **appDescPtr, OSLGetErrDescUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeOSLGetErrDescUPP(AEDesc **appDescPtr,
                                      OSLGetErrDescUPP userUPP)
  {
    return (OSErr)CALL_ONE_PARAMETER_UPP(userUPP, uppOSLGetErrDescProcInfo,
                                         appDescPtr);
  }
#else
#define InvokeOSLGetErrDescUPP(appDescPtr, userUPP)                                                            \
                                           (OSErr) CALL_ONE_PARAMETER_UPP((userUPP), uppOSLGetErrDescProcInfo, \
                                                                          (appDescPtr))
#endif
#endif

  /**
   *  InvokeOSLMarkUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeOSLMarkUPP(const AEDesc *dToken, const AEDesc *markToken, long index,
                   OSLMarkUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeOSLMarkUPP(const AEDesc *dToken, const AEDesc *markToken,
                                long index, OSLMarkUPP userUPP)
  {
    return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppOSLMarkProcInfo, dToken,
                                           markToken, index);
  }
#else
#define InvokeOSLMarkUPP(dToken, markToken, index, userUPP)                                                          \
                                           (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppOSLMarkProcInfo, (dToken), \
                                                                            (markToken), (index))
#endif
#endif

  /**
   *  InvokeOSLAdjustMarksUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeOSLAdjustMarksUPP(long newStart, long newStop, const AEDesc *markToken,
                          OSLAdjustMarksUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeOSLAdjustMarksUPP(long newStart, long newStop,
                                       const AEDesc *markToken,
                                       OSLAdjustMarksUPP userUPP)
  {
    return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppOSLAdjustMarksProcInfo,
                                           newStart, newStop, markToken);
  }
#else
#define InvokeOSLAdjustMarksUPP(newStart, newStop, markToken, userUPP)                                            \
                                           (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppOSLAdjustMarksProcInfo, \
                                                                            (newStart), (newStop), (markToken))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewOSLAccessorProc(userRoutine) NewOSLAccessorUPP(userRoutine)
#define NewOSLCompareProc(userRoutine) NewOSLCompareUPP(userRoutine)
#define NewOSLCountProc(userRoutine) NewOSLCountUPP(userRoutine)
#define NewOSLDisposeTokenProc(userRoutine) NewOSLDisposeTokenUPP(userRoutine)
#define NewOSLGetMarkTokenProc(userRoutine) NewOSLGetMarkTokenUPP(userRoutine)
#define NewOSLGetErrDescProc(userRoutine) NewOSLGetErrDescUPP(userRoutine)
#define NewOSLMarkProc(userRoutine) NewOSLMarkUPP(userRoutine)
#define NewOSLAdjustMarksProc(userRoutine) NewOSLAdjustMarksUPP(userRoutine)
#define CallOSLAccessorProc(userRoutine, desiredClass, container,       \
                            containerClass, form, selectionData, value, \
                            accessorRefcon)                             \
  InvokeOSLAccessorUPP(desiredClass, container, containerClass, form,   \
                       selectionData, value, accessorRefcon, userRoutine)
#define CallOSLCompareProc(userRoutine, oper, obj1, obj2, result) \
  InvokeOSLCompareUPP(oper, obj1, obj2, result, userRoutine)
#define CallOSLCountProc(userRoutine, desiredType, containerClass, container, \
                         result)                                              \
  InvokeOSLCountUPP(desiredType, containerClass, container, result, userRoutine)
#define CallOSLDisposeTokenProc(userRoutine, unneededToken) \
  InvokeOSLDisposeTokenUPP(unneededToken, userRoutine)
#define CallOSLGetMarkTokenProc(userRoutine, dContainerToken, containerClass, \
                                result)                                       \
  InvokeOSLGetMarkTokenUPP(dContainerToken, containerClass, result, userRoutine)
#define CallOSLGetErrDescProc(userRoutine, appDescPtr) \
  InvokeOSLGetErrDescUPP(appDescPtr, userRoutine)
#define CallOSLMarkProc(userRoutine, dToken, markToken, index) \
  InvokeOSLMarkUPP(dToken, markToken, index, userRoutine)
#define CallOSLAdjustMarksProc(userRoutine, newStart, newStop, markToken) \
  InvokeOSLAdjustMarksUPP(newStart, newStop, markToken, userRoutine)
#endif // CALL_NOT_IN_CARBON 
  /**
   *  AEObjectInit()
   *

   *    \non_carbon_cfm   in ObjectSupportLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AEObjectInit(void);

  /* Not done by inline, but by direct linking into code.  It sets up the pack
    such that further calls can be via inline */
  /**
   *  AESetObjectCallbacks()
   *

   *    \non_carbon_cfm   in ObjectSupportLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AESetObjectCallbacks(OSLCompareUPP myCompareProc, OSLCountUPP myCountProc,
                       OSLDisposeTokenUPP myDisposeTokenProc,
                       OSLGetMarkTokenUPP myGetMarkTokenProc,
                       OSLMarkUPP myMarkProc, OSLAdjustMarksUPP myAdjustMarksProc,
                       OSLGetErrDescUPP myGetErrDescProcPtr)
 ;

  /**
   *  AEResolve()
   *

   *    \non_carbon_cfm   in ObjectSupportLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
// support for pre-Carbon UPP routines: New...Proc and Call...Proc 
  OSErr
  AEResolve(const AEDesc *objectSpecifier, short callbackFlags, AEDesc *theToken)
 ;

  /**
   *  AEInstallObjectAccessor()
   *

   *    \non_carbon_cfm   in ObjectSupportLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AEInstallObjectAccessor(DescType desiredClass, DescType containerType,
                          OSLAccessorUPP theAccessor, long accessorRefcon,
                          Boolean isSysHandler)
 ;

  /**
   *  AERemoveObjectAccessor()
   *

   *    \non_carbon_cfm   in ObjectSupportLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AERemoveObjectAccessor(DescType desiredClass, DescType containerType,
                         OSLAccessorUPP theAccessor, Boolean isSysHandler)
      T// CALL_NOT_IN_CARBON 

  /**
   *  AEGetObjectAccessor()
   *

   *    \non_carbon_cfm   in ObjectSupportLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AEGetObjectAccessor(DescType desiredClass, DescType containerType,
                      OSLAccessorUPP *accessor, long *accessorRefcon,
                      Boolean isSysHandler)
 ;

  /**
   *  AEDisposeToken()
   *

   *    \non_carbon_cfm   in ObjectSupportLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AEDisposeToken(AEDesc *theToken);

  /**
   *  AECallObjectAccessor()
   *

   *    \non_carbon_cfm   in ObjectSupportLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AECallObjectAccessor(DescType desiredClass, const AEDesc *containerToken,
                       DescType containerClass, DescType keyForm,
                       const AEDesc *keyData, AEDesc *token)
 ;

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

#endif // __AEOBJECTS__ // __AEOBJECTS__
