/**
     \file       HyperXCmd.h

    \brief   Interfaces for HyperCard XCMD's

    \introduced_in  HyperCard 2.3
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1987-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Misc

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __HYPERXCMD__
#define __HYPERXCMD__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FP__
#include <fp.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __TEXTEDIT__
#include <TextEdit.h>
#endif

#ifndef __MENUS__
#include <Menus.h>
#endif

#ifndef __STANDARDFILE__
#include <StandardFile.h>
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

        // result codes         enum
        {
            xresSucc = 0,
            xresFail = 1,
            xresNotImp = 2};

        // XCMDBlock constants for event.what...         enum
        // XCMDBlock constants for event.what...
        xOpenEvt = 1000,  /** first */
event after you are created                 xCloseEvt  =  1001          /** window */
is being forced close (Quit?)                 xGiveUpEditEvt  =  1002     /** are */
losing Edit...                 xGiveUpSoundEvt  =  1003    /** are */
losing the sound channel...                 xHidePalettesEvt  =  1004   /** called */
HideHCPalettes                 xShowPalettesEvt  =  1005   /** called */
ShowHCPalettes                 xEditUndo  =  1100          
               xEditCut  =  1102           
               xEditCopy  =  1103          
               xEditPaste  =  1104         
               xEditClear  =  1105         
               xSendEvt  =  1200           /** has */
sent you a message (text)                 xSetPropEvt  =  1201        /** a */
window property                 xGetPropEvt  =  1202        /** a */
window property                 xCursorWithin  =  1300      /** is */
within the window                 xMenuEvt  =  1400           /** has */
selected an item in your menu                 xMBarClickedEvt  =  1401    /** menu */
is about to be shown--update if needed                 xShowWatchInfoEvt  =  1501  /** variable */
and message watchers                 xScriptErrorEvt  =  1502    /** the */
insertion point                 xDebugErrorEvt  =  1503     /** clicked */
"Debug" at a complaint                 xDebugStepEvt  =  1504      /** the */
line                 xDebugTraceEvt  =  1505    // same as step but tracing                 xDebugFinishedEvt = 1506  // script ended
};

enum                        // the first event after you are created
{                           // your window is being forced close (Quit?)
        paletteProc = 2048, // W// you are losing Edit...
                            // you are losing the sound channel...
        enum                // someone called HideHCPalettes
        {
            // someone called ShowHCPalettes
            hasZoom = 8,     // Edit©©Undo
            hasTallTBar = 2, // Edit©©Cut
            toggleHilite = 1 // Edit©©Copy
        };                   // Edit©©Paste
                             // Edit©©Clear
                             // paramCount is set to these cons// script has sent you a message (text)
        {
            // set a window property
            xMessageWatcherID = -2,  // get a window property
            xVariableWatcherID = -3, // cursor is within the window
            xScriptEditorID = -4,    // user has selected an item in your menu
            xDebuggerID = -5         // a menu is about to be shown--update if needed
        };                           // for variable and message watchers
                                     // place the insertion point
                                     // XTalkObjectPtr->objectKind valu// user clicked "Debug" at a complaint
        {                            // hilite the line
         stackObj = 1,               // same as step but tracing
         bkgndObj = 2,               // script ended
         cardObj = 3,
         fieldObj = 4,
         buttonObj = 5};
        // Windoid with grow box
        // selectors for ShowHCAlert's// standard Windoid defproc
        {                // Windoid with zoom and grow
         errorDlgID = 1, /// Windoid with zoom and no grow

         // type definitions         struct XCmdBlock
         {
             short paramCount; // If = -1 then new use for XWindoids                 Handle params[16];
             Handle returnValue;
             Boolean passFlag;
             SignedByte filler1;
             UniversalProcPtr entryPoint; // to call back to HyperCard                 short request;
             short result;
             // paramCount is set to these constants when first calling special XThings
             long outArgs[4];};
typedef struct XCmdBlock XCmdBlock;
typedef XCmdBlock *XCmdPtr;

struct XWEventInfo
{
        EventRecord event;
        // XTalkObjectPtr->objectKind values
        long eventParams[9];
        Handle eventResult;
};
typedef struct XWEventInfo XWEventInfo;
typedef XWEventInfo *XWEventInfoPtr;
struct XTalkObject
{
        short objectKind; // stack, bkgnd, card, field, or button                 long stackNum;    // reference number of the source stack                 long bkgndID;
        long cardID;
        // selectors for ShowHCAlert's dialogs (shown as buttonID:buttonText)
        long fieldID;
};
typedef struct XTalkObject XT     // 1:OK (default)
    typedef XTalkObject *XTalkObj // 1:OK (default) and 2:Cancel
    // maximum number of checkpoi// 1:Cancel (default) and 2:Delete
    {// 1:Yes (default), 2:Cancel, and 3:No
     maxCachedChecks = 16};
// type definitions
struct CheckPts
{
        short checks[16]; // If = -1 then new use for XWindoids
};
typedef struct CheckPts CheckPts;
typedef CheckPts *CheckPtPtr;
typedef CheckPtPtr *CheckPtHandle;
/**  to call back to HyperCard HyperTalk Utilities */
#if CALL_NOT_IN_CARBON
/**
 *  EvalExpr()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
EvalExpr(XCmdPtr paramPtr, ConstStr255Param expr);

/**
 *  SendCardMessage()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        n// stack, bkgnd, card, field, or button
 *    \mac_os_x         no// reference number of the source stack
 */
void SendCardMessage(XCmdPtr paramPtr, ConstStr255Param msg);

/**
 *  SendHCMessage()
 *
// maximum number of checkpoints in a script
 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SendHCMessage(XCmdPtr paramPtr, ConstStr255Param msg);

/**
 *  RunHandler()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void RunHandler(XCmdPtr paramPtr, Handle handler);

/**
        Memory Utilities
*/
/**
 *  GetGlobal()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
GetGlobal(XCmdPtr paramPtr, ConstStr255Param globName);

/**
 *  SetGlobal()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetGlobal(XCmdPtr paramPtr, ConstStr255Param globName, Handle globValue);

/**
 *  ZeroBytes()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void ZeroBytes(XCmdPtr paramPtr, void *dstPtr, long longCount);

/**
        String Utilities
*/
/**
 *  ScanToReturn()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void ScanToReturn(XCmdPtr paramPtr, Ptr *scanPtr);

/**
 *  ScanToZero()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void ScanToZero(XCmdPtr paramPtr, Ptr *scanPtr);

/**
 *  StringEqual()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
StringEqual(XCmdPtr paramPtr, ConstStr255Param str1, ConstStr255Param str2);

/**
 *  StringLength()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long StringLength(XCmdPtr paramPtr, void *strPtr);

/**
 *  StringMatch()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void *
StringMatch(XCmdPtr paramPtr, ConstStr255Param pattern, void *target);

/**
 *  ZeroTermHandle()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void ZeroTermHandle(XCmdPtr paramPtr, Handle hndl);

/**
        String Conversions
*/
/**
 *  BoolToStr()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void BoolToStr(XCmdPtr paramPtr, Boolean value, Str255 str);

/**
 *  Double_tToStr()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void Double_tToStr(XCmdPtr paramPtr, double_t num, Str255 str);

/**
 *  LongToStr()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void LongToStr(XCmdPtr paramPtr, long posNum, Str255 str);

/**
 *  NumToHex()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void NumToHex(XCmdPtr paramPtr, long num, short nDigits, Str255 str);

/**
 *  NumToStr()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void NumToStr(XCmdPtr paramPtr, long num, Str255 str);

/**
 *  PasToZero()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
PasToZero(XCmdPtr paramPtr, ConstStr255Param str);

/**
 *  PointToStr()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void PointToStr(XCmdPtr paramPtr, Point pt, Str255 str);

/**
 *  RectToStr()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void RectToStr(XCmdPtr paramPtr, const Rect *rct, Str255 str);

/**
 *  ReturnToPas()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void ReturnToPas(XCmdPtr paramPtr, void *zeroStr, Str255 pasStr);

/**
 *  StrToBool()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
StrToBool(XCmdPtr paramPtr, ConstStr255Param str);

/**
 *  StrToDouble_t()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
double_t
StrToDouble_t(XCmdPtr paramPtr, ConstStr255Param str);

/**
 *  StrToLong()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long StrToLong(XCmdPtr paramPtr, ConstStr255Param str);

/**
 *  StrToNum()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long StrToNum(XCmdPtr paramPtr, ConstStr255Param str);

/**
 *  StrToPoint()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void StrToPoint(XCmdPtr paramPtr, ConstStr255Param str, Point *pt);

/**
 *  StrToRect()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void StrToRect(XCmdPtr paramPtr, ConstStr255Param str, Rect *rct);

/**
 *  ZeroToPas()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void ZeroToPas(XCmdPtr paramPtr, void *zeroStr, Str255 pasStr);

/**
        Field Utilities
*/
/**
 *  GetFieldByID()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
GetFieldByID(XCmdPtr paramPtr, Boolean cardFieldFlag, short fieldID);

/**
 *  GetFieldByName()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
GetFieldByName(XCmdPtr paramPtr, Boolean cardFieldFlag,
               ConstStr255Param fieldName);

/**
 *  GetFieldByNum()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
GetFieldByNum(XCmdPtr paramPtr, Boolean cardFieldFlag, short fieldNum);

/**
 *  SetFieldByID()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetFieldByID(XCmdPtr paramPtr, Boolean cardFieldFlag, short fieldID,
                  Handle fieldVal);

/**
 *  SetFieldByName()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetFieldByName(XCmdPtr paramPtr, Boolean cardFieldFlag,
                    ConstStr255Param fieldName, Handle fieldVal);

/**
 *  SetFieldByNum()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetFieldByNum(XCmdPtr paramPtr, Boolean cardFieldFlag, short fieldNum,
                   Handle fieldVal);

/**
 *  GetFieldTE()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TEHandle
GetFieldTE(XCmdPtr paramPtr, Boolean cardFieldFlag, short fieldID,
           short fieldNum, ConstStr255Param fieldName);

/**
 *  SetFieldTE()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetFieldTE(XCmdPtr paramPtr, Boolean cardFieldFlag, short fieldID,
                short fieldNum, ConstStr255Param fieldName, TEHandle fieldTE);

/**
        Miscellaneous Utilities
*/
/**
 *  BeginXSound()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void BeginXSound(XCmdPtr paramPtr, WindowRef window);

/**
 *  EndXSound()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void EndXSound(XCmdPtr paramPtr);

/**
 *  GetFilePath()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GetFilePath(XCmdPtr paramPtr, ConstStr255Param fileName, short numTypes,
            ConstSFTypeListPtr typeList, Boolean askUser, OSType *fileType,
            Str255 fullName);

/**
 *  GetXResInfo()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void GetXResInfo(XCmdPtr paramPtr, short *resFile, short *resID, ResType *rType,
                 Str255 name);

/**
 *  Notify()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void Notify(XCmdPtr paramPtr);

/**
 *  SendHCEvent()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SendHCEvent(XCmdPtr paramPtr, const EventRecord *event);

/**
 *  SendWindowMessage()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SendWindowMessage(XCmdPtr paramPtr, WindowRef windPtr,
                       ConstStr255Param windowName, ConstStr255Param msg);

/**
 *  FrontDocWindow()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
WindowRef
FrontDocWindow(XCmdPtr paramPtr);

/**
 *  StackNameToNum()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long StackNameToNum(XCmdPtr paramPtr, ConstStr255Param stackName);

/**
 *  ShowHCAlert()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short ShowHCAlert(XCmdPtr paramPtr, short dlgID, ConstStr255Param promptStr);

/**
 *  AbortInQueue()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
AbortInQueue(XCmdPtr paramPtr);

/**
 *  FlushStackFile()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void FlushStackFile(XCmdPtr paramPtr);

/**
        Creating and Disposing XWindoids
*/
/**
 *  NewXWindow()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
WindowRef
NewXWindow(XCmdPtr paramPtr, const Rect *boundsRect, ConstStr255Param title,
           Boolean visible, short procID, Boolean color, Boolean floating);

/**
 *  GetNewXWindow()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
WindowRef
GetNewXWindow(XCmdPtr paramPtr, ResType templateType, short templateID,
              Boolean color, Boolean floating);

/**
 *  CloseXWindow()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void CloseXWindow(XCmdPtr paramPtr, WindowRef window);

/**
        XWindoid Utilities
*/
/**
 *  HideHCPalettes()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void HideHCPalettes(XCmdPtr paramPtr);

/**
 *  ShowHCPalettes()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void ShowHCPalettes(XCmdPtr paramPtr);

/**
 *  RegisterXWMenu()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void RegisterXWMenu(XCmdPtr paramPtr, WindowRef window, MenuRef menu,
                    Boolean registering);

/**
 *  SetXWIdleTime()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetXWIdleTime(XCmdPtr paramPtr, WindowRef window, long interval);

/**
 *  XWHasInterruptCode()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void XWHasInterruptCode(XCmdPtr paramPtr, WindowRef window, Boolean haveCode);

/**
 *  XWAlwaysMoveHigh()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void XWAlwaysMoveHigh(XCmdPtr paramPtr, WindowRef window, Boolean moveHigh);

/**
 *  XWAllowReEntrancy()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void XWAllowReEntrancy(XCmdPtr paramPtr, WindowRef window, Boolean allowSysEvts,
                       Boolean allowHCEvts);

/**
        Text Editing Utilities
*/
/**
 *  BeginXWEdit()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void BeginXWEdit(XCmdPtr paramPtr, WindowRef window);

/**
 *  EndXWEdit()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void EndXWEdit(XCmdPtr paramPtr, WindowRef window);

/**
 *  HCWordBreakProc()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
WordBreakUPP
HCWordBreakProc(XCmdPtr paramPtr);

/**
 *  PrintTEHandle()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void PrintTEHandle(XCmdPtr paramPtr, TEHandle hTE, StringPtr header);

/**
        Script Editor support
*/
/**
 *  GetCheckPoints()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CheckPtHandle
GetCheckPoints(XCmdPtr paramPtr);

/**
 *  SetCheckPoints()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetCheckPoints(XCmdPtr paramPtr, CheckPtHandle checkLines);

/**
 *  FormatScript()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void FormatScript(XCmdPtr paramPtr, Handle scriptHndl, long *insertionPoint,
                  Boolean quickFormat);

/**
 *  SaveXWScript()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SaveXWScript(XCmdPtr paramPtr, Handle scriptHndl);

/**
 *  GetObjectName()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void GetObjectName(XCmdPtr paramPtr, XTalkObjectPtr xObjPtr, Str255 objName);

/**
 *  GetObjectScript()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void GetObjectScript(XCmdPtr paramPtr, XTalkObjectPtr xObjPtr, Handle *scriptHndl);

/**
 *  SetObjectScript()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetObjectScript(XCmdPtr paramPtr, XTalkObjectPtr xObjPtr, Handle scriptHndl);

/**
        Debugging Tools support
*/
/**
 *  AbortScript()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void AbortScript(XCmdPtr paramPtr);

/**
 *  GoScript()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void GoScript(XCmdPtr paramPtr);

/**
 *  StepScript()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void StepScript(XCmdPtr paramPtr, Boolean stepInto);

/**
 *  CountHandlers()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void CountHandlers(XCmdPtr paramPtr, short *handlerCount);

/**
 *  GetHandlerInfo()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void GetHandlerInfo(XCmdPtr paramPtr, short handlerNum, Str255 handlerName,
                    Str255 objectName, short *varCount);

/**
 *  GetVarInfo()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void GetVarInfo(XCmdPtr paramPtr, short handlerNum, short varNum, Str255 varName,
                Boolean *isGlobal, Str255 varValue, Handle varHndl);

/**
 *  SetVarValue()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void SetVarValue(XCmdPtr paramPtr, short handlerNum, short varNum, Handle varHndl);

/**
 *  GetStackCrawl()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Handle
GetStackCrawl(XCmdPtr paramPtr);

/**
 *  TraceScript()
 *

 *    \non_carbon_cfm   in HyperXLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void TraceScript(XCmdPtr paramPtr, Boolean traceInto);

#endif // CALL_NOT_IN_CARBON
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

#endif // __HYPERXCMD__ // CALL_NOT_IN_CARBON
// __HYPERXCMD__
