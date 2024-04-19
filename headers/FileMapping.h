/**
     \file       FileMapping.h

    \brief   File Mapping APIs

    \introduced_in  1.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1998-2001 by Apple Computer, Inc., all rights reserved.

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FILEMAPPING__
#define __FILEMAPPING__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __PROCESSES__
#include <Processes.h>
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

/**
 *  BackingFileID
 *
 *  Discussion:
 *    A BackingFileID is used to access a mapped file fork.
 */
typedef struct OpaqueBackingFileID *BackingFileID;

/**
 *  MappingPrivileges
 *
 *  Discussion:
 *    A set of flags that describe what operations can be performed on
 *    a mapped file fork.
 */
typedef UInt32 MappingPrivileges;
enum {
  kInvalidMappedPrivileges = 0x00000000,

  /**
   * Allow the file fork to be mapped such that the memory can be read
   * (this is required).
   */
  kCanReadMappedFile = 0x00000001, /** mapped file fork has read access */

  /**
   * Allow the file fork to be mapped such that the memory can be
   * written. If not set, then the memory can be mapped read-only.
   */
  kCanWriteMappedFile = 0x00000002, /** mapped file fork has write access */

  /**
   * The mapped file fork and its mapped file views are not tracked by
   * process ID.
   */
  kNoProcessMappedFile =
      (unsigned long)0x80000000, /** mapped file fork and views are not tracked
                                    by process */
  kValidMappingPrivilegesMask =
      (unsigned long)(kCanReadMappedFile + kCanWriteMappedFile +
                      kNoProcessMappedFile)
};

/**
 *  MappedFileAttributes
 *
 *  Discussion:
 *    A set of flags returned by GetMappedFileInformation that describe
 *    the attributes of a mapped file fork.
 */
typedef UInt32 MappedFileAttributes;
enum {

  /**
   * Set when the mapped file fork is a scratch file created with
   * OpenMappedScratchFile.
   */
  kIsMappedScratchFile = 0x00000001 /** mapped file fork is scratch file */
};

/**
 */
enum {

  /**
   * The version number of the MappedFileInformation struct.
   */
  kMappedFileInformationVersion1 = 1 /** version 1 of MappedFileInformation */
};

/**
 *  MappedFileInformation
 *
 *  Discussion:
 *    Receives the information supplied by GetMappedFileInformation.
 *    The current version of this struct is
 *    kMappedFileInformationVersion1.
 */
struct MappedFileInformation {

  /**
   * The ProcessSerialNumber of the process that owns this mapped file
   * fork.
   */
  ProcessSerialNumber owningProcess; /** owning process */

  /**
   * A pointer to a FSRef where the FSRef of the mapped file fork is
   * returned, or NULL if the FSRef is not needed.
   */
  FSRef *ref; /** pointer to FSRef or NULL */

  /**
   * A pointer to a HFSUniStr255 where the fork name of the mapped file
   * fork is returned, or NULL if the fork name is not needed.
   */
  HFSUniStr255 *forkName; /** pointer to HFSUniStr255 or NULL */

  /**
   * The MappingPrivileges of the mapped file fork.
   */
  MappingPrivileges privileges; /** mapping privileges */

  /**
   * The size, in bytes, of the mapped file fork.
   */
  UInt64 currentSize; /** size in bytes */

  /**
   * The MappedFileAttributes of the mapped file fork.
   */
  MappedFileAttributes attributes; /** attributes */
};
typedef struct MappedFileInformation MappedFileInformation;

/**
 *  FileViewAccess
 *
 *  Discussion:
 *    Values of type FileViewAccess represent allowable access to the
 *    memory in a mapped file view.
 */
typedef UInt32 FileViewAccess;
enum {

  /**
   * Memory in mapped file view can be read from.
   */
  kFileViewAccessReadBit = 0, /** Reads allowed */

  /**
   * Memory in mapped file view can be written to.
   */
  kFileViewAccessWriteBit = 1, /** Writes allowed */

  /**
   * Instruction execution from mapped file view is permitted.
   */
  kFileViewAccessExecuteBit = 2, /** Instruction execution permitted */
  kFileViewAccessReadMask = 1L << kFileViewAccessReadBit, /** Reads allowed */
  kFileViewAccessWriteMask = 1L
                             << kFileViewAccessWriteBit, /** Writes allowed */
  kFileViewAccessExecuteMask =
      1L << kFileViewAccessExecuteBit, /** Instruction execution permitted */
  kFileViewAccessExcluded = 0,         /** All access is prohibited */
  kFileViewAccessReadOnly =
      kFileViewAccessReadMask | kFileViewAccessExecuteMask,
  kFileViewAccessReadWrite = kFileViewAccessReadMask |
                             kFileViewAccessWriteMask |
                             kFileViewAccessExecuteMask
};

/**
 *  FileViewOptions
 *
 *  Discussion:
 *    Values of type FileViewOptions specify desired characteristics of
 *    the mapped file view being created. At this time, only
 *    kNilOptions is supported.
 */

typedef OptionBits FileViewOptions;

/**
 */
enum {

  /**
   * Pass kMapEntireFork to MapFileView as the backingLength parameter
   * to map from backingBase to logical end-of-file.
   */
  kMapEntireFork = -1 /** map from backingBase to logical end-of-file */
};

/**
 *  FileViewID
 *
 *  Discussion:
 *    A FileViewID is used to access a mapped file view.
 */
typedef struct OpaqueFileViewID *FileViewID;

/**
 */
enum {

  /**
   * The version number of the FileViewInformation struct.
   */
  kFileViewInformationVersion1 = 1 /** version 1 of MappedFileInformation */
};

/**
 *  FileViewInformation
 *
 *  Discussion:
 *    Receives the information supplied by GetFileViewInformation. The
 *    current version of this struct is kFileViewInformationVersion1.
 */
struct FileViewInformation {

  /**
   * The ProcessSerialNumber of the process that owns this mapped file
   * view.
   */
  ProcessSerialNumber owningProcess; /** owning process */

  /**
   * The starting address of mapped file view.
   */
  LogicalAddress viewBase; /** starting address of mapped file view */

  /**
   * The length of the mapped file view.
   */
  ByteCount viewLength; /** length of the mapped file view */

  /**
   * The BackingFileID of the mapped file fork.
   */
  BackingFileID backingFile; /** the mapped file fork */

  /**
   * The offset into mapped file fork.
   */
  UInt64 backingBase; /** offset into mapped file fork */

  /**
   * The FileViewAccess.
   */
  FileViewAccess access; /** the FileViewAccess */

  /**
   * The size of the guard ranges.
   */
  ByteCount guardLength; /** size of the guard ranges */

  /**
   * The FileViewOptions.
   */
  FileViewOptions options; /** the FileViewOptions */
};
typedef struct FileViewInformation FileViewInformation;
#if CALL_NOT_IN_CARBON
/**
 *  OpenMappedFile()
 *
 *  Summary:
 *    Opens a file fork with the privileges requested for use as
 *    backing storage.
 *
 *  Discussion:
 *    The OpenMappedFile function opens the fork specified by the
 *    forkNameLength and forkName parameters of the file specified by
 *    the ref parameter and returns a BackingFileID in the backingFile
 *    parameter. You can pass the BackingFileID to other routines which
 *    accept a BackingFileID as an input parameter. The privileges
 *    parameter specifies what operations you want to perform on the
 *    mapped file fork. Programs can request either kCanReadMappedFile
 *    privileges, or both kCanReadMappedFile and kCanWriteMappedFile
 *    privileges. To disable Process Manager tracking of the mapped
 *    file fork and its mapped file views, you may also request
 *    kNoProcessMappedFile privileges.
 *
 *  Parameters:
 *
 *    ref:
 *      The file to map.
 *
 *    forkNameLength:
 *      The fork name length in Unicode characters.
 *
 *    forkName:
 *      The fork name in Unicode (NULL = data fork).
 *
 *    privileges:
 *      The requested MappingPrivileges.
 *
 *    backing\file
 *      Receives a BackingFileID which you can use to access the mapped
 *      file fork.
 *
 *  Result:
 *    An operating system result code: noErr, paramErr,
 *    vmMappingPrivilegesErr, or various File Manager and Memory
 *    Manager errors.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
OpenMappedFile(const FSRef *ref, UniCharCount forkNameLength,
               const UniChar *forkName, /** can be NULL */
               MappingPrivileges privileges, BackingFileID *backingFile)
    TWOWORDINLINE(0x7000, 0xAA81);

/**
 *  FSpOpenMappedFile()
 *
 *  Summary:
 *    Opens a file fork with the privileges requested for use as
 *    backing storage.
 *
 *  Discussion:
 *    The FSpOpenMappedFile function opens the fork specified by the
 *    mapResFork parameter of the file specified by the spec parameter
 *    and returns a BackingFileID in the backingFile parameter. You can
 *    pass the BackingFileID to other routines which accept a
 *    BackingFileID as an input parameter. The privileges parameter
 *    specifies what operations you want to perform on the mapped file
 *    fork. Programs can request either kCanReadMappedFile privileges,
 *    or both kCanReadMappedFile and kCanWriteMappedFile privileges. To
 *    disable Process Manager tracking of the mapped file fork and its
 *    mapped file views, you may also request kNoProcessMappedFile
 *    privileges.
 *
 *  Parameters:
 *
 *    spec:
 *      The file to map.
 *
 *    mapResFork:
 *      Fork to map: false = data fork; true = resource fork.
 *
 *    privileges:
 *      The requested MappingPrivileges.
 *
 *    backing\file
 *      Receives a BackingFileID which you can use to access the mapped
 *      file fork.
 *
 *  Result:
 *    An operating system result code: noErr, paramErr,
 *    vmMappingPrivilegesErr, or various File Manager and Memory
 *    Manager errors.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
FSpOpenMappedFile(const FSSpec *spec, Boolean mapResFork,
                  MappingPrivileges privileges, BackingFileID *backingFile)
    TWOWORDINLINE(0x7001, 0xAA81);

/**
 *  OpenMappedScratchFile()
 *
 *  Summary:
 *    Creates and opens a scratch file with the privileges requested
 *    for use as backing storage.
 *
 *  Discussion:
 *    The OpenMappedScratchFile function creates a file with the size
 *    specified by the fileSize parameter on the volume specified by
 *    the volume parameter. If kFSInvalidVolumeRefNum is passed as the
 *    volume parameter, the system code will choose the location of the
 *    file. OpenMappedScratchFile then opens the file and returns a
 *    BackingFileID in the backingFile parameter. You can pass the
 *    BackingFileID to other routines which accept a BackingFileID as
 *    an input parameter. The privileges parameter specifies what
 *    operations you want to perform on the mapped file fork. Programs
 *    can request either kCanReadMappedFile privileges, or both
 *    kCanReadMappedFile and kCanWriteMappedFile privileges. To disable
 *    Process Manager tracking of the mapped file fork and its mapped
 *    file views, you may also request kNoProcessMappedFile privileges.
 *    The data for a scratch file is only valid in an open mapped file
 *    view. When a mapped file view is first created for a scratch file
 *    with MapFileView, data on disk is not paged into memory. When
 *    that mapped file view is unmapped with UnmapFileView, changes are
 *    not flushed from memory to disk.
 *
 *  Parameters:
 *
 *    volume:
 *      The volume where scratch file should be created or
 *      kFSInvalidVolumeRefNum to let the system choose the volume.
 *
 *    fileSize:
 *      The size of the scratch file.
 *
 *    privileges:
 *      The requested MappingPrivileges.
 *
 *    backing\file
 *      Receives a BackingFileID which you can use to access the mapped
 *      file fork.
 *
 *  Result:
 *    An operating system result code: noErr, paramErr,
 *    vmMappingPrivilegesErr, or various File Manager and Memory
 *    Manager errors.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
OpenMappedScratchFile(FSVolumeRefNum volume, ByteCount fileSize,
                      MappingPrivileges privileges, BackingFileID *backingFile)
    TWOWORDINLINE(0x7002, 0xAA81);

/**
 *  CloseMappedFile()
 *
 *  Summary:
 *    Closes a mapped file fork.
 *
 *  Discussion:
 *    The CloseMappedFile function closes the mapped file fork
 *    specified by the backingFile parameter. All mapped file views
 *    using the BackingFileID must be closed before closing the mapped
 *    file fork. If the BackingFileID is for a scratch file created
 *    with OpenMappedScratchFile, the scratch file is deleted by
 *    CloseMappedFile after it is closed.
 *
 *  Parameters:
 *
 *    backing\file
 *      The mapped file fork to close.
 *
 *  Result:
 *    An operating system result code: noErr,
 *    vmInvalidBackingFileIDErr, vmInvalidOwningProcessErr,
 *    vmBusyBackingFileErr, or various File Manager errors.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
CloseMappedFile(BackingFileID backingFile) TWOWORDINLINE(0x7003, 0xAA81);

/**
 *  GetMappedFileInformation()
 *
 *  Summary:
 *    Returns information about a mapped file fork.
 *
 *  Discussion:
 *    The GetMappedFileInformation function returns information about
 *    the mapped file fork specified by the backingFile parameter. The
 *    struct version of the mappedFileInfo parameter is passed in the
 *    version parameter. The mapped file fork information is returned
 *    in the mappedFileInfo parameter.
 *
 *  Parameters:
 *
 *    backing\file
 *      The mapped file fork.
 *
 *    version:
 *      The version of the MappedFileInformation struct passed.
 *
 *    mappedFileInfo:
 *      A pointer to the MappedFileInformation struct where the
 *      information about a mapped file fork is returned.
 *
 *  Result:
 *    An operating system result code: noErr, paramErr,
 *    vmInvalidBackingFileIDErr, or various File Manager errors.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
GetMappedFileInformation(BackingFileID backingFile, PBVersion version,
                         MappedFileInformation *mappedFileInfo)
    TWOWORDINLINE(0x7004, 0xAA81);

/**
 *  GetNextMappedFile()
 *
 *  Summary:
 *    Gets a list of mapped file forks.
 *
 *  Discussion:
 *    The GetNextMappedFile function returns the BackingFileID of the
 *    mapped file fork next in the list of mapped file forks. You can
 *    enumerate through the list of mapped file forks by passing
 *    kInvalidID as the backingFile parameter and then repetitively
 *    calling GetNextMappedFile with the last BackingFileID returned
 *    until the result code vmNoMoreBackingFilesErr is returned.
 *
 *  Parameters:
 *
 *    backing\file
 *      Input: The last BackingFileID returned by GetNextMappedFile, or
 *      kInvalidID to get the first mapped file fork. Output: If noErr,
 *      receives the BackingFileID of the next mapped file fork.
 *
 *  Result:
 *    An operating system result code: noErr,
 *    vmInvalidBackingFileIDErr, or vmNoMoreBackingFilesErr.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
GetNextMappedFile(BackingFileID *backingFile) TWOWORDINLINE(0x7005, 0xAA81);

/**
 *  SetMappedFileSize()
 *
 *  Summary:
 *    Changes the size (logical end-of-file) of a mapped file fork.
 *
 *  Discussion:
 *    The SetMappedFileSize function sets the logical end-of-file of
 *    the mapped file fork specified by backingFile. The new logical
 *    end-of-file is specified by the positionMode and positionOffset
 *    parameters.
 *
 *  Parameters:
 *
 *    backing\file
 *      The mapped file fork to change the size of.
 *
 *    positionMode:
 *      The base location for the new size: fsAtMark, fsFromStart,
 *      fsFromLEOF, or fsFromMark.
 *
 *    positionOffset:
 *      Pointer to a SInt64 which contains the offset of the size from
 *      the base.
 *
 *  Result:
 *    An operating system result code: noErr, paramErr, or various File
 *    Manager errors.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
SetMappedFileSize(BackingFileID backingFile, UInt16 positionMode,
                  const SInt64 *positionOffset) TWOWORDINLINE(0x7006, 0xAA81);

/**
 *  GetFileViewAccessOptions()
 *
 *  Summary:
 *    Returns the valid FileViewAccess and FileViewOptions bits.
 *
 *  Discussion:
 *    The GetFileViewAccessOptions function returns the valid
 *    FileViewAccess and FileViewOptions bits. Programs can use it to
 *    determine what FileViewAccess and FileViewOptions are available.
 *
 *  Parameters:
 *
 *    access:
 *      Receives the valid memory access flags.
 *
 *    options:
 *      Receives the valid view options.
 *
 *  Result:
 *    An operating system result code: noErr, or paramErr.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
GetFileViewAccessOptions(FileViewAccess *access, FileViewOptions *options)
    TWOWORDINLINE(0x7007, 0xAA81);

/**
 *  MapFileView()
 *
 *  Summary:
 *    Creates a mapped file view into a mapped file fork.
 *
 *  Discussion:
 *    The MapFileView function creates a mapped file view into the
 *    mapped file fork specified by the backingFile parameter.
 *    MapFileView returns a FileViewID in the theView parameter. You
 *    can pass the FileViewID to other routines which accept a
 *    FileViewID as an input parameter. The backingBase and
 *    backingLength parameters specify what part of the mapped file
 *    fork will be mapped to memory. The access parameter specifies the
 *    allowable access to the memory in a mapped file view. The
 *    guardLength parameter specifies the size, in bytes, of the
 *    excluded logical address ranges to place adjacent to each end of
 *    the mapped file view. The options parameter specifies the desired
 *    characteristics of the mapped file view. The viewBase parameter,
 *    as an optional input, specifies the requested viewBase. The
 *    backingBase parameter must be a whole multiple of the logical
 *    page size. If kMapEntireFork is passed as backingLength, accesses
 *    past the mapped file fork's logical end-of-file will not cause
 *    exceptions, but will have undefined behavior. Only accesses up to
 *    viewLength should be considered valid. The starting address of
 *    the mapped file view is returned in the viewBase parameter. The
 *    length of the mapped file view is returned in the viewLength
 *    parameter.
 *
 *  Parameters:
 *
 *    backing\file
 *      The mapped file fork to create a mapped file view from.
 *
 *    backingBase:
 *      Pointer to the offset into mapped file fork. Passing a NULL
 *      pointer is the same as passing an offset of zero.
 *
 *    backingLength:
 *      The number of bytes to map, or kMapEntireFork to map from
 *      backingBase to the mapped file fork's logical end-of-file.
 *
 *    access:
 *      The FileViewAccess.
 *
 *    guardLength:
 *      The size, in bytes, of the excluded logical address ranges to
 *      place adjacent to each end of the mapped file view.
 *
 *    options:
 *      The desired characteristics of the mapped file view.
 *
 *    viewBase:
 *      Input: The requested viewBase. Output: Receives the starting
 *      address of mapped file view.
 *
 *    viewLength:
 *      Receives the mapped file view length.
 *
 *    theView:
 *      Receives a FileViewID which you can use to access the mapped
 *      file view.
 *
 *  Result:
 *    An operating system result code: noErr, paramErr,
 *    vmInvalidBackingFileIDErr, vmInvalidOwningProcessErr,
 *    vmFileViewAccessErr, or various File Manager and Memory Manager
 *    errors.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
MapFileView(BackingFileID backingFile,
            const UInt64 *backingBase, /** can be NULL */
            ByteCount backingLength, FileViewAccess access,
            ByteCount guardLength, FileViewOptions options,
            LogicalAddress *viewBase, ByteCount *viewLength,
            FileViewID *theView) TWOWORDINLINE(0x7008, 0xAA81);

/**
 *  UnmapFileView()
 *
 *  Summary:
 *    Unmaps a mapped file view.
 *
 *  Discussion:
 *    The UnmapFileView function unmaps a mapped file view specified by
 *    the theView parameter from memory. All modified memory is flushed
 *    to the mapped file fork before the mapped file view is unmapped
 *    unless the mapped file view is to a scratch file.
 *
 *  Parameters:
 *
 *    theView:
 *      The mapped file view to unmap.
 *
 *  Result:
 *    An operating system result code: noErr, vmInvalidFileViewIDErr,
 *    vmInvalidOwningProcessErr, or various File Manager and Memory
 *    Manager errors.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
UnmapFileView(FileViewID theView) TWOWORDINLINE(0x7009, 0xAA81);

/**
 *  GetFileViewInformation()
 *
 *  Summary:
 *    Returns information about a mapped file view.
 *
 *  Discussion:
 *    The GetFileViewInformation function returns information about the
 *    mapped file view specified by the theView parameter. The struct
 *    version of the fileViewInfo parameter is passed in the version
 *    parameter. The mapped file view information is returned in the
 *    fileViewInfo parameter.
 *
 *  Parameters:
 *
 *    theView:
 *      The mapped file view.
 *
 *    version:
 *      The version of the FileViewInformation struct passed.
 *
 *    fileViewInfo:
 *      A pointer to the FileViewInformation struct where the
 *      information about a mapped file view is returned.
 *
 *  Result:
 *    An operating system result code: noErr, paramErr, or
 *    vmInvalidFileViewIDErr.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
GetFileViewInformation(FileViewID theView, PBVersion version,
                       FileViewInformation *fileViewInfo)
    TWOWORDINLINE(0x700A, 0xAA81);

/**
 *  GetFileViewFromAddress()
 *
 *  Summary:
 *    Returns the FileViewID for a given address.
 *
 *  Discussion:
 *    The GetFileViewFromAddress function returns the FileViewID for
 *    address specified in the address parameter.
 *
 *  Parameters:
 *
 *    address:
 *      The memory address.
 *
 *    theView:
 *      Receives a FileViewID for the given memory address.
 *
 *  Result:
 *    An operating system result code: noErr, paramErr, or
 *    vmAddressNotInFileViewErr.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
GetFileViewFromAddress(LogicalAddress address, FileViewID *theView)
    TWOWORDINLINE(0x700B, 0xAA81);

/**
 *  GetNextFileView()
 *
 *  Summary:
 *    Gets a list of mapped file views.
 *
 *  Discussion:
 *    The GetNextView function returns the FileViewID of the mapped
 *    file view next in the list of mapped file views. You can
 *    enumerate through the list of mapped file views by passing
 *    kInvalidID as the theView parameter and then repetitively calling
 *    GetNextView with the last FileViewID returned until the result
 *    code vmNoMoreFileViewsErr is returned.
 *
 *  Parameters:
 *
 *    theView:
 *      Input: The last FileViewID returned by GetNextView, or
 *      kInvalidID to get the first mapped file view. Output: If noErr,
 *      receives the FileViewID of the next mapped file view.
 *
 *  Result:
 *    An operating system result code: noErr, paramErr,
 *    vmInvalidFileViewIDErr, or vmNoMoreFileViewsErr.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
GetNextFileView(FileViewID *theView) TWOWORDINLINE(0x700C, 0xAA81);

/**
 *  SetFileViewAccess()
 *
 *  Summary:
 *    Changes a mapped file view's FileViewAccess.
 *
 *  Discussion:
 *    The SetViewAccess function changes the FileViewAccess of the
 *    mapped file view specified by the theView parameter. The new
 *    FileViewAccess is specified by the accessLevel parameter.
 *
 *  Parameters:
 *
 *    theView:
 *      The mapped file view.
 *
 *    access:
 *      The new FileViewAccess.
 *
 *  Result:
 *    An operating system result code: noErr, paramErr,
 *    vmInvalidFileViewIDErr, or vmFileViewAccessErr.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
SetFileViewAccess(FileViewID theView, FileViewAccess access)
    TWOWORDINLINE(0x700D, 0xAA81);

/**
 *  SetFileViewBackingBase()
 *
 *  Summary:
 *    Changes the backing base of a mapped file view.
 *
 *  Discussion:
 *    The SetFileViewBackingBase function changes the backing base of
 *    the mapped file view specified by theView. The new backing base
 *    is specified by the newBackingBase parameter.
 *
 *  Parameters:
 *
 *    theView:
 *      The mapped file view.
 *
 *    newBackingBase:
 *      Pointer to the offset into mapped file fork. Passing a NULL
 *      pointer is the same as passing an offset of zero.
 *
 *  Result:
 *    An operating system result code: noErr, vmInvalidFileViewIDErr,
 *    or paramErr.
 *

 *    \non_carbon_cfm   in InterfaceLib 9.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
SetFileViewBackingBase(
    FileViewID theView,
    const UInt64 *newBackingBase) /** can be NULL */ TWOWORDINLINE(0x700E,
                                                                   0xAA81);

#endif /** CALL_NOT_IN_CARBON */

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

#endif /** __FILEMAPPING__ */
