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

  // ***** Setup Default Compiler Variables *****
  /**
     OTKERNEL is used to indicate whether the code is being built
     for the kernel environment.  It defaults to 0.  If you include
     "OpenTransportKernel.h" before including this file,
     it will be 1 and you will only be able to see stuff available
     to kernel code.
  */

#ifndef OTKERNEL
#define OTKERNEL 0
#endif // !defined(OTKERNEL) 
/**// !defined(OTKERNEL) 
   OTUNIXERRORS determines whether this file defines a bunch of
   common UNIX error codes, like EPERM.  Typically, client code does
   not want to do this because of the possibility of a clash with
   other code modules, like the standard C libraries, that also
   defines these routines.  However, client code can turn it on to
   get these definitions.  This might be done by protocol stack
   infrastructure, or some other low-level code.
   "OpenTransportKernel.i" sets this flag before include
   "OpenTransport.h" because kernel modules typically need these
   error codes.  Note that kernel modules shouldn't be including
   standard C libraries, so this is rarely a problem.
   In general, the clash between OT and standard C definitions
   of these error codes is rarely a problem becasue both OT
   and the C libraries define them to have the same value.  But
   I'm sure this check is useful to some people.
*/
#ifndef OTUNIXERRORS
#define OTUNIXERRORS 0
#endif // !defined(OTUNIXERRORS) 
/**
   OTDE// !defined(OTUNIXERRORS) 
   macros.  If you set it to non-zero, the macros will generate code
   that drops you into the debugger.  If you set it to 0, or leave it
   undefined, the macros are compiled out.
   Setting up this compiler variable is a little tricky because previous
   versions of the OT interfaces used a different variable, qDebug.
   We replaced qDebug with OTDEBUG because qDebug does not fit into
   the OT namespace.  But I didn't want to break a lot of currently
   building code.  The following tricky compiler variable footwork
   avoids this.
   There are four outcomes when this code is compiled, depending on
   whether qDebug and OTDEBUG are defined beforehand.  The following
   table shows the outcome in each case.
   qDebug     OTDEBUG    Outcome       Explanation
   ------     -------    -------       -----------
   defined    defined    OTDEBUG wins  Mixed legacy and new code, we believe the
   new code. defined    undefined  qDebug wins   Legacy code. undefined  defined
   OTDEBUG wins  New code. undefined  undefined  no debugging  No debugging.
*/
#ifdef qDebug
#ifndef OTDEBUG
#define OTDebug qDebug
#endif // !defined(OTDEBUG) 
#endif // defined(qDebug) 
#ifndef OTDEBUG
#define// !defined(OTDEBUG) 
#endif // !defined(OTDEBUG) 
// Carb// defined(qDebug) 
#define OTCARBONAPPLICATION 0
#endif // !defined(OTCARBONAPPLICATION) 
  /**
     **// !defined(OTDEBUG) 
     Define special types that handle the difference in parameter passing
// Carbon Applications have some restrictions on using OT
     exports C calling conventions routines, and various C compilers use
     various different conventions.  Differences in the placement of the result
     ar// !defined(OTCARBONAPPLICATION) 
     difference is how the compilers pass integer parameters less than 32 bits.
     The MPW compiler always extends these to 32 bits; other compilers simply
     push a value of the appropriate size.  We overcome this difference by
     defining special OTFooParam types, which are only used when passing
     sub 32 bit values to routines.  They are always defined to a 32 bit
     size, which makes all the compilers do the same thing.
     One weird consequence of this is that in more strict type checking
     languages (eg Pascal) OTBooleanParam is not compatible with Boolean.
     Sorry.
  */

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
#endif // TARGET_CPU_68K 
#if defined(__MWERKS__) || defined(THINK_C) || defined(SYMANTEC_CPLUS) || \
    defined(SYMANTEC_C) || defined(__xlc) || defined(__xlC) ||            \
    defined(__xlC__)
  typedef ByteCount OTByteCount;
  typedef ItemCount OTItemCount;
  typedef SInt32 OTInt32;
  typedef UInt32 OTUInt32;
#else// TARGET_CPU_68K 
typedef unsigned int OTByteCount;
typedef unsigned int OTItemCount;
typedef int OTInt32;
typedef unsigned int OTUInt32;
#endif

  // ***** C++ Support *****
  /**
     Setup _MDECL to be _cdecl when compiling C++ code with
     compilers that support it, or nothing otherwise.
  */

#define _MDECL
#if defined(__SC__) || defined(THINK_CPLUS) || defined(__MRC__)
#ifdef __cplusplus
#u// ***** C++ Support *****
#define _MDECL _cdecl
#endif
#endif

  // ***** Shared Library Prefixes *****
#define kOTLibraryVersion "1.1"

#define kOTLibraryPrefix "OTLib$"
#define kOTModulePrefix "OTModl$"
#define kOTClientPrefix "OTClnt$"
#define kOTKernelPrefix "OTKrnl$"

  enum
  {
  // ***** Shared Library Prefixes *****
  };

  // ***** Miscellaneous Type Definitions *****
  // A millisecond timeout value  typedef UInt32 OTTimeout;
  // An ID number in connections/transactions       typedef SInt32 OTSequence;
  // An ID number for registered names              typedef SInt32 OTNameID;
  /**
     A protocol-specific reason code for failure.
     Usually a Unix-style positive error code.
  */
  typedef SInt32 OTReason;
  // Number of outstanding connection requests at a time.  typedef UInt32 OTQLen;
  // Will become internationalizeable shortly (yeah, right).  typedef UInt8 *OTClientName;
  // ***** Miscellaneous Type Definitions *****
  // value describing a client  typedef struct OpaqueOTClient *OTClient;
// A millisecond timeout value
/**
  // An ID number in connections/transactions     
    macro so as to avoid including <stddef.h>.
*/// An ID number for registered names            
#define OTOffsetOf(structure, field) ((ByteCount) & ((structure *)0)->field)

  // ***** Debugging Macros *****
#define kOTFatalErr "FB "
#define kOTNonfatalErr "NB "
#define kOTExtFatalErr "FX "
#d// Number of outstanding connection requests at a time.
#define kOTUserFatalErr "UF "
#d// Will become internationalizeable shortly (yeah, right).
#define kOTUserNonfatalErr "UE "
#d// The command code in STREAMS messages.
#define kOTInfoBreak "IN "
// value describing a client
#if CALL_NOT_IN_CARBON
  /**
   *  OTDebugStr()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
  // ***** Debugging Macros *****
  void
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
#endif // qDebug > 0 
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
#endif // qDebug > 1 || qDebug2 > 1 
#endif // CALL_NOT_IN_CARBON 
  /**
     ***** Flags Used When Opening Providers *****
     Important
     OT does not currently support any of these flags.  You should
     always pass 0 to a parameter of type OTOpenFlags.  If you need
     to modify the mode of operation of a provider, use OTSetBlocking,
     OTSetSynchronous, etc.
  */// qDebug > 0 
  typedef UInt32 OTOpenFlags;
  enum
  {
    kO_ASYNC = 0x01,
    kO_NDELAY = 0x04,
    kO_NONBLOCK = 0x04
  };

#if CALL_NOT_IN_CARBON
  /**
     BSD defines O_ASYNC, O_NDELAY and O_NONBLOCK in fcntl.h
     Us// qDebug > 1 || qDebug2 > 1 
     value in Carbon
  */// CALL_NOT_IN_CARBON 
  enum
  {
    O_ASYNC = kO_ASYNC,
    O_NDELAY = kO_NDELAY,
    O_NONBLOCK = kO_NONBLOCK
  };

#endif // CALL_NOT_IN_CARBON 
  // ***** UNIX-Style Error Codes *****
  typedef UInt16 OTUnixErr;
/**
   These definitions are only compiled if you're building kernel code
   or you explicit request them by setting OTUNIXERRORS.  See the
   description of these compiler variables, given above.
*/
#if OTKERNEL || OTUNIXERRORS
  /**
     There may be some error code confusions with other compiler vendor header
     files - However, these match both MPW and AIX definitions.
  */
  /**
     First we undefine the #defined ones we know about so that we can put them
     in an enum.  Of course, this is only going to work in C, but hopefully
     other languages won't have these symbols overloaded.
  */

#undef EPERM
#undef ENOENT
#undef ENORSRC
#undef EINTR
#undef // CALL_NOT_IN_CARBON 
#undef ENXIO
#u// ***** UNIX-Style Error Codes *****
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
    EPERM = 1,        // Permission denied                ENOENT = 2,       // No such file or directory           ENORSRC = 3,      // No such resource                   EINTR = 4,        // Interrupted system service            EIO = 5,          // I/O error                     ENXIO = 6,        // No such device or address           EBADF = 9,        // Bad file number                     EAGAIN = 11,      // Try operation again later           ENOMEM = 12,      // Not enough space                   EACCES = 13,      // Permission denied                EFAULT = 14,      // Bad address                       EBUSY = 16,       // Device or resource busy              EEXIST = 17,      // File exists                       ENODEV = 19,      // No such device                   EINVAL = 22,      // Invalid argument                   ENOTTY = 25,      // Not a character device              EPIPE = 32,       // Broken pipe                       ERANGE = 34,      // Math result not representable       EDEADLK = 35,     // Call would block so was aborted           EWOULDBLOCK = 35, // Or a deadlock would occur           EALREADY = 37,
    ENOTSOCK = 38,        // Socket operation on non-socket         EDESTADDRREQ = 39,    // Destination address required          EMSGSIZE = 40,        // Message too long                   EPROTOTYPE = 41,      // Protocol wrong type for socket         ENOPROTOOPT = 42,     // Protocol not available              EPROTONOSUPPORT = 43, // Protocol not supported              ESOCKTNOSUPPORT = 44, // Socket type not supported           EOPNOTSUPP = 45,      // Operation not supported on socket      EADDRINUSE = 48,      // Address already in use              EADDRNOTAVAIL = 49,   // Can't assign requested address         ENETDOWN = 50,        // Network is down                     ENETUNREACH = 51,     // Network is unreachable              ENETRESET = 52,       // Network dropped connection on reset        ECONNABORTED = 53,    // Software caused connection abort         ECONNRESET = 54,      // Connection reset by peer              ENOBUFS = 55,         // No buffer space available           EISCONN = 56,         // Socket is already connected             ENOTCONN = 57,        // Socket is not connected              ESHUTDOWN = 58,       // Can't send after socket shutdown         ETOOMANYREFS = 59,    // Too many references: can't splice      ETIMEDOUT = 60,       // Connection timed out                 ECONNREFUSED = 61,    // Connection refused               EHOSTDOWN = 64,       // Host is down                    EHOSTUNREACH = 65,    // No route to host                   EPROTO = 70,          // STREAMS protocol error              ETIME = 71,
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

#endif // OTKERNEL || OTUNIXERRORS 
  // ***** Open Transport/XTI Error codes *****  typedef UInt16 OTXTIErr;
  enum
  {
    TSUCCESS = 0,       // No Error occurred                 TBADADDR = 1,       // A Bad address was specified              TBADOPT = 2,        // A Bad option was specified              TACCES = 3,         // Missing access permission              TBADF = 4,          // Bad provider reference               TNOADDR = 5,        // No address was specified                 TOUTSTATE = 6,      // Call issued in wrong state              TBADSEQ = 7,        // Sequence specified does not exist       TSYSERR = 8,        // A system error occurred                  TLOOK = 9,          // An event occurred - call Look()             TBADDATA = 10,      // An illegal amount of data was specified        TBUFOVFLW = 11,     // Passed buffer not big enough              TFLOW = 12,         // Provider is flow-controlled              TNODATA = 13,       // No data available for reading           TNODIS = 14,        // No disconnect indication available         TNOUDERR = 15,      // No Unit Data Error indication available        TBADFLAG = 16,      // A Bad flag value was supplied           TNOREL = 17,        // No orderly release indication available        TNOTSUPPORT = 18,   // Command is not supported                 TSTATECHNG = 19,    // State is changing - try again later           TNOSTRUCTYPE = 20,  // Bad structure type requested for OTAlloc       TBADNAME = 21,      // A bad endpoint name was supplied          TBADQLEN = 22,      // A Bind to an in-use address with qlen > 0    TADDRBUSY = 23,     // Address requested is already in use           TINDOUT = 24,       // Accept failed because of pending listen        TPROVMISMATCH = 25, // Tried to accept on incompatible endpoint       TRESQLEN = 26,
    TRESADDR = 27,
    TQFULL = 28,
    TPROTO = 29,    // An unspecified provider error occurred     TBADSYNC = 30,  // A synchronous call at interrupt time         TCANCELED = 31, // The command was cancelled              TLASTXTIERROR = 31
  };

  /**
     ***** Mac OS Error Codes *****
     Most OT client ro// Permission denied            
     defined in "MacTy// No such file or directory       
     defined below.  M// No such resource               
     codes (Txxxx) and// Interrupted system service        
     in the OSStatus s// I/O error                 
     Some routines ret// No such device or address       
     that the routine // Bad file number                 
     or possible retur// Try operation again later       
  */// Not enough space               
// Permission denied            
  typedef SInt32 OTRes// Bad address                   
// Device or resource busy          
/**// File exists                   
 * These map the Open // No such device               
 * StdCLib Exxxx error// Invalid argument               
 */// Not a character device          
#define XTI2OSStatus(x// Broken pipe                   
#define E2OSStatus(x) // Math result not representable   
// Call would block so was aborted       
#define OSStatus2XTI(x// Or a deadlock would occur       
#define OSStatus2E(x) ((OTUnixErr)(-3199 - (x)))
// Socket operation on non-socket     
#define IsXTIError(x) ((x)// Destination address required      
#define IsEError(x) ((x) <// Message too long               
// Protocol wrong type for socket     
  // ***** OTAddress *****// Protocol not available          
  /**// Protocol not supported          
     OTAddress type define// Socket type not supported       
     It consists of one 16// Operation not supported on socket  
     used, followed by an // Address already in use          
     Conceptually, all OT // Can't assign requested address     
     extended with fields // Network is down                 
     OTInetAddress starts // Network is unreachable          
     to include a host IP // Network dropped connection on reset    
  */// Software caused connection abort     
// Connection reset by peer          
  enum// No buffer space available       
  {// Socket is already connected         
    kOTGenericName = 0 /* // Socket is not connected          
                          // Can't send after socket shutdown     
  };// Too many references: can't splice  
// Connection timed out             
  typedef UInt16 OTAddress// Connection refused           
  struct OTAddress// Host is down                
  {// No route to host               
    OTAddressType fAddress// STREAMS protocol error          
  typedef struct OTAddress OTAddress;
  /**
     ***** OTAlloc Constants *****
     Note:
     In general, Apple recommends that you avoid the OTAlloc call because
     using it extensively causes your program to allocate and deallocate
     many memory blocks, with each extra memory allocation costing time.
  */
  /**
     OTStructType defines the structure type to be allocated using the OTAlloc
     call.
  */
  enum// OTKERNEL || OTUNIXERRORS 
  {
  // ***** Open Transport/XTI Error codes *****
    T_OPTMGMT = 2,
    T_CALL = 3,
    T_DIS = 4,
    T_UNITDATA = 5,// No Error occurred             
    T_UDERROR = 6,// A Bad address was specified          
    T_INFO = 7,// A Bad option was specified          
    T_REPLYDATA = 8,// Missing access permission          
    T_REQUESTDATA = 9,// Bad provider reference           
    T_UNITREQUEST = 10,// No address was specified             
    T_UNITREPLY = 11// Call issued in wrong state          
  };// Sequence specified does not exist   
// A system error occurred              
  typedef UInt32 OTStruc// An event occurred - call Look()         
  /**// An illegal amount of data was specified    
     These values are us// Passed buffer not big enough          
     to define which fie// Provider is flow-controlled          
  */// No data available for reading       
  enum// No disconnect indication available     
  {// No Unit Data Error indication available    
    T_ADDR = 0x01,// A Bad flag value was supplied       
    T_OPT = 0x02,// No orderly release indication available    
    T_UDATA = 0x04,// Command is not supported             
    T_ALL = 0xFFFF// State is changing - try again later       
  };// Bad structure type requested for OTAlloc   
// A bad endpoint name was supplied      
  typedef UInt32 OTField// A Bind to an in-use address with qlen > 0
  // ***** OTFlags *****// Address requested is already in use       
     This type is used t// Accept failed because of pending listen    
     and parameters.  Th// Tried to accept on incompatible endpoint   
     type in "MacTypes.h".
  */

  typedef UInt32 OTF// An unspecified provider error occurred 
  /**// A synchronous call at interrupt time     
     These flags are// The command was cancelled          
     constants defined are masks.
  */
  enum
  {
    T_MORE = 0x0001,         // More data to come in message         T_EXPEDITED = 0x0002,    // Data is expedited, if possible     T_ACKNOWLEDGED = 0x0004, // Acknowledge transaction             T_PARTIALDATA = 0x0008,  // Partial data - more coming         T_NORECEIPT = 0x0010,    // No event on transaction done         T_TIMEDOUT = 0x0020      // Reply timed out                };

  // These flags are used in the TOptMgmt structure to request services.
  enum
  {
    T_NEGOTIATE = 0x0004,
    T_CHECK = 0x0008,
    T_DEFAULT = 0x0010,
    T_CURRENT = 0x0080
  };

  /**
     These flags are used in the TOptMgmt and TOption structures to
     return results.
  */

  enum
  {
    T_SUCCESS = 0x0020,
    T_FAILURE = 0x0040,
    T_PARTSUCCESS = 0x0100,
    T_READONLY = 0x0200,
    T_NOTSUPPORT = 0x0400
  };

  /**
  // ***** OTAddress *****
     A band is a STREAMS concepts which defines the priority of data
     on a stream.  Although this type is defined as a 32 bit number
     for efficiency's sake, bands actually only range from 0 to 255.
     Typically band 0 is used for normal data and band 1 for expedited data.
  */
  typedef UInt32 OTBand;
// ***** Object References *****/**
   This deserves some explanation.  If you're compiling for
   C++, the C++ definitions of TEndpoint and TMapper at the
   end of this file are invoked, which lets the compiler
   know that they are both subclasses of TProvider.  This
   way the compiler will do the right subclass type checking,
   ie you will be able to pass an EndpointRef to a parameter
   of type ProviderRef, but not vice versa.
   On the other hand, if your compiling for straighth C,
   everything is defined as void.  This is somewhat dangerous,
   but it prevents you have to cast an EndpointRef to a
   ProviderRef every time you call a function that works
   on all forms of providers.
*/
#ifdef __cplusplus// The address format of this address...
  typedef class TProvider *Provi// ... followed by protocol specific address information.
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
  // ***** Event Codes *****  /**
     OT event codes values for Open Transport.  These are the event codes that
     are sent to notification routine (notifiers).
  */

  typedef UInt32 OTEventCode;
  /**
     Events are divided into numerous categories:

     1. (0x0000xxxx) The core XTI events have identifiers of the form
        T_XXXX.  These signal that an XTI event has occured on a stream.
     2. (0x1000xxxx) Private events are reserved for protocol specific
        events.  Each protocol stack defines them as appropriate for
        its own usage.
     3. (0x2000xxxxx) Completion events have identifiers of the form
        T_XXXXCOMPLETE.  These signal the completion of some asynchronous
        API routine, and are only delivered if the endpoint is in asynchronous
        mode.
     4. (0x2100xxxx) Stream events are generally encountered when programming
        the raw streams API and indicate some event on a raw stream, or
        some other event of interest in the STREAMS kernel.
     5. (0x2200xxxx) Signal events indicate that a signal has arrived on
        a raw stream.  See "Signal Values" for details.
     6. (0x2300xxxx) General provider events that might be generated by any
        provider.
     7. (0x2400xxxx) System events sent to all providers.
     8. (0x2500xxxx) System events sent to registered clients.
     9. (0x2600xxxx) System events used by configurators.
    10. (0x2700xxxx) Events sent to registered OT clients.
  */
  /**
  // ***** OTFlags *****
     an event code you do not understand, ignore it!
  */

  enum
  {
    T_LISTEN = 0x0001,                      // An connection request is available         T_CONNECT = 0x0002,                     // Confirmation of a connect request      T_DATA = 0x0004,                        // Standard data is available            T_EXDATA = 0x0008,                      // Expedited data is available             T_DISCONNECT = 0x0010,                  // A disconnect is available           T_ERROR = 0x0020,                       // obsolete/unused in library            T_UDERR = 0x0040,                       // A Unit Data Error has occurred         T_ORDREL = 0x0080,                      // An orderly release is available           T_GODATA = 0x0100,                      // Flow control lifted on standard data       T_GOEXDATA = 0x0200,                    // Flow control lifted on expedited data    T_REQUEST = 0x0400,                     // An Incoming request is available         T_REPLY = 0x0800,                       // An Incoming reply is available         T_PASSCON = 0x1000,                     // State is now T_DATAXFER              T_RESET = 0x2000,                       // Protocol has been reset              kPRIVATEEVENT = 0x10000000,             // Base of the private event range.    kCOMPLETEEVENT = 0x20000000,            // Base of the completion event range.    T_BINDCOMPLETE = 0x20000001,            // Bind call is complete              T_UNBINDCOMPLETE = 0x20000002,          // Unbind call is complete              T_ACCEPTCOMPLETE = 0x20000003,          // Accept call is complete              T_REPLYCOMPLETE = 0x20000004,           // SendReply call is complete            T_DISCONNECTCOMPLETE = 0x20000005,      // Disconnect call is complete             T_OPTMGMTCOMPLETE = 0x20000006,         // OptMgmt call is complete              T_OPENCOMPLETE = 0x20000007,            // An Open call is complete              T_GETPROTADDRCOMPLETE = 0x20000008,     // GetProtAddress call is complete     T_RESOLVEADDRCOMPLETE = 0x20000009,     // A ResolveAddress call is complet         T_GETINFOCOMPLETE = 0x2000000A,         // A GetInfo call is complete            T_SYNCCOMPLETE = 0x2000000B,            // A Sync call is complete              T_MEMORYRELEASED = 0x2000000C,          // No-copy memory was released             T_REGNAMECOMPLETE = 0x2000000D,         // A RegisterName call is complete           T_DELNAMECOMPLETE = 0x2000000E,         // A DeleteName call is complete       T_LKUPNAMECOMPLETE = 0x2000000F,        // A LookupName call is complete       T_LKUPNAMERESULT = 0x20000010,          // A LookupName is returning a name         kOTSyncIdleEvent = 0x20000011,          // Synchronous call Idle event             kSTREAMEVENT = 0x21000000,              // Base of the raw stream event range.    kOTReservedEvent1 = 0x21000001,         // reserved for internal use by OT           kGetmsgEvent = 0x21000002,              // A GetMessage call is complete       kStreamReadEvent = 0x21000003,          // A Read call is complete              kStreamWriteEvent = 0x21000004,         // A Write call is complete              kStreamIoctlEvent = 0x21000005,         // An Ioctl call is complete           kOTReservedEvent2 = 0x21000006,         // reserved for internal use by OT           kStreamOpenEvent = 0x21000007,          // An OpenStream call is complete         kPollEvent = 0x21000008,                // A Poll call is complete              kOTReservedEvent3 = 0x21000009,         // reserved for internal use by OT           kOTReservedEvent4 = 0x2100000A,         // reserved for internal use by OT           kOTReservedEvent5 = 0x2100000B,         // reserved for internal use by OT           kOTReservedEvent6 = 0x2100000C,         // reserved for internal use by OT           kOTReservedEvent7 = 0x2100000D,         // reserved for internal use by OT           kOTReservedEvent8 = 0x2100000E,         // reserved for internal use by OT           kSIGNALEVENT = 0x22000000,              /* A signal has arrived on a raw stream, see
                                               "Signal Values" below.*/
    kPROTOCOLEVENT = 0x23000000,            // Some event from the protocols       kOTProviderIsDisconnected = 0x23000001, // Provider is temporarily off-line     kOTProviderIsReconnected = 0x23000002,  // Provider is now back on-line          kOTProviderWillClose = 0x24000001,      // Provider will close immediately           kOTProviderIsClosed = 0x24000002,       // Provider was closed                  kOTPortDisabled =
        0x25000001, // Port is now disabled, result is 0, cookie is port ref     kOTPortEnabled =
        0x25000002, // Port is now enabled, result is 0, cookie is port ref     kOTPortOffline =
        0x25000003, // Port is now offline, result is 0, cookie is port ref     kOTPortOnline =
        0x25000004,                   // Port is now online, result is 0, cookie is port ref     kOTClosePortRequest = 0x25000005, /* Request to close/yield, result is reason,
                                         cookie is OTPortCloseStruct* */
    kOTYieldPortRequest = 0x2// More data to come in message     
                             // Data is expedited, if possible 
    kOTNewPortRegistered =// Acknowledge transaction         
        0x25000006,          // Partial data - more coming     
                             // No event on transaction done     
    kOTConfigurationChanged =// Reply timed out              
    kOTSystemShutdown = 0x26000003,
    kOTSystemAwaken = 0x26000004,
  // These flags are used in the TOptMgmt structure to request services.
    kOTSystemSleepPrep = 0x26000006,
    kOTSystemShutdownPrep = 0x26000007,
    kOTSystemAwakenPrep = 0x26000008,
    kOTStackIsLoading = 0x27000001, /* Sent before Open Transport attempts to load
                                       the TCP/IP protocol stack.*/
    kOTStackWasLoaded =
        0x27000002, // Sent after the TCP/IP stack has been successfully loaded.    kOTStackIsUnloading =
        0x27000003 // Sent before Open Transport unloads the TCP/IP stack.  };

  // ***** Event Classification Macros ***** 
#define IsOTPrivateEvent(x) (((x) & 0x70000000L) == kPRIVATEEVENT)
#define IsOTCompleteEvent(x) (((x) & 0x7f000000L) == kCOMPLETEEVENT)
#define IsOTProtocolEvent(x) (((x) & 0x7f000000L) == kPROTOCOLEVENT)
#define IsOTStreamEvent(x) (((x) & 0x7f000000L) == kSTREAMEVENT)
#define IsOTSignalEvent(x) (((x) & 0x7f000000L) == kSIGNALEVENT)
#define GetOTEventCode(x) (x)

  /**
     ***** Signal Values *****
     Signals that are generated by a raw stream.  When writing a notifier
     for a raw stream, add these values to kSIGNALEVENT to determine what
     event you are receiving.
  */

  enum
  {
    kSIGHUP = 1,
    kSIGURG = 16,
    kSIGPOLL = 30
  };

// ***** Object References *****
  {
    SIGHUP = kSIGHUP,
    SIGURG = kSIGURG,
    SIGPOLL = kSIGPOLL
  };

  /**
     ***** Notifier Type Definition *****
     Open Transport notifiers must conform to the OTNotifyProcPtr prototype.
     Even though a OTNotifyUPP is a OTNotifyProcPtr on pre-Carbon system,
     use NewOTNotifyUPP() and friends to make your source code portable to OS X
     and Carbon.
  */
  typedef CALLBACK_API(void, OTNotifyProcPtr)(void *contextPtr, OTEventCode code,
                                              OTResult result, void *cookie);
  typedef TVECTOR_UPP_TYPE(OTNotifyProcPtr) OTNotifyUPP;
  /**
   *  NewOTNotifyUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTNotifyUPP
  NewOTNotifyUPP(OTNotifyProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  // ***** Event Codes *****
  {
    uppOTNotifyProcInfo = 0x00003FC0
  }; // pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
  inline OTNotifyUPP NewOTNotifyUPP(OTNotifyProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewOTNotifyUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
   *  DisposeOTNotifyUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeOTNotifyUPP(OTNotifyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOTNotifyUPP(OTNotifyUPP) {}
#else
#define DisposeOTNotifyUPP(userUPP)
#endif
#endif

  /**
   *  InvokeOTNotifyUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */// An connection request is available     
  void// Confirmation of a connect request  
  InvokeOTNotifyUPP(void *contextPtr, OTEven// Standard data is available        
                    void *cookie, OTNotifyUP// Expedited data is available         
#if !OPAQUE_UPP_TYPES// A disconnect is available       
#ifdef __cplusplus// obsolete/unused in library        
  inline void InvokeOTNotifyUPP(void *contex// A Unit Data Error has occurred     
                                OTResult res// An orderly release is available       
                                OTNotifyUPP // Flow control lifted on standard data   
  {// Flow control lifted on expedited data
    (*userUPP)(contextPtr, code, result, coo// An Incoming request is available     
  }// An Incoming reply is available     
#else// State is now T_DATAXFER          
#define InvokeOTNotifyUPP(contextPtr, code, // Protocol has been reset          
  (*userUPP)(contextPtr, code, result, cooki// Base of the private event range.
#endif// Base of the completion event range.
#endif// Bind call is complete          
// Unbind call is complete          
  // ***** Option Management Definitions ***// Accept call is complete          
  {// SendReply call is complete        
    XTI_GENERIC = 0xFFFF // level for XTI op// Disconnect call is complete         
// OptMgmt call is complete          
  typedef UInt32 OTXTILevel;// An Open call is complete          
  // The XTI name of a protocol option.  typ// GetProtAddress call is complete 
  // XTI names for options used with XTI_GEN// A ResolveAddress call is complet     
  {// A GetInfo call is complete        
    XTI_DEBUG = 0x0001,// A Sync call is complete          
    XTI_LINGER = 0x0080,// No-copy memory was released         
    XTI_RCVBUF = 0x1002,// A RegisterName call is complete       
    XTI_RCVLOWAT = 0x1004,// A DeleteName call is complete   
    XTI_SNDBUF = 0x1001,// A LookupName call is complete   
    XTI_SNDLOWAT = 0x1003,// A LookupName is returning a name     
    XTI_PROTOTYPE = 0x1005,// Synchronous call Idle event         
    OPT_CHECKSUM = 0x0600,  // Set checksumm// Base of the raw stream event range.
        0x0604,                // Enable Sel// reserved for internal use by OT       
// A GetMessage call is complete   
// ***** Ioctl Definitions *****// A Read call is complete          
/**// A Write call is complete          
   All OT ioctl numbers are formed using the// An Ioctl call is complete       
   which divides the ioctl space by protocol// reserved for internal use by OT       
   first parameter) and ioctl number within // An OpenStream call is complete     
   space (the second parameter).  This macro// A Poll call is complete          
   to C users but it's relatively easy to sy// reserved for internal use by OT       
   results in other languages.// reserved for internal use by OT       
*/// reserved for internal use by OT       
#define MIOC_CMD(t, v) ((((t) & 0xFF) << 8) // reserved for internal use by OT       
// reserved for internal use by OT       
  // The following is a registry of the ioct// reserved for internal use by OT       
  enum
  {
    MIOC_STREAMIO = 'A',  // Basic Stream io// Some event from the protocols   
// Provider is temporarily off-line 
  // OT specific ioctls.// Provider is now back on-line      
  enum// Provider will close immediately       
  {// Provider was closed              
    I_OTGetMiscellaneousEvents =
        ((MIOC_OT <<// Port is now disabled, result is 0, cookie is port ref 
        (unsigned long)0xFFFFFFFF,         // Use this value to read framing            I_OTSetRawMode = ((MIOC_OT << 8) | 3), // Set raw mode for link                kOTSetRecvMode = 0x01,
    kOTSendErrorPack// Port is now enabled, result is 0, cookie is port ref 
    I_OTConnect = ((MIOC_OT << 8) | 4), // Generic connect request for links       I_OTDisconnect =
        ((MIOC_OT <<// Port is now offline, result is 0, cookie is port ref 

  // Structure for the I_OTScript Ioct// Port is now online, result is 0, cookie is port ref 
  struct OTScriptInfo
  {
    UInt32 fScriptType;
    void *fTheScript;
    UInt32 fScriptLength;
  };// New port has been registered, cookie is port ref 
  typedef struct OTScriptInfo OTScriptInfo;
  /**
     ***** XTI States *****// Protocol configuration changed     
     These are the potential values returned by OTGetEndpointState and OTSync
     which represent the XTI state of an endpoint.
  */
  typedef UInt32 OTXTIStates;
  enum
  {
    T_UNINIT = 0,   // addition to standard xti.h     T_UNBND = 1,    // unbound                     T_IDLE = 2,     // idle                    T_OUTCON = 3,   // outgoing connection pending        T_INCON = 4,    // incoming connection pending        T_DATAXFER = 5, // data transfer              T_OUTREL = 6,   // outgoing orderly release         T_INREL = 7     // incoming orderly release       };

  /**
     ***** General XTI Definitions *****
     These definitio// Sent after the TCP/IP stack has been successfully loaded.
  */
// Sent before Open Transport unloads the TCP/IP stack.
  enum
  {
  // ***** Event Classification Macros ***** 
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

  /**
     ***** OTConfiguration *****
     This is a "black box" structure used to define the configuration of a
     provider or endpoint.  This file defines a very limited set of operations
     on a configuration.  "OpenTransportClient.h" extends this with extra
     operations used by protocol stacks but not typically needed by clients.
  */

#ifdef __cplusplus
  typedef class OTConfiguration *OTConfigurationRef;
#else
typedef struct OTConfiguration *OTConfigurationRef;
#endif
#define kOTNoMemoryConfigurationPtr ((OTConfigurationRef)0L)
#define kOTInvalidConfigurationPtr ((OTConfigurationRef)-1L)
  // ***** Option Management Structures *****
  // This structure describes the contents of a single option in a buffer.
  struct TOptionHeader
  {
    ByteCount len;    // total length of option                                // = sizeof(TOptionHeader) + length                           //     of option value in bytes           OTXTILevel level; // protocol affected                OTXTIName name;   // option name                       UInt32 status;    // status value                  };
  typedef struct TOptionHeader TOptionHeader;
  /**
     This structure describes the contents of a single option in a buffer.
     It differs from TOptionHeader in that it includes the value field,
     which acts as an unbounded array representing the value of the option.
  */
  struct TOption
  {
    ByteCount len;    // total length of option                                // = sizeof(TOption) + length                       //     of option value in bytes           OTXTILevel level; // protocol affected                OTXTIName name;   // option name                       UInt32 status;    // status value                    UInt32 value[1];  // data goes here                 };
  typedef struct TOption TOption;
  // Some useful constants when manipulating option buffers.  enum
  {
    kOTOptionHeaderSize = sizeof(TOptionHeader),
    kOTBooleanOptionDataSize = sizeof(UInt32),
    kOTBooleanOptionSize = kOTOptionHeaderSize + kOTBooleanOptionDataSize,
    k// pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) 
    kOTTwoByteOptionSize = kOTOptionHeaderSize + 2,
    kOTFourByteOptionSize = kOTOptionHeaderSize + sizeof(UInt32)
  };

  /**
      This macro will align return the value of "len", rounded up to the next
      4-byte boundary.
  */

#define T_ALIGN(len) \
  (((UInt32)(len) + (sizeof(SInt32) - 1)) & ~(sizeof(SInt32) - 1))

  /**
     This macro will return the next option in the buffer, given the previous
    option in the buffer, returning NULL if there are no more. You start off by
    setting prevOption = (TOption*)theBuffer (Use OTNextOption for a more thorough
    check - it ensures the end of the option is in the buffer as well.)
  */

#define OPT_NEXTHDR(theBuffer, theBufLen, prevOption)                   \
  (((char *)(prevOption) + T_ALIGN((prevOption)->len) <                 \
    (char *)(theBuffer) + (theBufLen))                                  \
       ? (TOption *)((char *)(prevOption) + T_ALIGN((prevOption)->len)) \
       : (TOption *)NULL)

  // t_kpalive is used with OPT_KEEPALIVE option.
  struct t_kpalive
  {
    SInt32 kp_onoff;   // option on/off       SInt32 kp_timeout; // timeout in minutes   };
  typedef struct t_kpalive t_kpalive;
  // t_linger is used with XTI_LINGER option.  struct t_linger
  {
    SInt32 l_onoff;  // option on/off     SInt32 l_linger; // linger time   };
  typedef struct t_linger t_linger;
  /**
     ***** TEndpointInfo *****
     This structure is returned from the GetEndpointInfo call and contains
     information about an endpoint.  But first, some special flags and types.
  */
  // Values returned in servtype field of TEndpointInfo.
  typedef UInt32 OTServiceType;
  enum
  {
    T_COTS = 1,      // Connection-mode service                        T_COTS_ORD = 2,  // Connection service with orderly release              T_CLTS = 3,      // Connectionless-mode service                       T_TRANS = 5,     // Connection-mode transaction service                  T_TRANS_ORD = 6, // Connection transaction service with orderly release        T_TRANS_CLTS = 7 // Connectionless transaction service             };

  // Masks for the flags field of TEndpointInfo.
  enum
  {
    T_SENDZERO = 0x0001,              // supports 0-length TSDU's              T_XPG4_1 = 0x0002,                // supports the GetProtAddress call         T_CAN_SUPPORT_MDATA = 0x10000000, // support M_DATAs on packet protocols        T_CAN_RESOLVE_ADDR = 0x40000000,  // Supports ResolveAddress call          T_CAN_SUPPLY_MIB = 0x20000000     // Supports SNMP MIB data            };

  /**
     Special-case values for in the tsdu, etsdu, connect, and discon
     fields of TEndpointInfo.
  // ***** Option Management Definitions *****
// The XTI Level number of a protocol.
  enum
  {
    T_INFINITE = -1, // s// level for XTI options 

  typedef SInt32 OTDataSize;
  // Now the TEndpointInfo structure proper.  struct TEndpointInfo
  // The XTI name of a protocol option.
    OTDataSize addr;        // Maximum size of an address            OTDataSize options;     // Maximum size of options              OTDataSize tsdu;        // Standard data transmit unit size         OTDataSize etsdu;       // Expedited data transmit unit size      OTDataSize connect;     // Maximum data size on connect          OTDataSize discon;      // Maximum data size on disconnect           OTServiceType servtype; // service type                    UInt32 flags;           // Flags (see above for values)        };
  // XTI names for options used with XTI_GENERIC above
  /**
     "OpenTransport.h" no longer defines "struct t_info".  We recommend
     that you use TEndpointInfo instead.  If this is impossible, use
     the definition of "struct t_info" in "OpenTransportXTI.h".
  */
  // ***** OTPortRecord *****
  // Unique identifier for a port.
  typedef UInt32 OTPortRef;
  typedef OTPortRef *OTPortRefPtr;
  enum// Set checksumming = UInt32 - 0 or 1)
  {// Set a retry counter = UInt32 (0 = infinite)
    kOTInvalidPortRef = 0// Set a retry interval = UInt32 milliseconds
  };// Enable the EOM indication = UInt8 (0 or 1)

  // Valid values for the bus t// Enable Self-sending on broadcasts = UInt32 (0 or 1)
  typedef UInt8 OTBusType;// Set Server Status (format is proto dependent)
  enum// Enable/Disable protocol alerts
  {// See t_keepalive structure
    kOTUnknownBusPort = 0,
    kOTMotherboardBus = 1,
// ***** Ioctl Definitions *****
    kOTPCIBus = 3,
    kOTGeoPort = 4,
    kOTPCCardBus = 5,
    kOTFireWireBus = 6,
    kOTLastBusIndex = 15
  };

  /**
     A couple of special values for the device type element of an
     OTPortRef.  See "OpenTransportDevices.h" for the standard values.
  */
// The following is a registry of the ioctls protocol spaces.
  typedef UInt16 OTDeviceType;
  enum
  {
    kOTNoDeviceType = 0,// Basic Stream ioctl() cmds - I_PUSH, I_LOOK, etc. 
    kOTADEVDevice = 1,    // ioctl's for tmod test module    
  };// ioctl's for Mentat's log device      
// ioctl's for Mentat's nd device        
  // Special case values f// ioctl's for Mentat's echo device   
  enum// ioctl's for Mentat's timod module  
  {// reserved, used by SVR4 FIOxxx   
    kOTLastSlotNumber = 25// ioctl's for Mentat's sad module      
    kOTLastOtherNumber = 2// ioctl's for Mentat's arp module      
  };// Havoc module ioctls.           
// reserved, used by SVR4 SIOCxxx     
  typedef UInt16 OTSlotNum// sockio.h socket ioctl's           
  // Accessor functions fo// tcp.h ioctl's                
   *  OTCreatePortRef()// dlpi.h additions             
   *// Mentat sockmod ioctl's           
// ioctls for IPX               
   *    \non_carbon_cfm   // ioctls for Open Transport       
   *    \carbon_lib       // ioctl's for AppleTalk          
   *    \mac_os_x         // ioctl's for Serial           
   */// reserved, used by SVR4          
  OTPortRef// reserved, used by SVR4          
  OTCreatePortRef(OTBusTyp// reserved, used by SVR4          
                  UInt16 o// ioctl's for private configuration 

  /**
  // OT specific ioctls.
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and l// sign up for Misc Events              
   */// Set framing option for link 
  OTDeviceType
  OTGetDeviceTypeFromPortRef(OTPortRef ref)// Use this value to read framing        
// Set raw mode for link            
  /**
   *  OTGetBusTypeFromPortRef()
   *// Generic connect request for links   

   *    \non_carbon_cfm   in OTUtility// Generic disconnect request for links     
   *    \carbon_lib        in CarbonLi// Send a script to a module          
   *    \mac_os_x         in version 10.0 and later
   */
  // Structure for the I_OTScript Ioctl.
  OTGetBusTypeFromPortRef(OTPortRef ref);

  /**
   *  OTGetSlotFromPortRef()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTSlotNumber
  OTGetSlotFromPortRef(OTPortRef ref, UInt16 *other);

  /**
   *  OTSetDeviceTypeInPortRef()
   *
// addition to standard xti.h 
   *    \non_carbon_// unbound                 
   *    \carbon_lib // idle                
   *    \mac_os_x   // outgoing connection pending    
   */// incoming connection pending    
  OTPortRef// data transfer          
  OTSetDeviceTypeInP// outgoing orderly release     
// incoming orderly release     
  /**
   *  OTSetBusTypeInPortRef()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTPortRef
  OTSetBusTypeInPortRef(OTPortRef ref, OTBusType busType);

  /**
      Convenience macros for generating specific types of OTPortRefs.
  */

#define OTCreateNuBusPortRef(devType, slot, other) \
  OTCreatePortRef(kOTNuBus, devType, slot, other)

#define OTCreatePCIPortRef(devType, slot, other) \
  OTCreatePortRef(kOTPCIBus, devType, slot, other)

#define OTCreatePCCardPortRef(devType, slot, other) \
  OTCreatePortRef(kOTPCCardBus, devType, slot, other)

  // Name length definitions for various fields in OTPortRecord.
  enum
  {
    kMaxModuleNameLength = 31, // max length of a STREAMS module name    kMaxModuleNameSize = kMaxModuleNameLength + 1,
    kMaxProviderNameLength = kMaxModuleNameLength +
                             4, // providers allow 4 characters for minor number    kMaxProviderNameSize = kMaxProviderNameLength + 1,
    kMaxSlotIDLength = 7, // PCI slot names tend to be short    kMaxSlotIDSize = kMaxSlotIDLength + 1,
    kMaxResourceInfoLength = 31, // max length of a configuration helper name    kMaxResourceInfoSize = 32,
    kMaxPortNameLength =
        kMaxModuleNameLength + 4, // max size allowed to define a port    kMaxPortNameSize = kMaxPortNameLength + 1
  };

  /**
     Masks for the fPortFlags field of OTPortRecord
     If no bits are set, the port is currently inactive.
  */

  enum
  {
  // ***** Option Management Structures *****
    kOTPortIsDisabled = 0x00000002,
  // This structure describes the contents of a single option in a buffer.
    kOTPortIsOffline = 0x00000008
  };

  // Masks for the fIn// total length of option          
  enum// = sizeof(TOptionHeader) + length     
  {//     of option value in bytes       
    kOTPortIsDLPI = 0x// protocol affected            
    kOTPortIsTPI = 0x0// option name                   
    kOTPortCanYield =// status value                
        0x00000004, // will not be set until the port is used for the first time    kOTPortCanArbitrate =
        0x00000008, // will not be set until the port is used for the first time    kOTPortIsTransitory = 0x00000010,
    kOTPortAutoConnects = 0x00000020,
    kOTPortIsSystemRegistered = 0x00004000,
    kOTPortIsPrivate = 0x00008000,
    kOTPortIsAlias = (unsigned long)0x80000000
  };

  /**
     One OTPortRecord // total length of option          
     For Instance 'ene// = sizeof(TOption) + length 
     A OTPortRecord fo//     of option value in bytes       
     OTPortRef that wi// protocol affected            
     port it is suppos// option name                   
  */// status value                
// data goes here               
  struct OTPortRecord
  {
  // Some useful constants when manipulating option buffers.
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
/**
   Routines for finding, registering and unregistering ports.
   IMPORTANT:
   These routines have two versions, one for the client and one
   for the kernel.  Make sure you use and link with the right ones.
*/
#if !OTKERNEL
  /**
   *  OTGetIndexedPort()
   *

   *    \non_carbon_cfm   in OTClientUtilLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTGetIndexedPort(OTPortRecord *portRecord, OTItemCount index);

  // Index through the ports in the system  /**
  // t_kpalive is used with OPT_KEEPALIVE option.
   *

   *    \non_carbon_cfm   in OTClientUtilLib 1.0 and later
   *    \carbon_lib    // option on/off   
   *    \mac_os_x      // timeout in minutes 
   */
  Boolean
  // t_linger is used with XTI_LINGER option.

  // Find an OTPortRecord for a port using it's name  /**
   *  OTFindPortByRef// option on/off 
   *// linger time 

   *    \non_carbon_cfm   in OTClientUtilLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTFindPortByRef(OTPortRecord *portRecord, OTPortRef ref);
// Values returned in servtype field of TEndpointInfo.
// Find an OTPortRecord for a port using it's OTPortRef#if CALL_NOT_IN_CARBON
  /**
   *  OTRegisterPort()
   *
// Connection-mode service                    
   *    \non_carbon_c// Connection service with orderly release          
   *    \carbon_lib  // Connectionless-mode service                   
   *    \mac_os_x    // Connection-mode transaction service              
   */// Connection transaction service with orderly release    
  OSStatus// Connectionless transaction service           
  OTRegisterPort(OTPortRecord *portRecord, void *ref);

  // Masks for the flags field of TEndpointInfo.
     Register a port. The name the port was registered under is returned in
     the fPortName field.
  */
  /**// supports 0-length TSDU's          
   *  OTUnregisterPort()// supports the GetProtAddress call     
   *// support M_DATAs on packet protocols    
// Supports ResolveAddress call      
   *    \non_carbon_cfm   in OTClientU// Supports SNMP MIB data          
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTUnregisterPort(const char *portName, void **ref);

  /**
     Unregister the port with the given name (If you re-register the
     port, it may get a different name - use OTChangePortState if
     that is not desi// supports infinit amounts of data     
     with several nam// Does not support data transmission 
     the OTPortRef to disambiguate.
  */
  /**
  // Now the TEndpointInfo structure proper.
   *

   *    \non_carbon_cfm   in// Maximum size of an address        
   *    \carbon_lib        n// Maximum size of options          
   *    \mac_os_x         no// Standard data transmit unit size     
   */// Expedited data transmit unit size  
  OSStatus// Maximum data size on connect      
  OTChangePortState(OTPortRe// Maximum data size on disconnect       
// service type                
// Change the state of the p// Flags (see above for values)      
#endif // !OTKERNEL 
  // ***** Data Buffers *****  /**
     TNetbuf is the basic structure used to pass data back and forth
     between the Open Transport protocols and their clients
  */

  struct TNetbuf
  // ***** OTPortRecord *****
    ByteCount maxlen;
  // Unique identifier for a port.
    UInt8 *buf;
  };
  typedef struct TNetbuf TNetbuf;
  /**
     Some rarely used low-level routines in this file take a strbuf
     as a parameter.  This is the raw streams equivalent of a TNetbuf.
     The key difference is that the maxlen and len fields are signed,
     which allows you to specify extra operations by providing a
  // Valid values for the bus type element of an OTPortRef.
  */

  struct strbuf
  {
    SInt32 maxlen; // max buffer length     SInt32 len;    // length of data     char *buf;     // pointer to buffer   };
  typedef struct strbuf strbuf;
  /**
     OTData is used in a TNetbuf or netbuf to send
     non-contiguous data.  Set the 'len' field of the netbuf to the
     constant kNetbufDataIsOTData to signal that the 'buf' field of the
     netbuf actually points to one of these structures instead of a
     memory buffer.
  */
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
  };// An Atalk ADEV   
// A TCP/IP MDEV   
  /**// LocalTalk       
     OTBuffer is used for no-cop// IRTalk          
     set the receive length to k// Token Ring        
     pass the address of an OTBu// ISDN             
     fill it out to point to a c// ATM              
     When you are done with it, // SMDS             
     For best performance, you n// Serial           
     Only data netbufs may use t// Ethernet          
     like. Any OTBuffer returned// SLIP Pseudo-device 
     that this has a high correl// PPP Pseudo-device  
     are commented with their co// Modem Pseudo-Device    
  */// 100 MB Ethernet       
// FDDI             
  struct OTBuffer// IrDA Infrared   
  {// ATM SNAP emulation 
    void *fLink;            // b// Fibre Channel   
    UInt8 fFlags; // b_flag  };// FireWire link Device   
  typedef struct OTBuffer OTBuff// used where no other defined device type will work
  enum
  {
    kOTNetbufDataIsOTBufferStar = (unsigned long)0xFFFFFFFD
  // Special case values for the slot number element of an OTPortRef.

  /**
     OTBufferInfo is used with OTReadBuffer to keep track of where you
     are in the buffer, since the OTBuffer is "read-only".
  */
  /* Use the OTInitBuffer macro to initialise this structure from an OTBuffer
   * chain.*/
  struct OTBufferInfo
  // Accessor functions for the various elements of the OTPortRef.
    OTBuffer *fBuffer;
    ByteCount fOffset;
    UInt8 fPad;
  };
  typedef struct OTBufferInfo OTBufferInfo;

#define OTInitBufferInfo(infoPtr, theBuffer) \
  (infoPtr)->fBuffer = theBuffer;            \
  (infoPtr)->fPad = (theBuffer)->fPad1;      \
  (infoPtr)->fOffset = 0

  /**
     If the endpoint supports "raw mode" (the T_CAN_SUPPORT_MDATA bit will
     be set in the TEndpointInfo::flags field), then you specify the
     raw mode packet by putting the kOTNetbufIsRawMode value in
     the udata.addr.len field when calling OTSndUData and also set the
     udata.opt.len, udata.opt.buf, and udata.addr.buf fields to 0.
  */

  enum
  {
    kOTNetbufIsRawMode = (unsigned long)0xFFFFFFFF
  };

  /**
     ***** Standard XTI Parameter Types *****
     These structures are all used as parameters to the standard
     XTI routines.
  */

  /**
     TBind holds binding information for calls to
     OTGetProtAddress, OTResolveAddress and OTBind.
  */

  struct TBind
  {
    TNetbuf addr;
    OTQLen qlen;
  };
  typedef struct TBind TBind;
  /**
     TDiscon is passed to RcvDisconnect to find out additional information
     about the disconnect.
  */
  struct TDiscon
  {
    TNetbuf udata;
    OTReason reason;
    OTSequence sequence;
  };
  typedef struct TDiscon TDiscon;
  /**
     TCall holds information about a connection and is a parameter to
     OTConnect, OTRcvConnect, OTListen, OTAccept, and OTSndDisconnect.
  */
  struct TCall
  {
    TNetbuf addr;
    TNetbuf opt;
    TNetbuf udata;
    OTSequence sequence;
  };
  typedef struct TCall TCall;
  // TUnitData describes a datagram in calls to OTSndUData and OTRcvUData.  struct TUnitData
  {
    TNetbuf addr;
    TNetbuf opt;
    TNetbuf udata;
  };
  typedef struct TUnitData TUnitData;
  /**
     TUDErr is used to get information about a datagram error using
     OTRcvUDErr.
  */
  struct TUDErr
  {
    TNetbuf addr;
    TNetbuf opt;
    SInt32 error;
  // Name length definitions for various fields in OTPortRecord.
  typedef struct TUDErr TUDErr;
  // TOptMgmt is passed to the OTOptionManagement call to read or set protocol  struct TOptMgmt
  {
    TNetbuf opt;// max length of a STREAMS module name
    OTFlags flags;
  };
  typedef struct TOptMgmt TOptMg// providers allow 4 characters for minor number
  /**
     ***** Transactional X// PCI slot names tend to be short
     These structures are all used as parameters to the OT's
     XTI-like routines for transa// max length of a configuration helper name
  */
  /**
     TRequest is passed to OTSndRe// max size allowed to define a port
     information about the request.
  */

  struct TRequest
  {
    TNetbuf data;
    TNetbuf opt;
    OTSequence sequence;
  };
  typedef struct TRequest TRequest;
  // TReply is passed to OTSndReply to send a reply to an incoming request.  struct TReply
  {
    TNetbuf data;
    TNetbuf opt;
    OTSequence sequence;
  };
  // Masks for the fInfoFlags field of the OTPortRecord.
  /**
     TUnitRequest is passed to OTSndURequest and OTRcvURequest that contains
     the information about the request.
  */
  struct TUnitRequest
  {
    TNetbuf addr;// will not be set until the port is used for the first time
    TNetbuf opt;
    TNetbuf udata;// will not be set until the port is used for the first time
    OTSequence sequence;
  };
  typedef struct TUnitRequest TUnitRequest;
  // TUnitReply is passed to OTSndUReply to send a reply to an incoming request.  struct TUnitReply
  {
    TNetbuf opt;
    TNetbuf udata;
    OTSequence sequence;
  };
  typedef struct TUnitReply TUnitReply;
  /**
     ***** Mapper Parameter Types *****
     These structures are all used as parameters to the OT's
     mapper routines.
  */
  // TRegisterRequest holds the name to register in a call to OTRegisterName.
  struct TRegisterRequest
  {
    TNetbuf name;
    TNetbuf addr;
    OTFlags flags;
  };
  typedef struct TRegisterRequest TRegisterRequest;
  /**
     TRegisterReply returns information about the registered name in a call
     to OTRegisterName.
  */
  struct TRegisterReply
  {
    TNetbuf addr;
    OTNameID nameid;
  };
  typedef struct TRegisterReply TRegisterReply;
  // TLookupRequest holds the name to look up in a call to OTLookupName.  struct TLookupRequest
  {
    TNetbuf name;
    TNetbuf addr;
    UInt32 maxcnt;
    OTTimeout timeout;
    OTFlags flags;
  };
  typedef struct TLookupRequest TLookupRequest;
  /**
     TLookupReply returns information about the found names after a call
     to OTLookupName.
  */
  struct TLookupReply
  {
  // Index through the ports in the system
    UInt32 rspcount;
  };
  typedef struct TLookupReply TLookupReply;
  /**
     TLookupBuffer describes the contents of the names buffer pointed
     to by the TLookupReply.
  */
  struct TLookupBuffer
  {
    UInt16 fAddressLength;
    UInt16 fNameLength;
  // Find an OTPortRecord for a port using it's name
  };
  typedef struct TLookupBuffer TLookupBuffer;

  /**
      OTNextLookupBuffer allows you to step through a packed array
     of TLookupBuffers.
  */

#define OTNextLookupBuffer(buf)                                      \
  ((TLookupBuffer *)((char *)buf +                                   \
                     ((OTOffsetOf(TLookupBuffer, fAddressBuffer) +   \
// Find an OTPortRecord for a port using it's OTPortRef
                      ~3)))

  // ***** Initializing and Shutting Down Open Transport *****
#if !OTKERNEL
  typedef struct OpaqueOTClientContextPtr *OTClientContextPtr;
  /**
     For Carbon the InitOpenTransport interface has changed so it takes a flags
     parameter and returns a client context pointer. The flag passed to indicates
     whether OT should be initialized for application use or for some other target
     (for example, plugins that run in an application context but not the
     application itself.) Applications that are not interested in the value of the
     client context pointer may pass NULL as outClientContext -- they will pass
     NULL to other routines that take a OTClientContextPtr.
  */
  typedef UInt32 OTInitializationFlags;
  enum
  {
    kInitOTForApplicationMask = 1,
    kInitOTForExtensionMask = 2
  };

  /**
   *  InitOpenTransportInContext()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  InitOpenTransportInContext(
      OTInitializationFlags flags,
      OTClientContextPtr *outClientContext); // can be NULL 
  /**
     Under Carbon, CloseOpenTransport takes a client context pointer. Applications
     may pass NULL after calling InitOpenTransport(kInitOTForApplicationMask,
     ...).  Non-applications must always pass a valid client context.
  */
  /**
   *  CloseOpenTransportInContext()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
// Change the state of the port.
  void// CALL_NOT_IN_CARBON 
  CloseOpenTransportInContext(OTClientContextPtr clientContext);
// !OTKERNEL 
#if CALL_NOT_IN_CARBON
  // ***** Data Buffers *****
   *  InitOpenTransport()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  InitOpenTransport(void);

  /**
   *  InitOpenTransportUtilities()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  InitOpenTransportUtilities(void);

  /**
   *  CloseOpenTran// max buffer length 
   *// length of data 
// pointer to buffer 
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  CloseOpenTransport(void);

  /**
   *  OTRegisterAsClient()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTRegisterAsClient(OTClientName name, OTNotifyUPP proc);

  /**
     This registers yourself as a client for any miscellaneous Open Transport
     notifications that come along. CloseOpenTransport will automatically do
     an OTUnregisterAsClient, if you have not already done so.
  */
  /**
   *  OTUnregisterAsClient()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTUnregisterAsClient(void);

#endif // CALL_NOT_IN_CARBON 
  /**
   *  OTRegisterAsClientInCo// b_next
   *// b_prev
// b_cont
   *    \non_carbon_cfm   no// b_rptr
   *    \carbon_lib        i// b_wptr
   *    \mac_os_x         in// b_datap
   */// b_band
  OSStatus// b_pad1
  OTRegisterAsClientInContext(OTClientName name, OTNotifyUPP proc,
                  // b_flag
  /**
   *  OTUnregisterAsClientInContext()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTUnregisterAsClientInContext(OTClientContextPtr clientContext);

#if OTCARBONAPPLICATION
// The following macro may be used by applications only.#define InitOpenTransport() \
  InitOpenTransportInContext(kInitOTForApplicationMask, NULL)
#define CloseOpenTransport() CloseOpenTransportInContext(NULL)
#define OTRegisterAsClient(name, proc) \
  OTRegisterAsClientInContext(name, proc, NULL)
#define OTUnregisterAsClient() OTUnregisterAsClientInContext(NULL)
#endif // OTCARBONAPPLICATION 
#endif // !OTKERNEL 
  // ***** Tasking Model *****  /**
     OTEnterInterrupt/OTLeaveInterrupt are normally used within the kernel to
     tell Open Transport we're at hardware interrupt time.  Clients can also
     them to do the same.
  */

#if CALL_NOT_IN_CARBON
  /**
   *  OTEnterInterrupt()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  OTEnterInterrupt(void);

  /**
   *  OTLeaveInterrupt()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  OTLeaveInterrupt(void);

  /**
   *  OTIsAtInterruptLevel()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  OTIsAtInterruptLevel(void);

  /**
   *  OTCanLoadLibraries()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  OTCanLoadLibraries(void);

  /**
     All OT task callbacks use the same prototype, shown below.
     This is only a UPP for CFM-68K clients.
  */

#endif // CALL_NOT_IN_CARBON 
  typedef CALLBACK_API(void, OTProcessProcPtr)(void *arg);
  typedef TVECTOR_UPP_TYPE(OTProcessProcPtr) OTProcessUPP;
  // TUnitData describes a datagram in calls to OTSndUData and OTRcvUData.
   *  NewOTProcessUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTProcessUPP
  NewOTProcessUPP(OTProcessProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOTProcessProcInfo = 0x000000C0
  }; // pascal no_return_value Func(4_bytes) #ifdef __cplusplus
  inline OTProcessUPP NewOTProcessUPP(OTProcessProcPtr userRoutine)
  {
    return userRoutine;
  }
#e// TOptMgmt is passed to the OTOptionManagement call to read or set protocol
#define NewOTProcessUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
   *  DisposeOTProcessUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeOTProcessUPP(OTProcessUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOTProcessUPP(OTProcessUPP) {}
#else
#define DisposeOTProcessUPP(userUPP)
#endif
#endif

  /**
  // TReply is passed to OTSndReply to send a reply to an incoming request.
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
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

#i// TUnitReply is passed to OTSndUReply to send a reply to an incoming request.
  /**
     Under Carbon, OTCreateDeferredTask takes a client context pointer.
     Applications may pass NULL after calling
     InitOpenTransport(kInitOTForApplicationMask, ...).  Non-applications must
     always pass a valid client context.
  */
  /**
   *  OTCreateDeferredTaskInContext()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
  // TRegisterRequest holds the name to register in a call to OTRegisterName.
   */
  long
  OTCreateDeferredTaskInContext(
      OTProcessUPP upp, void *arg,
      OTClientContextPtr clientContext); // can be NULL 
#endif // !OTKERNEL 
  /**
     OT deferred tasks are often more convenience that standard Mac OS
     although they have no significant advantages beyond convenience.
  */

  typedef long OTDeferredTaskRef;
#if CALL_NOT_IN_CARBON
  /**
   *  OTCreateDeferredTask()
   *

   *    \non_carbon_cfm   not available
  // TLookupRequest holds the name to look up in a call to OTLookupName.
   *    \mac_os_x         not available
   */
  OTDeferredTaskRef
  OTCreateDeferredTask(OTProcessUPP proc, void *arg);

#endif // CALL_NOT_IN_CARBON 
  /**
   *  OTScheduleDeferredTask()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTScheduleDeferredTask(OTDeferredTaskRef dtCookie);

#if CALL_NOT_IN_CARBON
  /**
   *  OTScheduleInterruptTask()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  OTScheduleInterruptTask(OTDeferredTaskRef dtCookie);

#endif // CALL_NOT_IN_CARBON 
  /**
   *  OTDestroyDeferredTask()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTDestroyDeferredTask(OTDeferredTaskRef dtCookie);

#if OTCARBONAPPLICATION
//// ***** Initializing and Shutting Down Open Transport *****
  OTCreateDeferredTaskInContext(upp, arg, NULL)
#endif // OTCARBONAPPLICATION 
#if !OTKERNEL
  /**
     OT system tasks allow you to schedule a procedure to be called
     at system task time.  Potentially useful, but it relies on someone
     calling SystemTask (or WaitNextEvent, which calls SystemTask).
     Not available to kernel code because relying on system task time
     to make progress is likely to result in deadlocks.
  */
  typedef long OTSystemTaskRef;
#if CALL_NOT_IN_CARBON
  /**
   *  OTCreateSystemTask()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OTSystemTaskRef
  OTCreateSystemTask(OTProcessUPP proc, void *arg);

  /**
   *  OTDestroySystemTask()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */// can be NULL 
  OSStatus
  OTDestroySystemTask(OTSystemTaskRef stCookie);

  /**
   *  OTScheduleSystemTask()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  OTScheduleSystemTask(OTSystemTaskRef stCookie);

  /**
   *  OTCancelSystemTask()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  OTCancelSystemTask(OTSystemTaskRef stCookie);

#endif // CALL_NOT_IN_CARBON 
  /**
   *  OTCanMakeSyncCall()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTCanMakeSyncCall(void);

#endif // !OTKERNEL 
// ***** Interface to Providers *****#if !OTKERNEL
#if CALL_NOT_IN_CARBON
  /**
   *  OTAsyncOpenProvider()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTAsyncOpenProvider(OTConfigurationRef cfig, OTOpenFlags flags,
                      OTNotifyUPP proc, void *contextPtr);

  /**
   *  OTOpenProvider()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ProviderRef
  OTOpenProvider(OTConfigurationRef cfig, OTOpenFlags flags, OSStatus *errPtr);

#endif // CALL_NOT_IN_CARBON 
  /**
   *  OTCloseProvider()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTCloseProvider(ProviderRef ref);

#if CALL_NOT_IN_CARBON
  /**
   *  OTTransferProviderOwnership()
   *// CALL_NOT_IN_CARBON 

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ProviderRef
  OTTransferProviderOwnership(ProviderRef ref, OTClient prevOwner,
                              OSStatus *errPtr);

  /**
   *  OTWhoAmI()
   *// can be NULL 

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OTClient
  OTWhoAmI(void);

  /**
   *  OTGetProviderPortRef()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
// The following macro may be used by applications only.
   *    \mac_os_x         not available
   */
  OTPortRef
  OTGetProviderPortRef(ProviderRef ref);

#endif // CALL_NOT_IN_CARBON 
  /**// OTCARBONAPPLICATION 
   *  OTIoctl()
   *// !OTKERNEL 

  // ***** Tasking Model *****
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32
  OTIoctl(ProviderRef ref, UInt32 cmd, void *data);

#if CALL_NOT_IN_CARBON
  /**
   *  OTGetMessage()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OTResult
  OTGetMessage(ProviderRef ref, strbuf *ctlbuf, strbuf *databuf,
               OTFlags *flagsPtr);

  /**
   *  OTGetPriorityMessage()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OTResult
  OTGetPriorityMessage(ProviderRef ref, strbuf *ctlbuf, strbuf *databuf,
                       OTBand *bandPtr, OTFlags *flagsPtr);

  /**
   *  OTPutMessage()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTPutMessage(ProviderRef ref, const strbuf *ctlbuf, const strbuf *databuf,
               OTFlags flags);

  /**
   *  OTPutPriorityMessage()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTPutPriorityMessage(ProviderRef ref, const strbuf *ctlbuf,
                       const strbuf *databuf, OTBand band, OTFlags flags);

#endif // CALL_NOT_IN_CARBON 
  /**// CALL_NOT_IN_CARBON 
   *  OTSetAsynchronous()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTSetAsynchronous(ProviderRef ref);

  /**
   *  OTSetSynchronous()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */// pascal no_return_value Func(4_bytes) 
  OSStatus
  OTSetSynchronous(ProviderRef ref);

  /**
   *  OTIsSynchronous()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTIsSynchronous(ProviderRef ref);

  /**
   *  OTSetBlocking()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTSetBlocking(ProviderRef ref);

  /**
   *  OTSetNonBlocking()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTSetNonBlocking(ProviderRef ref);

  /**
   *  OTIsBlocking()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTIsBlocking(ProviderRef ref);

  /**
   *  OTInstallNotifier()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTInstallNotifier(ProviderRef ref, OTNotifyUPP proc, void *contextPtr);

  /**
   *  OTUseSyncIdleEvents()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTUseSyncIdleEvents(ProviderRef ref, Bo// can be NULL 

  /**// !OTKERNEL 
   *  OTRemoveNotifier()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTRemoveNotifier(ProviderRef ref);

  /**
   *  OTLeaveNotifier()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTLea// CALL_NOT_IN_CARBON 

  /**
   *  OTEnterNotifier()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTEnterNotifier(ProviderRef ref);

  /**
   *  OTAckSends()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTAckSends(ProviderRef ref);

  /**
   *  O// CALL_NOT_IN_CARBON 
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTDontAckSends(ProviderRef ref);

  /**
   *  OTIsAckingSends()
   *

// The following macro may be used by applications only.
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */// OTCARBONAPPLICATION 
  Boolean
  OTIsAckingSends(ProviderRef ref);

  /**
   *  OTCancelSynchronousCalls()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTCancelSynchronousCalls(ProviderRef ref, OSStatus err);

#define OTIsNonBlocking(ref) (!OTIsBlocking(ref))
#define OTIsAsynchronous(ref) (!OTIsSynchronous(ref))

#endif // !OTKERNEL 
// ***** Interface to Endpoints *****#if !OTKERNEL
  // Open/Close  /**
     Under Carbon, the OpenEndpoint routines take a client context pointer.
     Applications may pass NULL after calling
     InitOpenTransport(kInitOTForApplicationMask, ...).  Non-applications must
     always pass a valid client context.
  */
  /**
   *  OTOpenEndpointInContext()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EndpointRef
  OTOpenEndpointInContext(OTConfigurationRef config, OTOpenFlags oflag,
                          TEndpointInfo *info, // can be NULL                           OSStatus *err,
                          OTClientContextPtr clientContext); // can be NULL 
  /**
   *  OTAsyncOpenEndpointInContext()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTAsyncOpenEndpointInContext(
      OTConfigurationRef config, OTOpenFlags oflag,
      TEndpointInfo *info, // can be NULL       OTNotifyUPP upp, void *contextPtr,
      OTClientContextPtr clientContext); // can be NULL 
#if CALL_NOT_IN_CARBON
  /**
   *  OTOpenEndpoint()
   *

   *   // CALL_NOT_IN_CARBON 
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  EndpointRef
  OTOpenEndpoint(OTConfigurationRef cfig, OTOpenFlags oflag,
                 TEndpointInfo *info, // can be NULL                  OSStatus *err);

  /**
   *  OTAsyncOpenEndpoint()
   *

   *    \non_carbon_cfm   not available
   *   // !OTKERNEL 
   *    \mac_os_x         not available
// ***** Interface to Providers *****
  OSStatus
  OTAsyncOpenEndpoint(OTConfigurationRef cfig, OTOpenFlags oflag,
                      TEndpointInfo *info, // can be NULL                       OTNotifyUPP proc, void *contextPtr);

#endif // CALL_NOT_IN_CARBON 
#if OTCARBONAPPLICATION
// The following macros may be used by applications only.#define OTOpenEndpoint(config, oflag, info, err) \
  OTOpenEndpointInContext(config, oflag, info, err, NULL)
#define OTAsyncOpenEndpoint(config, oflag, info, proc, contextPtr) \
  OTAsyncOpenEndpointInContext(config, oflag, info, proc, contextPtr, NULL)
#endif // OTCARBONAPPLICATION 
  // Misc Information
  /**
   *  OTGetEndpointInfo()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTGetEndpointInfo(EndpointRef ref, TEndpointInfo *info);

  /**
   *  OTGetEndpointState()
   *// CALL_NOT_IN_CARBON 

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTResult
  OTGetEndpointState(EndpointRef ref);

  /**
   *  OTLook()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTResult
  OTLook(EndpointRef ref);

#if CALL_NOT_IN_CARBON
  /**
   *  OTSync()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OTResult
  OTSync(EndpointRef ref);

#endif // CALL_NOT_IN_CARBON 
  /**
   *  OTCountDataBytes()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTResult
  OTCountDataBytes(EndpointRef ref, OTByteCount *countPtr);

  /**
   *  OTGetProtAddress()
   *

   *   // CALL_NOT_IN_CARBON 
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTGetProtAddress(EndpointRef ref, TBind *boundAddr, // can be NULL                    TBind *peerAddr);                  // can be NULL 
  /**
   *  OTResolveAddress()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTResolveAddress(EndpointRef ref, TBind *reqAddr, TBind *retAddr,
                   OTTimeout timeOut);

  // Allocating structures
  /**
     Note:
     In general, Apple recommends that you avoid the OTAlloc call because
     using it extensively causes your program to allocate and deallocate
     many memory blocks, with each extra memory allocation costing time.
  */

  /**
     Under Carbon, OTAlloc takes a client context pointer.  Applications may pass
     NULL after calling InitOpenTransport(kInitOTForApplicationMask, ...).
     Non-applications must always pass a valid client context.
  */
  /**
   *  OTAllocInContext()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void *
  OTAllocInContext(EndpointRef ref, OTStructType structType, UInt32 fields,
                   OSStatus *err,
                   OTClientContextPtr clientContext); // can be NULL 
#if CALL_NOT_IN_CARBON
  /**
   *  OTAlloc()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void *
  OTAlloc(EndpointRef ref, OTStructType structType, OTFieldsType fields,
          OSStatus *err);

#endif // CALL_NOT_IN_CARBON 
#if OTCARBONAPPLICATION
// The following macro may be used by applications only.#define OTAlloc(ref, structType, fields, err) \
  OTAllocInContext(ref, structType, fields, err, NULL)
#endif // OTCARBONAPPLICATION 
  /**
   *  O// CALL_NOT_IN_CARBON 
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTResult
  OTFree(void *ptr, OTStructType structType);

  // Option management
  // It looks simple enough...
  /**
   *  OTOptionManagement()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTOptionManagement(EndpointRef ref, TOptMgmt *req, TOptMgmt *ret);

  // ... but then the hidden complexity emerges.
#if CALL_NOT_IN_CARBON
  /**
   *  OTCreateOptions()
   *

   *    \non_carbon_cfm   in OTClientUtilLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTCreateOptions(const char *endPtName, char **strPtr, TNetbuf *buf);

  /**
   *  OTCreateOptionString()
   *

   *    \non_carbon_cfm   in OTClientUtilLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTCreateOptionString(const char *endPtName, TOption **opt, void *bufEnd,
                       char *str, OTByteCount stringSize);

#endif // CALL_NOT_IN_CARBON 
  /**
   *  OTNextOption()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTNextOption(UInt8 *buffer, UInt32 buflen, TOption **prevOptPtr);

  /**
   *  OTFindOption()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TOption *
  OTFindOption(UInt8 *buffer, UInt32 buflen, OTXTILevel level, OTXTIName name);

  // Bind/Unbind
  /**
   *  OTBind()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTBind(EndpointRef ref, TBind *reqAddr, // can be NULL          TBind *retAddr);                 // can be NULL 
  /**
   *  OTUnbind()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTUnbind(EndpointRef ref);

  // Connection creation/tear-down
  /**
   *  OTConnect()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTConnect(EndpointRef ref, TCall *sndCall, TCall *rcvCall); // can be NULL 
  /**
   *  OTRcvConnect()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTRcvConnect(EndpointRef ref, TCall *call); // can be NULL 
  /**
   *  OTListen()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTListen(EndpointRef ref, TCall *call);

  /**
   *  OTAccept()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTAccept(EndpointRef listener, EndpointRef worker, TCall *call);

  /**
   *  OTSndDisconnect()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTSndDisconnect(EndpointRef ref, TCall *call); // can be NULL 
  /**
   *  OTSndOrderlyDisconnect()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTSndOrderlyDisconnect(EndpointRef ref);

  /**
   *  OTRcvDisconnect()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTRcvDisconnect(EndpointRef ref, TDiscon *discon); // can be NULL 
  /**
   *  OTRcvOrderlyDisconnect()
   *
// !OTKERNEL 
   *    \non_carbon_cfm   in OTClientLib 1.0 and later
// ***** Interface to Endpoints *****
   *    \mac_os_x         in version 10.0 and later
  // Open/Close
  OSStatus
  OTRcvOrderlyDisconnect(EndpointRef ref);

  // Connection-oriented send/receive
  /**
   *  OTRcv()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTResult
  OTRcv(EndpointRef ref, void *buf, OTByteCount nbytes, OTFlags *flags);

  /**
   *  OTSnd()// can be NULL 
   *
// can be NULL 
   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTResult
  OTSnd(EndpointRef ref, void *buf, OTByteCount nbytes, OTFlags flags);

  // Connectionless send/receive
  /**
   *  OTSndUData()
   *

   *    \non_carbon_cfm   i// can be NULL 
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0// can be NULL 
   */
  OSStatus
  OTSndUData(EndpointRef ref, TUnitData *udata);

  /**
   *  OTRcvUData()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus// can be NULL 
  OTRcvUData(EndpointRef ref, TUnitData *udata, OTFlags *flags);

  /**
   *  OTRcvUDErr()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTRcvUDErr(EndpointRef ref, TUDErr *uderr); // can be NULL 
  // Connection-oriented transactions// can be NULL 
#if CALL_NOT_IN_CARBON
  /**
   *  O// CALL_NOT_IN_CARBON 
   *

// The following macros may be used by applications only.
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTSnd// OTCARBONAPPLICATION 

  // Misc Information
   *  OTRcvReply()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTRcvReply(EndpointRef ref, TReply *reply, OTFlags *replyFlags);

  /**
   *  OTSndReply()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTSndReply(EndpointRef ref, TReply *reply, OTFlags replyFlags);

  /**
   *  OTRcvRequest()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTRcvRequest(EndpointRef ref, TRequest *req, OTFlags *reqFlags);

  /**
   *  OTCancelRequest()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTCancelRequest(EndpointRef ref, OTSequence sequence);

  /**
   *  OTCancelReply()
   *
// CALL_NOT_IN_CARBON 
   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTCancelReply(EndpointRef ref, OTSequence sequence);

  // Connectionless transactions
  /**
   *  OTSndURequest()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTSndURequest(EndpointRef ref, TUnitRequest *req, OTFlags reqFlags);

  /**
   *  OTRcvUReply()
   *// can be NULL 
// can be NULL 
   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTRcvUReply(EndpointRef ref, TUnitReply *reply, OTFlags *replyFlags);

  /**
   *  OTSndUReply()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
  // Allocating structures
   */
  OSStatus
  OTSndUReply(EndpointRef ref, TUnitReply *reply, OTFlags replyFlags);

  /**
   *  OTRcvURequest()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTRcvURequest(EndpointRef ref, TUnitRequest *req, OTFlags *reqFlags);

  /**
   *  OTCancelURequest()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTCancelURequest(EndpointRef ref, OTSequence seq);// can be NULL 

  /**
   *  OTCancelUReply()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTCancelUReply(EndpointRef ref, OTSequence seq);

// Interface to Mappers
/**
   Unde// CALL_NOT_IN_CARBON 
   Applications may pass NULL after calling
   InitOpenTransport(kInitOTForApplicationMask, ...).  Non-applications must
// The following macro may be used by applications only.
*/
#endif // CALL_NOT_IN_CARBON 
  /**// OTCARBONAPPLICATION 
   *  OTAsyncOpenMapperInContext()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTAsyncOpenMapperInContext(OTConfigurationRef config, OTOpenFlags oflag,
                             OTNotifyUPP upp, void *contextPtr,
                             OTClientContextPtr clientContext); // can be NULL 
  /**
  // Option management
   *
// It looks simple enough...
   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  MapperRef
  OTOpenMapperInContext(OTConfigurationRef config, OTOpenFlags oflag,
                        OSStatus *err,
                        OTClientContextPtr clientContext); // can be NULL 
#if CALL_NOT_IN_CARBON
  /**
   *  OTAsyncOpenMapper()
   *
// ... but then the hidden complexity emerges.
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  OTAsyncOpenMapper(OTConfigurationRef cfig, OTOpenFlags oflag, OTNotifyUPP proc,
                    void *contextPtr);

  /**
   *  OTOpenMapper()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MapperRef
  OTOpenMapper(OTConfigurationRef cfig, OTOpenFlags oflag, OSStatus *err);

#endif // CALL_NOT_IN_CARBON 
#if OTCARBONAPPLICATION
// The following macros may be used by applications only.#define OTAsyncOpenMapper(config, oflag, proc, contextPtr) \
  OTAsyncOpenMapperInContext(config, oflag, proc, contextPtr, NULL)
#define OTOpenMapper(config, oflag, err) \
  OTOpenMapperInContext(config, oflag, err, NULL)
#endif // CALL_NOT_IN_CARBON 
  /**
   *  OTRegisterName()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTRegisterName(MapperRef ref, TRegisterRequest *req, TRegisterReply *reply);

  /**
   *  OTDeleteName()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTDeleteName(MapperRef ref, TNetbuf *name);

  /**
  // Bind/Unbind
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTDeleteNameByID(MapperRef ref, OTNameID nameID);

  /**
   *  OTLookupName()// can be NULL 
   *// can be NULL 

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  OTLookupName(MapperRef ref, TLookupRequest *req, TLookupReply *reply);

  // Basic configuration manipulation
  /**
   *  OTCreateConfiguration()
   *
// Connection creation/tear-down
   *    \non_carbon_cfm   in OTClientUtilLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTConfigurationRef
  OTCreateConfiguration(const char *path);

  /**
   *  OTCloneConfiguration()
   *
// can be NULL 
   *    \non_carbon_cfm   in OTClientUtilLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTConfigurationRef
  OTCloneConfiguration(OTConfigurationRef cfig);

  /**
   *  OTDestroyConfiguration()
   *
// can be NULL 
   *    \non_carbon_cfm   in OTClientUtilLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTDestroyConfiguration(OTConfigurationRef cfig);

  /**
     This file defines a very limited set of operations
     on a configuration.  "OpenTransportClient.h" extends this with extra
     operations used by protocol stacks but not typically needed by clients.
  */

  // Interrupt-safe memory allocators
  /**
     Under Carbon, OTAllocMem takes a client context pointer.  Applications may
     pass NULL after calling InitOpenTransport(kInitOTForApplicationMask, ...).
     Non-applications must always pass a valid client context.
  */
  /**
   *  OTAllocMemInContext()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void *
  OTAllocMemInContext(OTByteCount size,
                      OTClientContextPtr clientContext); // can be NULL 
#if CALL_NOT_IN_CARBON
  /**
   *  OTAllocMem()// can be NULL 
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void *
  OTAllocMem(OTByteCount size);

#endif // CALL_NOT_IN_CARBON 
  /**
   *  OTFreeMem()
   *

   *    \non_carbon_cfm   in OTClientUtilLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTFreeMem(void *mem);

#if OTCARBONAPPLICATION// can be NULL 
// The following macros may be used by applications only.#define OTAllocMem(s) OTAllocMemInContext(s, NULL)
#endif // OTCARBONAPPLICATION 
  // Miscellaneous and Generic Routines
  /**
     Neither of these routines should be necessary to the correct
     operation of an OT program.  If you're calling them, think again.
  */

  /**
   *  OTDelay()
   *

  // Connection-oriented send/receive
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTDelay(UInt32 seconds);

  /**
   *  OTIdle()
   *

   *    \non_carbon_cfm   in OTClientLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTIdle(void);

#endif // !OTKERNEL 
  /**
     ***** Open Transport Utility Routines *****
     All of these routines are available to both client and kernel.
  */
  // Memory and String Routines
  // Connectionless send/receive
     These are preferable, especially in the kernel case, to the standard
     C equivalents because they don't require you to link with StdCLib.
  */

  /**
   *  OTMemcpy()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTMemcpy(void *dest, const void *src, OTByteCount nBytes);

  /**
   *  OTMemcmp()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTMemcmp(const void *mem1, const void *mem2, OTByteCount nBytes);

  /**
   *  OTMemmove()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and // can be NULL 
   */
  // Connection-oriented transactions
  OTMemmove(void *dest, const void *src, OTByteCount nBytes);

  /**
   *  OTMemzero()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTMemzero(void *dest, OTByteCount nBytes);

  /**
   *  OTMemset()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTMemset(void *dest, OTUInt8Param toSet, OTByteCount nBytes);

  /**
   *  OTStrLength()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTByteCount
  OTStrLength(const char *str);

  /**
   *  OTStrCopy()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTStrCopy(char *dest, const char *src);

  /**
   *  OTStrCat()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTStrCat(char *dest, const char *src);

  /**
   *  OTStrEqual()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTStrEqual(const char *src1, const char *src2);

  // Connectionless transactions
  /**
     OTGetTimeStamp returns time in "tick" numbers, stored in 64 bits.
     This timestamp can be used as a base number for calculating elapsed
     time.
     OTSubtractTimeStamps returns a pointer to the "result" parameter.

     OTGetClockTimeInSecs returns time since Open Transport was initialized
     in seconds.
  */

  typedef UnsignedWide OTTimeStamp;
  /**
   *  OTGetTimeStamp()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTGetTimeStamp(OTTimeStamp *currentTime);

  /**
   *  OTSubtractTimeStamps()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTTimeStamp *
  OTSubtractTimeStamps(OTTimeStamp *result, OTTimeStamp *startTime,
                       OTTimeStamp *endEnd);

  /**
   *  OTTimeStampInMilliseconds()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt32
  OTTimeStampInMilliseconds(OTTimeStamp *delta);

  /**
   *  OTTimeStampInMicroseconds()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt32
  OTTimeStampInMicroseconds(OTTimeStamp *delta);

  /**
   *  OTElapsedMilliseconds()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt32
  OTElapsedMilliseconds(OTTimeStamp *startTime);

// Interface to Mappers
   *  OTElapsedMicroseconds()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt3// CALL_NOT_IN_CARBON 
  OTElapsedMicroseconds(OTTimeStamp *startTime);

  /**
   *  OTGetClockTimeInSecs()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt32
  OTGetClockTimeInSecs(void);
// can be NULL 
  // ***** OT Link Element *****
  /**
     When using OT linked lists, all pointers to other elements are
     represented by the OTLink structure.  When operating on link
     lists, you always pass in the address of the OTLink on which
     list elements are chained.
  */

  struct OTLink
  {
    struct OTLink *fNext;

#ifdef __cplusplus// can be NULL 

    // C++ inline methods on this structure.

    void Init() { fNext = NULL; }
#endif
  };
  typedef struct OTLink OTLink;

/**
    You can use this macro to map from an OTLink field to the
  structure in which it's embedded.
*/
#define OTGetLinkObject(link, struc, field) \
  ((struc *)((char *)(link)-OTOffsetOf(struc, field)))

  // OTLIFO
  /**
     These are functions to implement a LIFO list that is interrupt-safe.
     The only function which is not is OTReverseList.  Normally, you create
     a LIFO list, populate it at interrupt time, and then use OTLIFOStealList
     to atomically remove the list, and OTReverseList to flip the list so that
     it is a FIFO list, which tends to be more useful.
  */

  struct OTLIFO
  {// CALL_NOT_IN_CARBON 
    OTLink *fHead;

// The following macros may be used by applications only.

    // C++ inline methods on this structure.

    void Init();
    voi// OTCARBONAPPLICATION 
    OTLink *Dequeue();
    OTLink *StealList();
    Boolean IsEmpty();
#endif
  };
  typedef struct OTLIFO OTLIFO;
  /**
     This function atomically enqueues the link onto the
     front of the list.
  */
  /**
   *  OTLIFOEnqueue()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTLIFOEnqueue(OTLIFO *list, OTLink *link);

  /**
     This function atomically dequeues the first element
     on the list.
  */
  /**
   *  OTLIFODequeue()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTLink *
  OTLIFODequeue(OTLIFO *list);

  /**
     This function atomically empties the list and returns a
     pointer to the first element on the list.
  */
  /**
   *  OTLIFOStealList()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
  // Basic configuration manipulation
   *    \mac_os_x         in version 10.0 and later
   */
  OTLink *
  OTLIFOStealList(OTLIFO *list);

  /**
     This function reverses a list that was stolen by
     OTLIFOStealList.  It is NOT atomic.  It returns the
     new starting list.
  */
  /**
   *  OTReverseList()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTLink *
  OTReverseList(OTLink *list);

#ifdef __cplusplus

  // C++ inline methods on this structure.

  inline void OTLIFO::Init() { fHead = NULL; }
  inline void OTLIFO::Enqueue(OTLink *link) { OTLIFOEnqueue(this, link); }
  inline OTLink *OTLIFO::Dequeue() { return OTLIFODequeue(this); }
  inline OTLink *OTLIFO::StealList() { return OTLIFOStealList(this); }
  inline Boolean OTLIFO::IsEmpty() { return fHead == NULL; }
#endif

  // OTList
  /**
     An OTList is a non-interrupt-safe list, but has more features than the
     OTLIFO list. It is a standard singly-linked list.
  */

  /**
     The following is the prototype for a list element comparison function,
  // Interrupt-safe memory allocators
     the client criteria (typically held in ref).
     This is only a UPP for CFM-68K clients.
  */

  typedef CALLBACK_API_C(Boolean, OTListSearchProcPtr)(const void *ref,
                                                       OTLink *linkToCheck);
  typedef TVECTOR_UPP_TYPE(OTListSearchProcPtr) OTListSearchUPP;
  /**
   *  NewOTListSearchUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTListSearchUPP
  NewOTListSearchUPP(OTListSearchProcPtr userRoutine);// can be NULL 
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppOTListSearchProcInfo = 0x000003D1
  }; // 1_byte Func(4_bytes, 4_bytes) #ifdef __cplusplus
  inline OTListSearchUPP NewOTListSearchUPP(OTListSearchProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewOTListSearchUPP(userRoutine) (userRoutine)
#endif
#endif
// CALL_NOT_IN_CARBON 
  /**
   *  DisposeOTListSearchUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeOTListSearchUPP(OTListSearchUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeOTListSearchUPP(OTListSearchUPP) {}
// The following macros may be used by applications only.
#define DisposeOTListSearchUPP(userUPP)
#endif// OTCARBONAPPLICATION 
#endif
// Miscellaneous and Generic Routines
  /**
   *  InvokeOTListSearchUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
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

#ifdef // !OTKERNEL 
    // C++ inline methods on this structure.

    void Init();
    Boolean IsEmpty();
    void AddFirst(OTLink *link);
  // Memory and String Routines
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
  // Add the link to the list at the front  /**
   *  OTAddFirst()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTAddFirst(OTList *list, OTLink *link);

  // Add the link to the list at the end  /**
   *  OTAddLast()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTAddLast(OTList *list, OTLink *link);

  // Remove the first link from the list  /**
   *  OTRemoveFirst()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTLink *
  OTRemoveFirst(OTList *list);

  // Remove the last link from the list  /**
   *  OTRemoveLast()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTLink *
  OTRemoveLast(OTList *list);

  // Return the first link from the list  /**
   *  OTGetFirst()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTLink *
  OTGetFirst(OTList *list);

  // Return the last link from the list  /**
   *  OTGetLast()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTLink *
  OTGetLast(OTList *list);

  // Return true if the link is present in the list  /**
   *  OTIsInList()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTIsInList(OTList *list, OTLink *link);

  /**
     Find a link in the list which matches the search criteria
     established by the search proc and the refPtr.  This is done
     by calling the search proc, passing it the refPtr and each
     link in the list, until the search proc returns true.
     NULL is returned if the search proc never returned true.
  */
  /**
   *  OTFindLink()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTLink *
  // Timer Utilities

  // Remove the specified link from the list, returning true if it was found  /**
   *  OTRemoveLink()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  OTRemoveLink(OTList *list, OTLink *link);

  // Similar to OTFindLink, but it also removes it from the list.  /**
   *  OTFindAndRemoveLink()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTLink *
  OTFindAndRemoveLink(OTList *list, OTListSearchUPP proc, const void *ref);

  // Return the "index"th link in the list  /**
   *  OTGetIndexedLink()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OTLink *
  OTGetIndexedLink(OTList *list, OTItemCount index);

  // OTEnqueue/OTDequeue
  /**
     These routines are atomic, mighty weird, and generally not
     worth the complexity.  If you need atomic list operations,
     use OTLIFO instead.
  */

  /**
     This function puts "object" on the listHead, and places the
     previous value at listHead into the pointer at "object" plus
     linkOffset.
  */
  /**
   *  OTEnqueue()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OTEnqueue(void **listHead, void *object, OTByteCount linkOffset);

  /**
     This function returns the head object of the list, and places
     the pointer at "object" + linkOffset into the listHead
  */
  /**
   *  OTDequeue()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void *
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
  // ***** OT Link Element *****
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

// Atomic Operations
/**
   Note:
   The Bit operations return the previous value of the bit (0 or non-zero).
   The memory pointed to must be a single byte and only bits 0 through 7 are
   valid.  Bit 0 corresponds to a mask of 0x01, and Bit 7 to a mask of 0x80.
*/

/**
   WARNING!
   void* and UInt32 locations MUST be on 4-byte boundaries.
   UInt16 locations must not cross a 4-byte boundary.
*/

/**
 *  OTAtomicSetBit()
 *// OTLIFO

 *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTAtomicSetBit(__A0, __D0)
#endif
  Boolean
  OTAtomicSetBit(UInt8 *bytePtr, OTByteCount bitNumber)
      FOURWORDINLINE(0x01D0, 0x56C0, 0x7201, 0xC081);

/**
   bset.b d0,(a0)
   sne d0
   moveq #1,d1
   and.l d1,d0
*/
/**
 *  OTAtomicClearBit()
 *

 *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTAtomicClearBit(__A0, __D0)
#endif
  Boolean
  OTAtomicClearBit(UInt8 *bytePtr, OTByteCount bitNumber)
      FOURWORDINLINE(0x0190, 0x56C0, 0x7201, 0xC081);

/**
   bclr.b d0,(a0)
   sne d0
   moveq #1,d1
   and.l d1,d0
*/
/**
 *  OTAtomicTestBit()
 *

 *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTAtomicTestBit(__A0, __D0)
#endif
  Boolean
  OTAtomicTestBit(UInt8 *bytePtr, OTByteCount bitNumber)
      FOURWORDINLINE(0x0110, 0x56C0, 0x7201, 0xC081);

/**
   btst.b d0,(a0)
   sne d0 *|
   moveq #1,d1
   and.l d1,d0 *|
*/
/**
 *  OTCompareAndSwapPtr()
 *

 *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTCompareAndSwapPtr(__D0, __D1, __A0)
#endif
  Boolean
  OTCompareAndSwapPtr(void *oldValue, void *newValue, void **dest)
      FIVEWORDINLINE(0x0ED0, 0x0040, 0x57C0, 0x7201, 0xC081);

/**
   cas.l    d0,d1,(a0)  *|
   seq      d0          *|
   moveq #1,d1; and.l d1,d0 *|
*/
/**
 *  OTCompareAndSwap32()
 *

 *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTCompareAndSwap32(__D0, __D1, __A0)
#endif
  Boolean
  OTCompareAndSwap32(UInt32 oldValue, UInt32 newValue, UInt32 *dest)
      FIVEWORDINLINE(0x0ED0, 0x0040, 0x57C0, 0x7201, 0xC081);

/**
   cas.l    d0,d1,(a0)  *|
  // OTList
   moveq #1,d1; and.l d1,d0 *|
*/
/**
 *  OTCompareAndSwap16()
 *

 *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTCompareAndSwap16(__D0, __D1, __A0)
#endif
  Boolean
  OTCompareAndSwap16(UInt32 oldValue, UInt32 newValue, UInt16 *dest)
      FIVEWORDINLINE(0x0CD0, 0x0040, 0x57C0, 0x7201, 0xC081);

/**
   cas.w    d0,d1,(a0)  *|
   seq      d0          *|
   moveq #1,d1; and.l d1,d0 *|
*/
/**
 *  OTCompareAndSwap8()
 *

 *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if T// 1_byte Func(4_bytes, 4_bytes) 
#pragma parameter __D0 OTCompareAndSwap8(__D0, __D1, __A0)
#endif
  Boolean
  OTCompareAndSwap8(UInt32 oldValue, UInt32 newValue, UInt8 *dest)
      FIVEWORDINLINE(0x0AD0, 0x0040, 0x57C0, 0x7201, 0xC081);

/**
   cas.b    d0,d1,(a0)  *|
   seq      d0          *|
   moveq #1,d1; and.l d1,d0 *|
*/
/**
 *  OTAtomicAdd32()
 *

 *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OTAtomicAdd32(__D0, __A0)
#endif
  SInt32
  OTAtomicAdd32(SInt32 toAdd, SInt32 *dest)
      SEVENWORDINLINE(0x2240, 0x2210, 0x2001, 0xD089, 0x0ED0, 0x0001, 0x66F4);

  /**
     move.l   d0,a1       *|
     move.l   (a0),d1     *|
     move.l   d1,d0       *|
     add.l    a1,d0       *|
     cas.l    d1,d0,(a0)  *|
     bne.s    @1          *|
  */
  /**
   *  OTAtomicAdd16()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16
  OTAtomicAdd16(SInt32 toAdd, SInt16 *dest);

  // Not used frequently enough to justify inlining.  /**
   *  OTAtomicAdd8()
   *

   *    \non_carbon_cfm   in OTUtilityLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt8
  OTAtomicAdd8(SInt32 toAdd, SInt8 *dest);

  // Not used frequently enough to justify inlining.  // OTLock is just a convenience type with some convenient macros.
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

/*  -------------------------------------------------------------------------
    CLASS TProvider

    This class provides the client interface to a Stream.  Typically, clients
  // Add the link to the list at the front
    of TProvider.
    ------------------------------------------------------------------------- */

#if !OTKERNEL

class TProvider
{
private:
  void *operator new(size_t);
  void operator delete(void *) {}

  // Add the link to the list at the end
  // This is the public interface to a TProvider.  All other public
  // methods normally come from the subclass.
  //
public:
  OSStatus Close() { return OTCloseProvider(this); }

  OSStatus SetNonBlocking() { return OTSetNonBlocking(this); }
  OSStatus SetBlocking() { return OTSetBlocking(this); }
  Boolean IsBlocking() { return OTIsBlocking(this); }
  Boolean IsNonBlocking() { return !OTIsBlocking(this); }
  OSStatus SetSynchronous() { return OTSetSynchronous(this); }
  // Remove the first link from the list
  Boolean IsSynchronous() { return OTIsSynchronous(this); }
  Boolean IsAsynchronous() { return !OTIsSynchronous(this); }

  OSStatus AckSends() { return OTAckSends(this); }
  OSStatus DontAckSends() { return OTDontAckSends(this); }
  Boolean IsAckingSends() { return OTIsAckingSends(this); }

  void CancelSynchronousCalls(OSStatus err)
  {
    (void)OTCancelSynchronousCalls(this, err);
  }
// Remove the last link from the list
  OSStatus InstallNotifier(OTNotifyUPP proc, void *ptr)
  {
    return OTInstallNotifier(this, proc, ptr);
  }

  OSStatus UseSyncIdleEvents() { return OTUseSyncIdleEvents(this, true); }

  OSStatus DontUseSyncIdleEvents() { return OTUseSyncIdleEvents(this, false); }

  void RemoveNotifier() { OTRemoveNotifier(this); }

  // Return the first link from the list

  void LeaveNotifier() { OTLeaveNotifier(this); }

#if CALL_NOT_IN_CARBON
  OTPortRef GetOTPortRef() { return OTGetProviderPortRef(this); }

  ProviderRef TransferOwnership(OTClient prevOwner, OSStatus *errPtr)
  {
    return OTTransferProviderOwnership(this, prevOwner, errPtr);
  }
#endif
// Return the last link from the list
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
  // Return true if the link is present in the list
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

/*  -------------------------------------------------------------------------
    Class TEndpoint

    This class is the interface to all TPI modules, which constitute the
    vast majority of protocols, with the exception of link-layer protocols.
    ------------------------------------------------------------------------- */

class TEndpoint : public TProvider
{
public:
  //
  // Miscellaneous informative functions
  // Remove the specified link from the list, returning true if it was found
  OSStatus GetEndpointInfo(TEndpointInfo *info)
  {
    return OTGetEndpointInfo(this, info);
  }

  OSStatus GetProtAddress(TBind *boundAddr, TBind *peerAddr)
  {
    return OTGetProtAddress(this, boundAddr, peerAddr);
  }

  OSStatus ResolveAddress(TBind *reqAddr, TBind *retAddr, OTTimeout timeout)
  // Similar to OTFindLink, but it also removes it from the list.
    return OTResolveAddress(this, reqAddr, retAddr, timeout);
  }

  OTResult GetEndpointState() { return OTGetEndpointState(this); }

  OTResult Look() { return OTLook(this); }

#if CALL_NOT_IN_CARBON
  OTResult Sync() { return OTSync(this); }
#endif
  //
  // Return the "index"th link in the list
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
  // OTEnqueue/OTDequeue
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

// Atomic Operations
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

/*  -------------------------------------------------------------------------
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

#endif // !OTKERNEL    
extern "C"
{      // resume C definitions
#endif // __cplusplus 
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

#endif // __OPENTRANSPORT__ // Not used frequently enough to justify inlining.
// Not used frequently enough to justify inlining.
// OTLock is just a convenience type with some convenient macros.
// !OTKERNEL    
// __cplusplus 
// __OPENTRANSPORT__ 
