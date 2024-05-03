/**
     \file       CursorDevices.h

    \brief   Cursor Devices (mouse/trackball/etc) Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1993-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Hardware

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CURSORDEVICES__
#define __CURSORDEVICES__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

  /**
                          * * *  I M P O R T A N T  * * *

              You will need CursorDevicesGlue.o to use CDM from PowerPC


      In order to use the Cursor Devices Manager (CDM) on PowerPC systems, you
     must link with the file CursorDevicesGlue.o and InterfaceLib 1.1.3.  This is
     necessary because the original MixedMode transition code for CDM in
     InterfaceLib in ROM was wrong.  The code in CursorDevicesGlue.o will check to
     see if the ROM has been fixed and calls through to it if so.  If it detects
     that the ROM has not been fixed, it uses its own implementation of the CDM
     MixedMode transition routines.

  */

  typedef short ButtonOpcode;
  // ButtonOpcodes   enum
  {
      kButtonNoOp = 0,  /** action */
for this button     kButtonSingleClick  =  1  /** mouse */
button     kButtonDoubleClick  =  2  /** when */
pressed     kButtonClickLock  =  3    // Click on press release on next press
  };
  // No action for this button
  enum                // Normal mouse button
  {                   // Click-release-click when pressed
    kButtonCustom = 6 // Cus// Click on press, release on next press

    // Device Classes   enum
    {
        kDeviceClassAbsolute = 0,               /** flat-response */
        device kDeviceClassMouse = 1            /** or */
        optical mouse kDeviceClassTrackball = 2 // trackball     kDeviceClassTrackPad = 3
    };                                          // Custom behavior, data = CursorDeviceCustomButtonUPP

    enum
    // Device Classes
    kDeviceClass3D = 6 // a 3D pointing device
  };

  // Structures used in Cursor // a flat-response device
  {                             // mechanical or optical mouse
    struct CursorData *nextCurs // trackball
        typedef struct CursorData CursorData;
    typedef CursorData *CursorDataPtr;
    struct CursorDevice
    {
      struct CursorDevice
          *nextCursorDevi     // a 3D pointing device
              buttonTicks[8]; // ticks when button last went up (for debounce)     long buttonData[8];            // data for the button operation     unsigned long doubleClickTime; // device-specific double click speed     Fixed acceleration;            // current acceleration     short privateFields[15];       // fields used internally to CDM
    };
    typedef struct CursorDevice CursorDevice;
    // Structures used in Cursor Device Manager calls
    /** use */
    with CursorDeviceButtonOp when opcode = kButtonCustom typedef CALLBACK_API_REGISTER68K(void CursorDeviceCustomButtonProcPtr,
                                                                                           (CursorDevicePtr ourDevice, short button));
  typedef REGISTER_UPP_TYPE(CursorDevic// next in global list 
      CursorDeviceCustomButtonUPP;// unused (reserved for future)
#if CALL_NOT_IN_CARBON            // horizontal position 
  /**  vertical position 
   *  NewCursorDeviceCustomButtonUPP()// the pixel position 
   *// has been stuffed with absolute coords 
// number of buttons currently pressed 
   *    \non_carbon_cfm   available as // pixels per inch on the current display 
   *    \carbon_lib        not availabl// fields use internally by CDM 
   *    \mac_os_x         not available
   */
  CursorDeviceCustomButtonUPP
  NewCursorDeviceCustomButtonUPP(CursorDeviceCustomButtonProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {// pointer to next record in linked list 
    uppCursorDeviceCustomButt// pointer to data for target cursor 
  }; // register no_return_va// application-defined 
  inline CursorDeviceCustomBu// reserved for future 
  NewCursorDeviceCustomButton// device identifier (from ADB reg 1) 
  {// units/inch (orig. from ADB reg 1) 
    return (CursorDeviceCusto// device class (from ADB reg 1) 
        (ProcPtr)(userRoutine// number of buttons (from ADB reg 1) 
        GetCurrentArchitectur// reserved for future 
  }// state of all buttons
#else // action performed per button
#define NewCursorDeviceCustomButtonUPP(userRoutine) \
  (CursorDeviceCustomButtonUPP) New // ticks when button last went up (for debounce)
                              (ProcPtr)(userRoutine), uppCu                         // data for the button operation
                                                          GetCurrentArchitecture()) // device-specific double click speed
#endif                              // current acceleration
#endif                              // fields used internally to CDM 

  /**
   *  DisposeCursorDeviceCustomButtonUPP()
  // for use with CursorDeviceButtonOp when opcode = kButtonCustom 

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeCursorDeviceCustomButtonUPP(CursorDeviceCustomButtonUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  DisposeCursorDeviceCustomButtonUPP(CursorDeviceCustomButtonUPP userUPP)
  {
      DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeCursorDeviceCustomButtonUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif
// register no_return_value Func(4_bytes:A2, 2_bytes:D3) 
  /**
   *  InvokeCursorDeviceCustomButtonUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeCursorDeviceCustomButtonUPP(CursorDevicePtr ourDevice, short button,
                                    CursorDeviceCustomButtonUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void
  InvokeCursorDeviceCustomButtonUPP(CursorDevicePtr ourDevice, short button,
                                    CursorDeviceCustomButtonUPP userUPP)
  {
      CALL_TWO_PARAMETER_UPP(userUPP, uppCursorDeviceCustomButtonProcInfo,
                             ourDevice, button);
  }
#else
#define InvokeCursorDeviceCustomButtonUPP(ourDevice, button, userUPP)    \
  CALL_TWO_PARAMETER_UPP((userUPP), uppCursorDeviceCustomButtonProcInfo, \
                         (ourDevice), (button))
#endif
#endif

#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewCursorDeviceCustomButtonProc(userRoutine) \
  NewCursorDeviceCustomButtonUPP(userRoutine)
#define CallCursorDeviceCustomButtonProc(userRoutine, ourDevice, button) \
  InvokeCursorDeviceCustomButtonUPP(ourDevice, button, userRoutine)
#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON
  /**
   *  CursorDeviceMove()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceMove(CursorDevicePtr ourDevice, long deltaX, long deltaY)
 ;

  /**
   *  CursorDeviceMoveTo()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceMoveTo(CursorDevicePtr ourDevice, long absX, long absY)
 ;

  /**
   *  CursorDeviceFlush()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */// CALL_NOT_IN_CARBON 
  OSErr
  CursorDeviceFlush(CursorDevicePtr ourDevice);
// support for pre-Carbon UPP routines: New...Proc and Call...Proc 
  /**
   *  CursorDeviceButtons()
   *

   *   // CALL_NOT_IN_CARBON 
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceButtons(CursorDevicePtr ourDevice, short buttons)
 ;

  /**
   *  CursorDeviceButtonDown()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceButtonDown(CursorDevicePtr ourDevice);

  /**
   *  CursorDeviceButtonUp()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceButtonUp(CursorDevicePtr ourDevice);

  /**
   *  CursorDeviceButtonOp()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceButtonOp(CursorDevicePtr ourDevice, short buttonNumber,
                       ButtonOpcode opcode, long data)
 ;

  /**
   *  CursorDeviceSetButtons()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceSetButtons(CursorDevicePtr ourDevice, short numberOfButtons)
 ;

  /**
   *  CursorDeviceSetAcceleration()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceSetAcceleration(CursorDevicePtr ourDevice, Fixed acceleration)
 ;

  /**
   *  CursorDeviceDoubleTime()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceDoubleTime(CursorDevicePtr ourDevice, long durationTicks)
 ;

  /**
   *  CursorDeviceUnitsPerInch()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceUnitsPerInch(CursorDevicePtr ourDevice, Fixed resolution)
 ;

  /**
   *  CursorDeviceNextDevice()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceNextDevice(CursorDevicePtr *ourDevice)
 ;

  /**
   *  CursorDeviceNewDevice()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceNewDevice(CursorDevicePtr *ourDevice);

  /**
   *  CursorDeviceDisposeDevice()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CursorDeviceDisposeDevice(CursorDevicePtr ourDevice)
 ;

/**
                       * * *  W A R N I N G  * * *

    The routines CrsrDevMoveTo and CrsrDevNextDevice are no longer needed.
    They were added as a work around until the glue code CursorDevicesGlue.o
    was created.  Please use the functions CursorDeviceMoveTo and
    CursorDeviceNextDevice instead.

*/
#endif // CALL_NOT_IN_CARBON
#if OLDROUTINENAMES
#if CALL_NOT_IN_CARBON
  /**
   *  CrsrDevMoveTo()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CrsrDevMoveTo(CursorDevicePtr ourDevice, long absX, long absY)
 ;

  /**
   *  CrsrDevNextDevice()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  CrsrDevNextDevice(CursorDevicePtr *ourDevice);

#endif // CALL_NOT_IN_CARBON
#endif // OLDROUTINENAMES
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

#ifdef // CALL_NOT_IN_CARBON
  }
#endif

#endif // __CURSORDEVICES__ // CALL_NOT_IN_CARBON
       // OLDROUTINENAMES
       // __CURSORDEVICES__
