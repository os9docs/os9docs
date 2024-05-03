/**
     \file       CMApplication.h

    \brief   Color Matching Interfaces

    \introduced_in  ColorSync 3.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1992-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup ColorSync

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CMAPPLICATION__
#define __CMAPPLICATION__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __CMICCPROFILE__
#include <CMICCProfile.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __CMTYPES__
#include <CMTypes.h>
#endif

#ifndef __CFSTRING__
#include <CFString.h>
#endif

#ifndef __CFDICTIONARY__
#include <CFDictionary.h>
#endif

#define _DECLARE_CS_QD_API_ 1
#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#if TARGET_API_MAC_OS8
#ifndef __PRINTING__
#include <Printing.h>
#endif

#endif // TARGET_API_MAC_OS8
#if TARGET_OS_WIN32
#include <windows.h>
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
        kDefaultCMMSignature = FOUR_CHAR_CODE('appl')
    };

    // Macintosh 68K trap word   enum
    {
        cmTrap = 0xABEE};

    // PicComment IDs   enum
    {
        cmBeginProfile = 220,
        cmEndProfile = 221,
        cmEnableMatching = 222,
        cmDisableMatching = 223,
        cmComment = 224};

    // PicComment selectors for cmComment   enum
    {
        cmBeginProfileSel = 0,
        cmContinueProfileSel = 1,
        cmEndProfileSel = 2,
        cmProfileIdentifierSel = 3};

    // Defines for version 1.0 CMProfileSearchRecord.fieldMask   enum
    {
        cmMatchCMMType = 0x00000001,
        cmMatchApplProfileVersion = 0x00000002,
        cmMatchDataType = 0x00000004,
        cmMatchDeviceType = 0x00000008,
        cmMatchDeviceManufacturer = 0x00000010,
        cmMatchDeviceModel = 0x00000020,
        cmMatchDeviceAttributes = 0x00000040,
        cmMatchFlags = 0x00000080,
        cmMatchOptions = 0x00000100,
        cmMatchWhite = 0x00000200,
        cmMatchBlack = 0x00000400};

    // Defines for version 2.0 CMSearchRecord.searchMask   enum
    {
        cmMatchAnyProfile = 0x00000000,
        cmMatchProfileCMMType = 0x00000001,
        cmMatchProfileClass = 0x00000002,
        cmMatchDataColorSpace = 0x00000004,
        cmMatchProfileConnectionSpace = 0x00000008,
        cmMatchManufacturer = 0x00000010,
        cmMatchModel = 0x00000020,
        cmMatchAttributes = 0x00000040,
        cmMatchProfileFlags = 0x00000080};

    // Flags for PostScript-related functions   enum
    {
        cmPS7bit = 1,
        cmPS8bit = 2};

    // Flags for profile embedding functions   enum
    {
        cmEmbedWholeProfile = 0x00000000,
        cmEmbedProfileIdentifier = 0x00000001};

    // Commands for CMFlattenUPP()   enum
    {
        cmOpenReadSpool = 1,
        cmOpenWriteSpool = 2,
        cmReadSpool = 3,
        cmWriteSpool = 4,
        cmCloseSpool = 5};

    // Commands for CMAccessUPP()   enum
    {
        cmOpenReadAccess = 1,
        cmOpenWriteAccess = 2,
        cmReadAccess = 3,
        cmWriteAccess = 4,
        cmCloseAccess = 5,
        cmCreateNewAccess = 6,
        cmAbortWriteAccess = 7,
        cmBeginAccess = 8,
        cmEndAccess = 9};

    // Use types for CMGet/SetDefaultProfileByUse()   enum
    {
        cmInputUse = FOUR_CHAR_CODE('inpt'),
        cmOutputUse = FOUR_CHAR_CODE('outp'),
        cmDisplayUse = FOUR_CHAR_CODE('dply'),
        cmProofUse = FOUR_CHAR_CODE('pruf')};

    // Union of 1.0 and 2.0 profile header variants   union CMAppleProfileHeader
    {
        CMHeader cm1;
        CM2Header cm2;
    };
    typedef union CMAppleProfileHeader CMAppleProfileHeader;
    // CWConcatColorWorld() definitions   struct CMConcatProfileSet
    {
        UInt16 keyIndex; // Zero-based     UInt16 count;               // Min 1     CMProfileRef profileSet[1]; // Variable. Ordered from Source -> Dest
    };
    typedef struct CMConcatProfileSet CMConcatProfileSet;
    // NCWConcatColorWorld() definitions   struct NCMConcatProfileSpec
    {
        UInt32 renderingIntent; // renderingIntent override     UInt32 transformTag;    // transform enumerations defined below     CMProfileRef profile;   // profile
    };
    typedef struct NCMConcatProfileSpec NCMConcatProfileSpec;
    struct NCMConcatProfileSet
    {
        OSType cmm;      // e.g. 'KCMS', 'appl', ...  uniquely ids the cmm, or 0000     UInt32 flags;        // specify quality, lookup only, no gamut checking ...     UInt32 flagsMask;    // which bits of 'flags' to use to override profile     UInt32 profileCount; // how many ProfileSpecs in the following set     NCMConcatProfileSpec
        profileSpecs[1]; // Variable. Ordered from Source -> Dest
    };
    typedef struct NCMConcatProfileSet NCMConcatProfileSet;
    enum
    {
        kNoTransform = 0, /** used */
        kUseAtoB = 1      /** 'A2B*' */
                   tag from this profile or
                   equivalent kUseBtoA = 2 /** 'B2A*' */
                                         tag from this profile or
                                         equivalent kUseBtoB = 3 /** 'pre*' */
                                                               tag from this profile or
                                                               equivalent                                        // For typical device profiles the following synonyms may be useful     kDeviceToPCS  =  kUseAtoB  /** Dependent */
                                                                   to Device Independent kPCSToDevice = kUseBtoA /** Independent */
                                                                   to Device Dependent kPCSToPCS = kUseBtoB      // Independent, through device's gamut     kUseProfileIntent =
        (long) 0xFFFFFFFF                                                                                        // For renderingIntent in NCMConcatProfileSpec
    };

    // ColorSync color data types   struct CMRGBColor
    {
        UInt16 red; // 0..65535     UInt16 green;
        UInt16 blue;
    };
    typedef struct CMRGBColor CMRGBColor;
    struct CMCMYKColor
    {
        UInt16 cyan; // 0..65535     UInt16 magenta;
        UInt16 yellow;
        UInt16 black;
    };
    typedef struct CMCMYKColor CMCMYKColor;
    struct CMCMYColor
    {
        UInt16 cyan; // 0..65535     UInt16 magenta;
        UInt16 yellow;
    };
    typedef struct CMCMYColor CMCMYColor;
    struct CMHLSColor
    {
        UInt16 hue; // 0..65535. Fraction of circle. Red at 0     UInt16 lightness;  // 0..65535     UInt16 saturation; // 0..65535
    };
    typedef struct CMHLSColor CMHLSColor;
    struct CMHSVColor
    {
        UInt16 hue; // 0..65535. Fraction of circle. Red at 0     UInt16 saturation; // 0..65535     UInt16 value;      // 0..65535
    };
    typedef struct CMHSVColor CMHSVColor;
    struct CMLabColor
    {
        UInt16 L; // 0..65535 maps to 0..100     UInt16 a; // 0..65535 maps to -128..127.996     UInt16 b; // 0..65535 maps to -128..127.996
    };
    typedef struct CMLabColor CMLabColor;
    struct CMLuvColor
    {
        UInt16 L; // 0..65535 maps to 0..100     UInt16 u; // 0..65535 maps to -128..127.996     UInt16 v; // 0..65535 maps to -128..127.996
    };
    typedef struct CMLuvColor CMLuvColor;
    struct CMYxyColor
    {
        UInt16 capY; // 0..65535 maps to 0..1     UInt16 x;    // 0..65535 maps to 0..1     UInt16 y;    // 0..65535 maps to 0..1
    };
    typedef struct CMYxyColor CMYxyColor;
    struct CMGrayColor
    {
        UInt16 gray; // 0..65535
    };
    typedef struct CMGrayColor CMGrayColor;
    struct CMMultichannel5Color
    {
        UInt8 components[5]; // 0..255
    };
    typedef struct CMMultichannel5Color CMMultichannel5Color;
    struct CMMultichannel6Color
    {
        UInt8 components[6]; // 0..255
    };
    typedef struct CMMultichannel6Color CMMultichannel6Color;
    struct CMMultichannel7Color
    {
        UInt8 components[7]; // 0..255
    };
    typedef struct CMMultichannel7Color CMMultichannel7Color;
    struct CMMultichannel8Color
    {
        UInt8 components[8]; // 0..255
    };
    typedef struct CMMultichannel8Color CMMultichannel8Color;
    struct CMNamedColor
    {
        UInt32 namedColorIndex; // 0..a lot
    };
    typedef struct CMNamedColor CMNamedColor;
    union CMColor
    {
        CMRGBColor rgb;
        CMHSVColor hsv;
        CMHLSColor hls;
        CMXYZColor XYZ;
        CMLabColor Lab;
        CMLuvColor Luv;
        CMYxyColor Yxy;
        CMCMYKColor cmyk;
        CMCMYColor cmy;
        CMGrayColor gray;
        CMMultichannel5Color mc5;
        CMMultichannel6Color mc6;
        CMMultichannel7Color mc7;
        CMMultichannel8Color mc8;
        CMNamedColor namedColor;
    };
    typedef union CMColor CMColor;
    // GetIndexedProfile() search definition   struct CMProfileSearchRecord
    {
        CMHeader header;
        UInt32 fieldMask;
        UInt32 reserved[2];
    };
    typedef struct CMProfileSearchRecord CMProfileSearchRecord;
    typedef CMProfileSearchRecord *CMProfileSearchRecordPtr;
    typedef CMProfileSearchRecordPtr *CMProfileSearchRecordHandle;
    // CMNewProfileSearch() search definition   struct CMSearchRecord
    {
        OSType CMMType;
        OSType profileClass;
        OSType dataColorSpace;
        OSType profileConnectionSpace;
        UInt32 deviceManufacturer;
        UInt32 deviceModel;
        UInt32 deviceAttributes[2];
        UInt32 profileFlags;
        UInt32 searchMask;
        CMProfileFilterUPP filter;
    };
    typedef struct CMSearchRecord CMSearchRecord;
    // CMMIterateUPP() structure   struct CMMInfo
    {
        UInt32 dataSize; // Size of this structure - compatibility    OSType CMMType;                // Signature, e.g. 'appl', 'HDM ' or 'KCMS'    OSType CMMMfr;                 // Vendor, e.g. 'appl'    UInt32 CMMVersion;             // CMM version number    unsigned char ASCIIName[32];   // pascal string - name    unsigned char ASCIIDesc[256];  // pascal string - description or copyright    UniCharCount UniCodeNameCount; // count of UniChars in following array    UniChar UniCodeName[32];       // the name in UniCode chars    UniCharCount UniCodeDescCount; // count of UniChars in following array    UniChar UniCodeDesc[256];      // the description in UniCode chars
    };
    typedef struct CMMInfo CMMInfo;
    // GetCWInfo() structures   struct CMMInfoRecord
    {
        OSType CMMType;
        long CMMVersion;
    };
    typedef struct CMMInfoRecord CMMInfoRecord;
    struct CMCWInfoRecord
    {
        UInt32 cmmCount;
        CMMInfoRecord cmmInfo[2];
    };
    typedef struct CMCWInfoRecord CMCWInfoRecord;
    // profile identifier structures   struct CMProfileIdentifier
    {
        CM2Header profileHeader;
        CMDateTime calibrationDate;
        UInt32 ASCIIProfileDescriptionLen;
        char ASCIIProfileDescription[1]; // variable length
    };
    typedef struct CMProfileIdentifier CMProfileIdentifier;
    typedef CMProfileIdentifier *CMProfileIdentifierPtr;
    // colorspace masks   enum
    {
        cmColorSpaceSpaceMask = 0x0000003F,
        cmColorSpacePremulAlphaMask = 0x00000040,
        cmColorSpaceAlphaMask = 0x00000080,
        cmColorSpaceSpaceAndAlphaMask = 0x000000FF,
        cmColorSpacePackingMask = 0x0000FF00,
        cmColorSpaceEncodingMask = 0x000F0000,
        cmColorSpaceReservedMask = (long)0xFFF00000};

    // packing formats   enum
    {
        cmNoColorPacking = 0x0000,
        cmWord5ColorPacking = 0x0500,
        cmWord565ColorPacking = 0x0600,
        cmLong8ColorPacking = 0x0800,
        cmLong10ColorPacking = 0x0A00,
        cmAlphaFirstPacking = 0x1000,
        cmOneBitDirectPacking = 0x0B00,
        cmAlphaLastPacking = 0x0000,
        cm8_8ColorPacking = 0x2800,
        cm16_8ColorPacking = 0x2000,
        cm24_8ColorPacking = 0x2100,
        cm32_8ColorPacking = cmLong8ColorPacking,
        cm40_8ColorPacking = 0x2200,
        cm48_8ColorPacking = 0x2300,
        cm56_8ColorPacking = 0x2400,
        cm64_8ColorPacking = 0x2500,
        cm32_16ColorPacking = 0x2600,
        cm48_16ColorPacking = 0x2900,
        cm64_16ColorPacking = 0x2A00,
        cm32_32ColorPacking = 0x2700,
        cmLittleEndianPacking = 0x4000,
        cmReverseChannelPacking = 0x8000};

    // channel encoding format   enum
    {
        cmSRGB16ChannelEncoding =
            0x00010000 // used for sRGB64 encoding ( ©3.12 format)
    };

    // general colorspaces   enum
    {
        cmNoSpace = 0x0000,
        cmRGBSpace = 0x0001,
        cmCMYKSpace = 0x0002,
        cmHSVSpace = 0x0003,
        cmHLSSpace = 0x0004,
        cmYXYSpace = 0x0005,
        cmXYZSpace = 0x0006,
        cmLUVSpace = 0x0007,
        cmLABSpace = 0x0008,
        cmReservedSpace1 = 0x0009,
        cmGraySpace = 0x000A,
        cmReservedSpace2 = 0x000B,
        cmGamutResultSpace = 0x000C,
        cmNamedIndexedSpace = 0x0010,
        cmMCFiveSpace = 0x0011,
        cmMCSixSpace = 0x0012,
        cmMCSevenSpace = 0x0013,
        cmMCEightSpace = 0x0014,
        cmAlphaPmulSpace = 0x0040,
        cmAlphaSpace = 0x0080,
        cmRGBASpace = cmRGBSpace + cmAlphaSpace,
        cmGrayASpace = cmGraySpace + cmAlphaSpace,
        cmRGBAPmulSpace = cmRGBASpace + cmAlphaPmulSpace,
        cmGrayAPmulSpace = cmGrayASpace + cmAlphaPmulSpace};

    // supported CMBitmapColorSpaces - Each of the following is a   // combination of a general colospace and a packing formats.   // Each can also be or'd with cmReverseChannelPacking.   enum
    {
        cmGray8Space = cmGraySpace + cm8_8ColorPacking,
        cmGray16Space = cmGraySpace,
        cmGray16LSpace = cmGraySpace + cmLittleEndianPacking,
        cmGrayA16Space = cmGrayASpace + cm16_8ColorPacking,
        cmGrayA32Space = cmGrayASpace,
        cmGrayA32LSpace = cmGrayASpace + cmLittleEndianPacking,
        cmGrayA16PmulSpace = cmGrayAPmulSpace + cm16_8ColorPacking,
        cmGrayA32PmulSpace = cmGrayAPmulSpace,
        cmGrayA32LPmulSpace = cmGrayAPmulSpace + cmLittleEndianPacking,
        cmRGB16Space = cmRGBSpace + cmWord5ColorPacking,
        cmRGB16LSpace = cmRGBSpace + cmWord5ColorPacking + cmLittleEndianPacking,
        cmRGB565Space = cmRGBSpace + cmWord565ColorPacking,
        cmRGB565LSpace = cmRGBSpace + cmWord565ColorPacking + cmLittleEndianPacking,
        cmRGB24Space = cmRGBSpace + cm24_8ColorPacking,
        cmRGB32Space = cmRGBSpace + cm32_8ColorPacking,
        cmRGB48Space = cmRGBSpace + cm48_16ColorPacking,
        cmRGB48LSpace = cmRGBSpace + cm48_16ColorPacking + cmLittleEndianPacking,
        cmARGB32Space = cmRGBASpace + cm32_8ColorPacking + cmAlphaFirstPacking,
        cmARGB64Space = cmRGBASpace + cm64_16ColorPacking + cmAlphaFirstPacking,
        cmARGB64LSpace = cmRGBASpace + cm64_16ColorPacking + cmAlphaFirstPacking +
                         cmLittleEndianPacking,
        cmRGBA32Space = cmRGBASpace + cm32_8ColorPacking + cmAlphaLastPacking,
        cmRGBA64Space = cmRGBASpace + cm64_16ColorPacking + cmAlphaLastPacking,
        cmRGBA64LSpace = cmRGBASpace + cm64_16ColorPacking + cmAlphaLastPacking +
                         cmLittleEndianPacking,
        cmARGB32PmulSpace =
            cmRGBAPmulSpace + cm32_8ColorPacking + cmAlphaFirstPacking,
        cmARGB64PmulSpace =
            cmRGBAPmulSpace + cm64_16ColorPacking + cmAlphaFirstPacking,
        cmARGB64LPmulSpace = cmRGBAPmulSpace + cm64_16ColorPacking +
                             cmAlphaFirstPacking + cmLittleEndianPacking,
        cmRGBA32PmulSpace = cmRGBAPmulSpace + cm32_8ColorPacking + cmAlphaLastPacking,
        cmRGBA64PmulSpace =
            cmRGBAPmulSpace + cm64_16ColorPacking + cmAlphaLastPacking,
        cmRGBA64LPmulSpace = cmRGBAPmulSpace + cm64_16ColorPacking +
                             cmAlphaLastPacking + cmLittleEndianPacking,
        cmCMYK32Space = cmCMYKSpace + cm32_8ColorPacking,
        cmCMYK64Space = cmCMYKSpace + cm64_16ColorPacking,
        cmCMYK64LSpace = cmCMYKSpace + cm64_16ColorPacking + cmLittleEndianPacking,
        cmHSV32Space = cmHSVSpace + cmLong10ColorPacking,
        cmHLS32Space = cmHLSSpace + cmLong10ColorPacking,
        cmYXY32Space = cmYXYSpace + cmLong10ColorPacking,
        cmXYZ24Space = cmXYZSpace + cm24_8ColorPacking,
        cmXYZ32Space = cmXYZSpace + cmLong10ColorPacking,
        cmXYZ48Space = cmXYZSpace + cm48_16ColorPacking,
        cmXYZ48LSpace = cmXYZSpace + cm48_16ColorPacking + cmLittleEndianPacking,
        cmLUV32Space = cmLUVSpace + cmLong10ColorPacking,
        cmLAB24Space = cmLABSpace + cm24_8ColorPacking,
        cmLAB32Space = cmLABSpace + cmLong10ColorPacking,
        cmLAB48Space = cmLABSpace + cm48_16ColorPacking,
        cmLAB48LSpace = cmLABSpace + cm48_16ColorPacking + cmLittleEndianPacking,
        cmGamutResult1Space = cmOneBitDirectPacking + cmGamutResultSpace,
        cmNamedIndexed32Space = cm32_32ColorPacking + cmNamedIndexedSpace,
        cmNamedIndexed32LSpace =
            cm32_32ColorPacking + cmNamedIndexedSpace + cmLittleEndianPacking,
        cmMCFive8Space = cm40_8ColorPacking + cmMCFiveSpace,
        cmMCSix8Space = cm48_8ColorPacking + cmMCSixSpace,
        cmMCSeven8Space = cm56_8ColorPacking + cmMCSevenSpace,
        cmMCEight8Space = cm64_8ColorPacking + cmMCEightSpace};

    typedef UInt32 CMBitmapColorSpace;
    struct CMBitmap
    {
        char *image;
        long width;
        long height;
        long rowBytes;
        long pixelSize;
        CMBitmapColorSpace space;
        long user1;
        long user2;
    };
    typedef struct CMBitmap CMBitmap;
    // CMConvertXYZToXYZ() definitions
    typedef UInt32 CMChromaticAdaptation;
    enum
    {
        cmUseDefaultChromaticAdaptation = 0,
        cmLinearChromaticAdaptation = 1,
        cmVonKriesChromaticAdaptation = 2,
        cmBradfordChromaticAdaptation = 3
    };

    // Profile Locations   enum
    {
        CS_MAX_PATH = 256};

    enum
    {
        cmNoProfileBase = 0,
        cmFileBasedProfile = 1,
        cmHandleBasedProfile = 2,
        cmPtrBasedProfile = 3,
        cmProcedureBasedProfile = 4,
        cmPathBasedProfile = 5,
        cmBufferBasedProfile = 6
    };

    struct CMFileLocation
    {
        FSSpec spec;
    };
    typedef struct CMFileLocation CMFileLocation;
    struct CMHandleLocation
    {
        Handle h;
    };
    typedef struct CMHandleLocation CMHandleLocation;
    struct CMPtrLocation
    {
        Ptr p;
    };
    typedef struct CMPtrLocation CMPtrLocation;
    struct CMProcedureLocation
    {
        CMProfileAccessUPP proc;
        void *refCon;
    };
    typedef struct CMProcedureLocation CMProcedureLocation;
    struct CMPathLocation
    {
        char path[256];
    };
    typedef struct CMPathLocation CMPathLocation;
    struct CMBufferLocation
    {
        void *buffer;
        UInt32 size;
    };
    typedef struct CMBufferLocation CMBufferLocation;
    union CMProfLoc
    {
        CMFileLocation fileLoc;
        CMHandleLocation handleLoc;
        CMPtrLocation ptrLoc;
        CMProcedureLocation procLoc;
        CMPathLocation pathLoc;
        CMBufferLocation bufferLoc;
    };
    typedef union CMProfLoc CMProfLoc;
    struct CMProfileLocation
    {
        short locType;
        CMProfLoc u;
    };
    typedef struct CMProfileLocation CMProfileLocation;
#if TARGET_OS_MAC
    enum
    {
        cmOriginalProfileLocationSize = 72,
        cmCurrentProfileLocationSize = 2 + CS_MAX_PATH
    };

#else
enum
{
    cmOriginalProfileLocationSize = 2 + CS_MAX_PATH,
    cmCurrentProfileLocationSize = 2 + CS_MAX_PATH
};

#endif // TARGET_OS_MAC
       // Typedef for Profile MD5 message digest
    typedef unsigned char CMProfileMD5[16];
    typedef CMProfileMD5 *CMProfileMD5Ptr;
    // Struct and enums used for Profile iteration   enum
    {
        cmProfileIterateDataVersion1 = 0x00010000,
        cmProfileIterateDataVersion2 = 0x00020000, // Added makeAndModel    cmProfileIterateDataVersion3 = 0x00030000  // Added MD5 digest
    };

    struct CMProfileIterateData
    {
        UInt32 dataVersion; // cmProfileIterateDataVersion2     CM2Header header;
        ScriptCode code;
        Str255 name;
        CMProfileLocation location;
        UniCharCount uniCodeNameCount;
        UniChar *uniCodeName;
        unsigned char *asciiName;
        CMMakeAndModel *makeAndModel;
        CMProfileMD5 *digest;
    };
    typedef struct CMProfileIterateData CMProfileIterateData;
    // Caller-supplied callback function for Profile & CMM iteration   typedef CALLBACK_API(OSErr,
                       CMProfileIterateProcPtr)(CMProfileIterateData *iterateData,
                                                void *refCon);
                       typedef CALLBACK_API(OSErr, CMMIterateProcPtr)(CMMInfo *iterateData,
                                                                      void *refCon);
                       typedef STACK_UPP_TYPE(CMProfileIterateProcPtr) CMProfileIterateUPP;
                       typedef STACK_UPP_TYPE(CMMIterateProcPtr) CMMIterateUPP;
                       /**
                        *  NewCMProfileIterateUPP()
                        *

                        *    \non_carbon_cfm   available as macro/inline
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in 3.0 and later
                        */
                       CMProfileIterateUPP
                       NewCMProfileIterateUPP(CMProfileIterateProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
                       enum
                       {
                           uppCMProfileIterateProcInfo = 0x000003E0
                       }; // pascal 2_bytes Func(4_bytes, 4_bytes) #ifdef __cplusplus
                       inline CMProfileIterateUPP
                       NewCMProfileIterateUPP(CMProfileIterateProcPtr userRoutine)
                       {
                           return (CMProfileIterateUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                                            uppCMProfileIterateProcInfo,
                                                                            GetCurrentArchitecture());
                       }
#else
#define NewCMProfileIterateUPP(userRoutine)                                                    \
                       (CMProfileIterateUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),      \
                                                                  uppCMProfileIterateProcInfo, \
                                                                  GetCurrentArchitecture())
#endif
#endif

                       /**
                        *  NewCMMIterateUPP()
                        *

                        *    \non_carbon_cfm   available as macro/inline
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in 3.0 and later
                        */
                       CMMIterateUPP
                       NewCMMIterateUPP(CMMIterateProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
                       enum
                       {
                           uppCMMIterateProcInfo = 0x000003E0
                       }; // pascal 2_bytes Func(4_bytes, 4_bytes) #ifdef __cplusplus
                       inline CMMIterateUPP NewCMMIterateUPP(CMMIterateProcPtr userRoutine)
                       {
                           return (CMMIterateUPP)NewRoutineDescriptor(
                               (ProcPtr)(userRoutine), uppCMMIterateProcInfo, GetCurrentArchitecture());
                       }
#else
#define NewCMMIterateUPP(userRoutine)                        \
                       (CMMIterateUPP) NewRoutineDescriptor( \
                           (ProcPtr)(userRoutine), uppCMMIterateProcInfo, GetCurrentArchitecture())
#endif
#endif

                       /**
                        *  DisposeCMProfileIterateUPP()
                        *

                        *    \non_carbon_cfm   available as macro/inline
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in 3.0 and later
                        */
                       void
                       DisposeCMProfileIterateUPP(CMProfileIterateUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                       inline void DisposeCMProfileIterateUPP(CMProfileIterateUPP userUPP)
                       {
                           DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
                       }
#else
#define DisposeCMProfileIterateUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

                       /**
                        *  DisposeCMMIterateUPP()
                        *

                        *    \non_carbon_cfm   available as macro/inline
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in 3.0 and later
                        */
                       void
                       DisposeCMMIterateUPP(CMMIterateUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                       inline void DisposeCMMIterateUPP(CMMIterateUPP userUPP)
                       {
                           DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
                       }
#else
#define DisposeCMMIterateUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

                       /**
                        *  InvokeCMProfileIterateUPP()
                        *

                        *    \non_carbon_cfm   available as macro/inline
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in 3.0 and later
                        */
                       OSErr
                       InvokeCMProfileIterateUPP(CMProfileIterateData *iterateData, void *refCon,
                                                 CMProfileIterateUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                       inline OSErr InvokeCMProfileIterateUPP(CMProfileIterateData *iterateData,
                                                              void *refCon,
                                                              CMProfileIterateUPP userUPP)
                       {
                           return (OSErr)CALL_TWO_PARAMETER_UPP(userUPP, uppCMProfileIterateProcInfo,
                                                                iterateData, refCon);
                       }
#else
#define InvokeCMProfileIterateUPP(iterateData, refCon, userUPP)                               \
                       (OSErr) CALL_TWO_PARAMETER_UPP((userUPP), uppCMProfileIterateProcInfo, \
                                                      (iterateData), (refCon))
#endif
#endif

                       /**
                        *  InvokeCMMIterateUPP()
                        *

                        *    \non_carbon_cfm   available as macro/inline
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in 3.0 and later
                        */
                       OSErr
                       InvokeCMMIterateUPP(CMMInfo *iterateData, void *refCon, CMMIterateUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                       inline OSErr InvokeCMMIterateUPP(CMMInfo *iterateData, void *refCon,
                                                        CMMIterateUPP userUPP)
                       {
                           return (OSErr)CALL_TWO_PARAMETER_UPP(userUPP, uppCMMIterateProcInfo,
                                                                iterateData, refCon);
                       }
#else
#define InvokeCMMIterateUPP(iterateData, refCon, userUPP)                               \
                       (OSErr) CALL_TWO_PARAMETER_UPP((userUPP), uppCMMIterateProcInfo, \
                                                      (iterateData), (refCon))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewCMProfileIterateProc(userRoutine) NewCMProfileIterateUPP(userRoutine)
#define NewCMMIterateProc(userRoutine) NewCMMIterateUPP(userRoutine)
#define CallCMProfileIterateProc(userRoutine, iterateData, refCon) \
    InvokeCMProfileIterateUPP(iterateData, refCon, userRoutine)
#define CallCMMIterateProc(userRoutine, iterateData, refCon) \
    InvokeCMMIterateUPP(iterateData, refCon, userRoutine)
#endif // CALL_NOT_IN_CARBON
       // Profile file and element access
       /**
          *CMNewProfile() *
   
                  *    \non_carbon_cfm in ColorSyncLib 2.0 and
              later
                  *    \carbon_lib in CarbonLib 1.0 and
              later
                  *    \mac_os_x in 3.0 and
              later*/
    CMError
    CMNewProfile(CMProfileRef *prof, const CMProfileLocation *theProfile);

    /**
     *  CMOpenProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMOpenProfile(CMProfileRef *prof, const CMProfileLocation *theProfile);

    /**
     *  CMCloseProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMCloseProfile(CMProfileRef prof);

    /**
     *  CMUpdateProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMUpdateProfile(CMProfileRef prof);

    /**
     *  CMCopyProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMCopyProfile(CMProfileRef *targetProf, const CMProfileLocation *targetLocation,
                  CMProfileRef srcProf);

    /**
     *  CMValidateProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMValidateProfile(CMProfileRef prof, Boolean *valid,
                      Boolean *preferredCMMnotfound);

    /**
     *  CMGetProfileLocation()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetProfileLocation(CMProfileRef prof, CMProfileLocation *theProfile);

    /**
     *  NCMGetProfileLocation()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    NCMGetProfileLocation(CMProfileRef prof, CMProfileLocation *theProfile,
                          UInt32 *locationSize);

    /**
     *  CMFlattenProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMFlattenProfile(CMProfileRef prof, UInt32 flags, CMFlattenUPP proc,
                     void *refCon, Boolean *preferredCMMnotfound);

#if TARGET_OS_MAC
#if CALL_NOT_IN_CARBON
    /**
     *  CMUnflattenProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CMUnflattenProfile(FSSpec *resultFileSpec, CMFlattenUPP proc, void *refCon,
                       Boolean *preferredCMMnotfound);

#endif // CALL_NOT_IN_CARBON
#endif // TARGET_OS_MAC
    /**
     *  CMGetProfileHeader()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetProfileHeader(CMProfileRef prof, CMAppleProfileHeader *header);

    /**
     *  CMSetProfileHeader()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetProfileHeader(CMProfileRef prof, const CMAppleProfileHeader *header);

    /**
     *  CMProfileElementExists()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMProfileElementExists(CMProfileRef prof, OSType tag, Boolean *found);

    /**
     *  CMCountProfileElements()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMCountProfileElements(CMProfileRef prof, UInt32 *elementCount);

    /**
     *  CMGetProfileElement()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetProfileElement(CMProfileRef prof, OSType tag, UInt32 *elementSize,
                        void *elementData);

    /**
     *  CMSetProfileElement()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetProfileElement(CMProfileRef prof, OSType tag, UInt32 elementSize,
                        const void *elementData);

    /**
     *  CMSetProfileElementSize()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetProfileElementSize(CMProfileRef prof, OSType tag, UInt32 elementSize);

    /**
     *  CMSetProfileElementReference()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetProfileElementReference(CMProfileRef prof, OSType elementTag,
                                 OSType referenceTag);

    /**
     *  CMGetPartialProfileElement()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetPartialProfileElement(CMProfileRef prof, OSType tag, UInt32 offset,
                               UInt32 *byteCount, void *elementData);

    /**
     *  CMSetPartialProfileElement()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetPartialProfileElement(CMProfileRef prof, OSType tag, UInt32 offset,
                               UInt32 byteCount, const void *elementData);

    /**
     *  CMGetIndProfileElementInfo()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetIndProfileElementInfo(CMProfileRef prof, UInt32 index, OSType *tag,
                               UInt32 *elementSize, Boolean *refs);

    /**
     *  CMGetIndProfileElement()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetIndProfileElement(CMProfileRef prof, UInt32 index, UInt32 *elementSize,
                           void *elementData);

    /**
     *  CMRemoveProfileElement()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMRemoveProfileElement(CMProfileRef prof, OSType tag);

    /**
     *  CMGetScriptProfileDescription()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetScriptProfileDescription(CMProfileRef prof, Str255 name, ScriptCode *code);

    /**
     *  CMGetProfileDescriptions()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetProfileDescriptions(CMProfileRef prof, char *aName, UInt32 *aCount,
                             Str255 mName, ScriptCode *mCode, UniChar *uName,
                             UniCharCount *uCount);

    /**
     *  CMSetProfileDescriptions()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetProfileDescriptions(CMProfileRef prof, const char *aName, UInt32 aCount,
                             ConstStr255Param mName, ScriptCode mCode,
                             const UniChar *uName, UniCharCount uCount);

    /**
     *  CMCopyProfileLocalizedStringDictionary()
     *

     *    \non_carbon_cfm   in ColorSyncLib 3.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         in 3.1 and later
     */
    CMError
    CMCopyProfileLocalizedStringDictionary(CMProfileRef prof, OSType tag,
                                           CFDictionaryRef *theDict);

    /**
     *  CMSetProfileLocalizedStringDictionary()
     *

     *    \non_carbon_cfm   in ColorSyncLib 3.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         in 3.1 and later
     */
    CMError
    CMSetProfileLocalizedStringDictionary(CMProfileRef prof, OSType tag,
                                          CFDictionaryRef theDict);

    /**
     *  CMCopyProfileLocalizedString()
     *

     *    \non_carbon_cfm   in ColorSyncLib 3.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         in 3.1 and later
     */
    CMError
    CMCopyProfileLocalizedString(CMProfileRef prof, OSType tag,
                                 CFStringRef reqLocale, CFStringRef *locale,
                                 CFStringRef *str);

    /**
     *  CMCloneProfileRef()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMCloneProfileRef(CMProfileRef prof);

    /**
     *  CMGetProfileRefCount()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetProfileRefCount(CMProfileRef prof, long *count);

    /**
     *  CMProfileModified()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMProfileModified(CMProfileRef prof, Boolean *modified);

    /**
     *  CMGetProfileMD5()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in 3.1 and later
     */
    CMError
    CMGetProfileMD5(CMProfileRef prof, CMProfileMD5 digest);

    // named Color access functions
    /**
       *CMGetNamedColorInfo() *

               *    \non_carbon_cfm in ColorSyncLib 2.1 and
           later
               *    \carbon_lib in CarbonLib 1.0 and
           later
               *    \mac_os_x in 3.0 and
           later*/
    CMError
    CMGetNamedColorInfo(CMProfileRef prof, UInt32 *deviceChannels,
                        OSType *deviceColorSpace, OSType *PCSColorSpace,
                        UInt32 *count, StringPtr prefix, StringPtr suffix);

    /**
     *  CMGetNamedColorValue()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetNamedColorValue(CMProfileRef prof, StringPtr name, CMColor *deviceColor,
                         CMColor *PCSColor);

    /**
     *  CMGetIndNamedColorValue()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetIndNamedColorValue(CMProfileRef prof, UInt32 index, CMColor *deviceColor,
                            CMColor *PCSColor);

    /**
     *  CMGetNamedColorIndex()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetNamedColorIndex(CMProfileRef prof, StringPtr name, UInt32 *index);

    /**
     *  CMGetNamedColorName()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetNamedColorName(CMProfileRef prof, UInt32 index, StringPtr name);

    // General-purpose matching functions
    /**
       *NCWNewColorWorld() *

               *    \non_carbon_cfm in ColorSyncLib 2.0 and
           later
               *    \carbon_lib in CarbonLib 1.0 and
           later
               *    \mac_os_x in 3.0 and
           later*/
    CMError
    NCWNewColorWorld(CMWorldRef *cw, CMProfileRef src, CMProfileRef dst);

    /**
     *  CWConcatColorWorld()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CWConcatColorWorld(CMWorldRef *cw, CMConcatProfileSet *profileSet);

    /**
     *  CWNewLinkProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CWNewLinkProfile(CMProfileRef *prof, const CMProfileLocation *targetLocation,
                     CMConcatProfileSet *profileSet);

    /**
     *  NCWConcatColorWorld()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    NCWConcatColorWorld(CMWorldRef *cw, NCMConcatProfileSet *profileSet,
                        CMConcatCallBackUPP proc, void *refCon);

    /**
     *  NCWNewLinkProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    NCWNewLinkProfile(CMProfileRef *prof, const CMProfileLocation *targetLocation,
                      NCMConcatProfileSet *profileSet, CMConcatCallBackUPP proc,
                      void *refCon);

    /**
     *  CWDisposeColorWorld()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    void
    CWDisposeColorWorld(CMWorldRef cw);

    /**
     *  CWMatchColors()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CWMatchColors(CMWorldRef cw, CMColor *myColors, UInt32 count);

    /**
     *  CWCheckColors()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CWCheckColors(CMWorldRef cw, CMColor *myColors, UInt32 count, UInt32 *result);

    /**
     *  CWMatchBitmap()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CWMatchBitmap(CMWorldRef cw, CMBitmap *bitmap, CMBitmapCallBackUPP progressProc,
                  void *refCon, CMBitmap *matchedBitmap);

    /**
     *  CWCheckBitmap()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CWCheckBitmap(CMWorldRef cw, const CMBitmap *bitmap,
                  CMBitmapCallBackUPP progressProc, void *refCon,
                  CMBitmap *resultBitmap);

    // Quickdraw-specific matching #if TARGET_OS_MAC && _DECLARE_CS_QD_API_
    /**
     *  CWMatchPixMap()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         not available
     */
    CMError
    CWMatchPixMap(CMWorldRef cw, PixMap *myPixMap, CMBitmapCallBackUPP progressProc,
                  void *refCon);

    /**
     *  CWCheckPixMap()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         not available
     */
    CMError
    CWCheckPixMap(CMWorldRef cw, PixMap *myPixMap, CMBitmapCallBackUPP progressProc,
                  void *refCon, BitMap *resultBitMap);

    /**
     *  NCMBeginMatching()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         not available
     */
    CMError
    NCMBeginMatching(CMProfileRef src, CMProfileRef dst, CMMatchRef *myRef);

    /**
     *  CMEndMatching()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         not available
     */
    void
    CMEndMatching(CMMatchRef myRef);

    /**
     *  NCMDrawMatchedPicture()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         not available
     */
    void
    NCMDrawMatchedPicture(PicHandle myPicture, CMProfileRef dst, Rect *myRect);

    /**
     *  CMEnableMatchingComment()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         not available
     */
    void
    CMEnableMatchingComment(Boolean enableIt);

    /**
     *  NCMUseProfileComment()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         not available
     */
    CMError
    NCMUseProfileComment(CMProfileRef prof, UInt32 flags);

#endif // TARGET_OS_MAC && _DECLARE_CS_QD_API_
#if TARGET_OS_WIN32
#if CALL_NOT_IN_CARBON
    /**
     *  CWMatchHBITMAP()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CWMatchHBITMAP(CMWorldRef cw, HBITMAP hBitmap, CMBitmapCallBackUPP progressProc,
                   void *refCon);

#endif // CALL_NOT_IN_CARBON
#endif // TARGET_OS_WIN32
    /**
     *  CMCreateProfileIdentifier()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMCreateProfileIdentifier(CMProfileRef prof, CMProfileIdentifierPtr ident,
                              UInt32 *size);

    // System Profile access
    /**
       *CMGetSystemProfile() *

               *    \non_carbon_cfm in ColorSyncLib 2.0 and
           later
               *    \carbon_lib in CarbonLib 1.0 and
           later
               *    \mac_os_x in 3.0 and
           later*/
    CMError
    CMGetSystemProfile(CMProfileRef *prof);

    /**
     *  CMSetSystemProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetSystemProfile(const FSSpec *profileFileSpec);

    /**
     *  NCMSetSystemProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    NCMSetSystemProfile(const CMProfileLocation *profLoc);

    /**
     *  CMGetDefaultProfileBySpace()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetDefaultProfileBySpace(OSType dataColorSpace, CMProfileRef *prof);

    /**
     *  CMSetDefaultProfileBySpace()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetDefaultProfileBySpace(OSType dataColorSpace, CMProfileRef prof);

#if TARGET_OS_MAC
    /**
     *  CMGetProfileByAVID()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetProfileByAVID(CMDisplayIDType theID, CMProfileRef *prof);

    /**
     *  CMSetProfileByAVID()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetProfileByAVID(CMDisplayIDType theID, CMProfileRef prof);

    /**
     *  CMGetGammaByAVID()
     *

     *    \non_carbon_cfm   in ColorSyncLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetGammaByAVID(CMDisplayIDType theID, CMVideoCardGamma *gamma, UInt32 *size);

    /**
     *  CMSetGammaByAVID()
     *

     *    \non_carbon_cfm   in ColorSyncLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetGammaByAVID(CMDisplayIDType theID, CMVideoCardGamma *gamma);

#endif // TARGET_OS_MAC
       // Profile access by Use
       /**
          *CMGetDefaultProfileByUse() *
   
                  *    \non_carbon_cfm in ColorSyncLib 3.0 and
              later
                  *    \carbon_lib in CarbonLib 1.0 and
              later
                  *    \mac_os_x in 3.0 and
              later*/
    CMError
    CMGetDefaultProfileByUse(OSType use, CMProfileRef *prof);

    /**
     *  CMSetDefaultProfileByUse()
     *

     *    \non_carbon_cfm   in ColorSyncLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSetDefaultProfileByUse(OSType use, CMProfileRef prof);

    // Profile Management
    /**
       *CMNewProfileSearch() *

               *    \non_carbon_cfm in ColorSyncLib 2.0 and
           later
               *    \carbon_lib in CarbonLib 1.0 and
           later
               *    \mac_os_x in 3.0 and
           later*/
    CMError
    CMNewProfileSearch(CMSearchRecord *searchSpec, void *refCon, UInt32 *count,
                       CMProfileSearchRef *searchResult);

    /**
     *  CMUpdateProfileSearch()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMUpdateProfileSearch(CMProfileSearchRef search, void *refCon, UInt32 *count);

    /**
     *  CMDisposeProfileSearch()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    void
    CMDisposeProfileSearch(CMProfileSearchRef search);

    /**
     *  CMSearchGetIndProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSearchGetIndProfile(CMProfileSearchRef search, UInt32 index,
                          CMProfileRef *prof);

    /**
     *  CMSearchGetIndProfileFileSpec()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMSearchGetIndProfileFileSpec(CMProfileSearchRef search, UInt32 index,
                                  FSSpec *profileFile);

    /**
     *  CMProfileIdentifierFolderSearch()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMProfileIdentifierFolderSearch(CMProfileIdentifierPtr ident,
                                    UInt32 *matchedCount,
                                    CMProfileSearchRef *searchResult);

    /**
     *  CMProfileIdentifierListSearch()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMProfileIdentifierListSearch(CMProfileIdentifierPtr ident,
                                  CMProfileRef *profileList, UInt32 listSize,
                                  UInt32 *matchedCount, CMProfileRef *matchedList);

    /**
     *  CMIterateColorSyncFolder()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMIterateColorSyncFolder(CMProfileIterateUPP proc, UInt32 *seed, UInt32 *count,
                             void *refCon);

    /**
     *  NCMUnflattenProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    NCMUnflattenProfile(CMProfileLocation *targetLocation, CMFlattenUPP proc,
                        void *refCon, Boolean *preferredCMMnotfound);

    // Utilities #if TARGET_OS_MAC
    /**
     *  CMGetColorSyncFolderSpec()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetColorSyncFolderSpec(short vRefNum, Boolean createFolder,
                             short *foundVRefNum, long *foundDirID);

#endif // TARGET_OS_MAC
#if TARGET_OS_WIN32 || TARGET_OS_UNIX
#if CALL_NOT_IN_CARBON
    /**
     *  CMGetColorSyncFolderPath()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CMGetColorSyncFolderPath(Boolean createFolder, char *lpBuffer, UInt32 uSize);

#endif // CALL_NOT_IN_CARBON
#endif // TARGET_OS_WIN32 || TARGET_OS_UNIX
    /**
     *  CMGetCWInfo()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetCWInfo(CMWorldRef cw, CMCWInfoRecord *info);

#if TARGET_API_MAC_OS8
#if CALL_NOT_IN_CARBON
    /**
     *  CMConvertProfile2to1()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CMConvertProfile2to1(CMProfileRef profv2, CMProfileHandle *profv1);

#endif // CALL_NOT_IN_CARBON
#endif // TARGET_API_MAC_OS8
    /**
     *  CMGetPreferredCMM()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetPreferredCMM(OSType *cmmType, Boolean *preferredCMMnotfound);

    /**
     *  CMIterateCMMInfo()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMIterateCMMInfo(CMMIterateUPP proc, UInt32 *count, void *refCon);

    /**
     *  CMGetColorSyncVersion()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.6 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetColorSyncVersion(UInt32 *version);

    /**
     *  CMLaunchControlPanel()
     *

     *    \non_carbon_cfm   in ColorSyncLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMLaunchControlPanel(UInt32 flags);

    // ColorSpace conversion functions
    /**
       *CMConvertXYZToLab() *

               *    \non_carbon_cfm in ColorSyncLib 2.1 and
           later
               *    \carbon_lib in CarbonLib 1.0 and
           later
               *    \mac_os_x in 3.0 and
           later*/
    CMError
    CMConvertXYZToLab(const CMColor *src, const CMXYZColor *white, CMColor *dst,
                      UInt32 count);

    /**
     *  CMConvertLabToXYZ()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertLabToXYZ(const CMColor *src, const CMXYZColor *white, CMColor *dst,
                      UInt32 count);

    /**
     *  CMConvertXYZToLuv()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertXYZToLuv(const CMColor *src, const CMXYZColor *white, CMColor *dst,
                      UInt32 count);

    /**
     *  CMConvertLuvToXYZ()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertLuvToXYZ(const CMColor *src, const CMXYZColor *white, CMColor *dst,
                      UInt32 count);

    /**
     *  CMConvertXYZToYxy()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertXYZToYxy(const CMColor *src, CMColor *dst, UInt32 count);

    /**
     *  CMConvertYxyToXYZ()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertYxyToXYZ(const CMColor *src, CMColor *dst, UInt32 count);

    /**
     *  CMConvertRGBToHLS()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertRGBToHLS(const CMColor *src, CMColor *dst, UInt32 count);

    /**
     *  CMConvertHLSToRGB()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertHLSToRGB(const CMColor *src, CMColor *dst, UInt32 count);

    /**
     *  CMConvertRGBToHSV()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertRGBToHSV(const CMColor *src, CMColor *dst, UInt32 count);

    /**
     *  CMConvertHSVToRGB()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertHSVToRGB(const CMColor *src, CMColor *dst, UInt32 count);

    /**
     *  CMConvertRGBToGray()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertRGBToGray(const CMColor *src, CMColor *dst, UInt32 count);

    /**
     *  CMConvertXYZToFixedXYZ()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertXYZToFixedXYZ(const CMXYZColor *src, CMFixedXYZColor *dst,
                           UInt32 count);

    /**
     *  CMConvertFixedXYZToXYZ()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMConvertFixedXYZToXYZ(const CMFixedXYZColor *src, CMXYZColor *dst,
                           UInt32 count);

    /**
     *  CMConvertXYZToXYZ()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in 3.1 and later
     */
    CMError
    CMConvertXYZToXYZ(const CMColor *src, const CMXYZColor *srcIlluminant,
                      CMColor *dst, const CMXYZColor *dstIlluminant,
                      CMChromaticAdaptation method, UInt32 count);

    // PS-related
    /**
       *CMGetPS2ColorSpace() *

               *    \non_carbon_cfm in ColorSyncLib 2.0 and
           later
               *    \carbon_lib in CarbonLib 1.0 and
           later
               *    \mac_os_x in 3.0 and
           later*/
    CMError
    CMGetPS2ColorSpace(CMProfileRef srcProf, UInt32 flags, CMFlattenUPP proc,
                       void *refCon, Boolean *preferredCMMnotfound);

    /**
     *  CMGetPS2ColorRenderingIntent()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetPS2ColorRenderingIntent(CMProfileRef srcProf, UInt32 flags,
                                 CMFlattenUPP proc, void *refCon,
                                 Boolean *preferredCMMnotfound);

    /**
     *  CMGetPS2ColorRendering()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetPS2ColorRendering(CMProfileRef srcProf, CMProfileRef dstProf, UInt32 flags,
                           CMFlattenUPP proc, void *refCon,
                           Boolean *preferredCMMnotfound);

    /**
     *  CMGetPS2ColorRenderingVMSize()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in 3.0 and later
     */
    CMError
    CMGetPS2ColorRenderingVMSize(CMProfileRef srcProf, CMProfileRef dstProf,
                                 UInt32 *vmSize, Boolean *preferredCMMnotfound);

// ColorSync 1.0 functions which have parallel 2.0 counterparts #if TARGET_API_MAC_OS8
#if CALL_NOT_IN_CARBON
    /**
     *  CWNewColorWorld()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CWNewColorWorld(CMWorldRef *cw, CMProfileHandle src, CMProfileHandle dst);

    /**
     *  ConcatenateProfiles()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    ConcatenateProfiles(CMProfileHandle thru, CMProfileHandle dst,
                        CMProfileHandle *newDst);

    /**
     *  CMBeginMatching()
     *

     *    \non_carbon_cfm   in ColorSyncLib 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CMBeginMatching(CMProfileHandle src, CMProfileHandle dst, CMMatchRef *myRef);

    /**
     *  CMDrawMatchedPicture()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    CMDrawMatchedPicture(PicHandle myPicture, CMProfileHandle dst, Rect *myRect);

    /**
     *  CMUseProfileComment()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CMUseProfileComment(CMProfileHandle profile);

    /**
     *  CMGetProfileName()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    CMGetProfileName(CMProfileHandle myProfile, CMIString *IStringResult);

    /**
     *  CMGetProfileAdditionalDataOffset()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    CMGetProfileAdditionalDataOffset(CMProfileHandle myProfile);

    // ProfileResponder definitions #endif // CALL_NOT_IN_CARBON
    enum
    {
        cmSystemDevice = FOUR_CHAR_CODE('sys '),
        cmGDevice = FOUR_CHAR_CODE('gdev')
    };

    // ProfileResponder functions #if CALL_NOT_IN_CARBON
    /**
     *  GetProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    GetProfile(OSType deviceType, long refNum, CMProfileHandle aProfile,
               CMProfileHandle *returnedProfile);

    /**
     *  SetProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    SetProfile(OSType deviceType, long refNum, CMProfileHandle newProfile);

    /**
     *  SetProfileDescription()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    SetProfileDescription(OSType deviceType, long refNum, long deviceData,
                          CMProfileHandle hProfile);

    /**
     *  GetIndexedProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    GetIndexedProfile(OSType deviceType, long refNum,
                      CMProfileSearchRecordHandle search,
                      CMProfileHandle *returnProfile, long *index);

    /**
     *  DeleteDeviceProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLib 1.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    DeleteDeviceProfile(OSType deviceType, long refNum, CMProfileHandle deleteMe);

#endif // CALL_NOT_IN_CARBON
#if OLDROUTINENAMES
    // old constants
    typedef CMFlattenProcPtr CMFlattenProc;
    typedef CMBitmapCallBackProcPtr CMBitmapCallBackProc;
    typedef CMProfileFilterProcPtr CMProfileFilterProc;
    enum
    {
        CMTrap = cmTrap,
        CMBeginProfile = cmBeginProfile,
        CMEndProfile = cmEndProfile,
        CMEnableMatching = cmEnableMatching,
        CMDisableMatching = cmDisableMatching
    };

    /* 1.0 Error codes, for compatibility with older applications. 1.0 CMM's may
     * return obsolete error codes */
    enum
    {
        CMNoError = 0,
        obsolete name,
        use noErr CMProfileError = cmProfileError
            CMMethodError = cmMethodError,
        CMMemFullError = -172,
        obsolete,
        2.0 uses memFullErr CMUnimplementedError = -173 obsolete,
        2.0 uses unimpErr CMParamError = -174 obsolete,
        2.0 uses paramErr CMMethodNotFound = cmMethodNotFound
            CMProfileNotFound = cmProfileNotFound,
        CMProfilesIdentical = cmProfilesIdentical,
        CMCantConcatenateError = cmCantConcatenateError,
        CMCantXYZ = cmCantXYZ,
        CMCantDeleteProfile = cmCantDeleteProfile,
        CMUnsupportedDataType = cmUnsupportedDataType,
        CMNoCurrentProfile = cmNoCurrentProfile
    };

    enum
    {
        qdSystemDevice = cmSystemDevice,
        qdGDevice = cmGDevice
    };

    enum
    {
        kMatchCMMType = cmMatchCMMType,
        kMatchApplProfileVersion = cmMatchApplProfileVersion,
        kMatchDataType = cmMatchDataType,
        kMatchDeviceType = cmMatchDeviceType,
        kMatchDeviceManufacturer = cmMatchDeviceManufacturer,
        kMatchDeviceModel = cmMatchDeviceModel,
        kMatchDeviceAttributes = cmMatchDeviceAttributes,
        kMatchFlags = cmMatchFlags,
        kMatchOptions = cmMatchOptions,
        kMatchWhite = cmMatchWhite,
        kMatchBlack = cmMatchBlack
    };

    // old types   typedef CMCMYKColor CMYKColor;
    typedef CMWorldRef CWorld;
    typedef long *CMGamutResult;
// old functions #define EndMatching(myRef) CMEndMatching(myRef)
#define EnableMatching(enableIt) CMEnableMatchingComment(enableIt)
#define GetColorSyncFolderSpec(vRefNum, createFolder, foundVRefNum, \
                               foundDirID)                          \
    CMGetColorSyncFolderSpec(vRefNum, createFolder, foundVRefNum, foundDirID)
#define BeginMatching(src, dst, myRef) CMBeginMatching(src, dst, myRef)
#define DrawMatchedPicture(myPicture, dst, myRect) \
    CMDrawMatchedPicture(myPicture, dst, myRect)
#define UseProfile(profile) CMUseProfileComment(profile)
#define GetProfileName(myProfile, IStringResult) \
    CMGetProfileName(myProfile, IStringResult)
#define GetProfileAdditionalDataOffset(myProfile) \
    CMGetProfileAdditionalDataOffset(myProfile)
#endif // OLDROUTINENAMES
       // Deprecated stuff  // PrGeneral parameter blocks   enum
    {
        enableColorMatchingOp = 12,
        registerProfileOp = 13};

    struct TEnableColorMatchingBlk
    {
        short iOpCode;
        short iError;
        long lReserved;
        THPrint hPrint;
        Boolean fEnableIt;
        SInt8 filler;
    };
    typedef struct TEnableColorMatchingBlk TEnableColorMatchingBlk;
    struct TRegisterProfileBlk
    {
        short iOpCode;
        short iError;
        long lReserved;
        THPrint hPrint;
        Boolean fRegisterIt;
        SInt8 filler;
    };
    typedef struct TRegisterProfileBlk TRegisterProfileBlk;
#endif // TARGET_API_MAC_OS8
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

#endif // __CMAPPLICATION__