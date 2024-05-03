/**
     \file       TextEdit.h

    \brief   TextEdit Interfaces.

    \introduced_in  System 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Font

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __TEXTEDIT__
#define __TEXTEDIT__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
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

  typedef struct TERec TERec;
  typedef TERec *TEPtr;
  typedef TEPtr *TEHandle;
  typedef CALLBACK_API_REGISTER68K(void, HighHookProcPtr,
                                   (const Rect *r, TEPtr pTE));
  typedef CALLBACK_API_REGISTER68K(Boolean, EOLHookProcPtr,
                                   (char theChar, TEPtr pTE, TEHandle hTE));
  typedef CALLBACK_API_REGISTER68K(void, CaretHookProcPtr,
                                   (const Rect *r, TEPtr pTE));
  typedef CALLBACK_API_REGISTER68K(unsigned short, WidthHookProcPtr,
                                   (unsigned short textLen,
                                    unsigned short textOffset,
                                    void *textBufferPtr, TEPtr pTE,
                                    TEHandle hTE));
  typedef CALLBACK_API_REGISTER68K(unsigned short, TextWidthHookProcPtr,
                                   (unsigned short textLen,
                                    unsigned short textOffset,
                                    void *textBufferPtr, TEPtr pTE,
                                    TEHandle hTE));
  typedef CALLBACK_API_REGISTER68K(unsigned short, NWidthHookProcPtr,
                                   (unsigned short styleRunLen,
                                    unsigned short styleRunOffset, short slop,
                                    short direction, void *textBufferPtr,
                                    short *lineStart, TEPtr pTE, TEHandle hTE));
  typedef CALLBACK_API_REGISTER68K(void, DrawHookProcPtr,
                                   (unsigned short textOffset,
                                    unsigned short drawLen, void *textBufferPtr,
                                    TEPtr pTE, TEHandle hTE));
  typedef CALLBACK_API_REGISTER68K(
      Boolean, HitTestHookProcPtr,
      (unsigned short styleRunLen, unsigned short styleRunOffset,
       unsigned short slop, void *textBufferPtr, TEPtr pTE, TEHandle hTE,
       unsigned short *pixelWidth, unsigned short *charOffset,
       Boolean *pixelInChar));
  typedef CALLBACK_API_REGISTER68K(void, TEFindWordProcPtr,
                                   (unsigned short currentPos, short caller,
                                    TEPtr pTE, TEHandle hTE,
                                    unsigned short *wordStart,
                                    unsigned short *wordEnd));
  typedef CALLBACK_API_REGISTER68K(void, TERecalcProcPtr,
                                   (TEPtr pTE, unsigned short changeLength,
                                    unsigned short *lineStart,
                                    unsigned short *firstChar,
                                    unsigned short *lastChar));
  typedef CALLBACK_API_REGISTER68K(void, TEDoTextProcPtr,
                                   (TEPtr pTE, unsigned short firstChar,
                                    unsigned short lastChar, short selector,
                                    GrafPtr *currentGrafPort,
                                    short *charPosition));
  typedef CALLBACK_API_REGISTER68K(Boolean, TEClickLoopProcPtr, (TEPtr pTE));
  typedef CALLBACK_API_REGISTER68K(Boolean, WordBreakProcPtr,
                                   (Ptr text, short charPos));
  /**
      Important note about TEClickLoopProcPtr and WordBreakProcPtr

      At one point these were defined as returning the function result in the
      condition code Z-bit.  This was correct, in that it was what the 68K
      implementation of TextEdit actually tested.  But, MixedMode had a different
      idea of what returning a boolean in the Z-bit meant.  MixedMode was setting
      the Z-bit the complement of what was wanted.

      Therefore, these ProcPtrs have been changed (back) to return the result in
      register D0.  It turns out that for register based routines,
      MixedMode sets the Z-bit of the 68K emulator based on the contents
      of the return result register.  Thus we can get the Z-bit set correctly.

      But, when TextEdit is recoded in PowerPC, if it calls a 68K ClickLoop
      or WordBreak routine, register D0 had better have the result (in addition
      to the Z-bit). Therefore all 68K apps should make sure their ClickLoop or
      WordBreak routines set register D0 at the end.
  */

  /**
      There is no function to get/set the low-mem for FindWordHook at 0x07F8.
      This is because it is not a low-mem ProcPtr. That address is the entry
      in the OS TrapTable for trap 0xA0FE.  You can use Get/SetTrapAddress to
      acccess it.
  */

  /**
      The following ProcPtrs cannot be written in or called from a high-level
      language without the help of mixed mode or assembly glue because they
      use the following parameter-passing conventions:

      typedef pascal void (*HighHookProcPtr)(const Rect *r, TEPtr pTE);
      typedef pascal void (*CaretHookProcPtr)(const Rect *r, TEPtr pTE);

          In:
              =>  r                       on stack
              =>  pTE                     A3.L
          Out:
              none

      typedef pascal Boolean (*EOLHookProcPtr)(char theChar, TEPtr pTE, TEHandle
     hTE);

          In:
              =>  theChar                 D0.B
              =>  pTE                     A3.L
              =>  hTE                     A4.L
          Out:
              <=  Boolean                 Z bit of the CCR

      typedef pascal unsigned short (*WidthHookProcPtr)(unsigned short textLen,
       unsigned short textOffset, void *textBufferPtr, TEPtr pTE, TEHandle hTE);
      typedef pascal unsigned short (*TextWidthHookProcPtr)(unsigned short
     textLen, unsigned short textOffset, void *textBufferPtr, TEPtr pTE, TEHandle
     hTE);

          In:
              =>  textLen                 D0.W
              =>  textOffset              D1.W
              =>  textBufferPtr           A0.L
              =>  pTE                     A3.L
              =>  hTE                     A4.L
          Out:
              <=  unsigned short          D1.W

      typedef pascal unsigned short (*NWidthHookProcPtr)(unsigned short
     styleRunLen, unsigned short styleRunOffset, short slop, short direction, void
     *textBufferPtr, short *lineStart, TEPtr pTE, TEHandle hTE);

          In:
              =>  styleRunLen             D0.W
              =>  styleRunOffset          D1.W
              =>  slop                    D2.W (low)
              =>  direction               D2.W (high)
              =>  textBufferPtr           A0.L
              =>  lineStart               A2.L
              =>  pTE                     A3.L
              =>  hTE                     A4.L
          Out:
              <=  unsigned short          D1.W

      typedef pascal void (*DrawHookProcPtr)(unsigned short textOffset, unsigned
     short drawLen, void *textBufferPtr, TEPtr pTE, TEHandle hTE);

          In:
              =>  textOffset              D0.W
              =>  drawLen                 D1.W
              =>  textBufferPtr           A0.L
              =>  pTE                     A3.L
              =>  hTE                     A4.L
          Out:
              none

      typedef pascal Boolean (*HitTestHookProcPtr)(unsigned short styleRunLen,
       unsigned short styleRunOffset, unsigned short slop, void *textBufferPtr,
       TEPtr pTE, TEHandle hTE, unsigned short *pixelWidth, unsigned short
     *charOffset, Boolean *pixelInChar);

          In:
              =>  styleRunLen             D0.W
              =>  styleRunOffset          D1.W
              =>  slop                    D2.W
              =>  textBufferPtr           A0.L
              =>  pTE                     A3.L
              =>  hTE                     A4.L
          Out:
              <=  pixelWidth              D0.W (low)
              <=  Boolean                 D0.W (high)
              <=  charOffset              D1.W
              <=  pixelInChar             D2.W

      typedef pascal void (*TEFindWordProcPtr)(unsigned short currentPos, short
     caller, TEPtr pTE, TEHandle hTE, unsigned short *wordStart, unsigned short
     *wordEnd);

          In:
              =>  currentPos              D0.W
              =>  caller                  D2.W
              =>  pTE                     A3.L
              =>  hTE                     A4.L
          Out:
              <=  wordStart               D0.W
              <=  wordEnd                 D1.W

      typedef pascal void (*TERecalcProcPtr)(TEPtr pTE, unsigned short
     changeLength, unsigned short *lineStart, unsigned short *firstChar, unsigned
     short *lastChar);

          In:
              =>  pTE                     A3.L
              =>  changeLength            D7.W
          Out:
              <=  lineStart               D2.W
              <=  firstChar               D3.W
              <=  lastChar                D4.W

      typedef pascal void (*TEDoTextProcPtr)(TEPtr pTE, unsigned short firstChar,
     unsigned short lastChar, short selector, GrafPtr *currentGrafPort, short
     *charPosition);

          In:
              =>  pTE                     A3.L
              =>  firstChar               D3.W
              =>  lastChar                D4.W
              =>  selector                D7.W
          Out:
              <=  currentGrafPort         A0.L
              <=  charPosition            D0.W

  */
  typedef REGISTER_UPP_TYPE(HighHookProcPtr) HighHookUPP;
  typedef REGISTER_UPP_TYPE(EOLHookProcPtr) EOLHookUPP;
  typedef REGISTER_UPP_TYPE(CaretHookProcPtr) CaretHookUPP;
  typedef REGISTER_UPP_TYPE(WidthHookProcPtr) WidthHookUPP;
  typedef REGISTER_UPP_TYPE(TextWidthHookProcPtr) TextWidthHookUPP;
  typedef REGISTER_UPP_TYPE(NWidthHookProcPtr) NWidthHookUPP;
  typedef REGISTER_UPP_TYPE(DrawHookProcPtr) DrawHookUPP;
  typedef REGISTER_UPP_TYPE(HitTestHookProcPtr) HitTestHookUPP;
  typedef REGISTER_UPP_TYPE(TEFindWordProcPtr) TEFindWordUPP;
  typedef REGISTER_UPP_TYPE(TERecalcProcPtr) TERecalcUPP;
  typedef REGISTER_UPP_TYPE(TEDoTextProcPtr) TEDoTextUPP;
  typedef REGISTER_UPP_TYPE(TEClickLoopProcPtr) TEClickLoopUPP;
  typedef REGISTER_UPP_TYPE(WordBreakProcPtr) WordBreakUPP;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TERec
  {
    Rect destRect;      /**<  Rectangle in which text is drawn*/
    Rect viewRect;      /**<  Rectangle in which text is visible*/
    Rect selRect;       /**<  Selection rectangle (undocumented)*/
    short lineHeight;   /**<  Distance between lines (see "style"*/
    short fontAscent;   /**<  Max distance above baseline for*/
    Point selPoint;     /**<  Point selected with mouse, in local*/
    short selStart;     /**<  Offset in hText of char at start of*/
    short selEnd;       /**<  Offset in hText of character at end of*/
    short active;       /**<  (used internally)*/
    ProcPtr wordBreak;  /**<  Routine handles word breaks*/
    ProcPtr clikLoop;   /**<  Rtn gets control while mouse down*/
    long clickTime;     /**<  (used internally)*/
    short clickLoc;     /**<  (used internally)*/
    long caretTime;     /**<  (used internally)*/
    short caretState;   /**<  (used internally)*/
    short just;         /**<  =justify left, =center,*/
    short teLength;     /**<  Number of characters in hText*/
    Handle hText;       /**<  Leads to characters to be edited*/
    short recalBack;    /**<  (used internally)*/
    short recalLines;   /**<  (used internally)*/
    short clikStuff;    /**<  (used internally)*/
    short crOnly;       /**<  > for word wrap, < for newline*/
    short txFont;       /**<  Font to be used  (See Notes on*/
    Style txFace;       /**<  Text Style to be used;/**< eg, bold, italic,*/
    char filler;        /**<  (unused)*/
    short txMode;       /**<  Transfer Mode ;/**< eg, srcCopy, srcOr,*/
    short txSize;       /**<  Size, in points, to use (< means*/
    GrafPtr inPort;     /**<  GrafPort  in which text is*/
    ProcPtr highHook;   /**<  Routine to perform highlighting*/
    ProcPtr caretHook;  /**<  Routine to display caret*/
    short nLines;       /**<  Number of lines of text in hText*/
    short lineStarts[]; /**< n Array of offsets to start of each line*/
  } TERec;              /**< +n(n  is nLines * )*/

  enum
  {
     /** (word */
alignment) styles     teJustLeft  =  0
    teJustCenter = 1,
    teJustRight = -1,
    teForceLeft =
        -2,             /** names */
for the Justification (word alignment) styles     teFlushDefault  =  0 // flush according to the line direction
    teCenter = 1,      // center justify (word alignment)
    teFlushRight = -1, // flush right for all scripts
    teFlushLeft = -2   // flush left for all scripts
  };

  enum
  {
    /** style */
    modes fontBit = 0 // set font
    faceBit = 1,      // set face
    sizeBit = 2,      // set size
    clrBit = 3,       // set color
    addSizeBit = 4,   // add size mode
    toggleBit = 5     // set faces in toggle mode
  };

  enum
  {
    /** modes */
    doFont = 1                /** font */
    (family)number doFace = 2 // set character style
    doSize = 4,               // set type size
    doColor = 8,              // set color
    doAll = 15,               // set all attributes
    addSize = 16,             // adjust type size
    doToggle = 32             // toggle mode for TESetStyle
  };

  enum
  {
    /** into */
    TEDispatchRec EOLHook = 0 // [UniversalProcPtr] TEEOLHook
    DRAWHook = 4,             // [UniversalProcPtr] TEWidthHook
    WIDTHHook = 8,            // [UniversalProcPtr] TEDrawHook
    HITTESTHook = 12,         // [UniversalProcPtr] TEHitTestHook
    nWIDTHHook = 24,          // [UniversalProcPtr] nTEWidthHook
    TextWidthHook = 28        // [UniversalProcPtr] TETextWidthHook
  };

  enum
  {
    /** for */
    TECustomHook intEOLHook = 0 // TEIntHook value
    intDrawHook = 1,            // TEIntHook value
    intWidthHook = 2,           // TEIntHook value
    intHitTestHook = 3,         // TEIntHook value
    intNWidthHook = 6,          // TEIntHook value for new version of WidthHook
    intTextWidthHook = 7,       // TEIntHook value for new TextWidthHook
    intInlineInputTSMTEPreUpdateHook =
        8, // TEIntHook value for TSMTEPreUpdateProcPtr callback
    intInlineInputTSMTEPostUpdateHook =
        9 // TEIntHook value for TSMTEPostUpdateProcPtr callback
  };

  enum
  {
     /** or */
bit definitions for TEFeatureFlag     teFAutoScroll  =  0           // 00000001b
    teFTextBuffering = 1,        // 00000010b
    teFOutlineHilite = 2,        // 00000100b
    teFInlineInput = 3,          // 00001000b
    teFUseWhiteBackground = 4,   // 00010000b
    teFUseInlineInput = 5,       // 00100000b
    teFInlineInputAutoScroll = 6 // 01000000b
  };

  enum
  {
    // feature or bit definitions for TEFeatureFlag -- Carbon only
    /* To avoid having to call TEIdle in Carbon apps, automatic idling can be
    activated */
    /* via the following feature flag, but you must ensure that the destRect
       and/or     */
    // GrafPort's origin be setup properly for drawing in a given TERec when     // the timer fires.    When this feature flag is set, TEIdle is a noop.     // Activate this feature flag before calling TEActivate.                     teFIdleWithEventLoopTimer = 7 // 10000000b
  };

  enum
  {
    /** for */
    the new "bit (un)set" interface,
    TEFeatureFlag teBitClear = 0 teBitSet = 1, // set the selector bit
    teBitTest = -1                             // no change; just return the current setting
  };

  enum
  {
    // constants for identifying the routine that called FindWord
    teWordSelect = 4, // clickExpand to select word
    teWordDrag = 8,   // clickExpand to drag new word
    teFromFind = 12,  // FindLine called it ($0C)
    teFromRecal = 16  // RecalLines called it ($10)      obsolete
  };

  enum
  {
    // constants for identifying TEDoText selectors
    teFind = 0,      // TEDoText called for searching
    teHighlight = 1, // TEDoText called for highlighting
    teDraw = -1,     // TEDoText called for drawing text
    teCaret = -2     // TEDoText called for drawing the caret
  };

  typedef char Chars[32001];
  typedef char *CharsPtr;
  typedef CharsPtr *CharsHandle;
  /**
  <pre>
   * \note <pre>At the end of the TEStyleRec structure is a variable-length data area
  composed of one or more of these StyleRun structures. Each element of that
  array describes a "run" of characters which all have the same attributes
  (font, face, size, etc.). The run ends at the offset identified by the startChar
  field in the next structure. This structure is not used directly in any
  system function.
  The startChar field identifies an offset into the edit text.  The edit text
  begins at the address lead to by the hText field of the TERec
  The styleIndex field identifies which element of the style table applies to
  theis run of text. The style table is made up of a series of 18-byte
  STElement structures. It begins at the address lead to by the styleTab field
  of the TEStyleRec (whose handle may be obtained by GetStylHandle .
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct StyleRun
  {
    short startChar;  /**< Offset within the data lead to by TERec.htext*/
    short styleIndex; /**< Index into style table at*/
  } StyleRun;         /**< */

  typedef struct StyleRun StyleRun;
  /**
  <pre>
   * \note <pre>This structure defines a single "style", as used in TextEdit. The STElement
  structure is not used directly in any TextEdit function, but all functions
  which modify styles affect the elements of the "style table".
  The "style table" is a list of these 18-byte STElement structures. Such a
  table may be found at the addesss lead to by the styleTab field of the
  TEStyleRec structure whose address may be obtained via GetStylHandle .
  There are TEStyleRec .nStyles elements in the style table.
  The stCount fields identifies in how many runs this style is used. If, for
  example, you were to delete all text which was in a particular style, then
  the stCount would go to 0, and would be removed from the table in a memory
  crunch.
  As with all TextEdit height values, stHeight refers to a line height, in
  points. Elements of the line height table ( LHTable) contain the maximum
  value in the stHeight field of each style run in a line.
  When the question of color is moot, the stColor field contains zero's in all
  three fields of the RGBColor structure.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct STElement
  {
    short stCount;    /**<  Number of runs which use this style*/
    short stHeight;   /**<  Line height for this style, in points*/
    short stAscent;   /**<  Ascent above the baseline for this*/
    short stFont;     /**<  Font/family number.  For more*/
    Style stFace;     /**<  Font face for this style.  For more*/
    short stSize;     /**<  Font size, in points*/
    RGBColor stColor; /**<  Color used in this style*/
  } STElement;        /**< */

  typedef struct STElement STElement;
  typedef STElement TEStyleTable[1777];
  typedef STElement *STPtr;
  typedef STPtr *STHandle;
  /**
  <pre>
   * \note <pre>The LHElement structure describes the height of a single line of edit text.
  The data lead to by the lhTab field of the TEStyleRec structure is a list of
  these LHElements. The list parallels the data in the lineStarts array which
  is part of the TERec structure. It is not used directly in any TextEdit
  function, but it is used to derive values returned by TEGetHeight .
  When a font size changes the height of some text on a particular line (e.g.,
  via TESetStyle ), then the new maximum is calculated for that line and
  stored in the line height table.
  It is permitted to manipulate this table youself, overriding the normal
  height calculations. When the high bit of lhHeight is set, then TextEdit will
  use the low 15 bits as a "fixed height" and will not perform calculations to
  modify it. For instance:
  LHHandle hLH;
  LHPtr pLH;
  TEStyleHandle hTEStyle;
  TEHandle hTE;
  hTEStyle = GetStylHandle ( hTE);
  hLH = (*hTEStyle)->lhTab;
  pLH = *hLH;
  pLH[17].lhHeight = 22 | 0x8000; // fix line height at 22 points
  This technique is handy for lines which will not be changed. If the line
  grows in length or is otherwised forced to wrap, TextEdit will not honor
  your setting (it will calculate the height if the "wrapped" portion).
  Note that the line-height table is used only when TERec.lineHeight and
  TERec.fontAscent are -1 (as set by TEStylNew ).
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct LHElement
  {
    short lhHeight; /**<  Height of this line, in points (bit */
    short lhAscent; /**<  Ascent of tallest character in this line*/
  } LHElement;      /**< */

  typedef struct LHElement LHElement;
  typedef LHElement LHTable[8001];
  typedef LHElement *LHPtr;
  typedef LHPtr *LHHandle;
  /**
  <pre>
   * \note <pre>This structure defines a single style, for a run of text as used by TextEdit
  in the desk scrap. A list of these records, i.e., a ScrpSTTable, is at the tail
  of the StScrpRec structure used in TexTedit cut-and-paste operations. This
  structure in not used directly in any TextEdit function.
  The scrpStartChar field specifies where in the text (usually a 'TEXT'
  element in the desk scrap) to begin applying this combination of attributes.
  This style applies to all text up to the offset indicated by the scrpStartChar
  field in the following table element. There is no overlap or reuse of styles.
  You may want to call TENumStyles to see how much space will be used in a
  TECut or TECopy operation.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct ScrpSTElement
  {
    long scrpStartChar; /**< Offset in data to which this style*/
    short scrpHeight;   /**< Line height for this style, in points*/
    short scrpAscent;   /**< Ascent above the baseline for this*/
    short scrpFont;     /**< Font/family number.  For more*/
    Style scrpFace;     /**< Font face for this style.  For more*/
    short scrpSize;     /**< Font size, in points*/
    RGBColor scrpColor; /**< Color used in this style*/
  } ScrpSTElement;      /**< */

  typedef struct ScrpSTElement ScrpSTElement;
  // ARRAY [0..1600] OF ScrpSTElement   typedef ScrpSTElement ScrpSTTable[1601];
  /**
  <pre>
   * \note <pre>This variable-length StScrpRec is known as the "style scrap" record. It
  contains style-definition data which applies textual data.  A structure of this
  format is stored into the desk scrap as 'styl' element, along with the 'TEXT'
  element, when you use TECut and TECopy on a style-aware edit record.
  An StScrpHandle is used in calls to GetStylScrap , SetStylScrap ,
  TEStylInsert , and indirectly in TECut, TECopy, and TEStylPaste .
  Note that scrpStyleTab is not a Handle; it is a variable-length table of data (a
  ScrpSTTable ). That makes this a "portable" piece of style information - it is
  all in one packet and not spread around in different tables.
  When your application places text data into the desk scrap, it's wise to create
  one of these records and store it as well, just in case the app which reads the
  scrap knows what to do with it (see PutScrap ).
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct StScrpRec
  {
    short scrpNStyles;        /**< number of elements in scrpStyleTab*/
    ScrpSTTable scrpStyleTab; /**< n*leads to a list of text offsets and style*/
  } StScrpRec;                /**<+(n *) (n = scrpNStyles )*/

  typedef struct StScrpRec StScrpRec;
  typedef StScrpRec *StScrpPtr;
  typedef StScrpPtr *StScrpHandle;
  /**
  <pre>
   * \note <pre>The NullStRec structure is maintained to describe the default format for
  text which is added when the selection range is an insertion point. It is not
  used directly in any TextEdit function.
  The nullScrap field leads to an StScrpRec which eventually leads to a
  ScrpSTElement defining the "null style" style.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct NullStRec
  {
    long teReserved;        /**< Height of this line, in points (bit */
    StScrpHandle nullScrap; /**< Ascent of tallest character/face in this*/
  } NullStRec;              /**< */

  typedef struct NullStRec NullStRec;
  typedef NullStRec *NullStPtr;
  typedef NullStPtr *NullStHandle;
  /**
  <pre>
   * \note <pre>In the new style-aware TERec, the fields at offsets 74-77 (the txFont and
  txFace and the 1-byte filler) contain a 4-byte TEStyleHandle which leads
  to this data structure, also known as the "style record".
  Although all TextEdit style-related functions depend on it, a TEStyleHandle
  is used in only two functions directly ( SetStylHandle and
  GetStylHandle ). It is the starting point for a complex set of
  inter-dependent records.
  The amount of data in the line-height table (at lhTab) depends on the value
  of TERec.nLines. There is one LHElement for each line in the edit record.
  The nullStyle handle eventually leads to an STScrpRec . It defines the font,
  face, etc. for text which is inserted via TEKey when the selection range is
  an insertion point.
  The runs field is variable length, but always contains at least one 4-byte
  StyleRun with an index to the first style in the style table lead to by
  styleTab (which gets initialized to the TextEdit defaults for font, face, etc.).
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TEStyleRec
  {
    short nRuns;            /**< Number of elements in runs*/
    short nStyles;          /**< Number of elements in handle at styleTab*/
    STHandle styleTab;      /**< Handle to style table*/
    LHHandle lhTab;         /**< Handle to line-height table*/
    long teRefCon;          /**< Available for use by applications*/
    NullSTHandle nullStyle; /**< Handle to styles for null selection*/
    StyleRun runs[];        /**< nList of offsets and style table indexes*/
  } TEStyleRec;             /**< +n (n  is nRuns * )*/

  typedef struct TEStyleRec TEStyleRec;
  typedef TEStyleRec *TEStylePtr;
  typedef TEStylePtr *TEStyleHandle;
  /**
  <pre>
   * \note <pre>This structure defines components of a TextEdit style which you can set,
  replace, or check via TESetStyle , TEReplaceStyle , TEGetStyle , and
  TEContinuousStyle .
  The the address of this structure is always passed to the above functions;
  however, there is no standard name for such an address. TextStylePtr might
  be a good choice...
  Note that all functions which use this structure actually read information
  from the style table, composed of STElement records. The relevant data is
  shuffled into and out of or compared against data in the style table. TextEdit
  does not maintain any TextStyle records, per se.
  In each case where TextStyle is used, you are required to pass a mode value
  to specify how much of this record to use or ignore. For more informationl,
  see Style Mode .
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct TextStyle
  {
    short tsFont;     /**< Font number.  See Standard Fonts .*/
    Style tsFace;     /**< Stylistic variation.  See Text Styles .*/
    char filler;      /**< */
    short tsSize;     /**< Font size, in points*/
    RGBColor tsColor; /**< Color components*/
  } TextStyle;        /**< */

  typedef struct TextStyle TextStyle;
  typedef TextStyle *TextStylePtr;
  typedef TextStylePtr *TextStyleHandle;
  typedef short TEIntHook;
  /**
   *  NewHighHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  HighHookUPP
  NewHighHookUPP(HighHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppHighHookProcInfo = 0x0000000F
  }; // SPECIAL_CASE_PROCINFO(0) #ifdef __cplusplus
  inline HighHookUPP NewHighHookUPP(HighHookProcPtr userRoutine)
  {
    return (HighHookUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppHighHookProcInfo, GetCurrentArchitecture());
  }
#else
#define NewHighHookUPP(userRoutine)   \
  (HighHookUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppHighHookProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewEOLHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EOLHookUPP
  NewEOLHookUPP(EOLHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppEOLHookProcInfo = 0x0000001F
  }; // SPECIAL_CASE_PROCINFO(1) #ifdef __cplusplus
  inline EOLHookUPP NewEOLHookUPP(EOLHookProcPtr userRoutine)
  {
    return (EOLHookUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppEOLHookProcInfo, GetCurrentArchitecture());
  }
#else
#define NewEOLHookUPP(userRoutine)   \
  (EOLHookUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppEOLHookProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewCaretHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  CaretHookUPP
  NewCaretHookUPP(CaretHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppCaretHookProcInfo = 0x0000000F
  }; // SPECIAL_CASE_PROCINFO(0) #ifdef __cplusplus
  inline CaretHookUPP NewCaretHookUPP(CaretHookProcPtr userRoutine)
  {
    return (CaretHookUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppCaretHookProcInfo, GetCurrentArchitecture());
  }
#else
#define NewCaretHookUPP(userRoutine)   \
  (CaretHookUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppCaretHookProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewWidthHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  WidthHookUPP
  NewWidthHookUPP(WidthHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppWidthHookProcInfo = 0x0000002F
  }; // SPECIAL_CASE_PROCINFO(2) #ifdef __cplusplus
  inline WidthHookUPP NewWidthHookUPP(WidthHookProcPtr userRoutine)
  {
    return (WidthHookUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppWidthHookProcInfo, GetCurrentArchitecture());
  }
#else
#define NewWidthHookUPP(userRoutine)   \
  (WidthHookUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppWidthHookProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewTextWidthHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TextWidthHookUPP
  NewTextWidthHookUPP(TextWidthHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppTextWidthHookProcInfo = 0x0000002F
  }; // SPECIAL_CASE_PROCINFO(2) #ifdef __cplusplus
  inline TextWidthHookUPP NewTextWidthHookUPP(TextWidthHookProcPtr userRoutine)
  {
    return (TextWidthHookUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppTextWidthHookProcInfo,
                                                  GetCurrentArchitecture());
  }
#else
#define NewTextWidthHookUPP(userRoutine)                                     \
  (TextWidthHookUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppTextWidthHookProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewNWidthHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  NWidthHookUPP
  NewNWidthHookUPP(NWidthHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppNWidthHookProcInfo = 0x0000003F
  }; // SPECIAL_CASE_PROCINFO(3) #ifdef __cplusplus
  inline NWidthHookUPP NewNWidthHookUPP(NWidthHookProcPtr userRoutine)
  {
    return (NWidthHookUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppNWidthHookProcInfo, GetCurrentArchitecture());
  }
#else
#define NewNWidthHookUPP(userRoutine)   \
  (NWidthHookUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppNWidthHookProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDrawHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DrawHookUPP
  NewDrawHookUPP(DrawHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDrawHookProcInfo = 0x0000004F
  }; // SPECIAL_CASE_PROCINFO(4) #ifdef __cplusplus
  inline DrawHookUPP NewDrawHookUPP(DrawHookProcPtr userRoutine)
  {
    return (DrawHookUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDrawHookProcInfo, GetCurrentArchitecture());
  }
#else
#define NewDrawHookUPP(userRoutine)   \
  (DrawHookUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppDrawHookProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewHitTestHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  HitTestHookUPP
  NewHitTestHookUPP(HitTestHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppHitTestHookProcInfo = 0x0000005F
  }; // SPECIAL_CASE_PROCINFO(5) #ifdef __cplusplus
  inline HitTestHookUPP NewHitTestHookUPP(HitTestHookProcPtr userRoutine)
  {
    return (HitTestHookUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppHitTestHookProcInfo, GetCurrentArchitecture());
  }
#else
#define NewHitTestHookUPP(userRoutine)                                     \
  (HitTestHookUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppHitTestHookProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewTEFindWordUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TEFindWordUPP
  NewTEFindWordUPP(TEFindWordProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppTEFindWordProcInfo = 0x0000006F
  }; // SPECIAL_CASE_PROCINFO(6) #ifdef __cplusplus
  inline TEFindWordUPP NewTEFindWordUPP(TEFindWordProcPtr userRoutine)
  {
    return (TEFindWordUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppTEFindWordProcInfo, GetCurrentArchitecture());
  }
#else
#define NewTEFindWordUPP(userRoutine)   \
  (TEFindWordUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppTEFindWordProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewTERecalcUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TERecalcUPP
  NewTERecalcUPP(TERecalcProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppTERecalcProcInfo = 0x0000009F
  }; // SPECIAL_CASE_PROCINFO(9) #ifdef __cplusplus
  inline TERecalcUPP NewTERecalcUPP(TERecalcProcPtr userRoutine)
  {
    return (TERecalcUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppTERecalcProcInfo, GetCurrentArchitecture());
  }
#else
#define NewTERecalcUPP(userRoutine)   \
  (TERecalcUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppTERecalcProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewTEDoTextUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TEDoTextUPP
  NewTEDoTextUPP(TEDoTextProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppTEDoTextProcInfo = 0x000000AF
  }; // SPECIAL_CASE_PROCINFO(10) #ifdef __cplusplus
  inline TEDoTextUPP NewTEDoTextUPP(TEDoTextProcPtr userRoutine)
  {
    return (TEDoTextUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppTEDoTextProcInfo, GetCurrentArchitecture());
  }
#else
#define NewTEDoTextUPP(userRoutine)   \
  (TEDoTextUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppTEDoTextProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewTEClickLoopUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TEClickLoopUPP
  NewTEClickLoopUPP(TEClickLoopProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppTEClickLoopProcInfo = 0x0000F812
  }; // register 1_byte:D0 Func(4_bytes:A3) #ifdef __cplusplus
  inline TEClickLoopUPP NewTEClickLoopUPP(TEClickLoopProcPtr userRoutine)
  {
    return (TEClickLoopUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppTEClickLoopProcInfo, GetCurrentArchitecture());
  }
#else
#define NewTEClickLoopUPP(userRoutine)                                     \
  (TEClickLoopUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppTEClickLoopProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

#if CALL_NOT_IN_CARBON
  /**
   *  NewWordBreakUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  WordBreakUPP
  NewWordBreakUPP(WordBreakProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppWordBreakProcInfo = 0x00029812
  }; // register 1_byte:D0 Func(4_bytes:A0, 2_bytes:D0) #ifdef __cplusplus
  inline WordBreakUPP NewWordBreakUPP(WordBreakProcPtr userRoutine)
  {
    return (WordBreakUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppWordBreakProcInfo, GetCurrentArchitecture());
  }
#else
#define NewWordBreakUPP(userRoutine)   \
  (WordBreakUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppWordBreakProcInfo, GetCurrentArchitecture())
#endif
#endif

#endif // CALL_NOT_IN_CARBON
  /**
   *  DisposeHighHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeHighHookUPP(HighHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeHighHookUPP(HighHookUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeHighHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeEOLHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeEOLHookUPP(EOLHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeEOLHookUPP(EOLHookUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeEOLHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeCaretHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeCaretHookUPP(CaretHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeCaretHookUPP(CaretHookUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeCaretHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeWidthHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeWidthHookUPP(WidthHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeWidthHookUPP(WidthHookUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeWidthHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeTextWidthHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeTextWidthHookUPP(TextWidthHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeTextWidthHookUPP(TextWidthHookUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeTextWidthHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeNWidthHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeNWidthHookUPP(NWidthHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeNWidthHookUPP(NWidthHookUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeNWidthHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDrawHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDrawHookUPP(DrawHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDrawHookUPP(DrawHookUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDrawHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeHitTestHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeHitTestHookUPP(HitTestHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeHitTestHookUPP(HitTestHookUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeHitTestHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeTEFindWordUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeTEFindWordUPP(TEFindWordUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeTEFindWordUPP(TEFindWordUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeTEFindWordUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeTERecalcUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeTERecalcUPP(TERecalcUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeTERecalcUPP(TERecalcUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeTERecalcUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeTEDoTextUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeTEDoTextUPP(TEDoTextUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeTEDoTextUPP(TEDoTextUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeTEDoTextUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeTEClickLoopUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeTEClickLoopUPP(TEClickLoopUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeTEClickLoopUPP(TEClickLoopUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeTEClickLoopUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

#if CALL_NOT_IN_CARBON
  /**
   *  DisposeWordBreakUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeWordBreakUPP(WordBreakUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeWordBreakUPP(WordBreakUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeWordBreakUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

#endif // CALL_NOT_IN_CARBON
  /**
   *  InvokeHighHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeHighHookUPP(const Rect *r, TEPtr pTE, HighHookUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeHighHookUPP(const Rect *r, TEPtr pTE, HighHookUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppHighHookProcInfo, r, pTE);
  }
#else
#define InvokeHighHookUPP(r, pTE, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppHighHookProcInfo, (r), (pTE))
#endif
#endif

  /**
   *  InvokeEOLHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeEOLHookUPP(char theChar, TEPtr pTE, TEHandle hTE, EOLHookUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline Boolean InvokeEOLHookUPP(char theChar, TEPtr pTE, TEHandle hTE,
                                  EOLHookUPP userUPP)
  {
    return (Boolean)CALL_THREE_PARAMETER_UPP(userUPP, uppEOLHookProcInfo, theChar,
                                             pTE, hTE);
  }
#else
#define InvokeEOLHookUPP(theChar, pTE, hTE, userUPP)                           \
  (Boolean) CALL_THREE_PARAMETER_UPP((userUPP), uppEOLHookProcInfo, (theChar), \
                                     (pTE), (hTE))
#endif
#endif

  /**
   *  InvokeCaretHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeCaretHookUPP(const Rect *r, TEPtr pTE, CaretHookUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeCaretHookUPP(const Rect *r, TEPtr pTE, CaretHookUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppCaretHookProcInfo, r, pTE);
  }
#else
#define InvokeCaretHookUPP(r, pTE, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppCaretHookProcInfo, (r), (pTE))
#endif
#endif

  /**
   *  InvokeWidthHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  unsigned short
  InvokeWidthHookUPP(unsigned short textLen, unsigned short textOffset,
                     void *textBufferPtr, TEPtr pTE, TEHandle hTE,
                     WidthHookUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline unsigned short InvokeWidthHookUPP(unsigned short textLen,
                                           unsigned short textOffset,
                                           void *textBufferPtr, TEPtr pTE,
                                           TEHandle hTE, WidthHookUPP userUPP)
  {
    return (unsigned short)CALL_FIVE_PARAMETER_UPP(userUPP, uppWidthHookProcInfo,
                                                   textLen, textOffset,
                                                   textBufferPtr, pTE, hTE);
  }
#else
#define InvokeWidthHookUPP(textLen, textOffset, textBufferPtr, pTE, hTE,   \
                           userUPP)                                        \
  (unsigned short)CALL_FIVE_PARAMETER_UPP((userUPP), uppWidthHookProcInfo, \
                                          (textLen), (textOffset),         \
                                          (textBufferPtr), (pTE), (hTE))
#endif
#endif

  /**
   *  InvokeTextWidthHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  unsigned short
  InvokeTextWidthHookUPP(unsigned short textLen, unsigned short textOffset,
                         void *textBufferPtr, TEPtr pTE, TEHandle hTE,
                         TextWidthHookUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline unsigned short InvokeTextWidthHookUPP(unsigned short textLen,
                                               unsigned short textOffset,
                                               void *textBufferPtr, TEPtr pTE,
                                               TEHandle hTE,
                                               TextWidthHookUPP userUPP)
  {
    return (unsigned short)CALL_FIVE_PARAMETER_UPP(
        userUPP, uppTextWidthHookProcInfo, textLen, textOffset, textBufferPtr,
        pTE, hTE);
  }
#else
#define InvokeTextWidthHookUPP(textLen, textOffset, textBufferPtr, pTE, hTE,   \
                               userUPP)                                        \
  (unsigned short)CALL_FIVE_PARAMETER_UPP((userUPP), uppTextWidthHookProcInfo, \
                                          (textLen), (textOffset),             \
                                          (textBufferPtr), (pTE), (hTE))
#endif
#endif

  /**
   *  InvokeNWidthHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  unsigned short
  InvokeNWidthHookUPP(unsigned short styleRunLen, unsigned short styleRunOffset,
                      short slop, short direction, void *textBufferPtr,
                      short *lineStart, TEPtr pTE, TEHandle hTE,
                      NWidthHookUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline unsigned short InvokeNWidthHookUPP(unsigned short styleRunLen,
                                            unsigned short styleRunOffset,
                                            short slop, short direction,
                                            void *textBufferPtr, short *lineStart,
                                            TEPtr pTE, TEHandle hTE,
                                            NWidthHookUPP userUPP)
  {
    return (unsigned short)CALL_EIGHT_PARAMETER_UPP(
        userUPP, uppNWidthHookProcInfo, styleRunLen, styleRunOffset, slop,
        direction, textBufferPtr, lineStart, pTE, hTE);
  }
#else
#define InvokeNWidthHookUPP(styleRunLen, styleRunOffset, slop, direction, \
                            textBufferPtr, lineStart, pTE, hTE, userUPP)  \
  (unsigned short)CALL_EIGHT_PARAMETER_UPP(                               \
      (userUPP), uppNWidthHookProcInfo, (styleRunLen), (styleRunOffset),  \
      (slop), (direction), (textBufferPtr), (lineStart), (pTE), (hTE))
#endif
#endif

  /**
   *  InvokeDrawHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDrawHookUPP(unsigned short textOffset, unsigned short drawLen,
                    void *textBufferPtr, TEPtr pTE, TEHandle hTE,
                    DrawHookUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeDrawHookUPP(unsigned short textOffset, unsigned short drawLen,
                                void *textBufferPtr, TEPtr pTE, TEHandle hTE,
                                DrawHookUPP userUPP)
  {
    CALL_FIVE_PARAMETER_UPP(userUPP, uppDrawHookProcInfo, textOffset, drawLen,
                            textBufferPtr, pTE, hTE);
  }
#else
#define InvokeDrawHookUPP(textOffset, drawLen, textBufferPtr, pTE, hTE, \
                          userUPP)                                      \
  CALL_FIVE_PARAMETER_UPP((userUPP), uppDrawHookProcInfo, (textOffset), \
                          (drawLen), (textBufferPtr), (pTE), (hTE))
#endif
#endif

  /**
   *  InvokeHitTestHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeHitTestHookUPP(unsigned short styleRunLen, unsigned short styleRunOffset,
                       unsigned short slop, void *textBufferPtr, TEPtr pTE,
                       TEHandle hTE, unsigned short *pixelWidth,
                       unsigned short *charOffset, Boolean *pixelInChar,
                       HitTestHookUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline Boolean
  InvokeHitTestHookUPP(unsigned short styleRunLen, unsigned short styleRunOffset,
                       unsigned short slop, void *textBufferPtr, TEPtr pTE,
                       TEHandle hTE, unsigned short *pixelWidth,
                       unsigned short *charOffset, Boolean *pixelInChar,
                       HitTestHookUPP userUPP)
  {
    return (Boolean)CALL_NINE_PARAMETER_UPP(
        userUPP, uppHitTestHookProcInfo, styleRunLen, styleRunOffset, slop,
        textBufferPtr, pTE, hTE, pixelWidth, charOffset, pixelInChar);
  }
#else
#define InvokeHitTestHookUPP(styleRunLen, styleRunOffset, slop, textBufferPtr, \
                             pTE, hTE, pixelWidth, charOffset, pixelInChar,    \
                             userUPP)                                          \
  (Boolean) CALL_NINE_PARAMETER_UPP((userUPP), uppHitTestHookProcInfo,         \
                                    (styleRunLen), (styleRunOffset), (slop),   \
                                    (textBufferPtr), (pTE), (hTE),             \
                                    (pixelWidth), (charOffset), (pixelInChar))
#endif
#endif

  /**
   *  InvokeTEFindWordUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeTEFindWordUPP(unsigned short currentPos, short caller, TEPtr pTE,
                      TEHandle hTE, unsigned short *wordStart,
                      unsigned short *wordEnd, TEFindWordUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeTEFindWordUPP(unsigned short currentPos, short caller,
                                  TEPtr pTE, TEHandle hTE,
                                  unsigned short *wordStart,
                                  unsigned short *wordEnd,
                                  TEFindWordUPP userUPP)
  {
    CALL_SIX_PARAMETER_UPP(userUPP, uppTEFindWordProcInfo, currentPos, caller,
                           pTE, hTE, wordStart, wordEnd);
  }
#else
#define InvokeTEFindWordUPP(currentPos, caller, pTE, hTE, wordStart, wordEnd, \
                            userUPP)                                          \
  CALL_SIX_PARAMETER_UPP((userUPP), uppTEFindWordProcInfo, (currentPos),      \
                         (caller), (pTE), (hTE), (wordStart), (wordEnd))
#endif
#endif

  /**
   *  InvokeTERecalcUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeTERecalcUPP(TEPtr pTE, unsigned short changeLength,
                    unsigned short *lineStart, unsigned short *firstChar,
                    unsigned short *lastChar, TERecalcUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeTERecalcUPP(TEPtr pTE, unsigned short changeLength,
                                unsigned short *lineStart,
                                unsigned short *firstChar,
                                unsigned short *lastChar, TERecalcUPP userUPP)
  {
    CALL_FIVE_PARAMETER_UPP(userUPP, uppTERecalcProcInfo, pTE, changeLength,
                            lineStart, firstChar, lastChar);
  }
#else
#define InvokeTERecalcUPP(pTE, changeLength, lineStart, firstChar, lastChar, \
                          userUPP)                                           \
  CALL_FIVE_PARAMETER_UPP((userUPP), uppTERecalcProcInfo, (pTE),             \
                          (changeLength), (lineStart), (firstChar),          \
                          (lastChar))
#endif
#endif

  /**
   *  InvokeTEDoTextUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeTEDoTextUPP(TEPtr pTE, unsigned short firstChar, unsigned short lastChar,
                    short selector, GrafPtr *currentGrafPort, short *charPosition,
                    TEDoTextUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeTEDoTextUPP(TEPtr pTE, unsigned short firstChar,
                                unsigned short lastChar, short selector,
                                GrafPtr *currentGrafPort, short *charPosition,
                                TEDoTextUPP userUPP)
  {
    CALL_SIX_PARAMETER_UPP(userUPP, uppTEDoTextProcInfo, pTE, firstChar, lastChar,
                           selector, currentGrafPort, charPosition);
  }
#else
#define InvokeTEDoTextUPP(pTE, firstChar, lastChar, selector, currentGrafPort, \
                          charPosition, userUPP)                               \
  CALL_SIX_PARAMETER_UPP((userUPP), uppTEDoTextProcInfo, (pTE), (firstChar),   \
                         (lastChar), (selector), (currentGrafPort),            \
                         (charPosition))
#endif
#endif

  /**
   *  InvokeTEClickLoopUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeTEClickLoopUPP(TEPtr pTE, TEClickLoopUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline Boolean InvokeTEClickLoopUPP(TEPtr pTE, TEClickLoopUPP userUPP)
  {
    return (Boolean)CALL_ONE_PARAMETER_UPP(userUPP, uppTEClickLoopProcInfo, pTE);
  }
#else
#define InvokeTEClickLoopUPP(pTE, userUPP) \
  (Boolean) CALL_ONE_PARAMETER_UPP((userUPP), uppTEClickLoopProcInfo, (pTE))
#endif
#endif

#if CALL_NOT_IN_CARBON
/**
 *  InvokeWordBreakUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InvokeWordBreakUPP(__A0, __D0, __A1)
#endif
  Boolean
  InvokeWordBreakUPP(Ptr text, short charPos, WordBreakUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline Boolean InvokeWordBreakUPP(Ptr text, short charPos,
                                    WordBreakUPP userUPP)
  {
    return (Boolean)CALL_TWO_PARAMETER_UPP(userUPP, uppWordBreakProcInfo, text,
                                           charPos);
  }
#else
#define InvokeWordBreakUPP(text, charPos, userUPP)                          \
  (Boolean) CALL_TWO_PARAMETER_UPP((userUPP), uppWordBreakProcInfo, (text), \
                                   (charPos))
#endif
#endif

#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewHighHookProc(userRoutine) NewHighHookUPP(userRoutine)
#define NewEOLHookProc(userRoutine) NewEOLHookUPP(userRoutine)
#define NewCaretHookProc(userRoutine) NewCaretHookUPP(userRoutine)
#define NewWidthHookProc(userRoutine) NewWidthHookUPP(userRoutine)
#define NewTextWidthHookProc(userRoutine) NewTextWidthHookUPP(userRoutine)
#define NewNWidthHookProc(userRoutine) NewNWidthHookUPP(userRoutine)
#define NewDrawHookProc(userRoutine) NewDrawHookUPP(userRoutine)
#define NewHitTestHookProc(userRoutine) NewHitTestHookUPP(userRoutine)
#define NewTEFindWordProc(userRoutine) NewTEFindWordUPP(userRoutine)
#define NewTERecalcProc(userRoutine) NewTERecalcUPP(userRoutine)
#define NewTEDoTextProc(userRoutine) NewTEDoTextUPP(userRoutine)
#define NewTEClickLoopProc(userRoutine) NewTEClickLoopUPP(userRoutine)
#define NewWordBreakProc(userRoutine) NewWordBreakUPP(userRoutine)
#define CallHighHookProc(userRoutine, r, pTE) \
  InvokeHighHookUPP(r, pTE, userRoutine)
#define CallEOLHookProc(userRoutine, theChar, pTE, hTE) \
  InvokeEOLHookUPP(theChar, pTE, hTE, userRoutine)
#define CallCaretHookProc(userRoutine, r, pTE) \
  InvokeCaretHookUPP(r, pTE, userRoutine)
#define CallWidthHookProc(userRoutine, textLen, textOffset, textBufferPtr, \
                          pTE, hTE)                                        \
  InvokeWidthHookUPP(textLen, textOffset, textBufferPtr, pTE, hTE, userRoutine)
#define CallTextWidthHookProc(userRoutine, textLen, textOffset, textBufferPtr, \
                              pTE, hTE)                                        \
  InvokeTextWidthHookUPP(textLen, textOffset, textBufferPtr, pTE, hTE,         \
                         userRoutine)
#define CallNWidthHookProc(userRoutine, styleRunLen, styleRunOffset, slop, \
                           direction, textBufferPtr, lineStart, pTE, hTE)  \
  InvokeNWidthHookUPP(styleRunLen, styleRunOffset, slop, direction,        \
                      textBufferPtr, lineStart, pTE, hTE, userRoutine)
#define CallDrawHookProc(userRoutine, textOffset, drawLen, textBufferPtr, pTE, \
                         hTE)                                                  \
  InvokeDrawHookUPP(textOffset, drawLen, textBufferPtr, pTE, hTE, userRoutine)
#define CallHitTestHookProc(userRoutine, styleRunLen, styleRunOffset, slop,   \
                            textBufferPtr, pTE, hTE, pixelWidth, charOffset,  \
                            pixelInChar)                                      \
  InvokeHitTestHookUPP(styleRunLen, styleRunOffset, slop, textBufferPtr, pTE, \
                       hTE, pixelWidth, charOffset, pixelInChar, userRoutine)
#define CallTEFindWordProc(userRoutine, currentPos, caller, pTE, hTE,   \
                           wordStart, wordEnd)                          \
  InvokeTEFindWordUPP(currentPos, caller, pTE, hTE, wordStart, wordEnd, \
                      userRoutine)
#define CallTERecalcProc(userRoutine, pTE, changeLength, lineStart, firstChar, \
                         lastChar)                                             \
  InvokeTERecalcUPP(pTE, changeLength, lineStart, firstChar, lastChar,         \
                    userRoutine)
#define CallTEDoTextProc(userRoutine, pTE, firstChar, lastChar, selector, \
                         currentGrafPort, charPosition)                   \
  InvokeTEDoTextUPP(pTE, firstChar, lastChar, selector, currentGrafPort,  \
                    charPosition, userRoutine)
#define CallTEClickLoopProc(userRoutine, pTE) \
  InvokeTEClickLoopUPP(pTE, userRoutine)
#define CallWordBreakProc(userRoutine, text, charPos) \
  InvokeWordBreakUPP(text, charPos, userRoutine)
#endif // CALL_NOT_IN_CARBON
  enum
  {
    // feature bit 4 for TEFeatureFlag no longer in use     teFUseTextServices = 4 // 00010000b
  };

#if OLDROUTINENAMES
// action for the old C "bit (un)set" interface, TEFeatureFlag #define TEBitClear teBitClear
#define TEBitSet teBitSet
#define TEBitTest teBitTest
#define teFAutoScr teFAutoScroll
#define toglBit toggleBit
#endif // OLDROUTINENAMES
  /**
  \brief Obtain handle leading to TextEdit scrap

  <pre>TEScrapHandle returns a handle leading to the TextEdit internal scrap.
On systems later than 4.1, TextEdit uses the desk scrap.
</pre>
* \returns <pre>a 32-bit Handle; the handle leading to the TextEdit scrap.
</pre>
* \note <pre>The global variable TEScrpHandle (at 0x0AB4) contains this
same information.
Probably better than working with the TE scrap itself, you should stick to
calling TEFromScrap , TEToScrap , TECopy, TEPaste , etc.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Handle
  TEScrapHandle(void);

  /**
   *  TEGetScrapLength()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long
  TEGetScrapLength(void);

#if TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#define TEGetScrapLength() ((long)*(unsigned short *)0x0AB0)
#endif
#if CALL_NOT_IN_CARBON
  /**
   *  TEInit()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TEInit(void);

#endif // CALL_NOT_IN_CARBON
  /**
   *  TENew()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TEHandle
  TENew(const Rect *destRect, const Rect *viewRect);

  /**
   *  TEDispose()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEDispose(TEHandle hTE);

  /**
   *  TESetText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TESetText(const void *text, long length, TEHandle hTE);

  /**
   *  TEGetText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  CharsHandle
  TEGetText(TEHandle hTE);

  /**
   *  TEIdle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEIdle(TEHandle hTE);

  /**
   *  TESetSelect()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TESetSelect(long selStart, long selEnd, TEHandle hTE);

  /**
   *  TEActivate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEActivate(TEHandle hTE);

  /**
   *  TEDeactivate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEDeactivate(TEHandle hTE);

  /**
   *  TEKey()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEKey(CharParameter key, TEHandle hTE);

  /**
   *  TECut()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TECut(TEHandle hTE);

  /**
   *  TECopy()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TECopy(TEHandle hTE);

  /**
   *  TEPaste()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEPaste(TEHandle hTE);

  /**
   *  TEDelete()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEDelete(TEHandle hTE);

  /**
   *  TEInsert()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEInsert(const void *text, long length, TEHandle hTE);

  /**
   *  TESetAlignment()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TESetAlignment(short just, TEHandle hTE);

  /**
   *  TEUpdate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEUpdate(const Rect *rUpdate, TEHandle hTE);

  /**
   *  TETextBox()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TETextBox(const void *text, long length, const Rect *box, short just);

  /**
   *  TEScroll()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEScroll(short dh, short dv, TEHandle hTE);

  /**
   *  TESelView()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TESelView(TEHandle hTE);

  /**
   *  TEPinScroll()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEPinScroll(short dh, short dv, TEHandle hTE);

  /**
   *  TEAutoView()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEAutoView(Boolean fAuto, TEHandle hTE);

  /**
   *  TECalText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TECalText(TEHandle hTE);

  /**
   *  TEGetOffset()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  TEGetOffset(Point pt, TEHandle hTE);

  /**
   *  TEGetPoint()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Point
  TEGetPoint(short offset, TEHandle hTE);

  /**
   *  TEClick()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEClick(Point pt, Boolean fExtend, TEHandle h);

  /**
   *  TEStyleNew()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TEHandle
  TEStyleNew(const Rect *destRect, const Rect *viewRect);

  /**
   *  TESetStyleHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TESetStyleHandle(TEStyleHandle theHandle, TEHandle hTE);

  /**
   *  TEGetStyleHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TEStyleHandle
  TEGetStyleHandle(TEHandle hTE);

  /**
   *  TEGetStyle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEGetStyle(short offset, TextStyle *theStyle, short *lineHeight,
             short *fontAscent, TEHandle hTE);

  /**
   *  TEStylePaste()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEStylePaste(TEHandle hTE);

  /**
   *  TESetStyle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TESetStyle(short mode, const TextStyle *newStyle, Boolean fRedraw, TEHandle hTE);

  /**
   *  TEReplaceStyle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEReplaceStyle(short mode, const TextStyle *oldStyle, const TextStyle *newStyle,
                 Boolean fRedraw, TEHandle hTE);

  /**
   *  TEGetStyleScrapHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  StScrpHandle
  TEGetStyleScrapHandle(TEHandle hTE);

  /**
   *  TEStyleInsert()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEStyleInsert(const void *text, long length, StScrpHandle hST, TEHandle hTE);

  /**
   *  TEGetHeight()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long
  TEGetHeight(long endLine, long startLine, TEHandle hTE);

  /**
  \brief TEContinuousStyle Check if a style element is continuous across selection

  <pre>The TEContinuousStyle function, new with System 6.0, gives you
information about the attributes of the current selection.
TEContinuousStyle examines the current selection range and checks if a
specified style attribute is continuous across the current selection range. You
can use this as an aid in toggling styles (see TESetStyle ) or to determine
which, if any, items in your Style... menu should have a check mark.
modeis the address of a short. On entry, it specifies a style operation
mode (see Style Mode ). Bits of this value specify which
characteristics of the selected text should be examined.
Upon return, each bit that was set on entry is been cleared if that
style element was not continuous.
theStyle is the address of a 12-byte TextStyle structure. On entry, it
identifies which characteristics to examine. Upon exit, fields
corresponding to set-bits in mode are filled-in to reflect the values
of any attributes which are continuous.
hTEis a handle leading to an edit record created via TEStylNew .
The mode parameter, which takes the same values as in TESetStyle ,
specifies which attributes should be checked. When TEContinuousStyle
returns, the mode parameter indicates which of the checked attributes is
continuous over the selection range, and the aStyle parameter reflects the
continuous attributes.
TEContinuousStyle returns TRUE if all of the attributes to be checked are
continuous and returns FALSE if they are not. In other words, if the mode
parameter is the same before and after the call, then TEContinuousStyle
returns TRUE.
Listing below illustrates how TEContinuousStyle is useful for marking
the Style menu items so they correspond to the current selection.
Marking the Style menu items so they correspond to the current selection
shortmode;
TextStyle aStyle;
TEHandle myTE;
MenuHandle styleMenu;
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  TEContinuousStyle(short *mode, TextStyle *aStyle, TEHandle hTE);

  /**
   *  TEUseStyleScrap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TEUseStyleScrap(long rangeStart, long rangeEnd, StScrpHandle newStyles,
                  Boolean fRedraw, TEHandle hTE);

  /**
  \brief Install custom handlers for TextEdit bottleneck routines

  <pre>The TECustomHook procedure lets your application customize the features
of TextEdit by setting the TextEdit hooks .
TECustomHook installs a custom routine for TextEdit EOL handling, text
drawing, text measuring, and hit-testing.  It returns the address of the
original handler to provide a way to chain functions.
whichspecifies which bottleneck routine to install. It is one of:
intEOLHook 0Calculates text width
intDrawHook 1Draws text
intWidthHook 2Measures text
intHitTestHook 3See which character corresponds to a screen pixel
intNWidthHook 6Width measurement hook nWIDTHHook
intTextWidthHook 7Width measurement hook TextWidthHook
addris the address of a ProcPtr. On entry, it is the address of your
custom routine to take over the function identified by whichHook .
Upon return, it will contain the address of the routine that normally
handles the function.
hTEis a handle leading to an edit record created via TEStylNew .
You specify your customized hook in the addr parameter. When
TECustomHook returns, the addr parameter contains the address of the
previous hook specified by the which parameter. This address is returned so
that hooks can be daisy-chained. The two new hooks, nWIDTHHook and
TextWidthHook , specified by the intNWidthHook and intTextWidthHook
constants, are described in “TextEdit Width Hooks ”.
Two integer fields of the edit record , not used for their original purposes but
still named recalBack and recalLines , combine to hold a handle to the
TextEdit dispatch record , which contains a list of TextEdit hooks . (See the
figure in the TextEdit Data Structures description for an illustration of the
edit record , the dispatch record, and all the TextEdit data structures.) Each
edit record has its own set of such routines to provide for maximum
flexibility. You should always use the TECustomHook procedure to change
these hooks instead of modifying the edit record directly.
Warning: Do not simply copy the recalBack and recalLines fields to
another edit record . If you do, a duplicate handle to the initial
TextEdit dispatch record is stored in recalBack and recalLines in your copy
of the record. When one of the edit record s is disposed, the handle stored in
the copy becomes invalid, and TextEdit can crash if the copy is used.
EOLHook, WIDTHHook , nWIDTHHook , TextWidthHook , DRAWHook , and
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  TECustomHook(TEIntHook which, UniversalProcPtr *addr, TEHandle hTE);

  /**
  \brief Obtains a count of style runs in a range of text

  <pre>The TENumStyles function returns the number of style changes contained in
the given range, counting one for the start of the range. Note that this number
does not necessarily represent the number of unique styles for the range
because some styles may be repeated. For unstyled edit record s,
TENumStyles always returns 1.
TENumStyles returns the count of style changes (including one for the
initial style) existing across the specified range. Use this to calculate the
amount of memory that will be needed in a large TECut or TECopy operation.
rangeStart and...
rangeEnd identify which text to examine.
hTEis a handle leading to an edit record created via TENew or
TEStylNew .
The rangeStart and rangeEnd parameters indicate the range. The text
containing the range is specified by the hTE parameter, a handle to the
edit record .
You can use TENumStyles to calculate the amount of memory that would be
required if TECut or TECopy were called. Since the style scrap record is
linear in nature, with one element for each style change, you can multiply the
result that TENumStyles returns by SizeOf( ScrpSTElement ) and add 2 to get
the amount of memory needed.
</pre>
* \returns <pre>a long integer; the number of style changes across the range.
</pre>
* \note <pre>The actual amount of memory used by styles in a Cut or Copy
operation will be the return value * sizeof( ScrpSTElement ) +2.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  long
  TENumStyles(long rangeStart, long rangeEnd, TEHandle hTE);

  /**
  \brief Return last setting of a specified feature's bit
  \param    feature enable/disable inline input
\param    action like feature, using bit constants
  <pre>The TEFeatureFlag function allows you to enable outline highlighting and
text buffering in your application. You can also use this function to disable
inline input in a particular edit record and to enable several new features that
have been provided so that inline input works correctly with TextEdit .
Note: To test for the availability of these features, you can call the Gestalt
function with the gestaltTextEditVersion selector. A result of gestaltTE4 or
greater returned in the response parameter indicates that outline highlighting
and text buffering are available. A result of gestaltTE5 or greater returned in
the response parameter indicates that the two inline input features are
available. (For details, see the description about
Determining the Version of TextEdit .
The inline input features are also available on version 6.0.7 systems with
non-Roman script systems installed. However, there is no Gestalt constant
that indicates this availability.
The feature parameter allows you to disable inline input in a particular
edit record or to specify the features you want to enable-outline highlighting,
text buffering, and features provided for inline input in TextEdit . The action
parameter lets you enable and disable these features by using the TEBitSet and
TEBitClear constants and lets you test the settings of these feature bits by
using the TEBitTest constant. The hTE parameter is a handle to the edit record .
The TEFeatureFlag function returns the previous setting of the feature's
bit, either TEBitSet or TEBitClear .
Note that there is also a constant named TEFeatureFlag which has the following
values:
The feature or bit definitions for TEFeatureFlag are:
teFAutoScr = 0, // 00000001b
teFTextBuffering = 1, // 00000010b
teFOutlineHilite = 2, // 00000100b
teFInlineInput = 3, // 00001000b
teFUseTextServices = 4, // 00010000b
The action for the new "bit (un)set" interface, TEFeatureFlag is:
TEBitClear = 0,
TEBitSet = 1// set the selector bit
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
       *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
  short
  TEFeatureFlag(short feature, short action, TEHandle hTE);

  /**
   *  TEGetHiliteRgn()
   *

   *    \non_carbon_cfm   in DragLib 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr TEGetHiliteRgn(RgnHandle region, TEHandle hTE);

  /**
   *  TESetScrapLength()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void TESetScrapLength(long length);

  /**
   *  TEFromScrap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr TEFromScrap(void);

  /**
   *  TEToScrap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr TEToScrap(void);

  /**
   *  TESetClickLoop()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void TESetClickLoop(TEClickLoopUPP clikProc, TEHandle hTE);

#if CALL_NOT_IN_CARBON
  /**
   *  TESetWordBreak()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void TESetWordBreak(WordBreakUPP wBrkProc, TEHandle hTE);

#endif // CALL_NOT_IN_CARBON
  /**
   *  TEGetDoTextHook()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TEDoTextUPP
  TEGetDoTextHook(void);

  /**
   *  TESetDoTextHook()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void TESetDoTextHook(TEDoTextUPP value);

  /**
   *  TEGetRecalcHook()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TERecalcUPP
  TEGetRecalcHook(void);

  /**
   *  TESetRecalcHook()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void TESetRecalcHook(TERecalcUPP value);

  /**
   *  TEGetFindWordHook()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TEFindWordUPP
  TEGetFindWordHook(void);

  /**
   *  TESetFindWordHook()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void TESetFindWordHook(TEFindWordUPP value);

  /**
   *  TEGetScrapHandle()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Handle
  TEGetScrapHandle(void);

  /**
   *  TESetScrapHandle()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void TESetScrapHandle(Handle value);

  // LMGetWordRedraw and LMSetWordRedraw were previously in LowMem.h  // Deprecated for Carbon on MacOS X                                 // This lomem is no longer used by the implementation of TextEdit   // on MacOS X, so setting it will have no effect.
  /**
   *LMGetWordRedraw() *

           *    \non_carbon_cfm in InterfaceLib 7.1 and
       later
           *    \carbon_lib in CarbonLib 1.0 and
       later
           *    \mac_os_x in version 10.0 and
       later*/
  UInt8 LMGetWordRedraw(void);

  /**
   *  LMSetWordRedraw()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void LMSetWordRedraw(UInt8 value);

#if CALL_NOT_IN_CARBON
  /**
   *  teclick()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void teclick(Point *pt, Boolean fExtend, TEHandle h);

#endif // CALL_NOT_IN_CARBON
#if OLDROUTINENAMES
#if CALL_NOT_IN_CARBON
#define TESetJust(just, hTE) TESetAlignment(just, hTE)
#define TextBox(text, length, box, just) TETextBox(text, length, box, just)
#define TEStylNew(destRect, viewRect) TEStyleNew(destRect, viewRect)
#define SetStylHandle(theHandle, hTE) TESetStyleHandle(theHandle, hTE)
#define SetStyleHandle(theHandle, hTE) TESetStyleHandle(theHandle, hTE)
#define GetStylHandle(hTE) TEGetStyleHandle(hTE)
#define GetStyleHandle(hTE) TEGetStyleHandle(hTE)
#define TEStylPaste(hTE) TEStylePaste(hTE)
#define GetStylScrap(hTE) TEGetStyleScrapHandle(hTE)
#define GetStyleScrap(hTE) TEGetStyleScrapHandle(hTE)
#define SetStylScrap(rangeStart, rangeEnd, newStyles, redraw, hTE) \
  TEUseStyleScrap(rangeStart, rangeEnd, newStyles, redraw, hTE)
#define SetStyleScrap(rangeStart, rangeEnd, newStyles, redraw, hTE) \
  TEUseStyleScrap(rangeStart, rangeEnd, newStyles, redraw, hTE)
#define TEStylInsert(text, length, hST, hTE) \
  TEStyleInsert(text, length, hST, hTE)
#define TESetScrapLen(length) TESetScrapLength(length)
#define TEGetScrapLen() TEGetScrapLength()
#define SetClikLoop(clikProc, hTE) TESetClickLoop(clikProc, hTE)
#define SetWordBreak(wBrkProc, hTE) TESetWordBreak(wBrkProc, hTE)
#endif // CALL_NOT_IN_CARBON #endif // OLDROUTINENAMES
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

#endif // __TEXTEDIT__