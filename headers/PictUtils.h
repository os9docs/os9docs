/**
     \file       PictUtils.h

    \brief   Picture Utilities Interfaces.

    \introduced_in  Mac OS 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Misc

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __PICTUTILS__
#define __PICTUTILS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __PALETTES__
#include <Palettes.h>
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

  /** verbs for the GetPictInfo, GetPixMapInfo, and NewPictInfo calls */
  enum
  {
    returnColorTable = 0x0001,
    returnPalette = 0x0002,
    recordComments = 0x0004,
    recordFontInfo = 0x0008,
    suppressBlackAndWhite = 0x0010
  };

  enum
  {
    /** color pick methods */
    systemMethod = 0,  /** system color pick method */
    popularMethod = 1, /** method that chooses the most popular set of colors */
    medianMethod = 2   /** method that chooses a good average mix of colors */
  };

  enum
  {
    /** color bank types */
    ColorBankIsCustom = -1,
    ColorBankIsExactAnd555 = 0,
    ColorBankIs555 = 1
  };

  typedef long PictInfoID;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct CommentSpec
  {
    short count; /**<   number of occurrances of*/
    short ID;    /**<   ID for the comment in the*/
  } CommentSpec; /**<*/

  typedef struct CommentSpec CommentSpec;
  typedef CommentSpec *CommentSpecPtr;
  typedef CommentSpecPtr *CommentSpecHandle;
  /**
  <pre><table><tbody>
  <tr>
    <td>pictFontID</td>
    <td><pre>The pictFontID field contains the ID number of the font as it is stored
  the picture.
    </pre></td>
  </tr>

  <tr>
    <td>sysFontID</td>
    <td><pre>The sysFontID field contains the ID number of the font as it is stored
  the current System file.
  The size field contains 128 bits, in which a bit is set for each point
  encountered, from 1 to 127 points. Bit 0 is set if a size larger
  127 is found.
    </pre></td>
  </tr>

  <tr>
    <td>style</td>
    <td><pre>The style field indicates the text styles (such as bold or italic) that
  encountered for this font at any of its sizes. The style field is
  by the StyleItem data type, described in the QuickDraw
  The nameOffset field contains the offset into the list of font names
  to by the fontNamesHandle field of the picture information
  at which this font name is stored.
  Reference © 1991-1992 Symantec Corporation
    </pre></td>
  </tr>
  </tbody></table>*/
  struct FontSpec
  {
    short pictFontID; /**< ID of the font in the picture*/
    short sysFontID;  /**< ID of the same font in the current system*/
    long size[];      /**< bit array of all the sizes found (..)*/
    short style;      /**< combined style of all occurrances of the font*/
    long nameOffset;  /**< offset into the fontNamesHdl handle for the*/
  } FontSpec;         /**< */

  typedef struct FontSpec FontSpec;
  typedef FontSpec *FontSpecPtr;
  typedef FontSpecPtr *FontSpecHandle;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct PictInfo
  {
    short version;                   /**< this is always zero, for now*/
    long uniqueColors;               /**< the number of actual colors in*/
    PaletteHandle thePalette;        /**< handle to the palette information*/
    CTabHandle theColorTable;        /**< handle to the color table*/
    Fixed hRes;                      /**< maximum horizontal resolution*/
    Fixed vRes;                      /**< maximum vertical resolution for*/
    short depth;                     /**< maximum depth for all the*/
    Rect sourceRect;                 /**< the picture frame rectangle (this*/
    long textCount;                  /**< total number of text strings in*/
    long lineCount;                  /**< total number of lines in the*/
    long rectCount;                  /**< total number of rectangles in the*/
    long rRectCount;                 /**< total number of round rectangles*/
    long ovalCount;                  /**< total number of ovals in the*/
    long arcCount;                   /**< total number of arcs in the*/
    long polyCount;                  /**< total number of polygons in the*/
    long regionCount;                /**< total number of regions in the*/
    long bitMapCount;                /**< total number of bitmaps in the*/
    long pixMapCount;                /**< total number of pixmaps in the*/
    long commentCount;               /**< total number of comments in the*/
    long uniqueComments;             /**< the number of unique comments*/
    CommentSpecHandle commentHandle; /**< handle to all the comment*/
    long uniqueFonts;                /**< the number of unique fonts in the*/
    FontSpecHandle fontHandle;       /**< handle to the FontSpec*/
    Handle fontNamesHandle;          /**< handle to the font names*/
    long reserved;                   /**< */
    long reserved;                   /**< */
  } PictInfo;                        /**< */

  typedef struct PictInfo PictInfo;
  typedef PictInfo *PictInfoPtr;
  typedef PictInfoPtr *PictInfoHandle;
  typedef CALLBACK_API(OSErr, InitPickMethodProcPtr)(SInt16 colorsRequested,
                                                     UInt32 *dataRef,
                                                     SInt16 *colorBankType);
  typedef CALLBACK_API(OSErr, RecordColorsProcPtr)(UInt32 dataRef,
                                                   RGBColor *colorsArray,
                                                   SInt32 colorCount,
                                                   SInt32 *uniqueColors);
  typedef CALLBACK_API(OSErr, CalcColorTableProcPtr)(UInt32 dataRef,
                                                     SInt16 colorsRequested,
                                                     void *colorBankPtr,
                                                     CSpecArray resultPtr);
  typedef CALLBACK_API(OSErr, DisposeColorPickMethodProcPtr)(UInt32 dataRef);
  typedef STACK_UPP_TYPE(InitPickMethodProcPtr) InitPickMethodUPP;
  typedef STACK_UPP_TYPE(RecordColorsProcPtr) RecordColorsUPP;
  typedef STACK_UPP_TYPE(CalcColorTableProcPtr) CalcColorTableUPP;
  typedef STACK_UPP_TYPE(DisposeColorPickMethodProcPtr) DisposeColorPickMethodUPP;
  /**
   *  NewInitPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  InitPickMethodUPP
  NewInitPickMethodUPP(InitPickMethodProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppInitPickMethodProcInfo = 0x00000FA0
  }; /** pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline InitPickMethodUPP
  NewInitPickMethodUPP(InitPickMethodProcPtr userRoutine)
  {
    return (InitPickMethodUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppInitPickMethodProcInfo,
                                                   GetCurrentArchitecture());
  }
#else
#define NewInitPickMethodUPP(userRoutine)                                     \
  (InitPickMethodUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppInitPickMethodProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewRecordColorsUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  RecordColorsUPP
  NewRecordColorsUPP(RecordColorsProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppRecordColorsProcInfo = 0x00003FE0
  }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline RecordColorsUPP NewRecordColorsUPP(RecordColorsProcPtr userRoutine)
  {
    return (RecordColorsUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppRecordColorsProcInfo,
                                                 GetCurrentArchitecture());
  }
#else
#define NewRecordColorsUPP(userRoutine)                                     \
  (RecordColorsUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppRecordColorsProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewCalcColorTableUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  CalcColorTableUPP
  NewCalcColorTableUPP(CalcColorTableProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppCalcColorTableProcInfo = 0x00003EE0
  }; /** pascal 2_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline CalcColorTableUPP
  NewCalcColorTableUPP(CalcColorTableProcPtr userRoutine)
  {
    return (CalcColorTableUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppCalcColorTableProcInfo,
                                                   GetCurrentArchitecture());
  }
#else
#define NewCalcColorTableUPP(userRoutine)                                     \
  (CalcColorTableUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppCalcColorTableProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDisposeColorPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DisposeColorPickMethodUPP
  NewDisposeColorPickMethodUPP(DisposeColorPickMethodProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDisposeColorPickMethodProcInfo = 0x000000E0
  }; /** pascal 2_bytes Func(4_bytes) */
#ifdef __cplusplus
  inline DisposeColorPickMethodUPP
  NewDisposeColorPickMethodUPP(DisposeColorPickMethodProcPtr userRoutine)
  {
    return (DisposeColorPickMethodUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDisposeColorPickMethodProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewDisposeColorPickMethodUPP(userRoutine)                \
  (DisposeColorPickMethodUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppDisposeColorPickMethodProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeInitPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeInitPickMethodUPP(InitPickMethodUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeInitPickMethodUPP(InitPickMethodUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeInitPickMethodUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeRecordColorsUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeRecordColorsUPP(RecordColorsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeRecordColorsUPP(RecordColorsUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeRecordColorsUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeCalcColorTableUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeCalcColorTableUPP(CalcColorTableUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeCalcColorTableUPP(CalcColorTableUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeCalcColorTableUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDisposeColorPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDisposeColorPickMethodUPP(DisposeColorPickMethodUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  DisposeDisposeColorPickMethodUPP(DisposeColorPickMethodUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDisposeColorPickMethodUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeInitPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeInitPickMethodUPP(SInt16 colorsRequested, UInt32 *dataRef,
                          SInt16 *colorBankType, InitPickMethodUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeInitPickMethodUPP(SInt16 colorsRequested, UInt32 *dataRef,
                                       SInt16 *colorBankType,
                                       InitPickMethodUPP userUPP)
  {
    return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppInitPickMethodProcInfo,
                                           colorsRequested, dataRef,
                                           colorBankType);
  }
#else
#define InvokeInitPickMethodUPP(colorsRequested, dataRef, colorBankType, \
                                userUPP)                                 \
  (OSErr)                                                                \
      CALL_THREE_PARAMETER_UPP((userUPP), uppInitPickMethodProcInfo,     \
                               (colorsRequested), (dataRef), (colorBankType))
#endif
#endif

  /**
   *  InvokeRecordColorsUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeRecordColorsUPP(UInt32 dataRef, RGBColor *colorsArray, SInt32 colorCount,
                        SInt32 *uniqueColors, RecordColorsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeRecordColorsUPP(UInt32 dataRef, RGBColor *colorsArray,
                                     SInt32 colorCount, SInt32 *uniqueColors,
                                     RecordColorsUPP userUPP)
  {
    return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppRecordColorsProcInfo,
                                          dataRef, colorsArray, colorCount,
                                          uniqueColors);
  }
#else
#define InvokeRecordColorsUPP(dataRef, colorsArray, colorCount, uniqueColors, \
                              userUPP)                                        \
  (OSErr)                                                                     \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppRecordColorsProcInfo, (dataRef),  \
                              (colorsArray), (colorCount), (uniqueColors))
#endif
#endif

  /**
   *  InvokeCalcColorTableUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeCalcColorTableUPP(UInt32 dataRef, SInt16 colorsRequested,
                          void *colorBankPtr, CSpecArray resultPtr,
                          CalcColorTableUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeCalcColorTableUPP(UInt32 dataRef, SInt16 colorsRequested,
                                       void *colorBankPtr, CSpecArray resultPtr,
                                       CalcColorTableUPP userUPP)
  {
    return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppCalcColorTableProcInfo,
                                          dataRef, colorsRequested, colorBankPtr,
                                          resultPtr);
  }
#else
#define InvokeCalcColorTableUPP(dataRef, colorsRequested, colorBankPtr,        \
                                resultPtr, userUPP)                            \
  (OSErr)                                                                      \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppCalcColorTableProcInfo, (dataRef), \
                              (colorsRequested), (colorBankPtr), (resultPtr))
#endif
#endif

  /**
   *  InvokeDisposeColorPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeDisposeColorPickMethodUPP(UInt32 dataRef,
                                  DisposeColorPickMethodUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr
  InvokeDisposeColorPickMethodUPP(UInt32 dataRef,
                                  DisposeColorPickMethodUPP userUPP)
  {
    return (OSErr)CALL_ONE_PARAMETER_UPP(
        userUPP, uppDisposeColorPickMethodProcInfo, dataRef);
  }
#else
#define InvokeDisposeColorPickMethodUPP(dataRef, userUPP)                      \
  (OSErr) CALL_ONE_PARAMETER_UPP((userUPP), uppDisposeColorPickMethodProcInfo, \
                                 (dataRef))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewInitPickMethodProc(userRoutine) NewInitPickMethodUPP(userRoutine)
#define NewRecordColorsProc(userRoutine) NewRecordColorsUPP(userRoutine)
#define NewCalcColorTableProc(userRoutine) NewCalcColorTableUPP(userRoutine)
#define NewDisposeColorPickMethodProc(userRoutine) \
  NewDisposeColorPickMethodUPP(userRoutine)
#define CallInitPickMethodProc(userRoutine, colorsRequested, dataRef, \
                               colorBankType)                         \
  InvokeInitPickMethodUPP(colorsRequested, dataRef, colorBankType, userRoutine)
#define CallRecordColorsProc(userRoutine, dataRef, colorsArray, colorCount, \
                             uniqueColors)                                  \
  InvokeRecordColorsUPP(dataRef, colorsArray, colorCount, uniqueColors,     \
                        userRoutine)
#define CallCalcColorTableProc(userRoutine, dataRef, colorsRequested,        \
                               colorBankPtr, resultPtr)                      \
  InvokeCalcColorTableUPP(dataRef, colorsRequested, colorBankPtr, resultPtr, \
                          userRoutine)
#define CallDisposeColorPickMethodProc(userRoutine, dataRef) \
  InvokeDisposeColorPickMethodUPP(dataRef, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  /**
   *  GetPictInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetPictInfo(PicHandle thePictHandle, PictInfo *thePictInfo, short verb,
              short colorsRequested, short colorPickMethod, short version);

  /**
   *  GetPixMapInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetPixMapInfo(PixMapHandle thePixMapHandle, PictInfo *thePictInfo, short verb,
                short colorsRequested, short colorPickMethod, short version);

  /**
   *  NewPictInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  NewPictInfo(PictInfoID *thePictInfoID, short verb, short colorsRequested,
              short colorPickMethod, short version);

  /**
   *  RecordPictInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RecordPictInfo(PictInfoID thePictInfoID, PicHandle thePictHandle);

  /**
   *  RecordPixMapInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RecordPixMapInfo(PictInfoID thePictInfoID, PixMapHandle thePixMapHandle);

  /**
   *  RetrievePictInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RetrievePictInfo(PictInfoID thePictInfoID, PictInfo *thePictInfo,
                   short colorsRequested);

  /**
   *  DisposePictInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DisposePictInfo(PictInfoID thePictInfoID);

#if OLDROUTINENAMES
#define DisposPictInfo(thePictInfoID) DisposePictInfo(thePictInfoID)
#endif /** OLDROUTINENAMES */

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

#endif /** __PICTUTILS__ */
PictInfoID)
#endif /** OLDROUTINENAMES */

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

#endif /** __PICTUTILS__ */
