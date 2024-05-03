/**
    \file ADSP.h

    \brief   AppleTalk Data Stream Protocol (ADSP) Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \ingroup AppleTalk

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

  /**driver control csCodes*/
  enum
  {
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

  enum
  {
    /** connection opening modes */
    ocRequest = 1,  /** request a connection with remote */
    ocPassive = 2,  /** wait for a connection request from remote */
    ocAccept = 3,   /** accept request as delivered by listener */
    ocEstablish = 4 /** consider connection to be open */
  };

  enum
  {
    /** connection end states */
    sListening = 1, /** for connection listeners */
    sPassive = 2,   /** waiting for a connection request from remote */
    sOpening = 3,   /** requesting a connection with remote */
    sOpen = 4,      /** connection is open */
    sClosing = 5,   /** connection is being torn down */
    sClosed = 6     /** connection end state is closed */
  };

  enum
  {
    /** client event flags */
    eClosed = 0x80,    /** received connection closed advice */
    eTearDown = 0x40,  /** connection closed due to broken connection */
    eAttention = 0x20, /** received attention message */
    eFwdReset = 0x10   /** received forward reset advice */
  };

  enum
  {
    /** miscellaneous constants */
    attnBufSize = 570,    /** size of client attention buffer */
    minDSPQueueSize = 100 /** Minimum size of receive or send Queue */
  };

  /** connection control block */
  typedef struct TRCCB TRCCB;
  typedef TRCCB *TPCCB;
  struct TRCCB
  {
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
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TRinitParams
  {
    TPCCB ccbPtr;        /**< Pointer to CCB*/
    ProcPtr userRoutine; /**< Client routine to call on event*/
    short sendQSize;     /**< Size of send queue (..K bytes)*/
    Ptr sendQueue;       /**< Client passed send queue buffer*/
    short recvQSize;     /**< Size of receive queue (..K bytes)*/
    Ptr recvQueue;       /**< Client passed receive queue*/
    Ptr attnPtr;         /**< Client passed receive attention*/
    char localSocket;    /**< Local socket number*/
  } TRinitParams;        /**< */

  typedef struct TRinitParams TRinitParams;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TRopenParams
  {
    short localCID;          /**< Local connection ID*/
    short remoteCID;         /**< Remote connection ID*/
    AddrBlock remoteAddress; /**< Address of remote end*/
    AddrBlock filterAddress; /**< Address filter*/
    long sendSeq;            /**< Local send sequence number*/
    short sendWindow;        /**< Send window size*/
    long recvSeq;            /**< Receive sequence number*/
    long attnSendSeq;        /**< Attention send seq number*/
    long attnRecvSeq;        /**< Attention receive seq num*/
    char ocMode;             /**< Open connection mode*/
    char ocInterval;         /**< Open connection request retry*/
    char ocMaximum;          /**< Open connection request retry*/
  } TRopenParams;            /**< */

  typedef struct TRopenParams TRopenParams;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TRcloseParams
  {
    char abort;    /**< Abort connection immediately if*/
  } TRcloseParams; /**< */

  typedef struct TRcloseParams TRcloseParams;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TRioParams
  {
    short reqCount; /**< Requested number of bytes*/
    short;          /**< actCount;/**< Actual number of bytes*/
    Ptr dataPtr;    /**< Pointer to data buffer*/
    char eom;       /**<  if end of message*/
    char flush;     /**<  to send data now*/
  } TRioParams;     /**< */

  typedef struct TRioParams TRioParams;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TRattnParams
  {
    short;             /**< attnCode;/**< Client attention code*/
    short attnSize;    /**< Size of attention data*/
    Ptr attnData;      /**< Pointer to attention data*/
    char attnInterval; /**< Retransmit int -tick intervals*/
  } TRattnParams;      /**< */

  typedef struct TRattnParams TRattnParams;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TRstatusParams
  {
    TPCCB ccbPtr;       /**<   Pointer to CCB*/
    short sendQPending; /**<   Bytes waiting in send queue*/
    short sendQFree;    /**<   Available space in send queue*/
    short recvQPending; /**<   Pending bytes in receive*/
    short recvQFree;    /**<   Available buffer space in*/
  } TRstatusParams;     /**< */

  typedef struct TRstatusParams TRstatusParams;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TRoptionParams
  {
    short sendBlocking; /**<  Quantum for data packets*/
    char sendTimer;     /**<  Send time in -ticks intervals*/
    char rtmtTimer;     /**<  Retransmit time in -tick*/
    char badSeqMax;     /**<  Threshold for sending retransmit*/
    char useCheckSum;   /**<  Use ddp packet checksum*/
  } TRoptionParams;     /**< */

  typedef struct TRoptionParams TRoptionParams;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TRnewcidParams
  {
    unsigned short newcid; /**<  new connection id returned*/
  } TRnewcidParams;        /**< */

  typedef struct TRnewcidParams TRnewcidParams;
  /**
  <pre>
   * \note <pre>The .DSP parameter block, defined by the DSPParamBlock data type, is a
  variant parameter block for the PBControl function.
  The qLink, qType, ioTrap, ioCmdAddr, ioNamePtr, and ioVRefNum fields
  are filled in by the Device Manager ; your application should not have to
  set or read these fields. The ioResult field returns the result of the function.
  If you call the routine asynchronously, the
  Device Manager sets this field to 1 as soon as you call the routine, and it
  changes the field to the actual result code when the routine completes
  execution. The ioCompletion field is a pointer to a completion routine that
  you can provide; the Device Manager calls your completion routine when
  it completes execution of the PBControl function. If you are not providing
  a completion routine, specify NIL for this field.
  The ioCRefNum field is returned by the OpenDriver function. You must
  specify this number every time you call The .DSP Driver .
  The csCode field specifies the command to be executed. You must fill in this
  field before calling the PBControl function. You can use the following
  constants as values for the csCode field:
  ADSP routine selectors
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct DSPParamBlock
  {
    QElem *qLink;                /**<  Address of next queue entry;/**<*/
    short qType;                 /**<  Queue type*/
    short ioTrap;                /**<  Routine trap*/
    Ptr ioCmdAddr;               /**<  Routine address*/
    ProcPtr ioCompletion;        /**<  Completion routine*/
    OSErr ioResult;              /**<  Result code*/
    StringPtr ioNamePtr;         /**<  Used only for dspOpen*/
    short ioVRefNum;             /**<  Volume reference number*/
    short ioCRefNum;             /**<  Driver reference number*/
    long qStatus;                /**<  Reserved for ADSP*/
    short ccbRefNum;             /**<  CCBreference number*/
    TRinitParams initParams;     /**<  dspInit, dspCLInit*/
    TRopenParams openParams;     /**<  dspOpen, dspCLListen ,*/
    TRcloseParams closeParams;   /**<  dspClose, dspRemove*/
    TRioParams ioParams;         /**<  dspRead, dspWrite*/
    TRattnParams attnParams;     /**<  dspAttention*/
    TRstatusParams statusParams; /**<  dspStatus*/
    TRoptionParams optionParams; /**<  dspOptions*/
    TRnewcidParams newCID;       /**<  dspNewCID*/
  } u;                           /**<*/

#if CALL_NOT_IN_CARBON
  /**
   *  NewADSPConnectionEventUPP()
   *

   *
  on_car\carbon_libavailable as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ADSPConnectionEventUPP
  NewADSPConnectionEventUPP(ADSPConnectionEventProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppADSPConnectionEventProcInfo = 0x0000B802
  }; /** register no_return_value Func(4_bytes:A1) */
#ifdef __cplusplus
  inline ADSPConnectionEventUPP
  NewADSPConnectionEventUPP(ADSPConnectionEventProcPtr userRoutine)
  {
    return (ADSPConnectionEventUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppADSPConnectionEventProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewADSPConnectionEventUPP(userRoutine)                \
  (ADSPConnectionEventUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppADSPConnectionEventProcInfo, \
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
  ADSPCompletionUPP
  NewADSPCompletionUPP(ADSPCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppADSPCompletionProcInfo = 0x00009802
  }; /** register no_return_value Func(4_bytes:A0) */
#ifdef __cplusplus
  inline ADSPCompletionUPP
  NewADSPCompletionUPP(ADSPCompletionProcPtr userRoutine)
  {
    return (ADSPCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppADSPCompletionProcInfo,
                                                   GetCurrentArchitecture());
  }
#else
#define NewADSPCompletionUPP(userRoutine)                                     \
  (ADSPCompletionUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppADSPCompletionProcInfo, \
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
  void
  DisposeADSPConnectionEventUPP(ADSPConnectionEventUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeADSPConnectionEventUPP(ADSPConnectionEventUPP userUPP)
  {
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
  void
  DisposeADSPCompletionUPP(ADSPCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeADSPCompletionUPP(ADSPCompletionUPP userUPP)
  {
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
  void
  InvokeADSPConnectionEventUPP(TPCCB sourceCCB, ADSPConnectionEventUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeADSPConnectionEventUPP(TPCCB sourceCCB,
                                           ADSPConnectionEventUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppADSPConnectionEventProcInfo, sourceCCB);
  }
#else
#define InvokeADSPConnectionEventUPP(sourceCCB, userUPP) \
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
  void
  InvokeADSPCompletionUPP(DSPPBPtr thePBPtr, ADSPCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeADSPCompletionUPP(DSPPBPtr thePBPtr,
                                      ADSPCompletionUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppADSPCompletionProcInfo, thePBPtr);
  }
#else
#define InvokeADSPCompletionUPP(thePBPtr, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppADSPCompletionProcInfo, (thePBPtr))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewADSPConnectionEventProc(userRoutine) \
  NewADSPConnectionEventUPP(userRoutine)
#define NewADSPCompletionProc(userRoutine) NewADSPCompletionUPP(userRoutine)
#define CallADSPConnectionEventProc(userRoutine, sourceCCB) \
  InvokeADSPConnectionEventUPP(sourceCCB, userRoutine)
#define CallADSPCompletionProc(userRoutine, thePBPtr) \
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
ADSPCompletionUPP(thePBPtr, userRoutine)
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
port off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif /** __ADSP__ */
rt off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif /** __ADSP__ */
