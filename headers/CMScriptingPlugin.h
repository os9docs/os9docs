/**
     \file       CMScriptingPlugin.h

    \brief   ColorSync Scripting Plugin API

    \introduced_in  ColorSync 2.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1998-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup ColorSync

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CMSCRIPTINGPLUGIN__
#define __CMSCRIPTINGPLUGIN__

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __CMAPPLICATION__
#include <CMApplication.h>
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
        /* ColorSync Scripting AppleEvent Errors */
        cmspInvalidImageFile = -4220, /* Plugin cannot handle this image file type */
        cmspInvalidImageSpace =
            -4221,                       /* Plugin cannot create an image file of this colorspace */
        cmspInvalidProfileEmbed = -4222, /* Specific invalid profile errors */
        cmspInvalidProfileSource = -4223,
        cmspInvalidProfileDest = -4224,
        cmspInvalidProfileProof = -4225,
        cmspInvalidProfileLink = -4226
    };

    /**** embedFlags field  ****/
    /* reserved for future use: currently 0 */

    /**** matchFlags field  ****/
    enum
    {
        cmspFavorEmbeddedMask =
            0x00000001 /* if bit 0 is 0 then use srcProf profile, if 1 then use
                          profile embedded in image if present*/
    };

    /**** scripting plugin entry points  ****/
    typedef CALLBACK_API_C(CMError, ValidateImageProcPtr)(const FSSpec *spec);
    typedef CALLBACK_API_C(CMError, GetImageSpaceProcPtr)(const FSSpec *spec,
                                                          OSType *space);
    typedef CALLBACK_API_C(CMError, ValidateSpaceProcPtr)(const FSSpec *spec,
                                                          OSType *space);
    typedef CALLBACK_API_C(CMError, EmbedImageProcPtr)(const FSSpec *specFrom,
                                                       const FSSpec *specInto,
                                                       CMProfileRef embedProf,
                                                       UInt32 embedFlags);
    typedef CALLBACK_API_C(CMError, UnembedImageProcPtr)(const FSSpec *specFrom,
                                                         const FSSpec *specInto);
    typedef CALLBACK_API_C(CMError, MatchImageProcPtr)(
        const FSSpec *specFrom, const FSSpec *specInto, UInt32 qual,
        UInt32 srcIntent, CMProfileRef srcProf, CMProfileRef dstProf,
        CMProfileRef prfProf, UInt32 matchFlags);
    typedef CALLBACK_API_C(CMError, CountImageProfilesProcPtr)(const FSSpec *spec,
                                                               UInt32 *count);
    typedef CALLBACK_API_C(CMError, GetIndImageProfileProcPtr)(const FSSpec *spec,
                                                               UInt32 index,
                                                               CMProfileRef *prof);
    typedef CALLBACK_API_C(CMError, SetIndImageProfileProcPtr)(
        const FSSpec *specFrom, const FSSpec *specInto, UInt32 index,
        CMProfileRef prof, UInt32 embedFlags);
    /**** CSScriptingLib API  ****/

    /**
     *  CMValidImage()
     *

     *    \non_carbon_cfm   in CSScriptingLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMValidImage(const FSSpec *spec);

    /**
     *  CMGetImageSpace()
     *

     *    \non_carbon_cfm   in CSScriptingLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetImageSpace(const FSSpec *spec, OSType *space);

    /**
     *  CMEmbedImage()
     *

     *    \non_carbon_cfm   in CSScriptingLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMEmbedImage(const FSSpec *specFrom, const FSSpec *specInto, Boolean repl,
                 CMProfileRef embProf);

    /**
     *  CMUnembedImage()
     *

     *    \non_carbon_cfm   in CSScriptingLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMUnembedImage(const FSSpec *specFrom, const FSSpec *specInto, Boolean repl);

    /**
     *  CMMatchImage()
     *

     *    \non_carbon_cfm   in CSScriptingLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMMatchImage(const FSSpec *specFrom, const FSSpec *specInto, Boolean repl,
                 UInt32 qual, CMProfileRef srcProf, UInt32 srcIntent,
                 CMProfileRef dstProf);

    /**
     *  CMProofImage()
     *

     *    \non_carbon_cfm   in CSScriptingLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMProofImage(const FSSpec *specFrom, const FSSpec *specInto, Boolean repl,
                 UInt32 qual, CMProfileRef srcProf, UInt32 srcIntent,
                 CMProfileRef dstProf, CMProfileRef prfProf);

    /**
     *  CMLinkImage()
     *

     *    \non_carbon_cfm   in CSScriptingLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMLinkImage(const FSSpec *specFrom, const FSSpec *specInto, Boolean repl,
                UInt32 qual, CMProfileRef lnkProf, UInt32 lnkIntent);

    /**
     *  CMCountImageProfiles()
     *

     *    \non_carbon_cfm   in CSScriptingLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMCountImageProfiles(const FSSpec *spec, UInt32 *count);

    /**
     *  CMGetIndImageProfile()
     *

     *    \non_carbon_cfm   in CSScriptingLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetIndImageProfile(const FSSpec *spec, UInt32 index, CMProfileRef *prof);

    /**
     *  CMSetIndImageProfile()
     *

     *    \non_carbon_cfm   in CSScriptingLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetIndImageProfile(const FSSpec *specFrom, const FSSpec *specInto,
                         Boolean repl, UInt32 index, CMProfileRef prof);

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

#endif /* __CMSCRIPTINGPLUGIN__ */
