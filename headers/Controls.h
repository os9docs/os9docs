/**
     \file       Controls.h

    \brief   Control Manager interfaces

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Managers

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CONTROLS__
#define __CONTROLS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __MENUS__
#include <Menus.h>
#endif

#ifndef __TEXTEDIT__
#include <TextEdit.h>
#endif

#ifndef __DRAG__
#include <Drag.h>
#endif

#ifndef __ICONS__
#include <Icons.h>
#endif

#ifndef __COLLECTIONS__
#include <Collections.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
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

  /*������������������������������������������������������������������������������������������������������*/
  /*  � Resource Types */
  /*������������������������������������������������������������������������������������������������������*/
  enum
  {
    kControlDefProcType = FOUR_CHAR_CODE('CDEF'),
    kControlTemplateResourceType = FOUR_CHAR_CODE('CNTL'),
    kControlColorTableResourceType = FOUR_CHAR_CODE('cctb'),
    kControlDefProcResourceType = FOUR_CHAR_CODE('CDEF')
  };

  /*������������������������������������������������������������������������������������������������������*/
  /*  � Format of a �CNTL� resource */
  /*������������������������������������������������������������������������������������������������������*/
  struct ControlTemplate
  {
    Rect controlRect;
    SInt16 controlValue;
    Boolean controlVisible;
    UInt8 fill;
    SInt16 controlMaximum;
    SInt16 controlMinimum;
    SInt16 controlDefProcID;
    SInt32 controlReference;
    Str255 controlTitle;
  };
  typedef struct ControlTemplate ControlTemplate;
  typedef ControlTemplate *ControlTemplatePtr;
  typedef ControlTemplatePtr *ControlTemplateHandle;

#if !TARGET_OS_MAC
  /**
    ���������������������������������������������������������������������������������������������������������
     � NON-MAC COMPATIBILITY CODES (QuickTime 3.0)
    ���������������������������������������������������������������������������������������������������������
  */
  typedef UInt32 ControlNotification;
  enum
  {
    controlNotifyNothing = FOUR_CHAR_CODE('nada'), /* No (null) notification*/
    controlNotifyClick = FOUR_CHAR_CODE('clik'),   /* Control was clicked*/
    controlNotifyFocus = FOUR_CHAR_CODE('focu'),   /* Control got keyboard focus*/
    controlNotifyKey = FOUR_CHAR_CODE('key ')      /* Control got a keypress*/
  };

  typedef UInt32 ControlCapabilities;
  enum
  {
    kControlCanAutoInvalidate =
        1L << 0 /* Control component automatically invalidates areas left behind
                   after hide/move operation.*/
  };

  /* procID's for our added "controls"*/
  enum
  {
    staticTextProc = 256, /* static text*/
    editTextProc = 272,   /* editable text*/
    iconProc = 288,       /* icon*/
    userItemProc = 304,   /* user drawn item*/
    pictItemProc = 320    /* pict*/
  };

#endif /* !TARGET_OS_MAC */

/*������������������������������������������������������������������������������������������������������*/
/*  � ControlRef */
/*������������������������������������������������������������������������������������������������������*/
#if !OPAQUE_TOOLBOX_STRUCTS
  typedef struct ControlRecord ControlRecord;
  typedef ControlRecord *ControlPtr;
  typedef ControlPtr *ControlRef;
#else
typedef struct OpaqueControlRef *ControlRef;
#endif /* !OPAQUE_TOOLBOX_STRUCTS */

  /* ControlHandle is obsolete. Use ControlRef.*/
  typedef ControlRef ControlHandle;
  typedef SInt16 ControlPartCode;
  /*������������������������������������������������������������������������������������������������������*/
  /* � Control ActionProcPtr */
  /*������������������������������������������������������������������������������������������������������*/
  typedef CALLBACK_API(void, ControlActionProcPtr)(ControlRef theControl,
                                                   ControlPartCode partCode);
  typedef STACK_UPP_TYPE(ControlActionProcPtr) ControlActionUPP;
/*������������������������������������������������������������������������������������������������������*/
/*  � ControlRecord */
/*������������������������������������������������������������������������������������������������������*/
#if !OPAQUE_TOOLBOX_STRUCTS
  struct ControlRecord
  {
    ControlRef nextControl;        /* in Carbon use embedding heirarchy functions*/
    WindowRef contrlOwner;         /* in Carbon use GetControlOwner or EmbedControl*/
    Rect contrlRect;               /* in Carbon use Get/SetControlBounds*/
    UInt8 contrlVis;               /* in Carbon use IsControlVisible, SetControlVisibility*/
    UInt8 contrlHilite;            /* in Carbon use GetControlHilite, HiliteControl*/
    SInt16 contrlValue;            /* in Carbon use Get/SetControlValue,
                                      Get/SetControl32BitValue*/
    SInt16 contrlMin;              /* in Carbon use Get/SetControlMinimum,
                                      Get/SetControl32BitMinimum*/
    SInt16 contrlMax;              /* in Carbon use Get/SetControlMaximum,
                                      Get/SetControl32BitMaximum*/
    Handle contrlDefProc;          /* not supported in Carbon*/
    Handle contrlData;             /* in Carbon use Get/SetControlDataHandle*/
    ControlActionUPP contrlAction; /* in Carbon use Get/SetControlAction*/
    SInt32 contrlRfCon;            /* in Carbon use Get/SetControlReference*/
    Str255 contrlTitle;            /* in Carbon use Get/SetControlTitle*/
  };

#endif /* !OPAQUE_TOOLBOX_STRUCTS */

  /*������������������������������������������������������������������������������������������������������*/
  /* � Control ActionProcPtr : Epilogue */
  /*������������������������������������������������������������������������������������������������������*/
  /**
   *  NewControlActionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ControlActionUPP
  NewControlActionUPP(ControlActionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppControlActionProcInfo = 0x000002C0
  }; /* pascal no_return_value Func(4_bytes, 2_bytes) */
#ifdef __cplusplus
  inline ControlActionUPP NewControlActionUPP(ControlActionProcPtr userRoutine)
  {
    return (ControlActionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppControlActionProcInfo,
                                                  GetCurrentArchitecture());
  }
#else
#define NewControlActionUPP(userRoutine)                                     \
  (ControlActionUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppControlActionProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeControlActionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeControlActionUPP(ControlActionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeControlActionUPP(ControlActionUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeControlActionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeControlActionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeControlActionUPP(ControlRef theControl, ControlPartCode partCode,
                         ControlActionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeControlActionUPP(ControlRef theControl,
                                     ControlPartCode partCode,
                                     ControlActionUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppControlActionProcInfo, theControl,
                           partCode);
  }
#else
#define InvokeControlActionUPP(theControl, partCode, userUPP)               \
  CALL_TWO_PARAMETER_UPP((userUPP), uppControlActionProcInfo, (theControl), \
                         (partCode))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewControlActionProc(userRoutine) NewControlActionUPP(userRoutine)
#define CallControlActionProc(userRoutine, theControl, partCode) \
  InvokeControlActionUPP(theControl, partCode, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

  /*������������������������������������������������������������������������������������������������������*/
  /*  � Control Color Table */
  /*������������������������������������������������������������������������������������������������������*/
  enum
  {
    cFrameColor = 0,
    cBodyColor = 1,
    cTextColor = 2,
    cThumbColor = 3,
    kNumberCtlCTabEntries = 4
  };

  struct CtlCTab
  {
    SInt32 ccSeed;
    SInt16 ccRider;
    SInt16 ctSize;
    ColorSpec ctTable[4];
  };
  typedef struct CtlCTab CtlCTab;
  typedef CtlCTab *CCTabPtr;
  typedef CCTabPtr *CCTabHandle;
/*������������������������������������������������������������������������������������������������������*/
/*  � Auxiliary Control Record */
/*������������������������������������������������������������������������������������������������������*/
#if !OPAQUE_TOOLBOX_STRUCTS
  struct AuxCtlRec
  {
    Handle acNext;        /* not supported in Carbon*/
    ControlRef acOwner;   /* not supported in Carbon*/
    CCTabHandle acCTable; /* not supported in Carbon*/
    SInt16 acFlags;       /* not supported in Carbon*/
    SInt32 acReserved;    /* not supported in Carbon*/
    SInt32 acRefCon;      /* in Carbon use Get/SetControlProperty if you need more
                             refCons*/
  };
  typedef struct AuxCtlRec AuxCtlRec;
  typedef AuxCtlRec *AuxCtlPtr;
  typedef AuxCtlPtr *AuxCtlHandle;
#endif /* !OPAQUE_TOOLBOX_STRUCTS */

  /*��������������������������������������������������������������������������������������*/
  /*  � Control Variants */
  /*��������������������������������������������������������������������������������������*/
  typedef SInt16 ControlVariant;
  enum
  {
    kControlNoVariant = 0, /* No variant*/
    kControlUsesOwningWindowsFontVariant =
        1 << 3 /* Control uses owning windows font to display text*/
  };

  /*��������������������������������������������������������������������������������������*/
  /*  � Control Part Codes */
  /*��������������������������������������������������������������������������������������*/
  /* Basic part codes */
  enum
  {
    kControlNoPart = 0,
    kControlIndicatorPart = 129,
    kControlDisabledPart = 254,
    kControlInactivePart = 255
  };

  /* Use this constant in Get/SetControlData when the data referred to is not */
  /* specific to a part, but rather the entire control, e.g. the list handle of a
   */
  /* list box control. */
  enum
  {
    kControlEntireControl = 0
  };

  /*  Meta-Parts */
  /*                                                                                      */
  /*  If you haven't guessed from looking at other toolbox headers. We like the
   * word      */
  /*  'meta'. It's cool. So here's one more for you. A meta-part is a part used in
   * a call */
  /*  to the GetControlRegion API. These parts are parts that might be defined by
   * a       */
  /*  control, but should not be returned from calls like TestControl, et al. They
   * define */
  /*  a region of a control, presently the structure and the content region. The
   * content  */
  /*  region is only defined by controls that can embed other controls. It is the
   * area    */
  /*  that embedded content can live. */
  /*                                                                                      */
  /*  Along with these parts, you can also pass in normal part codes to get the
   * regions   */
  /*  of the parts. Not all controls fully support this at the time this was
   * written.     */
  enum
  {
    kControlStructureMetaPart = -1,
    kControlContentMetaPart = -2
  };

  /* focusing part codes */
  enum
  {
    kControlFocusNoPart = 0,    /* tells control to clear its focus*/
    kControlFocusNextPart = -1, /* tells control to focus on the next part*/
    kControlFocusPrevPart = -2  /* tells control to focus on the previous part*/
  };

  typedef SInt16 ControlFocusPart;
  /*������������������������������������������������������������������������������������������������������*/
  /*  � Control Collection Tags */
  /*������������������������������������������������������������������������������������������������������*/
  /*  These are standard tags that you will find in the initial data Collection
   * that is passed in the     */
  /*  'param' parameter to the initCntl message (Carbon only). */
  /*                                                                                                      */
  /*  All tags at ID zero in a Control's Collection are reserved for Control
   * Manager use.                 */
  /*  Custom control definitions should use other IDs. */
  /*                                                                                                      */
  /*  Most of these tags are interpreted when you call CreateCustomControl; the
   * Control Manager will      */
  /*  put value in the right place before calling the Control Definition with the
   * initialization message. */
  enum
  {
    kControlCollectionTagBounds =
        FOUR_CHAR_CODE('boun'),                          /* Rect - the bounding rectangle*/
    kControlCollectionTagValue = FOUR_CHAR_CODE('valu'), /* SInt32 - the value*/
    kControlCollectionTagMinimum =
        FOUR_CHAR_CODE('min '), /* SInt32 - the minimum*/
    kControlCollectionTagMaximum =
        FOUR_CHAR_CODE('max '), /* SInt32 - the maximum*/
    kControlCollectionTagViewSize =
        FOUR_CHAR_CODE('view'), /* SInt32 - the view size*/
    kControlCollectionTagVisibility =
        FOUR_CHAR_CODE('visi'),                           /* Boolean - the visible state*/
    kControlCollectionTagRefCon = FOUR_CHAR_CODE('refc'), /* SInt32 - the refCon*/
    kControlCollectionTagTitle =
        FOUR_CHAR_CODE('titl'), /* arbitrarily sized character array - the title*/
    kControlCollectionTagUnicodeTitle = FOUR_CHAR_CODE(
        'uttl'), /* bytes as received via CFStringCreateExternalRepresentation*/
    kControlCollectionTagIDSignature =
        FOUR_CHAR_CODE('idsi'), /* OSType - the ControlID signature*/
    kControlCollectionTagIDID =
        FOUR_CHAR_CODE('idid'), /* SInt32 - the ControlID id*/
    kControlCollectionTagCommand =
        FOUR_CHAR_CODE('cmd '), /* UInt32 - the command*/
    kControlCollectionTagVarCode =
        FOUR_CHAR_CODE('varc') /* SInt16 - the variant*/
  };

  /*������������������������������������������������������������������������������������������������������*/
  /*  � Control Image Content */
  /*������������������������������������������������������������������������������������������������������*/
  enum
  {
    kControlContentTextOnly = 0,
    kControlNoContent = 0,
    kControlContentIconSuiteRes = 1,
    kControlContentCIconRes = 2,
    kControlContentPictRes = 3,
    kControlContentICONRes = 4,
    kControlContentIconSuiteHandle = 129,
    kControlContentCIconHandle = 130,
    kControlContentPictHandle = 131,
    kControlContentIconRef = 132,
    kControlContentICON = 133
  };

  typedef SInt16 ControlContentType;
  struct ControlButtonContentInfo
  {
    ControlContentType contentType;
    union
    {
      SInt16 resID;
      CIconHandle cIconHandle;
      Handle iconSuite;
      IconRef iconRef;
      PicHandle picture;
      Handle ICONHandle;
    } u;
  };
  typedef struct ControlButtonContentInfo ControlButtonContentInfo;
  typedef ControlButtonContentInfo *ControlButtonContentInfoPtr;
  typedef ControlButtonContentInfo ControlImageContentInfo;
  typedef ControlButtonContentInfo *ControlImageContentInfoPtr;
  /*������������������������������������������������������������������������������������������������������*/
  /*  � Control Key Script Behavior */
  /*������������������������������������������������������������������������������������������������������*/
  enum
  {
    kControlKeyScriptBehaviorAllowAnyScript =
        FOUR_CHAR_CODE('any '), /* leaves the current keyboard alone and allows
                                   user to change the keyboard.*/
    kControlKeyScriptBehaviorPrefersRoman =
        FOUR_CHAR_CODE('prmn'), /* switches the keyboard to roman, but allows them
                                   to change it as desired.*/
    kControlKeyScriptBehaviorRequiresRoman =
        FOUR_CHAR_CODE('rrmn') /* switches the keyboard to roman and prevents the
                                  user from changing it.*/
  };

  typedef UInt32 ControlKeyScriptBehavior;
  /*������������������������������������������������������������������������������������������������������*/
  /*  � Control Font Style */
  /*������������������������������������������������������������������������������������������������������*/
  /*    SPECIAL FONT USAGE NOTES: You can specify the font to use for many control
     types. The constants below are meta-font numbers which you can use to set a
     particular control's font usage. There are essentially two modes you can use:
     1) default, which is essentially the same as it always has been, i.e. it uses
     the system font, unless directed to use the window font via a control
     variant. 2) you can specify to use the big or small system font in a generic
     manner. The Big system font is the font used in menus, etc. Chicago has
     filled that role for some time now. Small system font is currently Geneva 10.
     The meta-font number implies the size and style.

      NOTE:       Not all font attributes are used by all controls. Most, in fact,
     ignore the fore and back color (Static Text is the only one that does, for
                  backwards compatibility). Also size, face, and addFontSize are
     ignored when using the meta-font numbering.
  */
  /* Meta-font numbering - see note above */
  enum
  {
    kControlFontBigSystemFont = -1,       /* force to big system font*/
    kControlFontSmallSystemFont = -2,     /* force to small system font*/
    kControlFontSmallBoldSystemFont = -3, /* force to small bold system font*/
    kControlFontViewSystemFont =
        -4 /* force to views system font (DataBrowser control only)*/
  };

  /* Add these masks together to set the flags field of a ControlFontStyleRec */
  /* They specify which fields to apply to the text. It is important to make  */
  /* sure that you specify only the fields that you wish to set.              */
  enum
  {
    kControlUseFontMask = 0x0001,
    kControlUseFaceMask = 0x0002,
    kControlUseSizeMask = 0x0004,
    kControlUseForeColorMask = 0x0008,
    kControlUseBackColorMask = 0x0010,
    kControlUseModeMask = 0x0020,
    kControlUseJustMask = 0x0040,
    kControlUseAllMask = 0x00FF,
    kControlAddFontSizeMask = 0x0100
  };

  /* AddToMetaFont indicates that we want to start with a standard system     */
  /* font, but then we'd like to add the other attributes. Normally, the meta */
  /* font ignores all other flags                                             */
  enum
  {
    kControlAddToMetaFontMask = 0x0200 /* Available in Appearance 1.1 or later*/
  };

  /* UseThemeFontID indicates that the font field of the ControlFontStyleRec  */
  /* should be interpreted as a ThemeFontID (see Appearance.h). In all other  */
  /* ways, specifying a ThemeFontID is just like using one of the control     */
  /* meta-fonts IDs.                                                          */
  enum
  {
    kControlUseThemeFontIDMask = 0x0080 /* Available in Mac OS X or later*/
  };

  struct ControlFontStyleRec
  {
    SInt16 flags;
    SInt16 font;
    SInt16 size;
    SInt16 style;
    SInt16 mode;
    SInt16 just;
    RGBColor foreColor;
    RGBColor backColor;
  };
  typedef struct ControlFontStyleRec ControlFontStyleRec;
  typedef ControlFontStyleRec *ControlFontStylePtr;
  /*������������������������������������������������������������������������������������������������������*/
  /*  � Click Activation Results */
  /*������������������������������������������������������������������������������������������������������*/
  /*  These are for use with GetControlClickActivation. The enumerated values
   * should be pretty            */
  /*  self-explanatory, but just in case: */
  /*  � Activate/DoNotActivate indicates whether or not to change the owning
   * window's z-ordering before   */
  /*      processing the click. If activation is requested, you may also want to
   * immediately redraw the   */
  /*      newly exposed portion of the window. */
  /*  � Ignore/Handle Click indicates whether or not to call an appropriate click
   * handling API (like      */
  /*      HandleControlClick) in respose to the event. */
  enum
  {
    kDoNotActivateAndIgnoreClick =
        0,                            /* probably never used. here for completeness.*/
    kDoNotActivateAndHandleClick = 1, /* let the control handle the click while
                                         the window is still in the background.*/
    kActivateAndIgnoreClick =
        2,                      /* control doesn't want to respond directly to the click, but window
                                   should still be brought forward.*/
    kActivateAndHandleClick = 3 /* control wants to respond to the click, but only
                                   after the window has been activated.*/
  };

  typedef UInt32 ClickActivationResult;
  /*������������������������������������������������������������������������������������������������������*/
  /*  � Common data tags for Get/SetControlData */
  /*������������������������������������������������������������������������������������������������������*/

  /**
   *  Discussion:
   *    Get/SetControlData Common Tags
   */
  enum
  {
    kControlFontStyleTag = FOUR_CHAR_CODE('font'),
    kControlKeyFilterTag = FOUR_CHAR_CODE('fltr'),

    /**
     * Sent with a pointer to a ControlKind record to be filled in. Only
     * valid for GetControlData.
     */
    kControlKindTag = FOUR_CHAR_CODE('kind'),

    /**
     * Sent with a pointer to a ControlSize. Only valid with explicitly
     * sizeable controls.
     */
    kControlSizeTag = FOUR_CHAR_CODE('size')
  };

  /*������������������������������������������������������������������������������������������������������*/
  /*  � Control Feature Bits */
  /*������������������������������������������������������������������������������������������������������*/
  enum
  {
    /* Control feature bits - returned by GetControlFeatures */
    kControlSupportsGhosting = 1 << 0,
    kControlSupportsEmbedding = 1 << 1,
    kControlSupportsFocus = 1 << 2,
    kControlWantsIdle = 1 << 3,
    kControlWantsActivate = 1 << 4,
    kControlHandlesTracking = 1 << 5,
    kControlSupportsDataAccess = 1 << 6,
    kControlHasSpecialBackground = 1 << 7,
    kControlGetsFocusOnClick = 1 << 8,
    kControlSupportsCalcBestRect = 1 << 9,
    kControlSupportsLiveFeedback = 1 << 10,
    kControlHasRadioBehavior = 1
                               << 11,          /* Available in Appearance 1.0.1 or later*/
    kControlSupportsDragAndDrop = 1 << 12,     /* Available in Carbon*/
    kControlAutoToggles = 1 << 14,             /* Available in Appearance 1.1 or later*/
    kControlSupportsGetRegion = 1 << 17,       /* Available in Appearance 1.1 or later*/
    kControlSupportsFlattening = 1 << 19,      /* Available in Carbon*/
    kControlSupportsSetCursor = 1 << 20,       /* Available in Carbon*/
    kControlSupportsContextualMenus = 1 << 21, /* Available in Carbon*/
    kControlSupportsClickActivation = 1 << 22, /* Available in Carbon*/
    kControlIdlesWithTimer = 1 << 23           /* Available in Carbon - this bit indicates
                                                  that the control animates automatically*/
  };

  /*������������������������������������������������������������������������������������������������������*/
  /*  � Control Messages */
  /*������������������������������������������������������������������������������������������������������*/
  enum
  {
    drawCntl = 0,
    testCntl = 1,
    calcCRgns = 2,
    initCntl = 3, /* Param is Collection, result is OSStatus*/
    dispCntl = 4,
    posCntl = 5,
    thumbCntl = 6,
    dragCntl = 7,
    autoTrack = 8,
    calcCntlRgn = 10,
    calcThumbRgn = 11,
    drawThumbOutline = 12,
    kControlMsgDrawGhost = 13,
    kControlMsgCalcBestRect =
        14, /* Calculate best fitting rectangle for control*/
    kControlMsgHandleTracking = 15,
    kControlMsgFocus = 16, /* param indicates action.*/
    kControlMsgKeyDown = 17,
    kControlMsgIdle = 18,
    kControlMsgGetFeatures = 19,
    kControlMsgSetData = 20,
    kControlMsgGetData = 21,
    kControlMsgActivate = 22,
    kControlMsgSetUpBackground = 23,
    kControlMsgCalcValueFromPos = 26,
    kControlMsgTestNewMsgSupport =
        27,                            /* See if this control supports new messaging*/
    kControlMsgSubValueChanged = 25,   /* Available in Appearance 1.0.1 or later*/
    kControlMsgSubControlAdded = 28,   /* Available in Appearance 1.0.1 or later*/
    kControlMsgSubControlRemoved = 29, /* Available in Appearance 1.0.1 or later*/
    kControlMsgApplyTextColor = 30,    /* Available in Appearance 1.1 or later*/
    kControlMsgGetRegion = 31,         /* Available in Appearance 1.1 or later*/
    kControlMsgFlatten = 32,           /* Available in Carbon. Param is Collection.*/
    kControlMsgSetCursor =
        33,                           /* Available in Carbon. Param is ControlSetCursorRec*/
    kControlMsgDragEnter = 38,        /* Available in Carbon. Param is DragRef, result is
                                         boolean indicating acceptibility of drag.*/
    kControlMsgDragLeave = 39,        /* Available in Carbon. As above.*/
    kControlMsgDragWithin = 40,       /* Available in Carbon. As above.*/
    kControlMsgDragReceive = 41,      /* Available in Carbon. Param is DragRef, result
                                         is OSStatus indicating success/failure.*/
    kControlMsgDisplayDebugInfo = 46, /* Available in Carbon on X.*/
    kControlMsgContextualMenuClick =
        47, /* Available in Carbon. Param is ControlContextualMenuClickRec*/
    kControlMsgGetClickActivation =
        48 /* Available in Carbon. Param is ControlClickActivationRec*/
  };

  typedef SInt16 ControlDefProcMessage;
  /*��������������������������������������������������������������������������������������*/
  /*  � Control Sizes */
  /*��������������������������������������������������������������������������������������*/
  enum
  {
    kControlSizeNormal = 0,
    kControlSizeSmall = 1,
    kControlSizeLarge = 2,
    kControlSizeAuto = 0xFFFF
  };

  typedef UInt16 ControlSize;
  /*��������������������������������������������������������������������������������������*/
  /*  � Constants for drawCntl message (passed in param) */
  /*��������������������������������������������������������������������������������������*/
  enum
  {
    kDrawControlEntireControl = 0,
    kDrawControlIndicatorOnly = 129
  };

  /*��������������������������������������������������������������������������������������*/
  /*  � Constants for dragCntl message (passed in param) */
  /*��������������������������������������������������������������������������������������*/
  enum
  {
    kDragControlEntireControl = 0,
    kDragControlIndicator = 1
  };

  /*��������������������������������������������������������������������������������������*/
  /*  � Drag Constraint Structure for thumbCntl message (passed in param) */
  /*��������������������������������������������������������������������������������������*/
  struct IndicatorDragConstraint
  {
    Rect limitRect;
    Rect slopRect;
    DragConstraint axis;
  };
  typedef struct IndicatorDragConstraint IndicatorDragConstraint;
  typedef IndicatorDragConstraint *IndicatorDragConstraintPtr;
  /*��������������������������������������������������������������������������������������*/
  /*  CDEF should return as result of kControlMsgTestNewMsgSupport */
  /*��������������������������������������������������������������������������������������*/
  enum
  {
    kControlSupportsNewMessages = FOUR_CHAR_CODE(' ok ')
  };

  /*��������������������������������������������������������������������������������������*/
  /*  This structure is passed into a CDEF when called with the
   * kControlMsgHandleTracking */
  /*  message */
  /*��������������������������������������������������������������������������������������*/
  struct ControlTrackingRec
  {
    Point startPt;
    EventModifiers modifiers;
    ControlActionUPP action;
  };
  typedef struct ControlTrackingRec ControlTrackingRec;
  typedef ControlTrackingRec *ControlTrackingPtr;
  /*��������������������������������������������������������������������������������������*/
  /* This structure is passed into a CDEF when called with the kControlMsgKeyDown
   * message */
  /*��������������������������������������������������������������������������������������*/
  struct ControlKeyDownRec
  {
    EventModifiers modifiers;
    SInt16 keyCode;
    SInt16 charCode;
  };
  typedef struct ControlKeyDownRec ControlKeyDownRec;
  typedef ControlKeyDownRec *ControlKeyDownPtr;
  /*��������������������������������������������������������������������������������������*/
  /* This structure is passed into a CDEF when called with the kControlMsgGetData
   * or      */
  /* kControlMsgSetData message */
  /*��������������������������������������������������������������������������������������*/
  struct ControlDataAccessRec
  {
    ResType tag;
    ResType part;
    Size size;
    Ptr dataPtr;
  };
  typedef struct ControlDataAccessRec ControlDataAccessRec;
  typedef ControlDataAccessRec *ControlDataAccessPtr;
  /*��������������������������������������������������������������������������������������*/
  /* This structure is passed into a CDEF when called with the
   * kControlCalcBestRect msg   */
  /*��������������������������������������������������������������������������������������*/
  struct ControlCalcSizeRec
  {
    SInt16 height;
    SInt16 width;
    SInt16 baseLine;
  };
  typedef struct ControlCalcSizeRec ControlCalcSizeRec;
  typedef ControlCalcSizeRec *ControlCalcSizePtr;
  /*��������������������������������������������������������������������������������������*/
  /* This structure is passed into a CDEF when called with the
   * kControlMsgSetUpBackground */
  /* message is sent */
  /*��������������������������������������������������������������������������������������*/
  struct ControlBackgroundRec
  {
    SInt16 depth;
    Boolean colorDevice;
  };
  typedef struct ControlBackgroundRec ControlBackgroundRec;
  typedef ControlBackgroundRec *ControlBackgroundPtr;
  /*��������������������������������������������������������������������������������������*/
  /* This structure is passed into a CDEF when called with the
   * kControlMsgApplyTextColor  */
  /* message is sent */
  /*��������������������������������������������������������������������������������������*/
  struct ControlApplyTextColorRec
  {
    SInt16 depth;
    Boolean colorDevice;
    Boolean active;
  };
  typedef struct ControlApplyTextColorRec ControlApplyTextColorRec;
  typedef ControlApplyTextColorRec *ControlApplyTextColorPtr;
  /*��������������������������������������������������������������������������������������*/
  /* This structure is passed into a CDEF when called with the
   * kControlMsgGetRegion       */
  /* message is sent */
  /*��������������������������������������������������������������������������������������*/
  struct ControlGetRegionRec
  {
    RgnHandle region;
    ControlPartCode part;
  };
  typedef struct ControlGetRegionRec ControlGetRegionRec;
  typedef ControlGetRegionRec *ControlGetRegionPtr;
  /*��������������������������������������������������������������������������������������*/
  /* This structure is passed into a CDEF when the kControlMsgSetCursor message is
   * sent   */
  /* Only sent on Carbon */
  /*��������������������������������������������������������������������������������������*/
  struct ControlSetCursorRec
  {
    Point localPoint;
    EventModifiers modifiers;
    Boolean cursorWasSet; /* your CDEF must set this to true if you set the
                             cursor, or false otherwise*/
  };
  typedef struct ControlSetCursorRec ControlSetCursorRec;
  typedef ControlSetCursorRec *ControlSetCursorPtr;
  /*��������������������������������������������������������������������������������������*/
  /* This structure is passed into a CDEF when the kControlMsgContextualMenuClick
   * message */
  /* is sent */
  /* Only sent on Carbon */
  /*��������������������������������������������������������������������������������������*/
  struct ControlContextualMenuClickRec
  {
    Point localPoint;
    Boolean menuDisplayed; /* your CDEF must set this to true if you displayed a
                              menu, or false otherwise*/
  };
  typedef struct ControlContextualMenuClickRec ControlContextualMenuClickRec;
  typedef ControlContextualMenuClickRec *ControlContextualMenuClickPtr;
  /*��������������������������������������������������������������������������������������*/
  /* This structure is passed into a CDEF when the kControlMsgGetClickActivation
   * message  */
  /* is sent */
  /* Only sent on Carbon */
  /*��������������������������������������������������������������������������������������*/
  struct ControlClickActivationRec
  {
    Point localPoint;
    EventModifiers modifiers;
    ClickActivationResult result; /* your CDEF must pass the desired result back*/
  };
  typedef struct ControlClickActivationRec ControlClickActivationRec;
  typedef ControlClickActivationRec *ControlClickActivationPtr;
  /*��������������������������������������������������������������������������������������*/
  /*  � �CDEF� entrypoint */
  /*��������������������������������������������������������������������������������������*/
  typedef CALLBACK_API(SInt32, ControlDefProcPtr)(SInt16 varCode,
                                                  ControlRef theControl,
                                                  ControlDefProcMessage message,
                                                  SInt32 param);
  typedef STACK_UPP_TYPE(ControlDefProcPtr) ControlDefUPP;
  /**
   *  NewControlDefUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ControlDefUPP
  NewControlDefUPP(ControlDefProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppControlDefProcInfo = 0x00003BB0
  }; /* pascal 4_bytes Func(2_bytes, 4_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ControlDefUPP NewControlDefUPP(ControlDefProcPtr userRoutine)
  {
    return (ControlDefUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppControlDefProcInfo, GetCurrentArchitecture());
  }
#else
#define NewControlDefUPP(userRoutine)   \
  (ControlDefUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppControlDefProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeControlDefUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeControlDefUPP(ControlDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeControlDefUPP(ControlDefUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeControlDefUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeControlDefUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SInt32
  InvokeControlDefUPP(SInt16 varCode, ControlRef theControl,
                      ControlDefProcMessage message, SInt32 param,
                      ControlDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline SInt32 InvokeControlDefUPP(SInt16 varCode, ControlRef theControl,
                                    ControlDefProcMessage message, SInt32 param,
                                    ControlDefUPP userUPP)
  {
    return (SInt32)CALL_FOUR_PARAMETER_UPP(userUPP, uppControlDefProcInfo,
                                           varCode, theControl, message, param);
  }
#else
#define InvokeControlDefUPP(varCode, theControl, message, param, userUPP)  \
  (SInt32)                                                                 \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppControlDefProcInfo, (varCode), \
                              (theControl), (message), (param))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewControlDefProc(userRoutine) NewControlDefUPP(userRoutine)
#define CallControlDefProc(userRoutine, varCode, theControl, message, param) \
  InvokeControlDefUPP(varCode, theControl, message, param, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

  /*��������������������������������������������������������������������������������������*/
  /*  Control Key Filter */
  /*��������������������������������������������������������������������������������������*/
  /* Certain controls can have a keyfilter attached to them. */
  /* Definition of a key filter for intercepting and possibly changing keystrokes
   */
  /* which are destined for a control. */
  /* Key Filter Result Codes */
  /* The filter proc should return one of the two constants below. If */
  /* kKeyFilterBlockKey is returned, the key is blocked and never makes it to the
   */
  /* control. If kKeyFilterPassKey is returned, the control receives the
   * keystroke.   */
  enum
  {
    kControlKeyFilterBlockKey = 0,
    kControlKeyFilterPassKey = 1
  };

  typedef SInt16 ControlKeyFilterResult;
  typedef CALLBACK_API(ControlKeyFilterResult,
                       ControlKeyFilterProcPtr)(ControlRef theControl,
                                                SInt16 *keyCode, SInt16 *charCode,
                                                EventModifiers *modifiers);
  typedef STACK_UPP_TYPE(ControlKeyFilterProcPtr) ControlKeyFilterUPP;
  /**
   *  NewControlKeyFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ControlKeyFilterUPP
  NewControlKeyFilterUPP(ControlKeyFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppControlKeyFilterProcInfo = 0x00003FE0
  }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ControlKeyFilterUPP
  NewControlKeyFilterUPP(ControlKeyFilterProcPtr userRoutine)
  {
    return (ControlKeyFilterUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                     uppControlKeyFilterProcInfo,
                                                     GetCurrentArchitecture());
  }
#else
#define NewControlKeyFilterUPP(userRoutine)                               \
  (ControlKeyFilterUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),      \
                                             uppControlKeyFilterProcInfo, \
                                             GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeControlKeyFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeControlKeyFilterUPP(ControlKeyFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeControlKeyFilterUPP(ControlKeyFilterUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeControlKeyFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeControlKeyFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ControlKeyFilterResult
  InvokeControlKeyFilterUPP(ControlRef theControl, SInt16 *keyCode,
                            SInt16 *charCode, EventModifiers *modifiers,
                            ControlKeyFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline ControlKeyFilterResult
  InvokeControlKeyFilterUPP(ControlRef theControl, SInt16 *keyCode,
                            SInt16 *charCode, EventModifiers *modifiers,
                            ControlKeyFilterUPP userUPP)
  {
    return (ControlKeyFilterResult)CALL_FOUR_PARAMETER_UPP(
        userUPP, uppControlKeyFilterProcInfo, theControl, keyCode, charCode,
        modifiers);
  }
#else
#define InvokeControlKeyFilterUPP(theControl, keyCode, charCode, modifiers, \
                                  userUPP)                                  \
  (ControlKeyFilterResult) CALL_FOUR_PARAMETER_UPP(                         \
      (userUPP), uppControlKeyFilterProcInfo, (theControl), (keyCode),      \
      (charCode), (modifiers))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewControlKeyFilterProc(userRoutine) NewControlKeyFilterUPP(userRoutine)
#define CallControlKeyFilterProc(userRoutine, theControl, keyCode, charCode, \
                                 modifiers)                                  \
  InvokeControlKeyFilterUPP(theControl, keyCode, charCode, modifiers,        \
                            userRoutine)
#endif /* CALL_NOT_IN_CARBON */

  /*��������������������������������������������������������������������������������������*/
  /*  � DragGrayRgn Constatns */
  /*                                                                                      */
  /*   For DragGrayRgnUPP used in TrackControl() */
  /*��������������������������������������������������������������������������������������*/
  enum
  {
    noConstraint = kNoConstraint,
    hAxisOnly = 1,
    vAxisOnly = 2
  };

  /*��������������������������������������������������������������������������������������*/
  /*  � Control Creation/Deletion/Persistence */
  /*��������������������������������������������������������������������������������������*/
  /*  CreateCustomControl is only available as part of Carbon */
  enum
  {
    kControlDefProcPtr = 0,    /* raw proc-ptr based access*/
    kControlDefObjectClass = 1 /* event-based definition (Mac OS X only)*/
  };

  typedef UInt32 ControlDefType;
  struct ControlDefSpec
  {
    ControlDefType defType;
    union
    {
      ControlDefUPP defProc;
      void *classRef;
    } u;
  };
  typedef struct ControlDefSpec ControlDefSpec;
  /**
   *  CreateCustomControl()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  CreateCustomControl(WindowRef owningWindow, const Rect *contBounds,
                      const ControlDefSpec *def, Collection initData,
                      ControlRef *outControl);

  /**
   *  NewControl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ControlRef
  NewControl(WindowRef owningWindow, const Rect *boundsRect,
             ConstStr255Param controlTitle, Boolean initiallyVisible,
             SInt16 initialValue, SInt16 minimumValue, SInt16 maximumValue,
             SInt16 procID, SInt32 controlReference);

  /**
   *  GetNewControl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ControlRef
  GetNewControl(SInt16 resourceID, WindowRef owningWindow);

  /**
   *  DisposeControl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeControl(ControlRef theControl);

  /**
   *  KillControls()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  KillControls(WindowRef theWindow);

  /*��������������������������������������������������������������������������������������*/
  /*  � Control Definition Registration */
  /*��������������������������������������������������������������������������������������*/
  typedef CALLBACK_API(OSStatus, ControlCNTLToCollectionProcPtr)(
      const Rect *bounds, SInt16 value, Boolean visible, SInt16 max, SInt16 min,
      SInt16 procID, SInt32 refCon, ConstStr255Param title,
      Collection collection);
  typedef STACK_UPP_TYPE(ControlCNTLToCollectionProcPtr)
      ControlCNTLToCollectionUPP;
  /**
   *  NewControlCNTLToCollectionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ControlCNTLToCollectionUPP
  NewControlCNTLToCollectionUPP(ControlCNTLToCollectionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppControlCNTLToCollectionProcInfo = 0x00FEA6F0
  }; /* pascal 4_bytes Func(4_bytes, 2_bytes, 1_byte, 2_bytes, 2_bytes, 2_bytes,
        4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ControlCNTLToCollectionUPP
  NewControlCNTLToCollectionUPP(ControlCNTLToCollectionProcPtr userRoutine)
  {
    return (ControlCNTLToCollectionUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppControlCNTLToCollectionProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewControlCNTLToCollectionUPP(userRoutine)                \
  (ControlCNTLToCollectionUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppControlCNTLToCollectionProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeControlCNTLToCollectionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeControlCNTLToCollectionUPP(ControlCNTLToCollectionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  DisposeControlCNTLToCollectionUPP(ControlCNTLToCollectionUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeControlCNTLToCollectionUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeControlCNTLToCollectionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  InvokeControlCNTLToCollectionUPP(const Rect *bounds, SInt16 value,
                                   Boolean visible, SInt16 max, SInt16 min,
                                   SInt16 procID, SInt32 refCon,
                                   ConstStr255Param title, Collection collection,
                                   ControlCNTLToCollectionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeControlCNTLToCollectionUPP(
      const Rect *bounds, SInt16 value, Boolean visible, SInt16 max, SInt16 min,
      SInt16 procID, SInt32 refCon, ConstStr255Param title, Collection collection,
      ControlCNTLToCollectionUPP userUPP)
  {
    return (OSStatus)CALL_NINE_PARAMETER_UPP(
        userUPP, uppControlCNTLToCollectionProcInfo, bounds, value, visible, max,
        min, procID, refCon, title, collection);
  }
#else
#define InvokeControlCNTLToCollectionUPP(bounds, value, visible, max, min,  \
                                         procID, refCon, title, collection, \
                                         userUPP)                           \
  (OSStatus) CALL_NINE_PARAMETER_UPP(                                       \
      (userUPP), uppControlCNTLToCollectionProcInfo, (bounds), (value),     \
      (visible), (max), (min), (procID), (refCon), (title), (collection))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewControlCNTLToCollectionProc(userRoutine) \
  NewControlCNTLToCollectionUPP(userRoutine)
#define CallControlCNTLToCollectionProc(userRoutine, bounds, value, visible, \
                                        max, min, procID, refCon, title,     \
                                        collection)                          \
  InvokeControlCNTLToCollectionUPP(bounds, value, visible, max, min, procID, \
                                   refCon, title, collection, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

  /**
   *  RegisterControlDefinition()
   *
   *  Summary:
   *    Associates or dissociates a control definition with a virtual
   *    CDEF resource ID.
   *
   *  Discussion:
   *    In GetNewControl or NewControl on Carbon, the Control Manager
   *    needs to know how to map the procID to a ControlDefSpec. With
   *    RegisterControlDefinition, your application can inform the
   *    Control Manager which ControlDefSpec to call when it sees a
   *    request to use a 'CDEF' of a particular resource ID. Since custom
   *    control definitions receive their initialization data in a
   *    Collection passed in the 'param' parameter, you must also provide
   *    a procedure to convert the bounds, min, max, and other parameters
   *    to NewControl into a Collection. If you don't provide a
   *    conversion proc, your control will receive an empty collection
   *    when it is sent the initialization message. If you want the
   *    value, min, visibility, etc. to be given to the control, you must
   *    add the appropriate tagged data to the collection. See the
   *    Control Collection Tags above. If you want to unregister a
   *    ControlDefSpec that you have already registered, call
   *    RegisterControlDefinition with the same CDEF resource ID, but
   *    pass NULL for the inControlDef parameter. In this situation,
   *    inConversionProc is effectively ignored.
   *
   *  Parameters:
   *
   *    inCDEFResID:
   *      The virtual CDEF resource ID to which you'd like to associate
   *      or dissociate the control definition.
   *
   *    inControlDef:
   *      A pointer to a ControlDefSpec which represents the control
   *      definition you want to register, or NULL if you are attempting
   *      to unregister a control definition.
   *
   *    inConversionProc:
   *      The conversion proc which will translate the NewControl
   *      parameters into a Collection.
   *
   *  Result:
   *    An OSStatus code indicating success or failure.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  RegisterControlDefinition(SInt16 inCDEFResID,
                            const ControlDefSpec *inControlDef,
                            ControlCNTLToCollectionUPP inConversionProc);

  /*��������������������������������������������������������������������������������������*/
  /*  � Control Visible State */
  /*��������������������������������������������������������������������������������������*/
  /**
   *  HiliteControl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  HiliteControl(ControlRef theControl, ControlPartCode hiliteState);

  /**
   *  ShowControl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ShowControl(ControlRef theControl);

  /**
   *  HideControl()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  HideControl(ControlRef theControl);

  /* following state routines available only with Appearance 1.0 and later*/
  /**
   *  IsControlActive()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  IsControlActive(ControlRef inControl);

  /**
   *  IsControlVisible()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  IsControlVisible(ControlRef inControl);

  /**
   *  ActivateControl()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ActivateControl(ControlRef inControl);

  /**
   *  DeactivateControl()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DeactivateControl(ControlRef inControl);

  /**
   *  SetControlVisibility()
   *

   *    \non_carbon_cfm   in AppearanceLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetControlVisibility(ControlRef inControl, Boolean inIsVisible,
                       Boolean inDoDraw);

  /* following state routines available only on Mac OS X and later*/
  /**
   *  IsControlEnabled()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  IsControlEnabled(ControlRef inControl);

  /**
   *  EnableControl()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  EnableControl(ControlRef inControl);

  /**
   *  DisableControl()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  DisableControl(ControlRef inControl);

  /*��������������������������������������������������������������������������������������*/
  /*  � Control Imaging */
  /*��������������������������������������������������������������������������������������*/

  /**
  \brief Draw all controls visible in a window

  <pre>DrawControls draws all of a window's currently active and visible controls.
This (or UpdtControl ) should be used upon detecting an update event for a
window that contains controls.
theWindow is a pointer to a 108-byte GrafPort structure (actually a 156-byte
WindowRecord ). It is typically a value obtained from
EventRecord .message after calling WaitNextEvent .
</pre>
* \returns <pre>none
</pre>
* \note <pre>This can be used at any time to draw the controls in a window. It works by
drawing all the controls, and letting the off-screen or covered controls be
clipped. The 128K ROM UpdtControl function is more efficient since it
doesn't waste time drawing outside of the window's visible region.
The most common usage is to call DrawControls to redraw scroll bars
upon detecting an update event as in this code skeleton:
if ( GetNextEvent ( everyEvent , &myEvent ) ) {
switch ( myEvent.what ) {
case updateEvt :
updtWin = (WindowPtr)myEvent.message;
GetPort ( &savePort );
SetPort ( updtWin)
BeginUpdate ( updtWin );
DrawControls ( updtWin );
DrawGrowIcon ( updtWin); // if needed
MyDrawWin(updtWin); /* draw window contents */
  EndUpdate(updtWin);
  SetPort(savePort) break;
case mouseDown:
  .....etc...
      .
}
}
The ’size icon' (if used) is also part of the content region of a window and will need to be redrawn when it is uncovered.</ pre>
            * \copyright THINK Reference © 1991 -
        1992 Symantec Corporation
            *    \non_carbon_cfm in InterfaceLib 7.1 and
    later
        *    \carbon_lib in CarbonLib 1.0 and
    later
        *    \mac_os_x in version 10.0 and
    later
            * /
        void
        DrawControls(WindowRef theWindow);

/**
 *  Draw1Control()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void Draw1Control(ControlRef theControl);

#define DrawOneControl(theControl) Draw1Control(theControl)

/**
 *  UpdateControls()
 *
 *  Summary:
 *    Redraws the controls that intersect a specified region in a
 *    window.
 *
 *  Parameters:
 *
 *    inWindow:
 *      The window whose controls to redraw.
 *
 *    inUpdateRegion:
 *      The region (in local coordinates) describing which controls to
 *      redraw. In Mac OS 10.1 and later, and in CarbonLib 1.5 and
 *      later, you may pass NULL for this parameter to redraw the
 *      controls intersecting the visible region of the window.
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void UpdateControls(
    WindowRef inWindow,
    RgnHandle inUpdateRegion) /* can be NULL */;

/* following imaging routines available only with Appearance 1.0 and later*/
/**
 *  GetBestControlRect()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr GetBestControlRect(ControlRef inControl, Rect *outRect,
                         SInt16 *outBaseLineOffset);

/**
 *  SetControlFontStyle()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr SetControlFontStyle(ControlRef inControl, const ControlFontStyleRec *inStyle);

/**
 *  DrawControlInCurrentPort()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DrawControlInCurrentPort(ControlRef inControl);

/**
 *  SetUpControlBackground()
 *
 *  Summary:
 *    Applies the proper background color for the given control to the
 *    current port.
 *
 *  Discussion:
 *    An embedding-savvy control which erases before drawing must
 *    ensure that its background color properly matches the body color
 *    of any parent controls on top of which it draws. This routine
 *    asks the Control Manager to determine and apply the proper
 *    background color to the current port. If a ControlColorProc has
 *    been provided for the given control, the proc will be called to
 *    set up the background color. If no proc exists, or if the proc
 *    returns a value other than noErr, the Control Manager ascends the
 *    parent chain for the given control looking for a control which
 *    has a special background (see the kControlHasSpecialBackground
 *    feature bit). The first such parent is asked to set up the
 *    background color (see the kControlMsgSetUpBackground message). If
 *    no such parent exists, the Control Manager applies any ThemeBrush
 *    which has been associated with the owning window (see
 *    SetThemeWindowBackground). Available in Appearance 1.0 (Mac OS
 *    8), CarbonLib 1.0, Mac OS X, and later.
 *
 *  Parameters:
 *
 *    inControl:
 *      The ControlRef that wants to erase.
 *
 *    inDepth:
 *      A short integer indicating the color depth of the device onto
 *      which drawing will take place.
 *
 *    inIsColorDevice:
 *      A Boolean indicating whether the draw device is a color device.
 *
 *  Result:
 *    An OSStatus code indicating success or failure. The most likely
 *    error is a controlHandleInvalidErr, resulting from a bad
 *    ControlRef. Any non-noErr result indicates that the color set up
 *    failed, and that the caller should probably give up its attempt
 *    to draw.
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr SetUpControlBackground(ControlRef inControl, SInt16 inDepth,
                             Boolean inIsColorDevice);

/**
 *  SetUpControlTextColor()
 *
 *  Summary:
 *    Applies the proper text color for the given control to the
 *    current port.
 *
 *  Discussion:
 *    An embedding-savvy control which draws text must ensure that its
 *    text color properly contrasts the background on which it draws.
 *    This routine asks the Control Manager to determine and apply the
 *    proper text color to the current port. If a ControlColorProc has
 *    been provided for the given control, the proc will be called to
 *    set up the text color. If no proc exists, or if the proc returns
 *    a value other than noErr, the Control Manager ascends the parent
 *    chain for the given control looking for a control which has a
 *    special background (see the kControlHasSpecialBackground feature
 *    bit). The first such parent is asked to set up the text color
 *    (see the kControlMsgApplyTextColor message). If no such parent
 *    exists, the Control Manager chooses a text color which contrasts
 *    any ThemeBrush which has been associated with the owning window
 *    (see SetThemeWindowBackground). Available in Appearance 1.1 (Mac
 *    OS 8.5), CarbonLib 1.0, Mac OS X, and later.
 *
 *  Parameters:
 *
 *    inControl:
 *      The ControlRef that wants to draw text.
 *
 *    inDepth:
 *      A short integer indicating the color depth of the device onto
 *      which drawing will take place.
 *
 *    inIsColorDevice:
 *      A Boolean indicating whether the draw device is a color device.
 *
 *  Result:
 *    An OSStatus code indicating success or failure. The most likely
 *    error is a controlHandleInvalidErr, resulting from a bad
 *    ControlRef. Any non-noErr result indicates that the color set up
 *    failed, and that the caller should probably give up its attempt
 *    to draw.
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr SetUpControlTextColor(ControlRef inControl, SInt16 inDepth,
                            Boolean inIsColorDevice);

/**
 *  ControlColorProcPtr
 *
 *  Discussion:
 *    Callback allowing clients to specify/override the background
 *    color and text color that a Control will use during drawing. Your
 *    procedure should make the color changes to the current port. See
 *    SetControlColorProc, SetUpControlBackground, and
 *    SetUpControlTextColor for more information. Available on Mac OS
 *    8.5, CarbonLib 1.1, Mac OS X, and later.
 *
 *  Parameters:
 *
 *    inControl:
 *      A reference to the Control for whom your proc is setting up
 *      colors.
 *
 *    inMessage:
 *      A ControlDefProcMessage indicating what sort of color your
 *      procedure should set up. It will be either
 *      kControlMsgApplyTextColor or kControlMsgSetUpBackground.
 *      kControlMsgApplyTextColor is a request to set up the
 *      appropriate text color (by setting the current port's
 *      foreground color, pen information, etc.).
 *      kControlMsgSetUpBackground is a request to set up the
 *      appropriate background color (the current port's background
 *      color, pattern, etc.).
 *
 *    inDrawDepth:
 *      A short integer indicating the bit depth of the device into
 *      which the Control is drawing. The bit depth is typically passed
 *      in as a result of someone someone trying to draw properly
 *      across multiple monitors with different bit depths. If your
 *      procedure wants to handle proper color set up based on bit
 *      depth, it should use this parameter to help decide what color
 *      to apply.
 *
 *    inDrawInColor:
 *      A Boolean indicating whether or not the device that the Control
 *      is drawing into is a color device. The value is typically
 *      passed in as a result of someone trying to draw properly across
 *      multiple monitors which may or may not be color devices. If
 *      your procedure wants to handle proper color set up for both
 *      color and grayscale devices, it should use this parameter to
 *      help decide what color to apply.
 *
 *  Result:
 *    An OSStatus code indicating success or failure. Returning noErr
 *    is an indication that your proc completely handled the color set
 *    up. If you return any other value, the Control Manager will fall
 *    back to the normal color set up mechanism.
 */
typedef CALLBACK_API(OSStatus, ControlColorProcPtr)(ControlRef inControl,
                                                    SInt16 inMessage,
                                                    SInt16 inDrawDepth,
                                                    Boolean inDrawInColor);
typedef STACK_UPP_TYPE(ControlColorProcPtr) ControlColorUPP;
/**
 *  NewControlColorUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlColorUPP
NewControlColorUPP(ControlColorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum
{
  uppControlColorProcInfo = 0x00001AF0
}; /* pascal 4_bytes Func(4_bytes, 2_bytes, 2_bytes, 1_byte) */
#ifdef __cplusplus
inline ControlColorUPP NewControlColorUPP(ControlColorProcPtr userRoutine)
{
  return (ControlColorUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                               uppControlColorProcInfo,
                                               GetCurrentArchitecture());
}
#else
#define NewControlColorUPP(userRoutine)                                     \
  (ControlColorUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppControlColorProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeControlColorUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DisposeControlColorUPP(ControlColorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeControlColorUPP(ControlColorUPP userUPP)
{
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeControlColorUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeControlColorUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
InvokeControlColorUPP(ControlRef inControl, SInt16 inMessage,
                      SInt16 inDrawDepth, Boolean inDrawInColor,
                      ControlColorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline OSStatus InvokeControlColorUPP(ControlRef inControl, SInt16 inMessage,
                                      SInt16 inDrawDepth, Boolean inDrawInColor,
                                      ControlColorUPP userUPP)
{
  return (OSStatus)CALL_FOUR_PARAMETER_UPP(userUPP, uppControlColorProcInfo,
                                           inControl, inMessage, inDrawDepth,
                                           inDrawInColor);
}
#else
#define InvokeControlColorUPP(inControl, inMessage, inDrawDepth,               \
                              inDrawInColor, userUPP)                          \
  (OSStatus)                                                                   \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppControlColorProcInfo, (inControl), \
                              (inMessage), (inDrawDepth), (inDrawInColor))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewControlColorProc(userRoutine) NewControlColorUPP(userRoutine)
#define CallControlColorProc(userRoutine, inControl, inMessage, inDrawDepth, \
                             inDrawInColor)                                  \
  InvokeControlColorUPP(inControl, inMessage, inDrawDepth, inDrawInColor,    \
                        userRoutine)
#endif /* CALL_NOT_IN_CARBON */

/**
 *  SetControlColorProc()
 *
 *  Summary:
 *    Associates a ControlColorUPP with a given Control, thereby
 *    allowing you to bypass the embedding hierarchy-based color setup
 *    of SetUpControlBackground/SetUpControlTextColor and replace it
 *    with your own.
 *
 *  Discussion:
 *    Before an embedded Control can erase, it calls
 *    SetUpControlBackground to have its background color set up by any
 *    parent controls. Similarly, any Control which draws text calls
 *    SetUpControlTextColor to have the appropriate text color set up.
 *    This allows certain controls (such as Tabs and Placards) to offer
 *    special backgrounds and text colors for any child controls. By
 *    default, the SetUp routines only move up the Control Manager
 *    embedding hierarchy looking for a parent which has a special
 *    background. This is fine in a plain vanilla embedding case, but
 *    many application frameworks find it troublesome; if there are
 *    interesting views between two Controls in the embedding
 *    hierarchy, the framework needs to be in charge of the background
 *    and text colors, otherwise drawing defects will occur. You can
 *    only associate a single color proc with a given ControlRef.
 *    Available on Mac OS 8.5, CarbonLib 1.1, Mac OS X, and later.
 *
 *  Parameters:
 *
 *    inControl:
 *      The ControlRef with whom the color proc should be associated.
 *
 *    inProc:
 *      The color proc to associate with the ControlRef. If you pass
 *      NULL, the ControlRef will be dissociated from any previously
 *      installed color proc.
 *
 *  Result:
 *    An OSStatus code indicating success or failure. The most likely
 *    error is a controlHandleInvalidErr resulting from a bad
 *    ControlRef.
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
SetControlColorProc(ControlRef inControl, ControlColorUPP inProc);

/*��������������������������������������������������������������������������������������*/
/*  � Control Mousing */
/*��������������������������������������������������������������������������������������*/
/**
    NOTE ON CONTROL ACTION PROCS

    When using the TrackControl() call when tracking an indicator, the
   actionProc parameter (type ControlActionUPP) should be replaced by a
   parameter of type DragGrayRgnUPP (see Quickdraw.h).

    If, however, you are using the live feedback variants of scroll bars or
   sliders, you must pass a ControlActionUPP in when tracking the indicator as
   well. This functionality is available in Appearance 1.0 or later.
*/
/**
 *  TrackControl()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlPartCode
TrackControl(
    ControlRef theControl, Point startPoint,
    ControlActionUPP actionProc) /* can be NULL */;

/**
 *  DragControl()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DragControl(ControlRef theControl, Point startPoint, const Rect *limitRect,
                 const Rect *slopRect, DragConstraint axis);

/**
 *  TestControl()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlPartCode
TestControl(ControlRef theControl, Point testPoint);

/**
 *  FindControl()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlPartCode
FindControl(Point testPoint, WindowRef theWindow, ControlRef *theControl);

/* The following mousing routines available only with Appearance 1.0 and later
 */
/*                                                                              */
/* HandleControlClick is preferable to TrackControl when running under */
/* Appearance 1.0 as you can pass in modifiers, which some of the new controls
 */
/* use, such as edit text and list boxes. */
/**
 *  FindControlUnderMouse()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlRef
FindControlUnderMouse(Point inWhere, WindowRef inWindow,
                      ControlPartCode *outPart);

/**
 *  HandleControlClick()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlPartCode
HandleControlClick(
    ControlRef inControl, Point inWhere, EventModifiers inModifiers,
    ControlActionUPP inAction) /* can be NULL */;

/* Contextual Menu support in the Control Manager is only available on Carbon.
 */
/* If the control didn't display a contextual menu (possibly because the point
 */
/* was in a non-interesting part), the menuDisplayed output parameter will be */
/* false. If the control did display a menu, menuDisplayed will be true. */
/* This in on Carbon only */
/**
 *  HandleControlContextualMenuClick()
 *

 *    \non_carbon_cfm   in ControlsLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
HandleControlContextualMenuClick(ControlRef inControl, Point inWhere,
                                 Boolean *menuDisplayed);

/* Some complex controls (like Data Browser) require proper sequencing of */
/* window activation and click processing. In some cases, the control might */
/* want the window to be left inactive yet still handle the click, or vice- */
/* versa. The GetControlClickActivation routine lets a control client ask the */
/* control how it wishes to behave for a particular click. */
/* This in on Carbon only. */
/**
 *  GetControlClickActivation()
 *

 *    \non_carbon_cfm   in ControlsLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
GetControlClickActivation(ControlRef inControl, Point inWhere,
                          EventModifiers inModifiers,
                          ClickActivationResult *outResult);

/*��������������������������������������������������������������������������������������*/
/*  � Control Events (available only with Appearance 1.0 and later) */
/*��������������������������������������������������������������������������������������*/
/**
 *  HandleControlKey()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlPartCode
HandleControlKey(ControlRef inControl, SInt16 inKeyCode, SInt16 inCharCode,
                 EventModifiers inModifiers);

/**
 *  IdleControls()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void IdleControls(WindowRef inWindow);

/*��������������������������������������������������������������������������������������*/
/* � Control Mouse Tracking (available with Carbon) */
/*��������������������������������������������������������������������������������������*/
/* The HandleControlSetCursor routine requests that a given control set the
 * cursor to   */
/* something appropriate based on the mouse location. */
/* If the control didn't want to set the cursor (because the point was in a */
/* non-interesting part), the cursorWasSet output parameter will be false. If
 * the       */
/* control did set the cursor, cursorWasSet will be true. */
/* Carbon only. */
/**
 *  HandleControlSetCursor()
 *

 *    \non_carbon_cfm   in ControlsLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
HandleControlSetCursor(ControlRef control, Point localPoint,
                       EventModifiers modifiers, Boolean *cursorWasSet);

/*��������������������������������������������������������������������������������������*/
/*  � Control Positioning */
/*��������������������������������������������������������������������������������������*/
/**
 *  MoveControl()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void MoveControl(ControlRef theControl, SInt16 h, SInt16 v);

/**
 *  SizeControl()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SizeControl(ControlRef theControl, SInt16 w, SInt16 h);

/*��������������������������������������������������������������������������������������*/
/*  � Control Title */
/*��������������������������������������������������������������������������������������*/
/**
 *  SetControlTitle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlTitle(ControlRef theControl, ConstStr255Param title);

/**
 *  GetControlTitle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void GetControlTitle(ControlRef theControl, Str255 title);

/**
 *  SetControlTitleWithCFString()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
SetControlTitleWithCFString(ControlRef inControl, CFStringRef inString);

/**
 *  CopyControlTitleAsCFString()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
CopyControlTitleAsCFString(ControlRef inControl, CFStringRef *outString);

/*��������������������������������������������������������������������������������������*/
/*  � Control Value */
/*��������������������������������������������������������������������������������������*/
/**
 *  GetControlValue()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt16
GetControlValue(ControlRef theControl);

/**
 *  SetControlValue()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlValue(ControlRef theControl, SInt16 newValue);

/**
 *  GetControlMinimum()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt16
GetControlMinimum(ControlRef theControl);

/**
 *  SetControlMinimum()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlMinimum(ControlRef theControl, SInt16 newMinimum);

/**
 *  GetControlMaximum()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt16
GetControlMaximum(ControlRef theControl);

/**
 *  SetControlMaximum()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlMaximum(ControlRef theControl, SInt16 newMaximum);

/* proportional scrolling/32-bit value support is new with Appearance 1.1*/

/**
 *  GetControlViewSize()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
GetControlViewSize(ControlRef theControl);

/**
 *  SetControlViewSize()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlViewSize(ControlRef theControl, SInt32 newViewSize);

/**
 *  GetControl32BitValue()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
GetControl32BitValue(ControlRef theControl);

/**
 *  SetControl32BitValue()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControl32BitValue(ControlRef theControl, SInt32 newValue);

/**
 *  GetControl32BitMaximum()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
GetControl32BitMaximum(ControlRef theControl);

/**
 *  SetControl32BitMaximum()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControl32BitMaximum(ControlRef theControl, SInt32 newMaximum);

/**
 *  GetControl32BitMinimum()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
GetControl32BitMinimum(ControlRef theControl);

/**
 *  SetControl32BitMinimum()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControl32BitMinimum(ControlRef theControl, SInt32 newMinimum);

/**
    IsValidControlHandle will tell you if the handle you pass in belongs to a
   control the Control Manager knows about. It does not sanity check the data in
   the control.
*/

/**
 *  IsValidControlHandle()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
IsValidControlHandle(ControlRef theControl);

/*��������������������������������������������������������������������������������������*/
/* � Control IDs */
/* Carbon only. */
/*��������������������������������������������������������������������������������������*/
struct ControlID
{
  OSType signature;
  SInt32 id;
};
typedef struct ControlID ControlID;
/**
 *  SetControlID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
SetControlID(ControlRef inControl, const ControlID *inID);

/**
 *  GetControlID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
GetControlID(ControlRef inControl, ControlID *outID);

/**
 *  GetControlByID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
GetControlByID(WindowRef inWindow, const ControlID *inID,
               ControlRef *outControl);

/*��������������������������������������������������������������������������������������*/
/* � Control Command IDs */
/* Carbon only. */
/*��������������������������������������������������������������������������������������*/
/**
 *  SetControlCommandID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
SetControlCommandID(ControlRef inControl, UInt32 inCommandID);

/**
 *  GetControlCommandID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
GetControlCommandID(ControlRef inControl, UInt32 *outCommandID);

/*��������������������������������������������������������������������������������������*/
/* � Control Identification */
/* Carbon only. */
/*��������������������������������������������������������������������������������������*/
struct ControlKind
{
  OSType signature;
  OSType kind;
};
typedef struct ControlKind ControlKind;

/**
 *  Discussion:
 *    Control signature kind
 */
enum
{

  /**
   * Signature of all system controls.
   */
  kControlKindSignatureApple = FOUR_CHAR_CODE('appl')
};

/**
 *  GetControlKind()
 *
 *  Summary:
 *    Returns the kind of the given control.
 *
 *  Discussion:
 *    GetControlKind allows you to query the kind of any control. This
 *    function is only available in Mac OS X.
 *
 *  Parameters:
 *
 *    inControl:
 *      The ControlRef to find the kind of.
 *
 *    outControlKind:
 *      On successful exit, this will contain the control signature and
 *      kind. See ControlDefinitions.h for the kinds of each system
 *      control.
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
GetControlKind(ControlRef inControl, ControlKind *outControlKind);

/*��������������������������������������������������������������������������������������*/
/* � Properties */
/*��������������������������������������������������������������������������������������*/
enum
{
  kControlPropertyPersistent = 0x00000001 /* whether this property gets saved
                                             when flattening the control*/
};

/**
 *  GetControlProperty()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
GetControlProperty(ControlRef control, OSType propertyCreator,
                   OSType propertyTag, UInt32 bufferSize, UInt32 *actualSize,
                   void *propertyBuffer);

/**
 *  GetControlPropertySize()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
GetControlPropertySize(ControlRef control, OSType propertyCreator,
                       OSType propertyTag, UInt32 *size);

/**
 *  SetControlProperty()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
SetControlProperty(ControlRef control, OSType propertyCreator,
                   OSType propertyTag, UInt32 propertySize, void *propertyData);

/**
 *  RemoveControlProperty()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
RemoveControlProperty(ControlRef control, OSType propertyCreator,
                      OSType propertyTag);

/**
 *  GetControlPropertyAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
GetControlPropertyAttributes(ControlRef control, OSType propertyCreator,
                             OSType propertyTag, UInt32 *attributes);

/**
 *  ChangeControlPropertyAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
ChangeControlPropertyAttributes(ControlRef control, OSType propertyCreator,
                                OSType propertyTag, UInt32 attributesToSet,
                                UInt32 attributesToClear);

/*��������������������������������������������������������������������������������������*/
/*  � Control Regions (Appearance 1.1 or later) */
/*                                                                                      */
/*  See the discussion on meta-parts in this header for more information */
/*��������������������������������������������������������������������������������������*/
/**
 *  GetControlRegion()
 *

 *    \non_carbon_cfm   in ControlsLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
GetControlRegion(ControlRef inControl, ControlPartCode inPart,
                 RgnHandle outRegion);

/*��������������������������������������������������������������������������������������*/
/*  � Control Variant */
/*��������������������������������������������������������������������������������������*/
/**
 *  GetControlVariant()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlVariant
GetControlVariant(ControlRef theControl);

/*��������������������������������������������������������������������������������������*/
/*  � Control Action */
/*��������������������������������������������������������������������������������������*/
/**
 *  SetControlAction()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlAction(ControlRef theControl, ControlActionUPP actionProc);

/**
 *  GetControlAction()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlActionUPP
GetControlAction(ControlRef theControl);

/*��������������������������������������������������������������������������������������*/
/* � Control Accessors */
/*��������������������������������������������������������������������������������������*/
/**
 *  SetControlReference()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlReference(ControlRef theControl, SInt32 data);

/**
 *  GetControlReference()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
GetControlReference(ControlRef theControl);

#if !OPAQUE_TOOLBOX_STRUCTS
#if CALL_NOT_IN_CARBON
/**
 *  GetAuxiliaryControlRecord()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GetAuxiliaryControlRecord(ControlRef theControl, AuxCtlHandle *acHndl);

#endif /* CALL_NOT_IN_CARBON */

#endif /* !OPAQUE_TOOLBOX_STRUCTS */

#if CALL_NOT_IN_CARBON
/**
 *  SetControlColor()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetControlColor(ControlRef theControl, CCTabHandle newColorTable);

/*��������������������������������������������������������������������������������������*/
/*  � Control Hierarchy (Appearance 1.0 and later only) */
/*��������������������������������������������������������������������������������������*/
#endif /* CALL_NOT_IN_CARBON */

/**
 *  SendControlMessage()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
SendControlMessage(ControlRef inControl, SInt16 inMessage, void *inParam);

/**
 *  DumpControlHierarchy()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr DumpControlHierarchy(WindowRef inWindow, const FSSpec *inDumpFile);

/**
 *  CreateRootControl()
 *
 *  Summary:
 *    Creates a new root control for a window.
 *
 *  Parameters:
 *
 *    inWindow:
 *      The window for which to create a root control.
 *
 *    outControl:
 *      On exit, contains the window's root control. In Mac OS 10.1 and
 *      CarbonLib 1.5 and later, this parameter may be NULL if you
 *      don't need the ControlRef.
 *
 *  Result:
 *    A result code indicating success or failure. errRootAlreadyExists
 *    is returned if the window already has a root control.
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr CreateRootControl(
    WindowRef inWindow,
    ControlRef *outControl) /* can be NULL */;

/**
 *  GetRootControl()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr GetRootControl(WindowRef inWindow, ControlRef *outControl);

/**
 *  EmbedControl()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr EmbedControl(ControlRef inControl, ControlRef inContainer);

/**
 *  AutoEmbedControl()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr AutoEmbedControl(ControlRef inControl, WindowRef inWindow);

/**
 *  GetSuperControl()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr GetSuperControl(ControlRef inControl, ControlRef *outParent);

/**
 *  CountSubControls()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr CountSubControls(ControlRef inControl, UInt16 *outNumChildren);

/**
 *  GetIndexedSubControl()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr GetIndexedSubControl(ControlRef inControl, UInt16 inIndex,
                           ControlRef *outSubControl);

/**
 *  SetControlSupervisor()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr SetControlSupervisor(ControlRef inControl, ControlRef inBoss);

/*��������������������������������������������������������������������������������������*/
/*  � Keyboard Focus (available only with Appearance 1.0 and later) */
/*��������������������������������������������������������������������������������������*/
/**
 *  GetKeyboardFocus()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr GetKeyboardFocus(WindowRef inWindow, ControlRef *outControl);

/**
 *  SetKeyboardFocus()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr SetKeyboardFocus(WindowRef inWindow, ControlRef inControl,
                       ControlFocusPart inPart);

/**
 *  AdvanceKeyboardFocus()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr AdvanceKeyboardFocus(WindowRef inWindow);

/**
 *  ReverseKeyboardFocus()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr ReverseKeyboardFocus(WindowRef inWindow);

/**
 *  ClearKeyboardFocus()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr ClearKeyboardFocus(WindowRef inWindow);

/*��������������������������������������������������������������������������������������*/
/*  � Control Data (available only with Appearance 1.0 and later) */
/*��������������������������������������������������������������������������������������*/

/**
 *  GetControlFeatures()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr GetControlFeatures(ControlRef inControl, UInt32 *outFeatures);

/**
 *  SetControlData()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr SetControlData(ControlRef inControl, ControlPartCode inPart, ResType inTagName,
                     Size inSize, const void *inData);

/**
 *  GetControlData()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr GetControlData(ControlRef inControl, ControlPartCode inPart, ResType inTagName,
                     Size inBufferSize, void *inBuffer, Size *outActualSize);

/**
 *  GetControlDataSize()
 *

 *    \non_carbon_cfm   in AppearanceLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr GetControlDataSize(ControlRef inControl, ControlPartCode inPart,
                         ResType inTagName, Size *outMaxSize);

/*��������������������������������������������������������������������������������������*/
/*  � Control Drag & Drop */
/*      Carbon only. */
/*��������������������������������������������������������������������������������������*/
/* some simple redefinitions of the similar values found in the Drag header*/
enum
{
  kDragTrackingEnterControl = 2,
  kDragTrackingInControl = 3,
  kDragTrackingLeaveControl = 4
};

/**
 *  HandleControlDragTracking()
 *

 *    \non_carbon_cfm   in ControlsLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
HandleControlDragTracking(ControlRef inControl, DragTrackingMessage inMessage,
                          DragReference inDrag, Boolean *outLikesDrag);

/**
 *  HandleControlDragReceive()
 *

 *    \non_carbon_cfm   in ControlsLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
HandleControlDragReceive(ControlRef inControl, DragReference inDrag);

/**
 *  SetControlDragTrackingEnabled()
 *

 *    \non_carbon_cfm   in ControlsLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
SetControlDragTrackingEnabled(ControlRef theControl, Boolean tracks);

/**
 *  IsControlDragTrackingEnabled()
 *

 *    \non_carbon_cfm   in ControlsLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
IsControlDragTrackingEnabled(ControlRef theControl, Boolean *tracks);

/**
 *  SetAutomaticControlDragTrackingEnabledForWindow()
 *

 *    \non_carbon_cfm   in ControlsLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
SetAutomaticControlDragTrackingEnabledForWindow(WindowRef theWindow,
                                                Boolean tracks);

/**
 *  IsAutomaticControlDragTrackingEnabledForWindow()
 *

 *    \non_carbon_cfm   in ControlsLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
IsAutomaticControlDragTrackingEnabledForWindow(WindowRef theWindow,
                                               Boolean *tracks);

#if !TARGET_OS_MAC
/*��������������������������������������������������������������������������������������*/
/*  � QuickTime 3.0 Win32/unix notification mechanism */
/*��������������������������������������������������������������������������������������*/
/* Proc used to notify window that something happened to the control*/
typedef CALLBACK_API_C(void, ControlNotificationProcPtr)(
    WindowRef theWindow, ControlRef theControl,
    ControlNotification notification, long param1, long param2);
/**
   Proc used to prefilter events before handled by control.  A client of a
   control calls CTRLSetPreFilterProc() to have the control call this proc
   before handling the event. If the proc returns TRUE, the control can go ahead
   and handle the event.
*/
typedef CALLBACK_API_C(Boolean, PreFilterEventProc)(ControlRef theControl,
                                                    EventRecord *theEvent);
#if CALL_NOT_IN_CARBON
/**
 *  GetControlComponentInstance()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long GetControlComponentInstance(ControlRef theControl);

/**
 *  GetControlHandleFromCookie()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
ControlRef
GetControlHandleFromCookie(long cookie);

#define GetControlRefFromCookie GetControlHandleFromCookie
/**
 *  SetControlDefProc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetControlDefProc(short resID, ControlDefProcPtr proc);

#endif /* CALL_NOT_IN_CARBON */

typedef ControlNotificationProcPtr ControlNotificationUPP;
#endif /* !TARGET_OS_MAC */

/*��������������������������������������������������������������������������������������*/
/*  � C Glue */
/*��������������������������������������������������������������������������������������*/
#if CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON
/**
 *  dragcontrol()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void dragcontrol(ControlRef theControl, Point *startPt, const Rect *limitRect,
                 const Rect *slopRect, short axis);

/**
 *  newcontrol()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
ControlRef
newcontrol(WindowRef theWindow, const Rect *boundsRect, const char *title,
           Boolean visible, short value, short min, short max, short procID,
           long refCon);

/**
 *  findcontrol()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short findcontrol(Point *thePoint, WindowRef theWindow, ControlRef *theControl);

/**
 *  getcontroltitle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void getcontroltitle(ControlRef theControl, char *title);

/**
 *  setcontroltitle()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void setcontroltitle(ControlRef theControl, const char *title);

/**
 *  trackcontrol()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short trackcontrol(ControlRef theControl, Point *thePoint,
                   ControlActionUPP actionProc);

/**
 *  testcontrol()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short testcontrol(ControlRef theControl, Point *thePt);

#endif /* CALL_NOT_IN_CARBON */

#endif /* CALL_NOT_IN_CARBON */

#if OLDROUTINENAMES
/*��������������������������������������������������������������������������������������*/
/*  � OLDROUTINENAMES */
/*��������������������������������������������������������������������������������������*/
enum
{
  useWFont = kControlUsesOwningWindowsFontVariant
};

enum
{
  inThumb = kControlIndicatorPart,
  kNoHiliteControlPart = kControlNoPart,
  kInIndicatorControlPart = kControlIndicatorPart,
  kReservedControlPart = kControlDisabledPart,
  kControlInactiveControlPart = kControlInactivePart
};

#define SetCTitle(theControl, title) SetControlTitle(theControl, title)
#define GetCTitle(theControl, title) GetControlTitle(theControl, title)
#define UpdtControl(theWindow, updateRgn) UpdateControls(theWindow, updateRgn)
#define SetCtlValue(theControl, theValue) SetControlValue(theControl, theValue)
#define GetCtlValue(theControl) GetControlValue(theControl)
#define SetCtlMin(theControl, minValue) SetControlMinimum(theControl, minValue)
#define GetCtlMin(theControl) GetControlMinimum(theControl)
#define SetCtlMax(theControl, maxValue) SetControlMaximum(theControl, maxValue)
#define GetCtlMax(theControl) GetControlMaximum(theControl)
#define GetAuxCtl(theControl, acHndl) \
  GetAuxiliaryControlRecord(theControl, acHndl)
#define SetCRefCon(theControl, data) SetControlReference(theControl, data)
#define GetCRefCon(theControl) GetControlReference(theControl)
#define SetCtlAction(theControl, actionProc) \
  SetControlAction(theControl, actionProc)
#define GetCtlAction(theControl) GetControlAction(theControl)
#define SetCtlColor(theControl, newColorTable) \
  SetControlColor(theControl, newColorTable)
#define GetCVariant(theControl) GetControlVariant(theControl)
#define getctitle(theControl, title) getcontroltitle(theControl, title)
#define setctitle(theControl, title) setcontroltitle(theControl, title)
#endif /* OLDROUTINENAMES */

#if ACCESSOR_CALLS_ARE_FUNCTIONS
/* Getters */
/**
 *  GetControlBounds()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Rect *
GetControlBounds(ControlRef control, Rect *bounds);

/**
 *  IsControlHilited()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
IsControlHilited(ControlRef control);

/**
 *  GetControlHilite()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
UInt16
GetControlHilite(ControlRef control);

/**
 *  GetControlOwner()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
WindowRef
GetControlOwner(ControlRef control);

/**
 *  GetControlDataHandle()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Handle
GetControlDataHandle(ControlRef control);

/**
 *  GetControlPopupMenuHandle()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
MenuRef
GetControlPopupMenuHandle(ControlRef control);

#define GetControlPopupMenuRef GetControlPopupMenuHandle
/**
 *  GetControlPopupMenuID()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
short GetControlPopupMenuID(ControlRef control);

/* Setters */
/**
 *  SetControlDataHandle()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlDataHandle(ControlRef control, Handle dataHandle);

/**
 *  SetControlBounds()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlBounds(ControlRef control, const Rect *bounds);

/**
 *  SetControlPopupMenuHandle()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlPopupMenuHandle(ControlRef control, MenuRef popupMenu);

#define SetControlPopupMenuRef SetControlPopupMenuHandle
/**
 *  SetControlPopupMenuID()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlPopupMenuID(ControlRef control, short menuID);

#endif /* ACCESSOR_CALLS_ARE_FUNCTIONS */

#if !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS
#define GetControlListFromWindow(theWindow) \
  (*(ControlRef *)(((UInt8 *)theWindow) + sizeof(GrafPort) + 0x20))
#define GetControlOwningWindowControlList(theWindow) \
  (*(ControlRef *)(((UInt8 *)theWindow) + sizeof(GrafPort) + 0x20))
#endif /* !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS */

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

#endif /* __CONTROLS__ */
*/);

/**
 *  SetControlBounds()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlBounds(ControlRef control, const Rect *bounds);

/**
 *  SetControlPopupMenuHandle()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlPopupMenuHandle(ControlRef control, MenuRef popupMenu);

#define SetControlPopupMenuRef SetControlPopupMenuHandle
/**
 *  SetControlPopupMenuID()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetControlPopupMenuID(ControlRef control, short menuID);

#endif /* ACCESSOR_CALLS_ARE_FUNCTIONS */

#if !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS
#define GetControlListFromWindow(theWindow) \
  (*(ControlRef *)(((UInt8 *)theWindow) + sizeof(GrafPort) + 0x20))
#define GetControlOwningWindowControlList(theWindow) \
  (*(ControlRef *)(((UInt8 *)theWindow) + sizeof(GrafPort) + 0x20))
#endif /* !OPAQUE_TOOLBOX_STRUCTS && !ACCESSOR_CALLS_ARE_FUNCTIONS */

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

#endif /* __CONTROLS__ */
