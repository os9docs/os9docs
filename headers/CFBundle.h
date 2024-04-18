/**
     \file       CFBundle.h

    \brief   CoreFoundation bundle

    \introduced_in  Mac OS X
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1999-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CFBUNDLE__
#define __CFBUNDLE__

#ifndef __CFBASE__
#include <CFBase.h>
#endif

#ifndef __CFARRAY__
#include <CFArray.h>
#endif

#ifndef __CFDICTIONARY__
#include <CFDictionary.h>
#endif

#ifndef __CFSTRING__
#include <CFString.h>
#endif

#ifndef __CFURL__
#include <CFURL.h>
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

typedef struct __CFBundle *CFBundleRef;
typedef struct __CFBundle *CFPlugInRef;
/** ===================== Standard Info.plist keys ===================== */
/**
 *  kCFBundleInfoDictionaryVersionKey
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFStringRef kCFBundleInfoDictionaryVersionKey;
/** The version of the Info.plist format */
/**
 *  kCFBundleExecutableKey
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFStringRef kCFBundleExecutableKey;
/** The name of the executable in this bundle (if any) */
/**
 *  kCFBundleIdentifierKey
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFStringRef kCFBundleIdentifierKey;
/** The bundle identifier (for CFBundleGetBundleWithIdentifier()) */
/**
 *  kCFBundleVersionKey
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFStringRef kCFBundleVersionKey;
/** The version number of the bundle.  Clients should use
   CFBundleGetVersionNumber() instead of accessing this key directly since that
   function will properly convert a version number in string format into its
   interger representation. */
/**
 *  kCFBundleDevelopmentRegionKey
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFStringRef kCFBundleDevelopmentRegionKey;
/** The name of the development language of the bundle. */
/**
 *  kCFBundleNameKey
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFStringRef kCFBundleNameKey;
/** The human-readable name of the bundle.  This key is often found in the
 * InfoPlist.strings since it is usually localized. */
/** ===================== Finding Bundles ===================== */
/**
 *  CFBundleGetMainBundle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFBundleRef)
CFBundleGetMainBundle(void);

/**
 *  CFBundleGetBundleWithIdentifier()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFBundleRef)
CFBundleGetBundleWithIdentifier(CFStringRef bundleID);

/** A bundle can name itself by providing a key in the info dictionary. */
/** This facility is meant to allow bundle-writers to get hold of their */
/** bundle from their code without having to know where it was on the disk. */
/** This is meant to be a replacement mechanism for +bundleForClass: users. */
/**
 *  CFBundleGetAllBundles()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFArrayRef)
CFBundleGetAllBundles(void);

/** This is potentially expensive.  Use with care. */
/** ===================== Creating Bundles ===================== */
/**
 *  CFBundleGetTypeID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt32)
CFBundleGetTypeID(void);

/**
 *  CFBundleCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFBundleRef)
CFBundleCreate(CFAllocatorRef allocator, CFURLRef bundleURL);

/** Might return an existing instance with the ref-count bumped. */
/**
 *  CFBundleCreateBundlesFromDirectory()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFArrayRef)
CFBundleCreateBundlesFromDirectory(CFAllocatorRef allocator,
                                   CFURLRef directoryURL,
                                   CFStringRef bundleType);

/** Create instances for all bundles in the given directory matching the given
 */
/** type (or all of them if bundleType is NULL) */
/** ==================== Basic Bundle Info ==================== */
/**
 *  CFBundleCopyBundleURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopyBundleURL(CFBundleRef bundle);

/**
 *  CFBundleGetValueForInfoDictionaryKey()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTypeRef)
CFBundleGetValueForInfoDictionaryKey(CFBundleRef bundle, CFStringRef key);

/** Returns a localized value if available, otherwise the global value. */
/**
 *  CFBundleGetInfoDictionary()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFDictionaryRef)
CFBundleGetInfoDictionary(CFBundleRef bundle);

/** This is the global info dictionary.  Note that CFBundle may add */
/** extra keys to the dictionary for its own use. */
/**
 *  CFBundleGetLocalInfoDictionary()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFDictionaryRef)
CFBundleGetLocalInfoDictionary(CFBundleRef bundle);

/** This is the localized info dictionary. */
/**
 *  CFBundleGetPackageInfo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBundleGetPackageInfo(CFBundleRef bundle, UInt32 *packageType,
                       UInt32 *packageCreator);

/**
 *  CFBundleGetIdentifier()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFStringRef)
CFBundleGetIdentifier(CFBundleRef bundle);

/**
 *  CFBundleGetVersionNumber()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt32)
CFBundleGetVersionNumber(CFBundleRef bundle);

/**
 *  CFBundleGetDevelopmentRegion()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFStringRef)
CFBundleGetDevelopmentRegion(CFBundleRef bundle);

/**
 *  CFBundleCopySupportFilesDirectoryURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopySupportFilesDirectoryURL(CFBundleRef bundle);

/**
 *  CFBundleCopyResourcesDirectoryURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopyResourcesDirectoryURL(CFBundleRef bundle);

/**
 *  CFBundleCopyPrivateFrameworksURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopyPrivateFrameworksURL(CFBundleRef bundle);

/**
 *  CFBundleCopySharedFrameworksURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopySharedFrameworksURL(CFBundleRef bundle);

/**
 *  CFBundleCopySharedSupportURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopySharedSupportURL(CFBundleRef bundle);

/**
 *  CFBundleCopyBuiltInPlugInsURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopyBuiltInPlugInsURL(CFBundleRef bundle);

/** ------------- Basic Bundle Info without a CFBundle instance ------------- */
/** This API is provided to enable developers to retrieve basic information */
/** about a bundle without having to create an instance of CFBundle. */
/**
 *  CFBundleCopyInfoDictionaryInDirectory()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFDictionaryRef)
CFBundleCopyInfoDictionaryInDirectory(CFURLRef bundleURL);

/**
 *  CFBundleGetPackageInfoInDirectory()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CFBundleGetPackageInfoInDirectory(CFURLRef url, UInt32 *packageType,
                                  UInt32 *packageCreator);

/** ==================== Resource Handling API ==================== */
/**
 *  CFBundleCopyResourceURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopyResourceURL(CFBundleRef bundle, CFStringRef resourceName,
                        CFStringRef resourceType, CFStringRef subDirName);

/**
 *  CFBundleCopyResourceURLsOfType()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFArrayRef)
CFBundleCopyResourceURLsOfType(CFBundleRef bundle, CFStringRef resourceType,
                               CFStringRef subDirName);

/**
 *  CFBundleCopyLocalizedString()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFStringRef)
CFBundleCopyLocalizedString(CFBundleRef bundle, CFStringRef key,
                            CFStringRef value, CFStringRef tableName);

#define CFCopyLocalizedString(key, comment)                                    \
  CFBundleCopyLocalizedString(CFBundleGetMainBundle(), (key), (key), NULL)
#define CFCopyLocalizedStringFromTable(key, tbl, comment)                      \
  CFBundleCopyLocalizedString(CFBundleGetMainBundle(), (key), (key), (tbl))
#define CFCopyLocalizedStringFromTableInBundle(key, tbl, bundle, comment)      \
  CFBundleCopyLocalizedString((bundle), (key), (key), (tbl))
/** ------------- Resource Handling without a CFBundle instance ------------- */
/** This API is provided to enable developers to use the CFBundle resource */
/** searching policy without having to create an instance of CFBundle. */
/** Because of caching behavior when a CFBundle instance exists, it will be
 * faster */
/** to actually create a CFBundle if you need to access several resources. */
/**
 *  CFBundleCopyResourceURLInDirectory()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopyResourceURLInDirectory(CFURLRef bundleURL, CFStringRef resourceName,
                                   CFStringRef resourceType,
                                   CFStringRef subDirName);

/**
 *  CFBundleCopyResourceURLsOfTypeInDirectory()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFArrayRef)
CFBundleCopyResourceURLsOfTypeInDirectory(CFURLRef bundleURL,
                                          CFStringRef resourceType,
                                          CFStringRef subDirName);

/** =========== Localization-specific Resource Handling API =========== */
/** This API allows finer-grained control over specific localizations,  */
/** as distinguished from the above API, which always uses the user's   */
/** preferred localizations.  */
/**
 *  CFBundleCopyBundleLocalizations()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFArrayRef)
CFBundleCopyBundleLocalizations(CFBundleRef bundle);

/** Lists the localizations that a bundle contains.  */
/**
 *  CFBundleCopyPreferredLocalizationsFromArray()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFArrayRef)
CFBundleCopyPreferredLocalizationsFromArray(CFArrayRef locArray);

/** Given an array of possible localizations, returns the one or more */
/** that CFBundle would use in the current context. To find out which */
/** localizations are in use for a particular bundle, apply this to   */
/** the result of CFBundleCopyBundleLocalizations.  */
/**
 *  CFBundleCopyResourceURLForLocalization()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopyResourceURLForLocalization(CFBundleRef bundle,
                                       CFStringRef resourceName,
                                       CFStringRef resourceType,
                                       CFStringRef subDirName,
                                       CFStringRef localizationName);

/**
 *  CFBundleCopyResourceURLsOfTypeForLocalization()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFArrayRef)
CFBundleCopyResourceURLsOfTypeForLocalization(CFBundleRef bundle,
                                              CFStringRef resourceType,
                                              CFStringRef subDirName,
                                              CFStringRef localizationName);

/** ==================== Primitive Code Loading API ==================== */
/** This API abstracts the various different executable formats supported on */
/** various platforms.  It can load DYLD, CFM, or DLL shared libraries (on their
 */
/** appropriate platforms) and gives a uniform API for looking up functions. */
/** Note that Cocoa-based bundles containing Objective-C or Java code must */
/** be loaded with NSBundle, not CFBundle.  Once they are loaded, however, */
/** either CFBundle or NSBundle can be used. */
/**
 *  CFBundleCopyExecutableURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopyExecutableURL(CFBundleRef bundle);

/**
 *  CFBundleIsExecutableLoaded()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CFBundleIsExecutableLoaded(CFBundleRef bundle);

/**
 *  CFBundleLoadExecutable()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CFBundleLoadExecutable(CFBundleRef bundle);

/**
 *  CFBundleUnloadExecutable()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBundleUnloadExecutable(CFBundleRef bundle);

/**
 *  CFBundleGetFunctionPointerForName()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void *)
CFBundleGetFunctionPointerForName(CFBundleRef bundle, CFStringRef functionName);

/**
 *  CFBundleGetFunctionPointersForNames()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBundleGetFunctionPointersForNames(CFBundleRef bundle,
                                    CFArrayRef functionNames, void *ftbl[]);

/**
 *  CFBundleGetDataPointerForName()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void *)
CFBundleGetDataPointerForName(CFBundleRef bundle, CFStringRef symbolName);

/**
 *  CFBundleGetDataPointersForNames()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBundleGetDataPointersForNames(CFBundleRef bundle, CFArrayRef symbolNames,
                                void *stbl[]);

/**
 *  CFBundleCopyAuxiliaryExecutableURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFURLRef)
CFBundleCopyAuxiliaryExecutableURL(CFBundleRef bundle,
                                   CFStringRef executableName);

/** This function can be used to find executables other than your main */
/** executable.  This is useful, for instance, for applications that have */
/** some command line tool that is packaged with and used by the application. */
/** The tool can be packaged in the various platform executable directories */
/** in the bundle and can be located with this function.  This allows an */
/** app to ship versions of the tool for each platform as it does for the */
/** main app executable. */
/** ==================== Getting a bundle's plugIn ==================== */
/**
 *  CFBundleGetPlugIn()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFPlugInRef)
CFBundleGetPlugIn(CFBundleRef bundle);

/** ==================== Resource Manager-Related API ==================== */
/**
 *  CFBundleOpenBundleResourceMap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(short)
CFBundleOpenBundleResourceMap(CFBundleRef bundle);

/** This function opens the non-localized and the localized resource files */
/** (if any) for the bundle, creates and makes current a single read-only */
/** resource map combining both, and returns a reference number for it. */
/** If it is called multiple times, it opens the files multiple times, */
/** and returns distinct reference numbers.  */
/**
 *  CFBundleOpenBundleResourceFiles()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt32)
CFBundleOpenBundleResourceFiles(CFBundleRef bundle, short *refNum,
                                short *localizedRefNum);

/** Similar to CFBundleOpenBundleResourceMap, except that it creates two */
/** separate resource maps and returns reference numbers for both. */
/**
 *  CFBundleCloseBundleResourceMap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBundleCloseBundleResourceMap(CFBundleRef bundle, short refNum);

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

#endif /** __CFBUNDLE__ */
