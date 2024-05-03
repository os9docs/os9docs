/**
    \file       Connections.h

    \brief   Communications Toolbox Connection Manager Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1988-2001 by Apple Computer, Inc., all rights reserved

    \ingroup CommunicationsToolbox
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CONNECTIONS__
#define __CONNECTIONS__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
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
enum {
  curCMVersion = 2 /* current Connection Manager version*/
};

enum {
  curConnEnvRecVers =
      0 /*    current Connection Manager Environment Record version*/
};

enum {
  /* CMErr */
  cmGenericError = -1,
  cmNoErr = 0,
  cmRejected = 1,
  cmFailed = 2,
  cmTimeOut = 3,
  cmNotOpen = 4,
  cmNotClosed = 5,
  cmNoRequestPending = 6,
  cmNotSupported = 7,
  cmNoTools = 8,
  cmUserCancel = 9,
  cmUnknownError = 11
};

typedef OSErr CMErr;

enum {
  cmData = 1L << 0,
  cmCntl = 1L << 1,
  cmAttn = 1L << 2,
  cmDataNoTimeout = 1L << 4,
  cmCntlNoTimeout = 1L << 5,
  cmAttnNoTimeout = 1L << 6,
  cmDataClean = 1L << 8,
  cmCntlClean = 1L << 9,
  cmAttnClean = 1L << 10, /*       Only for CMRecFlags (not CMChannel) in the
                             rest of this enum  */
  cmNoMenus = 1L << 16,
  cmQuiet = 1L << 17,
  cmConfigChanged = 1L << 18
};

/* CMRecFlags and CMChannel     */
/*      Low word of CMRecFlags is same as CMChannel */
typedef long CMRecFlags;
typedef short CMChannel;

enum {
  cmStatusOpening = 1L << 0,
  cmStatusOpen = 1L << 1,
  cmStatusClosing = 1L << 2,
  cmStatusDataAvail = 1L << 3,
  cmStatusCntlAvail = 1L << 4,
  cmStatusAttnAvail = 1L << 5,
  cmStatusDRPend = 1L << 6,  /* data read pending  */
  cmStatusDWPend = 1L << 7,  /* data write pending */
  cmStatusCRPend = 1L << 8,  /* cntl read pending  */
  cmStatusCWPend = 1L << 9,  /* cntl write pending */
  cmStatusARPend = 1L << 10, /* attn read pending  */
  cmStatusAWPend = 1L << 11, /* attn write pending */
  cmStatusBreakPend = 1L << 12,
  cmStatusListenPend = 1L << 13,
  cmStatusIncomingCallPresent = 1L << 14,
  cmStatusReserved0 = 1L << 15
};

typedef unsigned long CMStatFlags;
enum {
  cmDataIn = 0,
  cmDataOut = 1,
  cmCntlIn = 2,
  cmCntlOut = 3,
  cmAttnIn = 4,
  cmAttnOut = 5,
  cmRsrvIn = 6,
  cmRsrvOut = 7
};

typedef unsigned short CMBufFields;
typedef Ptr CMBuffers[8];
typedef long CMBufferSizes[8];
typedef const long *ConstCMBufferSizesParam;
enum { cmSearchSevenBit = 1L << 0 };

typedef unsigned short CMSearchFlags;
enum { cmFlagsEOM = 1L << 0 };

typedef unsigned short CMFlags;
struct ConnEnvironRec {
  short version;
  long baudRate;
  short dataBits;
  CMChannel channels;
  Boolean swFlowControl;
  Boolean hwFlowControl;
  CMFlags flags;
};
typedef struct ConnEnvironRec ConnEnvironRec;
typedef ConnEnvironRec *ConnEnvironRecPtr;
typedef struct ConnRecord ConnRecord;
typedef ConnRecord *ConnPtr;
typedef ConnPtr *ConnHandle;
typedef CALLBACK_API(long, ConnectionToolDefProcPtr)(ConnHandle hConn,
                                                     short msg, long p1,
                                                     long p2, long p3);
typedef CALLBACK_API(void, ConnectionSearchCallBackProcPtr)(ConnHandle hConn,
                                                            Ptr matchPtr,
                                                            long refNum);
typedef CALLBACK_API(void, ConnectionCompletionProcPtr)(ConnHandle hConn);
typedef CALLBACK_API(void, ConnectionChooseIdleProcPtr)(void);
typedef STACK_UPP_TYPE(ConnectionToolDefProcPtr) ConnectionToolDefUPP;
typedef STACK_UPP_TYPE(ConnectionSearchCallBackProcPtr)
    ConnectionSearchCallBackUPP;
typedef STACK_UPP_TYPE(ConnectionCompletionProcPtr) ConnectionCompletionUPP;
typedef STACK_UPP_TYPE(ConnectionChooseIdleProcPtr) ConnectionChooseIdleUPP;
struct ConnRecord {
  short procID;
  CMRecFlags flags;
  CMErr errCode;
  long refCon;
  long userData;
  ConnectionToolDefUPP defProc;
  Ptr config;
  Ptr oldConfig;
  long asyncEOM;
  long reserved1;
  long reserved2;
  Ptr cmPrivate;
  CMBuffers bufferArray;
  CMBufferSizes bufSizes;
  long mluField;
  CMBufferSizes asyncCount;
};

enum {
  /* CMIOPB constants and structure */
  cmIOPBQType = 10,
  cmIOPBversion = 0
};

struct CMIOPB {
  QElemPtr qLink;
  short qType; /* cmIOPBQType */
  ConnHandle hConn;
  Ptr theBuffer;
  long count;
  CMFlags flags;
  ConnectionCompletionUPP userCompletion;
  long timeout;
  CMErr errCode;
  CMChannel channel;
  long asyncEOM;
  long reserved1;
  short reserved2;
  short version;  /* cmIOPBversion */
  long refCon;    /* for application */
  long toolData1; /* for tool */
  long toolData2; /* for tool */
};
typedef struct CMIOPB CMIOPB;
typedef CMIOPB *CMIOPBPtr;
#if CALL_NOT_IN_CARBON
/**
 *  NewConnectionToolDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
ConnectionToolDefUPP
NewConnectionToolDefUPP(ConnectionToolDefProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppConnectionToolDefProcInfo = 0x0000FEF0
}; /* pascal 4_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
inline ConnectionToolDefUPP
NewConnectionToolDefUPP(ConnectionToolDefProcPtr userRoutine) {
  return (ConnectionToolDefUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppConnectionToolDefProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewConnectionToolDefUPP(userRoutine)                                   \
  (ConnectionToolDefUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),          \
                                              uppConnectionToolDefProcInfo,    \
                                              GetCurrentArchitecture())
#endif
#endif

/**
 *  NewConnectionSearchCallBackUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
ConnectionSearchCallBackUPP
NewConnectionSearchCallBackUPP(ConnectionSearchCallBackProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppConnectionSearchCallBackProcInfo = 0x00000FC0
}; /* pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
inline ConnectionSearchCallBackUPP
NewConnectionSearchCallBackUPP(ConnectionSearchCallBackProcPtr userRoutine) {
  return (ConnectionSearchCallBackUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppConnectionSearchCallBackProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewConnectionSearchCallBackUPP(userRoutine)                            \
  (ConnectionSearchCallBackUPP) NewRoutineDescriptor(                          \
      (ProcPtr)(userRoutine), uppConnectionSearchCallBackProcInfo,             \
      GetCurrentArchitecture())
#endif
#endif

/**
 *  NewConnectionCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
ConnectionCompletionUPP
NewConnectionCompletionUPP(ConnectionCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppConnectionCompletionProcInfo = 0x000000C0
}; /* pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
inline ConnectionCompletionUPP
NewConnectionCompletionUPP(ConnectionCompletionProcPtr userRoutine) {
  return (ConnectionCompletionUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppConnectionCompletionProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewConnectionCompletionUPP(userRoutine)                                \
  (ConnectionCompletionUPP) NewRoutineDescriptor(                              \
      (ProcPtr)(userRoutine), uppConnectionCompletionProcInfo,                 \
      GetCurrentArchitecture())
#endif
#endif

/**
 *  NewConnectionChooseIdleUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
ConnectionChooseIdleUPP
NewConnectionChooseIdleUPP(ConnectionChooseIdleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppConnectionChooseIdleProcInfo = 0x00000000
}; /* pascal no_return_value Func() */
#ifdef __cplusplus
inline ConnectionChooseIdleUPP
NewConnectionChooseIdleUPP(ConnectionChooseIdleProcPtr userRoutine) {
  return (ConnectionChooseIdleUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppConnectionChooseIdleProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewConnectionChooseIdleUPP(userRoutine)                                \
  (ConnectionChooseIdleUPP) NewRoutineDescriptor(                              \
      (ProcPtr)(userRoutine), uppConnectionChooseIdleProcInfo,                 \
      GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeConnectionToolDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeConnectionToolDefUPP(ConnectionToolDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeConnectionToolDefUPP(ConnectionToolDefUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeConnectionToolDefUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeConnectionSearchCallBackUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeConnectionSearchCallBackUPP(ConnectionSearchCallBackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void
DisposeConnectionSearchCallBackUPP(ConnectionSearchCallBackUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeConnectionSearchCallBackUPP(userUPP)                            \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeConnectionCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeConnectionCompletionUPP(ConnectionCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeConnectionCompletionUPP(ConnectionCompletionUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeConnectionCompletionUPP(userUPP)                                \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeConnectionChooseIdleUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeConnectionChooseIdleUPP(ConnectionChooseIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeConnectionChooseIdleUPP(ConnectionChooseIdleUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeConnectionChooseIdleUPP(userUPP)                                \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeConnectionToolDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
InvokeConnectionToolDefUPP(ConnHandle hConn, short msg, long p1, long p2,
                           long p3, ConnectionToolDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline long InvokeConnectionToolDefUPP(ConnHandle hConn, short msg, long p1,
                                       long p2, long p3,
                                       ConnectionToolDefUPP userUPP) {
  return (long)CALL_FIVE_PARAMETER_UPP(userUPP, uppConnectionToolDefProcInfo,
                                       hConn, msg, p1, p2, p3);
}
#else
#define InvokeConnectionToolDefUPP(hConn, msg, p1, p2, p3, userUPP)            \
  (long)CALL_FIVE_PARAMETER_UPP((userUPP), uppConnectionToolDefProcInfo,       \
                                (hConn), (msg), (p1), (p2), (p3))
#endif
#endif

/**
 *  InvokeConnectionSearchCallBackUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
InvokeConnectionSearchCallBackUPP(ConnHandle hConn, Ptr matchPtr, long refNum,
                                  ConnectionSearchCallBackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void
InvokeConnectionSearchCallBackUPP(ConnHandle hConn, Ptr matchPtr, long refNum,
                                  ConnectionSearchCallBackUPP userUPP) {
  CALL_THREE_PARAMETER_UPP(userUPP, uppConnectionSearchCallBackProcInfo, hConn,
                           matchPtr, refNum);
}
#else
#define InvokeConnectionSearchCallBackUPP(hConn, matchPtr, refNum, userUPP)    \
  CALL_THREE_PARAMETER_UPP((userUPP), uppConnectionSearchCallBackProcInfo,     \
                           (hConn), (matchPtr), (refNum))
#endif
#endif

/**
 *  InvokeConnectionCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
InvokeConnectionCompletionUPP(ConnHandle hConn,
                              ConnectionCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void InvokeConnectionCompletionUPP(ConnHandle hConn,
                                          ConnectionCompletionUPP userUPP) {
  CALL_ONE_PARAMETER_UPP(userUPP, uppConnectionCompletionProcInfo, hConn);
}
#else
#define InvokeConnectionCompletionUPP(hConn, userUPP)                          \
  CALL_ONE_PARAMETER_UPP((userUPP), uppConnectionCompletionProcInfo, (hConn))
#endif
#endif

/**
 *  InvokeConnectionChooseIdleUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
InvokeConnectionChooseIdleUPP(ConnectionChooseIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void InvokeConnectionChooseIdleUPP(ConnectionChooseIdleUPP userUPP) {
  CALL_ZERO_PARAMETER_UPP(userUPP, uppConnectionChooseIdleProcInfo);
}
#else
#define InvokeConnectionChooseIdleUPP(userUPP)                                 \
  CALL_ZERO_PARAMETER_UPP((userUPP), uppConnectionChooseIdleProcInfo)
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewConnectionToolDefProc(userRoutine)                                  \
  NewConnectionToolDefUPP(userRoutine)
#define NewConnectionSearchCallBackProc(userRoutine)                           \
  NewConnectionSearchCallBackUPP(userRoutine)
#define NewConnectionCompletionProc(userRoutine)                               \
  NewConnectionCompletionUPP(userRoutine)
#define NewConnectionChooseIdleProc(userRoutine)                               \
  NewConnectionChooseIdleUPP(userRoutine)
#define CallConnectionToolDefProc(userRoutine, hConn, msg, p1, p2, p3)         \
  InvokeConnectionToolDefUPP(hConn, msg, p1, p2, p3, userRoutine)
#define CallConnectionSearchCallBackProc(userRoutine, hConn, matchPtr, refNum) \
  InvokeConnectionSearchCallBackUPP(hConn, matchPtr, refNum, userRoutine)
#define CallConnectionCompletionProc(userRoutine, hConn)                       \
  InvokeConnectionCompletionUPP(hConn, userRoutine)
#define CallConnectionChooseIdleProc(userRoutine)                              \
  InvokeConnectionChooseIdleUPP(userRoutine)
#endif /* CALL_NOT_IN_CARBON */

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  InitCM()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
InitCM(void);

/**
 *  CMGetVersion()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
CMGetVersion(ConnHandle hConn);

/**
 *  CMGetCMVersion()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
CMGetCMVersion(void);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  CMNew()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
ConnHandle
CMNew(short procID, CMRecFlags flags, ConstCMBufferSizesParam desiredSizes,
      long refCon, long userData);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  CMDispose()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMDispose(ConnHandle hConn);

/**
 *  CMListen()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMListen(ConnHandle hConn, Boolean async, ConnectionCompletionUPP completor,
         long timeout);

/**
 *  CMAccept()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMAccept(ConnHandle hConn, Boolean accept);

/**
 *  CMOpen()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMOpen(ConnHandle hConn, Boolean async, ConnectionCompletionUPP completor,
       long timeout);

/**
 *  CMClose()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMClose(ConnHandle hConn, Boolean async, ConnectionCompletionUPP completor,
        long timeout, Boolean now);

/**
 *  CMAbort()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMAbort(ConnHandle hConn);

/**
 *  CMStatus()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMStatus(ConnHandle hConn, CMBufferSizes sizes, CMStatFlags *flags);

/**
 *  CMIdle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMIdle(ConnHandle hConn);

/**
 *  CMReset()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMReset(ConnHandle hConn);

/**
 *  CMBreak()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMBreak(ConnHandle hConn, long duration, Boolean async,
        ConnectionCompletionUPP completor);

/**
 *  CMRead()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMRead(ConnHandle hConn, void *theBuffer, long *toRead, CMChannel theChannel,
       Boolean async, ConnectionCompletionUPP completor, long timeout,
       CMFlags *flags);

/**
 *  CMWrite()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMWrite(ConnHandle hConn, const void *theBuffer, long *toWrite,
        CMChannel theChannel, Boolean async, ConnectionCompletionUPP completor,
        long timeout, CMFlags flags);

/**
 *  CMIOKill()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMIOKill(ConnHandle hConn, short which);

/**
 *  CMActivate()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMActivate(ConnHandle hConn, Boolean activate);

/**
 *  CMResume()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMResume(ConnHandle hConn, Boolean resume);

/**
 *  CMMenu()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
CMMenu(ConnHandle hConn, short menuID, short item);

/**
 *  CMValidate()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
CMValidate(ConnHandle hConn);

/**
 *  CMDefault()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMDefault(Ptr *theConfig, short procID, Boolean allocate);

/**
 *  CMSetupPreflight()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
CMSetupPreflight(short procID, long *magicCookie);

/**
 *  CMSetupFilter()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
CMSetupFilter(short procID, const void *theConfig, short count,
              DialogRef theDialog, EventRecord *theEvent, short *theItem,
              long *magicCookie);

/**
 *  CMSetupSetup()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMSetupSetup(short procID, const void *theConfig, short count,
             DialogRef theDialog, long *magicCookie);

/**
 *  CMSetupItem()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMSetupItem(short procID, const void *theConfig, short count,
            DialogRef theDialog, short *theItem, long *magicCookie);

/**
 *  CMSetupXCleanup()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMSetupXCleanup(short procID, const void *theConfig, short count,
                DialogRef theDialog, Boolean OKed, long *magicCookie);

/**
 *  CMSetupPostflight()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMSetupPostflight(short procID);

/**
 *  CMGetConfig()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Ptr
CMGetConfig(ConnHandle hConn);

/**
 *  CMSetConfig()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
CMSetConfig(ConnHandle hConn, const void *thePtr);

/**
 *  CMIntlToEnglish()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
CMIntlToEnglish(ConnHandle hConn, const void *inputPtr, Ptr *outputPtr,
                short language);

/**
 *  CMEnglishToIntl()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
CMEnglishToIntl(ConnHandle hConn, const void *inputPtr, Ptr *outputPtr,
                short language);

/**
 *  CMAddSearch()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
CMAddSearch(ConnHandle hConn, ConstStr255Param theString, CMSearchFlags flags,
            ConnectionSearchCallBackUPP callBack);

/**
 *  CMRemoveSearch()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMRemoveSearch(ConnHandle hConn, long refnum);

/**
 *  CMClearSearch()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMClearSearch(ConnHandle hConn);

/**
 *  CMGetConnEnvirons()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMGetConnEnvirons(ConnHandle hConn, ConnEnvironRec *theEnvirons);

/**
 *  CMChoose()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
CMChoose(ConnHandle *hConn, Point where, ConnectionChooseIdleUPP idle);

/**
 *  CMEvent()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMEvent(ConnHandle hConn, const EventRecord *theEvent);

/**
 *  CMGetToolName()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMGetToolName(short procID, Str255 name);

/**
 *  CMGetProcID()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
CMGetProcID(ConstStr255Param name);

/**
 *  CMSetRefCon()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMSetRefCon(ConnHandle hConn, long refCon);

/**
 *  CMGetRefCon()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
CMGetRefCon(ConnHandle hConn);

/**
 *  CMGetUserData()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
CMGetUserData(ConnHandle hConn);

/**
 *  CMSetUserData()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMSetUserData(ConnHandle hConn, long userData);

/**
 *  CMGetErrorString()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
CMGetErrorString(ConnHandle hConn, short id, Str255 errMsg);

/**
 *  CMNewIOPB()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMNewIOPB(ConnHandle hConn, CMIOPBPtr *theIOPB);

/**
 *  CMDisposeIOPB()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMDisposeIOPB(ConnHandle hConn, CMIOPBPtr theIOPB);

/**
 *  CMPBRead()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMPBRead(ConnHandle hConn, CMIOPBPtr theIOPB, Boolean async);

/**
 *  CMPBWrite()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMPBWrite(ConnHandle hConn, CMIOPBPtr theIOPB, Boolean async);

/**
 *  CMPBIOKill()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
CMPBIOKill(ConnHandle hConn, CMIOPBPtr theIOPB);

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

#endif /* __CONNECTIONS__ */
