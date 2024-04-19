/**
    \file ADSP.h

    \brief   AppleTalk Data Stream Protocol (ADSP) Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1986-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __ADSP__
#define __ADSP__

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __APPLETALK__
#include <AppleTalk.h>
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

/**driver control csCodes*/
enum {
  dspInit = 255,      /** create a new connection end */
  dspRemove = 254,    /** remove a connection end */
  dspOpen = 253,      /** open a connection */
  dspClose = 252,     /** close a connection */
  dspCLInit = 251,    /** create a connection listener */
  dspCLRemove = 250,  /** remove a connection listener */
  dspCLListen = 249,  /** post a listener request */
  dspCLDeny = 248,    /** deny an open connection request */
  dspStatus = 247,    /** get status of connection end */
  dspRead = 246,      /** read data from the connection */
  dspWrite = 245,     /** write data on the connection */
  dspAttention = 244, /** send an attention message */
  dspOptions = 243,   /** set connection end options */
  dspReset = 242,     /** forward reset the connection */
  dspNewCID = 241     /** generate a cid for a connection end */
};

enum {
  /** connection opening modes */
  ocRequest = 1,  /** request a connection with remote */
  ocPassive = 2,  /** wait for a connection request from remote */
  ocAccept = 3,   /** accept request as delivered by listener */
  ocEstablish = 4 /** consider connection to be open */
};

enum {
  /** connection end states */
  sListening = 1, /** for connection listeners */
  sPassive = 2,   /** waiting for a connection request from remote */
  sOpening = 3,   /** requesting a connection with remote */
  sOpen = 4,      /** connection is open */
  sClosing = 5,   /** connection is being torn down */
  sClosed = 6     /** connection end state is closed */
};

enum {
  /** client event flags */
  eClosed = 0x80,    /** received connection closed advice */
  eTearDown = 0x40,  /** connection closed due to broken connection */
  eAttention = 0x20, /** received attention message */
  eFwdReset = 0x10   /** received forward reset advice */
};

enum {
  /** miscellaneous constants */
  attnBufSize = 570,    /** size of client attention buffer */
  minDSPQueueSize = 100 /** Minimum size of receive or send Queue */
};

/** connection control block */
typedef struct TRCCB TRCCB;
typedef TRCCB *TPCCB;
struct TRCCB {
  TPCCB ccbLink;           /** link to next ccb */
  UInt16 refNum;           /** user reference number */
  UInt16 state;            /** state of the connection end */
  UInt8 userFlags;         /** flags for unsolicited connection events */
  UInt8 localSocket;       /** socket number of this connection end */
  AddrBlock remoteAddress; /** internet address of remote end */
  UInt16 attnCode;         /** attention code received */
  UInt16 attnSize;         /** size of received attention data */
  void *attnPtr;           /** ptr to received attention data */
  UInt8 reserved[220];     /** for adsp internal use */
};

typedef CALLBACK_API_REGISTER68K(void, ADSPConnectionEventProcPtr,
                                 (TPCCB sourceCCB));
typedef struct DSPParamBlock DSPParamBlock;
typedef DSPParamBlock *DSPPBPtr;
typedef CALLBACK_API_REGISTER68K(void, ADSPCompletionProcPtr,
                                 (DSPPBPtr thePBPtr));
typedef REGISTER_UPP_TYPE(ADSPConnectionEventProcPtr) ADSPConnectionEventUPP;
typedef REGISTER_UPP_TYPE(ADSPCompletionProcPtr) ADSPCompletionUPP;
struct TRinitParams {
  TPCCB ccbPtr;                       /** pointer to connection control block */
  ADSPConnectionEventUPP userRoutine; /** client routine to call on event */
  UInt16 sendQSize;                   /** size of send queue (0..64K bytes) */
  void *sendQueue;                    /** client passed send queue buffer */
  UInt16 recvQSize;  /** size of receive queue (0..64K bytes) */
  void *recvQueue;   /** client passed receive queue buffer */
  void *attnPtr;     /** client passed receive attention buffer */
  UInt8 localSocket; /** local socket number */
  UInt8 filler1;     /** filler for proper byte alignment */
};
typedef struct TRinitParams TRinitParams;
struct TRopenParams {
  UInt16 localCID;         /** local connection id */
  UInt16 remoteCID;        /** remote connection id */
  AddrBlock remoteAddress; /** address of remote end */
  AddrBlock filterAddress; /** address filter */
  UInt32 sendSeq;          /** local send sequence number */
  UInt16 sendWindow;       /** send window size */
  UInt32 recvSeq;          /** receive sequence number */
  UInt32 attnSendSeq;      /** attention send sequence number */
  UInt32 attnRecvSeq;      /** attention receive sequence number */
  UInt8 ocMode;            /** open connection mode */
  UInt8 ocInterval;        /** open connection request retry interval */
  UInt8 ocMaximum;         /** open connection request retry maximum */
  UInt8 filler2;           /** filler for proper byte alignment */
};
typedef struct TRopenParams TRopenParams;
struct TRcloseParams {
  UInt8 abort;   /** abort connection immediately if non-zero */
  UInt8 filler3; /** filler for proper byte alignment */
};
typedef struct TRcloseParams TRcloseParams;
struct TRioParams {
  UInt16 reqCount; /** requested number of bytes */
  UInt16 actCount; /** actual number of bytes */
  void *dataPtr;   /** pointer to data buffer */
  UInt8 eom;       /** indicates logical end of message */
  UInt8 flush;     /** send data now */
};
typedef struct TRioParams TRioParams;
struct TRattnParams {
  UInt16 attnCode;    /** client attention code */
  UInt16 attnSize;    /** size of attention data */
  void *attnData;     /** pointer to attention data */
  UInt8 attnInterval; /** retransmit timer in 10-tick intervals */
  UInt8 filler4;      /** filler for proper byte alignment */
};
typedef struct TRattnParams TRattnParams;
struct TRstatusParams {
  TPCCB statusCCB;     /** pointer to ccb */
  UInt16 sendQPending; /** pending bytes in send queue */
  UInt16 sendQFree;    /** available buffer space in send queue */
  UInt16 recvQPending; /** pending bytes in receive queue */
  UInt16 recvQFree;    /** available buffer space in receive queue */
};
typedef struct TRstatusParams TRstatusParams;
struct TRoptionParams {
  UInt16 sendBlocking; /** quantum for data packets */
  UInt8 sendTimer;     /** send timer in 10-tick intervals */
  UInt8 rtmtTimer;     /** retransmit timer in 10-tick intervals */
  UInt8 badSeqMax;     /** threshold for sending retransmit advice */
  UInt8 useCheckSum;   /** use ddp packet checksum */
};
typedef struct TRoptionParams TRoptionParams;
struct TRnewcidParams {
  UInt16 newcid; /** new connection id returned */
};
typedef struct TRnewcidParams TRnewcidParams;
struct DSPParamBlock {
  QElem *qLink;
  short qType;
  short ioTrap;
  Ptr ioCmdAddr;
  ADSPCompletionUPP ioCompletion;
  OSErr ioResult;
  StringPtr ioNamePtr;
  short ioVRefNum;
  short ioCRefNum; /** adsp driver refNum */
  short csCode;    /** adsp driver control code */
  long qStatus;    /** adsp internal use */
  short ccbRefNum;
  union {
    TRinitParams initParams;
    TRopenParams openParams;
    TRcloseParams closeParams;   /**dspClose, dspRemove*/
    TRioParams ioParams;         /**dspRead, dspWrite*/
    TRattnParams attnParams;     /**dspAttention*/
    TRstatusParams statusParams; /**dspStatus*/
    TRoptionParams optionParams; /**dspOptions*/
    TRnewcidParams newCIDParams; /**dspNewCID*/
  } u;
};

#if CALL_NOT_IN_CARBON
/**
 *  NewADSPConnectionEventUPP()
 *

 *
on_car\carbon_libavailable as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(ADSPConnectionEventUPP)
NewADSPConnectionEventUPP(ADSPConnectionEventProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppADSPConnectionEventProcInfo = 0x0000B802
}; /** register no_return_value Func(4_bytes:A1) */
#ifdef __cplusplus
inline ADSPConnectionEventUPP
NewADSPConnectionEventUPP(ADSPConnectionEventProcPtr userRoutine) {
  return (ADSPConnectionEventUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppADSPConnectionEventProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewADSPConnectionEventUPP(userRoutine)                                 \
  (ADSPConnectionEventUPP) NewRoutineDescriptor(                               \
      (ProcPtr)(userRoutine), uppADSPConnectionEventProcInfo,                  \
      GetCurrentArchitecture())
#endif
#endif

/**
 *  NewADSPCompletionUPP()
 *

 *    \carbon_lib\non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(ADSPCompletionUPP)
NewADSPCompletionUPP(ADSPCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppADSPCompletionProcInfo = 0x00009802
}; /** register no_return_value Func(4_bytes:A0) */
#ifdef __cplusplus
inline ADSPCompletionUPP
NewADSPCompletionUPP(ADSPCompletionProcPtr userRoutine) {
  return (ADSPCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppADSPCompletionProcInfo,
                                                 GetCurrentArchitecture());
}
#else
#define NewADSPCompletionUPP(userRoutine)                                      \
  (ADSPCompletionUPP)                                                          \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppADSPCompletionProcInfo,  \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeADSPConnectionEventUPP()
 *
\carbon_lib
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(void)
DisposeADSPConnectionEventUPP(ADSPConnectionEventUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeADSPConnectionEventUPP(ADSPConnectionEventUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeADSPConnectionEventUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeADSPCompletionUPP()
 *  \carbon_lib

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(void)
DisposeADSPCompletionUPP(ADSPCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeADSPCompletionUPP(ADSPCompletionUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeADSPCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  In\carbon_libnnectionEventUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeADSPConnectionEventUPP(__A1, __A0)
#endif
EXTERN_API_C(void)
InvokeADSPConnectionEventUPP(TPCCB sourceCCB, ADSPConnectionEventUPP userUPP)
    ONEWORDINLINE(0x4E90);
#if !OPAQUE_UPP_TYPES &&                                                       \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
inline void InvokeADSPConnectionEventUPP(TPCCB sourceCCB,
                                         ADSPConnectionEventUPP userUPP) {
  CALL_ONE_PARAMETER_UPP(userUPP, uppADSPConnectionEventProcInfo, sourceCCB);
}
#else
#define InvokeADSPConnectionEventUPP(sourceCCB, userUPP)                       \
  CALL_ONE_PARAMETER_UPP((userUPP), uppADSPConnectionEventProcInfo, (sourceCCB))
#endif
#endif

/**\carbon_lib
 *  InvokeADSPCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeADSPCompletionUPP(__A0, __A1)
#endif
EXTERN_API_C(void)
InvokeADSPCompletionUPP(DSPPBPtr thePBPtr, ADSPCompletionUPP userUPP)
    ONEWORDINLINE(0x4E91);
#if !OPAQUE_UPP_TYPES &&                                                       \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
inline void InvokeADSPCompletionUPP(DSPPBPtr thePBPtr,
                                    ADSPCompletionUPP userUPP) {
  CALL_ONE_PARAMETER_UPP(userUPP, uppADSPCompletionProcInfo, thePBPtr);
}
#else
#define InvokeADSPCompletionUPP(thePBPtr, userUPP)                             \
  CALL_ONE_PARAMETER_UPP((userUPP), uppADSPCompletionProcInfo, (thePBPtr))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewADSPConnectionEventProc(userRoutine)                                \
  NewADSPConnectionEventUPP(userRoutine)
#define NewADSPCompletionProc(userRoutine) NewADSPCompletionUPP(userRoutine)
#define CallADSPConnectionEventProc(userRoutine, sourceCCB)                    \
  InvokeADSPConnectionEventUPP(sourceCCB, userRoutine)
#define CallADSPCompletionProc(userRoutine, thePBPtr)                          \
  InvokeADSPCompletionUPP(thePBPtr, userRoutine)
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

#endif /** __ADSP__ */
