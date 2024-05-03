/**
     \file       Aliases.h

    \brief   Alias Manager Interfaces.

    \introduced_in  Mac OS 8.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1989-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Managers

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __ALIASES__
#define __ALIASES__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FILES__
#include <Files.h>
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
    rAliasType =
        FOUR_CHAR_CODE('alis') /** Aliases are stored as resources of this type */
  };

  enum
  {
    /** define alias resolution action rules mask */
    kARMMountVol = 0x00000001,      /** mount the volume automatically */
    kARMNoUI = 0x00000002,          /** no user interface allowed during resolution */
    kARMMultVols = 0x00000008,      /** search on multiple volumes */
    kARMSearch = 0x00000100,        /** search quickly */
    kARMSearchMore = 0x00000200,    /** search further */
    kARMSearchRelFirst = 0x00000400 /** search target on a relative path first */
  };

  enum
  {
    /** define alias record information types */
    asiZoneName = -3,   /** get zone name */
    asiServerName = -2, /** get server name */
    asiVolumeName = -1, /** get volume name */
    asiAliasName = 0,   /** get aliased file/folder/volume name */
    asiParentName = 1   /** get parent folder name */
  };

  /** ResolveAliasFileWithMountFlags options */
  enum
  {
    kResolveAliasFileNoUI =
        0x00000001 /** no user interaction during resolution */
  };

  /** define the alias record that will be the blackbox for the caller */
  struct AliasRecord
  {
    OSType userType;          /** appl stored type like creator type */
    unsigned short aliasSize; /** alias record size in bytes, for appl usage */
  };
  typedef struct AliasRecord AliasRecord;
  typedef AliasRecord *AliasPtr;
  typedef AliasPtr *AliasHandle;
  /** alias record information type */
  typedef short AliasInfoType;
  /**
   *  NewAlias()
   *
   *  Summary:
   *    create a new alias between fromFile and target, returns alias
   *    record handle
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  NewAlias(const FSSpec *fromFile, /** can be NULL */
           const FSSpec *target, AliasHandle *alias);

  /**
   *  NewAliasMinimal()
   *
   *  Summary:
   *    create a minimal new alias for a target and return alias record
   *    handle
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  NewAliasMinimal(const FSSpec *target, AliasHandle *alias);

  /**
   *  NewAliasMinimalFromFullPath()
   *
   *  Summary:
   *    create a minimal new alias from a target fullpath (optional zone
   *    and server name) and return alias record handle
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  NewAliasMinimalFromFullPath(short fullPathLength, const void *fullPath,
                              ConstStr32Param zoneName,
                              ConstStr31Param serverName, AliasHandle *alias);

  /**
   *  ResolveAlias()
   *
   *  Summary:
   *    given an alias handle and fromFile, resolve the alias, update the
   *    alias record and return aliased filename and wasChanged flag.
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ResolveAlias(const FSSpec *fromFile, /** can be NULL */
               AliasHandle alias, FSSpec *target, Boolean *wasChanged);

  /**
  \brief Get information from an AliasRecord

  <pre>You use the GetAliasInfo function to get information from an AliasRecord
without actually resolving the record.
alias is a handle to the AliasRecord to be read.
index specifies the kind of information to be retrieved. If index is a
positive integer, GetAliasInfo retrieves the parent directory that
has the same hierarchical level above the target as the index
parameter (for example, an index value of 2 returns the name of the
parent directory of the target's parent directory). You can therefore
assemble the names of the target and all of its parent directories by
making repeated calls to GetAliasInfo with incrementing index
values, starting with a value of 0. When index is greater than the
number of levels between the target and the root, GetAliasInfo
returns an empty string. You can also set the index parameter to one
of the following five values.
Constant Description
asiZoneName If the record represents a target on an AppleShare
volume, retrieve the server's zone name. Otherwise,
return an empty string.
asiServerName If the record represents a target on an AppleShare
volume, retrieve the server name. Otherwise, return
an empty string.
asiVolumeName Return the name of the volume on which the target
resides.
asiAliasName Return the name of the target.
asiParentName Return the name of the parent directory of the target
of the record. If the target is a volume, return the
volume name.
theString receives the requested information.
Returns: an operating system Error Code .
noErr(0)No error
nsvErr (-35)The volume is not mounted
fnfErr(-43)Target not found, but volume and parent directory
found; if aliasCount is 1, target parameter contains a
valid FSSpec record
paramErr (-50)Alias, theString, or both are NIL, the index is less than
asiZoneName, or the AliasRecord is corrupt
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  GetAliasInfo(AliasHandle alias, AliasInfoType index, Str63 theString);

  /**
   *  IsAliasFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  IsAliasFile(const FSSpec *fileFSSpec, Boolean *aliasFileFlag,
              Boolean *folderFlag);

  /**
   *  ResolveAliasWithMountFlags()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ResolveAliasWithMountFlags(const FSSpec *fromFile, /** can be NULL */
                             AliasHandle alias, FSSpec *target,
                             Boolean *wasChanged, unsigned long mountFlags);

  /**
   *  ResolveAliasFile()
   *
   *  Summary:
   *    Given a file spec, return target file spec if input file spec is
   *    an alias. It resolves the entire alias chain or one step of the
   *    chain.  It returns info about whether the target is a folder or
   *    file; and whether the input file spec was an alias or not.
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ResolveAliasFile(FSSpec *theSpec, Boolean resolveAliasChains,
                   Boolean *targetIsFolder, Boolean *wasAliased);

  /**
   *  ResolveAliasFileWithMountFlags()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ResolveAliasFileWithMountFlags(FSSpec *theSpec, Boolean resolveAliasChains,
                                 Boolean *targetIsFolder, Boolean *wasAliased,
                                 unsigned long mountFlags);

  /**
   *  FollowFinderAlias()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FollowFinderAlias(const FSSpec *fromFile, /** can be NULL */
                    AliasHandle alias, Boolean logon, FSSpec *target,
                    Boolean *wasChanged);

  /**
     Low Level Routines
  */
  /**
   *  UpdateAlias()
   *
   *  Summary:
   *    given a fromFile-target pair and an alias handle, update the
   *    alias record pointed to by alias handle to represent target as
   *    the new alias.
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  UpdateAlias(const FSSpec *fromFile, /** can be NULL */
              const FSSpec *target, AliasHandle alias, Boolean *wasChanged);

  typedef CALLBACK_API(Boolean, AliasFilterProcPtr)(CInfoPBPtr cpbPtr,
                                                    Boolean *quitFlag,
                                                    Ptr myDataPtr);
  typedef STACK_UPP_TYPE(AliasFilterProcPtr) AliasFilterUPP;
  /**
   *  NewAliasFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AliasFilterUPP
  NewAliasFilterUPP(AliasFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppAliasFilterProcInfo = 0x00000FD0
  }; /** pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline AliasFilterUPP NewAliasFilterUPP(AliasFilterProcPtr userRoutine)
  {
    return (AliasFilterUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppAliasFilterProcInfo, GetCurrentArchitecture());
  }
#else
#define NewAliasFilterUPP(userRoutine)                                     \
  (AliasFilterUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppAliasFilterProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeAliasFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeAliasFilterUPP(AliasFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeAliasFilterUPP(AliasFilterUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeAliasFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeAliasFilterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeAliasFilterUPP(CInfoPBPtr cpbPtr, Boolean *quitFlag, Ptr myDataPtr,
                       AliasFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeAliasFilterUPP(CInfoPBPtr cpbPtr, Boolean *quitFlag,
                                      Ptr myDataPtr, AliasFilterUPP userUPP)
  {
    return (Boolean)CALL_THREE_PARAMETER_UPP(userUPP, uppAliasFilterProcInfo,
                                             cpbPtr, quitFlag, myDataPtr);
  }
#else
#define InvokeAliasFilterUPP(cpbPtr, quitFlag, myDataPtr, userUPP)      \
  (Boolean) CALL_THREE_PARAMETER_UPP((userUPP), uppAliasFilterProcInfo, \
                                     (cpbPtr), (quitFlag), (myDataPtr))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewAliasFilterProc(userRoutine) NewAliasFilterUPP(userRoutine)
#define CallAliasFilterProc(userRoutine, cpbPtr, quitFlag, myDataPtr) \
  InvokeAliasFilterUPP(cpbPtr, quitFlag, myDataPtr, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  /**
   *  MatchAlias()
   *
   *  Summary:
   *    Given an alias handle and fromFile, match the alias and return
   *    aliased filename(s) and needsUpdate flag
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  MatchAlias(const FSSpec *fromFile, /** can be NULL */
             unsigned long rulesMask, AliasHandle alias, short *aliasCount,
             FSSpecArrayPtr aliasList, Boolean *needsUpdate,
             AliasFilterUPP aliasFilter, void *yourDataPtr);

  /**
   *  ResolveAliasFileWithMountFlagsNoUI()
   *
   *  Summary:
   *    variation on ResolveAliasFile that does not prompt user with a
   *    dialog
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ResolveAliasFileWithMountFlagsNoUI(FSSpec *theSpec, Boolean resolveAliasChains,
                                     Boolean *targetIsFolder, Boolean *wasAliased,
                                     unsigned long mountFlags);

  /**
   *  MatchAliasNoUI()
   *
   *  Summary:
   *    variation on MatchAlias that does not prompt user with a dialog
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  MatchAliasNoUI(const FSSpec *fromFile, /** can be NULL */
                 unsigned long rulesMask, AliasHandle alias, short *aliasCount,
                 FSSpecArrayPtr aliasList, Boolean *needsUpdate,
                 AliasFilterUPP aliasFilter, void *yourDataPtr);

  /**
   *  FSNewAlias()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSNewAlias(const FSRef *fromFile, /** can be NULL */
             const FSRef *target, AliasHandle *inAlias);

  /**
   *  FSNewAliasMinimal()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSNewAliasMinimal(const FSRef *target, AliasHandle *inAlias);

  /**
   *  FSIsAliasFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSIsAliasFile(const FSRef *fileRef, Boolean *aliasFileFlag, Boolean *folderFlag);

  /**
   *  FSResolveAliasWithMountFlags()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSResolveAliasWithMountFlags(const FSRef *fromFile, /** can be NULL */
                               AliasHandle inAlias, FSRef *target,
                               Boolean *wasChanged, unsigned long mountFlags);

  /**
   *  FSResolveAlias()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSResolveAlias(const FSRef *fromFile, /** can be NULL */
                 AliasHandle alias, FSRef *target, Boolean *wasChanged);

  /**
   *  FSResolveAliasFileWithMountFlags()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSResolveAliasFileWithMountFlags(FSRef *theRef, Boolean resolveAliasChains,
                                   Boolean *targetIsFolder, Boolean *wasAliased,
                                   unsigned long mountFlags);

  /**
   *  FSResolveAliasFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSResolveAliasFile(FSRef *theRef, Boolean resolveAliasChains,
                     Boolean *targetIsFolder, Boolean *wasAliased);

  /**
   *  FSFollowFinderAlias()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSFollowFinderAlias(FSRef *fromFile, /** can be NULL */
                      AliasHandle alias, Boolean logon, FSRef *target,
                      Boolean *wasChanged);

  /**
   *  FSUpdateAlias()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSUpdateAlias(const FSRef *fromFile, /** can be NULL */
                const FSRef *target, AliasHandle alias, Boolean *wasChanged);

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

#endif /** __ALIASES__ */
* /