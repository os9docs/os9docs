/**
     \file       StandardFile.h

    \brief   Standard File package Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup File

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __STANDARDFILE__
#define __STANDARDFILE__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
#endif

#ifndef __FILES__
#include <Files.h>
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

  enum
  {
    /* resource IDs of pre-7.0 get and put dialogs */
    putDlgID = -3999,
    getDlgID = -4000
  };

  enum
  {
    /* item offsets of pre-7.0 get and put dialogs */
    putSave = 1,
    putCancel = 2,
    putEject = 5,
    putDrive = 6,
    putName = 7,
    getOpen = 1,
    getCancel = 3,
    getEject = 5,
    getDrive = 6,
    getNmList = 7,
    getScroll = 8
  };

  enum
  {
    /* resource IDs of 7.0 get and put dialogs */
    sfPutDialogID = -6043,
    sfGetDialogID = -6042
  };

  enum
  {
    /* item offsets of 7.0 get and put dialogs */
    sfItemOpenButton = 1,
    sfItemCancelButton = 2,
    sfItemBalloonHelp = 3,
    sfItemVolumeUser = 4,
    sfItemEjectButton = 5,
    sfItemDesktopButton = 6,
    sfItemFileListUser = 7,
    sfItemPopUpMenuUser = 8,
    sfItemDividerLinePict = 9,
    sfItemFileNameTextEdit = 10,
    sfItemPromptStaticText = 11,
    sfItemNewFolderUser = 12
  };

  enum
  {
    /* pseudo-item hits for use in DlgHook */
    sfHookFirstCall = -1,
    sfHookCharOffset = 0x1000,
    sfHookNullEvent = 100,
    sfHookRebuildList = 101,
    sfHookFolderPopUp = 102,
    sfHookOpenFolder = 103, /* the following are only in system 7.0+ */
    sfHookLastCall = -2,
    sfHookOpenAlias = 104,
    sfHookGoToDesktop = 105,
    sfHookGoToAliasTarget = 106,
    sfHookGoToParent = 107,
    sfHookGoToNextDrive = 108,
    sfHookGoToPrevDrive = 109,
    sfHookChangeSelection = 110,
    sfHookSetActiveOffset = 200
  };

  /* the refcon field of the dialog record during a
   modalfilter or dialoghook contains one of the following */
  enum
  {
    sfMainDialogRefCon = FOUR_CHAR_CODE('stdf'),
    sfNewFolderDialogRefCon = FOUR_CHAR_CODE('nfdr'),
    sfReplaceDialogRefCon = FOUR_CHAR_CODE('rplc'),
    sfStatWarnDialogRefCon = FOUR_CHAR_CODE('stat'),
    sfLockWarnDialogRefCon = FOUR_CHAR_CODE('lock'),
    sfErrorDialogRefCon = FOUR_CHAR_CODE('err ')
  };

  struct SFReply
  {
    Boolean good;
    Boolean copy;
    OSType fType;
    short vRefNum;
    short version;
    StrFileName fName; /* a Str63 on MacOS */
  };
  typedef struct SFReply SFReply;
  struct StandardFileReply
  {
    Boolean sfGood;
    Boolean sfReplacing;
    OSType sfType;
    FSSpec sfFile;
    ScriptCode sfScript;
    short sfFlags;
    Boolean sfIsFolder;
    Boolean sfIsVolume;
    long sfReserved1;
    short sfReserved2;
  };
  typedef struct StandardFileReply StandardFileReply;
  /* for CustomXXXFile, ActivationOrderListPtr parameter is a pointer to an array
   * of item numbers */

  typedef const short *ActivationOrderListPtr;
  typedef CALLBACK_API(short, DlgHookProcPtr)(short item, DialogRef theDialog);
  typedef CALLBACK_API(Boolean, FileFilterProcPtr)(CInfoPBPtr pb);
  /* the following also include an extra parameter of "your data pointer" */
  typedef CALLBACK_API(short, DlgHookYDProcPtr)(short item, DialogRef theDialog,
                                                void *yourDataPtr);
  /* ModalFilterYDProcPtr moved to Dialogs.h */
  typedef CALLBACK_API(Boolean, FileFilterYDProcPtr)(CInfoPBPtr pb,
                                                     void *yourDataPtr);
  typedef CALLBACK_API(void, ActivateYDProcPtr)(DialogRef theDialog, short itemNo,
                                                Boolean activating,
                                                void *yourDataPtr);
  typedef STACK_UPP_TYPE(DlgHookProcPtr) DlgHookUPP;
  typedef STACK_UPP_TYPE(FileFilterProcPtr) FileFilterUPP;
  typedef STACK_UPP_TYPE(DlgHookYDProcPtr) DlgHookYDUPP;
  typedef STACK_UPP_TYPE(FileFilterYDProcPtr) FileFilterYDUPP;
  typedef STACK_UPP_TYPE(ActivateYDProcPtr) ActivateYDUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewDlgHookUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  DlgHookUPP
  NewDlgHookUPP(DlgHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDlgHookProcInfo = 0x000003A0
  }; /* pascal 2_bytes Func(2_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DlgHookUPP NewDlgHookUPP(DlgHookProcPtr userRoutine)
  {
    return (DlgHookUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDlgHookProcInfo, GetCurrentArchitecture());
  }
#else
#define NewDlgHookUPP(userRoutine)   \
  (DlgHookUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppDlgHookProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewFileFilterUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  FileFilterUPP
  NewFileFilterUPP(FileFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppFileFilterProcInfo = 0x000000D0
  }; /* pascal 1_byte Func(4_bytes) */
#ifdef __cplusplus
  inline FileFilterUPP NewFileFilterUPP(FileFilterProcPtr userRoutine)
  {
    return (FileFilterUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppFileFilterProcInfo, GetCurrentArchitecture());
  }
#else
#define NewFileFilterUPP(userRoutine)   \
  (FileFilterUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppFileFilterProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDlgHookYDUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  DlgHookYDUPP
  NewDlgHookYDUPP(DlgHookYDProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDlgHookYDProcInfo = 0x00000FA0
  }; /* pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DlgHookYDUPP NewDlgHookYDUPP(DlgHookYDProcPtr userRoutine)
  {
    return (DlgHookYDUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDlgHookYDProcInfo, GetCurrentArchitecture());
  }
#else
#define NewDlgHookYDUPP(userRoutine)   \
  (DlgHookYDUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppDlgHookYDProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewFileFilterYDUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  FileFilterYDUPP
  NewFileFilterYDUPP(FileFilterYDProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppFileFilterYDProcInfo = 0x000003D0
  }; /* pascal 1_byte Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline FileFilterYDUPP NewFileFilterYDUPP(FileFilterYDProcPtr userRoutine)
  {
    return (FileFilterYDUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppFileFilterYDProcInfo,
                                                 GetCurrentArchitecture());
  }
#else
#define NewFileFilterYDUPP(userRoutine)                                     \
  (FileFilterYDUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppFileFilterYDProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewActivateYDUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ActivateYDUPP
  NewActivateYDUPP(ActivateYDProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppActivateYDProcInfo = 0x000036C0
  }; /* pascal no_return_value Func(4_bytes, 2_bytes, 1_byte, 4_bytes) */
#ifdef __cplusplus
  inline ActivateYDUPP NewActivateYDUPP(ActivateYDProcPtr userRoutine)
  {
    return (ActivateYDUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppActivateYDProcInfo, GetCurrentArchitecture());
  }
#else
#define NewActivateYDUPP(userRoutine)   \
  (ActivateYDUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppActivateYDProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeDlgHookUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeDlgHookUPP(DlgHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDlgHookUPP(DlgHookUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDlgHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeFileFilterUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeFileFilterUPP(FileFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeFileFilterUPP(FileFilterUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeFileFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDlgHookYDUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeDlgHookYDUPP(DlgHookYDUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDlgHookYDUPP(DlgHookYDUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDlgHookYDUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeFileFilterYDUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeFileFilterYDUPP(FileFilterYDUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeFileFilterYDUPP(FileFilterYDUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeFileFilterYDUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeActivateYDUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeActivateYDUPP(ActivateYDUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeActivateYDUPP(ActivateYDUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeActivateYDUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeDlgHookUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  InvokeDlgHookUPP(short item, DialogRef theDialog, DlgHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline short InvokeDlgHookUPP(short item, DialogRef theDialog,
                                DlgHookUPP userUPP)
  {
    return (short)CALL_TWO_PARAMETER_UPP(userUPP, uppDlgHookProcInfo, item,
                                         theDialog);
  }
#else
#define InvokeDlgHookUPP(item, theDialog, userUPP)                     \
  (short)CALL_TWO_PARAMETER_UPP((userUPP), uppDlgHookProcInfo, (item), \
                                (theDialog))
#endif
#endif

  /**
   *  InvokeFileFilterUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  InvokeFileFilterUPP(CInfoPBPtr pb, FileFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeFileFilterUPP(CInfoPBPtr pb, FileFilterUPP userUPP)
  {
    return (Boolean)CALL_ONE_PARAMETER_UPP(userUPP, uppFileFilterProcInfo, pb);
  }
#else
#define InvokeFileFilterUPP(pb, userUPP) \
  (Boolean) CALL_ONE_PARAMETER_UPP((userUPP), uppFileFilterProcInfo, (pb))
#endif
#endif

  /**
   *  InvokeDlgHookYDUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  InvokeDlgHookYDUPP(short item, DialogRef theDialog, void *yourDataPtr,
                     DlgHookYDUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline short InvokeDlgHookYDUPP(short item, DialogRef theDialog,
                                  void *yourDataPtr, DlgHookYDUPP userUPP)
  {
    return (short)CALL_THREE_PARAMETER_UPP(userUPP, uppDlgHookYDProcInfo, item,
                                           theDialog, yourDataPtr);
  }
#else
#define InvokeDlgHookYDUPP(item, theDialog, yourDataPtr, userUPP)          \
  (short)CALL_THREE_PARAMETER_UPP((userUPP), uppDlgHookYDProcInfo, (item), \
                                  (theDialog), (yourDataPtr))
#endif
#endif

  /**
   *  InvokeFileFilterYDUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  InvokeFileFilterYDUPP(CInfoPBPtr pb, void *yourDataPtr,
                        FileFilterYDUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeFileFilterYDUPP(CInfoPBPtr pb, void *yourDataPtr,
                                       FileFilterYDUPP userUPP)
  {
    return (Boolean)CALL_TWO_PARAMETER_UPP(userUPP, uppFileFilterYDProcInfo, pb,
                                           yourDataPtr);
  }
#else
#define InvokeFileFilterYDUPP(pb, yourDataPtr, userUPP)                      \
  (Boolean) CALL_TWO_PARAMETER_UPP((userUPP), uppFileFilterYDProcInfo, (pb), \
                                   (yourDataPtr))
#endif
#endif

  /**
   *  InvokeActivateYDUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeActivateYDUPP(DialogRef theDialog, short itemNo, Boolean activating,
                      void *yourDataPtr, ActivateYDUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeActivateYDUPP(DialogRef theDialog, short itemNo,
                                  Boolean activating, void *yourDataPtr,
                                  ActivateYDUPP userUPP)
  {
    CALL_FOUR_PARAMETER_UPP(userUPP, uppActivateYDProcInfo, theDialog, itemNo,
                            activating, yourDataPtr);
  }
#else
#define InvokeActivateYDUPP(theDialog, itemNo, activating, yourDataPtr,  \
                            userUPP)                                     \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppActivateYDProcInfo, (theDialog), \
                          (itemNo), (activating), (yourDataPtr))
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewDlgHookProc(userRoutine) NewDlgHookUPP(userRoutine)
#define NewFileFilterProc(userRoutine) NewFileFilterUPP(userRoutine)
#define NewDlgHookYDProc(userRoutine) NewDlgHookYDUPP(userRoutine)
#define NewFileFilterYDProc(userRoutine) NewFileFilterYDUPP(userRoutine)
#define NewActivateYDProc(userRoutine) NewActivateYDUPP(userRoutine)
#define CallDlgHookProc(userRoutine, item, theDialog) \
  InvokeDlgHookUPP(item, theDialog, userRoutine)
#define CallFileFilterProc(userRoutine, pb) InvokeFileFilterUPP(pb, userRoutine)
#define CallDlgHookYDProc(userRoutine, item, theDialog, yourDataPtr) \
  InvokeDlgHookYDUPP(item, theDialog, yourDataPtr, userRoutine)
#define CallFileFilterYDProc(userRoutine, pb, yourDataPtr) \
  InvokeFileFilterYDUPP(pb, yourDataPtr, userRoutine)
#define CallActivateYDProc(userRoutine, theDialog, itemNo, activating, \
                           yourDataPtr)                                \
  InvokeActivateYDUPP(theDialog, itemNo, activating, yourDataPtr, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

  typedef OSType SFTypeList[4];
  /**
      The GetFile "typeList" parameter type has changed from "SFTypeList" to
     "ConstSFTypeListPtr". For C, this will add "const" and make it an in-only
     parameter. For Pascal, this will require client code to use the @ operator,
     but make it easier to specify long lists.

      ConstSFTypeListPtr is a pointer to an array of OSTypes.
  */
  typedef const OSType *ConstSFTypeListPtr;
#if CALL_NOT_IN_CARBON
  /**
   *  SFPutFile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  SFPutFile(Point where, ConstStr255Param prompt,          /* can be NULL */
            ConstStr255Param origName, DlgHookUPP dlgHook, /* can be NULL */
            SFReply *reply);

  /**
   *  SFGetFile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  SFGetFile(Point where, ConstStr255Param prompt,
            FileFilterUPP fileFilter,                    /* can be NULL */
            short numTypes, ConstSFTypeListPtr typeList, /* can be NULL */
            DlgHookUPP dlgHook,                          /* can be NULL */
            SFReply *reply);

  /**
   *  SFPPutFile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  SFPPutFile(Point where, ConstStr255Param prompt, /* can be NULL */
             ConstStr255Param origName, DlgHookUPP dlgHook, SFReply *reply,
             short dlgID,
             ModalFilterUPP filterProc) /* can be NULL */;

  /**
   *  SFPGetFile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  SFPGetFile(Point where, ConstStr255Param prompt,
             FileFilterUPP fileFilter,                    /* can be NULL */
             short numTypes, ConstSFTypeListPtr typeList, /* can be NULL */
             DlgHookUPP dlgHook,                          /* can be NULL */
             SFReply *reply, short dlgID,
             ModalFilterUPP filterProc) /* can be NULL */;

  /**
   *  StandardPutFile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  StandardPutFile(ConstStr255Param prompt, /* can be NULL */
                  ConstStr255Param defaultName, StandardFileReply *reply);

  /**
   *  StandardGetFile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  StandardGetFile(FileFilterUPP fileFilter,                    /* can be NULL */
                  short numTypes, ConstSFTypeListPtr typeList, /* can be NULL */
                  StandardFileReply *reply);

  /**
   *  CustomPutFile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  CustomPutFile(ConstStr255Param prompt, /* can be NULL */
                ConstStr255Param defaultName, StandardFileReply *reply,
                short dlgID, Point where, DlgHookYDUPP dlgHook, /* can be NULL */
                ModalFilterYDUPP filterProc,                    /* can be NULL */
                ActivationOrderListPtr activeList,              /* can be NULL */
                ActivateYDUPP activate,                         /* can be NULL */
                void *yourDataPtr);

  /**
   *  CustomGetFile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  CustomGetFile(FileFilterYDUPP fileFilter,                  /* can be NULL */
                short numTypes, ConstSFTypeListPtr typeList, /* can be NULL */
                StandardFileReply *reply, short dlgID, Point where,
                DlgHookYDUPP dlgHook,              /* can be NULL */
                ModalFilterYDUPP filterProc,       /* can be NULL */
                ActivationOrderListPtr activeList, /* can be NULL */
                ActivateYDUPP activate,            /* can be NULL */
                void *yourDataPtr);

  /**
   *  StandardOpenDialog()
   *
   *  Availability:
   *    \non_carbon_cfm   in Translation 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  StandardOpenDialog(StandardFileReply *reply);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
  /**
   *  sfpputfile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  sfpputfile(Point *where, const char *prompt, const char *origName,
             DlgHookUPP dlgHook, /* can be NULL */
             SFReply *reply, short dlgID,
             ModalFilterUPP filterProc); /* can be NULL */

  /**
   *  sfgetfile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  sfgetfile(Point *where, const char *prompt,
            FileFilterUPP fileFilter,                    /* can be NULL */
            short numTypes, ConstSFTypeListPtr typeList, /* can be NULL */
            DlgHookUPP dlgHook,                          /* can be NULL */
            SFReply *reply);

  /**
   *  sfpgetfile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  sfpgetfile(Point *where, const char *prompt,
             FileFilterUPP fileFilter,                    /* can be NULL */
             short numTypes, ConstSFTypeListPtr typeList, /* can be NULL */
             DlgHookUPP dlgHook,                          /* can be NULL */
             SFReply *reply, short dlgID,
             ModalFilterUPP filterProc); /* can be NULL */

  /**
   *  sfputfile()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  sfputfile(Point *where, const char *prompt, const char *origName,
            DlgHookUPP dlgHook, /* can be NULL */
            SFReply *reply);

#endif /* CALL_NOT_IN_CARBON */

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

#endif /* __STANDARDFILE__ */
