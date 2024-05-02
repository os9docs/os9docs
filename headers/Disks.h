/**
	 \file       Disks.h

	\brief   Disk Driver Interfaces.

	\introduced_in  System 7.5
	\avaliable_from Universal Interfaces 3.4.1

	\copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

	\ingroup AppleDisk

	For bug reports, consult the following page on
				 the World Wide Web:

					 http://developer.apple.com/bugreporter/

*/
#ifndef __DISKS__
#define __DISKS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __OSUTILS__
#include <OSUtils.h>
#endif

#ifndef __FILES__
#include <Files.h>
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
		sony = 0,
		hard20 = 1
	};

	/* Disk Driver Status csCodes */
	enum
	{
		kReturnFormatList = 6, /* .Sony */
		kDriveStatus = 8,
		kMFMStatus = 10
	};

	/* Disk Driver Control csCodes */
	enum
	{
		kVerify = 5,
		kFormat = 6,
		kEject = 7,
		kSetTagBuffer = 8, /* .Sony */
		kTrackCache = 9,   /* .Sony */
		kDriveIcon = 21,
		kMediaIcon = 22,
		kDriveInfo = 23,
		kRawTrack = 18244 /* .Sony: �diagnostic� raw track dump */
	};

	/**
		Note:

		qLink is usually the first field in queues, but back in the MacPlus
		days, the DrvSts record needed to be expanded.  In order to do this without
		breaking disk drivers that already added stuff to the end, the fields
		where added to the beginning.  This was originally done in assembly language
		and the record was defined to start at a negative offset, so that the qLink
		field would end up at offset zero.  When the C and pascal interfaces where
		made, they could not support negative record offsets, so qLink was no longer
		the first field.  Universal Interfaces are auto generated and don't support
		negative offsets for any language, so DrvSts in Disks.a has qLinks at a
		none zero offset.  Assembly code which switches to Universal Interfaces will
		need to compensate for that.

	*/
	/**
	<pre>
	 * \note <pre>This structure is used in the Disk Driver's DriveStatus call to return
	information about the internal and external drives. The diskInPlace field is
	0 when there is no disk and a 1 or a 2 for internal and external drives,
	respectively. A value of -4 to -1 indicates that the disk was ejected in the
	last one-and-a-half seconds. The installed field is 1 if the drive is
	connected, -1 if not connected, and 0 if the drive might be connected. The
	value for the twoSideFmt field is valid only if diskInPlace equals 2. The
	count in diskErrs is incremented every time an error occurs internally
	within the Disk Driver.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct DrvSts
	{
		short track;			/**< Current track*/
		SignedByte writeProt;	/**<  Bit  is  if volume is locked*/
		SignedByte diskInPlace; /**< Disk in place*/
		SignedByte installed;	/**< Drive installed*/
		SignedByte sides;		/**< Bit  is  is the disk is single-sided*/
		QElemPtr qLink;			/**< Address of next queue element*/
		short qType;			/**< Reserved*/
		short dQDrive;			/**< Drive number*/
		short dQRefNum;			/**< Drive reference number*/
		short dQFSID;			/**< File system identifier*/
		SignedByte twoSideFmt;	/**< - if double-sided disk*/
		SignedByte needsFlush;	/**< Reserved*/
		short diskErrs;			/**< Error count*/
	} DrvSts;					/**< */

	typedef struct DrvSts DrvSts;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct DrvSts2
	{
		short track;			/**< Current track*/
		SignedByte writeProt;	/**<  Bit  is  if volume is locked*/
		SignedByte diskInPlace; /**< Disk in place*/
		SignedByte installed;	/**< Drive installed*/
		SignedByte sides;		/**< Bit  is  is the disk is single-sided*/
		QElemPtr qLink;			/**< Address of next queue element*/
		short qType;			/**< Reserved*/
		short dQDrive;			/**< Drive number*/
		short dQRefNum;			/**< Drive reference number*/
		short dQFSID;			/**< File system identifier*/
		short driveSize;		/**< */
		short driveS;			/**< */
		short driveType;		/**< */
		short driveManf;		/**< */
		short driveChar;		/**< */
		char driveMisc;			/**< */
	} DrvSts;					/**< */

	typedef struct DrvSts2 DrvSts2;
/* Macros to get a DrvSts pointer or a DrvSts2 pointer from a DrvQEl pointer. */
/* Note: If you use these macros, your source file must include stddef.h to get
 * offsetof */
#define GetDrvStsPtrFromDrvQElPtr(driveQElement) \
	((DrvSts *)((BytePtr)driveQElement - offsetof(DrvSts, qLink)))
#define GetDrvSts2PtrFromDrvQElPtr(driveQElement) \
	((DrvSts2 *)((BytePtr)driveQElement - offsetof(DrvSts2, qLink)))
	enum
	{
		kdqManualEjectBit = 5
	};

#if CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON
	/**
	 *  DiskEject()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	DiskEject(short drvNum);

	/**
	 *  SetTagBuffer()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	SetTagBuffer(void *buffPtr);

	/**
	 *  DriveStatus()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	OSErr
	DriveStatus(short drvNum, DrvSts *status);

#endif /* CALL_NOT_IN_CARBON */

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON

	/**
	\brief Add a drive to the drive queue

	<pre>AddDrive adds a drive to the drive queue.
drvrRefNum driver reference number
drvNum drive number being added
qElpointer to DrvQEl structure
</pre>
* \returns <pre>an operating system Error Code .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	void
	AddDrive(short drvrRefNum, short drvNum, DrvQElPtr qEl);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON

	/**
	\brief Obtain pointer to the drive queue header

	<pre>GetDrvQHdr returns the address of the header of the standard Operating
System queue used to maintain the linked-list of disk drive information
records. There is one DrvQEl entry for each physical drive attached to the Mac.
</pre>
* \returns <pre>a 32-bit QHdrPtr; the address of the 10-byte QHdr structure whose
qLink field points to the first DrvQEl structure in the queue.
</pre>
* \note <pre>C programmers may prefer to get this address from the global variable
DrvQHdr (at 0x0308).
You can use this function to obtain information about drives attached to the
system; it may be the only way to get this collection of information. If you
need to monkey with this queue, you can use Enqueue and Dequeue .
In addition to the information in the DrvQEl structure, there are four
bytes of additional data that precede each element. The following describes
these prefix bytes:
OffsetDescription
-4(bit 7 set) = disk is locked (write-protected)
-30 = no disk in drive
1 or 2 = disk is in drive
8 = non-ejectable disk
FCh...FFh = disk was ejected within last 1.5 seconds
48h = non-ejectable disk, but driver expects a call
-2(used internally during system startup)
-1(bit 7 clear) = drive supports only single-sided media
The following example reads the elements of the drive queue and displays
information about all drives attached to the system.
Example
#include < Files.h>
#include < OSUtils.h >
QHdrPtr qhp; /* address of a QHdr structure */
	DrvQEl *qep;
	Byte *bp; /* helps to decode prefix bytes */
	long totBlks;
	Boolean locked, oneSide, empty;
	qhp = GetDrvQHdr();			/* address of queue header */
	qep = (DrvQEl *)qhp->qHead; /* address of a queue element */
	printf("Drv# FileSys Blocks locked 1-sided empty\n");
	do
	{
		bp = (Byte *)qep;
		bp -= 4; /* point to structure prefix bytes */
		</ pre>
					* \copyright THINK Reference © 1991 - 1992 Symantec Corporation
															  *    \non_carbon_cfm in InterfaceLib 7.1 and
			later
					*    \carbon_lib not available *    \mac_os_x not available *
				/
				QHdrPtr
				GetDrvQHdr(void) THREEWORDINLINE(0x2EBC, 0x0000, 0x0308);

#endif /* CALL_NOT_IN_CARBON */

#endif /* CALL_NOT_IN_CARBON */

		/*��������������������������������������������������������������������������������������������������*/
		/* Obsolete definitions */
		/*��������������������������������������������������������������������������������������������������*/
		/* Status csCode previously defined in Devices.h/p/a.
		 * This is obsolete and the new name should be used instead.
		 */
		enum
		{
			drvStsCode = kDriveStatus /* status call code for drive status */
		};

		/* Control csCodes previously defined in Devices.h/p/a.
		 * These are obsolete and the new names should be used instead.
		 */
		enum
		{
			ejectCode = kEject,		   /* control call eject code */
			tgBuffCode = kSetTagBuffer /* set tag buffer code */
		};

		/* Control csCodes previously defined in DriverGestalt.h/p/a.
		 * These are obsolete and the new names should be used instead.
		 */
		enum
		{
			VerifyCmd = kVerify,
			FormatCmd = kFormat,
			EjectCmd = kEject
		};

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

#endif /* __DISKS__ */
	*/*/