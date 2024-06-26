/**
     \file       AppleGuide.h

    \brief   Apple Guide Interfaces.

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup DefGroup

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __APPLEGUIDE__
#define __APPLEGUIDE__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __APPLEEVENTS__
#include <AppleEvents.h>
#endif

#ifndef __FILES__
#include <Files.h>
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

   /* Types*/
   typedef UInt32 AGRefNum;
   typedef UInt32 AGCoachRefNum;
   typedef UInt32 AGContextRefNum;
   struct AGAppInfo
   {
      AEEventID eventId;
      long refCon;
      void *contextObj; /* private system field*/
   };
   typedef struct AGAppInfo AGAppInfo;
   typedef AGAppInfo *AGAppInfoPtr;
   typedef AGAppInfoPtr *AGAppInfoHdl;
   typedef CALLBACK_API(OSErr, CoachReplyProcPtr)(Rect *pRect, Ptr name,
                                                  long refCon);
   typedef CALLBACK_API(OSErr, ContextReplyProcPtr)(Ptr pInputData,
                                                    Size inputDataSize,
                                                    Ptr *ppOutputData,
                                                    Size *pOutputDataSize,
                                                    AGAppInfoHdl hAppInfo);
   typedef STACK_UPP_TYPE(CoachReplyProcPtr) CoachReplyUPP;
   typedef STACK_UPP_TYPE(ContextReplyProcPtr) ContextReplyUPP;
#if CALL_NOT_IN_CARBON
   /**
    *  NewCoachReplyUPP()
    *

    *    \non_carbon_cfm   available as macro/inline
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   CoachReplyUPP
   NewCoachReplyUPP(CoachReplyProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
   enum
   {
      uppCoachReplyProcInfo = 0x00000FE0
   }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
   inline CoachReplyUPP NewCoachReplyUPP(CoachReplyProcPtr userRoutine)
   {
      return (CoachReplyUPP)NewRoutineDescriptor(
          (ProcPtr)(userRoutine), uppCoachReplyProcInfo, GetCurrentArchitecture());
   }
#else
#define NewCoachReplyUPP(userRoutine)    \
   (CoachReplyUPP) NewRoutineDescriptor( \
       (ProcPtr)(userRoutine), uppCoachReplyProcInfo, GetCurrentArchitecture())
#endif
#endif

   /**
    *  NewContextReplyUPP()
    *

    *    \non_carbon_cfm   available as macro/inline
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   ContextReplyUPP
   NewContextReplyUPP(ContextReplyProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
   enum
   {
      uppContextReplyProcInfo = 0x0000FFE0
   }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
   inline ContextReplyUPP NewContextReplyUPP(ContextReplyProcPtr userRoutine)
   {
      return (ContextReplyUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppContextReplyProcInfo,
                                                   GetCurrentArchitecture());
   }
#else
#define NewContextReplyUPP(userRoutine)                                      \
   (ContextReplyUPP)                                                         \
       NewRoutineDescriptor((ProcPtr)(userRoutine), uppContextReplyProcInfo, \
                            GetCurrentArchitecture())
#endif
#endif

   /**
    *  DisposeCoachReplyUPP()
    *

    *    \non_carbon_cfm   available as macro/inline
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   void
   DisposeCoachReplyUPP(CoachReplyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
   inline void DisposeCoachReplyUPP(CoachReplyUPP userUPP)
   {
      DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
   }
#else
#define DisposeCoachReplyUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

   /**
    *  DisposeContextReplyUPP()
    *

    *    \non_carbon_cfm   available as macro/inline
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   void
   DisposeContextReplyUPP(ContextReplyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
   inline void DisposeContextReplyUPP(ContextReplyUPP userUPP)
   {
      DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
   }
#else
#define DisposeContextReplyUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

   /**
    *  InvokeCoachReplyUPP()
    *

    *    \non_carbon_cfm   available as macro/inline
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   InvokeCoachReplyUPP(Rect *pRect, Ptr name, long refCon, CoachReplyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
   inline OSErr InvokeCoachReplyUPP(Rect *pRect, Ptr name, long refCon,
                                    CoachReplyUPP userUPP)
   {
      return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppCoachReplyProcInfo, pRect,
                                             name, refCon);
   }
#else
#define InvokeCoachReplyUPP(pRect, name, refCon, userUPP)                      \
   (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppCoachReplyProcInfo, (pRect), \
                                    (name), (refCon))
#endif
#endif

   /**
    *  InvokeContextReplyUPP()
    *

    *    \non_carbon_cfm   available as macro/inline
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   InvokeContextReplyUPP(Ptr pInputData, Size inputDataSize, Ptr *ppOutputData,
                         Size *pOutputDataSize, AGAppInfoHdl hAppInfo,
                         ContextReplyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
   inline OSErr InvokeContextReplyUPP(Ptr pInputData, Size inputDataSize,
                                      Ptr *ppOutputData, Size *pOutputDataSize,
                                      AGAppInfoHdl hAppInfo,
                                      ContextReplyUPP userUPP)
   {
      return (OSErr)CALL_FIVE_PARAMETER_UPP(userUPP, uppContextReplyProcInfo,
                                            pInputData, inputDataSize, ppOutputData,
                                            pOutputDataSize, hAppInfo);
   }
#else
#define InvokeContextReplyUPP(pInputData, inputDataSize, ppOutputData,    \
                              pOutputDataSize, hAppInfo, userUPP)         \
   (OSErr) CALL_FIVE_PARAMETER_UPP(                                       \
       (userUPP), uppContextReplyProcInfo, (pInputData), (inputDataSize), \
       (ppOutputData), (pOutputDataSize), (hAppInfo))
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewCoachReplyProc(userRoutine) NewCoachReplyUPP(userRoutine)
#define NewContextReplyProc(userRoutine) NewContextReplyUPP(userRoutine)
#define CallCoachReplyProc(userRoutine, pRect, name, refCon) \
   InvokeCoachReplyUPP(pRect, name, refCon, userRoutine)
#define CallContextReplyProc(userRoutine, pInputData, inputDataSize,  \
                             ppOutputData, pOutputDataSize, hAppInfo) \
   InvokeContextReplyUPP(pInputData, inputDataSize, ppOutputData,     \
                         pOutputDataSize, hAppInfo, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

   /* Constants*/

   enum
   {
      kAGDefault = 0,
      kAGFrontDatabase = 1,
      kAGNoMixin = (-1)
   };

   enum
   {
      kAGViewFullHowdy = 1,   /* Full-size Howdy*/
      kAGViewTopicAreas = 2,  /* Full-size Topic Areas*/
      kAGViewIndex = 3,       /* Full-size Index Terms*/
      kAGViewLookFor = 4,     /* Full-size Look-For (Search)*/
      kAGViewSingleHowdy = 5, /* Single-list-size Howdy*/
      kAGViewSingleTopics = 6 /* Single-list-size Topics*/
   };

   enum
   {
      kAGFileMain = FOUR_CHAR_CODE('poco'),
      kAGFileMixin = FOUR_CHAR_CODE('mixn')
   };

   /* To test against AGGetAvailableDBTypes*/
   enum
   {
      kAGDBTypeBitAny = 0x00000001,
      kAGDBTypeBitHelp = 0x00000002,
      kAGDBTypeBitTutorial = 0x00000004,
      kAGDBTypeBitShortcuts = 0x00000008,
      kAGDBTypeBitAbout = 0x00000010,
      kAGDBTypeBitOther = 0x00000080
   };

   typedef UInt16 AGStatus;
   /* Returned by AGGetStatus*/
   enum
   {
      kAGIsNotRunning = 0,
      kAGIsSleeping = 1,
      kAGIsActive = 2
   };

   /* Flags used in AGOpen, AGOpenWithSearch, AGOpenWithView*/
   enum
   {
      kHelpViewerSearchAll = (1 << 0)
   };

   typedef UInt16 AGWindowKind;
   /* Returned by AGGetFrontWindowKind*/
   enum
   {
      kAGNoWindow = 0,
      kAGAccessWindow = 1,
      kAGPresentationWindow = 2
   };

   /* Error Codes*/

   /* Not an enum, because other OSErrs are valid.*/
   typedef SInt16 AGErr;
   /* Apple Guide error codes*/
   enum
   {
      /* -------------------- Apple event reply codes*/
      kAGErrUnknownEvent = -2900,
      kAGErrCantStartup = -2901,
      kAGErrNoAccWin = -2902,
      kAGErrNoPreWin = -2903,
      kAGErrNoSequence = -2904,
      kAGErrNotOopsSequence = -2905,
      kAGErrReserved06 = -2906,
      kAGErrNoPanel = -2907,
      kAGErrContentNotFound = -2908,
      kAGErrMissingString = -2909,
      kAGErrInfoNotAvail = -2910,
      kAGErrEventNotAvailable = -2911,
      kAGErrCannotMakeCoach = -2912,
      kAGErrSessionIDsNotMatch = -2913,
      kAGErrMissingDatabaseSpec = -2914,
      kAGMissingSequenceMap =
          -2915, /* -------------------- Coach's Chalkboard reply codes*/
      kAGErrItemNotFound = -2925,
      kAGErrBalloonResourceNotFound = -2926,
      kAGErrChalkResourceNotFound = -2927,
      kAGErrChdvResourceNotFound = -2928,
      kAGErrAlreadyShowing = -2929,
      kAGErrBalloonResourceSkip = -2930,
      kAGErrItemNotVisible = -2931,
      kAGErrReserved32 = -2932,
      kAGErrNotFrontProcess = -2933,
      kAGErrMacroResourceNotFound = -2934, /* -------------------- API reply codes*/
      kAGErrAppleGuideNotAvailable = -2951,
      kAGErrCannotInitCoach = -2952,
      kAGErrCannotInitContext = -2953,
      kAGErrCannotOpenAliasFile = -2954,
      kAGErrNoAliasResource = -2955,
      kAGErrDatabaseNotAvailable = -2956,
      kAGErrDatabaseNotOpen = -2957,
      kAGErrMissingAppInfoHdl = -2958,
      kAGErrMissingContextObject = -2959,
      kAGErrInvalidRefNum = -2960,
      kAGErrDatabaseOpen = -2961,
      kAGErrInsufficientMemory = -2962
   };

   /* Events*/

   /* Not an enum because we want to make assignments.*/
   typedef UInt32 AGEvent;
   /* Handy events for AGGeneral.*/
   enum
   {
      /* Panel actions (Require a presentation window).*/
      kAGEventDoCoach = FOUR_CHAR_CODE('doco'),
      kAGEventDoHuh = FOUR_CHAR_CODE('dhuh'),
      kAGEventGoNext = FOUR_CHAR_CODE('gonp'),
      kAGEventGoPrev = FOUR_CHAR_CODE('gopp'),
      kAGEventHidePanel = FOUR_CHAR_CODE('pahi'),
      kAGEventReturnBack = FOUR_CHAR_CODE('gobk'),
      kAGEventShowPanel = FOUR_CHAR_CODE('pash'),
      kAGEventTogglePanel = FOUR_CHAR_CODE('patg')
   };

   /* Functions*/

   /**
      AGClose
      Close the database associated with the AGRefNum.
   */

#if CALL_NOT_IN_CARBON
   /**
    *  AGClose()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGClose(AGRefNum *refNum);

   /**
      AGGeneral
      Cause various events to happen.
   */

   /**
    *  AGGeneral()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGGeneral(AGRefNum refNum, AGEvent theEvent);

   /**
      AGGetAvailableDBTypes
      Return the database types available for this application.
   */

   /**
    *  AGGetAvailableDBTypes()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   UInt32
   AGGetAvailableDBTypes(void);

   /**
      AGGetFrontWindowKind
      Return the kind of the front window.
   */

   /**
    *  AGGetFrontWindowKind()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGWindowKind
   AGGetFrontWindowKind(AGRefNum refNum);

   /**
      AGGetFSSpec
      Return the FSSpec for the AGRefNum.
   */

   /**
    *  AGGetFSSpec()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGGetFSSpec(AGRefNum refNum, FSSpec *fileSpec);

   /**
      AGGetStatus
      Return the status of Apple Guide.
   */

   /**
    *  AGGetStatus()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGStatus
   AGGetStatus(void);

   /**
      AGInstallCoachHandler
      Install a Coach object location query handler.
   */

   /**
    *  AGInstallCoachHandler()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGInstallCoachHandler(CoachReplyUPP coachReplyProc, long refCon,
                         AGCoachRefNum *resultRefNum);

   /**
      AGInstallContextHandler
      Install a context check query handler.
   */

   /**
    *  AGInstallContextHandler()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGInstallContextHandler(ContextReplyUPP contextReplyProc, AEEventID eventID,
                           long refCon, AGContextRefNum *resultRefNum);

   /**
      AGIsDatabaseOpen
      Return true if the database associated with the AGRefNum is open.
   */

   /**
    *  AGIsDatabaseOpen()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   Boolean
   AGIsDatabaseOpen(AGRefNum refNum);

   /**
      AGOpen
      Open a guide database.
   */

   /**
    *  AGOpen()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGOpen(ConstFSSpecPtr fileSpec, UInt32 flags, Handle mixinControl,
          AGRefNum *resultRefNum);

   /**
      AGOpenWithSearch
      Open a guide database and preset a search string.
   */

   /**
    *  AGOpenWithSearch()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGOpenWithSearch(ConstFSSpecPtr fileSpec, UInt32 flags, Handle mixinControl,
                    ConstStr255Param searchString, AGRefNum *resultRefNum);

   /**
      AGOpenWithSequence
      Open a guide database and display a presentation window sequence.
   */

   /**
    *  AGOpenWithSequence()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGOpenWithSequence(ConstFSSpecPtr fileSpec, UInt32 flags, Handle mixinControl,
                      short sequenceID, AGRefNum *resultRefNum);

   /**
      AGOpenWithView
      Open a guide database and override the default view.
   */

   /**
    *  AGOpenWithView()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGOpenWithView(ConstFSSpecPtr fileSpec, UInt32 flags, Handle mixinControl,
                  short viewNum, AGRefNum *resultRefNum);

   /**
      AGQuit
      Make Apple Guide quit.
   */

   /**
    *  AGQuit()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGQuit(void);

   /**
      AGRemoveCoachHandler
      Remove the Coach object location query handler.
   */

   /**
    *  AGRemoveCoachHandler()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGRemoveCoachHandler(AGCoachRefNum *resultRefNum);

   /**
      AGRemoveContextHandler
      Remove the context check query handler.
   */

   /**
    *  AGRemoveContextHandler()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGRemoveContextHandler(AGContextRefNum *resultRefNum);

   /**
      AGStart
      Start up Apple Guide in the background.
   */

   /**
    *  AGStart()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.0 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGErr
   AGStart(void);

   /* typedef's*/

#endif /* CALL_NOT_IN_CARBON */

   typedef FSSpec AGFileFSSpecType;
   typedef short AGFileSelectorCountType;
   typedef short AGFileSelectorIndexType;
   typedef OSType AGFileSelectorType;
   typedef long AGFileSelectorValueType;
   typedef short AGFileDBType;
   typedef Str63 AGFileDBMenuNamePtr;
   typedef short AGFileDBScriptType;
   typedef short AGFileDBRegionType;
   typedef short AGFileMajorRevType;
   typedef short AGFileMinorRevType;
   typedef short AGFileCountType;
   /* Database types (for AGFileDBType parameter).*/
   enum
   {
      kAGFileDBTypeAny = 0,
      kAGFileDBTypeHelp = 1,
      kAGFileDBTypeTutorial = 2,
      kAGFileDBTypeShortcuts = 3,
      kAGFileDBTypeAbout = 4,
      kAGFileDBTypeOther = 8
   };

#if CALL_NOT_IN_CARBON
   /**
    *  AGFileGetDBMenuName()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   AGFileGetDBMenuName(const FSSpec *fileSpec, Str63 menuItemNameString);

   /* Get the database type.*/
   /**
    *  AGFileGetDBType()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   AGFileGetDBType(const FSSpec *fileSpec, AGFileDBType *databaseType);

   /**
      Get the version of the software
      that created this database.
   */
   /**
    *  AGFileGetDBVersion()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   AGFileGetDBVersion(const FSSpec *fileSpec, AGFileMajorRevType *majorRev,
                      AGFileMinorRevType *minorRev);

   /* Get the database script and region information.*/
   /**
    *  AGFileGetDBCountry()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   AGFileGetDBCountry(const FSSpec *fileSpec, AGFileDBScriptType *script,
                      AGFileDBRegionType *region);

   /* Return the number of selectors in database.*/
   /**
    *  AGFileGetSelectorCount()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGFileSelectorCountType
   AGFileGetSelectorCount(const FSSpec *fileSpec);

   /**
      Get the i-th database selector (1 to AGFileSelectorCountType)
      and its value.
   */
   /**
    *  AGFileGetSelector()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   AGFileGetSelector(const FSSpec *fileSpec,
                     AGFileSelectorIndexType selectorNumber,
                     AGFileSelectorType *selector, AGFileSelectorValueType *value);

   /* Return true if database is mixin.*/
   /**
    *  AGFileIsMixin()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   Boolean
   AGFileIsMixin(const FSSpec *fileSpec);

   /**
      Return the number of database files
      of the specified databaseType and main/mixin.
      Any file creator is acceptible,
      but type must be kAGFileMain or kAGFileMixin.
   */
   /**
    *  AGFileGetDBCount()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   AGFileCountType
   AGFileGetDBCount(short vRefNum, long dirID, AGFileDBType databaseType,
                    Boolean wantMixin);

   /**
      Get the FSSpec for the dbIndex-th database
      of the specified databaseType and main/mixin.
      Any file creator is acceptible,
      but type must be kAGFileMain or kAGFileMixin.
   */
   /**
    *  AGFileGetIndDB()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   AGFileGetIndDB(short vRefNum, long dirID, AGFileDBType databaseType,
                  Boolean wantMixin, short dbIndex, FSSpec *fileSpec);

   /**
      This selector must match with the application
      creator in order for this file to appear in the
      application's Help menu. Ignored for mixin files
      because they never appear in the Help menu anyway.
      If empty (zeros), will appear in the Help menu
      of any host application.
   */
   /**
    *  AGFileGetHelpMenuAppCreator()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   AGFileGetHelpMenuAppCreator(const FSSpec *fileSpec, OSType *helpMenuAppCreator);

   /**
      This selector must match in the main and mixin
      files in order for the mixin to mix-in with the main.
      Empty (zeros) selectors are valid matches.
      A '****' selector will mix-in with any main.
   */
   /**
    *  AGFileGetMixinMatchSelector()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   AGFileGetMixinMatchSelector(const FSSpec *fileSpec, OSType *mixinMatchSelector);

   /**
      This is the text of the balloon for the
      Help menu item for this database.
   */
   /**
    *  AGFileGetHelpMenuBalloonText()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   AGFileGetHelpMenuBalloonText(const FSSpec *fileSpec,
                                Str255 helpMenuBalloonString);

   /**
    *  AGGetSystemDB()
    *

    *    \non_carbon_cfm   in AppleGuideLib 2.2 and later
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   OSErr
   AGGetSystemDB(AGFileDBType databaseType, Boolean wantMixin, FSSpec *pFileSpec);

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

#endif /* __APPLEGUIDE__ */
