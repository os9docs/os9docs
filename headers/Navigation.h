
/**
     \file       Navigation.h

    \brief   Navigation Services Interfaces

    \introduced_in  Navigation 3.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1996-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __NAVIGATION__
#define __NAVIGATION__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __APPLEEVENTS__
#include <AppleEvents.h>
#endif

#ifndef __TRANSLATION__
#include <Translation.h>
#endif

#ifndef __MACWINDOWS__
#include <MacWindows.h>
#endif

#ifndef __CODEFRAGMENTS__
#include <CodeFragments.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __CFARRAY__
#include <CFArray.h>
#endif

#ifndef __CFSTRING__
#include <CFString.h>
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

  typedef UInt32 NavAskSaveChangesAction;
  enum
  {
    /* input action codes for NavAskSaveChanges() */
    kNavSaveChangesClosingDocument = 1,
    kNavSaveChangesQuittingApplication = 2,
    kNavSaveChangesOther = 0
  };

  typedef UInt32 NavAskSaveChangesResult;
  enum
  {
    /* result codes for NavAskSaveChanges() */
    kNavAskSaveChangesSave = 1,
    kNavAskSaveChangesCancel = 2,
    kNavAskSaveChangesDontSave = 3
  };

  typedef UInt32 NavAskDiscardChangesResult;
  enum
  {
    /* result codes for NavAskDiscardChanges() */
    kNavAskDiscardChanges = 1,
    kNavAskDiscardChangesCancel = 2
  };

  typedef SInt16 NavFilterModes;
  enum
  {
    /* which elements are being filtered for objects: */
    kNavFilteringBrowserList = 0,
    kNavFilteringFavorites = 1,
    kNavFilteringRecents = 2,
    kNavFilteringShortCutVolumes = 3,
    kNavFilteringLocationPopup = 4 /* for v1.1 or greater */
  };

  enum
  {
    kNavFileOrFolderVersion = 1
  };

  struct NavFileOrFolderInfo
  {
    UInt16 version;
    Boolean isFolder;
    Boolean visible;
    UInt32 creationDate;
    UInt32 modificationDate;
    union
    {
      struct
      {
        Boolean locked;       /* file is locked */
        Boolean resourceOpen; /* resource fork is opened */
        Boolean dataOpen;     /* data fork is opened */
        Boolean reserved1;
        UInt32 dataSize;     /* size of the data fork */
        UInt32 resourceSize; /* size of the resource fork */
        FInfo finderInfo;    /* more file info: */
        FXInfo finderXInfo;
      } fileInfo;
      struct
      {
        Boolean shareable;
        Boolean sharePoint;
        Boolean mounted;
        Boolean readable;
        Boolean writeable;
        Boolean reserved2;
        UInt32 numberOfFiles;
        DInfo finderDInfo;
        DXInfo finderDXInfo;
        OSType folderType;    /* package type, For struct version >= 1 */
        OSType folderCreator; /* package creator, For struct version >= 1 */
        char reserved3[206];
      } folderInfo;

    } fileAndFolder;
  };
  typedef struct NavFileOrFolderInfo NavFileOrFolderInfo;
  union NavEventDataInfo
  {
    EventRecord *event; /* for event processing */
    void *param;        /* points to event specific data */
  };
  typedef union NavEventDataInfo NavEventDataInfo;
  struct NavEventData
  {
    NavEventDataInfo eventDataParms; /* the event data */
    SInt16 itemHit;                  /* the dialog item number, for v1.1 or greater */
  };
  typedef struct NavEventData NavEventData;

  typedef struct __NavDialog *NavDialogRef;
#if CALL_NOT_IN_CARBON
  /* NavContext is the old name for NavDialogRef */

  typedef NavDialogRef NavContext;
#endif /* CALL_NOT_IN_CARBON */

  typedef UInt32 NavUserAction;
  enum
  {

    kNavUserActionNone = 0,

    kNavUserActionCancel = 1,

    kNavUserActionOpen = 2,

    kNavUserActionSaveAs = 3,

    kNavUserActionChoose = 4,

    kNavUserActionNewFolder = 5,

    kNavUserActionSaveChanges = 6,

    kNavUserActionDontSaveChanges = 7,

    kNavUserActionDiscardChanges = 8,

    kNavUserActionReviewDocuments = 9,

    kNavUserActionDiscardDocuments = 10
  };

  enum
  {
    kNavCBRecVersion = 1
  };

  struct NavCBRec
  {

    UInt16 version;

    NavDialogRef context;

    WindowRef window;

    Rect customRect;

    Rect previewRect;

    NavEventData eventData;

    NavUserAction userAction;

    char reserved[218];
  };
  typedef struct NavCBRec NavCBRec;
  typedef NavCBRec *NavCBRecPtr;

  typedef SInt32 NavEventCallbackMessage;
  enum
  {

    kNavCBEvent = 0,

    kNavCBCustomize = 1,

    kNavCBStart = 2,

    kNavCBTerminate = 3,

    kNavCBAdjustRect = 4,

    kNavCBNewLocation = 5,

    kNavCBShowDesktop = 6,

    kNavCBSelectEntry = 7,

    kNavCBPopupMenuSelect = 8,

    kNavCBAccept = 9,

    kNavCBCancel = 10,

    kNavCBAdjustPreview = 11,

    kNavCBUserAction = 12,

    kNavCBOpenSelection = (long)0x80000000
  };

  typedef void *NavCallBackUserData;
  /* for events and customization: */
  typedef CALLBACK_API(void,
                       NavEventProcPtr)(NavEventCallbackMessage callBackSelector,
                                        NavCBRecPtr callBackParms,
                                        void *callBackUD);
  /* for preview support: */
  typedef CALLBACK_API(Boolean, NavPreviewProcPtr)(NavCBRecPtr callBackParms,
                                                   void *callBackUD);
  /* filtering callback information: */
  typedef CALLBACK_API(Boolean,
                       NavObjectFilterProcPtr)(AEDesc *theItem, void *info,
                                               void *callBackUD,
                                               NavFilterModes filterMode);
  typedef STACK_UPP_TYPE(NavEventProcPtr) NavEventUPP;
  typedef STACK_UPP_TYPE(NavPreviewProcPtr) NavPreviewUPP;
  typedef STACK_UPP_TYPE(NavObjectFilterProcPtr) NavObjectFilterUPP;
  EXTERN_API_C(NavEventUPP)
  NewNavEventUPP(NavEventProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppNavEventProcInfo = 0x00000FC0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline NavEventUPP NewNavEventUPP(NavEventProcPtr userRoutine)
  {
    return (NavEventUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppNavEventProcInfo, GetCurrentArchitecture());
  }
#else
#define NewNavEventUPP(userRoutine)   \
  (NavEventUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppNavEventProcInfo, GetCurrentArchitecture())
#endif
#endif

  EXTERN_API_C(NavPreviewUPP)
  NewNavPreviewUPP(NavPreviewProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppNavPreviewProcInfo = 0x000003D0
  }; /* pascal 1_byte Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline NavPreviewUPP NewNavPreviewUPP(NavPreviewProcPtr userRoutine)
  {
    return (NavPreviewUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppNavPreviewProcInfo, GetCurrentArchitecture());
  }
#else
#define NewNavPreviewUPP(userRoutine)   \
  (NavPreviewUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppNavPreviewProcInfo, GetCurrentArchitecture())
#endif
#endif

  EXTERN_API_C(NavObjectFilterUPP)
  NewNavObjectFilterUPP(NavObjectFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppNavObjectFilterProcInfo = 0x00002FD0
  }; /* pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes, 2_bytes) */
#ifdef __cplusplus
  inline NavObjectFilterUPP
  NewNavObjectFilterUPP(NavObjectFilterProcPtr userRoutine)
  {
    return (NavObjectFilterUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    uppNavObjectFilterProcInfo,
                                                    GetCurrentArchitecture());
  }
#else
#define NewNavObjectFilterUPP(userRoutine)                                     \
  (NavObjectFilterUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppNavObjectFilterProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  EXTERN_API_C(void)
  DisposeNavEventUPP(NavEventUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeNavEventUPP(NavEventUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeNavEventUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  EXTERN_API_C(void)
  DisposeNavPreviewUPP(NavPreviewUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeNavPreviewUPP(NavPreviewUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeNavPreviewUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  EXTERN_API_C(void)
  DisposeNavObjectFilterUPP(NavObjectFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeNavObjectFilterUPP(NavObjectFilterUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeNavObjectFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  EXTERN_API_C(void)
  InvokeNavEventUPP(NavEventCallbackMessage callBackSelector,
                    NavCBRecPtr callBackParms, void *callBackUD,
                    NavEventUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeNavEventUPP(NavEventCallbackMessage callBackSelector,
                                NavCBRecPtr callBackParms, void *callBackUD,
                                NavEventUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppNavEventProcInfo, callBackSelector,
                             callBackParms, callBackUD);
  }
#else
#define InvokeNavEventUPP(callBackSelector, callBackParms, callBackUD,         \
                          userUPP)                                             \
  CALL_THREE_PARAMETER_UPP((userUPP), uppNavEventProcInfo, (callBackSelector), \
                           (callBackParms), (callBackUD))
#endif
#endif

  EXTERN_API_C(Boolean)
  InvokeNavPreviewUPP(NavCBRecPtr callBackParms, void *callBackUD,
                      NavPreviewUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeNavPreviewUPP(NavCBRecPtr callBackParms, void *callBackUD,
                                     NavPreviewUPP userUPP)
  {
    return (Boolean)CALL_TWO_PARAMETER_UPP(userUPP, uppNavPreviewProcInfo,
                                           callBackParms, callBackUD);
  }
#else
#define InvokeNavPreviewUPP(callBackParms, callBackUD, userUPP)      \
  (Boolean) CALL_TWO_PARAMETER_UPP((userUPP), uppNavPreviewProcInfo, \
                                   (callBackParms), (callBackUD))
#endif
#endif

  EXTERN_API_C(Boolean)
  InvokeNavObjectFilterUPP(AEDesc *theItem, void *info, void *callBackUD,
                           NavFilterModes filterMode, NavObjectFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeNavObjectFilterUPP(AEDesc *theItem, void *info,
                                          void *callBackUD,
                                          NavFilterModes filterMode,
                                          NavObjectFilterUPP userUPP)
  {
    return (Boolean)CALL_FOUR_PARAMETER_UPP(userUPP, uppNavObjectFilterProcInfo,
                                            theItem, info, callBackUD,
                                            filterMode);
  }
#else
#define InvokeNavObjectFilterUPP(theItem, info, callBackUD, filterMode, \
                                 userUPP)                               \
  (Boolean)                                                             \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppNavObjectFilterProcInfo,    \
                              (theItem), (info), (callBackUD), (filterMode))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewNavEventProc(userRoutine) NewNavEventUPP(userRoutine)
#define NewNavPreviewProc(userRoutine) NewNavPreviewUPP(userRoutine)
#define NewNavObjectFilterProc(userRoutine) NewNavObjectFilterUPP(userRoutine)
#define CallNavEventProc(userRoutine, callBackSelector, callBackParms, \
                         callBackUD)                                   \
  InvokeNavEventUPP(callBackSelector, callBackParms, callBackUD, userRoutine)
#define CallNavPreviewProc(userRoutine, callBackParms, callBackUD) \
  InvokeNavPreviewUPP(callBackParms, callBackUD, userRoutine)
#define CallNavObjectFilterProc(userRoutine, theItem, info, callBackUD, \
                                filterMode)                             \
  InvokeNavObjectFilterUPP(theItem, info, callBackUD, filterMode, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

  typedef SInt32 NavCustomControlMessage;
  enum
  {
    kNavCtlShowDesktop = 0, /* show desktop, parms = nil */
    kNavCtlSortBy = 1,      /* sort key field, parms->NavSortKeyField */
    kNavCtlSortOrder = 2,   /* sort order, parms->NavSortOrder */
    kNavCtlScrollHome = 3,  /* scroll list home, parms = nil */
    kNavCtlScrollEnd = 4,   /* scroll list end, parms = nil */
    kNavCtlPageUp = 5,      /* page list up, parms = nil */
    kNavCtlPageDown = 6,    /* page list down, parms = nil */
    kNavCtlGetLocation = 7, /* get current location, parms<-AEDesc* */
    kNavCtlSetLocation = 8, /* set current location, parms->AEDesc* */
    kNavCtlGetSelection =
        9, /* get current selection, parms<-AEDescList* */
    kNavCtlSetSelection =
        10,                       /* set current selection, parms->AEDescList* */
    kNavCtlShowSelection = 11,    /* make selection visible, parms = nil */
    kNavCtlOpenSelection = 12,    /* open view of selection, parms = nil */
    kNavCtlEjectVolume = 13,      /* eject volume, parms->vRefNum */
    kNavCtlNewFolder = 14,        /* create a new folder, parms->StringPtr */
    kNavCtlCancel = 15,           /* cancel dialog, parms = nil */
    kNavCtlAccept = 16,           /* accept dialog default, parms = nil */
    kNavCtlIsPreviewShowing = 17, /* query preview status, parms<-Boolean */
    kNavCtlAddControl =
        18, /* add one control to dialog, parms->ControlHandle */
    kNavCtlAddControlList =
        19, /* add control list to dialog, parms->Handle (DITL rsrc) */
    kNavCtlGetFirstControlID =
        20, /* get 1st control ID, parms<-UInt16 */
    kNavCtlSelectCustomType =
        21,                    /* select a custom menu item parms->NavMenuItemSpec* */
    kNavCtlSelectAllType = 22, /* select an "All" menu item parms->SInt16 */
    kNavCtlGetEditFileName =
        23, /* get save dlog's file name parms<-StringPtr */
    kNavCtlSetEditFileName =
        24, /* set save dlog's file name parms->StringPtr */
    kNavCtlSelectEditFileName =
        25, /* select save dlog file name parms->ControlEditTextSelectionRec*,
        v1.1 or greater */
    kNavCtlBrowserSelectAll =
        26, /* re-scan the browser list parms = nil, v2.0 or greater */
    kNavCtlGotoParent =
        27,                     /* navigate to parent parms = nil, v2.0 or greater */
    kNavCtlSetActionState = 28, /* restrict navigation parms->NavActionState
    (flags), v2.0 or greater */
    kNavCtlBrowserRedraw =
        29, /* rescan browser list parms = nil, v2.0 or greater */
    kNavCtlTerminate =
        30 /* terminate/dismiss dialog parms = nil, v2.0 or greater */
  };

  typedef UInt32 NavActionState;
  enum
  {
    kNavNormalState = 0x00000000,       /* normal/default state */
    kNavDontOpenState = 0x00000001,     /* disallow opening files/folders */
    kNavDontSaveState = 0x00000002,     /* disallow saving files */
    kNavDontChooseState = 0x00000004,   /* disallow choosing objects */
    kNavDontNewFolderState = 0x00000010 /* disallow creating new folders */
  };

  typedef UInt16 NavPopupMenuItem;
  enum
  {
    kNavAllKnownFiles = 0,
    kNavAllReadableFiles = 1,
    kNavAllFiles = 2
  };

  typedef UInt16 NavSortKeyField;
  enum
  {
    kNavSortNameField = 0,
    kNavSortDateField = 1
  };

  typedef UInt16 NavSortOrder;
  enum
  {
    kNavSortAscending = 0,
    kNavSortDescending = 1
  };

  typedef UInt32 NavDialogOptionFlags;
  enum
  {
    kNavDefaultNavDlogOptions = 0x000000E4, /* use defaults for all the options */
    kNavNoTypePopup =
        0x00000001, /* don't show file type/extension popup on Open/Save */
    kNavDontAutoTranslate =
        0x00000002, /* don't automatically translate on Open */
    kNavDontAddTranslateItems =
        0x00000004, /* don't add translation choices on Open/Save */
    kNavAllFilesInPopup =
        0x00000010,                       /* "All Files" menu item in the type popup on Open */
    kNavAllowStationery = 0x00000020,     /* allow saving of stationery files */
    kNavAllowPreviews = 0x00000040,       /* allow preview to show */
    kNavAllowMultipleFiles = 0x00000080,  /* allow multiple items to be selected */
    kNavAllowInvisibleFiles = 0x00000100, /* allow invisible items to be shown */
    kNavDontResolveAliases = 0x00000200,  /* don't resolve aliases */
    kNavSelectDefaultLocation =
        0x00000400, /* make the default location the browser selection */
    kNavSelectAllReadableItem =
        0x00000800, /* make the dialog select "All Readable Documents" on open */
    kNavSupportPackages =
        0x00001000, /* recognize file system packages, v2.0 or greater */
    kNavAllowOpenPackages =
        0x00002000,                  /* allow opening of packages, v2.0 or greater */
    kNavDontAddRecents = 0x00004000, /* don't add chosen objects to the recents
    list, v2.0 or greater */
    kNavDontUseCustomFrame =
        0x00008000, /* don't draw the custom area bevel frame, v2.0 or greater */
    kNavDontConfirmReplacement =
        0x00010000, /* don't show the "Replace File?" alert on save conflict, v3.0
        or greater */
    kNavPreserveSaveFileExtension =
        0x00020000 /* extension in default file name is preserved and initially
        hidden, v3.1 or greater */
  };

  typedef UInt32 NavTranslationOptions;
  enum
  {
    kNavTranslateInPlace = 0, /* translate in place, replacing translation
    source file (default for Save) */
    kNavTranslateCopy =
        1 /* translate to a copy of the source file (default for Open) */
  };

  enum
  {
    kNavMenuItemSpecVersion = 0
  };

  struct NavMenuItemSpec
  {
    UInt16 version;
    OSType menuCreator;
    OSType menuType;
    Str255 menuItemName;
    char reserved[245];
  };
  typedef struct NavMenuItemSpec NavMenuItemSpec;
  typedef NavMenuItemSpec *NavMenuItemSpecArrayPtr;
  typedef NavMenuItemSpecArrayPtr *NavMenuItemSpecArrayHandle;
  typedef NavMenuItemSpecArrayPtr NavMenuItemSpecPtr;
  typedef NavMenuItemSpecArrayHandle NavMenuItemSpecHandle;
  enum
  {
    kNavGenericSignature = FOUR_CHAR_CODE('****')
  };

  struct NavTypeList
  {
    OSType componentSignature;
    short reserved;
    short osTypeCount;
    OSType osType[1];
  };
  typedef struct NavTypeList NavTypeList;
  typedef NavTypeList *NavTypeListPtr;
  typedef NavTypeListPtr *NavTypeListHandle;
  enum
  {
    kNavDialogOptionsVersion = 0
  };

  struct NavDialogOptions
  {
    UInt16 version;
    NavDialogOptionFlags
        dialogOptionFlags; /* option flags for affecting the dialog's behavior */
    Point location;        /* top-left location of the dialog, or {-1,-1} for default
           position */
    Str255 clientName;
    Str255 windowTitle;
    Str255 actionButtonLabel;                  /* label of the default button (or null string for
                     default) */
    Str255 cancelButtonLabel;                  /* label of the cancel button (or null string for
                     default) */
    Str255 savedFileName;                      /* default name for text box in NavPutFile (or null
                         string for default) */
    Str255 message;                            /* custom message prompt (or null string for default) */
    UInt32 preferenceKey;                      /* a key for to managing preferences for using multiple
                         utility dialogs */
    NavMenuItemSpecArrayHandle popupExtension; /* extended popup menu items, an
    array of NavMenuItemSpecs */
    char reserved[494];
  };
  typedef struct NavDialogOptions NavDialogOptions;
  enum
  {
    kNavReplyRecordVersion = 2
  };

  struct NavReplyRecord
  {

    UInt16 version;

    Boolean validRecord;

    Boolean replacing;

    Boolean isStationery;

    Boolean translationNeeded;

    AEDescList selection;

    ScriptCode keyScript;

    FileTranslationSpecArrayHandle fileTranslation;

    UInt32 reserved1;

    CFStringRef saveFileName;

    Boolean saveFileExtensionHidden;

    UInt8 reserved2;

    char reserved[225];
  };
  typedef struct NavReplyRecord NavReplyRecord;
  EXTERN_API(OSErr)
  NavLoad(void);

  EXTERN_API(OSErr)
  NavUnload(void);

  EXTERN_API(UInt32)
  NavLibraryVersion(void);

  EXTERN_API(OSErr)
  NavGetDefaultDialogOptions(NavDialogOptions *dialogOptions);

  EXTERN_API(OSErr)
  NavGetFile(AEDesc *defaultLocation, /* can be NULL */
             NavReplyRecord *reply,
             NavDialogOptions *dialogOptions, /* can be NULL */
             NavEventUPP eventProc,           /* can be NULL */
             NavPreviewUPP previewProc,       /* can be NULL */
             NavObjectFilterUPP filterProc,   /* can be NULL */
             NavTypeListHandle typeList,      /* can be NULL */
             void *callBackUD);               /* can be NULL */

  EXTERN_API(OSErr)
  NavPutFile(AEDesc *defaultLocation, /* can be NULL */
             NavReplyRecord *reply,
             NavDialogOptions *dialogOptions, /* can be NULL */
             NavEventUPP eventProc,           /* can be NULL */
             OSType fileType, OSType fileCreator,
             void *callBackUD); /* can be NULL */

  EXTERN_API(OSErr)
  NavAskSaveChanges(NavDialogOptions *dialogOptions,
                    NavAskSaveChangesAction action,
                    NavAskSaveChangesResult *reply,
                    NavEventUPP eventProc, /* can be NULL */
                    void *callBackUD);     /* can be NULL */

  EXTERN_API(OSErr)
  NavCustomAskSaveChanges(NavDialogOptions *dialogOptions,
                          NavAskSaveChangesResult *reply,
                          NavEventUPP eventProc, /* can be NULL */
                          void *callBackUD);     /* can be NULL */

  EXTERN_API(OSErr)
  NavAskDiscardChanges(NavDialogOptions *dialogOptions,
                       NavAskDiscardChangesResult *reply,
                       NavEventUPP eventProc, /* can be NULL */
                       void *callBackUD);     /* can be NULL */

  EXTERN_API(OSErr)
  NavChooseFile(AEDesc *defaultLocation, /* can be NULL */
                NavReplyRecord *reply,
                NavDialogOptions *dialogOptions, /* can be NULL */
                NavEventUPP eventProc,           /* can be NULL */
                NavPreviewUPP previewProc,       /* can be NULL */
                NavObjectFilterUPP filterProc,   /* can be NULL */
                NavTypeListHandle typeList,      /* can be NULL */
                void *callBackUD);               /* can be NULL */

  EXTERN_API(OSErr)
  NavChooseFolder(AEDesc *defaultLocation, /* can be NULL */
                  NavReplyRecord *reply,
                  NavDialogOptions *dialogOptions, /* can be NULL */
                  NavEventUPP eventProc,           /* can be NULL */
                  NavObjectFilterUPP filterProc,   /* can be NULL */
                  void *callBackUD);               /* can be NULL */

  EXTERN_API(OSErr)
  NavChooseVolume(AEDesc *defaultSelection, /* can be NULL */
                  NavReplyRecord *reply,
                  NavDialogOptions *dialogOptions, /* can be NULL */
                  NavEventUPP eventProc,           /* can be NULL */
                  NavObjectFilterUPP filterProc,   /* can be NULL */
                  void *callBackUD);               /* can be NULL */

  EXTERN_API(OSErr)
  NavChooseObject(AEDesc *defaultLocation, /* can be NULL */
                  NavReplyRecord *reply,
                  NavDialogOptions *dialogOptions, /* can be NULL */
                  NavEventUPP eventProc,           /* can be NULL */
                  NavObjectFilterUPP filterProc,   /* can be NULL */
                  void *callBackUD);               /* can be NULL */

  EXTERN_API(OSErr)
  NavNewFolder(AEDesc *defaultLocation, /* can be NULL */
               NavReplyRecord *reply,
               NavDialogOptions *dialogOptions, /* can be NULL */
               NavEventUPP eventProc,           /* can be NULL */
               void *callBackUD);               /* can be NULL */

  EXTERN_API(OSErr)
  NavTranslateFile(NavReplyRecord *reply, NavTranslationOptions howToTranslate);

  EXTERN_API(OSErr)
  NavCompleteSave(NavReplyRecord *reply, NavTranslationOptions howToTranslate);

  EXTERN_API(OSErr)
  NavCustomControl(NavDialogRef dialog, NavCustomControlMessage selector,
                   void *parms);

  EXTERN_API(OSErr)
  NavCreatePreview(AEDesc *theObject, OSType previewDataType,
                   const void *previewData, Size previewDataSize);

  EXTERN_API(OSErr)
  NavDisposeReply(NavReplyRecord *reply);

  EXTERN_API(Boolean)
  NavServicesCanRun(void);

#if TARGET_RT_MAC_CFM
#ifdef __cplusplus
  inline pascal Boolean NavServicesAvailable()
  {
    return ((NavLibraryVersion != (void *)kUnresolvedCFragSymbolAddress) &&
            NavServicesCanRun());
  }
#else
#define NavServicesAvailable()                                     \
  ((NavLibraryVersion != (void *)kUnresolvedCFragSymbolAddress) && \
   NavServicesCanRun())
#endif
#elif TARGET_RT_MAC_MACHO
/* Navigation is always available on OS X */
#ifdef __cplusplus
inline pascal Boolean NavServicesAvailable() { return true; }
#else
#define NavServicesAvailable() (true)
#endif
#else
/* NavServicesAvailable() is implemented in Navigation.o for classic 68K
 * clients*/
#if CALL_NOT_IN_CARBON
EXTERN_API(Boolean)
NavServicesAvailable(void);

#endif /* CALL_NOT_IN_CARBON */

#endif /* */

  /* Carbon API */
  /* Includes support for Unicode and long file names (where available). */

  enum
  {
    kNavDialogCreationOptionsVersion = 0
  };

  struct NavDialogCreationOptions
  {

    UInt16 version;

    NavDialogOptionFlags optionFlags;

    Point location;

    CFStringRef clientName;

    CFStringRef windowTitle;

    CFStringRef actionButtonLabel;

    CFStringRef cancelButtonLabel;

    CFStringRef saveFileName;

    CFStringRef message;

    UInt32 preferenceKey;

    CFArrayRef popupExtension;

    WindowModality modality;

    WindowRef parentWindow;

    char reserved[16];
  };
  typedef struct NavDialogCreationOptions NavDialogCreationOptions;
  EXTERN_API_C(OSStatus)
  NavGetDefaultDialogCreationOptions(NavDialogCreationOptions *outOptions);

  EXTERN_API_C(OSStatus)
  NavCreateGetFileDialog(
      const NavDialogCreationOptions *inOptions, /* can be NULL */
      NavTypeListHandle inTypeList,              /* can be NULL */
      NavEventUPP inEventProc,                   /* can be NULL */
      NavPreviewUPP inPreviewProc,               /* can be NULL */
      NavObjectFilterUPP inFilterProc,           /* can be NULL */
      void *inClientData,                        /* can be NULL */
      NavDialogRef *outDialog);

  EXTERN_API_C(OSStatus)
  NavCreatePutFileDialog(
      const NavDialogCreationOptions *inOptions, /* can be NULL */
      OSType inFileType, OSType inFileCreator,
      NavEventUPP inEventProc, /* can be NULL */
      void *inClientData,      /* can be NULL */
      NavDialogRef *outDialog);

  EXTERN_API_C(OSStatus)
  NavCreateAskReviewDocumentsDialog(const NavDialogCreationOptions *inOptions,
                                    UInt32 inDocumentCount,
                                    NavEventUPP inEventProc, /* can be NULL */
                                    void *inClientData,      /* can be NULL */
                                    NavDialogRef *outDialog);

  EXTERN_API_C(OSStatus)
  NavCreateAskSaveChangesDialog(const NavDialogCreationOptions *inOptions,
                                NavAskSaveChangesAction inAction,
                                NavEventUPP inEventProc, /* can be NULL */
                                void *inClientData,      /* can be NULL */
                                NavDialogRef *outDialog);

  EXTERN_API_C(OSStatus)
  NavCreateAskDiscardChangesDialog(const NavDialogCreationOptions *inOptions,
                                   NavEventUPP inEventProc, /* can be NULL */
                                   void *inClientData,      /* can be NULL */
                                   NavDialogRef *outDialog);

  EXTERN_API_C(OSStatus)
  NavCreateChooseFileDialog(
      const NavDialogCreationOptions *inOptions, /* can be NULL */
      NavTypeListHandle inTypeList,              /* can be NULL */
      NavEventUPP inEventProc,                   /* can be NULL */
      NavPreviewUPP inPreviewProc,               /* can be NULL */
      NavObjectFilterUPP inFilterProc,           /* can be NULL */
      void *inClientData,                        /* can be NULL */
      NavDialogRef *outDialog);

  EXTERN_API_C(OSStatus)
  NavCreateChooseFolderDialog(
      const NavDialogCreationOptions *inOptions, /* can be NULL */
      NavEventUPP inEventProc,                   /* can be NULL */
      NavObjectFilterUPP inFilterProc,           /* can be NULL */
      void *inClientData,                        /* can be NULL */
      NavDialogRef *outDialog);

  EXTERN_API_C(OSStatus)
  NavCreateChooseVolumeDialog(
      const NavDialogCreationOptions *inOptions, /* can be NULL */
      NavEventUPP inEventProc,                   /* can be NULL */
      NavObjectFilterUPP inFilterProc,           /* can be NULL */
      void *inClientData,                        /* can be NULL */
      NavDialogRef *outDialog);

  EXTERN_API_C(OSStatus)
  NavCreateChooseObjectDialog(
      const NavDialogCreationOptions *inOptions, /* can be NULL */
      NavEventUPP inEventProc,                   /* can be NULL */
      NavPreviewUPP inPreviewProc,               /* can be NULL */
      NavObjectFilterUPP inFilterProc,           /* can be NULL */
      void *inClientData,                        /* can be NULL */
      NavDialogRef *outDialog);

  EXTERN_API_C(OSStatus)
  NavCreateNewFolderDialog(
      const NavDialogCreationOptions *inOptions, /* can be NULL */
      NavEventUPP inEventProc,                   /* can be NULL */
      void *inClientData,                        /* can be NULL */
      NavDialogRef *outDialog);

  EXTERN_API_C(OSStatus)
  NavDialogRun(NavDialogRef inDialog);

  EXTERN_API_C(void)
  NavDialogDispose(NavDialogRef inDialog);

  EXTERN_API_C(WindowRef)
  NavDialogGetWindow(NavDialogRef inDialog);

  EXTERN_API_C(NavUserAction)
  NavDialogGetUserAction(NavDialogRef inDialog);

  EXTERN_API_C(OSStatus)
  NavDialogGetReply(NavDialogRef inDialog, NavReplyRecord *outReply);

  EXTERN_API_C(CFStringRef)
  NavDialogGetSaveFileName(NavDialogRef inPutFileDialog);

  EXTERN_API_C(OSStatus)
  NavDialogSetSaveFileName(NavDialogRef inPutFileDialog, CFStringRef inFileName);

  EXTERN_API_C(Boolean)
  NavDialogGetSaveFileExtensionHidden(NavDialogRef inPutFileDialog);

  EXTERN_API_C(OSStatus)
  NavDialogSetSaveFileExtensionHidden(NavDialogRef inPutFileDialog,
                                      Boolean inHidden);

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

#endif /* __NAVIGATION__ */
