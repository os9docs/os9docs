/**
     \file       Serial.h

    \brief   Asynchronous Serial Driver (.AIn/.AOut/.BIn/.BOut) Interfaces

    \introduced_in  System 7.6+
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Hardware

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __SERIAL__
#define __SERIAL__

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

  enum
  {
    baud150 = 763,
    baud300 = 380,
    baud600 = 189,
    baud1200 = 94,
    baud1800 = 62,
    baud2400 = 46,
    baud3600 = 30,
    baud4800 = 22,
    baud7200 = 14,
    baud9600 = 10,
    baud14400 = 6,
    baud19200 = 4,
    baud28800 = 2,
    baud38400 = 1,
    baud57600 = 0
  };

  enum
  {
    stop10 = 16384,
    stop15 = -32768L,
    stop20 = -16384
  };

  enum
  {
    noParity = 0,
    oddParity = 4096,
    evenParity = 12288
  };

  enum
  {
    data5 = 0,
    data6 = 2048,
    data7 = 1024,
    data8 = 3072
  };

  enum
  {
    aData = 6, /** channel A data in or out (historical) */
    aCtl = 2,  /** channel A control (historical) */
    bData = 4, /** channel B data in or out (historical) */
    bCtl = 0   /** channel B control (historical) */
  };

  enum
  {
    dsrEvent = 2,    /** flag for SerShk.evts */
    riEvent = 4,     /** flag for SerShk.evts */
    dcdEvent = 8,    /** flag for SerShk.evts */
    ctsEvent = 32,   /** flag for SerShk.evts */
    breakEvent = 128 /** flag for SerShk.evts */
  };

  enum
  {
    xOffWasSent = 128, /** flag for SerStaRec.xOffSent */
    dtrNegated = 64,   /** flag for SerStaRec.xOffSent */
    rtsNegated = 32    /** flag for SerStaRec.xOffSent */
  };

  enum
  {
    ainRefNum = -6,  /** serial port A input */
    aoutRefNum = -7, /** serial port A output */
    binRefNum = -8,  /** serial port B input */
    boutRefNum = -9  /** serial port B output */
  };

  enum
  {
    swOverrunErr = 1,  /** serial driver error masks */
    breakErr = 8,      /** serial driver error masks */
    parityErr = 16,    /** serial driver error masks */
    hwOverrunErr = 32, /** serial driver error masks */
    framingErr = 64    /** serial driver error masks */
  };

  enum
  {
    kOptionPreserveDTR = 128, /** option bit used with Control code 16 */
    kOptionClockX1CTS = 64    /** option bit used with Control code 16 */
  };

  enum
  {
    kUseCTSOutputFlowControl = 128, /** flag for SerShk.fCTS */
    kUseDSROutputFlowControl = 64,  /** flag for SerShk.fCTS */
    kUseRTSInputFlowControl = 128,  /** flag for SerShk.fDTR */
    kUseDTRInputFlowControl = 64    /** flag for SerShk.fDTR */
  };

  enum
  {
    sPortA = 0, /** Macintosh modem port */
    sPortB = 1, /** Macintosh printer port */
    sCOM1 = 2,  /** RS-232 port COM1 */
    sCOM2 = 3   /** RS-232 port COM2 */
  };

  typedef SInt8 SPortSel;
  /** csCodes for serial driver Control routines */
  enum
  {
    kSERDConfiguration =
        8, /** program port speed, bits/char, parity, and stop bits */
    kSERDInputBuffer =
        9,                  /** set buffer for chars received with no read pending */
    kSERDSerHShake = 10,    /** equivalent to SerHShake, largely obsolete */
    kSERDClearBreak = 11,   /** assert break signal on output */
    kSERDSetBreak = 12,     /** negate break state on output */
    kSERDBaudRate = 13,     /** set explicit baud rate, other settings unchanged */
    kSERDHandshake = 14,    /** superset of 10, honors setting of fDTR */
    kSERDClockMIDI = 15,    /** clock externally on CTS with specified multiplier */
    kSERDMiscOptions = 16,  /** select clock source and DTR behavior on close */
    kSERDAssertDTR = 17,    /** assert DTR output */
    kSERDNegateDTR = 18,    /** negate DTR output */
    kSERDSetPEChar = 19,    /** select char to replace chars with invalid parity */
    kSERDSetPEAltChar = 20, /** select char to replace char that replaces chars
                               with invalid parity */
    kSERDSetXOffFlag =
        21, /** set XOff output flow control (same as receiving XOff) */
    kSERDClearXOffFlag =
        22,                 /** clear XOff output flow control (same as receiving XOn) */
    kSERDSendXOn = 23,      /** send XOn if input flow control state is XOff */
    kSERDSendXOnOut = 24,   /** send XOn regardless of input flow control state */
    kSERDSendXOff = 25,     /** send XOff if input flow control state is XOn */
    kSERDSendXOffOut = 26,  /** send XOff regardless of input flow control state */
    kSERDResetChannel = 27, /** reset serial I/O channel hardware */
    kSERDHandshakeRS232 =
        28,                /** extension of 14, allows full RS-232 hardware handshaking */
    kSERDStickParity = 29, /** use mark/space parity */
    kSERDAssertRTS = 30,   /** assert RTS output */
    kSERDNegateRTS = 31,   /** negate RTS output */
    kSERD115KBaud = 115,   /** set 115.2K baud data rate */
    kSERD230KBaud = 230    /** set 230.4K baud data rate */
  };

  /** csCodes for serial driver Status routines */
  enum
  {
    kSERDInputCount = 2, /** return characters available (SerGetBuf) */
    kSERDStatus = 8,     /** return characters available (SerStatus) */
    kSERDVersion = 9,    /** return version number in first byte of csParam */
    kSERDGetDCD = 256    /** get instantaneous state of DCD (GPi) */
  };

  /**
  <pre>
   * \note <pre> This structure represents the contents of the flags parameter in the
  SerHShake procedure and addresses the input and output drivers as
  identified by the call's refNum field. It is used to set handshaking and
  control parameters as follows:
  Output flow control is enabled when fXOn is set, disabled when cleared to
  zero. The same holds true for FInX (as regard input flow control.  The xOn
  and xOff fields specify XOn and XOff characters for flow control. Setting
  the fCTS enables the Clear to Send (CTS) hardware handshake.
   The errs field shows the values:
  parityErr (16)set if a parity error has occurred
  hwOverrunErr (32)set in the event of a hardware overrun
  error
  framingErr (64)set in the event of a framing error
  Any one of these errors will cause input requests to abort.
  The evts field shows whether or not changes in Clear to Send or Break
  status will make the Serial Driver post a device driver event as follows:
  ctsEvent (32)set if Clear to Send change will post an event
  breakEvent (128)set if Break status change will post an event
  Your applications can use these constants to set or test the value of the
  evts field but we're warned against it because posting events disables
  interrupts for an inordinately long time.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct SerShk
  {
    char fXOn; /**< XOn/XOff output flow control*/
    char fCTS; /**< Clear to Send hardware handshake*/
    char xOn;  /**< XOn character*/
    char xOff; /**< XOff character*/
    char errs; /**< Errors resulting in abort*/
    char evts; /**< Status changes that cause events*/
    char fInX; /**< XOn/XOff input flow control*/
    char fDTR; /**< Data Terminal Ready input flow*/
  } SerShk;    /**< */

  typedef struct SerShk SerShk;
  /**
  <pre>
   * \note <pre> This structure represents the contents of the serSta field in the SerStatus
  procedure and addresses the input and output drivers as identified by the
  call's refNum field. It is used to by the driver to deliver status
  information as follows:
  The Cumerrs field shows the values:
  swOverrunErr (1)set if a software overrun error has
  occurred
  parityErr (16)set if a parity error has occurred
  hwOverrunErr (32)set in the event of a hardware overrun
  errorframingErr (64)set in the event of a framing error
  When the driver sends an XOff character, the xOffSent field will contain
  the predefined constant:
  xOffWasSent 0x080 XOff character sent
  A pending Read or Write will set the rdPend and wrPend parameters;
  when no Read or Write is pending they will both be zero.
  CtsHold is set when output is suspended because the hardware handshake
  was disabled: otherwise it is zero.
  XOffHold will be set if output was suspended due to receipt of an XOff
  character.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct SerStaRec
  {
    char cumErrs;  /**< Accumulated errors*/
    char xOffSent; /**< Input flow control XOff message*/
    char rdPend;   /**< Flags a pending Read*/
    char wrPend;   /**< Flags a pending Write*/
    char ctsHold;  /**< Flags a Clear to Send flow control*/
    char xOffHold; /**< Flags an XOff flow control Hold*/
  } SerStaRec;     /**< */

  typedef struct SerStaRec SerStaRec;
#if OLDROUTINENAMES
  /** ********************************************************************************************* */
  /** The following constant names have been retired in favor of standard, more
   * descriptive names.  */
  /** You can still compile old code by defining OLDROUTINENAMES. There were
   * several constants that */
  /** were formerly available that have been removed, as they are now regarded as
   * either private or */
  /** unsupported. We advise that you stop using any constants that are not
   * defined in this file.   */
  /** ********************************************************************************************* */
  enum
  {
    serdOptionClockExternal =
        kOptionClockX1CTS, /** option bit used with Control code 16 */
    serdOptionPreserveDTR =
        kOptionPreserveDTR /** option bit used with Control code 16 */
  };

  /** csCodes for serial driver Control routines */
  enum
  {
    serdReset = kSERDConfiguration,
    serdSetBuf = kSERDInputBuffer,
    serdHShake = kSERDSerHShake,
    serdClrBrk = kSERDClearBreak,
    serdSetBrk = kSERDSetBreak,
    serdSetBaud = kSERDBaudRate,
    serdHShakeDTR = kSERDHandshake,
    serdSetMIDI = kSERDClockMIDI,
    serdSetMisc = kSERDMiscOptions,
    serdSetDTR = kSERDAssertDTR,
    serdClrDTR = kSERDNegateDTR,
    serdSetPEChar = kSERDSetPEChar,
    serdSetPECharAlternate = kSERDSetPEAltChar,
    serdSetXOff = kSERDSetXOffFlag,
    serdClrXOff = kSERDClearXOffFlag,
    serdSendXOnConditional = kSERDSendXOn,
    serdSendXOn = kSERDSendXOnOut,
    serdSendXOffConditional = kSERDSendXOff,
    serdSendXOff = kSERDSendXOffOut,
    serdChannelReset = kSERDResetChannel,
    serdSet230KBaud = kSERD230KBaud /** set 230K baud data rate */
  };

  /** csCodes for serial driver Status routines */
  enum
  {
    serdGetBuf = kSERDInputCount,
    serdStatus = kSERDStatus,
    serdGetVers = kSERDVersion
  };

#endif /** OLDROUTINENAMES */

/**
    The following interfaces are for the legacy high-level serial driver glue in
    the interface libraries of your development system. They merely substitue
   for the corresponding synchronous calls to PBControl and PBStatus.

    They have not been updated as the serial driver API has evolved. Take note:

        SerHShake does not support hardware input flow control. Use csCode 14.
        SerStatus returns only the first six bytes of SerStaRec (through
   xOffHold).
*/
#if CALL_NOT_IN_CARBON
  /**
   *  SerReset()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  SerReset(short refNum, short serConfig);

  /**
   *  SerSetBuf()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  SerSetBuf(short refNum, Ptr serBPtr, short serBLen);

  /**
   *  SerHShake()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  SerHShake(short refNum, const SerShk *flags);

  /**
   *  SerSetBrk()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  SerSetBrk(short refNum);

  /**
   *  SerClrBrk()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  SerClrBrk(short refNum);

  /**
  \brief Get the number of bytes in an input driver's buffer

  <pre>SerGetBuf gets the number of bytes in the buffer for the specified input
driver.
refNum is the parameter that identifies the input driver with the buffer that
is being counted.
countis the total number of bytes in the buffer.
</pre>
* \returns <pre>an operating system Error Code .
noErr(0) No error
</pre>
* \note <pre> This call is equivalent to a Device Manager Status call with csCode=2
and with the count returned as a long in csParam.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
  OSErr
  SerGetBuf(short refNum, long *count);

  /**
   *  SerStatus()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  SerStatus(short refNum, SerStaRec *serSta);

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

#endif /** __SERIAL__ */