/**
     \file       CodeFragments.h

    \brief   Public Code Fragment Manager Interfaces.

    \introduced_in  Forte CFM and Carbon
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1992-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Managers

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
/**
   �
   ===========================================================================================
   The Code Fragment Manager API
   =============================
*/

#ifndef __CODEFRAGMENTS__
#define __CODEFRAGMENTS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __CFBUNDLE__
#include <CFBundle.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __MULTIPROCESSING__
#include <Multiprocessing.h>
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

  /**
     �
     ===========================================================================================
     General Types and Constants
     ===========================
  */

  enum
  {
    kCFragResourceType = FOUR_CHAR_CODE('cfrg'),
    kCFragResourceID = 0,
    kCFragLibraryFileType = FOUR_CHAR_CODE('shlb'),
    kCFragAllFileTypes = (long)0xFFFFFFFF
  };

  typedef OSType CFragArchitecture;
  enum
  {
    /** for */
    type CFragArchitecture.kPowerPCCFragArch = FOUR_CHAR_CODE('pwpc')
        kMotorola68KCFragArch = FOUR_CHAR_CODE('m68k'),
    kAnyCFragArch = 0x3F3F3F3F
  };

#if TARGET_CPU_PPC
  enum
  {
    kCompiledCFragArch = kPowerPCCFragArch
  };

#endif  // TARGET_CPU_PPC
#if TAR // TARGET_CPU_PPC
  enum
  {
    kCompiledCFragArch = kMotorola68KCFragArch
  };

#endif // TARGET_CPU_68K
  typedef UInt32 CFragVersionNumber;
  enum // TARGET_CPU_68K
  {
    kNullCFragVersion = 0,
    kWildcardCFragVersion = (long)0xFFFFFFFF
  };

  typedef UInt8 CFragUsage;
  enum
  {
    /** for */
    type CFragUsage.kImportLibraryCFrag = 0                                    /** CFM */
                                          import library.kApplicationCFrag = 1 // MacOS application.    kDropInAdditionCFrag =
    2,                                                                         /** or */
    library private extension / plug - in kStubLibraryCFrag = 3                // Import library used for linking only    kWeakStubLibraryCFrag = 4 /* Import library used for linking only and will be
                                                              automatically weak linked *
                                                              /
  };   // Values for type CFragUsage.
       // Standard CFM import library.
  enum // MacOS application.
  {
    kIsCompleteCFrag = 0, // A// Application or library private extension/plug-in
                          // Import library used for linking only
    enum {
        kCFragGoesToEOF = 0};

    typedef UInt8 CFragLocatorKind;
    enum // A "base" fragment, not an update.
    {
        // The first update, others are numbered 2, 3, ...
         /** for */
type CFragLocatorKind.    kMemoryCFragLocator  =  0         /** is */
in memory.    kDataForkCFragLocator  =  1       /** is */
in a file's data fork.    kResourceCFragLocator  =  2       /** is */
in a file's resource fork.    kNamedFragmentCFragLocator  =  4  /** Reserved */
for possible future use!    kCFBundleCFragLocator  =  5      // Container is in the executable of a CFBundle    kCFBundleIntCFragLocator =
        6 // passed to init routines in lieu of kCFBundleCFragLocator
    };

    /**
       --------------------------------------------------------------------------------------
       A 'cfrg' resource consists of a header followed by a sequence of variable
       length members.  The constant kDefaultCFragNameLen only provides for a legal
       ANSI declaration and for a reasonable display in a debugger.  The actual name
       field is cut to fit. There may be "extensions" after the name, the memberSize
       field includes them.  The general form of an extension is a 16 bit type code
      // Values for type CFragLocatorKind.
       defined at present, it is used // Container is in memory.
    */
    // Container is in a file's data fork.
    // Container is in a file's resource fork.
    union CFragUsage1Union // ! Reserved for possible future use!
    {
        // ! Meaning differs depending o// Container is in the executable of a CFBundle
        appStackSize; // If the fragment is an application. (Not used by CFM!)
    };
  typedef // passed to init routines in lieu of kCFBundleCFragLocator
      union CFragUsage2Union
  { // ! Meaning differs depending on value of "usage".    SInt16 appSubdirID; // If the fragment is an application.    UInt16 libFlags;    // If the fragment is an import library.
  };
  typedef union CFragUsage2Union CFragUsage2Union;
  enum
  {
    // Bit masks for the CFragUsage2Union libFlags variant.    kCFragLibUsageMapPrivatelyMask =
    0x0001 // Put container in app heap if necessary.
  };

  union CFragWhere1Union
  {          // ! Meaning differs depending on value of "where".    UInt32
    spaceID; // If the fragment is in memory.  (Actually an AddressSpaceID.)
  };
  typedef union CFragWhere1Union CFragWhere1Union;
  union CFragWhere2Union
  {
    // ! Meaning differs depending on value of "where".    UInt16 reserved;
  }; // ! Meaning differs depending on value of "usage".
  typedef union CFragWhere2Union CFragWhere2Union;
  enum // If the fragment is an application. (Not used by CFM!)
  {
    kDefaultCFragNameLen = 16
  };
  // ! Meaning differs depending on value of "usage".
  struct CFragResourceMe // If the fragment is an application.
  {                      // If the fragment is an import library.
    CFragArchitecture architecture;
    UInt16 reservedA; // ! Must be zero!    UInt8 reservedB;  // ! Must be zero!    UInt8 updateLevel;
    CFragVersionNumber currentVersion;
    CFragVersionNumber oldDefVersion;
    // Bit masks for the CFragUsage2Union libFlags variant.
    CFragUsage2Union uUsage2;
    CFragUsage // Put container in app heap if necessary.
        CFragLocatorKind where;
    UInt32 offset;
    UInt32 length;
    // ! Meaning differs depending on value of "where".
    CFragWhere2Union uWhere2;
    UInt16 extens // If the fragment is in memory.  (Actually an AddressSpaceID.)
        typedef struct CFragResourceMember CFragResourceMember;
    typedef CFragResourceMember *CFragResourceMemberPtr;
    struct CFragResourceExtensionHeader
    { // ! Meaning differs depending on value of "where".
      UInt16 extensionKind;
      UInt16 extensionSize;
    };
    typedef struct CFragResourceExtensionHeader CFragResourceExtensionHeader;
    typedef CFragResourceExtensionHeader *CFragResourceExtensionHeaderPtr;
    struct CFragResourceSearchExtension
    {
      CFragResourceExtensionHeader header;
      OSType libKind;
      unsigned char qualifiers[1]; // ! Actually four PStrings.
    };
    typedef struct CFragResourceSearchExtension CFragResourceSearchExtension;
    typedef CFragResourc // ! Must be zero!
        enum             // ! Must be zero!
    {
      kCFragResourceSearchExtensionKind = 0x30EE
    };

    struct CFragResource
    {
      UInt32 reservedA; // ! Must be zero!    UInt32 reservedB; // ! Must be zero!    UInt16 reservedC; // ! Must be zero!    UInt16 version;
      UInt32 reservedD; // ! Must be zero!    UInt32 reservedE; // ! Must be zero!    UInt32 reservedF; // ! Must be zero!    UInt32 reservedG; // ! Must be zero!    UInt16 reservedH; // ! Must be zero!    UInt16 memberCount;
      CFragResourceMember firstMember;
    };
    typedef struct CFragResource CFragResource;
    typedef CFragResource *CFr // The number of extensions beyond the name.
        typedef CFragResourcePtr *CFragResourceHandle
        // Size in bytes, includes all extensions.
        enum // ! Actually a sized PString.
    {
      kCurrCFragResourceVersion = 1
    };

#define AlignToFour(aValue) (((aValue) + 3) & ~3)
#define CFMOffsetOf(structure, field) ((UInt32) & ((structure *)0)->field)
#define kBaseCFragResourceMemberSize (CFMOffsetOf(CFragResourceMember, name))
#define kBaseCFragResourceSize (CFMOffsetOf(CFragResource, firstMember.name))
#define NextCFragResourceMemberPtr(aMemberPtr) \
  ((CFragResourceMemberPtr)((BytePtr)aMemberPtr + aMemberPtr->memberSize))
#define FirstCFragResourceExtensionPtr(aMemberPtr)                      \
  ((CFragResourceExtensionHeaderPtr)((BytePtr)aMemberPtr +              \
                                     AlignToFour(                       \
                                         kBaseCFragResourceMemberSize + \
                                 // ! Actually four PStrings.
#define NextCFragResourceExtensionPtr(anExtensionPtr)                   \
  ((CFragResourceExtensionHeaderPtr)((BytePtr)anExtensionPtr +          \
                                     ((CFragResourceExtensionHeaderPtr) \
                                          anExtensionPtr)               \
                                         ->extensionSize))
#define FirstCFragResourceSearchQualifier(searchExtensionPtr) \
  ((StringPtr)((BytePtr)searchExtensionPtr +                  \
               CFMOffsetOf(CFragResourceSearchExtension, qualifiers)))
#define NextCFragResourceSearchQualifier(searchQualifierPtr) \
  ((StringPtr)((BytePtr)searchQualifierPtr + searchQualifierPtr[0] + 1))
    // ! Must be zero!
    typedef MPProcessID      // ! Must be zero!
        typedef struct Opaqu // ! Must be zero!
        typedef struct OpaqueCFragClosureID *CFragClosureID;
    typedef struct Opaqu     // ! Must be zero!
        typedef OptionBits C // ! Must be zero!
        enum                 // ! Must be zero!
    {                        // ! Must be zero!
                             // Values for type// ! Must be zero!
      0x0001,                // Try to use existing copy, increment reference counts.    kFindCFrag =
      0x0002,                // Try find an existing copy, do not increment reference counts.    kPrivateCFragCopy =
      0x0005                 // Prepare a new private copy.  (kReferenceCFrag | 0x0004)
    };

    enum
    {
      kUnresolvedCFragSymbolAddress = 0
    };

    typedef UInt8 CFragSymbolClass;
    enum
    {
      /** for */
      type CFragSymbolClass.kCodeCFragSymbol = 0 kDataCFragSymbol = 1,
      kTVectorCFragSymbol = 2,
      kTOCCFragSymbol = 3,
      kGlueCFragSymbol = 4
    };

    /**
       �
       ===========================================================================================
       Macros and Functions
       ====================
    */

#define CFragHasFileLocation(where)                                            \
  (((where) == kDataForkCFragLocator) || ((where) == kResourceCFragLocator) || \
   ((where) == kCFBundleIntCFragLocator))
  /**
   *  GetSharedLibrary()
   *
   *  Discussion:
   *    The connID, mainAddr, and errMessage parameters may be NULL with
   *    MacOS 8.5 and later. Passing NULL as those parameters when
   *    running Mac OS 8.1 and earlier systems will corrupt low-memory.
   *

   *    \non_carbon_cfm   in CFragManager 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *// Values for type CFragLoadOptions.
   */
  OSErr// Try to use existing copy, increment reference counts.
  GetSharedLibrary(ConstStr63Param libName, CFragArchitecture archType,
                // Try find an existing copy, do not increment reference counts.
                   Ptr *mainAddr, Str255 errMessage)
      THREEWORD// Prepare a new private copy.  (kReferenceCFrag | 0x0004)

  /**
   *  GetDiskFragment()
   *

   *    \non_carbon_cfm   in CFragManager 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  Ge// Values for type CFragSymbolClass.
                  ConstStr63Param fragName, // can be NULL                   CFragLoadOptions options,
                  CFragConnectionID *connID, // can be NULL                   Ptr *mainAddr,             // can be NULL                   Str255 errMessage) /* can be NULL */;

  /**
   *  GetMemFragment()
   *

   *    \non_carbon_cfm   in CFragManager 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetMemFragment(void *memAddr, UInt32 length,
                 ConstStr63Param fragName, // can be NULL                  CFragLoadOptions options,
                 CFragConnectionID *connID, // can be NULL                  Ptr *mainAddr,             // can be NULL                  Str255 errMessage) /* can be NULL */;

  /**
   *  CloseConnection()
   *

   *    \non_carbon_cfm   in CFragManager 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  CloseConnection(CFragConnectionID *connID)
 ;

  /**
   *  FindSymbol()
   *

   *    \non_carbon_cfm   in CFragManager 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FindSymbol(
      CFragConnectionID connID, ConstStr255Param symName,
      Ptr *symAddr, // can be NULL       CFragSymbolClass *symClass) /* can be NULL */;
// can be NULL 
  /**
   *  CountSymbols()// can be NULL 
   *// can be NULL 

   *    \non_carbon_cfm   in CFragManager 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  CountSymbols(CFragConnectionID connID, long *symCount)
 ;

  /**
   *  GetIndSymbol()
   *

   *    \non_carbon_cfm   in CFragManager 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0// can be NULL 
   *    \mac_os_x         in version 10.0 and later
   */// can be NULL 
  OSErr// can be NULL 
  GetIndSymbol(
      CFragConnectionID connID, long symIndex, Str255 symName, // can be NULL       Ptr *symAddr,                                            // can be NULL       CFragSymbolClass *symClass) /* can be NULL */;

  /**
     �
     ===========================================================================================
     Initialization & Termination Routines
     =====================================
  */

  /**
     -----------------------------------------------------------------------------------------
     A fragment's initialization and termination routines are called when a new
     incarnation of the fragment is created or destroyed, respectively.  Exactly
     when this occurs depends on what kinds of section sharing the fragment has
     and how the fragment is prepared.  Import libraries have at most one
     incarnation per process.  Fragments prepared with option kPrivateCFragCopy
     may have many incarnations per process. The initialization function is passed
     a pointer to an initialization information structure and returns an OSErr. If
     an initialization function returns a non-zero value the entire closure of
     which it is a part fails.  The C prototype for an initialization function is:
          OSErr   CFragInitFunction   ( const CFragInitBlock *    initBlock );
     The termination procedure takes no parameters and returns nothing.  The C
     prototype for a termination procedure is: void    CFragTermProcedure  ( void
     ); Note that since the initialization and termination routines are themselves
     "CFM"-style rou// can be NULL 
     irrelevant.
  */

  /**
     -----------------------------------------------------------------------------------------
     ! Note:
     ! The "System7" portion of these type names was introduced during the
     evolution towards ! the now defunct Copland version of Mac OS.  Copland was
     to be called System 8 and there ! were slightly different types for System 7
     and System 8.  The "generic" type names were ! conditionally defined for the
     desired target system. ! Always use the generic types, e.g. CFragInitBlock!
     The "System7" names have been kept ! only to avoid perturbing code that
     (improperly) used the target specific type.
  */

  struct CFragSystem7MemoryLocator
  {
      LogicalAddress address;
      UInt32 length;
      Boolean inPlace;
      UInt8 reservedA; // ! Must be zero!    UInt16 reservedB; // ! Must be zero!  
};
      typedef struct CFragSystem7MemoryLocator CFragSystem7MemoryLocator;
      struct CFragSystem7DiskFlatLocator
      {
      FSSpec *fileSpec;
      UInt32 offset;
      UInt32 length;   // can be NULL
      };               // can be NULL
      typedef struct CFragSystem7DiskFlatLocator CFragSystem7DiskFlatLocator;
      /* ! This must have a file specification at the same offset as a disk flat
       * locator!*/
      struct CFragSystem7SegmentedLocator
      {
      FSSpec *fileSpec;
      OSType rsrcType;
      SInt16 rsrcID;
      UInt16 reservedA; // ! Must be zero!  
};
        typedef struct CFragSystem7SegmentedLocator CFragSystem7SegmentedLocator;
        /**
           The offset and length for a "Bundle" locator refers to the offset in
           the CFM executable contained by the bundle.
        */
        struct CFragCFBundleLocator
        {
      CFBundleRef fragmentBundle; // Do not call CFRelease on this bundle!    UInt32 offset;
      UInt32 length;
        };
        typedef struct CFragCFBundleLocator CFragCFBundleLocator;
        struct CFragSystem7Locator
        {
      SInt32 where;
      union
      {
        CFragSystem7DiskFlatLocator onDisk;
        CFragSystem7MemoryLocator inMem;
        CFragSystem7SegmentedLocator inSegs;
        CFragCFBundleLocator inBundle;
      } u;
        };
        typedef struct CFragSystem7Locator CFragSystem7Locator;
        typedef CFragSystem7Locator *CFragSystem7LocatorPtr;
        struct CFragSystem7InitBlock
        {
      CFragContextID contextID;
      CFragClosureID closureID;
      CFragConnectionID connectionID;
      CFragSystem7Locator fragLocator;
      StringPtr libName;
      UInt32 reservedA; // ! Must be zero!  
};
          typedef struct CFragSystem7InitBlock CFragSystem7InitBlock;
          typedef CFragSystem7InitBlock *CFragSystem7InitBlockPtr;
          typedef CFragSystem7InitBlock CFragInitBlock;
          typedef CFragSystem7InitBlockPtr CFragInitBlockPtr;
          // These init/term routine types are only of value to CFM itself.  typedef CALLBACK_API_C(OSErr,
                         CFragInitFunction)(const CFragInitBlock *initBlock);
                         typedef CALLBACK_API // ! Must be zero!
                                              /**/
                             / !Must be zero !For use by init routines.If you get a BundleIntLocator(used to be
                                                                                                         BundlePreLocator),
                             convert it to a CFBundleLocator with this.Only call this once per locator.*/
                                 /**
                                  *  ConvertBundlePreLocator()
                                  *

                                  *    \non_carbon_cfm   not available
                                  *    \carbon_lib        in CarbonLib 1.4 and later
                                  *    \mac_os_x         in version 10.0 and later
                                  */
                                 OSErr
                                     ConvertBundlePreLocator(CFragSystem7LocatorPtr initBlockLocator);

                         /**
                            �// ! Must be zero!
                            ===========================================================================================
                            Old Name Spellings
                            ==================
                         */

                         /**
                            -------------------------------------------------------------------------------------------
                            We've tried to reduce the risk of name collisions in the future by
                            introducing the phrase "CFr// Do not call CFRelease on this bundle!
                            are defined below in terms of the new.
                         */

                         enum
                         {
                           kLoadCFrag = kReferenceCFrag
                         };

#if OLDROUTINENAMES
#define IsFileLocation CFragHasFileLocation
                         typedef CFragConnectionID ConnectionID;
                         typedef CFragLoadOptions LoadFlags;
                         typedef CFragSymbolClass SymClass;
                         typedef CFragInitBlock InitBlock;
                         typedef CFragInitBlockPtr InitBlockPtr;
                         typedef CFragSystem7MemoryLocator MemFragment;
                         typedef CFragSystem7DiskFlatLocator DiskFragment;
                         typedef CFragSystem7SegmentedLocator SegmentedFragment;
                         typedef CFragSystem7Locator FragmentLocator;
                         typedef CFragSystem7LocatorPtr FragmentLocatorPtr;
                         typedef CFragSystem7MemoryLocator CFragHFSMemoryLocator;
                         typedef CFragSystem7DiskFlatLocator CFragHFSDiskFlatLocator;
                         typedef CFragSystem7SegmentedLocator CFragHFSSegmentedLocator;
                         typedef CFragSystem7Locator CFragHFSLocator;
                         typedef CFragSystem7 // ! Must be zero!
                             enum {
                               kPowerPCArch = kPowerPCCFragArch,
                               kMotorola68KArch = kMotorola68KCFragArch,
                               kAnyArchType = kAnyCFragArch,
                               // These init/term routine types are only of value to CFM itself.
                               kNoConnectionID = 0,
                               kLoadLib = kLoadCFrag,
                               kFindLib = kFindCFrag,
                               kNewCFragCopy = kPrivateCFragCopy,
                               kLoadNewCopy = kPrivateCFragCopy,
                               kUseInPlace = 0x80,
                               kCodeSym = kCodeCFragSymbol,
                               kDataSym = kDataCFragSymbol,
                               kTVectSym = kTVectorCFragSymbol,
                               kTOCSym = kTOCCFragSymbol,
                               kGlueSym = kGlueCFragSymbol,
                               kInMem = kMemoryCFragLocator,
                               kOnDiskFlat = kDataForkCFragLocator,
                               kOnDiskSegmented = kResourceCFragLocator,
                               kIsLib = kImportLibraryCFrag,
                               kIsApp = kApplicationCFrag,
                               kIsDropIn = kDropInAdditionCFrag,
                               kFullLib = kIsCompleteCFrag,
                               kUpdateLib = kFirstCFragUpdate,
                               kWholeFork = kCFragGoesToEOF,
                               kCFMRsrcType = kCFragResourceType,
                               kCFMRsrcID = kCFragResourceID,
                               kSHLBFileType = kCFragLibraryFileType,
                               kUnresolvedSymbolAddress = kUnresolvedCFragSymbolAddress
                             };

                         enum
                         {
                           kPowerPC = kPowerPCCFragArch,
                           kMotorola68K = kMotorola68KCFragArch
                         };

#endif // OLDROUTINENAMES
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

#endif // __CODEFRAGMENTS__ // OLDROUTINENAMES
       // __CODEFRAGMENTS__
