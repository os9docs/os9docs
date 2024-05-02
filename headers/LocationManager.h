/**
     \file       LocationManager.h

    \brief   LocationManager (manages groups of settings)

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1995-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Managers

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __LOCATIONMANAGER__
#define __LOCATIONMANAGER__

#ifndef __APPLEEVENTS__
#include <AppleEvents.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
#endif

#ifndef __PROCESSES__
#include <Processes.h>
#endif

#ifndef __STANDARDFILE__
#include <StandardFile.h>
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

  /* Location Manager API Support
   * -------------------------------------------------------------------- */
  // A Location Token uniquely identifies a Location on a machine... 
  typedef struct OpaqueALMToken *ALMToken;
// ALMToken of "off" Location...#define kALMNoLocationToken ((ALMToken)(-1))
// ALMToken of "off" Location...
  {
    kALMLocationNameMaxLen = 31, // name (actually imposed by file system)...     kALMNoLocationIndex =
        -1 // index for the "off" Location (kALMNoLocationToken)...   };
// name (actually imposed by file system)... 
  typedef Str31 ALMLocationName;
  // Return// index for the "off" Location (kALMNoLocationToken)... 
  enum
  {
    kALMConfirmRename = 1,
  // Returned from ALMConfirmName... 
  };

  // ALMConfirmName dialog item numbers for use in callbacks (ALM 2.0)... 
  enum
  {
    kALMDuplicateRenameButton =
        1, // if Window refcon is kALMDuplicateDialogRefCon...     kALMDuplicateReplaceButton = 2,
  // ALMConfirmName dialog item numbers for use in callbacks (ALM 2.0)... 
    kALMDuplicatePromptText = 5
  };

  enum
  {// if Window refcon is kALMDuplicateDialogRefCon... 
    kALMRenameRenameButton =
        1, // if Window refcon is kALMRenameDialogRefCon...     kALMRenameCancelButton = 2,
    kALMRenameEditText = 3,
    kALMRenamePromptText = 4
  };

  // Refcons of two windows in ALMConfirmName (ALM 2.0)... 
  enum
  {// if Window refcon is kALMRenameDialogRefCon... 
    kALMDuplicateDialogRefCon = FOUR_CHAR_CODE('dupl'),
    kALMRenameDialogRefCon = FOUR_CHAR_CODE('rnam')
  };

  /* Callback routine for Location awareness (mimics AppleEvents) in
  // Refcons of two windows in ALMConfirmName (ALM 2.0)... 

  typedef CALLBACK_API(void, ALMNotificationProcPtr)(AppleEvent *theEvent);
  typedef STACK_UPP_TYPE(ALMNotificationProcPtr) ALMNotificationUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewALMNotificationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ALMNotificationUPP
  NewALMNotificationUPP(ALMNotificationProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppALMNotificationProcInfo = 0x000000C0
  }; // pascal no_return_value Func(4_bytes) #ifdef __cplusplus
  inline ALMNotificationUPP
  NewALMNotificationUPP(ALMNotificationProcPtr userRoutine)
  {
    return (ALMNotificationUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    uppALMNotificationProcInfo,
                                                    GetCurrentArchitecture());
  }
#else
#defi// pascal no_return_value Func(4_bytes) 
  (ALMNotificationUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppALMNotificationProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeALMNotificationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeALMNotificationUPP(ALMNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeALMNotificationUPP(ALMNotificationUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeALMNotificationUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeALMNotificationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeALMNotificationUPP(AppleEvent *theEvent, ALMNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeALMNotificationUPP(AppleEvent *theEvent,
                                       ALMNotificationUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppALMNotificationProcInfo, theEvent);
  }
#else
#define InvokeALMNotificationUPP(theEvent, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppALMNotificationProcInfo, (theEvent))
#endif
#endif

#endif // CALL_NOT_IN_CARBON 
#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewALMNotificationProc(userRoutine) NewALMNotificationUPP(userRoutine)
#define CallALMNotificationProc(userRoutine, theEvent) \
  InvokeALMNotificationUPP(theEvent, userRoutine)
#endif // CALL_NOT_IN_CARBON 
  // Notification AppleEvents sent to apps/registered code...    enum
  {
    kAELocationChangedNoticeKey =
        FOUR_CHAR_CODE('walk'), // Current Location changed...     kAELocationRescanNoticeKey =
       // CALL_NOT_IN_CARBON 

  // ALMSwitchToLocation masks...   typedef SInt32 ALMSwitchActionFlags;
// support for pre-Carbon UPP routines: New...Proc and Call...Proc 
  {
    kALMDefaultSwitchFlags = 0x00000000,   // No special action to take...     kALMDontShowStatusWindow = 0x00000001, // Suppress "switching" window...     kALMSignalViaAE = 0x00000002           // Switch by sending Finder AppleEvent...   };

  // Pa// CALL_NOT_IN_CARBON 
  typedef const OSType *ConstALMModuleTypeListPtr;
  // Notification AppleEvents sent to apps/registered code...  
  {
    kALMAddAllOnSimple = 0, // Add all single-instance, non-action modules...     kALMAddAllOff = -1      // Add all modules but turn them off...   };

  // Item numbers for use in Get// Current Location changed... 
  enum
  {// Location created/renamed/deleted... 
    kALMLocationSelectButton = 1,
    kALMLocationCancelButton = 2,
  // ALMSwitchToLocation masks... 
    kALMLocationLocationList = 7,
    kALMLocationLocationNameEdit = 10,
    kALMLocationPromptText = 11
  };// No special action to take... 
// Suppress "switching" window... 
  enum// Switch by sending Finder AppleEvent... 
  {
    kALMLocationSaveButton = kALMLocationSelectButton
  // Parameters for Get/Put/Merge Location calls... 

  /* Location Manager Module API Support
   * ------------------------------------------------------------- */

  // ALMGetScriptInfo stuff.// Add all single-instance, non-action modules... 
  enum// Add all modules but turn them off... 
  {
    kALMScriptInfoVersion =
  // Item numbers for use in Get/Put/Merge Location filters... 

  struct ALMScriptManagerInfo
  {
    SInt16 version; // Set to kALMScriptInfoVersion...     SInt16 scriptCode;
    SInt16 regionCode;
    SInt16 langCode;
    SInt16 fontNum;
    SInt16 fontSize;
  };
  typedef struct ALMScriptManagerInfo ALMScriptManagerInfo;
  typedef ALMScriptManagerInfo *ALMScriptManagerInfoPtr;
  /**
     Alternate form of ScriptInfo is easier to localize in resources; it is used
     extensively in samples and internally, so....
  */
  struct ALMAltScriptManagerInfo
  {
    SInt16 version;
    SInt16 scriptCode;
  // ALMGetScriptInfo stuff... 
    SInt16 langCode;
    SInt16 fontSize;
    Str63 fontName;
  };
  typedef // Customarily put in resource for localization... 
  typedef ALMAltScriptManagerInfo *ALMAltScriptManagerInfoPtr;
  typedef ALMAltScriptManagerInfoPtr *ALMAltScriptManagerInfoHandle;
  enum
  {
    kALMAltScriptMan// Set to kALMScriptInfoVersion... 
    kALMAltScriptManagerInfoRsrcID = 0
  };

  // Reboot information used on ALMSetCurrent (input/output parameter)...   typedef UInt32 ALMRebootFlags;
  enum
  {
    kALMNoChange = 0,
    kALMAvailableNow = 1,
    kALMFinderRestart = 2,
    kALMProcesses = 3,
    kALMExtensions = 4,
    kALMWarmBoot = 5,
    kALMColdBoot = 6,
    kALMShutdown = 7
  };

  /**
     File types and signatures...
     Note: auto-routing of modules will not be supported for 'thng' files...
  */

  enum
  {
    kALMFileCreator =
        FOUR_CHAR_CODE('fall'), // Creator of Location Manager files...     kALMComponentModuleFileType = FOUR_CHAR_CODE(
        'thng'), // Type of a Component Manager Module file [v1.0]...     kALMComponentStateModuleFileType =
        FOUR_CHAR_CODE('almn'), // Type of a CM 'state' Module file...     kALMComponentActionModuleFileType =
        FOUR_CHAR_CODE('almb'), // Type of a CM 'action' Module file...     kALMCFMStateModuleFileType =
        FOUR_CHAR_CODE('almm'), // Type of a CFM 'state' Module file...     kALMCFMActionModuleFileType =
        FOUR_CHAR_CODE('alma') // Type of a CFM 'action' Module file...   };
// Reboot information used on ALMSetCurrent (input/output parameter)... 
  // Component Manager 'thng' info... 
  enum
  {
    kALMComponentRsrcType = FOUR_CHAR_CODE('thng'),
    kALMComponentType = FOUR_CHAR_CODE('walk')
  };

  /* CFM Modules require a bit of information (replacing some of the 'thng'
   * resource)... */

  enum
  {
    kALMModuleInfoRsrcType = FOUR_CHAR_CODE('walk'),
    kALMModuleInfoOriginalVersion = 0
  };

  // These masks apply to the "Flags" field in the 'thng' or 'walk' resource... 
  enum
  {
    kALMMultiplePerLocation =
        0x00000001, // Module can be added more than once to a Location...     kALMDescriptionGetsStale =
        0x00000002 // Descriptio// Creator of Location Manager files... 

  /* Misc stuff f// Type of a Component Manager Module file [v1.0]... 
   * ------------------------------------------------------------ */
// Type of a CM 'state' Module file... 
#if OLDROUTINENAMES
  // Old error codes for compati// Type of a CM 'action' Module file... 
  {
    ALMInternalErr = -30049,    // Type of a CFM 'state' Module file... 

  // Old ALMConfirmName constan// Type of a CFM 'action' Module file... 
  enum
  {
  // Component Manager 'thng' info... 
    ALMConfirmReplaceConfig = kALMConfirmReplace
  };

  // Old AppleEvents... 
  enum
  {
    kAELocationNotice = kAELocationChangedNoticeKey
  };

  typedef ALMScriptManagerInfo ALMScriptMgrInfo;
  typedef UInt32 ALMComponentFlagsEnum;
#endif // OLDROUTINENAMES 
  /* Location Manager API
   * ----------------------------------------------------------------------------
   */

  // These masks apply to the "Flags" field in the 'thng' or 'walk' resource... 
   * gestaltALMPresent set... */

#if CALL_NOT_IN_CARBON
  /**
   *  ALMGetCurrentL// Module can be added more than once to a Location... 
   *
// Descriptions may change though the setting didn't...  
   *    \non_carbon_cfm   in Walkabout 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ALMGetCurrentLocation(SInt16 *index, ALMToken *token, ALMLocationName name)
  // Old error codes for compatibility - new names are in Errors interface... 

  /**
   *  ALMGetIndLocation()// use kALMInternalErr 
   *// use kALMLocationNotFoundErr 
// use kALMNoSuchModuleErr 
   *    \non_carbon_cfm   in Walkabout 1// use kALMModuleCommunicationErr 
   *    \carbon_lib        not available// use kALMDuplicateModuleErr 
   *    \mac_os_x         not available// use kALMInstallationErr 
   */// use kALMDeferSwitchErr 
  OSErr
  ALMGetIndLocation(SInt16 index, ALMToken *token, ALMLocationName name)
  // Old ALMConfirmName constants... 

  /**
   *  ALMCountLocations()
   *

   *    \non_carbon_cfm   in Walkabout 1.0 and later
   *    \carbon_lib        not available
  // Old AppleEvents... 
   */
  OSErr
  ALMCountLocations(SInt16 *locationCount)
      THREEWORDINLINE(0x303C, 0x0202, 0xAAA4);

  /**
   *  ALMSwitchToLocation()
   *
// OLDROUTINENAMES 
   *    \non_carbon_cfm   in Walkabout 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ALMSwitchToLocation(ALMToken newLocation, ALMSwitchActionFlags switchFlags)
      THREEWORDINLINE(0x303C, 0x0403, 0xAAA4);

  /**
   *  ALMRegisterNotifyProc()
   *

   *    \non_carbon_cfm   in Walkabout 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ALMRegisterNotifyProc(ALMNotificationUPP notificationProc,
                        const ProcessSerialNumber *whichPSN)
      THREEWORDINLINE(0x303C, 0x0404, 0xAAA4);

  /**
   *  ALMRemoveNotifyProc()
   *

   *    \non_carbon_cfm   in Walkabout 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ALMRemoveNotifyProc(ALMNotificationUPP notificationProc,
                      const ProcessSerialNumber *whichPSN)
      THREEWORDINLINE(0x303C, 0x0405, 0xAAA4);

  /**
   *  ALMConfirmName()
   *

   *    \non_carbon_cfm   in Walkabout 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ALMConfirmName(ConstStr255Param message, Str255 theName,
                 ALMConfirmChoice *choice, ModalFilterUPP filter)
      THREEWORDINLINE(0x303C, 0x0806, 0xAAA4);

  /* The following 3 routines are present if gestaltALMAttr has bit
   * gestaltALMHasSFLocation set... */

  /**
   *  ALMPutLocation()
   *

   *    \non_carbon_cfm   in Walkabout 2.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ALMPutLocation(ConstStr255Param prompt, ALMLocationName name, SInt16 numTypes,
                 ConstALMModuleTypeListPtr typeList, ModalFilterYDUPP filter,
                 void *yourDataPtr) THREEWORDINLINE(0x303C, 0x0B07, 0xAAA4);

  /**
   *  ALMGetLocation()
   *

   *    \non_carbon_cfm   in Walkabout 2.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ALMGetLocation(ConstStr255Param prompt, ALMLocationName name,
                 ModalFilterYDUPP filter, void *yourDataPtr)
      THREEWORDINLINE(0x303C, 0x0808, 0xAAA4);

  /**
   *  ALMMergeLocation()
   *

   *    \non_carbon_cfm   in Walkabout 2.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ALMMergeLocation(ConstStr255Param prompt, ALMLocationName name, SInt16 numTypes,
                   ConstALMModuleTypeListPtr typeList, ModalFilterYDUPP filter,
                   void *yourDataPtr) THREEWORDINLINE(0x303C, 0x0B09, 0xAAA4);

#endif // CALL_NOT_IN_CARBON 
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

#endif // __LOCATIONMANAGER__ // CALL_NOT_IN_CARBON 
// __LOCATIONMANAGER__ 
