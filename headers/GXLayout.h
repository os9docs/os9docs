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
                const gxLayoutOptions *layoutOptions, const gxPoint *position);

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
                gxLayoutOptions *layoutOptions, gxPoint *position);

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
                const gxPoint *position);

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
                 const gxPoint *position);

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
                     const short newLevelRunLengths[], const short newLevels[]);

    /**
     *  GXSetLayoutShapeParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetLayoutShapeParts(gxShape layout, gxByteOffset startOffset,
                          gxByteOffset endOffset, gxShape insert);

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
                     short levelRunLengths[], short levels[]);

    /**
     *  GXGetLayoutShapeParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXGetLayoutShapeParts(gxShape layout, gxByteOffset startOffset,
                          gxByteOffset endOffset, gxShape dest);

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
                      short styleRuns[], gxStyle glyphStyles[]);

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
                    gxShape hitTrackingArea);

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
                         gxShape highlight);

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
                               gxShape highlight);

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
                     gxShape caret);

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
                           gxByteOffset *nextStake);

    /**
     *  GXGetLayoutRangeWidth()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    GXGetLayoutRangeWidth(gxShape layout, gxByteOffset startOffset,
                          gxByteOffset endOffset, gxShape supplementaryText);

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
                         gxShape supplementaryText);

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
                        short *returnedRise, short *returnedRun);

    /**
     *  GXGetStyleBaselineDeltas()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXGetStyleBaselineDeltas(gxStyle baseStyle, gxBaselineType baseType,
                             gxBaselineDeltas returnedDeltas);

    /**
     *  GXGetRightVisualOffset()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxByteOffset
    GXGetRightVisualOffset(gxShape layout, gxByteOffset currentOffset);

    /**
     *  GXGetLeftVisualOffset()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxByteOffset
    GXGetLeftVisualOffset(gxShape layout, gxByteOffset currentOffset);

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
                                 Boolean *onBoundary);

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
                      unsigned short *secondGlyph);

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
                     Boolean *wasRealCharacter);

    /**
     *  GXGetLayoutSpan()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXGetLayoutSpan(gxShape layout, Fixed *lineAscent, Fixed *lineDescent);

    /**
     *  GXSetLayoutSpan()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetLayoutSpan(gxShape layout, Fixed lineAscent, Fixed lineDescent);

    /**
     *  GXGetLayoutJustificationGap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    GXGetLayoutJustificationGap(gxShape layout);

    /**
     *  GXGetLayoutJustificationFactors()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXGetLayoutJustificationFactors(gxShape layout, Fixed constrainedFactors[],
                                    Fixed unconstrainedFactors[]);

    /**
     *  GXSetStyleRunControls()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleRunControls(gxStyle target, const gxRunControls *runControls);

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
        const gxPriorityJustificationOverride *priorityJustificationOverride);

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
        const gxGlyphJustificationOverride glyphJustificationOverrides[]);

    /**
     *  GXSetStyleRunGlyphSubstitutions()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleRunGlyphSubstitutions(gxStyle target, long count,
                                    const gxGlyphSubstitution glyphSubstitutions[]);

    /**
     *  GXSetStyleRunFeatures()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleRunFeatures(gxStyle target, long count,
                          const gxRunFeature runFeatures[]);

    /**
     *  GXSetStyleRunKerningAdjustments()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleRunKerningAdjustments(gxStyle target, long count,
                                    const gxKerningAdjustment kerningAdjustments[]);

    /**
     *  GXSetShapeRunControls()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeRunControls(gxShape target, const gxRunControls *runControls);

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
        const gxPriorityJustificationOverride *priorityJustificationOverride);

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
        const gxGlyphJustificationOverride glyphJustificationOverrides[]);

    /**
     *  GXSetShapeRunGlyphSubstitutions()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeRunGlyphSubstitutions(gxShape target, long count,
                                    const gxGlyphSubstitution glyphSubstitutions[]);

    /**
     *  GXSetShapeRunFeatures()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeRunFeatures(gxShape target, long count,
                          const gxRunFeature runFeatures[]);

    /**
     *  GXSetShapeRunKerningAdjustments()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeRunKerningAdjustments(gxShape target, long count,
                                    const gxKerningAdjustment kerningAdjustments[]);

    /**
     *  GXGetStyleRunControls()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetStyleRunControls(gxStyle source, gxRunControls *runControls);

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
        gxPriorityJustificationOverride *priorityJustificationOverride);

    /**
     *  GXGetStyleRunGlyphJustOverrides()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetStyleRunGlyphJustOverrides(
        gxStyle source, gxGlyphJustificationOverride glyphJustificationOverrides[]);

    /**
     *  GXGetStyleRunGlyphSubstitutions()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetStyleRunGlyphSubstitutions(gxStyle source,
                                    gxGlyphSubstitution glyphSubstitutions[]);

    /**
     *  GXGetStyleRunFeatures()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetStyleRunFeatures(gxStyle source, gxRunFeature runFeatures[]);

    /**
     *  GXGetStyleRunKerningAdjustments()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetStyleRunKerningAdjustments(gxStyle source,
                                    gxKerningAdjustment kerningAdjustments[]);

    /**
     *  GXGetShapeRunControls()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeRunControls(gxShape source, gxRunControls *runControls);

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
        gxPriorityJustificationOverride *priorityJustificationOverride);

    /**
     *  GXGetShapeRunGlyphJustOverrides()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeRunGlyphJustOverrides(
        gxShape source, gxGlyphJustificationOverride glyphJustificationOverrides[]);

    /**
     *  GXGetShapeRunGlyphSubstitutions()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeRunGlyphSubstitutions(gxShape source,
                                    gxGlyphSubstitution glyphSubstitutions[]);

    /**
     *  GXGetShapeRunFeatures()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeRunFeatures(gxShape source, gxRunFeature runFeatures[]);

    /**
     *  GXGetShapeRunKerningAdjustments()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeRunKerningAdjustments(gxShape source,
                                    gxKerningAdjustment kerningAdjustments[]);

#endif // CALL_NOT_IN_CARBON
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

#endif // __GXLAYOUT__ // __GXLAYOUT__
