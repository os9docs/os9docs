/**
     \file       ScalerStreamTypes.h

    \brief   Scaler streaming data structures and constants for OFA 1.x

    \introduced_in  Quickdraw GX 1.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Quickdraw

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __SCALERSTREAMTYPES__
#define __SCALERSTREAMTYPES__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __SFNTTYPES__
#include <SFNTTypes.h>
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

// ScalerStream input/output types enum {
  cexec68K = 0x00000001,
  truetypeStreamType = 0x00000001,
  type1StreamType = 0x00000002,
  type3StreamType = 0x00000004,
  type42StreamType = 0x00000008,
  type42GXStreamType = 0x00000010,
  portableStreamType = 0x00000020,
  flattenedStreamType = 0x00000040,
  cidType2StreamType = 0x00000080,
  cidType0StreamType = 0x00000100,
  type1CFFStreamType = 0x00000200,
  evenOddModifierStreamType = 0x00008000,
  eexecBinaryModifierStreamType =
      0x00010000, // encrypted portion of Type1Stream to be binary   unicodeMappingModifierStreamType =
      0x00020000, // encrypted portion of Type1Stream to be binary 
      (long)0xFFFFF000 // 16 bits for Apple, 4 bits for scaler };
// include glyph ID to unicode mapping info for PDF 
// Possible streamed font formats typedef // for scaler's internal use 
enum {
  downloadStreamAction // 16 bits for Apple, 4 bits for scaler 
      1, // Transmit font data to a 7-bit ASCII destination   fontSizeQueryStreamAction =
      2, // Estimate in-printer memory used if the font were downloaded   encodingOnlyStreamAction = 3, // Transmit only the encoding for the font   prerequisiteQueryStreamAction =
// Possible streamed font formats 
      6, // Return information regarding support for variation streaming   variationPSOperatorStreamAction =
      7 // Transmit Postscript code necessary to effect variation of a font };
// Transmit the (possibly sparse) font data 
typedef long scalerStreamAction;
enum {// Transmit font data to a 7-bit ASCII destination 
  selectAllVariations =
      -1 // Estimate in-printer memory used if the font were downloaded 
// Transmit only the encoding for the font 
struct scalerPrerequisiteItem {
  long en// Return a list of prerequisite items needed for the font 
                            (Pascal // Transmit a specified prerequisite item 
};
typedef s// Return information regarding support for variation streaming 
struct scalerStream {
  const // Transmit Postscript code necessary to effect variation of a font 
      memorySize;      // -> Worst case memory use (vm) in printer or as sfnt   long variationCount; // <- The number of variations, or selectAllVariations   const void *variations; /* <- A pointer to an array of the variations
                             (gxFontVariation) */
  union {
    // Normal font streaming information    struct {
      const unsigned short
         // Special variationCount value meaning include all variation data 
                          desired/supplied */
      char *name;      // <->    The printer font name to use/used (C string)     } font;

    // Used to obtain a l// Shorthand tag identifying the item 
      long size;  /* ->  // Worst case vm in printer item requires 
                     prerequisites)*/
      void *list; /* <- Pointer to client block to hold list (nil = list size
                     query only) */
    } prerequisiteQuery;

    long prerequisiteItem; /* // <- private reference for client 
                              // <- e.g. Postscript printer name (C string) 
// <->    Data stream formats desired/supplied 
    long variationQueryResult;// <-     What action to take 
                                */
  } info;// -> Worst case memory use (vm) in printer or as sfnt 
};// <- The number of variations, or selectAllVariations 
typedef struct scalerStream scalerStream;
struct scalerStreamData {
  long hexFlag;   /* Indicates that the data is to be interpreted as hex, versus
    // Normal font streaming information
  long byteCount; // Number of bytes in the data being streamed   const void *data; // Pointer to the data being streamed };
typedef struct scalerStreamData scalerStreamData;
// <- Intention is * unsigned short[256] 
#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PAC// <->    The printer font name to use/used (C string) 
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pra// Used to obtain a list of prerequisites from the scaler
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __SCALERSTREAMTYPES__ // Number of bytes in the data being streamed 
// Pointer to the data being streamed 
// __SCALERSTREAMTYPES__ 
