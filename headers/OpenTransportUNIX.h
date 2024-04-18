/**
     \file       OpenTransportUNIX.h

    \brief   Open Transport client interface file for UNIX compatibility
   clients.

    \introduced_in  2.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1993-2001 by Apple Computer, Inc. and Mentat Inc., all rights
   reserved.

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __OPENTRANSPORTUNIX__
#define __OPENTRANSPORTUNIX__

#include <stddef.h>
#ifndef __OPENTRANSPORTPROTOCOL__
#include <OpenTransportProtocol.h>
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

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma push
#pragma pointers_in_D0
#endif

/** ***** Global Variables ******/

/**
 *  t_errno
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
extern int t_errno;

/** ***** XTI Structures ******/

/**
   WARNING:
   These structures will only work if "int"s are the
   same size as "size_t", "long", and "UInt32".  We left
   them this way for maximum UNIX compatibility.
*/

struct netbuf {
  unsigned int maxlen;
  unsigned int len;
  char *buf;
};
typedef struct netbuf netbuf;
struct t_info {
  int addr;              /** Maximum size of an address        */
  int options;           /** Maximum size of options          */
  int tsdu;              /** Standard data transmit unit size     */
  int etsdu;             /** Expedited data transmit unit size  */
  int connect;           /** Maximum data size on connect      */
  int discon;            /** Maximum data size on disconnect       */
  unsigned int servtype; /** service type                */
  unsigned int flags;    /** Flags (see "OpenTransport.h")   */
};
typedef struct t_info t_info;

struct t_bind {
  netbuf addr;
  unsigned int qlen;
};
struct t_optmgmt {
  netbuf opt;
  long flags;
};
struct t_discon {
  netbuf udata;
  int reason;
  int sequence;
};
typedef struct t_discon t_discon;
struct t_call {
  netbuf addr;
  netbuf opt;
  netbuf udata;
  int sequence;
};
typedef struct t_call t_call;
struct t_unitdata {
  netbuf addr;
  netbuf opt;
  netbuf udata;
};
typedef struct t_unitdata t_unitdata;
struct t_uderr {
  netbuf addr;
  netbuf opt;
  long error;
};
typedef struct t_uderr t_uderr;
/**    -------------------------------------------------------------------------
    Transaction data structures
    ------------------------------------------------------------------------- */
struct t_request {
  netbuf data;
  netbuf opt;
  long sequence;
};
typedef struct t_request t_request;
struct t_reply {
  netbuf data;
  netbuf opt;
  long sequence;
};
typedef struct t_reply t_reply;
struct t_unitrequest {
  netbuf addr;
  netbuf opt;
  netbuf udata;
  long sequence;
};
typedef struct t_unitrequest t_unitrequest;
struct t_unitreply {
  netbuf opt;
  netbuf udata;
  long sequence;
};
typedef struct t_unitreply t_unitreply;
struct t_opthdr {
  unsigned long len;   /** total length of option = sizeof(struct t_opthdr) + */
                       /**                 length of option value in bytes   */
  unsigned long level; /** protocol affected */
  unsigned long name;  /** option name */
  unsigned long status; /** status value */
                        /** followed by the option value */
};
typedef struct t_opthdr t_opthdr;
/** ***** XTI Interfaces ******/
#if !OTKERNEL
#if CALL_NOT_IN_CARBON
/**
 *  t_accept()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_accept(int fd, int resfd, t_call *call);

/**
 *  t_alloc()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(char *)
t_alloc(int fd, int struct_type, int fields);

#endif /** CALL_NOT_IN_CARBON */

EXTERN_API(int) t_bind(int fd, struct t_bind *req, struct t_bind *ret);
EXTERN_API(int) t_optmgmt(int fd, struct t_optmgmt *req, struct t_optmgmt *ret);
EXTERN_API(int)
t_getprotaddr(int fd, struct t_bind *boundaddr, struct t_bind *peeraddr);
EXTERN_API(int)
t_resolveaddr(int fd, struct t_bind *reqAddr, struct t_bind *retAddr,
              OTTimeout timeout);
#if CALL_NOT_IN_CARBON
/**
 *  t_close()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_close(int fd);

/**
 *  t_connect()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_connect(int fd, t_call *sndcall, t_call *rcvcall);

/**
 *  t_free()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_free(char *ptr, int struct_type);

/**
 *  t_getinfo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_getinfo(int fd, t_info *info);

/**
 *  t_getstate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_getstate(int fd);

/**
 *  t_listen()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_listen(int fd, t_call *call);

/**
 *  t_look()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_look(int fd);

/**
 *  t_open()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_open(char *path, int oflag, t_info *info);

/**
 *  t_blocking()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_blocking(int fd);

/**
 *  t_nonblocking()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_nonblocking(int fd);

/**
 *  t_rcv()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_rcv(int fd, char *buf, size_t nbytes, int *flags);

/**
 *  t_rcvconnect()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_rcvconnect(int fd, t_call *call);

/**
 *  t_rcvdis()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_rcvdis(int fd, t_discon *discon);

/**
 *  t_rcvrel()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_rcvrel(int fd);

/**
 *  t_rcvudata()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_rcvudata(int fd, t_unitdata *unitdata, int *flags);

/**
 *  t_rcvuderr()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_rcvuderr(int fd, t_uderr *uderr);

/**
 *  t_snd()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_snd(int fd, char *buf, size_t nbytes, int flags);

/**
 *  t_snddis()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_snddis(int fd, t_call *call);

/**
 *  t_sndrel()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_sndrel(int fd);

/**
 *  t_sndudata()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_sndudata(int fd, t_unitdata *unitdata);

/**
 *  t_sync()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_sync(int fd);

/**
 *  t_unbind()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_unbind(int fd);

/**
 *  t_error()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_error(char *errmsg);

/** Apple extensions*/

/**
 *  t_isnonblocking()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_isnonblocking(int fd);

/**
 *  t_asynchronous()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_asynchronous(int fd);

/**
 *  t_synchronous()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_synchronous(int fd);

/**
 *  t_issynchronous()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_issynchronous(int fd);

/**
 *  t_usesyncidleevents()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_usesyncidleevents(int fd, int useEvents);

/** Not XTI standard functions, but extensions for transaction endpoints */

/**
 *  t_sndrequest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_sndrequest(int fd, t_request *req, int flags);

/**
 *  t_rcvreply()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_rcvreply(int fd, t_reply *rep, int *flags);

/**
 *  t_rcvrequest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_rcvrequest(int fd, t_request *req, int *flags);

/**
 *  t_sndreply()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_sndreply(int fd, t_reply *rep, int flags);

/**
 *  t_cancelrequest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_cancelrequest(int fd, long sequence);

/**
 *  t_cancelreply()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_cancelreply(int fd, long sequence);

/**
 *  t_sndurequest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_sndurequest(int fd, t_unitrequest *ureq, int flags);

/**
 *  t_rcvureply()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_rcvureply(int fd, t_unitreply *urep, int *flags);

/**
 *  t_rcvurequest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_rcvurequest(int fd, t_unitrequest *ureq, int *flags);

/**
 *  t_sndureply()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_sndureply(int fd, t_unitreply *urep, int flags);

/**
 *  t_cancelurequest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_cancelurequest(int fd, long sequence);

/**
 *  t_cancelureply()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_cancelureply(int fd, long sequence);

/**
 *  t_cancelsynchronouscalls()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_cancelsynchronouscalls(int fd);

/**
 *  t_installnotifier()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
t_installnotifier(int fd, OTNotifyProcPtr proc, void *contextPtr);

/**
 *  t_removenotifier()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
t_removenotifier(int fd);

/** STREAMS Primitives*/

/**
 *  getmsg()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
getmsg(int fd, strbuf *ctlbuf, strbuf *databuf, int *flagsp);

/**
 *  putmsg()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
putmsg(int fd, const strbuf *ctlbuf, const strbuf *databuf, int flags);

/**
 *  getpmsg()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
getpmsg(int fd, strbuf *ctlbuf, strbuf *databuf, int *bandp, int *flagsp);

/**
 *  putpmsg()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
putpmsg(int fd, const strbuf *ctlbuf, const strbuf *databuf, int band,
        int flags);

/** Raw streams operations.*/

/**
 *  stream_installnotifier()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_installnotifier(int fd, OTNotifyProcPtr proc, void *contextPtr);

/**
 *  stream_blocking()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_blocking(int fd);

/**
 *  stream_nonblocking()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_nonblocking(int fd);

/**
 *  stream_isblocking()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_isblocking(int fd);

/**
 *  stream_synchronous()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_synchronous(int fd);

/**
 *  stream_asynchronous()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_asynchronous(int fd);

/**
 *  stream_issynchronous()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_issynchronous(int fd);

/**
 *  stream_open()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_open(char *path, unsigned long flags);

/**
 *  stream_close()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_close(int fd);

/**
 *  stream_read()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_read(int fd, void *buf, size_t len);

/**
 *  stream_write()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_write(int fd, void *buf, size_t len);

/**
 *  stream_ioctl()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(int)
stream_ioctl(int fd, unsigned long cmd, ...);

/**
 *  stream_pipe()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
stream_pipe(int *fds);

#endif /** CALL_NOT_IN_CARBON */

struct pollfd {
  SInt32 fd;
  short events;
  short revents;
  long _ifd; /** Internal "fd" for the benefit of the kernel */
};
typedef struct pollfd pollfd;
#if CALL_NOT_IN_CARBON
/**
 *  poll()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(int)
poll(pollfd *fds, size_t nfds, unsigned long timeout);

#endif /** CALL_NOT_IN_CARBON */

#endif /** !OTKERNEL */

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma pop
#endif

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

#endif /** __OPENTRANSPORTUNIX__ */
