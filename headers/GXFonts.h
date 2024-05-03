/**
     \file       GXFonts.h

    \brief   QuickDraw GX font routine interfaces.

    \introduced_in  Quickdraw GX 1.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup QuickDraw

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __GXFONTS__
#define __GXFONTS__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __GXMATH__
#include <GXMath.h>
#endif

#ifndef __GXTYPES__
#include <GXTypes.h>
#endif

#ifndef __SCALERSTREAMTYPES__
#include <ScalerStreamTypes.h>
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
     *  GXNewFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFont
    GXNewFont(gxFontStorageTag storage, gxFontStorageReference reference,
              gxFontAttribute attributes);

    /**
     *  GXGetFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontStorageTag
    GXGetFont(gxFont fontID, gxFontStorageReference *reference,
              gxFontAttribute *attributes);

    /**
     *  GXFindFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFont
    GXFindFont(gxFontStorageTag storage, gxFontStorageReference reference,
               gxFontAttribute *attributes);

    /**
     *  GXSetFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetFont(gxFont fontID, gxFontStorageTag storage,
              gxFontStorageReference reference, gxFontAttribute attributes);

    /**
     *  GXDisposeFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeFont(gxFont fontID);

    /**
     *  GXChangedFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXChangedFont(gxFont fontID);

    /**
     *  GXGetFontFormat()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontFormatTag
    GXGetFontFormat(gxFont fontID);

    /**
     *  GXGetDefaultFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFont
    GXGetDefaultFont(void);

    /**
     *  GXSetDefaultFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFont
    GXSetDefaultFont(gxFont fontID);

    /**
     *  GXFindFonts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXFindFonts(gxFont familyID, gxFontName name, gxFontPlatform platform,
                gxFontScript script, gxFontLanguage language, long length,
                const unsigned char text[], long index, long count, gxFont fonts[]);

    /**
     *  GXCountFontGlyphs()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXCountFontGlyphs(gxFont fontID);

    /**
     *  GXCountFontTables()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXCountFontTables(gxFont fontID);

    /**
     *  GXGetFontTable()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetFontTable(gxFont fontID, long index, void *tableData,
                   gxFontTableTag *tableTag);

    /**
     *  GXFindFontTable()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXFindFontTable(gxFont fontID, gxFontTableTag tableTag, void *tableData,
                    long *index);

    /**
     *  GXGetFontTableParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetFontTableParts(gxFont fontID, long index, long offset, long length,
                        void *tableData, gxFontTableTag *tableTag);

    /**
     *  GXFindFontTableParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXFindFontTableParts(gxFont fontID, gxFontTableTag tableTag, long offset,
                         long length, void *tableData, long *index);

    /**
     *  GXSetFontTable()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXSetFontTable(gxFont fontID, long index, gxFontTableTag tableTag, long length,
                   const void *tableData);

    /**
     *  GXSetFontTableParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXSetFontTableParts(gxFont fontID, long index, gxFontTableTag tableTag,
                        long offset, long oldLength, long newLength,
                        const void *tableData);

    /**
     *  GXDeleteFontTable()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXDeleteFontTable(gxFont fontID, long index, gxFontTableTag tableTag);

    /**
     *  GXCountFontNames()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXCountFontNames(gxFont fontID);

    /**
     *  GXGetFontName()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetFontName(gxFont fontID, long index, gxFontName *name,
                  gxFontPlatform *platform, gxFontScript *script,
                  gxFontLanguage *language, unsigned char text[]);

    /**
     *  GXFindFontName()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXFindFontName(gxFont fontID, gxFontName name, gxFontPlatform platform,
                   gxFontScript script, gxFontLanguage language,
                   unsigned char text[], long *index);

    /**
     *  GXSetFontName()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXSetFontName(gxFont fontID, gxFontName name, gxFontPlatform platform,
                  gxFontScript script, gxFontLanguage language, long length,
                  const unsigned char text[]);

    /**
     *  GXDeleteFontName()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXDeleteFontName(gxFont fontID, long index, gxFontName name,
                     gxFontPlatform platform, gxFontScript script,
                     gxFontLanguage language);

    /**
     *  GXNewFontNameID()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontName
    GXNewFontNameID(gxFont fontID);

    /**
     *  GXCountFontEncodings()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXCountFontEncodings(gxFont fontID);

    /**
     *  GXGetFontEncoding()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontPlatform
    GXGetFontEncoding(gxFont fontID, long index, gxFontScript *script,
                      gxFontLanguage *language);

    /**
     *  GXFindFontEncoding()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXFindFontEncoding(gxFont fontID, gxFontPlatform platform, gxFontScript script,
                       gxFontLanguage language);

    /**
     *  GXApplyFontEncoding()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXApplyFontEncoding(gxFont fontID, long index, long *length,
                        const unsigned char text[], long count,
                        unsigned short glyphs[], char was16Bit[]);

    /**
     *  GXCountFontVariations()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXCountFontVariations(gxFont fontID);

    /**
     *  GXFindFontVariation()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXFindFontVariation(gxFont fontID, gxFontVariationTag variationTag,
                        Fixed *minValue, Fixed *defaultValue, Fixed *maxValue,
                        gxFontName *name);

    /**
     *  GXGetFontVariation()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontVariationTag
    GXGetFontVariation(gxFont fontID, long index, Fixed *minValue,
                       Fixed *defaultValue, Fixed *maxValue, gxFontName *name);

    /**
     *  GXCountFontInstances()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXCountFontInstances(gxFont fontID);

    /**
     *  GXGetFontInstance()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontName
    GXGetFontInstance(gxFont fontID, long index, gxFontVariation variation[]);

    /**
     *  GXSetFontInstance()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXSetFontInstance(gxFont fontID, long index, gxFontName name,
                      const gxFontVariation variation[]);

    /**
     *  GXDeleteFontInstance()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXDeleteFontInstance(gxFont fontID, long index, gxFontName name);

    /**
     *  GXCountFontDescriptors()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXCountFontDescriptors(gxFont fontID);

    /**
     *  GXGetFontDescriptor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontDescriptorTag
    GXGetFontDescriptor(gxFont fontID, long index, Fixed *descriptorValue);

    /**
     *  GXFindFontDescriptor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXFindFontDescriptor(gxFont fontID, gxFontDescriptorTag descriptorTag,
                         Fixed *descriptorValue);

    /**
     *  GXSetFontDescriptor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXSetFontDescriptor(gxFont fontID, long index,
                        gxFontDescriptorTag descriptorTag, Fixed descriptorValue);

    /**
     *  GXDeleteFontDescriptor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXDeleteFontDescriptor(gxFont fontID, long index,
                           gxFontDescriptorTag descriptorTag);

    /**
     *  GXCountFontFeatures()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXCountFontFeatures(gxFont fontID);

    /**
     *  GXGetFontFeature()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontName
    GXGetFontFeature(gxFont fontID, long index, gxFontFeatureFlag *flags,
                     long *settingCount, gxFontFeatureSetting settings[],
                     gxFontFeature *feature);

    /**
     *  GXFindFontFeature()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontName
    GXFindFontFeature(gxFont fontID, gxFontFeature feature,
                      gxFontFeatureFlag *flags, long *settingCount,
                      gxFontFeatureSetting settings[], long *index);

    /**
     *  GXGetFontDefaultFeatures()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetFontDefaultFeatures(gxFont fontID, gxRunFeature features[]);

    /**
     *  GXFlattenFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXFlattenFont(gxFont source, scalerStream *stream, gxSpoolBlock *block);

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

#endif // __GXFONTS__
