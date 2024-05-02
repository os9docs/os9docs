/**
	 \file       AppleTalk.h

	\brief   AppleTalk Interfaces.

	\introduced_in  System 8.5
	\avaliable_from Universal Interfaces 3.4.1

	\copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

	\ingroup AppleTalk

	For bug reports, consult the following page on
				 the World Wide Web:

					 http://developer.apple.com/bugreporter/

*/
#ifndef __APPLETALK__
#define __APPLETALK__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __OSUTILS__
#include <OSUtils.h>
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
		/** Driver unit numbers (ADSP is dynamic) */
		mppUnitNum = 9,	 /** MPP unit number */
		atpUnitNum = 10, /** ATP unit number */
		xppUnitNum = 40	 /** XPP unit number */
	};

	enum
	{
		/** Driver refNums (ADSP is dynamic) */
		mppRefNum = -10, /** MPP reference number */
		atpRefNum = -11, /** ATP reference number */
		xppRefNum = -41	 /** XPP reference number */
	};

	enum
	{
		/** .MPP csCodes */
		lookupReply = 242,	 /** This command queued to ourself */
		writeLAP = 243,		 /** Write out LAP packet */
		detachPH = 244,		 /** Detach LAP protocol handler */
		attachPH = 245,		 /** Attach LAP protocol handler */
		writeDDP = 246,		 /** Write out DDP packet */
		closeSkt = 247,		 /** Close DDP socket */
		openSkt = 248,		 /** Open DDP socket */
		loadNBP = 249,		 /** Load NBP command-executing code */
		lastResident = 249,	 /** Last resident command */
		confirmName = 250,	 /** Confirm name */
		lookupName = 251,	 /** Look up name on internet */
		removeName = 252,	 /** Remove name from Names Table */
		registerName = 253,	 /** Register name in Names Table */
		killNBP = 254,		 /** Kill outstanding NBP request */
		unloadNBP = 255,	 /** Unload NBP command code */
		setSelfSend = 256,	 /** MPP: Set to allow writes to self */
		SetMyZone = 257,	 /** Set my zone name */
		GetATalkInfo = 258,	 /** get AppleTalk information */
		ATalkClosePrep = 259 /** AppleTalk close query */
	};

	enum
	{
		/** .ATP csCodes */
		nSendRequest = 248, /** NSendRequest code */
		relRspCB = 249,		/** Release RspCB */
		closeATPSkt = 250,	/** Close ATP socket */
		addResponse = 251,	/** Add response code | Require open skt */
		sendResponse = 252, /** Send response code */
		getRequest = 253,	/** Get request code */
		openATPSkt = 254,	/** Open ATP socket */
		sendRequest = 255,	/** Send request code */
		relTCB = 256,		/** Release TCB */
		killGetReq = 257,	/** Kill GetRequest */
		killSendReq = 258,	/** Kill SendRequest */
		killAllGetReq = 259 /** Kill all getRequests for a skt */
	};

	enum
	{
		/** .XPP csCodes */
		openSess = 255,	   /** Open session */
		closeSess = 254,   /** Close session */
		userCommand = 253, /** User command */
		userWrite = 252,   /** User write */
		getStatus = 251,   /** Get status */
		afpCall = 250,	   /** AFP command (buffer has command code) */
		getParms = 249,	   /** Get parameters */
		abortOS = 248,	   /** Abort open session request */
		closeAll = 247,	   /** Close all open sessions */
		xCall = 246		   /** .XPP extended calls */
	};

	enum
	{
		/** Transition Queue transition types */
		ATTransOpen = 0,	   /**AppleTalk has opened*/
		ATTransClose = 2,	   /**AppleTalk is about to close*/
		ATTransClosePrep = 3,  /**Is it OK to close AppleTalk ?*/
		ATTransCancelClose = 4 /**Cancel the ClosePrep transition*/
	};

	enum
	{
		afpByteRangeLock = 1, /**AFPCall command codes*/
		afpVolClose = 2,	  /**AFPCall command codes*/
		afpDirClose = 3,	  /**AFPCall command codes*/
		afpForkClose = 4,	  /**AFPCall command codes*/
		afpCopyFile = 5,	  /**AFPCall command codes*/
		afpDirCreate = 6,	  /**AFPCall command codes*/
		afpFileCreate = 7,	  /**AFPCall command codes*/
		afpDelete = 8,		  /**AFPCall command codes*/
		afpEnumerate = 9,	  /**AFPCall command codes*/
		afpFlush = 10,		  /**AFPCall command codes*/
		afpForkFlush = 11,	  /**AFPCall command codes*/
		afpGetDirParms = 12,  /**AFPCall command codes*/
		afpGetFileParms = 13, /**AFPCall command codes*/
		afpGetForkParms = 14, /**AFPCall command codes*/
		afpGetSInfo = 15,	  /**AFPCall command codes*/
		afpGetSParms = 16,	  /**AFPCall command codes*/
		afpGetVolParms = 17,  /**AFPCall command codes*/
		afpLogin = 18,		  /**AFPCall command codes*/
		afpContLogin = 19,	  /**AFPCall command codes*/
		afpLogout = 20,		  /**AFPCall command codes*/
		afpMapID = 21,		  /**AFPCall command codes*/
		afpMapName = 22,	  /**AFPCall command codes*/
		afpMove = 23,		  /**AFPCall command codes*/
		afpOpenVol = 24,	  /**AFPCall command codes*/
		afpOpenDir = 25,	  /**AFPCall command codes*/
		afpOpenFork = 26,	  /**AFPCall command codes*/
		afpRead = 27,		  /**AFPCall command codes*/
		afpRename = 28,		  /**AFPCall command codes*/
		afpSetDirParms = 29,  /**AFPCall command codes*/
		afpSetFileParms = 30, /**AFPCall command codes*/
		afpSetForkParms = 31, /**AFPCall command codes*/
		afpSetVolParms = 32,  /**AFPCall command codes*/
		afpWrite = 33,		  /**AFPCall command codes*/
		afpGetFlDrParms = 34, /**AFPCall command codes*/
		afpSetFlDrParms = 35, /**AFPCall command codes*/
		afpDTOpen = 48,		  /**AFPCall command codes*/
		afpDTClose = 49,	  /**AFPCall command codes*/
		afpGetIcon = 51,	  /**AFPCall command codes*/
		afpGtIcnInfo = 52,	  /**AFPCall command codes*/
		afpAddAPPL = 53,	  /**AFPCall command codes*/
		afpRmvAPPL = 54,	  /**AFPCall command codes*/
		afpGetAPPL = 55,	  /**AFPCall command codes*/
		afpAddCmt = 56,		  /**AFPCall command codes*/
		afpRmvCmt = 57,		  /**AFPCall command codes*/
		afpGetCmt = 58,		  /**AFPCall command codes*/
		afpAddIcon = 192	  /**Special code for ASP Write commands*/
	};

	enum
	{
		xppLoadedBit = 5, /** XPP bit in PortBUse */
		scbMemSize = 192, /** Size of memory for SCB */
		xppFlagClr = 0	  /** Cs for AFPCommandBlock */
	};

	enum
	{
		xppFlagSet = 128 /** StartEndFlag & NewLineFlag fields. */
	};

	enum
	{
		lapSize = 20,
		ddpSize = 26,
		nbpSize = 26,
		atpSize = 56
	};

	enum
	{
		atpXOvalue = 32,	  /**ATP exactly-once bit */
		atpEOMvalue = 16,	  /**ATP End-Of-Message bit */
		atpSTSvalue = 8,	  /**ATP Send-Transmission-Status bit */
		atpTIDValidvalue = 2, /**ATP trans. ID valid bit */
		atpSendChkvalue = 1	  /**ATP send checksum bit */
	};

	enum
	{
		zipGetLocalZones = 5,
		zipGetZoneList = 6,
		zipGetMyZone = 7
	};

	enum
	{
		LAPMgrPtr = 0x0B18 /**Entry point for LAP Manager*/
	};

	enum
	{
		LAPMgrCall = 2, /**Offset to LAP routines*/
		LAddAEQ = 23,	/**LAPAddATQ routine selector*/
		LRmvAEQ = 24	/**LAPRmvATQ routine selector*/
	};

#define MPPioCompletion MPP.ioCompletion
#define MPPioResult MPP.ioResult
#define MPPioRefNum MPP.ioRefNum
#define MPPcsCode MPP.csCode
#define LAPprotType LAP.protType
#define LAPwdsPointer LAP.u.wdsPointer
#define LAPhandler LAP.u.handler
#define DDPsocket DDP.socket
#define DDPchecksumFlag DDP.checksumFlag
#define DDPwdsPointer DDP.u.wdsPointer
#define DDPlistener DDP.u.listener
#define NBPinterval NBP.interval
#define NBPcount NBP.count
#define NBPntQElPtr NBP.nbpPtrs.ntQElPtr
#define NBPentityPtr NBP.nbpPtrs.entityPtr
#define NBPverifyFlag NBP.parm.verifyFlag
#define NBPretBuffPtr NBP.parm.Lookup.retBuffPtr
#define NBPretBuffSize NBP.parm.Lookup.retBuffSize
#define NBPmaxToGet NBP.parm.Lookup.maxToGet
#define NBPnumGotten NBP.parm.Lookup.numGotten
#define NBPconfirmAddr NBP.parm.Confirm.confirmAddr
#define NBPnKillQEl NBPKILL.nKillQEl
#define NBPnewSocket NBP.parm.Confirm.newSocket
#define ATPioCompletion ATP.ioCompletion
#define ATPioResult ATP.ioResult
#define ATPuserData ATP.userData
#define ATPreqTID ATP.reqTID
#define ATPioRefNum ATP.ioRefNum
#define ATPcsCode ATP.csCode
#define ATPatpSocket ATP.atpSocket
#define ATPatpFlags ATP.atpFlags
#define ATPaddrBlock ATP.addrBlock
#define ATPreqLength ATP.reqLength
#define ATPreqPointer ATP.reqPointer
#define ATPbdsPointer ATP.bdsPointer
#define ATPtimeOutVal SREQ.timeOutVal
#define ATPnumOfResps SREQ.numOfResps
#define ATPretryCount SREQ.retryCount
#define ATPnumOfBuffs OTH1.u.numOfBuffs
#define ATPbitMap OTH1.u.bitMap
#define ATPrspNum OTH1.u.rspNum
#define ATPbdsSize OTH2.bdsSize
#define ATPtransID OTH2.transID
#define ATPaKillQEl KILL.aKillQEl
	enum
	{
		tLAPRead = 0,
		tLAPWrite = 1,
		tDDPRead = 2,
		tDDPWrite = 3,
		tNBPLookup = 4,
		tNBPConfirm = 5,
		tNBPRegister = 6,
		tATPSndRequest = 7,
		tATPGetRequest = 8,
		tATPSdRsp = 9,
		tATPAddRsp = 10,
		tATPRequest = 11,
		tATPResponse = 12
	};

	typedef SInt8 ABCallType;
	enum
	{
		lapProto = 0,
		ddpProto = 1,
		nbpProto = 2,
		atpProto = 3
	};

	typedef UInt8 ABProtoType;
	typedef Byte ABByte;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct LAPAdrBlock
	{
		unsigned char dstNodeID; /**< Destination node ID*/
		unsigned char srcNodeID; /**< Source node ID*/
		ABByte lapProtType;		 /**< ALAP protocol type*/
	} LAPAdrBlock;				 /**< */

	typedef struct LAPAdrBlock LAPAdrBlock;
	typedef struct ATQEntry ATQEntry;

	typedef ATQEntry *ATQEntryPtr;
	typedef CALLBACK_API_C(long, ATalkTransitionEventProcPtr)(long eventCode,
															  ATQEntryPtr qElem,
															  void *eventParameter);
	typedef STACK_UPP_TYPE(ATalkTransitionEventProcPtr) ATalkTransitionEventUPP;
	typedef ATalkTransitionEventUPP ATalkTransitionEvent;
	/**
	<pre>
	 * \note <pre>When you want to add an entry to the AppleTalk Transition Queue, you must
	create an ATQentry data structure and give LAP Manager a pointer to it.
	The qLink field is a pointer to the next queue entry. You should set this field
	to NIL; LAP Manager fills it in when an application adds another entry to
	the queue. The qType field is reserved to maintain consistency with other
	operating-system queues. The CallAddr field is a pointer to a routine that
	you provide.
	Because you provide the memory for the AppleTalk Transition Queue entry,
	you can add as many fields to the end of the entry as you wish for your own
	purposes. Whenever your routine is called, the caller provides you with a
	pointer to the queue entry so that you can have access to the information you
	stored at the end of your queue entry.
	There are four LAP Manager functions you can use that are related to the
	AppleTalk Transition Queue:
	•The LAPAddATQ function adds an entry to the AppleTalk Transition
	Queue.
	•The LAPRmvATQ function removes an entry from the AppleTalk
	Transition Queue.
	•The ATEvent procedure calls all the entries in the AppleTalk
	Transition Queue with an AppleTalk transition event of your own
	definition.
	•The ATPreFlightEvent function calls all the entries in the AppleTalk
	Transition Queue with an AppleTalk transition event of your own
	definition and gives each entry the opportunity to respond.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ATQEntry
	{
		ATQEntryPtr *qLink; /**< Address of next queue entry;/**<*/
		short qType;		/**< Reserved*/
		ProcPtr CallAddr;	/**< Pointer to your routine*/
	} ATQEntry;				/**< */

	/**
		Real definition of EntityName is 3 PACKED strings of any length (32 is just
	   an example). No offests for Asm since each String address must be calculated
	   by adding length byte to last string ptr. In Pascal, String(32) will be 34
	   bytes long since fields never start on an odd byte unless they are only a
	   byte long. So this will generate correct looking interfaces for Pascal and C,
	   but they will not be the same, which is OK since they are not used.
	*/
	/**
	<pre>
	 * \note <pre>Real definition of EntityName is 3 PACKED strings of any length (32 is
	just an example). No offsets for Asm since each String address must be
	calculated by adding length byte to last string ptr.In Pascal, String(32)
	will be 34 bytes long since fields never start on an odd byte unless they are
	only a byte long. So this will generate correct looking interfaces for Pascal
	and C, but they will not be the same, which is OK since they are not used.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct EntityName
	{
		Str objStr;	 /**< Object*/
		Str typeStr; /**< Type*/
		Str zoneStr; /**< Zone*/
	} EntityName;	 /**< */

	typedef struct EntityName EntityName;
	typedef EntityName *EntityPtr;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct AddrBlock
	{
		short aNet;			   /**< Network number*/
		unsigned char aNode;   /**< Node ID*/
		unsigned char aSocket; /**< Socket number*/
	} AddrBlock;			   /**< */

	typedef struct AddrBlock AddrBlock;
	/**
	<pre>
	 * \note <pre>RetransCount contains the total number of times a packet should be
	transmitted, including the first transmission. If retransCount is 0, the
	packet will be transmitted a total of 255 times.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct RetransType
	{
		unsigned char retransInterval; /**< Retransmit interval in -tick units*/
		unsigned char retransCount;	   /**< Total number of attempts*/
	} RetransType;					   /**< */

	typedef struct RetransType RetransType;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct BDSElement
	{
		short buffSize; /**< Buffer size in bytes*/
		Ptr buffPtr;	/**< Pointer to buffer*/
		short dataSize; /**< Number of bytes actually received*/
		long userBytes; /**< User bytes*/
	} BDSElement;		/**<*/

	typedef struct BDSElement BDSElement;
	typedef BDSElement BDSType[8];
	typedef BDSElement *BDSPtr;
	typedef char BitMapType;
	/**
	<pre>
	 * \note <pre>When an ALAP frame is sent, the lapAddress field indicates the ID of the
	destination node. When an ALAP frame is received, lapAddress returns the
	ID of the source node. The lapAddress field also indicates the ALAP protocol
	type of the frame.
	When an ALAP frame is sent, lapReqCount indicates the size of the frame
	data in bytes and lapDataPtr points to a buffer containing the frame data to
	be sent. When an ALAP frame is received, the lapDataPtr points to a buffer
	in which the incoming data can be stored and lapReqCount indicates the size
	of the buffer in bytes. The number of bytes actually sent or received is
	returned the the lapActCount field.
	Each ALAP frame contains an 8-bit ALAP protocol type in the header. ALAP
	protocol types 128 through 255 are reserved for internal use by ALAP,
	hence the declaration:
	Warning: Do not use ALAP protocol type values 1 and 2; they're reserved
	for use by DDP. Values 3 through 15 are reserved for internal use by Apple
	and also should not be used.
	Using ALAP
	Most programs will never need to call ALAP, because higher-level
	protocols will automatically call it as necessary. If you do want to send a
	frame directly via ALAP, cal the LAPWrite function. If you want to read
	ALAP frames, you have two choices:
	• Call LAPOpenProtocol with NIL for protoPtr; this installs the default
	protocol handler provided by the AppleTalk Manager . Then call
	LAPRead to receive frames.
	• Write your own protocol handler, and call LAPOpenProtocol to add it to
	the node's protocol handler table. The ALAP code will examine every
	incoming frame and send all those with the correct ALAP protocol type to
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ATLAPRec
	{
		ABCallType abOpcode;	/**< Type of call*/
		short abResult;			/**< Result code*/
		long abUserReference;	/**< For your use*/
		LAPAdrBlock lapAddress; /**< Destination or source node ID*/
		short lapReqCount;		/**< Length of frame data or buffer*/
		short lapActCount;		/**< Number of frame data bytes*/
		Ptr lapDataPtr;			/**< Pointer to frame data or pointer*/
	} ATLAPRec;					/**< */

	typedef struct ATLAPRec ATLAPRec;
	typedef ATLAPRec *ATLAPRecPtr;
	typedef ATLAPRecPtr *ATLAPRecHandle;
	/**
	<pre>
	 * \note <pre>When a DDP datagram is sent, ddpReqCount indicates the size of the
	datagram data in bytes and ddpDataPtr points to a buffer containing the
	datagram data. DDPSocket specifies the socket from which the datagram
	should be sent. DDPAddress is the internet address of the socket to which the
	datagram should be sent:
	The network number you specify in ddpAddress.aNet tells MMP whether to
	create a long header (for an internet) or a short header (for a local network
	only). A short DDP header will be sent if ddpAddress.aNet is 0 or equal to
	the network number of the local network.
	When a DDP datagram is received, ddpDataPtr points to a buffer in which
	the incoming data can be stored and ddpReqCount indicates the size of the
	buffer in bytes. The number of bytes actually sent or received is returned
	in the ddpActCount field. DDPAddress is the internet address of the socket
	from which the datagram was sent.
	DDPType is the DDP protocol type of the datagram, and ddpSocket specifies
	the socket that will receive the datagram.
	Warning: DDP protocol types 1 through 15 and DDP socket numbers 1
	through 63 are reserved by Apple for internal use. Socket numbers 64
	through 127 are available for experimental use. Use of these experimental
	sockets is not recommended for commercial products since there's no
	mechanism for eliminating conflicting usage by different developers.
	Using DDP
	Before it can use a socket, the program must call DDPOpenSocket , which
	adds a socket and its socket listener to the socket table. When a program is
	finished using a socket, call DDPCloseSocket , which removes the socket's
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ATDDPRec
	{
		ABCallType abOpcode;  /**< Type of call*/
		short abResult;		  /**< Result code*/
		long abUserReference; /**< For your use*/
		short ddpType;		  /**< DDP protocol type*/
		AddrBlock ddpAddress; /**< Destination or source socket*/
		short ddpReqCount;	  /**< Length of datagram data or buffer*/
		short ddpActCount;	  /**< Number of frame data bytes*/
		Ptr ddpDataPtr;		  /**< Pointer to frame data or pointer*/
		short ddpNodeID;	  /**< original destination node ID*/
	} ATDDPRec;				  /**< */

	typedef struct ATDDPRec ATDDPRec;
	typedef ATDDPRec *ATDDPRecPtr;
	typedef ATDDPRecPtr *ATDDPRecHandle;
	/**
	<pre>
	 * \note <pre>When data is sent via NBP, nbpBufSize indicates the size of the data in
	bytes and nbpBufPtr points to a buffer containing the data. When data is
	received via NBP, nbpBufPtr points to a buffer in which the incoming data
	can be stored and nbpBufSize indicates the size of the buffer in bytes.
	NBPAddress is used in some calls to give the internet address of a named
	entity. The AddrBlock is described in ATDDPRec .
	NBPRetransmitInfo contains information about the number of times a
	packet should be transmitted and the interval between retransmission. See
	RetransType .
	NBPEntityPtr points to a variable of type EntityName .
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ATNBPRec
	{
		ABCallType abOpcode;		   /**< Type of call*/
		short abResult;				   /**< Result code*/
		long abUserReference;		   /**< For your use*/
		EntityPtr nbpEntityPtr;		   /**< Pointer to entity name*/
		Ptr nbpBufPtr;				   /**< Pointer to buffer*/
		short nbpBufSize;			   /**< Buffer size in bytes*/
		short nbpDataField;			   /**< Number of addresses or socket*/
		AddrBlock nbpAddress;		   /**< Socket address*/
		RetransType nbpRetransmitInfo; /**< Retransmission information*/
	} ATNBPRec;						   /**< */

	typedef struct ATNBPRec ATNBPRec;
	typedef ATNBPRec *ATNBPRecPtr;
	typedef ATNBPRecPtr *ATNBPRecHandle;
	/**
	<pre>
	 * \note <pre>The socket receiving the request or sending the response is identified by
	atpSocket. ATPAddress is the address of either the destination or the source
	socket of a transaction, depending on whether the call is sending or
	receiving data, respectively. ATPDataPtr and atpReqCount specify the
	location and size (in bytes) of a buffer that either contains a request or will
	receive a request. The number of bytes actually received in a request is
	returned in atpActCount ATPTransID specifies the transaction ID. The
	transaction bit map is contained in atpBitMap, in the form:
	Each bit in the bit map corresponds to one of the eight possible packets in a
	response. For example, when a request is made for which five response
	packets are expected, the bit map sent is binary 00011111 or decimal 31.
	If the second packet in the response is lost, the requesting socket will
	retransmit the request with a bitmap of 00000010 or decimal
	2.ATPUserData contains the user bytes of an ATP header.ATPXO Is TRUE if
	the transaction is to be made with exactly-once service. ATPEOM is TRUE if
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ATATPRec
	{
		ABCallType abOpcode;  /**< Type of call*/
		short abResult;		  /**< Result code*/
		long abUserReference; /**< For your use*/
		short atpSocket;	  /**< Listening or responding socket*/
		AddrBlock atpAddress; /**< Destination or source socket address*/
		short atpReqCount;	  /**< Request size or buffer size*/
		Ptr atpDataPtr;		  /**< Pointer to buffer*/
		BDSPtr atpRspBDSPtr;  /**< Pointer to response BDS*/
		BitMapType atpBitMap; /**< Transaction bit map*/
		short atpTransID;	  /**< Transaction ID*/
		short atpActCount;	  /**< Number of bytes actually received*/
		long atpUserData;	  /**< User bytes*/
		Boolean atpXO;		  /**< Exactly-once flag*/
		Boolean atpEOM;		  /**< End-of-message flag*/
		short atpTimeOut;	  /**< Retry timeout interval in seconds*/
		short atpRetries;	  /**< Maximum number of retries*/
		short atpNumBufs;	  /**< Number of elements in response*/
		short atpNumRsp;	  /**< Number of response packets received*/
		short atpBDSSize;	  /**< Number of elements in response*/
		long atpRspUData;	  /**< User bytes sent or received in*/
		Ptr atpRspBuf;		  /**< Pointer to response message buffer*/
		short atpRspSize;	  /**< Size of response message buffer*/
	} ATATPRec;				  /**< */

	typedef struct ATATPRec ATATPRec;
	typedef ATATPRec *ATATPRecPtr;
	typedef ATATPRecPtr *ATATPRecHandle;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct AFPCommandBlock
	{
		char cmdByte;	   /**< Command byte*/
		char startEndFlag; /**< Start/end Flag*/
		short forkRefNum;  /**< Used by server*/
		long rwOffset;	   /**< Offset within fork to write*/
		long reqCount;	   /**< Requested count*/
		char newLineFlag;  /**< Newline flag*/
		char newLineChar;  /**< Newline character*/
	} AFPCommandBlock;	   /**< */

	typedef struct AFPCommandBlock AFPCommandBlock;
	typedef union MPPParamBlock MPPParamBlock;
	typedef union ATPParamBlock ATPParamBlock;
	typedef union XPPParamBlock XPPParamBlock;

	typedef MPPParamBlock *MPPPBPtr;
	typedef ATPParamBlock *ATPPBPtr;
	typedef XPPParamBlock *XPPParmBlkPtr;
	typedef CALLBACK_API_REGISTER68K(void, MPPCompletionProcPtr,
									 (MPPPBPtr thePBptr));
	typedef CALLBACK_API_REGISTER68K(void, ATPCompletionProcPtr,
									 (ATPPBPtr thePBptr));
	typedef CALLBACK_API_REGISTER68K(void, XPPCompletionProcPtr,
									 (XPPParmBlkPtr thePBptr));
	typedef CALLBACK_API_REGISTER68K(void, AttnRoutineProcPtr,
									 (short sessRefnum, short attnBytes));
	typedef REGISTER_UPP_TYPE(MPPCompletionProcPtr) MPPCompletionUPP;
	typedef REGISTER_UPP_TYPE(ATPCompletionProcPtr) ATPCompletionUPP;
	typedef REGISTER_UPP_TYPE(XPPCompletionProcPtr) XPPCompletionUPP;
	typedef REGISTER_UPP_TYPE(AttnRoutineProcPtr) AttnRoutineUPP;

	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct WDSElement
	{
		short entryLength; /**< */
		Ptr entryPtr;	   /**< */
	} WDSElement;		   /**<*/

	typedef struct WDSElement WDSElement;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct NTElement
	{
		AddrBlock netAddress; /**< network address of entity*/
		char filler;		  /**< */
		char entityData[];	  /**< Object, Type & Zone*/
	} NTElement;			  /**< */

	typedef struct NTElement NTElement;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct NamesTableEntry
	{
		Ptr qNext;	   /**< ptr to next NTE*/
		NTElement nt;  /**< */
	} NamesTableEntry; /**< */

	typedef struct NamesTableEntry NamesTableEntry;
	typedef CALLBACK_API_REGISTER68K(Boolean, MPPProtocolHandlerProcPtr,
									 (Ptr SCCAddr1, Ptr SCCAddr2, Ptr MPPLocalVars,
									  Ptr nextFreeByteInRHA,
									  Ptr ReadPacketAndReadRestPtr,
									  short numBytesLeftToReadInPacket));
	typedef CALLBACK_API_REGISTER68K(Boolean, DDPSocketListenerProcPtr,
									 (Ptr SCCAddr1, Ptr SCCAddr2, Ptr MPPLocalVars,
									  Ptr nextFreeByteInRHA,
									  Ptr ReadPacketAndReadRestPtr,
									  UInt8 packetDestinationNumber,
									  short numBytesLeftToReadInPacket));
	typedef REGISTER_UPP_TYPE(MPPProtocolHandlerProcPtr) MPPProtocolHandlerUPP;
	typedef REGISTER_UPP_TYPE(DDPSocketListenerProcPtr) DDPSocketListenerUPP;
	/**
		MPPProtocolHandlerProcs and  DDPSocketListenerProcs cannot be written
		in or called from a high-level language without the help of mixed mode
		or assembly glue because they use the following parameter-passing
	   conventions:

		typedef Boolean (*MPPProtocolHandlerProcPtr)(Ptr SCCAddr1, Ptr SCCAddr2,
				Ptr MPPLocalVars, Ptr nextFreeByteInRHA, Ptr
	   ReadPacketAndReadRestPtr, short numBytesLeftToReadInPacket);

			In:
				=>  SCCAddr1                    A0.L
				=>  SCCAddr2                    A1.L
				=>  MPPLocalVars                A2.L
				=>  nextFreeByteInRHA           A3.L
				=>  ReadPacketAndReadRestPtr    A4.L
				=>  numBytesLeftToReadInPacket  D1.W
			Out:
				<=  Boolean                     Z bit of CCR

		typedef Boolean (*DDPSocketListenerProcPtr)(Ptr SCCAddr1, Ptr SCCAddr2,
				Ptr MPPLocalVars, Ptr nextFreeByteInRHA, Ptr
	   ReadPacketAndReadRestPtr, UInt8 packetDestinationNumber, short
	   numBytesLeftToReadInPacket);

			In:
				=>  SCCAddr1                    A0.L
				=>  SCCAddr2                    A1.L
				=>  MPPLocalVars                A2.L
				=>  nextFreeByteInRHA           A3.L
				=>  ReadPacketAndReadRestPtr    A4.L
				=>  packetDestinationNumber     D0.B
				=>  numBytesLeftToReadInPacket  D1.W
			Out:
				<=  Boolean                     Z bit of CCR

	*/
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct MPPparms
	{
	} MPPParms; /**< */

	typedef struct MPPparms MPPparms;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct LAPparms
	{
		char protType;	/**< ALAP protocol type*/
		char filler;	/**< */
		Ptr wdsPointer; /**< Ptr to write data structure*/
		Ptr handler;	/**< Ptr to protocol handler routine*/
	} LAPptrs;			/**<*/

	typedef struct LAPparms LAPparms;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct DDPparms
	{
		char socket;	   /**< Socket number*/
		char checksumFlag; /**< Check sum flag*/
		Ptr wdsPointer;	   /**< Pointer to write data structure*/
		Ptr listener;	   /**< Pointer to write data structure or*/
	} DDPptrs;			   /**<*/

	typedef struct DDPparms DDPparms;
	union NBPPtrs
	{
		Ptr ntQElPtr;
		Ptr entityPtr;
	};
	typedef union NBPPtrs NBPPtrs;
	union LookupConfirmParams
	{
		UInt8 verifyFlag;
		struct
		{
			void *retBuffPtr;
			short retBuffSize;
			short maxToGet;
			short numGotten;
		} Lookup;
		struct
		{
			AddrBlock confirmAddr;
			UInt8 newSocket;
			SInt8 filler; /**    Filler for proper byte alignment*/
		} Confirm;
	};
	typedef union LookupConfirmParams LookupConfirmParams;
	/**
	<pre>union {
	char verifyFlag; 134
	struct {
	Ptr retBuffPtr; 434
	short retBuffSize; 238
	short maxToGet; 240
	short numGotten; 242
	struct {
	AddrBlock confirmAddr; 434
	char newSocket; 138
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct NBPparms
	{
		char interval; /**< Retry interval*/
		char count;	   /**< Retry count*/
		Ptr ntQElPtr;  /**< */
		Ptr entityPtr; /**< */
	} NBPPtrs;		   /**<*/

	typedef struct NBPparms NBPparms;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct SetSelfparms
	{
		char newSelfFlag; /**< Self-send toggle flag*/
		char oldSelfFlag; /**< Previous self-send state*/
	} SetSelfparms;		  /**< */

	typedef struct SetSelfparms SetSelfparms;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct NBPKillparms
	{
		Ptr nKillQEl; /**< Ptr to i/o queue element to cancel*/
	} NBPKillparms;	  /**< */

	typedef struct NBPKillparms NBPKillparms;

	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct GetAppleTalkInfoParm
	{
		short version;		/**< Requested info version*/
		Ptr varsPtr;		/**< Pointer to  MPP vars*/
		Ptr DCEPtr;			/**< Pointer to MPP DCE*/
		short portID;		/**< Port number (..)*/
		long configuration; /**< -bit configuration word*/
		short selfSend;		/**< Non-zero if SelfSend is*/
		short netLo;		/**< Low value of network range*/
		short netHi;		/**< High value of network range*/
		long ourAdd;		/**< Our -bit AppleTalk*/
		long routerAdd;		/**< -bit address of (last)*/
		short numOfPHs;		/**< Max number of protocol*/
		short numOfSkts;	/**< Max number of static sockets*/
		short numNBPEs;		/**< Max concurrent NBP*/
		Ptr nTQueue;		/**< Pointer to registered name*/
		short LAlength;		/**< length in bytes of data link*/
		Ptr linkAddr;		/**< Data link address returned*/
		Ptr zoneName;		/**< Zone name returned*/
	} GetAppleTalkInfoParm; /**< */

	typedef struct GetAppleTalkInfoParm GetAppleTalkInfoParm;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ATalkClosePrepParm
	{
		Ptr appName;	  /**< Ptr to application name in*/
	} ATalkClosePrepParm; /**< */

	typedef struct ATalkClosePrepParm ATalkClosePrepParm;
	union MPPParamBlock
	{
		MPPparms MPP; /**General MPP parms*/
		LAPparms LAP; /**ALAP calls*/
		DDPparms DDP; /**DDP calls*/
		NBPparms NBP; /**NBP calls*/
		SetSelfparms SETSELF;
		NBPKillparms NBPKILL;
		GetAppleTalkInfoParm GAIINFO;
		ATalkClosePrepParm ATALKCLOSE;
	};

	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct XPPPrmBlk
	{
		short sessRefnum; /**< Offset to session refnum*/
		char aspTimeout;  /**< Timeout for ATP*/
		char aspRetry;	  /**< Retry count for ATP*/
		short cbSize;	  /**< Command block size*/
		Ptr cbPtr;		  /**< Command block pointer*/
		short rbSize;	  /**< Reply buffer size*/
		Ptr rbPtr;		  /**< Reply buffer pointer*/
		short wdSize;	  /**< Write data size*/
		Ptr wdPtr;		  /**< Write data pointer*/
		char ccbStart[];  /**< CCB memory allocated for driver*/
	} XPPPrmBlk;		  /**< */

	typedef struct XPPPrmBlk XPPPrmBlk;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ASPGetparmsBlk
	{
		short aspMaxCmdSize;  /**< For SPGetParms*/
		short aspQuantumSize; /**< */
		short numSesss;		  /**< */
	} ASPGetparmsBlk;		  /**< */

	typedef struct ASPGetparmsBlk ASPGetparmsBlk;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ASPAbortPrm
	{
		Ptr abortSCPPtr; /**< SCB Pointer for AbortOS*/
	} ASPAbortPrm;		 /**< */

	typedef struct ASPAbortPrm ASPAbortPrm;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ASPOpenPrm
	{
		short sessRefnum;	  /**< Offset to session refnum*/
		char aspTimeout;	  /**< Timeout for ATP*/
		char aspRetry;		  /**< Retry count for ATP*/
		AddrBlock serverAddr; /**< Server address block*/
		Ptr scbPointer;		  /**< SCB pointer*/
		Ptr attnRoutine;	  /**< Attention routine pointer*/
	} ASPOpenPrm;			  /**< */

	typedef struct ASPOpenPrm ASPOpenPrm;
	typedef ASPOpenPrm *ASPOpenPrmPtr;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct AFPLoginPrm
	{
		short sessRefnum;		/**< Offset to session refnum*/
		char aspTimeout;		/**< Timeout for ATP*/
		char aspRetry;			/**< Retry count for ATP*/
		short cbSize;			/**< Command block size*/
		Ptr cbPtr;				/**< Command block pointer*/
		short rbSize;			/**< Reply buffer size*/
		Ptr rbPtr;				/**< Reply buffer pointer*/
		AddrBlock afpAddrBlock; /**< Block in AFP login*/
		Ptr afpSCBPtr;			/**< SCB pointer in AFP login*/
		Ptr afpAttnRoutine;		/**< Routine pointer in AFP login*/
		char ccbFill[];			/**< CCB memory allocated for driver;/**<*/
	} AFPLoginPrm;				/**< */

	typedef struct AFPLoginPrm AFPLoginPrm;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct XCallParam
	{
		short xppSubCode;	 /**< */
		char xppTimeout;	 /**< Retry interval (seconds)*/
		char xppRetry;		 /**< Retry count*/
		short filler;		 /**< */
		Ptr zipBuffPtr;		 /**< Pointer to buffer (must be */
		short zipNumZones;	 /**< No. of zone names in this response*/
		char zipLastFlag;	 /**< Non-zero if no more zones*/
		char filler;		 /**< Filler*/
		char zipInfoField[]; /**< On initial call, set first word to zero*/
	} XCallParam;			 /**< */

	typedef struct XCallParam XCallParam;
	/**
	<pre>
	 * \note <pre>The .XPP Driver provides these functions that return information about
	zones:
	•The GetMyZone function returns the AppleTalk zone name of the node on
	which your application is running. This function works for both extended
	and nonextended networks.
	•The GetLocalZones function returns a list of zone names on the network
	that includes the node on which your application is running. This function
	works for extended networks only.
	•The GetZoneList function returns a complete list of zones on the internet.
	Before the AppleTalk Phase 2 version of The .XPP Driver , you had to
	use the AppleTalk Transaction Protocol (ATP) to obtain zone information
	and request it directly from a router. The Zone Information Protocol (ZIP)
	functions provided by the new version of The .XPP Driver make it much
	easier for you to obtain this information. To ensure compatibility with
	future versions of AppleTalk, you should always use the functions described
	in above to obtain zone information.
	For the GetMyZone , the GetLocalZones , and the GetZoneList
	functions, The .XPP Driver uses the xCallParam variant to the XPP
	parameter block.
	As for all other AppleTalk Manager preferred interface functions, the
	MPW interface calls the Device Manager function known as PBControl to
	implement these ZIP protocol functions. The qLink, qType, ioTrap,
	ioCmdAddr, and ioVRefNum fields are filled in by the Device Manager ;
	your application should not have to set or read these fields. The ioResult
	field returns the result of the function. If you call the function
	asynchronously, the Device Manager sets this field to 1 as soon as you
	call the function, and it changes the field to the actual result code when the
	function completes execution. The ioCompletion field is a pointer to a
	completion routine that you can provide; the Device Manager calls your
	completion routine when it completes execution of the PBControl function.
	If you are not providing a completion routine, specify NIL for this field.
	The value of the ioRefNum field is returned by the OpenDriver function;
	you must provide this value in each call to an .XPP driver routine. The
	csCode and xppSubCode fields specify the command to be executed; the MPW
	Pascal interface fills in these fields for you.The .XPP zone information
	functions do not use the cmdResult field.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	union XPPParamBlock
	{
		XPPPrmBlk XPP;			/**< */
		ASPGetparmsBlk GETPARM; /**< */
		ASPAbortPrm ABORT;		/**< */
		ASPOpenPrm OPEN;		/**< */
		AFPLoginPrm LOGIN;		/**< */
		XCallParam XCALL;		/**< */
	} XPPParamBlock;			/**< */

	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ATPparms
	{
	} ATPparms; /**< */

	typedef struct ATPparms ATPparms;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct SendReqparms
	{
		char filler;	 /**< numOfBuffs*/
		char timeOutVal; /**< Timeout interval*/
		char numOfResps; /**< Number of responses actually*/
		char retryCount; /**< Number of retries*/
		short intBuff;	 /**< Used internally for NSendRequest*/
		char TRelTime;	 /**< */
	} SendReqparms;		 /**< */

	typedef struct SendReqparms SendReqparms;

	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ATPmisc1
	{
		char bitMap;	 /**< Bitmap received*/
		char numOfBuffs; /**< Number of responses being sent*/
		char rspNum;	 /**< Sequence number*/
	} uo;				 /**<*/

	typedef struct ATPmisc1 ATPmisc1;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ATPmisc2
	{
		char filler;   /**< */
		char bdsSize;  /**< Number of BDS elements*/
		short transID; /**< Transaction ID received*/
	} ATPmisc;		   /**< */

	typedef struct ATPmisc2 ATPmisc2;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct Killparms
	{
		Ptr aKillQEl; /**< Ptr to i/o queue element to cancel*/
	} Killparms;	  /**< */

	typedef struct Killparms Killparms;
	/**
	<pre>
	 * \note <pre>The .ATP Driver maintains a timer, called the release timer, for each
	call to the ATPSndRsp function that is part of an exactly-once (XO)
	transaction. If the timer expires before the transaction is complete (that
	is, before the socket receives the transaction release packet), the driver
	completes the ATPSndRsp function. Before AppleTalk Phase 2, the release
	timer was always set to 30 seconds. To set the other connection end's
	release timer to another value, set bit 2 of the atpFlags field in the
	parameter block for the ATPSndRequest or the PNSendRequest function
	and add a new byte field to the parameter block at offset 50-the TRelTime
	field. (The ATPSndRequest and PNSendRequest functions use the
	SendRequestParm variant of the ATP parameter block.)
	The lower three bits of the TRelTime field indicate the time to which the
	release timer is to be set, as follows:
	TRelTime Setting of
	field release timer
	000 30 seconds
	001 1 minute
	010 2 minutes
	011 4 minutes
	100 8 minutes
	The nodes at both ends of the ATP connection must be running AppleTalk
	Phase 2 drivers for this feature to work.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	union ATPParamBlock
	{
		ATPParms ATP;	   /**<  General ATP parms*/
		SendReqParms SREQ; /**<  sendrequest parms*/
		ATPmisc OTH;	   /**<  and a few others*/
		ATPmisc OTH;	   /**<  and a few others*/
		Killparms KILL;	   /**<  and a few others*/
	} ATPParamBlock;	   /**< */

#if CALL_NOT_IN_CARBON
	/**
	 *  NewATalkTransitionEventUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	ATalkTransitionEventUPP
	NewATalkTransitionEventUPP(ATalkTransitionEventProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppATalkTransitionEventProcInfo = 0x00000FF1
	}; /** 4_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
	inline ATalkTransitionEventUPP
	NewATalkTransitionEventUPP(ATalkTransitionEventProcPtr userRoutine)
	{
		return (ATalkTransitionEventUPP)NewRoutineDescriptor(
			(ProcPtr)(userRoutine), uppATalkTransitionEventProcInfo,
			GetCurrentArchitecture());
	}
#else
#define NewATalkTransitionEventUPP(userRoutine)                  \
	(ATalkTransitionEventUPP) NewRoutineDescriptor(              \
		(ProcPtr)(userRoutine), uppATalkTransitionEventProcInfo, \
		GetCurrentArchitecture())
#endif
#endif

	/**
	 *  NewMPPCompletionUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	MPPCompletionUPP
	NewMPPCompletionUPP(MPPCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppMPPCompletionProcInfo = 0x00009802
	}; /** register no_return_value Func(4_bytes:A0) */
#ifdef __cplusplus
	inline MPPCompletionUPP NewMPPCompletionUPP(MPPCompletionProcPtr userRoutine)
	{
		return (MPPCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
													  uppMPPCompletionProcInfo,
													  GetCurrentArchitecture());
	}
#else
#define NewMPPCompletionUPP(userRoutine)                                       \
	(MPPCompletionUPP)                                                         \
		NewRoutineDescriptor((ProcPtr)(userRoutine), uppMPPCompletionProcInfo, \
							 GetCurrentArchitecture())
#endif
#endif

	/**
	 *  NewATPCompletionUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	ATPCompletionUPP
	NewATPCompletionUPP(ATPCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppATPCompletionProcInfo = 0x00009802
	}; /** register no_return_value Func(4_bytes:A0) */
#ifdef __cplusplus
	inline ATPCompletionUPP NewATPCompletionUPP(ATPCompletionProcPtr userRoutine)
	{
		return (ATPCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
													  uppATPCompletionProcInfo,
													  GetCurrentArchitecture());
	}
#else
#define NewATPCompletionUPP(userRoutine)                                       \
	(ATPCompletionUPP)                                                         \
		NewRoutineDescriptor((ProcPtr)(userRoutine), uppATPCompletionProcInfo, \
							 GetCurrentArchitecture())
#endif
#endif

	/**
	 *  NewXPPCompletionUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	XPPCompletionUPP
	NewXPPCompletionUPP(XPPCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppXPPCompletionProcInfo = 0x00009802
	}; /** register no_return_value Func(4_bytes:A0) */
#ifdef __cplusplus
	inline XPPCompletionUPP NewXPPCompletionUPP(XPPCompletionProcPtr userRoutine)
	{
		return (XPPCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
													  uppXPPCompletionProcInfo,
													  GetCurrentArchitecture());
	}
#else
#define NewXPPCompletionUPP(userRoutine)                                       \
	(XPPCompletionUPP)                                                         \
		NewRoutineDescriptor((ProcPtr)(userRoutine), uppXPPCompletionProcInfo, \
							 GetCurrentArchitecture())
#endif
#endif

	/**
	 *  NewAttnRoutineUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	AttnRoutineUPP
	NewAttnRoutineUPP(AttnRoutineProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppAttnRoutineProcInfo = 0x00061002
	}; /** register no_return_value Func(2_bytes:D0, 2_bytes:D1) */
#ifdef __cplusplus
	inline AttnRoutineUPP NewAttnRoutineUPP(AttnRoutineProcPtr userRoutine)
	{
		return (AttnRoutineUPP)NewRoutineDescriptor(
			(ProcPtr)(userRoutine), uppAttnRoutineProcInfo, GetCurrentArchitecture());
	}
#else
#define NewAttnRoutineUPP(userRoutine)                                       \
	(AttnRoutineUPP)                                                         \
		NewRoutineDescriptor((ProcPtr)(userRoutine), uppAttnRoutineProcInfo, \
							 GetCurrentArchitecture())
#endif
#endif

	/**
	 *  NewMPPProtocolHandlerUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	MPPProtocolHandlerUPP
	NewMPPProtocolHandlerUPP(MPPProtocolHandlerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppMPPProtocolHandlerProcInfo = 0x0000007F
	}; /** SPECIAL_CASE_PROCINFO(7) */
#ifdef __cplusplus
	inline MPPProtocolHandlerUPP
	NewMPPProtocolHandlerUPP(MPPProtocolHandlerProcPtr userRoutine)
	{
		return (MPPProtocolHandlerUPP)NewRoutineDescriptor(
			(ProcPtr)(userRoutine), uppMPPProtocolHandlerProcInfo,
			GetCurrentArchitecture());
	}
#else
#define NewMPPProtocolHandlerUPP(userRoutine)                                   \
	(MPPProtocolHandlerUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),        \
												 uppMPPProtocolHandlerProcInfo, \
												 GetCurrentArchitecture())
#endif
#endif

	/**
	 *  NewDDPSocketListenerUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	DDPSocketListenerUPP
	NewDDPSocketListenerUPP(DDPSocketListenerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppDDPSocketListenerProcInfo = 0x0000008F
	}; /** SPECIAL_CASE_PROCINFO(8) */
#ifdef __cplusplus
	inline DDPSocketListenerUPP
	NewDDPSocketListenerUPP(DDPSocketListenerProcPtr userRoutine)
	{
		return (DDPSocketListenerUPP)NewRoutineDescriptor(
			(ProcPtr)(userRoutine), uppDDPSocketListenerProcInfo,
			GetCurrentArchitecture());
	}
#else
#define NewDDPSocketListenerUPP(userRoutine)                                  \
	(DDPSocketListenerUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),       \
												uppDDPSocketListenerProcInfo, \
												GetCurrentArchitecture())
#endif
#endif

	/**
	 *  DisposeATalkTransitionEventUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposeATalkTransitionEventUPP(ATalkTransitionEventUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeATalkTransitionEventUPP(ATalkTransitionEventUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposeATalkTransitionEventUPP(userUPP) \
	DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  DisposeMPPCompletionUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposeMPPCompletionUPP(MPPCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeMPPCompletionUPP(MPPCompletionUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposeMPPCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  DisposeATPCompletionUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposeATPCompletionUPP(ATPCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeATPCompletionUPP(ATPCompletionUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposeATPCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  DisposeXPPCompletionUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposeXPPCompletionUPP(XPPCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeXPPCompletionUPP(XPPCompletionUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposeXPPCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  DisposeAttnRoutineUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposeAttnRoutineUPP(AttnRoutineUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeAttnRoutineUPP(AttnRoutineUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposeAttnRoutineUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  DisposeMPPProtocolHandlerUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposeMPPProtocolHandlerUPP(MPPProtocolHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeMPPProtocolHandlerUPP(MPPProtocolHandlerUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposeMPPProtocolHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  DisposeDDPSocketListenerUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposeDDPSocketListenerUPP(DDPSocketListenerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposeDDPSocketListenerUPP(DDPSocketListenerUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposeDDPSocketListenerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  InvokeATalkTransitionEventUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	long
	InvokeATalkTransitionEventUPP(long eventCode, ATQEntryPtr qElem,
								  void *eventParameter,
								  ATalkTransitionEventUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline long InvokeATalkTransitionEventUPP(long eventCode, ATQEntryPtr qElem,
											  void *eventParameter,
											  ATalkTransitionEventUPP userUPP)
	{
		return (long)CALL_THREE_PARAMETER_UPP(userUPP,
											  uppATalkTransitionEventProcInfo,
											  eventCode, qElem, eventParameter);
	}
#else
#define InvokeATalkTransitionEventUPP(eventCode, qElem, eventParameter,        \
									  userUPP)                                 \
	(long)CALL_THREE_PARAMETER_UPP((userUPP), uppATalkTransitionEventProcInfo, \
								   (eventCode), (qElem), (eventParameter))
#endif
#endif

/**
 *  InvokeMPPCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeMPPCompletionUPP(__A0, __A1)
#endif
	void
	InvokeMPPCompletionUPP(MPPPBPtr thePBptr, MPPCompletionUPP userUPP)
		ONEWORDINLINE(0x4E91);
#if !OPAQUE_UPP_TYPES && \
	(!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
	inline void InvokeMPPCompletionUPP(MPPPBPtr thePBptr,
									   MPPCompletionUPP userUPP)
	{
		CALL_ONE_PARAMETER_UPP(userUPP, uppMPPCompletionProcInfo, thePBptr);
	}
#else
#define InvokeMPPCompletionUPP(thePBptr, userUPP) \
	CALL_ONE_PARAMETER_UPP((userUPP), uppMPPCompletionProcInfo, (thePBptr))
#endif
#endif

/**
 *  InvokeATPCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeATPCompletionUPP(__A0, __A1)
#endif
	void
	InvokeATPCompletionUPP(ATPPBPtr thePBptr, ATPCompletionUPP userUPP)
		ONEWORDINLINE(0x4E91);
#if !OPAQUE_UPP_TYPES && \
	(!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
	inline void InvokeATPCompletionUPP(ATPPBPtr thePBptr,
									   ATPCompletionUPP userUPP)
	{
		CALL_ONE_PARAMETER_UPP(userUPP, uppATPCompletionProcInfo, thePBptr);
	}
#else
#define InvokeATPCompletionUPP(thePBptr, userUPP) \
	CALL_ONE_PARAMETER_UPP((userUPP), uppATPCompletionProcInfo, (thePBptr))
#endif
#endif

/**
 *  InvokeXPPCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeXPPCompletionUPP(__A0, __A1)
#endif
	void
	InvokeXPPCompletionUPP(XPPParmBlkPtr thePBptr, XPPCompletionUPP userUPP)
		ONEWORDINLINE(0x4E91);
#if !OPAQUE_UPP_TYPES && \
	(!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
	inline void InvokeXPPCompletionUPP(XPPParmBlkPtr thePBptr,
									   XPPCompletionUPP userUPP)
	{
		CALL_ONE_PARAMETER_UPP(userUPP, uppXPPCompletionProcInfo, thePBptr);
	}
#else
#define InvokeXPPCompletionUPP(thePBptr, userUPP) \
	CALL_ONE_PARAMETER_UPP((userUPP), uppXPPCompletionProcInfo, (thePBptr))
#endif
#endif

/**
 *  InvokeAttnRoutineUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeAttnRoutineUPP(__D0, __D1, __A0)
#endif
	void
	InvokeAttnRoutineUPP(short sessRefnum, short attnBytes, AttnRoutineUPP userUPP)
		ONEWORDINLINE(0x4E90);
#if !OPAQUE_UPP_TYPES && \
	(!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
	inline void InvokeAttnRoutineUPP(short sessRefnum, short attnBytes,
									 AttnRoutineUPP userUPP)
	{
		CALL_TWO_PARAMETER_UPP(userUPP, uppAttnRoutineProcInfo, sessRefnum,
							   attnBytes);
	}
#else
#define InvokeAttnRoutineUPP(sessRefnum, attnBytes, userUPP)                \
	CALL_TWO_PARAMETER_UPP((userUPP), uppAttnRoutineProcInfo, (sessRefnum), \
						   (attnBytes))
#endif
#endif

	/**
	 *  InvokeMPPProtocolHandlerUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	Boolean
	InvokeMPPProtocolHandlerUPP(Ptr SCCAddr1, Ptr SCCAddr2, Ptr MPPLocalVars,
								Ptr nextFreeByteInRHA, Ptr ReadPacketAndReadRestPtr,
								short numBytesLeftToReadInPacket,
								MPPProtocolHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
	(!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
	inline Boolean InvokeMPPProtocolHandlerUPP(Ptr SCCAddr1, Ptr SCCAddr2,
											   Ptr MPPLocalVars,
											   Ptr nextFreeByteInRHA,
											   Ptr ReadPacketAndReadRestPtr,
											   short numBytesLeftToReadInPacket,
											   MPPProtocolHandlerUPP userUPP)
	{
		return (Boolean)CALL_SIX_PARAMETER_UPP(
			userUPP, uppMPPProtocolHandlerProcInfo, SCCAddr1, SCCAddr2, MPPLocalVars,
			nextFreeByteInRHA, ReadPacketAndReadRestPtr, numBytesLeftToReadInPacket);
	}
#else
#define InvokeMPPProtocolHandlerUPP(                                      \
	SCCAddr1, SCCAddr2, MPPLocalVars, nextFreeByteInRHA,                  \
	ReadPacketAndReadRestPtr, numBytesLeftToReadInPacket, userUPP)        \
	(Boolean) CALL_SIX_PARAMETER_UPP(                                     \
		(userUPP), uppMPPProtocolHandlerProcInfo, (SCCAddr1), (SCCAddr2), \
		(MPPLocalVars), (nextFreeByteInRHA), (ReadPacketAndReadRestPtr),  \
		(numBytesLeftToReadInPacket))
#endif
#endif

	/**
	 *  InvokeDDPSocketListenerUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	Boolean
	InvokeDDPSocketListenerUPP(Ptr SCCAddr1, Ptr SCCAddr2, Ptr MPPLocalVars,
							   Ptr nextFreeByteInRHA, Ptr ReadPacketAndReadRestPtr,
							   UInt8 packetDestinationNumber,
							   short numBytesLeftToReadInPacket,
							   DDPSocketListenerUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
	(!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
	inline Boolean InvokeDDPSocketListenerUPP(
		Ptr SCCAddr1, Ptr SCCAddr2, Ptr MPPLocalVars, Ptr nextFreeByteInRHA,
		Ptr ReadPacketAndReadRestPtr, UInt8 packetDestinationNumber,
		short numBytesLeftToReadInPacket, DDPSocketListenerUPP userUPP)
	{
		return (Boolean)CALL_SEVEN_PARAMETER_UPP(
			userUPP, uppDDPSocketListenerProcInfo, SCCAddr1, SCCAddr2, MPPLocalVars,
			nextFreeByteInRHA, ReadPacketAndReadRestPtr, packetDestinationNumber,
			numBytesLeftToReadInPacket);
	}
#else
#define InvokeDDPSocketListenerUPP(                                      \
	SCCAddr1, SCCAddr2, MPPLocalVars, nextFreeByteInRHA,                 \
	ReadPacketAndReadRestPtr, packetDestinationNumber,                   \
	numBytesLeftToReadInPacket, userUPP)                                 \
	(Boolean) CALL_SEVEN_PARAMETER_UPP(                                  \
		(userUPP), uppDDPSocketListenerProcInfo, (SCCAddr1), (SCCAddr2), \
		(MPPLocalVars), (nextFreeByteInRHA), (ReadPacketAndReadRestPtr), \
		(packetDestinationNumber), (numBytesLeftToReadInPacket))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewATalkTransitionEventProc(userRoutine) \
	NewATalkTransitionEventUPP(userRoutine)
#define NewMPPCompletionProc(userRoutine) NewMPPCompletionUPP(userRoutine)
#define NewATPCompletionProc(userRoutine) NewATPCompletionUPP(userRoutine)
#define NewXPPCompletionProc(userRoutine) NewXPPCompletionUPP(userRoutine)
#define NewAttnRoutineProc(userRoutine) NewAttnRoutineUPP(userRoutine)
#define NewMPPProtocolHandlerProc(userRoutine) \
	NewMPPProtocolHandlerUPP(userRoutine)
#define NewDDPSocketListenerProc(userRoutine) \
	NewDDPSocketListenerUPP(userRoutine)
#define CallATalkTransitionEventProc(userRoutine, eventCode, qElem, \
									 eventParameter)                \
	InvokeATalkTransitionEventUPP(eventCode, qElem, eventParameter, userRoutine)
#define CallMPPCompletionProc(userRoutine, thePBptr) \
	InvokeMPPCompletionUPP(thePBptr, userRoutine)
#define CallATPCompletionProc(userRoutine, thePBptr) \
	InvokeATPCompletionUPP(thePBptr, userRoutine)
#define CallXPPCompletionProc(userRoutine, thePBptr) \
	InvokeXPPCompletionUPP(thePBptr, userRoutine)
#define CallAttnRoutineProc(userRoutine, sessRefnum, attnBytes) \
	InvokeAttnRoutineUPP(sessRefnum, attnBytes, userRoutine)
#define CallMPPProtocolHandlerProc(                                          \
	userRoutine, SCCAddr1, SCCAddr2, MPPLocalVars, nextFreeByteInRHA,        \
	ReadPacketAndReadRestPtr, numBytesLeftToReadInPacket)                    \
	InvokeMPPProtocolHandlerUPP(SCCAddr1, SCCAddr2, MPPLocalVars,            \
								nextFreeByteInRHA, ReadPacketAndReadRestPtr, \
								numBytesLeftToReadInPacket, userRoutine)
#define CallDDPSocketListenerProc(                                          \
	userRoutine, SCCAddr1, SCCAddr2, MPPLocalVars, nextFreeByteInRHA,       \
	ReadPacketAndReadRestPtr, packetDestinationNumber,                      \
	numBytesLeftToReadInPacket)                                             \
	InvokeDDPSocketListenerUPP(SCCAddr1, SCCAddr2, MPPLocalVars,            \
							   nextFreeByteInRHA, ReadPacketAndReadRestPtr, \
							   packetDestinationNumber,                     \
							   numBytesLeftToReadInPacket, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON

	/**
	\brief Open XPP driver

	<pre>OpenXPP opens the XPP driver.
</pre>
* \returns <pre>an operating system Error Code .
noErr(0) No error
portInUse (-97) Port B is already in use
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	OpenXPP(short *xppRefnum);

	/**
	\brief Initiate a workstation/server session

	<pre>ASPOpenSession initiates a session between a workstation and a server.
xParamBlock is a pointer to a parameter block structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←csCode short 226AlwaysASPOpenSession
←sessRefnum short 228Session reference number
←aspTimeout char 130Retry interval in seconds
←aspRetry char 131Number of retries
←serverAddr long 432Server socket address
←scbPointer Ptr 436Pointer to session control block
←attnRoutine Ptr 440Pointer to attention routine
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
aspBadVersNum (-1066) Sever cannot support the offered version number
aspNoMoreSess (-1068) Driver cannot support another session
aspNoservers (-1069) No servers at that address, or the server did not
respond to the request
aspParamErr (-1070) Server returned bad (positive) error code
aspServerBusy (-1071) Server cannot open another session
reqAborted (-1105) OpenSess was aborted by an AbortOS
</pre>
* \note <pre> SessRefnum is a unique number identifying the open session between the
workstation and the server. The SessRefnum is returned when the function
completes successfully and is used in all calls to identify the session.
ASPTimeOut is the interval in seconds between retries of the open session
request.
ASPRetry is the number of retries that will be attempted.
ServerAddr is the network identifier or address of the socket on which the
server is listening.
SCBPointer points to a nonrelocatable block of data for the session control
block (SCB) that the .XPP driver reserves for use in maintaining an open
session. The SCB size is defined by the constant scbMemSize. The SCB is a
locked block and as long as the session is open, the SCB cannot be modified in
any way by the application. There is one SCB for each open session. This
block can be reused when an ASPCloseSession call is issued and completed
for that session, or when the session is indicated as closed through return of
aspParamErr as the result of a call for that session.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	ASPOpenSession(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Close a workstation/server session

	<pre>ASPCloseSession closes a session between a workstation and a server.
xParamBlock is a pointer to a parameter block structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←csCode short 226AlwaysASPCloseSession
←sessRefnum short 228Session reference number
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
aspParamErr (-1070) Server returned bad (positive) error code
aspSessClosed (-1072) Session already in process of closing
</pre>
* \note <pre> This call aborts any calls that are active on the session, closes the session,
and calls the attention routine, if any, with an attention code of zero (zero is
invalid as a real attention code).
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	ASPCloseSession(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Abort a pending ASPOpenSession  call

	<pre>ASPAbortOS aborts a pending ASPOpenSession call.
xParamBlock is a pointer to a parameter block structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←csCode short 226AlwaysASPAbortOS
←abortSCBPointer short 228Pointer to session control block
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code .
cbNotFound (-1102) Control Block (SCB ) not found, Pointer did not point
to an open session SCB
</pre>
* \note <pre>The aborted ASPOpenSession call will return a reqAborted error.
AbortSCBPointer points to the original SCB used in the pending
ASPOpenSession call.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	ASPAbortOS(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Get three ASP parameters

	<pre>ASPGetParms returns three ASP parameters. This call does not require an
open session.
xParamBlock is a pointer to a parameter block structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←csCode short 226AlwaysASPGetParms
←aspMaxCmdSize short 228Maximum size of command block
←aspQuantumSize short 230Maximum data size
←numSess short 232Number of sessions
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code .
</pre>
* \note <pre>aspMaxCmdSize is the maximum size of a command that can be sent to the
server.
ASPQuantumSize is the maximum size of data that can be transferred to the
server in a Write request or from the server in a command reply.
NumSess is the number of concurrent sessions supported by the driver.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	ASPGetParms(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Close every active session

	<pre>ASPCloseAll closes every session that the driver has active, aborting all
active requests and invoking the attention routines where provided.
xParamBlock is a pointer to a parameter block structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←csCode short 226Always ASPCloseAll
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code .
</pre>
* \note <pre>This call should be used carefully. ASPCloseAll can be used as a system
level resource for making sure all sessions are closed prior to closing the
driver.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	ASPCloseAll(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Transfer data on a  session

	<pre>ASPUserWrite transfers data on a session. It is one of the two main calls
that can be used to transfer data on an ASP session. It returns data in two
different places. Four bytes of data are returned in the cmdResult field and a
variable size reply buffer is also returned.
xParamBlock is a pointer to a parameter block structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←cmdResult long 418ASP command result
←csCode short 226AlwaysASPUserWrite
←sessRefnum short 228Session reference number
←aspTimeout char 130Retry interval in seconds
←cbSize short 232Command block size
←cbPtr Ptr 434Command block pointer
↔rbSize short 238Reply buffer size and reply size
←rbPtr Ptr 440Reply buffer pointer
←wdSize short 244Write data size
←wdPtr Ptr 446Write data pointer
←ccbStart record 296 50Start of memory for CCB
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code .
aspBufTooSmall (-1067) Reply is bigger than response buffer; the buffer will
be filled, data will be truncated
aspParamErr (-1070) Server returned bad (positive) error code
aspSessClosed (-1072) Session already in process of closing
aspSizeErr (-1073) Command block size is buffer than MaxCmdSize
</pre>
* \note <pre> CmdResult is four bytes of data returned by the server.
SessRefnum is the session reference number returned in the
ASPOpenSession call
ASPTimeOut is the interval in seconds between retries of the call. Notice
that there is no aspRetry field (retries are infinite). The command will be
retried at the prescribed interval until completion or the session is closed.
CBSize is the size in bytes of the command data that is to be written on the
session. The size of the command block must not exceed the value of
aspMaxCmdSize returned by the ASPGetParms call. Note that this buffer
is not the data to be written by the command but only the data of the
command itself.
CBPtr points to the command data.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	ASPUserWrite(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Send a command to the server

	<pre>ASPUserCommand sends a command to the server on a session.
xParamBlock is a pointer to a parameter block structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←cmdResult long 418ASP command result
←csCode short 226AlwaysASPUserCommand
←sessRefnum short 228Session number
←aspTimeout char 130Retry interval in seconds
←cbSize short 232Command block size
←cbPtr Ptr 434Command block pointer
↔rbSize short 238Reply buffer and reply size
←rbPtr Ptr 440Reply buffer pointer
←ccbStart record 150 50Start of memory for CCB
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code .
aspBufTooSmall (-1067) Reply is bigger than response buffer; the buffer will
be filled, data will be truncated
aspParamErr (-1070) Server returned bad (positive) error code
aspSessClosed (-1072) Session already in process of closing
aspSizeErr (-1073) Command block size is buffer than MaxCmdSize
</pre>
* \note <pre> SessRefnum is the session reference number returned in the
ASPOpenSession call.
ASPTimeOut is the interval in seconds between retries of the call. Notice
that there is no aspRetry field (retries are infinite). The command will be
retried at the prescribed interval until completion or the session is closed.
CBSize is the size in bytes of the command data that is to be written on the
session. The size of the command block must not exceed the value of
aspMaxCmdSize returned by the ASPGetParms call.
CBPtr points to the command data.
RBSize is passed and indicates the size of the reply buffer in bytes expected
by the command. RBSize is also returned and indicates the size of the reply
that was actually returned.
RBPtr points to the reply buffer.
CCBStart is the start of the memory to be used by the .XPP driver for the
command control block. The size of this block is equal to a maximum of 150
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	ASPUserCommand(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Get server status

	<pre>ASPGetStatus returns server status.This call is also used as GetServerInfo
at the AFP level. This call is unique in that it transfers data over the network
without having a session open. This call does not pass any data but requests that
server status be returned.
xParamBlock is a pointer to a parameter block structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←csCode short 226AlwaysASPGetStatus
←aspTimeout char 130Retry interval in seconds
←aspRetry char 131Number of retries
←serverAddr short 232Server socket address
↔rbSize short 238Reply buffer and reply size
←rbPtr Ptr 440Reply buffer pointer
←ccbStart record 150 50Start of memory for CCB
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code .
aspBufTooSmall (-1067) Reply is bigger than response buffer; the buffer will
be filled, data will be truncated
aspNoServer (-1069) No response from server at address used in call
</pre>
* \note <pre> ASPTimeOut is the interval in seconds between retries of the call.
ASPRetry is the number of retries that will be attempted.
ServerAddr is the network identifier or address of the socket on which the
server is listening.
RBSize is passed and indicates the size of the reply buffer in bytes expected
by the command. RBSize is also returned and indicates the size of the reply
that was actually returned.
RBPtr points to the reply buffer.
CCBStart is the start of the memory to be used by the .XPP driver for the
command control block. The size of this block is equal to a maximum of 150
bytes.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	ASPGetStatus(XPPParmBlkPtr thePBptr, Boolean async);

#define ASPGetStatusSync(paramBlock) ASPGetStatus((paramBlock), false)

	/**
	\brief Pass an AFP command to the server

	<pre>The AFPCommand function can have one of the following formats:
• General
• Login
• AFPWrite
• AFPRead
General Command Format
The general command format for the AFPCommad function passes an AFP
command to the server. This format is used for all AFP calls except AFPLogin,
AFPRead, and AFPWrite.
xParamBlock is a pointer to an XPPParamBlock structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←cmdResult long 418AFP command result
←csCode short 226Always afpCall
←sessRefNum short 228Session reference number
←aspTimeout char 130Retry interval in seconds
←cbSize short 232Command buffer siz
←cbPtr Ptr 434Command buffer
↔rbSize short 238Reply buffer size and reply size
←rbPtr Ptr 440Reply buffer pointer
↔wdSize short 244Write data size
←wdPtr Ptr 446Write data pointer
←ccbStart 296 bytes 296 50Start of memory for CCB
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to function asynchronously. See Async I/O .
</pre>
* \returns <pre>an operating system Error Code .
aspBufTooSmall (-1067) Reply is bigger than response buffer; the buffer will
be filled, data will be truncated
aspParamErr (-1070) Invalid session number; session has been closed
aspSessClosed (-1072) Session already in process of closing
aspSizeErr (-1073) Command block size is bigger than MaxCmdSize
afpParmErr (-5019) AFP command block size is equal to zero. This error
will also be returned if the command byte in the
command block is equal to 0 or 0xFF (255) or
GetSrvrStatus(15)
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	AFPCommand(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Get AppleTalk zone names on the local network

	<pre>GetLocalZones returns a list of all the zone names on the local network-that
is, the network that includes the node on which your application is running.
thePBptr is a pointer to an XPPParamBlock structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Routine selector; always xCall
→xppSubCode short 228Routine selector; zipGetMyZone
→xppTimeOut char 130Retry interval in seconds
→xppRetry char 131Retry count
→zipBuffPtr long 434Pointer to data buffer
←zipNumZones short 238Number of names returned
→zipLastFlag char 140Nonzero if no more names
→zipInfoField 70 bytes 7042For use by ZIP; first word set to 0
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
noBrideErr (-93) No Router is available
reqFailed (-1096) Request to contact router failed; retry count
exceeded
tooManyReqs (-1097) Too many concurrent requests
noDataArea (-1104) Too many outstanding ATP calls
</pre>
* \note <pre>The ioResult field returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode and xppSubCode fields are routine selectors
and are automatically set by the high-level language interface to xCall and
zipGetLocalZones for this function. The xppTimeOut field specifies the
amount of time, in seconds, that The .ATP Driver should wait between
attempts to obtain the data. A value of 3 or 4 for the xppTimeOut field
generally gives good results. The xppRetry field specifies the number of
times The .ATP Driver should attempt to obtain the data before returning
the reqFailed (request failed) result code. A value of 3 or 4 for the
xppRetry field usually works well.
The zipBuffPtr field is a pointer to a 578-byte data buffer that you must
allocate. ZIP returns the zone names into this buffer as a packed array of
high-level language strings. The zipNumZones parameter returns the
number of zone names that ZIP placed in the data buffer.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	GetLocalZones(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Returns a list of all the zone names on the internet

	<pre>GetZoneList returns a complete list of all the zone names on the internet.
thePBptr is a pointer to an XPPParamBlock structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Routine selector; always xCall
→xppSubCode short 228Routine selector; zipGetMyZone
→xppTimeOut char 130Retry interval in seconds
→xppRetry char 131Retry count
→zipBuffPtr long 434Pointer to data buffer
←zipNumZones short 238Number of names returned
→zipLastFlag char 140Nonzero if no more names
→zipInfoField 70 bytes 7042For use by ZIP; first word set to 0
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
noBrideErr (-93) No Router is available
reqFailed (-1096) Request to contact router failed; retry count
exceeded
tooManyReqs (-1097) Too many concurrent requests
noDataArea (-1104) Too many outstanding ATP calls
</pre>
* \note <pre>To obtain a list of only the zone names on the local network, use the
GetLocalZones function instead.
The ioResult field returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode and xppSubCode fields are routine selectors
and are automatically set by the high-level language interface to xCall and
zipGetZoneList for this function. The xppTimeOut field specifies the amount
of time, in seconds, that The .ATP Driver should wait between attempts to
obtain the data. A value of 3 or 4 for the xppTimeOut field generally gives
good results. The xppRetry field specifies the number of times
The .ATP Driver should attempt to obtain the data before returning the
reqFailed (request failed) result code. A value of 3 or 4 for the xppRetry
field usually works well.
The zipBuffPtr field is a pointer to a 578-byte data buffer that you must
allocate. ZIP returns the zone names into this buffer as high-level language
strings. The zipNumZones parameter returns the number of zone names that
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	GetZoneList(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Get AppleTalk zone name

	<pre>GetMyZone returns only the AppleTalk zone name of the node on which the
application is running.
thePBptr is a pointer to an XPPParamBlock structure. The relevant fields are
as follows:
Out-In Name Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Routine selector; always xCall
→xppSubCode short 228Routine selector; zipGetMyZone
→xppTimeOut char 130Retry interval in seconds
→xppRetry char 131Retry count
→zipBuffPtr long 434Pointer to data buffer
→zipInfoField 70 bytes 7042For use by ZIP; first word set to 0
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
noBridgeErr (-93) No Router is available
reqFailed (-1096) Request to contact router failed; retry count
exceeded
tooManyReqs (-1097) Too many concurrent requests
noDataArea (-1104) Too many outstanding ATP calls
</pre>
* \note <pre>The GetMyZone function returns only the AppleTalk zone name of the node
on which your application is running.
The ioResult field returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode and xppSubCode fields are routine selectors
and are automatically set by the high-level language interface to xCall and
zipGetMyZone for this function. The xppTimeOut field specifies the amount
of time, in seconds, that The .ATP Driver should wait between attempts to
obtain the data. A value of 3 or 4 for the xppTimeOut field generally gives
good results. The xppRetry field specifies the number of times
The .ATP Driver should attempt to obtain the data before returning the
reqFailed (request failed) result code. A value of 3 or 4 for the xppRetry
field usually works well.
The zipBuffPtr field is a pointer to a 33-byte data buffer that you must
allocate. ZIP returns the zone name into this buffer as a high-level language
string. The zipInfoField field is a 70-byte data buffer that you must allocate
for use by ZIP. You must set the first word of this buffer to 0 before you
call the GetMyZone function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	GetMyZone(XPPParmBlkPtr thePBptr, Boolean async);

	/**
	\brief Add a protocol handler to the protocol table

	<pre>PAttachPH adds the protocol handler pointed to by the handler field of the
LAPparms structure to the node's protocol table.
thePBptr iis a pointer to an LAPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226always attachPH
→ protType char 128ALAP protocol type
→ handler Ptr 430protocol handler
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
lapProtErr (-94) Error attaching protocol type
</pre>
* \note <pre>handler is the protocol handler to add to the protocol table. protType
specifies what kind of frame the protocol handler can service. After
PAttachPH is called, the protocol handler is called for each incoming
frame whose ALAP protocol type equals protType .
Most programs will never need to call ALAP, because higher-level
protocols will automatically call ALAP as necessary. If you do want to send a
frame directly via ALAP, call the PWriteLAP function. There is no
PReadLAP function. If you want to read ALAP frames, you must call
PAttachPH to add your protocol handler to the node's protocol handler
table. The ALAP module will examine every incoming frame and call your
protocol handler for each frame received with the correct ALAP protocol.
When your program no longer wants to receive frames with a particular
ALAP protocol type value, it can call PDetachPH to remove the
corresponding protocol handler from the protocol handler table.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PAttachPH(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Remove protocol type and handler from protocol table

	<pre>PDetachPH removes from the node's protocol table the specified ALAP
protocol type and corresponding protocol handler.
thePBptr iis a pointer to an LAPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226always detachPH
→ protType char 128ALAP protocol type
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
lapProtErr (-94) Error attaching protocol type
</pre>
* \note <pre>protType specifies the type of the protocol handler to remove.
Most programs will never need to call ALAP, because higher-level
protocols will automatically call ALAP as necessary. If you do want to send a
frame directly via ALAP, call the PWriteLAP function. There is no
PReadLAP function. If you want to read ALAP frames, you must call
PAttachPH to add your protocol handler to the node's protocol handler
table. The ALAP module will examine every incoming frame and call your
protocol handler for each frame received with the correct ALAP protocol.
When your program no longer wants to receive frames with a particular
ALAP protocol type value, it can call PDetachPH to remove the
corresponding protocol handler from the protocol handler table.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PDetachPH(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Send a frame to another node

	<pre>PWriteLAP sends a frame to another node
thePBptr iis a pointer to an LAPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226always writeLAP
→ wdsPointer Ptr 430write data structure
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
ddpLengthErr (-92) Packet length exceeds maximum
lapProtErr (-94) Invalid ALAP protocol type
excessCollsns (-95) No CTS received after 32 RTS's
</pre>
* \note <pre>The frame data and destination of the frame are described by the write data
structure pointed to by wdsPointer. The first two data bytes of an ALAP
frame sent to another computer using the AppleTalk Manager must
indicate the length of the frame in bytes. The ALAP protocol type must be in
the range 1 to 127.
Most programs will never need to call ALAP, because higher-level
protocols will automatically call ALAP as necessary. If you do want to send a
frame directly via ALAP, call the PWriteLAP function. There is no
PReadLAP function. If you want to read ALAP frames, you must call
PAttachPH to add your protocol handler to the node's protocol handler
table. The ALAP module will examine every incoming frame and call your
protocol handler for each frame received with the correct ALAP protocol.
When your program no longer wants to receive frames with a particular
ALAP protocol type value, it can call PDetachPH to remove the
corresponding protocol handler from the protocol handler table.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PWriteLAP(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Add a socket and listener to the socket table

	<pre>POpenSkt adds a socket and its socket listener to the socket table
thePBptr iis a pointer to an DDPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226always openSkt
↔ socket char 128socket number
→ listener Ptr 430socket listener
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
ddpSktErr (-91) Socket error
</pre>
* \note <pre>If the socket parameter is nozero, it must be in the range 64 to 127, and it
specifies the socket's number; if socket is 0, POpenSkt opens a socket
with a socket number in the range 128 to 254, and returns it in the socket
parameter. listener contains a pointer to the socket listener.
POpenSkt will return ddpSktErr if you pass the number of an already
opened socket, if you pass a socket number greater than 127, or if the
socket table is full (the socket table can hold a maximum of 12 sockets).
Before it can use a socket, the program must call POpenSkt which adds a
socket and its socket listener to the socket table. When a client is finished
using a socket, call PCloseSkt , which removes the socket's entry from the
socket table. To send a datagram via DDP, call PWriteDDP . If you want to
read DDP datagrams, you must write your own socket listener. DDP will
send every incoming datagram for that socket to your socket listener.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	POpenSkt(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Remove specified socket from the socket table

	<pre>PCloseSkt removes the entry of the specified socket from the socket table.
thePBptr iis a pointer to an DDPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226always closeSkt
→ socket char 128socket number
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
ddpSktErr (-91) Socket error
</pre>
* \note <pre>If you pass a socket number of 0, or if you attempt to close a socket that
isn't open, PCloseSkt will return a ddpSktErr .
Before it can use a socket, the program must call POpenSkt which adds a
socket and its socket listener to the socket table. When a client is finished
using a socket, call PCloseSkt , which removes the socket's entry from the
socket table. To send a datagram via DDP, call PWriteDDP . If you want to
read DDP datagrams, you must write your own socket listener. DDP will
send every incoming datagram for that socket to your socket listener.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PCloseSkt(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Send a datagram to another socket

	<pre>PWriteDDP sends a datagram to another socket.
thePBptr iis a pointer to an DDPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226 always closeSkt
→ socket char 128 socket number
→ checksumFlag char 129 checksum flag
→ wdsPointer Ptr 430 write data structure
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
ddpSktErr (-91) Socket Error
ddpLenErr (-92) Datagram length too big
noBridgeErr (-93) No bridge found
</pre>
* \note <pre>wdsPointer points to a write data structure containing the datagram and the
address of the destination socket. If the checksumFlag is TRUE,
PWriteDDP will compute the checksum for all datagrams requiring long
headers.
Before it can use a socket, the program must call POpenSkt which adds a
socket and its socket listener to the socket table. When a client is finished
using a socket, call PCloseSkt , which removes the socket's entry from the
socket table. To send a datagram via DDP, call PWriteDDP . If you want to
read DDP datagrams, you must write your own socket listener. DDP will
send every incoming datagram for that socket to your socket listener.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PWriteDDP(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Add the name and address of an entity to names table

	<pre>PRegisterName adds the name and address of an entity to the node's names
table.
thePBptr is a pointer to an NBPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226always registerName
→ interval char 128retry interval
↔ count char 129retry count
→ ntQElPtr Ptr 430names table element pointer
→ verifyFlag char 134set if verify needed
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nbpDuplicate (-1027) Duplicate name already exists
nbpNISErr (-1029) Error opening names information socket
</pre>
* \note <pre>ntQElPtr points to a names table entry containing the entity's name and
internet address (built using NBPSetNTE ). Meta-characters aren't
allowed in the object and type fields of the entity name; the zone field,
however, must contain the meta-character "*". If verifyFlag is TRUE,
PRegisterName checks on the network to see if the name is already in
use, and returns a result code of nbpDuplicate if so. interval and count
contain the retry interval in eight-tick units and the retry count. When a
retry is made, the count field is modified.
Warning: The names table entry passes to PRegisterName remains the
property of NBP until removed from the names table. Don't
attempt to remove or modify it. If you've allocated memory
using a NewHandle call, you must lock it as long as the name is
registered.
Warning: verifyFlag should normally be set before calling
PRegisterName .
When an entity wants to communicate via an AppleTalk network, it should
call PRegisterName to place its name and internet address in the names
table. When an entity no longer wants to communicate on the network, or is
being shut down, it should call PLookupName , which returns a list of all
entities with the name you specify. If you already know the address of an
entity, and want only to confirm that it still exists, call PConfirmName .
PConfirmName is more efficient than PLookupName in terms of
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PRegisterName(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Return the addresses of all entities with a specified name

	<pre>PLookupName returns the addresses of all entities with a specified name.
thePBptr is a pointer to an NBPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226always lookupName
→ interval char 128retry interval
↔ count char 129retry count
→ entityPtr Ptr 430pointer to entity name
→ retBuffPtr Ptr 434pointer to buffer
→ retBuffSize short 240buffer size in bytes
→ maxToGet short 240matches to get
← numGotten short 242matches found
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nbpBuffOvr (-1024) Buffer overflow
</pre>
* \note <pre>PLookupName returns the addresses of all entities with a specified name.
entityPtr points to the entity's name (built using NBPSetEntity ).
Meta-characters are allowed in the entity name. retBuffPtr and retBuffSize
contain the location and size of an area of memory in which the tuples
describing the entity names and their corresponding addresses should be
returned. maxToGet indicates the maiximum number of matching names to
find addresses for; the actual number of addresses found is returned in
numGotten . interval and count contain the retry interval and the retry
count. PLookupName completes when either the number of matches is
equal to or greater than maxToGet , or the retry count has been exceeded.
The count field is decremented for each retransmission.
numGotten is first set to 0 and then incremented with each match found.
You can test the value in this field, and can start examining the received
address in the buffer while the lookup continues.
Use NBPExtract to extract entity names from the buffer pointed to by
retBuffPtr .
When an entity wants to communicate via an AppleTalk network, it should
call PRegisterName to place its name and internet address in the names
table. When an entity no longer wants to communicate on the network, or is
being shut down, it should call PLookupName , which returns a list of all
entities with the name you specify. If you already know the address of an
entity, and want only to confirm that it still exists, call PConfirmName .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PLookupName(MPPPBPtr thePBptr, Boolean async);

#define PLookupNameSync(paramBlock) PLookupName((paramBlock), false)

	/**
	\brief Confirm that an entity still exists

	<pre>PConfirmName confirms that an entity known by name and address still
exists (is still entered in the names directory).
thePBptr is a pointer to an NBPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226always confirmName
→ interval char 128retry interval
↔ count char 129retry count
→ entityPtr Ptr 430pointer to entity name
→ confirmAddr AddrBlock 434entity address
← newSocket char 138socket number
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nbpNoConfirm (-1025) Name not confirmed
nbpConfDiff (-1026) Name confirmed for a different socket
</pre>
* \note <pre>entityPtr points to the entity's name (built using NBPSetEntity ).
confirmAddr specifies the address to be confirmed. No meta-characters
are allowed in the entity name. interval and count contain the retry
interval and the retry count. The socket number of the entity is returned in
newSocket .
When an entity wants to communicate via an AppleTalk network, it should
call PRegisterName to place its name and internet address in the names
table. When an entity no longer wants to communicate on the network, or is
being shut down, it should call PLookupName , which returns a list of all
entities with the name you specify. If you already know the address of an
entity, and want only to confirm that it still exists, call PConfirmName .
PConfirmName is more efficient than PLookupName in terms of
network traffic.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PConfirmName(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Remove an entity name for the names table

	<pre>PRemoveName removes an entity name from the names table of the given
entity's node.
thePBptr iis a pointer to an NBPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226always removeName
→ entityPtr Ptr 430pointer to entity name
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nbpNotFound (-1028) Name not found
</pre>
* \note <pre>When an entity wants to communicate via an AppleTalk network, it should
call PRegisterName to place its name and internet address in the names
table. When an entity no longer wants to communicate on the network, or is
being shut down, it should call PLookupName , which returns a list of all
entities with the name you specify. If you already know the address of an
entity, and want only to confirm that it still exists, call PConfirmName .
PConfirmName is more efficient than PLookupName in terms of
network traffic.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PRemoveName(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Enable or disable intranode delivery

	<pre>PSetSelfSend enables or disables the intranode deliver feature of the
AppleTalk Manager .
thePBptr is a pointer to an MPPParamBlock structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
→csCode short 226Always PSetSelfSend
→newSelfFlag short 228New SelfSend flag
←oldSelfFlag char 129Old SelfSend flag
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
</pre>
* \note <pre>If newSelfFlag is nonzero, the feature will be enabled; otherwise it will be
disabled. The previous value of the flag will be returned in oldSelfFlag.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PSetSelfSend(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Kill a PLookUpName , PRegisterName , or PConfirmName

	<pre>PKillNBP aborts an outstanding PLookUpName , PRegisterName , or
PConfirmName request.
thePBptr is a pointer to an ATPParamBlock structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
→csCode short 226Always PKillNBP
→aKillQEl Ptr 128Pointer to a queue element
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
cbNotFound (-1102) aKIllQEl does not point to a valid NBP queue element
</pre>
* \note <pre>PKillNBP will abort an outstanding PLookUpName , PRegisterName ,
or PConfirmName request. To abort one of these calls, place a pointer to
the queue element of the call to abort in aKillQEl and issue the PKillNBP
call. The call will be completed with a reqAborted error.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PKillNBP(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief PGetAppleTalkInfo Obtain information about The .MPP Driver

	<pre>PGetAppleTalkInfo returns information about The .MPP Driver . If the
node on which your program is running happens also to be running AppleTalk
Internet Router software in the background, more than one set of .MPP global
variables may be in RAM. .
thePBptr is a pointer to a device control entry (DCE) structure. The relevant
fields are as follows:
Out-InName Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Always PGetAppleTalkInfo
→version short 228Version of function
←varsPtr long 430Pointer to .MPP globals
←dcePtr long 434Pointer to DCE for .MPP
←portID short 238Port number
←configuration long 440Configuration flags
←selfSend short 244Nonzero if self-send is enabled
←netLo short 246Low value of the network range
←netHi short 248High value of the network range
←ourAddr long 450Local 24-bit AppleTalk address
←routerAddr long 45424-bit address of router
←numOfPHs short 258Max number of protocol handlers
←numOfSkts short 260Max number of static sockets
←numNBPEs short 262Max concurrent NBP requests
←ntQueue long 464Pointer to registered names table
↔laLength short 268Length in bytes of data link address
(extended networks only)
→linkAddr long 470Pointer to data link address buffer
(extended networks only)
→zoneName long 474Pointer to zone name buffer
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
paramErr (-50) Version number is too high
</pre>
* \note <pre>To make sure you are obtaining information about The .MPP Driver that
handles application software, always use the PGetAppleTalkInfo function
rather than the Device Manager 's PBControl function. If you are using
assembly language or want to use the PBControl function, you must be
sure to use a device driver reference number of -10 for
The .MPP Driver
Field descriptions
ioResult The result of the function. When you execute the function
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PGetAppleTalkInfo(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Request permission to close The .MPP Driver

	<pre>PATalkClosePrep calls each routine listed in the AppleTalk Transition
Queue to request permission to close The .MPP Driver
thePBptr is a pointer to an .MPP parameter block structure. The relevant
fields are as follows:
Out-In Name Type SizeOffsetDescription
→csCode short 226Always PATalkClosePrep
←appName Ptr 428Pointer to application that denies request
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
closeErr (-24) Permission to close .MPP was denied
</pre>
* \note <pre>The PATalkClosePrep function calls each routine listed in the AppleTalk
Transition Queue to request permission to close The .MPP Driver .
If a routine in the AppleTalk Transition Queue denies permission to close
The .MPP Driver , that routine can return a pointer to a high-level
language string. The high-level language string should contain the name of
the application that placed the entry in the AppleTalk Transition Queue. The
PATalkClosePrep function returns that pointer in the appName field.
The function also returns the result code closeErr, indicating that the
calling routine has been denied permission to close The .MPP Driver . The
routine that called PATalkClosePrep can then display a dialog box telling
the user the name of the application that is currently using AppleTalk and
asking whether to close AppleTalk anyway.
The csCode parameter is a routine selector; it is always equal to
PATalkClosePrep for this function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PATalkClosePrep(MPPPBPtr thePBptr, Boolean async);

	/**
	\brief Open a socket for the purpose of receiving requests

	<pre>POpenATPSkt opens a socket for the purpose of receiving requests.
thePBptr iis a pointer to an ATPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226 always openATPSkt
↔ atpSocket char 128 socket number
→ addrBlock AddrBlock 430 socket request specification
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
tooManySkts (-1074) Too many responding sockets
noDataArea (-1104) Too many outstanding ATP calls
</pre>
* \note <pre>atpSocket contains the socket number of the socket to open. If it's 0, a
number is dynamically assigned and returned in atpSocket. addrBlock
contains a specification of the socket addresss from which requests will be
accepted. A 0 in the network number, node ID, or socket number field of
addrBlock means that requests will be accepted from every network, node,
or socket, respectively.
To send a request to another socket and get a response, call
PSendRequest . The call terminates when either an entire response is
received or a specified retry timeout interval elapses. To open a socket for
the purpose of responding to requests, call POpenATPSkt . Then call
PGetRequest to receive a request; when a request is received, the call is
completed. After receiving and servicing a request, call PSendResponse
to return response information. If you cannot or do not want to send the
entire response all at once, make a PSendResponse call to send some of
the response, and then call PAddResponse later to send the remainder of
the response. To close a socket opened for the purpose of sending responses,
call PCloseATPSkt .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	POpenATPSkt(ATPPBPtr thePBptr, Boolean async);

	/**
	\brief Close a specified socket

	<pre>PCloseATPSkt closes the socket whose number is specified in the atpSocket
parameter of the ATPparms structure, for the purpose of receiving requests.
thePBptr iis a pointer to an ATPparms structure.
Out-In Name Type SizeOffset Description
→ csCode short 226 always closeATPSkt
→ atpSocket char 128 socket number
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
noDataArea (-1104) Too many outstanding ATP calls
</pre>
* \note <pre>To send a request to another socket and get a response, call
PSendRequest . The call terminates when either an entire response is
received or a specified retry timeout interval elapses. To open a socket for
the purpose of responding to requests, call POpenATPSkt . Then call
PGetRequest to receive a request; when a request is received, the call is
completed. After receiving and servicing a request, call PSendResponse
to return response information. If you cannot or do not want to send the
entire response all at once, make a PSendResponse call to send some of
the response, and then call PAddResponse later to send the remainder of
the response. To close a socket opened for the purpose of sending responses,
call PCloseATPSkt .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PCloseATPSkt(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief Send a request to another socket and wait for response

	<pre>PSendRequest sends a request to another socket and waits for a reponse.
thePBptr iis a pointer to an SendReqparms structure.
Out-In Name Type SizeOffset Description
→ userData long 418 user bytes
← reqTID short 222 transaction ID used in request
→ csCode short 226 always sendRequest
← atpSocket char 128 bit map
↔ atpFlags char 129 control information
→ addrBlock AddrBlock 430 destination socket address
→ reqLength short 234 request size in bytes
→ reqPointer Ptr 436 pointer to request data
→ bdsPointer Ptr 440 pointer to response BDS
→ numOfBuffs char 144 number of responses expected
→ timeOutVal char 145 timeout interval
→ numOfResps char 146 number of responses received
→ retryCount char 147 number of retries
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
reqFailed (-1096) Retry count exceeded
tooManyReqs (-1097) Too many concurrent requests
noDataArea (-1104) Too many outstanding ATP calls
reqAborted (-1105) Request cancelled by user
</pre>
* \note <pre>userData contains the four user bytes. addrBlock indicates the socket to
which the request should be sent. reqLength and reqPointer contain the size
and location of the request too send. bdsPointer points to a response BDS
where the responses are to be returned; numOfBuffs indicates the number of
responses requested. The number of responses received is returned in
numOfResps . If a nonzero value is returned in numOfResps , you can
examine atpSocket to determine which packets of the transaction were
actually received. and to detect pieces for higher-level recovery.
timeOutVal indicates the number of seconds that PSendRequest should
wait for a response before resending the request. retryCount indicates the
maximum number or retries PSendRequest should attempt. The
end-of-message flag of atpFlags will be set if the EOM Bit is set in the last
packet received in a valid response sequence. The exactly-once flag should
be set if you want the request to be part of an exactly-once transaction.
To cancel a PSendRequest call, you need the transaction ID; it's returned
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PSendRequest(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief Receive a request sent by a PSendRequest  call

	<pre>PGetRequest sets up the mechanism to receive a request sent by a
PSendRequest call.
thePBptr iis a pointer to an ATPParamBlock structure.
Out-In Name Type SizeOffset Description
← userData long 418 user bytes
→ csCode short 226 always getRequest
→ atpSocket char 128 socket number
← atpFlags char 129 control information
← addrBlock AddrBlock 430 destination socket address
↔ reqLength short 234 request size in bytes
→ reqPointer Ptr 436 pointer to request data
← bitMap Ptr 440 bitmap
← transID short 248 transaction ID
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
badATPSkt (-1099) Bad responding socket
</pre>
* \note <pre>userData returns the four user bytes from the request. atpSocket contains
the socket number of the socket that should listen for a request. The
internet address of the socket from which the request was sent is returned
in addrBlock. reqLength and reqPointer indicate the size (in bytes) and
location of a buffer to store the incoming request. The actual size of the
request is returned in reqLength . The transaction bitmap and transaction ID
will be returned in bitMap and transID. The exactly-once flag in atpFlags
will be set if the request is part of an exactly-once transaction.
To send a request to another socket and get a response, call
PSendRequest . The call terminates when either an entire response is
received or a specified retry timeout interval elapses. To open a socket for
the purpose of responding to requests, call POpenATPSkt . Then call
PGetRequest to receive a request; when a request is received, the call is
completed. After receiving and servicing a request, call PSendResponse
to return response information. If you cannot or do not want to send the
entire response all at once, make a PSendResponse call to send some of
the response, and then call PAddResponse later to send the remainder of
the response. To close a socket opened for the purpose of sending responses,
call PCloseATPSkt .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PGetRequest(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief Send a response to a socket

	<pre>PSendResponse sends a response to a socket.
thePBptr iis a pointer to an ATPParamBlock structure.
Out-In Name Type SizeOffset Description
← userData long 418 user bytes from TRel
→ csCode short 226 always sendResponse
→ atpSocket char 128 socket number
→ atpFlags char 129 control information
→ addrBlock AddrBlock 430 response destination
→ bdsPointer Ptr 432 pointer to response BDS
→ numBuffs char 144 number of response packets being
sent
→ bdsSize Ptr 145 BDS size in elements
→ transID short 248 transaction ID
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
badATPSkt (-1099) Bad responding socket
badBuffNum (-1100) Sequence number out to range
noRelErr (-1101) No release received
noDataArea (-1104) Too many outstanding ATP calls
</pre>
* \note <pre>If the response was part of an exactly-once transaction, userData will
contain the user bytes from the TRel packet. atpSocket contains the socket
number from which the response should be sent. The end-of-message flag
in atpFlags should be set if the response contains the final packet in a
transaction composed of a group of packets and the number of responses is
less than requested. addrBlock indicates the address of the socket to which
the response should be sent. bdsPointer points to a response BDS containing
room for the maximum number of responses to be sent; bdsSize contains
this maximum number. numOfBuffs contains the number or response
packets to be sent in this call; you may wish to make PAddResponse calls
to complete the response. transID indicates the transaction ID of the
associated request.
During exactly-once transactions, PSendResponse doesn't complete until
either a TRel packet is received from the socket that made the request, or
the retry count is exceeded.
To send a request to another socket and get a response, call
PSendRequest . The call terminates when either an entire response is
received or a specified retry timeout interval elapses. To open a socket for
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PSendResponse(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief Send an additional response packet

	<pre>PAddResponse sends an additional response packet to a socket that has
already been send the initial part of a response via PSendResponse .
thePBptr iis a pointer to an ATPParamBlock structure.
Out-In Name Type SizeOffset Description
→ userData long 418 user bytes from TRel
→ csCode short 226 always addResponse
→ atpSocket char 128 socket number
→ atpFlags char 129 control information
→ addrBlock AddrBlock 430 response destination
→ reqLength short 234 response size
→ reqPointer Ptr 436 pointer to response
→ rspNum char 144 sequence number
→ transID short 248 transaction ID
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
badATPSkt (-1099) Bad responding socket
badBuffNum (-1100) Sequence number out to range
noSendResp (-1103) PAddResponse issued before PSendResponse
noDataArea (-1104) Too many outstanding ATP calls
</pre>
* \note <pre>userData contains the four user bytes. atpSocket contains the socket
number from which the response should be sent. The end-of-message flag
in atpFlags should be set if this response packet is the final packet in the
transaction composed of a group of packets and the number of responses is
less than requested. addrBlock indicates the socket to which the response
should be sent. reqLength and reqPointer contain the size (in bytes) and
location of the response to send; rspNum indicates the sequence number of
the response (in the range 0 to 7). transID must contain the transaction
ID.
Warning: If the transaction is part of an exactly-once transaction, the
buffer used in the PAddResponse call must not be altered or
released until the corresponding PSendResponse call has
completed.
To send a request to another socket and get a response, call
PSendRequest . The call terminates when either an entire response is
received or a specified retry timeout interval elapses. To open a socket for
the purpose of responding to requests, call POpenATPSkt . Then call
PGetRequest to receive a request; when a request is received, the call is
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PAddResponse(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief Dequeue a PSendRequest  call

	<pre>PRelTCB dequeues the specified PSendRequest call and returns the result
code reqAborted for the aborted call. The transaction ID can be obtained from
the reqTID field of the PSendRequest call; see PSendRequest for details.
thePBptr iis a pointer to an ATPParamBlock structure.
Out-In Name Type SizeOffset Description
→ csCode short 226 always relTCB
→ addrBlock AddrBlock 430 destination of request
→ transID short 248 transaction ID of request
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
cbNotFound (-1102) ATP control block not found
noDataArea (-1104) Too many outstanding ATP calls
</pre>
* \note <pre>To send a request to another socket and get a response, call
PSendRequest . The call terminates when either an entire response is
received or a specified retry timeout interval elapses. To open a socket for
the purpose of responding to requests, call POpenATPSkt . Then call
PGetRequest to receive a request; when a request is received, the call is
completed. After receiving and servicing a request, call PSendResponse
to return response information. If you cannot or do not want to send the
entire response all at once, make a PSendResponse call to send some of
the response, and then call PAddResponse later to send the remainder of
the response. To close a socket opened for the purpose of sending responses,
call PCloseATPSkt .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PRelTCB(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief Cancel a PSendResponse call

	<pre>In an exactly-once transaction, PRelRspCB cancels the specified
PSendResponse call, without waiting for the release timer to expire or a
TRel packet to be received. No error is returned for the PSendResponse call.
When called to cancel a transaction that isn't using exactly-once service,
PRelRspCB returns cbNotFound . The transaction ID can be obtained from
the reqTID field of the PSendResponse queue entry; see the description of
PSendResponse for details.
thePBptr iis a pointer to an ATPParamBlock structure.
Out-In Name Type SizeOffset Description
→ csCode short 226 always relRspCB
→ atpSocket char 128 socket number that request was
received on
→ addrBlock AddrBlock 430 destination of request
→ transID short 248 transaction ID of request
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
cbNotFound (-1102) ATP control block not found
</pre>
* \note <pre>To send a request to another socket and get a response, call
PSendRequest . The call terminates when either an entire response is
received or a specified retry timeout interval elapses. To open a socket for
the purpose of responding to requests, call POpenATPSkt . Then call
PGetRequest to receive a request; when a request is received, the call is
completed. After receiving and servicing a request, call PSendResponse
to return response information. If you cannot or do not want to send the
entire response all at once, make a PSendResponse call to send some of
the response, and then call PAddResponse later to send the remainder of
the response. To close a socket opened for the purpose of sending responses,
call PCloseATPSkt .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PRelRspCB(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief Send an ATP request to another socket

	<pre>PNSendRequest sends an ATP request to another socket.
thePBptr is a pointer to an ATPParamBlock structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
←userData long 418User bytes
←reqTID short 222Transaction ID used in request
→csCode short 226Always sendRequest
→atpSocket short 228Socket to send request on; current bitmap
↔atpFlags char 129control information
→addrBlock long 430Destination socket address
→reqLength short 234Request size in bytes
→reqPointer Ptr 436Pointer to request data
→bdsPointer Ptr 440Pointer to response BDS
←numOfBuffs char 144Number of responses expected
→timeOutVal char 145Timeout interval
→numOfResps char 146Number of responses received
→retryCount char 147Number of retries
←intBuff short 248Used internally
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
reqFailed (-1096) SendRequest failed: retry count exceeded
tooManyReqs (-1097) Too many concurrent requests
noDataArea (-1104) Too many outstanding ATP calls
reqAborted (-1105) Request canceled by user
</pre>
* \note <pre>The PNSendRequest call is functionally equivalent to the PSendRequest
call, however, PNSendRequest allows you to specify, in the atpSocket
field, the socket through which the request is to be sent. This socket must
have previously opened through an POpenATPSkt request (otherwise a
badATPSkt error will be returned). Note that PNSendRequest . Note that
PNSendRequest requires two additional bytes of memory at the end of the
parameter block, immediately following the retryCount. These bytes are
for the internal use of the AppleTalk Manager and should not be modified
while the PNSendRequest call is active.
There is a machine-dependent limit as to the number of of concurrent
PNSendRequests that can be active on a given socket. If this limit is
exceeded, the error tooManyReqs is returned.
One additional difference between PSendRequest and PNSendRequest is
that PNSendRequest is that a PNSendRequest can only be aborted by a
PKillSendReq call, whereas a PSendRequest can be aborted by either a
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PNSendRequest(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief Abort a PNSendRequest  or PSendRequest

	<pre>PKillSendReq aborts PNSendRequest or PSendRequest calls.
thePBptr is a pointer to an ATPParamBlock structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
→csCode short 226Always PKillSendRequest
→aKillQEl Ptr 144Pointer to a queue element
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
cbNotFound -1102 aKillQEl does not point to a SendReq or NSendReq
queue element
</pre>
* \note <pre>PKillSendReq is functionally equivalent to PRelTCB , except that it
takes different arguments, and will abort both PSendRequest and
PNSendRequest . To abort one of these calls, place a pointer to the queue
element of the call to abort in aKillQEl and issue the PKillSendReq .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PKillSendReq(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief Kill a PGetRequest

	<pre>PKillGetReq aborts a PGetRequest
thePBptr is a pointer to an ATPParamBlock structure. The relevant fields are
as follows:
Out-InName Type SizeOffsetDescription
→csCode short 226Always PKillGetReq
→aKillQEl Ptr 144Pointer to a queue element
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
cbNotFound (-1102) aKIllQEl does not point to a GetReq queue element
</pre>
* \note <pre>PKillGetReq will abort a specific outstanding PGetRequest call (as
opposed to closing the socket, which aborts all outstanding PGetRequest
calls on that socket). The call will be completed with a reqAborted error. To
abort a PGetRequest , place a pointer to the queue element of the call to
abort in aKillQEl and issue the PKillGetReq call.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	PKillGetReq(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief ATPKillAllGetReq Cancel all calls to ATPGetRequest

	<pre>ATPKillAllGetReq function cancels all pending asynchronous calls to the
ATPGetRequest function for the socket you specify with the atpSocket
parameter.
thePBptr is a pointer to an ATPParamBlock structure. The relevant fields are
as follows:
Out-In Name Type SizeOffsetDescription
→csCode short 226AlwaysATPKillAllGetReq
→atpSocket char 128Sockets for which to cancel all calls to
ATPGetRequest
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
cbNotFound (-1102) Control block not found; no pending asynchronous
calls
</pre>
* \note <pre>The ATPKillAllGetReq function also calls the completion routine for
each call to the ATPGetRequest function with the value reqAborted
(-1105) in the D0 register.
Unlike the ATPCloseSocket function, the ATPKillAllGetReq function
does not close the socket. You should call the ATPKillAllGetReq function
before closing a socket. The csCode parameter is a routine selector,
automatically set by the high-level language interface. It is always equal to
ATPKillAllGetReq for this function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	ATPKillAllGetReq(ATPPBPtr thePBPtr, Boolean async);

	/**
	\brief Build a single-frame write data structure

	<pre>BuildLAPwds builds a single-frame write data structure LAP WDS for use
with the LAPWrite call. Given a buffer of length frameLen pointed to by
dataPtr, it fills in the WDS pointed to by wdsPtr and sets the destination node
and protocol type as indicated by destHost and protoType, respectively.
wdsPtris the write data structure's address.
dataPtris a pointer to the data buffer.
destHost is the destination node.
protoType specifies the protocol type.
frameLen is the size of the data in bytes.
</pre>
* \returns <pre>none
</pre>
* \note <pre>The WDS indicated must contain at least two elements.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	void
	BuildLAPwds(Ptr wdsPtr, Ptr dataPtr, short destHost, short prototype,
				short frameLen);

	/**
	\brief Build a single-frame write data structure

	<pre>BuildDDPwds builds a single-frame write data structure DDP WDS for use
with the DDPWrite call. Given a header buffer of at least 17 bytes pointed to
by headerPtr, it fills in the WDS pointed to by wdsPtr and sets the destination
address and protocol type as indicated by destAddress and DDPtype,
respectively.
wdsPtris the write data structure's address
headerPtr is the header buffer's address
dataPtris a pointer to the data buffer
destAddress is the destination address
DDPType specifies the protocol type
dataLenis the size of the data in bytes
</pre>
* \returns <pre>none
</pre>
* \note <pre>The WDS indicated must contain at least three elements.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	void
	BuildDDPwds(Ptr wdsPtr, Ptr headerPtr, Ptr dataPtr, AddrBlock netAddr,
				short ddpType, short dataLen);

	/**
	\brief Build an NBP entity structure

	<pre>NBPSetEntity builds an NBP entity structure, for use with the
PLookupName and PConfirmName calls. Given a buffer of at least the size
of the EntityName data structure (99 bytes), this routine sets the indicated
object, type, and zone in that buffer
bufferis the EntityName data structure's address
nbpObject is the buffer object
nbpType is the buffer type
nbpZone is the buffer zone
</pre>
* \returns <pre>none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	void
	NBPSetEntity(Ptr buffer, ConstStr32Param nbpObject, ConstStr32Param nbpType,
				 ConstStr32Param nbpZone);

	/**
	\brief Build a Names Table Entry

	<pre>NBPSetNTE builds an NBP names table entry, for use with
PRegistername  call. Given a names table entry of at least the size of the
EntityName data structure plus nine bytes (108 bytes), this routine sets
the indicated object, type, zone and socket in that names table entry.
ntePtris the names table entry's address.
nbpObject is the names table entry object.
nbpType is the names table entry type.
nbpZone is the names table entry zone.
</pre>
* \returns <pre>none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	void
	NBPSetNTE(Ptr ntePtr, ConstStr32Param nbpObject, ConstStr32Param nbpType,
			  ConstStr32Param nbpZone, short socket);

	/**
	\brief GetBridgeAddress Get bridge's current address

	<pre>GetBridgeAddress returns the current address of a bridge.
</pre>
* \returns <pre>a short, the current address of the bridge.
</pre>
* \note <pre>A zero is returned in the low byte if there is no current address.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	short
	GetBridgeAddress(void);

	/**
	\brief Build a BDS

	<pre>BuildBDS builds a BDS, for use with ATP calls
bufPtris the BDS structure's address.
bdsPtris the BDS's address.
buffSize specifies the length of the data buffer.
</pre>
* \returns <pre>a short
</pre>
* \note <pre>The buffer will be broken up into pieces of maximum size (578 bytes).
The user bytes in the BDS are not modified by this routine. This routine is
provided only as a convenience, generally, the caller will be able to build
the BDS completely from a high-level language without it.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	short
	BuildBDS(Ptr buffPtr, Ptr bdsPtr, short buffSize);

	/**
	 *  MPPOpen()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	MPPOpen(void);

	/**
	\brief Add an entry to the queue

	<pre>LAPAddATQ adds an entry to the AppleTalk Transition Queue.
theATQEntry is a pointer to an ATQEntry data structure. The CallAddr field of the
data structure holds a pointer to the routine that AppleTalk calls for
any AppleTalk transition event.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
</pre>
* \note <pre>From assembly language, you add and remove AppleTalk Transition Queue
entries by placing a routine selector in the D0 register, placing a pointer to
your AppleTalk Transition Queue entry in the A0 register, and executing a
JSR instruction to an offset past the start of LAP Manager . The start of
LAP Manager is contained in the global variable LAPMgrPtr (0x0B18).
The offset to LAP Manager routines is given by the constant LAPMgrCall
(2).
Here is assembly-language code that adds or removes AppleTalk Transition
Queue entries:
LAPMgrPtr EQU 0x0B18 ;LAP Manager entry point
LAPMgrCall EQU 2 ;offset to LAP Manager
routines
MOVEQ #RSel,D0 ;place routine selector
; in D0 (23 to add an entry,
;24 to remove one)
MOVE.L LAPMgrPtr,A n;put pointer to LAP Mgr in A n
MOVE.L ATQEntry,A0 ;put ATQ entry in A0
JSR LAPMgrCall(A n);jump to start of LAP Mgr
;routines
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	LAPAddATQ(ATQEntryPtr theATQEntry);

	/**
	\brief Remove entry from  AppleTalk Transition Queue

	<pre>LAPRmvATQ removes an entry from the AppleTalk Transition Queue
theATQEntry is a pointer to an ATQEntry data structure.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
qErr(-1) Queue element not found
</pre>
* \note <pre>You must not call the LAPRmvATQ function at interrupt time or through a
callback routine. This restriction is to prevent any routine from removing
an entry from the AppleTalk Transition Queue while another routine is in
the process of adding or removing an entry.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	LAPRmvATQ(ATQEntryPtr theATQEntry);

	/**
	 *  ATPLoad()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPLoad(void);

	/**
	 *  ATPUnload()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPUnload(void);

	/**
	 *  NBPExtract()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	NBPExtract(Ptr theBuffer, short numInBuf, short whichOne, EntityName *abEntity,
			   AddrBlock *address);

	/**
	\brief Get caller's node ID and network number

	<pre>GetNodeAddress returns the current node ID and network number of the
caller.
myNode points to the caller's current network node ID.
myNetpoints to the current network number of the caller.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
noMPPErr (-3102) MPP driver not installed
</pre>
* \note <pre> If myNet contains 0, this means that a bridge has not yet been found.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	OSErr
	GetNodeAddress(short *myNode, short *myNet);

	/**
	\brief Is the .MPP driver loaded and running?

	<pre>IsMPPOpen returns TRUE if the .MPP driver is loaded and running.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	Boolean
	IsMPPOpen(void);

	/**
	\brief Is the .ATP driver loaded and running?

	<pre>IsATPOpen returns TRUE if the .ATP driver is loaded and running.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	Boolean
	IsATPOpen(void);

	/**
	\brief Call all routines with specified event code
	\param    infoPtr Address of your custom routine
	<pre>ATEvent calls all of the routines in the AppleTalk Transition Queue with the
AppleTalk transition event code you specify in the event parameter.
eventcan be any 4-byte character code that starts with an uppercase
letter-that is, any value in the range 0x041 00 00 00 through
0x05A FF FF FF
infoPtrpoint to any information that you want to make available to the
AppleTalk Transition Queue routines
</pre>
* \returns <pre>none
</pre>
* \note <pre>You can use the infoPtr parameter to point to any information that you
want to make available to the AppleTalk Transition Queue routines; for an
ADSP-open transition, for example, you might pass a pointer to the
parameter block used by the dspOpen routine. If you do not want to pass any
information to the AppleTalk Transition Queue routines, set the infoPtr
parameter to NIL.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	void
	ATEvent(long event, Ptr infoPtr);

	/**
	 *  ATPreFlightEvent()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPreFlightEvent(long event, long cancel, Ptr infoPtr);

/**
	The following routines are obsolete and will not be supported on
	PowerPC. Equivalent functionality is provided by the routines
	above.
*/
#endif /** CALL_NOT_IN_CARBON */

#if TARGET_CPU_68K
#if CALL_NOT_IN_CARBON
	/**
	 *  MPPClose()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	MPPClose(void);

	/**
	 *  LAPOpenProtocol()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	LAPOpenProtocol(ABByte theLAPType, Ptr protoPtr);

	/**
	 *  LAPCloseProtocol()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	LAPCloseProtocol(ABByte theLAPType);

	/**
	 *  LAPWrite()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	LAPWrite(ATLAPRecHandle abRecord, Boolean async);

	/**
	 *  LAPRead()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	LAPRead(ATLAPRecHandle abRecord, Boolean async);

	/**
	 *  LAPRdCancel()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	LAPRdCancel(ATLAPRecHandle abRecord);

	/**
	 *  DDPOpenSocket()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	DDPOpenSocket(short *theSocket, Ptr sktListener);

	/**
	 *  DDPCloseSocket()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	DDPCloseSocket(short theSocket);

	/**
	 *  DDPRead()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	DDPRead(ATDDPRecHandle abRecord, Boolean retCksumErrs, Boolean async);

	/**
	 *  DDPWrite()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	DDPWrite(ATDDPRecHandle abRecord, Boolean doChecksum, Boolean async);

	/**
	 *  DDPRdCancel()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	DDPRdCancel(ATDDPRecHandle abRecord);

	/**
	 *  ATPOpenSocket()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPOpenSocket(AddrBlock addrRcvd, short *atpSocket);

	/**
	 *  ATPCloseSocket()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPCloseSocket(short atpSocket);

	/**
	 *  ATPSndRequest()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPSndRequest(ATATPRecHandle abRecord, Boolean async);

	/**
	 *  ATPRequest()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPRequest(ATATPRecHandle abRecord, Boolean async);

	/**
	 *  ATPReqCancel()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPReqCancel(ATATPRecHandle abRecord, Boolean async);

	/**
	 *  ATPGetRequest()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPGetRequest(ATATPRecHandle abRecord, Boolean async);

	/**
	 *  ATPSndRsp()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPSndRsp(ATATPRecHandle abRecord, Boolean async);

	/**
	 *  ATPAddRsp()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPAddRsp(ATATPRecHandle abRecord);

	/**
	 *  ATPResponse()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPResponse(ATATPRecHandle abRecord, Boolean async);

	/**
	 *  ATPRspCancel()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	ATPRspCancel(ATATPRecHandle abRecord, Boolean async);

	/**
	 *  NBPRegister()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	NBPRegister(ATNBPRecHandle abRecord, Boolean async);

	/**
	 *  NBPLookup()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	NBPLookup(ATNBPRecHandle abRecord, Boolean async);

	/**
	 *  NBPConfirm()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	NBPConfirm(ATNBPRecHandle abRecord, Boolean async);

	/**
	 *  NBPRemove()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	NBPRemove(EntityPtr abEntity);

	/**
	 *  NBPLoad()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	NBPLoad(void);

	/**
	 *  NBPUnload()
	 *

	 *    \non_carbon_cfm   not available
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	NBPUnload(void);

#endif /** CALL_NOT_IN_CARBON */

#endif /** TARGET_CPU_68K */

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

#endif /** __APPLETALK__ */
* /   \carbon_lib not available *    \mac_os_x not available * /
	OSErr
	NBPConfirm(ATNBPRecHandle abRecord, Boolean async);

/**
 *  NBPRemove()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr NBPRemove(EntityPtr abEntity);

/**
 *  NBPLoad()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr NBPLoad(void);

/**
 *  NBPUnload()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr NBPUnload(void);

#endif /** CALL_NOT_IN_CARBON */

#endif /** TARGET_CPU_68K */

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

#endif																														  /** __APPLETALK__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ *	  /*/
	
								   #endif /** __APPLETALK__ */
	* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/ALL_NOT_IN_CARBON */

#endif /** TARGET_CPU_68K */

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

#endif																													  /** __APPLETALK__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/

							   #endif /** __APPLETALK__ */
	* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /
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

#endif																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										 /** __APPLETALK__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ *																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																													 /*/
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																												   
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																				  #endif /** __APPLETALK__ */
	* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*//*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * //*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/