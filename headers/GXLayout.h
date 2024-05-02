/**
     \file       GXLayout.h

    \brief   QuickDraw GX layout routine interfaces.

    \introduced_in  Quickdraw GX 1.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup QuickDraw

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __GXLAYOUT__
#define __GXLAYOUT__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __GXTYPES__
#include <GXTypes.h>
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

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma push
#pragma pointers_in_D0
#endif

#if CALL_NOT_IN_CARBON
/**
 *  GXNewLayout()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewLayout(long textRunCount, const short textRunLengths[], const void *text[],
            long styleRunCount, const short styleRunLengths[],
            const gxStyle styles[], long levelRunCount,
            const short levelRunLengths[], const short levels[],
            const gxLayoutOptions *layoutOptions, const gxPoint *position)
    THREEWORDINLINE(0x303C, 0x0000, 0xA832);

/**
 *  GXGetLayout()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetLayout(gxShape layout, void *text, long *styleRunCount,
            short styleRunLengths[], gxStyle styles[], long *levelRunCount,
            short levelRunLengths[], short levels[],
            gxLayoutOptions *layoutOptions, gxPoint *position)
    THREEWORDINLINE(0x303C, 0x0001, 0xA832);

/**
 *  GXSetLayout()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetLayout(gxShape layout, long textRunCount, const short textRunLengths[],
            const void *text[], long styleRunCount,
            const short styleRunLengths[], const gxStyle styles[],
            long levelRunCount, const short levelRunLengths[],
            const short levels[], const gxLayoutOptions *layoutOptions,
            const gxPoint *position) THREEWORDINLINE(0x303C, 0x0002, 0xA832);

/**
 *  GXDrawLayout()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawLayout(long textRunCount, const short textRunLengths[],
             const void *text[], long styleRunCount,
             const short styleRunLengths[], const gxStyle styles[],
             long levelRunCount, const short levelRunLengths[],
             const short levels[], const gxLayoutOptions *layoutOptions,
             const gxPoint *position) THREEWORDINLINE(0x303C, 0x0003, 0xA832);

/**
 *  GXSetLayoutParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetLayoutParts(gxShape layout, gxByteOffset oldStartOffset,
                 gxByteOffset oldEndOffset, long newTextRunCount,
                 const short newTextRunLengths[], const void *newText[],
                 long newStyleRunCount, const short newStyleRunLengths[],
                 const gxStyle newStyles[], long newLevelRunCount,
                 const short newLevelRunLengths[], const short newLevels[])
    THREEWORDINLINE(0x303C, 0x0004, 0xA832);

/**
 *  GXSetLayoutShapeParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetLayoutShapeParts(gxShape layout, gxByteOffset startOffset,
                      gxByteOffset endOffset, gxShape insert)
    THREEWORDINLINE(0x303C, 0x0005, 0xA832);

/**
 *  GXGetLayoutParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetLayoutParts(gxShape layout, gxByteOffset startOffset,
                 gxByteOffset endOffset, void *text, long *styleRunCount,
                 short styleRunLengths[], gxStyle styles[], long *levelRunCount,
                 short levelRunLengths[], short levels[])
    THREEWORDINLINE(0x303C, 0x0006, 0xA832);

/**
 *  GXGetLayoutShapeParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetLayoutShapeParts(gxShape layout, gxByteOffset startOffset,
                      gxByteOffset endOffset, gxShape dest)
    THREEWORDINLINE(0x303C, 0x0007, 0xA832);

/**
 *  GXGetLayoutGlyphs()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetLayoutGlyphs(gxShape layout, gxGlyphcode *glyphs, gxPoint positions[],
                  long advance[], gxPoint tangents[], long *runCount,
                  short styleRuns[], gxStyle glyphStyles[])
    THREEWORDINLINE(0x303C, 0x0008, 0xA832);

/**
 *  GXHitTestLayout()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxByteOffset
GXHitTestLayout(gxShape layout, const gxPoint *hitDown,
                gxHighlightType highlightType, gxLayoutHitInfo *hitInfo,
                gxShape hitTrackingArea)
    THREEWORDINLINE(0x303C, 0x0009, 0xA832);

/**
 *  GXGetLayoutHighlight()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetLayoutHighlight(gxShape layout, gxByteOffset startOffset,
                     gxByteOffset endOffset, gxHighlightType highlightType,
                     gxShape highlight) THREEWORDINLINE(0x303C, 0x000A, 0xA832);

/**
 *  GXGetLayoutVisualHighlight()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetLayoutVisualHighlight(gxShape layout, gxByteOffset startOffset,
                           long startLeadingEdge, gxByteOffset endOffset,
                           long endLeadingEdge, gxHighlightType highlightType,
                           gxShape highlight)
    THREEWORDINLINE(0x303C, 0x000B, 0xA832);

/**
 *  GXGetLayoutCaret()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetLayoutCaret(gxShape layout, gxByteOffset offset,
                 gxHighlightType highlightType, gxCaretType caretType,
                 gxShape caret) THREEWORDINLINE(0x303C, 0x000C, 0xA832);

/**
 *  GXGetLayoutBreakOffset()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxByteOffset
GXGetLayoutBreakOffset(gxShape layout, gxByteOffset startOffset,
                       Fixed lineWidth, long hyphenationCount,
                       const gxByteOffset hyphenationPoints[],
                       Boolean *startIsStaked, gxByteOffset *priorStake,
                       gxByteOffset *nextStake)
    THREEWORDINLINE(0x303C, 0x000D, 0xA832);

/**
 *  GXGetLayoutRangeWidth()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
GXGetLayoutRangeWidth(gxShape layout, gxByteOffset startOffset,
                      gxByteOffset endOffset, gxShape supplementaryText)
    THREEWORDINLINE(0x303C, 0x000E, 0xA832);

/**
 *  GXNewLayoutFromRange()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewLayoutFromRange(gxShape layout, gxByteOffset startOffset,
                     gxByteOffset endOffset,
                     const gxLayoutOptions *layoutOptions,
                     gxShape supplementaryText)
    THREEWORDINLINE(0x303C, 0x000F, 0xA832);

/**
 *  GXGetCaretAngleArea()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetCaretAngleArea(gxShape layout, const gxPoint *hitPoint,
                    gxHighlightType highlightType, gxShape caretArea,
                    short *returnedRise, short *returnedRun)
    THREEWORDINLINE(0x303C, 0x0010, 0xA832);

/**
 *  GXGetStyleBaselineDeltas()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXGetStyleBaselineDeltas(gxStyle baseStyle, gxBaselineType baseType,
                         gxBaselineDeltas returnedDeltas)
    THREEWORDINLINE(0x303C, 0x0011, 0xA832);

/**
 *  GXGetRightVisualOffset()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxByteOffset
GXGetRightVisualOffset(gxShape layout, gxByteOffset currentOffset)
    THREEWORDINLINE(0x303C, 0x0012, 0xA832);

/**
 *  GXGetLeftVisualOffset()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxByteOffset
GXGetLeftVisualOffset(gxShape layout, gxByteOffset currentOffset)
    THREEWORDINLINE(0x303C, 0x0013, 0xA832);

/**
 *  GXGetCompoundCharacterLimits()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXGetCompoundCharacterLimits(gxShape layout, gxByteOffset trial,
                             gxByteOffset *minOffset, gxByteOffset *maxOffset,
                             Boolean *onBoundary)
    THREEWORDINLINE(0x303C, 0x0014, 0xA832);

/**
 *  GXGetOffsetGlyphs()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXGetOffsetGlyphs(gxShape layout, gxByteOffset trial, long leadingEdge,
                  gxLayoutOffsetState *offsetState, unsigned short *firstGlyph,
                  unsigned short *secondGlyph)
    THREEWORDINLINE(0x303C, 0x0015, 0xA832);

/**
 *  GXGetGlyphOffset()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXGetGlyphOffset(gxShape layout, long trial, long onLeftTop,
                 gxByteOffset *offset, Boolean *leadingEdge,
                 Boolean *wasRealCharacter)
    THREEWORDINLINE(0x303C, 0x0016, 0xA832);

/**
 *  GXGetLayoutSpan()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXGetLayoutSpan(gxShape layout, Fixed *lineAscent, Fixed *lineDescent)
    THREEWORDINLINE(0x303C, 0x0017, 0xA832);

/**
 *  GXSetLayoutSpan()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetLayoutSpan(gxShape layout, Fixed lineAscent, Fixed lineDescent)
    THREEWORDINLINE(0x303C, 0x0018, 0xA832);

/**
 *  GXGetLayoutJustificationGap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
GXGetLayoutJustificationGap(gxShape layout)
    THREEWORDINLINE(0x303C, 0x0279, 0xA832);

/**
 *  GXGetLayoutJustificationFactors()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXGetLayoutJustificationFactors(gxShape layout, Fixed constrainedFactors[],
                                Fixed unconstrainedFactors[])
    THREEWORDINLINE(0x303C, 0x027A, 0xA832);

/**
 *  GXSetStyleRunControls()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleRunControls(gxStyle target, const gxRunControls *runControls)
    THREEWORDINLINE(0x303C, 0x0019, 0xA832);

/**
 *  GXSetStyleRunPriorityJustOverride()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleRunPriorityJustOverride(
    gxStyle target,
    const gxPriorityJustificationOverride *priorityJustificationOverride)
    THREEWORDINLINE(0x303C, 0x001A, 0xA832);

/**
 *  GXSetStyleRunGlyphJustOverrides()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleRunGlyphJustOverrides(
    gxStyle target, long count,
    const gxGlyphJustificationOverride glyphJustificationOverrides[])
    THREEWORDINLINE(0x303C, 0x001B, 0xA832);

/**
 *  GXSetStyleRunGlyphSubstitutions()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleRunGlyphSubstitutions(gxStyle target, long count,
                                const gxGlyphSubstitution glyphSubstitutions[])
    THREEWORDINLINE(0x303C, 0x001C, 0xA832);

/**
 *  GXSetStyleRunFeatures()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleRunFeatures(gxStyle target, long count,
                      const gxRunFeature runFeatures[])
    THREEWORDINLINE(0x303C, 0x001D, 0xA832);

/**
 *  GXSetStyleRunKerningAdjustments()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleRunKerningAdjustments(gxStyle target, long count,
                                const gxKerningAdjustment kerningAdjustments[])
    THREEWORDINLINE(0x303C, 0x001E, 0xA832);

/**
 *  GXSetShapeRunControls()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeRunControls(gxShape target, const gxRunControls *runControls)
    THREEWORDINLINE(0x303C, 0x001F, 0xA832);

/**
 *  GXSetShapeRunPriorityJustOverride()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeRunPriorityJustOverride(
    gxShape target,
    const gxPriorityJustificationOverride *priorityJustificationOverride)
    THREEWORDINLINE(0x303C, 0x0020, 0xA832);

/**
 *  GXSetShapeRunGlyphJustOverrides()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeRunGlyphJustOverrides(
    gxShape target, long count,
    const gxGlyphJustificationOverride glyphJustificationOverrides[])
    THREEWORDINLINE(0x303C, 0x0021, 0xA832);

/**
 *  GXSetShapeRunGlyphSubstitutions()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeRunGlyphSubstitutions(gxShape target, long count,
                                const gxGlyphSubstitution glyphSubstitutions[])
    THREEWORDINLINE(0x303C, 0x0022, 0xA832);

/**
 *  GXSetShapeRunFeatures()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeRunFeatures(gxShape target, long count,
                      const gxRunFeature runFeatures[])
    THREEWORDINLINE(0x303C, 0x0023, 0xA832);

/**
 *  GXSetShapeRunKerningAdjustments()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeRunKerningAdjustments(gxShape target, long count,
                                const gxKerningAdjustment kerningAdjustments[])
    THREEWORDINLINE(0x303C, 0x0024, 0xA832);

/**
 *  GXGetStyleRunControls()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetStyleRunControls(gxStyle source, gxRunControls *runControls)
    THREEWORDINLINE(0x303C, 0x0025, 0xA832);

/**
 *  GXGetStyleRunPriorityJustOverride()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetStyleRunPriorityJustOverride(
    gxStyle source,
    gxPriorityJustificationOverride *priorityJustificationOverride)
    THREEWORDINLINE(0x303C, 0x0026, 0xA832);

/**
 *  GXGetStyleRunGlyphJustOverrides()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetStyleRunGlyphJustOverrides(
    gxStyle source, gxGlyphJustificationOverride glyphJustificationOverrides[])
    THREEWORDINLINE(0x303C, 0x0027, 0xA832);

/**
 *  GXGetStyleRunGlyphSubstitutions()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetStyleRunGlyphSubstitutions(gxStyle source,
                                gxGlyphSubstitution glyphSubstitutions[])
    THREEWORDINLINE(0x303C, 0x0028, 0xA832);

/**
 *  GXGetStyleRunFeatures()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetStyleRunFeatures(gxStyle source, gxRunFeature runFeatures[])
    THREEWORDINLINE(0x303C, 0x0029, 0xA832);

/**
 *  GXGetStyleRunKerningAdjustments()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetStyleRunKerningAdjustments(gxStyle source,
                                gxKerningAdjustment kerningAdjustments[])
    THREEWORDINLINE(0x303C, 0x002A, 0xA832);

/**
 *  GXGetShapeRunControls()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeRunControls(gxShape source, gxRunControls *runControls)
    THREEWORDINLINE(0x303C, 0x002B, 0xA832);

/**
 *  GXGetShapeRunPriorityJustOverride()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeRunPriorityJustOverride(
    gxShape source,
    gxPriorityJustificationOverride *priorityJustificationOverride)
    THREEWORDINLINE(0x303C, 0x002C, 0xA832);

/**
 *  GXGetShapeRunGlyphJustOverrides()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeRunGlyphJustOverrides(
    gxShape source, gxGlyphJustificationOverride glyphJustificationOverrides[])
    THREEWORDINLINE(0x303C, 0x002D, 0xA832);

/**
 *  GXGetShapeRunGlyphSubstitutions()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeRunGlyphSubstitutions(gxShape source,
                                gxGlyphSubstitution glyphSubstitutions[])
    THREEWORDINLINE(0x303C, 0x002E, 0xA832);

/**
 *  GXGetShapeRunFeatures()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeRunFeatures(gxShape source, gxRunFeature runFeatures[])
    THREEWORDINLINE(0x303C, 0x002F, 0xA832);

/**
 *  GXGetShapeRunKerningAdjustments()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeRunKerningAdjustments(gxShape source,
                                gxKerningAdjustment kerningAdjustments[])
    THREEWORDINLINE(0x303C, 0x0030, 0xA832);

#endif /* CALL_NOT_IN_CARBON */

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma pop
#endif

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

#endif /* __GXLAYOUT__ */
