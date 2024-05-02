/**
     \file       RAVE.h

    \brief   Interface for RAVE (Renderer Acceleration Virtual Engine)

    \introduced_in  Quickdraw 3D 1.6
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1995-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup RAVE

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __RAVE__
#define __RAVE__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#if TARGET_OS_MAC
#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __QDOFFSCREEN__
#include <QDOffscreen.h>
#endif

#endif // TARGET_OS_MAC 
#if TARGET_OS_WIN32
#include <windows.h>
#ifndef RAVE_NO_DIRECTDRAW
#include <ddraw.h>
#endif // !defined(RAVE_NO_DIRECTDRAW) 
#endif // !defined(RAVE_NO_DIRECTDRAW) 
#if PRAGMA_ONCE
#pragma// TARGET_OS_WIN32 
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_IMPORT
#pragma import on
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align = power
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __RAVE__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __RAVE__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

#define RAVE_OBSOLETE 0

/******************************************************************************
 *
 * Platform macros.
 * This sets kQAPlatform to one of kQAMacOS, kQAWin32, or kQAGeneric.
 * kQAPlatform controls platform-specific compilation switches and types.
 *
 *****************************************************************************/

#if !defined(kQAMacOS)
#define kQAMacOS 1 // Target is MacOS                  #endif

#if !defined(kQAGeneric)
#define kQAGeneric // Target is MacOS                  

#if !defined(kQAWin32)
#define kQAWin32 3 // Target is Win32                  #endif
// Target is generic platform       
#if defined(_WIN32) || defined(_WINDOWS)
#define kQAPlatform kQAWin32
#elif !defined(kQAPlatform)
#define kQAPlatform// Target is Win32                  
#endif

/******************************************************************************
 *
 * Export Control
 *
 *****************************************************************************/
#if defined(_MSC_VER)
// Microsoft Visual C #if defined(WIN32_RAVEEXPORTING)
// define when building DLL #define RAVE_EXPORT __declspec(dllexport)
#define RAVE_CALL
#define RAVE_CALLBACK
#else
#define RAVE_EXPORT __declspec(dllimport)
// Microsoft Visual C 
#define RAVE_CALLBACK __cdecl
// define when building DLL 
// WIN32_RAVEEXPORTING #else
#define RAVE_EXPORT
#define RAVE_CALL
#define RAVE_CALLBACK
#endif
// _MSC_VER 
/******************************************************************************
 *
// WIN32_RAVEEXPORTING 
 *TQARect.
 *
 *****************************************************************************/
enum TQAImagePixelType {
  kQAPixel_Alpha1 = 0, // 1 bit/pixel alpha   kQAPixel_RGB16 = 1,  // 16 bits/pixel, R=14:10, G=9:5, B=4:0   kQAPixel_ARGB16 = 2, // 16 bits/pixel, A=15, R=14:10, G=9:5, B=4:0   kQAPixel_RGB32 = 3,  // 32 bits/pixel, R=23:16, G=15:8, B=7:0   kQAPixel_ARGB32 = 4, // 32 bits/pixel, A=31:24, R=23:16, G=15:8, B=7:0   kQAPixel_CL4 = 5, /* 4 bit color look up table, always big endian, ie high 4
// _MSC_VER 
  kQAPixel_CL8 = 6, // 8 bit color look up table   kQAPixel_RGB16_565 =
      7,              // Win32 ONLY  16 bits/pixel, no alpha, R:5, G:6, B:5   kQAPixel_RGB24 = 8, // Win32 ONLY  24 bits/pixel, no alpha, R:8, G:8, B:8   kQAPixel_RGB8_332 = 9,     // 8 bits/pixel, R=7:5, G = 4:2, B = 1:0   kQAPixel_ARGB16_4444 = 10, // 16 bits/pixel, A=15:12, R=11:8, G=7:4, B=3:0   kQAPixel_ACL16_88 =
      11, // 16 bits/pixel, A=15:8, CL=7:0, 8 bit alpha + 8 bit color lookup   kQAPixel_I8 = 12, // 8 bits/pixel, I=7:0, intensity map (grayscale)   kQAPixel_AI16_88 =
      13, // 16 bits/pixel, A=15:8, I=7:0, intensity map (grayscale)   kQAPixel_YUVS = 14,    /* 16 bits/pixel, QD's kYUVSPixelFormat (4:2:2, YUYV
                            ordering, unsigned UV) */
  kQAPixel_YUVU = 15,    /* 16 bits/pixel, QD's kYUVUPixelFormat (4:2:2, YUYV
                            ordering, signed UV) */
  kQAPixel_YVYU422 = 16, /* 16 bits/pixel, QD's kYVYU422PixelFormat (4:2:2, YVYU
                       // 1 bit/pixel alpha 
  kQAPixel_UYVY422 = 17// 16 bits/pixel, R=14:10, G=9:5, B=4:0 
                       // 16 bits/pixel, A=15, R=14:10, G=9:5, B=4:0 
};// 32 bits/pixel, R=23:16, G=15:8, B=7:0 
typedef enum TQAImagePi// 32 bits/pixel, A=31:24, R=23:16, G=15:8, B=7:0 

enum TQAColorTableType {
  kQAColorTable_CL8_// 8 bit color look up table 
      0, // 256 entry, 32 bit/pixel, R=23:16, G=15:8, B=7:0   kQAColorTable_CL4_RGB32 =
      1 // 16 entry, 3// Win32 ONLY  16 bits/pixel, no alpha, R:5, G:6, B:5 
typedef enum TQAColorT// Win32 ONLY  24 bits/pixel, no alpha, R:8, G:8, B:8 
// 8 bits/pixel, R=7:5, G = 4:2, B = 1:0 
// Selects target device type// 16 bits/pixel, A=15:12, R=11:8, G=7:4, B=3:0 
  kQADeviceMemory = 0,   // Memory draw context   kQADeviceGDevice = 1,  // Macintosh GDevice draw context   kQADeviceWin32DC = 2,  // Win32 DC   kQADeviceDDSurface = 3 // Win32 DirectDraw Surface };
typedef en// 16 bits/pixel, A=15:8, CL=7:0, 8 bit alpha + 8 bit color lookup 
// 8 bits/pixel, I=7:0, intensity map (grayscale) 
// Generic memory pixmap device struct TQADeviceMemory {
  long row// 16 bits/pixel, A=15:8, I=7:0, intensity map (grayscale) 
typedef struct TQADeviceMemory TQADeviceMemory;
// Offscreen Device struct TQADeviceOffscreen {
  TQAImagePixelType pixelType; // Depth, color space, etc. };
typedef struct TQADeviceOffscreen TQADeviceOffscreen;
// Selects target clip type enum TQAClipType {
  kQAClipRgn = 0,     // Macintosh clipRgn with serial number   kQAClipWin32Rgn = 1 // Win32 clip region };
typedef enum TQAClipType TQAClipType;

struct TQARect {
  long left;
  long right;
  long top;
  long bottom;
};// 256 entry, 32 bit/pixel, R=23:16, G=15:8, B=7:0 
typedef struct TQARect TQARect;
#if TARG// 16 entry, 32 bit/pixel, R=23:16, G=15:8, B=7:0 
union TQAPlatformDevice {
  TQADeviceMemory memoryDevice;
  GDHandle gDevice;
// Selects target device type 
typedef union TQAPlatformDevice TQAPlatformDevice;
union TQAPlatformClip {// Memory draw context 
  RgnHandle clipRgn;// Macintosh GDevice draw context 
};// Win32 DC 
typedef union TQAPlatform// Win32 DirectDraw Surface 
typedef CALLBACK_API(void, TQADrawNotificationProcPtr)(short left, short top,
                                                       short right,
                                                       short bottom,
// Generic memory pixmap device 

typedef long TQADrawNotificatio// Rowbytes 
// used to unregister your proc// Depth, color space, etc. 
// Width in pixels 
#if !defined(RAVE_NO_DIRECTDRAW// Height in pixels 
// Base address of pixmap 
enum TQADirectDrawObjectSelector {
  kQADirectDrawObject = 1,
// Offscreen Device 
};
typedef enum TQADirectDrawObjec// Depth, color space, etc. 

enum TQADirectDrawSurfaceSelector {
// Selects target clip type 
  kQADirectDrawSurface2 = 2
};// Macintosh clipRgn with serial number 
typedef enum TQADirect// Win32 clip region 

#endif // !RAVE_NO_DIRECTDRAW 
union TQAPlatformDevice {
  TQADeviceMemory memoryDevice;
  HDC hdc;
#if !defined(RAVE_NO_DIRECTDRAW)
  /**
<pre>
 * \note <pre>This ColorInfo record type is the basic building block of the array that
eventually comprises a color palette data structure. Taken together with
other information on how the colors are used within the palette, the
completed data structure is also the same as the 'pltt' resource type.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
/**
<pre>
 * \note <pre>Use this WDPBRec structure in calls to PBOpenWD , PBCloseWD , and
PBGetWDInfo .
Set ioWDIndex to 0 if in all cases except for indexed lookups via
PBGetWDInfo .
The meaning and usage of ioWDProcID has not been fully explained by
Apple, but they do recommend that you set it to 'ERIK'.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
// used to unregister your proc 
<pre>
 * \note <pre>Applications can all have their own search procedures, yet share the same
gDevice. The search procedures form the elements in a linked list that
starts in the device port's gdSearchProc field. The search procedures list
can be any length and each search procedure on the list gets a chance to act
or not.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
/**
<pre>
 * \note <pre>The meaning of the qType field has been corrupted. If HFS is present, then
this field indicates how to calculate the size of the drive. It is one of:
0The drive contains dQDrvSz blocks (probably 512-bytes each)
1The drive contains dQDrvSz +( dQDrvSz * 0x10000 ) blocks
3MFS is probably present and dQDrvSz is the total blocks
Precedi// !RAVE_NO_DIRECTDRAW 
follows:
Offset Description
-4(bit 7 set) = disk is locked (write-protected)
-30 no disk in drive
1 or 2 disk is in drive
8 non-ejectable disk
FCh...FFh disk was ejected within last 1.5 seconds
48h non-ejectable disk, but driver expects a call (?)
-2(used internally during system startup)
-1(bit 7 clear) drive supports only single-sided media
See GetDrvQHdr for an example of how to access these prefix bytes and
how to calculate the true size of the drive.
The global variable DrvQHdr contains the queue header which begins the
chain of drive queue elements. Or call GetDrvQHdr to obtain that address.
dQDrvSz2 is only used if qType is 1. In this case, dQDrvSz2 contains the
high-order word of the size, and dQDrvSz contains the low-order word.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
/**
<pre>
 * \note <pre> Color icons are used just like black and white icons. 'cicn' resources will
take precedence over 'ICON' resources whenever they're present. When
calculating n, above:
n=IconMask. rowBytes *height
Height=IconPMap. bounds.bottom-IconPmap. bounds.top
PlotIcon is used to draw a color icon already in RAM.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct {
	PixMap iconPMap;/**< Pixel Map describing icon*/
	BitMap iconMask;/**< Icon mask bitmap*/
	BitMap iconBMap;/**< Icon bitmap*/
	Handle iconData;/**< Handle to icon*/
	short *iconMaskData;/**< nData for bitmap and map*/
	} CIcon ;/**< +n*/

typedef union TQAPlatformClip TQAPlatformClip;

#else
/**
 * Generic platform supports memory device only. TQARect is generic. TQAClip is
 * ???.
 */
union TQAPlatformDevice {
  TQADeviceMemory memoryDevice;
};
typedef union TQAPlatformDevice TQAPlatformDevice;
union TQAPlatformClip {
  void *region; // ??? };
typedef union TQAPlatformClip TQAPlatformClip;
#endif //  
struct TQADevice {
  TQADeviceType deviceType;
  TQAPlatformDevice device;
};
typedef struct TQADevice TQADevice;
struct TQAClip {
  TQAClipType clipType;
  TQAPlatformClip clip;
};
typedef struct TQAClip TQAClip;
/******************************************************************************
 *
 * Basic data types.
 *
 *****************************************************************************/

// Pointer to a drawing engine typedef struct TQAEngine TQAEngine;
// Pointer to an allocated texture typedef struct TQATexture TQATexture;
// Pointer to an allocated bitmap typedef struct TQABitmap TQABitmap;
// Engine's private draw context pointer typedef struct TQADrawPrivate TQADrawPrivate;
// An engine specific color table structure typedef struct TQAColorTable TQAColorTable;
// A single triangle element for QADrawTriMesh struct TQAIndexedTriangle {
  unsigned long triangleFlags; // Triangle flags, see kQATriFlags_   unsigned long vertices[3];   // Indices into a vertex array };
typedef struct TQAIndexedTriangle TQAIndexedTriangle;
// An image for use as texture or bitmap struct TQAImage {
  long width;    // Width of pixmap   long height;   // Height of pixmap   long rowBytes; // Rowbytes of pixmap   void *pixmap;  // Pixmap };
typedef struct TQAImage TQAImage;
// a pixel buffer 
typedef TQADeviceMemory TQAPixelBuffer;
// a zbuffer struct TQAZBuffer {
  long width;       // Width of pixmap   long height;      // Height of pixmap   long rowBytes;    // Rowbytes of pixmap   void *zbuffer;    // pointer to the zbuffer data   long zDepth;      // bit depth of zbuffer (16,24,32...)   long isBigEndian; /* true if zbuffer values are in big-endian format, false if
                       little-endian */
};
typedef struct TQAZBuffer TQAZBuffer;
// Standard error type enum TQAError {
  kQANoErr = 0,          // No error   kQAError = 1,          // Generic error flag   kQAOutOfMemory = 2,    // Insufficient memory   kQANotSupported = 3,   // Requested feature is not supported   kQAOutOfDate = 4,      // A newer drawing engine was registered   kQAParamErr = 5,       // Error in passed parameters   kQAGestaltUnknown = 6, // Requested gestalt type isn't available   kQADisplayModeUnsupported =
      7, // Engine cannot render to the display in its current ,          // mode, but could if it were in some other mode   kQAOutOfVideoMemory =
      8 // There is not enough VRAM to support the desired context dimensions };
typedef enum TQAError TQAError;

// TQABoolean // ??? 
typedef unsigned char TQABoolean;
/************************************************************************************************
 *//  
 * Vertex data types.
 *
 ***********************************************************************************************/
/**
 * TQAVGouraud is used for Gouraud shading. Each vertex specifies position,
 * color and Z.
 *
 * Alpha is always treated as indicating transparency. Drawing engines which
 * don't support Z-sorted rendering use the back-to-front transparency blending
 * functions shown below. (ARGBsrc are the source (new) values, ARGBdest are the
 * destination (previous) pixel values.)
 *
 *      Premultiplied                           Interpolated
 *
 *      A = 1 - (1 - Asrc) * (1 - Adest)        A = 1 - (1 - Asrc) * (1 - Adest)
 *      R = (1 - Asrc) * Rdest + Rsrc           R = (1 - Asrc) * Rdest + Asrc *
 * Rsrc G = (1 - Asrc) * Gdest + Gsrc           G = (1 - Asrc) * Gdest + Asrc *
// Pointer to a drawing engine 
 * Bsrc
// Pointer to an allocated texture 
 * Note that the use of other blending modes to implement antialiasing is
// Pointer to an allocated bitmap 
 * variable != kQAAntiAlias_Fast. The driving software should continue to use
// Engine's private draw context pointer 
 * drawing engine will resolve the multiple blending requirements as best as it
// An engine specific color table structure 
 *
// A single triangle element for QADrawTriMesh 
 * the blending function shown above with the equivalent front-to-back formula.
 */// Triangle flags, see kQATriFlags_ 
struct TQAVGouraud {// Indices into a vertex array 
  float x;    // X pixel coordinate, 0.0 <= x < width   float y;    // Y pixel coordinate, 0.0 <= y < height   float z;    // Z coordinate, 0.0 <= z <= 1.0   float invW; // 1 / w; required only when kQAPerspectiveZ_On is set 
  float r; // Red, 0.0 <= r <= 1.0   float g; // Green, 0.0 <= g <= 1.0   float b; // Blue, 0.0 <= b <= 1.0   float a; // Alpha, 0.0 <= a <= 1.0, 1.0 is opaque };
// An image for use as texture or bitmap 
/**
 * TQAVTexture is// Width of pixmap 
 * is controlled // Height of pixmap 
 * kQATextureOp_N// Rowbytes of pixmap 
 * texture shadin// Pixmap 
 *
 *      texPix = TextureLookup (uq/q, vq/q);
// a pixel buffer 
 *      {
 *          texPix.r = texPix.a * texPix.r + (1 - texPix.a) * r;
// a zbuffer 
 *          texPix.b = texPix.a * texPix.b + (1 - texPix.a) * b;
 *          texPix.a// Width of pixmap 
 *      }// Height of pixmap 
 *      else// Rowbytes of pixmap 
 *      {// pointer to the zbuffer data 
 *          texPix.a// bit depth of zbuffer (16,24,32...) 
 *      }
 *      if (kQATextureOp_Modulate)
 *      {
 *          texPix.r *= kd_r;       // Clamped to prevent overflow
// Standard error type 
 *          texPix.b *= kd_b;       // Clamped to prevent overflow
 *      }// No error 
 *      if (kQATextureOp_// Generic error flag 
 *      {// Insufficient memory 
 *          texPix.r += k// Requested feature is not supported 
 *          texPix.g += k// A newer drawing engine was registered 
 *          texPix.b += k// Error in passed parameters 
 *      }// Requested gestalt type isn't available 
 *
 * After // Engine cannot render to the display in its current , 
 * above // mode, but could if it were in some other mode 
 */
struct T// There is not enough VRAM to support the desired context dimensions 
  float x;    // X pixel coordinate, 0.0 <= x < width   float y;    // Y pixel coordinate, 0.0 <= y < height   float z;    // Z coordinate, 0.0 <= z <= 1.0   float invW; // 1 / w (always required) 
  // rgb are used only when kQATextureOp_Decal is set. a is always required 
  float r; // Red, 0.0 <= r <= 1.0   float g; // Green, 0.0 <= g <= 1.0   float b; // Blue, 0.0 <= b <= 1.0   float a; // Alpha, 0.0 <= a <= 1.0, 1.0 is opaque 
// TQABoolean 
  float uOverW; // u / w   float vOverW; // v / w 
  // kd_r/g/b are used only when kQATextureOp_Modulate is set 
  float kd_r; // Scale factor for texture red, 0.0 <= kd_r   float kd_g; // Scale factor for texture green, 0.0 <= kd_g   float kd_b; // Scale factor for texture blue, 0.0 <= kd_b 
  // ks_r/g/b are used only when kQATextureOp_Highlight is set 
  float ks_r; // Red specular highlight, 0.0 <= ks_r <= 1.0   float ks_g; // Green specular highlight, 0.0 <= ks_g <= 1.0   float ks_b; // Blue specular highlight, 0.0 <= ks_b <= 1.0 };
typedef struct TQAVTexture TQAVTexture;
/**
 *  TQAVMultiTexture allows you to specify the uv and invW values
 *  for secondary textures.  This data is submitted with the
 *  QASubmitMultiTextureParams() call.
 */
struct TQAVMultiTexture {
  float invW;
  float uOverW;
  float vOverW;
};
typedef struct TQAVMultiTexture TQAVMultiTexture;

/************************************************************************************************
 *
 * Constants used for the state variables.
 *
 ***********************************************************************************************/
/**
 * kQATag_xxx is used to select a state variable when calling QASetFloat(),
 QASetInt(),
 * QAGetFloat() and QAGetInt(). The kQATag values are split into three separate
 enumerated
 * types: TQATagInt, TQATagPtr and TQATagFloat. TQATagInt is used for the
 QASet/GetInt()
 * functions, TQATagPtr is used for the QASet/GetPtr() functions, and
 TQATagFloat is used for
 * the QASet/GetFloat() functions. (This is so that a compiler that typechecks
 enums can flag
 * a float/int tag mismatch during compile.)
 *// X pixel coordinate, 0.0 <= x < width 
 * -=- All tag// Y pixel coordinate, 0.0 <= y < height 
 *// Z coordinate, 0.0 <= z <= 1.0 
 * These varia// 1 / w; required only when kQAPerspectiveZ_On is set 
 *      kQATag_ZFunction            (Int)   One of kQAZFunction_xxx
 *      kQA// Red, 0.0 <= r <= 1.0 
 *      kQA// Green, 0.0 <= g <= 1.0 
 *      kQA// Blue, 0.0 <= b <= 1.0 
 *      kQA// Alpha, 0.0 <= a <= 1.0, 1.0 is opaque 
 *      kQATag_Width                (Float) Line and point width (pixels)
 *      kQATag_ZMinOffset           (Float) Min offset to Z to guarantee
 visibility (Read only!)
 *      kQATag_ZMinScale            (Float) Min scale to Z to guarantee
 visibility (Read only!)

 * These variables are used for optional features:
 *      kQATag_Antialias            (Int)   One of kQAAntiAlias_xxx
 *      kQATag_Blend                (Int)   One of kQABlend_xxx
 *      kQATag_PerspectiveZ         (Int)   One of kQAPerspectiveZ_xxx
 *      kQATag_TextureFilter        (Int)   One of kQATextureFilter_xxx
 *      kQATag_TextureOp            (Int)   Mask of kQATextureOp_xxx
 *      kQATag_Texture              (Ptr)   Pointer to current TQATexture
 *      kQATag_CSGTag               (Int)   One of kQACSGTag_xxx
 *      kQATag_CSGEquation          (Int)   32 bit CSG truth table
 *      kQATag_FogMode              (Int)   One of kQAFogMode_xxxx
 *      kQATag_FogColor_a           (Float) Fog color alpha
 *      kQATag_FogColor_r           (Float) Fog color red
 *      kQATag_FogColor_g           (Float) Fog color green
 *      kQATag_FogColor_b           (Float) Fog color blue
 *      kQATag_FogStart             (Float) Fog start
 *      kQATag_FogEnd               (Float) Fog end
 *      kQATag_FogDensity           (Float) Fog density
 *      kQATag_FogMaxDepth          (Float) Maximun value for 1.0 / invW
 *      kQATag_MipmapBias           (Float) The mipmap page bias factor
 *      kQATag_ChannelMask          (Int) one of kQAChannelMask_xxx
 *      kQATag_ZBufferMask          (Int) one of kQAZBufferMask_xxx
 *      kQATag_ZSortedHint          (Int) 1 = depth sort transparent triangles,
 0 = do not sort.
 *      kQATag_Chromakey_r          (Float) chroma key red
 *      kQATag_Chromakey_g          (Float) chroma key green
 *      kQATag_Chromakey_b          (Float) chroma key blue
 *      kQATag_ChromakeyEnable      (Int) 1 = enable chroma keying, 0 = disable
 chroma keying
 *      kQATag_AlphaTestFunc        (Int) one of kQAAlphaTest_xxx
 *      kQATag_AlphaTestRef         (Float) from 0 to 1
 *      kQATag_DontSwap             (Int) 1 = dont swap buffers during
 QARenderEnd, // X pixel coordinate, 0.0 <= x < width 
// Y pixel coordinate, 0.0 <= y < height 
 *      kQATag// Z coordinate, 0.0 <= z <= 1.0 
 *      kQATag// 1 / w (always required) 
 *      kQATag_MultiTextureCurrent  (Int) which multitexture layer to use for
 a// rgb are used only when kQATextureOp_Decal is set. a is always required 
 *      kQATag_MultiTextureEnable   (Int) how many multitexture layers to use (0
 = no multi// Red, 0.0 <= r <= 1.0 
 *      kQA// Green, 0.0 <= g <= 1.0 
 *      kQA// Blue, 0.0 <= b <= 1.0 
 *      kQA// Alpha, 0.0 <= a <= 1.0, 1.0 is opaque 
 *      kQATag_MultiTextureMinFilter (Int)
 *// uOverW and vOverW are required by all modes 
 *      kQATag_MultiTextureBorder_r (Float)
 *      kQATag_M// u / w 
 *      kQATag_M// v / w 
 *      kQATag_MultiTextureMipmapBias (Float)
 *// kd_r/g/b are used only when kQATextureOp_Modulate is set 
 determine blending factor
 *// Scale factor for texture red, 0.0 <= kd_r 
 * These varia// Scale factor for texture green, 0.0 <= kd_g 
 *      kQATag// Scale factor for texture blue, 0.0 <= kd_b 
 *      kQATagGL_TextureWrapU       (Int)   kQAGL_Clamp or kQAGL_Repeat
 *// ks_r/g/b are used only when kQATextureOp_Highlight is set 
 *      kQATagGL_TextureMagFilter   (Int)   kQAGL_Nearest or kQAGL_Linear
 *      kQATag// Red specular highlight, 0.0 <= ks_r <= 1.0 
 *      kQATag// Green specular highlight, 0.0 <= ks_g <= 1.0 
 rectangle// Blue specular highlight, 0.0 <= ks_b <= 1.0 
 *      kQATagGL_ScissorYMin        (Int)   Minimum Y value for scissor
 rectangle
 *      kQATagGL_ScissorXMax        (Int)   Maximum X value for scissor
 rectangle
 *      kQATagGL_ScissorYMax        (Int)   Maximum Y value for scissor
 rectangle
 *      kQATagGL_BlendSrc           (Int)   Source blending operation
 *      kQATagGL_BlendDst           (Int)   Destination blending operation
 *      kQATagGL_LinePattern        (Int)   Line rasterization pattern
 *      kQATagGL_AreaPattern0       (Int)   First of 32 area pattern registers
 *      kQATagGL_AreaPattern31      (Int)   Last of 32 area pattern registers
 *
 *      kQATagGL_DepthBG            (Float) Background Z
 *      kQATagGL_TextureBorder_a    (Float) Texture border color alpha
 *      kQATagGL_TextureBorder_r    (Float) Texture border color red
 *      kQATagGL_TextureBorder_g    (Float) Texture border color green
 *      kQATagGL_TextureBorder_b    (Float) Texture border color blue
 *
 * Tags >= kQATag_EngineSpecific_Minimum may be assigned by the vendor for use
 as
 * engine-specific variables. NOTE: These should be used only in exceptional
 circumstances,
 * as functions performed by these variables won't be generally accessible. All
 other tag
 * values are reserved.
 *
 *      kQATag_EngineSpecific_Minimum   Minimum tag value for drawing-engine
 specific variables
 */
enum TQATagInt {
  kQATag_ZFunction = 0,
  kQATag_Antialias = 8,
  kQATag_Blend = 9,
  kQATag_PerspectiveZ = 10,
  kQATag_TextureFilter = 11,
  kQATag_TextureOp = 12,
  kQATag_CSGTag = 14,
  kQATag_CSGEquation = 15,
  kQATag_BufferComposite = 16,
  kQATag_FogMode = 17,
  kQATag_ChannelMask = 27,
  kQATag_ZBufferMask = 28,
  kQATag_ZSortedHint = 29,
  kQATag_ChromakeyEnable = 30,
  kQATag_AlphaTestFunc = 31,
  kQATag_DontSwap = 32,
  kQATag_MultiTextureEnable = 33,
  kQATag_MultiTextureCurrent = 34,
  kQATag_MultiTextureOp = 35,
  kQATag_MultiTextureFilter = 36,
  kQATag_MultiTextureWrapU = 37,
  kQATag_MultiTextureWrapV = 38,
  kQATag_MultiTextureMagFilter = 39,
  kQATag_MultiTextureMinFilter = 40,
  kQATag_BitmapFilter =
      54, // filter to use while scaling bitmaps, one of kQAFilter_xxx   kQATag_DrawContextFilter =
      55, // filter to use while scaling draw contexts, one of kQAFilter_xxx   kQATagGL_DrawBuffer = 100,
  kQATagGL_TextureWrapU = 101,
  kQATagGL_TextureWrapV = 102,
  kQATagGL_TextureMagFilter = 103,
  kQATagGL_TextureMinFilter = 104,
  kQATagGL_ScissorXMin = 105,
  kQATagGL_ScissorYMin = 106,
  kQATagGL_ScissorXMax = 107,
  kQATagGL_ScissorYMax = 108,
  kQATagGL_BlendSrc = 109,
  kQATagGL_BlendDst = 110,
  kQATagGL_LinePattern = 111,
  kQATagGL_AreaPattern0 = 117, // ...kQATagGL_AreaPattern1-30   kQATagGL_AreaPattern31 = 148,
  kQATagGL_LinePatternFactor = 149, // equivalent to GL_LINE_STIPPLE_REPEAT   kQATag_EngineSpecific_Minimum = 1000
};
typedef enum TQATagInt TQATagInt;

enum TQATagPtr { kQATag_Texture = 13, kQATag_MultiTexture = 26 };
typedef enum TQATagPtr TQATagPtr;

enum TQATagFloat {
  kQATag_ColorBG_a = 1,
  kQATag_ColorBG_r = 2,
  kQATag_ColorBG_g = 3,
  kQATag_ColorBG_b = 4,
  kQATag_Width = 5,
  kQATag_ZMinOffset = 6,
  kQATag_ZMinScale = 7,
  kQATag_FogColor_a = 18,
  kQATag_FogColor_r = 19,
  kQATag_FogColor_g = 20,
  kQATag_FogColor_b = 21,
  kQATag_FogStart = 22,
  kQATag_FogEnd = 23,
  kQATag_FogDensity = 24,
  kQATag_FogMaxDepth = 25,
  kQATag_MipmapBias = 41,
  kQATag_MultiTextureMipmapBias = 42,
  kQATag_Chromakey_r = 43,
  kQATag_Chromakey_g = 44,
  kQATag_Chromakey_b = 45,
  kQATag_AlphaTestRef = 46,
  kQATag_MultiTextureBorder_a = 47,
  kQATag_MultiTextureBorder_r = 48,
  kQATag_MultiTextureBorder_g = 49,
  kQATag_MultiTextureBorder_b = 50,
  kQATag_MultiTextureFactor = 51,
  kQATag_BitmapScale_x =
      52, // horizontal bitmap scale factor, default value is 1.0   kQATag_BitmapScale_y =
      53, // vertical bitmap scale factor, default value is 1.0   kQATag_MultiTextureEnvColor_a = 56,
  kQATag_MultiTextureEnvColor_r = 57,
  kQATag_MultiTextureEnvColor_g = 58,
  kQATag_MultiTextureEnvColor_b = 59,
  kQATagGL_DepthBG = 112,
  kQATagGL_TextureBorder_a = 113,
  kQATagGL_TextureBorder_r = 114,
  kQATagGL_TextureBorder_g = 115,
  kQATagGL_TextureBorder_b = 116,
  kQATagGL_TextureEnvColor_a = 150,
  kQATagGL_TextureEnvColor_r = 151,
  kQATagGL_TextureEnvColor_g = 152,
  kQATagGL_TextureEnvColor_b = 153
};
typedef enum TQATagFloat TQATagFloat;

// kQATag_ZFunction enum {
  kQAZFunction_None =
      0, // Z is neither tested nor written (same as no Z buffer)   kQAZFunction_LT = 1,   // Znew < Zbuffer is visible   kQAZFunction_EQ = 2,   // Znew == Zbuffer is visible   kQAZFunction_LE = 3,   // Znew <= Zbuffer is visible   kQAZFunction_GT = 4,   // Znew > Zbuffer is visible   kQAZFunction_NE = 5,   // Znew != Zbuffer is visible   kQAZFunction_GE = 6,   // Znew >= Zbuffer is visible   kQAZFunction_True = 7, // Znew is always visible   kQAZFunction_False = 8 // Znew is never visible };

// kQATag_Width #define kQAMaxWidth 128.0
// kQATag_Antialias enum {
  kQAAntiAlias_Off = 0,
  kQAAntiAlias_Fast = 1,
  kQAAntiAlias_Mid = 2,
  kQAAntiAlias_Best = 3
};

// kQATag_Blend enum {
  kQABlend_PreMultiply = 0,
  kQABlend_Interpolate = 1,
  kQABlend_OpenGL = 2
};

// kQATag_BufferComposite enum {
  kQABufferComposite_None =
      0, // Default: New pixels overwrite initial buffer contents   kQABufferComposite_PreMultiply = 1, /* New pixels are blended with initial
                                         buffer contents via PreMultiply */
  kQABufferComposite_Interpolate = 2  /* New pixels are blended with initial
                                         buffer contents via Interpolate */
};

// kQATag_PerspectiveZ enum {
  kQAPerspectiveZ_Off = 0, // Use Z for hidden surface removal   kQAPerspectiveZ_On = 1   // Use InvW for hidden surface removal };

// kQATag_TextureFilter enum {
  // suggested meanings of these values   kQATextureFilter_Fast = 0, // No filtering, pick nearest   kQATextureFilter_Mid = 1,  // Fastest method that does some filtering   kQATextureFilter_Best = 2  // Highest quality renderer can do };

// filter tag values enum {
  // suggested meanings of these values   kQAFilter_Fast = 0, // No filtering, pick nearest   kQAFilter_Mid = 1,  // Fastest method that does some filtering   kQAFilter_Best = 2  // Highest quality renderer can do };

// kQATag_TextureOp (mask of one or more) enum {
  kQATextureOp_None = 0,             // Default texture mapping mode   kQATextureOp_Modulate = (1 << 0),  // Modulate texture color with kd_r/g/b   kQATextureOp_Highlight = (1 << 1), // Add highlight value ks_r/g/b   kQATextureOp_Decal = (1 << 2), // When texture alpha == 0, use rgb instead   kQATextureOp_Shrink =
      (1 << 3),                 // This is a non-wrapping texture, so the ???   kQATextureOp_Blend = (1 << 4) // Same as GL_TEXTURE_ENV_MODE GL_BLEND };

// kQATag_// filter to use while scaling bitmaps, one of kQAFilter_xxx 
  kQAMultiTexture_Add = 0,      // texels are added to form final pixel   kQAMultiTexture_Modulate = 1, // texels are multiplied to form final pixel   kQAMultiTexture_BlendAlpha =
      2, /// filter to use while scaling draw contexts, one of kQAFilter_xxx 
      3 // texels are blended by a fixed factor via kQATag_MultiTextureFactor };

// kQATag_CSGTag #define kQACSGTag_None 0xffffffffUL
enum {
  kQACSGTag_0 = 0, // Submitted tris have CSG ID 0   kQACSGTag_1 = 1, // Submitted tris have CSG ID 1   kQACSGTag_2 = 2, // Submitted tris have CSG ID 2   kQACSGTag_3 = 3, // Submitted tris have CSG ID 3   kQACSGTag_4 = 4  // Submitted tris have CSG ID 4 };

// kQATagGL_TextureWrapU/V enum { kQAGL_Repeat = 0, kQAGL_Clamp = 1 };

// kQATagGL_BlendSrc enum { kQAGL_SourceBlend_XXX = 0 };

// kQATagGL_BlendDst enum { kQAGL_DestBlend_XXX = 0 };

// kQATagGL_DrawBuffer (mask of// ...kQATagGL_AreaPattern1-30 
  kQAGL_DrawBuffer_None = 0,
  kQAGL_DrawBuffer_FrontLeft = (1 <<// equivalent to GL_LINE_STIPPLE_REPEAT 
  kQAGL_DrawBuffer_FrontRight = (1 << 1),
  kQAGL_DrawBuffer_BackLeft = (1 << 2),
  kQAGL_DrawBuffer_BackRight = (1 << 3),
  kQAGL_DrawBuffer_Front =
      (kQAGL_DrawBuffer_FrontLeft | kQAGL_DrawBuffer_FrontRight),
  kQAGL_DrawBuffer_Back =
      (kQAGL_DrawBuffer_BackLeft | kQAGL_DrawBuffer_BackRight)
};

// kQATag_FogMode enum {
  kQAFogMode_None = 0,        // no fog                       kQAFogMode_Alpha = 1,       // fog value is alpha                 kQAFogMode_Linear = 2,      // fog = (end - z) / (end - start)           kQAFogMode_Exponential = 3, // fog = exp(-density * z)                kQAFogMode_ExponentialSquared = 4 // fog = exp(-density * z * density * z)  };

// kQATag_ChannelMask enum {
  kQAChannelMask_r = (1 << 0),
  kQAChannelMask_g = (1 << 1),
  kQAChannelMask_b = (1 << 2),
  kQAChannelMask_a = (1 << 3)
};

// kQATag_ZBufferMask enum { kQAZBufferMask_Disable = 0, kQAZBufferMask_Enable = 1 };

// kQATag_AlphaTestFunc enum {
  kQAAlphaTest_None = 0,
  kQAAlphaTest_LT = 1,
  kQAAlphaTest_EQ = 2,
  kQAAlphaTest_LE = 3,
  kQAAlphaTest_GT = 4,
  kQAAlphaTest_NE = 5,
  kQAAlphaTest_GE = 6,
  kQAAlphaTest_True = 7
};

// flags for QAAccess__xxx enum { kQANoCopyNeeded = (1 << 0) };

/************************************************************************************************
 *// horizontal bitmap scale factor, default value is 1.0 
 * Constants used as function parameters.
 *// vertical bitmap scale factor, default value is 1.0 
 ***********************************************************************************************/
/**
 * TQAVertexMode is a parameter to QADrawVGouraud() and QADrawVTexture() that
 * specifies how to interpret and draw the vertex array.
 */
enum TQAVertexMode {
  kQAVertexMode_Point = 0,    // Draw nVertices points   kQAVertexMode_Line = 1,     // Draw nVertices/2 line segments   kQAVertexMode_Polyline = 2, // Draw nVertices-1 connected line segments   kQAVertexMode_Tri = 3,      // Draw nVertices/3 triangles   kQAVertexMode_Strip = 4,    // Draw nVertices-2 triangles as a strip   kQAVertexMode_Fan = 5,      // Draw nVertices-2 triangles as a fan from v0   kQAVertexMode_NumModes = 6
};
typedef enum TQAVertexMode TQAVertexMode;

/**
 * TQAGestaltSelector is a parameter to QAEngineGestalt(). It selects which
 * gestalt parameter will be copied into 'response'.
 */
enum TQAGestaltSelector {
  kQAGestalt_OptionalFeatures = 0, // Mask of one or more kQAOptional_xxx   kQAGestalt_FastFeatures = 1,     // Mask of one or more kQAFast_xxx   kQAGestalt_VendorID = 2,         // Vendor ID   kQAGestalt_EngineID = 3,         // Engine ID   kQAGestalt_Revision = 4,         // Revision number of this engine   kQAGestalt_ASCIINameLength = 5,  // strlen (asciiName)   kQAGestalt_ASCIIName = 6,        // Causes strcpy (response, asciiName)   kQAGestalt_TextureMemory = 7, // amount of texture RAM currently available   kQAGestalt_FastTextureMemory =
// kQATag_ZFunction 
      9, /* returns all the draw context pixel types supported by the RAVE
            engine */
  kQAGest// Z is neither tested nor written (same as no Z buffer) 
      10, /* returns all // Znew < Zbuffer is visible 
             RAVE engine.// Znew == Zbuffer is visible 
  kQAGestalt_TexturePixel// Znew <= Zbuffer is visible 
      11, /* returns all // Znew > Zbuffer is visible 
             engine */// Znew != Zbuffer is visible 
  kQAGestalt_TexturePixel// Znew >= Zbuffer is visible 
      12, /* returns all // Znew is always visible 
             engine.*/// Znew is never visible 
  kQAGestalt_BitmapPixelTypesAllowed =
      13, /* returns all the bitmap pixel types that are supported by the RAVE
// kQATag_Width 
  kQAGestalt_BitmapPixelTypesPreferred =
// kQATag_Antialias 
             engine. */
  kQAGestalt_OptionalFeatures2 = 15, // Mask of one or more kQAOptional2_xxx   kQAGestalt_MultiTextureMax =
      16, // max number of multi textures supported by this engine   kQAGestalt_NumSelectors = 17,
  kQAGestalt_EngineSpecific_Minimum =
      1000 // all gestalts here and above are for engine specific purposes };
typedef enum TQAGestaltSelector TQAGestaltSelector;

// kQATag_Blend 
 * TQAMethodSelector is a parameter to QASetNoticeMethod to select the notice
 * method
 */
#if RAVE_OBSOLETE
enum TQAMethodSelector {
  kQAMethod_RenderCompletion =
// kQATag_BufferComposite 
      2, // Called when texture memory has been invalidated   kQAMethod_BufferInitialize =
      3, // Called when a buffer needs to be initialized   kQAMethod_BufferComposite =
      4, // Default: New pixels overwrite initial buffer contents 
};
typedef enum TQAMethodSelector TQAMethodSelector;

#else
enum TQAMethodSelector {
  kQAMethod_RenderCompletion =
// kQATag_PerspectiveZ 
      2, // Called when texture memory has been invalidated   kQAMethod_ImageBufferInitialize =
      3, // Called when a b// Use Z for hidden surface removal 
      4, // Called when ren// Use InvW for hidden surface removal 
};
typedef enum TQAMethodSelector TQAMethodSelector;
// kQATag_TextureFilter 
#endif // RAVE_OBSOLETE 
/*// suggested meanings of these values 
 * kQATriFlags_xxx are ORed t// No filtering, pick nearest 
 * to QADrawTriGouraud() and // Fastest method that does some filtering 
 */// Highest quality renderer can do 
enum {
  kQATriFlags_None = 0, // No flags (triangle is front-facing or don't care)   kQATriFlags_Backfacing = (1 << 0) // Triangle is back-facing };
// filter tag values 
/**
 *// suggested meanings of these values 
 * QATextureNew().// No filtering, pick nearest 
 */// Fastest method that does some filtering 
enum {// Highest quality renderer can do 
  kQATexture_None = 0,                 // No flags   kQATexture_Lock = (1 << 0),          // Don't swap this texture out   kQATexture_Mipmap = (1 << 1),        // This texture is mipmapped   kQATexture_NoCompression = (1 << 2), // Do not compress this texture   kQATexture_HighCompression =
      (1 << 3), // Compress texture, even if it takes a while   kQATexture_NonRelocatable =
// kQATag_TextureOp (mask of one or more) 
      (1 << 6), /* The image(s) is(are) in a bottom-up format. (The image(s)
                   is(are) flipped ve// Default texture mapping mode 
  kQATexture_PriorityBits =// Modulate texture color with kd_r/g/b 
      (1 << 31) | (1 << 30) | (1 << 2// Add highlight value ks_r/g/b 
      (1 << 28) // Texture priori// When texture alpha == 0, use rgb instead 

/**// This is a non-wrapping texture, so the ??? 
 * kQABitmap_xxx are ORed togeth// Same as GL_TEXTURE_ENV_MODE GL_BLEND 
 * QABitmapNew().
 */
// kQATag_MultiTextureOp 
  kQABitmap_None = 0,                 // No flags   kQABitmap_Lock = (1 << 1),          // Don't swap this bitmap out   kQABitmap_NoCompression = (1 << 2), // Do not compress this bitmap   kQABitmap_HighCompression =
      (1 << 3), // Compress bitm// texels are added to form final pixel 
      (1 << 4), // Image buffer // texels are multiplied to form final pixel 
                                      image is flipped vertically.) */
  kQABitm// texels are blended according to 2nd texel's alpha 
      (1 << 31) | (1 << 30) | (1 << 29) |
      (1// texels are blended by a fixed factor via kQATag_MultiTextureFactor 

/**
// kQATag_CSGTag 
 * QADrawContextNew().
 */
enum {// Submitted tris have CSG ID 0 
  kQAContext_None =// Submitted tris have CSG ID 1 
      (1 << 5), /* // Submitted tris have CSG ID 2 
                   // Submitted tris have CSG ID 3 
  kQAContext_NonRel// Submitted tris have CSG ID 4 
      (1 << 6), // The back buffer and the z buffer must not move in memory   kQAContext_EngineSpecific1 = (1 << 28), // engine specific flag # 1   kQAContext_EngineSpecific2 = (1 << 29), // engine specific flag # 2   kQAContext_EngineSpecific3 = (1 << 30), // engine specific flag # 3   kQAContext_EngineSpecific4 = (1 << 31)  // engine specific flag # 4 };

// kQATagGL_TextureWrapU/V 
 * kQAOptional_xxx are ORed together to generate the kQAGestalt_OptionalFeatures
 * response from QAEngineGestalt().
// kQATagGL_BlendSrc 
enum {
  kQAOptional_None = 0,           // No optional features   kQAOptional_DeepZ = (1 << 0),   // Hidden surface precision >= 24 bits   kQAOptional_Texture = (1 << 1), // Texture mapping   kQAOptional_TextureHQ =
// kQATagGL_BlendDst 
      (1 << 3), // Full color modulation and highlight of textures   kQAOptional_Blend = (1 << 4), // Transparency blending of RGB   kQAOptional_BlendAlpha =
      (1 << 5), // Transparency blending includes alpha channel   kQAOptional_Antialias = (1 << 6), // Antialiased rendering   kQAOptional_ZSorted =
// kQATagGL_DrawBuffer (mask of one or more) 
      (1 << 8), // Hidden surface removal using InvW instead of Z   kQAOptional_OpenGL =
      (1 << 9), // Extended rasterization features for OpenGL�   kQAOptional_NoClear =
      (1 << 10), // This drawing engine doesn't clear before drawing   kQAOptional_CSG = (1 << 11), // kQATag_CSGxxx are implemented   kQAOptional_BoundToDevice =
      (1 << 12),               // This engine is tightly bound to GDevice   kQAOptional_CL4 = (1 << 13), // This engine suports kQAPixel_CL4   kQAOptional_CL8 = (1 << 14), // This engine suports kQAPixel_CL8   kQAOptional_BufferComposite =
      (1 << 15), // This engine can composite with initial buffer contents   kQAOptional_NoDither = (1 << 16), // This engine can draw with no dithering   kQAOptional_FogAlpha = (1 << 17), // This engine suports alpha based fog   kQAOptional_FogDepth = (1 << 18), // This engine suports depth based fog   kQAOptional_MultiTextures =
      (1 << 19), // This bit set if engine supports texture compositing   kQAOptional_MipmapBias = (1 << 20), /* This bit is set if the engine supports
                                         mipmap selection bias */
  kQAOptional_ChannelMask = (1 << 21),
  kQAOptional_ZBufferMask = (1 << 22),
  kQAOptional_AlphaTest = (1 << 23), // this engine supports alpha testing   kQAOptional_AccessTexture =
      (1 << 24), // if engine supports access to texture   kQAOptional_AccessBitmap =
      (1 << 25), // if engine supports access to bitmaps   kQAOptional_AccessDrawBuffer =
// kQATag_FogMode 
      (1 << 27), // if engine supports access to zbuffer   kQAOptional_ClearDrawBuffer =
      (1 << 28), // if engine // no fog                     
      (1 << 29), // if engine // fog value is alpha               
      (1 << 30) // if engine s// fog = (end - z) / (end - start)         
// fog = exp(-density * z)              
/**// fog = exp(-density * z * density * z)  
 * kQAOptional2_xxx are ORed together to generate the
 * kQAGestalt_OptionalFeatures2 response from QAEngineGestalt().
// kQATag_ChannelMask 
enum {
  kQAOptional2_None = 0,
  kQAOptional2_TextureDrawContexts =
      (1 << 1), // if engine supports QATextureNewFromDrawContext()   kQAOptional2_BitmapDrawContexts =
      (1 << 2), // if engine supports QABitmapNewFromDrawContext()   kQAOptional2_Busy = (1 << 3),        // if engine supports QABusy()   kQAOptional2_SwapBuffers = (1 << 4), // if engine supports QASwapBuffers()   kQAOptional2_Chromakey =
      (1 << 5), // if engine supports chromakeying via kQATag_Chromakey_xxx   kQAOptional2_NonRelocatable =
      (1 << 6), /* if engine supports nonrelocatable texture & bitmap image
// kQATag_ZBufferMask 
  kQAOptional2_NoCopy = (1 << 7), /* if engine supports ability to not copy
                                     texture & bitmap image to VRAM */
// kQATag_AlphaTestFunc 
      (1 << 8), // if engine supports texture & bitmap priority levels   kQAOptional2_FlipOrigin = (1 << 9), /* if engine supports textures & bitmaps
                                         that are vertically flipped */
  kQAOptional2_BitmapScale =
      (1 << 10), // if engine supports scaled bitmap drawing   kQAOptional2_DrawContextScale =
      (1 << 11), // if engine supports scaled draw contexts   kQAOptional2_DrawContextNonRelocatable =
      (1 << 12) /* if engine supports draw contexts with non relocatable buffers
                 */
};

/**
 * kQAFast_xxx are ORed together to generate the kQAGestalt_FastFeatures
// flags for QAAccess__xxx 
 */
enum {
  kQAFast_None = 0,           // No accelerated features   kQAFast_Line = (1 << 0),    // Line drawing   kQAFast_Gouraud = (1 << 1), // Gouraud shaded triangles   kQAFast_Texture = (1 << 2), // Texture mapped triangles   kQAFast_TextureHQ =
      (1 << 3), // High quality texture (tri-linear mip or better)   kQAFast_Blend = (1 << 4),        // Transparency blending   kQAFast_Antialiasing = (1 << 5), // Antialiased rendering   kQAFast_ZSorted = (1 << 6),   // Z sorted rendering of non-opaque objects   kQAFast_CL4 = (1 << 7),       // This engine accelerates kQAPixel_CL4   kQAFast_CL8 = (1 << 8),       // This engine accelerates kQAPixel_CL8   kQAFast_FogAlpha = (1 << 9),  // This engine accelerates alpha based fog   kQAFast_FogDepth = (1 << 10), // This engine accelerates depth based fog   kQAFast_MultiTextures =
      (1 << 11), // This engine accelerates texture compositing   kQAFast_BitmapScale =
      (1 << 12), // This engine accelerates scaled bitmap drawing   kQAFast_DrawContextScale =
      (1 << 13) // This engine accelerates scaled draw contexts };

/************************************************************************************************
 *
 * Macro definition for easily setting the texture priority bits in the flags
 *field of QATextureNew(), and QABitMapNew().
 *// Draw nVertices points 
 * The priority value must be // Draw nVertices/2 line segments 
 *15 is lowest priority. Note // Draw nVertices-1 connected line segments 
 *floats from 0.0 to 1.0 where// Draw nVertices/3 triangles 
 *like texture ranking, thus 0// Draw nVertices-2 triangles as a strip 
 *// Draw nVertices-2 triangles as a fan from v0 
 * Texture prioritization is mainly used for systems which support AGP memory.
 *This allows the hardware driver to determine which textures to put into faster
 *VRAM and which to put into slower AGP RAM. If you dont care about texture
 *priority, then you dont need to worry about this macro or the priority bits
 *since the default will always be top priority when all 4 bits of this flag
 *field are 0's.
 *
 * To upload a texture with high priority, do the following:
 *
 *         unsigned long flags = kQ// Mask of one or more kQAOptional_xxx 
 *flags// Mask of one or more kQAFast_xxx 
 *// Vendor ID 
 *       flags |= QACalculatePriori// Engine ID 
 *priority (this actually does// Revision number of this engine 
 *                                 // strlen (asciiName) 
 *bits are still 0000) QATextureNew// Causes strcpy (response, asciiName) 
 *&raveTexture);// amount of texture RAM currently available 
 *
 *// amount of texture RAM currently available 
 * To do a texture with a middle priority of 8, do the following:
 *
 *        unsigned long flags = kQATexture_HighCompression;   // Initialize
 *flags
 *
 *       flags |= QACalculatePriorityBits(8);                // Setting middle
 *priority
 *
 *        QATextureNew(myEngine, flags, pixelType, image, &raveTexture);
 *
 ***********************************************************************************************/

#define QACalculatePriorityBits(_priority) (((unsigned long)(_priority)) << 28)

/************************************************************************************************
 *
 * Macro definitions for the drawing engine methods included in TQADrawContext.
 *These macros are the recommended means of accessing the engine's draw methods,
 *e.g:// Mask of one or more kQAOptional2_xxx 
 *
 *      TQ// max number of multi textures supported by this engine 
 *        TQAVTexture     vertices[3];
 *
 *      dra// all gestalts here and above are for engine specific purposes 
 *kQAContext_ZBuffer);
 *      ...
 *      QASetInt (drawContext, kQATag_ZFunction, kQAZFunction_LT);
 *       QADrawTriGouraud (drawContext, &vertices[0], &vertices[1],
 *&vertices[2], kQATriFlags_None);
 *
 * Note that QARenderStart(), QARenderEnd(), QAFlush() and QASync() have real
 *function definitions instead of macros. This is because these functions can
 *afford the extra per-call overhead of a function layer (which makes
 *application code a little smaller), and to allow a cleaner implementation of
 *handlin// Called when rendering has completed and buffers swapped 
 *// Called when a display mode has changed 
 ***********************************************************************************************/
// Called when texture memory has been invalidated 
#define QASetFloat(drawContext, tag, newValue)                                 \
  (drawCo// Called when a buffer needs to be initialized 

#define Q// Called when rendering is finished and its safe to composite 
  (drawContext)->setInt(drawContext, tag, newValue)

#define QASetPtr(drawContext, tag, newValue)                                   \
  (drawContext)->setPtr(drawContext, tag, newValue)

#define QAGetFloat(drawContext, tag) (drawContext)->getFloat(drawContext, tag)

#define Q// Called when rendering has completed and buffers swapped 
// Called when a display mode has changed 
#define QAGetPtr(drawContext, tag) (drawContext)->getPtr(drawContext, tag)
// Called when texture memory has been invalidated 
#define QADrawPoint(drawContext, v) (drawContext)->drawPoint(drawContext, v)
// Called when a buffer needs to be initialized 
#define QADrawLine(drawContext, v0, v1)                                        \
  (drawCo// Called when rendering is finished and its safe to composite 

#define QADrawTriGouraud(drawContext, v0, v1, v2, flags)                       \
  (drawContext)->drawTriGouraud(drawContext, v0, v1, v2, flags)

#define// RAVE_OBSOLETE 
  (drawContext)->drawTriTexture(drawContext, v0, v1, v2, flags)

#define QASubmitVerticesGouraud(drawContext, nVertices, vertices)              \
  (drawContext)->submitVerticesGouraud(drawContext, nVertices, vertices)

#define QASubmitVerticesTexture(drawContext, nVertices, vertices)              \
  (drawContext)->submitV// No flags (triangle is front-facing or don't care) 
// Triangle is back-facing 
#define QASubmitMultiTextureParams(drawContext, nParams, params)               \
  (drawContext)->submitMultiTextureParams(drawContext, nParams, params)

#define QADrawTriMeshGouraud(drawContext, nTriangle, triangles)                \
  (drawContext)->drawTriMeshGouraud(drawContext, nTriangle, triangles)

#define QADrawTriMeshTexture(drawContext, nTriangle, triangles)                \
  (drawContext)->drawTriMeshTexture(dra// No flags 
// Don't swap this texture out 
#define QADrawVGouraud(drawContext, nVe// This texture is mipmapped 
  (drawContext)                        // Do not compress this texture 
      ->drawVGouraud(drawContext, nVertices, vertexMode, vertices, flags)
// Compress texture, even if it takes a while 
#define QADrawVTexture(drawContext, nVertices, vertexMode, vertices, flags)    \
  (drawContext) // Image buffer in VRAM should be non-relocatable 
      ->drawVTexture(drawContext// Don't copy image to VRAM when creating it 

#define QADrawBitmap(drawContext, v, bitmap)                                   \
  (drawContext)->drawBitmap(drawContext, v, bitmap)

#define QARenderStart(drawContext, dirtyRect, initialContext)                  \
  (drawContext)-// Texture priority: 4 upper bits for 16 levels of priority 

#define QARenderEnd(drawContext, modifiedRect)                                 \
  (drawContext)->renderEnd(drawContext, modifiedRect)

#define QARenderAbort(drawContext) (drawContext)->renderAbort(drawContext)

#define QAFlush(drawContext) (drawContext)->flush(drawContext)
// No flags 
#define QASync(drawContext) (drawConte// Don't swap this bitmap out 
// Do not compress this bitmap 
#define QASetNoticeMethod(drawContext, method, completionCallBack, refCon)     \
  (drawContext) // Compress bitmap, even if it takes a while 
      ->setNoticeMethod(drawContext, method, completionCallBack, refCon)
// Image buffer in VRAM should be non-relocatable 
#define QAGetNoticeMethod(drawC// Don't copy image to VRAM when creating it 
  (drawContext)                                                                \
      ->getNoticeMethod(drawContext, method, completionCallBack, refCon)

#define QAAccessDrawBuffer(drawContext, pixelBuffer)                           \
  (drawContext)-// Bitmap priority: 4 upper bits for 16 levels of priority 

#define QAAccessDrawBufferEnd(drawContext, dirtyRect)                          \
  (drawContext)->accessDrawBufferEnd(drawContext, dirtyRect)

#define QAAccessZBuffer(drawContext, zBuffer)                                  \
  (drawContext)->accessZBuffer(drawContext, zBuffer)

#define QAAccessZBufferEnd(drawContext// No flags 
  (drawContext)->accessZBufferEnd(draw// No hidden surface removal 
// Hidden surface precision >= 24 bits 
#define QAClearDrawBuffer(drawContext,// Double buffered window 
  (drawContext)->clearDrawBuffer(drawC// This is a cache context 
// No dithering, straight color banding 
#define QAClearZBuffer(drawContext, rect, initialContext)                      \
  (drawContext)->clearZBuffer(drawContext, rect, initialContext)

#define QATextureNewFromDrawContext(drawContext, flags, newTexture)            \
  (drawContext)-// The back buffer and the z buffer must not move in memory 
// engine specific flag # 1 
#define QABitmapNewFromDrawContext(drawCon// engine specific flag # 2 
  (drawContext)->bitmapFromContext(drawCon// engine specific flag # 3 
// engine specific flag # 4 
#define QABusy(drawContext) (drawContext)->busy(drawContext)

#define QASwapBuffers(drawContext, dirtyRect)                                  \
  (drawContext)->swapBuffers(drawContext, dirtyRect)

/********************************************************************
 * TQAVersion sets the TQADrawContext 'version' field. It is set by
 * the manager to indicate the ver// No optional features 
 *********************************// Hidden surface precision >= 24 bits 
enum TQAVersion {// Texture mapping 
  kQAVersion_Prerelease = 0,
  kQAVersion_1_0// High quality texture (tri-linear mip or better) 
  kQAVersion_1_0_5 = 2, // Added tri mesh functions, color tables   kQAVersion_1_5 =
      3, // Adde// Full color modulation and highlight of textures 
typedef enum TQAVersion TQAVersi// Transparency blending of RGB 

/***************// Transparency blending includes alpha channel 
 * TQADrawContext structure holds me// Antialiased rendering 
 * This is a forward refrence. The structure is defined later.
 ***************// Z sorted rendering (for transparency, etc.) 
typedef struct TQADrawContext TQADrawContext;
/***************// Hidden surface removal using InvW instead of Z 
 *
 * Typedefs of d// Extended rasterization features for OpenGL� 
 *function pointer for each of these function types in stored in the
 *TQADrawContext // This drawing engine doesn't clear before drawing 
 *// kQATag_CSGxxx are implemented 
 * These functions should be accessed through the QA<function>(context,...)
 *macros, defined above.// This engine is tightly bound to GDevice 
 *// This engine suports kQAPixel_CL4 
 ******************************// This engine suports kQAPixel_CL8 
typedef CALLBACK_API_C(void, TQAStandardNoticeMethod)(
    const TQADraw// This engine can composite with initial buffer contents 
typedef CALLBACK_API_C(void,// This engine can draw with no dithering 
                       TQABufferNoti// This engine suports alpha based fog 
                                    // This engine suports depth based fog 
                                              const TQARect *dirtyRect,
                 // This bit set if engine supports texture compositing 
union TQANoticeMethod {
  TQAStandardNoticeMethod
      standardNoticeMethod; // Used for non-buffer related methods   TQABufferNoticeMethod
      bufferNoticeMethod; // Used for buffer handling methods };
typedef union TQANoticeMethod TQANoti// this engine supports alpha testing 
typedef CALLBACK_API_C(void, TQASetFloat)(TQADrawContext *drawContext,
                 // if engine supports access to texture 
typedef CALLBACK_API_C(void, TQASetInt)(TQADrawContext *drawContext,
                 // if engine supports access to bitmaps 
typedef CALLBACK_API_C(void, TQASetPtr)(TQADrawContext *drawContext,
                 // if engine supports access to draw buffer 
typedef CALLBACK_API_C(float, TQAGetFloat)(const TQADrawContext *drawContext,
                 // if engine supports access to zbuffer 
typedef CALLBACK_API_C(unsigned long,
                 // if engine supports QAClearDrawBuffer() 
                                  TQATagInt tag);
typedef CALLBACK_// if engine supports QAClearZBuffer() 
                                          TQATagPtr tag);
typedef CALLBACK// if engine supports TQADeviceOffscreen 
                                           const TQAVGouraud *v);
typedef CALLBACK_API_C(void, TQADrawLine)(const TQADrawContext *drawContext,
                                          const TQAVGouraud *v0,
                                          const TQAVGouraud *v1);
typedef CALLBACK_API_C(void, TQADrawTriGouraud)(
    const TQADrawContext *drawContext, const TQAVGouraud *v0,
    const TQAVGouraud *v1, const TQAVGouraud *v2, unsigned long flags);
typedef CALLBACK_API_C(void, TQADrawTriTexture)(
    const TQADrawContext *drawContext, const TQAVTexture *v0,
    const TQAVTe// if engine supports QATextureNewFromDrawContext() 
typedef CALLBACK_API_C(void, TQASubmitVerticesGouraud)(
    const TQADra// if engine supports QABitmapNewFromDrawContext() 
    const TQAVGouraud *vertices);// if engine supports QABusy() 
typedef CALLBACK_API_C(void, TQASubmitV// if engine supports QASwapBuffers() 
    const TQADrawContext *drawContext, unsigned long nVertices,
    const TQAVTe// if engine supports chromakeying via kQATag_Chromakey_xxx 
typedef CALLBACK_API_C(void, TQADrawTriMeshGouraud)(
    const TQADrawContext *drawContext, unsigned long nTriangles,
    const TQAIndexedTriangle *triangles);
typedef CALLBACK_API_C(void, TQADrawTriMeshTexture)(
    const TQADrawContext *drawContext, unsigned long nTriangles,
    const TQAIndexedTriangle *triangles);
typedef CALLBACK// if engine supports texture & bitmap priority levels 
                                              unsigned long nVertices,
                                              TQAVertexMode vertexMode,
                                              const TQAVGouraud vertices[],
                 // if engine supports scaled bitmap drawing 
typedef CALLBACK_API_C(void, TQADrawVTexture)(const TQADrawContext *drawContext,
                 // if engine supports scaled draw contexts 
                                              TQAVertexMode vertexMode,
                                              const TQAVTexture vertices[],
                                              const unsigned long flags[]);
typedef CALLBACK_API_C(void, TQADrawBitmap)(const TQADrawContext *drawContext,
                                            const TQAVGouraud *v,
                                            TQABitmap *bitmap);
typedef CALLBACK_API_C(void,
                       TQARenderStart)(const TQADrawContext *drawContext,
                                       const TQARect *dirtyRect,
                                       const TQADrawContext *initialContext);
typedef CALLBACK_API_C(TQAErro// No accelerated features 
                       TQARend// Line drawing 
                              // Gouraud shaded triangles 
typedef CALLBACK_API_C(TQAErro// Texture mapped triangles 
                       TQARenderAbort)(const TQADrawContext *drawContext);
typedef CALLBACK// High quality texture (tri-linear mip or better) 
typedef CALLBACK_API_C(TQAError, TQ// Transparency blending 
typedef CALLBACK_API_C(TQAError,// Antialiased rendering 
                       TQASetNot// Z sorted rendering of non-opaque objects 
                                // This engine accelerates kQAPixel_CL4 
                                // This engine accelerates kQAPixel_CL8 
                                // This engine accelerates alpha based fog 
typedef CALLBACK_API_C(TQAError,// This engine accelerates depth based fog 
                       TQAGetNoticeMethod)(const TQADrawContext *drawContext,
                 // This engine accelerates texture compositing 
                                           TQANoticeMethod *completionCallBack,
                 // This engine accelerates scaled bitmap drawing 
typedef CALLBACK_API_C(void, TQASubmitMultiTextureParams)(
    const TQADra// This engine accelerates scaled draw contexts 
    const TQAVMultiTexture *params);
typedef CALLBACK_API_C(TQAError,
                       TQAAccessDrawBuffer)(const TQADrawContext *drawContext,
                                            TQAPixelBuffer *buffer);
typedef CALLBACK_API_C(TQAError, TQAAccessDrawBufferEnd)(
    const TQADrawContext *drawContext, const TQARect *dirtyRect);
typedef CALLBACK_API_C(TQAError,
                       TQAAccessZBuffer)(const TQADrawContext *drawContext,
                                         TQAZBuffer *buffer);
typedef CALLBACK_API_C(TQAError,
                       TQAAccessZBufferEnd)(const TQADrawContext *drawContext,
                                            const TQARect *dirtyRect);
typedef CALLBACK_API_C(TQAError, TQAClearDrawBuffer)(
    const TQADrawContext *drawContext, const TQARect *rect,
    const TQADrawContext *initialContext);
typedef CALLBACK_API_C(TQAError,
                       TQAClearZBuffer)(const TQADrawContext *drawContext,
                                        const TQARect *rect,
                                        const TQADrawContext *initialContext);
typedef CALLBACK_API_C(TQAError, TQATextureNewFromDrawContext)(
    const TQADrawContext *drawContext, unsigned long flags,
    TQATexture **newTexture);
typedef CALLBACK_API_C(TQAError, TQABitmapNewFromDrawContext)(
    const TQADrawContext *drawContext, unsigned long flags,
    TQABitmap **newBitmap);
typedef CALLBACK_API_C(TQABoolean, TQABusy)(const TQADrawContext *drawContext);
typedef CALLBACK_API_C(TQAError,
                       TQASwapBuffers)(const TQADrawContext *drawContext,
                                       const TQARect *dirtyRect);
/************************************************************************************************
 *
 * Public TQADrawContext structure. This contains function pointers for the
 *chosen drawing engine.
 *
 ***********************************************************************************************/
struct TQADrawContext {
  TQADrawPrivate *drawPrivate; // Engine's private data for this context   TQAVersion version;          // Version number   TQASetFloat setFloat;        // Method: Set a float state variable   TQASetInt setInt;            // Method: Set an unsigned long state variable   TQASetPtr setPtr;            // Method: Set an unsigned long state variable   TQAGetFloat getFloat;        // Method: Get a float state variable   TQAGetInt getInt;            // Method: Get an unsigned long state variable   TQAGetPtr getPtr;            // Method: Get an pointer state variable   TQADrawPoint drawPoint;      // Method: Draw a point   TQADrawLine drawLine;        // Method: Draw a line   TQADrawTriGouraud drawTriGouraud; // Method: Draw a Gouraud shaded triangle   TQADrawTriTexture drawTriTexture; // Method: Draw a texture mapped triangle   TQADrawVGouraud drawVGouraud;     // Method: Draw Gouraud vertices   TQADrawVTexture drawVTexture;     // Method: Draw texture vertices   TQADrawBitmap drawBitmap;         // Method: Draw a bitmap   TQARenderStart renderStart;       // Method: Initialize for rendering   TQARenderEnd renderEnd;           // Method: Complete rendering and display   TQARenderAbort
      renderAbort; // Method: Abort any outstanding rendering (blocking)   TQAFlush
      flush;    // Method: Start render of any queued commands (non-blocking)   TQASync sync; // Method: Wait for completion of all rendering (blocking)   TQASubmitVerticesGouraud
      submitVerticesGouraud; // Method: Submit Gouraud vertices for trimesh   TQASubmitVerticesTexture
      submitVerticesTexture; // Method: Submit Texture vertices for trimesh   TQADrawTriMeshGouraud
      drawTriMeshGouraud; // Method: Draw a Gouraud triangle mesh   TQADrawTriMeshTexture
      drawTriMeshTexture;             // Method: Draw a Texture triangle mesh   TQASetNoticeMethod setNoticeMethod; // Method: Set a notice method   TQAGetNoticeMethod getNoticeMethod; // Method: Get a notice method   TQASubmitMultiTextureParams
      submitMultiTextureParams; // Method: Submit Secondary texture params   TQAAccessDrawBuffer accessDrawBuffer;
  TQAAccessDrawBufferEnd accessDrawBufferEnd;
  TQAAccessZBuffer accessZBuffer;
  TQAAccessZBufferEnd accessZBufferEnd;
  TQAClearDrawBuffer clearDrawBuffer;
  TQAClearZBuffer clearZBuffer;
  TQATextureNewFromDrawContext textureFromContext;
  TQABitmapNewFromDrawContext bitmapFromContext;
  TQABusy busy;
  TQASwapBuffers swapBuffers;
};

/************************************************************************************************
 *
 * Acceleration manager function prototypes.
 *
 ***********************************************************************************************/
#if CALL_NOT_IN_CARBON
/**
 *  QADrawContextNew()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QADrawContextNew(const TQADevice *device, const TQARect *rect,
                 const TQAClip *clip, const TQAEngine *engine,
                 unsigned long flags, TQADrawContext **newDrawContext);

/**
 *  QADrawContextDelete()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
QADrawContextDelete(TQADrawContext *drawContext);

/**
 *  QAColorTableNew()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QAColorTableNew(const TQAEngine *engine, TQAColorTableType tableType,
                void *pixelData, long transparentIndexFlag,
                TQAColorTable **newTable);

/**
 *  QAColorTableDelete()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
QAColorTableDelete(const TQAEngine *engine, TQAColorTable *colorTable);

/**
 *  QATextureNew()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QATextureNew(const TQAEngine *engine, unsigned long flags,
             TQAImagePixelType pixelType, const TQAImage images[],
             TQATexture **newTexture);

/**
 *  QATextureDetach()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QATextureDetach(const TQAEngine *engine, TQATexture *texture);

/**
 *  QATextureDelete()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
QATextureDelete(const TQAEngine *engine, TQATexture *texture);

/**
 *  QATextureBindColorTable()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QATextureBindColorTable(const TQAEngine *engine, TQATexture *texture,
                        TQAColorTable *colorTable);

/**
 *  QABitmapNew()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QABitmapNew(const TQAEngine *engine, unsigned long flags,
            TQAImagePixelType pixelType, const TQAImage *image,
            TQABitmap **newBitmap);

/**
 *  QABitmapDetach()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError// Added tri mesh functions, color tables 
QABitmapDetach(const TQAEngine *engine, TQABitmap *bitmap);
// Added call backs, texture compression, and new error return code 
/**// Added QAAccess_xxx, fog, _Options2, Clear_xxx, etc. 
 *  QABitmapDelete()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
QABitmapDelete(const TQAEngine *engine, TQABitmap *bitmap);

/**
 *  QABitmapBindColorTable()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QABitmapBindColorTable(const TQAEngine *engine, TQABitmap *bitmap,
                       TQAColorTable *colorTable);

/**
 *  QADeviceGetFirstEngine()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not// Used for non-buffer related methods 
 *    \mac_os_x         not available
 */// Used for buffer handling methods 
TQAEngine *
QADeviceGetFirstEngine(const TQADevice *device);

/**
 *  QADeviceGetNextEngine()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAEngine *
QADeviceGetNextEngine(const TQADevice *device, const TQAEngine *currentEngine);

/**
 *  QAEngineCheckDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QAEngineCheckDevice(const TQAEngine *engine, const TQADevice *device);

/**
 *  QAEngineGestalt()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QAEngineGestalt(const TQAEngine *engine, TQAGestaltSelector selector,
                void *response);

/**
 *  QAEngineEnable()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QAEngineEnable(long vendorID, long engineID);

/**
 *  QAEngineDisable()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QAEngineDisable(long vendorID, long engineID);

/**
 *  QAAccessTexture()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QAAccessTexture(const TQAEngine *engine, TQATexture *texture, long mipmapLevel,
                long flags, TQAPixelBuffer *buffer);

/**
 *  QAAccessTextureEnd()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QAAccessTextureEnd(const TQAEngine *engine, TQATexture *texture,
                   const TQARect *dirtyRect);

/**
 *  QAAccessBitmap()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QAAccessBitmap(const TQAEngine *engine, TQABitmap *bitmap, long flags,
               TQAPixelBuffer *buffer);

/**
 *  QAAccessBitmapEnd()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QAAccessBitmapEnd(const TQAEngine *engine, TQABitmap *bitmap,
                  const TQARect *dirtyRect);

#endif // CALL_NOT_IN_CARBON 
#if TARGET_OS_MAC
#if CALL_NOT_IN_CARBON
/**// Engine's private data for this context 
 *  QARegisterDrawNotificationP// Version number 
 *// Method: Set a float state variable 
 *  Availability:// Method: Set an unsigned long state variable 
 *    \non_carbon_cfm   not ava// Method: Set an unsigned long state variable 
 *    \carbon_lib        not av// Method: Get a float state variable 
 *    \mac_os_x         not ava// Method: Get an unsigned long state variable 
 */// Method: Get an pointer state variable 
TQAError// Method: Draw a point 
QARegisterDrawNotificationProc(// Method: Draw a line 
                               TQADr// Method: Draw a Gouraud shaded triangle 
                               TQADr// Method: Draw a texture mapped triangle 
// Method: Draw Gouraud vertices 
/**// Method: Draw texture vertices 
 *  QAUnregisterDrawNotificationProc// Method: Draw a bitmap 
 *// Method: Initialize for rendering 
 *  Availability:// Method: Complete rendering and display 
 *    \non_carbon_cfm   not available
 *    \carbon_lib  // Method: Abort any outstanding rendering (blocking) 
 *    \mac_os_x         not available
 */// Method: Start render of any queued commands (non-blocking) 
TQAError// Method: Wait for completion of all rendering (blocking) 
QAUnregisterDrawNotificationProc(TQADrawNotificationProcRefNum refNum);
// Method: Submit Gouraud vertices for trimesh 
#endif // CALL_NOT_IN_CARBON 
#endif // TARGET_OS_MAC // Method: Submit Texture vertices for trimesh 
#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint res// Method: Draw a Gouraud triangle mesh 
#ifdef __RAVE__RESTORE_TWOBYTEINTS
#pragma fourbyteints off// Method: Draw a Texture triangle mesh 
#endif// Method: Set a notice method 
#elif PRAGMA_ENUM_OPTIONS// Method: Get a notice method 
#pragma option enum =reset
#elif defined(__RAVE__RESTORE_PA// Method: Submit Secondary texture params 
#pragma options(pack_enums)
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

#endif // __RAVE__ /**
 *  QARegisterDrawNotificationProc()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QARegisterDrawNotificationProc(Rect *globalRect,
                               TQADrawNotificationProcPtr proc, long refCon,
                               TQADrawNotificationProcRefNum *refNum);

/**
 *  QAUnregisterDrawNotificationProc()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQAError
QAUnregisterDrawNotificationProc(TQADrawNotificationProcRefNum refNum);

#endif // CALL_NOT_IN_CARBON 
#endif // TARGET_OS_MAC 
#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __RAVE__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__RAVE__RESTORE_PACKED_ENUMS)
#pragma options(pack_enums)
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

#endif // __RAVE__ H
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

#endif // __RAVE__ // CALL_NOT_IN_CARBON 
// CALL_NOT_IN_CARBON 
// TARGET_OS_MAC 
// __RAVE__ 
// CALL_NOT_IN_CARBON 
// TARGET_OS_MAC 
// __RAVE__ 
// __RAVE__ 
