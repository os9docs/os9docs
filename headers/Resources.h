/**
     \file       Resources.h

    \brief   Resource Manager Interfaces.

    \introduced_in  Mac OS 8.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Managers

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __RESOURCES__
#define __RESOURCES__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
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
    resSysHeap = 64,   // System or application heap?
    resPurgeable = 32, // Purgeable resource?
    resLocked = 16,    // Load it in locked?
    resProtected = 8,  // Protected?
    resPreload = 4,    // Load in on OpenResFile?
    resChanged = 2,    // Resource changed?
    mapReadOnly = 128, // Resource file read-only
    mapCompact = 64,   // Compact resource file
    mapChanged = 32    // Write map out at update
  };

  enum
  {
    resSysRefBit = 7,    // reference to system/local reference
    resSysHeapBit = 6,   // In system/in application heap
    resPurgeableBit = 5, // Purgeable/not purgeable
    resLockedBit = 4,    // Locked/not locked
    resProtectedBit = 3, // Protected/not protected
    resPreloadBit = 2,   // Read in at OpenResource?
    resChangedBit = 1,   // Existing resource changed since last update
    mapReadOnlyBit = 7,  // is this file read-only?
    mapCompactBit = 6,   // Is a compact necessary?
    mapChangedBit = 5    // Is it necessary to write map?
  };

  enum
  {
    kResFileNotOpened =
        -1,            // ref num return as error when opening a resource file
    kSystemResFile = 0 // this is the default ref num to the system file
  };

  typedef CALLBACK_API_REGISTER68K(void, ResErrProcPtr, (OSErr thErr));
  typedef REGISTER_UPP_TYPE(ResErrProcPtr) ResErrUPP;
  /**
   *  NewResErrUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ResErrUPP
  NewResErrUPP(ResErrProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppResErrProcInfo = 0x00001002
  }; // register no_return_value Func(2_bytes:D0) #ifdef __cplusplus
  inline ResErrUPP NewResErrUPP(ResErrProcPtr userRoutine)
  {
    return (ResErrUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppResErrProcInfo, GetCurrentArchitecture());
  }
#else
#define NewResErrUPP(userRoutine)                                             \
  (ResErrUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppResErrProcInfo, \
                                   GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeResErrUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeResErrUPP(ResErrUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeResErrUPP(ResErrUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeResErrUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeResErrUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeResErrUPP(__D0, __A0)
#endif
  void
  InvokeResErrUPP(OSErr thErr, ResErrUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeResErrUPP(OSErr thErr, ResErrUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppResErrProcInfo, thErr);
  }
#else
#define InvokeResErrUPP(thErr, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppResErrProcInfo, (thErr))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewResErrProc(userRoutine) NewResErrUPP(userRoutine)
#define CallResErrProc(userRoutine, thErr) InvokeResErrUPP(thErr, userRoutine)
#endif // CALL_NOT_IN_CARBON
       // QuickTime 3.0  typedef CALLBACK_API(OSErr,
                       ResourceEndianFilterPtr)(Handle theResource,
                                                Boolean currentlyNativeEndian);
#if CALL_NOT_IN_CARBON
                       /**
                        *  InitResources()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        not available
                        *    \mac_os_x         not available
                        */
                       short
                       InitResources(void);

                       /**
                        *  RsrcZoneInit()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        not available
                        *    \mac_os_x         not available
                        */
                       void
                       RsrcZoneInit(void);

#endif // CALL_NOT_IN_CARBON
                       /**
                        *  CloseResFile()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in version 10.0 and later
                        */
                       void
                       CloseResFile(short refNum);

                       /**
                       \brief Find if an error occurred in a resource operation

                       <pre>You can use ResError to read that code and see if the most recent operation
                     caused an error, and if so, what the error was.
                     </pre>
                     * \returns <pre>an integer; the Error Code of the most recent resource-related
                     operation. It may be a file system error or one of the following
                     resource error constants:
                     noErr(0)No Error (this constant is defined in MacTypes.h)
                     resNotFound (-192)Resource not found
                     resFNotFound (-193)Resource file not found
                     addResFailed (-194)AddResource failed
                     rmvResFailed (-196)RmveResource failed
                     (-197)(not used)
                     resAttrErr (-198)Attribute does not permit operation
                     mapReadErr (-199)Error reading resource map
                     </pre>
                     * \note <pre>ResError is functionally equivalent to reading the low-memory global,
                     ResErr; i.e., the following are the same, except the latter generates less
                     code and is faster:
                     if ( ResError () ){ ... an error occurred ... }
                     if ( ResErr ) { ... an error occurred ... }
                     ResError may return other system errors, for instance, dskFulErr or
                     memFullErr . See Error Codes for a full list.
                     A few Resource Manager functions indicate errors by returning a NIL
                     handle (e.g., GetResource ). When these calls fail, ResError returns
                     noErr, so be sure to check for NIL handles!
                     </pre>
                     * \copyright THINK Reference © 1991-1992 Symantec Corporation
                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                     *    \carbon_lib        in CarbonLib 1.0 and later
                     *    \mac_os_x         in version 10.0 and later
                     */
                       OSErr
                       ResError(void);

                       /**
                       \brief Get reference number of current resource file

                       <pre>CurResFile returns the file reference number of the "current resource
                     file" - the first file searched during a resource request.
                     </pre>
                     * \returns <pre>an integer; the reference number of the current resource file.
                     </pre>
                     * \note <pre>You can use this function early in an application to determine the reference
                     number of the application's resource file.
                     The global variable CurMap (at 0x0A5A) contains the same information
                     that this call returns. Thus, the following are the same except that the
                     latter generates less code:
                     fRef= CurResFile ();
                     fRef= CurMap;
                     </pre>
                     * \copyright THINK Reference © 1991-1992 Symantec Corporation
                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                     *    \carbon_lib        in CarbonLib 1.0 and later
                     *    \mac_os_x         in version 10.0 and later
                     */
                       short
                       CurResFile(void);

                       /**
                       \brief Given a resource handle, return a file reference number
                       \param    rHandle generic Handle of resource of interest
                       <pre>In the 64K ROMs, HomeResFile can be used to make sure a resource is
                     from the application's resource file. The "one-deep" functions
                     (Get1Resource , Get1IndResource , etc.) of the 128K ROMs make this
                     usage unnecessary.
                     </pre>
                     * \copyright THINK Reference © 1991-1992 Symantec Corporation
                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                     *    \carbon_lib        in CarbonLib 1.0 and later
                     *    \mac_os_x         in version 10.0 and later
                     */
                       short
                       HomeResFile(Handle theResource);

#if CALL_NOT_IN_CARBON
                       /**
                        *  CreateResFile()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        not available
                        *    \mac_os_x         not available
                        */
                       void
                       CreateResFile(ConstStr255Param fileName);

                       /**
                        *  OpenResFile()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        not available
                        *    \mac_os_x         not available
                        */
                       short
                       OpenResFile(ConstStr255Param fileName);

#endif // CALL_NOT_IN_CARBON
                       /**
                       \brief Make specified resource file the "current file".

                       <pre>UseResFile selects a different file (already open) as the current resource
                     file. On subsequent resource requests, the specified file will be searched first
                     and none of the more recently opened resource files will be searched.
                     rfRefNum is a resource file reference number; typically a value obtained from
                     OpenResFile , HomeResFile , or CurResFile . Use 0 to specify
                     the system resource file.
                     </pre>
                     * \returns <pre>none (use ResError to determine success/failure)
                     </pre>
                     * \note <pre>Open resource files are arranged as a linked list; the most recently opened
                     file is at the end of the list and is the first one the Resource Manager
                     searches when looking for a resource. UseResFile lets you start the search
                     with a file opened earlier; the file(s) following it in the list are then left out
                     of the search process. When a new resource file is opened, it's added to the
                     end of the list; this overrides any previous calls to UseResFile , causing
                     the entire list of open resource files to be searched. For example, assume
                     that there are four open resource files (R0 through R3) and the search
                     order is R3, R2, R1, R0. If you call UseResFile (R2), the search order
                     becomes R2, R1, R0. Note that R3 is no longer searched. If you then open a
                     fifth resource file (R4), it is added to the end of the list and the search
                     order becomes R4, R3, R2, R1, R0.
                     UseResFile does not re-order the resource file list; it causes resource
                     searching to start at a specified file and work backwards (chronologically)
                     down the list if it fails to find a resource in the current file.
                     For instance, after UseResFile (0), calls such as GetResource or
                     GetPicture will search only the system resource file.
                     The application's resource file is implicitly set as the current file when an
                     application is started. The OpenResFile function also sets the current
                     resource file, thereby overriding any previous call to UseResFile .
                     The resource search order is affected by the setting of the low-memory
                     globals RomMapInsert and TmpResLoad . These affect whether ROM-based
                     resources are considered to be in the normal lookup list.
                     </pre>
                     * \copyright THINK Reference © 1991-1992 Symantec Corporation
                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                     *    \carbon_lib        in CarbonLib 1.0 and later
                     *    \mac_os_x         in version 10.0 and later
                     */
                       void
                       UseResFile(short refNum);

                       /**
                       \brief Get total number of resource types in open files

                       <pre>CountTypes returns the total number of resource types in all
                     currently-opened resource files. It can be used as a first step in a
                     system-wide examination of resources.
                     </pre>
                     * \returns <pre>a positive integer; it is the total number of distinct resource types
                     in all open resource files.
                     </pre>
                     * \note <pre>CountTypes is only needed by resource-management utilities such as
                     ResEdit or Resorcerer. This function is the first step in generating a list of
                     all the different resource types, thus making it possible to look up each
                     individual resource. Subsequent calls to GetIndType will return the
                     ResType value for types from 1 to the return value of this call.
                     This function operates across all open resource files while the similar
                     Count1Types function counts just the resource types in the current
                     resource file.
                     The following example displays a list of resource types along with the
                     number of such resources, contained in all open resource files.
                     Example
                     #include < Resources.h >
                     #include <stdio.h> // for printf()   short rTotal, j;
                       ResType rt;
                       char *rtp;
                       rTotal = CountTypes();
                       for (j = 1; j <= rTotal; j++)
                       {
                         GetIndType(&rt, j);
                         rtp = &rt;
                         printf("Type '%c%c%c%c' has %d resources\n",
                                rtp[0], rtp[1], rtp[2], rtp[3], CountResources(rt));
                       }
                       </ pre>
                                   * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                                             *    \non_carbon_cfm in InterfaceLib 7.1 and
                           later
                               *    \carbon_lib in CarbonLib 1.0 and
                           later
                               *    \mac_os_x in version 10.0 and
                           later
                                 */
                       short
                       CountTypes(void);

                       /**
                       \brief Get total number of resource types in current file

                       <pre>Count1Types returns the number of resource types in the current resource
                     file. It can be used as a first step in "1-deep" examination of resources.
                     </pre>
                     * \returns <pre>a positive integer; it is the total number of distinct resource types
                     in the current resource file.
                     </pre>
                     * \note <pre>Count1Types works exactly like CountTypes except that it limits the
                     type search to the current resource file.  This is normally followed by a
                     series of calls to Get1IndType .
                     Refer to CountTypes for related details.
                     </pre>
                     * \copyright THINK Reference © 1991-1992 Symantec Corporation
                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                     *    \carbon_lib        in CarbonLib 1.0 and later
                     *    \mac_os_x         in version 10.0 and later
                     */
                       short
                       Count1Types(void);

                       /**
                       \brief Get the ResType of a resource, given its index

                       <pre>GetIndType obtains the 4-byte ResType of a resource, given an
                     arbitrarily-defined index number.
                     rTypeis the address of a 4-byte ResType value. Upon return, it will
                     contain the resource type code associated with the resource identified
                     by index ; e.g., 'FONT', 'ICON', 'ICN#', etc. A value of 0 (four ASCII
                     NULs) indicates that index was an invalid value.
                     indexis a positive integer. It should range from 1 to the total number of
                     distinct resources available (see CountTypes ).
                     </pre>
                     * \returns <pre>none
                     </pre>
                     * \note <pre>GetIndType is usually only needed by resource-management utilities
                     such as ResEdit. This function is the second step (following CountTypes )
                     in generating a list of all the different resource types, thus making it
                     possible to look up each individual resource.
                     Note: All the types obtained via this call are not necessarily available for
                     access. The "indexed ResType list" contains ALL resource types while calls
                     such as GetResource may search a subset of this list (i.e., the list of files
                     starting with the current resource file and working chronologically
                     backward toward the system file).
                     See CountTypes for an example of usage.
                     </pre>
                     * \copyright THINK Reference © 1991-1992 Symantec Corporation
                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                     *    \carbon_lib        in CarbonLib 1.0 and later
                     *    \mac_os_x         in version 10.0 and later
                     */
                       void
                       GetIndType(ResType *theType, short index);

                       /**
                        *  Get1IndType()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in version 10.0 and later
                        */
                       void
                       Get1IndType(ResType *theType, short index);

                       /**
                       \brief Set state of automatic resource loading

                       <pre>After using SetResLoad (FALSE), be sure to use SetResLoad (TRUE) as
                     soon as possible. Some toolbox calls malfunction when resources do not
                     automatically load. Furthermore, remember to use SetResLoad (TRUE)
                     before exiting from your application; otherwise the Finder's code resource
                     will not be loaded.
                     The low-memory global variable ResLoad echoes the status of this call, but
                     remember that any non-zero value indicates that resource loading is
                     disabled.
                     The following calls set ResLoad to TRUE (enable auto-loading) as a
                     side-effect: GetFNum , GetFontName , RealFont and AddResMenu .
                     See CountResources for an example of usage.
                     </pre>
                     * \copyright THINK Reference © 1991-1992 Symantec Corporation
                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                     *    \carbon_lib        in CarbonLib 1.0 and later
                     *    \mac_os_x         in version 10.0 and later
                     */
                       void
                       SetResLoad(Boolean load);

                       /**
                       \brief Find how many of a selected resource type exist

                       <pre>CountResources returns the number of resources of a specified resource
                     type that exist among the currently-open resource files.
                     rTypeis a 4-byte ResType value identifying the resource type you wish to
                     count (e.g. 'FONT', 'MENU', etc.).
                     </pre>
                     * \returns <pre>a positive integer; the number of resources of the specified type
                     contained in all currently-open resource files. Returns 0 if none are
                     found.
                     </pre>
                     * \note <pre>This function is used as the first step in generating a list of
                     currently-available resources of a particular type. To generate the list,
                     use GetIndResource with an index ranging from 1 to the
                     CountResources return value.
                     Use Count1Types and Get1IndResource to count and access only the
                     resources in the current resource file.
                     The following example prints a list of the names of all resources of type
                     'DRVR' (i.e., desk accessories).
                     Example
                     #include < Resources.h >
                     short rCount, rID, j;
                     Handle rHandle;
                     ResType rType;
                     Str255 rName;
                     printf("\n"); // ensure printf can get fonts
 // before calling SetResLoad
 rCount = CountResources('DRVR');
                       SetResLoad(FALSE); // do not need resource, just info   for (j = 1; j <= rCount; j++)
                       {
                         rHandle = GetIndResource('DRVR', j);
                         GetResInfo(rHandle, &rID, &rType, rName);
                         printf(" 'DRVR' Rsrc ID: %6d, Name: %s\n", rID, PtoCstr(rName) + 1);
                       }
                       SetResLoad(TRUE); // better do this!   </ pre>
                                   * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                                             *    \non_carbon_cfm in InterfaceLib 7.1 and
                           later
                               *    \carbon_lib in CarbonLib 1.0 and
                           later
                               *    \mac_os_x in version 10.0 and
                           later
                                 */
                       short
                       CountResources(ResType theType);

                       /**
                       \brief Get "1-deep" count of resources of selected type

                       <pre>Count1Resources returns the number of resources of a specified type
                     which exist in the current resource file.
                     rTypeis a 4-byte ResType value identifying the resource type you wish to
                     count (e.g. 'FONT', 'MENU', etc.).
                     </pre>*/
                       * \returns<pre> a positive integer; the number of resources of the specified type in
the current resource file. Returns 0 if none found.
</pre>
* \note <pre>This function is the "1-deep" version of CountResources . To generate a
list of resources of type rType for the current resource file, use
Get1IndResource with an index ranging from 1 to the value obtained via
Count1Resources .
Refer to CountTypes and GetIndResource for related details.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  short
  Count1Resources(ResType theType);

                       /**
                        *  GetIndResource()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in version 10.0 and later
                        */
                       Handle
                       GetIndResource(ResType theType, short index);

                       /**
                        *  Get1IndResource()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in version 10.0 and later
                        */
                       Handle
                       Get1IndResource(ResType theType, short index);

                       /**
                        *  GetResource()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in version 10.0 and later
                        */
                       Handle
                       GetResource(ResType theType, short theID);

                       /**
                        *  Get1Resource()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in version 10.0 and later
                        */
                       Handle
                       Get1Resource(ResType theType, short theID);

                       /**
                        *  GetNamedResource()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in version 10.0 and later
                        */
                       Handle
                       GetNamedResource(ResType theType, ConstStr255Param name);

                       /**
                        *  Get1NamedResource()
                        *

                        *    \non_carbon_cfm   in InterfaceLib 7.1 and later
                        *    \carbon_lib        in CarbonLib 1.0 and later
                        *    \mac_os_x         in version 10.0 and later
                        */
                       Handle
                       Get1NamedResource(ResType theType, ConstStr255Param name);

/**
 *  [Mac]LoadResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacLoadResource LoadResource
#endif
  void
  MacLoadResource(Handle theResource);

  /**
   *  ReleaseResource()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ReleaseResource(Handle theResource);

  /**
  \brief Prevent resource from being discarded when file is closed

  <pre>DetachResource removes a resource handle from the resource map
without releasing it from memory. This can be used to keep one or more
resources in memory after closing a resource file.
rHandle is a handle leading to some variable length resource data. This
should be a valid handle obtained via GetResource ,
GetNamedResource , etc.
</pre>
* \returns <pre>none (if rHandle is not a handle to a resource, or if detachment is
disallowed, ResError will return an error).
</pre>
* \note <pre>DetachResource causes rHandle 's resource map pointer to be set to
NIL while maintaining the resource in memory and keeping the handle's
master pointer valid. One significant effect is that when a resource's file is
closed (see CloseResFile ), the resource data is not purged from memory.
After this call, rHandle is no longer considered to be a resource handle.
Calls such as ReleaseResource and GetResInfo will not respond. If you
call GetResource (et. al.) for the same handle, the resource will be read
into memory again. You can copy the detached resource and install the
duplicate into the resource list via AddResource . To discard the detached
resource data, use DisposHandle .
This function is not valid for resources tagged with the resChanged
attribute ( ResError returns resAttrErr ).
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  DetachResource(Handle theResource);

  /**
  \brief Get unique resource ID (before adding a resource)

  <pre>UniqueID returns a unique, unused resource ID that will not collide with any
resource of the specified type in any open resource file.
rTypeis a 4-byte ResType value. It identifies the resource type for which
you wish a unique resource ID (e.g., 'FONT', 'WIND', etc.)
</pre>
* \returns <pre>an integer; a resource ID number that is unique with respect to all
resources of type rType in all currently-open resource files.
</pre>
* \note <pre>UniqueID and Unique1ID are used by applications that create resources;
especially temporary resources that are removed when the program
terminates. After making this call, you can safely add to the resource list,
e.g.,:
newID = UniqueID ( 'MENU' );
AddResource ( myHand, 'MENU', newID, "\pMy New Menu" );
To avoid colliding with IDs of ROM-based resources (i.e., get a truly
unique ID), set the RomMapInsert flag directly before calling:
RomMapInsert = mapTrue ;
newID = UniqueID ( 'MENU' );
See GetResource for information about ROM-based resources.
This call may return IDs less than 128 which, by convention, are reserved
for system resources. Just call it again until you get an ID greater than
127.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  short
  UniqueID(ResType theType);

  /**
  \brief 1-deep, get unique resource ID

  <pre>Unique1ID returns a unique, unused resource ID that will not collide with
any resource of the specified type in the current resource file.
rTypeis a 4-byte ResType value. It identifies the resource type for which
you wish a unique resource ID (e.g., 'FONT', 'WIND', etc.)
</pre>
* \returns <pre>an integer; a resource ID number that is unique with respect to
resources of type rType in the current resource file.
</pre>
* \note <pre>This function is the "1-deep" version of UniqueID . It generates a
resource ID that is unique with respect to resources in the current resource
file (see UseResFile ).  Refer to UniqueID for related details.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  short
  Unique1ID(ResType theType);

  /**
   *  GetResAttrs()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  GetResAttrs(Handle theResource);

  /**
  \brief Given a handle, obtain resource ID, type, and name


   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  GetResInfo(Handle theResource, short *theID, ResType *theType, Str255 name);

  /**
   *  SetResInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SetResInfo(Handle theResource, short theID, ConstStr255Param name);

  /**
  \brief Make arbitrary data in memory into a resource

  <pre>
* \note <pre>AddResource converts an existing handle (either one that points to any
existing data or even an empty handle) into a handle recognized by the
Resource Manager and saved in the resource map . This affects the
map of the current resource file (see UseResFile ).
This function automatically sets the resChanged bit of the resource
attribute. Thus, when the current resource file is closed or updated the
resource data and map will be written to disk (see ChangedResource ).
All other attributes are cleared; use SetResAttrs before writing the
resource if you want different attributes.
This is the opposite of DetachResource , which converts a resource
handle into a generic handle. To duplicate a resource, use DetachResource
followed by AddResource .
Example
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  AddResource(Handle theData, ResType theType, short theID, ConstStr255Param name);

  /**
   *  GetResourceSizeOnDisk()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long
  GetResourceSizeOnDisk(Handle theResource);

  /**
   *  GetMaxResourceSize()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long
  GetMaxResourceSize(Handle theResource);

#if CALL_NOT_IN_CARBON

  /**
  \brief Obtain offset in resource map for a handle's entry

  <pre>RsrcMapEntry returns an offset from the start of the resource map . The
offset specifies the location of a particular resource entry.
rHandle is a valid resource handle. It is a value obtained via GetResource ,
GetIndResource , et. al.
</pre>
* \returns <pre>a 32-bit long integer; the offset from the start of the resource
map which contains the start of the resource entry for rHandle . A
return value of NIL indicates an error and ResError will return
resNotFound .
</pre>
* \note <pre>The low-memory global variable TopMapHndl (0xA50) contains a handle
leading to the start of the resource map of the current resource file.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
  long
  RsrcMapEntry(Handle theResource);

#endif // CALL_NOT_IN_CARBON
  /**
  \brief Set resource attributes (purgeable, locked, etc.)

  <pre>SetResAttrs sets resource attributes in the resource map . The modified
attributes will not take effect until the next time the resource is loaded.
rHandle is a resource handle. It is a handle obtained via GetResource ,
GetIndResource , et. al.
rAttrsis a 16-bit resource attribute word - a bit record which specifies
how the resource is to be handled when loaded subsequently (see
below).
</pre>
* \returns <pre>none
</pre>
* \note <pre>SetResAttrs is normally needed only by resource-management utilities
such as ResEdit; it is a rare application that needs to modify attributes by
using this function.
The rAttrs parameter specifies resource attributes as follows:
7  6  5 4  3  2  1  0
0x01
0x02
0x04
0x08
0x10
0x20
0x40
0x80(reserved)
resChanged
resPreload
resProtected
resLocked
resPurgeable
resSysHeap
(reserved)1= has changed; UpdateResFile will write to disk
1= is preloaded when file is opened
1= can’t change ID, name, contents, etc.
1= won’t be moved or purged
1= purgeable (call LoadResource before access)
1= load in system heap; 0= use application heap
The new setting of resProtected takes effect immediately, so make sure you
have already written any changes out to disk; other attributes take effect
the next time the resource is loaded. We are warned specifically against
modifying the state of the resChanged attribute directly. Use
ChangedResource to flag a resource for update.
A normal sequence is to use GetResAttrs to find the current settings,
modifying one or more bits (without changing bit 1), then use SetResAttrs
to update the resource map . This is illustrated in the following example:
Example
#include < Resources.h >
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  SetResAttrs(Handle theResource, short attrs);

  /**
   *  ChangedResource()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ChangedResource(Handle theResource);

  /**
   *  RemoveResource()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  RemoveResource(Handle theResource);

  /**
  \brief Write changed resource map and data to disk

  <pre>UpdateResFile writes the resource map and all changed data of the
specified resource file to disk. Data is written only if one or more resources
are tagged as having been modified.
rfRefNum identifies the resource file to update. It is a value obtained from
OpenResFile , HomeResFile , or CurResFile . A value of 0
refers to the system resource file.
</pre>
* \returns <pre>none (use ResError to determine success/failure)
</pre>
* \note <pre>All changed resource data (as tagged with the resChanged attribute set via
ChangedResource ) is written to disk as described in WriteResource .
All changes to the resource map of the file are recorded, including changes
made by AddResource and RmveResource . The file data is compacted, if
necessary. The resChanged attribute of all resources written to disk is
reset. You might wish to call FlushVol to ensure that the information is
really written out to disk.
Be aware that using DetachResource sets the resource's handle to NIL in
the resource map .  Similarly, any purged resource will be saved as an
empty resource (see WriteResource ).
You may use CurResFile , early in your program, to obtain the rfRefNum
of your application's resource file.
This function is called automatically when the file is closed via
CloseResFile .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  UpdateResFile(short refNum);

  /**
  \brief Write data of one resource to disk

  <pre>
* \note <pre>WriteResource is called automatically by UpdateResFile and
CloseResFile .
Remember that if a resource has been purged, these file operations will
write a 0-length resource to the file. Thus, a typical use of this function is
in a sequence that locks a resource, changes it, writes the changes, and
unlocks the resource:
HNoPurge ( rHandle ); // inhibit purging   // ... modify the handle data...
  ChangedResource(rHandle); // tag as changed   if (ResError() == noErr)
  {                         // always check this!
   WriteResource(rHandle); // record changes to disk   }
  HPurge(rHandle); // allow purge   Make sure you check ResError after calling ChangedResource(or
                                                             AddResource) and
      before calling WriteResource.</ pre>
              * \copyright THINK Reference © 1991 -
          1992 Symantec Corporation
              *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
          *    \carbon_lib in CarbonLib 1.0 and
      later
          *    \mac_os_x in version 10.0 and
      later
            */
  void WriteResource(Handle theResource);

  /**
  \brief Force resource changes to be written before purge

  <pre>
* \note <pre>SetResPurge is an attempt to avoid the "silent error" of writing a
0-length resource to disk when a resource file is updated. It is needed only
by applications that modify a resource tagged as resPurgeable (see
GetResAttrs ).
In a memory shortage situation the Memory Manager will discard all
purgeable resources and compact memory. Then, when you
WriteResource , UpdateResFile , or CloseResFile , a 0-length
resource is sent to disk. By calling SetResPurge (TRUE), you can avoid
this problem. Another way is to set the address of a custom "purge warning
handler" into the purgeProc field of the memory manager's Zone structure
obtained via*/icZone . Yet another way is: avoid changing purgeable
resources altogether!
Note that this does NOT keep the resource from getting purged. You must
use LoadResource before each access of an unlocked purgeable resource.
See HNoPurge for a way to force any purgeable handle to remain in
memory.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  SetResPurge(Boolean install);

  /**
  \brief Obtain resource file attributes

  <pre>GetResFileAttrs returns a value representing the bit record that holds a
resource file's attributes. In doing so, it tests whether a resource file is
marked as read-only, has changed, or needs compacting.
rfRefNum identifies the resource file to query. It is a value obtained from
OpenResFile , HomeResFile , or CurResFile . A value of 0
refers to the system resource file.
</pre>
* \returns <pre>a signed short; a bit record identifying the current resource file
attributes of rfRefNum  (see below). Note: Use ResError to check
whether this function succeeded before assuming a valid return value.
</pre>
* \note <pre>You will want to use this function before calling SetResFileAttrs , in
order to modify one or two attributes while leaving others unchanged.
Resource file attributes are defined as follows:
7  6  5 4  3  2  1  0
0x01
0x02
0x04
0x08
0x10
0x20
0x40
0x80(reserved)
(reserved)
(reserved)
(reserved)
(reserved)
mapChanged
mapCompact
mapReadOnly1= resource map will be written on update
1= file will be compacted upon update
1= file can’t be written
The mapChanged attribute is set by commands such as AddResource ,
RmveResource , SetResAttrs and SetResInfo , and when
ChangedResource tags a resource whose size has been changed. When
set, the resource map will be written to the file.
The mapCompact bit is set on all operations that change the size of the file
(Note: on the 64K ROMs, this bit was not set if a resource simply got
smaller). When set, the entire resource file is reorganized as it is
rewritten and all empty space in the file is removed.
The mapReadOnly attribute overrides all resource resChanged attributes in
that WriteResource , UpdateResFile , and CloseResFile will NOT cause
data to be written to the file.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  short
  GetResFileAttrs(short refNum);

  /**
  \brief Set resource file attributes

  <pre>SetResFileAttrs sets resource file attributes. It specifies whether a
resource file is marked as read-only, has changed, or needs compacting. This
is needed rarely, since file attributes are modified automatically by the
Resource Manager .
rfRefNum identifies the resource file whose attributes you wish to modify. It
is a value obtained from OpenResFile , HomeResFile ,
CurResFile or OpenRFPerm . A value of 0 refers to the system
resource file.
rfAttrsidentifies the desired attributes you wish to apply to the resource
file. See below..
</pre>
* \returns <pre>none (use ResError to check for success/failure)
</pre>
* \note <pre>Resource file attributes are defined as follows:
7  6  5 4  3  2  1  0
0x01
0x02
0x04
0x08
0x10
0x20
0x40
0x80(reserved)
(reserved)
(reserved)
(reserved)
(reserved)
mapChanged
mapCompact
mapReadOnly1= resource map will be written on update
1= file will be compacted upon update
1= file can’t be written
See GetResFileAttrs for related information.
In the 64K ROMs, it was necessary to set mapCompact manually if you
wanted to recover the file space that had been occupied by a resource after it
was shortened. Since this was fixed, there was little reason to modify
resource file attributes.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  SetResFileAttrs(short refNum, short attrs);

  /**
   *  OpenRFPerm()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  OpenRFPerm(ConstStr255Param fileName, short vRefNum, SInt8 permission);

#if CALL_NOT_IN_CARBON
  /**
   *  RGetResource()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle
  RGetResource(ResType theType, short theID);

#endif // CALL_NOT_IN_CARBON
  /**
   *  HOpenResFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  HOpenResFile(short vRefNum, long dirID, ConstStr255Param fileName,
               SInt8 permission);

  /**
   *  HCreateResFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  HCreateResFile(short vRefNum, long dirID, ConstStr255Param fileName);

  /**
  \brief Open resource file specified by an FSSpec

  <pre>The FSpOpenResFile function creates the file named in the spec parameter.
The FSpOpenResFile function lets you open a resource file without creating a
working directory. The permission parameter can contain any one of the
following constants:
fsCurPerm whatever is currently allowed
fsRdPerm request for read permission only
fsWrPerm request for write permission
fsRdWrPerm request for exclusive read/write permission
fsRdWrShPerm request for shared read/write permission
More information about these constants can be found in the
Low-Level File Manager section of the File Manager . If the
FSpOpenResFile function failed to open the resource file, the reference
number returned is -1. Call the ResError function to check for errors.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  short
  FSpOpenResFile(const FSSpec *spec, SignedByte permission);

  /**
   *  FSpCreateResFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FSpCreateResFile(const FSSpec *spec, OSType creator, OSType fileType,
                   ScriptCode scriptTag);

  /**
   *  ReadPartialResource()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ReadPartialResource(Handle theResource, long offset, void *buffer, long count);

  /**
   *  WritePartialResource()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  WritePartialResource(Handle theResource, long offset, const void *buffer,
                       long count);

  /**
   *  SetResourceSize()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SetResourceSize(Handle theResource, long newSize);

  /**
   *  GetNextFOND()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Handle
  GetNextFOND(Handle fondHandle);

  // QuickTime 3.0#if CALL_NOT_IN_CARBON
  /**
   *  RegisterResourceEndianFilter()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  RegisterResourceEndianFilter(ResType theType,
                               ResourceEndianFilterPtr theFilterProc);

  /* Use TempInsertROMMap to force the ROM resource map to be
     inserted into the chain in front of the system. Note that
     this call is only temporary - the modified resource chain
     is only used for the next call to the resource manager.
     See IM IV 19 for more information.
  */
  /**
   *  TempInsertROMMap()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TempInsertROMMap(Boolean tempResLoad);

  /**
    _________________________________________________________________________________________________________

     © RESOURCE CHAIN LOCATION - for use with the Resource Manager chain
    manipulation routines under Carbon.
    _________________________________________________________________________________________________________
  */

#endif // CALL_NOT_IN_CARBON
  typedef SInt16 RsrcChainLocation;
  enum
  {
    kRsrcChainBelowSystemMap = 0,                                                                                                            /** the */
    system 's resource map    kRsrcChainBelowApplicationMap  =  1  /** the */ application ' s resource map kRsrcChainAboveApplicationMap = 2 // Above the application' s resource map kRsrcChainAboveAllMaps = 4 // Above all resource maps
  };

  /**
     If the file is already in the resource chain, it is removed and re-inserted
     at the specified location If the file has been detached, it is added to the
     resource chain at the specified location Returns resFNotFound if it's not
     currently open.
  */
  /**
   *  InsertResourceFile()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InsertResourceFile(SInt16 refNum, RsrcChainLocation where);

  /**
     If the file is not currently in the resource chain, this returns resNotFound
     Otherwise, the resource file is removed from the resource chain.
  */
  /**
   *  DetachResourceFile()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DetachResourceFile(SInt16 refNum);

  /**
     Returns true if the resource file is already open and known by the Resource
     Manager (i.e., it is either in the current resource chain or it's a detached
     resource file.)  If it's in the resource chain, the inChain Boolean is set to
     true on exit and true is returned.  If it's an open file, but the file is
     currently detached, inChain is set to false and true is returned.  If the
     file is open, the refNum to the file is returned.
  */
  /**
   *  FSpResourceFileAlreadyOpen()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  FSpResourceFileAlreadyOpen(const FSSpec *resourceFile, Boolean *inChain,
                             SInt16 *refNum);

  /**
     FSpOpenOrphanResFile should be used to open a resource file that is
     persistent across all contexts, because using OpenResFile normally loads a
     map and all preloaded resources into the application context.
     FSpOpenOrphanResFile loads everything into the system context and detaches
     the file from the context in which it was opened.  If the file is already in
     the resource chain and a new instance is not opened, FSpOpenOrphanResFile
     will return a paramErr. Use with care, as can and will fail if the map is
     very large or a lot of preload resources exist.
  */
  /**
   *  FSpOpenOrphanResFile()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSpOpenOrphanResFile(const FSSpec *spec, SignedByte permission, SInt16 *refNum);

  /**
     GetTopResourceFile returns the refNum of the top most resource map in the
     current resource chain. If the resource chain is empty it returns
     resFNotFound.
  */
  /**
   *  GetTopResourceFile()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetTopResourceFile(SInt16 *refNum);

  /**
     GetNextResourceFile can be used to iterate over resource files in the
     resource chain. By passing a valid refNum in curRefNum it will return in
     nextRefNum the refNum of the next file in the chain. If curRefNum is not
     found in the resource chain, GetNextResourceFile returns resFNotFound. When
     the end of the chain is reached GetNextResourceFile will return noErr and
     nextRefNum will be NIL.
  */
  /**
   *  GetNextResourceFile()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetNextResourceFile(SInt16 curRefNum, SInt16 *nextRefNum);

#if CALL_NOT_IN_CARBON
  /**
   *  getnamedresource()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle
  getnamedresource(ResType theType, const char *name);

  /**
   *  get1namedresource()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle
  get1namedresource(ResType theType, const char *name);

  /**
   *  openrfperm()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  openrfperm(const char *fileName, short vRefNum, char permission);

  /**
   *  openresfile()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  openresfile(const char *fileName);

  /**
   *  createresfile()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  createresfile(const char *fileName);

  /**
   *  getresinfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  getresinfo(Handle theResource, short *theID, ResType *theType, char *name);

  /**
   *  setresinfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  setresinfo(Handle theResource, short theID, const char *name);

  /**
   *  addresource()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  addresource(Handle theResource, ResType theType, short theID, const char *name);

#endif // CALL_NOT_IN_CARBON
#if OLDROUTINENAMES
#define SizeResource(theResource) GetResourceSizeOnDisk(theResource)
#define MaxSizeRsrc(theResource) GetMaxResourceSize(theResource)
#define RmveResource(theResource) RemoveResource(theResource)
#endif // OLDROUTINENAMES
  /**
   *  FSOpenResFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  FSOpenResFile(const FSRef *ref, SInt8 permission);

  /**
   *  FSCreateResFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FSCreateResFile(const FSRef *parentRef, UniCharCount nameLength,
                  const UniChar *name, FSCatalogInfoBitmap whichInfo,
                  const FSCatalogInfo *catalogInfo, FSRef *newRef,
                  FSSpec *newSpec);

  /**
   *  FSResourceFileAlreadyOpen()
   *

   *    \non_carbon_cfm   in InterfaceLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  FSResourceFileAlreadyOpen(const FSRef *resourceFileRef, Boolean *inChain,
                            SInt16 *refNum);

  /**
   *  FSCreateResourceFile()
   *
   *  Summary:
   *    Creates a new resource file.
   *
   *  Discussion:
   *    This function creates a new file and initializes the specified
   *    named fork as an empty resource fork.  This function allows for
   *    the creation of data fork only files which can be used for
   *    storing resources.  Passing in a null name defaults to using the
   *    data fork.
   *
   *  Parameters:
   *
   *    parentRef:
   *      The directory where the file is to be created
   *
   *    nameLength:
   *      Number of Unicode characters in the file's name
   *
   *    name:
   *      A pointer to the Unicode name
   *
   *    whichInfo:
   *      Which catalog info fields to set
   *
   *    catalogInfo:
   *      The values for catalog info fields to set; may be NULL
   *
   *    forkNameLength:
   *      The length of the fork name (in Unicode characters)
   *
   *    forkName:
   *      The name of the fork to initialize (in Unicode); may be NULL
   *
   *    newRef:
   *      A pointer to the FSRef for the new file; may be NULL
   *
   *    newSpec:
   *      A pointer to the FSSpec for the new directory; may be NULL
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSCreateResourceFile(const FSRef *parentRef, UniCharCount nameLength,
                       const UniChar *name, FSCatalogInfoBitmap whichInfo,
                       const FSCatalogInfo *catalogInfo, // can be NULL                        UniCharCount forkNameLength,
                       const UniChar *forkName,          // can be NULL
                       FSRef *newRef,                    // can be NULL
                       FSSpec *newSpec);                 // can be NULL
  /**
   *  FSOpenResourceFile()
   *
   *  Summary:
   *    Opens the specified named fork as a resource fork.
   *
   *  Discussion:
   *    This function allows any named fork of a file to be used for
   *    storing resources.  Passing in a null forkname will result in the
   *    data fork being used.
   *
   *  Parameters:
   *
   *    ref:
   *      The file containing the fork to open
   *
   *    forkNameLength:
   *      The length of the fork name (in Unicode characters)
   *
   *    forkName:
   *      The name of the fork to open (in Unicode); may be NULL
   *
   *    permissions:
   *      The access (read and/or write) you want
   *
   *    refNum:
   *      On exit the reference number for accessing the open fork
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FSOpenResourceFile(const FSRef *ref, UniCharCount forkNameLength,
                     const UniChar *forkName, // can be NULL
                     SInt8 permissions, SInt16 *refNum);

  /**
      These typedefs were originally created for the Copland Resource Mangager
  */
  typedef short ResFileRefNum;
  typedef short ResID;
  typedef short ResAttributes;
  typedef short ResFileAttributes;

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
