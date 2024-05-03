/**
     \file       KeychainCore.h

    \brief   Keychain low-level Interfaces

    \introduced_in  Keychain 3.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 2000-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Keychain

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __KEYCHAINCORE__
#define __KEYCHAINCORE__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __ALIASES__
#include <Aliases.h>
#endif

#ifndef __CODEFRAGMENTS__
#include <CodeFragments.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __PROCESSES__
#include <Processes.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
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

/** Data structures and types */
#ifndef __SEC_TYPES__
#define __SEC_TYPES__
  typedef struct OpaqueSecKeychainRef *SecKeychainRef;
  typedef struct OpaqueSecKeychainItemRef *SecKeychainItemRef;
  typedef struct OpaqueSecKeychainSearchRef *SecKeychainSearchRef;
  typedef OSType SecKeychainAttrType;
  typedef UInt32 SecKeychainStatus;
  struct SecKeychainAttribute
  {
    SecKeychainAttrType tag; /** 4-byte attribute tag */
    UInt32 length;           /** Length of attribute data */
    void *data;              /** Pointer to attribute data */
  };
  typedef struct SecKeychainAttribute SecKeychainAttribute;
  typedef SecKeychainAttribute *SecKeychainAttributePtr;
  struct SecKeychainAttributeList
  {
    UInt32 count;               /** How many attributes in the array */
    SecKeychainAttribute *attr; /** Pointer to first attribute in array */
  };
  typedef struct SecKeychainAttributeList SecKeychainAttributeList;
#endif

  typedef SecKeychainRef KCRef;
  typedef SecKeychainItemRef KCItemRef;
  typedef SecKeychainSearchRef KCSearchRef;
  typedef SecKeychainAttribute KCAttribute;
  typedef SecKeychainAttributeList KCAttributeList;
  typedef SecKeychainAttrType KCAttrType;
  typedef SecKeychainStatus KCStatus;
  typedef UInt16 KCEvent;
  enum
  {
    kIdleKCEvent = 0,                /** null event */
    kLockKCEvent = 1,                /** a keychain was locked */
    kUnlockKCEvent = 2,              /** a keychain was unlocked */
    kAddKCEvent = 3,                 /** an item was added to a keychain */
    kDeleteKCEvent = 4,              /** an item was deleted from a keychain */
    kUpdateKCEvent = 5,              /** an item was updated */
    kPasswordChangedKCEvent = 6,     /** the keychain identity was changed */
    kSystemKCEvent = 8,              /** the keychain client can process events */
    kDefaultChangedKCEvent = 9,      /** the default keychain was changed */
    kDataAccessKCEvent = 10,         /** a process has accessed a keychain item's data */
    kKeychainListChangedKCEvent = 11 /** the list of keychains has changed */
  };

  typedef UInt16 KCEventMask;
  enum
  {
    kIdleKCEventMask = 1 << kIdleKCEvent,
    kLockKCEventMask = 1 << kLockKCEvent,
    kUnlockKCEventMask = 1 << kUnlockKCEvent,
    kAddKCEventMask = 1 << kAddKCEvent,
    kDeleteKCEventMask = 1 << kDeleteKCEvent,
    kUpdateKCEventMask = 1 << kUpdateKCEvent,
    kPasswordChangedKCEventMask = 1 << kPasswordChangedKCEvent,
    kSystemEventKCEventMask = 1 << kSystemKCEvent,
    kDefaultChangedKCEventMask = 1 << kDefaultChangedKCEvent,
    kDataAccessKCEventMask = 1 << kDataAccessKCEvent,
    kEveryKCEventMask = 0xFFFF /** all of the above*/
  };

  typedef UInt8 AFPServerSignature[16];
  typedef UInt8 KCPublicKeyHash[20];
  struct KCCallbackInfo
  {
    UInt32 version;
    KCItemRef item;
    ProcessSerialNumber processID;
    EventRecord event;
    KCRef keychain;
  };
  typedef struct KCCallbackInfo KCCallbackInfo;
  enum
  {
    kUnlockStateKCStatus = 1,
    kRdPermKCStatus = 2,
    kWrPermKCStatus = 4
  };

  enum
  {
    kCertificateKCItemClass = FOUR_CHAR_CODE('cert'), /** Certificate */
    kAppleSharePasswordKCItemClass =
        FOUR_CHAR_CODE('ashp'), /** Appleshare password */
    kInternetPasswordKCItemClass =
        FOUR_CHAR_CODE('inet'),                          /** Internet password */
    kGenericPasswordKCItemClass = FOUR_CHAR_CODE('genp') /** Generic password */
  };

  typedef FourCharCode KCItemClass;
  enum
  {
    /** Common attributes */
    kClassKCItemAttr = FOUR_CHAR_CODE('clas'), /** Item class (KCItemClass) */
    kCreationDateKCItemAttr =
        FOUR_CHAR_CODE('cdat'), /** Date the item was created (UInt32) */
    kModDateKCItemAttr =
        FOUR_CHAR_CODE('mdat'), /** Last time the item was updated (UInt32) */
    kDescriptionKCItemAttr =
        FOUR_CHAR_CODE('desc'), /** User-visible description string (string) */
    kCommentKCItemAttr =
        FOUR_CHAR_CODE('icmt'),                  /** User's comment about the item (string) */
    kCreatorKCItemAttr = FOUR_CHAR_CODE('crtr'), /** Item's creator (OSType) */
    kTypeKCItemAttr = FOUR_CHAR_CODE('type'),    /** Item's type (OSType) */
    kScriptCodeKCItemAttr =
        FOUR_CHAR_CODE('scrp'),                     /** Script code for all strings (ScriptCode) */
    kLabelKCItemAttr = FOUR_CHAR_CODE('labl'),      /** Item label (string) */
    kInvisibleKCItemAttr = FOUR_CHAR_CODE('invi'),  /** Invisible (boolean) */
    kNegativeKCItemAttr = FOUR_CHAR_CODE('nega'),   /** Negative (boolean) */
    kCustomIconKCItemAttr = FOUR_CHAR_CODE('cusi'), /** Custom icon (boolean) */
    kAccountKCItemAttr = FOUR_CHAR_CODE('acct'),    /** User account (string) */
    /** Unique Generic password attributes */
    kServiceKCItemAttr = FOUR_CHAR_CODE('svce'), /** Service (string) */
    kGenericKCItemAttr =
        FOUR_CHAR_CODE('gena'), /** User-defined attribute (untyped bytes) */
                                /** Unique Internet password attributes */
    kSecurityDomainKCItemAttr =
        FOUR_CHAR_CODE('sdmn'), /** Security domain (string) */
    kServerKCItemAttr =
        FOUR_CHAR_CODE('srvr'), /** Server's domain name or IP address (string) */
    kAuthTypeKCItemAttr =
        FOUR_CHAR_CODE('atyp'),               /** Authentication Type (KCAuthType) */
    kPortKCItemAttr = FOUR_CHAR_CODE('port'), /** Port (UInt16) */
    kPathKCItemAttr = FOUR_CHAR_CODE('path'), /** Path (string) */
    /** Unique Appleshare password attributes */
    kVolumeKCItemAttr = FOUR_CHAR_CODE('vlme'), /** Volume (string) */
    kAddressKCItemAttr = FOUR_CHAR_CODE(
        'addr'), /** Server address (IP or domain name) or zone name (string) */
    kSignatureKCItemAttr =
        FOUR_CHAR_CODE('ssig'),                   /** Server signature block (AFPServerSignature) */
                                                  /** Unique AppleShare and Internet attributes */
    kProtocolKCItemAttr = FOUR_CHAR_CODE('ptcl'), /** Protocol (KCProtocolType) */
                                                  /** Certificate attributes */
    kSubjectKCItemAttr = FOUR_CHAR_CODE(
        'subj'), /** Subject distinguished name (DER-encoded data) */
    kCommonNameKCItemAttr =
        FOUR_CHAR_CODE('cn  '), /** Common Name (UTF8-encoded string) */
    kIssuerKCItemAttr = FOUR_CHAR_CODE(
        'issu'), /** Issuer distinguished name (DER-encoded data) */
    kSerialNumberKCItemAttr = FOUR_CHAR_CODE(
        'snbr'), /** Certificate serial number (DER-encoded data) */
    kEMailKCItemAttr =
        FOUR_CHAR_CODE('mail'), /** E-mail address (ASCII-encoded string) */
    kPublicKeyHashKCItemAttr = FOUR_CHAR_CODE(
        'hpky'), /** Hash of public key (KCPublicKeyHash), 20 bytes max. */
    kIssuerURLKCItemAttr = FOUR_CHAR_CODE(
        'iurl'),                                   /** URL of the certificate issuer (ASCII-encoded string) */
                                                   /** Shared by keys and certificates */
    kEncryptKCItemAttr = FOUR_CHAR_CODE('encr'),   /** Encrypt (Boolean) */
    kDecryptKCItemAttr = FOUR_CHAR_CODE('decr'),   /** Decrypt (Boolean) */
    kSignKCItemAttr = FOUR_CHAR_CODE('sign'),      /** Sign (Boolean) */
    kVerifyKCItemAttr = FOUR_CHAR_CODE('veri'),    /** Verify (Boolean) */
    kWrapKCItemAttr = FOUR_CHAR_CODE('wrap'),      /** Wrap (Boolean) */
    kUnwrapKCItemAttr = FOUR_CHAR_CODE('unwr'),    /** Unwrap (Boolean) */
    kStartDateKCItemAttr = FOUR_CHAR_CODE('sdat'), /** Start Date (UInt32) */
    kEndDateKCItemAttr = FOUR_CHAR_CODE('edat')    /** End Date (UInt32) */
  };

  typedef FourCharCode KCItemAttr;
  enum
  {
    kKCAuthTypeNTLM = FOUR_CHAR_CODE('ntlm'),
    kKCAuthTypeMSN = FOUR_CHAR_CODE('msna'),
    kKCAuthTypeDPA = FOUR_CHAR_CODE('dpaa'),
    kKCAuthTypeRPA = FOUR_CHAR_CODE('rpaa'),
    kKCAuthTypeHTTPDigest = FOUR_CHAR_CODE('httd'),
    kKCAuthTypeDefault = FOUR_CHAR_CODE('dflt')
  };

  typedef FourCharCode KCAuthType;
  enum
  {
    kKCProtocolTypeFTP = FOUR_CHAR_CODE('ftp '),
    kKCProtocolTypeFTPAccount = FOUR_CHAR_CODE('ftpa'),
    kKCProtocolTypeHTTP = FOUR_CHAR_CODE('http'),
    kKCProtocolTypeIRC = FOUR_CHAR_CODE('irc '),
    kKCProtocolTypeNNTP = FOUR_CHAR_CODE('nntp'),
    kKCProtocolTypePOP3 = FOUR_CHAR_CODE('pop3'),
    kKCProtocolTypeSMTP = FOUR_CHAR_CODE('smtp'),
    kKCProtocolTypeSOCKS = FOUR_CHAR_CODE('sox '),
    kKCProtocolTypeIMAP = FOUR_CHAR_CODE('imap'),
    kKCProtocolTypeLDAP = FOUR_CHAR_CODE('ldap'),
    kKCProtocolTypeAppleTalk = FOUR_CHAR_CODE('atlk'),
    kKCProtocolTypeAFP = FOUR_CHAR_CODE('afp '),
    kKCProtocolTypeTelnet = FOUR_CHAR_CODE('teln')
  };

  typedef FourCharCode KCProtocolType;
  typedef UInt32 KCCertAddOptions;
  enum
  {
    kSecOptionReserved =
        0x000000FF,      /** First byte reserved for SecOptions flags */
    kCertUsageShift = 8, /** start at bit 8 */
    kCertUsageSigningAdd = 1 << (kCertUsageShift + 0),
    kCertUsageSigningAskAndAdd = 1 << (kCertUsageShift + 1),
    kCertUsageVerifyAdd = 1 << (kCertUsageShift + 2),
    kCertUsageVerifyAskAndAdd = 1 << (kCertUsageShift + 3),
    kCertUsageEncryptAdd = 1 << (kCertUsageShift + 4),
    kCertUsageEncryptAskAndAdd = 1 << (kCertUsageShift + 5),
    kCertUsageDecryptAdd = 1 << (kCertUsageShift + 6),
    kCertUsageDecryptAskAndAdd = 1 << (kCertUsageShift + 7),
    kCertUsageKeyExchAdd = 1 << (kCertUsageShift + 8),
    kCertUsageKeyExchAskAndAdd = 1 << (kCertUsageShift + 9),
    kCertUsageRootAdd = 1 << (kCertUsageShift + 10),
    kCertUsageRootAskAndAdd = 1 << (kCertUsageShift + 11),
    kCertUsageSSLAdd = 1 << (kCertUsageShift + 12),
    kCertUsageSSLAskAndAdd = 1 << (kCertUsageShift + 13),
    kCertUsageAllAdd = 0x7FFFFF00
  };

  typedef UInt16 KCVerifyStopOn;
  enum
  {
    kPolicyKCStopOn = 0,
    kNoneKCStopOn = 1,
    kFirstPassKCStopOn = 2,
    kFirstFailKCStopOn = 3
  };

  typedef UInt32 KCCertSearchOptions;
  enum
  {
    kCertSearchShift = 0, /** start at bit 0 */
    kCertSearchSigningIgnored = 0,
    kCertSearchSigningAllowed = 1 << (kCertSearchShift + 0),
    kCertSearchSigningDisallowed = 1 << (kCertSearchShift + 1),
    kCertSearchSigningMask =
        ((kCertSearchSigningAllowed) | (kCertSearchSigningDisallowed)),
    kCertSearchVerifyIgnored = 0,
    kCertSearchVerifyAllowed = 1 << (kCertSearchShift + 2),
    kCertSearchVerifyDisallowed = 1 << (kCertSearchShift + 3),
    kCertSearchVerifyMask =
        ((kCertSearchVerifyAllowed) | (kCertSearchVerifyDisallowed)),
    kCertSearchEncryptIgnored = 0,
    kCertSearchEncryptAllowed = 1 << (kCertSearchShift + 4),
    kCertSearchEncryptDisallowed = 1 << (kCertSearchShift + 5),
    kCertSearchEncryptMask =
        ((kCertSearchEncryptAllowed) | (kCertSearchEncryptDisallowed)),
    kCertSearchDecryptIgnored = 0,
    kCertSearchDecryptAllowed = 1 << (kCertSearchShift + 6),
    kCertSearchDecryptDisallowed = 1 << (kCertSearchShift + 7),
    kCertSearchDecryptMask =
        ((kCertSearchDecryptAllowed) | (kCertSearchDecryptDisallowed)),
    kCertSearchWrapIgnored = 0,
    kCertSearchWrapAllowed = 1 << (kCertSearchShift + 8),
    kCertSearchWrapDisallowed = 1 << (kCertSearchShift + 9),
    kCertSearchWrapMask =
        ((kCertSearchWrapAllowed) | (kCertSearchWrapDisallowed)),
    kCertSearchUnwrapIgnored = 0,
    kCertSearchUnwrapAllowed = 1 << (kCertSearchShift + 10),
    kCertSearchUnwrapDisallowed = 1 << (kCertSearchShift + 11),
    kCertSearchUnwrapMask =
        ((kCertSearchUnwrapAllowed) | (kCertSearchUnwrapDisallowed)),
    kCertSearchPrivKeyRequired = 1 << (kCertSearchShift + 12),
    kCertSearchAny = 0
  };

  /** Other constants */
  enum
  {
    kAnyPort = 0
  };

  enum
  {
    kAnyProtocol = 0,
    kAnyAuthType = 0
  };

  /** Opening and getting information about the Keychain Manager */
  /**
   *  KCGetKeychainManagerVersion()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         not available
   */
  OSStatus
  KCGetKeychainManagerVersion(UInt32 *returnVers);

#if TARGET_RT_MAC_CFM
#ifdef __cplusplus
  inline pascal Boolean KeychainManagerAvailable()
  {
    return (
        (KCGetKeychainManagerVersion != (void *)kUnresolvedCFragSymbolAddress) &&
        (KCGetKeychainManagerVersion(nil) != cfragNoSymbolErr));
  }
#else
#define KeychainManagerAvailable()                                           \
  ((KCGetKeychainManagerVersion != (void *)kUnresolvedCFragSymbolAddress) && \
   (KCGetKeychainManagerVersion(nil) != cfragNoSymbolErr))
#endif
#elif TARGET_RT_MAC_MACHO
/** Keychain is always available on OS X */
#ifdef __cplusplus
inline pascal Boolean KeychainManagerAvailable() { return true; }
#else
#define KeychainManagerAvailable() (true)
#endif
#endif /**  */

  /** Managing the Human Interface */
  /**
   *  KCSetInteractionAllowed()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCSetInteractionAllowed(Boolean state);

  /**
   *  KCIsInteractionAllowed()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  KCIsInteractionAllowed(void);

  /** Creating references to keychains */
  /**
   *  KCMakeKCRefFromFSSpec()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCMakeKCRefFromFSSpec(FSSpec *keychainFSSpec, KCRef *keychain);

  /**
   *  KCMakeKCRefFromAlias()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCMakeKCRefFromAlias(AliasHandle keychainAlias, KCRef *keychain);

  /**
   *  KCMakeAliasFromKCRef()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCMakeAliasFromKCRef(KCRef keychain, AliasHandle *keychainAlias);

  /**
   *  KCReleaseKeychain()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCReleaseKeychain(KCRef *keychain);

  /** Specifying the default keychain */
  /**
   *  KCGetDefaultKeychain()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCGetDefaultKeychain(KCRef *keychain);

  /**
   *  KCSetDefaultKeychain()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCSetDefaultKeychain(KCRef keychain);

  /** Getting information about a keychain */
  /**
   *  KCGetStatus()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCGetStatus(KCRef keychain, /** can be NULL */
              UInt32 *keychainStatus);

  /**
   *  KCGetKeychain()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCGetKeychain(KCItemRef item, KCRef *keychain);

  /**
   *  KCGetKeychainName()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCGetKeychainName(KCRef keychain, StringPtr keychainName);

  /** Enumerating available keychains */
  /**
   *  KCCountKeychains()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt16
  KCCountKeychains(void);

  /**
   *  KCGetIndKeychain()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCGetIndKeychain(UInt16 index, KCRef *keychain);

  typedef CALLBACK_API(OSStatus, KCCallbackProcPtr)(KCEvent keychainEvent,
                                                    KCCallbackInfo *info,
                                                    void *userContext);
  typedef STACK_UPP_TYPE(KCCallbackProcPtr) KCCallbackUPP;
  /**
   *  NewKCCallbackUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  KCCallbackUPP
  NewKCCallbackUPP(KCCallbackProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppKCCallbackProcInfo = 0x00000FB0
  }; /** pascal 4_bytes Func(2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline KCCallbackUPP NewKCCallbackUPP(KCCallbackProcPtr userRoutine)
  {
    return (KCCallbackUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppKCCallbackProcInfo, GetCurrentArchitecture());
  }
#else
#define NewKCCallbackUPP(userRoutine)   \
  (KCCallbackUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppKCCallbackProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeKCCallbackUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeKCCallbackUPP(KCCallbackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeKCCallbackUPP(KCCallbackUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeKCCallbackUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeKCCallbackUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  InvokeKCCallbackUPP(KCEvent keychainEvent, KCCallbackInfo *info,
                      void *userContext, KCCallbackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeKCCallbackUPP(KCEvent keychainEvent, KCCallbackInfo *info,
                                      void *userContext, KCCallbackUPP userUPP)
  {
    return (OSStatus)CALL_THREE_PARAMETER_UPP(userUPP, uppKCCallbackProcInfo,
                                              keychainEvent, info, userContext);
  }
#else
#define InvokeKCCallbackUPP(keychainEvent, info, userContext, userUPP)  \
  (OSStatus) CALL_THREE_PARAMETER_UPP((userUPP), uppKCCallbackProcInfo, \
                                      (keychainEvent), (info), (userContext))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewKCCallbackProc(userRoutine) NewKCCallbackUPP(userRoutine)
#define CallKCCallbackProc(userRoutine, keychainEvent, info, userContext) \
  InvokeKCCallbackUPP(keychainEvent, info, userContext, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  /** Keychain Manager callbacks */
  /**
   *  KCAddCallback()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCAddCallback(KCCallbackUPP callbackProc, KCEventMask eventMask,
                void *userContext);

  /**
   *  KCRemoveCallback()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCRemoveCallback(KCCallbackUPP callbackProc);

  /** Creating and editing a keychain item */
  /**
   *  KCNewItem()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCNewItem(KCItemClass itemClass, OSType itemCreator, UInt32 length,
            const void *data, KCItemRef *item);

  /**
   *  KCSetAttribute()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCSetAttribute(KCItemRef item, KCAttribute *attr);

  /**
   *  KCGetAttribute()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCGetAttribute(KCItemRef item, KCAttribute *attr, UInt32 *actualLength);

  /**
   *  KCSetData()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCSetData(KCItemRef item, UInt32 length, const void *data);

  /** Managing keychain items */
  /**
   *  KCUpdateItem()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCUpdateItem(KCItemRef item);

  /**
   *  KCReleaseItem()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCReleaseItem(KCItemRef *item);

  /**
   *  KCCopyItem()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCCopyItem(KCItemRef item, KCRef destKeychain, KCItemRef *copy);

  /** Searching and enumerating keychain items */
  /**
   *  KCFindFirstItem()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCFindFirstItem(KCRef keychain,                  /** can be NULL */
                  const KCAttributeList *attrList, /** can be NULL */
                  KCSearchRef *search, KCItemRef *item);

  /**
   *  KCFindNextItem()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCFindNextItem(KCSearchRef search, KCItemRef *item);

  /**
   *  KCReleaseSearch()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCReleaseSearch(KCSearchRef *search);

  /** Routines that use "C" strings */
  /**
   *  kcgetkeychainname()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  kcgetkeychainname(KCRef keychain, char *keychainName);

  /** Managing keychain items */
  /**
   *  KCDeleteItem()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCDeleteItem(KCItemRef item);

  /**
   *  KCGetData()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCGetData(KCItemRef item, UInt32 maxLength, void *data, UInt32 *actualLength);

  /** Storing and retrieving AppleShare passwords */
  /**
   *  KCAddAppleSharePassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCAddAppleSharePassword(AFPServerSignature *serverSignature,
                          StringPtr serverAddress, StringPtr serverName,
                          StringPtr volumeName, StringPtr accountName,
                          UInt32 passwordLength, const void *passwordData,
                          KCItemRef *item); /** can be NULL */

  /**
   *  KCFindAppleSharePassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCFindAppleSharePassword(AFPServerSignature *serverSignature, /** can be NULL */
                           StringPtr serverAddress,             /** can be NULL */
                           StringPtr serverName,                /** can be NULL */
                           StringPtr volumeName,                /** can be NULL */
                           StringPtr accountName,               /** can be NULL */
                           UInt32 maxLength, void *passwordData,
                           UInt32 *actualLength,
                           KCItemRef *item); /** can be NULL */

  /** Storing and retrieving Internet passwords */
  /**
   *  KCAddInternetPassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCAddInternetPassword(StringPtr serverName, StringPtr securityDomain,
                        StringPtr accountName, UInt16 port, OSType protocol,
                        OSType authType, UInt32 passwordLength,
                        const void *passwordData,
                        KCItemRef *item); /** can be NULL */

  /**
   *  KCAddInternetPasswordWithPath()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCAddInternetPasswordWithPath(StringPtr serverName, StringPtr securityDomain,
                                StringPtr accountName, StringPtr path,
                                UInt16 port, OSType protocol, OSType authType,
                                UInt32 passwordLength, const void *passwordData,
                                KCItemRef *item); /** can be NULL */

  /**
   *  KCFindInternetPassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCFindInternetPassword(StringPtr serverName,     /** can be NULL */
                         StringPtr securityDomain, /** can be NULL */
                         StringPtr accountName,    /** can be NULL */
                         UInt16 port, OSType protocol, OSType authType,
                         UInt32 maxLength, void *passwordData,
                         UInt32 *actualLength,
                         KCItemRef *item); /** can be NULL */

  /**
   *  KCFindInternetPasswordWithPath()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCFindInternetPasswordWithPath(StringPtr serverName,     /** can be NULL */
                                 StringPtr securityDomain, /** can be NULL */
                                 StringPtr accountName,    /** can be NULL */
                                 StringPtr path,           /** can be NULL */
                                 UInt16 port, OSType protocol, OSType authType,
                                 UInt32 maxLength, void *passwordData,
                                 UInt32 *actualLength,
                                 KCItemRef *item); /** can be NULL */

  /** Storing and retrieving other types of passwords */
  /**
   *  KCAddGenericPassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCAddGenericPassword(StringPtr serviceName, StringPtr accountName,
                       UInt32 passwordLength, const void *passwordData,
                       KCItemRef *item); /** can be NULL */

  /**
   *  KCFindGenericPassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCFindGenericPassword(StringPtr serviceName, /** can be NULL */
                        StringPtr accountName, /** can be NULL */
                        UInt32 maxLength, void *passwordData,
                        UInt32 *actualLength, KCItemRef *item); /** can be NULL */

  /**
   *  KCLock()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  KCLock(KCRef keychain);

  /** Routines that use "C" strings */
  /**
   *  kcaddapplesharepassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  kcaddapplesharepassword(AFPServerSignature *serverSignature,
                          const char *serverAddress, const char *serverName,
                          const char *volumeName, const char *accountName,
                          UInt32 passwordLength, const void *passwordData,
                          KCItemRef *item); /** can be NULL */

  /**
   *  kcfindapplesharepassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  kcfindapplesharepassword(AFPServerSignature *serverSignature, /** can be NULL */
                           const char *serverAddress,           /** can be NULL */
                           const char *serverName,              /** can be NULL */
                           const char *volumeName,              /** can be NULL */
                           const char *accountName,             /** can be NULL */
                           UInt32 maxLength, void *passwordData,
                           UInt32 *actualLength,
                           KCItemRef *item); /** can be NULL */

  /**
   *  kcaddinternetpassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  kcaddinternetpassword(const char *serverName, const char *securityDomain,
                        const char *accountName, UInt16 port, OSType protocol,
                        OSType authType, UInt32 passwordLength,
                        const void *passwordData,
                        KCItemRef *item); /** can be NULL */

  /**
   *  kcaddinternetpasswordwithpath()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  kcaddinternetpasswordwithpath(const char *serverName,
                                const char *securityDomain,
                                const char *accountName, const char *path,
                                UInt16 port, OSType protocol, OSType authType,
                                UInt32 passwordLength, const void *passwordData,
                                KCItemRef *item); /** can be NULL */

  /**
   *  kcfindinternetpassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  kcfindinternetpassword(const char *serverName,     /** can be NULL */
                         const char *securityDomain, /** can be NULL */
                         const char *accountName,    /** can be NULL */
                         UInt16 port, OSType protocol, OSType authType,
                         UInt32 maxLength, void *passwordData,
                         UInt32 *actualLength,
                         KCItemRef *item); /** can be NULL */

  /**
   *  kcfindinternetpasswordwithpath()
   *

   *    \non_carbon_cfm   in KeychainLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  kcfindinternetpasswordwithpath(const char *serverName,     /** can be NULL */
                                 const char *securityDomain, /** can be NULL */
                                 const char *accountName,    /** can be NULL */
                                 const char *path,           /** can be NULL */
                                 UInt16 port, OSType protocol, OSType authType,
                                 UInt32 maxLength, void *passwordData,
                                 UInt32 *actualLength,
                                 KCItemRef *item); /** can be NULL */

  /**
   *  kcaddgenericpassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  kcaddgenericpassword(const char *serviceName, const char *accountName,
                       UInt32 passwordLength, const void *passwordData,
                       KCItemRef *item); /** can be NULL */

  /**
   *  kcfindgenericpassword()
   *

   *    \non_carbon_cfm   in KeychainLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  kcfindgenericpassword(const char *serviceName, /** can be NULL */
                        const char *accountName, /** can be NULL */
                        UInt32 maxLength, void *passwordData,
                        UInt32 *actualLength, KCItemRef *item); /** can be NULL */

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

#endif /** __KEYCHAINCORE__ */
