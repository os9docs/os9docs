/**
     \file       NetSprocket.h

    \brief   Games Sprockets: NetSprocket interfaces

    \introduced_in  NetSprocket 1.7
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1996-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Networking

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __NETSPROCKET__
#define __NETSPROCKET__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __OPENTRANSPORT__
#include <OpenTransport.h>
#endif

#ifndef __OPENTRANSPORTPROVIDERS__
#include <OpenTransportProviders.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
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
#pragma options align = power
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

#if TARGET_OS_MAC
enum {
  kNSpMaxPlayerNameLen = 31,
  kNSpMaxGroupNameLen = 31,
  kNSpMaxPasswordLen = 31,
  kNSpMaxGameNameLen = 31,
  kNSpMaxDefinitionStringLen = 255
};

/** NetSprocket basic types */
typedef struct OpaqueNSpGameReference *NSpGameReference;
typedef struct OpaqueNSpProtocolReference *NSpProtocolReference;
typedef struct OpaqueNSpProtocolListReference *NSpProtocolListReference;
typedef struct OpaqueNSpAddressReference *NSpAddressReference;
typedef SInt32 NSpEventCode;
typedef SInt32 NSpGameID;
typedef SInt32 NSpPlayerID;
typedef NSpPlayerID NSpGroupID;
typedef UInt32 NSpPlayerType;
typedef SInt32 NSpFlags;
typedef Str31 NSpPlayerName;
/** Individual player info */

struct NSpPlayerInfo {
  NSpPlayerID id;
  NSpPlayerType type;
  Str31 name;
  UInt32 groupCount;
  NSpGroupID groups[1];
};
typedef struct NSpPlayerInfo NSpPlayerInfo;

typedef NSpPlayerInfo *NSpPlayerInfoPtr;
/** list of all players */
struct NSpPlayerEnumeration {
  UInt32 count;
  NSpPlayerInfoPtr playerInfo[1];
};
typedef struct NSpPlayerEnumeration NSpPlayerEnumeration;
typedef NSpPlayerEnumeration *NSpPlayerEnumerationPtr;
/** Individual group info */
struct NSpGroupInfo {
  NSpGroupID id;
  UInt32 playerCount;
  NSpPlayerID players[1];
};
typedef struct NSpGroupInfo NSpGroupInfo;
typedef NSpGroupInfo *NSpGroupInfoPtr;
/** List of all groups */
struct NSpGroupEnumeration {
  UInt32 count;
  NSpGroupInfoPtr groups[1];
};
typedef struct NSpGroupEnumeration NSpGroupEnumeration;
typedef NSpGroupEnumeration *NSpGroupEnumerationPtr;
/** Topology types */
typedef UInt32 NSpTopology;
enum { kNSpClientServer = 0x00000001 };

/** Game information */
struct NSpGameInfo {
  UInt32 maxPlayers;
  UInt32 currentPlayers;
  UInt32 currentGroups;
  NSpTopology topology;
  UInt32 reserved;
  Str31 name;
  Str31 password;
};
typedef struct NSpGameInfo NSpGameInfo;
/** Structure used for sending and receiving network messages */
struct NSpMessageHeader {
  UInt32 version;    /** Used by NetSprocket.  Don't touch this */
  SInt32 what;       /** The kind of message (e.g. player joined) */
  NSpPlayerID from;  /** ID of the sender */
  NSpPlayerID to;    /** (player or group) id of the intended recipient */
  UInt32 id;         /** Unique ID for this message & (from) player */
  UInt32 when;       /** Timestamp for the message */
  UInt32 messageLen; /** Bytes of data in the entire message (including the
                        header) */
};
typedef struct NSpMessageHeader NSpMessageHeader;
/** NetSprocket-defined message structures */
struct NSpErrorMessage {
  NSpMessageHeader header;
  OSStatus error;
};
typedef struct NSpErrorMessage NSpErrorMessage;
struct NSpJoinRequestMessage {
  NSpMessageHeader header;
  Str31 name;
  Str31 password;
  UInt32 theType;
  UInt32 customDataLen;
  UInt8 customData[1];
};
typedef struct NSpJoinRequestMessage NSpJoinRequestMessage;
struct NSpJoinApprovedMessage {
  NSpMessageHeader header;
};
typedef struct NSpJoinApprovedMessage NSpJoinApprovedMessage;
struct NSpJoinDeniedMessage {
  NSpMessageHeader header;
  Str255 reason;
};
typedef struct NSpJoinDeniedMessage NSpJoinDeniedMessage;
struct NSpPlayerJoinedMessage {
  NSpMessageHeader header;
  UInt32 playerCount;
  NSpPlayerInfo playerInfo;
};
typedef struct NSpPlayerJoinedMessage NSpPlayerJoinedMessage;
struct NSpPlayerLeftMessage {
  NSpMessageHeader header;
  UInt32 playerCount;
  NSpPlayerID playerID;
  NSpPlayerName playerName;
};
typedef struct NSpPlayerLeftMessage NSpPlayerLeftMessage;
struct NSpHostChangedMessage {
  NSpMessageHeader header;
  NSpPlayerID newHost;
};
typedef struct NSpHostChangedMessage NSpHostChangedMessage;
struct NSpGameTerminatedMessage {
  NSpMessageHeader header;
};
typedef struct NSpGameTerminatedMessage NSpGameTerminatedMessage;
struct NSpCreateGroupMessage {
  NSpMessageHeader header;
  NSpGroupID groupID;
  NSpPlayerID requestingPlayer;
};
typedef struct NSpCreateGroupMessage NSpCreateGroupMessage;
struct NSpDeleteGroupMessage {
  NSpMessageHeader header;
  NSpGroupID groupID;
  NSpPlayerID requestingPlayer;
};
typedef struct NSpDeleteGroupMessage NSpDeleteGroupMessage;
struct NSpAddPlayerToGroupMessage {
  NSpMessageHeader header;
  NSpGroupID group;
  NSpPlayerID player;
};
typedef struct NSpAddPlayerToGroupMessage NSpAddPlayerToGroupMessage;
struct NSpRemovePlayerFromGroupMessage {
  NSpMessageHeader header;
  NSpGroupID group;
  NSpPlayerID player;
};
typedef struct NSpRemovePlayerFromGroupMessage NSpRemovePlayerFromGroupMessage;
struct NSpPlayerTypeChangedMessage {
  NSpMessageHeader header;
  NSpPlayerID player;
  NSpPlayerType newType;
};
typedef struct NSpPlayerTypeChangedMessage NSpPlayerTypeChangedMessage;
/** Different kinds of messages.  These can NOT be bitwise ORed together */
enum {
  kNSpSendFlag_Junk = 0x00100000,   /** will be sent (try once) when there is
                                       nothing else pending */
  kNSpSendFlag_Normal = 0x00200000, /** will be sent immediately (try once) */
  kNSpSendFlag_Registered =
      0x00400000 /** will be sent immediately (guaranteed, in order) */
};

/** Options for message delivery.  These can be bitwise ORed together with each
   other, as well as with ONE of the above */
enum {
  kNSpSendFlag_FailIfPipeFull = 0x00000001,
  kNSpSendFlag_SelfSend = 0x00000002,
  kNSpSendFlag_Blocking = 0x00000004
};

/** Options for Hosting Joining, and Deleting games */
enum {
  kNSpGameFlag_DontAdvertise = 0x00000001,
  kNSpGameFlag_ForceTerminateGame = 0x00000002
};

/** Message "what" types */
/** Apple reserves all negative "what" values (anything with high bit set) */
enum {
  kNSpSystemMessagePrefix = (long)0x80000000,
  kNSpError = kNSpSystemMessagePrefix | 0x7FFFFFFF,
  kNSpJoinRequest = kNSpSystemMessagePrefix | 0x00000001,
  kNSpJoinApproved = kNSpSystemMessagePrefix | 0x00000002,
  kNSpJoinDenied = kNSpSystemMessagePrefix | 0x00000003,
  kNSpPlayerJoined = kNSpSystemMessagePrefix | 0x00000004,
  kNSpPlayerLeft = kNSpSystemMessagePrefix | 0x00000005,
  kNSpHostChanged = kNSpSystemMessagePrefix | 0x00000006,
  kNSpGameTerminated = kNSpSystemMessagePrefix | 0x00000007,
  kNSpGroupCreated = kNSpSystemMessagePrefix | 0x00000008,
  kNSpGroupDeleted = kNSpSystemMessagePrefix | 0x00000009,
  kNSpPlayerAddedToGroup = kNSpSystemMessagePrefix | 0x0000000A,
  kNSpPlayerRemovedFromGroup = kNSpSystemMessagePrefix | 0x0000000B,
  kNSpPlayerTypeChanged = kNSpSystemMessagePrefix | 0x0000000C
};

/** Special TPlayerIDs  for sending messages */
enum { kNSpAllPlayers = 0x00000000, kNSpHostOnly = (long)0xFFFFFFFF };

/*************************  Initialization  ************************/
/**
 *  NSpInitialize()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpInitialize(UInt32 inStandardMessageSize, UInt32 inBufferSize,
              UInt32 inQElements, NSpGameID inGameID, UInt32 inTimeout);

/***************************  Protocols  **************************/
/** Programmatic protocol routines */
/**
 *  NSpProtocol_New()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpProtocol_New(const char *inDefinitionString,
                NSpProtocolReference *outReference);

/**
 *  NSpProtocol_Dispose()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
void
NSpProtocol_Dispose(NSpProtocolReference inProtocolRef);

/**
 *  NSpProtocol_ExtractDefinitionString()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpProtocol_ExtractDefinitionString(NSpProtocolReference inProtocolRef,
                                    char *outDefinitionString);

/** Protocol list routines */
/**
 *  NSpProtocolList_New()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpProtocolList_New(NSpProtocolReference inProtocolRef,
                    NSpProtocolListReference *outList);

/**
 *  NSpProtocolList_Dispose()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
void
NSpProtocolList_Dispose(NSpProtocolListReference inProtocolList);

/**
 *  NSpProtocolList_Append()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpProtocolList_Append(NSpProtocolListReference inProtocolList,
                       NSpProtocolReference inProtocolRef);

/**
 *  NSpProtocolList_Remove()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpProtocolList_Remove(NSpProtocolListReference inProtocolList,
                       NSpProtocolReference inProtocolRef);

/**
 *  NSpProtocolList_RemoveIndexed()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpProtocolList_RemoveIndexed(NSpProtocolListReference inProtocolList,
                              UInt32 inIndex);

/**
 *  NSpProtocolList_GetCount()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
UInt32
NSpProtocolList_GetCount(NSpProtocolListReference inProtocolList);

/**
 *  NSpProtocolList_GetIndexedRef()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
NSpProtocolReference
NSpProtocolList_GetIndexedRef(NSpProtocolListReference inProtocolList,
                              UInt32 inIndex);

/** Helpers */
/**
 *  NSpProtocol_CreateAppleTalk()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
NSpProtocolReference
NSpProtocol_CreateAppleTalk(ConstStr31Param inNBPName,
                            ConstStr31Param inNBPType, UInt32 inMaxRTT,
                            UInt32 inMinThruput);

/**
 *  NSpProtocol_CreateIP()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
NSpProtocolReference
NSpProtocol_CreateIP(InetPort inPort, UInt32 inMaxRTT, UInt32 inMinThruput);

/************************  Human Interface  ************************/
typedef CALLBACK_API(Boolean, NSpEventProcPtr)(EventRecord *inEvent);
/**
 *  NSpDoModalJoinDialog()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
NSpAddressReference
NSpDoModalJoinDialog(ConstStr31Param inGameType,
                     ConstStr255Param inEntityListLabel, Str31 ioName,
                     Str31 ioPassword, NSpEventProcPtr inEventProcPtr);

/**
 *  NSpDoModalHostDialog()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
Boolean
NSpDoModalHostDialog(NSpProtocolListReference ioProtocolList, Str31 ioGameName,
                     Str31 ioPlayerName, Str31 ioPassword,
                     NSpEventProcPtr inEventProcPtr);

/**********************  Hosting and Joining  **********************/
/**
 *  NSpGame_Host()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGame_Host(NSpGameReference *outGame, NSpProtocolListReference inProtocolList,
             UInt32 inMaxPlayers, ConstStr31Param inGameName,
             ConstStr31Param inPassword, ConstStr31Param inPlayerName,
             NSpPlayerType inPlayerType, NSpTopology inTopology,
             NSpFlags inFlags);

/**
 *  NSpGame_Join()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGame_Join(NSpGameReference *outGame, NSpAddressReference inAddress,
             ConstStr31Param inName, ConstStr31Param inPassword,
             NSpPlayerType inType, void *inCustomData, UInt32 inCustomDataLen,
             NSpFlags inFlags);

/**
 *  NSpGame_EnableAdvertising()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGame_EnableAdvertising(NSpGameReference inGame,
                          NSpProtocolReference inProtocol, Boolean inEnable);

/**
 *  NSpGame_Dispose()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGame_Dispose(NSpGameReference inGame, NSpFlags inFlags);

/**
 *  NSpGame_GetInfo()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0.3 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGame_GetInfo(NSpGameReference inGame, NSpGameInfo *ioInfo);

/***************************  Messaging  **************************/
/**
 *  NSpMessage_Send()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpMessage_Send(NSpGameReference inGame, NSpMessageHeader *inMessage,
                NSpFlags inFlags);

/**
 *  NSpMessage_Get()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
NSpMessageHeader *
NSpMessage_Get(NSpGameReference inGame);

/**
 *  NSpMessage_Release()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
void
NSpMessage_Release(NSpGameReference inGame, NSpMessageHeader *inMessage);

/** Helpers */
/**
 *  NSpMessage_SendTo()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpMessage_SendTo(NSpGameReference inGame, NSpPlayerID inTo, SInt32 inWhat,
                  void *inData, UInt32 inDataLen, NSpFlags inFlags);

/**********************  Player Information  **********************/
/**
 *  NSpPlayer_ChangeType()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.7 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpPlayer_ChangeType(NSpGameReference inGame, NSpPlayerID inPlayerID,
                     NSpPlayerType inNewType);

/**
 *  NSpPlayer_Remove()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.7 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpPlayer_Remove(NSpGameReference inGame, NSpPlayerID inPlayerID);

/**
 *  NSpPlayer_GetAddress()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.7 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpPlayer_GetAddress(NSpGameReference inGame, NSpPlayerID inPlayerID,
                     OTAddress **outAddress);

/**
 *  NSpPlayer_GetMyID()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
NSpPlayerID
NSpPlayer_GetMyID(NSpGameReference inGame);

/**
 *  NSpPlayer_GetInfo()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpPlayer_GetInfo(NSpGameReference inGame, NSpPlayerID inPlayerID,
                  NSpPlayerInfoPtr *outInfo);

/**
 *  NSpPlayer_ReleaseInfo()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
void
NSpPlayer_ReleaseInfo(NSpGameReference inGame, NSpPlayerInfoPtr inInfo);

/**
 *  NSpPlayer_GetEnumeration()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpPlayer_GetEnumeration(NSpGameReference inGame,
                         NSpPlayerEnumerationPtr *outPlayers);

/**
 *  NSpPlayer_ReleaseEnumeration()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
void
NSpPlayer_ReleaseEnumeration(NSpGameReference inGame,
                             NSpPlayerEnumerationPtr inPlayers);

/**
 *  NSpPlayer_GetRoundTripTime()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
UInt32
NSpPlayer_GetRoundTripTime(NSpGameReference inGame, NSpPlayerID inPlayer);

/**
 *  NSpPlayer_GetThruput()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
UInt32
NSpPlayer_GetThruput(NSpGameReference inGame, NSpPlayerID inPlayer);

/**********************  Group Management  **********************/
/**
 *  NSpGroup_New()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGroup_New(NSpGameReference inGame, NSpGroupID *outGroupID);

/**
 *  NSpGroup_Dispose()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGroup_Dispose(NSpGameReference inGame, NSpGroupID inGroupID);

/**
 *  NSpGroup_AddPlayer()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGroup_AddPlayer(NSpGameReference inGame, NSpGroupID inGroupID,
                   NSpPlayerID inPlayerID);

/**
 *  NSpGroup_RemovePlayer()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGroup_RemovePlayer(NSpGameReference inGame, NSpGroupID inGroupID,
                      NSpPlayerID inPlayerID);

/**
 *  NSpGroup_GetInfo()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGroup_GetInfo(NSpGameReference inGame, NSpGroupID inGroupID,
                 NSpGroupInfoPtr *outInfo);

/**
 *  NSpGroup_ReleaseInfo()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
void
NSpGroup_ReleaseInfo(NSpGameReference inGame, NSpGroupInfoPtr inInfo);

/**
 *  NSpGroup_GetEnumeration()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpGroup_GetEnumeration(NSpGameReference inGame,
                        NSpGroupEnumerationPtr *outGroups);

/**
 *  NSpGroup_ReleaseEnumeration()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
void
NSpGroup_ReleaseEnumeration(NSpGameReference inGame,
                            NSpGroupEnumerationPtr inGroups);

/***************************  Utilities  ***************************/
/**
 *  NSpGetVersion()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0.3 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
NumVersion
NSpGetVersion(void);

/**
 *  NSpSetConnectTimeout()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.7 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
void
NSpSetConnectTimeout(UInt32 inSeconds);

/**
 *  NSpClearMessageHeader()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
void
NSpClearMessageHeader(NSpMessageHeader *inMessage);

/**
 *  NSpGetCurrentTimeStamp()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
UInt32
NSpGetCurrentTimeStamp(NSpGameReference inGame);

/**
 *  NSpConvertOTAddrToAddressReference()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
NSpAddressReference
NSpConvertOTAddrToAddressReference(OTAddress *inAddress);

/**
 *  NSpConvertAddressReferenceToOTAddr()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OTAddress *
NSpConvertAddressReferenceToOTAddr(NSpAddressReference inAddress);

/**
 *  NSpReleaseAddressReference()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
void
NSpReleaseAddressReference(NSpAddressReference inAddress);

/************************* Advanced/Async routines ****************/
typedef CALLBACK_API(void,
                     NSpCallbackProcPtr)(NSpGameReference inGame,
                                         void *inContext, NSpEventCode inCode,
                                         OSStatus inStatus, void *inCookie);
/**
 *  NSpInstallCallbackHandler()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpInstallCallbackHandler(NSpCallbackProcPtr inHandler, void *inContext);

typedef CALLBACK_API(Boolean, NSpJoinRequestHandlerProcPtr)(
    NSpGameReference inGame, NSpJoinRequestMessage *inMessage, void *inContext,
    Str255 outReason);
/**
 *  NSpInstallJoinRequestHandler()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpInstallJoinRequestHandler(NSpJoinRequestHandlerProcPtr inHandler,
                             void *inContext);

typedef CALLBACK_API(Boolean,
                     NSpMessageHandlerProcPtr)(NSpGameReference inGame,
                                               NSpMessageHeader *inMessage,
                                               void *inContext);
/**
 *  NSpInstallAsyncMessageHandler()
 *

 *    \non_carbon_cfm   in NetSprocketLib 1.0 and later
 *    \carbon_lib        not in Carbon, but NetSprocketLib is compatible with
 Carbon
 *    \mac_os_x         not available
 */
OSStatus
NSpInstallAsyncMessageHandler(NSpMessageHandlerProcPtr inHandler,
                              void *inContext);

#endif /** TARGET_OS_MAC */

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

#endif /** __NETSPROCKET__ */
