/**
     \file       OpenTransport.h

    \brief   Open Transport client interface file.  This contains all the client
   APIs

    \introduced_in  Open Transport 2.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup OpenTransport

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __OPENTRANSPORT__
#define __OPENTRANSPORT__

/**
   The following table shows how to map from the old (pre-Universal
   Interfaces) header file name to the equivalent Universal Interfaces
   header file name.
    Old Header              New Header
    ----------              ----------
    cred.h                  OpenTransportProtocol.h
    dlpi.h                  OpenTransportProtocol.h
    miioccom.h              OpenTransportProtocol.h
    mistream.h              OpenTransportProtocol.h/OpenTransportKernel.h
    modnames.h              OpenTransportProtocol.h
    OpenTptAppleTalk.h      OpenTransportProviders.h
    OpenTptClient.h         OpenTransportProtocol.h
    OpenTptCommon.h         OpenTransportProtocol.h
    OpenTptConfig.h         OpenTransportProtocol.h
    OpenTptDevLinks.h       OpenTransportProviders.h
    OpenTptInternet.h       OpenTransportProviders.h
    OpenTptISDN.h           OpenTransportProviders.h
    OpenTptLinks.h          OpenTransportProviders.h
    OpenTptModule.h         OpenTransportKernel.h
    OpenTptPCISupport.h     OpenTransportKernel.h
    OpenTptSerial.h         OpenTransportProviders.h
    OpenTptXTI.h            OpenTransportUNIX.r
    OpenTransport.h         OpenTransport.h
    OpenTransport.r         OpenTransport.r
    OTConfig.r              OpenTransportProtocol.r
    OTDebug.h               OpenTransport.h
    OTSharedLibs.h          OpenTransportProviders.h
    strlog.h                OpenTransportProtocol.h/OpenTransportKernel.h
    stropts.h               OpenTransportProtocol.h/OpenTransportUNIX.h
    strstat.h               OpenTransportProtocol.h
    tihdr.h                 OpenTransportProtocol.h
*/

#ifndef __OPENTRANSPORT__
#define __OPENTRANSPORT__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifdef __cplusplus
#include <stddef.h>
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

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma push
#pragma pointers_in_D0
#endif

  /* ***** Setup Default Compiler Variables ******/

#ifndef OTKERNEL
#define OTKERNEL 0
#endif /* !defined(OTKERNEL) */

#ifndef OTUNIXERRORS
#define OTUNIXERRORS 0
#endif /* !defined(OTUNIXERRORS) */

#ifdef qDebug
#ifndef OTDEBUG
#define OTDebug qDebug
#endif /* !defined(OTDEBUG) */

#endif /* defined(qDebug) */

#ifndef OTDEBUG
#define OTDEBUG 0
#endif /* !defined(OTDEBUG) */

/* Carbon Applications have some restrictions on using OT*/
#ifndef OTCARBONAPPLICATION
#define OTCARBONAPPLICATION 0
#endif /* !defined(OTCARBONAPPLICATION) */

#if TARGET_CPU_68K
  typedef UInt32 OTUInt8Param;
  typedef UInt32 OTUInt16Param;
  typedef SInt32 OTSInt16Param;
  typedef SInt32 OTSInt8Param;
  typedef SInt32 OTBooleanParam;
#else
typedef UInt8 OTUInt8Param;
typedef UInt16 OTUInt16Param;
typedef SInt16 OTSInt16Param;
typedef SInt8 OTSInt8Param;
typedef Boolean OTBooleanParam;
#endif /* TARGET_CPU_68K */

#if defined(__MWERKS__) || defined(THINK_C) || defined(SYMANTEC_CPLUS) || \
    defined(SYMANTEC_C) || defined(__xlc) || defined(__xlC) ||            \
    defined(__xlC__)
  typedef ByteCount OTByteCount;
  typedef ItemCount OTItemCount;
  typedef SInt32 OTInt32;
  typedef UInt32 OTUInt32;
#else
typedef unsigned int OTByteCount;
typedef unsigned int OTItemCount;
typedef int OTInt32;
typedef unsigned int OTUInt32;
#endif

  /* ***** C++ Support ******/

#define _MDECL
#if defined(__SC__) || defined(THINK_CPLUS) || defined(__MRC__)
#ifdef __cplusplus
#undef _MDECL
#define _MDECL _cdecl
#endif
#endif

  /* ***** Shared Library Prefixes ******/

#define kOTLibraryVersion "1.1"

#define kOTLibraryPrefix "OTLib$"
#define kOTModulePrefix "OTModl$"
#define kOTClientPrefix "OTClnt$"
#define kOTKernelPrefix "OTKrnl$"

  enum
  {
    kOTCFMClass = FOUR_CHAR_CODE('otan')
  };

  /* ***** Miscellaneous Type Definitions ******/

  /* A millisecond timeout value*/
  typedef UInt32 OTTimeout;
  /* An ID number in connections/transactions */
  typedef SInt32 OTSequence;
  /* An ID number for registered names */
  typedef SInt32 OTNameID;
  typedef SInt32 OTReason;
  /* Number of outstanding connection requests at a time.*/
  typedef UInt32 OTQLen;
  /* Will become internationalizeable shortly (yeah, right).*/
  typedef UInt8 *OTClientName;
  /* The command code in STREAMS messages.*/
  typedef SInt32 OTCommand;
  /* value describing a client*/
  typedef struct OpaqueOTClient *OTClient;

#define OTOffsetOf(structure, field) ((ByteCount) & ((structure *)0)->field)

  /* ***** Debugging Macros ******/

#define kOTFatalErr "FB "
#define kOTNonfatalErr "NB "
#define kOTExtFatalErr "FX "
#define kOTExtNonfatalErr "NX "
#define kOTUserFatalErr "UF "
#define kOTUserErr "UE "
#define kOTUserNonfatalErr "UE "
#define kOTInfoErr "IE "
#define kOTInfoBreak "IN "

#if CALL_NOT_IN_CARBON
  EXTERN_API(void)
  OTDebugStr(const char *str);

#if qDebug > 0
#define OTDebugBreak(str) OTDebugStr(str)
#define OTDebugTest(val, str) \
  {                           \
    if (val)                  \
      OTDebugStr(str);        \
  }
#define OTAssert(name, cond) \
  ((cond) ? ((void)0) : (OTDebugStr(__FILE__ ": " #name ": " #cond)))
#else
#define OTDebugBreak(str)
#define OTDebugTest(val, str)
#define OTAssert(name, cond)
#endif /* qDebug > 0 */

#if qDebug > 1 || qDebug2 > 1
#define OTDebugBreak2(str) OTDebugStr(str)
#define OTDebugTest2(val, str) \
  {                            \
    if (val)                   \
      OTDebugStr(str);         \
  }
#else
#define OTDebugBreak2(str)
#define OTDebugTest2(val, str)
#endif /* qDebug > 1 || qDebug2 > 1 */

#endif /* CALL_NOT_IN_CARBON */

  typedef UInt32 OTOpenFlags;
  enum
  {
    kO_ASYNC = 0x01,
    kO_NDELAY = 0x04,
    kO_NONBLOCK = 0x04
  };

#if CALL_NOT_IN_CARBON
  enum
  {
    O_ASYNC = kO_ASYNC,
    O_NDELAY = kO_NDELAY,
    O_NONBLOCK = kO_NONBLOCK
  };

#endif /* CALL_NOT_IN_CARBON */

  /* ***** UNIX-Style Error Codes ******/

  typedef UInt16 OTUnixErr;
#if OTKERNEL || OTUNIXERRORS
#undef EPERM
#undef ENOENT
#undef ENORSRC
#undef EINTR
#undef EIO
#undef ENXIO
#undef E2BIG
#undef EBADF
#undef EAGAIN
#undef ENOMEM
#undef EACCES
#undef EFAULT
#undef EBUSY
#undef EEXIST
#undef ENODEV
#undef EINVAL
#undef ENOTTY
#undef ERANGE
#undef ESRCH
#undef EPIPE

  enum
  {
    EPERM = 1,        /* Permission denied */
    ENOENT = 2,       /* No such file or directory */
    ENORSRC = 3,      /* No such resource */
    EINTR = 4,        /* Interrupted system service */
    EIO = 5,          /* I/O error */
    ENXIO = 6,        /* No such device or address */
    EBADF = 9,        /* Bad file number */
    EAGAIN = 11,      /* Try operation again later */
    ENOMEM = 12,      /* Not enough space */
    EACCES = 13,      /* Permission denied */
    EFAULT = 14,      /* Bad address */
    EBUSY = 16,       /* Device or resource busy */
    EEXIST = 17,      /* File exists */
    ENODEV = 19,      /* No such device */
    EINVAL = 22,      /* Invalid argument */
    ENOTTY = 25,      /* Not a character device */
    EPIPE = 32,       /* Broken pipe */
    ERANGE = 34,      /* Math result not representable */
    EDEADLK = 35,     /* Call would block so was aborted */
    EWOULDBLOCK = 35, /* Or a deadlock would occur */
    EALREADY = 37,
    ENOTSOCK = 38,        /* Socket operation on non-socket */
    EDESTADDRREQ = 39,    /* Destination address required */
    EMSGSIZE = 40,        /* Message too long */
    EPROTOTYPE = 41,      /* Protocol wrong type for socket */
    ENOPROTOOPT = 42,     /* Protocol not available */
    EPROTONOSUPPORT = 43, /* Protocol not supported */
    ESOCKTNOSUPPORT = 44, /* Socket type not supported */
    EOPNOTSUPP = 45,      /* Operation not supported on socket */
    EADDRINUSE = 48,      /* Address already in use */
    EADDRNOTAVAIL = 49,   /* Can't assign requested address */
    ENETDOWN = 50,        /* Network is down */
    ENETUNREACH = 51,     /* Network is unreachable */
    ENETRESET = 52,       /* Network dropped connection on reset */
    ECONNABORTED = 53,    /* Software caused connection abort */
    ECONNRESET = 54,      /* Connection reset by peer */
    ENOBUFS = 55,         /* No buffer space available */
    EISCONN = 56,         /* Socket is already connected */
    ENOTCONN = 57,        /* Socket is not connected */
    ESHUTDOWN = 58,       /* Can't send after socket shutdown */
    ETOOMANYREFS = 59,    /* Too many references: can't splice */
    ETIMEDOUT = 60,       /* Connection timed out */
    ECONNREFUSED = 61,    /* Connection refused */
    EHOSTDOWN = 64,       /* Host is down */
    EHOSTUNREACH = 65,    /* No route to host */
    EPROTO = 70,          /* STREAMS protocol error */
    ETIME = 71,
    ENOSR = 72,
    EBADMSG = 73,
    ECANCEL = 74,
    ENOSTR = 75,
    ENODATA = 76,
    EINPROGRESS = 77,
    ESRCH = 78,
    ENOMSG = 79,
    ELASTERRNO = 79
  };

#endif /* OTKERNEL || OTUNIXERRORS */

  /* ***** Open Transport/XTI Error codes ******/
  typedef UInt16 OTXTIErr;
  enum
  {
    TSUCCESS = 0,       /* No Error occurred */
    TBADADDR = 1,       /* A Bad address was specified */
    TBADOPT = 2,        /* A Bad option was specified */
    TACCES = 3,         /* Missing access permission */
    TBADF = 4,          /* Bad provider reference */
    TNOADDR = 5,        /* No address was specified */
    TOUTSTATE = 6,      /* Call issued in wrong state */
    TBADSEQ = 7,        /* Sequence specified does not exist */
    TSYSERR = 8,        /* A system error occurred */
    TLOOK = 9,          /* An event occurred - call Look() */
    TBADDATA = 10,      /* An illegal amount of data was specified */
    TBUFOVFLW = 11,     /* Passed buffer not big enough */
    TFLOW = 12,         /* Provider is flow-controlled */
    TNODATA = 13,       /* No data available for reading */
    TNODIS = 14,        /* No disconnect indication available */
    TNOUDERR = 15,      /* No Unit Data Error indication available */
    TBADFLAG = 16,      /* A Bad flag value was supplied */
    TNOREL = 17,        /* No orderly release indication available */
    TNOTSUPPORT = 18,   /* Command is not supported */
    TSTATECHNG = 19,    /* State is changing - try again later */
    TNOSTRUCTYPE = 20,  /* Bad structure type requested for OTAlloc */
    TBADNAME = 21,      /* A bad endpoint name was supplied */
    TBADQLEN = 22,      /* A Bind to an in-use address with qlen > 0*/
    TADDRBUSY = 23,     /* Address requested is already in use */
    TINDOUT = 24,       /* Accept failed because of pending listen */
    TPROVMISMATCH = 25, /* Tried to accept on incompatible endpoint */
    TRESQLEN = 26,
    TRESADDR = 27,
    TQFULL = 28,
    TPROTO = 29,    /* An unspecified provider error occurred */
    TBADSYNC = 30,  /* A synchronous call at interrupt time */
    TCANCELED = 31, /* The command was cancelled */
    TLASTXTIERROR = 31
  };

  typedef SInt32 OTResult;

#define XTI2OSStatus(x) (-3149 - (x))
#define E2OSStatus(x) (-3199 - (x))

#define OSStatus2XTI(x) ((OTXTIErr)(-3149 - (x)))
#define OSStatus2E(x) ((OTUnixErr)(-3199 - (x)))

#define IsXTIError(x) ((x) < -3149 && (x) >= (-3149 - TLASTXTIERROR))
#define IsEError(x) ((x) < -3199 && (x) >= (-3199 - ELASTERRNO))

  /* ***** OTAddress ******/

  enum
  {
    kOTGenericName = 0 /* Protocol specific data is just a string, interpreted in
    a protocol-specific fashion.*/
  };

  typedef UInt16 OTAddressType;
  struct OTAddress
  {
    OTAddressType fAddressType; /* The address format of this address...*/
    UInt8 fAddress[1];          /* ... followed by protocol specific address information.*/
  };
  typedef struct OTAddress OTAddress;
  enum
  {
    T_BIND = 1,
    T_OPTMGMT = 2,
    T_CALL = 3,
    T_DIS = 4,
    T_UNITDATA = 5,
    T_UDERROR = 6,
    T_INFO = 7,
    T_REPLYDATA = 8,
    T_REQUESTDATA = 9,
    T_UNITREQUEST = 10,
    T_UNITREPLY = 11
  };

  typedef UInt32 OTStructType;
  enum
  {
    T_ADDR = 0x01,
    T_OPT = 0x02,
    T_UDATA = 0x04,
    T_ALL = 0xFFFF
  };

  typedef UInt32 OTFieldsType;
  /* ***** OTFlags ******/
  typedef UInt32 OTFlags;
  enum
  {
    T_MORE = 0x0001,         /* More data to come in message */
    T_EXPEDITED = 0x0002,    /* Data is expedited, if possible */
    T_ACKNOWLEDGED = 0x0004, /* Acknowledge transaction */
    T_PARTIALDATA = 0x0008,  /* Partial data - more coming */
    T_NORECEIPT = 0x0010,    /* No event on transaction done */
    T_TIMEDOUT = 0x0020      /* Reply timed out */
  };

  /* These flags are used in the TOptMgmt structure to request services.*/

  enum
  {
    T_NEGOTIATE = 0x0004,
    T_CHECK = 0x0008,
    T_DEFAULT = 0x0010,
    T_CURRENT = 0x0080
  };

  enum
  {
    T_SUCCESS = 0x0020,
    T_FAILURE = 0x0040,
    T_PARTSUCCESS = 0x0100,
    T_READONLY = 0x0200,
    T_NOTSUPPORT = 0x0400
  };

  typedef UInt32 OTBand;
/* ***** Object References ******/
#ifdef __cplusplus
  typedef class TProvider *ProviderRef;
  typedef class TEndpoint *EndpointRef;
  typedef class TMapper *MapperRef;
#else
typedef void *ProviderRef;
typedef void *EndpointRef;
typedef void *MapperRef;
#endif
#define kOTInvalidRef 0L
#define kOTInvalidProviderRef ((ProviderRef)0L)
#define kOTInvalidEndpointRef ((EndpointRef)0L)
#define kOTInvalidMapperRef ((MapperRef)0L)
  /* ***** Event Codes ******/
  typedef UInt32 OTEventCode;
  enum
  {
    T_LISTEN = 0x0001,                      /* An connection request is available */
    T_CONNECT = 0x0002,                     /* Confirmation of a connect request */
    T_DATA = 0x0004,                        /* Standard data is available */
    T_EXDATA = 0x0008,                      /* Expedited data is available */
    T_DISCONNECT = 0x0010,                  /* A disconnect is available */
    T_ERROR = 0x0020,                       /* obsolete/unused in library */
    T_UDERR = 0x0040,                       /* A Unit Data Error has occurred */
    T_ORDREL = 0x0080,                      /* An orderly release is available */
    T_GODATA = 0x0100,                      /* Flow control lifted on standard data */
    T_GOEXDATA = 0x0200,                    /* Flow control lifted on expedited data*/
    T_REQUEST = 0x0400,                     /* An Incoming request is available */
    T_REPLY = 0x0800,                       /* An Incoming reply is available */
    T_PASSCON = 0x1000,                     /* State is now T_DATAXFER */
    T_RESET = 0x2000,                       /* Protocol has been reset */
    kPRIVATEEVENT = 0x10000000,             /* Base of the private event range.*/
    kCOMPLETEEVENT = 0x20000000,            /* Base of the completion event range.*/
    T_BINDCOMPLETE = 0x20000001,            /* Bind call is complete */
    T_UNBINDCOMPLETE = 0x20000002,          /* Unbind call is complete */
    T_ACCEPTCOMPLETE = 0x20000003,          /* Accept call is complete */
    T_REPLYCOMPLETE = 0x20000004,           /* SendReply call is complete */
    T_DISCONNECTCOMPLETE = 0x20000005,      /* Disconnect call is complete */
    T_OPTMGMTCOMPLETE = 0x20000006,         /* OptMgmt call is complete */
    T_OPENCOMPLETE = 0x20000007,            /* An Open call is complete */
    T_GETPROTADDRCOMPLETE = 0x20000008,     /* GetProtAddress call is complete */
    T_RESOLVEADDRCOMPLETE = 0x20000009,     /* A ResolveAddress call is complet */
    T_GETINFOCOMPLETE = 0x2000000A,         /* A GetInfo call is complete */
    T_SYNCCOMPLETE = 0x2000000B,            /* A Sync call is complete */
    T_MEMORYRELEASED = 0x2000000C,          /* No-copy memory was released */
    T_REGNAMECOMPLETE = 0x2000000D,         /* A RegisterName call is complete */
    T_DELNAMECOMPLETE = 0x2000000E,         /* A DeleteName call is complete */
    T_LKUPNAMECOMPLETE = 0x2000000F,        /* A LookupName call is complete */
    T_LKUPNAMERESULT = 0x20000010,          /* A LookupName is returning a name */
    kOTSyncIdleEvent = 0x20000011,          /* Synchronous call Idle event */
    kSTREAMEVENT = 0x21000000,              /* Base of the raw stream event range.*/
    kOTReservedEvent1 = 0x21000001,         /* reserved for internal use by OT */
    kGetmsgEvent = 0x21000002,              /* A GetMessage call is complete */
    kStreamReadEvent = 0x21000003,          /* A Read call is complete */
    kStreamWriteEvent = 0x21000004,         /* A Write call is complete */
    kStreamIoctlEvent = 0x21000005,         /* An Ioctl call is complete */
    kOTReservedEvent2 = 0x21000006,         /* reserved for internal use by OT */
    kStreamOpenEvent = 0x21000007,          /* An OpenStream call is complete */
    kPollEvent = 0x21000008,                /* A Poll call is complete */
    kOTReservedEvent3 = 0x21000009,         /* reserved for internal use by OT */
    kOTReservedEvent4 = 0x2100000A,         /* reserved for internal use by OT */
    kOTReservedEvent5 = 0x2100000B,         /* reserved for internal use by OT */
    kOTReservedEvent6 = 0x2100000C,         /* reserved for internal use by OT */
    kOTReservedEvent7 = 0x2100000D,         /* reserved for internal use by OT */
    kOTReservedEvent8 = 0x2100000E,         /* reserved for internal use by OT */
    kSIGNALEVENT = 0x22000000,              /* A signal has arrived on a raw stream, see
                 "Signal Values" below.*/
    kPROTOCOLEVENT = 0x23000000,            /* Some event from the protocols */
    kOTProviderIsDisconnected = 0x23000001, /* Provider is temporarily off-line */
    kOTProviderIsReconnected = 0x23000002,  /* Provider is now back on-line */
    kOTProviderWillClose = 0x24000001,      /* Provider will close immediately */
    kOTProviderIsClosed = 0x24000002,       /* Provider was closed */
    kOTPortDisabled =
        0x25000001, /* Port is now disabled, result is 0, cookie is port ref */
    kOTPortEnabled =
        0x25000002, /* Port is now enabled, result is 0, cookie is port ref */
    kOTPortOffline =
        0x25000003, /* Port is now offline, result is 0, cookie is port ref */
    kOTPortOnline =
        0x25000004,                   /* Port is now online, result is 0, cookie is port ref */
    kOTClosePortRequest = 0x25000005, /* Request to close/yield, result is reason,
    cookie is OTPortCloseStruct* */
    kOTYieldPortRequest = 0x25000005, /* Request to close/yield, result is reason,
    cookie is OTPortCloseStruct* */
    kOTNewPortRegistered =
        0x25000006,                       /* New port has been registered, cookie is port ref */
    kOTPortNetworkChange = 0x25000007,    /* Port may have moved to a new network,
       result is 0, cookie is port ref */
    kOTConfigurationChanged = 0x26000001, /* Protocol configuration changed */
    kOTSystemSleep = 0x26000002,
    kOTSystemShutdown = 0x26000003,
    kOTSystemAwaken = 0x26000004,
    kOTSystemIdle = 0x26000005,
    kOTSystemSleepPrep = 0x26000006,
    kOTSystemShutdownPrep = 0x26000007,
    kOTSystemAwakenPrep = 0x26000008,
    kOTStackIsLoading = 0x27000001, /* Sent before Open Transport attempts to load
    the TCP/IP protocol stack.*/
    kOTStackWasLoaded =
        0x27000002, /* Sent after the TCP/IP stack has been successfully loaded.*/
    kOTStackIsUnloading =
        0x27000003 /* Sent before Open Transport unloads the TCP/IP stack.*/
  };

  /* ***** Event Classification Macros ***** */

#define IsOTPrivateEvent(x) (((x) & 0x70000000L) == kPRIVATEEVENT)
#define IsOTCompleteEvent(x) (((x) & 0x7f000000L) == kCOMPLETEEVENT)
#define IsOTProtocolEvent(x) (((x) & 0x7f000000L) == kPROTOCOLEVENT)
#define IsOTStreamEvent(x) (((x) & 0x7f000000L) == kSTREAMEVENT)
#define IsOTSignalEvent(x) (((x) & 0x7f000000L) == kSIGNALEVENT)
#define GetOTEventCode(x) (x)

  enum
  {
    kSIGHUP = 1,
    kSIGURG = 16,
    kSIGPOLL = 30
  };

  enum
  {
    SIGHUP = kSIGHUP,
    SIGURG = kSIGURG,
    SIGPOLL = kSIGPOLL
  };

  typedef CALLBACK_API(void, OTNotifyProcPtr)(void *contextPtr, OTEventCode code,
                                              OTResult result, void *cookie);
  typedef TVECTOR_UPP_TYPE(OTNotifyProcPtr) OTNotifyUPP;
  EXTERN_API_C(OTNotifyUPP)
  NewOTNotifyUPP(OTNotifyProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOTNotifyProcInfo = 0x00003FC0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline OTNotifyUPP NewOTNotifyUPP(OTNotifyProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewOTNotifyUPP(userRoutine) (userRoutine)
#endif
#endif

  EXTERN_API_C(void)
  DisposeOTNotifyUPP(OTNotifyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOTNotifyUPP(OTNotifyUPP) {}
#else
#define DisposeOTNotifyUPP(userUPP)
#endif
#endif

  EXTERN_API_C(void)
  InvokeOTNotifyUPP(void *contextPtr, OTEventCode code, OTResult result,
                    void *cookie, OTNotifyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeOTNotifyUPP(void *contextPtr, OTEventCode code,
                                OTResult result, void *cookie,
                                OTNotifyUPP userUPP)
  {
    (*userUPP)(contextPtr, code, result, cookie);
  }
#else
#define InvokeOTNotifyUPP(contextPtr, code, result, cookie, userUPP) \
  (*userUPP)(contextPtr, code, result, cookie)
#endif
#endif

  /* ***** Option Management Definitions ******/
  /* The XTI Level number of a protocol.*/
  enum
  {
    XTI_GENERIC = 0xFFFF /* level for XTI options */
  };

  typedef UInt32 OTXTILevel;
  /* The XTI name of a protocol option.*/
  typedef UInt32 OTXTIName;
  /* XTI names for options used with XTI_GENERIC above*/
  enum
  {
    XTI_DEBUG = 0x0001,
    XTI_LINGER = 0x0080,
    XTI_RCVBUF = 0x1002,
    XTI_RCVLOWAT = 0x1004,
    XTI_SNDBUF = 0x1001,
    XTI_SNDLOWAT = 0x1003,
    XTI_PROTOTYPE = 0x1005,
    OPT_CHECKSUM = 0x0600,  /* Set checksumming = UInt32 - 0 or 1)*/
    OPT_RETRYCNT = 0x0601,  /* Set a retry counter = UInt32 (0 = infinite)*/
    OPT_INTERVAL = 0x0602,  /* Set a retry interval = UInt32 milliseconds*/
    OPT_ENABLEEOM = 0x0603, /* Enable the EOM indication = UInt8 (0 or 1)*/
    OPT_SELFSEND =
        0x0604,                /* Enable Self-sending on broadcasts = UInt32 (0 or 1)*/
    OPT_SERVERSTATUS = 0x0605, /* Set Server Status (format is proto dependent)*/
    OPT_ALERTENABLE = 0x0606,  /* Enable/Disable protocol alerts*/
    OPT_KEEPALIVE = 0x0008     /* See t_keepalive structure*/
  };

  /* ***** Ioctl Definitions ******/

#define MIOC_CMD(t, v) ((((t) & 0xFF) << 8) | ((v) & 0xFF))

  /* The following is a registry of the ioctls protocol spaces.*/

  enum
  {
    MIOC_STREAMIO = 'A',  /* Basic Stream ioctl() cmds - I_PUSH, I_LOOK, etc. */
    MIOC_TMOD = 'a',      /* ioctl's for tmod test module */
    MIOC_STRLOG = 'b',    /* ioctl's for Mentat's log device */
    MIOC_ND = 'c',        /* ioctl's for Mentat's nd device */
    MIOC_ECHO = 'd',      /* ioctl's for Mentat's echo device */
    MIOC_TLI = 'e',       /* ioctl's for Mentat's timod module */
    MIOC_RESERVEDf = 'f', /* reserved, used by SVR4 FIOxxx */
    MIOC_SAD = 'g',       /* ioctl's for Mentat's sad module */
    MIOC_ARP = 'h',       /* ioctl's for Mentat's arp module */
    MIOC_HAVOC = 'H',     /* Havoc module ioctls. */
    MIOC_RESERVEDi = 'i', /* reserved, used by SVR4 SIOCxxx */
    MIOC_SIOC = 'j',      /* sockio.h socket ioctl's */
    MIOC_TCP = 'k',       /* tcp.h ioctl's */
    MIOC_DLPI = 'l',      /* dlpi.h additions */
    MIOC_SOCKETS = 'm',   /* Mentat sockmod ioctl's */
    MIOC_IPX = 'o',       /* ioctls for IPX */
    MIOC_OT = 'O',        /* ioctls for Open Transport */
    MIOC_ATALK = 'T',     /* ioctl's for AppleTalk */
    MIOC_SRL = 'U',       /* ioctl's for Serial */
    MIOC_RESERVEDp = 'p', /* reserved, used by SVR4 */
    MIOC_RESERVEDr = 'r', /* reserved, used by SVR4 */
    MIOC_RESERVEDs = 's', /* reserved, used by SVR4 */
    MIOC_CFIG = 'z'       /* ioctl's for private configuration */
  };

  /* OT specific ioctls.*/

  enum
  {
    I_OTGetMiscellaneousEvents =
        ((MIOC_OT << 8) | 1),                  /* sign up for Misc Events */
    I_OTSetFramingType = ((MIOC_OT << 8) | 2), /* Set framing option for link */
    kOTGetFramingValue =
        (unsigned long)0xFFFFFFFF,         /* Use this value to read framing */
    I_OTSetRawMode = ((MIOC_OT << 8) | 3), /* Set raw mode for link */
    kOTSetRecvMode = 0x01,
    kOTSendErrorPacket = 0x02,
    I_OTConnect = ((MIOC_OT << 8) | 4), /* Generic connect request for links */
    I_OTDisconnect =
        ((MIOC_OT << 8) | 5),         /* Generic disconnect request for links */
    I_OTScript = ((MIOC_OT << 8) | 6) /* Send a script to a module */
  };

  /* Structure for the I_OTScript Ioctl.*/

  struct OTScriptInfo
  {
    UInt32 fScriptType;
    void *fTheScript;
    UInt32 fScriptLength;
  };
  typedef struct OTScriptInfo OTScriptInfo;
  typedef UInt32 OTXTIStates;
  enum
  {
    T_UNINIT = 0,   /* addition to standard xti.h */
    T_UNBND = 1,    /* unbound */
    T_IDLE = 2,     /* idle */
    T_OUTCON = 3,   /* outgoing connection pending */
    T_INCON = 4,    /* incoming connection pending */
    T_DATAXFER = 5, /* data transfer */
    T_OUTREL = 6,   /* outgoing orderly release */
    T_INREL = 7     /* incoming orderly release */
  };

  enum
  {
    T_YES = 1,
    T_NO = 0,
    T_UNUSED = (unsigned long)(-1),
    kT_NULL = 0,
    T_ABSREQ = 0x8000
  };

  enum
  {
    kT_UNSPEC = (unsigned long)0xFFFFFFFD,
    T_ALLOPT = 0
  };

  enum
  {
    T_NULL = kT_NULL,
    T_UNSPEC = kT_UNSPEC
  };

#ifdef __cplusplus
  typedef class OTConfiguration *OTConfigurationRef;
#else
typedef struct OTConfiguration *OTConfigurationRef;
#endif
#define kOTNoMemoryConfigurationPtr ((OTConfigurationRef)0L)
#define kOTInvalidConfigurationPtr ((OTConfigurationRef)-1L)
  /* ***** Option Management Structures ******/

  /* This structure describes the contents of a single option in a buffer.*/

  struct TOptionHeader
  {
    ByteCount len; /* total length of option */
    /* = sizeof(TOptionHeader) + length */
    /* of option value in bytes */
    OTXTILevel level; /* protocol affected */
    OTXTIName name;   /* option name */
    UInt32 status;    /* status value */
  };
  typedef struct TOptionHeader TOptionHeader;
  struct TOption
  {
    ByteCount len; /* total length of option */
    /* = sizeof(TOption) + length */
    /* of option value in bytes */
    OTXTILevel level; /* protocol affected */
    OTXTIName name;   /* option name */
    UInt32 status;    /* status value */
    UInt32 value[1];  /* data goes here */
  };
  typedef struct TOption TOption;
  /* Some useful constants when manipulating option buffers.*/
  enum
  {
    kOTOptionHeaderSize = sizeof(TOptionHeader),
    kOTBooleanOptionDataSize = sizeof(UInt32),
    kOTBooleanOptionSize = kOTOptionHeaderSize + kOTBooleanOptionDataSize,
    kOTOneByteOptionSize = kOTOptionHeaderSize + 1,
    kOTTwoByteOptionSize = kOTOptionHeaderSize + 2,
    kOTFourByteOptionSize = kOTOptionHeaderSize + sizeof(UInt32)
  };

#define T_ALIGN(len) \
  (((UInt32)(len) + (sizeof(SInt32) - 1)) & ~(sizeof(SInt32) - 1))

#define OPT_NEXTHDR(theBuffer, theBufLen, prevOption)                   \
  (((char *)(prevOption) + T_ALIGN((prevOption)->len) <                 \
    (char *)(theBuffer) + (theBufLen))                                  \
       ? (TOption *)((char *)(prevOption) + T_ALIGN((prevOption)->len)) \
       : (TOption *)NULL)

  /* t_kpalive is used with OPT_KEEPALIVE option.*/

  struct t_kpalive
  {
    SInt32 kp_onoff;   /* option on/off */
    SInt32 kp_timeout; /* timeout in minutes */
  };
  typedef struct t_kpalive t_kpalive;
  /* t_linger is used with XTI_LINGER option.*/
  struct t_linger
  {
    SInt32 l_onoff;  /* option on/off */
    SInt32 l_linger; /* linger time */
  };
  typedef struct t_linger t_linger;
  /* Values returned in servtype field of TEndpointInfo.*/

  typedef UInt32 OTServiceType;
  enum
  {
    T_COTS = 1,      /* Connection-mode service */
    T_COTS_ORD = 2,  /* Connection service with orderly release */
    T_CLTS = 3,      /* Connectionless-mode service */
    T_TRANS = 5,     /* Connection-mode transaction service */
    T_TRANS_ORD = 6, /* Connection transaction service with orderly release */
    T_TRANS_CLTS = 7 /* Connectionless transaction service */
  };

  /* Masks for the flags field of TEndpointInfo.*/

  enum
  {
    T_SENDZERO = 0x0001,              /* supports 0-length TSDU's */
    T_XPG4_1 = 0x0002,                /* supports the GetProtAddress call */
    T_CAN_SUPPORT_MDATA = 0x10000000, /* support M_DATAs on packet protocols */
    T_CAN_RESOLVE_ADDR = 0x40000000,  /* Supports ResolveAddress call */
    T_CAN_SUPPLY_MIB = 0x20000000     /* Supports SNMP MIB data */
  };

  enum
  {
    T_INFINITE = -1, /* supports infinit amounts of data */
    T_INVALID = -2   /* Does not support data transmission */
  };

  typedef SInt32 OTDataSize;
  /* Now the TEndpointInfo structure proper.*/
  struct TEndpointInfo
  {
    OTDataSize addr;        /* Maximum size of an address */
    OTDataSize options;     /* Maximum size of options */
    OTDataSize tsdu;        /* Standard data transmit unit size */
    OTDataSize etsdu;       /* Expedited data transmit unit size */
    OTDataSize connect;     /* Maximum data size on connect */
    OTDataSize discon;      /* Maximum data size on disconnect */
    OTServiceType servtype; /* service type */
    UInt32 flags;           /* Flags (see above for values) */
  };
  typedef struct TEndpointInfo TEndpointInfo;
  /* ***** OTPortRecord ******/

  /* Unique identifier for a port.*/

  typedef UInt32 OTPortRef;
  typedef OTPortRef *OTPortRefPtr;
  enum
  {
    kOTInvalidPortRef = 0
  };

  /* Valid values for the bus type element of an OTPortRef.*/

  typedef UInt8 OTBusType;
  enum
  {
    kOTUnknownBusPort = 0,
    kOTMotherboardBus = 1,
    kOTNuBus = 2,
    kOTPCIBus = 3,
    kOTGeoPort = 4,
    kOTPCCardBus = 5,
    kOTFireWireBus = 6,
    kOTLastBusIndex = 15
  };

  typedef UInt16 OTDeviceType;
  enum
  {
    kOTNoDeviceType = 0,
    kOTADEVDevice = 1,          /* An Atalk ADEV */
    kOTMDEVDevice = 2,          /* A TCP/IP MDEV */
    kOTLocalTalkDevice = 3,     /* LocalTalk */
    kOTIRTalkDevice = 4,        /* IRTalk */
    kOTTokenRingDevice = 5,     /* Token Ring */
    kOTISDNDevice = 6,          /* ISDN */
    kOTATMDevice = 7,           /* ATM */
    kOTSMDSDevice = 8,          /* SMDS */
    kOTSerialDevice = 9,        /* Serial */
    kOTEthernetDevice = 10,     /* Ethernet */
    kOTSLIPDevice = 11,         /* SLIP Pseudo-device */
    kOTPPPDevice = 12,          /* PPP Pseudo-device */
    kOTModemDevice = 13,        /* Modem Pseudo-Device */
    kOTFastEthernetDevice = 14, /* 100 MB Ethernet */
    kOTFDDIDevice = 15,         /* FDDI */
    kOTIrDADevice = 16,         /* IrDA Infrared */
    kOTATMSNAPDevice = 17,      /* ATM SNAP emulation */
    kOTFibreChannelDevice = 18, /* Fibre Channel */
    kOTFireWireDevice = 19,     /* FireWire link Device */
    kOTPseudoDevice = 1023,     /* used where no other defined device type will work*/
    kOTLastDeviceIndex = 1022
  };

  /* Special case values for the slot number element of an OTPortRef.*/

  enum
  {
    kOTLastSlotNumber = 255,
    kOTLastOtherNumber = 255
  };

  typedef UInt16 OTSlotNumber;
  /* Accessor functions for the various elements of the OTPortRef.*/
  EXTERN_API(OTPortRef)
  OTCreatePortRef(OTBusType busType, OTDeviceType devType, OTSlotNumber slot,
                  UInt16 other);

  EXTERN_API(OTDeviceType)
  OTGetDeviceTypeFromPortRef(OTPortRef ref);

  EXTERN_API(UInt16)
  OTGetBusTypeFromPortRef(OTPortRef ref);

  EXTERN_API(OTSlotNumber)
  OTGetSlotFromPortRef(OTPortRef ref, UInt16 *other);

  EXTERN_API(OTPortRef)
  OTSetDeviceTypeInPortRef(OTPortRef ref, OTDeviceType devType);

  EXTERN_API(OTPortRef)
  OTSetBusTypeInPortRef(OTPortRef ref, OTBusType busType);

#define OTCreateNuBusPortRef(devType, slot, other) \
  OTCreatePortRef(kOTNuBus, devType, slot, other)

#define OTCreatePCIPortRef(devType, slot, other) \
  OTCreatePortRef(kOTPCIBus, devType, slot, other)

#define OTCreatePCCardPortRef(devType, slot, other) \
  OTCreatePortRef(kOTPCCardBus, devType, slot, other)

  /* Name length definitions for various fields in OTPortRecord.*/

  enum
  {
    kMaxModuleNameLength = 31, /* max length of a STREAMS module name*/
    kMaxModuleNameSize = kMaxModuleNameLength + 1,
    kMaxProviderNameLength = kMaxModuleNameLength +
                             4, /* providers allow 4 characters for minor number*/
    kMaxProviderNameSize = kMaxProviderNameLength + 1,
    kMaxSlotIDLength = 7, /* PCI slot names tend to be short*/
    kMaxSlotIDSize = kMaxSlotIDLength + 1,
    kMaxResourceInfoLength = 31, /* max length of a configuration helper name*/
    kMaxResourceInfoSize = 32,
    kMaxPortNameLength =
        kMaxModuleNameLength + 4, /* max size allowed to define a port*/
    kMaxPortNameSize = kMaxPortNameLength + 1
  };

  enum
  {
    kOTPortIsActive = 0x00000001,
    kOTPortIsDisabled = 0x00000002,
    kOTPortIsUnavailable = 0x00000004,
    kOTPortIsOffline = 0x00000008
  };

  /* Masks for the fInfoFlags field of the OTPortRecord.*/

  enum
  {
    kOTPortIsDLPI = 0x00000001,
    kOTPortIsTPI = 0x00000002,
    kOTPortCanYield =
        0x00000004, /* will not be set until the port is used for the first time*/
    kOTPortCanArbitrate =
        0x00000008, /* will not be set until the port is used for the first time*/
    kOTPortIsTransitory = 0x00000010,
    kOTPortAutoConnects = 0x00000020,
    kOTPortIsSystemRegistered = 0x00004000,
    kOTPortIsPrivate = 0x00008000,
    kOTPortIsAlias = (unsigned long)0x80000000
  };

  struct OTPortRecord
  {
    OTPortRef fRef;
    UInt32 fPortFlags;
    UInt32 fInfoFlags;
    UInt32 fCapabilities;
    ItemCount fNumChildPorts;
    OTPortRef *fChildPorts;
    char fPortName[36];
    char fModuleName[32];
    char fSlotID[8];
    char fResourceInfo[32];
    char fReserved[164];
  };
  typedef struct OTPortRecord OTPortRecord;
#if !OTKERNEL
  EXTERN_API(Boolean)
  OTGetIndexedPort(OTPortRecord *portRecord, OTItemCount index);

  /* Index through the ports in the system*/
  EXTERN_API(Boolean)
  OTFindPort(OTPortRecord *portRecord, const char *portName);

  /* Find an OTPortRecord for a port using it's name*/
  EXTERN_API(Boolean)
  OTFindPortByRef(OTPortRecord *portRecord, OTPortRef ref);

/* Find an OTPortRecord for a port using it's OTPortRef*/
#if CALL_NOT_IN_CARBON
  EXTERN_API_C(OSStatus)
  OTRegisterPort(OTPortRecord *portRecord, void *ref);

  EXTERN_API_C(OSStatus)
  OTUnregisterPort(const char *portName, void **ref);

  EXTERN_API_C(OSStatus)
  OTChangePortState(OTPortRef portRef, OTEventCode theChange, OTResult why);

/* Change the state of the port.*/
#endif /* CALL_NOT_IN_CARBON */

#endif /* !OTKERNEL */

  /* ***** Data Buffers ******/
  struct TNetbuf
  {
    ByteCount maxlen;
    ByteCount len;
    UInt8 *buf;
  };
  typedef struct TNetbuf TNetbuf;
  struct strbuf
  {
    SInt32 maxlen; /* max buffer length */
    SInt32 len;    /* length of data */
    char *buf;     /* pointer to buffer */
  };
  typedef struct strbuf strbuf;
  struct OTData
  {
    void *fNext;
    void *fData;
    ByteCount fLen;
  };
  typedef struct OTData OTData;
  enum
  {
    kNetbufDataIsOTData = (unsigned long)0xFFFFFFFE
  };

  struct OTBuffer
  {
    void *fLink;            /* b_next*/
    void *fLink2;           /* b_prev*/
    struct OTBuffer *fNext; /* b_cont*/
    UInt8 *fData;           /* b_rptr*/
    ByteCount fLen;         /* b_wptr*/
    void *fSave;            /* b_datap*/
    UInt8 fBand;            /* b_band*/
    UInt8 fType;            /* b_pad1*/
    UInt8 fPad1;
    UInt8 fFlags; /* b_flag*/
  };
  typedef struct OTBuffer OTBuffer;
  enum
  {
    kOTNetbufDataIsOTBufferStar = (unsigned long)0xFFFFFFFD
  };

  /* Use the OTInitBuffer macro to initialise this structure from an OTBuffer
   * chain.*/
  struct OTBufferInfo
  {
    OTBuffer *fBuffer;
    ByteCount fOffset;
    UInt8 fPad;
  };
  typedef struct OTBufferInfo OTBufferInfo;

#define OTInitBufferInfo(infoPtr, theBuffer) \
  (infoPtr)->fBuffer = theBuffer;            \
  (infoPtr)->fPad = (theBuffer)->fPad1;      \
  (infoPtr)->fOffset = 0

  enum
  {
    kOTNetbufIsRawMode = (unsigned long)0xFFFFFFFF
  };

  struct TBind
  {
    TNetbuf addr;
    OTQLen qlen;
  };
  typedef struct TBind TBind;
  struct TDiscon
  {
    TNetbuf udata;
    OTReason reason;
    OTSequence sequence;
  };
  typedef struct TDiscon TDiscon;
  struct TCall
  {
    TNetbuf addr;
    TNetbuf opt;
    TNetbuf udata;
    OTSequence sequence;
  };
  typedef struct TCall TCall;
  /* TUnitData describes a datagram in calls to OTSndUData and OTRcvUData.*/
  struct TUnitData
  {
    TNetbuf addr;
    TNetbuf opt;
    TNetbuf udata;
  };
  typedef struct TUnitData TUnitData;
  struct TUDErr
  {
    TNetbuf addr;
    TNetbuf opt;
    SInt32 error;
  };
  typedef struct TUDErr TUDErr;
  /* TOptMgmt is passed to the OTOptionManagement call to read or set protocol*/
  struct TOptMgmt
  {
    TNetbuf opt;
    OTFlags flags;
  };
  typedef struct TOptMgmt TOptMgmt;
  struct TRequest
  {
    TNetbuf data;
    TNetbuf opt;
    OTSequence sequence;
  };
  typedef struct TRequest TRequest;
  /* TReply is passed to OTSndReply to send a reply to an incoming request.*/
  struct TReply
  {
    TNetbuf data;
    TNetbuf opt;
    OTSequence sequence;
  };
  typedef struct TReply TReply;
  struct TUnitRequest
  {
    TNetbuf addr;
    TNetbuf opt;
    TNetbuf udata;
    OTSequence sequence;
  };
  typedef struct TUnitRequest TUnitRequest;
  /* TUnitReply is passed to OTSndUReply to send a reply to an incoming request.*/
  struct TUnitReply
  {
    TNetbuf opt;
    TNetbuf udata;
    OTSequence sequence;
  };
  typedef struct TUnitReply TUnitReply;
  /* TRegisterRequest holds the name to register in a call to OTRegisterName.*/

  struct TRegisterRequest
  {
    TNetbuf name;
    TNetbuf addr;
    OTFlags flags;
  };
  typedef struct TRegisterRequest TRegisterRequest;
  struct TRegisterReply
  {
    TNetbuf addr;
    OTNameID nameid;
  };
  typedef struct TRegisterReply TRegisterReply;
  /* TLookupRequest holds the name to look up in a call to OTLookupName.*/
  struct TLookupRequest
  {
    TNetbuf name;
    TNetbuf addr;
    UInt32 maxcnt;
    OTTimeout timeout;
    OTFlags flags;
  };
  typedef struct TLookupRequest TLookupRequest;
  struct TLookupReply
  {
    TNetbuf names;
    UInt32 rspcount;
  };
  typedef struct TLookupReply TLookupReply;
  struct TLookupBuffer
  {
    UInt16 fAddressLength;
    UInt16 fNameLength;
    UInt8 fAddressBuffer[1];
  };
  typedef struct TLookupBuffer TLookupBuffer;

#define OTNextLookupBuffer(buf)                                      \
  ((TLookupBuffer *)((char *)buf +                                   \
                     ((OTOffsetOf(TLookupBuffer, fAddressBuffer) +   \
                       buf->fAddressLength + buf->fNameLength + 3) & \
                      ~3)))

  /* ***** Initializing and Shutting Down Open Transport ******/

#if !OTKERNEL
  typedef struct OpaqueOTClientContextPtr *OTClientContextPtr;
  typedef UInt32 OTInitializationFlags;
  enum
  {
    kInitOTForApplicationMask = 1,
    kInitOTForExtensionMask = 2
  };

  EXTERN_API(OSStatus)
  InitOpenTransportInContext(
      OTInitializationFlags flags,
      OTClientContextPtr *outClientContext); /* can be NULL */

  EXTERN_API(void)
  CloseOpenTransportInContext(OTClientContextPtr clientContext);

#if CALL_NOT_IN_CARBON
  EXTERN_API(OSStatus)
  InitOpenTransport(void);

  EXTERN_API(OSStatus)
  InitOpenTransportUtilities(void);

  EXTERN_API(void)
  CloseOpenTransport(void);

  EXTERN_API(OSStatus)
  OTRegisterAsClient(OTClientName name, OTNotifyUPP proc);

  EXTERN_API(OSStatus)
  OTUnregisterAsClient(void);

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API(OSStatus)
  OTRegisterAsClientInContext(OTClientName name, OTNotifyUPP proc,
                              OTClientContextPtr clientContext); /* can be NULL */

  EXTERN_API(OSStatus)
  OTUnregisterAsClientInContext(OTClientContextPtr clientContext);

#if OTCARBONAPPLICATION
/* The following macro may be used by applications only.*/
#define InitOpenTransport() \
  InitOpenTransportInContext(kInitOTForApplicationMask, NULL)
#define CloseOpenTransport() CloseOpenTransportInContext(NULL)
#define OTRegisterAsClient(name, proc) \
  OTRegisterAsClientInContext(name, proc, NULL)
#define OTUnregisterAsClient() OTUnregisterAsClientInContext(NULL)
#endif /* OTCARBONAPPLICATION */

#endif /* !OTKERNEL */

/* ***** Tasking Model ******/
#if CALL_NOT_IN_CARBON
  EXTERN_API(void)
  OTEnterInterrupt(void);

  EXTERN_API(void)
  OTLeaveInterrupt(void);

  EXTERN_API_C(Boolean)
  OTIsAtInterruptLevel(void);

  EXTERN_API_C(Boolean)
  OTCanLoadLibraries(void);

#endif /* CALL_NOT_IN_CARBON */

  typedef CALLBACK_API(void, OTProcessProcPtr)(void *arg);
  typedef TVECTOR_UPP_TYPE(OTProcessProcPtr) OTProcessUPP;
  EXTERN_API_C(OTProcessUPP)
  NewOTProcessUPP(OTProcessProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOTProcessProcInfo = 0x000000C0
  }; /* pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
  inline OTProcessUPP NewOTProcessUPP(OTProcessProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewOTProcessUPP(userRoutine) (userRoutine)
#endif
#endif

  EXTERN_API_C(void)
  DisposeOTProcessUPP(OTProcessUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOTProcessUPP(OTProcessUPP) {}
#else
#define DisposeOTProcessUPP(userUPP)
#endif
#endif

  EXTERN_API_C(void)
  InvokeOTProcessUPP(void *arg, OTProcessUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeOTProcessUPP(void *arg, OTProcessUPP userUPP)
  {
    (*userUPP)(arg);
  }
#else
#define InvokeOTProcessUPP(arg, userUPP) (*userUPP)(arg)
#endif
#endif

#if !OTKERNEL
  EXTERN_API(long)
  OTCreateDeferredTaskInContext(
      OTProcessUPP upp, void *arg,
      OTClientContextPtr clientContext); /* can be NULL */

#endif /* !OTKERNEL */

  typedef long OTDeferredTaskRef;
#if CALL_NOT_IN_CARBON
  EXTERN_API(OTDeferredTaskRef)
  OTCreateDeferredTask(OTProcessUPP proc, void *arg);

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API(Boolean)
  OTScheduleDeferredTask(OTDeferredTaskRef dtCookie);

#if CALL_NOT_IN_CARBON
  EXTERN_API(Boolean)
  OTScheduleInterruptTask(OTDeferredTaskRef dtCookie);

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API(OSStatus)
  OTDestroyDeferredTask(OTDeferredTaskRef dtCookie);

#if OTCARBONAPPLICATION
/* The following macro may be used by applications only.*/
#define OTCreateDeferredTask(upp, arg) \
  OTCreateDeferredTaskInContext(upp, arg, NULL)
#endif /* OTCARBONAPPLICATION */

#if !OTKERNEL
  typedef long OTSystemTaskRef;
#if CALL_NOT_IN_CARBON
  EXTERN_API(OTSystemTaskRef)
  OTCreateSystemTask(OTProcessUPP proc, void *arg);

  EXTERN_API(OSStatus)
  OTDestroySystemTask(OTSystemTaskRef stCookie);

  EXTERN_API(Boolean)
  OTScheduleSystemTask(OTSystemTaskRef stCookie);

  EXTERN_API(Boolean)
  OTCancelSystemTask(OTSystemTaskRef stCookie);

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API(Boolean)
  OTCanMakeSyncCall(void);

#endif /* !OTKERNEL */

/* ***** Interface to Providers ******/
#if !OTKERNEL
#if CALL_NOT_IN_CARBON
  EXTERN_API(OSStatus)
  OTAsyncOpenProvider(OTConfigurationRef cfig, OTOpenFlags flags,
                      OTNotifyUPP proc, void *contextPtr);

  EXTERN_API(ProviderRef)
  OTOpenProvider(OTConfigurationRef cfig, OTOpenFlags flags, OSStatus *errPtr);

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API(OSStatus)
  OTCloseProvider(ProviderRef ref);

#if CALL_NOT_IN_CARBON
  EXTERN_API(ProviderRef)
  OTTransferProviderOwnership(ProviderRef ref, OTClient prevOwner,
                              OSStatus *errPtr);

  EXTERN_API(OTClient)
  OTWhoAmI(void);

  EXTERN_API(OTPortRef)
  OTGetProviderPortRef(ProviderRef ref);

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API(SInt32)
  OTIoctl(ProviderRef ref, UInt32 cmd, void *data);

#if CALL_NOT_IN_CARBON
  EXTERN_API(OTResult)
  OTGetMessage(ProviderRef ref, strbuf *ctlbuf, strbuf *databuf,
               OTFlags *flagsPtr);

  EXTERN_API(OTResult)
  OTGetPriorityMessage(ProviderRef ref, strbuf *ctlbuf, strbuf *databuf,
                       OTBand *bandPtr, OTFlags *flagsPtr);

  EXTERN_API(OSStatus)
  OTPutMessage(ProviderRef ref, const strbuf *ctlbuf, const strbuf *databuf,
               OTFlags flags);

  EXTERN_API(OSStatus)
  OTPutPriorityMessage(ProviderRef ref, const strbuf *ctlbuf,
                       const strbuf *databuf, OTBand band, OTFlags flags);

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API(OSStatus)
  OTSetAsynchronous(ProviderRef ref);

  EXTERN_API(OSStatus)
  OTSetSynchronous(ProviderRef ref);

  EXTERN_API(Boolean)
  OTIsSynchronous(ProviderRef ref);

  EXTERN_API(OSStatus)
  OTSetBlocking(ProviderRef ref);

  EXTERN_API(OSStatus)
  OTSetNonBlocking(ProviderRef ref);

  EXTERN_API(Boolean)
  OTIsBlocking(ProviderRef ref);

  EXTERN_API(OSStatus)
  OTInstallNotifier(ProviderRef ref, OTNotifyUPP proc, void *contextPtr);

  EXTERN_API(OSStatus)
  OTUseSyncIdleEvents(ProviderRef ref, Boolean useEvents);

  EXTERN_API(void)
  OTRemoveNotifier(ProviderRef ref);

  EXTERN_API(void)
  OTLeaveNotifier(ProviderRef ref);

  EXTERN_API(Boolean)
  OTEnterNotifier(ProviderRef ref);

  EXTERN_API(OSStatus)
  OTAckSends(ProviderRef ref);

  EXTERN_API(OSStatus)
  OTDontAckSends(ProviderRef ref);

  EXTERN_API(Boolean)
  OTIsAckingSends(ProviderRef ref);

  EXTERN_API(OSStatus)
  OTCancelSynchronousCalls(ProviderRef ref, OSStatus err);

#define OTIsNonBlocking(ref) (!OTIsBlocking(ref))
#define OTIsAsynchronous(ref) (!OTIsSynchronous(ref))

#endif /* !OTKERNEL */

/* ***** Interface to Endpoints ******/
#if !OTKERNEL
  /* Open/Close*/
  EXTERN_API(EndpointRef)
  OTOpenEndpointInContext(OTConfigurationRef config, OTOpenFlags oflag,
                          TEndpointInfo *info, /* can be NULL */
                          OSStatus *err,
                          OTClientContextPtr clientContext); /* can be NULL */

  EXTERN_API(OSStatus)
  OTAsyncOpenEndpointInContext(
      OTConfigurationRef config, OTOpenFlags oflag,
      TEndpointInfo *info, /* can be NULL */
      OTNotifyUPP upp, void *contextPtr,
      OTClientContextPtr clientContext); /* can be NULL */

#if CALL_NOT_IN_CARBON
  EXTERN_API(EndpointRef)
  OTOpenEndpoint(OTConfigurationRef cfig, OTOpenFlags oflag,
                 TEndpointInfo *info, /* can be NULL */
                 OSStatus *err);

  EXTERN_API(OSStatus)
  OTAsyncOpenEndpoint(OTConfigurationRef cfig, OTOpenFlags oflag,
                      TEndpointInfo *info, /* can be NULL */
                      OTNotifyUPP proc, void *contextPtr);

#endif /* CALL_NOT_IN_CARBON */

#if OTCARBONAPPLICATION
/* The following macros may be used by applications only.*/
#define OTOpenEndpoint(config, oflag, info, err) \
  OTOpenEndpointInContext(config, oflag, info, err, NULL)
#define OTAsyncOpenEndpoint(config, oflag, info, proc, contextPtr) \
  OTAsyncOpenEndpointInContext(config, oflag, info, proc, contextPtr, NULL)
#endif /* OTCARBONAPPLICATION */

  /* Misc Information*/

  EXTERN_API(OSStatus)
  OTGetEndpointInfo(EndpointRef ref, TEndpointInfo *info);

  EXTERN_API(OTResult)
  OTGetEndpointState(EndpointRef ref);

  EXTERN_API(OTResult)
  OTLook(EndpointRef ref);

#if CALL_NOT_IN_CARBON
  EXTERN_API(OTResult)
  OTSync(EndpointRef ref);

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API(OTResult)
  OTCountDataBytes(EndpointRef ref, OTByteCount *countPtr);

  EXTERN_API(OSStatus)
  OTGetProtAddress(EndpointRef ref, TBind *boundAddr, /* can be NULL */
                   TBind *peerAddr);                  /* can be NULL */

  EXTERN_API(OSStatus)
  OTResolveAddress(EndpointRef ref, TBind *reqAddr, TBind *retAddr,
                   OTTimeout timeOut);

  /* Allocating structures*/

  EXTERN_API(void *)
  OTAllocInContext(EndpointRef ref, OTStructType structType, UInt32 fields,
                   OSStatus *err,
                   OTClientContextPtr clientContext); /* can be NULL */

#if CALL_NOT_IN_CARBON
  EXTERN_API(void *)
  OTAlloc(EndpointRef ref, OTStructType structType, OTFieldsType fields,
          OSStatus *err);

#endif /* CALL_NOT_IN_CARBON */

#if OTCARBONAPPLICATION
/* The following macro may be used by applications only.*/
#define OTAlloc(ref, structType, fields, err) \
  OTAllocInContext(ref, structType, fields, err, NULL)
#endif /* OTCARBONAPPLICATION */

  EXTERN_API(OTResult)
  OTFree(void *ptr, OTStructType structType);

  /* Option management*/

  /* It looks simple enough...*/

  EXTERN_API(OSStatus)
  OTOptionManagement(EndpointRef ref, TOptMgmt *req, TOptMgmt *ret);

  /* ... but then the hidden complexity emerges.*/

#if CALL_NOT_IN_CARBON
  EXTERN_API(OSStatus)
  OTCreateOptions(const char *endPtName, char **strPtr, TNetbuf *buf);

  EXTERN_API(OSStatus)
  OTCreateOptionString(const char *endPtName, TOption **opt, void *bufEnd,
                       char *str, OTByteCount stringSize);

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API(OSStatus)
  OTNextOption(UInt8 *buffer, UInt32 buflen, TOption **prevOptPtr);

  EXTERN_API(TOption *)
  OTFindOption(UInt8 *buffer, UInt32 buflen, OTXTILevel level, OTXTIName name);

  /* Bind/Unbind*/

  EXTERN_API(OSStatus)
  OTBind(EndpointRef ref, TBind *reqAddr, /* can be NULL */
         TBind *retAddr);                 /* can be NULL */

  EXTERN_API(OSStatus)
  OTUnbind(EndpointRef ref);

  /* Connection creation/tear-down*/

  EXTERN_API(OSStatus)
  OTConnect(EndpointRef ref, TCall *sndCall, TCall *rcvCall); /* can be NULL */

  EXTERN_API(OSStatus)
  OTRcvConnect(EndpointRef ref, TCall *call); /* can be NULL */

  EXTERN_API(OSStatus)
  OTListen(EndpointRef ref, TCall *call);

  EXTERN_API(OSStatus)
  OTAccept(EndpointRef listener, EndpointRef worker, TCall *call);

  EXTERN_API(OSStatus)
  OTSndDisconnect(EndpointRef ref, TCall *call); /* can be NULL */

  EXTERN_API(OSStatus)
  OTSndOrderlyDisconnect(EndpointRef ref);

  EXTERN_API(OSStatus)
  OTRcvDisconnect(EndpointRef ref, TDiscon *discon); /* can be NULL */

  EXTERN_API(OSStatus)
  OTRcvOrderlyDisconnect(EndpointRef ref);

  /* Connection-oriented send/receive*/

  EXTERN_API(OTResult)
  OTRcv(EndpointRef ref, void *buf, OTByteCount nbytes, OTFlags *flags);

  EXTERN_API(OTResult)
  OTSnd(EndpointRef ref, void *buf, OTByteCount nbytes, OTFlags flags);

  /* Connectionless send/receive*/

  EXTERN_API(OSStatus)
  OTSndUData(EndpointRef ref, TUnitData *udata);

  EXTERN_API(OSStatus)
  OTRcvUData(EndpointRef ref, TUnitData *udata, OTFlags *flags);

  EXTERN_API(OSStatus)
  OTRcvUDErr(EndpointRef ref, TUDErr *uderr); /* can be NULL */

  /* Connection-oriented transactions*/

#if CALL_NOT_IN_CARBON
  EXTERN_API(OSStatus)
  OTSndRequest(EndpointRef ref, TRequest *req, OTFlags reqFlags);

  EXTERN_API(OSStatus)
  OTRcvReply(EndpointRef ref, TReply *reply, OTFlags *replyFlags);

  EXTERN_API(OSStatus)
  OTSndReply(EndpointRef ref, TReply *reply, OTFlags replyFlags);

  EXTERN_API(OSStatus)
  OTRcvRequest(EndpointRef ref, TRequest *req, OTFlags *reqFlags);

  EXTERN_API(OSStatus)
  OTCancelRequest(EndpointRef ref, OTSequence sequence);

  EXTERN_API(OSStatus)
  OTCancelReply(EndpointRef ref, OTSequence sequence);

  /* Connectionless transactions*/

  EXTERN_API(OSStatus)
  OTSndURequest(EndpointRef ref, TUnitRequest *req, OTFlags reqFlags);

  EXTERN_API(OSStatus)
  OTRcvUReply(EndpointRef ref, TUnitReply *reply, OTFlags *replyFlags);

  EXTERN_API(OSStatus)
  OTSndUReply(EndpointRef ref, TUnitReply *reply, OTFlags replyFlags);

  EXTERN_API(OSStatus)
  OTRcvURequest(EndpointRef ref, TUnitRequest *req, OTFlags *reqFlags);

  EXTERN_API(OSStatus)
  OTCancelURequest(EndpointRef ref, OTSequence seq);

  EXTERN_API(OSStatus)
  OTCancelUReply(EndpointRef ref, OTSequence seq);

  /* Interface to Mappers*/

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API(OSStatus)
  OTAsyncOpenMapperInContext(OTConfigurationRef config, OTOpenFlags oflag,
                             OTNotifyUPP upp, void *contextPtr,
                             OTClientContextPtr clientContext); /* can be NULL */

  EXTERN_API(MapperRef)
  OTOpenMapperInContext(OTConfigurationRef config, OTOpenFlags oflag,
                        OSStatus *err,
                        OTClientContextPtr clientContext); /* can be NULL */

#if CALL_NOT_IN_CARBON
  EXTERN_API(OSStatus)
  OTAsyncOpenMapper(OTConfigurationRef cfig, OTOpenFlags oflag, OTNotifyUPP proc,
                    void *contextPtr);

  EXTERN_API(MapperRef)
  OTOpenMapper(OTConfigurationRef cfig, OTOpenFlags oflag, OSStatus *err);

#endif /* CALL_NOT_IN_CARBON */

#if OTCARBONAPPLICATION
/* The following macros may be used by applications only.*/
#define OTAsyncOpenMapper(config, oflag, proc, contextPtr) \
  OTAsyncOpenMapperInContext(config, oflag, proc, contextPtr, NULL)
#define OTOpenMapper(config, oflag, err) \
  OTOpenMapperInContext(config, oflag, err, NULL)
#endif /* OTCARBONAPPLICATION */

  EXTERN_API(OSStatus)
  OTRegisterName(MapperRef ref, TRegisterRequest *req, TRegisterReply *reply);

  EXTERN_API(OSStatus)
  OTDeleteName(MapperRef ref, TNetbuf *name);

  EXTERN_API(OSStatus)
  OTDeleteNameByID(MapperRef ref, OTNameID nameID);

  EXTERN_API(OSStatus)
  OTLookupName(MapperRef ref, TLookupRequest *req, TLookupReply *reply);

  /* Basic configuration manipulation*/

  EXTERN_API(OTConfigurationRef)
  OTCreateConfiguration(const char *path);

  EXTERN_API(OTConfigurationRef)
  OTCloneConfiguration(OTConfigurationRef cfig);

  EXTERN_API(void)
  OTDestroyConfiguration(OTConfigurationRef cfig);

  /* Interrupt-safe memory allocators*/

  EXTERN_API_C(void *)
  OTAllocMemInContext(OTByteCount size,
                      OTClientContextPtr clientContext); /* can be NULL */

#if CALL_NOT_IN_CARBON
  EXTERN_API_C(void *)
  OTAllocMem(OTByteCount size);

#endif /* CALL_NOT_IN_CARBON */

  EXTERN_API_C(void)
  OTFreeMem(void *mem);

#if OTCARBONAPPLICATION
/* The following macros may be used by applications only.*/
#define OTAllocMem(s) OTAllocMemInContext(s, NULL)
#endif /* OTCARBONAPPLICATION */

  /* Miscellaneous and Generic Routines*/

  EXTERN_API(void)
  OTDelay(UInt32 seconds);

  EXTERN_API(void)
  OTIdle(void);

#endif /* !OTKERNEL */

  /* Memory and String Routines*/

  EXTERN_API_C(void)
  OTMemcpy(void *dest, const void *src, OTByteCount nBytes);

  EXTERN_API_C(Boolean)
  OTMemcmp(const void *mem1, const void *mem2, OTByteCount nBytes);

  EXTERN_API_C(void)
  OTMemmove(void *dest, const void *src, OTByteCount nBytes);

  EXTERN_API_C(void)
  OTMemzero(void *dest, OTByteCount nBytes);

  EXTERN_API_C(void)
  OTMemset(void *dest, OTUInt8Param toSet, OTByteCount nBytes);

  EXTERN_API_C(OTByteCount)
  OTStrLength(const char *str);

  EXTERN_API_C(void)
  OTStrCopy(char *dest, const char *src);

  EXTERN_API_C(void)
  OTStrCat(char *dest, const char *src);

  EXTERN_API_C(Boolean)
  OTStrEqual(const char *src1, const char *src2);

  /* Timer Utilities*/

  typedef UnsignedWide OTTimeStamp;
  EXTERN_API_C(void)
  OTGetTimeStamp(OTTimeStamp *currentTime);

  EXTERN_API_C(OTTimeStamp *)
  OTSubtractTimeStamps(OTTimeStamp *result, OTTimeStamp *startTime,
                       OTTimeStamp *endEnd);

  EXTERN_API_C(UInt32)
  OTTimeStampInMilliseconds(OTTimeStamp *delta);

  EXTERN_API_C(UInt32)
  OTTimeStampInMicroseconds(OTTimeStamp *delta);

  EXTERN_API_C(UInt32)
  OTElapsedMilliseconds(OTTimeStamp *startTime);

  EXTERN_API_C(UInt32)
  OTElapsedMicroseconds(OTTimeStamp *startTime);

  EXTERN_API_C(UInt32)
  OTGetClockTimeInSecs(void);

  /* ***** OT Link Element ******/

  struct OTLink
  {
    struct OTLink *fNext;

#ifdef __cplusplus

    // C++ inline methods on this structure.

    void Init() { fNext = NULL; }
#endif
  };
  typedef struct OTLink OTLink;

#define OTGetLinkObject(link, struc, field) \
  ((struc *)((char *)(link)-OTOffsetOf(struc, field)))

  /* OTLIFO*/

  struct OTLIFO
  {
    OTLink *fHead;

#ifdef __cplusplus

    // C++ inline methods on this structure.

    void Init();
    void Enqueue(OTLink *link);
    OTLink *Dequeue();
    OTLink *StealList();
    Boolean IsEmpty();
#endif
  };
  typedef struct OTLIFO OTLIFO;
  EXTERN_API_C(void)
  OTLIFOEnqueue(OTLIFO *list, OTLink *link);

  EXTERN_API_C(OTLink *)
  OTLIFODequeue(OTLIFO *list);

  EXTERN_API_C(OTLink *)
  OTLIFOStealList(OTLIFO *list);

  EXTERN_API_C(OTLink *)
  OTReverseList(OTLink *list);

#ifdef __cplusplus

  // C++ inline methods on this structure.

  inline void OTLIFO::Init() { fHead = NULL; }
  inline void OTLIFO::Enqueue(OTLink *link) { OTLIFOEnqueue(this, link); }
  inline OTLink *OTLIFO::Dequeue() { return OTLIFODequeue(this); }
  inline OTLink *OTLIFO::StealList() { return OTLIFOStealList(this); }
  inline Boolean OTLIFO::IsEmpty() { return fHead == NULL; }
#endif

  /* OTList*/

  typedef CALLBACK_API_C(Boolean, OTListSearchProcPtr)(const void *ref,
                                                       OTLink *linkToCheck);
  typedef TVECTOR_UPP_TYPE(OTListSearchProcPtr) OTListSearchUPP;
  EXTERN_API_C(OTListSearchUPP)
  NewOTListSearchUPP(OTListSearchProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOTListSearchProcInfo = 0x000003D1
  }; /* 1_byte Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline OTListSearchUPP NewOTListSearchUPP(OTListSearchProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewOTListSearchUPP(userRoutine) (userRoutine)
#endif
#endif

  EXTERN_API_C(void)
  DisposeOTListSearchUPP(OTListSearchUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOTListSearchUPP(OTListSearchUPP) {}
#else
#define DisposeOTListSearchUPP(userUPP)
#endif
#endif

  EXTERN_API_C(Boolean)
  InvokeOTListSearchUPP(const void *ref, OTLink *linkToCheck,
                        OTListSearchUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeOTListSearchUPP(const void *ref, OTLink *linkToCheck,
                                       OTListSearchUPP userUPP)
  {
    return (*userUPP)(ref, linkToCheck);
  }
#else
#define InvokeOTListSearchUPP(ref, linkToCheck, userUPP) \
  (*userUPP)(ref, linkToCheck)
#endif
#endif

  struct OTList
  {
    OTLink *fHead;

#ifdef __cplusplus
    // C++ inline methods on this structure.

    void Init();
    Boolean IsEmpty();
    void AddFirst(OTLink *link);
    void AddLast(OTLink *link);
    OTLink *GetFirst();
    OTLink *GetLast();
    OTLink *RemoveFirst();
    OTLink *RemoveLast();
    Boolean IsInList(OTLink *link);
    OTLink *FindLink(OTListSearchUPP proc, const void *ref);
    Boolean RemoveLink(OTLink *link);
    OTLink *FindAndRemoveLink(OTListSearchUPP proc, const void *ref);
    OTLink *GetIndexedLink(OTItemCount index);
#endif
  };
  typedef struct OTList OTList;
  /* Add the link to the list at the front*/
  EXTERN_API_C(void)
  OTAddFirst(OTList *list, OTLink *link);

  /* Add the link to the list at the end*/
  EXTERN_API_C(void)
  OTAddLast(OTList *list, OTLink *link);

  /* Remove the first link from the list*/
  EXTERN_API_C(OTLink *)
  OTRemoveFirst(OTList *list);

  /* Remove the last link from the list*/
  EXTERN_API_C(OTLink *)
  OTRemoveLast(OTList *list);

  /* Return the first link from the list*/
  EXTERN_API_C(OTLink *)
  OTGetFirst(OTList *list);

  /* Return the last link from the list*/
  EXTERN_API_C(OTLink *)
  OTGetLast(OTList *list);

  /* Return true if the link is present in the list*/
  EXTERN_API_C(Boolean)
  OTIsInList(OTList *list, OTLink *link);

  EXTERN_API_C(OTLink *)
  OTFindLink(OTList *list, OTListSearchUPP proc, const void *ref);

  /* Remove the specified link from the list, returning true if it was found*/
  EXTERN_API_C(Boolean)
  OTRemoveLink(OTList *list, OTLink *link);

  /* Similar to OTFindLink, but it also removes it from the list.*/
  EXTERN_API_C(OTLink *)
  OTFindAndRemoveLink(OTList *list, OTListSearchUPP proc, const void *ref);

  /* Return the "index"th link in the list*/
  EXTERN_API_C(OTLink *)
  OTGetIndexedLink(OTList *list, OTItemCount index);

  /* OTEnqueue/OTDequeue*/

  EXTERN_API_C(void)
  OTEnqueue(void **listHead, void *object, OTByteCount linkOffset);

  EXTERN_API_C(void *)
  OTDequeue(void **listHead, OTByteCount linkOffset);

#ifdef __cplusplus
  // C++ inline methods on this structure.

  inline void OTList::Init() { fHead = NULL; }
  inline Boolean OTList::IsEmpty() { return fHead == NULL; }
  inline void OTList::AddFirst(OTLink *link) { OTAddFirst(this, link); }
  inline void OTList::AddLast(OTLink *link) { OTAddLast(this, link); }
  inline OTLink *OTList::GetFirst() { return OTGetFirst(this); }
  inline OTLink *OTList::GetLast() { return OTGetLast(this); }
  inline OTLink *OTList::RemoveFirst() { return OTRemoveFirst(this); }
  inline OTLink *OTList::RemoveLast() { return OTRemoveLast(this); }
  inline Boolean OTList::IsInList(OTLink *link) { return OTIsInList(this, link); }
  inline OTLink *OTList::FindLink(OTListSearchUPP proc, const void *ref)
  {
    return OTFindLink(this, proc, ref);
  }
  inline Boolean OTList::RemoveLink(OTLink *link)
  {
    return OTRemoveLink(this, link);
  }
  inline OTLink *OTList::FindAndRemoveLink(OTListSearchUPP proc,
                                           const void *ref)
  {
    return OTFindAndRemoveLink(this, proc, ref);
  }
  inline OTLink *OTList::GetIndexedLink(OTItemCount index)
  {
    return OTGetIndexedLink(this, index);
  }
#endif

  /* Atomic Operations*/

#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTAtomicSetBit(__A0, __D0)
#endif
  EXTERN_API_C(Boolean)
  OTAtomicSetBit(UInt8 *bytePtr, OTByteCount bitNumber)
      FOURWORDINLINE(0x01D0, 0x56C0, 0x7201, 0xC081);

#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTAtomicClearBit(__A0, __D0)
#endif
  EXTERN_API_C(Boolean)
  OTAtomicClearBit(UInt8 *bytePtr, OTByteCount bitNumber)
      FOURWORDINLINE(0x0190, 0x56C0, 0x7201, 0xC081);

#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTAtomicTestBit(__A0, __D0)
#endif
  EXTERN_API_C(Boolean)
  OTAtomicTestBit(UInt8 *bytePtr, OTByteCount bitNumber)
      FOURWORDINLINE(0x0110, 0x56C0, 0x7201, 0xC081);

#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTCompareAndSwapPtr(__D0, __D1, __A0)
#endif
  EXTERN_API_C(Boolean)
  OTCompareAndSwapPtr(void *oldValue, void *newValue, void **dest)
      FIVEWORDINLINE(0x0ED0, 0x0040, 0x57C0, 0x7201, 0xC081);

#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTCompareAndSwap32(__D0, __D1, __A0)
#endif
  EXTERN_API_C(Boolean)
  OTCompareAndSwap32(UInt32 oldValue, UInt32 newValue, UInt32 *dest)
      FIVEWORDINLINE(0x0ED0, 0x0040, 0x57C0, 0x7201, 0xC081);

#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTCompareAndSwap16(__D0, __D1, __A0)
#endif
  EXTERN_API_C(Boolean)
  OTCompareAndSwap16(UInt32 oldValue, UInt32 newValue, UInt16 *dest)
      FIVEWORDINLINE(0x0CD0, 0x0040, 0x57C0, 0x7201, 0xC081);

#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTCompareAndSwap8(__D0, __D1, __A0)
#endif
  EXTERN_API_C(Boolean)
  OTCompareAndSwap8(UInt32 oldValue, UInt32 newValue, UInt8 *dest)
      FIVEWORDINLINE(0x0AD0, 0x0040, 0x57C0, 0x7201, 0xC081);

#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTAtomicAdd32(__D0, __A0)
#endif
  EXTERN_API_C(SInt32)
  OTAtomicAdd32(SInt32 toAdd, SInt32 *dest)
      SEVENWORDINLINE(0x2240, 0x2210, 0x2001, 0xD089, 0x0ED0, 0x0001, 0x66F4);

  EXTERN_API_C(SInt16)
  OTAtomicAdd16(SInt32 toAdd, SInt16 *dest);

  /* Not used frequently enough to justify inlining.*/
  EXTERN_API_C(SInt8)
  OTAtomicAdd8(SInt32 toAdd, SInt8 *dest);

  /* Not used frequently enough to justify inlining.*/
  /* OTLock is just a convenience type with some convenient macros.*/

  typedef UInt8 OTLock;

#define OTClearLock(lockPtr) *(lockPtr) = 0
#define OTAcquireLock(lockPtr) (OTAtomicSetBit(lockPtr, 0) == 0)

  /*******************************************************************************
  **
  ** FROM HERE ON DOWN ARE THE C++ Interfaces to Open Transport
  **
  ********************************************************************************/

#ifdef __cplusplus
} // Terminate C definitions

/* -------------------------------------------------------------------------
 CLASS TProvider

 This class provides the client interface to a Stream. Typically, clients
 talk to an object (or glue code in front of the object) that is a subclass
 of TProvider.
 ------------------------------------------------------------------------- */

#if !OTKERNEL

class TProvider
{
private:
  void *operator new(size_t);
  void operator delete(void *) {}

  //
  // This is the public interface to a TProvider. All other public
  // methods normally come from the subclass.
  //
public:
  OSStatus Close() { return OTCloseProvider(this); }

  OSStatus SetNonBlocking() { return OTSetNonBlocking(this); }
  OSStatus SetBlocking() { return OTSetBlocking(this); }
  Boolean IsBlocking() { return OTIsBlocking(this); }
  Boolean IsNonBlocking() { return !OTIsBlocking(this); }
  OSStatus SetSynchronous() { return OTSetSynchronous(this); }
  OSStatus SetAsynchronous() { return OTSetAsynchronous(this); }
  Boolean IsSynchronous() { return OTIsSynchronous(this); }
  Boolean IsAsynchronous() { return !OTIsSynchronous(this); }

  OSStatus AckSends() { return OTAckSends(this); }
  OSStatus DontAckSends() { return OTDontAckSends(this); }
  Boolean IsAckingSends() { return OTIsAckingSends(this); }

  void CancelSynchronousCalls(OSStatus err)
  {
    (void)OTCancelSynchronousCalls(this, err);
  }

  OSStatus InstallNotifier(OTNotifyUPP proc, void *ptr)
  {
    return OTInstallNotifier(this, proc, ptr);
  }

  OSStatus UseSyncIdleEvents() { return OTUseSyncIdleEvents(this, true); }

  OSStatus DontUseSyncIdleEvents() { return OTUseSyncIdleEvents(this, false); }

  void RemoveNotifier() { OTRemoveNotifier(this); }

  Boolean EnterNotifier() { return OTEnterNotifier(this); }

  void LeaveNotifier() { OTLeaveNotifier(this); }

#if CALL_NOT_IN_CARBON
  OTPortRef GetOTPortRef() { return OTGetProviderPortRef(this); }

  ProviderRef TransferOwnership(OTClient prevOwner, OSStatus *errPtr)
  {
    return OTTransferProviderOwnership(this, prevOwner, errPtr);
  }
#endif

  SInt32 Ioctl(UInt32 cmd, void *data) { return OTIoctl(this, cmd, data); }
  SInt32 Ioctl(UInt32 cmd, long data)
  {
    return OTIoctl(this, cmd, (void *)data);
  }

#if CALL_NOT_IN_CARBON
  OTResult GetMessage(strbuf *ctlbuf, strbuf *databuf, OTFlags *flagPtr)
  {
    return OTGetMessage(this, ctlbuf, databuf, flagPtr);
  }
  OTResult GetPriorityMessage(strbuf *ctlbuf, strbuf *databuf, OTBand *bandPtr,
                              OTFlags *flagPtr)
  {
    return OTGetPriorityMessage(this, ctlbuf, databuf, bandPtr, flagPtr);
  }
  OSStatus PutMessage(const strbuf *ctlbuf, const strbuf *databuf,
                      OTFlags flags)
  {
    return OTPutMessage(this, ctlbuf, databuf, flags);
  }
  OSStatus PutPriorityMessage(const strbuf *ctlbuf, const strbuf *databuf,
                              OTBand band, OTFlags flags)
  {
    return OTPutPriorityMessage(this, ctlbuf, databuf, band, flags);
  }
#endif
};

/* -------------------------------------------------------------------------
 Class TEndpoint

 This class is the interface to all TPI modules, which constitute the
 vast majority of protocols, with the exception of link-layer protocols.
 ------------------------------------------------------------------------- */

class TEndpoint : public TProvider
{
public:
  //
  // Miscellaneous informative functions
  //
  OSStatus GetEndpointInfo(TEndpointInfo *info)
  {
    return OTGetEndpointInfo(this, info);
  }

  OSStatus GetProtAddress(TBind *boundAddr, TBind *peerAddr)
  {
    return OTGetProtAddress(this, boundAddr, peerAddr);
  }

  OSStatus ResolveAddress(TBind *reqAddr, TBind *retAddr, OTTimeout timeout)
  {
    return OTResolveAddress(this, reqAddr, retAddr, timeout);
  }

  OTResult GetEndpointState() { return OTGetEndpointState(this); }

  OTResult Look() { return OTLook(this); }

#if CALL_NOT_IN_CARBON
  OTResult Sync() { return OTSync(this); }
#endif
  //
  // Allocating structures
  //
  void *AllocInContext(OTStructType structType, UInt32 fields,
                       OSStatus *err = NULL,
                       OTClientContextPtr clientContext = NULL)
  {
    return OTAllocInContext(this, structType, fields, err, clientContext);
  }

  void *Alloc(OTStructType structType, UInt32 fields, OSStatus *err = NULL)
  {
#if TARGET_API_MAC_CARBON
    return OTAllocInContext(this, structType, fields, err, NULL);
#else
    return OTAlloc(this, structType, fields, err);
#endif
  };

  OTResult Free(void *ptr, OTStructType structType)
  {
    return OTFree(ptr, structType);
  }
  //
  // Option Management
  //
  OSStatus OptionManagement(TOptMgmt *req, TOptMgmt *ret)
  {
    return OTOptionManagement(this, req, ret);
  }
  //
  // Bind/Unbind
  //
  OSStatus Bind(TBind *reqAddr, TBind *retAddr)
  {
    return OTBind(this, reqAddr, retAddr);
  }

  OSStatus Unbind() { return OTUnbind(this); }
  //
  // Connection creation and tear-down
  //
  OSStatus Connect(TCall *sndCall, TCall *rcvCall)
  {
    return OTConnect(this, sndCall, rcvCall);
  }

  OSStatus RcvConnect(TCall *call) { return OTRcvConnect(this, call); }

  OSStatus Listen(TCall *call) { return OTListen(this, call); }

  OSStatus Accept(EndpointRef resRef, TCall *call)
  {
    return OTAccept(this, resRef, call);
  }

  OSStatus SndDisconnect(TCall *call) { return OTSndDisconnect(this, call); }

  OSStatus SndOrderlyDisconnect() { return OTSndOrderlyDisconnect(this); }

  OSStatus RcvDisconnect(TDiscon *discon)
  {
    return OTRcvDisconnect(this, discon);
  }

  OSStatus RcvOrderlyDisconnect() { return OTRcvOrderlyDisconnect(this); }
  //
  // Connection-oriented data transfer
  //
  OTResult Snd(void *buf, OTByteCount nbytes, OTFlags flags)
  {
    return OTSnd(this, buf, nbytes, flags);
  }

  OTResult Rcv(void *buf, OTByteCount nbytes, OTFlags *flagP)
  {
    return OTRcv(this, buf, nbytes, flagP);
  }
  //
  // Non-connection-oriented data transfer
  //
  OSStatus SndUData(TUnitData *udata) { return OTSndUData(this, udata); }

  OSStatus RcvUData(TUnitData *udata, OTFlags *flagP)
  {
    return OTRcvUData(this, udata, flagP);
  }

  OSStatus RcvUDErr(TUDErr *uderr) { return OTRcvUDErr(this, uderr); }

#if CALL_NOT_IN_CARBON
  //
  // Connection-oriented transactions
  //
  OSStatus SndRequest(TRequest *req, OTFlags reqFlags)
  {
    return OTSndRequest(this, req, reqFlags);
  }

  OSStatus RcvReply(TReply *reply, OTFlags *replyFlags)
  {
    return OTRcvReply(this, reply, replyFlags);
  }

  OSStatus SndReply(TReply *reply, OTFlags flags)
  {
    return OTSndReply(this, reply, flags);
  }

  OSStatus RcvRequest(TRequest *req, OTFlags *flags)
  {
    return OTRcvRequest(this, req, flags);
  }

  OSStatus CancelRequest(OTSequence seq) { return OTCancelRequest(this, seq); }

  OSStatus CancelReply(OTSequence seq) { return OTCancelReply(this, seq); }
  //
  // Non-connection-oriented transactions
  //
  OSStatus SndURequest(TUnitRequest *req, OTFlags reqFlags)
  {
    return OTSndURequest(this, req, reqFlags);
  }

  OSStatus RcvUReply(TUnitReply *reply, OTFlags *replyFlags)
  {
    return OTRcvUReply(this, reply, replyFlags);
  }

  OSStatus SndUReply(TUnitReply *reply, OTFlags flags)
  {
    return OTSndUReply(this, reply, flags);
  }

  OSStatus RcvURequest(TUnitRequest *req, OTFlags *flags)
  {
    return OTRcvURequest(this, req, flags);
  }

  OSStatus CancelURequest(OTSequence seq)
  {
    return OTCancelURequest(this, seq);
  }

  OSStatus CancelUReply(OTSequence seq) { return OTCancelUReply(this, seq); }
#endif
  //
  // Miscellaneous functions
  //
  OTResult CountDataBytes(OTByteCount *countPtr)
  {
    return OTCountDataBytes(this, countPtr);
  }
};

/* -------------------------------------------------------------------------
 CLASS TMapper

 This class is the interface to naming protocols.
 ------------------------------------------------------------------------- */

class TMapper : public TProvider
{
public:
  OSStatus RegisterName(TRegisterRequest *req, TRegisterReply *reply)
  {
    return OTRegisterName(this, req, reply);
  }

  OSStatus DeleteName(TNetbuf *name) { return OTDeleteName(this, name); }

  OSStatus DeleteName(OTNameID theID) { return OTDeleteNameByID(this, theID); }

  OSStatus LookupName(TLookupRequest *req, TLookupReply *reply)
  {
    return OTLookupName(this, req, reply);
  }
};

#endif /* !OTKERNEL */

extern "C"
{      // resume C definitions
#endif /* __cplusplus */

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma pop
#endif

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

#endif /* __OPENTRANSPORT__ */
