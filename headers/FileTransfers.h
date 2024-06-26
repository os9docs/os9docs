/**
     \file       FileTransfers.h

    \brief   CommToolbox File Transfer Manager Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1988-2001 by Apple Computer, Inc., all rights reserved

    \ingroup File
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FILETRANSFERS__
#define __FILETRANSFERS__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __STANDARDFILE__
#include <StandardFile.h>
#endif

#ifndef __CTBUTILITIES__
#include <CTBUtilities.h>
#endif

#ifndef __CONNECTIONS__
#include <Connections.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __TERMINALS__
#include <Terminals.h>
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
  curFTVersion = 2 /* current file transfer manager version*/
};

enum {
  /* FTErr    */
  ftGenericError = -1,
  ftNoErr = 0,
  ftRejected = 1,
  ftFailed = 2,
  ftTimeOut = 3,
  ftTooManyRetry = 4,
  ftNotEnoughDSpace = 5,
  ftRemoteCancel = 6,
  ftWrongFormat = 7,
  ftNoTools = 8,
  ftUserCancel = 9,
  ftNotSupported = 10
};

typedef OSErr FTErr;
enum {
  ftIsFTMode = 1 << 0,
  ftNoMenus = 1 << 1,
  ftQuiet = 1 << 2,
  ftConfigChanged = 1 << 4,
  ftSucc = 1 << 7
};

typedef unsigned long FTFlags;
enum {
  ftSameCircuit = 1 << 0,
  ftSendDisable = 1 << 1,
  ftReceiveDisable = 1 << 2,
  ftTextOnly = 1 << 3,
  ftNoStdFile = 1 << 4,
  ftMultipleFileSend = 1 << 5
};

typedef unsigned short FTAttributes;
enum {
  ftReceiving = 0,
  ftTransmitting = 1,
  ftFullDuplex = 2 /* (16) added ftFullDuplex bit.*/
};

typedef unsigned short FTDirection;
typedef CALLBACK_API(long, FileTransferDefProcPtr)(TermHandle hTerm, short msg,
                                                   long p1, long p2, long p3);
/*  application routines type definitions */
typedef struct FTRecord FTRecord;
typedef FTRecord *FTPtr;
typedef FTPtr *FTHandle;
typedef CALLBACK_API(OSErr, FileTransferReadProcPtr)(unsigned long *count,
                                                     Ptr pData, long refCon,
                                                     short fileMsg);
typedef CALLBACK_API(OSErr, FileTransferWriteProcPtr)(unsigned long *count,
                                                      Ptr pData, long refCon,
                                                      short fileMsg);
typedef CALLBACK_API(Size, FileTransferSendProcPtr)(Ptr thePtr, long theSize,
                                                    long refCon,
                                                    CMChannel channel,
                                                    CMFlags flag);
typedef CALLBACK_API(Size, FileTransferReceiveProcPtr)(Ptr thePtr, long theSize,
                                                       long refCon,
                                                       CMChannel channel,
                                                       CMFlags *flag);
typedef CALLBACK_API(OSErr,
                     FileTransferEnvironsProcPtr)(long refCon,
                                                  ConnEnvironRec *theEnvirons);
typedef CALLBACK_API(void,
                     FileTransferNotificationProcPtr)(FTHandle hFT,
                                                      const FSSpec *pFSSpec);
typedef CALLBACK_API(void, FileTransferChooseIdleProcPtr)(void);
typedef STACK_UPP_TYPE(FileTransferDefProcPtr) FileTransferDefUPP;
typedef STACK_UPP_TYPE(FileTransferReadProcPtr) FileTransferReadUPP;
typedef STACK_UPP_TYPE(FileTransferWriteProcPtr) FileTransferWriteUPP;
typedef STACK_UPP_TYPE(FileTransferSendProcPtr) FileTransferSendUPP;
typedef STACK_UPP_TYPE(FileTransferReceiveProcPtr) FileTransferReceiveUPP;
typedef STACK_UPP_TYPE(FileTransferEnvironsProcPtr) FileTransferEnvironsUPP;
typedef STACK_UPP_TYPE(FileTransferNotificationProcPtr)
    FileTransferNotificationUPP;
typedef STACK_UPP_TYPE(FileTransferChooseIdleProcPtr) FileTransferChooseIdleUPP;
struct FTRecord {
  short procID;
  FTFlags flags;
  FTErr errCode;
  long refCon;
  long userData;
  FileTransferDefUPP defProc;
  Ptr config;
  Ptr oldConfig;
  FileTransferEnvironsUPP environsProc;
  long reserved1;
  long reserved2;
  Ptr ftPrivate;
  FileTransferSendUPP sendProc;
  FileTransferReceiveUPP recvProc;
  FileTransferWriteUPP writeProc;
  FileTransferReadUPP readProc;
  WindowRef owner;
  FTDirection direction;
  SFReply theReply;
  long writePtr;
  long readPtr;
  Ptr theBuf;
  long bufSize;
  Str255 autoRec;
  FTAttributes attributes;
};

typedef unsigned short FTCompletionKind;
enum {
  /* FTReadProc messages */
  ftReadOpenFile = 0, /* count = forkFlags, buffer = pblock from PBGetFInfo */
  ftReadDataFork = 1,
  ftReadRsrcFork = 2,
  ftReadAbort = 3,
  ftReadComplete = 4,
  ftReadSetFPos = 6, /* count = forkFlags, buffer = pBlock same as PBSetFPos */
  ftReadGetFPos = 7  /* count = forkFlags, buffer = pBlock same as PBGetFPos */
};

enum {
  /* FTWriteProc messages */
  ftWriteOpenFile = 0, /* count = forkFlags, buffer = pblock from PBGetFInfo */
  ftWriteDataFork = 1,
  ftWriteRsrcFork = 2,
  ftWriteAbort = 3,
  ftWriteComplete = 4,
  ftWriteFileInfo = 5,
  ftWriteSetFPos = 6, /* count = forkFlags, buffer = pBlock same as PBSetFPos */
  ftWriteGetFPos = 7  /* count = forkFlags, buffer = pBlock same as PBGetFPos */
};

enum {
  /*    fork flags */
  ftOpenDataFork = 1,
  ftOpenRsrcFork = 2
};

#if CALL_NOT_IN_CARBON
/**
 *  NewFileTransferDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FileTransferDefUPP
NewFileTransferDefUPP(FileTransferDefProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppFileTransferDefProcInfo = 0x0000FEF0
}; /* pascal 4_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
inline FileTransferDefUPP
NewFileTransferDefUPP(FileTransferDefProcPtr userRoutine) {
  return (FileTransferDefUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppFileTransferDefProcInfo,
                                                  GetCurrentArchitecture());
}
#else
#define NewFileTransferDefUPP(userRoutine)                                     \
  (FileTransferDefUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppFileTransferDefProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  NewFileTransferReadUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FileTransferReadUPP
NewFileTransferReadUPP(FileTransferReadProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppFileTransferReadProcInfo = 0x00002FE0
}; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 2_bytes) */
#ifdef __cplusplus
inline FileTransferReadUPP
NewFileTransferReadUPP(FileTransferReadProcPtr userRoutine) {
  return (FileTransferReadUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppFileTransferReadProcInfo,
                                                   GetCurrentArchitecture());
}
#else
#define NewFileTransferReadUPP(userRoutine)                                    \
  (FileTransferReadUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),           \
                                             uppFileTransferReadProcInfo,      \
                                             GetCurrentArchitecture())
#endif
#endif

/**
 *  NewFileTransferWriteUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FileTransferWriteUPP
NewFileTransferWriteUPP(FileTransferWriteProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppFileTransferWriteProcInfo = 0x00002FE0
}; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 2_bytes) */
#ifdef __cplusplus
inline FileTransferWriteUPP
NewFileTransferWriteUPP(FileTransferWriteProcPtr userRoutine) {
  return (FileTransferWriteUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppFileTransferWriteProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewFileTransferWriteUPP(userRoutine)                                   \
  (FileTransferWriteUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),          \
                                              uppFileTransferWriteProcInfo,    \
                                              GetCurrentArchitecture())
#endif
#endif

/**
 *  NewFileTransferSendUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FileTransferSendUPP
NewFileTransferSendUPP(FileTransferSendProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppFileTransferSendProcInfo = 0x0000AFF0
}; /* pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 2_bytes, 2_bytes) */
#ifdef __cplusplus
inline FileTransferSendUPP
NewFileTransferSendUPP(FileTransferSendProcPtr userRoutine) {
  return (FileTransferSendUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppFileTransferSendProcInfo,
                                                   GetCurrentArchitecture());
}
#else
#define NewFileTransferSendUPP(userRoutine)                                    \
  (FileTransferSendUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),           \
                                             uppFileTransferSendProcInfo,      \
                                             GetCurrentArchitecture())
#endif
#endif

/**
 *  NewFileTransferReceiveUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FileTransferReceiveUPP
NewFileTransferReceiveUPP(FileTransferReceiveProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppFileTransferReceiveProcInfo = 0x0000EFF0
}; /* pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
inline FileTransferReceiveUPP
NewFileTransferReceiveUPP(FileTransferReceiveProcPtr userRoutine) {
  return (FileTransferReceiveUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppFileTransferReceiveProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewFileTransferReceiveUPP(userRoutine)                                 \
  (FileTransferReceiveUPP) NewRoutineDescriptor(                               \
      (ProcPtr)(userRoutine), uppFileTransferReceiveProcInfo,                  \
      GetCurrentArchitecture())
#endif
#endif

/**
 *  NewFileTransferEnvironsUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FileTransferEnvironsUPP
NewFileTransferEnvironsUPP(FileTransferEnvironsProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppFileTransferEnvironsProcInfo = 0x000003E0
}; /* pascal 2_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
inline FileTransferEnvironsUPP
NewFileTransferEnvironsUPP(FileTransferEnvironsProcPtr userRoutine) {
  return (FileTransferEnvironsUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppFileTransferEnvironsProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewFileTransferEnvironsUPP(userRoutine)                                \
  (FileTransferEnvironsUPP) NewRoutineDescriptor(                              \
      (ProcPtr)(userRoutine), uppFileTransferEnvironsProcInfo,                 \
      GetCurrentArchitecture())
#endif
#endif

/**
 *  NewFileTransferNotificationUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FileTransferNotificationUPP
NewFileTransferNotificationUPP(FileTransferNotificationProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppFileTransferNotificationProcInfo = 0x000003C0
}; /* pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
inline FileTransferNotificationUPP
NewFileTransferNotificationUPP(FileTransferNotificationProcPtr userRoutine) {
  return (FileTransferNotificationUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppFileTransferNotificationProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewFileTransferNotificationUPP(userRoutine)                            \
  (FileTransferNotificationUPP) NewRoutineDescriptor(                          \
      (ProcPtr)(userRoutine), uppFileTransferNotificationProcInfo,             \
      GetCurrentArchitecture())
#endif
#endif

/**
 *  NewFileTransferChooseIdleUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FileTransferChooseIdleUPP
NewFileTransferChooseIdleUPP(FileTransferChooseIdleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppFileTransferChooseIdleProcInfo = 0x00000000
}; /* pascal no_return_value Func() */
#ifdef __cplusplus
inline FileTransferChooseIdleUPP
NewFileTransferChooseIdleUPP(FileTransferChooseIdleProcPtr userRoutine) {
  return (FileTransferChooseIdleUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppFileTransferChooseIdleProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewFileTransferChooseIdleUPP(userRoutine)                              \
  (FileTransferChooseIdleUPP) NewRoutineDescriptor(                            \
      (ProcPtr)(userRoutine), uppFileTransferChooseIdleProcInfo,               \
      GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeFileTransferDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeFileTransferDefUPP(FileTransferDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeFileTransferDefUPP(FileTransferDefUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeFileTransferDefUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeFileTransferReadUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeFileTransferReadUPP(FileTransferReadUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeFileTransferReadUPP(FileTransferReadUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeFileTransferReadUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeFileTransferWriteUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeFileTransferWriteUPP(FileTransferWriteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeFileTransferWriteUPP(FileTransferWriteUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeFileTransferWriteUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeFileTransferSendUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeFileTransferSendUPP(FileTransferSendUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeFileTransferSendUPP(FileTransferSendUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeFileTransferSendUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeFileTransferReceiveUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeFileTransferReceiveUPP(FileTransferReceiveUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeFileTransferReceiveUPP(FileTransferReceiveUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeFileTransferReceiveUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeFileTransferEnvironsUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeFileTransferEnvironsUPP(FileTransferEnvironsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeFileTransferEnvironsUPP(FileTransferEnvironsUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeFileTransferEnvironsUPP(userUPP)                                \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeFileTransferNotificationUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeFileTransferNotificationUPP(FileTransferNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void
DisposeFileTransferNotificationUPP(FileTransferNotificationUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeFileTransferNotificationUPP(userUPP)                            \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeFileTransferChooseIdleUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeFileTransferChooseIdleUPP(FileTransferChooseIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void
DisposeFileTransferChooseIdleUPP(FileTransferChooseIdleUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeFileTransferChooseIdleUPP(userUPP)                              \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeFileTransferDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
InvokeFileTransferDefUPP(TermHandle hTerm, short msg, long p1, long p2, long p3,
                         FileTransferDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline long InvokeFileTransferDefUPP(TermHandle hTerm, short msg, long p1,
                                     long p2, long p3,
                                     FileTransferDefUPP userUPP) {
  return (long)CALL_FIVE_PARAMETER_UPP(userUPP, uppFileTransferDefProcInfo,
                                       hTerm, msg, p1, p2, p3);
}
#else
#define InvokeFileTransferDefUPP(hTerm, msg, p1, p2, p3, userUPP)              \
  (long)CALL_FIVE_PARAMETER_UPP((userUPP), uppFileTransferDefProcInfo,         \
                                (hTerm), (msg), (p1), (p2), (p3))
#endif
#endif

/**
 *  InvokeFileTransferReadUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InvokeFileTransferReadUPP(unsigned long *count, Ptr pData, long refCon,
                          short fileMsg, FileTransferReadUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline OSErr InvokeFileTransferReadUPP(unsigned long *count, Ptr pData,
                                       long refCon, short fileMsg,
                                       FileTransferReadUPP userUPP) {
  return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppFileTransferReadProcInfo,
                                        count, pData, refCon, fileMsg);
}
#else
#define InvokeFileTransferReadUPP(count, pData, refCon, fileMsg, userUPP)      \
  (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP), uppFileTransferReadProcInfo,      \
                                  (count), (pData), (refCon), (fileMsg))
#endif
#endif

/**
 *  InvokeFileTransferWriteUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InvokeFileTransferWriteUPP(unsigned long *count, Ptr pData, long refCon,
                           short fileMsg, FileTransferWriteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline OSErr InvokeFileTransferWriteUPP(unsigned long *count, Ptr pData,
                                        long refCon, short fileMsg,
                                        FileTransferWriteUPP userUPP) {
  return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppFileTransferWriteProcInfo,
                                        count, pData, refCon, fileMsg);
}
#else
#define InvokeFileTransferWriteUPP(count, pData, refCon, fileMsg, userUPP)     \
  (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP), uppFileTransferWriteProcInfo,     \
                                  (count), (pData), (refCon), (fileMsg))
#endif
#endif

/**
 *  InvokeFileTransferSendUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Size
InvokeFileTransferSendUPP(Ptr thePtr, long theSize, long refCon,
                          CMChannel channel, CMFlags flag,
                          FileTransferSendUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline Size InvokeFileTransferSendUPP(Ptr thePtr, long theSize, long refCon,
                                      CMChannel channel, CMFlags flag,
                                      FileTransferSendUPP userUPP) {
  return (Size)CALL_FIVE_PARAMETER_UPP(userUPP, uppFileTransferSendProcInfo,
                                       thePtr, theSize, refCon, channel, flag);
}
#else
#define InvokeFileTransferSendUPP(thePtr, theSize, refCon, channel, flag,      \
                                  userUPP)                                     \
  (Size) CALL_FIVE_PARAMETER_UPP((userUPP), uppFileTransferSendProcInfo,       \
                                 (thePtr), (theSize), (refCon), (channel),     \
                                 (flag))
#endif
#endif

/**
 *  InvokeFileTransferReceiveUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Size
InvokeFileTransferReceiveUPP(Ptr thePtr, long theSize, long refCon,
                             CMChannel channel, CMFlags *flag,
                             FileTransferReceiveUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline Size InvokeFileTransferReceiveUPP(Ptr thePtr, long theSize, long refCon,
                                         CMChannel channel, CMFlags *flag,
                                         FileTransferReceiveUPP userUPP) {
  return (Size)CALL_FIVE_PARAMETER_UPP(userUPP, uppFileTransferReceiveProcInfo,
                                       thePtr, theSize, refCon, channel, flag);
}
#else
#define InvokeFileTransferReceiveUPP(thePtr, theSize, refCon, channel, flag,   \
                                     userUPP)                                  \
  (Size) CALL_FIVE_PARAMETER_UPP((userUPP), uppFileTransferReceiveProcInfo,    \
                                 (thePtr), (theSize), (refCon), (channel),     \
                                 (flag))
#endif
#endif

/**
 *  InvokeFileTransferEnvironsUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InvokeFileTransferEnvironsUPP(long refCon, ConnEnvironRec *theEnvirons,
                              FileTransferEnvironsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline OSErr InvokeFileTransferEnvironsUPP(long refCon,
                                           ConnEnvironRec *theEnvirons,
                                           FileTransferEnvironsUPP userUPP) {
  return (OSErr)CALL_TWO_PARAMETER_UPP(userUPP, uppFileTransferEnvironsProcInfo,
                                       refCon, theEnvirons);
}
#else
#define InvokeFileTransferEnvironsUPP(refCon, theEnvirons, userUPP)            \
  (OSErr) CALL_TWO_PARAMETER_UPP((userUPP), uppFileTransferEnvironsProcInfo,   \
                                 (refCon), (theEnvirons))
#endif
#endif

/**
 *  InvokeFileTransferNotificationUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
InvokeFileTransferNotificationUPP(FTHandle hFT, const FSSpec *pFSSpec,
                                  FileTransferNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void
InvokeFileTransferNotificationUPP(FTHandle hFT, const FSSpec *pFSSpec,
                                  FileTransferNotificationUPP userUPP) {
  CALL_TWO_PARAMETER_UPP(userUPP, uppFileTransferNotificationProcInfo, hFT,
                         pFSSpec);
}
#else
#define InvokeFileTransferNotificationUPP(hFT, pFSSpec, userUPP)               \
  CALL_TWO_PARAMETER_UPP((userUPP), uppFileTransferNotificationProcInfo,       \
                         (hFT), (pFSSpec))
#endif
#endif

/**
 *  InvokeFileTransferChooseIdleUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
InvokeFileTransferChooseIdleUPP(FileTransferChooseIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void InvokeFileTransferChooseIdleUPP(FileTransferChooseIdleUPP userUPP) {
  CALL_ZERO_PARAMETER_UPP(userUPP, uppFileTransferChooseIdleProcInfo);
}
#else
#define InvokeFileTransferChooseIdleUPP(userUPP)                               \
  CALL_ZERO_PARAMETER_UPP((userUPP), uppFileTransferChooseIdleProcInfo)
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewFileTransferDefProc(userRoutine) NewFileTransferDefUPP(userRoutine)
#define NewFileTransferReadProc(userRoutine) NewFileTransferReadUPP(userRoutine)
#define NewFileTransferWriteProc(userRoutine)                                  \
  NewFileTransferWriteUPP(userRoutine)
#define NewFileTransferSendProc(userRoutine) NewFileTransferSendUPP(userRoutine)
#define NewFileTransferReceiveProc(userRoutine)                                \
  NewFileTransferReceiveUPP(userRoutine)
#define NewFileTransferEnvironsProc(userRoutine)                               \
  NewFileTransferEnvironsUPP(userRoutine)
#define NewFileTransferNotificationProc(userRoutine)                           \
  NewFileTransferNotificationUPP(userRoutine)
#define NewFileTransferChooseIdleProc(userRoutine)                             \
  NewFileTransferChooseIdleUPP(userRoutine)
#define CallFileTransferDefProc(userRoutine, hTerm, msg, p1, p2, p3)           \
  InvokeFileTransferDefUPP(hTerm, msg, p1, p2, p3, userRoutine)
#define CallFileTransferReadProc(userRoutine, count, pData, refCon, fileMsg)   \
  InvokeFileTransferReadUPP(count, pData, refCon, fileMsg, userRoutine)
#define CallFileTransferWriteProc(userRoutine, count, pData, refCon, fileMsg)  \
  InvokeFileTransferWriteUPP(count, pData, refCon, fileMsg, userRoutine)
#define CallFileTransferSendProc(userRoutine, thePtr, theSize, refCon,         \
                                 channel, flag)                                \
  InvokeFileTransferSendUPP(thePtr, theSize, refCon, channel, flag, userRoutine)
#define CallFileTransferReceiveProc(userRoutine, thePtr, theSize, refCon,      \
                                    channel, flag)                             \
  InvokeFileTransferReceiveUPP(thePtr, theSize, refCon, channel, flag,         \
                               userRoutine)
#define CallFileTransferEnvironsProc(userRoutine, refCon, theEnvirons)         \
  InvokeFileTransferEnvironsUPP(refCon, theEnvirons, userRoutine)
#define CallFileTransferNotificationProc(userRoutine, hFT, pFSSpec)            \
  InvokeFileTransferNotificationUPP(hFT, pFSSpec, userRoutine)
#define CallFileTransferChooseIdleProc(userRoutine)                            \
  InvokeFileTransferChooseIdleUPP(userRoutine)
#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  InitFT()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTErr
InitFT(void);

/**
 *  FTGetVersion()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
FTGetVersion(FTHandle hFT);

/**
 *  FTGetFTVersion()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
FTGetFTVersion(void);

/**
 *  FTNew()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTHandle
FTNew(short procID, FTFlags flags, FileTransferSendUPP sendProc,
      FileTransferReceiveUPP recvProc, FileTransferReadUPP readProc,
      FileTransferWriteUPP writeProc, FileTransferEnvironsUPP environsProc,
      WindowRef owner, long refCon, long userData);

/**
 *  FTDispose()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTDispose(FTHandle hFT);

/**
 *  FTStart()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTErr
FTStart(FTHandle hFT, FTDirection direction, const SFReply *fileInfo);

/**
 *  FTAbort()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTErr
FTAbort(FTHandle hFT);

/**
 *  FTSend()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTErr
FTSend(FTHandle hFT, short numFiles, FSSpecArrayPtr pFSSpec,
       FileTransferNotificationUPP notifyProc);

/**
 *  FTReceive()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTErr
FTReceive(FTHandle hFT, FSSpecPtr pFSSpec,
          FileTransferNotificationUPP notifyProc);

/**
 *  FTExec()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTExec(FTHandle hFT);

/**
 *  FTActivate()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTActivate(FTHandle hFT, Boolean activate);

/**
 *  FTResume()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTResume(FTHandle hFT, Boolean resume);

/**
 *  FTMenu()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
FTMenu(FTHandle hFT, short menuID, short item);

/**
 *  FTChoose()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
FTChoose(FTHandle *hFT, Point where, FileTransferChooseIdleUPP idleProc);

/**
 *  FTEvent()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTEvent(FTHandle hFT, const EventRecord *theEvent);

/**
 *  FTValidate()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
FTValidate(FTHandle hFT);

/**
 *  FTDefault()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTDefault(Ptr *theConfig, short procID, Boolean allocate);

/**
 *  FTSetupPreflight()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
FTSetupPreflight(short procID, long *magicCookie);

/**
 *  FTSetupSetup()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTSetupSetup(short procID, const void *theConfig, short count,
             DialogRef theDialog, long *magicCookie);

/**
 *  FTSetupFilter()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
FTSetupFilter(short procID, const void *theConfig, short count,
              DialogRef theDialog, EventRecord *theEvent, short *theItem,
              long *magicCookie);

/**
 *  FTSetupItem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTSetupItem(short procID, const void *theConfig, short count,
            DialogRef theDialog, short *theItem, long *magicCookie);

/**
 *  FTSetupXCleanup()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTSetupXCleanup(short procID, const void *theConfig, short count,
                DialogRef theDialog, Boolean OKed, long *magicCookie);

/**
 *  FTSetupPostflight()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTSetupPostflight(short procID);

/**
 *  FTGetConfig()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Ptr
FTGetConfig(FTHandle hFT);

/**
 *  FTSetConfig()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
FTSetConfig(FTHandle hFT, const void *thePtr);

/**
 *  FTIntlToEnglish()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTErr
FTIntlToEnglish(FTHandle hFT, const void *inputPtr, Ptr *outputPtr,
                short language);

/**
 *  FTEnglishToIntl()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTErr
FTEnglishToIntl(FTHandle hFT, const void *inputPtr, Ptr *outputPtr,
                short language);

/**
 *  FTGetToolName()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTGetToolName(short procID, Str255 name);

/**
 *  FTGetProcID()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
FTGetProcID(ConstStr255Param name);

/**
 *  FTSetRefCon()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTSetRefCon(FTHandle hFT, long refCon);

/**
 *  FTGetRefCon()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
FTGetRefCon(FTHandle hFT);

/**
 *  FTSetUserData()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTSetUserData(FTHandle hFT, long userData);

/**
 *  FTGetUserData()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
FTGetUserData(FTHandle hFT);

/**
 *  FTGetErrorString()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
FTGetErrorString(FTHandle hFT, short id, Str255 errMsg);

/**
    These Async routines were added to InterfaceLib in System 7.5
*/
/**
 *  FTSendAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTErr
FTSendAsync(FTHandle hFT, short numFiles, FSSpecArrayPtr pFSSpec,
            FileTransferNotificationUPP notifyProc);

/**
 *  FTReceiveAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTErr
FTReceiveAsync(FTHandle hFT, FSSpecPtr pFSSpec,
               FileTransferNotificationUPP notifyProc);

/**
 *  FTCompletionAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
FTErr
FTCompletionAsync(FTHandle hFT, FTCompletionKind completionCall);

#endif /* CALL_NOT_IN_CARBON */

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

#endif /* __FILETRANSFERS__ */
