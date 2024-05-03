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

  /** data type codes */
  enum
  {
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
  enum
  {
    /** messages for status functions for DBStartQuery */
    kDBUpdateWind = 0,
    kDBAboutToInit = 1,
    kDBInitComplete = 2,
    kDBSendComplete = 3,
    kDBExecComplete = 4,
    kDBStartQueryComplete = 5
  };

  enum
  {
    /** messages for status functions for DBGetQueryResults */
    kDBGetItemComplete = 6,
    kDBGetQueryResultsComplete = 7,
    kDBWaitForever = -1
  };

  enum
  {
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
  struct DBAsyncParamBlockRec
  {
    DBCompletionUPP completionProc; /** pointer to completion routine */
    OSErr result;                   /** result of call */
    long userRef;                   /** for application's use */
    long ddevRef;                   /** for ddev's use */
    long reserved;                  /** for internal use */
  };

  /** structure for resource list in QueryRecord */
  struct ResListElem
  {
    ResType theType; /** resource type */
    short id;        /** resource id */
  };
  typedef struct ResListElem ResListElem;
  typedef ResListElem *ResListPtr;
  typedef ResListPtr *ResListHandle;
  /** structure for query list in QueryRecord */
  typedef Handle QueryArray[256];
  typedef Handle *QueryListPtr;
  typedef QueryListPtr *QueryListHandle;
  struct QueryRecord
  {
    short version;             /** version */
    short id;                  /** id of 'qrsc' this came from */
    Handle queryProc;          /** handle to query def proc */
    Str63 ddevName;            /** ddev name */
    Str255 host;               /** host name */
    Str255 user;               /** user name */
    Str255 password;           /** password */
    Str255 connStr;            /** connection string */
    short currQuery;           /** index of current query */
    short numQueries;          /** number of queries in list */
    QueryListHandle queryList; /** handle to array of handles to text */
    short numRes;              /** number of resources in list */
    ResListHandle resList;     /** handle to array of resource list elements */
    Handle dataHandle;         /** for use by query def proc */
    long refCon;               /** for use by application */
  };
  typedef struct QueryRecord QueryRecord;
  typedef QueryRecord *QueryPtr;
  typedef QueryPtr *QueryHandle;
  /** structure of column types array in ResultsRecord */
  typedef DBType ColTypesArray[256];
  typedef Handle ColTypesHandle;
  /** structure for column info in ResultsRecord */
  struct DBColInfoRecord
  {
    short len;
    short places;
    short flags;
  };
  typedef struct DBColInfoRecord DBColInfoRecord;
  typedef DBColInfoRecord ColInfoArray[256];
  typedef Handle ColInfoHandle;
  /** structure of results returned by DBGetResults */
  struct ResultsRecord
  {
    short numRows;           /** number of rows in result */
    short numCols;           /** number of columns per row */
    ColTypesHandle colTypes; /** data type array */
    Handle colData;          /** actual results */
    ColInfoHandle colInfo;   /** DBColInfoRecord array */
  };
  typedef struct ResultsRecord ResultsRecord;
  enum
  {
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
  enum
  {
    uppDBCompletionProcInfo = 0x0000B802
  }; /** register no_return_value Func(4_bytes:A1) */
#ifdef __cplusplus
  inline DBCompletionUPP NewDBCompletionUPP(DBCompletionProcPtr userRoutine)
  {
    return (DBCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppDBCompletionProcInfo,
                                                 GetCurrentArchitecture());
  }
#else
#define NewDBCompletionUPP(userRoutine)                                     \
  (DBCompletionUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppDBCompletionProcInfo, \
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
  enum
  {
    uppDBQueryDefProcInfo = 0x000003E0
  }; /** pascal 2_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DBQueryDefUPP NewDBQueryDefUPP(DBQueryDefProcPtr userRoutine)
  {
    return (DBQueryDefUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDBQueryDefProcInfo, GetCurrentArchitecture());
  }
#else
#define NewDBQueryDefUPP(userRoutine)   \
  (DBQueryDefUPP) NewRoutineDescriptor( \
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
  enum
  {
    uppDBStatusProcInfo = 0x000FAA90
  }; /** pascal 1_byte Func(2_bytes, 2_bytes, 2_bytes, 2_bytes, 2_bytes, 4_bytes,
        4_bytes) */
#ifdef __cplusplus
  inline DBStatusUPP NewDBStatusUPP(DBStatusProcPtr userRoutine)
  {
    return (DBStatusUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDBStatusProcInfo, GetCurrentArchitecture());
  }
#else
#define NewDBStatusUPP(userRoutine)   \
  (DBStatusUPP) NewRoutineDescriptor( \
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
  enum
  {
    uppDBResultHandlerProcInfo = 0x0003EAE0
  }; /** pascal 2_bytes Func(4_bytes, 2_bytes, 2_bytes, 2_bytes, 4_bytes, 4_bytes)
      */
#ifdef __cplusplus
  inline DBResultHandlerUPP
  NewDBResultHandlerUPP(DBResultHandlerProcPtr userRoutine)
  {
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
  inline void DisposeDBCompletionUPP(DBCompletionUPP userUPP)
  {
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
  inline void DisposeDBQueryDefUPP(DBQueryDefUPP userUPP)
  {
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
  inline void DisposeDBStatusUPP(DBStatusUPP userUPP)
  {
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
  inline void DisposeDBResultHandlerUPP(DBResultHandlerUPP userUPP)
  {
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
  InvokeDBCompletionUPP(DBAsyncParmBlkPtr pb, DBCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeDBCompletionUPP(DBAsyncParmBlkPtr pb,
                                    DBCompletionUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppDBCompletionProcInfo, pb);
  }
#else
#define InvokeDBCompletionUPP(pb, userUPP) \
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
                                   DBQueryDefUPP userUPP)
  {
    return (OSErr)CALL_TWO_PARAMETER_UPP(userUPP, uppDBQueryDefProcInfo, sessID,
                                         query);
  }
#else
#define InvokeDBQueryDefUPP(sessID, query, userUPP)                          \
  (OSErr) CALL_TWO_PARAMETER_UPP((userUPP), uppDBQueryDefProcInfo, (sessID), \
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
                                   DBStatusUPP userUPP)
  {
    return (Boolean)CALL_SEVEN_PARAMETER_UPP(userUPP, uppDBStatusProcInfo,
                                             message, result, dataLen, dataPlaces,
                                             dataFlags, dataType, dataPtr);
  }
#else
#define InvokeDBStatusUPP(message, result, dataLen, dataPlaces, dataFlags, \
                          dataType, dataPtr, userUPP)                      \
  (Boolean) CALL_SEVEN_PARAMETER_UPP(                                      \
      (userUPP), uppDBStatusProcInfo, (message), (result), (dataLen),      \
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
                                        DBResultHandlerUPP userUPP)
  {
    return (OSErr)CALL_SIX_PARAMETER_UPP(userUPP, uppDBResultHandlerProcInfo,
                                         dataType, theLen, thePlaces, theFlags,
                                         theData, theText);
  }
#else
#define InvokeDBResultHandlerUPP(dataType, theLen, thePlaces, theFlags, \
                                 theData, theText, userUPP)             \
  (OSErr) CALL_SIX_PARAMETER_UPP((userUPP), uppDBResultHandlerProcInfo, \
                                 (dataType), (theLen), (thePlaces),     \
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
#define CallDBCompletionProc(userRoutine, pb) \
  InvokeDBCompletionUPP(pb, userRoutine)
#define CallDBQueryDefProc(userRoutine, sessID, query) \
  InvokeDBQueryDefUPP(sessID, query, userRoutine)
#define CallDBStatusProc(userRoutine, message, result, dataLen, dataPlaces,    \
                         dataFlags, dataType, dataPtr)                         \
  InvokeDBStatusUPP(message, result, dataLen, dataPlaces, dataFlags, dataType, \
                    dataPtr, userRoutine)
#define CallDBResultHandlerProc(userRoutine, dataType, theLen, thePlaces,  \
                                theFlags, theData, theText)                \
  InvokeDBResultHandlerUPP(dataType, theLen, thePlaces, theFlags, theData, \
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
  OSErr
  InitDBPack(void);

  /**
   *  DBInit()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBInit(long *sessID, ConstStr63Param ddevName, ConstStr255Param host,
         ConstStr255Param user, ConstStr255Param passwd, ConstStr255Param connStr,
         DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBEnd()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBEnd(long sessID, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBGetConnInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBGetConnInfo(long sessID, short sessNum, long *returnedID, long *version,
                Str63 ddevName, Str255 host, Str255 user, Str255 network,
                Str255 connStr, long *start, OSErr *state,
                DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBGetSessionNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBGetSessionNum(long sessID, short *sessNum, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBSend()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBSend(long sessID, Ptr text, short len, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBSendItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBSendItem(long sessID, DBType dataType, short len, short places, short flags,
             void *buffer, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBExec()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBExec(long sessID, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBState()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBState(long sessID, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBGetErr()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBGetErr(long sessID, long *err1, long *err2, Str255 item1, Str255 item2,
           Str255 errorMsg, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBBreak()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBBreak(long sessID, Boolean abort, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBGetItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBGetItem(long sessID, long timeout, DBType *dataType, short *len,
            short *places, short *flags, void *buffer, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBUnGetItem()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBUnGetItem(long sessID, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBKill()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBKill(DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBGetNewQuery()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBGetNewQuery(short queryID, QueryHandle *query);

  /**
   *  DBDisposeQuery()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBDisposeQuery(QueryHandle query);

  /**
   *  DBStartQuery()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBStartQuery(long *sessID, QueryHandle query, DBStatusUPP statusProc,
               DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBGetQueryResults()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBGetQueryResults(long sessID, ResultsRecord *results, long timeout,
                    DBStatusUPP statusProc, DBAsyncParmBlkPtr asyncPB);

  /**
   *  DBResultsToText()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBResultsToText(ResultsRecord *results, Handle *theText);

  /**
   *  DBInstallResultHandler()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBInstallResultHandler(DBType dataType, DBResultHandlerUPP theHandler,
                         Boolean isSysHandler);

  /**
   *  DBRemoveResultHandler()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBRemoveResultHandler(DBType dataType);

  /**
   *  DBGetResultHandler()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBGetResultHandler(DBType dataType, DBResultHandlerUPP *theHandler,
                     Boolean getSysHandler);

  /**
   *  DBIdle()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DBIdle(void);

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
