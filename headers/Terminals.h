/**
     \file       Terminals.h

    \brief   Communications Toolbox Terminal tool Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1988-2001 by Apple Computer, Inc., all rights reserved

    \ingroup CommunicationsToolbox
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __TERMINALS__
#define __TERMINALS__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
#endif

#ifndef __CTBUTILITIES__
#include <CTBUtilities.h>
#endif

#ifndef __CONNECTIONS__
#include <Connections.h>
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
  curTMVersion = 2 /** current Terminal Manager version */
};

enum {
  curTermEnvRecVers =
      0 /** current Terminal Manager Environment Record version */
};

enum {
  /** error codes    */
  tmGenericError = -1,
  tmNoErr = 0,
  tmNotSent = 1,
  tmEnvironsChanged = 2,
  tmNotSupported = 7,
  tmNoTools = 8
};

typedef OSErr TMErr;
typedef UInt32 TMFlags;
enum {
  tmInvisible = 1 << 0,
  tmSaveBeforeClear = 1 << 1,
  tmNoMenus = 1 << 2,
  tmAutoScroll = 1 << 3,
  tmConfigChanged = 1 << 4
};

typedef SInt16 TMSelTypes;
enum {
  selTextNormal = 1 << 0,
  selTextBoxed = 1 << 1,
  selGraphicsMarquee = 1 << 2,
  selGraphicsLasso = 1 << 3
};

typedef UInt16 TMSearchTypes;
enum { tmSearchNoDiacrit = 1 << 8, tmSearchNoCase = 1 << 9 };

typedef UInt16 TMCursorTypes;
enum { cursorText = 1, cursorGraphics = 2 };

typedef UInt16 TMTermTypes;
enum { tmTextTerminal = 1 << 0, tmGraphicsTerminal = 1 << 1 };

struct TermDataBlock {
  TMTermTypes flags;
  Handle theData;
  Handle auxData;
  long reserved;
};
typedef struct TermDataBlock TermDataBlock;
typedef TermDataBlock *TermDataBlockPtr;
typedef TermDataBlockPtr *TermDataBlockH;
typedef TermDataBlockPtr *TermDataBlockHandle;
struct TermEnvironRec {
  short version;
  TMTermTypes termType;
  short textRows;
  short textCols;
  Point cellSize;
  Rect graphicSize;
  Point slop;
  Rect auxSpace;
};
typedef struct TermEnvironRec TermEnvironRec;
typedef TermEnvironRec *TermEnvironPtr;
union TMSelection {
  Rect selRect;
  RgnHandle selRgnHandle;
};
typedef union TMSelection TMSelection;
typedef struct TermRecord TermRecord;

typedef TermRecord *TermPtr;
typedef TermPtr *TermHandle;
typedef CALLBACK_API(long, TerminalSendProcPtr)(Ptr thePtr, long theSize,
                                                long refCon, CMFlags flags);
typedef CALLBACK_API(void, TerminalBreakProcPtr)(long duration, long refCon);
typedef CALLBACK_API(long, TerminalCacheProcPtr)(long refCon,
                                                 TermDataBlockPtr theTermData);
typedef CALLBACK_API(void, TerminalSearchCallBackProcPtr)(TermHandle hTerm,
                                                          short refNum,
                                                          Rect *foundRect);
typedef CALLBACK_API(Boolean, TerminalClikLoopProcPtr)(long refCon);
typedef CALLBACK_API(CMErr,
                     TerminalEnvironsProcPtr)(long refCon,
                                              ConnEnvironRec *theEnvirons);
typedef CALLBACK_API(void, TerminalChooseIdleProcPtr)(void);
typedef CALLBACK_API(long, TerminalToolDefProcPtr)(TermHandle hTerm, short msg,
                                                   long p1, long p2, long p3);
typedef STACK_UPP_TYPE(TerminalSendProcPtr) TerminalSendUPP;
typedef STACK_UPP_TYPE(TerminalBreakProcPtr) TerminalBreakUPP;
typedef STACK_UPP_TYPE(TerminalCacheProcPtr) TerminalCacheUPP;
typedef STACK_UPP_TYPE(TerminalSearchCallBackProcPtr) TerminalSearchCallBackUPP;
typedef STACK_UPP_TYPE(TerminalClikLoopProcPtr) TerminalClikLoopUPP;
typedef STACK_UPP_TYPE(TerminalEnvironsProcPtr) TerminalEnvironsUPP;
typedef STACK_UPP_TYPE(TerminalChooseIdleProcPtr) TerminalChooseIdleUPP;
typedef STACK_UPP_TYPE(TerminalToolDefProcPtr) TerminalToolDefUPP;
/**    TMTermTypes     */
struct TermRecord {
  short procID;
  TMFlags flags;
  TMErr errCode;
  long refCon;
  long userData;
  TerminalToolDefUPP defProc;
  Ptr config;
  Ptr oldConfig;
  TerminalEnvironsUPP environsProc;
  long reserved1;
  long reserved2;
  Ptr tmPrivate;
  TerminalSendUPP sendProc;
  TerminalBreakUPP breakProc;
  TerminalCacheUPP cacheProc;
  TerminalClikLoopUPP clikLoop;
  WindowRef owner;
  Rect termRect;
  Rect viewRect;
  Rect visRect;
  long lastIdle;
  TMSelection selection;
  TMSelTypes selType;
  long mluField;
};

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  NewTerminalSendUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TerminalSendUPP
NewTerminalSendUPP(TerminalSendProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppTerminalSendProcInfo = 0x00002FF0
}; /** pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 2_bytes) */
#ifdef __cplusplus
inline TerminalSendUPP NewTerminalSendUPP(TerminalSendProcPtr userRoutine) {
  return (TerminalSendUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                               uppTerminalSendProcInfo,
                                               GetCurrentArchitecture());
}
#else
#define NewTerminalSendUPP(userRoutine)                                        \
  (TerminalSendUPP)                                                            \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppTerminalSendProcInfo,    \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  NewTerminalBreakUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TerminalBreakUPP
NewTerminalBreakUPP(TerminalBreakProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppTerminalBreakProcInfo = 0x000003C0
}; /** pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
inline TerminalBreakUPP NewTerminalBreakUPP(TerminalBreakProcPtr userRoutine) {
  return (TerminalBreakUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                uppTerminalBreakProcInfo,
                                                GetCurrentArchitecture());
}
#else
#define NewTerminalBreakUPP(userRoutine)                                       \
  (TerminalBreakUPP)                                                           \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppTerminalBreakProcInfo,   \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  NewTerminalCacheUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TerminalCacheUPP
NewTerminalCacheUPP(TerminalCacheProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppTerminalCacheProcInfo = 0x000003F0
}; /** pascal 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
inline TerminalCacheUPP NewTerminalCacheUPP(TerminalCacheProcPtr userRoutine) {
  return (TerminalCacheUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                uppTerminalCacheProcInfo,
                                                GetCurrentArchitecture());
}
#else
#define NewTerminalCacheUPP(userRoutine)                                       \
  (TerminalCacheUPP)                                                           \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppTerminalCacheProcInfo,   \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  NewTerminalSearchCallBackUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TerminalSearchCallBackUPP
NewTerminalSearchCallBackUPP(TerminalSearchCallBackProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppTerminalSearchCallBackProcInfo = 0x00000EC0
}; /** pascal no_return_value Func(4_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
inline TerminalSearchCallBackUPP
NewTerminalSearchCallBackUPP(TerminalSearchCallBackProcPtr userRoutine) {
  return (TerminalSearchCallBackUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppTerminalSearchCallBackProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewTerminalSearchCallBackUPP(userRoutine)                              \
  (TerminalSearchCallBackUPP) NewRoutineDescriptor(                            \
      (ProcPtr)(userRoutine), uppTerminalSearchCallBackProcInfo,               \
      GetCurrentArchitecture())
#endif
#endif

/**
 *  NewTerminalClikLoopUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TerminalClikLoopUPP
NewTerminalClikLoopUPP(TerminalClikLoopProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppTerminalClikLoopProcInfo = 0x000000D0
}; /** pascal 1_byte Func(4_bytes) */
#ifdef __cplusplus
inline TerminalClikLoopUPP
NewTerminalClikLoopUPP(TerminalClikLoopProcPtr userRoutine) {
  return (TerminalClikLoopUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppTerminalClikLoopProcInfo,
                                                   GetCurrentArchitecture());
}
#else
#define NewTerminalClikLoopUPP(userRoutine)                                    \
  (TerminalClikLoopUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),           \
                                             uppTerminalClikLoopProcInfo,      \
                                             GetCurrentArchitecture())
#endif
#endif

/**
 *  NewTerminalEnvironsUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TerminalEnvironsUPP
NewTerminalEnvironsUPP(TerminalEnvironsProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppTerminalEnvironsProcInfo = 0x000003E0
}; /** pascal 2_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
inline TerminalEnvironsUPP
NewTerminalEnvironsUPP(TerminalEnvironsProcPtr userRoutine) {
  return (TerminalEnvironsUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppTerminalEnvironsProcInfo,
                                                   GetCurrentArchitecture());
}
#else
#define NewTerminalEnvironsUPP(userRoutine)                                    \
  (TerminalEnvironsUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),           \
                                             uppTerminalEnvironsProcInfo,      \
                                             GetCurrentArchitecture())
#endif
#endif

/**
 *  NewTerminalChooseIdleUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TerminalChooseIdleUPP
NewTerminalChooseIdleUPP(TerminalChooseIdleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppTerminalChooseIdleProcInfo = 0x00000000
}; /** pascal no_return_value Func() */
#ifdef __cplusplus
inline TerminalChooseIdleUPP
NewTerminalChooseIdleUPP(TerminalChooseIdleProcPtr userRoutine) {
  return (TerminalChooseIdleUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppTerminalChooseIdleProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewTerminalChooseIdleUPP(userRoutine)                                  \
  (TerminalChooseIdleUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),         \
                                               uppTerminalChooseIdleProcInfo,  \
                                               GetCurrentArchitecture())
#endif
#endif

/**
 *  NewTerminalToolDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TerminalToolDefUPP
NewTerminalToolDefUPP(TerminalToolDefProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppTerminalToolDefProcInfo = 0x0000FEF0
}; /** pascal 4_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
inline TerminalToolDefUPP
NewTerminalToolDefUPP(TerminalToolDefProcPtr userRoutine) {
  return (TerminalToolDefUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppTerminalToolDefProcInfo,
                                                  GetCurrentArchitecture());
}
#else
#define NewTerminalToolDefUPP(userRoutine)                                     \
  (TerminalToolDefUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppTerminalToolDefProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeTerminalSendUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeTerminalSendUPP(TerminalSendUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeTerminalSendUPP(TerminalSendUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeTerminalSendUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeTerminalBreakUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeTerminalBreakUPP(TerminalBreakUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeTerminalBreakUPP(TerminalBreakUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeTerminalBreakUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeTerminalCacheUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeTerminalCacheUPP(TerminalCacheUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeTerminalCacheUPP(TerminalCacheUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeTerminalCacheUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeTerminalSearchCallBackUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeTerminalSearchCallBackUPP(TerminalSearchCallBackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void
DisposeTerminalSearchCallBackUPP(TerminalSearchCallBackUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeTerminalSearchCallBackUPP(userUPP)                              \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeTerminalClikLoopUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeTerminalClikLoopUPP(TerminalClikLoopUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeTerminalClikLoopUPP(TerminalClikLoopUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeTerminalClikLoopUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeTerminalEnvironsUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeTerminalEnvironsUPP(TerminalEnvironsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeTerminalEnvironsUPP(TerminalEnvironsUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeTerminalEnvironsUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeTerminalChooseIdleUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeTerminalChooseIdleUPP(TerminalChooseIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeTerminalChooseIdleUPP(TerminalChooseIdleUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeTerminalChooseIdleUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeTerminalToolDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeTerminalToolDefUPP(TerminalToolDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeTerminalToolDefUPP(TerminalToolDefUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeTerminalToolDefUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeTerminalSendUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
InvokeTerminalSendUPP(Ptr thePtr, long theSize, long refCon, CMFlags flags,
                      TerminalSendUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline long InvokeTerminalSendUPP(Ptr thePtr, long theSize, long refCon,
                                  CMFlags flags, TerminalSendUPP userUPP) {
  return (long)CALL_FOUR_PARAMETER_UPP(userUPP, uppTerminalSendProcInfo, thePtr,
                                       theSize, refCon, flags);
}
#else
#define InvokeTerminalSendUPP(thePtr, theSize, refCon, flags, userUPP)         \
  (long)CALL_FOUR_PARAMETER_UPP((userUPP), uppTerminalSendProcInfo, (thePtr),  \
                                (theSize), (refCon), (flags))
#endif
#endif

/**
 *  InvokeTerminalBreakUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
InvokeTerminalBreakUPP(long duration, long refCon, TerminalBreakUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void InvokeTerminalBreakUPP(long duration, long refCon,
                                   TerminalBreakUPP userUPP) {
  CALL_TWO_PARAMETER_UPP(userUPP, uppTerminalBreakProcInfo, duration, refCon);
}
#else
#define InvokeTerminalBreakUPP(duration, refCon, userUPP)                      \
  CALL_TWO_PARAMETER_UPP((userUPP), uppTerminalBreakProcInfo, (duration),      \
                         (refCon))
#endif
#endif

/**
 *  InvokeTerminalCacheUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
InvokeTerminalCacheUPP(long refCon, TermDataBlockPtr theTermData,
                       TerminalCacheUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline long InvokeTerminalCacheUPP(long refCon, TermDataBlockPtr theTermData,
                                   TerminalCacheUPP userUPP) {
  return (long)CALL_TWO_PARAMETER_UPP(userUPP, uppTerminalCacheProcInfo, refCon,
                                      theTermData);
}
#else
#define InvokeTerminalCacheUPP(refCon, theTermData, userUPP)                   \
  (long)CALL_TWO_PARAMETER_UPP((userUPP), uppTerminalCacheProcInfo, (refCon),  \
                               (theTermData))
#endif
#endif

/**
 *  InvokeTerminalSearchCallBackUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
InvokeTerminalSearchCallBackUPP(TermHandle hTerm, short refNum, Rect *foundRect,
                                TerminalSearchCallBackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void InvokeTerminalSearchCallBackUPP(TermHandle hTerm, short refNum,
                                            Rect *foundRect,
                                            TerminalSearchCallBackUPP userUPP) {
  CALL_THREE_PARAMETER_UPP(userUPP, uppTerminalSearchCallBackProcInfo, hTerm,
                           refNum, foundRect);
}
#else
#define InvokeTerminalSearchCallBackUPP(hTerm, refNum, foundRect, userUPP)     \
  CALL_THREE_PARAMETER_UPP((userUPP), uppTerminalSearchCallBackProcInfo,       \
                           (hTerm), (refNum), (foundRect))
#endif
#endif

/**
 *  InvokeTerminalClikLoopUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
InvokeTerminalClikLoopUPP(long refCon, TerminalClikLoopUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline Boolean InvokeTerminalClikLoopUPP(long refCon,
                                         TerminalClikLoopUPP userUPP) {
  return (Boolean)CALL_ONE_PARAMETER_UPP(userUPP, uppTerminalClikLoopProcInfo,
                                         refCon);
}
#else
#define InvokeTerminalClikLoopUPP(refCon, userUPP)                             \
  (Boolean)                                                                    \
      CALL_ONE_PARAMETER_UPP((userUPP), uppTerminalClikLoopProcInfo, (refCon))
#endif
#endif

/**
 *  InvokeTerminalEnvironsUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMErr
InvokeTerminalEnvironsUPP(long refCon, ConnEnvironRec *theEnvirons,
                          TerminalEnvironsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline CMErr InvokeTerminalEnvironsUPP(long refCon, ConnEnvironRec *theEnvirons,
                                       TerminalEnvironsUPP userUPP) {
  return (CMErr)CALL_TWO_PARAMETER_UPP(userUPP, uppTerminalEnvironsProcInfo,
                                       refCon, theEnvirons);
}
#else
#define InvokeTerminalEnvironsUPP(refCon, theEnvirons, userUPP)                \
  (CMErr) CALL_TWO_PARAMETER_UPP((userUPP), uppTerminalEnvironsProcInfo,       \
                                 (refCon), (theEnvirons))
#endif
#endif

/**
 *  InvokeTerminalChooseIdleUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
InvokeTerminalChooseIdleUPP(TerminalChooseIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void InvokeTerminalChooseIdleUPP(TerminalChooseIdleUPP userUPP) {
  CALL_ZERO_PARAMETER_UPP(userUPP, uppTerminalChooseIdleProcInfo);
}
#else
#define InvokeTerminalChooseIdleUPP(userUPP)                                   \
  CALL_ZERO_PARAMETER_UPP((userUPP), uppTerminalChooseIdleProcInfo)
#endif
#endif

/**
 *  InvokeTerminalToolDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
InvokeTerminalToolDefUPP(TermHandle hTerm, short msg, long p1, long p2, long p3,
                         TerminalToolDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline long InvokeTerminalToolDefUPP(TermHandle hTerm, short msg, long p1,
                                     long p2, long p3,
                                     TerminalToolDefUPP userUPP) {
  return (long)CALL_FIVE_PARAMETER_UPP(userUPP, uppTerminalToolDefProcInfo,
                                       hTerm, msg, p1, p2, p3);
}
#else
#define InvokeTerminalToolDefUPP(hTerm, msg, p1, p2, p3, userUPP)              \
  (long)CALL_FIVE_PARAMETER_UPP((userUPP), uppTerminalToolDefProcInfo,         \
                                (hTerm), (msg), (p1), (p2), (p3))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewTerminalSendProc(userRoutine) NewTerminalSendUPP(userRoutine)
#define NewTerminalBreakProc(userRoutine) NewTerminalBreakUPP(userRoutine)
#define NewTerminalCacheProc(userRoutine) NewTerminalCacheUPP(userRoutine)
#define NewTerminalSearchCallBackProc(userRoutine)                             \
  NewTerminalSearchCallBackUPP(userRoutine)
#define NewTerminalClikLoopProc(userRoutine) NewTerminalClikLoopUPP(userRoutine)
#define NewTerminalEnvironsProc(userRoutine) NewTerminalEnvironsUPP(userRoutine)
#define NewTerminalChooseIdleProc(userRoutine)                                 \
  NewTerminalChooseIdleUPP(userRoutine)
#define NewTerminalToolDefProc(userRoutine) NewTerminalToolDefUPP(userRoutine)
#define CallTerminalSendProc(userRoutine, thePtr, theSize, refCon, flags)      \
  InvokeTerminalSendUPP(thePtr, theSize, refCon, flags, userRoutine)
#define CallTerminalBreakProc(userRoutine, duration, refCon)                   \
  InvokeTerminalBreakUPP(duration, refCon, userRoutine)
#define CallTerminalCacheProc(userRoutine, refCon, theTermData)                \
  InvokeTerminalCacheUPP(refCon, theTermData, userRoutine)
#define CallTerminalSearchCallBackProc(userRoutine, hTerm, refNum, foundRect)  \
  InvokeTerminalSearchCallBackUPP(hTerm, refNum, foundRect, userRoutine)
#define CallTerminalClikLoopProc(userRoutine, refCon)                          \
  InvokeTerminalClikLoopUPP(refCon, userRoutine)
#define CallTerminalEnvironsProc(userRoutine, refCon, theEnvirons)             \
  InvokeTerminalEnvironsUPP(refCon, theEnvirons, userRoutine)
#define CallTerminalChooseIdleProc(userRoutine)                                \
  InvokeTerminalChooseIdleUPP(userRoutine)
#define CallTerminalToolDefProc(userRoutine, hTerm, msg, p1, p2, p3)           \
  InvokeTerminalToolDefUPP(hTerm, msg, p1, p2, p3, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  InitTM()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(TMErr)
InitTM(void);

/**
 *  TMGetVersion()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Handle)
TMGetVersion(TermHandle hTerm);

/**
 *  TMGetTMVersion()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
TMGetTMVersion(void);

/**
 *  TMNew()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(TermHandle)
TMNew(const Rect *termRect, const Rect *viewRect, TMFlags flags, short procID,
      WindowRef owner, TerminalSendUPP sendProc, TerminalCacheUPP cacheProc,
      TerminalBreakUPP breakProc, TerminalClikLoopUPP clikLoop,
      TerminalEnvironsUPP environsProc, long refCon, long userData);

/**
 *  TMDispose()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMDispose(TermHandle hTerm);

/**
 *  TMKey()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMKey(TermHandle hTerm, const EventRecord *theEvent);

/**
 *  TMUpdate()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMUpdate(TermHandle hTerm, RgnHandle visRgn);

/**
 *  TMPaint()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMPaint(TermHandle hTerm, const TermDataBlock *theTermData,
        const Rect *theRect);

/**
 *  TMActivate()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMActivate(TermHandle hTerm, Boolean activate);

/**
 *  TMResume()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMResume(TermHandle hTerm, Boolean resume);

/**
 *  TMClick()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMClick(TermHandle hTerm, const EventRecord *theEvent);

/**
 *  TMIdle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMIdle(TermHandle hTerm);

/**
 *  TMStream()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(long)
TMStream(TermHandle hTerm, void *theBuffer, long theLength, CMFlags flags);

/**
 *  TMMenu()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Boolean)
TMMenu(TermHandle hTerm, short menuID, short item);

/**
 *  TMReset()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMReset(TermHandle hTerm);

/**
 *  TMClear()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMClear(TermHandle hTerm);

/**
 *  TMResize()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMResize(TermHandle hTerm, const Rect *newViewRect);

/**
 *  TMGetSelect()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(long)
TMGetSelect(TermHandle hTerm, Handle theData, ResType *theType);

/**
 *  TMGetLine()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMGetLine(TermHandle hTerm, short lineNo, TermDataBlock *theTermData);

/**
 *  TMSetSelection()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMSetSelection(TermHandle hTerm, const TMSelection *theSelection,
               TMSelTypes selType);

/**
 *  TMScroll()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMScroll(TermHandle hTerm, short dh, short dv);

/**
 *  TMValidate()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Boolean)
TMValidate(TermHandle hTerm);

/**
 *  TMDefault()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMDefault(Ptr *theConfig, short procID, Boolean allocate);

/**
 *  TMSetupPreflight()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Handle)
TMSetupPreflight(short procID, long *magicCookie);

/**
 *  TMSetupSetup()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMSetupSetup(short procID, const void *theConfig, short count,
             DialogRef theDialog, long *magicCookie);

/**
 *  TMSetupFilter()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Boolean)
TMSetupFilter(short procID, const void *theConfig, short count,
              DialogRef theDialog, EventRecord *theEvent, short *theItem,
              long *magicCookie);

/**
 *  TMSetupItem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMSetupItem(short procID, const void *theConfig, short count,
            DialogRef theDialog, short *theItem, long *magicCookie);

/**
 *  TMSetupXCleanup()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMSetupXCleanup(short procID, const void *theConfig, short count,
                DialogRef theDialog, Boolean OKed, long *magicCookie);

/**
 *  TMSetupPostflight()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMSetupPostflight(short procID);

/**
 *  TMGetConfig()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Ptr)
TMGetConfig(TermHandle hTerm);

/**
 *  TMSetConfig()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
TMSetConfig(TermHandle hTerm, const void *thePtr);

/**
 *  TMIntlToEnglish()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
TMIntlToEnglish(TermHandle hTerm, const void *inputPtr, Ptr *outputPtr,
                short language);

/**
 *  TMEnglishToIntl()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
TMEnglishToIntl(TermHandle hTerm, const void *inputPtr, Ptr *outputPtr,
                short language);

/**
 *  TMGetToolName()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMGetToolName(short id, Str255 name);

/**
 *  TMGetProcID()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
TMGetProcID(ConstStr255Param name);

/**
 *  TMSetRefCon()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMSetRefCon(TermHandle hTerm, long refCon);

/**
 *  TMGetRefCon()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(long)
TMGetRefCon(TermHandle hTerm);

/**
 *  TMSetUserData()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMSetUserData(TermHandle hTerm, long userData);

/**
 *  TMGetUserData()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(long)
TMGetUserData(TermHandle hTerm);

/**
 *  TMAddSearch()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
TMAddSearch(TermHandle hTerm, ConstStr255Param theString, const Rect *where,
            TMSearchTypes searchType, TerminalSearchCallBackUPP callBack);

/**
 *  TMRemoveSearch()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMRemoveSearch(TermHandle hTerm, short refnum);

/**
 *  TMClearSearch()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMClearSearch(TermHandle hTerm);

/**
 *  TMGetCursor()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Point)
TMGetCursor(TermHandle hTerm, TMCursorTypes cursType);

/**
 *  TMGetTermEnvirons()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(TMErr)
TMGetTermEnvirons(TermHandle hTerm, TermEnvironRec *theEnvirons);

/**
 *  TMChoose()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
TMChoose(TermHandle *hTerm, Point where, TerminalChooseIdleUPP idleProc);

/**
 *  TMEvent()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMEvent(TermHandle hTerm, const EventRecord *theEvent);

/**
 *  TMDoTermKey()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Boolean)
TMDoTermKey(TermHandle hTerm, ConstStr255Param theKey);

/**
 *  TMCountTermKeys()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
TMCountTermKeys(TermHandle hTerm);

/**
 *  TMGetIndTermKey()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMGetIndTermKey(TermHandle hTerm, short id, Str255 theKey);

/**
 *  TMGetErrorString()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
TMGetErrorString(TermHandle hTerm, short id, Str255 errMsg);

#endif /** CALL_NOT_IN_CARBON */

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

#endif /** __TERMINALS__ */
