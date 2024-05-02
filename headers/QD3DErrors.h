/**
     \file       QD3DErrors.h

    \brief   Error API and error codes

    \introduced_in  Quickdraw 3D 1.6
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1995-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Quickdraw3D

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QD3DERRORS__
#define __QD3DERRORS__

#ifndef __QD3D__
#include <QD3D.h>
#endif

#if TARGET_OS_MAC
#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#endif // TARGET_OS_MAC 
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
#pragma options align = power
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __QD3DERRORS__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __QD3DERRORS__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

/******************************************************************************
 **                                                                          **
 **                         Error Types and Codes                            **
 **                                                                          **
 *****************************************************************************/
enum TQ3Error {
  kQ3ErrorNone = 0, // Fatal Errors   kQ3ErrorInternalError = -28500,
  kQ3ErrorNoRecovery// Fatal Errors 
  kQ3ErrorLastFatalError = -28498, // System Errors   kQ3ErrorNotInitialized = -28490,
  kQ3ErrorAlreadyInitialized = -28489,
  kQ3ErrorUnimplemented = -28488,// System Errors 
  kQ3ErrorRegistrationFailed = -28487, // OS Errors   kQ3ErrorUnixError = -28486,
  kQ3ErrorMacintoshError = -28485,
  kQ3ErrorX11Error = -28484, // Memory Errors   kQ3ErrorMemoryLeak = -28483,
  kQ3ErrorOutOfMemory = -28482, // Para// OS Errors 
  kQ3ErrorParameterOutOfRange = -28480,
  kQ3ErrorInvalidParameter = -28479,
  kQ3ErrorInvalidData = -2847// Memory Errors 
  kQ3ErrorAcceleratorAlreadySet = -28477,
  kQ3ErrorVector3DNotUnitLength // Parameter errors 
  kQ3ErrorVector3DZeroLength = -28475, // Object Errors   kQ3ErrorInvalidObject = -28474,
  kQ3ErrorInvalidObjectClass = -28473,
  kQ3ErrorInvalidObjectType = -28472,
  kQ3ErrorInvalidObjectName = -28471,
  kQ3ErrorObjectClassInUse = -28470,
  kQ3ErrorAccessRestricted = -28469,
  kQ3ErrorMetaHandlerRequired = -28468,// Object Errors 
  kQ3ErrorNeedRequiredMethods = -28467,
  kQ3ErrorNoSubClassType = -28466,
  kQ3ErrorUnknownElementType = -28465,
  kQ3ErrorNotSupported = -28464, // Extension Errors   kQ3ErrorNoExtensionsFolder = -28463,
  kQ3ErrorExtensionError = -28462,
  kQ3ErrorPrivateExtensionError = -28461, // Geometry Errors   kQ3ErrorDegenerateGeometry = -28460,
  kQ3ErrorGeometryInsufficientNumberOfPoints = -28459, // IO Errors   kQ3ErrorNoStorageSetForFile = -28458,
  kQ3ErrorEndOfFile = -28457,
  kQ3ErrorFileCancelled = -28456,
  kQ3ErrorInvalidMetafile = -28455,
  kQ3ErrorInvalidMetafilePrimitiv// Extension Errors 
  kQ3ErrorInvalidMetafileLabel = -28453,
  kQ3ErrorInvalidMetafileObject = -28452,
  kQ3ErrorInvalidMetafileSubObject = -2845// Geometry Errors 
  kQ3ErrorInvalidSubObjectForObject = -28450,
  kQ3ErrorUnresolvableReference = -28449,// IO Errors 
  kQ3ErrorUnknownObject = -28448,
  kQ3ErrorStorageInUse = -28447,
  kQ3ErrorStorageAlreadyOpen = -28446,
  kQ3ErrorStorageNotOpen = -28445,
  kQ3ErrorStorageIsOpen = -28444,
  kQ3ErrorFileAlreadyOpen = -28443,
  kQ3ErrorFileNotOpen = -28442,
  kQ3ErrorFileIsOpen = -28441,
  kQ3ErrorBeginWriteAlreadyCalled = -28440,
  kQ3ErrorBeginWriteNotCalled = -28439,
  kQ3ErrorEndWriteNotCalled = -28438,
  kQ3ErrorReadStateInactive = -28437,
  kQ3ErrorStateUnavailable = -28436,
  kQ3ErrorWriteStateInactive = -28435,
  kQ3ErrorSizeNotLongAligned = -28434,
  kQ3ErrorFileModeRestriction = -28433,
  kQ3ErrorInvalidHexString = -28432,
  kQ3ErrorWroteMoreThanSize = -28431,
  kQ3ErrorWroteLessThanSize = -28430,
  kQ3ErrorReadLessThanSize = -28429,
  kQ3ErrorReadMoreThanSize = -28428,
  kQ3ErrorNoBeginGroup = -28427,
  kQ3ErrorSizeMismatch = -28426,
  kQ3ErrorStringExceedsMaximumLength = -28425,
  kQ3ErrorValueExceedsMaximumSize = -28424,
  kQ3ErrorNonUniqueLabel = -28423,
  kQ3ErrorEndOfContainer = -28422,
  kQ3ErrorUnmatchedEndGroup = -28421,
  kQ3ErrorFileVersionExists = -28420, // View errors   kQ3ErrorViewNotStarted = -28419,
  kQ3ErrorViewIsStarted = -28418,
  kQ3ErrorRendererNotSet = -28417,
  kQ3ErrorRenderingIsActive = -28416,
  kQ3ErrorImmediateModeUnderflow = -28415,
  kQ3ErrorDisplayNotSet = -28414,
  kQ3ErrorCameraNotSet = -28413,
  kQ3ErrorDrawContextNotSet = -28412,
  kQ3ErrorNonInvertibleMatrix = -28411,
  kQ3ErrorRenderingNotStarted = -28410,
  kQ3ErrorPickingNotStarted = -28409,// View errors 
  kQ3ErrorBoundsNotStarted = -28408,
  kQ3ErrorDataNotAvailable = -28407,
  kQ3ErrorNothingToPop = -28406, // Renderer Errors   kQ3ErrorUnknownStudioType = -28405,
  kQ3ErrorAlreadyRendering = -28404,
  kQ3ErrorStartGroupRange = -28403,
  kQ3ErrorUnsupportedGeometryType = -28402,
  kQ3ErrorInvalidGeometryType = -28401,
  kQ3ErrorUnsupportedFunctionality = -28400, // Group Errors   kQ3ErrorInvalidPositionForGroup = -28399,
  kQ3ErrorInvalidObjectForGroup = -28398,
  kQ3ErrorInvalidObjectForPosition = -28397, // Transform Errors   kQ3ErrorScaleOfZero = -28396,              // String Errors   kQ3ErrorBadStringType = -28395,            // Attribute Errors   kQ3ErrorAttributeNotContained = -28394,
  kQ3ErrorAttributeInvalidType = -28393, // Camera Errors   kQ3ErrorInvalidCameraValues = -28392,  // DrawContext Errors   kQ3ErrorBadDrawContextType = -28391,
  kQ3ErrorBadDrawContextFlag = -28390,
  kQ3ErrorBadDrawContext = -28389,
  kQ3ErrorUnsupportedPixelDepth =// Renderer Errors 
  kQ3ErrorTypeAlreadyExistsAndOtherClassesDependOnIt = -28383,
  kQ3ErrorTypeAlreadyExistsAndHasObjectInstances =
      -28382, /* submit loop errors: if you ever get one of these check the
                 previous*/
  // error posted, it may be kQ3ErrorOutOfMemory.  If so you *may* be able  // to recover by freeing up some memory and trying again  kQ3ErrorPickingLoopFailed = -28381,
  kQ3ErrorRenderingLoopFailed = -28380,// Group Errors 
  kQ3ErrorWritingLoopFailed = -28379,
  kQ3ErrorBoundingLoopFailed = -28378
};// Transform Errors 
typedef enum TQ3Error TQ3Error;// String Errors 
// Attribute Errors 
enum TQ3Warning {
  kQ3WarningNone = 0,                   /// Camera Errors 
  kQ3WarningNoObjectSupportForDrawMethod // DrawContext Errors 
  kQ3WarningNoObjectSupportForWriteMethod = -28297,
  kQ3WarningNoObjectSupportForReadMethod = -28296,
  kQ3WarningUnknownElementType = -28295,
  kQ3WarningTypeAndMethodAlreadyDefined = // Controller Errors 
  kQ3WarningTypeIsOutOfRange = -28293,// Tracker Errors 
  kQ3WarningTypeHasNotBeenRegistered = -28// Another OS Error 
  kQ3WarningInvalidHexString = -28289,// Object Errors 
  kQ3WarningUnknownObject = -28288,
  kQ3WarningInvalidMetafileObject = -28287,
  kQ3WarningUnmatchedBeginGroup = -28286,
  kQ3WarningUnmatchedEndGroup = -28285,
  kQ3WarningInvalidTableOfContents = -28284,
  // error posted, it may be kQ3ErrorOutOfMemory.  If so you *may* be able
  // to recover by freeing up some memory and trying again
  kQ3WarningInconsistentData = -28281,
  kQ3WarningReadLessThanSize = -28280,
  kQ3WarningFilePointerResolutionFailed = -28279,
  kQ3WarningFilePointerRedefined = -28278,
  kQ3WarningStringExceedsMaximumLength = -28277, // Memory Warnings   kQ3WarningLowMemory = -28276,
  kQ3WarningPossibleMemoryLeak = -28275, // View Warnings   kQ3WarningViewTraversalInProgress = -28274,
  kQ3WarningNonInvertibleMatrix = -28273,       // Quaternion Warning   kQ3WarningQuaternionEntriesAreZero = -28272,  // Renderer Warning   kQ3WarningFunctionalityNotSupported = -28271, // DrawContext Warning   kQ3WarningInvalidPaneDimensions = -28270,     // Pick Warning   kQ3WarningPickParamOutside = -28269,          // Scale Warnings   kQ3WarningScaleEntriesAllZero = -28268,
  kQ3WarningScaleContainsNegativeEntries = -28267, // Generic Warnings   kQ3WarningParameterOutOfRange = -28266,          // Extension Warnings   kQ3WarningExtensionNotLoading = -28265,          // Object Warnings   kQ3WarningTypeAlreadyRegistered = -28264,
  kQ3WarningTypeSameVersionAlreadyRegist// General System 
  kQ3WarningTypeNewerVersionAlreadyRegis// Object Warnings 
      -28262, // Invalid Group Object   kQ3WarningInvalidObjectInGroupMetafile = -28261
};
typedef enum TQ3Warning TQ3Warning;

enum TQ3Notice {
  kQ3NoticeNone = 0,
  kQ3NoticeDataAlreadyEmpty = -28100,
  kQ3NoticeMethodNotSupported = -28099,// Parameter Warnings 
  kQ3NoticeObjectAlreadySet = -28098,// IO Warnings 
  kQ3NoticeParameterOutOfRange = -28097,
  kQ3NoticeFileAliasWasChanged = -28096,
  kQ3NoticeMeshVertexHasNoComponent = -28095,
  kQ3NoticeMeshInvalidVertexFacePair = -28094,
  kQ3NoticeMeshEdgeVertexDoNotCorrespond = -28093,
  kQ3NoticeMeshEdgeIsNotBoundary = -28092,
  kQ3NoticeDrawContextNotSetUsingInternalDefaults = -28091,
  kQ3NoticeInvalidAttenuationTypeUsingInternalDefaults = -28090,
  kQ3NoticeBrightnessGreaterThanOne = -28089,
  kQ3NoticeScaleContainsZeroEntries = -28088,
  kQ3NoticeSystemAlreadyInitialized = -28087,
  kQ3NoticeViewSyncCalledAgain = -28086,
  kQ3NoticeFileCancelled = -28085
};// Memory Warnings 
typedef enum TQ3Notice TQ3Notice;
// View Warnings 
typedef CALLBACK_API_C(void, TQ3ErrorMethod)(TQ3Error firstError,
                                             TQ3// Quaternion Warning 
                                             lon// Renderer Warning 
typedef CALLBACK_API_C(void, TQ3WarningMethod)(T// DrawContext Warning 
                                               T// Pick Warning 
                                               l// Scale Warnings 
typedef CALLBACK_API_C(void, TQ3NoticeMethod)(TQ3Notice firstNotice,
                                              TQ3No// Generic Warnings 
                                              long // Extension Warnings 
/**************************************************// Object Warnings 
 **                                                                          **
 **                             Error Routines                               **
 **                                                                          **
 *************// Invalid Group Object 
#if CALL_NOT_IN_CARBON
/**
 *  Q3Error_Register()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Error_Register(TQ3ErrorMethod errorPost, long reference);

/**
 *  Q3Warning_Register()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Warning_Register(TQ3WarningMethod warningPost, long reference);

/**
 *  Q3Notice_Register()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Notice_Register(TQ3NoticeMethod noticePost, long reference);

/**
 *  Getting error codes -
 *  Clears error type on next entry into system (except all of these
 *  error calls), and returns the last error, and optionally the
 *  first error. The parameter to these "_Get" calls may be NULL.
 */
/**
 *  Q3Error_Get()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Error
Q3Error_Get(TQ3Error *firstError);

/**
 *  Q3Error_IsFatalError()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Boolean
Q3Error_IsFatalError(TQ3Error error);

/**
 *  Q3Warning_Get()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Warning
Q3Warning_Get(TQ3Warning *firstWarning);

/**
 *  Q3Notice_Get()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Notice
Q3Notice_Get(TQ3Notice *firstNotice);

#endif // CALL_NOT_IN_CARBON 
#if TARGET_OS_MAC
#if CALL_NOT_IN_CARBON
/**
 *  Q3MacintoshError_Get()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
Q3MacintoshError_Get(OSErr *firstMacErr);

#endif // CALL_NOT_IN_CARBON 
#endif // TARGET_OS_MAC 
#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __QD3DERRORS__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__QD3DERRORS__RESTORE_PACKED_ENUMS)
#pragma options(pack_enums)
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
#endif// CALL_NOT_IN_CARBON 

#ifdef __cplusplus
}
#endif

#endif // __QD3DERRORS__ // CALL_NOT_IN_CARBON 
// TARGET_OS_MAC 
// __QD3DERRORS__ 
