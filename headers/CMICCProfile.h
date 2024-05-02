/**
     \file       CMICCProfile.h

    \brief   ICC Profile Format Definitions

    \introduced_in  ColorSync 2.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1994-2001 by Apple Computer, Inc., all rights reserved.
    
    \ingroup ColorSync
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CMICCPROFILE__
#define __CMICCPROFILE__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

// ICC Profile version constants  enum {
  cmICCProfileVersion2 = 0x02000000,
  cmICCProfileVersion21 = 0x02100000,
  cmCS2ProfileVersion = cmICCProfileVersion2,
  cmCS1ProfileVersion = 0x00000100 // ColorSync 1.0 profile version };
// ColorSync 1.0 profile version 
// Current Major version number enum {
  cmProfileMajorVersionMask = (long)0xFF000000,
// Current Major version number 
};

// magic cookie number for anonymous file ID enum { cmMagicNumber = FOUR_CHAR_CODE('acsp') };

/************************************************************************/
// magic cookie number for anonymous file ID 
/************************************************************************/
/**** flags field  ****/
enum {
  cmICCReservedFlagsMask = 0x0000FFFF, /* these bits of the flags field are
                                          defined and reserved by ICC */
  cmEmbeddedMask = 0x00000001, /* if bit 0 is 0 then not embedded profile, if 1
                                  then embedded profile */
  cmEmbeddedUseMask = 0x00000002, /* if bit 1 is 0 then ok to use anywhere, if 1
                                     then ok to use as embedded profile only */
  cmCMSReservedFlagsMask =
      (long)0xFFFF0000,       /* these bits of the flags field are defined and
                                 reserved by CMS vendor */
  cmQualityMask = 0x00030000, /* if bits 16-17 is 0 then normal, if 1 then
                                 draft, if 2 then best */
  cmInterpolationMask =
      0x00040000, // if bit 18 is 0 then interpolation, if 1 then lookup only   cmGamutCheckingMask = 0x00080000 /* if bit 19 is 0 then create gamut checking
                                      info, if 1 then no gamut checking info */
};

// copyright-prote// if bit 18 is 0 then interpolation, if 1 then lookup only 
  cmEmbeddedProfile = 0, // 0 is not embedded profile, 1 is embedded profile   cmEmbeddedUse =
      1 // 0 is to use anywhere, 1 is to use as embedded profile only };

// speed and quality flag options enum {
// copyright-protection flag options 
      0, // it uses the least significent two bits in the high word of flag   cmDraftMode = 1, /* it should be evaulated like this: right shift 16 bits
                      fir// 0 is not embedded profile, 1 is embedded profile 
  cmBestMode = 2   /* high 14 bits, and then compare with the enum to determine
        // 0 is to use anywhere, 1 is to use as embedded profile only 
};

// speed and quality flag options 
// deviceAttributes[0] is defined by and reserved for device vendors // deviceAttributes[1] is defined by and reserved for ICC // The following bits of deviceAttributes[1] are currently defined enum {
  cmReflectiveTransparentMask =
      0x0// it uses the least significent two bits in the high word of flag 
                     media */
  cmGlossyMatteMask =
      0x00000002 // if bit 1 is 0 then glossy, if 1 then matte };

// device/media attributes element values  enum {
  cmReflective =
      0, // if bit 0 is 0 then reflective media, if 1 then transparency media   cmGlossy = 1 // if bit 1 is 0 then glossy, if 1 then matte };
// deviceAttributes[0] is defined by and reserved for device vendors 
// deviceAttributes[1] is defined by and reserved for ICC 
// The following bits of deviceAttributes[1] are currently defined 
  cmPerceptual = 0,           // Photographic images   cmRelativeColorimetric = 1, // Logo Colors   cmSaturation = 2,           // Business graphics   cmAbsoluteColorimetric = 3  // Logo Colors };

// data type element values enum { cmAsciiData = 0, cmBinaryData = 1 };

// screen encodings  enum {
  cmPrtrDefaultSc// if bit 1 is 0 then glossy, if 1 then matte 
      0,         // Use printer default screens.  0 is false, 1 is ture   cmLinesPer = 1 // 0 is LinesPerCm, 1 is LinesPerInch };

// device/media attributes element values  

// public tags enum {
  cmAToB0// if bit 0 is 0 then reflective media, if 1 then transparency media 
  cmAToB1Tag = // if bit 1 is 0 then glossy, if 1 then matte 
  cmAToB2Tag = FOUR_CHAR_CODE('A2B2'),
  cmBlueColorantTag = FOUR_CHAR_CODE('bXYZ'),
  cmBlueTRCTag = FOUR_CHAR_CODE('bTRC'),
  cmBToA0Tag = FOUR_CHAR_CODE('B2A0'),
  cmBToA1Tag = FOUR_CHAR_CODE(// Photographic images 
  cmBToA2Tag = FOUR_CHAR_CODE(// Logo Colors 
  cmCalibrationDateTimeTag = F// Business graphics 
  cmChromaticAdaptationTag = F// Logo Colors 
  cmCharTargetTag = FOUR_CHAR_CODE('targ'),
  cmCopyrightTag = FOUR_CHAR_CODE('cprt'),
// data type element values 
  cmDeviceModelDescTag = FOUR_CHAR_CODE('dmdd'),
  cmGamutTag = FOUR_CHAR_CODE('gamt'),
// screen encodings  
  cmGreenColorantTag = FOUR_CHAR_CODE('gXYZ'),
  cmGreenTRCTag = FOUR_CHAR_CODE('gTRC'),
  cmLuminanceTag // Use printer default screens.  0 is false, 1 is ture 
  cmMeasurementTa// 0 is LinesPerCm, 1 is LinesPerInch 
  cmMediaBlackPointTag = FOUR_CHAR_CODE('bkpt'),
  cmMediaWhitePointTag = FOUR_CHAR_CODE('wtpt'),
// 2.0 tag type information 
  cmNamedColor2Tag = FOUR_CHAR_CODE('ncl2'),
  cmPreview0Tag = FOUR_CHAR_CODE('pre0'),
// public tags 
  cmPreview2Tag = FOUR_CHAR_CODE('pre2'),
  cmProfileDescriptionTag = FOUR_CHAR_CODE('desc'),
  cmProfileSequenceDescTag = FOUR_CHAR_CODE('pseq'),
  cmPS2CRD0Tag = FOUR_CHAR_CODE('psd0'),
  cmPS2CRD1Tag = FOUR_CHAR_CODE('psd1'),
  cmPS2CRD2Tag = FOUR_CHAR_CODE('psd2'),
  cmPS2CRD3Tag = FOUR_CHAR_CODE('psd3'),
  cmPS2CSATag = FOUR_CHAR_CODE('ps2s'),
  cmPS2RenderingIntentTag = FOUR_CHAR_CODE('ps2i'),
  cmRedColorantTag = FOUR_CHAR_CODE('rXYZ'),
  cmRedTRCTag = FOUR_CHAR_CODE('rTRC'),
  cmScreeningDescTag = FOUR_CHAR_CODE('scrd'),
  cmScreeningTag = FOUR_CHAR_CODE('scrn'),
  cmTechnologyTag = FOUR_CHAR_CODE('tech'),
  cmUcrBgTag = FOUR_CHAR_CODE('bfd '),
  cmViewingConditionsDescTag = FOUR_CHAR_CODE('vued'),
  cmViewingConditionsTag = FOUR_CHAR_CODE('view')
};

// custom tags enum {
  cmPS2CRDVMSizeTag = FOUR_CHAR_CODE('psvm'),
  cmVideoCardGammaTag = FOUR_CHAR_CODE('vcgt'),
  cmMakeAndModelTag = FOUR_CHAR_CODE('mmod'),
  cmProfileDescriptionMLTag = FOUR_CHAR_CODE('dscm')
};

// technology tag descriptions enum {
  cmTechnologyFilmScanner = FOUR_CHAR_CODE('fscn'),
  cmTechnologyReflectiveScanner = FOUR_CHAR_CODE('rscn'),
  cmTechnologyInkJetPrinter = FOUR_CHAR_CODE('ijet'),
  cmTechnologyThermalWaxPrinter = FOUR_CHAR_CODE('twax'),
  cmTechnologyElectrophotographicPrinter = FOUR_CHAR_CODE('epho'),
  cmTechnologyElectrostaticPrinter = FOUR_CHAR_CODE('esta'),
  cmTechnologyDyeSublimationPrinter = FOUR_CHAR_CODE('dsub'),
  cmTechnologyPhotographicPaperPrinter = FOUR_CHAR_CODE('rpho'),
  cmTechnologyFilmWriter = FOUR_CHAR_CODE('fprn'),
  cmTechnologyVideoMonitor = FOUR_CHAR_CODE('vidm'),
  cmTechnologyVideoCamera = FOUR_CHAR_CODE('vidc'),
  cmTechnologyProjectionTelevision = FOUR_CHAR_CODE('pjtv'),
  cmTechnologyCRTDisplay = FOUR_CHAR_CODE('CRT '),
  cmTechnologyPMDisplay = FOUR_CHAR_CODE('PMD '),
  cmTechnologyAMDisplay = FOUR_CHAR_CODE('AMD '),
  cmTechnologyPhotoCD = FOUR_CHAR_CODE('KPCD'),
  cmTechnologyPhotoImageSetter = FOUR_CHAR_CODE('imgs'),
  cmTechnologyGravure = FOUR_CHAR_CODE('grav'),
  cmTechnologyOffsetLithography = FOUR_CHAR_CODE('offs'),
// custom tags 
  cmTechnologyFlexography = FOUR_CHAR_CODE('flex')
};

// public type signatures enum {
  cmSigCurveType = FOUR_CHAR_CODE('curv'),
  cmSigDataType = FOUR_CHAR_CODE('data'),
  cmSigDateTimeType = FOUR_CHAR_CODE('dtim'),
// technology tag descriptions 
  cmSigLut8Type = FOUR_CHAR_CODE('mft1'),
  cmSigMeasurementType = FOUR_CHAR_CODE('meas'),
  cmSigNamedColorType = FOUR_CHAR_CODE('ncol'),
  cmSigNamedColor2Type = FOUR_CHAR_CODE('ncl2'),
  cmSigProfileDescriptionType = FOUR_CHAR_CODE('desc'),
  cmSigScreeningType = FOUR_CHAR_CODE('scrn'),
  cmSigS15Fixed16Type = FOUR_CHAR_CODE('sf32'),
  cmSigSignatureType = FOUR_CHAR_CODE('sig '),
  cmSigTextType = FOUR_CHAR_CODE('text'),
  cmSigU16Fixed16Type = FOUR_CHAR_CODE('uf32'),
  cmSigU1Fixed15Type = FOUR_CHAR_CODE('uf16'),
  cmSigUInt8Type = FOUR_CHAR_CODE('ui08'),
  cmSigUInt16Type = FOUR_CHAR_CODE('ui16'),
  cmSigUInt32Type = FOUR_CHAR_CODE('ui32'),
  cmSigUInt64Type = FOUR_CHAR_CODE('ui64'),
  cmSigUcrBgType = FOUR_CHAR_CODE('bfd '),
  cmSigUnicodeTextType = FOUR_CHAR_CODE('utxt'),
  cmSigViewingConditionsType = FOUR_CHAR_CODE('view'),
  cmSigXYZType = FOUR_CHAR_CODE('XYZ ')
};

// custom type signatures enum {
  cmSigPS2CRDVMSizeType = FOUR_CHAR_CODE('psvm'),
  cmSigVideoCardGammaType = FOUR_CHAR_CODE('vcgt'),
// public type signatures 
  cmSigMultiLocalizedUniCodeType = FOUR_CHAR_CODE('mluc')
};

// Measurement type encodings // Measurement Flare enum { cmFlare0 = 0x00000000, cmFlare100 = 0x00000001 };

// Measurement Geometry enum {
  cmGeometryUnknown = 0x00000000,
  cmGeometry045or450 = 0x00000001,
  cmGeometry0dord0 = 0x00000002
};

// Standard Observer    enum {
  cmStdobsUnknown = 0x00000000,
  cmStdobs1931TwoDegrees = 0x00000001,
  cmStdobs1964TenDegrees = 0x00000002
};

// Standard Illuminant enum {
  cmIlluminantUnknown = 0x00000000,
  cmIlluminantD50 = 0x00000001,
  cmIlluminantD65 = 0x00000002,
  cmIlluminantD93 = 0x00000003,
  cmIlluminantF2 = 0x00000004,
  cmIlluminantD55 = 0x00000005,
  cmIlluminantA = 0x00000006,
  cmIlluminantEquiPower = 0x00000007,
// custom type signatures 
};

// Spot Function Value enum {
  cmSpotFunctionUnknown = 0,
  cmSpotFunctionDefault = 1,
  cmSpotFunctionRound = 2,
  cmSpotFunctionDiamond = 3,
// Measurement type encodings 
// Measurement Flare 
  cmSpotFunctionSquare = 6,
  cmSpotFunctionCross = 7
// Measurement Geometry 

// Color Space Signatures enum {
  cmXYZData = FOUR_CHAR_CODE('XYZ '),
  cmLabData = FOUR_CHAR_CODE('Lab '),
  cmLuvData = FOUR_CHAR_CODE('Luv '),
  cmYxyData = FOUR_CHAR_CODE('Yxy '),
// Standard Observer    
  cmSRGBData = FOUR_CHAR_CODE('sRGB'),
  cmGrayData = FOUR_CHAR_CODE('GRAY'),
  cmHSVData = FOUR_CHAR_CODE('HSV '),
  cmHLSData = FOUR_CHAR_CODE('HLS '),
  cmCMYKData = FOUR_CHAR_CODE('CMYK'),
  cmCMYData = FOUR_CHAR_CODE('CMY '),
// Standard Illuminant 
  cmMCH6Data = FOUR_CHAR_CODE('MCH6'),
  cmMCH7Data = FOUR_CHAR_CODE('MCH7'),
  cmMCH8Data = FOUR_CHAR_CODE('MCH8'),
  cm3CLRData = FOUR_CHAR_CODE('3CLR'),
  cm4CLRData = FOUR_CHAR_CODE('4CLR'),
  cm5CLRData = FOUR_CHAR_CODE('5CLR'),
  cm6CLRData = FOUR_CHAR_CODE('6CLR'),
  cm7CLRData = FOUR_CHAR_CODE('7CLR'),
  cm8CLRData = FOUR_CHAR_CODE('8CLR'),
  cmNamedData = FOUR_CHAR_CODE('NAME')
};

// Spot Function Value 
  cmInputClass = FOUR_CHAR_CODE('scnr'),
  cmDisplayClass = FOUR_CHAR_CODE('mntr'),
  cmOutputClass = FOUR_CHAR_CODE('prtr'),
  cmLinkClass = FOUR_CHAR_CODE('link'),
  cmAbstractClass = FOUR_CHAR_CODE('abst'),
  cmColorSpaceClass = FOUR_CHAR_CODE('spac'),
  cmNamedColorClass = FOUR_CHAR_CODE('nmcl')
};

// platform enumerations enum {
  cmMacintosh = FOUR_CHAR_CODE('APPL'),
// Color Space Signatures 
  cmSolaris = FOUR_CHAR_CODE('SUNW'),
  cmSiliconGraphics = FOUR_CHAR_CODE('SGI '),
  cmTaligent = FOUR_CHAR_CODE('TGNT')
};

// ColorSync 1.0 elements enum {
  cmCS1ChromTag = FOUR_CHAR_CODE('chrm'),
  cmCS1TRCTag = FOUR_CHAR_CODE('trc '),
  cmCS1NameTag = FOUR_CHAR_CODE('name'),
  cmCS1CustTag = FOUR_CHAR_CODE('cust')
};

// General element data types struct CMDateTime {
  UInt16 year;
  UInt16 month;
  UInt16 dayOfTheMonth;
  UInt16 hours;
  UInt16 minutes;
  UInt16 seconds;
};
typedef struct CMDateTime CMDateTime;
struct CMFixedXYZColor {
  Fixed X;
  Fixed Y;
  Fixed Z;
// profileClass enumerations 
typedef struct CMFixedXYZColor CMFixedXYZColor;

typedef UInt16 CMXYZComponent;
struct CMXYZColor {
  CMXYZComponent X;
  CMXYZComponent Y;
  CMXYZComponent Z;
};
typedef struct CMXYZColor CMXYZColor;
struct CM2Header {
// platform enumerations 
                          conversion profile type */
  OSType dataColorSpace;         // color space of data   OSType profileConnectionSpace; // profile connection color space   CMDateTime dateTime;           // date and time of profile creation   OSType CS2profileSignature;    // 'acsp' constant ColorSync 2.0 file ID   OSType
      platform; // primary profile platform, Registered with CS2 consortium   UInt32 flags; // profile flags   OSType deviceManufacturer;  // Registered with ICC consortium   UInt32 deviceModel;         // Registered with ICC consortium   UInt32 deviceAttributes[2]; /* Attributes[0] is for device vendors, [1] is for
                                 ICC */
  UInt32 renderingIntent;     // preferred rendering intent of tagged object   CMFixedXYZColor white;      // profile illuminant   OSType creator;             // profile creator   char reserved[44];          // reserved for future use };
typedef struct CM2Header CM2Header;
struct CMTagRecord {
  OSType tag;           // Registered with CS2 consortium   UInt32 elementOffset; // Relative to start of CMProfile   UInt32 elementSize;
// ColorSync 1.0 elements 
typedef struct CMTagRecord CMTagRecord;
struct CMTagElemTable {
  UInt32 count;
  CMTagRecord tagList[1]; // variable size, determined by count };
typedef struct CMTagElemTable CMTagElemTable;
struct CM2Profile {
  CM2Header header;
// General element data types 
  char elemData[1]; // variable size data for tagged element storage };
typedef struct CM2Profile CM2Profile;
typedef CM2Profile *CM2ProfilePtr;
typedef CM2ProfilePtr *CM2ProfileHandle;
// Tag Type Definitions struct CMAdaptationMatrixType {
  OSType typeDescriptor;     // 'sf32' = cmSigS15Fixed16Type   unsigned long reserved;    // fill with 0x00   Fixed adaptationMatrix[9]; // fixed size of nine matrix entries };
typedef struct CMAdaptationMatrixType CMAdaptationMatrixType;
struct CMCurveType {
  OSType typeDescriptor; // 'curv' = cmSigCurveType   UInt32 reserved;       // fill with 0x00   UInt32 countValue;     // number of entries in table that follows   UInt16 data[1];        // variable size, determined by countValue };
typedef struct CMCurveType CMCurveType;
struct CMDataType {
  OSType typeDescriptor; // 'data' = cmSigDataType  UInt32 reserved;       // fill with 0x00   UInt32 dataFlag;       // 0 = ASCII, 1 = binary   char data[1];          // variable size, determined by tag element size };
typedef struct CMDataType CMDataType;
struct CMDateTimeType {
  OSType typeDescriptor; // 'dtim' = cmSigDateTimeType   UInt32 reserved;       // fill with 0x00   CMDateTime dateTime;   // };
typedef struct CMDateTimeType CMDateTimeType;
struct CMLut16Type {
  OSType typeDescriptor;     // 'mft2' = cmSigLut16Type   UInt32 reserved;           // fill with 0x00   UInt8 inputChannels;       // Number of input channels   UInt8 outputChannels;      // Number of output channels   UInt8 gridPoints;          // Number of clutTable grid points   UInt8 reserved2;           // fill with 0x00   Fixed matrix[3][3];        //   UInt16 inputTableEntries;  // Number of entries in 1-D input luts   UInt16 outputTableEntries; // Number of entries in 1-D output luts   UInt16 inputTable[1];      /* variable size, determined by
                                inputChannels*inputTableEntries */
#if 0 // NOTE: Field offsets are variable from here on.   // In order to correctly reflect the actual format of this tag, some of the fields in   // this structure have been removed because they follow an array field of variable size.   // As a result, the size of this structure has changed from previous versions of this interface.   // Code that relies on sizeof(CMLut16Type) should be changed.   UInt16              CLUT[];                 // variable size, determined by (gridPoints^inputChannels)*outputChannels   UInt16              outputTable[];          // variable size, determined by outputChannels*outputTableEntries #endif
};
typedef struct CMLut16Type CMLut16Type;
struct CMLut8Type {
  OSType typeDescriptor; // 'mft1' = cmSigLut8Type   UInt32 reserved;       // fill with 0x00   UInt8 inputChannels;   // Number of input channels   UInt8 outputChannels;  // Number of output channels   UInt8 gridPoints;      // Number of clutTable grid points   UInt8 reserved2;       // fill with 0x00   Fixed matrix[3][3];    //   UInt8 inputTable[1];   // variable size, determined by inputChannels*256 #if 0                    // NOTE: Field offsets are variable from here on.   // In order to correctly reflect the actual format of this tag, some of the fields in   // this structure have been removed because they follow an array field of variable size.   // As a result, the size of this structure has changed from previous versions of this interface.   // Code that relies on sizeof(CMLut8Type) should be changed.   UInt8               CLUT[];                 // variable size, determined by (gridPoints^inputChannels)*outputChannels   UInt8               outputTable[];          // variable size, determined by outputChannels*256 #endif
};// This is the total size of the Profile 
typedef struct CMLut8Type// CMM signature,  Registered with CS2 consortium  
struct CMMeasurementType // Version of CMProfile format 
  OSType typeDescriptor;      // 'meas' = cmSigMeasurementType   UInt32 reserved;            // fill with 0x00   UInt32 standardObserver;    /* cmStdobsUnknown, cmStdobs1931TwoDegrees,
                                 cmStdobs1964TenDegrees */
  CMFixedXYZColor backingXYZ; // // color space of data 
                                 // profile connection color space 
  UInt32 flare;               // // date and time of profile creation 
typedef struct CMMeasurementType // 'acsp' constant ColorSync 2.0 file ID 
struct CMNamedColorType {
  OSType typeDes// primary profile platform, Registered with CS2 consortium 
    UInt8       // profile flags 
};// Registered with ICC consortium 
typedef struct CMNamedColorTyp// Registered with ICC consortium 
struct CMNamedColor2EntryType {
  UInt8 rootName[32];          // 32 byte field.  7 bit ASCII null terminated   UInt16 PCSColorCoords[3];    // Lab or XYZ color   UInt16 DeviceColorCoords[1]; // variable size };
typedef struct CMNamedColor2En// preferred rendering intent of tagged object 
struct CMNamedColor2Type {// profile illuminant 
  OSType typeDescriptor;     /// profile creator 
                              // reserved for future use 
  UInt8 prefixName[32]; // Fixed 32 byte size.  7 bit ASCII null terminated   UInt8 suffixName[32]; // Fixed 32 byte size.  7 bit ASCII null terminated   char data[1];         // variable size data for CMNamedColor2EntryType };
typedef struct CMNamedColor2Type CMNamedColor2Type;
struct CMTextDescriptionType {
  OSType typeDescriptor;// Registered with CS2 consortium 
                        // Relative to start of CMProfile 
#if 0                 // NOTE: Field offsets are variable from here on.   // In order to correctly reflect the actual format of this tag, some of the fields in   // this structure have been removed because they follow an array field of variable size.   // As a result, the size of this structure has changed from previous versions of this interface.   // Code that relies on sizeof(CMTextDescriptionType) should be changed.   UInt32              UniCodeCode;            // Unused   UInt32              UniCodeCount;           // Count of 2-byte characters (including null terminator)   UInt8               UniCodeName[];          // variable size, determined by UniCodeCount   SInt16              ScriptCodeCode;         // Mac-defined script code   UInt8               ScriptCodeCount;        // Count of bytes (including null terminator)   UInt8               ScriptCodeName[];       // variable size, determined by ScriptCodeCount #endif
};
typedef struct CMTextDescriptionType CMTextDescriptionType;
struct CMTextType {
  OSType typeDescriptor; // 'text' = cmSigTextType   UInt32 reserved;       // fill with 0x00   UInt8 text[1];         // variable size, determined by tag element size };
typedef struct CMTextType // variable size, determined by count 
struct CMUnicodeTextType {
  OSType typeDescriptor; // 'utxt' = cmSigUnicodeTextType   UInt32 reserved;       // fill with 0x00   UniChar text[1];       // variable size, determined by tag element size  };
typedef struct CMUnicodeTextType CMUnicodeTextType;
struct CMScreeningChannelRec {
  Fixed frequency;
  Fixed angle;// variable size data for tagged element storage 
  UInt32 spotFunction;
};
typedef struct CMScreeningChannelRec CMScreeningChannelRec;
struct CMScreeningType {
// Tag Type Definitions 
      screeningFlag; // bit 0 : use printer default screens, bit 1 : inch/cm   UInt32 channelCount; //   CMScreeningChannelRec
      channelInfo[1]; // vari// 'sf32' = cmSigS15Fixed16Type 
typedef struct CMScreeningTyp// fill with 0x00 
struct CMSignatureType {// fixed size of nine matrix entries 
  OSType typeDescriptor; // 'sig ' = cmSigSignatureType   UInt32 reserved;       // fill with 0x00   OSType signature;
};
typedef struct CMSignatureType CMSignatureType;
struct CMS15Fixed16ArrayT// 'curv' = cmSigCurveType 
  OSType typeDescriptor; // fill with 0x00 
typedef struct CMS15Fixed// number of entries in table that follows 
struct CMU16Fixed16ArrayT// variable size, determined by countValue 
  OSType typeDescriptor; // 'uf32' = cmSigU16Fixed16Type   UInt32 reserved;       // fill with 0x00   UInt32 value[1];       // variable size, determined by tag element size };
typedef struct CMU16Fixed16ArrayType CMU16Fixed16ArrayType;
struct CMUInt8ArrayType {
  OSType typeDescriptor; // 'data' = cmSigDataType
typedef struct CMUInt8Arr// fill with 0x00 
struct CMUInt16ArrayType // 0 = ASCII, 1 = binary 
  OSType typeDescriptor; // variable size, determined by tag element size 
typedef struct CMUInt16ArrayType CMUInt16ArrayType;
struct CMUInt32ArrayType {
  OSType typeDescriptor; // 'ui32' = cmSigUInt32Type   UInt32 reserved;       // fill with 0x00   UInt32 value[1];       // variable size, determined by tag element size };
typedef struct CMUInt32Ar// 'dtim' = cmSigDateTimeType 
struct CMUInt64ArrayType // fill with 0x00 
  OSType typeDescriptor; // 
typedef struct CMUInt64ArrayType CMUInt64ArrayType;
struct CMViewingConditionsType {
  OSType typeDescriptor;      // 'view' = cmSigViewingConditionsType   UInt32 reserved;            // fill with 0x00   CMFixedXYZColor illuminant; // absolute XYZs of illuminant  in cd/m^2   CMFixedXYZColor surround;   // absolute XYZs of surround in cd/m^2   UInt32 stdIlluminant;       // see definitions of std illuminants };
typedef struct CMViewingCondi// 'mft2' = cmSigLut16Type 
struct CMXYZType {// fill with 0x00 
  OSType typeDescriptor;  // // Number of input channels 
typedef struct CMXYZType CMXY// Number of output channels 
struct CMProfileSequenceDescT// Number of clutTable grid points 
  OSType typeDescriptor; // '// fill with 0x00 
typedef struct CMProfileSeque// 
struct CMUcrBgType {// Number of entries in 1-D input luts 
  OSType typeDescriptor; // '// Number of entries in 1-D output luts 
};
typedef struct CMUcrBgType CMUcrBgType;
// Pri// NOTE: Field offsets are variable from here on. 
  // In order to correctly reflect the actual format of this tag, some of the fields in 
ty// this structure have been removed because they follow an array field of variable size. 
st// As a result, the size of this structure has changed from previous versions of this interface. 
  // Code that relies on sizeof(CMLut16Type) should be changed. 
typedef struct CMPS2CRDVMSizeType CMPS2CRDVMSi// variable size, determined by (gridPoints^inputChannels)*outputChannels 
enum { cmVideoCardGammaTableType = 0, cmVideoC// variable size, determined by outputChannels*outputTableEntries 

struct CMVideoCardGammaTable {
  UInt16 channels;   // # of gamma channels (1 or 3)   UInt16 entryCount; // 1-based number of entries per channel   UInt16 entrySize;  // size in bytes of each entry   char data[1]; // variable size, determined by channels*entryCount*entrySize };
typedef struct CMVideoCardGammaTable CMVideoCardGammaTable;
struct CMVideoCardGammaFo// 'mft1' = cmSigLut8Type 
  Fixed redGamma;   // mu// fill with 0x00 
typedef struct CMVideoCar// Number of input channels 
struct CMVideoCardGamma {// Number of output channels 
  UInt32 tagType;// Number of clutTable grid points 
  union {// fill with 0x00 
    CMVideoCardGammaTable// 
    CMVideoCardGammaFormu// variable size, determined by inputChannels*256 
  } u;// NOTE: Field offsets are variable from here on. 
};// In order to correctly reflect the actual format of this tag, some of the fields in 
ty// this structure have been removed because they follow an array field of variable size. 
st// As a result, the size of this structure has changed from previous versions of this interface. 
  // Code that relies on sizeof(CMLut8Type) should be changed. 
};// variable size, determined by (gridPoints^inputChannels)*outputChannels 
typedef struct CMVideoCardGammaType CMVideoCar// variable size, determined by outputChannels*256 
struct CMMakeAndModel {
  OSType manufacturer;
  UInt32 model;
  UInt32 serialNumber;
  UInt32 manufactureDate;// 'meas' = cmSigMeasurementType 
  UInt32 reserved1; // fill wi// fill with 0x00 
typedef struct CMMakeAndModel CMMakeAndModel;
struct CMMakeAndModelType {
  OSType typeDescriptor; // 'm// absolute XYZ values of backing 
};
typedef struct CMMakeAndModelType CMMakeAndModelType;
struct CMMultiLocalizedUniCode// cmFlare0, cmFlare100 
  char languageCode[2]; // lan// cmIlluminantUnknown, cmIlluminantD50, ... 
typedef struct CMMultiLocalizedUniCodeEntryRec CMMultiLocalizedUniCodeEntryRec;
struct CMMultiLocalizedUniCodeType {
  OSType typeDescriptor; // 'mluc' = cmSigMultiLocalizedUniCodeType   UInt32 reserved;       // fill with 0x00   UInt32 entryCount;     // 1-based number of name records that follow   UInt32 entrySize;      // size in bytes of name records that follow 
  // variable-length data// 'ncol' = cmSigNamedColorType 
  // variable-length data// fill with 0x00 
typedef struct CMMultiLoc// 
/************************// count of named colors in array that follows 
/*************** ColorSyn// variable size, max = 32 
/************************// NOTE: Field offsets are variable from here on. 
en// In order to correctly reflect the actual format of this tag, some of the fields in 
  // this structure have been removed because they follow an array field of variable size. 
  // As a result, the size of this structure has changed from previous versions of this interface. 
  // Code that relies on sizeof(CMNamedColorType) should be changed. 
  cmBlueResponse = 3,// variable size, max = 32 
  cmCyanResponse = 4,
  cmMagentaResponse = 5,// variable size, max = 32 
  cmYellowResponse = 6,// variable size 
  cmUcrResponse = 7,// variable size 
  cmBgResponse = 8,
  cmOnePlusLastResponse = 9
};

// Device types enum {// 32 byte field.  7 bit ASCII null terminated 
  cmMonitorDevice = FOUR_CHAR_C// Lab or XYZ color 
  cmScannerDevice = FOUR_CHAR_C// variable size 
  cmPrinterDevice = FOUR_CHAR_CODE('prtr')
};

struct CMIString {// 'ncl2' = cmSigNamedColor2Type 
  ScriptCode theScript;// fill with 0x00 
  Str63 theString;// lower 16 bits reserved for ICC use 
};// count of named colors in array that follows 
typedef struct CMIString CMIString;
// Profile options enum {
  cmPerceptualMatch = 0x// Fixed 32 byte size.  7 bit ASCII null terminated 
// Fixed 32 byte size.  7 bit ASCII null terminated 
// Profile flags enum {// variable size data for CMNamedColor2EntryType 
  cmNativeMatchingPreferred = 0x00000001, // Default to native not preferred   cmTurnOffCache = 0x00000002             // Default to turn on CMM cache };

typedef long CMMatchOption;
typedef long CMMatchFlag;// 'desc' = cmSigProfileDescriptionType 
struct CMHeader {// fill with 0x00 
  UInt32 size;// Count of bytes (including null terminator)  
  OSType CMMType;
  UInt32 applProfileVersion;
  OSType dataType;// NOTE: Field offsets are variable from here on. 
  // In order to correctly reflect the actual format of this tag, some of the fields in 
  // this structure have been removed because they follow an array field of variable size. 
  // As a result, the size of this structure has changed from previous versions of this interface. 
  // Code that relies on sizeof(CMTextDescriptionType) should be changed. 
  UInt32 profileNameOffset;// Unused 
  UInt32 customDataOffset;// Count of 2-byte characters (including null terminator) 
  CMMatchFlag flags;// variable size, determined by UniCodeCount 
  CMMatchOption options;// Mac-defined script code 
  CMXYZColor white;// Count of bytes (including null terminator) 
  CMXYZColor black;// variable size, determined by ScriptCodeCount 
};
typedef struct CMHeader CMHeader;
struct CMProfileChromaticities {
  CMXYZColor red;
  CMXYZColor green;// 'text' = cmSigTextType 
  CMXYZColor blue;// fill with 0x00 
  CMXYZColor cyan;// variable size, determined by tag element size 
  CMXYZColor magenta;
  CMXYZColor yellow;
};
typedef struct CMProfileC// 'utxt' = cmSigUnicodeTextType 
struct CMProfileResponse // fill with 0x00 
  UInt16 counts[9];// variable size, determined by tag element size  
  UInt16 data[1]; // Variable size };
typedef struct CMProfileResponse CMProfileResponse;
struct CMProfile {
  CMHeader header;
  CMProfileChromaticities profile;
  CMProfileResponse response;
  CMIString profileName;
  char customData[1]; // Variable size };
typedef struct CMProfile CMProfile;
typedef CMProfile *CMProf// 'scrn' = cmSigScreeningType 
typedef CMProfilePtr *CMP// fill with 0x00 
#if OLDROUTINENAMES
enum { kCMApplProfile// bit 0 : use printer default screens, bit 1 : inch/cm 
// 
enum {
  grayResponse = cmGra// variable size, determined by channelCount 
  redResponse = cmRedResponse,
  greenResponse = cmGreenResponse,
  blueResponse = cmBlueResponse,
  cyanResponse = cmCyanRe// 'sig ' = cmSigSignatureType 
  magentaResponse = cmMag// fill with 0x00 
  yellowResponse = cmYellowResponse,
  ucrResponse = cmUcrResponse,
  bgResponse = cmBgResponse,
  onePlusLastResponse = cmOnePlusLastResponse
};// 'sf32' = cmSigS15Fixed16Type 
// fill with 0x00 
enum {// variable size, determined by tag element size 
  rgbData = cmRGBData,
  cmykData = cmCMYKData,
  grayData = cmGrayData,
  xyzData = cmXYZData// 'uf32' = cmSigU16Fixed16Type 
};// fill with 0x00 
// variable size, determined by tag element size 
enum { XYZData = cmXYZData };

enum {
  monitorDevice = cmMonit// 'ui08' = cmSigUInt8Type 
  scannerDevice = cmScann// fill with 0x00 
  printerDevice = cmPrint// variable size, determined by tag element size 
};

enum {
  CMNativeMatchingPreferr// 'ui16' = cmSigUInt16Type 
      cmNativeMatchingPre// fill with 0x00 
// variable size, determined by tag element size 
enum {
  CMPerceptualMatch = cmPerceptualMatch, // Default. For photographic images   CMColorimetricMatch = cmColorimetricMatch, // Exact matching when possible   CMSaturationMatch = cmSaturationMatch      // For solid colors };

typedef UInt16 XYZCompone// 'ui32' = cmSigUInt32Type 
typedef CMXYZColor XYZCol// fill with 0x00 
typedef UInt16 CMResponse// variable size, determined by tag element size 
typedef CMIString IString;
typedef long CMResponseColor;
typedef CMResponseColor responseColor;
#endif // OLDROUTINENAMES// 'ui64' = cmSigUInt64Type 
#if PRAGMA_STRUCT_ALIGN// fill with 0x00 
#pragma options align = r// variable size, determined by tag element size 
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack()// 'view' = cmSigViewingConditionsType 
#endif// fill with 0x00 
// absolute XYZs of illuminant  in cd/m^2 
#ifdef PRAGMA_IMPORT_OFF// absolute XYZs of surround in cd/m^2 
#pragma import off// see definitions of std illuminants 
#elif PRAGMA_IMPORT
#pragma import reset
#endif
// 'XYZ ' = cmSigXYZType 
#ifdef __cplusplus// fill with 0x00 
}// variable size, determined by tag element size 
#endif

#endif // __CMICCPROFILE__ // 'pseq' = cmProfileSequenceDescTag 
// fill with 0x00 
// Number of descriptions 
// variable size data explained in ICC spec 
// 'bfd ' = cmSigUcrBgType 
// fill with 0x00 
// Number of UCR entries 
// variable size, determined by ucrCount 
// NOTE: Field offsets are variable from here on. 
// In order to correctly reflect the actual format of this tag, some of the fields in 
// this structure have been removed because they follow an array field of variable size. 
// As a result, the size of this structure has changed from previous versions of this interface. 
// Code that relies on sizeof(CMUcrBgType) should be changed. 
// Number of BG entries 
// variable size, determined by bgCount 
// null terminated ASCII string 
// Private Tag Type Definitions 
// rendering intent 
// VM size taken up by the CRD 
// 'psvm' = cmSigPS2CRDVMSizeType 
// fill with 0x00 
// number of intent entries 
// variable size, determined by count 
// # of gamma channels (1 or 3) 
// 1-based number of entries per channel 
// size in bytes of each entry 
// variable size, determined by channels*entryCount*entrySize 
// must be > 0.0 
// must be > 0.0 and < 1.0 
// must be > 0.0 and < 1.0 
// must be > 0.0 
// must be > 0.0 and < 1.0 
// must be > 0.0 and < 1.0 
// must be > 0.0 
// must be > 0.0 and < 1.0 
// must be > 0.0 and < 1.0 
// 'vcgt' = cmSigVideoCardGammaType 
// fill with 0x00 
// fill with 0x00 
// fill with 0x00 
// fill with 0x00 
// fill with 0x00 
// 'mmod' = cmSigMakeAndModelType 
// fill with 0x00 
// language code from ISO-639 
// region code from ISO-3166 
// the length in bytes of the string 
// the offset from the start of tag in bytes 
// 'mluc' = cmSigMultiLocalizedUniCodeType 
// fill with 0x00 
// 1-based number of name records that follow 
// size in bytes of name records that follow 
// variable-length data for storage of CMMultiLocalizedUniCodeEntryRec 
// variable-length data for storage of Unicode strings
// Device types 
// Profile options 
// Default. For photographic images 
// Exact matching when possible 
// For solid colors 
// Profile flags 
// Default to native not preferred 
// Default to turn on CMM cache 
// Variable size 
// Variable size 
// Default to native not preferred 
// Default to turn on CMM cache 
// Default. For photographic images 
// Exact matching when possible 
// For solid colors 
// OLDROUTINENAMES 
// __CMICCPROFILE__ 
