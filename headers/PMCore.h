/**
     \file       PMCore.h

    \brief   Carbon Printing Manager Interfaces.

    \introduced_in  Mac OS X
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1998-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __PMCORE__
#define __PMCORE__

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __CMAPPLICATION__
#include <CMApplication.h>
#endif

#ifndef __PMDEFINITIONS__
#include <PMDefinitions.h>
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

#ifndef PM_USE_SESSION_APIS
#define PM_USE_SESSION_APIS 1
#endif /* !defined(PM_USE_SESSION_APIS) */

/* Callbacks */
typedef CALLBACK_API(void, PMIdleProcPtr)(void);
typedef STACK_UPP_TYPE(PMIdleProcPtr) PMIdleUPP;
/**
 *  NewPMIdleUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(PMIdleUPP)
NewPMIdleUPP(PMIdleProcPtr userRoutine);

/**
 *  DisposePMIdleUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposePMIdleUPP(PMIdleUPP userUPP);

/**
 *  InvokePMIdleUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
InvokePMIdleUPP(PMIdleUPP userUPP);

#if PM_USE_SESSION_APIS
/* Session routines */
/* Session support */
/**
 *  PMRetain()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMRetain(PMObject object);

/**
 *  PMRelease()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMRelease(PMObject object);

/* Session Print loop */
/************************/
/* A session is created with a refcount of 1. */
/************************/
/**
 *  PMCreateSession()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMCreateSession(PMPrintSession *printSession);

/* Session PMPageFormat */
/************************/
/* A pageformat is created with a refcount of 1. */
/************************/
/**
 *  PMCreatePageFormat()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMCreatePageFormat(PMPageFormat *pageFormat);

/**
 *  PMSessionDefaultPageFormat()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionDefaultPageFormat(PMPrintSession printSession,
                           PMPageFormat pageFormat);

/**
 *  PMSessionValidatePageFormat()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionValidatePageFormat(PMPrintSession printSession,
                            PMPageFormat pageFormat, Boolean *result);

/* Session PMPrintSettings */
/************************/
/* A printSettings is created with a refcount of 1. */
/************************/
/**
 *  PMCreatePrintSettings()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMCreatePrintSettings(PMPrintSettings *printSettings);

/**
 *  PMSessionDefaultPrintSettings()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionDefaultPrintSettings(PMPrintSession printSession,
                              PMPrintSettings printSettings);

/**
 *  PMSessionValidatePrintSettings()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionValidatePrintSettings(PMPrintSession printSession,
                               PMPrintSettings printSettings, Boolean *result);

/* Session Classic support */
/**
 *  PMSessionGeneral()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionGeneral(PMPrintSession printSession, Ptr pData);

/**
 *  PMSessionConvertOldPrintRecord()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionConvertOldPrintRecord(PMPrintSession printSession,
                               Handle printRecordHandle,
                               PMPrintSettings *printSettings,
                               PMPageFormat *pageFormat);

/**
 *  PMSessionMakeOldPrintRecord()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionMakeOldPrintRecord(PMPrintSession printSession,
                            PMPrintSettings printSettings,
                            PMPageFormat pageFormat, Handle *printRecordHandle);

/* Session Driver Information */
/**
 *  PMPrinterGetDescriptionURL()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrinterGetDescriptionURL(PMPrinter printer, CFStringRef descriptionType,
                           CFURLRef *fileURL);

/**
 *  PMSessionGetCurrentPrinter()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionGetCurrentPrinter(PMPrintSession printSession,
                           PMPrinter *currentPrinter);

/**
 *  PMPrinterGetLanguageInfo()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrinterGetLanguageInfo(PMPrinter printer, PMLanguageInfo *info);

/**
 *  PMPrinterGetDriverCreator()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrinterGetDriverCreator(PMPrinter printer, OSType *creator);

/**
 *  PMPrinterGetDriverReleaseInfo()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrinterGetDriverReleaseInfo(PMPrinter printer, VersRec *release);

/**
 *  PMPrinterGetPrinterResolutionCount()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrinterGetPrinterResolutionCount(PMPrinter printer, UInt32 *count);

/**
 *  PMPrinterGetPrinterResolution()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrinterGetPrinterResolution(PMPrinter printer, PMTag tag, PMResolution *res);

/**
 *  PMPrinterGetIndexedPrinterResolution()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrinterGetIndexedPrinterResolution(PMPrinter printer, UInt32 index,
                                     PMResolution *res);

/* Session ColorSync & PostScript Support */
/**
 *  PMSessionEnableColorSync()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionEnableColorSync(PMPrintSession printSession);

/**
 *  PMSessionDisableColorSync()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionDisableColorSync(PMPrintSession printSession);

/**
 *  PMSessionPostScriptBegin()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPostScriptBegin(PMPrintSession printSession);

/**
 *  PMSessionPostScriptEnd()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPostScriptEnd(PMPrintSession printSession);

/**
 *  PMSessionPostScriptHandle()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPostScriptHandle(PMPrintSession printSession, Handle psHandle);

/**
 *  PMSessionPostScriptData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPostScriptData(PMPrintSession printSession, Ptr psPtr, Size len);

/**
 *  PMSessionPostScriptFile()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPostScriptFile(PMPrintSession printSession, FSSpec *psFile);

/**
 *  PMSessionSetPSInjectionData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionSetPSInjectionData(PMPrintSession printSession,
                            PMPrintSettings printSettings,
                            CFArrayRef injectionDictArray);

/* Session Error */
/**
 *  PMSessionError()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionError(PMPrintSession printSession);

/**
 *  PMSessionSetError()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionSetError(PMPrintSession printSession, OSStatus printError);

/* Other Session routines */
/**
 *  PMSessionGetDocumentFormatGeneration()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionGetDocumentFormatGeneration(PMPrintSession printSession,
                                     CFArrayRef *docFormats);

/**
 *  PMSessionSetDocumentFormatGeneration()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionSetDocumentFormatGeneration(PMPrintSession printSession,
                                     CFStringRef docFormat,
                                     CFArrayRef graphicsContextTypes,
                                     CFTypeRef options);

/**
 *  PMSessionGetDocumentFormatSupported()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionGetDocumentFormatSupported(PMPrintSession printSession,
                                    CFArrayRef *docFormats, UInt32 limit);

/**
 *  PMSessionIsDocumentFormatSupported()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionIsDocumentFormatSupported(PMPrintSession printSession,
                                   CFStringRef docFormat, Boolean *supported);

/**
 *  PMSessionGetGraphicsContext()
 *
 *  Parameters:
 *
 *    printSession:
 *      the session
 *
 *    graphicsContextType:
 *      either kPMGraphicsContextQuickdraw or
 *      kPMGraphicsContextCoreGraphics
 *
 *    graphicsContext:
 *      returns a GrafPtr or a CGContextRef
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionGetGraphicsContext(PMPrintSession printSession,
                            CFStringRef graphicsContextType,
                            void **graphicsContext);

/**
 *  PMSessionSetIdleProc()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionSetIdleProc(PMPrintSession printSession, PMIdleUPP idleProc);

/**
 *  PMSessionSetDataInSession()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionSetDataInSession(PMPrintSession printSession, CFStringRef key,
                          CFTypeRef data);

/**
 *  PMSessionGetDataFromSession()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionGetDataFromSession(PMPrintSession printSession, CFStringRef key,
                            CFTypeRef *data);

/**
 *  PMSessionCreatePrinterList()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.4 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionCreatePrinterList(PMPrintSession printSession, CFArrayRef *printerList,
                           CFIndex *currentIndex, PMPrinter *currentPrinter);

/**
 *  PMSessionSetCurrentPrinter()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.4 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionSetCurrentPrinter(PMPrintSession session, CFStringRef printerName);

/**
 *  PMSessionSetDestination()
 *
 *  Summary:
 *    Alter a print session and print settings so that an associated
 *    print job is sent to the provided destination type in the,
 *    optional, MIME document format.
 *
 *  Discussion:
 *    This function is most useful when an application would like to
 *    write its print output to disk without requiring user
 *    interaction. The list of MIME types that can be sent to the
 *    provided destination can be obtained from
 *    PMSessionCopyOutputFormatList and one of these passed to this
 *    function.
 *
 *  Parameters:
 *
 *    printSession:
 *      The session to be used for a print job. The session holds the
 *      preview setting which can override the destination type in the
 *      print settings.
 *
 *    printSettings:
 *      The print settings to be used for a print job. The print
 *      settings specify whether a job will be directed toward a
 *      printer or to file. It also holds the requested MIME output
 *      type.
 *
 *    destType:
 *      The destiation type for a print job associated with the
 *      provided print session and print settings. Fax is currently not
 *      supported, but kPMDestinationPrinter, kPMDestinationFile, and
 *      kPMDestinationPreview can be set.
 *
 *    destFormat:
 *      The MIME type to be generated for the provided destination
 *      type. This parameter can be NULL in which the default format
 *      for the requested destination type is used. To obtain a list of
 *      valid formats for a given destiation type, use the function
 *      PMSessionCopyOutputFormatList.
 *
 *    destLocation:
 *      Some destination types support a destination location. The
 *      clearest example is the kPMDestinationFile destination type
 *      which allows a caller to also supply a file URL specifying
 *      where the output file is to be created.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionSetDestination(PMPrintSession printSession,
                        PMPrintSettings printSettings,
                        PMDestinationType destType, CFStringRef destFormat,
                        CFURLRef destLocation);

/**
 *  PMSessionGetDestinationType()
 *
 *  Summary:
 *    Hand back the destination type that will be used for a print job
 *    with the specified print settings and print session.
 *
 *  Discussion:
 *    Currently there are four destination types:
 *    kPMDestinationPrinter, kPMDestinationFile, kPMDestinationFax and
 *    kPMDestinationPreview. The first three destination types are
 *    stored in the print settings. The switch for preview is stored in
 *    the print session and, if enabled, overrides the destination in
 *    the print setting. This function is preferred over
 *    PMGetDestination as the latter does not take a print session
 *    parameter and therefore can not indicate whether preview has been
 *    selected as the destination.
 *
 *  Parameters:
 *
 *    printSession:
 *      The session to be used for a print job. The session holds the
 *      preview setting which can override the destination type in the
 *      print settings.
 *
 *    printSettings:
 *      The print settings to be used for a print job. The print
 *      settings specify whether a job will be directed toward a
 *      printer or to file.
 *
 *    destTypeP:
 *      A pointer to a caller supplied PMDestinationType variable. If
 *      this function succeeds then *'destTypeP' will be filled in with
 *      the destination type for a print job that used the specified
 *      session and print settings. If this function fails, then
 *      *'destType' will be set to kPMDestinationInvalid.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionGetDestinationType(PMPrintSession printSession,
                            PMPrintSettings printSettings,
                            PMDestinationType *destTypeP);

/**
 *  PMSessionCopyDestinationFormat()
 *
 *  Summary:
 *    Hand back the destination output MIME type associated with the
 *    provided print session and print settings.
 *
 *  Parameters:
 *
 *    printSession:
 *      A currently open print session.
 *
 *    printSettings:
 *      The print settings that are to be searched.
 *
 *    destFormatP:
 *      A pointer to a caller allocated CFStringRef variable. If this
 *      routine returns noErr then *'destFormatP' will either be a copy
 *      of a CFStringRef specifying the output format for the print
 *      job, or NULL indicating that the default output format will be
 *      used. If this function return an error, then *'destFormatP'
 *      will be set to NULL.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionCopyDestinationFormat(PMPrintSession printSession,
                               PMPrintSettings printSettings,
                               CFStringRef *destFormatP);

/**
 *  PMSessionCopyDestinationLocation()
 *
 *  Summary:
 *    Hand back the URL destination location given a print session and
 *    print settings.
 *
 *  Discussion:
 *    Some destination type support a destination location which
 *    further defines where the output from a pritn job should be sent.
 *    The kPMDestinationFile destiation type, for example, will use a
 *    file URL to determine where a new file should be created.
 *
 *  Parameters:
 *
 *    printSession:
 *      A currently open print session.
 *
 *    printSettings:
 *      The print settings that are to be searched.
 *
 *    destLocationP:
 *      A pointer to a caller allocated CFURLRef variable. If this
 *      routine returns noErr then *'outputFileP' will either be NULL
 *      indicating that the job is using the default destination
 *      location for the current destination type or a copy of a
 *      CFURLRef will be placed in *'destLocationP'. If this function
 *      returns an error then 'destLocationP' will be set to NULL.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionCopyDestinationLocation(PMPrintSession printSession,
                                 PMPrintSettings printSettings,
                                 CFURLRef *destLocationP);

/**
 *  PMSessionCopyOutputFormatList()
 *
 *  Summary:
 *    Hands back an an array of MIME types describing the possible
 *    output formats for the printer module associated with the current
 *    printer.
 *
 *  Parameters:
 *
 *    printSession:
 *      This session's current printer's printer module will be queried
 *      for its supported output MIME types.
 *
 *    destType:
 *      A print job can have one of several possible destination types.
 *      The list of valid output formats is dependent upon the
 *      destination type. This parameter specifies destination type of
 *      interest when retrieving the output formats list.
 *
 *    documentFormatP:
 *      A pointer to a caller's CFArrayRef variable. If this routine
 *      completes successfully, then *'documentFormatP' will be set to
 *      a CFArrayRef containing CFStringRefs. Each CFStringRef in the
 *      array is a MIME type specifying a type of output that can be
 *      generated by the printer module associated with the current
 *      printer.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionCopyOutputFormatList(PMPrintSession printSession,
                              PMDestinationType destType,
                              CFArrayRef *documentFormatP);

/**
 *  PMSessionCreatePageFormatList()
 *
 *  Summary:
 *    Hand back a list of page format instances. Each page format
 *    instance describes a paper size available on the specified
 *    printer.
 *
 *  Parameters:
 *
 *    printSession:
 *      A currently open print session.
 *
 *    printer:
 *      The printer whose page size list should be enumerated. To get
 *      the session's current printer, see PMSessionGetCurrentPrinter().
 *
 *    pageFormatList:
 *      If this function is successful then noErr will be returned and
 *      *'pageFormatList' will be set to a newly created CFArray. Each
 *      element in the array will be a PMPageFormat describing an
 *      available paper size for the specified printer. If this
 *      function fails then a non-zero error code will be returned and
 *      *'pageFormatList' will be set to NULL.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionCreatePageFormatList(PMPrintSession printSession, PMPrinter printer,
                              CFArrayRef *pageFormatList);

#else
/**
 *  PMSetIdleProc()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetIdleProc(PMIdleUPP idleProc);

/* Print loop */
/**
 *  PMBegin()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMBegin(void);

/**
 *  PMEnd()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMEnd(void);

/************************/
/*  Valid only within a PMBeginPage/PMEndPage block. You should retrieve the
 * printing */
/*  port with this call and set it before imaging a page. */
/************************/
/**
 *  PMGetGrafPtr()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetGrafPtr(PMPrintContext printContext, GrafPtr *grafPort);

/* PMPageFormat */
/**
 *  PMNewPageFormat()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMNewPageFormat(PMPageFormat *pageFormat);

/**
 *  PMDisposePageFormat()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMDisposePageFormat(PMPageFormat pageFormat);

/**
 *  PMDefaultPageFormat()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMDefaultPageFormat(PMPageFormat pageFormat);

/**
 *  PMValidatePageFormat()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMValidatePageFormat(PMPageFormat pageFormat, Boolean *result);

/* PMPrintSettings */
/**
 *  PMNewPrintSettings()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMNewPrintSettings(PMPrintSettings *printSettings);

/**
 *  PMDisposePrintSettings()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMDisposePrintSettings(PMPrintSettings printSettings);

/**
 *  PMDefaultPrintSettings()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMDefaultPrintSettings(PMPrintSettings printSettings);

/**
 *  PMValidatePrintSettings()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMValidatePrintSettings(PMPrintSettings printSettings, Boolean *result);

/* Classic Support */
/**
 *  PMGeneral()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGeneral(Ptr pData);

/**
 *  PMConvertOldPrintRecord()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMConvertOldPrintRecord(Handle printRecordHandle,
                        PMPrintSettings *printSettings,
                        PMPageFormat *pageFormat);

/**
 *  PMMakeOldPrintRecord()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMMakeOldPrintRecord(PMPrintSettings printSettings, PMPageFormat pageFormat,
                     Handle *printRecordHandle);

/* Driver Information */
/**
 *  PMIsPostScriptDriver()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMIsPostScriptDriver(Boolean *isPostScript);

/**
 *  PMGetLanguageInfo()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetLanguageInfo(PMLanguageInfo *info);

/**
 *  PMGetDriverCreator()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetDriverCreator(OSType *creator);

/**
 *  PMGetDriverReleaseInfo()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetDriverReleaseInfo(VersRec *release);

/**
 *  PMGetPrinterResolutionCount()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetPrinterResolutionCount(UInt32 *count);

/**
 *  PMGetPrinterResolution()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetPrinterResolution(PMTag tag, PMResolution *res);

/**
 *  PMGetIndexedPrinterResolution()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetIndexedPrinterResolution(UInt32 index, PMResolution *res);

/************************/
/*  PMEnableColorSync and PMDisableColorSync are valid within */
/*  BeginPage/EndPage block */
/************************/
/* ColorSync & PostScript Support */
/**
 *  PMEnableColorSync()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMEnableColorSync(void);

/**
 *  PMDisableColorSync()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMDisableColorSync(void);

/************************/
/*  The PMPostScriptxxx calls are valid within a */
/*  BeginPage/EndPage block */
/************************/
/**
 *  PMPostScriptBegin()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPostScriptBegin(void);

/**
 *  PMPostScriptEnd()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPostScriptEnd(void);

/************************/
/*  These PMPostScriptxxx calls are valid within a */
/*  PMPostScriptBegin/PMPostScriptEnd block */
/************************/
/**
 *  PMPostScriptHandle()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPostScriptHandle(Handle psHandle);

/**
 *  PMPostScriptData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPostScriptData(Ptr psPtr, Size len);

/**
 *  PMPostScriptFile()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPostScriptFile(FSSpec *psFile);

/* Error */
/**
 *  PMError()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMError(void);

/**
 *  PMSetError()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetError(OSStatus printError);

#endif /* PM_USE_SESSION_APIS */

/* PMPageFormat */
/**
 *  PMCopyPageFormat()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMCopyPageFormat(PMPageFormat formatSrc, PMPageFormat formatDest);

/************************/
/*  Flattening a page format should only be necessary if you intend to preserve
 */
/*  the object settings along with a document. A page format will persist
 * outside of a */
/*  PMBegin/PMEnd block. This will allow you to use any accessors on the object
 * without */
/*  the need to flatten and unflatten. Keep in mind accessors make no assumption
 */
/*  on the validity of the value you set. This can only be done thru
 * PMValidatePageFormat */
/*  in a PMBegin/PMEnd block or with PMSessionValidatePageFormat with a valid
 * session. */
/*  It is your responsibility for disposing of the handle. */
/************************/
/**
 *  PMFlattenPageFormat()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMFlattenPageFormat(PMPageFormat pageFormat, Handle *flatFormat);

/**
 *  PMUnflattenPageFormat()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMUnflattenPageFormat(Handle flatFormat, PMPageFormat *pageFormat);

/* PMPageFormat Accessors */
/************************/
/* PMSetxxx calls only saves the value inside the printing object. They make no
 * assumption on the */
/* validity of the value. This should be done using
 * PMValidatePageFormat/PMSessionValidatePageFormat */
/* Any dependant settings are also updated during a validate call. */
/* For example: */
/* PMGetAdjustedPaperRect - returns a rect of a certain size */
/* PMSetScale( aPageFormat, 500.0 )  */
/* PMGetAdjustedPaperRect - returns the SAME rect as the first call  */
/**/
/* PMGetAdjustedPaperRect - returns a rect of a certain size */
/* PMSetScale( aPageFormat, 500.0 ) */
/* PMValidatePageFormat or PMSessionValidatePageFormat */
/* PMGetAdjustedPaperRect - returns a rect thats scaled 500% from the first call
 */
/************************/
/**
 *  PMGetPageFormatExtendedData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetPageFormatExtendedData(PMPageFormat pageFormat, OSType dataID,
                            UInt32 *size, void *extendedData);

/**
 *  PMSetPageFormatExtendedData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetPageFormatExtendedData(PMPageFormat pageFormat, OSType dataID, UInt32 size,
                            void *extendedData);

/************************/
/*  A value of 100.0 means 100% (no scaling). 50.0 means 50% scaling */
/************************/
/**
 *  PMGetScale()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetScale(PMPageFormat pageFormat, double *scale);

/**
 *  PMSetScale()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetScale(PMPageFormat pageFormat, double scale);

/************************/
/*  This is the drawing resolution of an app. This should not be confused with
 */
/*  the resolution of the printer. You can call PMGetPrinterResolution to see */
/*  what resolutions are avaliable for the current printer. */
/************************/
/**
 *  PMGetResolution()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetResolution(PMPageFormat pageFormat, PMResolution *res);

/**
 *  PMSetResolution()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetResolution(PMPageFormat pageFormat, const PMResolution *res);

/************************/
/*  This is the physical size of the paper without regard to resolution,
 * orientation */
/*  or scaling. It is returned as a 72dpi value. */
/************************/
/**
 *  PMGetPhysicalPaperSize()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetPhysicalPaperSize(PMPageFormat pageFormat, PMRect *paperSize);

/**
 *  PMSetPhysicalPaperSize()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetPhysicalPaperSize(PMPageFormat pageFormat, const PMRect *paperSize);

/************************/
/*  This is the physical size of the page without regard to resolution,
 * orientation */
/*  or scaling. It is returned as a 72dpi value. */
/************************/
/**
 *  PMGetPhysicalPageSize()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetPhysicalPageSize(PMPageFormat pageFormat, PMRect *pageSize);

/**
 *  PMGetAdjustedPaperRect()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetAdjustedPaperRect(PMPageFormat pageFormat, PMRect *paperRect);

/**
 *  PMGetAdjustedPageRect()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetAdjustedPageRect(PMPageFormat pageFormat, PMRect *pageRect);

/**
 *  PMGetUnadjustedPaperRect()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetUnadjustedPaperRect(PMPageFormat pageFormat, PMRect *paperRect);

/**
 *  PMSetUnadjustedPaperRect()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetUnadjustedPaperRect(PMPageFormat pageFormat, const PMRect *paperRect);

/**
 *  PMGetUnadjustedPageRect()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetUnadjustedPageRect(PMPageFormat pageFormat, PMRect *pageRect);

/**
 *  PMSetAdjustedPageRect()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetAdjustedPageRect(PMPageFormat pageFormat, const PMRect *pageRect);

/**
 *  PMGetOrientation()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetOrientation(PMPageFormat pageFormat, PMOrientation *orientation);

/**
 *  PMSetOrientation()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetOrientation(PMPageFormat pageFormat, PMOrientation orientation,
                 Boolean lock);

/* PMPrintSettings */
/**
 *  PMCopyPrintSettings()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMCopyPrintSettings(PMPrintSettings settingSrc, PMPrintSettings settingDest);

/************************/
/*  Flattening a print settings should only be necessary if you intend to
 * preserve */
/*  the object settings along with a document. A print settings will persist
 * outside of a */
/*  PMBegin/PMEnd block. This allows you to use any accessors on the object
 * without */
/*  the need to flatten and unflatten. Keep in mind the accessors make no
 * assumption */
/*  on the validity of the value. This can only be done thru
 * PMValidatePrintSettings */
/*  in a PMBegin/PMEnd block or with PMSessionValidatePrintSettings with a valid
 * session. */
/*  It is your responsibility for disposing of the handle. */
/************************/
/**
 *  PMFlattenPrintSettings()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMFlattenPrintSettings(PMPrintSettings printSettings, Handle *flatSettings);

/**
 *  PMUnflattenPrintSettings()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMUnflattenPrintSettings(Handle flatSettings, PMPrintSettings *printSettings);

/* PMPrintSettings Accessors */
/**
 *  PMGetPrintSettingsExtendedData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetPrintSettingsExtendedData(PMPrintSettings printSettings, OSType dataID,
                               UInt32 *size, void *extendedData);

/**
 *  PMSetPrintSettingsExtendedData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetPrintSettingsExtendedData(PMPrintSettings printSettings, OSType dataID,
                               UInt32 size, void *extendedData);

/**
 *  PMGetDestination()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetDestination(PMPrintSettings printSettings, PMDestinationType *destType,
                 CFURLRef *fileURL);

/**
 *  PMGetJobName()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetJobName(PMPrintSettings printSettings, StringPtr name);

/**
 *  PMSetJobName()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetJobName(PMPrintSettings printSettings, StringPtr name);

/**
 *  PMGetCopies()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetCopies(PMPrintSettings printSettings, UInt32 *copies);

/**
 *  PMSetCopies()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetCopies(PMPrintSettings printSettings, UInt32 copies, Boolean lock);

/**
 *  PMGetFirstPage()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetFirstPage(PMPrintSettings printSettings, UInt32 *first);

/**
 *  PMSetFirstPage()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetFirstPage(PMPrintSettings printSettings, UInt32 first, Boolean lock);

/**
 *  PMGetLastPage()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetLastPage(PMPrintSettings printSettings, UInt32 *last);

/**
 *  PMSetLastPage()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetLastPage(PMPrintSettings printSettings, UInt32 last, Boolean lock);

/************************/
/*  The default page range is from 1-32000. The page range is something that is
 */
/*  set by the application. It is NOT the first and last page to print. It
 * serves */
/*  as limits for setting the first and last page. You may pass kPMPrintAllPages
 * for */
/*  the maxPage value to specified that all pages are available for printing. */
/************************/
/**
 *  PMGetPageRange()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetPageRange(PMPrintSettings printSettings, UInt32 *minPage, UInt32 *maxPage);

/************************/
/* The first and last page are immediately clipped to the new range */
/************************/
/**
 *  PMSetPageRange()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetPageRange(PMPrintSettings printSettings, UInt32 minPage, UInt32 maxPage);

/**
 *  PMSetProfile()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetProfile(PMPrintSettings printSettings, PMTag tag,
             const CMProfileLocation *profile);

/**
 *  PMGetColorMode()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetColorMode(PMPrintSettings printSettings, PMColorMode *colorMode);

/**
 *  PMSetColorMode()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetColorMode(PMPrintSettings printSettings, PMColorMode colorMode);

/**
 *  PMGetJobNameCFString()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetJobNameCFString(PMPrintSettings printSettings, CFStringRef *name);

/**
 *  PMSetJobNameCFString()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetJobNameCFString(PMPrintSettings printSettings, CFStringRef name);

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

#endif /* __PMCORE__ */
