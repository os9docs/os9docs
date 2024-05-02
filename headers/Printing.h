/**
	 \file       Printing.h

	\brief   Print Manager Interfaces.

	\introduced_in  System 7.5
	\avaliable_from Universal Interfaces 3.4.1

	\copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

	\ingroup Hardware

	For bug reports, consult the following page on
				 the World Wide Web:

					 http://developer.apple.com/bugreporter/

*/
#ifndef __PRINTING__
#define __PRINTING__

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
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
		kFirstPageMin = 1,	 /** min value for first page */
		kLastPageMax = 32767 /** max value for last page */
	};

	enum
	{
		iPFMaxPgs = 128,
		iPrPgFract =
			120,	  /**Page scale factor. ptPgSize (below) is in units of 1/iPrPgFract*/
		iPrPgFst = 1, /**Page range constants*/
		iPrPgMax = 9999,
		iPrRelease = 3, /**Current version number of the code.*/
		iPrSavPFil = -1,
		iPrAbort = 0x0080,
		iPrDevCtl = 7,		   /**The PrDevCtl Proc's ctl number*/
		lPrReset = 0x00010000, /**The PrDevCtl Proc's CParam for reset*/
		lPrLineFeed = 0x00030000,
		lPrLFStd = 0x0003FFFF, /**The PrDevCtl Proc's CParam for std paper advance*/
		lPrLFSixth = 0x0003FFFF,
		lPrPageEnd = 0x00020000, /**The PrDevCtl Proc's CParam for end page*/
		lPrDocOpen = 0x00010000,
		lPrPageOpen = 0x00040000,
		lPrPageClose = 0x00020000,
		lPrDocClose = 0x00050000,
		iFMgrCtl = 8, /**The FMgr's Tail-hook Proc's ctl number*/
		iMscCtl = 9,  /**The FMgr's Tail-hook Proc's ctl number*/
		iPvtCtl = 10  /**The FMgr's Tail-hook Proc's ctl number*/
	};

#define sPrDrvr ".Print"
	/**  Error Codes moved to Errors.(hap) */
	enum
	{
		pPrGlobals = 0x00000944, /**The PrVars lo mem area:*/
		bDraftLoop = 0,
		bSpoolLoop = 1,
		bUser1Loop = 2,
		bUser2Loop = 3,
		fNewRunBit = 2,
		fHiResOK = 3,
		fWeOpenedRF = 4, /**Driver constants */
		iPrBitsCtl = 4,
		lScreenBits = 0,
		lPaintBits = 1,
		lHiScreenBits = 0x00000002, /**The Bitmap Print Proc's Screen Bitmap param*/
		lHiPaintBits = 0x00000003,	/**The Bitmap Print Proc's Paint [sq pix] param*/
		iPrIOCtl = 5,
		iPrEvtCtl = 6,			/**The PrEvent Proc's ctl number*/
		lPrEvtAll = 0x0002FFFD, /**The PrEvent Proc's CParam for the entire screen*/
		lPrEvtTop = 0x0001FFFD, /**The PrEvent Proc's CParam for the top folder*/
		iPrDrvrRef = -3
	};

	enum
	{
		getRslDataOp = 4,
		setRslOp = 5,
		draftBitsOp = 6,
		noDraftBitsOp = 7,
		getRotnOp = 8,
		NoSuchRsl = 1,
		OpNotImpl = 2, /**the driver doesn't support this opcode*/
		RgType1 = 1
	};

	typedef SInt8 TFeed;
	enum
	{
		feedCut = 0,
		feedFanfold = 1,
		feedMechCut = 2,
		feedOther = 3
	};

	typedef SInt8 TScan;
	enum
	{
		scanTB = 0,
		scanBT = 1,
		scanLR = 2,
		scanRL = 3
	};

	/** A Rect Ptr */
	typedef Rect *TPRect;
	typedef CALLBACK_API(void, PrIdleProcPtr)(void);
	typedef CALLBACK_API(void, PItemProcPtr)(DialogRef theDialog, short item);
	typedef STACK_UPP_TYPE(PrIdleProcPtr) PrIdleUPP;
	typedef STACK_UPP_TYPE(PItemProcPtr) PItemUPP;
#if CALL_NOT_IN_CARBON
	/**
	 *  NewPrIdleUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	PrIdleUPP
	NewPrIdleUPP(PrIdleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppPrIdleProcInfo = 0x00000000
	}; /** pascal no_return_value Func() */
#ifdef __cplusplus
	inline PrIdleUPP NewPrIdleUPP(PrIdleProcPtr userRoutine)
	{
		return (PrIdleUPP)NewRoutineDescriptor(
			(ProcPtr)(userRoutine), uppPrIdleProcInfo, GetCurrentArchitecture());
	}
#else
#define NewPrIdleUPP(userRoutine)                                               \
	(PrIdleUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppPrIdleProcInfo, \
									 GetCurrentArchitecture())
#endif
#endif

	/**
	 *  NewPItemUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	PItemUPP
	NewPItemUPP(PItemProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppPItemProcInfo = 0x000002C0
	}; /** pascal no_return_value Func(4_bytes, 2_bytes) */
#ifdef __cplusplus
	inline PItemUPP NewPItemUPP(PItemProcPtr userRoutine)
	{
		return (PItemUPP)NewRoutineDescriptor(
			(ProcPtr)(userRoutine), uppPItemProcInfo, GetCurrentArchitecture());
	}
#else
#define NewPItemUPP(userRoutine)                                              \
	(PItemUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppPItemProcInfo, \
									GetCurrentArchitecture())
#endif
#endif

	/**
	 *  DisposePrIdleUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposePrIdleUPP(PrIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposePrIdleUPP(PrIdleUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposePrIdleUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  DisposePItemUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposePItemUPP(PItemUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposePItemUPP(PItemUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposePItemUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  InvokePrIdleUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	InvokePrIdleUPP(PrIdleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void InvokePrIdleUPP(PrIdleUPP userUPP)
	{
		CALL_ZERO_PARAMETER_UPP(userUPP, uppPrIdleProcInfo);
	}
#else
#define InvokePrIdleUPP(userUPP) \
	CALL_ZERO_PARAMETER_UPP((userUPP), uppPrIdleProcInfo)
#endif
#endif

	/**
	 *  InvokePItemUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	InvokePItemUPP(DialogRef theDialog, short item, PItemUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void InvokePItemUPP(DialogRef theDialog, short item, PItemUPP userUPP)
	{
		CALL_TWO_PARAMETER_UPP(userUPP, uppPItemProcInfo, theDialog, item);
	}
#else
#define InvokePItemUPP(theDialog, item, userUPP) \
	CALL_TWO_PARAMETER_UPP((userUPP), uppPItemProcInfo, (theDialog), (item))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewPrIdleProc(userRoutine) NewPrIdleUPP(userRoutine)
#define NewPItemProc(userRoutine) NewPItemUPP(userRoutine)
#define CallPrIdleProc(userRoutine) InvokePrIdleUPP(userRoutine)
#define CallPItemProc(userRoutine, theDialog, item) \
	InvokePItemUPP(theDialog, item, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

#if !OPAQUE_TOOLBOX_STRUCTS
	/**
	<pre>
	 * \note <pre>TPrPort is a sort of "Printer Port Peek" structure. As with a
	WindowRecord , its first 108 bytes contain the fields of a GrafPort into
	which all drawing will occur.
	This structure is used internally by the Printing Manager. A pointer to a
	TPrPort is obtained via PrOpenDoc , and a is used directly in calls to
	PrCloseDoc PrOpenDoc PrPicFile
	PrClosePage PrOpenPage
	Subfields of the gProcs field can be modified to provide custom routines for
	text-measuring, line-drawing, etc.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TPrPort
	{
		GrafPort gPort;	  /**<  portBits, portRect , pnSize, txFont,*/
		QDProcs gProcs;	  /**<  Specialized printer drawing hooks*/
		long lGParam;	  /**<  Private storage ...*/
		long lGParam;	  /**<  ... for the driver*/
		long lGParam;	  /**< */
		long lGParam;	  /**< */
		Boolean fOurPtr;  /**<  Was this port allocated by the*/
		Boolean fOurBits; /**<  Was the bit map allocated by the*/
	} TPrPort;			  /**< */

	typedef struct TPrPort TPrPort;
	typedef TPrPort *TPPrPort;
#else
typedef struct OpaqueTPPrPort *TPPrPort;
#endif /** !OPAQUE_TOOLBOX_STRUCTS */

	typedef TPPrPort TPPrPortRef;
	/** Printing Graf Port. All printer imaging, whether spooling, banding, etc,
	  happens "thru" a GrafPort. This is the "PrPeek" record. */
	/**
	<pre>
	 * \note <pre>TPrInfo defines the printer information subfield of the TPrint structure
	(ie TPrint.prInfo). Its fields are set according to selections made in the
	print dialogs.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TPrInfo
	{
		short iDev;	 /**< Device code used by Font Mgr and Quickdraw*/
		short iVRes; /**< Vert resolution of device (dots per inch)*/
		short iHRes; /**< Horizontal resolution of device (dpi)*/
		Rect rPage;	 /**< Printable page size ( top and left are usually*/
		;			 /**<  physical paper size is in TPrint.rPaper)*/
	} TPrInfo;		 /**< */

	typedef struct TPrInfo TPrInfo;
	typedef TPrInfo *TPPrInfo;
	/** Print Info Record: The parameters needed for page composition. */
	/**
	<pre>
	 * \note <pre>TPrStl gets set according to selections made in the print dialogs, especially
	the style dialog presented via PrStlDialog . It is not used directly in any
	Printing Manager functions, but it defines a subrecord of the TPrint
	structure (ie, TPrint.prStl) which is used in many Printing Manager calls.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TPrStl
	{
		short wDev;			/**<  Device number.  Hi byte is refNum*/
		short iPageV;		/**<  Paper height in /th-inch units*/
		short iPageH;		/**<  Paper width*/
		char bPort;			/**<  I/O port number*/
		unsigned char feed; /**<  Type of paper feed:*/
	} TPrStl;				/**< */

	typedef struct TPrStl TPrStl;
	typedef TPrStl *TPPrStl;
	/**
	<pre>
	 * \note <pre>TPrXInfo defines a subrecord of the TPrint structure (ie, TPrint.prXInfo)
	which is used in many Printing Manager calls. The fields of this structure
	are set according to the type of printer being used and the style of the
	output.
	If you decide to allocate your own device buffer when you call PrPicFile ,
	that buffer must be at least TPrXInfo.iDevBytes large.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TPrXInfo
	{
		short iRowBytes;	  /**<  rowBytes (as in a bitMap) for a band*/
		short iBandV;		  /**<  Height of a band, in printer dots*/
		short iBandH;		  /**<  Width of a band*/
		short iDevBytes;	  /**<  Size of buffer needed by PrPicFile*/
		short iBands;		  /**<  Number of bands per page*/
		SignedByte bPatScale; /**<  Pattern scaling factor*/
		SignedByte bUlThick;  /**<  Underlining parameters*/
		SignedByte bUlOffset; /**< */
		SignedByte bUlShadow; /**< */
		SignedByte scan;	  /**<  Band-scanning direction code:*/
		SignedByte XInfoX;	  /**<  (not used)*/
	} TPrXInfo;				  /**< */

	typedef struct TPrXInfo TPrXInfo;
	typedef TPrXInfo *TPPrXInfo;
	/**
	<pre>
	 * \note <pre>TPrJob gets set according to selections made in the print dialogs,
	especially the job dialog presented via PrJobDialog . It is not used
	directly in any Printing Manager functions, but it defines a subrecord of the
	TPrint structure (ie, TPrint.prJob) which is used in many Printing
	Manager calls.
	The iFstPage and iLstPage fields define the range of pages which will be
	printed. Calls to PrOpenPage are counted as they are made (starting from
	1) and if the current page number falls in this range, it is printed.
	Otherwise, the page is not output. To avoid time-consuming drawing of
	pages which will be skipped, you will want to set this range yourself. See
	PrOpenPage .
	It is important to check the bJDocLoop flag after you close a document. If it
	has been set to 1, then the print job has been spooled and you must call
	PrPicFile to actually output the print image (see PrOpenDoc for an
	example).
	Background Processing
	If you leave pIdle procedure as 0, then the default background task will
	check for the press of -. (Cmd-period) and abort the printing if that
	occurs.
	You might want to provide a user-friendly dialog window with some sort of
	Cancel button. Another common enhancement is to display some sort of
	status as to which page is being printed, etc.
	To do so, you must draw the dialog before starting to print. As the last step
	before printing the first page, store the address of your background routine
	into pIdleProc (note this gets set back to 0 by PrValidate , PrOpenDoc ,
	PrStlDialog , and PrJobDialog ). Your routine should be declared as:
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TPrJob
	{
		short iFstPage;			 /**< Page number of first page to print*/
		short iLstPage;			 /**< Last page to print*/
		short iCopies;			 /**< Number of copies to print*/
		char bJDocLoop;			 /**< Print method;/**< =draft, =spooled*/
		Boolean fFromUsr;		 /**< (used internally)*/
		PrIdleProcPtr pIdleProc; /**< Address of background routine;/**< =use*/
		StringPtr pFileName;	 /**< Addr of spool filename;/**< =default "\pPrint*/
		short iFileVol;			 /**< Spool volume reference number*/
		char bFileVers;			 /**< Spool file version number (use  here)*/
		char bJobX;				 /**< (not used)*/
	} TPrJob;					 /**< */

	typedef struct TPrJob TPrJob;
	typedef TPrJob *TPPrJob;
	/** Print Job: Print "form" for a single print request. */
	struct TPrint
	{
		short iPrVersion; /**(2) Printing software version*/
		TPrInfo prInfo;	  /**(14) the PrInfo data associated with the current style.*/
		Rect rPaper;	  /**(8) The paper rectangle [offset from rPage]*/
		TPrStl prStl;	  /**(8)  This print request's style.*/
		TPrInfo prInfoPT; /**(14)  Print Time Imaging metrics*/
		TPrXInfo prXInfo; /**(16)  Print-time (expanded) Print info record.*/
		TPrJob prJob;	  /**(20) The Print Job request (82)  Total of the above; 120-82 =
							 38 bytes needed to fill 120*/
		short printX[19]; /**Spare to fill to 120 bytes!*/
	};
	typedef struct TPrint TPrint;
	typedef TPrint *TPPrint;
	typedef TPPrint *THPrint;
	/**
	<pre>
	 * \note <pre>A pointer to a TPrStatus structure is used in calls to PrPicFile . If you
	employ a background procedure while printing a spooled file, you can
	examine this structure to inform the user of the printing progress. The
	structure will be updated as the printing progresses.
	See PrPicFile and TPrJob for related information.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TPrStatus
	{
		short iTotPages;  /**<  Total pages in spool file*/
		short iCurPage;	  /**<  Page currently being printed*/
		short iTotCopies; /**<  Total copies requested*/
		short iCurCopy;	  /**<  Current copy (-based)*/
		short iTotBands;  /**<  Total bands per page*/
		short iCurBand;	  /**<  Band currently being printed*/
		Boolean fPgDirty; /**<  TRUE if printing has started for this*/
		Boolean fImaging; /**<  TRUE while in banded DrawPicture*/
		THPrint hPrint;	  /**<  Leads to active print record. See*/
		TPPrPort pPrPort; /**<  Addr of active printer port.  See*/
		PicHandle hPic;	  /**<  Leads to active Picture structure*/
	} TPrStatus;		  /**< */

	typedef struct TPrStatus TPrStatus;
	typedef TPrStatus *TPPrStatus;
	typedef TPPrStatus TPPrStatusRef;

	/** Print Status: Print information during printing. */
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TPfPgDir
	{
		short iPages;  /**< */
		long iPgPos[]; /**< array [.. iPfMaxPgs ]*/
	} TPfPgDir;		   /**< */

	typedef struct TPfPgDir TPfPgDir;
	typedef TPfPgDir *TPPfPgDir;
	typedef TPPfPgDir *THPfPgDir;
/** PicFile = a TPfHeader followed by n QuickDraw Pics (whose PicSize is
 * invalid!) */
/** This is the Printing Dialog Record. Only used by folks appending their own
   DITLs to the print dialogs.  Print Dialog: The Dialog Stream object. */
#if !OPAQUE_TOOLBOX_STRUCTS
	/**
	<pre>
	 * \note <pre>A TPrDlg structure is used by applications which need to add items to the
	standard print dialogs. For instance, if you want the user to be able to
	renumber printed pages or to set the paper size in some reasonable manner,
	then you may want to modify the standard "Page Setup..." dialog which is
	used by PrStlDialog .
	The technique is rather complex and is explained in Apple Technical Note
	#95. It involves calling PrJobInit (or PrStlInit ) to obtain the address
	of an initialized TPrDlg structure. Then store the address of a custom
	routine into pItemProc (and possibly pFltrProc) and append your custom
	items to the dialog. Next call PrDlgMain , passing it the address of a
	custom dialog initialization procedure. For more detailed information, see
	Adding Items to the Print Dialogs .
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TPrDlg
	{
		DialogRecord dlg;  /**< Dialog info: window, items, editField, ...*/
		ProcPtr pFltrProc; /**< Addr of modal Dialog filter proc*/
		ProcPtr pItemProc; /**< Addr of item evaluation proc*/
		THPrint hPrintUsr; /**< Handle to user's print record.  See TPrint*/
		Boolean fDoIt;	   /**< (used internally)*/
		Boolean fDone;	   /**< (used internally)*/
		long lUser;		   /**< (reserved)*/
		long lUser;		   /**< (reserved)*/
		long lUser;		   /**< (reserved)*/
		long lUser;		   /**< (reserved)*/
	} TPrDlg;			   /**< +n*/

	typedef struct TPrDlg TPrDlg;
	typedef TPrDlg *TPPrDlg;
#else
typedef struct OpaqueTPPrDlg *TPPrDlg;
#endif /** !OPAQUE_TOOLBOX_STRUCTS */

	typedef TPPrDlg TPPrDlgRef;
	typedef CALLBACK_API(TPPrDlgRef, PDlgInitProcPtr)(THPrint hPrint);
	typedef STACK_UPP_TYPE(PDlgInitProcPtr) PDlgInitUPP;
#if CALL_NOT_IN_CARBON
	/**
	 *  NewPDlgInitUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	PDlgInitUPP
	NewPDlgInitUPP(PDlgInitProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum
	{
		uppPDlgInitProcInfo = 0x000000F0
	}; /** pascal 4_bytes Func(4_bytes) */
#ifdef __cplusplus
	inline PDlgInitUPP NewPDlgInitUPP(PDlgInitProcPtr userRoutine)
	{
		return (PDlgInitUPP)NewRoutineDescriptor(
			(ProcPtr)(userRoutine), uppPDlgInitProcInfo, GetCurrentArchitecture());
	}
#else
#define NewPDlgInitUPP(userRoutine)     \
	(PDlgInitUPP) NewRoutineDescriptor( \
		(ProcPtr)(userRoutine), uppPDlgInitProcInfo, GetCurrentArchitecture())
#endif
#endif

	/**
	 *  DisposePDlgInitUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	DisposePDlgInitUPP(PDlgInitUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline void DisposePDlgInitUPP(PDlgInitUPP userUPP)
	{
		DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
	}
#else
#define DisposePDlgInitUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

	/**
	 *  InvokePDlgInitUPP()
	 *

	 *    \non_carbon_cfm   available as macro/inline
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	TPPrDlgRef
	InvokePDlgInitUPP(THPrint hPrint, PDlgInitUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
	inline TPPrDlgRef InvokePDlgInitUPP(THPrint hPrint, PDlgInitUPP userUPP)
	{
		return (TPPrDlgRef)CALL_ONE_PARAMETER_UPP(userUPP, uppPDlgInitProcInfo,
												  hPrint);
	}
#else
#define InvokePDlgInitUPP(hPrint, userUPP) \
	(TPPrDlgRef) CALL_ONE_PARAMETER_UPP((userUPP), uppPDlgInitProcInfo, (hPrint))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewPDlgInitProc(userRoutine) NewPDlgInitUPP(userRoutine)
#define CallPDlgInitProc(userRoutine, hPrint) \
	InvokePDlgInitUPP(hPrint, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

	/**
	<pre>
	 * \note <pre>TGnlData defines a record used in PrGeneral calls. The fields of this
	structure are set according to the type of printer being used and the style
	and resolution of the output.
	The first field specifies an opcode that serves as a routine selector for
	subsidiary data blocks and can be:
	iOpCode (4) GetRsl (TGetRslBlk )
	iOpCode (5) SetRsl (TSetRslBlk )
	iOpCode (6) DraftBits ( TDftBitsBlk )
	iOpCode (7) NoDraftBits ( TDftBitsBlk )
	iOpCode (8) GetRotn ( TGetRotnBlk )
	When either opcode 4 or opcode 5 occupies the first field of the TGnlData
	record you are letting the application know what resolutions the printer
	supports -- and then specifying the desired resolution. Opcodes 6 and 7
	tell you whether or not you can print bitmaps in draft mode on the
	ImageWriter. Opcode 8 informs the application that the page has been
	rotated to print sideways.
	The iError field only returns the result produced by the print code and
	only reflects conditions that occur during a PrGeneral call.
	 It will be one of:
	noErr(0) No error
	noSuchRsl (1) Specified resolution not available
	opNotImpl (2) Printer driver doesn't support this opcode
	After the four-byte reserved field, the rest of the data block will be filled
	in with one or another of the subsidiary data blocks specified by the opcode
	listed in the first field (iOpCode).
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TGnlData
	{
		short iOpCode;	/**< One of  possible subsidiary data*/
		short iError;	/**< =noErr;/**< =noSuchRsl;/**<*/
		long lReserved; /**< (not used )*/
	} TGnlData;			/**< +n*/

	typedef struct TGnlData TGnlData;
	/**
	<pre>
	 * \note <pre>The values specified by iMin and iMax show the range of resolutions
	achievable by a particular printer. There is a TRslRg given for each axis,
	oriented on the printer rather than the document--as when a document is
	set to print in a sideways or "landscape" mode.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TRslRg
	{
		short iMin; /**<  = discrete resolution printer*/
		short iMax; /**<  = discrete resolution printer*/
	} TRslRg;		/**< */

	typedef struct TRslRg TRslRg;
	/**
	<pre>
	 * \note <pre>The values specified by iXRsl and iYRsl show actual dot densities in the
	horizontal and vertical axes. Depending on the number of discrete
	resolutions the printer can achieve, there can be up to 27 records in an
	array of TRslRec (called a RgRslRec) for each printer.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TRslRec
	{
		short iXRsl; /**< Particular X resolution value*/
		short iYRsl; /**< Particular Y resolution value*/
	} TRslRec;		 /**< */

	typedef struct TRslRec TRslRec;
	/**
	<pre>
	 * \note <pre>TGetRslBlk defines a subsidiary record used by the TGnlData record in
	PrGeneral calls. The first 8 bytes are common for all PrGeneral calls
	and, in fact, constitute the TGnlData record.
	Once the application knows what resolutions the printer supports, it can
	then use SetRsl to pick among the various choices available, as specified in
	the array of resolution records rgRslRec.
	Laser printers, with their variable resolution, use the XRslRg and YRslRg
	fields (pointed to by TRslRg) to show the different minimum and maximum
	dot densities they can achieve in both the X and Y axes. Dot matrix printers,
	like the ImageWriter, are called discrete-resolution printers because only
	specific resolutions can be stipulated and return zeros in the X and Y
	resolution range fields.
	For resolution records (pointed to by TRslRec) a LaserWriter will show
	only one (300 x 300) while an ImageWriter will go ahead and give a
	resolution record for each of the discrete physical resolutions it can achieve
	(72 x 72; 144 x 144; 80 x 72; and 160 x 144)
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TGetRslBlk
	{
		short iOpCode;		/**<  = opcode for GetRslData*/
		short iError;		/**< =noErr;/**< =noSuchRsl;/**<*/
		long lReserved;		/**< (not used )*/
		short iRgType;		/**< Range type;/**< = ImageWriter,*/
		TRslRg XRslRg;		/**< Ptr to record of Min and Max X*/
		TRslRg YRslRg;		/**< Ptr to record of Min and Max Y*/
		short iRslRecCnt;	/**< Number of resolution records to*/
		TRslRec rgRslRec[]; /**< Array of printer's resolution*/
	} TGetRslBlk;			/**< */

	typedef struct TGetRslBlk TGetRslBlk;
	/**
	<pre>
	 * \note <pre>TSetRslBlk defines a subsidiary record used by the TGnlData record in
	PrGeneral calls. The first 8 bytes are common for all PrGeneral calls
	and, in fact, constitute the TGnlData record. HPrint is the handle to a
	TPrint structure that has already been passed by PrValidate . If the call
	succeeds, TPrint is updated with the resolution requested in iXRsl and
	iYRsl, a 0=noErr is returned. If the request can't be satisfied, an error
	code is returned (1=noSuchRsl) and the resolution fields take the values of
	the printer's default resolution
	(default = 0 x 0 ).
	Purposely specifying an invalid resolution can be used to undo the effect of
	a previous PrGeneral call since the effect will be to force the printer back
	to its default.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TSetRslBlk
	{
		short iOpCode;	/**<  = opcode for SetRsl*/
		short iError;	/**< =noErr;/**< =noSuchRsl;/**<*/
		long lReserved; /**< (not used )*/
		THPrint hPrint; /**< Handle  to a valid print record*/
		short iXRsl;	/**< Requested X-axis resolution*/
		short iYRsl;	/**< Requested Y-axis resolution*/
	} TSetRslBlk;		/**< */

	typedef struct TSetRslBlk TSetRslBlk;
	/**
	<pre>
	 * \note <pre>TDftBlk defines a subsidiary record used by the TGnlData record in
	PrGeneral calls. The first 8 bytes are common for all PrGeneral calls
	and, in fact, constitute the TGnlData record. It forces draft-mode printing
	and allows screen dumps through a call to CopyBits . DraftBits printing
	is immediate, thereby avoiding print spooling and producing faster results.
	While it is implemented on the LaserWriter, the call does nothing.
	LaserWriters are always in draft mode and always capable of printing
	screen dumps.
	HPrint is the handle to a TPrint structure that has already been passed by
	PrValidate .
	Although speedy and versatile, certain caveats apply when you use
	TDftBlk. For example, make this call before bringing up dialog boxes as
	it affects their appearance. Also, on the ImageWriter, it disables the
	Landscape icon in the Style dialog (Landscape format is not supported) and
	the Best, Faster and Draft buttons in the Job dialog.
	TDftBlk will do nothing if the printer doesn't have a draft mode, already
	prints screen dumps in draft mode, or doesn't print them at all.
	You can't use it to print anything but text and screen dumps and everything
	on the page has to be oriented along the Y-axis (meaning that you can't go
	back over an area, you can't have two objects next to each other, and the top
	of one object can't intrude into the bottom of the preceding object.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TDftBitsBlk
	{
		short iOpCode;	/**< = opcode for DraftBits*/
		short iError;	/**< =noErr;/**< =noSuchRsl;/**<*/
		long lReserved; /**< (not used )*/
		THPrint hPrint; /**< Handle  to a valid print record*/
	} TDftBitsBlk;		/**< */

	typedef struct TDftBitsBlk TDftBitsBlk;
	/**
	<pre>
	 * \note <pre>TGetRotnBlk defines a subsidiary record used by the TGnlData record in
	PrGeneral calls. The first 8 bytes are common for all PrGeneral calls
	and, in fact, constitute the TGnlData record. fLandscape is TRUE when the
	printer is set to produce a sideways-rotated page.
	HPrint is the handle to a TPrint structure that has already been passed by
	PrValidate .
	TGetRotnBlk will do nothing if the printer doesn't have a draft mode or if
	there was no preceding DraftBits call.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TGetRotnBlk
	{
		short iOpCode;		/**< = opcode for GetRotn*/
		short iError;		/**< =noErr;/**< =noSuchRsl;/**<*/
		long lReserved;		/**< (not used )*/
		THPrint hPrint;		/**< Handle  to a valid print record*/
		Boolean fLandscape; /**< Was landscape orientation selected?*/
		SignedByte bXtra;	/**< (not used)*/
	} TGetRotnBlk;			/**< */

	typedef struct TGetRotnBlk TGetRotnBlk;
#if CALL_NOT_IN_CARBON
	/**
	 *  PrPurge()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrPurge(void) FOURWORDINLINE(0x2F3C, 0xA800, 0x0000, 0xA8FD);

	/**
	 *  PrNoPurge()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrNoPurge(void) FOURWORDINLINE(0x2F3C, 0xB000, 0x0000, 0xA8FD);

	/**
	 *  PrOpen()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrOpen(void) FOURWORDINLINE(0x2F3C, 0xC800, 0x0000, 0xA8FD);

	/**
	 *  PrClose()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrClose(void) FOURWORDINLINE(0x2F3C, 0xD000, 0x0000, 0xA8FD);

	/**
	 *  PrintDefault()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrintDefault(THPrint hPrint) FOURWORDINLINE(0x2F3C, 0x2004, 0x0480, 0xA8FD);

	/**
	 *  PrValidate()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	Boolean
	PrValidate(THPrint hPrint) FOURWORDINLINE(0x2F3C, 0x5204, 0x0498, 0xA8FD);

	/**
	 *  PrStlDialog()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	Boolean
	PrStlDialog(THPrint hPrint) FOURWORDINLINE(0x2F3C, 0x2A04, 0x0484, 0xA8FD);

	/**
	 *  PrJobDialog()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	Boolean
	PrJobDialog(THPrint hPrint) FOURWORDINLINE(0x2F3C, 0x3204, 0x0488, 0xA8FD);

	/**
	\brief Obtain address of an initialized TPrDlg structure

	<pre>PrStlInit is called automatically by the Printing Manager when you call
PrStlDialog . Applications may call it as part of a complicated kludge to
modify the standard "Page Setup..." dialog. There is a detailed discussion of this
in Adding Items to the Print Dialogs .
hPrtRec is a handle leading to a 120-byte TPrint structure, as previously
prepared by a call to PrintDefault or PrValidate .
</pre>
* \returns <pre>the address of a TPrDlg structure. The structure includes a
DialogRecord and other fields previously initialized for a call to
ModalDialog .
</pre>
* \note <pre>This function is documented in Macintosh Technical Note #95, which
describes a technique for adding items to the standard "Print..." and "Page
Setup..." dialogs.
See PrDlgMain and TPrDlg for related information.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	TPPrDlgRef
	PrStlInit(THPrint hPrint) FOURWORDINLINE(0x2F3C, 0x3C04, 0x040C, 0xA8FD);

	/**
	\brief Obtain address of an initialized TPrDlg structure

	<pre>PrJobInit is called automatically by the Printing Manager when you call
PrJobDialog . Applications may call it as part of a complicated kludge to
modify the standard "Print..." dialog. See Adding Items to the Print Dialogs for
more information.
hPrtRec is a handle leading to a 120-byte TPrint structure, as previously
prepared by a call to PrintDefault or PrValidate .
</pre>
* \returns <pre>the address of a TPrDlg structure. The structure includes a
DialogRecord and other fields that have been initialized for a call to
ModalDialog .
</pre>
* \note <pre>This function is documented in Macintosh Technical Note #95, which
describes a technique with which you can add items to the standard "Print..."
and "Page Setup..." dialogs.
See PrDlgMain and TPrDlg for related information.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	TPPrDlgRef
	PrJobInit(THPrint hPrint) FOURWORDINLINE(0x2F3C, 0x4404, 0x0410, 0xA8FD);

	/**
	 *  PrJobMerge()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrJobMerge(THPrint hPrintSrc, THPrint hPrintDst)
		FOURWORDINLINE(0x2F3C, 0x5804, 0x089C, 0xA8FD);

	/**
	\brief Initialize for and execute a print dialog

	<pre>PrDlgMain is called automatically by PrJobDialog and PrStlDialog .
Applications may call it to modify the standard print dialogs.
hPrtRec is a handle leading to a 120-byte TPrint structure, as previously
prepared by a call to PrintDefault or PrValidate .
pDlgInit is the address of a special dialog initialization routine. When called
by the Print Manager (i.e., in the normal course of events), this
value is the address of the code handling PrJobInit or PrStlInit .
</pre>
* \returns <pre>a Boolean; it indicates whether the user has approved the contents of
hPrtRec as reflected in the dialog. It is one of:
FALSEThe user selected Cancel; no fields were changed.
TRUEThe user selected OK and the print record is valid.
</pre>
* \note <pre>PrDlgMain is documented in Technical Note #95, which describes a
technique with which you can add items to the standard "Print..." and "Page
Setup..." dialogs. See Adding Items to the Print Dialogs for more information.
PrDlgMain calls pDlgInit to setup a TPrDlg structure, then displays the
dialog obtained thereby and calls ModalDialog .
See PrJobInit , PrStlInit , and TPrDlg for related information
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
	Boolean
	PrDlgMain(THPrint hPrint, PDlgInitUPP pDlgInit)
		FOURWORDINLINE(0x2F3C, 0x4A04, 0x0894, 0xA8FD);

	/**
	 *  PrOpenDoc()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	TPPrPort
	PrOpenDoc(THPrint hPrint, TPPrPort pPrPort, /** can be NULL */
			  Ptr pIOBuf) FOURWORDINLINE(0x2F3C, 0x0400, 0x0C00, 0xA8FD);

	/**
	 *  PrCloseDoc()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrCloseDoc(TPPrPort pPrPort) FOURWORDINLINE(0x2F3C, 0x0800, 0x0484, 0xA8FD);

	/**
	 *  PrOpenPage()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrOpenPage(TPPrPort pPrPort, TPRect pPageFrame)
		FOURWORDINLINE(0x2F3C, 0x1000, 0x0808, 0xA8FD);

	/**
	 *  PrClosePage()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrClosePage(TPPrPort pPrPort) FOURWORDINLINE(0x2F3C, 0x1800, 0x040C, 0xA8FD);

	/**
	 *  PrPicFile()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrPicFile(THPrint hPrint, TPPrPort pPrPort, Ptr pIOBuf, Ptr pDevBuf,
			  TPPrStatus prStatus) FOURWORDINLINE(0x2F3C, 0x6005, 0x1480, 0xA8FD);

	/**
	 *  PrError()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	short
	PrError(void) FOURWORDINLINE(0x2F3C, 0xBA00, 0x0000, 0xA8FD);

	/**
	 *  PrSetError()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrSetError(short iErr) FOURWORDINLINE(0x2F3C, 0xC000, 0x0200, 0xA8FD);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
	/**
	 *  PrGeneral()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrGeneral(Ptr pData) FOURWORDINLINE(0x2F3C, 0x7007, 0x0480, 0xA8FD);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
	/**
	 *  PrDrvrOpen()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrDrvrOpen(void) FOURWORDINLINE(0x2F3C, 0x8000, 0x0000, 0xA8FD);

	/**
	 *  PrDrvrClose()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrDrvrClose(void) FOURWORDINLINE(0x2F3C, 0x8800, 0x0000, 0xA8FD);

	/**
	 *  PrCtlCall()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	void
	PrCtlCall(short iWhichCtl, long lParam1, long lParam2, long lParam3)
		FOURWORDINLINE(0x2F3C, 0xA000, 0x0E00, 0xA8FD);

	/**
	 *  PrDrvrDCE()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	Handle
	PrDrvrDCE(void) FOURWORDINLINE(0x2F3C, 0x9400, 0x0000, 0xA8FD);

	/**
	 *  PrDrvrVers()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	short
	PrDrvrVers(void) FOURWORDINLINE(0x2F3C, 0x9A00, 0x0000, 0xA8FD);

	/**
	 *  PrLoadDriver()
	 *

	 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
	 *    \carbon_lib        not available
	 *    \mac_os_x         not available
	 */
	short
	PrLoadDriver(void) FOURWORDINLINE(0x2F3C, 0xD800, 0x0000, 0xA8FD);

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

#endif /** __PRINTING__ */
*	   /*/*/