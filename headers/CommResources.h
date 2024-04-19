/**
     \file       CommResources.h

    \brief   Communications Toolbox Resource Manager Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1988-2001 by Apple Computer, Inc., all rights reserved

    \ingroup CommunicationsToolbox
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __COMMRESOURCES__
#define __COMMRESOURCES__

#ifndef __OSUTILS__
#include <OSUtils.h>
#endif

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
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

#if CALL_NOT_IN_CARBON
enum {
  /**    tool classes (also the tool file types)    */
  classCM = FOUR_CHAR_CODE('cbnd'),
  classFT = FOUR_CHAR_CODE('fbnd'),
  classTM = FOUR_CHAR_CODE('tbnd')
};

enum {
  /**    version of the Comm Resource Manager   */
  curCRMVersion = 2, /** constants general to the use of the Communications
                        Resource Manager */
  crmType = 9,       /** queue type */
  crmRecVersion = 1, /** version of queue structure */
                     /**    error codes */
  crmGenericError = -1,
  crmNoErr = 0
};

/** data structures general to the use of the Communications Resource Manager */
typedef OSErr CRMErr;
struct CRMRec {
  QElemPtr qLink;     /**reserved*/
  short qType;        /**queue type -- ORD(crmType) = 9*/
  short crmVersion;   /**version of queue element data structure*/
  long crmPrivate;    /**reserved*/
  short crmReserved;  /**reserved*/
  long crmDeviceType; /**type of device, assigned by DTS*/
  long crmDeviceID;   /**device ID; assigned when CRMInstall is called*/
  long crmAttributes; /**pointer to attribute block*/
  long crmStatus;     /**status variable - device specific*/
  long crmRefCon;     /**for device private use*/
};
typedef struct CRMRec CRMRec;
typedef CRMRec *CRMRecPtr;
#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  InitCRM()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CRMErr)
InitCRM(void);

/**
 *  CRMGetHeader()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(QHdrPtr)
CRMGetHeader(void);

/**
 *  CRMInstall()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
CRMInstall(CRMRecPtr crmReqPtr);

/**
 *  CRMRemove()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
CRMRemove(CRMRecPtr crmReqPtr);

/**
 *  CRMSearch()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CRMRecPtr)
CRMSearch(CRMRecPtr crmReqPtr);

/**
 *  CRMGetCRMVersion()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
CRMGetCRMVersion(void);

/**
 *  CRMGetResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Handle)
CRMGetResource(ResType theType, short theID);

/**
 *  CRMGet1Resource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Handle)
CRMGet1Resource(ResType theType, short theID);

/**
 *  CRMGetIndResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Handle)
CRMGetIndResource(ResType theType, short index);

/**
 *  CRMGet1IndResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Handle)
CRMGet1IndResource(ResType theType, short index);

/**
 *  CRMGetNamedResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Handle)
CRMGetNamedResource(ResType theType, ConstStr255Param name);

/**
 *  CRMGet1NamedResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Handle)
CRMGet1NamedResource(ResType theType, ConstStr255Param name);

/**
 *  CRMReleaseResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
CRMReleaseResource(Handle theHandle);

/**
 *  CRMGetToolResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Handle)
CRMGetToolResource(short procID, ResType theType, short theID);

/**
 *  CRMGetToolNamedResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Handle)
CRMGetToolNamedResource(short procID, ResType theType, ConstStr255Param name);

/**
 *  CRMReleaseToolResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
CRMReleaseToolResource(short procID, Handle theHandle);

/**
 *  CRMGetIndex()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(long)
CRMGetIndex(Handle theHandle);

/**
 *  CRMLocalToRealID()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
CRMLocalToRealID(ResType bundleType, short toolID, ResType theType,
                 short localID);

/**
 *  CRMRealToLocalID()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
CRMRealToLocalID(ResType bundleType, short toolID, ResType theType,
                 short realID);

/**
 *  CRMGetIndToolName()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
CRMGetIndToolName(OSType bundleType, short index, Str255 toolName);

/**
 *  CRMFindCommunications()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
CRMFindCommunications(short *vRefNum, long *dirID);

/**
 *  CRMIsDriverOpen()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Boolean)
CRMIsDriverOpen(ConstStr255Param driverName);

/**
 *  CRMParseCAPSResource()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CRMErr)
CRMParseCAPSResource(Handle theHandle, ResType selector, unsigned long *value);

/**
 *  CRMReserveRF()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
CRMReserveRF(short refNum);

/**
 *  CRMReleaseRF()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
CRMReleaseRF(short refNum);

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

#endif /** __COMMRESOURCES__ */
