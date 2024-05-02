/**
     \file       PPCToolbox.h

    \brief   Program-Program Communications Toolbox Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1989-2001 by Apple Computer, Inc., all rights reserved

    \ingroup CommunicationsToolbox

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __PPCTOOLBOX__
#define __PPCTOOLBOX__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

  typedef UInt8 PPCServiceType;
  enum
  {
    ppcServiceRealTime = 1
  };

  typedef SInt16 PPCLocationKind;
  enum
  {
    ppcNoLocation = 0,  /* There is no PPCLocName */
    ppcNBPLocation = 1, /* Use AppleTalk NBP      */
    ppcNBPTypeLocation =
        2,                 /* Used for specifying a location name type during PPCOpen only */
    ppcXTIAddrLocation = 3 /* Use TCP/IP or DNS host name address */
  };

  typedef SInt16 PPCPortKinds;
  enum
  {
    ppcByCreatorAndType =
        1,          /* Port type is specified as colloquial Mac creator and type */
    ppcByString = 2 /* Port type is in pascal string format */
  };

  /* Values returned for request field in PPCInform call */
  typedef UInt8 PPCSessionOrigin;
  enum
  {
    ppcLocalOrigin = 1, /* session originated from this machine */
    ppcRemoteOrigin = 2 /* session originated from remote machine */
  };

  typedef short PPCPortRefNum;
  typedef long PPCSessRefNum;

  /*  The maximum allowed size of a fAddress in PPCXTIAddress */
  enum
  {
    kMaxPPCXTIAddress = 95
  };

  /**
      The possible types of information found in the fAddressType field of a
     PPCXTIAddress record Note:   These constants are the same as the AF_INET &
     AF_DNS constants, defined in OpenTptInternet.x
  */
  typedef SInt16 PPCXTIAddressType;
  enum
  {
    kINETAddrType = 2, /*    An IP address in binary form (type InetHost).*/
    kDNSAddrType = 42  /*    A DNS or dotted-decimal name string (no leading length
                          byte, no NULL termination byte)*/
  };

  /**
      This structure specifies a transport independent network address in a
      form that can be used by Open Transport, or as a XTI/TLI/socket network
      address in UNIX terminology.
  */
  struct PPCXTIAddress
  {
    PPCXTIAddressType fAddressType; /* A constant specifying what kind of network
                                       address this is */
    UInt8 fAddress[96];             /* The contents of the network address (variable length,
                                       NULL terminated). */
  };
  typedef struct PPCXTIAddress PPCXTIAddress;
  typedef PPCXTIAddress *PPCXTIAddressPtr;

  /**
      This structure is the variant type used in a LocationNameRec when an IP
     connection is being established for a PPC Toolbox session.

      NOTE: The value of the xtiAddrLen must be the length of the entire
     PPCXTIAddress structure in the xtiAddr field, and not just the length of the
     fAddress field of the PPCXTIAddress structure.
  */
  struct PPCAddrRec
  {
    UInt8 Reserved[3];     /* reserved - must be initialize to 0          */
    UInt8 xtiAddrLen;      /* size of the xtiAddr field             */
    PPCXTIAddress xtiAddr; /* the transport-independent network address   */
  };
  typedef struct PPCAddrRec PPCAddrRec;
  typedef PPCAddrRec *PPCAddrRecPtr;

  struct LocationNameRec
  {
    PPCLocationKind locationKindSelector; /* which variant */
    union
    {
      EntityName nbpEntity; /* NBP name entity                   */
      Str32 nbpType;        /* just the NBP type string, for PPCOpen  */
      PPCAddrRec xtiType;   /* an XTI-type network address record     */
    } u;
  };
  typedef struct LocationNameRec LocationNameRec;
  typedef LocationNameRec *LocationNamePtr;

  struct PPCPortRec
  {
    ScriptCode nameScript;         /* script of name */
    Str32Field name;               /* name of port as seen in browser */
    PPCPortKinds portKindSelector; /* which variant */
    union
    {
      Str32 portTypeStr; /* pascal type string */
      struct
      {
        OSType portCreator;
        OSType portType;
      } port;
    } u;
  };
  typedef struct PPCPortRec PPCPortRec;
  typedef PPCPortRec *PPCPortPtr;
  struct PortInfoRec
  {
    SInt8 filler1;
    Boolean authRequired;
    PPCPortRec name;
  };
  typedef struct PortInfoRec PortInfoRec;
  typedef PortInfoRec *PortInfoPtr;
  typedef PortInfoRec *PortInfoArrayPtr;
  typedef union PPCParamBlockRec PPCParamBlockRec;
  typedef PPCParamBlockRec *PPCParamBlockPtr;
  typedef CALLBACK_API(void, PPCCompProcPtr)(PPCParamBlockPtr pb);
  typedef STACK_UPP_TYPE(PPCCompProcPtr) PPCCompUPP;
#define PPCHeader                                             \
  Ptr qLink;                 /* PPC's Internal Use */         \
  unsigned short csCode;     /* Requested PPC command */      \
  unsigned short intUse;     /* Internal Use */               \
  Ptr intUsePtr;             /* Internal Use */               \
  PPCCompUPP ioCompletion;   /* 12 --> Completion Routine */  \
  volatile OSErr ioResult;   /* 16 <-- Command Result Code */ \
  unsigned long Reserved[5]; /* Reserved for PPC, Don't use */

  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct PPCOpenPBRec
  {
    PPCPortRefNum portRefNum;     /**<  Port Reference*/
    long filler;                  /**<  Filler*/
    PPCServiceType serviceType;   /**<  Bit field describing the*/
    unsigned char resFlag;        /**<  Must be set to */
    PPCPortPtr portName;          /**<  PortName for PPC*/
    LocationNamePtr locationName; /**<  If NBP Registration is*/
    Boolean networkVisible;       /**<  Make this network visible*/
    Boolean nbpRegistered;        /**<  The given location name*/
  } PPCOpenPBRec;                 /**< */

  typedef struct PPCOpenPBRec PPCOpenPBRec;
  typedef PPCOpenPBRec *PPCOpenPBPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct PPCInformPBRec
  {
    unsigned long Reserved[];     /**< Reserved for PPC, Don't use*/
    PPCPortRefNum portRefNum;     /**< Port reference number of this*/
    PPCSessRefNum sessRefNum;     /**< Session reference number of*/
    PPCServiceType serviceType;   /**< Service type of this session*/
    Boolean autoAccept;           /**< If TRUE, session is accepted*/
    PPCPortPtr portName;          /**< Pointer to PPCPortRec , may be*/
    LocationNamePtr locationName; /**< Pointer to LocationNameRec ,*/
    StringPtr userName;           /**< pointer to Str, may be NIL*/
    unsigned long userData;       /**< application-specific data*/
    PPCSessionOrigin requestType; /**< network or local request*/
  } PPCInformPBRec;               /**< */

  typedef struct PPCInformPBRec PPCInformPBRec;
  typedef PPCInformPBRec *PPCInformPBPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct PPCStartPBRec
  {
    PPCPortRefNum portRefNum;     /**< Port reference number of this*/
    PPCSessRefNum sessRefNum;     /**< Session reference number of this*/
    PPCServiceType serviceType;   /**< Service type requested-must be*/
    unsigned char resFlag;        /**< Reserved field-must be */
    PPCPortPtr portName;          /**< Pointer to PPCPortRec*/
    LocationNamePtr locationName; /**< Pointer to LocationNameRec*/
    unsigned long rejectInfo;     /**< Value from PPCReject if session*/
    unsigned long userData;       /**< Application-specific data*/
    unsigned long userRefNum;     /**< User reference number*/
  } PPCStartPBRec;                /**< */

  typedef struct PPCStartPBRec PPCStartPBRec;
  typedef PPCStartPBRec *PPCStartPBPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct PPCAcceptPBRec
  {
    short filler;             /**< Port reference number of this*/
    PPCSessRefNum sessRefNum; /**< Session reference number of this*/
  } PPCAcceptPBRec;           /**< */

  typedef struct PPCAcceptPBRec PPCAcceptPBRec;
  typedef PPCAcceptPBRec *PPCAcceptPBPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct PPCRejectPBRec
  {
    short filler;             /**< Port reference number of this*/
    PPCSessRefNum sessRefNum; /**< Session reference number of this*/
    short filler;             /**< Filler*/
  } PPCRejectPBRec;           /**< */

  typedef struct PPCRejectPBRec PPCRejectPBRec;
  typedef PPCRejectPBRec *PPCRejectPBPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct PPCWritePBRec
  {
    short filler;             /**< Port reference number of this*/
    PPCSessRefNum sessRefNum; /**< Session reference number*/
    Size bufferLength;        /**< Length of data buffer*/
    Size actualLength;        /**< Actual length of data written*/
    Ptr bufferPtr;            /**< Pointer to data buffer*/
    Boolean more;             /**< TRUE if more data in this block to be*/
    unsigned char filler;     /**< Filler*/
    unsigned long userData;   /**< Application-specific data*/
    OSType blockCreator;      /**< Creator of block read*/
    OSType blockType;         /**< Type of block read*/
  } PPCWritePBRec;            /**< */

  typedef struct PPCWritePBRec PPCWritePBRec;
  typedef PPCWritePBRec *PPCWritePBPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct PPCReadPBRec
  {
    short filler;             /**< Port reference number of this*/
    PPCSessRefNum sessRefNum; /**< Session reference number*/
    Size bufferLength;        /**< Length of data buffer*/
    Size actualLength;        /**< Actual length of data written*/
    Ptr bufferPtr;            /**< Pointer to data buffer*/
    Boolean more;             /**< TRUE if more data in this block to be*/
    unsigned char filler;     /**< Filler*/
    unsigned long userData;   /**< Application-specific data*/
    OSType blockCreator;      /**< Creator of block read*/
    OSType blockType;         /**< Type of block read*/
  } PPCReadPBRec;             /**< */

  typedef struct PPCReadPBRec PPCReadPBRec;
  typedef PPCReadPBRec *PPCReadPBPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct PPCEndPBRec
  {
    PPCSessRefNum sessRefNum; /**< Session reference number*/
  } PPCEndPBRec;              /**< */

  typedef struct PPCEndPBRec PPCEndPBRec;
  typedef PPCEndPBRec *PPCEndPBPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct PPCClosePBRec
  {
    PPCPortRefNum portRefNum; /**< Session reference number*/
  } PPCClosePBRec;            /**< */

  typedef struct PPCClosePBRec PPCClosePBRec;
  typedef PPCClosePBRec *PPCClosePBPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct IPCListPortsPBRec
  {
    unsigned short csCode;        /**<  Requested PPC command*/
    unsigned short intUse;        /**< Internal Use*/
    Ptr intUsePtr;                /**<  Internal Use*/
    PPCCompProcPtr ioCompletion;  /**<  Completion Routine*/
    OSErr ioResult;               /**< Command Result Code*/
    unsigned long Reserved[];     /**< Reserved for PPC, Don't use*/
    short filler;                 /**< Port reference number of this*/
    unsigned short startIndex;    /**< Index to port entry list*/
    unsigned short requestCount;  /**< Number of port names*/
    unsigned short actualCount;   /**< Number of port names*/
    PPCPortPtr portName;          /**< Pointer to PPCPortRec*/
    LocationNamePtr locationName; /**< Pointer to LocationNameRec*/
    PortInfoArrayPtr bufferPtr;   /**< Pointer to array of PortInfoRec*/
  } IPCListPortsPBRec;            /**< */

  typedef struct IPCListPortsPBRec IPCListPortsPBRec;
  typedef IPCListPortsPBRec *IPCListPortsPBPtr;
  union PPCParamBlockRec
  {
    PPCOpenPBRec openParam;
    PPCInformPBRec informParam;
    PPCStartPBRec startParam;
    PPCAcceptPBRec acceptParam;
    PPCRejectPBRec rejectParam;
    PPCWritePBRec writeParam;
    PPCReadPBRec readParam;
    PPCEndPBRec endParam;
    PPCClosePBRec closeParam;
    IPCListPortsPBRec listPortsParam;
  };

/*  PPC Calling Conventions  */
#if CALL_NOT_IN_CARBON
/**
 *  PPCInit()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCInit
#endif
  OSErr
  PPCInit(void) TWOWORDINLINE(0x7000, 0xA0DD);

/**
 *  PPCOpenSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCOpenSync(__A0)
#endif
  OSErr
  PPCOpenSync(PPCOpenPBPtr pb) TWOWORDINLINE(0x7001, 0xA0DD);

/**
 *  PPCOpenAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCOpenAsync(__A0)
#endif
  OSErr
  PPCOpenAsync(PPCOpenPBPtr pb) TWOWORDINLINE(0x7001, 0xA4DD);

/**
 *  PPCInformSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCInformSync(__A0)
#endif
  OSErr
  PPCInformSync(PPCInformPBPtr pb) TWOWORDINLINE(0x7003, 0xA0DD);

/**
 *  PPCInformAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCInformAsync(__A0)
#endif
  OSErr
  PPCInformAsync(PPCInformPBPtr pb) TWOWORDINLINE(0x7003, 0xA4DD);

/**
 *  PPCStartSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCStartSync(__A0)
#endif
  OSErr
  PPCStartSync(PPCStartPBPtr pb) TWOWORDINLINE(0x7002, 0xA0DD);

/**
 *  PPCStartAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCStartAsync(__A0)
#endif
  OSErr
  PPCStartAsync(PPCStartPBPtr pb) TWOWORDINLINE(0x7002, 0xA4DD);

/**
 *  PPCAcceptSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCAcceptSync(__A0)
#endif
  OSErr
  PPCAcceptSync(PPCAcceptPBPtr pb) TWOWORDINLINE(0x7004, 0xA0DD);

/**
 *  PPCAcceptAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCAcceptAsync(__A0)
#endif
  OSErr
  PPCAcceptAsync(PPCAcceptPBPtr pb) TWOWORDINLINE(0x7004, 0xA4DD);

/**
 *  PPCRejectSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCRejectSync(__A0)
#endif
  OSErr
  PPCRejectSync(PPCRejectPBPtr pb) TWOWORDINLINE(0x7005, 0xA0DD);

/**
 *  PPCRejectAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCRejectAsync(__A0)
#endif
  OSErr
  PPCRejectAsync(PPCRejectPBPtr pb) TWOWORDINLINE(0x7005, 0xA4DD);

/**
 *  PPCWriteSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCWriteSync(__A0)
#endif
  OSErr
  PPCWriteSync(PPCWritePBPtr pb) TWOWORDINLINE(0x7006, 0xA0DD);

/**
 *  PPCWriteAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCWriteAsync(__A0)
#endif
  OSErr
  PPCWriteAsync(PPCWritePBPtr pb) TWOWORDINLINE(0x7006, 0xA4DD);

/**
 *  PPCReadSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCReadSync(__A0)
#endif
  OSErr
  PPCReadSync(PPCReadPBPtr pb) TWOWORDINLINE(0x7007, 0xA0DD);

/**
 *  PPCReadAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCReadAsync(__A0)
#endif
  OSErr
  PPCReadAsync(PPCReadPBPtr pb) TWOWORDINLINE(0x7007, 0xA4DD);

/**
 *  PPCEndSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCEndSync(__A0)
#endif
  OSErr
  PPCEndSync(PPCEndPBPtr pb) TWOWORDINLINE(0x7008, 0xA0DD);

/**
 *  PPCEndAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCEndAsync(__A0)
#endif
  OSErr
  PPCEndAsync(PPCEndPBPtr pb) TWOWORDINLINE(0x7008, 0xA4DD);

/**
 *  PPCCloseSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCCloseSync(__A0)
#endif
  OSErr
  PPCCloseSync(PPCClosePBPtr pb) TWOWORDINLINE(0x7009, 0xA0DD);

/**
 *  PPCCloseAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PPCCloseAsync(__A0)
#endif
  OSErr
  PPCCloseAsync(PPCClosePBPtr pb) TWOWORDINLINE(0x7009, 0xA4DD);

/**
 *  IPCListPortsSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 IPCListPortsSync(__A0)
#endif
  OSErr
  IPCListPortsSync(IPCListPortsPBPtr pb) TWOWORDINLINE(0x700A, 0xA0DD);

/**
 *  IPCListPortsAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 IPCListPortsAsync(__A0)
#endif
  OSErr
  IPCListPortsAsync(IPCListPortsPBPtr pb) TWOWORDINLINE(0x700A, 0xA4DD);

/**
 *  IPCKillListPorts()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 IPCKillListPorts(__A0)
#endif
  OSErr
  IPCKillListPorts(IPCListPortsPBPtr pb) TWOWORDINLINE(0x700B, 0xA0DD);

  /**
   *  DeleteUserIdentity()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DeleteUserIdentity(unsigned long userRef);

  /**
   *  GetDefaultUser()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  GetDefaultUser(unsigned long *userRef, Str32 userName);

  /**
   *  StartSecureSession()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  StartSecureSession(PPCStartPBPtr pb, Str32 userName, Boolean useDefault,
                     Boolean allowGuest, Boolean *guestSelected,
                     ConstStr255Param prompt);

#endif /* CALL_NOT_IN_CARBON */

  typedef CALLBACK_API(Boolean, PPCFilterProcPtr)(LocationNamePtr name,
                                                  PortInfoPtr port);
  typedef STACK_UPP_TYPE(PPCFilterProcPtr) PPCFilterUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewPPCCompUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  PPCCompUPP
  NewPPCCompUPP(PPCCompProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppPPCCompProcInfo = 0x000000C0
  }; /* pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
  inline PPCCompUPP NewPPCCompUPP(PPCCompProcPtr userRoutine)
  {
    return (PPCCompUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppPPCCompProcInfo, GetCurrentArchitecture());
  }
#else
#define NewPPCCompUPP(userRoutine)   \
  (PPCCompUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppPPCCompProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewPPCFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  PPCFilterUPP
  NewPPCFilterUPP(PPCFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppPPCFilterProcInfo = 0x000003D0
  }; /* pascal 1_byte Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline PPCFilterUPP NewPPCFilterUPP(PPCFilterProcPtr userRoutine)
  {
    return (PPCFilterUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppPPCFilterProcInfo, GetCurrentArchitecture());
  }
#else
#define NewPPCFilterUPP(userRoutine)   \
  (PPCFilterUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppPPCFilterProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposePPCCompUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposePPCCompUPP(PPCCompUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposePPCCompUPP(PPCCompUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposePPCCompUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposePPCFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposePPCFilterUPP(PPCFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposePPCFilterUPP(PPCFilterUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposePPCFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokePPCCompUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokePPCCompUPP(PPCParamBlockPtr pb, PPCCompUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokePPCCompUPP(PPCParamBlockPtr pb, PPCCompUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppPPCCompProcInfo, pb);
  }
#else
#define InvokePPCCompUPP(pb, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppPPCCompProcInfo, (pb))
#endif
#endif

  /**
   *  InvokePPCFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  InvokePPCFilterUPP(LocationNamePtr name, PortInfoPtr port,
                     PPCFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokePPCFilterUPP(LocationNamePtr name, PortInfoPtr port,
                                    PPCFilterUPP userUPP)
  {
    return (Boolean)CALL_TWO_PARAMETER_UPP(userUPP, uppPPCFilterProcInfo, name,
                                           port);
  }
#else
#define InvokePPCFilterUPP(name, port, userUPP) \
  (Boolean)                                     \
      CALL_TWO_PARAMETER_UPP((userUPP), uppPPCFilterProcInfo, (name), (port))
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewPPCCompProc(userRoutine) NewPPCCompUPP(userRoutine)
#define NewPPCFilterProc(userRoutine) NewPPCFilterUPP(userRoutine)
#define CallPPCCompProc(userRoutine, pb) InvokePPCCompUPP(pb, userRoutine)
#define CallPPCFilterProc(userRoutine, name, port) \
  InvokePPCFilterUPP(name, port, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
  /**
   *  PPCBrowser()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  PPCBrowser(ConstStr255Param prompt, ConstStr255Param applListLabel,
             Boolean defaultSpecified, LocationNameRec *theLocation,
             PortInfoRec *thePortInfo, PPCFilterUPP portFilter,
             ConstStr32Param theLocNBPType)
      THREEWORDINLINE(0x303C, 0x0D00, 0xA82B);

/**
  The ParamBlock calls without the "Sync" or "Async" suffix are being phased
  out.
*/
#endif /* CALL_NOT_IN_CARBON */

#define PPCOpen(pb, async) ((async) ? PPCOpenAsync(pb) : PPCOpenSync(pb))
#define PPCInform(pb, async) ((async) ? PPCInformAsync(pb) : PPCInformSync(pb))
#define PPCStart(pb, async) ((async) ? PPCStartAsync(pb) : PPCStartSync(pb))
#define PPCAccept(pb, async) ((async) ? PPCAcceptAsync(pb) : PPCAcceptSync(pb))
#define PPCReject(pb, async) ((async) ? PPCRejectAsync(pb) : PPCRejectSync(pb))
#define PPCWrite(pb, async) ((async) ? PPCWriteAsync(pb) : PPCWriteSync(pb))
#define PPCRead(pb, async) ((async) ? PPCReadAsync(pb) : PPCReadSync(pb))
#define PPCEnd(pb, async) ((async) ? PPCEndAsync(pb) : PPCEndSync(pb))
#define PPCClose(pb, async) ((async) ? PPCCloseAsync(pb) : PPCCloseSync(pb))
#define IPCListPorts(pb, async) \
  ((async) ? IPCListPortsAsync(pb) : IPCListPortsSync(pb))

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

#endif /* __PPCTOOLBOX__ */
Sync(pb))
#define PPCInform(pb, async) ((async) ? PPCInformAsync(pb) : PPCInformSync(pb))
#define PPCStart(pb, async) ((async) ? PPCStartAsync(pb) : PPCStartSync(pb))
#define PPCAccept(pb, async) ((async) ? PPCAcceptAsync(pb) : PPCAcceptSync(pb))
#define PPCReject(pb, async) ((async) ? PPCRejectAsync(pb) : PPCRejectSync(pb))
#define PPCWrite(pb, async) ((async) ? PPCWriteAsync(pb) : PPCWriteSync(pb))
#define PPCRead(pb, async) ((async) ? PPCReadAsync(pb) : PPCReadSync(pb))
#define PPCEnd(pb, async) ((async) ? PPCEndAsync(pb) : PPCEndSync(pb))
#define PPCClose(pb, async) ((async) ? PPCCloseAsync(pb) : PPCCloseSync(pb))
#define IPCListPorts(pb, async) \
  ((async) ? IPCListPortsAsync(pb) : IPCListPortsSync(pb))

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

#endif /* __PPCTOOLBOX__ */
seAsync(pb) : PPCCloseSync(pb))
#define IPCListPorts(pb, async) \
  ((async) ? IPCListPortsAsync(pb) : IPCListPortsSync(pb))

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

#endif /* __PPCTOOLBOX__ */
CListPortsSync(pb))

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

#endif /* __PPCTOOLBOX__ */
align = reset
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

#endif /* __PPCTOOLBOX__ */
}
#endif

#endif /* __PPCTOOLBOX__ */
align = reset
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

#endif /* __PPCTOOLBOX__ */
ma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __PPCTOOLBOX__ */
}
#endif

#endif /* __PPCTOOLBOX__ */
align = reset
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

#endif /* __PPCTOOLBOX__ */
dif    /* __PPCTOOLBOX__ */
    ma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __PPCTOOLBOX__ */
}
#endif

#endif /* __PPCTOOLBOX__ */
align = reset
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

#endif /* __PPCTOOLBOX__ */
import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
    }
#endif

#endif /* __PPCTOOLBOX__ */

}
#endif

#endif /* __PPCTOOLBOX__ */
align = reset
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

#endif /* __PPCTOOLBOX__ */
agma import reset
#endif

#ifdef __cplusplus
    }
#endif

#endif /* __PPCTOOLBOX__ */
import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
    }
#endif

#endif /* __PPCTOOLBOX__ */

}
#endif

#endif /* __PPCTOOLBOX__ */
align = reset
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

#endif /* __PPCTOOLBOX__ */
reset
#endif

#ifdef __cplusplus
    }
#endif

#endif /* __PPCTOOLBOX__ */

}
#endif

#endif /* __PPCTOOLBOX__ */
align = reset
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

#endif /* __PPCTOOLBOX__ */
