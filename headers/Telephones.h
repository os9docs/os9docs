/**
     \file       Telephones.h

    \brief   Telephone Manager Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup CommunicationsToolbox

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __TELEPHONES__
#define __TELEPHONES__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __CTBUTILITIES__
#include <CTBUtilities.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
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

#if CALL_NOT_IN_CARBON
  enum
  {
    curTELVersion = 3, // current Telephone Manager version     //    the chooseXXX symbols are defined in CTBUtilities.(pah)     telChooseDisaster = chooseDisaster,
    telChooseFailed = chooseFailed,
    telChooseAborted = chooseAborted,
    telChooseOKMinor = chooseOKMinor,
    telChooseOKMajor = chooseOKMajor,
    telChooseCancel = chooseCancel,
    telChooseOKTermChanged = 4
  };

#ifndef classTEL
  enum
  {
    // telephone tool file type     classTEL = FOUR_CHAR_CODE('vbnd')
  };
// telephone tool file type 
#endif // !defined(classTEL) 
  // PHYSICAL TERMINAL CONSTANTS   // INDEPENDENT HANDSET CONSTANTS   enum
  {
    tel// !defined(classTEL) 

  // PHYSICAL TERMINAL CONSTANTS 
  // INDEPENDENT HANDSET CONSTANTS 
    telIndHSDisconnected = 0, // handset disconnected from the line     telIndHSConnected = 1     // handset connected to the line   };

  // HOOK STATE CONSTANT// independent handset on hook 
  {// independent handset off hook 
    telHandset = 1,     // handset hookswitch     telSpeakerphone = 2 // speakerphone 'on' switch   };

  enum
  {
    telDeviceOffHook = 1, // d// handset disconnected from the line 
// handset connected to the line 
  // VOLUME CONTROL CONSTANTS   enum
  {
  // HOOK STATE CONSTANTS 

  enum
  {// handset hookswitch 
    telVolSame = 0, // l// speakerphone 'on' switch 

  enum
  {
    telVolStateSame = 0, // leaves device in same state     telVolStateOff = 1,  /* turns the device off, but doesn't change the volume
                          // device off hook 
    telVolStateOn = 2    /// device on hook 
                            previously set. */
  };
// VOLUME CONTROL CONSTANTS 
  // DISPLAY CONSTANTS   enum
  {
    telNormalDisplayMode = 1,  // volume of the handset speaker 
// sensitivity of the handset mic 
  // KEY PRESS CONSTANTS   enum// speakerphone volume 
  {// sensitivity of the spkrphone mic 
    telHangupKey = 1,          // volume of the ringer 
// volume of the built-in speakerphone 
  enum// sensitivity of the built-in speakerphone mic 
  {
    telKeyPadPress = 1,    // key pressed on 12 digit keypad    telFeatureKeyPress = 2 // feature Key Pressed   };

  enum
  {// leaves the volume at previous level 
    telTerminalEnabl// turns volume down to minimum level, but not off 
    telTerminalDisab// highest level allowed by the Telephone Manager 
  };

  enum
  {
    telUnknown = 0,      // leaves device in same state 

  // ALERT PATTERN   enum
  {
    telPattern0 = 0,
    telPattern1 = 1,
    telPattern2 = 2,
  // DISPLAY CONSTANTS 
    telPattern4 = 4,
    telPattern5 = 5,
    telPattern6 = 6,// normal display mode 
    telPattern7 = 7,// inspect display mode 
    telPatternOff = 8,// miscellaneous display mode 
    telPatternUndefined = 15// message retrieval mode 
  };// electronic directory mode 
// entire Display 
  // DN TYPES   enum
  {
  // KEY PRESS CONSTANTS 

  // DN USAGE   enum
  {// drop, or release, key pressed 
    telDNNotUsed = 0,     // DN // hold key pressed 
// conference key pressed 
  // CALL FORWARDING TYPES   enu// transfer key pressed 
  {// call forward key pressed 
    telForwardImmediate = 1,  //// call back key pressed 
// do not disturb key pressed 
  // CALL FORWARDING MESSAGES   // call Pickup key pressed 
  {// call Park key pressed 
    telForwardCleared = 0, // fo// call Deflect key pressed 
// voice Mail Access key pressed 
  // DO NOT DISTURB TYPES   enum// call Reject key pressed 
  {// other key pressed 
    telDNDIntExt = 0,     // do not disturb for all internal and external calls    telDNDExternal = 1,   // do not disturb for external calls only     telDNDInternal = 2,   // do not disturb for internal calls only     telDNDNonIntercom = 3 // do not disturb for all calls except intercom   };

  // DO NOT DISTURB MESSAGES   enum
  {
    telDNDCleared = 0, // d// key pressed on 12 digit keypad
// feature Key Pressed 
  // VOICE MAIL MESSAGES   enum
  {
    telAllVoiceMessagesRead =
        0, // all messages have been read, none are  waiting            // to be read     telNewVoiceMessage =
        1 // a new message has arrived or messages are waiting for this DN   };

  // DNSELECT MESSAGE   enum
  {
    telDNDeselected = 0, // DN has been deselected     telDNSelected = 1    // DN has been selected   };

  // CALL ORIGINATORS   enum// unknown error 
  {// terminal hardware is disconnected 
    telInternalCall = 0,      // re// device driver is closed 

  // CALL TYPES   enum
  // ALERT PATTERN 
    telVoiceMailAccessOut = (-7),
    telPageOut = (-6),
    telIntercomOut = (-5),
    telCallbackOut = (-4),
    telPickup = (-3),
    telParkRetrieve = (-2),
    telNormalOut = (-1),
    telUnknownCallType = 0,
    telNormalIn = 1,
    telForwardedImmediate = 2,
    telForwardedBusy = 3,
    telForwardedNoAnswer = 4,
    telTransfer = 5,
    telDeflected = 6,
  // DN TYPES 
    telDeflectRecall = 8,
    telParkRecall = 9,
    telTransferredRecall = 1// counts all types of DNs 
    telIntercomIn = 11,// connected to PBX or other non-public switch 
    telCallbackIn = 12// connected to PBX or other non-public switch 
  };// and able to place internal calls only 
// connected to public network 
  // DIAL TYPES   enum// DN type unknown 
  {
    telDNDialable = 0,      // this DN could be dialed via TELSetupCall     telDNNorthAmerican = 1, // rmtDN is standard North America 10 digit number     telDNInternational = 2, // rmtDN is an international number     telDNAlmostDialable =
  // DN USAGE 

  // CALL PROGRESS MESSAGES   enum
  {// DN is not used - onhook 
    telCAPDialTone = 1, //// DN used for POTs call 
                          // DN used for fax call 
    telCAPRoutedOff =// DN used for data call 
        7,                // Incoming call at DN 
                          // DN is in unknown state 
    telCAPCPC = 12,               // telephone tool detected CPC signal     telCAPNoDialTone = 13,        // dial tone not detected     telCAPUnknown = 15,           // call progress state unknown     telCAPDialDisabled = 16,      // Blacklisting: Dial Disabled     telCAPBlacklistedNumber = 17, // Blacklisting: Blacklisted Number     telCAPForbiddenNumber = 18,   // Blacklisting: Forbidden Number     telCAPModemGuardTime = 19,    // Modem Guard Timein force, unable to dial     telCAPLCDetected =
        20,           // trying to dial a number while the handset is offhook     telCAPLostLC = 21 /* trying manual dial or answer while handset not off hook
  // CALL FORWARDING TYPES 
  };

  // OUTGOING CALL MESSAGES   // immediately forward calls 
  {// forward on Busy 
    telPhysical = 0,    // use// forward on No answer 
// forwarding for busy and no answer
  // DISCONNECT MESSAGES   enu// type of forwarding is unknown 
  {
    telLocalDisconnect =
  // CALL FORWARDING MESSAGES 

  // DISCONNECT TYPES   enum
  {// forwarding has been cleared 
    telCADNormal = 1,      // forwarding has been established
// attempt to setup forwarding has failed
  // CONFERENCE MESSAGES   enum
  {
  // DO NOT DISTURB TYPES 

  // TRANSFER MESSAGES   enum
  {// do not disturb for all internal and external calls
    telTransferPrepFailed // do not disturb for external calls only 
                          // do not disturb for internal calls only 
  };// do not disturb for all calls except intercom 

  // HOLD MESSAGES   enum
  // DO NOT DISTURB MESSAGES 
    telHoldCleared = 0,
    telHoldEst = 1,
    telHoldFailed = 2// do not disturb has been cleared 
  };// do not disturb has been established 
// attempt to setup do not disturb has failed 
  // RECEIVE DIGIT MESSAGES   enum
  {
  // VOICE MAIL MESSAGES 
    telDigitNotAudible = 1
  };

  // CALL P// all messages have been read, none are  waiting 
  {// to be read 
    telCallParkEst = 1,            // call has been successfully parked     telCallParkRetrieveEst = 2,    // parked Call has been successfully retrieved     telCallParkFailed = 3,         // attempt to setup call park has failed     telCallParkRetrieveFailed = 4, // attempt to retrieve parked call failed     telCallParkRecall = 5          // call park has been recalled   };
// a new message has arrived or messages are waiting for this DN 
  // CALL BACK MESSAGES   enum
  {
  // DNSELECT MESSAGE 
                                      is zero, else call IS calling back on CA */
    telCallbackFailed = 3,         // attempt to setup callback has failed     telCallbackDesired = 4,        /* a user has called this terminal, received no answer
                         // DN has been deselected 
    telCallbackDesiredCle// DN has been selected 

  // CALL REJECT MESSAGES   enum
  // CALL ORIGINATORS 
    telCallRejectFailed = 0, // attempt to reject call has failed     telCallRejectEst = 1,    // call successfully rejected     telCallRejected = 2      // message to originator that call was rejected   };

  // CALL DEFLECT MESSAGES   e// return nth internal CA 
  {// return nth external CA 
    telCallDeflectFailed = 0, // unknown call type 
        3, // message to origi// return nth CA internal or external 
        4,                  /* a call was automatically deflected from this terminal as a result of
                               immediate call forwarding */
  // CALL TYPES 
                               terminal as a result of call forwarding on busy */
    telAutoDeflectNoAnswer =
        6 /* a call was automatically deflected from this terminal as a result of
             call forwarding on no answer */
  };

  // CONFERENCE SPLIT MESSAGES   enum
  {
    telConferenceSplitFailed = 0, // CA could not be split     telConferenceSplitEst = 1     // CA split successfully   };

  // CONFERENCE DROP MESSAGES   enum
  {
    telConferenceDropFailed = 0, // CA could not be dropped     telConferenceDropped = 1     // CA dropped successfully   };

  // CALL PICKUP MESSAGES   enum
  {
    telCallPickupEst = 0,    // call pickup was successful     telCallPickupFailed = 1, // call pickup failed     telCallPickedUp =
        2 // message to originator that call was picked up at a different DN   };

  // PAGING MESSAGES   enum
  {
    telPageEst = 0,      // paging was successful     telPageComplete = 1, // paging activity completed     telPageFailed = 2    // paging failed   };

  // INTERCOM MESSAGES   enum
  // DIAL TYPES 
    telIntercomEst = 0,      // intercom was successful     telIntercomComplete = 1, // intercom activity completed     telIntercomFailed = 2    // intercom failed   };

  // MODEM TONE MESSAGES   e// this DN could be dialed via TELSetupCall 
  {// rmtDN is standard North America 10 digit number 
    telModemToneDetected = 0// rmtDN is an international number 

  // FAX TONE MESSAGES// rmtDN is almost dialable, missing prefix such as 9 or 1 
  {// unknown whether DN is dialable 
    telFaxToneDetected = 0, // fax tone was detected     telFaxToneCleared = 1   // fax tone went away   };

  // CALL PROGRESS MESSAGES 
  {
    telInUsePrivate = 0, // MADN is in use and can't be accessed     telInUseCanAccess =
        1, // MADN is in// dial tone 
        2,              // destination CA is alerting 
// dialing the other end 
  // CALL APPEARANCE STA// reorder 
  {// busy 
    telCAIdleState = 0,     // a call doesn't exist at this time     telCAInUseState = 1,    // the call is active but at another terminal     telCAOfferState = 2,    // a call is being offered to the terminal     telCAQueuedState = 3,   // a call is being queued at this terminal     telCAAlertingState = 4, // a call is alerting at the terminal     telCADialToneState = 5, // initiated outgoing call has dialtone     telCADialingState = 6,  // initiated outgoing call is dialing     telCAWaitingState =
        7,                      // initiated outgoing call is waiting for response from destination     telCARingingState = 8,      // the outgoing call is ringing.     telCABusyState = 9,         // destination is busy or can't be reached     telCAHeldState = 10,        // call has been put on hold by this terminal     telCAConferencedState = 11, // this CA is part of a conference now     telCAActiveState =
        12,                         // the call is active and parties are free to exchange data    telCAReorderState = 13,         // CA is in a reorder state     telCAConferencedHeldState = 14, // CA is a conference call in a held state     telCAUnknownState = 15          // the call state is unknown   };
// call routed off-network; no further progress will be available 
  // TERMINAL MESSAGE EVENTMASKS  // call timed out 
  {// name and rmtDN information has been updated 
    telTermHookMsg = 0x00000001,  // the network is prompting for more information 
                                             to active or vice versa */
    telTermIndHSConnectMsg =
        0x00000400,               // telephone tool detected CPC signal 
        0x00001FFF // mask to all // dial tone not detected 
// call progress state unknown 
  // DN MESSAGE EVENTMASK CONSTANT// Blacklisting: Dial Disabled 
  {// Blacklisting: Blacklisted Number 
    telDNForwardMsg = 0x00000001, // Blacklisting: Forbidden Number 
// Modem Guard Timein force, unable to dial 
  // CA MESSAGE EVENTMASK CONSTANTS   enum
  {// trying to dial a number while the handset is offhook 
    telCAAlertingMsg = 0x00000001,   // CA is alerting      telCAOfferMsg = 0x00000002,      // CA is being offered a call     telCAProgressMsg = 0x00000004,   // call progress info for this CA     telCAOutgoingMsg = 0x00000008,   // CA is initiating an outgoing call     telCADisconnectMsg = 0x00000010, // CA disconnected (dropped or rmt disc     telCAActiveMsg =
        0x00000020,                       // CA is active and voice/data is free to flow end to end     telCAConferenceMsg = 0x00000040,      // conference activity on CA     telCATransferMsg = 0x00000080,        // transfer feature activity     telCAHoldMsg = 0x00000100,            // hold feature activity     telCADigitsMsg = 0x00000200,          // remote signaling digits arrived     telCACallParkMsg = 0x00000400,        // CA call park feature activity     telCACallbackMsg = 0x00000800,        // CA call back feature activity      telCARejectMsg = 0x00001000,          // CA is rejected     telCADeflectMsg = 0x00002000,         // CA is deflected     telCAForwardMsg = 0x00004000,         // CA is forwarded to this DN      telCAConferenceSplitMsg = 0x00008000, // conference split activity      telCAConferenceDropMsg = 0x00010000,  // conference drop activity      telCAQueuedMsg = 0x00020000,          // CA has been queued      telCAInUseMsg = 0x00040000,           // CA is in use      telCACallPickupMsg = 0x00080000,      // CA pickup activity     telCAPagingMsg = 0x00100000,          // CA paging activity     telCAIntercomMsg = 0x00200000,        // CA intercom activity     telCAModemToneMsg = 0x00400000,       // modem tones detected     telCAFaxToneMsg = 0x00800000,         // fax tones detected     telCAIdleMsg = 0x01000000,            // CA is in idle state     telCASuccessiveAlertMsg = 0x02000000, // phone is alerting, one per ring     telCAUserUserInfoMsg =
        0x04000000,                       // user to user information has arrrived for this CA     telCAHandOffMsg = 0x08000000,         // CA is ready for hand-off     telCAVoiceDetectedMsg = 0x10000000,   // voice Detect related event     telCASilenceDetectedMsg = 0x20000000, // silence Detect related event     telCADigitsImmMsg =
        0x40000000,                   // immidiate arrival of remote signaling digits     telCAOtherMsg = (long)0x80000000, // tool specific CA message     telAllCAMsgs = 0x7FFFFFFF         // mask to all non tool specific CA events   };
// OUTGOING CALL MESSAGES 
  typedef OSErr TELErr;
  typedef UInt32 TELFlags;
  enum// user lifted handset and initiated call 
  {// programmatic initiation of outgoing call 
    telNoMenus = 1L << 16, // tells tool not to display any custom menus     telQuiet =
        1L << 17, // tells tool not to display any dialog boxes or alerts     telConfigChanged =
  // DISCONNECT MESSAGES 

  typedef UInt32 TELFeatureFlags;
  enum
  {// local party, this user, responsible for disconnect 
    pcmAvail = 1L << 0,     // remote party responsible for disconnect 
        1L << 12, // sound streams are supported on the handset     hasIndHandset =
        1L << 13, // handset can be accessed independently of the phone line     hasBuiltinSpeakerphone =
  // DISCONNECT TYPES 

  struct TELTermRecord
  {// normal disconnect 
    short tRef;// remote user busy 
    TELFeatureFlags featureFlags;// remote not responding 
    short handsetSpeakerVol;// call rejected 
    short handsetMicVol;// number changed 
    short speakerphoneVol;// invalid destination address 
    short speakerphoneMicVol;// requested facility rejected 
    short ringerVol;// destination not obtainable 
    short otherVol;// network congestion 
    short ringerTypes;// incompatible destination 
    short hasDisplay;// call timed out 
    short displayRows;// reason unknown 
    short numDNs;
    short maxAllocCA;
  // CONFERENCE MESSAGES 
    short builtinSpeakerVol;
    short builtinSpeakerMicVol;
    long reserved;// conference could not be prepared 
  };// conference prepared successfully 
  typedef struct TELTermRecord TE// conference could not be established 
  typedef TELTermRecord *TELTermP// conference established 
  struct TELRecord
  {
  // TRANSFER MESSAGES 

    TELFlags flags;
    short reserved;// transfer could not be prepared 
// transfer prepared successfully 
    long refCon;// consult or blind xfer successful 
    long userData;// consult or blind xfer failed 

    UniversalProcPtr defproc;

    Ptr config;
  // HOLD MESSAGES 

    TELTermPtr pTELTerm;

    long telPrivate;
    long reserved1;
    long reserved2;

  // RECEIVE DIGIT MESSAGES 
    short version;
  };
  typedef struct TELRecord TELRecord;
  typedef TELRecord *TELPtr;
  typedef TELPtr *TELHandle;

  // CALL PARK MESSAGES 
  enum
  {
    dndSub = 1L << 0,              // call has been successfully parked 
        1L << 24,              // A// parked Call has been successfully retrieved 
        1L << 26 // tollSaver is cu// attempt to setup call park has failed 
// attempt to retrieve parked call failed 
  typedef UInt32 TELDNForwardFlags;// call park has been recalled 
  enum
  {
  // CALL BACK MESSAGES 

  struct TELDNRecord
  {// call back has been cleared 
// call back has been established 
    short dnRef;
    StringPtr dn;
    StringPtr dnPartyName;// attempt to setup callback has failed 
    StringPtr dnSubaddress;
    TELHandle hTEL;
    short maxAllocCA;// call back for no answer no longer desired 
    short curAllocCA;// callback has occurred successfully 
    short dnType;
    TELDNFeatureFlags featureFlags;
  // CALL REJECT MESSAGES 
    short numIntercomIDs;
    short numPickupIDs;
    TELDNForwardFlags forward// attempt to reject call has failed 
    StringPtr iForwardDN;// call successfully rejected 
    StringPtr iForwardSubaddr// message to originator that call was rejected 
    StringPtr iForwardPartyName;
    StringPtr bForwardDN;
  // CALL DEFLECT MESSAGES 
    StringPtr bForwardPartyName;
    StringPtr naForwardDN;
    StringPtr naForwardSubaddr// attempt to deflect call has failed 
    StringPtr naForwardPartyNa// call successfully deflected 
    short naForwardRings;// deflected call has been recalled 
    long telDNPrivate;
    long re// message to originator that call was deflected to rmtDN 
    long userData;
    long reserved;
  };
  typedef struct TELDNRecord TELDNRecord;
  typedef TELDNRecord *TELDNPtr;
  typedef TELDNPtr *TELDNHandle;
  typedef UInt32 TELCAFeatureFlags;
  enum
  {
    holdSub = 1L << 0,           // hold subscribed      holdAvail = 1L << 1,         // hold available      holdActive = 1L << 2,        // hold active      conferenceSub = 1L << 3,     // conference subscribed     conferenceAvail = 1L << 4,   // conference available     conferenceActive = 1L << 5,  // conference active      conferenceDropSub = 1L << 6, // conference drop subscribed      conferenceDropAvail =
  // CONFERENCE SPLIT MESSAGES 
                                           required in TELConfPrep */
    transferSub = 1L << 11,             // transfer subscribed      transferAvail = 1L << 12,           // transfer available      transferActive = 1L << 13,          // transfer active     caRelated =
        1L << 14 // this CA is the// CA could not be split 
// CA split successfully 
  typedef UInt32 TELCAOtherFeatures;
  enum
  // CONFERENCE DROP MESSAGES 
    callbackSub = 1L << 0,         // call back subscribed     callbackAvail = 1L << 1,       // call back available     callbackActive = 1L << 2,      // call back active      callbackClearSub = 1L << 3,    // call back clearing subscribed     callbackNowSub = 1L << 4,      // call back now subscribed     callbackNowAvail = 1L << 5,    // call back now available      callbackBusy = 1L << 6,        // call back on busy     callbackNoAnswer = 1L << 7,    // call back on no answer     callbackReturnsRef = 1L << 8,  // call back returns a reference     parkSub = 1L << 9,             // call park subscribed     parkAvail = 1L << 10,          // call park available     parkActive = 1L << 11,         // call park active     parkRetrieveSub = 1L << 12,    // call park retrieve subscribed     parkRetrieveWithID = 1L << 13, // retrieve parked calls with IDs     parkWithReturnedID = 1L << 14, // park call to a specific remote ID     parkWithGivenID = 1L << 18,    // for switch that requires ID for parking     rejectable = 1L << 15,         // CA is rejectable      deflectable = 1L << 16,        // CA is deflectable      acceptable = 1L << 17,         // CA is acceptable     voiceDetected =
        1L
        << 19, // voice has been // CA could not be dropped 
        1L << 20 // incoimng call// CA dropped successfully 

  typedef struct TELCARecord TELCARecord;
  // CALL PICKUP MESSAGES 
  typedef TELCAPtr *TELCAHandle;
  struct TELCARecord
  {// call pickup was successful 
    short caRef;// call pickup failed 
    TELDNHandle hTELDN;
    TELHan// message to originator that call was picked up at a different DN 
    short caState;
    TELCAHandle relatedCA;
  // PAGING MESSAGES 
                       */
    short intExt;
    short callType;// paging was successful 
    short dialType;// paging activity completed 
    short bearerType;// paging failed 
    short rate;
    StringPtr rmtDN;
  // INTERCOM MESSAGES 
    StringPtr rmtSubaddress;
    StringPtr routeDN;
    StringPtr routePartyName;// intercom was successful 
    StringPtr routeSubaddress// intercom activity completed 
    short priority;// intercom failed 
    short conferenceLimit;
    TELCAFeatureFlags featureFlags;
  // MODEM TONE MESSAGES 
    long telCAPrivate;
    long refCon;
    long userData;// modem tone was detected 
    long reserved;// modem tone went away 
  };

  // FAX TONE MESSAGES 
  {
    telHandleType = 0,   // feature requires a terminal handle     telDNHandleType = 1, // feature requires a DN handle     telCAHandleType = 2  // feature requires a CA handle   };
// fax tone was detected 
  struct FeatureList// fax tone went away 
  {
    short featureID;
  // IN USE MESSAGES 
    short handleType;
    struct FeatureList *nextFeature;
  };// MADN is in use and can't be accessed 
  typedef struct FeatureList FeatureList;
  typedef F// MADN is in use, and others can access it and join in 
  // CA MESSAGE STRUCTURES FOR MSGINFO   struct CAGenericMsgRec
  {// MADN is in use, but available for any one person to access 
    StringPtr rmtDN;// MADN is no longer in use 
    StringPtr rmtName;
    StringPtr rmtSubaddress;
  // CALL APPEARANCE STATES 
  };
  typedef struct CAGenericMsgRec CAGenericMsgRec;
  struct CAUserUserInfoMsgRe// a call doesn't exist at this time 
  {// the call is active but at another terminal 
    StringPtr userUserInfo;// a call is being offered to the terminal 
  };// a call is being queued at this terminal 
  typedef struct CAUserUserI// a call is alerting at the terminal 
  struct CAConfMsgRec// initiated outgoing call has dialtone 
  {// initiated outgoing call is dialing 
    TELCAHandle relatedCA;
  };// initiated outgoing call is waiting for response from destination 
  typedef struct CAConfMsgRec CA// the outgoing call is ringing. 
  struct CATransfMsgRec// destination is busy or can't be reached 
  {// call has been put on hold by this terminal 
    StringPtr rmtDN;// this CA is part of a conference now 
    StringPtr rmtName;
    StringPtr rmtSubaddress;// the call is active and parties are free to exchange data
    short dialType;// CA is in a reorder state 
    TELCAHandle prepCA;// CA is a conference call in a held state 
  };// the call state is unknown 
  typedef struct CATransfMsgRec CATransfMsgRec;
  typedef CALLBACK_API(void, TelephoneTermMsgProcPtr)(TELHandle hTEL, long msg,
  // TERMINAL MESSAGE EVENTMASKS 
                                                      long globals);
  typedef CALLBACK_API(void, TelephoneDNMsgProcPtr)(
      TELDNHandle hTELDN, long Msg, short // the hookswitch state has changed 
      ConstStr255Param rmtDN, ConstStr255P// a phone pad key has been depressed 
      ConstStr255Param rmtSubaddress, long// volume setting has changed 
  typedef CALLBACK_API(void, TelephoneCAMs// display has changed 
                                          // terminal has become enabled 
                                          // terminal has been opened 
  typedef CALLBACK_API(void, TelephoneChoo// terminal is shutting down 
  typedef STACK_UPP_TYPE(TelephoneTermMsgP// terminal has been reset 
  typedef STACK_UPP_TYPE(TelephoneDNMsgPro// hard equipment error 
  typedef STACK_UPP_TYPE(TelephoneCAMsgProcPtr) TelephoneCAMsgUPP;
  typedef STACK_UPP_TYPE(TelephoneChooseIdleProcPtr) TelephoneChooseIdleUPP;
#if CALL_NOT_IN_CARBON
  /**// independent handset connection has been changed 
   *  NewTelephoneTermMsgUPP()// immidiate arrival of phone pad key 
   *// volume state has changed 
   *  Availability:// vendor defined error 
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib// mask to all non tool specific terminal events 
   *    \mac_os_x         not available
   */
  // DN MESSAGE EVENTMASK CONSTANTS 
  NewTelephoneTermMsgUPP(TelephoneTermMsgProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum// forward feature activity 
  {// do not disturb feature activity 
    uppTelephoneTermMsgProcInfo = 0x00// message has arrived for this DN 
  }; /* pascal no_return_value Func(4_// DN has been selected or deselected 
      */// a custom message for use by tools 
#ifdef __cplusplus// mask to all non tool specific dn events 
  inline TelephoneTermMsgUPP
  NewTelephoneTermMsgUPP(TelephoneTermMsgProcPtr userRoutine)
  // CA MESSAGE EVENTMASK CONSTANTS 
    return (TelephoneTermMsgUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                     uppTelephoneTermMsgProcInfo,
                                     // CA is alerting  
  }// CA is being offered a call 
#else// call progress info for this CA 
#define NewTelephoneTermMsgUPP(userRo// CA is initiating an outgoing call 
  (TelephoneTermMsgUPP) NewRoutineDes// CA disconnected (dropped or rmt disc 
                                             uppTelephoneTermMsgProcInfo, \
                                          // CA is active and voice/data is free to flow end to end 
#endif// conference activity on CA 
#endif// transfer feature activity 
// hold feature activity 
  /**// remote signaling digits arrived 
   *  NewTelephoneDNMsgUPP()// CA call park feature activity 
   *// CA call back feature activity  
   *  Availability:// CA is rejected 
   *    \non_carbon_cfm   available as mac// CA is deflected 
   *    \carbon_lib        not available// CA is forwarded to this DN  
   *    \mac_os_x         not available// conference split activity  
   */// conference drop activity  
  TelephoneDNMsgUPP// CA has been queued  
  NewTelephoneDNMsgUPP(TelephoneDNMsgProcP// CA is in use  
#if !OPAQUE_UPP_TYPES// CA pickup activity 
  enum// CA paging activity 
  {// CA intercom activity 
    uppTelephoneDNMsgProcInfo = 0x003FEBC0// modem tones detected 
  }; /* pascal no_return_value Func(4_byte// fax tones detected 
        4_bytes, 4_bytes, 4_bytes) */// CA is in idle state 
#ifdef __cplusplus// phone is alerting, one per ring 
  inline TelephoneDNMsgUPP
  NewTelephoneDNMsgUPP(TelephoneDNMsgProcP// user to user information has arrrived for this CA 
  {// CA is ready for hand-off 
    return (TelephoneDNMsgUPP)NewRoutineDe// voice Detect related event 
                                          // silence Detect related event 
                                                   GetCurrentArchitecture());
  }// immidiate arrival of remote signaling digits 
#else// tool specific CA message 
#define NewTelephoneDNMsgUPP(userRouti// mask to all non tool specific CA events 
  (TelephoneDNMsgUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppTelephoneDNMsgProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**// tells tool not to display any custom menus 
   *  NewTelephoneCAMsgUPP()
   *// tells tool not to display any dialog boxes or alerts 
   *  Availability:
   *    \non_carb// notifies application that the config has changed 
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TelephoneCAMsgUPP
  NewTelephoneCAMsgUPP(TelephoneCAMsgProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES// true if PCM voice data accessible 
  enum// true if a phone handset is attached  
  {// true if a 2 way speakerphone is attached 
    uppTelephoneCAMsgProcInfo = 0// can on-hook dial 
  }; /* pascal no_return_value Fu// terminal has its own ringer 
        4_bytes) */// application can write to the display 
#ifdef __cplusplus// attached phone has standard 12 key pad 
  inline TelephoneCAMsgUPP// terminal has a videophone 
  NewTelephoneCAMsgUPP(TelephoneC// reserved for future use 
  {// can perform cross-DN conferences 
    return (TelephoneCAMsgUPP)New// attached network supports subaddressing 
                                 // network supports user-to-user info 
                                                   GetCurrentArchitecture());
  }// sound streams are supported on the handset 
#else
#define NewTelepho// handset can be accessed independently of the phone line 
  (TelephoneCAMsgUPP)                                                         \
      NewRoutineD// speaker and microphone of the Mac can be used 
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewTelephoneChooseIdleUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TelephoneChooseIdleUPP
  NewTelephoneChooseIdleUPP(TelephoneChooseIdleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppTelephoneChooseIdleProcInfo = 0x00000000
  }; // pascal no_return_value Func() #ifdef __cplusplus
  inline TelephoneChooseIdleUPP
  NewTelephoneChooseIdleUPP(TelephoneChooseIdleProcPtr userRoutine)
  {
    return (TelephoneChooseIdleUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppTelephoneChooseIdleProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewTelephoneChooseIdleUPP(userRoutine)                \
  (TelephoneChooseIdleUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppTelephoneChooseIdleProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeTelephoneTermMsgUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeTelephoneTermMsgUPP(TelephoneTermMsgUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeTelephoneTermMsgUPP(TelephoneTermMsgUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeTelephoneTermMsgUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**// do not disturb subscribed 
   *  DisposeTelephoneDNMsgUPP()// do not disturb available 
   *// do not disturb active 
   *  Availability:// message waiting subscribed 
   *    \non_carbon_cfm   available a// message waiting available 
   *    \carbon_lib        not availa// message waiting active 
   *    \mac_os_x         not availab// paging is subscribed 
   */// paging is available 
  void// paging is active 
  DisposeTelephoneDNMsgUPP(TelephoneD// intercom is subscribed 
#if !OPAQUE_UPP_TYPES// intercom is available 
#ifdef __cplusplus// intercom is active 
  inline void DisposeTelephoneDNMsgUP// DN select is subscribed 
  {// DN select is available 
    DisposeRoutineDescriptor((Univers// DN is selected 
  }// call pickup is subscribed 
#else// call pickup is available 
#define DisposeTelephoneDNMsgUPP(user// a CA is allocated for this DN 
#endif// this DN is not on this terminal 
#endif// commands can be sent to this DN 
// an outgoing CA can be initiated 
  /**// voice mail waiting for this dn 
   *  DisposeTelephoneCAMsgUPP()// sound streams are supported on this DN 
   *// AutoAnswer is set for this DN 
   *  Availability:
   *    \non_carbon_cfm   avail// AutoAnswer is currently applied to CA on this DN 
   *    \carbon_lib        not // tollSaver is set for this DN 
   *    \mac_os_x         not available
   */// tollSaver is currently applied to CA on this DN 
  void
  DisposeTelephoneCAMsgUPP(TelephoneCAMsgUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeTelephoneCAMsgUPP(TelephoneCAMsgUPP userUPP)
  {// immediate call forward subscribed 
    DisposeRoutineDescriptor((Universa// immediate call forward available 
  }// immediate call forward active 
#else// forward on busy subscribed 
#define DisposeTelephoneCAMsgUPP(userU// forward on busy available 
#endif// forward on busy active 
#endif// no answer call forward subscribed 
// no answer call forward available 
  /**// no answer call forward active 
   *  DisposeTelephoneChooseIdleUPP()// busy & no answer call forward subscribed 
   *// busy & no answer call forward available 
   *  Availability:// busy & no answer call forward active 
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeTelephoneChooseIdleUPP(TelephoneChooseIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeTelephoneChooseIdleUPP(TelephoneChooseIdleUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeTelephoneChooseIdleUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeTelephoneTermMsgUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeTelephoneTermMsgUPP(TELHandle hTEL, long msg, short mtype, short value,
                            long globals, TelephoneTermMsgUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeTelephoneTermMsgUPP(TELHandle hTEL, long msg, short mtype,
                                        short value, long globals,
                                        TelephoneTermMsgUPP userUPP)
  {
    CALL_FIVE_PARAMETER_UPP(userUPP, uppTelephoneTermMsgProcInfo, hTEL, msg,
                            mtype, value, globals);
  }
#else
#define InvokeTelephoneTermMsgUPP(hTEL, msg, mtype, value, globals, userUPP) \
  CALL_FIVE_PARAMETER_UPP((userUP// hold subscribed  
                          (msg), // hold available  
#endif// hold active  
#endif// conference subscribed 
// conference available 
  /**// conference active  
   *  InvokeTelephoneDNMsgUPP()// conference drop subscribed  
   *
   *  Availability:// a call to TELDrop will drop this CA only from a conference 
   *    \non_carbon_cfm   available as m// conference split subscribed  
   *    \carbon_lib        not available// conference split available for this CA 
   *    \mac_os_x         not available
   */
  void// transfer subscribed  
  InvokeTelephoneDNMsgUPP(TELDNHandle hT// transfer available  
                          ConstStr255Par// transfer active 
                          ConstStr255Param rmtSubaddress, long globals,
                 // this CA is the specified in some other CA's relatedCA field
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeTelephoneDNMsgUPP(TELDNHandle hTELDN, long Msg, short mtype,
                                      short value, ConstStr255Param rmtDN,
                                      ConstStr255Param rmtName,
                                   // call back subscribed 
                                   // call back available 
  {// call back active  
    CALL_EIGHT_PARAMETER_UPP(userUP// call back clearing subscribed 
                             mtype,// call back now subscribed 
                             global// call back now available  
  }// call back on busy 
#else// call back on no answer 
#define InvokeTelephoneDNMsgUPP(hTE// call back returns a reference 
                                rmt// call park subscribed 
  CALL_EIGHT_PARAMETER_UPP((userUPP// call park available 
                           (Msg), (// call park active 
                           (rmtSuba// call park retrieve subscribed 
#endif// retrieve parked calls with IDs 
#endif// park call to a specific remote ID 
// for switch that requires ID for parking 
  /**// CA is rejectable  
   *  InvokeTelephoneCAMsgUPP()// CA is deflectable  
   *// CA is acceptable 
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon// voice has been detected on this CA incase of an incoming call
   *    \mac_os_x         not available
   */// incoimng call was answered on TollSaver rings 
  void
  InvokeTelephoneCAMsgUPP(TELCAHandle hTELCA, long Msg, short mtype, short value,
                          Ptr Msginfo, long globals, TelephoneCAMsgUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeTelephoneCAMsgUPP(TELCAHandle hTELCA, long Msg, short mtype,
                                      short value, Ptr Msginfo, long globals,
                                      TelephoneCAMsgUPP userUPP)
  {
    CALL_SIX_PARAMETER_UPP(userUPP, uppTelephoneCAMsgProcInfo, hTELCA, Msg, mtype,
                           value, Msginfo, globals);
  }
#else
#define InvokeTelephoneCAMsgUPP(hTELCA, Msg, mtype, value, Msginfo, globals, \
                                userUPP)                                     \
  CALL_SIX_PARAMETER_UPP((userUPP), uppTelephoneCAMsgProcInfo, (hTELCA),     \
                         (Msg), (mtype), (value), (Msginfo), (globals))
#endif
#endif

  /**
   *  InvokeTelephoneChooseIdleUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeTelephoneChooseIdleUPP(TelephoneChooseIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeTelephoneChooseIdleUPP(TelephoneChooseIdleUPP userUPP)
  {
    CALL_ZERO_PARAMETER_UPP(userUPP, uppTelephoneChooseIdleProcInfo);
  // Constants for HandleType in structure above 
#else
#define InvokeTelephoneChooseIdleUPP(userUPP) \
  CALL_ZERO_PARAMETER_UPP// feature requires a terminal handle 
#endif// feature requires a DN handle 
#endif// feature requires a CA handle 

#endif // CALL_NOT_IN_CARBON 
#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewTelephoneTermMsgProc(userRoutine) NewTelephoneTermMsgUPP(userRoutine)
#define NewTelephoneDNMsgProc(userRoutine) NewTelephoneDNMsgUPP(userRoutine)
#define NewTelephoneCAMsgProc(userRoutine) NewTelephoneCAMsgUPP(userRoutine)
#define NewTelephoneChooseIdleProc(userRoutine) \
  NewTelephoneChooseIdleUPP(userRoutine)
#define CallTelephoneTermMsgProc(userRoutine, hTEL, msg, mtype, value, \
                                 globals)                              \
  InvokeTelephoneTermMsgUPP(hTEL, msg, mtype, value, globals, userRoutine)
#d// CA MESSAGE STRUCTURES FOR MSGINFO 
                               rmtName, rmtSubaddress, globals)               \
  InvokeTelephoneDNMsgUPP(hTELDN, Msg, mtype, value, rmtDN, rmtName,          \
                          rmtSubaddress, globals, userRoutine)
#define CallTelephoneCAMsgProc(userRoutine, hTELCA, Msg, mtype, value, \
                               Msginfo, globals)                       \
  InvokeTelephoneCAMsgUPP(hTELCA, Msg, mtype, value, Msginfo, globals, \
                          userRoutine)
#define CallTelephoneChooseIdleProc(userRoutine) \
  InvokeTelephoneChooseIdleUPP(userRoutine)
#endif // CALL_NOT_IN_CARBON 
#endif // CALL_NOT_IN_CARBON 
#if CALL_NOT_IN_CARBON
  /**
   *  InitTEL()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  InitTEL(void);

  /**
   *  TELGetInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetInfo(TELHandle hTEL);

  /**
   *  TELOpenTerm()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELOpenTerm(TELHandle hTEL);

  /**
   *  TELResetTerm()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELResetTerm(TELHandle hTEL);

  /**
   *  TELCloseTerm()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCloseTerm(TELHandle hTEL);

  /**
   *  TELTermMsgHand()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELTermMsgHand(TELHandle hTEL, long eventMask, TelephoneTermMsgUPP msgProc,
                 long globals);

  /**
   *  TELClrTermMsgHand()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELClrTermMsgHand(TELHandle hTEL, TelephoneTermMsgUPP msgProc);

  /**
   *  TELTermEventsSupp()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELTermEventsSupp(TELHandle hTEL, long *eventMask);

  /**
   *  TELGetProcID()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  TELGetProcID(Str255 name);

  /**
   *  TELNew()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELHandle
  TELNew(short procID, TELFlags flags, long refCon, long userData);

  /**
   *  TELNewWithResult()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELHandle
  TELNewWithResult(short procID, TELFlags flags, long refCon, long userData,
                   TELErr *error);

  /**
   *  TELDefault()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDefault(Ptr *theConfig, short procID, Boolean allocate);

  /**
   *  TELValidate()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */// pascal no_return_value Func() 
  Boolean
  TELValidate(TELHandle hTEL);

  /**
   *  TELGetConfig()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Ptr TELGetConfig(TELHandle hTEL);

  /**
   *  TELSetConfig()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  TELSetConfig(TELHandle hTEL, Ptr thePtr);

  /**
   *  TELChoose()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELChoose(TELHandle *hTEL, Point where, TelephoneChooseIdleUPP idleProc);

  /**
   *  TELSetupPreflight()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle
  TELSetupPreflight(short procID, long *magicCookie);

  /**
   *  TELSetupSetup()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TELSetupSetup(short procID, Ptr theConfig, short count, DialogRef theDialog,
                long *magicCookie);

  /**
   *  TELSetupFilter()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  TELSetupFilter(short procID, Ptr theConfig, short count, DialogRef theDialog,
                 EventRecord *theEvent, short *theItem, long *magicCookie);

  /**
   *  TELSetupItem()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TELSetupItem(short procID, Ptr theConfig, short count, DialogRef theDialog,
               short *theItem, long *magicCookie);

  /**
   *  TELSetupCleanup()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TELSetupCleanup(short procID, Ptr theConfig, short count, DialogRef theDialog,
                  long *magicCookie);

  /**
   *  TELSetupXCleanup()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TELSetupXCleanup(short procID, Ptr theConfig, short count, DialogRef theDialog,
                   Boolean OKed, long *magicCookie);

  /**
   *  TELSetupPostflight()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TELSetupPostflight(short procID);

  /**
   *  TELDispose()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDispose(TELHandle hTEL);

  /**
   *  TELCountDNs()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  TELCountDNs(TELHandle hTEL, short dnType, Boolean physical);

  /**
   *  TELDNLookupByIndex()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDNLookupByIndex(TELHandle hTEL, short dnType, Boolean physical, short index,
                     TELDNHandle *hTELDN);

  /**
   *  TELDNLookupByName()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDNLookupByName(TELHandle hTEL, ConstStr255Param DN, TELDNHandle *hTELDN);

  /**
   *  TELDNSelect()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDNSelect(TELDNHandle hTELDN, Boolean select);

  /**
   *  TELDNDispose()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDNDispose(TELDNHandle hTELDN);

  /**
   *  TELGetDNInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetDNInfo(TELDNHandle hTELDN);

  /**
   *  TELGetDNFlags()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetDNFlags(TELDNHandle hTELDN, long *dnFeatureFlags, long *dnForwardFlags);

  /**
   *  TELDNMsgHand()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *   // CALL_NOT_IN_CARBON 
   *    \mac_os_x         not available
   */
// support for pre-Carbon UPP routines: New...Proc and Call...Proc 
  TELDNMsgHand(TELDNHandle hTELDN, Boolean allDNs, long eventMask,
               TelephoneDNMsgUPP msgProc, long globals);

  /**
   *  TELClrDNMsgHand()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELClrDNMsgHand(TELDNHandle hTELDN, TelephoneDNMsgUPP msgProc);

  /**
   *  TELDNEventsSupp()
   *
   *  Availability:
   *   // CALL_NOT_IN_CARBON 
   *    \carbon_lib        not available
   *   // CALL_NOT_IN_CARBON 
   */
  TELErr
  TELDNEventsSupp(TELDNHandle hTELDN, long *eventMask);

  /**
   *  TELCountCAs()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  TELCountCAs(TELDNHandle hTELDN, short internalExternal);

  /**
   *  TELCALookup()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCALookup(TELDNHandle hTELDN, short internalExternal, short index,
              TELCAHandle *hTELCA);

  /**
   *  TELCADispose()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCADispose(TELCAHandle hTELCA);

  /**
   *  TELGetCAState()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetCAState(TELCAHandle hTELCA, short *state);

  /**
   *  TELGetCAFlags()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetCAFlags(TELCAHandle hTELCA, long *caFeatureFlags, long *caOtherFeatures);

  /**
   *  TELGetCAInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetCAInfo(TELCAHandle hTELCA);

  /**
   *  TELCAMsgHand()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCAMsgHand(TELDNHandle hTELDN, long eventMask, TelephoneCAMsgUPP msgProc,
               long globals);

  /**
   *  TELClrCAMsgHand()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELClrCAMsgHand(TELDNHandle hTELDN, TelephoneCAMsgUPP msgProc);

  /**
   *  TELCAEventsSupp()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCAEventsSupp(TELDNHandle hTELDN, long *eventMask);

  /**
   *  TELSetupCall()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELSetupCall(TELDNHandle hTELDN, TELCAHandle *hTELCA, ConstStr255Param destDN,
               ConstStr255Param destName, ConstStr255Param destSubaddress,
               ConstStr255Param userUserInfo, short bearerType, short rate);

  /**
   *  TELConnect()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELConnect(TELCAHandle hTELCA);

  /**
   *  TELDialDigits()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDialDigits(TELCAHandle hTELCA, ConstStr255Param digits);

  /**
   *  TELAcceptCall()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELAcceptCall(TELCAHandle hTELCA);

  /**
   *  TELRejectCall()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELRejectCall(TELCAHandle hTELCA, short reason);

  /**
   *  TELDeflectCall()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDeflectCall(TELCAHandle hTELCA, ConstStr255Param rmtDN,
                 ConstStr255Param rmtName, ConstStr255Param rmtSubaddress);

  /**
   *  TELAnswerCall()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELAnswerCall(TELCAHandle hTELCA);

  /**
   *  TELDrop()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDrop(TELCAHandle hTELCA, ConstStr255Param userUserInfo);

  /**
   *  TELHold()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELHold(TELCAHandle hTELCA);

  /**
   *  TELRetrieve()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELRetrieve(TELCAHandle hTELCA);

  /**
   *  TELConferencePrep()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELConferencePrep(TELCAHandle hTELCA1, TELCAHandle hTELCA2,
                    short numToConference);

  /**
   *  TELConferenceEstablish()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELConferenceEstablish(TELCAHandle hTELCA1, TELCAHandle hTELCA2);

  /**
   *  TELConferenceSplit()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELConferenceSplit(TELCAHandle hTELCA);

  /**
   *  TELTransferPrep()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELTransferPrep(TELCAHandle hTELCA1, TELCAHandle hTELCA2);

  /**
   *  TELTransferEstablish()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELTransferEstablish(TELCAHandle hTELCA1, TELCAHandle hTELCA2);

  /**
   *  TELTransferBlind()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELTransferBlind(TELCAHandle hTELCA, ConstStr255Param rmtDN,
                   ConstStr255Param rmtName, ConstStr255Param rmtSubaddress);

  /**
   *  TELForwardSet()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELForwardSet(TELDNHandle hTELDN, ConstStr255Param forwardDN,
                ConstStr255Param forwardName, ConstStr255Param forwardSubaddress,
                short forwardType, short numrings);

  /**
   *  TELForwardClear()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELForwardClear(TELDNHandle hTELDN, short forwardType);

  /**
   *  TELCallbackSet()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCallbackSet(TELCAHandle hTELCA, short *callbackRef);

  /**
   *  TELCallbackClear()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCallbackClear(TELHandle hTEL, short callbackRef);

  /**
   *  TELCallbackNow()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCallbackNow(TELCAHandle hTELCA, short callbackRef);

  /**
   *  TELDNDSet()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDNDSet(TELDNHandle hTELDN, short dndType);

  /**
   *  TELDNDClear()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDNDClear(TELDNHandle hTELDN, short dndType);

  /**
   *  TELCallPickup()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCallPickup(TELCAHandle hTELCA, ConstStr255Param pickupDN,
                short pickupGroupID);

  /**
   *  TELParkCall()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELParkCall(TELCAHandle hTELCA, StringPtr *parkRetrieveID,
              ConstStr255Param parkID);

  /**
   *  TELRetrieveParkedCall()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELRetrieveParkedCall(TELCAHandle hTELCA, ConstStr255Param parkRetrieveID);

  /**
   *  TELVoiceMailAccess()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELVoiceMailAccess(TELCAHandle hTELCA);

  /**
   *  TELPaging()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELPaging(TELCAHandle hTELCA, short pageID);

  /**
   *  TELIntercom()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELIntercom(TELCAHandle hTELCA, short intercomID);

  /**
   *  TELOtherFeatureList()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELOtherFeatureList(TELHandle hTEL, FeatureListPtr *fList);

  /**
   *  TELOtherFeatureImplement()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELOtherFeatureImplement(TELHandle hTEL, Handle theHandle, short featureID);

  /**
   *  TELToolFunctions()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELToolFunctions(TELHandle hTEL, short msgcode, Boolean *supportsIt);

  /**
   *  TELOtherFunction()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELOtherFunction(TELHandle hTEL, Ptr paramblock, long size);

  /**
   *  TELGetHooksw()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetHooksw(TELHandle hTEL, short hookType, Boolean *offHook);

  /**
   *  TELSetHooksw()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELSetHooksw(TELHandle hTEL, short hookType, Boolean offHook);

  /**
   *  TELGetVolume()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetVolume(TELHandle hTEL, short volType, short *level, short *volState);

  /**
   *  TELSetVolume()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELSetVolume(TELHandle hTEL, short volType, short *level, short volState);

  /**
   *  TELAlert()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELAlert(TELHandle hTEL, short *level, short alertPattern);

  /**
   *  TELGetDisplay()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetDisplay(TELHandle hTEL, short index, short *displayMode, StringPtr *text);

  /**
   *  TELSetDisplay()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELSetDisplay(TELHandle hTEL, short index, short displayMode,
                ConstStr255Param text);

  /**
   *  TELIdle()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TELIdle(TELHandle hTEL);

  /**
   *  TELActivate()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TELActivate(TELHandle hTEL, Boolean activate);

  /**
   *  TELResume()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TELResume(TELHandle hTEL, Boolean resume);

  /**
   *  TELMenu()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  TELMenu(TELHandle hTEL, short menuID, short item);

  /**
   *  TELEvent()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TELEvent(TELHandle hTEL, const EventRecord *theEvent);

  /**
   *  TELGetToolName()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  TELGetToolName(short procID, Str255 name);

  /**
   *  TELGetVersion()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle
  TELGetVersion(TELHandle hTEL);

  /**
   *  TELGetTELVersion()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  TELGetTELVersion(void);

  /**
   *  TELIntlToEnglish()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELIntlToEnglish(TELHandle hTEL, Ptr inputPtr, Ptr *outputPtr, short language);

  /**
   *  TELEnglishToIntl()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELEnglishToIntl(TELHandle hTEL, Ptr inputPtr, Ptr *outputPtr, short language);

  /**
   *  TELGetDNSoundInput()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetDNSoundInput(TELDNHandle hTELDN, Str255 deviceName);

  /**
   *  TELDisposeDNSoundInput()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDisposeDNSoundInput(TELDNHandle hTELDN, ConstStr255Param deviceName);

  /**
   *  TELGetDNSoundOutput()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetDNSoundOutput(TELDNHandle hTELDN, Component *SndOut);

  /**
   *  TELDisposeDNSoundOutput()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDisposeDNSoundOutput(TELDNHandle hTELDN, Component SndOut);

  /**
   *  TELGetHSSoundInput()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetHSSoundInput(TELHandle termHand, Str255 deviceName);

  /**
   *  TELDisposeHSSoundInput()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDisposeHSSoundInput(TELHandle termHand, ConstStr255Param deviceName);

  /**
   *  TELGetHSSoundOutput()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetHSSoundOutput(TELHandle termHand, Component *SndOut);

  /**
   *  TELDisposeHSSoundOutput()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDisposeHSSoundOutput(TELHandle termHand, Component SndOut);

  /**
   *  TELDNSetAutoAnswer()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDNSetAutoAnswer(TELDNHandle hTELDN, Boolean AutoAnswerOn);

  /**
   *  TELDNTollSaverControl()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDNTollSaverControl(TELDNHandle hTELDN, Boolean QuickAnswer);

  /**
   *  TELSetIndHSConnect()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELSetIndHSConnect(TELHandle termHand, Boolean Connect);

  /**
   *  TELGetIndHSConnect()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetIndHSConnect(TELHandle termHand, Boolean *Connect);

  /**
   *  TELCAVoiceDetect()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCAVoiceDetect(TELCAHandle hTELCA, Boolean VoiceDetectOn);

  /**
   *  TELCASilenceDetect()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELCASilenceDetect(TELCAHandle hTELCA, Boolean DetectOn, long Period);

  /**
   *  TELGetTelNewErr()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetTelNewErr(void);

  /**
   *  TELDNSetDTMF()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDNSetDTMF(TELDNHandle hTELDN, Boolean dtmfOn);

  /**
   *  TELDNGetDTMF()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELDNGetDTMF(TELDNHandle hTELDN, Boolean *dtmfOn);

  /**
   *  TELHSSetDTMF()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELHSSetDTMF(TELHandle termHand, Boolean dtmfOn);

  /**
   *  TELHSGetDTMF()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELHSGetDTMF(TELHandle termHand, Boolean *dtmfOn);

  /**
   *  TELGetDNStatus()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetDNStatus(TELDNHandle hTELDN, long *inUse);

  /**
   *  TELGetDNProgressDet()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELGetDNProgressDet(TELDNHandle hTELDN, long selector, Boolean *prgDetOn);

  /**
   *  TELSetDNProgressDet()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TELErr
  TELSetDNProgressDet(TELDNHandle hTELDN, long selector, Boolean prgDetOn);

#endif // CALL_NOT_IN_CARBON 
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

#endif // __TELEPHONES__ // CALL_NOT_IN_CARBON 
// __TELEPHONES__ 
