/**
     \file       DiskInit.h

    \brief   Disk Initialization Package ('PACK' 2) Interfaces.

    \introduced_in  System 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup AppleDisk

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DISKINIT__
#define __DISKINIT__

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

    /**
    <pre>
     * \note <pre>This structure contains options used by DIFormat when it formats a disk
    (see also DIBadMount ). The global variable FmtDefaults (at 0x39E)
    contains the address of a structure with this layout which is normally
    contained in ROM.
    If you wish to format a diskette using different defaults, you can allocate a
    24-byte non-relocatable block and fill it with the HFSDefaults field values
    and set FmtDefaults to point to your version of the structure. Then call
    DIFormat . To restore the normal values, just clear FmtDefaults .
    The nxFreeFN field sets the initial 'hard' file number used in identifying
    files and directories on the volume. This value will be stored in the volume
    information (ie, the ioVNxtFNum field in a VolumeParam or VCB
    structure) and is incremented each time a new file or directory is created.
    If you set the abSize and/or btClpSize fields to 0, their values will be
    automatically calculated based upon the volume size.
    </pre>
     * \copyright THINK Reference © 1991-1992 Symantec Corporation
    */
    struct HFSDefaults
    {
        char sigWord[]; /**< Signature ('BD' for HSF floppies)*/
        long abSize;    /**< Allocation block size in bytes ( or */
        long clpSize;   /**< Clump size in bytes*/
        long nxFreeFN;  /**< Next free file number (normally*/
        long btClpSize; /**< B* tree clump size in bytes(or  to*/
        short rsrv;     /**< (unused)*/
        short rsrv;     /**< (unused)*/

        typedef struct HFSDefaults HFSDefaults;
        enum
        {
            kHFSPlusDefaultsVersion = 1
        };

        struct HFSPlusDefaults
        {
            UInt16 version;             /** version of this structure */
            UInt16 flags;               /** currently undefined; pass zero */
            UInt32 blockSize;           /** allocation block size in bytes */
            UInt32 rsrcClumpSize;       /** clump size for resource forks */
            UInt32 dataClumpSize;       /** clump size for data forks */
            UInt32 nextFreeFileID;      /** next free file number */
            UInt32 catalogClumpSize;    /** clump size for catalog B-tree */
            UInt32 catalogNodeSize;     /** node size for catalog B-tree */
            UInt32 extentsClumpSize;    /** clump size for extents B-tree */
            UInt32 extentsNodeSize;     /** node size for extents B-tree */
            UInt32 attributesClumpSize; /** clump size for attributes B-tree */
            UInt32 attributesNodeSize;  /** node size for attributes B-tree */
            UInt32 allocationClumpSize; /** clump size for allocation bitmap file */
        };
        typedef struct HFSPlusDefaults HFSPlusDefaults;
#if CALL_NOT_IN_CARBON
        /**
         *  DILoad()
         *

         *    \non_carbon_cfm   in InterfaceLib 7.1 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        void
        DILoad(void) THREEWORDINLINE(0x7002, 0x3F00, 0xA9E9);

        /**
         *  DIUnload()
         *

         *    \non_carbon_cfm   in InterfaceLib 7.1 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        void
        DIUnload(void) THREEWORDINLINE(0x7004, 0x3F00, 0xA9E9);

        /**
         *  DIBadMount()
         *

         *    \non_carbon_cfm   in InterfaceLib 7.1 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        short
        DIBadMount(Point where, UInt32 evtMessage)
            THREEWORDINLINE(0x7000, 0x3F00, 0xA9E9);

        /**
         *  DIFormat()
         *

         *    \non_carbon_cfm   in InterfaceLib 7.1 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        OSErr
        DIFormat(short drvNum) THREEWORDINLINE(0x7006, 0x3F00, 0xA9E9);

        /**
         *  DIVerify()
         *

         *    \non_carbon_cfm   in InterfaceLib 7.1 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        OSErr
        DIVerify(short drvNum) THREEWORDINLINE(0x7008, 0x3F00, 0xA9E9);

        /**
         *  DIZero()
         *

         *    \non_carbon_cfm   in InterfaceLib 7.1 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        OSErr
        DIZero(short drvNum, ConstStr255Param volName)
            THREEWORDINLINE(0x700A, 0x3F00, 0xA9E9);

        /**
            DIXFormat, DIXZero, and DIReformat are only available when FSM (File System
           Manager) is installed. FSM is part of Macintosh PC Exchange and System 7.5.
        */
        /**
         *  DIXFormat()
         *

         *    \non_carbon_cfm   in InterfaceLib 8.5 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        OSErr
        DIXFormat(short drvNum, Boolean fmtFlag, unsigned long fmtArg,
                  unsigned long *actSize) THREEWORDINLINE(0x700C, 0x3F00, 0xA9E9);

        /**
         *  DIXZero()
         *

         *    \non_carbon_cfm   in InterfaceLib 8.5 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        OSErr
        DIXZero(short drvNum, ConstStr255Param volName, short fsid, short mediaStatus,
                short volTypeSelector, unsigned long volSize, void *extendedInfoPtr)
            THREEWORDINLINE(0x700E, 0x3F00, 0xA9E9);

        /**
         *  DIReformat()
         *

         *    \non_carbon_cfm   in InterfaceLib 8.5 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        OSErr
        DIReformat(short drvNum, short fsid, ConstStr255Param volName,
                   ConstStr255Param msgText) THREEWORDINLINE(0x7010, 0x3F00, 0xA9E9);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
        /**
         *  dibadmount()
         *

         *    \non_carbon_cfm   in InterfaceLib 7.1 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        OSErr
        dibadmount(Point *where, long evtMessage);

        /**
         *  dizero()
         *

         *    \non_carbon_cfm   in InterfaceLib 7.1 and later
         *    \carbon_lib        not available
         *    \mac_os_x         not available
         */
        OSErr
        dizero(short drvnum, const char *volName);

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

#endif /** __DISKINIT__ */
