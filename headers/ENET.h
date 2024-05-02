/**
     \file       ENET.h

    \brief   Ethernet Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Networking
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __ENET__
#define __ENET__

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

enum {
  ENetSetGeneral = 253, /*Set "general" mode*/
  ENetGetInfo = 252,    /*Get info*/
  ENetRdCancel = 251,   /*Cancel read*/
  ENetRead = 250,       /*Read*/
  ENetWrite = 249,      /*Write*/
  ENetDetachPH = 248,   /*Detach protocol handler*/
  ENetAttachPH = 247,   /*Attach protocol handler*/
  ENetAddMulti = 246,   /*Add a multicast address*/
  ENetDelMulti = 245    /*Delete a multicast address*/
};

enum {
  EAddrRType = FOUR_CHAR_CODE('eadr') /*Alternate address resource type*/
};

typedef struct EParamBlock EParamBlock;
typedef EParamBlock *EParamBlkPtr;
typedef CALLBACK_API_REGISTER68K(void, ENETCompletionProcPtr,
                                 (EParamBlkPtr thePBPtr));
typedef REGISTER_UPP_TYPE(ENETCompletionProcPtr) ENETCompletionUPP;
struct EParamBlock {
  QElem *qLink;                   /*General EParams*/
  short qType;                    /*queue type*/
  short ioTrap;                   /*routine trap*/
  Ptr ioCmdAddr;                  /*routine address*/
  ENETCompletionUPP ioCompletion; /*completion routine*/
  OSErr ioResult;                 /*result code*/
  StringPtr ioNamePtr;            /*->filename*/
  short ioVRefNum;                /*volume reference or drive number*/
  short ioRefNum;                 /*driver reference number*/
  short csCode;                   /*Call command code*/
  union {
    struct {
      short eProtType; /*Ethernet protocol type*/
      Ptr ePointer;    /*No support for PowerPC code*/
      short eBuffSize; /*buffer size*/
      short eDataSize; /*number of bytes read*/
    } EParms1;
    struct {
      Byte eMultiAddr[6]; /*Multicast Address*/
    } EParms2;
  } u;
};

#if CALL_NOT_IN_CARBON
/**
 *  NewENETCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
ENETCompletionUPP
NewENETCompletionUPP(ENETCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppENETCompletionProcInfo = 0x00009802
}; /* register no_return_value Func(4_bytes:A0) */
#ifdef __cplusplus
inline ENETCompletionUPP
NewENETCompletionUPP(ENETCompletionProcPtr userRoutine) {
  return (ENETCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppENETCompletionProcInfo,
                                                 GetCurrentArchitecture());
}
#else
#define NewENETCompletionUPP(userRoutine)                                      \
  (ENETCompletionUPP)                                                          \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppENETCompletionProcInfo,  \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeENETCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
DisposeENETCompletionUPP(ENETCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeENETCompletionUPP(ENETCompletionUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeENETCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeENETCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeENETCompletionUPP(__A0, __A1)
#endif
void
InvokeENETCompletionUPP(EParamBlkPtr thePBPtr, ENETCompletionUPP userUPP)
    ONEWORDINLINE(0x4E91);
#if !OPAQUE_UPP_TYPES &&                                                       \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
inline void InvokeENETCompletionUPP(EParamBlkPtr thePBPtr,
                                    ENETCompletionUPP userUPP) {
  CALL_ONE_PARAMETER_UPP(userUPP, uppENETCompletionProcInfo, thePBPtr);
}
#else
#define InvokeENETCompletionUPP(thePBPtr, userUPP)                             \
  CALL_ONE_PARAMETER_UPP((userUPP), uppENETCompletionProcInfo, (thePBPtr))
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewENETCompletionProc(userRoutine) NewENETCompletionUPP(userRoutine)
#define CallENETCompletionProc(userRoutine, thePBPtr)                          \
  InvokeENETCompletionUPP(thePBPtr, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON

			/** 
			\brief Send a data packet over Ethernet 
			
			<pre>EWrite uses The .ENET Driver to send a data packet over Ethernet.
thePBptr is a pointer to an EParamBlock structure. The relevant fields are as
follows:
Out-InName Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Always ENetWrite
→ePointer long 430Pointer to write-data structure
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to function asynchronously. See Async I/O .
</pre>
 * \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
eLenErr (-92) Packet too large or first entry of the write-data
structure did not contain the full 14-byte header
excessCollsns (-95) Hardware error
</pre>
 * \note <pre>You must first prepare a write-data structure that specifies the
destination address and the protocol type and contains the data that you want
to send. You place a pointer to the write-data structure in the ePointer
parameter. If you want to send a packet larger than 768 bytes, first call
the ESetGeneral function to put The .ENET Driver in
general-transmission mode. If the size of the packet you provide is less than
60 bytes, the driver adds pad bytes to the packet. Write-data structures are
described in Using a Write-Data Structure
The ioResult parameter returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode parameter is a routine selector that is set
automatically for you by the high-level language interface; it is always
equal to ENetWrite for this function
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EWrite(EParamBlkPtr thePBptr, Boolean async);


			/** 
			\brief Attach protocol handler to The .ENET Driver 
			
			<pre>EAttachPH serves two purposes: use it to attach to The .ENET Driver
your own protocol handler for a specific protocol type, or you can use it to
specify that The .ENET Driver should use the default protocol handler for a
particular protocol type. .
thePBptr is a pointer to an EParamBlock structure. The relevant fields are as
follows:
Out-InName Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Always ENetAttachPH
→eProtType short 228Ethernet protocol type
→ePointer long 430Pointer to protocol handler
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to function asynchronously. See Async I/O .
</pre>
 * \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
LAPProtErr (-94) Protocol handler is already attached or node's
protocol table is full.
</pre>
 * \note <pre>If you attach your own protocol handler, The .ENET Driver calls that
protocol handler each time it receives a packet with the protocol type you
specified. If you specify that The .ENET Driver should use the default
protocol handler, then you can use the ERead command to read packets with
that protocol type.
The ioResult parameter returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode parameter is a routine selector; it is
always equal to ENetAttachPH for this function.
You specify the protocol type in the eProtType parameter and provide a
pointer to the protocol handler in the ePointer parameter. If you specify NIL
for the ePointer parameter, then The .ENET Driver uses the default
protocol handler for that protocol type. Specify 0 for the eProtType
parameter to attach a protocol handler for the IEEE 802.3 protocol, which
uses protocol types 0 through 0x05DC
The LAP Manager calls the EAttachPH function with a protocol type of
0 and thus receives all 802.3 protocol packets. Instead of using the
EAttachPH function to install a protocol handler for an 802.3 Ethernet
protocol type, you should use the L802Attach routine. In the case of an
802.3 protocol packet, The .ENET Driver passes the packet to the
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EAttachPH(EParamBlkPtr thePBptr, Boolean async);


			/** 
			\brief Detach a protocol handler from  The .ENET Driver 
			
			<pre>EDetachPH detaches a protocol handler from The .ENET Driver .
thePBptr is a pointer to an EParamBlock structure. The relevant fields are as
follows:
Out-InName Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Always ENetDetachPH
→eProtType short 228Ethernet protocol type
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to function asynchronously. See Async I/O .
</pre>
 * \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
LAPProtErr (-94) Protocol handler is already attached or node's
protocol table is full.
</pre>
 * \note <pre>Once you have removed a protocol type from the node's protocol table with
this function, The .ENET Driver no longer delivers packets with that
protocol type. You specify the protocol type in the eProtType parameter.
The ioResult parameter returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode parameter is a routine selector that is set
automatically for you by the high-level language interface; it is always
equal to ENetDetachPH for this function.
When you call the EDetachPH function, any pending calls to the ERead
function terminate with the reqAborted result code.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EDetachPH(EParamBlkPtr thePBptr, Boolean async);


			/** 
			\brief Read a data packet and place it in a data buffer 
			
			<pre>ERead uses the default protocol handler to read a data packet and place it in a
data buffer.
thePBptr is a pointer to an EParamBlock structure. The relevant fields are as
follows:
Out-InName Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Always ENetRead
→eProtType short 228Ethernet protocol type
→ePointer long 430pointer to data buffer
→eBuffSize short 234size of data buffer
←eDataSize short 236number of bytes read
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to function asynchronously. See Async I/O .
</pre>
 * \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
LAPProtErr (-94) No protocol is attached or protocol handler pointer
was not 0
reqAborted (-1105) ERdCancel or EDetachPH function called
buf2SmallErr (-3101) Packet too large for buffer; partial data returned
</pre>
 * \note <pre>The ERead function uses the default protocol handler to read a data packet
and place it in a data buffer. You can use the ERead function to read packets
of a particular protocol type only after you have used the EDetachPH
function to specify a NIL pointer to the protocol handler for that protocol
type.
The ioResult parameter returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode parameter is the routine selector,
automatically set by the high-level language interface. It is always
ENetRead for this function.
The eProtType parameter specifies the protocol type of the packet you want
to read. The ePointer parameter is a pointer to the data buffer into which
you want to read data, and the eBuffSize parameter indicates the size of the
data buffer. If you are expecting EtherTalk data packets, the buffer should
be at least 621 bytes in size; if you are expecting general Ethernet data
packets, the buffer should be at least 1514 bytes in size.
The ERead function places the entire packet, including the packet header,
into your buffer. The function returns in the eDataSize parameter the
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
ERead(EParamBlkPtr thePBptr, Boolean async);


			/** 
			\brief Cancel execution of a specific call to the ERead function 
			
			<pre>ERdCancel cancels execution of a specific call to the ERead function.
thePBptr is a pointer to an EParamBlock structure. The relevant fields are as
follows:
Out-InName Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Always ENetRdCancel
→eProtType short 228Ethernet protocol type
→ePointer long 430pointer to data buffer
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to function asynchronously. See Async I/O .
</pre>
 * \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
cbNotFound (-1102) ERead not active
</pre>
 * \note <pre>You must have called the ERead function asynchronously to use the
ERdCancel function. You specify in the ePointer parameter a pointer to
the parameter block that you used when you called the ERead function. The
ioResult parameter returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode parameter is the routine selector,
automatically set by the high-level language interface. It is always
ENetRdCancel for this function.
When you call the ERdCancel function, the pending ERead function that
you cancel receives the reqAborted result code.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
ERdCancel(EParamBlkPtr thePBptr, Boolean async);


			/** 
			\brief Return information about The .ENET Driver 
			
			<pre>EGetInfo returns information about The .ENET Driver .
thePBptr is a pointer to an EParamBlock structure. The relevant fields are as
follows:
Out-InName Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Always ENetGetInfo
→ePointer long 430Pointer to data buffer
→eBuffSize short 234Size of buffer
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to function asynchronously. See Async I/O .
</pre>
 * \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
</pre>
 * \note <pre>Before calling this function, you must allocate a data buffer of at least 18
bytes. Put a pointer to the buffer in the ePointer parameter and the size of
the buffer in the eBuffSize parameter.
The EGetInfo function places the following information in the data buffer:
Bytes Information
1-6 Ethernet address of the node on which the driver is installed
7-10 Number of times the receive queue has overflowed
11-14 Number of data transmission operations that have timed out
15-18 Number of packets received that contain an incorrect address
An incorrect Ethernet address is one that is neither the broadcast address,
a multicast address for which this node is registered, nor the node's data
link address. A node could receive an incorrect Ethernet address due to a
hardware or software error.
The ioResult parameter returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode parameter is the routine selector,
automatically set by the high-level language interface. It is always
ENetGetInfo for this function.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EGetInfo(EParamBlkPtr thePBptr, Boolean async);


			/** 
			\brief Switch The .ENET Driver  to general-transmission 
			
			<pre>ESetGeneral switches The .ENET Driver from limited-transmission
mode to general-transmission mode.
thePBptr is a pointer to an EParamBlock structure. The relevant fields are as
follows:
Out-InName Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Always ENetSetGeneral
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to function asynchronously. See Async I/O .
</pre>
 * \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
memFullErr (-108) Insufficient memory in heap
</pre>
 * \note <pre>The ESetGeneral function switches The .ENET Driver from
limited-transmission mode to general-transmission mode. In
limited-transmission mode, The .ENET Driver allocates a write-data
buffer of 768 bytes. This buffer size is more than sufficient to hold an
EtherTalk data packet, which can be no larger than 621 bytes. In
general-transmission mode, The .ENET Driver can transmit an Ethernet
data packet of up to 1514 bytes.
The ioResult parameter returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode parameter is the routine selector,
automatically set by the high-level language interface. It is always
ENetSetGeneral for this function.
There is no command to switch The .ENET Driver from
general-transmission mode to limited-transmission mode. To switch back
to limited-transmission mode, you have to reset the driver by restarting
the computer.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
ESetGeneral(EParamBlkPtr thePBptr, Boolean async);


			/** 
			\brief Add a multicast address to the node 
			
			<pre>EAddMulti is a function used to add a multicast address to the node on which
The .ENET Driver is running.
thePBptr is a pointer to an EParamBlock structure. The relevant fields are as
follows:
Out-In Name Type SizeOffsetDescription
←ioResult short 216Result code
→csCode short 226Always ENetAddMulti
→eMultiAddr 6 bytes 628Multicast address
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to function asynchronously. See Async I/O .
</pre>
 * \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
eMultiErr (-91) Invalid address or table is full
</pre>
 * \note <pre>You must provide (in the eMultiAddr parameter) the multicast address
that you want to use. Each time a client of The .ENET Driver calls the
EAddMulti function for a particular multicast address, the driver
increments a counter for that multicast address. Each time a client of
The .ENET Driver calls the EDelMulti function, the driver decrements
the counter for that address. As long as the count for a multicast address is
equal to or greater than 1, The .ENET Driver accepts packets directed to
that multicast address. If any client of The .ENET Driver in the node has
called the EAddMulti function for a particular multicast address, the
driver receives packets delivered to that address.
The ioResult parameter returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode parameter is the routine selector,
automatically set by the high-level language interface. It is always
ENetAddMulti for this function.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EAddMulti(EParamBlkPtr thePBptr, Boolean async);


			/** 
			\brief Decrement a multicast address counter 
			
			<pre>EDelMulti decrements the counter kept by The .ENET Driver for a
particular multicast address.
thePBptr is a pointer to an EParamBlock structure. The relevant fields are as
follows:
Out-In Name Type SizeOffset Description
← ioResult short 216Result code
→ csCode short 226Always ENetDelMulti
→ eMultiAddr 6 bytes 628Multicast address
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to function asynchronously. See Async I/O .
</pre>
 * \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
eMultiErr (-91) Address not found
</pre>
 * \note <pre>EDelMulti decrements the counter kept by The .ENET Driver for a
particular multicast address. Each time a client of The .ENET Driver
calls the EAddMulti function, the driver increments a counter for the
multicast address specified by the eMultiAddr parameter. Each time a client
of The .ENET Driver calls the EDelMulti function, the driver
decrements the counter for the address specified by the eMultiAddr
parameter. As long as the count for a multicast address is equal to or greater
than 1, The .ENET Driver accepts packets directed to that multicast
address. When the count for an address equals 0, the driver removes that
address from the list of multicast addresses that it accepts.
Because more than one client of The .ENET Driver might be using a
particular multicast address, you should call the EDelMulti function only
once for each time you called the EAddMulti function.
The ioResult parameter returns the result of the function. If you call the
function asynchronously, the function sets this field to 1 as soon as it
begins execution, and it changes the field to the actual result code when it
completes execution. The csCode parameter is the routine selector
automatically set by the high-level language interface. It is always
ENetDelMulti for this function.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EDelMulti(EParamBlkPtr thePBptr, Boolean async);

#endif /* CALL_NOT_IN_CARBON */

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

#endif /* __ENET__ */
*/*/*/*/*/*/*/*/*/