/**
	 \file       IntlResources.h

	\brief   International Resource definitions.

	\introduced_in  System 7.5+
	\avaliable_from Universal Interfaces 3.4.1

	\copyright � 1983-2001 by Apple Computer, Inc., all rights reserved.

	\ingroup System

	For bug reports, consult the following page on
				 the World Wide Web:

					 http://developer.apple.com/bugreporter/

*/
#ifndef __INTLRESOURCES__
#define __INTLRESOURCES__

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
		// Bits in the itlcFlags byte   itlcShowIcon = 7,     // Show icon even if only one script
		itlcDualCaret = 6, // Use dual caret for mixed direction text
						   // Bits in the itlcSysFlags word   itlcSysDirection = 15 // System direction - left to right/right to left
	};					   // Bits in the itlcSysFlags word

	enum
	{
		// One more flag in the itlcFlags byte   itlcDisableKeyScriptSync =
		3 // Disable font and keyboard script synchrinozation
	};	  // One more flag in the itlcFlags byte

	enum
	{
		// We should define masks, too.   itlcDisableKeyScriptSyncMask =
		1 << itlcDisableKeyScriptSync /*Disable font and keyboard script
										 synchrinozation mask*/
	};								  // We should define masks, too.

	enum
	{
		tokLeftQuote = 1, // NumberParts.data[] enumerators    tokRightQuote = 2, /*  In general, these are NOT to be considered indices into
		the data[] array * /
			tokLeadPlacer = 3,
		tokLeader = 4,
		tokNonLeader = 5, // NumberParts.data[] enumerators
		tokZeroLead = 6,
		tokPercent = 7,
		tokPlusSign = 8,
		tokMinusSign = 9,
		tokThousands = 10,
		tokReserved = 11, // 11 is reserved field   tokSeparator = 12,
		tokEscape = 13,
		tokDecPoint = 14,
		tokEPlus = 15,
		tokEMinus = 16,
		tokMaxSymbols = 31		  // 11 is reserved field
		curNumberPartsVersion = 1 // current version of NumberParts record
	};

	enum
	{
		currSymLead = 16,
		currNegSym = 32,
		currTrailingZ = 64,
		currLeadingZ = 128
	};

	enum
	{
		mdy = 0,
		dmy = 1,
		ymd = 2,
		myd = 3,
		dym = 4,
		ydm = 5
	};

	typedef SInt8 DateOrders;
	enum
	{
		timeCycle24 = 0,   // time sequence 0:00 - 23:59
		timeCycleZero = 1, // time sequence 0:00-11:59, 0:00 - 11:59
		timeCycle12 = 255, // time sequence 12:00 - 11:59, 12:00 - 11:59
		zeroCycle = 1,	   // old name for timeCycleZero
		longDay = 0,	   // day of the month
		longWeek = 1,	   // day of the week
		longMonth = 2,	   // month of the year
		longYear = 3,	   // year
		supDay = 1,		   // suppress day of month
		supWeek = 2,	   // suppress day of week
		supMonth = 4,	   // suppress month
		supYear = 8,	   // suppress year
		dayLdingZ = 32,
		mntLdingZ = 64,
		century = 128,
		secLeadingZ = 32,
		minLeadingZ = 64,
		hrLeadingZ = 128
	};

	// moved OffsetTable back here from QuickdrawText struct OffPair {
	short offFirst;
	short offSecond;
};
typedef struct OffPair OffPair;
typedef OffPair OffsetTable[3];
// moved OffsetTable back here from QuickdrawText
<pre>
	* \note<pre> Use Intl0Rec in calls to IUGetIntl(0), IUSetIntl(..., 0, ...),
	</ pre>
			* \copyright THINK Reference © 1991 - 1992 Symantec Corporation
														  * /
													  struct Intl0Rec
{
	char decimalPt;			   /**< Decimal point character;/**< eg, '.'*/
	char thousSep;			   /**< Thousands separator;/**< eg, ',' (ASCII*/
	char listSep;			   /**< List separator*/
	char currSym;			   /**< Currency symbol (up to three*/
	char currSym;			   /**< */
	char currSym;			   /**< */
	unsigned char currFmt;	   /**< Currency format flags*/
	unsigned char dateOrder;   /**< Order of short dates:*/
	unsigned char shrtDateFmt; /**< Short format date options:*/
	unsigned char dateSep;	   /**< Short date separator;/**< eg,'/' or '-'*/
	unsigned char timeCycle;   /**< = hr, = hr,  uses :*/
	unsigned char timeFmt;	   /**< Time format options:*/
	char mornStr[];			   /**< Morning text;/**< eg, "AM\\"*/
	char eveStr[];			   /**< Evening text;/**< eg, "PM\\"*/
	char timeSep;			   /**< Time separator;/**< eg, ':' (ASCII xA)*/
	char timeSuff;			   /**< -hr time suffix characters ...*/
	char timeSuff;			   /**<    Example: "O'Clock"*/
	char timeSuff;			   /**< */
	char timeSuff;			   /**< */
	char timeSuff;			   /**< */
	char timeSuff;			   /**< */
	char timeSuff;			   /**< */
	char timeSuff;			   /**< */
	unsigned char metricSys;   /**< =not metric, = use metric*/
	short intlVers;			   /**< Version and country code*/
} IntlRec;					   /**< */

typedef struct Intl0Rec Intl0Rec;
typedef Intl0Rec *Intl0Ptr;
typedef Intl0Ptr *Intl0Hndl;
/**
<pre>
 * \note <pre>Use Intl1Rec in calls to IUGetIntl (1), IUSetIntl (...,1,...), and
IUDatePString .  Values in the current version of this structure are also
used internally by IUDateString .
The localRtn field is actually a variable-length piece of code which gets
executed when you call any of the International Utilities Package string
comparison routines (e.g., IUCompString ).
This structure echoes the contents of the 'INTL' resource whose ID is 1.
The Intl0Rec structure contains additional information used in formatting
time and date output in the International Utilities Package .
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct Intl1Rec
{
	char days[];			   /**< Seven p-strings: "\pSunday",*/
	char months[];			   /**< Twelve p-strings: "\pJanuary",...*/
	unsigned char suppressDay; /**< =use day name, =suppress;/**<*/
	unsigned char lngDateFmt;  /**< =dmy, =mdy;/**<  Otherwise :*/
	unsigned char dayleading;  /**< =leading  in day number*/
	unsigned char abbrLen;	   /**< Length for abbreviating names;/**< eg, */
	char st[];				   /**< Text separators ... before text*/
	char st[];				   /**<   ... between day name and day*/
	char st[];				   /**<   ... between day number and month*/
	char st[];				   /**<   ... between month and year*/
	char st[];				   /**<   ... after text*/
	short intlVers;			   /**< Version and country code*/
	short localRtn;			   /**< nStart of code for string comparison*/
} IntlRec;					   /**< +n*/

typedef struct Intl1Rec Intl1Rec;
typedef Intl1Rec *Intl1Ptr;
typedef Intl1Ptr *Intl1Hndl;
// fields for optional itl1 extension
struct Itl1ExtRec
{
	Intl1Rec base; // un-extended Intl1Rec
	short version;
	short format;
	short calendarCode;			  // calendar code for this itl1 resource
	long extraDaysTableOffset;	  // offset in itl1 to extra days table
	long extraDaysTableLength;	  // length of extra days table
	long extraMonthsTableOffset;  // offset in itl1 to extra months table
	long extraMonthsTableLength;  // length of extra months table
	long abbrevDaysTableOffset;	  // offset in itl1 to abbrev days table
	long abbrevDaysTableLength;	  // length of abbrev days table
	long abbrevMonthsTableOffset; // offset in itl1 to abbrev months table
	long abbrevMonthsTableLength; // length of abbrev months table
	long extraSepsTableOffset;	  // offset in itl1 to extra seps table
	long extraSepsTableLength;	  // length of extra seps table
	short tables[1];			  // now a flag for opt extension
};
typedef struct Itl1ExtRec Itl1ExtRec;
struct UntokenTable
{
	short len;
	short lastToken;
	short index[256]; // index table; last = lastToken
};
typedef struct UntokenTable UntokenTable;
typedef UntokenTable *UntokenTablePtr;
typedef UntokenTablePtr *UntokenTableHandle;
union WideChar
{
	char a[2]; // 0 is the high order character
	short b;
};
typedef union WideChar WideChar;
struct WideCharArr
{
	short size;
	WideChar data[10];
};
typedef struct WideCharArr WideCharArr;
struct NumberParts
{
	short version;
	WideChar data[31]; // index by [tokLeftQuote..tokMaxSymbols]
	WideCharArr pePlus;
	WideCharArr peMinus;
	WideCharArr peMinusPlus;
	WideCharArr altNumTable;
	char reserved[20];
};
typedef struct NumberParts NumberParts;
typedef NumberParts *NumberPartsPtr;

/**
<pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct Itl4Rec
{
	short flags;		 /**<  reserved*/
	long resourceType;	 /**<  contains 'itl'*/
	short resourceNum;	 /**<  resource ID*/
	short version;		 /**<  version number*/
	short format;		 /**<  format code*/
	short resHeader;	 /**<  reserved*/
	long resHeader;		 /**<  reserved*/
	short numTables;	 /**<  number of tables, one-based*/
	long mapOffset;		 /**<  *offsets are from record start*/
	long strOffset;		 /**<  offset to routine that  copies*/
	long fetchOffset;	 /**<  offset to routine that gets next byte*/
	long unTokenOffset;	 /**<  offset to untoken table, maps  token*/
	long defPartsOffset; /**<  offset to default number parts*/
	long resOffset;		 /**<  reserved*/
	long resOffset;		 /**<  reserved*/
	long resOffset;		 /**<  reserved*/
} ItlRec;				 /**< */

typedef struct Itl4Rec Itl4Rec;
typedef Itl4Rec *Itl4Ptr;
typedef Itl4Ptr *Itl4Handle;
// New NItl4Rec for System 7.0: /**
<pre> A new section of the 'itl4' resource contains a table of white space characters
	in the script.A formerly reserved field in the header specifies the offset to this whiteSpaceList table,
	and a new field specifies its length.The format of
			the table defined by whiteSpaceList is similar to the format of the untoken
				table : dc.w(length of whiteSpaceList in bytes)
						// New NItl4Rec for System 7.0:
						dc.w(offset from beginning of whiteSpaceList to first entry)
							dc.w(offset from beginning of whiteSpaceList to second entry)
								.</ pre>
									* \copyright THINK Reference © 1991 -
		1992 Symantec Corporation
				* /
			struct NItl4Rec
{
	shortflags;			  /**<  reserved*/
	longresourceType;	  /**<  contains 'itl'*/
	shortresourceNum;	  /**<  resource ID*/
	shortversion;		  /**<  version number*/
	shortformat;		  /**<  format code*/
	shortresHeader;		  /**<  reserved*/
	longresHeader;		  /**<  reserved*/
	shortnumTables;		  /**<  number of tables, one-based*/
	longmapOffset;		  /**<  offset to table that maps byte to*/
	longstrOffset;		  /**<  offset to routine that  copies*/
	longfetchOffset;	  /**<  offset to routine that gets next byte*/
	longunTokenOffset;	  /**<  offset to untoken table, maps  token*/
	longdefPartsOffset;	  /**<  offset to default number parts*/
	longwhtSpListOffset;  /**<  offset to white space code list*/
	longresOffset;		  /**<  reserved*/
	longresOffset;		  /**<  reserved*/
	shortresLength;		  /**<  reserved*/
	shortresLength;		  /**<  reserved*/
	shortresLength;		  /**<  reserved*/
	shortunTokenLength;	  /**<  length of untoken table*/
	shortdefPartsLength;  /**<  length of default number parts*/
	shortwhtSpListLength; /**<  length of white space code list*/
	shortresLength;		  /**<  reserved*/
	shortresLength;		  /**<  reserved*/
} NItlRec;				  /**< */

typedef struct NItl4Rec NItl4Rec;
typedef NItl4Rec *NItl4Ptr;
typedef NItl4Ptr *NItl4Handle;

struct TableDirectoryRecord
{
	OSType tableSignature;			// 4 byte long table name
	unsigned long reserved;			// Reserved for internal use
	unsigned long tableStartOffset; // Table start offset in byte
	unsigned long tableSize;		// Table size in byte
};
typedef struct TableDirectoryRecord TableDirectoryRecord;
struct Itl5Record
{
	Fixed versionNumber;					// itl5 resource version number
	unsigned short numberOfTables;			// Number of tables it contains
	unsigned short reserved[3];				// Reserved for internal use
	TableDirectoryRecord tableDirectory[1]; // Table directory records
};
typedef struct Itl5Record Itl5Record;
struct RuleBasedTrslRecord
{
	short sourceType;	 // Transliterate target type for the LHS of the rule
	short targetType;	 // Transliterate target type for the RHS of the rule
	short formatNumber;	 // Transliterate resource format number
	short propertyFlag;	 // Transliterate property flags
	short numberOfRules; // Number of rules following this field
};
typedef struct RuleBasedTrslRecord RuleBasedTrslRecord;

/**
<pre>If you do not have access to the Rez file SysTypes.r, which contains the Rez
type definition of the 'itlc' resource, consult with Macintosh Developer
Technical Support for details.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct ItlcRecord
{
	shortitlcSystem;	 /**<  default system script*/
	shortitlcReserved;	 /**<  reserved*/
	charitlcFontForce;	 /**<  default font force flag*/
	charitlcIntlForce;	 /**<  default intl force flag*/
	charitlcOldKybd;	 /**<  old keyboard*/
	chartlcFlags;		 /**<  general flags*/
	shortitlcIconOffset; /**<  script icon offset*/
	charitlcIconSide;	 /**<  con side*/
	charitlcIconRsvd;	 /**<  rsvd for other icon info*/
	shortitlcRegionCode; /**<  preferred verXxx code*/
	charitlcReserved[];	 /**<  for future use*/
} ItlcRecord;			 /**< */

typedef struct ItlcRecord ItlcRecord;
/**
<pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct ItlbRecord
{
	shortitlbNumber;   /**<  itl id number*/
	shortitlbDate;	   /**<  itl id number*/
	shortitlbSort;	   /**<  itl id number*/
	shortitlbFlags;	   /**<  Script flags*/
	shortitlbToken;	   /**<  itl id number*/
	shortitlbEncoding; /**<  itl ID # (optional;/**< char*/
	shortitlbLang;	   /**<  cur language for script*/
	charitlbNumRep;	   /**<  number representation code*/
	charitlbDateRep;   /**<  date representation code*/
	shortitlbKeys;	   /**<  KCHR id number*/
	shortitlbIcon;	   /**<  ID # of SICN or kcs#/kcs/kcs*/
} ItlbRecord;		   /**< */

typedef struct ItlbRecord ItlbRecord;
// New ItlbExtRecord structure for System 7.0 /**
<pre>The new bit flag, defined for the script flags word, is located in the itlbFlags
field in the 'itlb' record data structure. Set the smsfAutoInit bit in a script's
'itlb' to instruct the Script Manager to initialize the script system
automatically. (See Creating Simple Script Systems for details.)
If you do not have access to the Rez file SysTypes.r, which contains the Rez
type for the 'itlb' resource, consult Macintosh Developer Technical Support
for details.
// New ItlbExtRecord structure for System 7.0 
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct ItlbExtRecord
{
	ItlbRecord base;	  /**< un-extended ItlbRecord*/
	longItlbLocalSize;	  /**< size of script's local record*/
	shortItlbMonoFond;	  /**< default monospace FOND ID*/
	shortItlbMonoSize;	  /**< default monospace font size*/
	shortItlbPrefFond;	  /**< preferred FOND ID*/
	shortItlbPrefSize;	  /**< preferred font size*/
	shortItlbSmallFond;	  /**< default small FOND ID*/
	shortItlbSmallSize;	  /**< default small font size*/
	shortItlbSysFond;	  /**< default system FOND ID*/
	shortItlbSysSize;	  /**< default system font size*/
	shortItlbAppFond;	  /**< default application FOND ID*/
	shortItlbAppSize;	  /**< default application font size*/
	shortItlbHelpFond;	  /**< default Help Mgr FOND ID*/
	shortItlbHelpSize;	  /**< default Help Mgr font size*/
	StyleItlbValidStyles; /**< set of valid styles for script*/
	StyleItlbAliasStyle;  /**< style (set) to mark aliases*/
} ItlbExtRecord;		  /**< */

typedef struct ItlbExtRecord ItlbExtRecord;

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

#endif // __INTLRESOURCES__ // __INTLRESOURCES__
