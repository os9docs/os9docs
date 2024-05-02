/**
     \file       FindByContent.h

    \brief   Public search interface for the Find by Content shared library

    \introduced_in  2.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1997-2001 by Apple Computer, Inc., all rights reserved.

   \ingroup Misc
   
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FINDBYCONTENT__
#define __FINDBYCONTENT__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __CFSTRING__
#include <CFString.h>
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
   ***************************************************************************
   Language constants used with FBCIndexItemsInLanguages: these numbers are bits
   in a 64-bit array that consists of two UInt32 words.  In the current
   implementation the low word is always 0, so values for the high word are
   given.  If both UInt32 words are 0, the default value of
   kDefaultLanguagesHighWord is used.
   ***************************************************************************
*/
enum {
  // languages that use the Roman character mapping  englishHighWord = (long)0x80000000,
  dutchHighWord = 0x40000000, // also Afrikaans  germanHighWord = 0x20000000,
  swedishHighWord = 0x10000000// also Afrikaans
  spanishHighWord = 0x04000000, // also Catalan  portugueseHighWord = 0x02000000,
  italianHighWord = 0x01000000,// also Norwegian
  frenchHighWord = 0x00800000,
  romanHighWord = 0x00400000,   // also Catalan
      0x00040000, // Central European languages not using Cyrillic  croatianHighWord = 0x00020000,
  turkishHighWord = 0x00010000,
  romanianHighWord = 0x00008000,
  greekHighWord = 0x00004000,// other languages using Roman alphabet
  cyrillicHighWord = 0x00002000, /// Languages that use other mappings
  gujuratiHighWord = 0x00000800,// also Faroese
  gurmukhiHighWord = 0x00000400,// also Yiddish
  japaneseHighWord = 0x00000200,// also Farsi, Urdu
  koreanHighWord = 0x00000100,
  kDefaultLanguage// Central European languages not using Cyrillic

/**
   ***************************************************************************
   Phase values
   These values are passed to the// all languages using Cyrillic
   the FBC code is doing.
   ***************************************************************************
*/
enum {
  // indexing phases  kFBCphIndexing = 0,
  kFBCphFlushing = 1,// sum of first 9
  kFBCphMerging = 2,
  kFBCphMakingIndexAccessor = 3,
  kFBCphCompacting = 4,
  kFBCphIndexWaiting = 5, // access phases  kFBCphSearching = 6,
  kFBCphMakingAccessAccessor = 7,
  kFBCphAccessWaiting = 8, // summarization  kFBCphSummarizing = 9,   // indexing or access  kFBCphIdle = 10,
  kFBCphCanceling = 11
};

/**
  // indexing phases
   Pointer types
   These point to memory allocated by the FBC shared library, and must be
   deallocated by calls that are defined below.
   ***************************************************************************
*/
// access phases
// A collection of state information for searchingtypedef struct OpaqueFBCSearchSession *FBCSearchSession;
// An ordinary C string (used for hit/doc terms)typedef char *FBCWordItem;
// An array of WordItemstyp// summarization
/**// indexing or access
   ***************************************************************************
   Callback function type for progress reporting and cancelation during
   searching and indexing.  The client's callback function should call
   WaitNextEvent; a "sleep" value of 1 is suggested.  If the callback function
   wants to cancel the current operation (indexing, search, or doc-terms
   retrieval) it should return true.
   ***************************************************************************
*/

typedef CALLBACK_API_C(Boolean, FBCCallbackProcPtr)(UInt16 phase,
                                                    float percentDone,
                                                    void *data);
// A collection of state information for searching
/**
// An ordinary C string (used for hit/doc terms)
 *
// An array of WordItems
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
FBCCallbackUPP
NewFBCCallbackUPP(FBCCallbackProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppFBCCallbackProcInfo = 0x00000F91
}; // 1_byte Func(2_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
inline FBCCallbackUPP NewFBCCallbackUPP(FBCCallbackProcPtr userRoutine) {
  return userRoutine;
}
#else
#define NewFBCCallbackUPP(userRoutine) (userRoutine)
#endif
#endif

/**
 *  DisposeFBCCallbackUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
DisposeFBCCallbackUPP(FBCCallbackUPP userUPP);
#if// 1_byte Func(2_bytes, 4_bytes, 4_bytes) 
#ifdef __cplusplus
inline void DisposeFBCCallbackUPP(FBCCallbackUPP) {}
#else
#define DisposeFBCCallbackUPP(userUPP)
#endif
#endif

/**
 *  InvokeFBCCallbackUPP()
 *
 *  Availability:
 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
InvokeFBCCallbackUPP(UInt16 phase, float percentDone, void *data,
                     FBCCallbackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline Boolean InvokeFBCCallbackUPP(UInt16 phase, float percentDone, void *data,
                                    FBCCallbackUPP userUPP) {
  return (*userUPP)(phase, percentDone, data);
}
#else
#define InvokeFBCCallbackUPP(phase, percentDone, data, userUPP)                \
  (*userUPP)(phase, percentDone, data)
#endif
#endif

/**
   ***************************************************************************
   Set the callback function for progress reporting and cancelation during
   searching and indexing, and set the amount of heap space to reserve for
   the client's use when FBC allocates memory.
   ***************************************************************************
*/
/**
 *  FBCSetCallback()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
FBCSetCallback(FBCCallbackUPP fn, void *data);

/**
 *  FBCSetHeapReservation()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
FBCSetHeapReservation(UInt32 bytes);

/**
   ***************************************************************************
   Find out whether a volume is indexed, the date & time of its last
   completed  update, and its physical size.
   ***************************************************************************
*/

/**
 *  FBCVolumeIsIndexed()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
FBCVolumeIsIndexed(SInt16 theVRefNum);

/**
 *  FBCVolumeIsRemote()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
FBCVolumeIsRemote(SInt16 theVRefNum);

/**
 *  FBCVolumeIndexTimeStamp()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCVolumeIndexTimeStamp(SInt16 theVRefNum, UInt32 *timeStamp);

/**
 *  FBCVolumeIndexPhysicalSize()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCVolumeIndexPhysicalSize(SInt16 theVRefNum, UInt32 *size);

/**
   ***************************************************************************
   Create & configure a search session
   ***************************************************************************
*/

/**
 *  FBCCreateSearchSession()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCCreateSearchSession(FBCSearchSession *searchSession);

/**
 *  FBCAddAllVolumesToSession()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCAddAllVolumesToSession(FBCSearchSession theSession, Boolean includeRemote);

/**
 *  FBCSetSessionVolumes()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCSetSessionVolumes(FBCSearchSession theSession, const SInt16 vRefNums[],
                     UInt16 numVolumes);

/**
 *  FBCAddVolumeToSession()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCAddVolumeToSession(FBCSearchSession theSession, SInt16 vRefNum);

/**
 *  FBCRemoveVolumeFromSession()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCRemoveVolumeFromSession(FBCSearchSession theSession, SInt16 vRefNum);

/**
 *  FBCGetSessionVolumeCount()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCGetSessionVolumeCount(FBCSearchSession theSession, UInt16 *count);

/**
 *  FBCGetSessionVolumes()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCGetSessionVolumes(FBCSearchSession theSession, SInt16 vRefNums[],
                     UInt16 *numVolumes);

/**
 *  FBCCloneSearchSession()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCCloneSearchSession(FBCSearchSession original, FBCSearchSession *clone);

/**
   ***************************************************************************
   Execute a search
   ***************************************************************************
*/

/**
 *  FBCDoQuerySearch()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCDoQuerySearch(FBCSearchSession theSession, char *queryText,
                 const FSSpec targetDirs[], UInt32 numTargets, UInt32 maxHits,
                 UInt32 maxHitWords);

/**
 *  FBCDoCFStringSearch()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCDoCFStringSearch(FBCSearchSession theSession, CFStringRef queryString,
                    const FSSpec targetDirs[], UInt32 numTargets,
                    UInt32 maxHits, UInt32 maxHitWords);

/**
 *  FBCDoExampleSearch()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCDoExampleSearch(FBCSearchSession theSession, const UInt32 *exampleHitNums,
                   UInt32 numExamples, const FSSpec targetDirs[],
                   UInt32 numTargets, UInt32 maxHits, UInt32 maxHitWords);

/**
 *  FBCBlindExampleSearch()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCBlindExampleSearch(FSSpec examples[], UInt32 numExamples,
                      const FSSpec targetDirs[], UInt32 numTargets,
                      UInt32 maxHits, UInt32 maxHitWords, Boolean allIndexes,
                      Boolean includeRemote, FBCSearchSession *theSession);

/**
   ***************************************************************************
   Get information about hits [wrapper for THitItem C++ API]
   ***************************************************************************
*/

/**
 *  FBCGetHitCount()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCGetHitCount(FBCSearchSession theSession, UInt32 *count);

/**
 *  FBCGetHitDocument()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCGetHitDocument(FBCSearchSession theSession, UInt32 hitNumber,
                  FSSpec *theDocument);

/**
 *  FBCGetHitDocumentRef()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCGetHitDocumentRef(FBCSearchSession theSession, UInt32 hitNumber,
                     FSRef *theDocument);

/**
 *  FBCGetHitScore()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCGetHitScore(FBCSearchSession theSession, UInt32 hitNumber, float *score);

/**
 *  FBCGetMatchedWords()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCGetMatchedWords(FBCSearchSession theSession, UInt32 hitNumber,
                   UInt32 *wordCount, FBCWordList *list);

/**
 *  FBCGetTopicWords()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCGetTopicWords(FBCSearchSession theSession, UInt32 hitNumber,
                 UInt32 *wordCount, FBCWordList *list);

/**
   ***************************************************************************
   Summarize a buffer of text
   ***************************************************************************
*/

/**
 *  FBCSummarize()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCSummarize(void *inBuf, UInt32 inLength, void *outBuf, UInt32 *outLength,
             UInt32 *numSentences);

/**
   ***************************************************************************
   Deallocate hit lists, word arrays, and search sessions
   ***************************************************************************
*/

/**
 *  FBCReleaseSessionHits()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCReleaseSessionHits(FBCSearchSession theSession);

/**
 *  FBCDestroyWordList()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCDestroyWordList(FBCWordList theList, UInt32 wordCount);

/**
 *  FBCDestroySearchSession()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCDestroySearchSession(FBCSearchSession theSession);

/**
   ***************************************************************************
   Index one or more files and/or folders
   ***************************************************************************
*/

/**
 *  FBCIndexItems()
 *
 *  Availability:
 *    \non_carbon_cfm   in FindByContent 9.0 and later
 *    \carbon_lib        not available in CarbonLib 1.x
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCIndexItems(FSSpecArrayPtr theItems, UInt32 itemCount);

/**
 *  FBCIndexItemsInLanguages()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCIndexItemsInLanguages(FSSpecArrayPtr theItems, UInt32 itemCount,
                         UInt32 languageHighBits, UInt32 languageLowBits);

/**
   ***************************************************************************
   (OS X only) Given a folder, find the folder that contains the index file
   of the given index
   ***************************************************************************
*/

/**
 *  FBCFindIndexFileFolderForFolder()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCFindIndexFileFolderForFolder(FSRef *inFolder, FSRef *outFolder);

/**
   ***************************************************************************
   (OS X only) Given a folder, delete the index file that indexes it
   ***************************************************************************
*/

/**
 *  FBCDeleteIndexFileForFolder()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
FBCDeleteIndexFileForFolder(const FSRef *folder);

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

#endif // __FINDBYCONTENT__ // __FINDBYCONTENT__ 
