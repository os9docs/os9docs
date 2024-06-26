/**
     \file       CMAcceleration.h

    \brief   ColorSync Acceleration Component API

    \introduced_in  ColorSync 2.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1995-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup ColorSync

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CMACCELERATION__
#define __CMACCELERATION__

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __CMAPPLICATION__
#include <CMApplication.h>
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

  /** ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©© version info */
  enum
  {
    cmAccelerationInterfaceVersion = 1
  };

  /** ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©© Component Type */
  enum
  {
    cmAccelerationComponentType = FOUR_CHAR_CODE('csac')
  };

  /** ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©© Required Component function selectors
   */
  enum
  {
    cmLoadTables = 0,
    cmCalculateData = 1
  };

  /** ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©© table data for acceleration component
   */
  struct CMAccelerationTableData
  {
    long
        inputLutEntryCount;              /** count of entries for input lut for one dimension*/
    long inputLutWordSize;               /** count of bits of each entry ( e.g. 16 for WORD )*/
    Handle inputLut;                     /** handle to input lut*/
    long outputLutEntryCount;            /** count of entries for output lut for one
                                            dimension  */
    long outputLutWordSize;              /** count of bits of each entry ( e.g. 8 for BYTE )*/
    Handle outputLut;                    /** handle to output lut*/
    long colorLutInDim;                  /** input dimension  ( e.g. 3 for LAB ; 4 for CMYK )*/
    long colorLutOutDim;                 /** output dimension ( e.g. 3 for LAB ; 4 for CMYK )*/
    long colorLutGridPoints;             /** count of gridpoints for color lut ( for one
                                            Dimension )    */
    long colorLutWordSize;               /** count of bits of each entry ( e.g. 8 for BYTE )*/
    Handle colorLut;                     /** handle to color lut*/
    CMBitmapColorSpace inputColorSpace;  /** packing info for input*/
    CMBitmapColorSpace outputColorSpace; /** packing info for output*/
    void *userData;
    unsigned long reserved1;
    unsigned long reserved2;
    unsigned long reserved3;
    unsigned long reserved4;
    unsigned long reserved5;
  };
  typedef struct CMAccelerationTableData CMAccelerationTableData;
  typedef CMAccelerationTableData *CMAccelerationTableDataPtr;
  typedef CMAccelerationTableDataPtr *CMAccelerationTableDataHdl;
  /** ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©© calc data for acceleration component
   */
  struct CMAccelerationCalcData
  {
    long pixelCount; /** count of input pixels*/
    Ptr inputData;   /** input array*/
    Ptr outputData;  /** output array*/
    unsigned long reserved1;
    unsigned long reserved2;
  };
  typedef struct CMAccelerationCalcData CMAccelerationCalcData;
  typedef CMAccelerationCalcData *CMAccelerationCalcDataPtr;
  typedef CMAccelerationCalcDataPtr *CMAccelerationCalcDataHdl;
/**
   ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
                A c c e l e r a t i o n   C o m p o n e n t   I n t e r f a c e
   s
   ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
*/
#if CALL_NOT_IN_CARBON
  /**
   *  CMAccelerationLoadTables()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  CMError
  CMAccelerationLoadTables(ComponentInstance CMSession,
                           CMAccelerationTableDataPtr tableData);

  /**
   *  CMAccelerationCalculateData()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  CMError
  CMAccelerationCalculateData(ComponentInstance CMSession,
                              CMAccelerationCalcDataPtr calcData);

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

#endif /** __CMACCELERATION__ */
