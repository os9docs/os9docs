/**
     \file       QDOffscreen.h

    \brief   Quickdraw Offscreen GWorld Interfaces.

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Quickdraw3D

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QDOFFSCREEN__
#define __QDOFFSCREEN__

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
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

enum {
  pixPurgeBit = 0,
  noNewDeviceBit = 1,
  useTempMemBit = 2,
  keepLocalBit = 3,
  useDistantHdwrMemBit = 4,
  useLocalHdwrMemBit = 5,
  pixelsPurgeableBit = 6,
  pixelsLockedBit = 7,
  mapPixBit = 16,
  newDepthBit = 17,
  alignPixBit = 18,
  newRowBytesBit = 19,
  reallocPixBit = 20,
  clipPixBit = 28,
  stretchPixBit = 29,
  ditherPixBit = 30,
  gwFlagErrBit = 31
};

enum {
  pixPurge = 1L << pixPurgeBit,
  noNewDevice = 1L << noNewDeviceBit,
  useTempMem = 1L << useTempMemBit,
  keepLocal = 1L << keepLocalBit,
  useDistantHdwrMem = 1L << useDistantHdwrMemBit,
  useLocalHdwrMem = 1L << useLocalHdwrMemBit,
  pixelsPurgeable = 1L << pixelsPurgeableBit,
  pixelsLocked = 1L << pixelsLockedBit,
  kAllocDirectDrawSurface = 1L << 14,
  mapPix = 1L << mapPixBit,
  newDepth = 1L << newDepthBit,
  alignPix = 1L << alignPixBit,
  newRowBytes = 1L << newRowBytesBit,
  reallocPix = 1L << reallocPixBit,
  clipPix = 1L << clipPixBit,
  stretchPix = 1L << stretchPixBit,
  ditherPix = 1L << ditherPixBit,
  gwFlagErr = 1L << gwFlagErrBit
};

typedef unsigned long GWorldFlags;
/* Type definition of a GWorldPtr */
typedef CGrafPtr GWorldPtr;
/**
 *  NewGWorld()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(QDErr)
NewGWorld(GWorldPtr *offscreenGWorld, short PixelDepth, const Rect *boundsRect,
          CTabHandle cTable, /* can be NULL */
          GDHandle aGDevice, /* can be NULL */
          GWorldFlags flags) FOURWORDINLINE(0x203C, 0x0016, 0x0000, 0xAB1D);

/* GDevice attribute bits for Carbon and QuickTime 3.0*/
enum {
  deviceIsIndirect = (1L << 0),
  deviceNeedsLock = (1L << 1),
  deviceIsStatic = (1L << 2),
  deviceIsExternalBuffer = (1L << 3),
  deviceIsDDSurface = (1L << 4),
  deviceIsDCISurface = (1L << 5),
  deviceIsGDISurface = (1L << 6),
  deviceIsAScreen = (1L << 7),
  deviceIsOverlaySurface = (1L << 8)
};

#if TARGET_OS_WIN32
#if CALL_NOT_IN_CARBON
/**
 *  GetGDeviceSurface()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void *)
GetGDeviceSurface(GDHandle gdh);

/**
 *  GetGDeviceAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(unsigned long)
GetGDeviceAttributes(GDHandle gdh);

/* to allocate non-mac-rgb GWorlds use QTNewGWorld (ImageCompression.h) */
/**
 *  NewGWorldFromHBITMAP()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(QDErr)
NewGWorldFromHBITMAP(GWorldPtr *offscreenGWorld, CTabHandle cTable,
                     GDHandle aGDevice, GWorldFlags flags, void *newHBITMAP,
                     void *newHDC);

#endif /* CALL_NOT_IN_CARBON */

#endif /* TARGET_OS_WIN32 */

/**
 *  NewGWorldFromPtr()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(QDErr)
NewGWorldFromPtr(GWorldPtr *offscreenGWorld, unsigned long PixelFormat,
                 const Rect *boundsRect, CTabHandle cTable, GDHandle aGDevice,
                 GWorldFlags flags, Ptr newBuffer, long rowBytes);


			/** 
			\brief Lock the offscreen buffer in memory for duration of a draw 
			
			<pre>LockPixels should be called before drawing to or from an offscreen graphics
world. In the pm parameter pass the pixel map handle returned from a
GetGWorldPixMap call. LockPixels locks the offscreen buffer in memory
for the duration of the drawing.
If the offscreen buffer is purgeable and has been purged, LockPixels
returns FALSE to signal that no drawing can be made to the buffer memory. At
that point, the application should either call UpdateGWorld to reallocate the
buffer or draw directly in the window it represents.
If the offscreen buffer hasn't been purged or is not purgeable, LockPixels
returns TRUE.
As soon as the drawing is completed, you should call UnlockPixels .
</pre>
 * \returns <pre> a Boolean value; It will be one of:
TRUEbuffer is in memory (either not purged or not purgeable)
FALSEbuffer has been purged
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
LockPixels(PixMapHandle pm) FOURWORDINLINE(0x203C, 0x0004, 0x0001, 0xAB1D);


			/** 
			\brief Unlock the buffer used by an offscreen graphics world 
			
			<pre>UnlockPixels unlocks the offscreen buffer. Call UnlockPixels as soon as
the application finishes drawing to or from the offscreen pixel map. You don't
need to call UnlockPixels if LockPixels returned FALSE, because
LockPixels doesn't lock purged pixels. However, calling UnlockPixels on
purged pixels does no harm.
</pre>
 * \returns <pre> an Error Code . It is one of:
noErr(0) No error
paramErr (-50) Illegal parameter
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
UnlockPixels(PixMapHandle pm) FOURWORDINLINE(0x203C, 0x0004, 0x0002, 0xAB1D);

/**
 *  UpdateGWorld()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(GWorldFlags)
UpdateGWorld(GWorldPtr *offscreenGWorld, short pixelDepth,
             const Rect *boundsRect, CTabHandle cTable,
             GDHandle aGDevice, /* can be NULL */
             GWorldFlags flags) FOURWORDINLINE(0x203C, 0x0016, 0x0003, 0xAB1D);


			/** 
			\brief Dispose of a GDevice structure and substructures 
			
			<pre>If an offscreen graphics device was created, DisposeGWorld disposes of its
GDevice structure and substructures.
Call DisposeGWorld only when the application no longer needs the offscreen
buffer. If the current device was the offscreen device attached to
offscreenGWorld, the current device is reset to the device stored in the global
variable MainDevice .
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
DisposeGWorld(GWorldPtr offscreenGWorld)
    FOURWORDINLINE(0x203C, 0x0004, 0x0004, 0xAB1D);


			/** 
			\brief Get the current graphics world 
			
			<pre>GetGWorld returns the current graphics world in the port and gdh
parameters. The port parameter is set to the current port, which can be of
type GrafPtr, CGrafPtr or GWorldPtr . The gdh parameter is set to the current
device.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
GetGWorld(CGrafPtr *port, GDHandle *gdh)
    FOURWORDINLINE(0x203C, 0x0008, 0x0005, 0xAB1D);


			/** 
			\brief Set the current graphics world 
			
			<pre>SetGWorld sets the current graphics world. SetGWorld can be used with a
port parameter of type GrafPtr. CGrafPtr , or GWorldPtr (with proper type
coercion).
If the port parameter is of type GrafPtr or CGrafPtr , the current port is set
to the port specified by the port parameter, and the current device is set to the
device specified by the gdh parameter.
If the port parameter is of type GWorldPtr , the current port is set to the port
specified by the port parameter, and the current device is set to the device
attatched to the given graphics world. The gdh parameter will be ignored.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
SetGWorld(CGrafPtr port, GDHandle gdh)
    FOURWORDINLINE(0x203C, 0x0008, 0x0006, 0xAB1D);


			/** 
			\brief Get a new seed (a unique identifier) for the color table 
			
			<pre>Call CTabChanged after modifying the content of the color table specified by
the ctab parameter. CTabChanged calls GetCTSeed to get a new seed (a
unique identifier) for the color table and notifies QuickDraw of the change.
ctabthe color table handle
</pre>
 * \returns <pre>none
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
CTabChanged(CTabHandle ctab) FOURWORDINLINE(0x203C, 0x0004, 0x0007, 0xAB1D);


			/** 
			\brief Set the patXValid flag to -1 
			
			<pre>Call PixPatChanged after modifying either the pixel pattern record
specified by the ppat parameter or any of its substructures (pattern map or
pattern data records). PixPatChanged sets the patXValid flag to -1 and
notifies QuickDraw of the change.
ppatthe pixel pattern record handle
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>If your application changes the pmTable field of the pattern map's pixel
pattern, it should call PixPatChanged . However, if your application
changes the content of the color table referenced by the pixel map's pmTable
field, it should call CTabChanged as well.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
PixPatChanged(PixPatHandle ppat) FOURWORDINLINE(0x203C, 0x0004, 0x0008, 0xAB1D);


			/** 
			\brief Notify QuickDraw  of a change 
			
			<pre>Call PortChanged after modifying the content of a grafPort or any of its
substructures. PortChanged notifies QuickDraw of the change.
porta grafPort pointer
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>You should not directly change any of the pixel pattern records pointed to
by a color grafPort record. Instead, use the PenPixPat and BackPixPat
procedures. However, if your application changes the content of one of the
pixel pattern records, it should call PixPatChanged .
If your application changes the pmTable field of the port's pixel map, it
should call PortChanged . However, if your application changes the content
of the color table referenced by pmTable, it should call CTabChanged as
well.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
PortChanged(GrafPtr port) FOURWORDINLINE(0x203C, 0x0004, 0x0009, 0xAB1D);


			/** 
			\brief Notify QuickDraw  of a graphics device record change 
			
			<pre>Call GDeviceChanged after modifying the graphics device record specified
by the gdh parameter or any of its substructures. GDeviceChanged notifies
QuickDraw of the change.
gdhhandle to the graphics device record or any of its substructures.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>If your application changes the pmTable field of the graphics device's pixel
map, it should call GDeviceChanged . However, if your application changes
the content of the color table referenced by gdPMap, it should call
CTabChanged as well.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
GDeviceChanged(GDHandle gdh) FOURWORDINLINE(0x203C, 0x0004, 0x000A, 0xAB1D);


			/** 
			\brief AllowPurgePixels Mark the pixel map's offscreen buffer as purgeable 
			
			<pre>AllowPurgePixels marks the pixel map's offscreen buffer as purgeable.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
AllowPurgePixels(PixMapHandle pm)
    FOURWORDINLINE(0x203C, 0x0004, 0x000B, 0xAB1D);


			/** 
			\brief Mark the pixel map's offscreen buffer as unpurgeable 
			
			<pre>NoPurgePixels marks the pixel map's offscreen buffer as unpurgeable.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
NoPurgePixels(PixMapHandle pm) FOURWORDINLINE(0x203C, 0x0004, 0x000C, 0xAB1D);


			/** 
			\brief Get state of the pixel map's offscreen buffer 
			
			<pre>GetPixelsState returns the state of the pixel map's offscreen buffer. The
state can be a combination of the flags pixelsPurgeable , pixelsLocked and
keepLocal , which are members of GWorldFlags . Use GetPixelsState in
conjunction with SetPixelsState to save and restore the state of these flags.
You can save the flags, change any of them, and then restore their original state
by passing the result of GetPixelsState back to the SetPixelsState
procedure.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(GWorldFlags)
GetPixelsState(PixMapHandle pm) FOURWORDINLINE(0x203C, 0x0004, 0x000D, 0xAB1D);


			/** 
			\brief Set state of the pixel map's offscreen buffer 
			
			<pre>SetPixelsState sets the lock and purge states of the pixel map's offscreen
buffer to the given flags by calling LockPixels or UnlockPixels and
AllowPurgePixels or NoPurgePixels . Pass the pixel map handle
returned from a GetGWorldPixMap call, and a setting of 0 or 1 for the
GWorldFlags , pixelsPurgeable and pixelsLocked .
You can also use SetPixelsState to set the keepLocal flag: pass keepLocal as
a state parameter to specify that the offscreen graphics world stays in main
memory rather than being checked on an accelerator card. A graphics world that
has already been cached will be brought back to main memory. Clearing the flag
will again allow caching. Use this setting carefully, as keeping graphics world
local surrenders the benefits of graphics accelerators.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
SetPixelsState(PixMapHandle pm, GWorldFlags state)
    FOURWORDINLINE(0x203C, 0x0008, 0x000E, 0xAB1D);


			/** 
			\brief Get a pointer to the beginning of the pixel map's pixels 
			
			<pre>GetPixBaseAddr returns a 32-bit pointer to the beginning of the pixel
map's pixels. Your application should always call GetPixBaseAddr before
accessing the pixels of an offscreen pixel map directly. Then your application
should switch to 32-bit mode, access the pixels, and switch back to 24-bit
mode (if that's the mode you were in). Your application should never access the
baseAddr field of the pixel map directly.
If the offscreen buffer has been purged, GetPixBaseAddr returns NULL.
If QuickDraw is called after GetPixBaseAddr , the contents of the offscreen
buffer are not guaranteed to be accurate.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Ptr)
GetPixBaseAddr(PixMapHandle pm) FOURWORDINLINE(0x203C, 0x0004, 0x000F, 0xAB1D);

/**
 *  GetPixRowBytes()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(long)
GetPixRowBytes(PixMapHandle pm) FOURWORDINLINE(0x203C, 0x0004, 0x0018, 0xAB1D);

/**
 *  NewScreenBuffer()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(QDErr)
NewScreenBuffer(const Rect *globalRect, Boolean purgeable, GDHandle *gdh,
                PixMapHandle *offscreenPixMap)
    FOURWORDINLINE(0x203C, 0x000E, 0x0010, 0xAB1D);


			/** 
			\brief DisposeScreenBuffer Dispose of memory for offscreen buffer and color table 
			
			<pre>DisposeScreenBuffer is called by DisposeGWorld . It disposes of the
memory allocated for the offscreen buffer, the offscreen pixel map, and the
color table.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
DisposeScreenBuffer(PixMapHandle offscreenPixMap)
    FOURWORDINLINE(0x203C, 0x0004, 0x0011, 0xAB1D);


			/** 
			\brief Get a handle to the device attached to the offscreen world 
			
			<pre>GetGWorldDevice returns a handle to the device attached to the offscreen
world specified by the offscreenGWorld parameter. This device is generally the
offscreen device created by NewGWorld . If offscreenGWorld was created with
the noNewDevice flag set, the attached device is one of the screen devices or the
device was passed to NewGWorld or UpdateGWorld .
If the offscreenGWorld parameter points to a regular GrafPort or CGrafPort ,
GetGWorldDevice returns the current device.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(GDHandle)
GetGWorldDevice(GWorldPtr offscreenGWorld)
    FOURWORDINLINE(0x203C, 0x0004, 0x0012, 0xAB1D);


			/** 
			\brief Ensure that all drawing is done 
			
			<pre>You can use the QDDone function to ensure that all drawing is done and avoid
the possibility that new drawing operations might be overlaid by previously
issued but unexecuted operations. This function is especially useful if a
graphics accelerator is present and operating asynchronously.
port the designated graphics port
</pre>
 * \returns <pre>a Boolean value. The QDDone function returns TRUE if drawing
operations have finished in the designated graphics port, FALSE if any
remain to be executed. If you pass NIL as the port parameter, then
QDDone returns TRUE only if drawing operations have completed in
all ports. (If a port has a clock or other continuously operating
process, QDDone may never return TRUE.)
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
QDDone(GrafPtr port) FOURWORDINLINE(0x203C, 0x0004, 0x0013, 0xAB1D);

/**
 *  OffscreenVersion()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(long)
OffscreenVersion(void) TWOWORDINLINE(0x7014, 0xAB1D);

/**
 *  NewTempScreenBuffer()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(QDErr)
NewTempScreenBuffer(const Rect *globalRect, Boolean purgeable, GDHandle *gdh,
                    PixMapHandle *offscreenPixMap)
    FOURWORDINLINE(0x203C, 0x000E, 0x0015, 0xAB1D);


			/** 
			\brief Determine if PixMap requires 32-bit addr mode to access its pixels 
			
			<pre>PixMap32Bit returns TRUE if the specified pixel map requires 32-bit
addressing mode for access to its pixels.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
PixMap32Bit(PixMapHandle pmHandle)
    FOURWORDINLINE(0x203C, 0x0004, 0x0016, 0xAB1D);


			/** 
			\brief Get a handle to the pixel map for an offscreen graphics world 
			
			<pre>GetGWorldPixMap returns a handle to the pixel map created for an
offscreen graphics world. Use GetGWorldPixMap whenever you need to
address the pixel map record created for an offscreen graphics world, rather
than dereferencing the GWorldPtr , to ensure compatibility on systems that
have the offscreen graphics world routines but are running the original
QuickDraw (not Color QuickDraw).
For example, you should use this function before calling CopyBits when
copying from the pixel map of an offscreen graphics world:
pixBase = GetGWorldPixMap (offscreenGWorld );
CopyBits (*pixBase,myWindow->portBits,&aRect,&otherR,srcCopy,NULL);
Use the GetGWorldPixMap function with offscreen graphics world
routines, such as LockPixels , AllowPurgePixels and GetPixelsState ,
that use a handle to a pixel map.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(PixMapHandle)
GetGWorldPixMap(GWorldPtr offscreenGWorld)
    FOURWORDINLINE(0x203C, 0x0004, 0x0017, 0xAB1D);

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

#endif /* __QDOFFSCREEN__ */
*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/