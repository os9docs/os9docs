/**
     \file       Processes.h

    \brief   Process Manager Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1989-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __PROCESSES__
#define __PROCESSES__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __TEXTCOMMON__
#include <TextCommon.h>
#endif

#ifndef __CFSTRING__
#include <CFString.h>
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

  // type for unique process identifier   /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct ProcessSerialNumber
  {
    unsigned long highLongOfPSN; /**< */
    unsigned long lowLongOfPSN;  /**< */
  } ProcessSerialNumber;         /**< */

  typedef struct ProcessSerialNumber ProcessSerialNumber;
  typedef ProcessSerialNumber *ProcessSerialNumberPtr;
  enum
  {
    // Process identifier - Various reserved process serial numbers     kNoProcess = 0,
    // Process identifier - Various reserved process serial numbers 
    kCurrentProcess = 2
  };

  // Definition of the parameter block passed to _Launch   // Typedef and flags for launchControlFlags field  typedef unsigned short LaunchFlags;
  enum
  // Definition of the parameter block passed to _Launch 
  // Typedef and flags for launchControlFlags field
    launchNoFileFlags = 0x0800,
    launchUseMinimum = 0x0400,
    launchDontSwitch = 0x0200,
    launchAllow24Bit = 0x0100,
    launchInhibitDaemon = 0x0080
  };

  /* Format for first AppleEvent to pass to new process.  The size of the overall
    buffer variable: the message body immediately follows the messageLength */
  struct AppParameters
  {
    EventRecord theMsgEvent;
    unsigned long eventRefCon;
    unsigned long messageLength;
  };
  typedef struct AppParameters AppParameters;
  typedef AppParameters *AppParametersPtr;
  // Parameter block to _Launch   struct LaunchParamBlockRec
  {
    unsigned long reserved1;
    unsigned short reserved2;
  // Parameter block to _Launch 
    unsigned long launchEPBLength;
    unsigned short launchFileFlags;
    LaunchFlags launchControlFlags;
    FSSpecPtr launchAppSpec;
    ProcessSerialNumber launchProcessSN;
    unsigned long launchPreferredSize;
    unsigned long launchMinimumSize;
    unsigned long launchAvailableSize;
    AppParametersPtr launchAppParameters;
  };
  typedef struct LaunchParamBlockRec LaunchParamBlockRec;
  typedef LaunchParamBlockRec *LaunchPBPtr;
  /* Set launchBlockID to extendedBlock to specify that extensions exist.
   Set launchEPBLength to extendedBlockLen for compatibility.*/
  enum
  {
    extendedBlock = 0x4C43, // 'LC'     extendedBlockLen = sizeof(LaunchParamBlockRec) - 12
  };

  enum
  {
    // Definition of the inf// 'LC' 
    modeControlPanel = 0x00080000,
    modeLaunchDontSwitch = 0x00040000,
    modeDeskAccessory = 0x00020000,
    modeMultiLaunch = 0x00010000,
    modeNeedSuspendResume = 0x00004000,
    // Definition of the information block returned by GetProcessInformation 
    modeDoesActivateOnFGSwitch = 0x00000800,
    modeOnlyBackground = 0x00000400,
    modeGetFrontClicks = 0x00000200,
    modeGetAppDiedMsg = 0x00000100,
    mode32BitCompatible = 0x00000080,
    modeHighLevelEventAware = 0x00000040,
    modeLocalAndRemoteHLEvents = 0x00000020,
    modeStationeryAware = 0x00000010,
    modeUseTextEditServices = 0x00000008,
    modeDisplayManagerAware = 0x00000004
  };

  /**
     Record returned by GetProcessInformation
      When calling GetProcessInformation(), the input ProcesInfoRec
      should have the processInfoLength set to sizeof(ProcessInfoRec),
      the processName field set to nil or a pointer to a Str255, and
      processAppSpec set to nil or a pointer to an FSSpec.  If
      processName or processAppSpec are not specified, this routine
      will very likely write data to whatever random location in memory
      these happen to point to, which is not a good thing.
  */
  /**
  <pre>
   * \note <pre>You specify the values for three fields of the process information record:
  processInfoLength , processName and processAppSpec . You must either set
  the processName and processAppSpec fields to NIL or set these fields to
  point to storage that you have allocated for them. The
  GetProcessInformation function returns information in all other fields
  of the process information record.
  The processInfoLength field is the number of bytes in the process
  information record. For compatibility, you should specify the length of the
  record in this field. The name returned in the processName field is the name
  of the application or desk accessory. For applications, this field contains the
  name of the application as designated by the user at the time the application
  was opened. For example, for foreground applications, the processName field
  is the name as it appears in the Application menu. For desk accessories, the
  processName field contains the name of the 'DRVR' resource. You must
  specify NIL in the processName field if you do not want the application name
  or the desk accessory name returned. Otherwise, you should allocate at least
  32 bytes of storage for the string pointed to by the processName field. Note
  that the processName field specifies the name of either the application or
  the 'DRVR' resource, whereas the processAppSpec field specifies the
  location of the file.
  The processNumber field specifies the process serial number. The process
  serial number is a 64-bit number; the meaning of these bits is internal to
  the Process Manager . You should not interpret the value of the process
  serial number.
  The processType field indicates the file type of the application, generally
  'APPL' for applications, and 'appe' for background-only applications
  launched at startup. If the process is a desk accessory, the processType field
  is the type of the file containing the 'DRVR' resource.
  The processSignature field indicates the signature of the file containing the
  application or the 'DRVR' resource (for example, the signature of the
  TeachText application is 'ttxt').
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct ProcessInfoRec
  {
    unsigned long processInfoLength;     /**< length of record*/
    StringPtr processName;               /**< name of process*/
    ProcessSerialNumber processNumber;   /**< psn of the process*/
    unsigned long processType;           /**< file type of app file*/
    OSType processSignature;             /**< signature of app file*/
    unsigned long processMode;           /**< 'SIZE' resource flags*/
    Ptr processLocation;                 /**< address of partition*/
    unsigned long processSize;           /**< partition size*/
    unsigned long processFreeMem;        /**< free bytes in heap*/
    ProcessSerialNumber processLauncher; /**<  process that launched*/
    unsigned long processLaunchDate;     /**< time when launched*/
    unsigned long processActiveTime;     /**< accumulated CPU time*/
    FSSpecPtr processAppSpec;            /**< location of the file*/
  } ProcessInfoRec;                      /**< */

  typedef struct ProcessInfoRec ProcessInfoRec;
  typedef ProcessInfoRec *ProcessInfoRecPtr;
  /**
      Some applications assumed the size of a ProcessInfoRec would never change,
      which has caused problems trying to return additional information.  In
      the future, we will add fields to ProcessInfoExtendedRec when necessary,
      and callers which wish to access 'more' data than originally was present
      in ProcessInfoRec should allocate space for a ProcessInfoExtendedRec,
      fill in the processInfoLength ( and processName and processAppSpec ptrs ),
      then coerce this to a ProcessInfoRecPtr in the call to
      GetProcessInformation().
  */
  struct ProcessInfoExtendedRec
  {
    unsigned long processInfoLength;
    StringPtr processName;
    ProcessSerialNumber processNumber;
    unsigned long processType;
    OSType processSignature;
    unsigned long processMode;
    Ptr processLocation;
    unsigned long processSize;
    unsigned long processFreeMem;
    ProcessSerialNumber processLauncher;
    unsigned long processLaunchDate;
    unsigned long processActiveTime;
    FSSpecPtr processAppSpec;
    unsigned long processTempMemTotal;
    unsigned long processPurgeableTempMemTotal;
  };
  typedef struct ProcessInfoExtendedRec ProcessInfoExtendedRec;
  typedef ProcessInfoExtendedRec *ProcessInfoExtendedRecPtr;
  // Record corresponding to the SIZE resource definition   struct SizeResourceRec
  {
    unsigned short flags;
    unsigned long preferredHeapSize;
    unsigned long minimumHeapSize;
  };
  typedef struct SizeResourceRec SizeResourceRec;
  // Record corresponding to the SIZE resource definition 
  typedef SizeResourceRecPtr *SizeResourceRecHandle;
  /**
      Applications and background applications can control when they are asked to
     quit by the system at restart/shutdown by setting these bits in a 'quit' ( 0
     ) resource in their application's resource fork.  Applications without a
     'quit' ( 0 ) will be quit at kQuitAtNormalTime mask.
  */
  enum
  {
    kQuitBeforeNormalTimeMask = 1,
    kQuitAtNormalTimeMask = 2,
    kQuitBeforeFBAsQuitMask = 4,
    kQuitBeforeShellQuitsMask = 8,
    kQuitBeforeTerminatorAppQuitsMask = 16,
    kQuitNeverMask = 32,
    kQuitOptionsMask = 0x7F,
    kQuitNotQuitDuringInstallMask = 0x0100,
    kQuitNotQuitDuringLogoutMask = 0x0200
  };

/**
 *  LaunchApplication()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 LaunchApplication(__A0)
#endif
  OSErr
  LaunchApplication(LaunchPBPtr LaunchParams) ONEWORDINLINE(0xA9F2);

#if CALL_NOT_IN_CARBON
  /**
   *  LaunchDeskAccessory()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  LaunchDeskAccessory(const FSSpec *pFileSpec, ConstStr255Param pDAName)
      THREEWORDINLINE(0x3F3C, 0x0036, 0xA88F);

#endif // CALL_NOT_IN_CARBON 
/**
 *  [Mac]GetCurrentProcess()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */// CALL_NOT_IN_CARBON 
#if TARGET_OS_MAC
#define MacGetCurrentProcess GetCurrentProcess
#endif
  OSErr
  MacGetCurrentProcess(ProcessSerialNumber *PSN)
      THREEWORDINLINE(0x3F3C, 0x0037, 0xA88F);

  /**
  \brief Get serial number of foreground process

  <pre>If no process is running in the foreground, GetFrontProcess returns the
result code procNotFound.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  GetFrontProcess(ProcessSerialNumber *PSN)
      FIVEWORDINLINE(0x70FF, 0x2F00, 0x3F3C, 0x0039, 0xA88F);

  /**
  \brief Get the process serial number of the next process

  <pre>You use the GetNextProcess to get the process serial number of the next
process
PSN is a pointer to a valid process serial number returned from
LaunchApplication , GetNextProcess , GetFrontProcess , or
GetCurrentProcess , or the defined constant kNoProcess.
Returns: an operating system Error Code .
noErr(0)No error
paramErr (-50)Process serial number is invalid
procNotFound (-600)No process in the process list following the specified
process
</pre>
* \note <pre>You can use the returned process serial number from this function in
other Process Manager routines. You can also use this process serial
number to specify a target application when your application sends a
high-level event.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  GetNextProcess(ProcessSerialNumber *PSN)
      THREEWORDINLINE(0x3F3C, 0x0038, 0xA88F);

  /**
   *  GetProcessInformation()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetProcessInformation(const ProcessSerialNumber *PSN, ProcessInfoRec *info)
      THREEWORDINLINE(0x3F3C, 0x003A, 0xA88F);

  /**
  \brief Make a process the foreground process

  <pre>You use the SetFrontProcess to schedule the specified process to become
the foreground process.
PSN is a pointer to a the process serial number of the process running in
the foreground
Returns: an operating system Error Code .
noErr(0)No error
procNotFound (-600)Process with specified process serial number does not
exist or process is suspended by high-level debugger
appIsDaemon (-606)Specified process is background-only
</pre>
* \note <pre>The specified process becomes the foreground process after the current
foreground process makes a subsequent call to WaitNextEvent or
EventAvail .
The process serial number in the PSN parameter should be a valid process
serial number returned from LaunchApplication , GetNextProcess ,
SetFrontProcess , GetCurrentProcess , or a high-level event. You
can also use the constant kCurrentProcess to refer to the current process.
If the specified process serial number is invalid or if the specified process
is a background-only application, SetFrontProcess returns a nonzero
result code and does not change the current foreground process.
If a modal dialog box is the frontmost window, the specified process does
not become the foreground process until after the user dismisses the modal
dialog box.
Note: Do not call SetFrontProcess from a routine that executes
at interrupt time.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  SetFrontProcess(const ProcessSerialNumber *PSN)
      THREEWORDINLINE(0x3F3C, 0x003B, 0xA88F);

  /**
  \brief Make a process eligible to receive CPU time

  <pre>You use the WakeUpProcess to makes a process suspended by
WaitNextEvent eligible to receive CPU time.
PSN is a pointer to the process serial number of the process designated to
receive CPU time.
Returns: an operating system Error Code .
noErr(0)No error
procNotFound (-600)Suspended process with specified process serial
number does not exist
</pre>
* \note <pre>When a process specifies a nonzero value for the sleep parameter in the
WaitNextEvent function, and there are no events for that process
pending in the event queue, the process is suspended. This process remains
suspended until the time specified in the sleep parameter expires or an
event becomes available for that process. You can use WakeUpProcess to
make the process eligible for execution before the time specified in the sleep
parameter expires.
The WakeUpProcess function does not change the order of the processes
scheduled for execution; it only makes the specified process eligible for
execution.
The process serial number specified in the PSN parameter should be a
valid process serial number returned from LaunchApplication ,
GetNextProcess , GetFrontProcess , GetCurrentProcess , or a
high-level event.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  WakeUpProcess(const ProcessSerialNumber *PSN)
      THREEWORDINLINE(0x3F3C, 0x003C, 0xA88F);

  /**
  \brief Compare two process serial numbers

  <pre>You use SameProcess to compare two process serial numbers and to
determine whether they refer to the same process.
PSN1 is a pointer to a valid process serial number returned from
LaunchApplication , GetNextProcess , GetFrontProcess , or
GetCurrentProcess , or a high level event. You can also use the
constant kCurrentProcess to return to the current process.
PSN2 is a valid process serial number returned from
LaunchApplication , GetNextProcess , GetFrontProcess , or
GetCurrentProcess , or a high level event. You can also use the
constant kCurrentProcess to return to the current process.
result is a pointer to a Boolean value. If the process serial numbers
specified in the PSN1 and PSN2 parameters refer to the same
process, the SameProcess function returns TRUE in the result
parameter; otherwise, it returns FALSE in the result parameter.
Returns: an operating system Error Code .
noErr(0)No error
paramErr (-50)Process serial number is invalid
</pre>
* \note <pre>When you compare two process serial numbers, use the SameProcess
function rather than any other means, because the interpretation of the bits
in a process serial number is internal to the Process Manager .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  SameProcess(const ProcessSerialNumber *PSN1, const ProcessSerialNumber *PSN2,
              Boolean *result) THREEWORDINLINE(0x3F3C, 0x003D, 0xA88F);

  //  ExitToShell was previously in SegLoad.h  /**
   *  ExitToShell()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  //  ExitToShell was previously in SegLoad.h

/**
   LaunchControlPanel is similar to LaunchDeskAccessory, but for Control Panel
   files instead. It launches a control panel in an application shell maintained
   by the Process Manager.
*/
#if CALL_NOT_IN_CARBON
  /**
   *  LaunchControlPanel()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  LaunchControlPanel(const FSSpec *pFileSpec)
      THREEWORDINLINE(0x3F3C, 0x007B, 0xA88F);

#endif // CALL_NOT_IN_CARBON 
  /**
   *  GetApplicationTextEncoding()
   *
   *  Summary:
   *    Returns the application text encoding for Resource Manager
   *    resources.
   *
   *  Discussion:
   *    The application text encoding is used when you create a
   *   // CALL_NOT_IN_CARBON 
   *    typically uses one of the Mac encodings such as MacRoman or
   *    MacJapanese.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TextEncoding
  GetApplicationTextEncoding(void);

  /**
   *  GetApplicationScript()
   *
   *  Summary:
   *    Returns the application script.
   *
   *  Discussion:
   *    The application script is used when you need a ScriptCode to pass
   *    to some other API, such as UseThemeFont.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ScriptCode
  GetApplicationScript(void);

  /**
   *  GetProcessBundleLocation()
   *
   *  Summary:
   *    Retrieve the filesystem location of the process bundle, or
   *    executable if unbundled.
   *
   *  Discussion:
   *    Retrieves a reference to the filesystem location of the specified
   *    application.  For an application that is packaged as an app
   *    bundle, this will be the app bundle directory; otherwise it will
   *    be the location of the executable itself.
   *
   *  Parameters:
   *
   *    psn:
   *      Serial number of the target process
   *
   *    location:
   *      Location of the bundle or executable, as an FSRef
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  GetProcessBundleLocation(const ProcessSerialNumber *psn, FSRef *location);

  /**
   *  CopyProcessName()
   *
   *  Summary:
   *    Get a copy of the name of a process.
   *
   *  Discussion:
   *    Use this call to get the name of a process as a CFString.  The
   *    name returned is a copy, so the caller must CFRelease the name
   *    when finished with it.  The difference between this call and the
   *    processName field filled in by GetProcessInformation is that the
   *    name here is a CFString, and thus is capable of representing a
   *    multi-lingual name, whereas previously only a mac-encoded string
   *    was possible.
   *
   *  Parameters:
   *
   *    psn:
   *      Serial number of the target process
   *
   *    name:
   *      CFString representing the name of the process (must be released
   *      by caller with CFRelease)
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  CopyProcessName(const ProcessSerialNumber *psn, CFStringRef *name);

  /*************************************************************************
   *  Process Visibility.
   *************************************************************************/
  /**
   *  IsProcessVisible()
   *
   *  Summary:
   *    Determines whether a particular process is visible or not.
   *
   *  Discussion:
   *    Given a psn, this call will return true or false depending on
   *    whether or not the process is currently visible.
   *
   *  Parameters:
   *
   *    psn:
   *      Serial number of the process
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  Boolean
  IsProcessVisible(const ProcessSerialNumber *psn)
      THREEWORDINLINE(0x3F3C, 0x005F, 0xA88F);

  /**
   *  ShowHideProcess()
   *
   *  Summary:
   *    Hides or shows a given process.
   *
   *  Discussion:
   *    Given a psn, this call will hide or show the process specified in
   *    the psn parameter. You determine whether you would like to show
   *    or hide the process with the visible parameter. True passed into
   *    visible indicates you wish for the process to become visible.
   *
   *  Parameters:
   *
   *    psn:
   *      Serial number of the process
   *
   *    visible:
   *      true = show process; false = hide process
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSErr
  ShowHideProcess(const ProcessSerialNumber *psn, Boolean visible)
      THREEWORDINLINE(0x3F3C, 0x0060, 0xA88F);

  // Values of the 'message' parameter to a Control Panel 'cdev'   enum
  {
    initDev = 0,    /*Time for cdev to initialize itself*/
    hitDev = 1,     /*Hit on one of my items*/
    closeDev = 2,   /*Close yourself*/
    nulDev = 3,     /*Null event*/
    updateDev = 4,  /*Update event*/
    activDev = 5,   /*Activate event*/
    deactivDev = 6, /*Deactivate event*/
    keyEvtDev = 7,  /*Key down/auto key*/
    macDev = 8,     /*Decide whether or not to show up*/
  // Values of the 'message' parameter to a Control Panel 'cdev' 
    cutDev = 10,
    copyDev = 11,
    pasteDev = 12,
    clearDev = 13,
    cursorDev = 14
  };

  // Special values a Control Panel 'cdev' can return   enum
  {
    cdevGenErr = -1, /*General error; gray cdev w/o alert*/
    cdevMemErr = 0,  /*Memory shortfall; alert user please*/
    cdevResErr = 1,  /*Couldn't get a needed resource; alert*/
    cdevUnset = 3    // cdevValue is initialized to this  };

  // Control Panel Default Proc   typedef CALLBACK_API(long, ControlPanelDefProcPtr)(
      short message, short item, short numItems, short cPanelID,
      EventRecord *theEvent, long cdevValue, DialogPtr cpDialog);
  typedef STACK_UPP_TYPE(ControlPanelDefProcPtr) ControlPanelDefUPP;
#if CALL_NOT_IN_CARBON
  // Special values a Control Panel 'cdev' can return 
   *  NewControlPanelDefUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x    // cdevValue is initialized to this
   */
  ControlPanelDefUPP
  // Control Panel Default Proc 
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppControlPanelDefProcInfo = 0x000FEAB0
  }; /* pascal 4_bytes Func(2_bytes, 2_bytes, 2_bytes, 2_bytes, 4_bytes, 4_bytes,
        4_bytes) */
#ifdef __cplusplus
  inline ControlPanelDefUPP
  NewControlPanelDefUPP(ControlPanelDefProcPtr userRoutine)
  {
    return (ControlPanelDefUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    uppControlPanelDefProcInfo,
                                                    GetCurrentArchitecture());
  }
#else
#define NewControlPanelDefUPP(userRoutine)                                     \
  (ControlPanelDefUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppControlPanelDefProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeControlPanelDefUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeControlPanelDefUPP(ControlPanelDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeControlPanelDefUPP(ControlPanelDefUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeControlPanelDefUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeControlPanelDefUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long
  InvokeControlPanelDefUPP(short message, short item, short numItems,
                           short cPanelID, EventRecord *theEvent, long cdevValue,
                           DialogPtr cpDialog, ControlPanelDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline long InvokeControlPanelDefUPP(short message, short item, short numItems,
                                       short cPanelID, EventRecord *theEvent,
                                       long cdevValue, DialogPtr cpDialog,
                                       ControlPanelDefUPP userUPP)
  {
    return (long)CALL_SEVEN_PARAMETER_UPP(userUPP, uppControlPanelDefProcInfo,
                                          message, item, numItems, cPanelID,
                                          theEvent, cdevValue, cpDialog);
  }
#else
#define InvokeControlPanelDefUPP(message, item, numItems, cPanelID, theEvent, \
                                 cdevValue, cpDialog, userUPP)                \
  (long)CALL_SEVEN_PARAMETER_UPP((userUPP), uppControlPanelDefProcInfo,       \
                                 (message), (item), (numItems), (cPanelID),   \
                                 (theEvent), (cdevValue), (cpDialog))
#endif
#endif

#endif // CALL_NOT_IN_CARBON 
#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewControlPanelDefProc(userRoutine) NewControlPanelDefUPP(userRoutine)
#define CallControlPanelDefProc(userRoutine, message, item, numItems,    \
                                cPanelID, theEvent, cdevValue, cpDialog) \
  InvokeControlPanelDefUPP(message, item, numItems, cPanelID, theEvent,  \
                           cdevValue, cpDialog, userRoutine)
#endif // CALL_NOT_IN_CARBON 
#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack()
#endif
// CALL_NOT_IN_CARBON 
#ifdef PRAGMA_IMPORT_OFF
#pragma import off
// support for pre-Carbon UPP routines: New...Proc and Call...Proc 
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif// CALL_NOT_IN_CARBON 

#endif // __PROCESSES__ * /*/*/ */*/// __PROCESSES__ 
