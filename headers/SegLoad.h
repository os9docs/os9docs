/**
     \file       SegLoad.h

    \brief   Segment Loader Interfaces.

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __SEGLOAD__
#define __SEGLOAD__

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

#if TARGET_CPU_68K && !TARGET_RT_MAC_CFM || !TARGET_OS_MAC
   /**
      CountAppFiles, GetAppFiles, ClrAppFiles, GetAppParms, getappparms,
      and the AppFile data structure and enums are obsolete.
      They are still supported for writing old style 68K apps,
      but they are not supported for CFM-based apps.
      Use AppleEvents to determine which files are to be
      opened or printed from the Finder.
   */
   enum
   {
      appOpen = 0, // Open the Document (s)
      appPrint = 1 // Print the Document (s)
   };

   /**
   <pre>
    * \note <pre>The AppFile structure is used in calls to GetAppFiles . Or, if you want,
   you can parse the Finder information independently: The global variable
   AppParmHandle (at 0x0AEC) leads to a block of information as follows:
   File Action (word) 0=appOpen, 1=appPrint
   Count (word) Number of AppFile structures to follow
   AppFile 1 Information about first file (variable length)
   .
   .
   .
   AppFile n Information about last file
   Note that the data is packed. Each structure starting on the first
   even-numbered byte directly after the last character of the filename of the
   previous structure.
   </pre>
    * \copyright THINK Reference © 1991-1992 Symantec Corporation
   */
   struct AppFile
   {
      short vRefNum; /**< Volume or working directory*/
      OSType fType;  /**< File type, eg, 'TEXT' or 'MSWD', etc.*/
      Str fName;     /**< length-prefixed p-string of file*/
   } AppFile;        /**<  (data will probably be shorter)*/

   typedef struct AppFile AppFile;
#if CALL_NOT_IN_CARBON

   /**
   \brief Count selected files; determine Open or Print

   <pre>Call CountAppFiles to determine how many files the user had selected in the
Finder. This is the first step in determining which file or files the user wants
you to process and what the user wants you to do with it (them).
doWhatis the address of a short. Upon return, it contains one of the
following action codes (defined in SegmentLdr.h):
appOpen 0Open the file(s)
appPrint 1Print the file(s)
fileCntis the address of a short. Upon return, it contains the number of
files the user selected in the Finder before selecting Open or Print.
If the user double-clicked a document, fileCnt will return containing
a 1.
</pre>
* \returns <pre>none
</pre>
* \note <pre>After initializing the various managers, most applications will want to
follow these steps to determine what files the user wishes to open or print:
•Call CountAppFiles . If fileCnt =0, open a blank, untitled document.
Otherwise...
•Call GetAppFiles indexing from 1 through fileCnt. Use the returned
information to open or print each file. If you can't or don't want to process
the file, issue a CautionAlert .
•After opening or printing the file, call ClrAppFiles with the same index.
This system lets a user open one or more documents automatically.
Example
#include < SegLoad.h >
#include <stdio.h>
shortfileCnt, doWhat, index;
AppFile fileStuff;
char*cp = (char *)&fileStuff.ftype;  // ease handling of file type
   CountAppFiles(&doWhat, &fileCnt);
   for (index = 1; index <= fileCnt; index++)
   {
      GetAppFiles(index, &fileStuff);
      /* --- normally you'd open or print the file here ---
       */
   </ pre>
           * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                         *    \non_carbon_cfm not available *    \carbon_lib not available *    \mac_os_x not available *
                                                     /
                                                     void
                                                     CountAppFiles(short *message, short *count);

   /**
   \brief Get information about files selected in the Finder

   <pre>GetAppFiles obtains the filename, type, and volume of one of the files
selected by the user when the Finder started your application.
indexspecifies which file you want to query. It should range from 1 to the
fileCnt value obtained through a previous call to CountAppFiles .
fileStuff is the address of a 264-byte AppFile structure. Upon return, it
contains information about the index-th file selected when the Finder
started your application.
</pre>
* \returns <pre>none
</pre>
* \note <pre>When a user double-clicks a document whose FInfo.fdCreator field (see
GetFInfo ) contains your signature, your application will begin executing.
At that time, you should call CountAppFiles and use GetAppFiles to
obtain the information needed to open that document.
In the event that the user selected two or more of your documents, and then
selected Open from the Finder's File menu, you should call GetAppFiles
several times and open each of the selected documents. See CountAppFiles
for an example.
Note: The files are indexed in the order the user selected them.
See AppFile for a description of the information returned by this call.
GetAppParms returns a handle to a block of data that contains this same
application file information - in a slightly different form.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
    *    \non_carbon_cfm   not available
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
   void
   GetAppFiles(short index, AppFile *theFile);

   /**
   \brief Let the Finder know have processed a file

   <pre>via GetAppFiles , call ClrAppFiles to mark it as having been processed.
indexspecifies which file you want to "clear". It should range from 1 to
the fileCnt value obtained through a previous call to
CountAppFiles .
</pre>
* \returns <pre>none
</pre>
* \note <pre>ClrAppFiles simply clears (sets to 0) the ftype field of the index-th
AppFile structure. See CountAppFiles for an example of usage.
This function seems to have no effect whatsoever on how the Finder or
Segment Loader calls respond. However, you could use this function to help
make multiple passes at the file list. For instance, you could process all
'TEXT' files, followed by all files of a second type, and so forth. Once
cleared, the file's type won't match with any subsequently-compared type.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
    *    \non_carbon_cfm   not available
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
   void
   ClrAppFiles(short index);

   /**
   \brief Get application name, resource file reference, et.al.

   <pre>You can use GetAppParms to obtain your application's filename, your
resource fork's file reference number, and a handle. The handle leads to the list
of Finder file information about documents that were selected when your
program was launched.
apName is the address of a 32-byte buffer. Upon return, it is filled with a
length-prefixed pascal-style string containing the name of the
currently executing application.
resRefNum is the file reference number of the application resource file(fork).
You could use this to CloseResFile , UseResFile , FSRead, etc.
hParms is the address of a 4-byte Handle. Upon return, it will contain a
Handle leading to information about the files selected in the Finder
when your application was opened. The format of this data is
described in the AppFile topic.
</pre>
* \returns <pre>none
</pre>
* \note <pre>There are other ways to get information besides GetAppParms :
•You can get the fRefNum of your open resource file by calling
CurResFile early on.
•Use CountAppFiles and GetAppFiles to index easily through the Finder
information about documents you're supposed to process.
Furthermore, you can examine the global variables CurApName (at
0x0910), CurApRefNum (at 0x0900), and AppParmHandle (at 0x0AEC).
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
    *    \non_carbon_cfm   not available
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
   void
   GetAppParms(Str255 apName, short *apRefNum, Handle *apParam)
       ONEWORDINLINE(0xA9F5);

#endif // CALL_NOT_IN_CARBON

#if CALL_NOT_IN_CARBON
   /**
    *  getappparms()
    *

    *    \non_carbon_cfm   not available
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   void
   getappparms(char *apName, short *apRefNum, Handle *apParam);

#endif // CALL_NOT_IN_CARBON

#endif // TARGET_CPU_68K && !TARGET_RT_MAC_CFM || !TARGET_OS_MAC

/**
   Because PowerPC applications don©t have segments.
   But, in order to allow applications to not have conditionalized
   source code, UnloadSeg is macro'ed away for PowerPC.
*/
#if TARGET_CPU_68K
#if CALL_NOT_IN_CARBON
   /**
    *  UnloadSeg()
    *

    *    \non_carbon_cfm   not available
    *    \carbon_lib        not available
    *    \mac_os_x         not available
    */
   void
   UnloadSeg(void *routineAddr) ONEWORDINLINE(0xA9F1);

#endif // CALL_NOT_IN_CARBON

#else
#define UnloadSeg(x)
#endif // TARGET_CPU_68K

   // ExitToShell() has moved to Process.h

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

#endif // __SEGLOAD__
* /*/*/ * /