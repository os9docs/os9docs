/**
     \file       PMApplication.h

    \brief   Carbon Printing Manager Interfaces.

    \introduced_in  Mac OS X
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1998-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __PMAPPLICATION__
#define __PMAPPLICATION__

#ifndef __PMCORE__
#include <PMCore.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
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

/** Callbacks */
typedef CALLBACK_API(void, PMItemProcPtr)(DialogRef theDialog, short item);
typedef CALLBACK_API(void,
                     PMPrintDialogInitProcPtr)(PMPrintSettings printSettings,
                                               PMDialog *theDialog);
typedef CALLBACK_API(void,
                     PMPageSetupDialogInitProcPtr)(PMPageFormat pageFormat,
                                                   PMDialog *theDialog);
typedef CALLBACK_API(void, PMSheetDoneProcPtr)(PMPrintSession printSession,
                                               WindowRef documentWindow,
                                               Boolean accepted);
typedef STACK_UPP_TYPE(PMItemProcPtr) PMItemUPP;
typedef STACK_UPP_TYPE(PMPrintDialogInitProcPtr) PMPrintDialogInitUPP;
typedef STACK_UPP_TYPE(PMPageSetupDialogInitProcPtr) PMPageSetupDialogInitUPP;
typedef STACK_UPP_TYPE(PMSheetDoneProcPtr) PMSheetDoneUPP;
/**
 *  NewPMItemUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(PMItemUPP)
NewPMItemUPP(PMItemProcPtr userRoutine);

/**
 *  NewPMPrintDialogInitUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(PMPrintDialogInitUPP)
NewPMPrintDialogInitUPP(PMPrintDialogInitProcPtr userRoutine);

/**
 *  NewPMPageSetupDialogInitUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(PMPageSetupDialogInitUPP)
NewPMPageSetupDialogInitUPP(PMPageSetupDialogInitProcPtr userRoutine);

/**
 *  NewPMSheetDoneUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(PMSheetDoneUPP)
NewPMSheetDoneUPP(PMSheetDoneProcPtr userRoutine);

/**
 *  DisposePMItemUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposePMItemUPP(PMItemUPP userUPP);

/**
 *  DisposePMPrintDialogInitUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposePMPrintDialogInitUPP(PMPrintDialogInitUPP userUPP);

/**
 *  DisposePMPageSetupDialogInitUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposePMPageSetupDialogInitUPP(PMPageSetupDialogInitUPP userUPP);

/**
 *  DisposePMSheetDoneUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
DisposePMSheetDoneUPP(PMSheetDoneUPP userUPP);

/**
 *  InvokePMItemUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
InvokePMItemUPP(DialogRef theDialog, short item, PMItemUPP userUPP);

/**
 *  InvokePMPrintDialogInitUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
InvokePMPrintDialogInitUPP(PMPrintSettings printSettings, PMDialog *theDialog,
                           PMPrintDialogInitUPP userUPP);

/**
 *  InvokePMPageSetupDialogInitUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
InvokePMPageSetupDialogInitUPP(PMPageFormat pageFormat, PMDialog *theDialog,
                               PMPageSetupDialogInitUPP userUPP);

/**
 *  InvokePMSheetDoneUPP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
InvokePMSheetDoneUPP(PMPrintSession printSession, WindowRef documentWindow,
                     Boolean accepted, PMSheetDoneUPP userUPP);

#if PM_USE_SESSION_APIS
/** Print loop */
/**
 *  PMSessionBeginDocument()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionBeginDocument(PMPrintSession printSession,
                       PMPrintSettings printSettings, PMPageFormat pageFormat);

/**
 *  PMSessionEndDocument()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionEndDocument(PMPrintSession printSession);

/**
 *  PMSessionBeginPage()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionBeginPage(PMPrintSession printSession, PMPageFormat pageFormat,
                   const PMRect *pageFrame);

/**
 *  PMSessionEndPage()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionEndPage(PMPrintSession printSession);

/** Session Printing Dialogs */
/**
 *  PMSessionPageSetupDialog()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPageSetupDialog(PMPrintSession printSession, PMPageFormat pageFormat,
                         Boolean *accepted);

/**
 *  PMSessionPrintDialog()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPrintDialog(PMPrintSession printSession, PMPrintSettings printSettings,
                     PMPageFormat constPageFormat, Boolean *accepted);

/**
 *  PMSessionPageSetupDialogInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPageSetupDialogInit(PMPrintSession printSession,
                             PMPageFormat pageFormat, PMDialog *newDialog);

/**
 *  PMSessionPrintDialogInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPrintDialogInit(PMPrintSession printSession,
                         PMPrintSettings printSettings,
                         PMPageFormat constPageFormat, PMDialog *newDialog);

/**
 *  PMSessionPrintDialogMain()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPrintDialogMain(PMPrintSession printSession,
                         PMPrintSettings printSettings,
                         PMPageFormat constPageFormat, Boolean *accepted,
                         PMPrintDialogInitUPP myInitProc);

/**
 *  PMSessionPageSetupDialogMain()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionPageSetupDialogMain(PMPrintSession printSession,
                             PMPageFormat pageFormat, Boolean *accepted,
                             PMPageSetupDialogInitUPP myInitProc);

/*************************/
/**  Sheets are not available on classic. */
/*************************/
/**
 *  PMSessionUseSheets()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSessionUseSheets(PMPrintSession printSession, WindowRef documentWindow,
                   PMSheetDoneUPP sheetDoneProc);

#else
/** Print loop */
/**
 *  PMBeginDocument()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMBeginDocument(PMPrintSettings printSettings, PMPageFormat pageFormat,
                PMPrintContext *printContext);

/**
 *  PMEndDocument()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMEndDocument(PMPrintContext printContext);

/**
 *  PMBeginPage()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMBeginPage(PMPrintContext printContext, const PMRect *pageFrame);

/**
 *  PMEndPage()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMEndPage(PMPrintContext printContext);

/** Printing Dialogs */
/**
 *  PMPageSetupDialog()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPageSetupDialog(PMPageFormat pageFormat, Boolean *accepted);

/**
 *  PMPrintDialog()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrintDialog(PMPrintSettings printSettings, PMPageFormat constPageFormat,
              Boolean *accepted);

/**
 *  PMPageSetupDialogInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPageSetupDialogInit(PMPageFormat pageFormat, PMDialog *newDialog);

/*************************/
/**  PMPrintDialogInit is not recommended. You should instead use */
/**  PMPrintDialogInitWithPageFormat or PMSessionPrintDialogInit */
/*************************/
/**
 *  PMPrintDialogInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrintDialogInit(PMPrintSettings printSettings, PMDialog *newDialog);

/**
 *  PMPrintDialogInitWithPageFormat()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrintDialogInitWithPageFormat(PMPrintSettings printSettings,
                                PMPageFormat constPageFormat,
                                PMDialog *newDialog);

/**
 *  PMPrintDialogMain()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPrintDialogMain(PMPrintSettings printSettings, PMPageFormat constPageFormat,
                  Boolean *accepted, PMPrintDialogInitUPP myInitProc);

/**
 *  PMPageSetupDialogMain()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMPageSetupDialogMain(PMPageFormat pageFormat, Boolean *accepted,
                      PMPageSetupDialogInitUPP myInitProc);

#endif /** PM_USE_SESSION_APIS */

/** Printing Dialog accessors */
/**
 *  PMGetDialogPtr()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetDialogPtr(PMDialog pmDialog, DialogRef *theDialog);

#define PMGetDialogRef PMGetDialogPtr
/**
 *  PMGetModalFilterProc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetModalFilterProc(PMDialog pmDialog, ModalFilterUPP *filterProc);

/**
 *  PMSetModalFilterProc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetModalFilterProc(PMDialog pmDialog, ModalFilterUPP filterProc);

/**
 *  PMGetItemProc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetItemProc(PMDialog pmDialog, PMItemUPP *itemProc);

/**
 *  PMSetItemProc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetItemProc(PMDialog pmDialog, PMItemUPP itemProc);

/**
 *  PMGetDialogAccepted()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetDialogAccepted(PMDialog pmDialog, Boolean *process);

/**
 *  PMSetDialogAccepted()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetDialogAccepted(PMDialog pmDialog, Boolean process);

/**
 *  PMGetDialogDone()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMGetDialogDone(PMDialog pmDialog, Boolean *done);

/**
 *  PMSetDialogDone()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
PMSetDialogDone(PMDialog pmDialog, Boolean done);

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

#endif /** __PMAPPLICATION__ */
