/**
     \file       Lists.h

    \brief   List Manager Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Managers

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __LISTS__
#define __LISTS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __CONTROLS__
#include <Controls.h>
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

  typedef Point Cell;
  typedef Rect ListBounds;
  typedef char DataArray[32001];
  typedef char *DataPtr;
  typedef DataPtr *DataHandle;
  typedef CALLBACK_API(short, ListSearchProcPtr)(Ptr aPtr, Ptr bPtr, short aLen,
                                                 short bLen);
  typedef CALLBACK_API_REGISTER68K(Boolean, ListClickLoopProcPtr, (void));
  typedef STACK_UPP_TYPE(ListSearchProcPtr) ListSearchUPP;
  typedef REGISTER_UPP_TYPE(ListClickLoopProcPtr) ListClickLoopUPP;
#if !TARGET_OS_MAC
  /** QuickTime 3.0 */
  typedef long ListNotification;
  enum
  {
    listNotifyNothing = FOUR_CHAR_CODE('nada'), /** No (null) notification*/
    listNotifyClick = FOUR_CHAR_CODE('clik'),   /** Control was clicked*/
    listNotifyDoubleClick =
        FOUR_CHAR_CODE('dblc'),                 /** Control was double-clicked*/
    listNotifyPreClick = FOUR_CHAR_CODE('pclk') /** Control about to be clicked*/
  };

#endif /** !TARGET_OS_MAC */

  /**
  <pre>long
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct ListRec
  {
    Rect rView;            /**< Display rectangle, in local coords*/
    GrafPtr port;          /**< Where list resides (usually*/
    Point indent;          /**< Horiz and vert offset for text in each*/
    Point cellSize;        /**< Width and height of each cell*/
    Rect visible;          /**< Currently-visible cells, in cell coords*/
    ControlHandle vScroll; /**< Leads to ControlRecord  for vert scroll*/
    ControlHandle hScroll; /**< Leads to ControlRecord  for horiz scroll*/
    char selFlags;         /**< Mouse-selection options (see Notes)*/
    Boolean lActive;       /**< TRUE when list active ( LActivate )*/
    char lReserved;        /**< (reserved, internal flags)*/
    char listFlags;        /**< Auto scroll:*/
    long clikTime;         /**< Time of last click (ticks since*/
    Point clikLoc;         /**< Location of previous click, in local*/
    Point mouseLoc;        /**< Current mouse location, in local*/
    ProcPtr lClikLoop;     /**< Addr called while mouse is down*/
    Cell lastClick;        /**< Last cell clicked (cell*/
    long refCon;           /**< Available for application use*/
    Handle listDefProc;    /**< Leads to custom LDEF code*/
    Handle userHandle;     /**< Available for app or list definition*/
    Rect dataBounds;       /**< Bounds of data cells, in cell coords*/
    DataHandle cells;      /**< Leads to cell contents (see LFind for*/
    short maxIndex;        /**< (used internally)*/
    short cellArray[];     /**< nArray of offsets to the cell data*/
  } ListRec;               /**< +nn  is(dataBounds width*height*) bytes*/

  typedef struct ListRec ListRec;
  typedef ListRec *ListPtr;
  typedef ListPtr *ListHandle;
  /** ListRef is obsolete.  Use ListHandle. */
  typedef ListHandle ListRef;

  enum
  {
    /** ListRec.listFlags bits*/
    lDrawingModeOffBit = 3,
    lDoVAutoscrollBit = 1,
    lDoHAutoscrollBit = 0
  };

  enum
  {
    /** ListRec.listFlags masks*/
    lDrawingModeOff = 8,
    lDoVAutoscroll = 2,
    lDoHAutoscroll = 1
  };

  enum
  {
    /** ListRec.selFlags bits*/
    lOnlyOneBit = 7,
    lExtendDragBit = 6,
    lNoDisjointBit = 5,
    lNoExtendBit = 4,
    lNoRectBit = 3,
    lUseSenseBit = 2,
    lNoNilHiliteBit = 1
  };

  enum
  {
    /** ListRec.selFlags masks*/
    lOnlyOne = -128,
    lExtendDrag = 64,
    lNoDisjoint = 32,
    lNoExtend = 16,
    lNoRect = 8,
    lUseSense = 4,
    lNoNilHilite = 2
  };

  enum
  {
    /** LDEF messages*/
    lInitMsg = 0,
    lDrawMsg = 1,
    lHiliteMsg = 2,
    lCloseMsg = 3
  };

  /**
     StandardIconListCellDataRec is the cell data format for
     use with the standard icon list (kListDefStandardIconType).
  */
  struct StandardIconListCellDataRec
  {
    Handle iconHandle;
    short font;
    short face;
    short size;
    Str255 name;
  };
  typedef struct StandardIconListCellDataRec StandardIconListCellDataRec;
  typedef StandardIconListCellDataRec *StandardIconListCellDataPtr;

  typedef CALLBACK_API(void, ListDefProcPtr)(short lMessage, Boolean lSelect,
                                             Rect *lRect, Cell lCell,
                                             short lDataOffset, short lDataLen,
                                             ListHandle lHandle);
  typedef STACK_UPP_TYPE(ListDefProcPtr) ListDefUPP;
  /**
   *  NewListSearchUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ListSearchUPP
  NewListSearchUPP(ListSearchProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppListSearchProcInfo = 0x00002BE0
  }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 2_bytes, 2_bytes) */
#ifdef __cplusplus
  inline ListSearchUPP NewListSearchUPP(ListSearchProcPtr userRoutine)
  {
    return (ListSearchUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppListSearchProcInfo, GetCurrentArchitecture());
  }
#else
#define NewListSearchUPP(userRoutine)   \
  (ListSearchUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppListSearchProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewListClickLoopUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ListClickLoopUPP
  NewListClickLoopUPP(ListClickLoopProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppListClickLoopProcInfo = 0x00000012
  }; /** register 1_byte:D0 Func() */
#ifdef __cplusplus
  inline ListClickLoopUPP NewListClickLoopUPP(ListClickLoopProcPtr userRoutine)
  {
    return (ListClickLoopUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppListClickLoopProcInfo,
                                                  GetCurrentArchitecture());
  }
#else
#define NewListClickLoopUPP(userRoutine)                                     \
  (ListClickLoopUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppListClickLoopProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewListDefUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ListDefUPP
  NewListDefUPP(ListDefProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppListDefProcInfo = 0x000EBD80
  }; /** pascal no_return_value Func(2_bytes, 1_byte, 4_bytes, 4_bytes, 2_bytes,
        2_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ListDefUPP NewListDefUPP(ListDefProcPtr userRoutine)
  {
    return (ListDefUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppListDefProcInfo, GetCurrentArchitecture());
  }
#else
#define NewListDefUPP(userRoutine)   \
  (ListDefUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppListDefProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeListSearchUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeListSearchUPP(ListSearchUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeListSearchUPP(ListSearchUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeListSearchUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeListClickLoopUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeListClickLoopUPP(ListClickLoopUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeListClickLoopUPP(ListClickLoopUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeListClickLoopUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeListDefUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeListDefUPP(ListDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeListDefUPP(ListDefUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeListDefUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeListSearchUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  InvokeListSearchUPP(Ptr aPtr, Ptr bPtr, short aLen, short bLen,
                      ListSearchUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline short InvokeListSearchUPP(Ptr aPtr, Ptr bPtr, short aLen, short bLen,
                                   ListSearchUPP userUPP)
  {
    return (short)CALL_FOUR_PARAMETER_UPP(userUPP, uppListSearchProcInfo, aPtr,
                                          bPtr, aLen, bLen);
  }
#else
#define InvokeListSearchUPP(aPtr, bPtr, aLen, bLen, userUPP)               \
  (short)CALL_FOUR_PARAMETER_UPP((userUPP), uppListSearchProcInfo, (aPtr), \
                                 (bPtr), (aLen), (bLen))
#endif
#endif

/**
 *  InvokeListClickLoopUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InvokeListClickLoopUPP(__A0)
#endif
  Boolean
  InvokeListClickLoopUPP(ListClickLoopUPP userUPP) ONEWORDINLINE(0x4E90);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline Boolean InvokeListClickLoopUPP(ListClickLoopUPP userUPP)
  {
    return (Boolean)CALL_ZERO_PARAMETER_UPP(userUPP, uppListClickLoopProcInfo);
  }
#else
#define InvokeListClickLoopUPP(userUPP) \
  (Boolean) CALL_ZERO_PARAMETER_UPP((userUPP), uppListClickLoopProcInfo)
#endif
#endif

  /**
   *  InvokeListDefUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeListDefUPP(short lMessage, Boolean lSelect, Rect *lRect, Cell lCell,
                   short lDataOffset, short lDataLen, ListHandle lHandle,
                   ListDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeListDefUPP(short lMessage, Boolean lSelect, Rect *lRect,
                               Cell lCell, short lDataOffset, short lDataLen,
                               ListHandle lHandle, ListDefUPP userUPP)
  {
    CALL_SEVEN_PARAMETER_UPP(userUPP, uppListDefProcInfo, lMessage, lSelect,
                             lRect, lCell, lDataOffset, lDataLen, lHandle);
  }
#else
#define InvokeListDefUPP(lMessage, lSelect, lRect, lCell, lDataOffset, \
                         lDataLen, lHandle, userUPP)                   \
  CALL_SEVEN_PARAMETER_UPP((userUPP), uppListDefProcInfo, (lMessage),  \
                           (lSelect), (lRect), (lCell), (lDataOffset), \
                           (lDataLen), (lHandle))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewListSearchProc(userRoutine) NewListSearchUPP(userRoutine)
#define NewListClickLoopProc(userRoutine) NewListClickLoopUPP(userRoutine)
#define NewListDefProc(userRoutine) NewListDefUPP(userRoutine)
#define CallListSearchProc(userRoutine, aPtr, bPtr, aLen, bLen) \
  InvokeListSearchUPP(aPtr, bPtr, aLen, bLen, userRoutine)
#define CallListClickLoopProc(userRoutine) InvokeListClickLoopUPP(userRoutine)
#define CallListDefProc(userRoutine, lMessage, lSelect, lRect, lCell,      \
                        lDataOffset, lDataLen, lHandle)                    \
  InvokeListDefUPP(lMessage, lSelect, lRect, lCell, lDataOffset, lDataLen, \
                   lHandle, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  enum
  {
    kListDefProcPtr = 0,
    kListDefUserProcType = kListDefProcPtr,
    kListDefStandardTextType = 1,
    kListDefStandardIconType = 2
  };

  typedef UInt32 ListDefType;
  struct ListDefSpec
  {
    ListDefType defType;
    union
    {
      ListDefUPP userProc;
    } u;
  };
  typedef struct ListDefSpec ListDefSpec;
  typedef ListDefSpec *ListDefSpecPtr;
  /**
   *  CreateCustomList()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  CreateCustomList(const Rect *rView, const ListBounds *dataBounds,
                   Point cellSize, const ListDefSpec *theSpec,
                   WindowRef theWindow, Boolean drawIt, Boolean hasGrow,
                   Boolean scrollHoriz, Boolean scrollVert, ListHandle *outList);

#if !TARGET_OS_MAC
  /** QuickTime 3.0 */
  typedef CALLBACK_API(void,
                       ListNotificationProcPtr)(ListHandle theList,
                                                ListNotification notification,
                                                long param);
  typedef ListNotificationProcPtr ListNotificationUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  LSetNotificationCallback()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  LSetNotificationCallback(ListNotificationProcPtr callBack, ListHandle lHandle);

  /**
   *  GetListVisibleBounds()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  GetListVisibleBounds(ListHandle theList, Rect *visibleBounds);

#endif /** CALL_NOT_IN_CARBON */

#endif /** !TARGET_OS_MAC */

  /**
   *  LNew()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ListHandle
  LNew(const Rect *rView, const ListBounds *dataBounds, Point cSize,
       short theProc, WindowRef theWindow, Boolean drawIt, Boolean hasGrow,
       Boolean scrollHoriz, Boolean scrollVert)
      THREEWORDINLINE(0x3F3C, 0x0044, 0xA9E7);

  /**
  \brief Discard a list and release all its memory

  <pre>LDispose frees up all memory associated with a list. Use it only after you no
longer need the list.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
* \returns <pre> none
</pre>
* \note <pre>LDispose frees up the list data (the handle in ListRec.cells), the memory
associated with the scroll bar controls (if any) and the memory containing
the ListRec itself (including the variable-length portion - the array of
offsets to the data).
If you have allocated additional data and stored the handle in
ListRec.userHandle or ListRec.refCon, it is your responsibility to dispose
of this memory before calling LDispose .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  LDispose(ListHandle lHandle) THREEWORDINLINE(0x3F3C, 0x0028, 0xA9E7);

  /**
  \brief Insert column(s) of empty cells into a list
  \param    count how many columns to insert
  <pre>LAddColumn inserts one or more columns of empty cells into a list. If
drawing is on, the list display and the horizontal scroll bar (if any) are
updated.
countspecifies the number of columns to insert.
clmNum specifies where to start inserting columns. Columns are inserted
before this column. For instance, if clmNum=3 and count=1,
columns 3... n are renumbered as columns 4... n+1. Thus, the cell
that used to be called (3,0) is now called (4,0), and so forth.
If clmNum > ListRec.dataBounds.right (i.e., greater than the
current width), then exactly count columns are added to the
rightmost side of the list. The column where they were actually added
is returned.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
* \returns <pre>a short; the column number of the first column inserted. When
inserting within the array bounds, this simply returns clmNum.
But, if you attempt to insert beyond the current bounds, the return
value is the current horizontal size of the list (i.e.,
ListRec.dataBounds.right).
</pre>
* \note <pre>LAddColumn increases the size of the ListRec structure by ( count *
ListRec.dataBounds.bottom) * 2 bytes. ListRec.dataBounds.right is
increased by count.
For instance, after:
LAddColumn( 1,1, theList ); /* insert 1 column at column 1 */
  The list shown in the LNew example changes to look like : </ pre>
                                                                * \copyright THINK Reference © 1991 -
                                                            1992 Symantec Corporation
                                                                *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
          *    \carbon_lib in CarbonLib 1.0 and
      later
          *    \mac_os_x in version 10.0 and
      later
              * /
          short
          LAddColumn(short count, short colNum, ListHandle lHandle)
              THREEWORDINLINE(0x3F3C, 0x0004, 0xA9E7);

  /**
  \brief Insert row(s) of empty cells into a list
  \param    count how many rows to insert
  <pre>LAddRow inserts one or more rows of empty cells into a list. If drawing is
on, the list display and the vertical scroll bar (if any) are updated.
countis the desired number of rows to insert.
rowNum specifies where to start inserting rows. Rows are inserted before
this row. For instance, if rowNum=3 and count=1, then rows 3... n
are renumbered as rows 4... n+1. Thus, the cell that used to be called
(0,3) is now called (0,4), and so forth.
If rowNum > ListRec.dataBounds.bottom (i.e., greater than the
current height), exactly count rows are added to the bottom of the
list. The row where they were actually added is returned.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
* \returns <pre>a short; the row number of the first new row inserted. When
inserting within the array bounds, this simply returns rowNum.
But, if you attempt to insert beyond the current bounds, the return
value is the current vertical size of the list (i.e.,
ListRec.dataBounds.bottom).
</pre>
* \note <pre>LAddRow increases the size of the ListRec structure by ( count *
ListRec.dataBounds.right) * 2 bytes. ListRec.dataBounds.bottom is
increased by count.
For instance, after:
LAddRow( 3,2, theList ); /* insert 3 rows at row 2 */
  The list shown in the LNew example would look like : </ pre>
                                                           * \copyright THINK Reference © 1991 -
                                                       1992 Symantec Corporation
                                                           *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
          *    \carbon_lib in CarbonLib 1.0 and
      later
          *    \mac_os_x in version 10.0 and
      later
              * /
          short
          LAddRow(short count, short rowNum, ListHandle lHandle)
              THREEWORDINLINE(0x3F3C, 0x0008, 0xA9E7);

  /**
  \brief Delete column(s) of cells from a list

  <pre>LDelColumn deletes one or more columns of cells from a list. If drawing is
on, the list display and the horizontal scroll bar (if any) are updated.
countis the desired number of columns to delete. If count=0, all cell are
deleted and ListRec.dataBounds.right is set to dataBounds.left.
clmNum specifies where to start deleting rows. For instance, if clmNum=3
and count=1, columns 4... n are renumbered as 3... n-1. Thus, the
cell that used to be called (4,0) is now called (3,0), and so forth.
If clmNum > ListRec.dataBounds.right (i.e., beyond the list's
width), then nothing happens.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
* \returns <pre>none
</pre>
* \note <pre>LDelColumn decreases the size of the ListRec structure by ( count *
ListRec.dataBounds.bottom) * 2 bytes. ListRec.dataBounds.right is
decreased by count.
For instance, after:
LDelColumn ( 1,1, theList ); /* delete column 1 */
  the list shown in the LNew example might look like : It is a lot faster to delete multiple columns in one call than to delete one at
                                                           a time.Use
                                                           LDispose(or set count to 0) to delete them all.</ pre>
                                                               * \copyright THINK Reference © 1991 -
          1992 Symantec Corporation
              *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
          *    \carbon_lib in CarbonLib 1.0 and
      later
          *    \mac_os_x in version 10.0 and
      later
              * /
          void LDelColumn(short count, short colNum, ListHandle lHandle)
              THREEWORDINLINE(0x3F3C, 0x0020, 0xA9E7);

  /**
  \brief Delete rows(s) of cells from a list

  <pre>LDelRow deletes one or more rows of cells from a list. If drawing is on, the
list display and the horizontal scroll bar (if any) are updated.
countis the desired number of rows to delete. If count=0, all cells are
deleted and ListRec.dataBounds.bottom is set to dataBounds.top.
rowNum specifies where to start deleting rows. For instance, if rowNum=3
and count=1, columns 4... n are renumbered as columns 3... n-1.
Thus, the cell that used to be called (0,4) is now called (0,3), and so
forth.
If rowNum > ListRec.dataBounds.bottom, then nothing happens.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
* \returns <pre>none
</pre>
* \note <pre>LDelRow decreases the size of the ListRec structure by ( count *
ListRec.dataBounds.right) * 2 bytes. ListRec.dataBounds.bottom is
decreased by count.
For instance, after:
LDelRow ( 4,3, theList ); /* delete 4 rows, starting at row 3 */
  The list shown in the LNew example might look like : It is a lot faster to delete multiple rows with one call than than to delete one at a time.Use LDispose(or set count to 0) to delete them all.</ pre>
                                                           * \copyright THINK Reference © 1991 -
          1992 Symantec Corporation
              *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
          *    \carbon_lib in CarbonLib 1.0 and
      later
          *    \mac_os_x in version 10.0 and
      later
              * /
          void LDelRow(short count, short rowNum, ListHandle lHandle)
              THREEWORDINLINE(0x3F3C, 0x0024, 0xA9E7);

  /**
  \brief Query if a cell is selected; get next selected cell

  <pre>LGetSelect performs two different operations. It can query to see if a
specific cell is currently selected OR it can check cells until it finds one that
is selected.
advanceIt is a Boolean specifying which operation to perform. It is one of:
FALSESee if theCell is currently selected and return TRUE if it is. If
it is not selected, return FALSE.
TRUESee if theCell is selected and return TRUE if it is; otherwise,
advance to the next cell on the row and check it. Keep advancing
across the row and on to subsequent rows until a selected cell is
found or the end of the list is reached. If a selected cell is
found, return TRUE and store its coordinates in theCell.
theCellis the address of a 32-bit Cell (a.k.a. Point). On entry it specifies
the first (or only) cell to check. Upon return, it receives the
coordinates of the selected cell (if the return value is TRUE).
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
* \returns <pre>a Boolean identifying whether theCell is selected (if
advance=FALSE) OR whether the search for a selected cell
succeeded. It is one of:
FALSEtheCell is NOT currently selected OR none of the cells to the
right of (or in rows below) theCell is currently selected.
TRUEtheCell IS currently selected OR another selected cell was
found by scanning the list (its coordinates have been stored in
theCell ).
</pre>
* \note <pre>LGetSelect is designed for locating selected (highlighted) cells in a list.
You might use it after LLastClick to verify that a certain cell is currently
selected, but it is most often used to search for selected cells.
If advanceIt  is TRUE, the search starts at theCell and proceeds from left to
right and if no selection is found in a row, the search continues on to
subsequent rows, as described under LNextCell ( TRUE,TRUE,...).
Note that in searching for all selections in a list, you will need to advance
theCell after a selection is found.  For example:
CelltheCell;
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  LGetSelect(Boolean next, Cell *theCell, ListHandle lHandle)
      THREEWORDINLINE(0x3F3C, 0x003C, 0xA9E7);

  /**
  \brief Query which cell was clicked last

  <pre>Use LLastClick after calling LClick. It returns the list coordinates of the
cell most recently clicked.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
* \returns <pre>either a 32-bit long integer, or a Cell, depending on your
programming environment. The low word is the horizontal index and
the high word is the vertical index of the most recently clicked cell.
</pre>
* \note <pre>LLastClick returns the same value as that stored in the lastClick field of
the ListRec.
Note that this does NOT necessarily identify the last cell selected or a cell
in which a double-click occurred. It is simply the last cell in which a
mouseDown occurred. However, if called directly after a call to LClick
that returns TRUE, it does return the cell that was double clicked.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Cell
  LLastClick(ListHandle lHandle) THREEWORDINLINE(0x3F3C, 0x0040, 0xA9E7);

  /**
  \brief Query which cell is next in a list
  \param    hNext look horizontally (toward the right)?
\param    vNext look vertically (toward the bottom)?
  <pre>LNextCell advances from one cell position to the next. You can advance
horizontally only (across a row), vertically only (down a column), or both
(horizontally until at the end of a row and wrapping from row to row).
hNextand . . .
vNextAre Booleans that identify how to look for the next cell. There are
three meaningful combinations:
hNext=TRUE(vNext=FALSE) Advance horizontally to the right. If beyond
the end of the row, return FALSE.
vNext=TRUE(hNext=FALSE) Advance vertically toward the bottom. If
beyond the bottom of the list, return FALSE.
Both TRUEAdvance horizontally to the right. If beyond the last column,
advance to first cell in the the next lower row. If beyond the
bottom of the list, return FALSE.
theCellis the address of a 32-bit Cell (a.k.a. Point). On entry, it specifies
where to start looking. Upon return, it contains the cell coordinates
of the next cell, according to the criteria set forth in hNext and
vNext. If the return value is FALSE, the value of theCell is
undefined upon exit.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
* \returns <pre>a Boolean identifying whether a valid 'next' cell was obtained. It is
one of:
FALSENo more cells - either at the end of a row, column, or list. The
value of theCell is now undefined.
TRUEA valid 'next' cell was found, its coordinates are in theCell.
</pre>
* \note <pre>You can use LNextCell in place of a set of nested loops. For instance, you
could use it to loop through and deselect all cells (a function NOT provided
by the List Manager). Another example: given a mouse location in local
coordinates, you could determine which cell was currently pointed to via:
Cell theCell;
Rect cellRect;
Point mousePt;
Boolean found;
found = FALSE; theCell. h=theCell. v=0; /* start at top left */
  </ pre>
              * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                        *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
          *    \carbon_lib in CarbonLib 1.0 and
      later
          *    \mac_os_x in version 10.0 and
      later
              * /
          Boolean
          LNextCell(Boolean hNext, Boolean vNext, Cell *theCell, ListHandle lHandle)
              THREEWORDINLINE(0x3F3C, 0x0048, 0xA9E7);

  /**
  \brief Search cells for a match with specific data
  \param    dataPtr address of data to match
  <pre>LSearch examines the contents of cells in a list, attempting to find a cell
containing specified data.
dataPtris the address of some data to match. Unless you have written a
custom 'LDEF', this is the address of some text.
dataLenis the length of the data to match.
compProc is the address of a pascal-style callback function that will be called
repeatedly to compare the contents of each cell with the data at
dataPtr. Use 0 to specify the default comparison function, which is
IUMagIDString .
theCellis the address of a 4-byte Cell (a.k.a. Point). On entry, it specifies
the first list element to compare. Upon return, it identifies the cell
in which a match was found (if the returned value is TRUE).
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
* \returns <pre>a Boolean. It is one of:
FALSEMatch not found.
TRUEA match was found.
</pre>
* \note <pre>The list is searched in row-major order, starting at theCell and advancing
left-to-right and top-to-bottom as with LNextCell (TRUE,TRUE,...).
You can use LSearch as a lookup routine to locate a cell if you happen to
know its contents. In this respect, the List Manager can be used in simple
database operations. A more common use is to call LSearch followed by
LSetSelect and LAutoScroll in order to pre-select a default (e.g.,
highlight the current font in a font-selection list).
SetPt( &theCell, 0,0 ); /* search from top of list */
if ( LSearch ( "Geneva", 6, NIL, &theCell, theList ) {
    LSetSelect(TRUE, theCell, theList);
    LAutoScroll(theList);
}
Callback Comparison Function
By default, LSearch uses IUMagIDString as the comparison function (a
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
LSearch(const void *dataPtr, short dataLen, ListSearchUPP searchProc,
        Cell *theCell, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x0054, 0xA9E7);


			/** 
			\brief Change the size of a list's viewing area 
			
			<pre>LSize changes the size of the viewing rectangle of a list. It is normally called
after using SizeWindow when the user grows or shrinks the list's window.
LSize is needed on lists that have a grow box in the bottom right corner.
listWidth and . . .
listHeight specify the desired new size, in pixels, for the list display area. As
with the rView parameter used in LNew, these values do NOT include
room for the scroll bars (if any), so the enclosing window should be
at least 15 pixels wider and/or higher.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>If drawing is on, the list contents are redrawn clipped to the new size. The
scroll bars are redrawn, reflecting any change to the thumb position.
As with SizeWindow , LSize leaves the top left corner of the viewing
rectangle in place (relative to the list's window). It changes the ListRec.
rView rectangle, invalidates the changed portion of that area, and forces an
update event.
The following code might be used when GetNextEvent returns a
mouseDown in the content region of a window:
longresult;
result = GrowWindow ( listWindow,mousePt, &boundsRect );
SizeWindow ( listWindow, LoWord (result), HiWord (result), TRUE );
LSize( LoWord (result)-15, HiWord (result)-15, theList );
DrawGrowIcon ( listWindow );
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LSize(short listWidth, short listHeight, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x0060, 0xA9E7);

/**
 *  LSetDrawingMode()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LSetDrawingMode(Boolean drawIt, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x002C, 0xA9E7);


			/** 
			\brief Scroll list by specific number of rows and columns 
			
			<pre>LScroll scrolls (repositions) the list within its viewing area by a specified
number of rows and columns. The scroll bars (if any) are updated. If drawing
is on, the list is redisplayed immediately.
deltaClms is the horizontal distance to scroll the list, in columns. Values
greater than 0 scroll the list toward the right (causing information
to move toward the left), and values less than 0 cause the list to
scroll left.
deltaRows is the vertical distance to scroll the list, in rows. Values greater
than 0 scroll the list down (causing information to move upward),
and values less than 0 cause the list to scroll up.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>LScroll does not really "scroll" the data; it jumps it in the specified
direction(s). It's an efficient operation since it appears to use the
Quickdraw ScrollRect function to move the bulk of the image (invalidating
the vacated area and redrawing only the cells that were previously hidden
from view).
Over-large values for deltaClms  and deltaRows  are pinned to the data
bounds; e.g., scrolling above row 0 will stop at row 0 (if
ListRec.dataBounds.top is 0).
One case where you might use LScroll is to take action on a press of the
PageUp or PageDown keys.  Another case is when you want a particular cell
to be positioned at the top of the list (e.g., a default selection). For
instance:
SetPt( &theCell, 0,0 ); /* search from top of list */
LSearch ( "Geneva", 6, nil, &theCell, theList );  /* where's Geneva? */
LDoDraw (FALSE, theList ); /* temporarily off */
LScroll ( -1000,-1000, theList ); /* go to a reference point */
LDoDraw (TRUE, theList ); /* back on */
LScroll ( theCell. h,theCell.v, theList ); /* put Geneva on top */
LSetSelect ( TRUE, theCell, theList ); /* pre-select it */
Note that LScroll uses relative positioning. The example first scrolls to
the top of the list by scrolling up and left by 1000. The scroll will actually
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LScroll(short dCols, short dRows, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x0050, 0xA9E7);


			/** 
			\brief Scroll list to display the first selected cell 
			
			<pre>LAutoScroll scrolls the list to position the first selected (highlighted) cell
inside the visible area. The scroll bars (if any) are updated. If drawing is on,
the list is redrawn with the selected cell somewhere in the visible area.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>If more than one cell is currently selected, LAutoScroll locates the first
of the selections. It starts searching at the top of the list and scans
left-to-right and top-to-bottom, as with LNextCell .
If the cell is off the screen, it will usually be positioned in the top,
leftmost visible column. If even a small part of the cell is already visible,
LAutoScroll does nothing.
The LScroll function scrolls the list by a specific distance. You may need
to use it if you allow more than one cell to be selected at a time.
See LSetSelect for an example of usage.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LAutoScroll(ListHandle lHandle) THREEWORDINLINE(0x3F3C, 0x0010, 0xA9E7);


			/** 
			\brief Redraw list; handle update events 
			
			<pre>Call LUpdate in response to an update event for the list's window. It redraws
the cells that intersect a specified region (usually the window's visRgn) and
updates the scroll bars if needed. If drawing is off, this does not affect the
list's visible area.
theRgnis a handle leading to a variable-length Region structure. It
identifies the portion of the list you wish to update. Normal usage is
to pass the window's entire visible region, e.g.:
LUpdate ( (*theList)->port->visRgn, theList );
You can specify a smaller region (e.g., the rectangle of one or two
cells) if you don't want to update everything (see LRect and
RectRgn ).
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>When an update event occurs for the window that encloses a list, call
LUpdate to force the List Manager to redraw the parts of the list that need
updating. For instance:
WindowPtr listWindow; /* assumed to be created */
if(WaitNextEvent (everyEvent , &theEvent, 0, nil)) {/* in event loop */
    if (theEvent.what == updateEvt)
    {
      if (theEvent.message == (long)listWindow)
      {
        BeginUpdate(listWindow);
        LUpdate(listWindow->visRgn, theList);
        DrawGrowIcon(listWindow); /* if needed */
        EndUpdate(listWindow)
      }
    }
}
Update events are generated when you call InvalRect for a portion of the
list window or when another window gets moved, uncovering all or a
portion of the list. See GetNextEvent and BeginUpdate for related
information.
Hint: You may find it advantageous to store the ListHandle (theList ) into
its window's WindowRecord .refCon field; that way, you can use
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LUpdate(RgnHandle theRgn, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x0064, 0xA9E7);


			/** 
			\brief Activate or deactivate a list (after activate event) 
			
			<pre>Call LActivate in response to an activate event for a list's enclosing window.
It highlights or unhighlights any cells that are currently selected and shows or
hides the scroll bars (if any).
activateIt specifies whether to activate or deactivate the list. It is one of:
FALSEDeactivate the list.
TRUEActivate the list.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>The List Manager does NOT take care of the size box (grow icon) of lists
that can be sized, so you must draw or erase it yourself. Here's a fragment
of a main event loop that maintains a growable list:
WindowPtr listWindow; // assume this already exists
EventRecord theEvent;
ListHandle theList;
// in event loop
if(WaitNextEvent (everyEvent , &theEvent, 0, nil)) {
if ( theEvent. what == activateEvt ) {
if ( theEvent. message == (long)listWindow ) {
if ( theEvent. modifiers & activeFlag )
// it's an activate request
LActivate ( TRUE, theList );// U get bonus for ternary op
else
LActivate ( FALSE, theList ); // it's a deactivate request
DrawGrowIcon ( listWindow ); // do this in either case
}
}
}
You may not need or want to deactivate a list displayed in a modeless dialog
box.  Calling LActivate (FALSE,...) causes the scroll bars to go away
entirely.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LActivate(Boolean act, ListHandle lHandle) TWOWORDINLINE(0x4267, 0xA9E7);


			/** 
			\brief Set size for cell display rectangles 
			
			<pre>LCellSize changes the height and width of the rectangle that defines the size
of all cells in a list. If drawing is on, the display is updated to reflect the new
cell size.
cellSize is a 32-bit Point; it specifies the desired height and width to be used
in laying out the cell matrix and drawing the cell data. Think of it as
the bottomRight of a rectangle whose topLeft is at (0,0).
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre> none
</pre>
 * \note <pre>LCellSize simply changes the ListRec.cellSize field. You will normally
specify the desired size when you create the list via LNew.
This function doesn't update other fields of the ListRec (e.g., the indent
field), and does not make intelligent decisions about what part of the screen
to clear. Therefore, it works best when no cells have been drawn (i.e.,
drawIt was FALSE in the call to LNew).
Note: LCellSize does NOT automatically calculate the size from the font
(as does LNew). Do NOT use a cellSize of (0,0).
The following sequence changes the cell size and ensures proper updating of
the screen:
cellSz.h=30; cellSz. v=20; /* for example */
LCellSize ( cellSz, theList ); /* change the size */
FillRect ( &listWindow-> portRect , white );/* clear the window */
InvalRect ( &listWindow-> portRect ); /* indicate redraw all */
LUpdate ( listWindow->visRgn, theList ); /*force update (in evt loop)*/
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LCellSize(Point cSize, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x0014, 0xA9E7);


			/** 
			\brief Process mouse-down for list dragging and selection 
			
			<pre>LClick handles all mouse tracking and clicking for a list. Call it from your
event loop when a mousedown occurs inside the list viewing area of a window.
By default, LClick keeps control until the button is released, but you can
write a custom click loop routine to monitor the action.
localPtis a Point, expressed local coordinates local to a list window.
Normally, it is the where field of an EventRecord when a mouseDown
occurs in the display area of theList. Use GlobalToLocal to convert
from global coordinates of the EventRecord to the local coordinates
needed here.
modifiers is the state of the modifier keys (such as , Shift, and Option) at
the time of the click. Use the value obtained in the modifiers field of
the EventRecord .
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre>a Boolean; it identifies whether or not a double-click occurred. It
is one of:
FALSENo double-click.
TRUEDouble-click. The previous click occurred in the same cell
within a short time span (see GetDblTime ).
</pre>
 * \note <pre>LClick is at the heart of List Manager handling. After drawing the list,
your application will simply idle in your main event loop (see
GetNextEvent ). When a mouseDown occurs in the content region of a list
window(see FindWindow ), call LClick to process the action.
If the click is outside of the list's viewing area and scroll bars, LClick
returns immediately. Otherwise, it retains control, handling all screen
updating and mouse tracking, including maintenance of the scroll bars. If
the user attempts to drag outside the visible area, it automatically scrolls
the list contents.
LClick performs cell selection according to the criteria established by the
bits of ListRec.selFlags. This important field lets you specify how to handle
shift- and - clicks and drags, and lets you limit selection to one cell at a
time. See ListRec for details.
Here's a skeletal example:
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
LClick(Point pt, EventModifiers modifiers, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x0018, 0xA9E7);


			/** 
			\brief Append data to a cell 
			\param    dataPtr address of data to append
	\param    theCell the cell to which data are appended
			<pre>LAddToCell appends data to the contents of a specified cell in a list.
dataPtris the address of some data you wish to append. Unless you have
written a custom 'LDEF', this should point to some ASCII text.
dataLenis a positive short integer; the size, in bytes, of the data you wish to
append (typically the length of a string of text).
theCellis a Cell (a.k.a. a Point); it identifies the cell to which you wish to
append data.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre> none
</pre>
 * \note <pre>The cell is redisplayed immediately, unless it is outside of the viewing
rectangle or drawing is off (see LDoDraw ).
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LAddToCell(const void *dataPtr, short dataLen, Cell theCell, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x000C, 0xA9E7);


			/** 
			\brief Delete the contents of a cell 
			\param    theCell the cell to erase
			<pre>LClrCell removes all data from a cell, by setting its length to 0.
theCellis a Cell (a.k.a. Point); it identifies the cell you wish to clear.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre> none
</pre>
 * \note <pre>The cell's display area is cleared immediately, unless drawing is off (see
LDoDraw ).
The cell's length is set to 0 and the actual storage area is not recovered
until the 32K list-data maximum is reached (triggering garbage
collection).
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LClrCell(Cell theCell, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x001C, 0xA9E7);


			/** 
			\brief Obtain a copy of a cell's data 
			\param    dataPtr address of buffer to receive the data
	\param    theCell the cell to query
			<pre>LGetCell copies the current contents of a specified cell into the caller's
buffer.
dataPtris the address of a buffer (the buffer should be at least dataLen
bytes long). Upon return, the buffer contains the data from the cell
(normally text).
dataLenis the address of a short integer. On entry, it must contain the size,
in bytes, of the buffer at dataPtr. Upon return, it contains the actual
length of the data transferred.
theCellidentifies the cell whose data you wish to examine.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre> none
</pre>
 * \note <pre>LGetCell copies cell contents into a local variable. You may be able to
realize better performance with the LFind function. Use LFind to
calculate the address of a cell's data and read (or compare, or display, etc.)
the contents directly from the list storage area; thereby avoiding a data
transfer.
See LNew for an example usage of LGetCell .
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LGetCell(void *dataPtr, short *dataLen, Cell theCell, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x0038, 0xA9E7);


			/** 
			\brief Obtain location of a cell's display rectangle 
			\param    theCell cell to query
			<pre>LRect obtains the local coordinates of the rectangle that encloses a specified
cell.
cellRect is the address of an 8-byte Rect structure. Upon return, it contains
the coordinates of the corners of the rectangle that encloses cell
theCell. If theCell is invalid, this will contain the empty rectangle
(0,0)(0,0).
theCellis a Cell (a.k.a. Point) identifying the cell of interest.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>LRect can be used in a "click loop" routine to help match a mouse point
with a cell (see LClick and LNextCell ).
You can force a single cell to be redrawn by invalidating its rectangle and
then calling LUpdate ; e.g.:
RectcellRect;
LRect( &cellRect, theCell, theList );
InvalRect ( &cellRect );
LUpdate ( (*theList)->port-> visRgn , theList );
cellRect is expressed in the coordinate system of the list's window; the
window identified by ListRec.port. If theCell is invalid (outside of
ListRec.dataBounds), cellRect gets set to the empty rectangle (0,0)(0,0).
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LRect(Rect *cellRect, Cell theCell, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x004C, 0xA9E7);


			/** 
			\brief Store data into a cell 
			\param    dataPtr address of data to be placed in the cell
	\param    theCell the cell that will receive the new data
			<pre>LSetCell stores data into a cell and, if drawing is on and the cell is currently
visible, displays the new contents.
dataPtris the address of the start of the data you wish to store into the cell.
Unless you have written a custom 'LDEF', this is typically ASCII text.
dataLenis a positive integer; the size, in bytes, of the data to be stored.
theCellis a Cell (a.k.a. Point); it identifies the cell whose data you wish to
initialize or replace.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre> none
</pre>
 * \note <pre>LSetCell replaces the current contents of a cell with the data at dataPtr.
To append data to an existing cell, use LAddToCell . Use LClrCell to clear
the contents of the cell.
Lists may contain no more that 32K of data (the total of the lengths of all
cells). Use LFind to learn the current size of a cell's data.
See LNew for an example usage of LSetCell .
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LSetCell(const void *dataPtr, short dataLen, Cell theCell, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x0058, 0xA9E7);


			/** 
			\brief Select or deselect a cell 
			\param    theCell the cell to select/deselect
			<pre>LSetSelect selects or deselects a specified cell in a list. If drawing is on, the
cell is redrawn (if necessary) to reflect its changed condition.
setItis a Boolean that specifies one of:
FALSEDeselect theCell (and unhighlight it)
TRUESelect theCell (and highlight it)
theCellis a Cell (a.k.a. Point) that identifies the cell to select or deselect.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre> none
</pre>
 * \note <pre>LSetSelect lets you select or deselect a cell (altering its highlighting)
programmatically, without the user clicking the mouse. Before presenting
a list, you may want to pre-select the top item, so the user has some sort of
default.
This function is also helpful in handling character-based list searching as
implemented in Standard File (for example, when you press the G key,
Standard File scrolls to and highlights the first filename starting with "G").
Note: Even if you have set ListRec.selFlags to lOnlyOne (to permit only
one selection at a time), LSetSelect will NOT automatically deselect
before selecting another. You must deselect manually.
After selecting a cell, you can use LAutoScroll to bring the cell into the
viewing area.
chartheChar; /* a keyboard character */
CelltheCell;
pascal Boolean cmp1stChar(); /* custom comparison function */
if ( LSearch ( &theChar, 1, cmp1stChar, &theCell, theList ) ){
    LSetSelect(TRUE, theCell, theList);
    LAutoScroll(theList); /* make sure selection is visible */
}
See LSearch for an example of how to make a first-character search
routine, similar to that used by Standard File.
Another use for LSetSelect might be to make a double-clicked selection
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LSetSelect(Boolean setIt, Cell theCell, ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x005C, 0xA9E7);


			/** 
			\brief Draw the contents of a single cell 
			\param    theCell cell to redraw
			<pre>LDraw draws the contents of a single cell. If the cell is currently outside the
visible region, or if drawing is off, this call does nothing.
theCellis a Cell (a.k.a. Point); it identifies the cell to draw.
theListis a handle leading to a variable-length ListRec structure. It is a
value previously obtained via LNew.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>List Manager functions that change the contents of a cell automatically
update the screen to reflect those changes. For instance, LSetCell
(changing the contents of a cell) will display the changed data
automatically. Similarly, LSetSelect automatically highlights or
normalizes the cell.
Note: Contrary to information in IM IV, if drawing is off (see
LDoDraw ), even LDraw does not change the screen.
You could use LDraw to customize the way some cells are displayed. For
instance, the following code draws a particular cell in boldface:
TextFace ( bold );
LDraw( theCell, theList );
TextFace ( 0 );
Note that the above style change will NOT be remembered the next time the
cell is redrawn. For instance, if theCell gets scrolled out of the window and
back in, it will be redrawn in the current text style of the list's window.
If you change the contents of a cell without informing the List Manager, you
can use LDraw to force that change to be displayed. For instance, it is
much more efficient to "zap" a character, say a check mark ( √) or a bullet
(•), over a space character than it is to use LSetCell to change the entire
contents of a cell:
shortoffset, len;
char*cp;
LFind( &offset, &len, theCell, theList );
cp = (char *)((long)**(*theList)->cells ) + offset;
*cp = checkMark; /* zap the check mark in place */
LDraw( theCell, theList ); /* force cell to be redrawn */
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LDraw(Cell theCell, ListHandle lHandle) THREEWORDINLINE(0x3F3C, 0x0030, 0xA9E7);

/**
 *  LGetCellDataLocation()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
LGetCellDataLocation(short *offset, short *len, Cell theCell,
                     ListHandle lHandle)
    THREEWORDINLINE(0x3F3C, 0x0034, 0xA9E7);

/** Routines available in Carbon only*/

/**
 *  RegisterListDefinition()
 *
 *  Summary:
 *    Registers a binding between a resource ID and a list definition
 *    function.
 *
 *  Discussion:
 *    In the Mac OS 8.x List Manager, a 'ldes' resource can contain an
 *    embedded LDEF procID that is used by the List Manager as the
 *    resource ID of an 'LDEF' resource to measure and draw the list.
 *    Since LDEFs can no longer be packaged as code resources on
 *    Carbon, the procID can no longer refer directly to an LDEF
 *    resource. However, using RegisterListDefinition you can instead
 *    specify a UniversalProcPtr pointing to code in your application
 *    code fragment.
 *
 *  Parameters:
 *
 *    inResID:
 *      An LDEF proc ID, as used in a 'ldes' resource.
 *
 *    inDefSpec:
 *      Specifies the ListDefUPP that should be used for lists with the
 *      given LDEF procID.
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
RegisterListDefinition(SInt16 inResID, ListDefSpecPtr inDefSpec);

#if CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON
/**
 *  SetListDefinitionProc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
SetListDefinitionProc(SInt16 resID, ListDefUPP defProc);

#endif /** CALL_NOT_IN_CARBON */

#endif /** CALL_NOT_IN_CARBON */

#if !TARGET_OS_MAC
/** QuickTime 3.0 */
#if CALL_NOT_IN_CARBON
/**
 *  LSetLDEF()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
LSetLDEF(ListDefProcPtr proc, ListRef lHandle);

#endif /** CALL_NOT_IN_CARBON */

#endif /** !TARGET_OS_MAC */

#if CALL_NOT_IN_CARBON
/**
 *  laddtocell()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
laddtocell(const void *dataPtr, short dataLen, const Cell *theCell,
           ListHandle lHandle);

/**
 *  lclrcell()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
lclrcell(const Cell *theCell, ListHandle lHandle);

/**
 *  lgetcelldatalocation()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
lgetcelldatalocation(short *offset, short *len, const Cell *theCell,
                     ListHandle lHandle);

/**
 *  lgetcell()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
lgetcell(void *dataPtr, short *dataLen, const Cell *theCell,
         ListHandle lHandle);

/**
 *  lnew()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
ListHandle
lnew(const Rect *rView, const ListBounds *dataBounds, Point *cSize,
     short theProc, WindowRef theWindow, Boolean drawIt, Boolean hasGrow,
     Boolean scrollHoriz, Boolean scrollVert);

/**
 *  lrect()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
lrect(Rect *cellRect, const Cell *theCell, ListHandle lHandle);

/**
 *  lsetcell()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
lsetcell(const void *dataPtr, short dataLen, const Cell *theCell,
         ListHandle lHandle);

/**
 *  lsetselect()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
lsetselect(Boolean setIt, const Cell *theCell, ListHandle lHandle);

/**
 *  ldraw()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
ldraw(const Cell *theCell, ListHandle lHandle);

/**
 *  lclick()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
lclick(Point *pt, EventModifiers modifiers, ListHandle lHandle);

/**
 *  lcellsize()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
lcellsize(Point *cSize, ListHandle lHandle);

#endif /** CALL_NOT_IN_CARBON */

#if OLDROUTINENAMES
#define LDoDraw(drawIt, lHandle) LSetDrawingMode(drawIt, lHandle)
#define LFind(offset, len, theCell, lHandle) \
  LGetCellDataLocation(offset, len, theCell, lHandle)
#if CGLUESUPPORTED
#define lfind(offset, len, theCell, lHandle) \
  lgetcelldatalocation(offset, len, theCell, lHandle)
#endif
#endif /** OLDROUTINENAMES */

#if ACCESSOR_CALLS_ARE_FUNCTIONS
/** Getters */
/**
 *  GetListViewBounds()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Rect *
GetListViewBounds(ListRef list, Rect *view);

/**
 *  GetListPort()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
CGrafPtr
GetListPort(ListRef list);

/**
 *  GetListCellIndent()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Point *
GetListCellIndent(ListRef list, Point *indent);

/**
 *  GetListCellSize()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Point *
GetListCellSize(ListRef list, Point *size);

/**
 *  GetListVisibleCells()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ListBounds *
GetListVisibleCells(ListRef list, ListBounds *visible);

/**
 *  GetListVerticalScrollBar()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlRef
GetListVerticalScrollBar(ListRef list);

/**
 *  GetListHorizontalScrollBar()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ControlRef
GetListHorizontalScrollBar(ListRef list);

/**
 *  GetListActive()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
GetListActive(ListRef list);

/**
 *  GetListClickTime()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
GetListClickTime(ListRef list);

/**
 *  GetListClickLocation()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Point *
GetListClickLocation(ListRef list, Point *click);

/**
 *  GetListMouseLocation()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Point *
GetListMouseLocation(ListRef list, Point *mouse);

/**
 *  GetListClickLoop()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ListClickLoopUPP
GetListClickLoop(ListRef list);

/**
 *  GetListRefCon()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
GetListRefCon(ListRef list);

/**
 *  GetListDefinition()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Handle
GetListDefinition(ListRef list);

/**
 *  GetListUserHandle()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Handle
GetListUserHandle(ListRef list);

/**
 *  GetListDataBounds()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
ListBounds *
GetListDataBounds(ListRef list, ListBounds *bounds);

/**
 *  GetListDataHandle()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
DataHandle
GetListDataHandle(ListRef list);

/**
 *  GetListFlags()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OptionBits
GetListFlags(ListRef list);

/**
 *  GetListSelectionFlags()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OptionBits
GetListSelectionFlags(ListRef list);

/** Setters */
/**
 *  SetListViewBounds()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
SetListViewBounds(ListRef list, const Rect *view);

/**
 *  SetListPort()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
SetListPort(ListRef list, CGrafPtr port);

/**
 *  SetListCellIndent()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
SetListCellIndent(ListRef list, Point *indent);

/**
 *  SetListClickTime()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
SetListClickTime(ListRef list, SInt32 time);

/**
 *  SetListClickLoop()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
SetListClickLoop(ListRef list, ListClickLoopUPP clickLoop);

/**
 *  SetListLastClick()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
SetListLastClick(ListRef list, Cell *lastClick);

/**
 *  SetListRefCon()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
SetListRefCon(ListRef list, SInt32 refCon);

/**
 *  SetListUserHandle()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
SetListUserHandle(ListRef list, Handle userHandle);

/**
 *  SetListFlags()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
SetListFlags(ListRef list, OptionBits listFlags);

/**
 *  SetListSelectionFlags()
 *

 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
SetListSelectionFlags(ListRef list, OptionBits selectionFlags);

#endif /** ACCESSOR_CALLS_ARE_FUNCTIONS */

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

#endif                                                    /** __LISTS__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/A_IMPORT_OFF
               #pragma import off
               #elif PRAGMA_IMPORT
               #pragma import reset
               #endif

               #ifdef __cplusplus
               }
               #endif

               #endif /** __LISTS__ */
    * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ */*/