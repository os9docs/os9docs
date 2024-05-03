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
    struct Palette
    {
        short pmEntries;       /**entries in pmTable*/
        short pmDataFields[7]; /**private fields*/
        ColorInfo pmInfo[1];
    };
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
    InitPalettes(void);

    /**
     *  NewPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    PaletteHandle
    NewPalette(short entries, CTabHandle srcColors, short srcUsage,
               short srcTolerance);

    /**
     *  GetNewPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    PaletteHandle
    GetNewPalette(short PaletteID);

    /**
     *  DisposePalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposePalette(PaletteHandle srcPalette);

    /**
     *  ActivatePalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    ActivatePalette(WindowRef srcWindow);

    /**
     *  SetPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    SetPalette(WindowRef dstWindow, PaletteHandle srcPalette, Boolean cUpdates);

    /**
     *  NSetPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    NSetPalette(WindowRef dstWindow, PaletteHandle srcPalette, short nCUpdates);

    /**
     *  GetPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    PaletteHandle
    GetPalette(WindowRef srcWindow);

    /**
     *  CopyPalette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    CopyPalette(PaletteHandle srcPalette, PaletteHandle dstPalette, short srcEntry,
                short dstEntry, short dstLength);

    /**
     *  PmForeColor()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    PmForeColor(short dstEntry);

    /**
     *  PmBackColor()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    PmBackColor(short dstEntry);

    /**
     *  AnimateEntry()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    AnimateEntry(WindowRef dstWindow, short dstEntry, const RGBColor *srcRGB);

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
                      short dstEntry, short dstLength);

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
    GetEntryColor(PaletteHandle srcPalette, short srcEntry, RGBColor *dstRGB);

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
    SetEntryColor(PaletteHandle dstPalette, short dstEntry, const RGBColor *srcRGB);

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
                  short *dstTolerance);

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
                  short srcTolerance);

    /**
     *  CTab2Palette()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    CTab2Palette(CTabHandle srcCTab, PaletteHandle dstPalette, short srcUsage,
                 short srcTolerance);

    /**
     *  Palette2CTab()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    Palette2CTab(PaletteHandle srcPalette, CTabHandle dstCTab);

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
    Entry2Index(short entry);

    /**
     *  RestoreDeviceClut()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    RestoreDeviceClut(GDHandle gd);

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
    MacResizePalette(PaletteHandle p, short size);

    /**
     *  SaveFore()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    SaveFore(ColorSpec *c);

    /**
     *  SaveBack()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    SaveBack(ColorSpec *c);

    /**
     *  RestoreFore()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    RestoreFore(const ColorSpec *c);

    /**
     *  RestoreBack()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    RestoreBack(const ColorSpec *c);

    /**
     *  SetDepth()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SetDepth(GDHandle gd, short depth, short whichFlags, short flags);

    /**
     *  HasDepth()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    short
    HasDepth(GDHandle gd, short depth, short whichFlags, short flags);

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
    PMgrVersion(void);

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
    SetPaletteUpdates(PaletteHandle p, short updates);

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
    GetPaletteUpdates(PaletteHandle p);

    /**
     *  GetGray()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    Boolean
    GetGray(GDHandle device, const RGBColor *backGround, RGBColor *foreGround);

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