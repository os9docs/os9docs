/**
     \file       FileSigning.h

    \brief   Apple File Signing Interfaces.

    \introduced_in  1.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1999-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FILESIGNING__
#define __FILESIGNING__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __KEYCHAIN__
#include <Keychain.h>
#endif

#ifndef __CRYPTOMESSAGESYNTAX__
#include <CryptoMessageSyntax.h>
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

/* Data structures and types */
typedef SInt32 SecOptions;
enum {
  kSecOptionProgress = 1 << 0,
  kSecOptionShowVerifyUI = 1 << 1,
  kSecOptionNeverShowUI = 1 << 2,
  kCertUsageReserved =
      0x7FFFFF00 /* Last 3 bytes reserved for SecOptions flags */
};

typedef UInt32 SecSignatureType;
enum {
  kSecSignatureTypeRawPKCS7 = 0,
  kSecSignatureTypeCMS = 1,
  kSecSignatureTypePGP = 2 /* reserved but not implemented */
};

typedef UInt32 SecTrustPolicy;
enum { kSecTrustPolicyCodeSigning = 0, kSecTrustPolicyPersonalFileSigning = 1 };

struct SecProgressCallbackInfo {
  UInt32 version;
  UInt32 bytesProcessed;
  UInt32 totalBytes;
  UInt32 itemsRemainingToSign;
  UInt32 totalItemsToSign;
  UInt32 secondsRemaining;
  UInt32 secondsElapsed;
  UInt32 microSecondsPerByte;
  Str255 fileName;
};
typedef struct SecProgressCallbackInfo SecProgressCallbackInfo;
typedef CALLBACK_API(OSStatus, SecProgressCallbackProcPtr)(
    SecProgressCallbackInfo *callbackInfo, void *userContext);
typedef STACK_UPP_TYPE(SecProgressCallbackProcPtr) SecProgressCallbackUPP;
#if CALL_NOT_IN_CARBON
/**
 *  NewSecProgressCallbackUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(SecProgressCallbackUPP)
NewSecProgressCallbackUPP(SecProgressCallbackProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppSecProgressCallbackProcInfo = 0x000003F0
}; /* pascal 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
inline SecProgressCallbackUPP
NewSecProgressCallbackUPP(SecProgressCallbackProcPtr userRoutine) {
  return (SecProgressCallbackUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppSecProgressCallbackProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewSecProgressCallbackUPP(userRoutine)                                 \
  (SecProgressCallbackUPP) NewRoutineDescriptor(                               \
      (ProcPtr)(userRoutine), uppSecProgressCallbackProcInfo,                  \
      GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeSecProgressCallbackUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(void)
DisposeSecProgressCallbackUPP(SecProgressCallbackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeSecProgressCallbackUPP(SecProgressCallbackUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeSecProgressCallbackUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeSecProgressCallbackUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(OSStatus)
InvokeSecProgressCallbackUPP(SecProgressCallbackInfo *callbackInfo,
                             void *userContext, SecProgressCallbackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline OSStatus
InvokeSecProgressCallbackUPP(SecProgressCallbackInfo *callbackInfo,
                             void *userContext,
                             SecProgressCallbackUPP userUPP) {
  return (OSStatus)CALL_TWO_PARAMETER_UPP(
      userUPP, uppSecProgressCallbackProcInfo, callbackInfo, userContext);
}
#else
#define InvokeSecProgressCallbackUPP(callbackInfo, userContext, userUPP)       \
  (OSStatus) CALL_TWO_PARAMETER_UPP((userUPP), uppSecProgressCallbackProcInfo, \
                                    (callbackInfo), (userContext))
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewSecProgressCallbackProc(userRoutine)                                \
  NewSecProgressCallbackUPP(userRoutine)
#define CallSecProgressCallbackProc(userRoutine, callbackInfo, userContext)    \
  InvokeSecProgressCallbackUPP(callbackInfo, userContext, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  SecSetProgressCallback()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecSetProgressCallback(SecProgressCallbackUPP callbackProc, void *userContext);

/**
 *  SecRemoveProgressCallback()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecRemoveProgressCallback(SecProgressCallbackUPP callbackProc);

/**
 *  DefaultSecProgressCallbackProc()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
DefaultSecProgressCallbackProc(SecProgressCallbackInfo *info,
                               void *userContext);

#endif /* CALL_NOT_IN_CARBON */

enum { kSecDefaultSignatureResID = 1 };

#if CALL_NOT_IN_CARBON
/**
 *  SecMacSignFile()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecMacSignFile(FSSpec *theFile, KCItemRef signingCertificate, Handle sigH,
               SecOptions options, SecProgressCallbackUPP progressProc,
               void *userContext);

/**
 *  SecMacSignFileSimple()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecMacSignFileSimple(FSSpec *theFile, KCItemRef signingCertificate,
                     SecOptions options);

/**
 *  SecMacLoadSigPound()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecMacLoadSigPound(FSSpec *theFile, Handle *resHandle);

/**
 *  SecMacRemoveSignature()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecMacRemoveSignature(FSSpec *theFile, SecSignatureType signatureType,
                      SInt16 signatureToRemove);

/**
 *  SecMacRemoveAllSignatures()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecMacRemoveAllSignatures(FSSpec *theFile, SecSignatureType signatureType);

/**
 *  SecMacVerifyFile()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecMacVerifyFile(FSSpec *theFile, SecOptions options,
                 SecProgressCallbackUPP progressProc, void *userContext,
                 SInt16 signatureToVerify, CFArrayRef policyOIDs,
                 KCVerifyStopOn stopOn, SecSignerRef *signer);

/**
 *  SecMacVerifyFileSimple()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecMacVerifyFileSimple(FSSpec *theFile, SecOptions options,
                       SecTrustPolicy trustPolicy, SecSignerRef *signer);

/**
 *  SecMacHasSignature()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Boolean)
SecMacHasSignature(FSSpec *theFile, SecSignatureType signatureType);

/**
 *  SecMacFindSignatureToVerify()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecMacFindSignatureToVerify(FSSpec *theFile, SecSignatureType signatureType,
                            SInt16 *signatureToVerify);

/**
 *  SecMacGetDefaultPolicyOIDs()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CFArrayRef)
SecMacGetDefaultPolicyOIDs(SecTrustPolicy trustPolicy);

/**
 *  SecMacDisplaySigner()
 *
 *  Availability:
 *    \non_carbon_cfm   in FileSigningLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSStatus)
SecMacDisplaySigner(OSStatus inputErr, SecSignerRef signer,
                    Boolean alwaysShowUI, FSSpec *theFile);

/* Errors Codes */
#endif /* CALL_NOT_IN_CARBON */

enum {
  errSecTooManySigners = -13839,
  errSecSigningFailed = -13838,
  errSecCorruptSigPound = -13837,
  errSecNoSignatureFound = -13836
};

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

#endif /* __FILESIGNING__ */
