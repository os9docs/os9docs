/**
     \file       Dialogs.h

    \brief   Dialog Manager interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DIALOGS__
#define __DIALOGS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __MACWINDOWS__
#include <MacWindows.h>
#endif

#ifndef __TEXTEDIT__
#include <TextEdit.h>
#endif

#ifndef __CONTROLS__
#include <Controls.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __CARBONEVENTS__
#include <CarbonEvents.h>
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
    /** new, more standard names for dialog item types*/
    kControlDialogItem = 4,
    kButtonDialogItem = kControlDialogItem | 0,
    kCheckBoxDialogItem = kControlDialogItem | 1,
    kRadioButtonDialogItem = kControlDialogItem | 2,
    kResourceControlDialogItem = kControlDialogItem | 3,
    kStaticTextDialogItem = 8,
    kEditTextDialogItem = 16,
    kIconDialogItem = 32,
    kPictureDialogItem = 64,
    kUserDialogItem = 0,
    kHelpDialogItem = 1,
    kItemDisableBit = 128
  };

  enum
  {
    /** old names for dialog item types*/
    ctrlItem = 4,
    btnCtrl = 0,
    chkCtrl = 1,
    radCtrl = 2,
    resCtrl = 3,
    statText = 8,
    editText = 16,
    iconItem = 32,
    picItem = 64,
    userItem = 0,
    itemDisable = 128
  };

  enum
  {
    /** standard dialog item numbers*/
    kStdOkItemIndex = 1,
    kStdCancelItemIndex = 2, /** old names*/
    ok = kStdOkItemIndex,
    cancel = kStdCancelItemIndex
  };

  enum
  {
    /** standard icon resource id's    */
    kStopIcon = 0,
    kNoteIcon = 1,
    kCautionIcon = 2, /** old names*/
    stopIcon = kStopIcon,
    noteIcon = kNoteIcon,
    cautionIcon = kCautionIcon
  };

#if OLDROUTINENAMES
  /**
     These constants lived briefly on ETO 16.  They suggest
     that there is only one index you can use for the OK
     item, which is not true.  You can put the ok item
     anywhere you want in the DITL.
  */
  enum
  {
    kOkItemIndex = 1,
    kCancelItemIndex = 2
  };

#endif /** OLDROUTINENAMES */

  /**  Dialog Item List Manipulation Constants */
  typedef SInt16 DITLMethod;
  enum
  {
    overlayDITL = 0,
    appendDITLRight = 1,
    appendDITLBottom = 2
  };

  typedef SInt16 StageList;
  /** DialogPtr is obsolete. Use DialogRef instead.*/
  typedef DialogPtr DialogRef;
#if !OPAQUE_TOOLBOX_STRUCTS
  struct DialogRecord
  {
    WindowRecord window; /** in Carbon use GetDialogWindow or GetDialogPort*/
    Handle items;        /** in Carbon use Get/SetDialogItem*/
    TEHandle textH;      /** in Carbon use GetDialogTextEditHandle*/
    SInt16 editField;    /** in Carbon use
                            SelectDialogItemText/GetDialogKeyboardFocusItem*/
    SInt16 editOpen;     /** not available in Carbon */
    SInt16 aDefItem;     /** in Carbon use Get/SetDialogDefaultItem*/
  };
  typedef struct DialogRecord DialogRecord;
  typedef DialogRecord *DialogPeek;
#endif /** !OPAQUE_TOOLBOX_STRUCTS */

  struct DialogTemplate
  {
    Rect boundsRect;
    SInt16 procID;
    Boolean visible;
    Boolean filler1;
    Boolean goAwayFlag;
    Boolean filler2;
    SInt32 refCon;
    SInt16 itemsID;
    Str255 title;
  };
  typedef struct DialogTemplate DialogTemplate;
  typedef DialogTemplate *DialogTPtr;
  typedef DialogTPtr *DialogTHndl;
  struct AlertTemplate
  {
    Rect boundsRect;
    SInt16 itemsID;
    StageList stages;
  };
  typedef struct AlertTemplate AlertTemplate;
  typedef AlertTemplate *AlertTPtr;
  typedef AlertTPtr *AlertTHndl;
  /** new type abstractions for the dialog manager */
  typedef SInt16 DialogItemIndexZeroBased;
  typedef SInt16 DialogItemIndex;
  typedef SInt16 DialogItemType;
  /** dialog manager callbacks */
  typedef CALLBACK_API(void, SoundProcPtr)(SInt16 soundNumber);
  typedef CALLBACK_API(Boolean, ModalFilterProcPtr)(DialogRef theDialog,
                                                    EventRecord *theEvent,
                                                    DialogItemIndex *itemHit);
  /** ModalFilterYDProcPtr was previously in StandardFile.h */
  typedef CALLBACK_API(Boolean, ModalFilterYDProcPtr)(DialogRef theDialog,
                                                      EventRecord *theEvent,
                                                      short *itemHit,
                                                      void *yourDataPtr);
  typedef CALLBACK_API(void, UserItemProcPtr)(DialogRef theDialog,
                                              DialogItemIndex itemNo);
  typedef STACK_UPP_TYPE(SoundProcPtr) SoundUPP;
  typedef STACK_UPP_TYPE(ModalFilterProcPtr) ModalFilterUPP;
  typedef STACK_UPP_TYPE(ModalFilterYDProcPtr) ModalFilterYDUPP;
  typedef STACK_UPP_TYPE(UserItemProcPtr) UserItemUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewSoundUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SoundUPP
  NewSoundUPP(SoundProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppSoundProcInfo = 0x00000080
  }; /** pascal no_return_value Func(2_bytes) */
#ifdef __cplusplus
  inline SoundUPP NewSoundUPP(SoundProcPtr userRoutine)
  {
    return (SoundUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppSoundProcInfo, GetCurrentArchitecture());
  }
#else
#define NewSoundUPP(userRoutine)                                            \
  (SoundUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppSoundProcInfo, \
                                  GetCurrentArchitecture())
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  NewModalFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ModalFilterUPP
  NewModalFilterUPP(ModalFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppModalFilterProcInfo = 0x00000FD0
  }; /** pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ModalFilterUPP NewModalFilterUPP(ModalFilterProcPtr userRoutine)
  {
    return (ModalFilterUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppModalFilterProcInfo, GetCurrentArchitecture());
  }
#else
#define NewModalFilterUPP(userRoutine)                                     \
  (ModalFilterUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppModalFilterProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewModalFilterYDUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ModalFilterYDUPP
  NewModalFilterYDUPP(ModalFilterYDProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppModalFilterYDProcInfo = 0x00003FD0
  }; /** pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ModalFilterYDUPP NewModalFilterYDUPP(ModalFilterYDProcPtr userRoutine)
  {
    return (ModalFilterYDUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppModalFilterYDProcInfo,
                                                  GetCurrentArchitecture());
  }
#else
#define NewModalFilterYDUPP(userRoutine)                                     \
  (ModalFilterYDUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppModalFilterYDProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewUserItemUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UserItemUPP
  NewUserItemUPP(UserItemProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppUserItemProcInfo = 0x000002C0
  }; /** pascal no_return_value Func(4_bytes, 2_bytes) */
#ifdef __cplusplus
  inline UserItemUPP NewUserItemUPP(UserItemProcPtr userRoutine)
  {
    return (UserItemUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppUserItemProcInfo, GetCurrentArchitecture());
  }
#else
#define NewUserItemUPP(userRoutine)   \
  (UserItemUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppUserItemProcInfo, GetCurrentArchitecture())
#endif
#endif

#if CALL_NOT_IN_CARBON
  /**
   *  DisposeSoundUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeSoundUPP(SoundUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeSoundUPP(SoundUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeSoundUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  DisposeModalFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeModalFilterUPP(ModalFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeModalFilterUPP(ModalFilterUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeModalFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeModalFilterYDUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeModalFilterYDUPP(ModalFilterYDUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeModalFilterYDUPP(ModalFilterYDUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeModalFilterYDUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeUserItemUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeUserItemUPP(UserItemUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeUserItemUPP(UserItemUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeUserItemUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

#if CALL_NOT_IN_CARBON
  /**
   *  InvokeSoundUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeSoundUPP(SInt16 soundNumber, SoundUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeSoundUPP(SInt16 soundNumber, SoundUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppSoundProcInfo, soundNumber);
  }
#else
#define InvokeSoundUPP(soundNumber, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppSoundProcInfo, (soundNumber))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  InvokeModalFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeModalFilterUPP(DialogRef theDialog, EventRecord *theEvent,
                       DialogItemIndex *itemHit, ModalFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeModalFilterUPP(DialogRef theDialog, EventRecord *theEvent,
                                      DialogItemIndex *itemHit,
                                      ModalFilterUPP userUPP)
  {
    return (Boolean)CALL_THREE_PARAMETER_UPP(userUPP, uppModalFilterProcInfo,
                                             theDialog, theEvent, itemHit);
  }
#else
#define InvokeModalFilterUPP(theDialog, theEvent, itemHit, userUPP)     \
  (Boolean) CALL_THREE_PARAMETER_UPP((userUPP), uppModalFilterProcInfo, \
                                     (theDialog), (theEvent), (itemHit))
#endif
#endif

  /**
   *  InvokeModalFilterYDUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeModalFilterYDUPP(DialogRef theDialog, EventRecord *theEvent,
                         short *itemHit, void *yourDataPtr,
                         ModalFilterYDUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeModalFilterYDUPP(DialogRef theDialog,
                                        EventRecord *theEvent, short *itemHit,
                                        void *yourDataPtr,
                                        ModalFilterYDUPP userUPP)
  {
    return (Boolean)CALL_FOUR_PARAMETER_UPP(userUPP, uppModalFilterYDProcInfo,
                                            theDialog, theEvent, itemHit,
                                            yourDataPtr);
  }
#else
#define InvokeModalFilterYDUPP(theDialog, theEvent, itemHit, yourDataPtr, \
                               userUPP)                                   \
  (Boolean) CALL_FOUR_PARAMETER_UPP((userUPP), uppModalFilterYDProcInfo,  \
                                    (theDialog), (theEvent), (itemHit),   \
                                    (yourDataPtr))
#endif
#endif

  /**
   *  InvokeUserItemUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeUserItemUPP(DialogRef theDialog, DialogItemIndex itemNo,
                    UserItemUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeUserItemUPP(DialogRef theDialog, DialogItemIndex itemNo,
                                UserItemUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppUserItemProcInfo, theDialog, itemNo);
  }
#else
#define InvokeUserItemUPP(theDialog, itemNo, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppUserItemProcInfo, (theDialog), (itemNo))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewSoundProc(userRoutine) NewSoundUPP(userRoutine)
#define NewModalFilterProc(userRoutine) NewModalFilterUPP(userRoutine)
#define NewModalFilterYDProc(userRoutine) NewModalFilterYDUPP(userRoutine)
#define NewUserItemProc(userRoutine) NewUserItemUPP(userRoutine)
#define CallSoundProc(userRoutine, soundNumber) \
  InvokeSoundUPP(soundNumber, userRoutine)
#define CallModalFilterProc(userRoutine, theDialog, theEvent, itemHit) \
  InvokeModalFilterUPP(theDialog, theEvent, itemHit, userRoutine)
#define CallModalFilterYDProc(userRoutine, theDialog, theEvent, itemHit, \
                              yourDataPtr)                               \
  InvokeModalFilterYDUPP(theDialog, theEvent, itemHit, yourDataPtr, userRoutine)
#define CallUserItemProc(userRoutine, theDialog, itemNo) \
  InvokeUserItemUPP(theDialog, itemNo, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

#if !TARGET_OS_MAC
  /** QuickTime 3.0 */
  typedef CALLBACK_API_C(void,
                         QTModelessCallbackProcPtr)(EventRecord *theEvent,
                                                    DialogRef theDialog,
                                                    DialogItemIndex itemHit);
#if CALL_NOT_IN_CARBON
  /**
   *  SetModelessDialogCallbackProc()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  SetModelessDialogCallbackProc(DialogRef theDialog,
                                QTModelessCallbackProcPtr callbackProc);

#endif /** CALL_NOT_IN_CARBON */

  typedef QTModelessCallbackProcPtr QTModelessCallbackUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  GetDialogControlNotificationProc()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  GetDialogControlNotificationProc(void *theProc);

  /**
   *  SetDialogMovableModal()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  SetDialogMovableModal(DialogRef theDialog);

  /**
   *  GetDialogParent()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void *
  GetDialogParent(DialogRef theDialog);

#endif /** CALL_NOT_IN_CARBON */

#endif /** !TARGET_OS_MAC */

  /**
    ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
      © Following types are valid with Appearance 1.0 and later
    ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
  */
  enum
  {
    /** Alert types to pass into StandardAlert */
    kAlertStopAlert = 0,
    kAlertNoteAlert = 1,
    kAlertCautionAlert = 2,
    kAlertPlainAlert = 3
  };

  typedef SInt16 AlertType;
  enum
  {
    kAlertDefaultOKText = -1,     /** "OK"*/
    kAlertDefaultCancelText = -1, /** "Cancel"*/
    kAlertDefaultOtherText = -1   /** "Don't Save"*/
  };

  /** StandardAlert alert button numbers */
  enum
  {
    kAlertStdAlertOKButton = 1,
    kAlertStdAlertCancelButton = 2,
    kAlertStdAlertOtherButton = 3,
    kAlertStdAlertHelpButton = 4
  };

  enum
  {
    /** Dialog Flags for use in NewFeaturesDialog or dlgx resource */
    kDialogFlagsUseThemeBackground = (1 << 0),
    kDialogFlagsUseControlHierarchy = (1 << 1),
    kDialogFlagsHandleMovableModal = (1 << 2),
    kDialogFlagsUseThemeControls = (1 << 3)
  };

  enum
  {
    /** Alert Flags for use in alrx resource */
    kAlertFlagsUseThemeBackground = (1 << 0),
    kAlertFlagsUseControlHierarchy = (1 << 1),
    kAlertFlagsAlertIsMovable = (1 << 2),
    kAlertFlagsUseThemeControls = (1 << 3)
  };

  /** For dftb resource */
  enum
  {
    kDialogFontNoFontStyle = 0,
    kDialogFontUseFontMask = 0x0001,
    kDialogFontUseFaceMask = 0x0002,
    kDialogFontUseSizeMask = 0x0004,
    kDialogFontUseForeColorMask = 0x0008,
    kDialogFontUseBackColorMask = 0x0010,
    kDialogFontUseModeMask = 0x0020,
    kDialogFontUseJustMask = 0x0040,
    kDialogFontUseAllMask = 0x00FF,
    kDialogFontAddFontSizeMask = 0x0100,
    kDialogFontUseFontNameMask = 0x0200,
    kDialogFontAddToMetaFontMask = 0x0400
  };

  /** Also for dftb resource. This one is available in Mac OS X or later. */
  /** It corresponds directly to kControlUseThemeFontIDMask from Controls.h. */
  enum
  {
    kDialogFontUseThemeFontIDMask = 0x0080
  };

  struct AlertStdAlertParamRec
  {
    Boolean movable;            /** Make alert movable modal */
    Boolean helpButton;         /** Is there a help button? */
    ModalFilterUPP filterProc;  /** Event filter */
    ConstStringPtr defaultText; /** Text for button in OK position */
    ConstStringPtr cancelText;  /** Text for button in cancel position */
    ConstStringPtr otherText;   /** Text for button in left position */
    SInt16 defaultButton;       /** Which button behaves as the default */
    SInt16 cancelButton;        /** Which one behaves as cancel (can be 0) */
    UInt16 position;            /** Position (kWindowDefaultPosition in this case */
                                /** equals kWindowAlertPositionParentWindowScreen) */
  };
  typedef struct AlertStdAlertParamRec AlertStdAlertParamRec;
  typedef AlertStdAlertParamRec *AlertStdAlertParamPtr;
  enum
  {
    kHICommandOther =
        FOUR_CHAR_CODE('othr') /** sent by standard sheet dialogs when the "other"
                                  button is pressed */
  };

  enum
  {
    kStdCFStringAlertVersionOne =
        1 /** current version of AlertStdCFStringAlertParamRec */
  };

  /**
   *  Summary:
   *    Flags to CreateStandardAlert that are specified in the
   *    AlertStdCFStringAlertParamRec.flags field.
   */
  enum
  {

    /**
     * Applies to StandardSheet only. Do not dispose of the sheet window
     * after closing it; allows the sheet to be re-used again in a later
     * call to ShowSheetWindow.
     */
    kStdAlertDoNotDisposeSheet = 1 << 0,

    /**
     * Applies to StandardSheet only. Causes the sheet window to be
     * hidden immediately without animation effects when the default
     * button is chosen by the user.
     */
    kStdAlertDoNotAnimateOnDefault = 1 << 1,

    /**
     * Applies to StandardSheet only. Causes the sheet window to be
     * hidden immediately without animation effects when the cancel
     * button is chosen by the user.
     */
    kStdAlertDoNotAnimateOnCancel = 1 << 2,

    /**
     * Applies to StandardSheet only. Causes the sheet window to be
     * hidden immediately without animation effects when the other button
     * is chosen by the user.
     */
    kStdAlertDoNotAnimateOnOther = 1 << 3
  };

  struct AlertStdCFStringAlertParamRec
  {
    UInt32 version;          /** kStdCFStringAlertVersionOne */
    Boolean movable;         /** Make alert movable modal */
    Boolean helpButton;      /** Is there a help button? */
    CFStringRef defaultText; /** Text for button in OK position */
    CFStringRef cancelText;  /** Text for button in cancel position */
    CFStringRef otherText;   /** Text for button in left position */
    SInt16 defaultButton;    /** Which button behaves as the default */
    SInt16 cancelButton;     /** Which one behaves as cancel (can be 0) */
    UInt16 position;         /** Position (kWindowDefaultPosition in this case */
                             /** equals kWindowAlertPositionParentWindowScreen) */
    OptionBits flags;        /** Options for the behavior of the alert or sheet */
  };
  typedef struct AlertStdCFStringAlertParamRec AlertStdCFStringAlertParamRec;
  typedef AlertStdCFStringAlertParamRec *AlertStdCFStringAlertParamPtr;
/** ©©© end Appearance 1.0 or later stuff*/

/**
    NOTE: Code running under MultiFinder or System 7.0 or newer
    should always pass NULL to InitDialogs.
*/
#if CALL_NOT_IN_CARBON

  /**
  \brief Initialize before using Dialog Manager functions

  <pre>InitDialogs initializes the Dialog Manager and optionally installs a routine
to get control after a fatal system error. It should be called once, after calling
InitGraf , InitFonts , InitWindows , InitMenus , TEInit (in that order),
and before using any other Dialog Manager functions.
resumeProc is the address of a caller-supplied routine. In the event of a fatal
system error, the system error alert is displayed and if the user
then selects the Resume button, resumeProc  will get control. If
you use resumeProc =NIL, no routine is installed and the Resume
button will be dimmed.
</pre>
* \returns <pre>none
</pre>
* \note <pre>InitDialogs installs the standard sound procedure (see ErrorSound )
and sets all text-replacement parameters to empty strings (see
ParamText ). It also stores the value of resumeProc  into the
low-memory variable ResumeProc .
During application development, you may wish to create a "resume"
procedure that jumps to some sort of diagnostic code, in an attempt to locate
where the error occurred.
The code at resumeProc  expects no parameters. When it gets control, the
stack has been discarded (reset to the value of the global variable
CurStackBase ) and A5 has been set to its position before the error
occurred. You can test your custom code by calling SysError and clicking
the Resume button when the alert appears.
See SysError , System Error Codes , and IM pg II-356-363 for
related information.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
  void
  InitDialogs(void *ignored);

  /**
  \brief Set up to use non-standard sounds for alerts

  <pre>ErrorSound lets you override the standard sounds that are made when alerts
are invoked.
soundProc is the address of a pascal-style procedure. This routine will get
control at each stage of each alert. A value of NIL disables alert
beeping altogether and also disables the menu bar-blinking that
occurs when the speaker volume has been set to 0.
</pre>
* \returns <pre>none
</pre>
* \note <pre>If you never call this function, the alert will emit simple beeps - up to 3;
one beep for the current alert stage - at the current speaker volume
(adjustable via the control panel DA). In the event that the volume has been
set to 0, the standard "sound" is a flashing of the menu bar. See SysBeep .
If you call ErrorSound ( 0 ), beeping and flashing will not occur.
To customize the sounds, use ErrorSound ( mySounds), as illustrated in
the following example.
Note: Sound number 1 is the sound made when a user clicks outside of a
modal dialog box (as well as in a stage-1 alert).
Example
#include < Dialogs.h >
#include < Sound.h>
pascal void MySoundProc( short sndNum );
#define kSndResNum 128 // 'snd ' resource number
pascal void MySoundProc(short sndNum)
  /* sndNum will range from 0 to 3 */
  {
    SndChannelPtr myChan = 0L;
    Handle mySound;
    OSErr err;
    if (sndNum == 0)
      return;
    mySound = GetResource(soundListRsrc, kSndResNum);
    err = SndNewChannel(&myChan, 0, 0, 0L);
    HLock(mySound);
    err = SndPlay(myChan, mySound, FALSE);
    HUnlock(mySound);
    err = SndDisposeChannel(myChan, FALSE);
  }
  </ pre>
              * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                        *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
              *    \carbon_lib not available *    \mac_os_x not available *
          /
          void
          ErrorSound(SoundUPP soundProc);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  NewDialog()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogRef
  NewDialog(void *dStorage, const Rect *boundsRect, ConstStr255Param title,
            Boolean visible, SInt16 procID, WindowRef behind, Boolean goAwayFlag,
            SInt32 refCon, Handle items);

  /**
   *  GetNewDialog()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogRef
  GetNewDialog(SInt16 dialogID, void *dStorage, WindowRef behind);

  /**
   *  NewColorDialog()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogRef
  NewColorDialog(void *dStorage, const Rect *boundsRect, ConstStr255Param title,
                 Boolean visible, SInt16 procID, WindowRef behind,
                 Boolean goAwayFlag, SInt32 refCon, Handle items);

#if CALL_NOT_IN_CARBON
  /**
   *  CloseDialog()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  CloseDialog(DialogRef theDialog);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  DisposeDialog()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDialog(DialogRef theDialog);

  /**
   *  ModalDialog()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ModalDialog(ModalFilterUPP modalFilter, DialogItemIndex *itemHit);

  /**
  \brief Check if an event belongs to a dialog window

  <pre>IsDialogEvent should be called directly after GetNextEvent if there are
any currently-open modeless dialogs. If the return value is TRUE, the next
step is to call DialogSelect and handle the event.
theEvent is the address of an EventRecord . Normally, this will contain the
data obtained by a call to GetNextEvent in your main event loop.
</pre>
* \returns <pre>a Boolean value indicating whether the event occurred in a modeless
dialog window. It is one of:
FALSE (0)theEvent  is unrelated to dialogs
TRUE (1)theEvent  occurred in a dialog; use DialogSelect to find
which dialog and to handle the event.
</pre>
* \note <pre>You should call IsDialogEvent in your main event loop if you have opened
any modeless dialogs (see NewDialog and GetNewDialog ). It is OK to call
this if all such dialogs are closed or haven't yet been opened - it just
returns FALSE.
The return value is TRUE if theEvent  is an "activate" or "update" event for
any dialog window. If the active window is a dialog, the return value is
TRUE for all mouse-downs in its content region and all other events related
to the window.
In most cases, the next step is to call DialogSelect to see which dialog is
associated with theEvent  and to handle the event. However, that function
doesn't handle -shifted keys or disk-insert events. Thus, you may need to
do some preprocessing of theEvent  beforehand.
If all your dialogs are modal, events are handled immediately after the
dialog is displayed by a loop that calls ModalDialog and you won't need this
function.
Note: It is normal to call IsDialogEvent and DialogSelect in your
event loop even when GetNextEvent returns FALSE (no event). This
ensures correct blinking of the caret for editText items.
DAs: This call checks the windowKind field of the relevant
WindowRecord , looking for a 2 (dialogKind). Since DAs must set their
reference number in this field, you must store 2 into dialog window's
windowKind field, call IsDialogEvent , and restore the value afterwards.
See DialogSelect for an example of usage.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  IsDialogEvent(const EventRecord *theEvent);

  /**
   *  DialogSelect()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  DialogSelect(const EventRecord *theEvent, DialogRef *theDialog,
               DialogItemIndex *itemHit);

  /**
   *  DrawDialog()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DrawDialog(DialogRef theDialog);

  /**
   *  UpdateDialog()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  UpdateDialog(DialogRef theDialog, RgnHandle updateRgn);

  /**
   *  HideDialogItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  HideDialogItem(DialogRef theDialog, DialogItemIndex itemNo);

  /**
   *  ShowDialogItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ShowDialogItem(DialogRef theDialog, DialogItemIndex itemNo);

  /**
   *  FindDialogItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogItemIndexZeroBased
  FindDialogItem(DialogRef theDialog, Point thePt);

  /**
   *  DialogCut()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DialogCut(DialogRef theDialog);

  /**
   *  DialogPaste()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DialogPaste(DialogRef theDialog);

  /**
   *  DialogCopy()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DialogCopy(DialogRef theDialog);

  /**
   *  DialogDelete()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DialogDelete(DialogRef theDialog);

  /**
   *  Alert()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogItemIndex
  Alert(SInt16 alertID, ModalFilterUPP modalFilter);

  /**
   *  StopAlert()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogItemIndex
  StopAlert(SInt16 alertID, ModalFilterUPP modalFilter);

  /**
   *  NoteAlert()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogItemIndex
  NoteAlert(SInt16 alertID, ModalFilterUPP modalFilter);

  /**
   *  CautionAlert()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogItemIndex
  CautionAlert(SInt16 alertID, ModalFilterUPP modalFilter);

  /**
   *  GetDialogItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  GetDialogItem(DialogRef theDialog, DialogItemIndex itemNo,
                DialogItemType *itemType, Handle *item, Rect *box);

  /**
   *  SetDialogItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SetDialogItem(DialogRef theDialog, DialogItemIndex itemNo,
                DialogItemType itemType, Handle item, const Rect *box);

  /**
   *  ParamText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ParamText(ConstStr255Param param0, ConstStr255Param param1,
            ConstStr255Param param2, ConstStr255Param param3);

  /**
   *  SelectDialogItemText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SelectDialogItemText(DialogRef theDialog, DialogItemIndex itemNo,
                       SInt16 strtSel, SInt16 endSel);

  /**
   *  GetDialogItemText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  GetDialogItemText(Handle item, Str255 text);

  /**
   *  SetDialogItemText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SetDialogItemText(Handle item, ConstStr255Param text);

  /**
   *  GetAlertStage()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16
  GetAlertStage(void);

  /**
   *  SetDialogFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SetDialogFont(SInt16 fontNum);

  /**
   *  ResetAlertStage()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ResetAlertStage(void);

  /** APIs in Carbon*/
  /**
   *  GetParamText()
   *

   *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  GetParamText(StringPtr param0, StringPtr param1, StringPtr param2,
               StringPtr param3);

#if CALL_NOT_IN_CARBON
  /**
   *  newdialog()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  DialogRef
  newdialog(void *dStorage, const Rect *boundsRect, const char *title,
            Boolean visible, SInt16 procID, WindowRef behind, Boolean goAwayFlag,
            SInt32 refCon, Handle items);

  /**
   *  newcolordialog()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  DialogRef
  newcolordialog(void *dStorage, const Rect *boundsRect, const char *title,
                 Boolean visible, SInt16 procID, WindowRef behind,
                 Boolean goAwayFlag, SInt32 refCon, Handle items);

  /**
   *  paramtext()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  paramtext(const char *param0, const char *param1, const char *param2,
            const char *param3);

  /**
   *  getdialogitemtext()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  getdialogitemtext(Handle item, char *text);

  /**
   *  setdialogitemtext()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  setdialogitemtext(Handle item, const char *text);

  /**
   *  finddialogitem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  DialogItemIndexZeroBased
  finddialogitem(DialogRef theDialog, Point *thePt);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  AppendDITL()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  AppendDITL(DialogRef theDialog, Handle theHandle, DITLMethod method);

  /**
   *  CountDITL()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogItemIndex
  CountDITL(DialogRef theDialog);

  /**
   *  ShortenDITL()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ShortenDITL(DialogRef theDialog, DialogItemIndex numberItems);

  /**
   *  InsertDialogItem()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  InsertDialogItem(DialogRef theDialog, DialogItemIndex afterItem,
                   DialogItemType itemType, Handle itemHandle, const Rect *box);

  /**
   *  RemoveDialogItems()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  RemoveDialogItems(DialogRef theDialog, DialogItemIndex itemNo,
                    DialogItemIndex amountToRemove, Boolean disposeItemData);

  /**
   *  StdFilterProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  StdFilterProc(DialogRef theDialog, EventRecord *event,
                DialogItemIndex *itemHit);

  /**
  \brief GetStdFilterProc Get a pointer to the Dialog Manager's standard dialog filter

  <pre>GetStdFilterProc returns a pointer to the Dialog Manager's standard dialog
filter.
theProc pointer to dialog filter procedure pointer.
</pre>
* \returns <pre>error code
</pre>
* \note <pre>This routine is not yet documented in any MPW header file (hence, it is not
in any THINK C or THINK Pascal header file either). The information given
above comes from Macintosh Technical Note #304. This tech. note also gives
the inline glue for the call as follows:
pascal OSErr GetStdFilterProc (ProcPtr *theProc)
= {0x303C, 0x0203, 0xAA68};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  GetStdFilterProc(ModalFilterUPP *theProc);

  /**
  \brief SetDialogDefaultItem Tell Dialog Mgr which item in dialog should be default item

  <pre>SetDialogDefaultItem indicates to the Dialog Manager which item is the
default. It will alias the return and enter keys to this item, and also bold
border it.
theDialog dialog whose default item is being set.
newItem item to make be the default item.
</pre>
* \returns <pre>error code
</pre>
* \note <pre>This routine is not yet documented in any MPW header file (hence, it is not
in any THINK C or THINK Pascal header file either). The information given
above comes from Macintosh Technical Note #304. This tech. note also gives
the inline glue for the call as follows:
pascal OSErr SetDialogDefaultItem (DialogPtr theDialog,
short newItem) = {0x303C,0x0304,0xAA68};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  SetDialogDefaultItem(DialogRef theDialog, DialogItemIndex newItem);

  /**
  \brief SetDialogCancelItem Tell Dialog Mgr which item should be default cancel item

  <pre>SetDialogCancelItem indicates to the Dialog Manager which item is the
default cancel item. It will alias the escape or "Command - period".
theDialog dialog whose default item is being set.
newItem item to make be the default cancel item.
</pre>
* \returns <pre>error code
</pre>
* \note <pre>This routine is not yet documented in any MPW header file (hence, it is not
in any THINK C or THINK Pascal header file either). The information given
above comes from Macintosh Technical Note #304. This tech. note also gives
the inline glue for the call as follows:
pascal OSErr SetDialogCancelItem (DialogPtr theDialog,
short newItem) = {0x303C,0x0305,0xAA68};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  SetDialogCancelItem(DialogRef theDialog, DialogItemIndex newItem);

  /**
   *  SetDialogTracksCursor()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetDialogTracksCursor(DialogRef theDialog, Boolean tracks);

  /**
    ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
      © Appearance Dialog Routines (available only with Appearance 1.0 and later)
    ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
  */

  /**
   *  NewFeaturesDialog()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogRef
  NewFeaturesDialog(void *inStorage, const Rect *inBoundsRect,
                    ConstStr255Param inTitle, Boolean inIsVisible,
                    SInt16 inProcID, WindowRef inBehind, Boolean inGoAwayFlag,
                    SInt32 inRefCon, Handle inItemListHandle, UInt32 inFlags);

  /**
   *  AutoSizeDialog()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AutoSizeDialog(DialogRef inDialog);

  /**
      Regarding StandardAlert and constness:
      Even though the inAlertParam parameter is marked const here, there was
      a chance Dialog Manager would modify it on versions of Mac OS prior to 9.
  */
  /**
   *  StandardAlert()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  StandardAlert(AlertType inAlertType, ConstStr255Param inError,
                ConstStr255Param inExplanation,
                const AlertStdAlertParamRec *inAlertParam, /** can be NULL */
                SInt16 *outItemHit);

  /** CFString-based StandardAlert and StandardSheet APIs are only available on
   * Mac OS X and later*/

  /**
   *  GetStandardAlertDefaultParams()
   *
   *  Summary:
   *    Fills out an AlertStdCFStringAlertParamRec with default values: -
   *      not movable -   no help button -   default button with title
   *    "OK" -   no cancel or other buttons
   *
   *  Parameters:
   *
   *    param:
   *      The parameter block to initialize.
   *
   *    version:
   *      The parameter block version; pass kStdCFStringAlertVersionOne.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  GetStandardAlertDefaultParams(AlertStdCFStringAlertParamPtr param,
                                UInt32 version);

  /**
   *  CreateStandardAlert()
   *
   *  Summary:
   *    Creates an alert containing standard elements and using standard
   *    formatting rules.
   *
   *  Discussion:
   *    CreateStandardAlert should be used in conjunction with
   *    RunStandardAlert. After CreateStandardAlert returns, the alert is
   *    still invisible. RunStandardAlert will show the alert and run a
   *    modal dialog loop to process events in the alert.
   *
   *  Parameters:
   *
   *    alertType:
   *      The type of alert to create.
   *
   *    error:
   *      The error string to display.
   *
   *    explanation:
   *      The explanation string to display. May be NULL or empty to
   *      display no explanation.
   *
   *    param:
   *      The parameter block describing how to create the alert. May be
   *      NULL.
   *
   *    outAlert:
   *      On exit, contains the new alert.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  CreateStandardAlert(
      AlertType alertType, CFStringRef error,
      CFStringRef explanation,                    /** can be NULL */
      const AlertStdCFStringAlertParamRec *param, /** can be NULL */
      DialogRef *outAlert);

  /**
   *  RunStandardAlert()
   *
   *  Summary:
   *    Shows and runs a standard alert using a modal dialog loop.
   *
   *  Parameters:
   *
   *    inAlert:
   *      The alert to display.
   *
   *    filterProc:
   *      An event filter function for handling events that do not apply
   *      to the alert. May be NULL.
   *
   *    outItemHit:
   *      On exit, contains the item index of the button that was pressed
   *      to close the alert.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  RunStandardAlert(DialogRef inAlert,
                   ModalFilterUPP filterProc, /** can be NULL */
                   DialogItemIndex *outItemHit);

  /**
   *  CreateStandardSheet()
   *
   *  Summary:
   *    Creates an alert containing standard elements and using standard
   *    formatting rules, and prepares it to be displayed as a sheet.
   *
   *  Discussion:
   *    CreateStandardSheet should be used in conjunction with
   *    ShowSheetWindow. After CreateStandardSheet returns, the alert is
   *    still invisible. ShowSheetWindow will show the alert and then
   *    return. Events in the sheet are handled asynchronously; the
   *    application should be prepared for the sheet window to be part of
   *    its windowlist while running its own event loop. When a button in
   *    the sheet is pressed, the EventTargetRef passed to
   *    CreateStandardSheet will receive a command event with one of the
   *    command IDs kHICommandOK, kHICommandCancel, or kHICommandOther.
   *    The sheet is closed before the command is sent.
   *
   *  Parameters:
   *
   *    alertType:
   *      The type of alert to create.
   *
   *    error:
   *      The error string to display.
   *
   *    explanation:
   *      The explanation string to display. May be NULL or empty to
   *      display no explanation.
   *
   *    param:
   *      The parameter block describing how to create the alert. May be
   *      NULL.
   *
   *    notifyTarget:
   *      The event target to be notified when the sheet is closed. The
   *      caller should install an event handler on this target for the
   *      [kEventClassCommand, kEventProcessCommand] event.
   *
   *    outSheet:
   *      On exit, contains the new alert.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  CreateStandardSheet(
      AlertType alertType, CFStringRef error,
      CFStringRef explanation,                    /** can be NULL */
      const AlertStdCFStringAlertParamRec *param, /** can be NULL */
      EventTargetRef notifyTarget, DialogRef *outSheet);

  /**
   *  CloseStandardSheet()
   *
   *  Summary:
   *    Closes a standard sheet dialog and releases the dialog data
   *    structures.
   *
   *  Discussion:
   *    CloseStandardSheet is meant to be used when you need to remove a
   *    sheet because of a higher-priority request to close the sheet's
   *    document window. For example, you might have a Save Changes sheet
   *    open on a document window. Meanwhile, the user drags the document
   *    into the trash. When your application sees that the document has
   *    been moved to the trash, it knows that it should close the
   *    document window, but first it needs to close the sheet.
   *    CloseStandardSheet should not be used by your Carbon event
   *    handler in response to a click in one of the sheet buttons; the
   *    Dialog Manager will close the sheet automatically in that case.
   *    If kStdAlertDoNotDisposeSheet was specified when the sheet was
   *    created, the sheet dialog will be hidden but not released, and
   *    you can reuse the sheet later.
   *
   *  Parameters:
   *
   *    inSheet:
   *      The sheet to close.
   *
   *    inResultCommand:
   *      This command, if not zero, will be sent to the EventTarget
   *      specified when the sheet was created.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  CloseStandardSheet(DialogRef inSheet, UInt32 inResultCommand);

  /**
   *  GetDialogItemAsControl()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetDialogItemAsControl(DialogRef inDialog, SInt16 inItemNo,
                         ControlRef *outControl);

  /**
   *  MoveDialogItem()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  MoveDialogItem(DialogRef inDialog, SInt16 inItemNo, SInt16 inHoriz,
                 SInt16 inVert);

  /**
   *  SizeDialogItem()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SizeDialogItem(DialogRef inDialog, SInt16 inItemNo, SInt16 inWidth,
                 SInt16 inHeight);

  /**
   *  AppendDialogItemList()
   *

   *    \non_carbon_cfm   in DialogsLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AppendDialogItemList(DialogRef dialog, SInt16 ditlID, DITLMethod method);

  /**
    ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
      © Dialog Routines available only with Appearance 1.1 and later
    ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
  */

  /**
   *  SetDialogTimeout()
   *

   *    \non_carbon_cfm   in DialogsLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  SetDialogTimeout(DialogRef inDialog, SInt16 inButtonToPress,
                   UInt32 inSecondsToWait);

  /**
   *  GetDialogTimeout()
   *

   *    \non_carbon_cfm   in DialogsLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  GetDialogTimeout(DialogRef inDialog, SInt16 *outButtonToPress,
                   UInt32 *outSecondsToWait, UInt32 *outSecondsRemaining);

  /**
   *  SetModalDialogEventMask()
   *

   *    \non_carbon_cfm   in DialogsLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  SetModalDialogEventMask(DialogRef inDialog, EventMask inMask);

  /**
   *  GetModalDialogEventMask()
   *

   *    \non_carbon_cfm   in DialogsLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  GetModalDialogEventMask(DialogRef inDialog, EventMask *outMask);

  /**
    ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
      © Accessor functions
    ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
  */

  /**
   *  GetDialogWindow()
   *

   *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  WindowRef
  GetDialogWindow(DialogRef dialog);
#if !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS
#ifdef __cplusplus
  inline DEFINE_API(WindowRef) GetDialogWindow(DialogRef dialog)
  {
    return (WindowRef)dialog;
  }
#else
#define GetDialogWindow(dialog) ((WindowRef)dialog)
#endif
#endif

  /**
   *  GetDialogTextEditHandle()
   *

   *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TEHandle
  GetDialogTextEditHandle(DialogRef dialog);
#if !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS
#ifdef __cplusplus
  inline DEFINE_API(TEHandle) GetDialogTextEditHandle(DialogRef dialog)
  {
    return ((DialogPeek)dialog)->textH;
  }
#else
#define GetDialogTextEditHandle(dialog) (((DialogPeek)dialog)->textH)
#endif
#endif

  /**
   *  GetDialogDefaultItem()
   *

   *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16
  GetDialogDefaultItem(DialogRef dialog);
#if !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS
#ifdef __cplusplus
  inline DEFINE_API(SInt16) GetDialogDefaultItem(DialogRef dialog)
  {
    return ((DialogPeek)dialog)->aDefItem;
  }
#else
#define GetDialogDefaultItem(dialog) (((DialogPeek)dialog)->aDefItem)
#endif
#endif

  /**
   *  GetDialogCancelItem()
   *

   *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16
  GetDialogCancelItem(DialogRef dialog);
#if !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS
#ifdef __cplusplus
  inline DEFINE_API(SInt16) GetDialogCancelItem(DialogRef dialog)
  {
    return ((DialogPeek)dialog)->editOpen;
  }
#else
#define GetDialogCancelItem(dialog) (((DialogPeek)dialog)->editOpen)
#endif
#endif

  /**
   *  GetDialogKeyboardFocusItem()
   *

   *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt16
  GetDialogKeyboardFocusItem(DialogRef dialog);
#if !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS
#ifdef __cplusplus
  inline DEFINE_API(SInt16) GetDialogKeyboardFocusItem(DialogRef dialog)
  {
    return ((DialogPeek)dialog)->editField < 0
               ? (short)(-1)
               : (short)(((DialogPeek)dialog)->editField + 1);
  }
#else
#define GetDialogKeyboardFocusItem(dialog) \
  (((DialogPeek)dialog)->editField < 0     \
       ? (short)(-1)                       \
       : (short)(((DialogPeek)dialog)->editField + 1))
#endif
#endif

  /**
   *  SetPortDialogPort()
   *

   *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SetPortDialogPort(DialogRef dialog);
#if !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS
#ifdef __cplusplus
  inline DEFINE_API(void) SetPortDialogPort(DialogRef dialog)
  {
    MacSetPort((GrafPtr)dialog);
  }
#else
#define SetPortDialogPort(dialog) (MacSetPort((GrafPtr)dialog))
#endif
#endif

  /**
   *  GetDialogPort()
   *

   *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  CGrafPtr
  GetDialogPort(DialogRef dialog);
#if !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS
#ifdef __cplusplus
  inline DEFINE_API(CGrafPtr) GetDialogPort(DialogRef dialog)
  {
    return (CGrafPtr)dialog;
  }
#else
#define GetDialogPort(dialog) ((CGrafPtr)dialog)
#endif
#endif

  /**
   *  GetDialogFromWindow()
   *

   *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later or as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DialogRef
  GetDialogFromWindow(WindowRef window);
#if !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS
#ifdef __cplusplus
  inline DEFINE_API(DialogRef) GetDialogFromWindow(WindowRef window)
  {
    return (DialogRef)window;
  }
#else
#define GetDialogFromWindow(window) ((DialogRef)window)
#endif
#endif

#if CALL_NOT_IN_CARBON
  /**
   *  CouldDialog()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  CouldDialog(SInt16 dialogID);

  /**
   *  FreeDialog()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  FreeDialog(SInt16 dialogID);

  /**
   *  CouldAlert()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  CouldAlert(SInt16 alertID);

  /**
   *  FreeAlert()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  FreeAlert(SInt16 alertID);

#endif /** CALL_NOT_IN_CARBON */

#if OLDROUTINENAMES
#define DisposDialog(theDialog) DisposeDialog(theDialog)
#define UpdtDialog(theDialog, updateRgn) UpdateDialog(theDialog, updateRgn)
#define GetDItem(theDialog, itemNo, itemType, item, box) \
  GetDialogItem(theDialog, itemNo, itemType, item, box)
#define SetDItem(theDialog, itemNo, itemType, item, box) \
  SetDialogItem(theDialog, itemNo, itemType, item, box)
#define HideDItem(theDialog, itemNo) HideDialogItem(theDialog, itemNo)
#define ShowDItem(theDialog, itemNo) ShowDialogItem(theDialog, itemNo)
#define SelIText(theDialog, itemNo, strtSel, endSel) \
  SelectDialogItemText(theDialog, itemNo, strtSel, endSel)
#define GetIText(item, text) GetDialogItemText(item, text)
#define SetIText(item, text) SetDialogItemText(item, text)
#define FindDItem(theDialog, thePt) FindDialogItem(theDialog, thePt)
#define NewCDialog(dStorage, boundsRect, title, visible, procID, behind, \
                   goAwayFlag, refCon, items)                            \
  NewColorDialog(dStorage, boundsRect, title, visible, procID, behind,   \
                 goAwayFlag, refCon, items)
#define GetAlrtStage() GetAlertStage()
#define ResetAlrtStage() ResetAlertStage()
#define DlgCut(theDialog) DialogCut(theDialog)
#define DlgPaste(theDialog) DialogPaste(theDialog)
#define DlgCopy(theDialog) DialogCopy(theDialog)
#define DlgDelete(theDialog) DialogDelete(theDialog)
#define SetDAFont(fontNum) SetDialogFont(fontNum)
#define SetGrafPortOfDialog(dialog) SetPortDialogPort(dialog)
#if CGLUESUPPORTED
#define newcdialog(dStorage, boundsRect, title, visible, procID, behind, \
                   goAwayFlag, refCon, items)                            \
  newcolordialog(dStorage, boundsRect, title, visible, procID, behind,   \
                 goAwayFlag, refCon, items)
#define getitext(item, text) getdialogitemtext(item, text)
#define setitext(item, text) setdialogitemtext(item, text)
#define findditem(theDialog, thePt) finddialogitem(theDialog, thePt)
#endif
#endif /** OLDROUTINENAMES */

#if !TARGET_OS_MAC
#endif /** !TARGET_OS_MAC */

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

#endif /** __DIALOGS__ */
* / _OS_MAC
#endif /** !TARGET_OS_MAC */

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

#endif /** __DIALOGS__ */
* /*/*/ */*/