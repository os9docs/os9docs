/**
     \file       KeychainHI.h

    \brief   Keychain API's with Human Interfaces

    \introduced_in  Keychain 3.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 2000-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Keychain
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __KEYCHAINHI__
#define __KEYCHAINHI__

#ifndef __KEYCHAINCORE__
#include <KeychainCore.h>
#endif

#ifndef __CFSTRING__
#include <CFString.h>
#endif

#ifndef __CFARRAY__
#include <CFArray.h>
#endif

#ifndef __CFDATE__
#include <CFDate.h>
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

/** Locking and unlocking a keychain */
/**
 *  KCUnlock()
 *

 *    \non_carbon_cfm   in KeychainLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
KCUnlock(KCRef keychain,      /** can be NULL */
         StringPtr password); /** can be NULL */

/** Managing keychain items */
/**
 *  KCAddItem()
 *

 *    \non_carbon_cfm   in KeychainLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
KCAddItem(KCItemRef item);

/** Creating a new keychain */
/**
 *  KCCreateKeychain()
 *

 *    \non_carbon_cfm   in KeychainLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
KCCreateKeychain(StringPtr password, /** can be NULL */
                 KCRef *keychain);   /** can be NULL */

/** Changing a keychain's settings */
/**
 *  KCChangeSettings()
 *

 *    \non_carbon_cfm   in KeychainLib 2.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
KCChangeSettings(KCRef keychain);

/**
 *  kcunlock()
 *

 *    \non_carbon_cfm   in KeychainLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
kcunlock(KCRef keychain,        /** can be NULL */
         const char *password); /** can be NULL */

/**
 *  kccreatekeychain()
 *

 *    \non_carbon_cfm   in KeychainLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
kccreatekeychain(const char *password, /** can be NULL */
                 KCRef *keychain);     /** can be NULL */

/** Working with certificates */
#if CALL_NOT_IN_CARBON
/**
 *  KCFindX509Certificates()
 *

 *    \non_carbon_cfm   in KeychainLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
KCFindX509Certificates(KCRef keychain, CFStringRef name,
                       CFStringRef emailAddress, KCCertSearchOptions options,
                       CFMutableArrayRef *certificateItems); /** can be NULL */

/**
 *  KCChooseCertificate()
 *

 *    \non_carbon_cfm   in KeychainLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
KCChooseCertificate(CFArrayRef items, KCItemRef *certificate,
                    CFArrayRef policyOIDs, KCVerifyStopOn stopOn);

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

#endif /** __KEYCHAINHI__ */
