/**
     \file       ATSUnicode.h

    \brief   Public interfaces for Apple Type Services for Unicode Imaging

    \introduced_in  Mac OS 9 / Carbon
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1997-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup AppleTypeServices

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __ATSUNICODE__
#define __ATSUNICODE__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __MACMEMORY__
#include <MacMemory.h>
#endif

#ifndef __ATSLAYOUTTYPES__
#include <ATSLayoutTypes.h>
#endif

#ifndef __FONTS__
#include <Fonts.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __SFNTTYPES__
#include <SFNTTypes.h>
#endif

#ifndef __SFNTLAYOUTTYPES__
#include <SFNTLayoutTypes.h>
#endif

#ifndef __TEXTCOMMON__
#include <TextCommon.h>
#endif

#ifndef __ATSTYPES__
#include <ATSTypes.h>
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

    /********************************/
    //  Types and related constants
    /********************************/
    /**
       UniCharArrayHandle and UniCharArrayOffset are defined in the
       TextCommon interface file.
    */

    /**
        ATSUTextMeasurement is specific to ATSUI in that measurement
        quantities are in fractional Fixed format instead of shorts
        used in QuickDraw Text.  This provides exact outline metrics and
        line specifications such as line width, ascent, descent, and so on.
    */
    typedef Fixed ATSUTextMeasurement;
    /**
        ATSUFontID indicates a particular font family and face.
        ATSUFontID's are not guaranteed to remain constant across
        reboots.  Clients should use the font's unique name to
        get a font token to store in documents which is
        guaranteed to remain constant across reboots.
    */
    typedef FMFont ATSUFontID;
    /**