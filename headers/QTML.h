/**
     \file       QTML.h

    \brief   QuickTime Cross-platform specific interfaces

    \introduced_in  QuickTime 5.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1997-2001 by Apple Computer, Inc., all rights reserved.

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QTML__
#define __QTML__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MACMEMORY__
#include <MacMemory.h>
#endif

#ifndef __MACWINDOWS__
#include <MacWindows.h>
#endif

#ifndef __OSUTILS__
#include <OSUtils.h>
#endif

#ifndef __FILES__
#include <Files.h>
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

#if CALL_NOT_IN_CARBON
/**
 *  QTMLYieldCPU()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLYieldCPU(void);

/**
 *  QTMLYieldCPUTime()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLYieldCPUTime(long milliSeconds, unsigned long flags);

#endif /* CALL_NOT_IN_CARBON */

typedef struct OpaqueQTMLMutex *QTMLMutex;
#if !(TARGET_OS_MAC && TARGET_API_MAC_OS8)
typedef struct OpaqueQTMLSyncVar *QTMLSyncVar;
typedef QTMLSyncVar *QTMLSyncVarPtr;
enum {
  kInitializeQTMLNoSoundFlag =
      (1L << 0), /* flag for requesting no sound when calling InitializeQTML*/
  kInitializeQTMLUseGDIFlag =
      (1L << 1), /* flag for requesting GDI when calling InitializeQTML*/
  kInitializeQTMLDisableDirectSound =
      (1L << 2), /* disables QTML's use of DirectSound*/
  kInitializeQTMLUseExclusiveFullScreenModeFlag =
      (1L << 3), /* later than QTML 3.0: qtml starts up in exclusive full screen
                    mode*/
  kInitializeQTMLDisableDDClippers =
      (1L << 4) /* flag for requesting QTML not to use DirectDraw clipper
                   objects; QTML 5.0 and later*/
};

enum {
  kQTMLHandlePortEvents =
      (1L << 0), /* flag for requesting requesting QTML to handle events*/
  kQTMLNoIdleEvents =
      (1L << 1) /* flag for requesting requesting QTML not to send Idle Events*/
};

#if CALL_NOT_IN_CARBON
/**
 *  InitializeQTML()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(OSErr)
InitializeQTML(long flag);

/**
 *  TerminateQTML()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
TerminateQTML(void);

/**
 *  CreatePortAssociation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(GrafPtr)
CreatePortAssociation(void *theWnd, Ptr storage, long flags);

/**
 *  DestroyPortAssociation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
DestroyPortAssociation(CGrafPtr cgp);

/**
 *  QTMLGrabMutex()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLGrabMutex(QTMLMutex mu);

/**
 *  QTMLTryGrabMutex()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
EXTERN_API(Boolean)
QTMLTryGrabMutex(QTMLMutex mu);

/**
 *  QTMLReturnMutex()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLReturnMutex(QTMLMutex mu);

/**
 *  QTMLCreateMutex()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(QTMLMutex)
QTMLCreateMutex(void);

/**
 *  QTMLDestroyMutex()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLDestroyMutex(QTMLMutex mu);

/**
 *  QTMLCreateSyncVar()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(QTMLSyncVarPtr)
QTMLCreateSyncVar(void);

/**
 *  QTMLDestroySyncVar()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLDestroySyncVar(QTMLSyncVarPtr p);

/**
 *  QTMLTestAndSetSyncVar()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(long)
QTMLTestAndSetSyncVar(QTMLSyncVarPtr sync);

/**
 *  QTMLWaitAndSetSyncVar()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLWaitAndSetSyncVar(QTMLSyncVarPtr sync);

/**
 *  QTMLResetSyncVar()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLResetSyncVar(QTMLSyncVarPtr sync);

/**
 *  InitializeQHdr()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
InitializeQHdr(QHdr *qhdr);

/**
 *  TerminateQHdr()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
TerminateQHdr(QHdr *qhdr);

/**
 *  QTMLAcquireWindowList()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLAcquireWindowList(void);

/**
 *  QTMLReleaseWindowList()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLReleaseWindowList(void);

/**
   These routines are here to support "interrupt level" code
      These are dangerous routines, only use if you know what you are doing.
*/

/**
 *  QTMLRegisterInterruptSafeThread()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(long)
QTMLRegisterInterruptSafeThread(unsigned long threadID, void *threadInfo);

/**
 *  QTMLUnregisterInterruptSafeThread()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(long)
QTMLUnregisterInterruptSafeThread(unsigned long threadID);

/**
 *  NativeEventToMacEvent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(long)
NativeEventToMacEvent(void *nativeEvent, EventRecord *macEvent);

#endif /* CALL_NOT_IN_CARBON */

#if TARGET_OS_WIN32
#if CALL_NOT_IN_CARBON
/**
 *  WinEventToMacEvent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(long)
WinEventToMacEvent(void *winMsg, EventRecord *macEvent);

#define WinEventToMacEvent NativeEventToMacEvent
/**
 *  IsTaskBarVisible()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(Boolean)
IsTaskBarVisible(void);

/**
 *  ShowHideTaskBar()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
ShowHideTaskBar(Boolean showIt);

#endif /* CALL_NOT_IN_CARBON */

enum { kDDSurfaceLocked = (1L << 0), kDDSurfaceStatic = (1L << 1) };

#if CALL_NOT_IN_CARBON
/**
 *  QTGetDDObject()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(OSErr)
QTGetDDObject(void **lpDDObject);

/**
 *  QTSetDDObject()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(OSErr)
QTSetDDObject(void *lpNewDDObject);

/**
 *  QTSetDDPrimarySurface()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(OSErr)
QTSetDDPrimarySurface(void *lpNewDDSurface, unsigned long flags);

/**
 *  QTMLGetVolumeRootPath()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(OSErr)
QTMLGetVolumeRootPath(char *fullPath, char *volumeRootPath,
                      unsigned long volumeRootLen);

/**
 *  QTMLSetWindowWndProc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void)
QTMLSetWindowWndProc(WindowRef theWindow, void *windowProc);

/**
 *  QTMLGetWindowWndProc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(void *)
QTMLGetWindowWndProc(WindowRef theWindow);

#endif /* CALL_NOT_IN_CARBON */

#endif /* TARGET_OS_WIN32 */

#if CALL_NOT_IN_CARBON
/**
 *  QTMLGetCanonicalPathName()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(OSErr)
QTMLGetCanonicalPathName(char *inName, char *outName, unsigned long outLen);

#endif /* CALL_NOT_IN_CARBON */

enum {
  kFullNativePath = 0,
  kFileNameOnly = (1 << 0),
  kDirectoryPathOnly = (1 << 1),
  kUFSFullPathName = (1 << 2),
  kTryVDIMask = (1 << 3), /*    Used in NativePathNameToFSSpec to specify to
                             search VDI mountpoints*/
  kFullPathSpecifiedMask =
      (1 << 4) /*    the passed in name is a fully qualified full path*/
};

#if CALL_NOT_IN_CARBON
/**
 *  FSSpecToNativePathName()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(OSErr)
FSSpecToNativePathName(const FSSpec *inFile, char *outName,
                       unsigned long outLen, long flags);

#endif /* CALL_NOT_IN_CARBON */

enum { kErrorIfFileNotFound = 1L << 31 };

#if CALL_NOT_IN_CARBON
/**
 *  NativePathNameToFSSpec()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API(OSErr)
NativePathNameToFSSpec(char *inName, FSSpec *outFile, long flags);

/**
 *  QTGetAliasInfo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
EXTERN_API(OSErr)
QTGetAliasInfo(AliasHandle alias, AliasInfoType index, char *outBuf,
               long bufLen, long *outLen, unsigned long flags);

#endif /* CALL_NOT_IN_CARBON */

#endif /* !(TARGET_OS_MAC && TARGET_API_MAC_OS8) */

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

#endif /* __QTML__ */
