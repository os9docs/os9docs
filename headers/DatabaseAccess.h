/**
     \file       DatabaseAccess.h

    \brief   Database Access Manager Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1989-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Managers
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DATABASEACCESS__
#define __DATABASEACCESS__

#ifndef __RESOURCES__
#include <Resources.h>
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

/** data type codes */
enum {
  typeNone = FOUR_CHAR_CODE('none'),
  typeDate = FOUR_CHAR_CODE('date'),
  typeTime = FOUR_CHAR_CODE('time'),
  typeTimeStamp = FOUR_CHAR_CODE('tims'),
  typeDecimal = FOUR_CHAR_CODE('deci'),
  typeMoney = FOUR_CHAR_CODE('mone'),
  typeVChar = FOUR_CHAR_CODE('vcha'),
  typeVBin = FOUR_CHAR_CODE('vbin'),
  typeLChar = FOUR_CHAR_CODE('lcha'),
  typeLBin = FOUR_CHAR_CODE('lbin'),
  typeDiscard = FOUR_CHAR_CODE('disc'), /** "dummy" types for DBResultsToText */
  typeUnknown = FOUR_CHAR_CODE('unkn'),
  typeColBreak = FOUR_CHAR_CODE('colb'),
  typeRowBreak =
      FOUR_CHAR_CODE('rowb'), /** pass this in to DBGetItem for any data type */
  typeAnyType = 0
};

/** infinite timeout value for DBGetItem */
enum {
  /** messages for status functions for DBStartQuery */
  kDBUpdateWind = 0,
  kDBAboutToInit = 1,
  kDBInitComplete = 2,
  kDBSendComplete = 3,
  kDBExecComplete = 4,
  kDBStartQueryComplete = 5
};

enum {
  /** messages for status functions for DBGetQueryResults */
  kDBGetItemComplete = 6,
  kDBGetQueryResultsComplete = 7,
  kDBWaitForever = -1
};

enum {
  /**  flags for DBGetItem  */
  kDBLastColFlag = 0x0001,
  kDBNullFlag = 0x0004
};

typedef OSType DBType;
typedef struct DBAsyncParamBlockRec DBAsyncParamBlockRec;
typedef DBAsyncParamBlockRec *DBAsyncParmBlkPtr;
typedef CALLBACK_API_REGISTER68K(void, DBCompletionProcPtr,
                                 (DBAsyncParmBlkPtr pb));
typedef REGISTER_UPP_TYPE(DBCompletionProcPtr) DBCompletionUPP;
/** structure for asynchronous parameter block */
/**
<pre>The completionProc field is a pointer to a completion routine that the database
extension calls when it has completed executing the asynchronous function.
Before calling the completion routine, the
Data Access Manager places a pointer to the asynchronous parameter
block in the A0 register. If you do not want to use a completion routine, set this
parameter to NIL.
The database extension sets the result field to 1 while the routine is
executing, and places the result code in it when the routine completes. Your
application can poll this field to determine when an asynchronous routine has
completed execution.
The userRef field is reserved for the application's use. Because the
Data Access Manager passes a pointer to the parameter block to the
completion routine, you can use this field to pass information to the completion
routine.
The ddevRef field is reserved for use by the database extension, and the
reserved field is reserved for use by the Data Access Manager .
You can use the DBKill function to cancel an asynchronous routine.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct DBAsyncParamBlockRec  {
	ProcPtr completionProc;/**< pointer to completion routine*/
	OSErr result;/**< result of call*/
	long userRef;/**< for application's use*/
	long ddevRef;/**< for ddev's use*/
	long reserved;/**< for internal use*/


/** structure for resource list in QueryRecord */
/**
<pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct ResListElem  {
	ResType theType;/**< resource type*/
	short id;/**< resource ID*/
	} ResListElem ;/**< */

typedef struct ResListElem ResListElem;
typedef ResListElem *ResListPtr;
typedef ResListPtr *ResListHandle;
/** structure for query list in QueryRecord */
typedef Handle QueryArray[256];
typedef Handle *QueryListPtr;
typedef QueryListPtr *QueryListHandle;
/**
<pre><table><tbody>
<tr>
	<td>version</td>
	<td><pre>The version number of the QueryRecord format. For
Data Access Manager released with system
version 7.0, the version number is 0.
	</pre></td>
</tr>

<tr>
	<td>id</td>
	<td><pre>The resource ID of the 'qrsc' resource from which the
Access Manager created this QueryRecord .
	</pre></td>
</tr>

<tr>
	<td>queryProc</td>
	<td><pre>A handle to the query definition function that the
 function calls. This handle is NIL if
is no query definition function-that is, if the
 function should send the query
by this QueryRecord to the data server
modifications.
	</pre></td>
</tr>

<tr>
	<td>ddevName</td>
	<td><pre>The database extension name used as a parameter to the
function.
	</pre></td>
</tr>

<tr>
	<td>host</td>
	<td><pre>The name of the host computer system used as a
to the DBInit function.
	</pre></td>
</tr>

<tr>
	<td>user</td>
	<td><pre>The name of the user, used as a parameter to the
function.
	</pre></td>
</tr>

<tr>
	<td>password</td>
	<td><pre>The user's password, used as a parameter to the
function.
	</pre></td>
</tr>

<tr>
	<td>connStr</td>
	<td><pre>The connection string used as a parameter to the
function.
	</pre></td>
</tr>

<tr>
	<td>currQuery</td>
	<td><pre>An index value from 1 through numQueries , indicating
Reference © 1991-1992 Symantec Corporation
	</pre></td>
</tr>
</tbody></table>*/
struct QueryRecord  {
	short version;/**< version*/
	short id;/**< id of 'qrsc' this came from*/
	Handle queryProc;/**< handle to query def proc*/
	Str ddevName;/**< ddev name*/
	Str host;/**< host*/
	Str user;/**< user*/
	Str password;/**< password*/
	Str connStr;/**< connection string*/
	short currQuery;/**< current query*/
	short numQueries;/**< number of queries in queryList*/
	QueryListHandle queryList;/**< handle to list of queries*/
	short numRes;/**< number of resources in resList*/
	ResListHandle resList;/**< handle to list of other resources*/
	Handle dataHandle;/**< data used by query def proc*/
	long refCon;/**< query's reference value*/
	} QueryRecord ;/**< */

typedef struct QueryRecord QueryRecord;
typedef QueryRecord *QueryPtr;
typedef QueryPtr *QueryHandle;
/** structure of column types array in ResultsRecord */
typedef DBType ColTypesArray[256];
typedef Handle ColTypesHandle;
/** structure for column info in ResultsRecord */
/**
<pre>The len field indicates the length of the data item. The DBGetQueryResults
function returns a value in this field only for those data types that do not have
implied lengths; see the Table above.
The places field indicates the number of decimal places in data items of types
typeMoney and typeDecimal . For all other data types, the places field returns
0.
The least significant bit of the flags field is set to 1 if the data item is in the
last column of the row. The third bit of the flags field is 1 if the data item is
NULL. You can use the constants kDBLastColFlag and kDBNullFlag to test for
these flag bits.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct DBColInfoRecord  {
	short len;/**< length of data item*/
	short places;/**< places for decimal and money data*/
	short flags;/**< flags for data item*/
	}DBColInfoRecord ;/**< */

typedef struct DBColInfoRecord DBColInfoRecord;
typedef DBColInfoRecord ColInfoArray[256];
typedef Handle ColInfoHandle;
/** structure of results returned by DBGetResults */
/**
<pre>The numRows field in the ResultsRecord indicates the total number of rows
retrieved. If the DBGetQueryResults function returns a result code other
than rcDBValue , then not all of the data actually returned by the data source
was retrieved. This could happen, for instance, if the user's computer does not
have sufficient memory space to hold all the data. In this case, your application
can make more space available (by writing the data in the data record to disk,
for example) and then call the DBGetQueryResults function again to
complete retrieval of the data.
Note: The DBGetQueryResults function retrieves whole rows
only; if it runs out of space in the middle of a row, it stores the
partial row in a private buffer so that the data in the
ResultsRecord ends with the last complete row. Because the last
partial row is no longer available from the data server, you cannot
start to retrieve data with the DBGetQueryResults function and
then switch to the DBGetItem function to complete the data
retrieval.
The numCols field indicates the number of columns in each row of data.
The colTypes field is a handle to an array of data types, specifying the type of
data in each column. The number of elements in the array is equal to the value
in the numCols parameter.
The colData field is a handle to the data retrieved by the
DBGetQueryResults function.
The colInfo field is a handle to an array of records of type
DBColInfoRecord , each of which specifies the length, places, and flags for a
data item. There are as many records in the array as there are data items
retrieved by the DBGetQueryResults function.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct ResultsRecord  {
	short numRows;/**< number of rows in result*/
	short numCols;/**< number of columns per row*/
	Handle colTypes;/**< data type array*/
	Handle colData;/**< actual results*/
	Handle colInfo;/**< DBColInfoRecord  array*/
	}ResultsRecord  ;/**< */

typedef struct ResultsRecord ResultsRecord;
enum {
  /** messages sent to a 'ddev'*/
  kDBInit = 0,
  kDBEnd = 1,
  kDBGetConnInfo = 2,
  kDBGetSessionNum = 3,
  kDBSend = 4,
  kDBSendItem = 5,
  kDBExec = 6,
  kDBState = 7,
  kDBGetErr = 8,
  kDBBreak = 9,
  kDBGetItem = 10,
  kDBUngetItem = 11,
  kDBKill = 12,
  kDBOpen = 100,
  kDBClose = 101,
  kDBIdle = 102
};

typedef CALLBACK_API(OSErr, DBQueryDefProcPtr)(long *sessID, QueryHandle query);
typedef CALLBACK_API(Boolean, DBStatusProcPtr)(short message, OSErr result,
                                               short dataLen, short dataPlaces,
                                               short dataFlags, DBType dataType,
                                               Ptr dataPtr);
typedef CALLBACK_API(OSErr,
                     DBResultHandlerProcPtr)(DBType dataType, short theLen,
                                             short thePlaces, short theFlags,
                                             Ptr theData, Handle theText);
typedef STACK_UPP_TYPE(DBQueryDefProcPtr) DBQueryDefUPP;
typedef STACK_UPP_TYPE(DBStatusProcPtr) DBStatusUPP;
typedef STACK_UPP_TYPE(DBResultHandlerProcPtr) DBResultHandlerUPP;
#if CALL_NOT_IN_CARBON
/**
 *  NewDBCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
DBCompletionUPP
NewDBCompletionUPP(DBCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppDBCompletionProcInfo = 0x0000B802
}; /** register no_return_value Func(4_bytes:A1) */
#ifdef __cplusplus
inline DBCompletionUPP NewDBCompletionUPP(DBCompletionProcPtr userRoutine) {
  return (DBCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                               uppDBCompletionProcInfo,
                                               GetCurrentArchitecture());
}
#else
#define NewDBCompletionUPP(userRoutine)                                        \
  (DBCompletionUPP)                                                            \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppDBCompletionProcInfo,    \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  NewDBQueryDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
DBQueryDefUPP
NewDBQueryDefUPP(DBQueryDefProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppDBQueryDefProcInfo = 0x000003E0
}; /** pascal 2_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
inline DBQueryDefUPP NewDBQueryDefUPP(DBQueryDefProcPtr userRoutine) {
  return (DBQueryDefUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppDBQueryDefProcInfo, GetCurrentArchitecture());
}
#else
#define NewDBQueryDefUPP(userRoutine)                                          \
  (DBQueryDefUPP) NewRoutineDescriptor(                                        \
      (ProcPtr)(userRoutine), uppDBQueryDefProcInfo, GetCurrentArchitecture())
#endif
#endif

/**
 *  NewDBStatusUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
DBStatusUPP
NewDBStatusUPP(DBStatusProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppDBStatusProcInfo = 0x000FAA90
}; /** pascal 1_byte Func(2_bytes, 2_bytes, 2_bytes, 2_bytes, 2_bytes, 4_bytes,
      4_bytes) */
#ifdef __cplusplus
inline DBStatusUPP NewDBStatusUPP(DBStatusProcPtr userRoutine) {
  return (DBStatusUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppDBStatusProcInfo, GetCurrentArchitecture());
}
#else
#define NewDBStatusUPP(userRoutine)                                            \
  (DBStatusUPP) NewRoutineDescriptor(                                          \
      (ProcPtr)(userRoutine), uppDBStatusProcInfo, GetCurrentArchitecture())
#endif
#endif

/**
 *  NewDBResultHandlerUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
DBResultHandlerUPP
NewDBResultHandlerUPP(DBResultHandlerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppDBResultHandlerProcInfo = 0x0003EAE0
}; /** pascal 2_bytes Func(4_bytes, 2_bytes, 2_bytes, 2_bytes, 4_bytes, 4_bytes)
    */
#ifdef __cplusplus
inline DBResultHandlerUPP
NewDBResultHandlerUPP(DBResultHandlerProcPtr userRoutine) {
  return (DBResultHandlerUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppDBResultHandlerProcInfo,
                                                  GetCurrentArchitecture());
}
#else
#define NewDBResultHandlerUPP(userRoutine)                                     \
  (DBResultHandlerUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppDBResultHandlerProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeDBCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeDBCompletionUPP(DBCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeDBCompletionUPP(DBCompletionUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeDBCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeDBQueryDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeDBQueryDefUPP(DBQueryDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeDBQueryDefUPP(DBQueryDefUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeDBQueryDefUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeDBStatusUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeDBStatusUPP(DBStatusUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeDBStatusUPP(DBStatusUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeDBStatusUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeDBResultHandlerUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeDBResultHandlerUPP(DBResultHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeDBResultHandlerUPP(DBResultHandlerUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeDBResultHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeDBCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeDBCompletionUPP(__A1, __A0)
#endif
void
InvokeDBCompletionUPP(DBAsyncParmBlkPtr pb, DBCompletionUPP userUPP)
    ONEWORDINLINE(0x4E90);
#if !OPAQUE_UPP_TYPES &&                                                       \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
inline void InvokeDBCompletionUPP(DBAsyncParmBlkPtr pb,
                                  DBCompletionUPP userUPP) {
  CALL_ONE_PARAMETER_UPP(userUPP, uppDBCompletionProcInfo, pb);
}
#else
#define InvokeDBCompletionUPP(pb, userUPP)                                     \
  CALL_ONE_PARAMETER_UPP((userUPP), uppDBCompletionProcInfo, (pb))
#endif
#endif

/**
 *  InvokeDBQueryDefUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InvokeDBQueryDefUPP(long *sessID, QueryHandle query, DBQueryDefUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline OSErr InvokeDBQueryDefUPP(long *sessID, QueryHandle query,
                                 DBQueryDefUPP userUPP) {
  return (OSErr)CALL_TWO_PARAMETER_UPP(userUPP, uppDBQueryDefProcInfo, sessID,
                                       query);
}
#else
#define InvokeDBQueryDefUPP(sessID, query, userUPP)                            \
  (OSErr) CALL_TWO_PARAMETER_UPP((userUPP), uppDBQueryDefProcInfo, (sessID),   \
                                 (query))
#endif
#endif

/**
 *  InvokeDBStatusUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
InvokeDBStatusUPP(short message, OSErr result, short dataLen, short dataPlaces,
                  short dataFlags, DBType dataType, Ptr dataPtr,
                  DBStatusUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline Boolean InvokeDBStatusUPP(short message, OSErr result, short dataLen,
                                 short dataPlaces, short dataFlags,
                                 DBType dataType, Ptr dataPtr,
                                 DBStatusUPP userUPP) {
  return (Boolean)CALL_SEVEN_PARAMETER_UPP(userUPP, uppDBStatusProcInfo,
                                           message, result, dataLen, dataPlaces,
                                           dataFlags, dataType, dataPtr);
}
#else
#define InvokeDBStatusUPP(message, result, dataLen, dataPlaces, dataFlags,     \
                          dataType, dataPtr, userUPP)                          \
  (Boolean) CALL_SEVEN_PARAMETER_UPP(                                          \
      (userUPP), uppDBStatusProcInfo, (message), (result), (dataLen),          \
      (dataPlaces), (dataFlags), (dataType), (dataPtr))
#endif
#endif

/**
 *  InvokeDBResultHandlerUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InvokeDBResultHandlerUPP(DBType dataType, short theLen, short thePlaces,
                         short theFlags, Ptr theData, Handle theText,
                         DBResultHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline OSErr InvokeDBResultHandlerUPP(DBType dataType, short theLen,
                                      short thePlaces, short theFlags,
                                      Ptr theData, Handle theText,
                                      DBResultHandlerUPP userUPP) {
  return (OSErr)CALL_SIX_PARAMETER_UPP(userUPP, uppDBResultHandlerProcInfo,
                                       dataType, theLen, thePlaces, theFlags,
                                       theData, theText);
}
#else
#define InvokeDBResultHandlerUPP(dataType, theLen, thePlaces, theFlags,        \
                                 theData, theText, userUPP)                    \
  (OSErr) CALL_SIX_PARAMETER_UPP((userUPP), uppDBResultHandlerProcInfo,        \
                                 (dataType), (theLen), (thePlaces),            \
                                 (theFlags), (theData), (theText))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewDBCompletionProc(userRoutine) NewDBCompletionUPP(userRoutine)
#define NewDBQueryDefProc(userRoutine) NewDBQueryDefUPP(userRoutine)
#define NewDBStatusProc(userRoutine) NewDBStatusUPP(userRoutine)
#define NewDBResultHandlerProc(userRoutine) NewDBResultHandlerUPP(userRoutine)
#define CallDBCompletionProc(userRoutine, pb)                                  \
  InvokeDBCompletionUPP(pb, userRoutine)
#define CallDBQueryDefProc(userRoutine, sessID, query)                         \
  InvokeDBQueryDefUPP(sessID, query, userRoutine)
#define CallDBStatusProc(userRoutine, message, result, dataLen, dataPlaces,    \
                         dataFlags, dataType, dataPtr)                         \
  InvokeDBStatusUPP(message, result, dataLen, dataPlaces, dataFlags, dataType, \
                    dataPtr, userRoutine)
#define CallDBResultHandlerProc(userRoutine, dataType, theLen, thePlaces,      \
                                theFlags, theData, theText)                    \
  InvokeDBResultHandlerUPP(dataType, theLen, thePlaces, theFlags, theData,     \
                           theText, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  InitDBPack()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
InitDBPack(void) FIVEWORDINLINE(0x3F3C, 0x0004, 0x303C, 0x0100, 0xA82F);

/**
 *  DBInit()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBInit(long *sessID, ConstStr63Param ddevName, ConstStr255Param host,
       ConstStr255Param user, ConstStr255Param passwd, ConstStr255Param connStr,
       DBAsyncParmBlkPtr asyncPB) THREEWORDINLINE(0x303C, 0x0E02, 0xA82F);

/**
 *  DBEnd()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBEnd(long sessID, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x0403, 0xA82F);

/**
 *  DBGetConnInfo()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBGetConnInfo(long sessID, short sessNum, long *returnedID, long *version,
              Str63 ddevName, Str255 host, Str255 user, Str255 network,
              Str255 connStr, long *start, OSErr *state,
              DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x1704, 0xA82F);

/**
 *  DBGetSessionNum()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBGetSessionNum(long sessID, short *sessNum, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x0605, 0xA82F);

/**
 *  DBSend()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBSend(long sessID, Ptr text, short len, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x0706, 0xA82F);

/**
 *  DBSendItem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBSendItem(long sessID, DBType dataType, short len, short places, short flags,
           void *buffer, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x0B07, 0xA82F);

/**
 *  DBExec()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBExec(long sessID, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x0408, 0xA82F);

/**
 *  DBState()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBState(long sessID, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x0409, 0xA82F);

/**
 *  DBGetErr()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBGetErr(long sessID, long *err1, long *err2, Str255 item1, Str255 item2,
         Str255 errorMsg, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x0E0A, 0xA82F);

/**
 *  DBBreak()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBBreak(long sessID, Boolean abort, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x050B, 0xA82F);

/**
 *  DBGetItem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBGetItem(long sessID, long timeout, DBType *dataType, short *len,
          short *places, short *flags, void *buffer, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x100C, 0xA82F);

/**
 *  DBUnGetItem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBUnGetItem(long sessID, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x040D, 0xA82F);

/**
 *  DBKill()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBKill(DBAsyncParmBlkPtr asyncPB) THREEWORDINLINE(0x303C, 0x020E, 0xA82F);

/**
 *  DBGetNewQuery()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBGetNewQuery(short queryID, QueryHandle *query)
    THREEWORDINLINE(0x303C, 0x030F, 0xA82F);

/**
 *  DBDisposeQuery()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBDisposeQuery(QueryHandle query) THREEWORDINLINE(0x303C, 0x0210, 0xA82F);

/**
 *  DBStartQuery()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBStartQuery(long *sessID, QueryHandle query, DBStatusUPP statusProc,
             DBAsyncParmBlkPtr asyncPB) THREEWORDINLINE(0x303C, 0x0811, 0xA82F);

/**
 *  DBGetQueryResults()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBGetQueryResults(long sessID, ResultsRecord *results, long timeout,
                  DBStatusUPP statusProc, DBAsyncParmBlkPtr asyncPB)
    THREEWORDINLINE(0x303C, 0x0A12, 0xA82F);

/**
 *  DBResultsToText()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBResultsToText(ResultsRecord *results, Handle *theText)
    THREEWORDINLINE(0x303C, 0x0413, 0xA82F);

/**
 *  DBInstallResultHandler()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBInstallResultHandler(DBType dataType, DBResultHandlerUPP theHandler,
                       Boolean isSysHandler)
    THREEWORDINLINE(0x303C, 0x0514, 0xA82F);

/**
 *  DBRemoveResultHandler()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBRemoveResultHandler(DBType dataType) THREEWORDINLINE(0x303C, 0x0215, 0xA82F);

/**
 *  DBGetResultHandler()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBGetResultHandler(DBType dataType, DBResultHandlerUPP *theHandler,
                   Boolean getSysHandler)
    THREEWORDINLINE(0x303C, 0x0516, 0xA82F);

/**
 *  DBIdle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
DBIdle(void) THREEWORDINLINE(0x303C, 0x00FF, 0xA82F);

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

#endif /** __DATABASEACCESS__ */
__ */
