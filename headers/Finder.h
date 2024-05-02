/**
     \file       Finder.h

    \brief   Finder flags and container types.

    \introduced_in  Mac OS 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup File

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FINDER__
#define __FINDER__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

  // Creator and type of clipping files enum {
  kClippingCreator = FOUR_CHAR_CODE('drag'),
  kClippingPictureType = FOUR_CHAR_CODE('clpp'),
  kClippingTextType = FOUR_CHAR_CODE('clpt'),
  kClippingSoundType = FOUR_CHAR_CODE('clps'),
  kClippingUnknownType = FOUR_CHAR_CODE('clpu')
};

// Creator and type of Internet Location files enum {
// Creator and type of Internet Location files
kInternetLocationHTTP = FOUR_CHAR_CODE('ilht'),
    kInternetLocationFTP = FOUR_CHAR_CODE('ilft'),
    kInternetLocationFile = FOUR_CHAR_CODE('ilfi'),
    kInternetLocationMail = FOUR_CHAR_CODE('ilma'),
    kInternetLocationNNTP = FOUR_CHAR_CODE('ilnw'),
    kInternetLocationAFP = FOUR_CHAR_CODE('ilaf'),
    kInternetLocationAppleTalk = FOUR_CHAR_CODE('ilat'),
    kInternetLocationNSL = FOUR_CHAR_CODE('ilns'),
    kInternetLocationGeneric = FOUR_CHAR_CODE('ilge')
}
;

enum {
  kCustomIconResource = -16455 // Custom icon family resource ID };

// In order to specify any of t// Custom icon family resource ID 
 * kExtendedFlagsAreInvalid */
/* and set kExtendedFlagHasCustomBadge of the FXInfo.fdXFlags or DXInfo.frXFlags
// In order to specify any of the information described in the 
/* and add a resource of type kCustomBadgeResourceType and ID
 * kCustomBadgeResourceID to */
// the file or to the "Icon/n" file for a folder enum {
  kCustomBadgeResourceType = FOUR_CHAR_CODE('badg'),
  kCustomBadgeResourceID = kCustomIconResource,
  kCustomBadgeResourceVersion = 0
// the file or to the "Icon/n" file for a folder 

struct CustomBadgeResource {
  SInt16 version; // This is version kCustomBadgeResourceVersion  SInt16
      customBadgeResourceID; // If not 0, the ID of a resource to use on top                             // of the icon for this file or folder  OSType customBadgeType;    // If not 0, the type and creator of an icon  OSType customBadgeCreator; // to use on top of the icon  OSType windowBadgeType;    // If not 0, the type and creator of an icon  OSType
      windowBadgeCreator; // to display in the header of the window for this                           // file or folder  OSType overrideType;    // If not 0, the type and creator of an icon to  OSType overrideCreator; // use INSTEAD of the icon for this file or folder};
typedef struct CustomBadgeResource CustomBadgeResource;
typedef CustomBadgeResource *CustomBadgeResourcePtr;
typedef CustomBadg// This is version kCustomBadgeResourceVersion
/* You can specify routing information for a file by including a 'rout' 0
    resource in it and settin// If not 0, the ID of a resource to use on top
   extended Finder flags. The// of the icon for this file or folder
   RoutingResourceEntry. Each// If not 0, the type and creator of an icon
   entry is used. If the crea// to use on top of the icon
   targetFolder match the fol// If not 0, the type and creator of an icon
   file is rerouted into the specified destination folder. The only target
   folder currently suppor// to display in the header of the window for this 
*/// file or folder
enum { kRoutingResourceTyp// If not 0, the type and creator of an icon to
// use INSTEAD of the icon for this file or folder
struct RoutingResourceEntry {
  OSType creator;      // Use '****' or 0 to match any creator   OSType fileType;     // Use '****' or 0 to match any file type   OSType targetFolder; // Folder ID of the folder this file was dropped onto   OSType destinationFolder; // Folder that the source will be routed to   OSType reservedField;     // Set to 0 };
typedef struct RoutingResourceEntry RoutingResourceEntry;
typedef RoutingResourceEntry *RoutingResourcePtr;
typedef RoutingResourcePtr *RoutingResourceHandle;

// Types for special container aliases enum {
  kContainerFolderAliasType =
      FOUR_CHAR_CODE('fdrp'), // type for folder aliases   kContainerTrashAliasType =
      FOUR_CHAR_CODE('trsh'), // type for trash folder aliases   kContainerHardDiskAliasType =
      FOUR_CHAR_CODE('hdsk'), // type for hard disk aliases   kContainerFloppyAliasType =
      FOUR_CHAR_CODE('flpy'), // type for floppy aliases   kContainerServerAliasType =
      FOUR_CHAR_CODE('srvr'), // type for server aliases   kApplicationAliasType =
      FOUR_CHAR_CODE('adrp'), // type for application aliases   kContainerAliasType =
      FOUR_CHAR_CODE('drop'), // type for all other containers   kDesktopPrinterAliasType =
      FOUR_CHAR_CODE('dtpa'), // type for Desktop Printer alias   kContainerCDROMAliasType = FOUR_CHAR_CODE('cddr'), // type for CD-ROM alias   kApplicationCPAliasType =
      FOUR_CHAR_CODE('a// Use '****' or 0 to match any creator 
      FOUR_CHAR_CODE('a// Use '****' or 0 to match any file type 
      FOUR_CHAR_CODE('f// Folder ID of the folder this file was dropped onto 
// Folder that the source will be routed to 
// Types for Special folder // Set to 0 
  kSystemFolderAliasType = FOUR_CHAR_CODE('fasy'),
  kAppleMenuFolderAliasType = FOUR_CHAR_CODE('faam'),
  kStartupFolderAliasType = FOUR_CHAR_CODE('fast'),
  kPrintMonitorDocsFolderAliasType = FOUR_CHAR_CODE('fapn'),
  kPreferencesFolderAliasType = FOUR_CHAR_CODE('fapf'),
// Types for special container aliases 
  kExtensionFolderAliasType = FOUR_CHAR_CODE('faex')
};
// type for folder aliases
// Types for AppleShare folder aliases enum {
kExportedFolderAliasType = F // type for trash folder aliases
    kDropFolderAliasType = FOUR_CHAR_CODE('fadr'),
    kSharedFolderAliasType = FOU // type for hard disk aliases
        kMountedFolderAliasType = FOUR_CHAR_CODE('famn')
}
; // type for floppy aliases

// Finder flags (finderFlags, // type for server aliases
 * ioDirMask) == 0) */
enum {// type for application aliases 
  kIsOnDesk = 0x0001, // Files and folders (System 6)   kColor = 0x000E,    // Files and folders   // bit 0x0020 was kRequireSwitchLaunch, but is now reserved for future use  kIsShared = 0x0040,      // Files only (Applications only)                            // If clear, the application needs to write to                            // its resource fork, and therefore cannot be                            // shared on a server   kHasNoINITs = 0x0080,    // Files only (Extensions/Control Panels only)                            // This file contains no INIT resource   kHasBeenInited = 0x0100, // Files only                            // Clear if the file contains desktop database                            // resources ('BNDL', 'FREF', 'open', 'kind'...)   // that have not been added yet. Set only by the Finder   // Reserved for folders - make sure this bit is cleared for folders   /* bit 0x0200 was the letter bit for AOCE, but is now reserved for future use
   */// type for all other containers 
  kHasCustomIcon = 0x0400, // Files and folders   kIsStationery = 0x0800,  // Files only   kNameLocked = 0x1000,    // Files and folders   kHasBundle = 0x2000,     // Files only   kIsInvisible = 0x4000,   // Files and folders   kIsAlias = 0x8000        // Files only };
// type for Desktop Printer alias 
// Obsolete. Use names defined above. enum {// type for CD-ROM alias 
  fOnDesk = kIsOnDesk,
  fHasBundle = kHasBundle,// type for application control panel alias 
  fInvisible = kIsInvisible
};// type for application DA alias
 // type for plain package alias
 // Obsolete enum { fTrash = -3, fDesktop = -2, fDisk = 0 };
 // type for application package alias
#if OLDROUTINENAMES
 enum
 {
   kIsStationary = kIsStationery
 };
 // Types for Special folder aliases
#endif // OLDROUTINENAMES
        // Extended flags (extendedFinderFlags, fdXFlags and frXFlags) // Any flag not specified should be set to 0. enum {
 kExtendedFlagsAreInvalid =
     0x8000, // If set the other extended flags are ignored   kExtendedFlagHasCustomBadge =
     0x0100, // Set if the file or folder has a badge resource   kExtendedFlagHasRoutingInfo =
     0x0004  // Set if the file contains routing info resource };

             // Use a filetype in this range to indicate that a file is temporarily busy // (while it is being downloaded or installed, for example).  This prevents // Finder 8.5 and later from trying to change the item's attributes before it /* is fully created. -- If you provide a series of 'BNDL' icons for your creator
             * /
         // and some of these filetypes, you can achieve limited icon animation while // the file creation progresses. enum {
         // Types for AppleShare folder aliases
         kLastMagicBusyFiletype = FOUR_CHAR_CODE('bzy?')
 }
 ;

 // Use this date as a file's or folder's creation date to indicate that it is // temporarily busy (while it is being downloaded or installed, for example). // This prevents Finder from trying to change the item's attributes before it /* is fully created (Finder 8.5 and 8.6 check file creation dates; later Finders
 */
// may check folder creation dates as well). enum { kMagicBusyCreationDate = 0x4F3AFDB0 };

// Finder flags (finderFlags, fdFlags and frFlags) 
// Any flag reserved or not specified should be set to 0. 
// If a flag applies to a file, but not to a folder, make sure to check 
   FXInfo and DXInfo but represent the Mac OS 8 semantic of the fields.
   Use these data structures preferably to FInfo, etc...
*/
/*--------------------// Files and folders (System 6) 
// Files and folders 
st// bit 0x0020 was kRequireSwitchLaunch, but is now reserved for future use
  OSType fileType;    // Th// Files only (Applications only) 
typedef struct FileInfo Fil// If clear, the application needs to write to 
struct FolderInfo {// its resource fork, and therefore cannot be 
  Rect windowBounds;  // Th// shared on a server 
typedef struct FolderInfo F// Files only (Extensions/Control Panels only) 
struct ExtendedFileInfo {// This file contains no INIT resource 
  SInt16 reserved1[4]; // R// Files only 
      extendedFinderFlags; // Clear if the file contains desktop database 
typedef struct ExtendedFile// resources ('BNDL', 'FREF', 'open', 'kind'...) 
st// that have not been added yet. Set only by the Finder 
  // Reserved for folders - make sure this bit is cleared for folders 
      extendedFinderFlags; // Extended flags (custom badge, routing info...)   SInt16 reserved2; // Reserved (set to 0). Comment ID if high-bit is clear   SInt32 putAwayFolderID; // Put away folder ID };
typedef struct ExtendedFolderInfo ExtendedFolderInfo;
/*-------------------------// Files and folders 
/**// Files only 
   The following data struc// Files and folders 
   Use the new data structu// Files only 
   instead of FInfo, etc...// Files and folders 
*/// Files only 
// ------------------------------------------------------------------------
// File info /**
// Obsolete. Use names defined above. 
     In MacOS 8, the fdFldr field has become reserved for the Finder.
*/
/**
<pre>
 * \note <pre>The fdType field helps applications figure out what to do with a file. It is
also used by SFGetFile et al. to let Standard File show a subset of files in a
// Obsolete 
text file) are standard types; others are defined by applications and can be
any 32-bit value.
The fdCreator field specifies which application should be executed when the
file's icon is double clicked. a value of '????' indicates it is not to be
opened that way. Other values identify the application by its
Apple-a// OLDROUTINENAMES 
The meaning of the flag bits in this structure have changed significantly
// Extended flags (extendedFinderFlags, fdXFlags and frXFlags) 
// Any flag not specified should be set to 0. 
The old fdFlags word is a set of bit flags, formatted as follows:
The new fdFlags word is a set of bit flags, formatted as follows:
</pre>// If set the other extended flags are ignored 
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/// Set if the file or folder has a badge resource 
struct FInfo
 {
   OSType fdTyp            // Set if the file contains routing info resource
       OSType fdCreator;   /**< File creator's signature;/**< eg,'MSWD'*/
   unsigned short fdFlags; /**< Flag bits used by Finder (see Notes)*/
   // Use a filetype in this range to indicate that a file is temporarily busy
   // (while it is being downloaded or installed, for example).  This prevents
   // Finder 8.5 and later from trying to change the item's attributes before it

   typedef struct FInfo FInfo;
   // and some of these filetypes, you can achieve limited icon animation while
   // the file creation progresses.
     In MacOS 8, the fdIconID and fdComment fields were changed
     to become reserved fields for the Finder.
     The fdScript has become an extended flag.
*/
/**
// Use this date as a file's or folder's creation date to indicate that it is 
// temporarily busy (while it is being downloaded or installed, for example). 
// This prevents Finder from trying to change the item's attributes before it 
PBSetCatInfo .
The fdIconID field may be related to icons in some indirect way. However,
// may check folder creation dates as well). 
The fdComment field contains the resource ID of an 'FCMT' in the Desktop
file. It identifies a p-string displayed/modified in the Finder's "Get Info"
menu item dialog.  See PBSetCatInfo for an example which changes a file's
comment.
The fdPutAway field is a 'hard' directory ID of the folder in which the file
is normally displayed. If the file gets moved to the desktop, the Finder uses
this field to implement its "Put Away" menu item.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct FXInfo
     {
       short fdIconID;        /**< F// The type of the file
               short fdUnused[];/**<// The file's creator
               char fdScript;/**< */
                              // ex: kHasBundle, kIsInvisible...
       char fdXFlags; /**< */ // File's location in the folder
       s                      // If set to {0, 0}, the Finder will place the item automatically
           long fdPutAway;    /**< Dir// (set to 0)
               } FXInfo;/**< */

       typedef struct FXInfo FXInfo;
       // Folder info /**// The position and dimension of the folder's window
       IMPORTANT : // ex. kIsInvisible, kNameLocked, etc.
                   In MacOS 8,
                   the f // Folder's location in the parent folder
                       // If set to {0, 0}, the Finder will place the item automatically
                       * /// (set to 0)
                   /**
                   <pre>
                    * \note <pre>A DInfo structure named ioDrUsrWds is embedded in the DirInfo structure
                   obtained by PBGetCatInf// Reserved (set to 0)
                   PBSetCatInfo .
                   The frFlags field has the s// Extended flags (custom badge, routing info...)
                   Many of the bits don// Reserved (set to 0). Comment ID if high-bit is clear
                   apply. See FInfo.// Put away folder ID
                   The frRect field identifies where the folder's window goes when the folder
                   is opened. Additional information is found in the FXInfo structure.
                   The content of the frView field is not documented, the high byte of this field
                   is one of:// Scroll position (for icon views)
                   1By Icon// Reserved (set to 0)
                   2By Name
                   3By Date// Extended flags (custom badge, routing info...)
                   4By Size// Reserved (set to 0). Comment ID if high-bit is clear
                   5By Kind// Put away folder ID
                   6By Color
                   Since the Finder performs its own internal caching, changes made to these
                   fields may not be noticed for some time (you may need to use the Finder's
                   Get Info command or manually close and reopen the the folder). Also, when
                   the Finder ejects a disk, it may overwrite your changes anyway.
                   </pre>
                    * \copyright THINK Reference © 1991-1992 Symantec Corporation
                   */
                   struct DInfo
       {
         // File info
         short frFlags;    /**< Bit flags (fOnDesk, et al.)  See FInfo*/
         Point frLocation; /**< Top-left corner for folder's icon*/
         short frView;     /**< Folder view*/
       } DInfo;            /**< */

       typedef struct DInfo DInfo;
       // Extended folder info /**
     IMPORTANT:
     In MacOS 8, the frOpenChain and frComment fields were changed
     to become reserved fields for the Finder.
     The frScript has become an extended flag.
*/
/**
<pre>
 * \note <pre>A DXInfo structure named ioDrFndrInfo is embedded in the DirInfo
structure obtained by PBGetCatInfo . Field values in it can be set via
PBSetCatInfo .
The frScroll field is the horizontal and vertical distance by which the
contents of the folder are currently scrolled.
The frComment field contains the resource ID of an 'FCMT' in the Desktop
file. It is a Pascal string which gets displayed/modified in the Finder's "Get
Info" menu item dialog.
The frPutAway field is a 'hard' directory ID of the folder in which this
folder is normally displayed. When a folder gets moved to the desktop, the
Finder uses this field to implement its "Put Away" menu item.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct DXInfo
     {
       Point frScroll;   /**< Currently scrolled by this horiz and*/
       long frOpenChain; /**< Directory ID in the chain of open*/
       short frUnused;   /**< (reserved)*/
                         // Extended file info
       long frPutAway;   /**< Dir ID of folder's home directory*/
     } DXInfo;           /**< */

     typedef struct DXInfo DXInfo;
     /* ControlPanelDefProcPtr and cdev constants have all been moved to
      * Processes.i*/

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

#endif // __FINDER__ // Folder info
     // Extended folder info
     // __FINDER__
