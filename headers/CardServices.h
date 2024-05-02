/**
     \file       CardServices.h

    \brief   The client interface to Card and Socket Services.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1994-2001 by Apple Computer, Inc. All rights reserved.

    \ingroup Networking

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CARDSERVICES__
#define __CARDSERVICES__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __PCCARDTUPLES__
#include <PCCardTuples.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
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

  //  miscellaneous
  enum
  {
    CS_MAX_SOCKETS = 32 // a long is used as a socket bitmap  };
                        // a long is used as a socket bitmap
    // Will move to <Traps.h>  enum
    {
        // Will move to <Traps.h>

        // Will move to <Errors.h>
        //  result codes// Card Services entry trap
        enum {
            // Will move to <Errors.h>
            -9058, // specified logical or physical socket number is invalid    kCSBadTypeErr = -9059,        // specified window or interface type is invalid    kCSBadVccErr = -9060,         // specified Vcc power level index is invalid    kCSBadVppErr = -9061,         // specified Vpp1 or Vpp2 power level index is invalid    kCSBadWindowErr = -9062,      // specified window is invalid    kCSBadArgLengthErr = -9063,   // ArgLength argument is invalid    kCSBadArgsErr = -9064,        // values in argument packet are invalid    kCSBadHandleErr = -9065,      // clientHandle is invalid    kCSBadCISErr = -9066,         // CIS on card is invalid    kCSBadSpeedErr = -9067,       // specified speed is unavailable    kCSReadFailureErr = -9068,    // unable to complete read request    kCSWriteFailureErr = -9069,   // unable to complete write request    kCSGeneralFailureErr = -9070, // an undefined error has occurred    kCSNoCardErr = -9071,         // no PC card in the socket    kCSUnsupportedFunctionErr =
                   //  result codes
            -9076, // a configuration has already been locked    kCSInUseErr = -9077,        // requested resource is being used by a client    kCSNoMoreItemsErr = -9078,  // there are no more of the requested item    kCSOutOfResourceErr = -9079 // Card Services has exhausted the resource  };

            //  messages sent to client's event handler
            enum                    // invalid adapter number
            {                       // specified attributes field value is invalid
             kCSNullMessage = 0x00, // specified base system memory address is invalid
             0x03,                  // specified EDC generator specified is invalid
             0x07,                  // request to inse// specified IRQ level is invalid
             0x08,                  // insertion motor// specified PC card memory array offset is invalid
             0x09,                  // user or other c// specified page is invalid
             0x0A,                  // specified size is invalid
             0x0D,                  // physical reset is about to occur on this card    kCSResetRequestMessage =
             0x0E,                  // physical reset ha// specified logical or physical socket number is invalid
             0x0F,                  // ResetCard() backg// specified window or interface type is invalid
             0x10,                  // specified Vcc power level index is invalid
             0x15,                  // specified Vpp1 or Vpp2 power level index is invalid
             0x18,                  // specified window is invalid
                                    // ArgLength argument is invalid
             /**/ / values in argument packet are invalid
                        The following is a mapping o     // clientHandle is invalid
                            space.These two enum lists w // CIS on card is invalid
                                separate file.           // specified speed is unavailable
                                    *                    /// unable to complete read request
                    enum                                 // unable to complete write request
                    {
                        // an undefined error has occurred
                        SUCCESS = noErr, // no PC card in the socket
                        BAD_ADAPTER = kCSBadAdapterErr,
                        BAD_ATTRIBUTE = kCSBadAttribute // function is not supported by this implementation
                            BAD_BASE = kCSBadBaseErr,   // mode is not supported
                        BAD_EDC = kCSBadEDCErr,         // unable to process request at this time - try later
                        BAD_IRQ = kCSBadIRQErr,         // media is write-protected
                        BAD_OFFSET = kCSBadOffsetErr,
                        BAD_PAGE = kCSBadPageErr,     // a configuration has already been locked
                        BAD_SIZE = kCSBadSizeErr,     // requested resource is being used by a client
                        BAD_SOCKET = kCSBadSocketErr  // there are no more of the requested item
                            BAD_TYPE = kCSBadTypeErr, // Card Services has exhausted the resource
                        BAD_VCC = kCSBadVccErr,
                        BAD_VPP = kCSBadVppErr,
                        //  messages sent to client's event handler
                        BAD_ARG_LENGTH = kCSBadArgLengthErr,
                        BAD_ARGS = kCSBadArgsErr,
                        BAD_HANDLE = kCSBadHandleErr,
                        BAD_CIS = kCSBadCISErr,          // no messages pending (not sent to clients)
                        BAD_SPEED = kCSBadSpeedErr,      // card has been inserted into the socket
                        READ_FAILURE = kCSReadFailureErr // card has been removed from the socket
                            WRITE_FAILURE = kCSWriteFailureErr,
                        GENERAL_FAILURE = kCSGeneralF     // card is locked into the socket with a mechanical latch
                            NO_CARD = kCSNoCardErr,       // card is no longer locked into the socket
                        UNSUPPORTED_FUNCTION = kCSUns     // card is ready to be accessed
                            UNSUPPORTED_MODE = kCSUnsuppo // physical reset has completed
                                BUSY = kCSBusyErr,
                        WRITE_PROT // request to insert a card using insertion motor
                            CONFIGURATION_LOCKED = kCSConfigurationLockedErr,
                        IN_USE = k // insertion motor has finished inserting a card
                            NO_MORE_ITEMS = kCSNoMoreItemsErr,
                        OUT_OF_RES // user or other client is requesting a card ejection
                    };
             // eject failure due to electrical/mechanical problems
             //  messages sent to client's // power management resume (TBD)
             enum        // power management suspend (TBD)
             {NULL_MESSA // physical reset is about to occur on this card
                  CARD_INSERTION = kCSCardInsertionMessage,
              CARD_REMOV // physical reset has been requested by a client
                  CARD_LOCK = kCSCardLockMessage,
              CARD_UNLOC // ResetCard() background reset has completed
                  CARD_READY = kCSCardReadyMessage,
              CARD_RESET = kCSCardResetMessag                 // battery is no longer useable, data will be lost
                  INSERTION_REQUEST = kCSInsertio             // battery is weak and should be replaced
                      INSERTION_COMPLETE = kCSInserti         // card is now write protected
                          EJECTION_REQUEST = kCSEjectionR     // card is now write enabled
                              EJECTION_FAILED = kCSEjectionFa // client is to return client information
                                  PM_RESUME = kCSPMResumeMessage,
              PM_SUSPEND = kCSPMSuspendMessage,        // AddSocketServices/ReplaceSocket services has changed SS support
              RESET_PHYSICAL = kCSResetPhysicalMes     // card function interrupt
                  RESET_REQUEST = kCSResetRequestMessa // client bus errored on access to socket
                      RESET_COMPLETE = kCSResetCompleteMessage,
              BATTERY_DEAD = kCSBatteryDeadMe         // a CARD_READY was delivered to all clients and no client
                  BATTERY_LOW = kCSBatteryLowMess     //    requested a configuration for the socket
                      WRITE_PROTECT = kCSWriteProtect // status change for cards in I/O mode
                          WRITE_ENABLED = kCSWriteEnabledMessage,
              CLIENT_INFO = kCSClientInfoMessage, SS_UPDATED = kCSSSUpdatedMessage, FUNCTION_INTERRUPT = kCSFunctionInterruptMessage, ACCESS_ERROR = kCSAccessErrorMessage, CARD_UNCONFIGURED = kCSCardUnconfiguredMessage, STATUS_CHANGED = kCSStatusChangedMessage};

             // ----------------      CSAccessConfigurationRegister   ----------------

             struct AccessConfigurationRegisterPB{UInt16 socket; //  -> global socket number    UInt8 action;     //  -> read/write    UInt8 offset;     //  -> offset from config register base    UInt8 value;      // <-> value to read/write    UInt8 padding[1]; //   };
                                                  typedef struct AccessConfigurationRegisterPB AccessConfigurationRegisterPB;
                                                  //  �action� field values
                                                  enum {kCSReadConfigRegister = 0x00, kCSWriteConfigRegister = 0x01};

                                                  // ----------------      CSGetCardServicesInfo           ----------------

                                                  struct GetCardServicesInfoPB{UInt8 signature[2]; // <-  two ascii chars 'CS'    UInt16 count;        // <-  total number of sockets installed    UInt16 revision;     // <-  BCD    UInt16 csLevel;      // <-  BCD    UInt16 reserved;     //  -> zero    UInt16 vStrLen;      // <-> in: client's buffer size, out: vendor string length    UInt8 *vendorString; /* <-> in: pointer to buffer to hold CS vendor string
                                                                               (zero - terminated) * /
                                                                               //    out: CS vendor string copied to buffer  };
                                                                               typedef struct GetCardServicesInfoPB GetCardServicesInfoPB;
                                                                               // ----------------      CSGetClientInfo                 ----------------

                                                                               // upper byte of attributes is kCSClientInfoSubfunction  struct ClientInfoParam
                                                                               {UInt32 clientHandle; //  -> clientHandle returned by RegisterClient    UInt16 attributes;   // <-> subfunction + bitmapped client attributes    UInt16 revision;     // <-  BCD value of client's revision    UInt16 csLevel;      // <-  BCD value of CS release    UInt16 revDate;      // <-  revision date: y[15-9], m[8-5], d[4-0]    SInt16
                                                                                nameLen;             // <-> in: max length of client name string, out: actual length    SInt16
                                                                                vStringLen;          // <-> in: max length of vendor string, out: actual length    UInt8 *nameString;   // <-  pointer to client name string (zero-terminated)    UInt8 *vendorString; // <-  pointer to vendor string (zero-terminated)  };
                                                                                typedef struct ClientInfoParam ClientInfoParam;
                                                                                /**
                                                                                   upper byte of attributes is kCSCardNameSubfunction,
                                                                                                               kCSCardTypeSubfunction,
                                                                                                               kCSHelpStringSubfunction
                                                                                //  messages sent to client's event handler
                                                                                struct AlternateTextStringParam
                                                                                {
                                                                                  UInt32 clientHandle; //  -> clientHandle returned by RegisterClient    UInt16 attributes;   // <-> subfunction + bitmapped client attributes    UInt16 socket;       //  -> logical socket number    UInt16 reserved;     //  -> zero    SInt16 length;       // <-> in: max length of string, out: actual length    UInt8 *text;         // <-  pointer to string (zero-terminated)  };
                                                                                typedef struct AlternateTextStringParam AlternateTextStringParam;
                                                                                // upper byte of attributes is kCSCardIconSubfunction  struct AlternateCardIconParam
                                                                                {
                                                                                  UInt32 clientHandle; //  -> clientHandle returned by RegisterClient    UInt16 attributes;   // <-> subfunction + bitmapped client attributes    UInt16 socket;       //  -> logical socket number    Handle iconSuite;    // <-  handle to icon suite containing all icons  };
                                                                                typedef struct AlternateCardIconParam AlternateCardIconParam;
                                                                                // upper byte of attributes is kCSActionProcSubfunction  struct CustomActionProcParam
                                                                                {
                                                                                  UInt32 clientHandle; //  -> clientHandle returned by RegisterClient    UInt16 attributes;   // <-> subfunction + bitmapped client attributes    UInt16 socket;       //  -> logical socket number  };
                                                                                typedef struct CustomActionProcParam CustomActionProcParam;
                                                                                struct GetClientInfoPB
                                                                                {
                                                                                  union
                                                                                  {
                                                                                    ClientInfoParam clientInfo;
                                                                                    AlternateTextStringParam alternateTextString;
                                                                                    AlternateCardIconParam alternateIcon;
                                                                                    CustomActionProcParam customActionProc;
                                                                                  } u;
                                                                                };
                                                                                typedef struct GetClientInfoPB GetClientInfoPB;
                                                                                //  �attributes� field values  enum
                                                                                {
                                                                                  kCSMemoryClient = 0x0001,
                                                                                  kCSIOClient = 0x0004,
                                                                                  kCSClientTypeMask = 0x0007,
                                                                                  kCSShareableCardInsertEvents = 0x0008,
                                                                                  kCSExclusiveCardInsertEvents = 0x0010,
                                                                                  kCSInfoSubfunctionMask = 0xFF00,
                                                                                  kCSClientInfoSubfunction = 0x0000,
                                                                                  kCSCardNameSubfunction = 0x8000,
                                                                                  kCSCardTypeSubfunction = 0x8100,
                                                                                  kCSHelpStringSubfunction = 0x8200,
                                                                                  kCSCardIconSubfunc//  -> global socket number
                                                                                  kCSActionProcSubfu//  -> read/write
                                                                                };//  -> offset from config register base
                                                                              // <-> value to read/write
                                                                                /**/
                                                                                / -- -- -- -- -- -- -- --CSGetConfigurationInfo-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --CSModifyConfiguration-- -- -- -- -- -- -- --
                                                                                                       //  �action� field values
                                                                                                       * /

                                                                                struct GetModRequestConfigInfoPB{UInt32 clientHandle; //  -> clientHandle returned by RegisterClient    UInt16 socket;       //  -> logical socket number    UInt16 attributes;   // <-> bitmap of configuration attributes    UInt8 vcc;           // <-> Vcc setting    UInt8 vpp1;          // <-> Vpp1 setting    UInt8 vpp2;          // <-> Vpp2 setting    UInt8 intType;       // <-> interface type (memory or memory+I/O)    UInt32 configBase;   // <-> card base address of configuration registers    UInt8 status;        // <-> card status register setting, if present    UInt8 pin;           // <-> card pin register setting, if present    UInt8 copy;          // <-> card socket/copy register setting, if present    UInt8 configIndex;   // <-> card option register setting, if present    UInt8 present;       // <-> bitmap of which configuration registers are present    UInt8 firstDevType;  // <-  from DeviceID tuple    UInt8 funcCode;      // <-  from FuncID tuple    UInt8 sysInitMask;   // <-  from FuncID tuple    UInt16 manufCode;    // <-  from ManufacturerID tuple    UInt16 manufInfo;    // <-  from ManufacturerID tuple    UInt8 cardValues;    // <-  valid card register values    UInt8 padding[1];    //   };
                                                                                                                 typedef struct GetModRequestConfigInfoPB GetModRequestConfigInfoPB;
                                                                                                                 //  �attributes� field values  enum
                                                                                                                 {
                                                                                                                     kCSExclusivelyUsed = 0x0001, kCSEnableIREQs = 0x0002, kCSVccChangeValid = 0x0004,
                                                                                                                     kCSVpp1ChangeValid =  // <-  two ascii chars 'CS'
                                                                                                                     kCSVpp2ChangeValid =  // <-  total number of sockets installed
                                                                                                                     kCSValidClient = 0x00 // <-  BCD
                                                                                                                     kCSSleepPower =       // <-  BCD
                                                                                                                     0x0040,               // reques//  -> zero
                                                                                                                     kCSTurnOnInUse = 0x01 // <-> in: client's buffer size, out: vendor string length
                                                                                                                 };

                                                                                                                 //  �intType� field val//    out: CS vendor string copied to buffer
                                                                                                                 enum {kCSMemoryInterface = 0x01, kCSMemory_And_IO_Interface = 0x02
                                                                                                                                                  // upper byte of attributes is kCSClientInfoSubfunction

                                                                                                                                                  //  �present� field values
                                                                                                                                                  enum                                         //  -> clientHandle returned by RegisterClient
                                                                                                                                                  {                                            // <-> subfunction + bitmapped client attributes
                                                                                                                                                   kCSOptionRegisterPres                       // <-  BCD value of client's revision
                                                                                                                                                       kCSStatusRegisterPres                   // <-  BCD value of CS release
                                                                                                                                                           kCSPinReplacementRegi               // <-  revision date: y[15-9], m[8-5], d[4-0]
                                                                                                                                                               kCSCopyRegisterPresent = 0x08}; // <-> in: max length of client name string, out: actual length

                                                                                                                       //  �cardValues� field // <-> in: max length of vendor string, out: actual length
                                                                                                                       enum // <-  pointer to client name string (zero-terminated)
                                                                                                                       {    // <-  pointer to vendor string (zero-terminated)
                                                                                                                        kCSOptionValueValid = 0x01, kCSStatusValueValid = 0x02, kCSPinReplacementValueValid = 0x04, kCSCopyValueValid = 0x08};

                                                                                                                       /**
                                                                                                                         ----------------      CSGetClientEventMask            ----------------
                                                                                                                         ----------------      CSSetClientEventMask            ----------------
                                                                                                                       */
                                                                                                                       //  -> clientHandle returned by RegisterClient
                                                                                                                       // <-> subfunction + bitmapped client attributes
                                                                                                                       struct GetSetClientEven //  -> logical socket number
                                                                                                                       {                       //  -> zero
                                                                                                                        UInt32 clientHandle;   // <-> in: max length of string, out: actual length
                                                                                                                                               // <-  pointer to string (zero-terminated)
                                                                                                                        UInt16 socket;         //  -> logical socket number  };
                                                                                                                        typedef struct GetSetClientEventMaskPB GetSetClientEventMaskPB;
                                                                                                                        // upper byte of attributes is kCSCardIconSubfunction
                                                                                                                        {kCSEventMaskThisSocketOnly = 0x0001}; //  -> clientHandle returned by RegisterClient
                                                                                                                                                               // <-> subfunction + bitmapped client attributes
                                                                                                                        //  �eventMask� field v//  -> logical socket number
                                                                                                                        enum // <-  handle to icon suite containing all icons
                                                                                                                        {kCSWriteProtectEvent = 0x0001,
                                                                                                                         // upper byte of attributes is kCSActionProcSubfunction
                                                                                                                         kCSEjectRequestEvent = 0x0004, kCSInsertRequestEvent = 0x0008,
                                                                                                                         kCSBatteryDeadEvent = //  -> clientHandle returned by RegisterClient
                                                                                                                         kCSBatteryLowEvent =  // <-> subfunction + bitmapped client attributes
                                                                                                                         kCSReadyChangeEvent = //  -> logical socket number
                                                                                                                         kCSCardDetectChangeEvent = 0x0080,
                                                                                                                         kCSPMChangeEvent = 0x0100, kCSResetEvent = 0x0200, kCSSSUpdateEvent = 0x0400, kCSFunctionInterrupt = 0x0800, kCSAllEvents = 0xFFFF};

                                                                                                                        /**
                                                                                                                          ----------------      CSGetFirstClient                ----------------
                                                                                                                          ----------------      CSGetNextClient                 ----------------
                                                                                                                        */

                                                                                                                        //  �attributes� field values
                                                                                                                        {UInt32 clientHandle; // <-  clientHandle for this client    UInt16 socket;       //  -> logical socket number    UInt16 attributes;   //  -> bitmap of attributes  };
                                                                                                                         typedef struct GetClientPB GetClientPB;
                                                                                                                         //  �attributes� field values  enum
                                                                                                                         {kCSClientsForAllSockets = 0x0000, kCSClientsThisSocketOnly = 0x0001};

                                                                                                                         /**
                                                                                                                           ----------------      CSGetFirstTuple                 ----------------
                                                                                                                           ----------------      CSGetNextTuple                  ----------------
                                                                                                                           ----------------      CSGetTupleData                  ----------------
                                                                                                                         */

                                                                                                                         struct GetTuplePB{UInt16 socket; //  -> logical socket number    UInt16 attributes;  //  -> bitmap of attributes    UInt8 desiredTuple; //  -> desired tuple code value, or $FF for all    UInt8 tupleOffset;  //  -> offset into tuple from link byte    UInt16 flags;       // <-> internal use    UInt32 linkOffset;  // <-> internal use    UInt32 cisOffset;   // <-> internal use
                                                                                                                                           union {struct {
                                                                                                                                               UInt8 tupleCode; // <-  tuple code found        UInt8 tupleLink; // <-  link value for tuple found      } TuplePB;

                                                                                                                                               struct //  -> clientHandle returned by RegisterClient
                                                                                                                                               {
                                                                                                                                                   //  -> logical socket number
                                                                                                                                                   UInt16 tupleDataM // <-> bitmap of configuration attributes
                                                                                                                                               } u;                  // <-> Vcc setting
                                                                                                                                           };                        // <-> Vpp1 setting
  typedef struct GetTuple                                                                                                                                            // <-> Vpp2 setting
  //  �attributes� field // <-> interface type (memory or memory+I/O)
  {                                                                         // <-> card base address of configuration registers
    kCSReturnLinkTuples =                                                   // <-> card status register setting, if present
  };                                                                        // <-> card pin register setting, if present
                                                                            // <-> card socket/copy register setting, if present
  /**/ / <->card option register setting, if present-- -- -- -- -- -- -- -- // <-> bitmap of which configuration registers are present
      -- -- -- -- -- -- -- --                                               // <-  from DeviceID tuple
      *                                                                     /// <-  from FuncID tuple
                                                                            // <-  from FuncID tuple
      struct ReqRelSocketMask                                               // <-  from ManufacturerID tuple
  {                                                                         // <-  from ManufacturerID tuple
    UInt32 clientHandle;                                                    // <-  valid card register values
                                                                            //
  };
  typedef struct ReqRelSocketMaskPB ReqRelSocketMaskPB;
  //  �attributes� field values
  // ----------------      CSGetStatus                     ----------------

  struct GetStatusPB
  {
    UInt16 socket; //  -> logical socket number    UInt16 cardState;   // <-  current state of installed card    UInt16 socketState; // <-  current state of the socket  };
    typedef struct GetStatusPB GetStatusPB;
    //  �cardState� field values  enum
    {
        kCSWriteProtected = 0x0001,
        kCSCardLocke // request that power be applied to socket during Sleep
            kCSEjectRequest = 0x0004,
        kCSInsertRequest = 0x0008,
        kCSBatteryDead = 0x0010,
        kCSBatteryLow = 0x0020,
        //  �intType� field values
        kCSCardDetected = 0x0080};

    //  �socketState� field values
    enum
    {
      kCSWriteProtectChanged = 0x0001,
      //  �present� field values
      kCSEjectRequestPending = 0x0004,
      kCSInsertRequestPending = 0x0008,
      kCSBatteryDeadChanged = 0x0010,
      kCSBatteryLowChanged = 0x0020,
      kCSReadyChanged = 0x0040,
      kCSCardDetectChanged = 0x0080
    };

    /**
    //  �cardValues� field values
      ----------------      CSReleaseWindow                 ----------------
      ----------------      CSRequestWindow                 ----------------
    */

    struct ReqModRelWindowPB
    {
      UInt32 clientHandle; //  -> clientHandle returned by RegisterClient    UInt32 windowHandle; // <-> window descriptor    UInt16 socket;       //  -> logical socket number    UInt16 attributes;   //  -> window attributes (bitmap)    UInt32 base;         // <-> system base address    UInt32 size;         // <-> memory window size    UInt8 accessSpeed;   //  -> window access speed (bitmap)                         //       (not applicable for I/O mode)    UInt8 padding[1];    //   };
      typedef struct ReqModRelWindowPB ReqModRelWindowPB;
      //  �attributes� field values  enum
      {
        kCSMemoryWindow = 0x0001,
        kCSIOWindow = 0x0002,
        kCSAttributeWindow = 0x0004, // not normally used by Card Services clients    kCSWindowTypeMask = 0x0007,
            kCSEnableWindow = 0x0008,
        kCSAccessSpeedValid = 0x0010,
        kCSLittleEndian = 0x0020, // configure socket for little endianess    kCS16BitDataPath = 0x0040,
            kCSWindowPaged = 0x00 //  -> clientHandle returned by RegisterClient
            kCSWindowFirstShared  // <-> bitmap of attributes

            //  �accessSpeed� field values
            enum //  -> logical socket number
        {
          kCSDeviceSpeedCodeMask = 0x07,
          //  �attributes� field values
          kCSSpeedMantissaMask = 0x78,
          kCSUseWait = 0x80,
          kCSAccessSpeed250nsec = 0x01,
          kCSAccessSpeed200nsec = 0x02,
          kCSAccessSpeed150nsec = 0x03,
          //  �eventMask� field values
          kCSExtAccSpeedMant1pt0 = 0x01,
          kCSExtAccSpeedMant1pt2 = 0x02,
          kCSExtAccSpeedMant1pt3 = 0x03,
          kCSExtAccSpeedMant1pt5 = 0x04,
          kCSExtAccSpeedMant2pt0 = 0x05,
          kCSExtAccSpeedMant2pt5 = 0x06,
          kCSExtAccSpeedMant3pt0 = 0x07,
          kCSExtAccSpeedMant3pt5 = 0x08,
          kCSExtAccSpeedMant4pt0 = 0x09,
          kCSExtAccSpeedMant4pt5 = 0x0A,
          kCSExtAccSpeedMant5pt0 = 0x0B,
          kCSExtAccSpeedMant5pt5 = 0x0C,
          kCSExtAccSpeedMant6pt0 = 0x0D,
          kCSExtAccSpeedMant7pt0 = 0x0E,
          kCSExtAccSpeedMant8pt0 = 0x0F,
          kCSExtAccSpeedExp1ns = 0x00,
          kCSExtAccSpeedExp10ns = 0x01,
          kCSExtAccSpeedExp100ns = 0x02,
          kCSExtAccSpeedExp1us = 0x03,
          kCSExtAccSpeedExp10us = 0x04,
          kCSExtAccSpeedExp100us = 0x05,
          kCSExtAccSpeedExp1ms = 0x06,
          kCSExtAccSpeedExp10ms = 0x07
        };

  /**// <-  clientHandle for this client
    ----------------     //  -> logical socket number
    ----------------     //  -> bitmap of attributes
  */

  //  �attributes� field values
  {
    UInt16 message; //  -> which event this is    UInt16 socket;  //  -> logical socket number    UInt16 info;    //  -> function-specific    UInt16 misc;    //  -> function-specific    Ptr reserved;   //  -> pointer to MTD request block    Ptr buffer;     //  -> function-specific    Ptr clientData; //  -> pointer to client's data (from RegisterClient)  };
    typedef struct ClientCallbackPB ClientCallbackPB;
    typedef ClientCallbackPB *ClientCallbackPBPtr;
    typedef CALLBACK_API(UInt16,
                         PCCardCSClientProcPtr)(ClientCallbackPBPtr ccPBPtr);
    typedef STACK_UPP_TYPE(PCCardCSClientProcPtr) PCCardCSClientUPP;
#if CALL_NOT_IN_CARBON
    /**
     *  NewPCCardCSClientUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x       //  -> logical socket number
     */
    //  -> bitmap of attributes
  PCCardCSClientUPP//  -> desired tuple code value, or $FF for all
  NewPCCardCSClientUPP(P//  -> offset into tuple from link byte
#if !OPAQUE_UPP_TYPES   // <-> internal use
  enum// <-> internal use
  {// <-> internal use
    uppPCCardCSClientProcInfo = 0x000000E0
  }; // pascal 2_bytes Func(4_bytes) #ifdef __cplusplus
  inline PCCardCSClientUPP
  NewPCCardCSClientUPP(PCCardCSClientProcPtr userRoutine)
  {
            return (PCCardCSClien // <-  tuple code found
                                  // <-  link value for tuple found
                        GetCurrentArchitecture());
  }
#else
#define NewPCCardCSClientUPP(userRoutine) \
  (PCCardCSClientUPP) //  -> maximum size of tuple data area
      NewRoutineDescriptor((P// <-  number of bytes in tuple body
                           Ge// <-  tuple data
#endif
#endif

  /**
  //  �attributes� field values
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposePCCardCSClientUPP(PCCardCSClientUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposePCCardCSClientUPP(PCCardCSClientUPP userUPP)
  {
            DisposeRoutineDescrip //  -> clientHandle returned by RegisterClient
  }//  -> logical socket
#else
#define DisposePCCardCSClientUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif
//  �eventMask� field values (see above for Get/SetClientEventMask
  /**
   *  InvokePCCardCSClientUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib     //  -> logical socket number
   *    \mac_os_x       // <-  current state of installed card
   */// <-  current state of the socket
  UInt16
  InvokePCCardCSClientUPP(ClientCallbackPBPtr ccPBPtr, PCCardCSClientUPP userUPP);
#i //  �cardState� field values
#ifdef __cplusplus
  inline UInt16 InvokePCCardCSClientUPP(ClientCallbackPBPtr ccPBPtr,
                                        PCCardCSClientUPP userUPP)
  {
            return (UInt16)CALL_ONE_PARAMETER_UPP(userUPP, uppPCCardCSClientProcInfo,
                                                  ccPBPtr);
  }
#else
#define InvokePCCardCSClientUPP(ccPBPtr, userUPP) \
  (UInt16)                                        \
      CALL_ONE_PARAMETER_UPP((userUPP), uppPCCardCSClientProcInfo, (ccPBPtr))
#endif
#e //  �socketState� field values

#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewPCCardCSClientProc(userRoutine) NewPCCardCSClientUPP(userRoutine)
#define CallPCCardCSClientProc(userRoutine, ccPBPtr) \
  InvokePCCardCSClientUPP(ccPBPtr, userRoutine)
#endif // CALL_NOT_IN_CARBON 
  struct RegisterClientPB
  {
            UInt32 clientHandle; // <-  client descriptor    PCCardCSClientUPP
            clientEntry;         //  -> universal procPtr to client's event handler    UInt16 attributes; //  -> bitmap of client attributes    UInt16 eventMask;  //  -> bitmap of events to notify client    Ptr clientData;    //  -> pointer to client's data    UInt16 version;    //  -> Card Services version this client expects  };
            typedef struct RegisterClientPB RegisterClientPB;
            //  �attributes� field values (see GetClientInfo)  /**
            kCSMemoryClient = 0x0001,
            kCSIOClient = 0x0004,
            kCSShareableCardInsertEvents = 0x0008,
            kCSExclusiveCardInsertEvents = 0x0010 * /

                                           // ----------------      CSReleaseConfiguration          ----------------

                                           struct ReleaseConfigura //  -> clientHandle returned by RegisterClient
            {                                                      // <-> window descriptor
              UInt32 clientHandle;                                 //  -> logical socket number
              typedef struct ReleaseC                              //  -> window attributes (bitmap)
                                                                   /*----------------     // <-> system base address
                                                                 // <-> memory window size
                                                                   struct ResetCardPB//  -> window access speed (bitmap)
                                                                   {//       (not applicable for I/O mode)
                                                                     UInt32 clientHandle; //
                                                                   typedef struct ResetCardPB ResetCardPB;
                                                                   // ----------------      CSValidateCIS                   ----------------
                                                                 //  �attributes� field values
                                                                   struct ValidateCISPB
                                                                   {
                                                                     UInt16 socket; //  ->     UInt16 chains; //  -> whether link/null tuples should be included  };
                                                                   typedef struct ValidateCISPB ValidateCISPB;
                                                                   /**/
                  / not normally used by Card Services clients-- -- -- -- -- -- -- --CSRequestIO-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --CSReleaseIO-- -- -- -- -- -- -- --* /
                  // configure socket for little endianess
                  struct ReqRelIOPB
              {                      //
                UInt32 clientHandle; //  -> clientHandle returned by RegisterClient    UInt16 socket;       //  -> socket number    UInt16 reserved;
                UInt16 basePort1;    //    -> bas//
                UInt16 basePort2;    //    -> bas//
                UInt8 ioAddrLines;   //    -> number of I/O lines decoded by card    UInt8 reserved1;
              };
              //  �accessSpeed� field values
              // ----------------      CSVendorSpecific                ----------------
              struct VendorSpecificPB
              {
                UInt32 clientHandle; //  -> clientHandle returned by RegisterClient    UInt16 vsCode;
                UInt16 socket;
                UInt32 dataLen; //  -> length of buffer pointed to by vsDataPtr    UInt8 *vsDataPtr; //  -> Card Services version this client expects  };
                typedef struct VendorSpecificPB VendorSpecificPB;
                //  �vsCode� field values
                enum
                {
                  vsAppleReserved = 0x0000,
                  vsEjectCard = 0x0001,
                  vsGetCardInfo = 0x0002,
                  vsEnableSocketEvents = 0x0003,
                  vsGetCardLocationIcon = 0x0004,
                  vsGetCardLocationText = 0x0005,
                  vsGetAdapterInfo = 0x0006
                };

                /**
                  ///////////////////////////////////////////////////////////////////////////////////////
                    GetAdapterInfo parameter block (vendor-specific call #6)
                */

                struct GetAdapterInfoPB
                {
                  UInt32 attributes; // <-  capabilties of socket's adapter    UInt16 revision;       // <-  id of adapter    UInt16 reserved;       //     UInt16 numVoltEntries; // <-  number of valid voltage values    UInt8 *voltages;       // <-> array of BCD voltage values  };
                  typedef struct GetAdapterInfoPB GetAdapterInfoPB;
                  //  �attributes� field values  enum
                  {
                      kCSLevelModeInterrupts = 0x00000001,
                      kCSPulseModeInterrupts = 0x00000002,
                      kCSProgrammableWindowAddr = 0x00000004,
                      kCSProgrammableWindowSize = 0x00000008,
                      kCSSocketSleepPower = 0x00000010,
                      kCSSoftwareEject = 0x00000020,
                      kCSLockableSocket = 0x00000040,
                      kCSInUseIndicator = 0x00000080};

                  /**
                    ///////////////////////////////////////////////////////////////////////////////////////
                      GetCardInfo parameter block (vendor-specific call #2)
                  */
                  //  -> which event this is
                  //  -> logical socket number
                  struct GetCardInfo   //  -> function-specific
                  {                    //  -> function-specific
                    UInt8 cardType;    //  -> pointer to MTD request block
                    vendorName;        //  -> function-specific
                    typedef struct Get //  -> pointer to client's data (from RegisterClient)
                    //  GetCardInfo card types  enum
                    {
                      kCSUnknownCardType = 0,
                      kCSMultiFunctionCardType = 1,
                      kCSMemoryCardType = 2,
                      kCSSerialPortCardType = 3,
                      kCSSerialOnlyType = 0,
                      kCSDataModemType = 1,
                      kCSFaxModemType = 2,
                      kCSFaxAndDataModemMask = (kCSDataModemType | kCSFaxModemType),
                      kCSVoiceEncodingType = 4,
                      kCSParallelPortCardType = 4,
                      kCSFixedDiskCardType = 5,
                      kCSUnknownFixedDiskType = 0,
                      kCSATAInterface = 1,
                      kCSRotatingDevice = (0 << 7),
                      kCSSiliconDevice = (1 << 7),
                      kCSVideoAdaptorCardType = 6,
                      kCSNetworkAdaptorCardType = 7,
                      kCSAIMSCardType = 8,
                      kCSNumCardTypes = 9
                    }; // pascal 2_bytes Func(4_bytes)

#ifndef __PCCARDENABLERPLUGIN__
/**
    NOTE: These prototypes conflict with PCCardEnablerPlugin.�
          You cannot use both PCCardEnablerPlugin.h and CardServices.h

*/
#if CALL_NOT_IN_CARBON
                    /**
                     *  CSVendorSpecific()
                     *

                     *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
                     *    \carbon_lib        not available
                     *    \mac_os_x         not available
                     */
                    OSErr
                    CSVendorSpecific(VendorSpecificPB *pb) TWOWORDINLINE(0x7000, 0xAAF0);

                    /**
                     *  CSRegisterClient()
                     *

                     *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
                     *    \carbon_lib        not available
                     *    \mac_os_x         not available
                     */
                    OSErr
                    CSRegisterClient(RegisterClientPB *pb) TWOWORDINLINE(0x7001, 0xAAF0);

                    /**
                     *  CSDeregisterClient()
                     *

                     *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
                     *    \carbon_lib        not available
                     *    \mac_os_x         not available
                     */
                    OSErr
                    CSDeregisterClient(RegisterClientPB *pb) TWOWORDINLINE(0x7002, 0xAAF0);

                    /**
                     *  CSGetFirstTuple()
                     *

                     *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
                     *    \carbon_lib        not available
                     *    \mac_os_x         not available
                     */
                    OSErr
                    CSGetFirstTuple(GetTuplePB *pb) TWOWORDINLINE(0x7003, 0xAAF0);

                    /**
                     *  CSGetNextTuple()
                     *

                     *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
                     *    \carbon_lib        not available
                     *    \mac_os_x         not available
                     */
                    OSErr
                    CSGetNextTuple(GetTuplePB *pb) TWOWORDINLINE(0x7004, 0xAAF0);
                    // CALL_NOT_IN_CARBON
                    /**
                     *  CSGetTupleData()
                  // support for pre-Carbon UPP routines: New...Proc and Call...Proc

                     *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
                     *    \carbon_lib        not available
                     *   // CALL_NOT_IN_CARBON
                     */
                    OSErr
                    CSGetTupleData(GetTuplePB *pb) TWOWORDINLINE(0x7005, 0xAAF0);
                    // <-  client descriptor
                    /**
                     *  CSGetConfiguratio//  -> universal procPtr to client's event handler
                     */ /->bitmap of client attributes
                             //  -> bitmap of events to notify client
                             *    \non_carbon_cfm //  -> pointer to client's data
                                 *    \carbon_lib //  -> Card Services version this client expects
                                     *    \mac_os_x not available *
                        /
                        //  �attributes� field values (see GetClientInfo)
                        CSGetConfigurationInfo(GetModRequestConfigInfoPB * pb)
                            TWOWORDINLINE(0x7006, 0xAAF0);

                    /**
                     *  CSGetCardServicesInfo()
                     *

                     *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
                     *    \carbon_lib        not available
                     *    \mac_os_x         not available
                     */
  OSErr//  -> clientHandle returned by RegisterClient
  CSGetCardServicesInfo(G//  -> 

  /**
   *  CSGetStatus()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib      //  -> clientHandle returned by RegisterClient
   *    \mac_os_x        //  -> 
   *///  -> xxx
  OSErr
  CSGetStatus(GetStatusPB *pb) TWOWORDINLINE(0x7008, 0xAAF0);

  /**
   *  CSValidateCIS()
   *
//  -> 
   *    \non_carbon//  -> whether link/null tuples should be included
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSValidateCIS(ValidateCISPB *pb) TWOWORDINLINE(0x7009, 0xAAF0);

  /**
   *  CSGetFirstClient()
   *
//  -> clientHandle returned by RegisterClient
   *    \non_carbon_cfm  //  -> socket number
   *    \carbon_lib        not available
   *    \mac_os_x      //    -> base I/O port for range
   *///    -> number of ports (e.g., bytes).
  OSErr//    -> attributes
  CSGetFirstClient(GetClientPB *pb) TWOWORDINLINE(0x700F, 0xAAF0);
//    -> base I/O port for range
  /**//    -> number of ports
   *  CSGetNextClient()//    -> attributes
   *
//    -> number of I/O lines decoded by card
   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSGetNextClient(GetClientPB *pb) TWOWORDINLINE(0x7010, 0xAAF0);
//  -> clientHandle returned by RegisterClient
  /**
   *  CSGetClientInfo()
   *//  -> length of buffer pointed to by vsDataPtr
//  -> Card Services version this client expects
   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
  //  �vsCode� field values
   */
  OSErr
  CSGetClientInfo(GetClientInfoPB *pb) TWOWORDINLINE(0x7011, 0xAAF0);

  /**
   *  CSResetCard()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSResetCard(ResetCardPB *pb) TWOWORDINLINE(0x7012, 0xAAF0);

  /**
   *  CSRequestWindow()
   *

   *    \non_carbon_cfm   i// <-  capabilties of socket's adapter
   *    \carbon_lib        // <-  id of adapter
   *    \mac_os_x         n// 
   */// <-  number of valid voltage values
  OSErr// <-> array of BCD voltage values
  CSRequestWindow(ReqModRelWindowPB *pb) TWOWORDINLINE(0x7013, 0xAAF0);

  //  �attributes� field values
   *  CSModifyWindow()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSModifyWindow(ReqModRelWindowPB *pb) TWOWORDINLINE(0x7014, 0xAAF0);

  /**
   *  CSReleaseWindow()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSReleaseWindow(ReqModRe// <-  type of card in this socket (defined at top of file)
// <-  more detailed card type (defined at top of file)
  /**// <-> reserved (should be set to zero)
   *  CSRequestConfigurati//  -> maximum length of card name to be returned
   *//  -> maximum length of vendor name to be returned
//  -> pointer to card name string (read from CIS), or nil
   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib //  -> pointer to vendor name string (read from CIS), or nil
   *    \mac_os_x         not available
   */
  //  GetCardInfo card types
  CSRequestConfiguration(GetModRequestConfigInfoPB *pb)
      TWOWORDINLINE(0x701B, 0xAAF0);

  /**
   *  CSModifyConfiguration()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSModifyConfiguration(GetModRequestConfigInfoPB *pb)
      TWOWORDINLINE(0x701C, 0xAAF0);

  /**
   *  CSAccessConfigurationRegister()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSAccessConfigurationRegister(AccessConfigurationRegisterPB *pb)
      TWOWORDINLINE(0x701D, 0xAAF0);

  /**
   *  CSReleaseConfiguration()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSReleaseConfiguration(ReleaseConfigurationPB *pb)
      TWOWORDINLINE(0x701E, 0xAAF0);

  /**
   *  CSGetClientEventMask()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSGetClientEventMask(GetSetClientEventMaskPB *pb) TWOWORDINLINE(0x701F, 0xAAF0);

  /**
   *  CSSetClientEventMask()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSSetClientEventMask(GetSetClientEventMaskPB *pb) TWOWORDINLINE(0x7020, 0xAAF0);

  /**
   *  CSRequestSocketMask()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSRequestSocketMask(ReqRelSocketMaskPB *pb) TWOWORDINLINE(0x7021, 0xAAF0);

  /**
   *  CSReleaseSocketMask()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSReleaseSocketMask(ReqRelSocketMaskPB *pb) TWOWORDINLINE(0x7022, 0xAAF0);

  /**
      Additional calls which are required for all I/O clients when running on
      systems which do not reserve dedicated I/O-spaces for each PC Card.
  */

  /**
   *  CSRequestIO()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSRequestIO(ReqRelIOPB *pb) TWOWORDINLINE(0x7025, 0xAAF0);

  /**
   *  CSReleaseIO()
   *

   *    \non_carbon_cfm   in PCCardLib 1.0 thru 2.0
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CSReleaseIO(ReqRelIOPB *pb) TWOWORDINLINE(0x7026, 0xAAF0);

#endif // CALL_NOT_IN_CARBON
#endif // !defined(__PCCARDENABLERPLUGIN__)
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

#endif // __CARDSERVICES__ // CALL_NOT_IN_CARBON
                // !defined(__PCCARDENABLERPLUGIN__)
                // __CARDSERVICES__
