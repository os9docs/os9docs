/**
     \file       Palettes.h

    \brief   Palette Manager Interfaces.

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1987-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Managers

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __PALETTES__
#define __PALETTES__

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
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
        pmCourteous = 0, /**Record use of color on each device touched.*/
        pmDithered = 0x0001,
        pmTolerant =
            0x0002, /**render ciRGB if ciTolerance is exceeded by best match.*/
        pmAnimated =
            0x0004, /**reserve an index on each device touched and render ciRGB.*/
        pmExplicit =
            0x0008, /**no reserve, no render, no record; stuff index into port.*/
        pmWhite = 0x0010,
        pmBlack = 0x0020,
        pmInhibitG2 = 0x0100,
        pmInhibitC2 = 0x0200,
        pmInhibitG4 = 0x0400,
        pmInhibitC4 = 0x0800,
        pmInhibitG8 = 0x1000,
        pmInhibitC8 = 0x2000, /** NSetPalette Update Constants */
        pmNoUpdates = 0x8000, /**no updates*/
        pmBkUpdates = 0xA000, /**background updates only*/
        pmFgUpdates = 0xC000, /**foreground updates only*/
        pmAllUpdates = 0xE000 /**all updates*/
    };

    struct ColorInfo
    {
        RGBColor ciRGB;        /**true RGB values*/
        short ciUsage;         /**color usage*/
        short ciTolerance;     /**tolerance value*/
        short ciDataFields[3]; /**private fields*/
    };
    typedef struct ColorInfo ColorInfo;
    typedef ColorInfo *ColorInfoPtr;
    typedef ColorInfoPtr *ColorInfoHandle;
    /**
    <pre>
     * \note <pre>The Palette data structure is identical in format to the resource 'pltt' and
    new color palettes are generally created using 'pltt' through the
    GetNewPalette procedure. The NewPalette routine is used to make a
    palette from inside an application. After either routine is called,
    SetPalette is used to render the palette on the monitor while
    DisposePalette removes the entire structure. Use ActivatePalette
    after changing a palette with any Palette Manager routine, it is also
    automatically called by Window Manager each time a window opens,
    closes, moves or is brought to the front. GetPalette will give you a handle
    to a particular window's palette.
    </pre>
     * \copyright THINK Reference © 1991-1992 Symantec Corporation
    */
    struct Palette
    {
        short pmEntries;      /**< Total pmTable entries*/
        short pmDataFields[]; /**< Array of private fields for internal*/
        ColorInfo pmInfo[];   /**< *n or more ColorInfo  records*/
    } Palette;                /**< +* nvariable-length structure*/

    typedef struct Palette Palette;
    typedef Palette *PalettePtr;
    typedef PalettePtr *PaletteHandle;
    /**
     *  InitPalettes()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InitPalettes(void) ONEWORDINLINE(0xAA90);

    /**
     *  NewPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    PaletteHandle
    NewPalette(short entries, CTabHandle srcColors, short srcUsage,
               short srcTolerance) ONEWORDINLINE(0xAA91);

    /**
     *  GetNewPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    PaletteHandle
    GetNewPalette(short PaletteID) ONEWORDINLINE(0xAA92);

    /**
     *  DisposePalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposePalette(PaletteHandle srcPalette) ONEWORDINLINE(0xAA93);

    /**
     *  ActivatePalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    ActivatePalette(WindowRef srcWindow) ONEWORDINLINE(0xAA94);

    /**
     *  SetPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    SetPalette(WindowRef dstWindow, PaletteHandle srcPalette, Boolean cUpdates)
        ONEWORDINLINE(0xAA95);

    /**
     *  NSetPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    NSetPalette(WindowRef dstWindow, PaletteHandle srcPalette, short nCUpdates)
        ONEWORDINLINE(0xAA95);

    /**
     *  GetPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    PaletteHandle
    GetPalette(WindowRef srcWindow) ONEWORDINLINE(0xAA96);

    /**
     *  CopyPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    CopyPalette(PaletteHandle srcPalette, PaletteHandle dstPalette, short srcEntry,
                short dstEntry, short dstLength) ONEWORDINLINE(0xAAA1);

    /**
     *  PmForeColor()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    PmForeColor(short dstEntry) ONEWORDINLINE(0xAA97);

    /**
     *  PmBackColor()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    PmBackColor(short dstEntry) ONEWORDINLINE(0xAA98);

    /**
     *  AnimateEntry()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    AnimateEntry(WindowRef dstWindow, short dstEntry, const RGBColor *srcRGB)
        ONEWORDINLINE(0xAA99);

/**
 *  [Mac]AnimatePalette()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacAnimatePalette AnimatePalette
#endif
    void
    MacAnimatePalette(WindowRef dstWindow, CTabHandle srcCTab, short srcIndex,
                      short dstEntry, short dstLength) ONEWORDINLINE(0xAA9A);

    /**
    \brief Access a palette entry from an application

    <pre>GetEntryColor lets your application open up a particular color in a source
palette so the SetEntryColor procedure can use it to make a change to a window
color.
srcPalette is the palette with colors you can use for making a change.
srcEntry is the particular color you've chosen to substitute for the old
color.
*destRGB is the specified RGB value of the old color about to be changed.
Returns: none
</pre>
* \note <pre> GetEntryColor does the preparation work in making a new color available.
Later, SetEntryColor can come along and make the change.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
    GetEntryColor(PaletteHandle srcPalette, short srcEntry, RGBColor *dstRGB)
        ONEWORDINLINE(0xAA9B);

    /**
    \brief Change the color of a palette entry from an application

    <pre>SetEntryColor lets your application change an individual target color in a
destination palette.
destPalette is the palette containing the color you want to change.
destEntry is the particular color you've targeted for change.
srcRGB is the specific RGB value of the new color about to be switched in
for the old.
Returns: none
</pre>
* \note <pre> SetEntryColor marks a change in a color palette from old to new color. As
yet, however, no visible change occurs in the color environment. That event
takes place at the next ActivatePalette call. The change comes quickly, though,
since a changed entry is marked as such and a palette update occurs even when
no other changes that would normally precipitate a color environment change
have taken place.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
    SetEntryColor(PaletteHandle dstPalette, short dstEntry, const RGBColor *srcRGB)
        ONEWORDINLINE(0xAA9C);

    /**
    \brief Access the usage and tolerance fields of one palette color

    <pre>GetEntryUsage lets your application open up a target color so it can be modified
by SetEntryUsage .
srcPalette is the palette containing the color values you want to copy.
srcEntry is the particular color whose values you want.
destUsage is pmCourteous , pmExplicit , pmTolerant , or pmAnimated
*destTolerance is the tolerance level of the color about to be changed.
Returns: none
</pre>
* \note <pre> GetEntryUsage does the preparation work in making new color qualities
available. Later, SetEntryUsage can come along and make the change.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
    GetEntryUsage(PaletteHandle srcPalette, short srcEntry, short *dstUsage,
                  short *dstTolerance) ONEWORDINLINE(0xAA9D);

    /**
    \brief Change the usage and tolerance of a palette entry

    <pre>SetEntryUsage lets your application alter a single palette entry's color usage
and tolerance.
destPalette is the palette containing the color you want to change.
destEntry is the particular color you've targeted for change.
srcUsage is pmCourteous , pmExplicit , pmTolerant or pmAnimated .
srcTolerance specification for tolerance level in new palette entry.
Returns: none
</pre>
* \note <pre> SetEntryUsage marks a change in a color palette entry from old to new usage
and tolerance. As yet, however, no visible change occurs in the color
environment. That event takes place at the next ActivatePalette call. The
change comes quickly, though, since a changed entry is marked as such and a
palette update occurs even when no other changes that would normally
precipitate a color environment change have taken place. Use this routine after
creating a new palette with NewPalette or modifying one with CTab2Palette
where the usage and tolerance fields carry the same value if you want to
customize your palette.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
    SetEntryUsage(PaletteHandle dstPalette, short dstEntry, short srcUsage,
                  short srcTolerance) ONEWORDINLINE(0xAA9E);

    /**
     *  CTab2Palette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    CTab2Palette(CTabHandle srcCTab, PaletteHandle dstPalette, short srcUsage,
                 short srcTolerance) ONEWORDINLINE(0xAA9F);

    /**
     *  Palette2CTab()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    Palette2CTab(PaletteHandle srcPalette, CTabHandle dstCTab)
        ONEWORDINLINE(0xAAA0);

    /**
    \brief Return the index for an entry in current palette

    <pre>Given an entry number, Entry2Index returns the index for that entry in
the current grafPort 's palette on the current device.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    long
    Entry2Index(short entry) TWOWORDINLINE(0x7000, 0xAAA2);

    /**
     *  RestoreDeviceClut()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    RestoreDeviceClut(GDHandle gd) TWOWORDINLINE(0x7002, 0xAAA2);

/**
 *  [Mac]ResizePalette()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacResizePalette ResizePalette
#endif
    void
    MacResizePalette(PaletteHandle p, short size) TWOWORDINLINE(0x7003, 0xAAA2);

    /**
     *  SaveFore()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    SaveFore(ColorSpec *c) THREEWORDINLINE(0x303C, 0x040D, 0xAAA2);

    /**
     *  SaveBack()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    SaveBack(ColorSpec *c) THREEWORDINLINE(0x303C, 0x040E, 0xAAA2);

    /**
     *  RestoreFore()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    RestoreFore(const ColorSpec *c) THREEWORDINLINE(0x303C, 0x040F, 0xAAA2);

    /**
     *  RestoreBack()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    RestoreBack(const ColorSpec *c) THREEWORDINLINE(0x303C, 0x0410, 0xAAA2);

    /**
     *  SetDepth()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SetDepth(GDHandle gd, short depth, short whichFlags, short flags)
        THREEWORDINLINE(0x303C, 0x0A13, 0xAAA2);

    /**
     *  HasDepth()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    short
    HasDepth(GDHandle gd, short depth, short whichFlags, short flags)
        THREEWORDINLINE(0x303C, 0x0A14, 0xAAA2);

    /**
    \brief Get version of the Palette Manager

    <pre>The PMgrVersion function returns an integer specifying the version
number of the currently executing Palette Manager . Returned values may be
as follows.
Value Description
0x0202 System 7.0 or later
0x0201 System 6.0.5
0x0200 Original 32-Bit QuickDraw system extension
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    short
    PMgrVersion(void) TWOWORDINLINE(0x7015, 0xAAA2);

    /**
    \brief SetPaletteUpdates Set the update attribute of a palette

    <pre>The SetPaletteUpdates procedure sets the update attribute of a palette.
pis the palette being updated
updatesone of the update attributes described for the NSetPalette
procedure.
Returns: none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
    SetPaletteUpdates(PaletteHandle p, short updates)
        THREEWORDINLINE(0x303C, 0x0616, 0xAAA2);

    /**
    \brief GetPaletteUpdates Return the update attribute of a palette

    <pre>The GetPaletteUpdates function returns the update attribute of a palette.
pis the palette being queried
Returns: one of the update attributes described for the NSetPalette
procedure
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    short
    GetPaletteUpdates(PaletteHandle p) THREEWORDINLINE(0x303C, 0x0417, 0xAAA2);

    /**
     *  GetGray()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    Boolean
    GetGray(GDHandle device, const RGBColor *backGround, RGBColor *foreGround)
        THREEWORDINLINE(0x303C, 0x0C19, 0xAAA2);

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

#endif /** __PALETTES__ */
* /*/*/ * /*/*/ */*/