/**
     \file       DateTimeUtils.h

    \brief   International Date and Time Interfaces (previously in TextUtils)

    \introduced_in  Mac OS 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Time

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DATETIMEUTILS__
#define __DATETIMEUTILS__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

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

      Here are the current routine names and the translations to the older forms.
      Please use the newer forms in all new code and migrate the older names out
     of existing code as maintainance permits.

      New Name                    Old Name(s)

      DateString                  IUDatePString IUDateString
      InitDateCache
      LongDateString              IULDateString
      LongTimeString              IULTimeString
      StringToDate                String2Date
      StringToTime
      TimeString                  IUTimeString IUTimePString
      LongDateToSeconds           LongDate2Secs
      LongSecondsToDate           LongSecs2Date
      DateToSeconds               Date2Secs
      SecondsToDate               Secs2Date


      Carbon only supports the new names.  The old names are undefined for Carbon
     targets. This is true for C, Assembly and Pascal.

      InterfaceLib always has exported the old names.  For C macros have been
     defined to allow the use of the new names.  For Pascal and Assembly using the
     new names will result in link errors.

  */

  typedef SInt16 ToggleResults;
  enum
  {
    /** Toggle results */
    toggleUndefined = 0,
    toggleOK = 1,
    toggleBadField = 2,
    toggleBadDelta = 3,
    toggleBadChar = 4,
    toggleUnknown = 5,
    toggleBadNum = 6,
    toggleOutOfRange = 7, /**synonym for toggleErr3*/
    toggleErr3 = 7,
    toggleErr4 = 8,
    toggleErr5 = 9
  };

  enum
  {
    /** Date equates */
    smallDateBit = 31,     /**Restrict valid date/time to range of Time global*/
    togChar12HourBit = 30, /**If toggling hour by char, accept hours 1..12 only*/
    togCharZCycleBit =
        29, /**Modifier for togChar12HourBit: accept hours 0..11 only*/
    togDelta12HourBit =
        28,               /**If toggling hour up/down, restrict to 12-hour range (am/pm)*/
    genCdevRangeBit = 27, /**Restrict date/time to range used by genl CDEV*/
    validDateFields = -1,
    maxDateField = 10
  };

  enum
  {
    eraMask = 0x0001,
    yearMask = 0x0002,
    monthMask = 0x0004,
    dayMask = 0x0008,
    hourMask = 0x0010,
    minuteMask = 0x0020,
    secondMask = 0x0040,
    dayOfWeekMask = 0x0080,
    dayOfYearMask = 0x0100,
    weekOfYearMask = 0x0200,
    pmMask = 0x0400,
    dateStdMask =
        0x007F /**default for ValidDate flags and ToggleDate TogglePB.togFlags*/
  };

  typedef SInt8 LongDateField;
  enum
  {
    eraField = 0,
    yearField = 1,
    monthField = 2,
    dayField = 3,
    hourField = 4,
    minuteField = 5,
    secondField = 6,
    dayOfWeekField = 7,
    dayOfYearField = 8,
    weekOfYearField = 9,
    pmField = 10,
    res1Field = 11,
    res2Field = 12,
    res3Field = 13
  };

  typedef SInt8 DateForm;
  enum
  {
    shortDate = 0,
    longDate = 1,
    abbrevDate = 2
  };

  enum
  {
    /** StringToDate status values */
    fatalDateTime =
        0x8000,        /** StringToDate and String2Time mask to a fatal error */
    longDateFound = 1, /** StringToDate mask to long date found */
    leftOverChars =
        2, /** StringToDate & Time mask to warn of left over characters */
    sepNotIntlSep =
        4, /** StringToDate & Time mask to warn of non-standard separators */
    fieldOrderNotIntl =
        8, /** StringToDate & Time mask to warn of non-standard field order */
    extraneousStrings =
        16, /** StringToDate & Time mask to warn of unparsable strings in text */
    tooManySeps =
        32, /** StringToDate & Time mask to warn of too many separators */
    sepNotConsistent =
        64, /** StringToDate & Time mask to warn of inconsistent separators */
    tokenErr =
        0x8100, /** StringToDate & Time mask for 'tokenizer err encountered' */
    cantReadUtilities = 0x8200,
    dateTimeNotFound = 0x8400,
    dateTimeInvalid = 0x8800
  };

  typedef short StringToDateStatus;
  typedef StringToDateStatus String2DateStatus;
  struct DateCacheRecord
  {
    short hidden[256]; /** only for temporary use */
  };
  typedef struct DateCacheRecord DateCacheRecord;
  typedef DateCacheRecord *DateCachePtr;
  struct DateTimeRec
  {
    short year;
    short month;
    short day;
    short hour;
    short minute;
    short second;
    short dayOfWeek;
  };
  typedef struct DateTimeRec DateTimeRec;

  typedef SInt64 LongDateTime;
  union LongDateCvt
  {
    SInt64 c;
    struct
    {
      UInt32 lHigh;
      UInt32 lLow;
    } hl;
  };
  typedef union LongDateCvt LongDateCvt;
  /**
  <pre>short list[14]; 280Index by LongDateField
  struct {
  short eraAlt; 20
  DateTimeRec oldDate; 142
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  union LongDateRec
  {
    short era;        /**< */
    short year;       /**< */
    short month;      /**< */
    short day;        /**< */
    short hour;       /**< */
    short minute;     /**< */
    short second;     /**< */
    short dayOfWeek;  /**< */
    short dayOfYear;  /**< */
    short weekOfYear; /**< */
    short pm;         /**< */
    short res;        /**< */
    short res;        /**< */
    short res;        /**< */
  } ld;               /**<*/

  typedef union LongDateRec LongDateRec;

  typedef SInt8 DateDelta;
  struct TogglePB
  {
    long togFlags;   /**caller normally sets low word to dateStdMask=$7F*/
    ResType amChars; /**from 'itl0', but uppercased*/
    ResType pmChars; /**from 'itl0', but uppercased*/
    long reserved[4];
  };
  typedef struct TogglePB TogglePB;
  /**
      These routine are available in Carbon with their new name
  */
  /**
   *  DateString()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DateString(long dateTime, DateForm longFlag, Str255 result, Handle intlHandle);

  /**
   *  TimeString()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  TimeString(long dateTime, Boolean wantSeconds, Str255 result, Handle intlHandle);

  /**
   *  LongDateString()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  LongDateString(const LongDateTime *dateTime, DateForm longFlag, Str255 result,
                 Handle intlHandle);

  /**
   *  LongTimeString()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  LongTimeString(const LongDateTime *dateTime, Boolean wantSeconds, Str255 result,
                 Handle intlHandle);

  /**
      These routine are available in Carbon and InterfaceLib with their new name
  */
  /**
   *  InitDateCache()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InitDateCache(DateCachePtr theCache);

  /**
   *  StringToDate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  StringToDateStatus
  StringToDate(Ptr textPtr, long textLen, DateCachePtr theCache, long *lengthUsed,
               LongDateRec *dateTime);

  /**
   *  StringToTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  StringToDateStatus
  StringToTime(Ptr textPtr, long textLen, DateCachePtr theCache, long *lengthUsed,
               LongDateRec *dateTime);

  /**
   *  LongDateToSeconds()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  LongDateToSeconds(const LongDateRec *lDate, LongDateTime *lSecs);

  /**
   *  LongSecondsToDate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  LongSecondsToDate(const LongDateTime *lSecs, LongDateRec *lDate);

  /**
  \brief Modify a LongDateTime parameter

  <pre>The ToggleDate function modifies a LongDateTime parameter by toggling one
of the corresponding fields of the long date record up or down or by setting it
explicitly.For more information see, Macintosh Worldwide Development: Guide
to System Software
</pre>
* \returns <pre>a ToggleResults
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  ToggleResults
  ToggleDate(LongDateTime *lSecs, LongDateField field, DateDelta delta, short ch,
             const TogglePB *params);

  /**
  \brief Check the validity of a long date record

  <pre>The ValidDate function checks the validity of a long date record For more
information see, Macintosh Worldwide Development: Guide to System Software.
</pre>
* \returns <pre>a short
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  short
  ValidDate(const LongDateRec *vDate, long flags, LongDateTime *newSecs);

  /**
  \brief Copy clock-chip time to Time variable

  <pre>ReadDateTime accesses the clock chip directly and stores its return value
into the low-memory variable Time (at 0x020C) and into the specified
variable. Applications normally use GetDateTime or GetTime .
secsis the address of a 4-byte variable. Upon return, it contains the
number of seconds since January 1, 1904 (as tracked by the
real-time clock hardware).
</pre>
* \returns <pre>an OSErr; an integer Error Code . It will be one of:
noErr(0) No error
clkRdErr (-85) Clock read error
</pre>
* \note <pre>You can convert the secs value to a more easily understood value (i.e., a
DateTimeRec ) via Secs2Date .
You can set the clock-chip to a new time/date using SetDateTime ; though
this is normally performed via the Control Panel DA.
Since the base date for the any "raw seconds" value is 1/1/1904 and since
secs is a 32-bit value, you won't be able to calculate with dates beyond
February 6, 2040.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 ReadDateTime(__A0)
#endif
  OSErr
  ReadDateTime(unsigned long *time);

  /**
  \brief Obtain "raw seconds" value of Time variable

  <pre>GetDateTime obtains the "raw" seconds value, as known to the system.
secsis the address of a 4-byte variable. Upon return, it contains the
number of seconds since Midnight, January 1, 1904 (as read from
the real-time clock hardware at startup and updated periodically by
the Time Manager ).
</pre>
* \returns <pre>none
</pre>
* \note <pre>GetDateTime simply copies the value of the low-memory variable Time
(at 0x020C) and into the specified variable. Thus, the following are
functionally equivalent:
unsigned long secs;
GetDateTime ( &secs); /* is the same as . . . */
  secs = Time;
It is recommended that you obtain the value using the GetDateTime trap
rather than using the low-memory variable however, as it is possible that
low-memory variables may change in the future.
You can convert the secs value to a more understandable value (i.e., a
DateTimeRec ) via Secs2Date .
The ReadDateTime function may return a slightly more accurate value
since it is possible for the Time variable to lose seconds when interrupts
get disabled for very long.
Since the base date for the "raw seconds" value is 1/1/1904 and since secs
is a 32-bit value, you won't be able to calculate with dates beyond February
6, 2040.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter GetDateTime(__A0)
#endif
void
GetDateTime(unsigned long *secs);

/**
\brief Set system date and time in "raw" seconds

<pre>SetDateTime sets the system data and time by writing a "raw" seconds value
to both the low-memory variable Time and the real-time clock chip. It also
verifies that the clock chip accepted the change without error.
secsspecifies the desired time. It is a count of seconds since Midnight,
January 1, 1904.
</pre>
* \returns <pre>an OSErr; an integer Error Code . It will be one of:
noErr(0) No error
clkWrErr (-86) Clock write error
clkRdErr (-85) Clock read error
</pre>
* \note <pre>The system time needs to be changed only rarely (e.g, on switching to
Daylight Savings Time) and is normally set by the user via the Control
Panel DA.
The Date2Secs function can be used to convert a DateTimeRec into a "raw"
seconds value. You could also use SetTime , which performs the conversion
automatically.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SetDateTime(__D0)
#endif
OSErr
SetDateTime(unsigned long time);

/**
\brief Set system date/time, using DateTimeRec  format

<pre>SetTime sets the system date and time, using the fields of a DateTimeRec
structure. The clock/calendar hardware and the global variable Time are
updated.
dtrpis the address of a 14-byte DateTimeRec structure. Its fields should
contain the current year, month, day, etc.
</pre>
* \returns <pre>none
</pre>
* \note <pre>SetTime converts dtrp to "raw" seconds and calls SetDateTime to store
the converted value into the clock chip and the Time variable.
The system time needs to be changed only rarely (e.g, on switching to or
from daylight savings time) and is normally set by the user via the Control
Panel DA.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetTime(__A0)
#endif
void
SetTime(const DateTimeRec *d);

/**
\brief Get current date and time in DateTimeRec format

<pre>GetTime obtains the current date and time in the form a DateTimeRec
structure.
dtrpis the address of a 14-byte DateTimeRec structure. Upon return,
its fields contain the current year, month, day, etc.
</pre>
* \returns <pre>none
</pre>
* \note <pre>GetTime calls GetDateTime and converts its "raw" seconds value into
corresponding DateTimeRec . For example:
DateTimeRec now; /* create a 14-byte record */
GetTime(&now);
printf("Today is %d/%d/%d\n", now.month, now.day, now.year);
printf("The first day of the rest of your life. . . ");
</ pre>
            * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                      *    \non_carbon_cfm in InterfaceLib 7.1 and
    later
        *    \carbon_lib in CarbonLib 1.0 and
    later
        *    \mac_os_x in version 10.0 and
    later
            * /
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter GetTime(__A0)
#endif
        void
            GetTime(DateTimeRec *d);

/**
 *  DateToSeconds()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
DateToSeconds(const DateTimeRec *d, unsigned long *secs);

/**
 *  SecondsToDate()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SecondsToDate(__D0, __A0)
#endif
  void
  SecondsToDate(unsigned long secs, DateTimeRec *d);

/**
    These routine are available in InterfaceLib using their old name.
    Macros allow using the new names in all source code.
*/
#if CALL_NOT_IN_CARBON
  /**
   *  IUDateString()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  IUDateString(long dateTime, DateForm longFlag, Str255 result);

  /**
  \brief Convert "raw" seconds into ASCII time string

  <pre>IUTimeString converts a binary date/time value into a string of text
identifying the corresponding time of day. International styles are taken into
consideration for the output.
rawSecs is a long integer; the number of seconds since Midnight, 1/1/1904.
You can use any time value obtained from a file or catalog information
block (see PBGetCatInfo ) or a value obtained via GetDateTime .
wantSecs specifies whether to include the seconds (as well as the hour and
minute) in the output. It is one of:
FALSEDiscard seconds: 12:05 AM
TRUEInclude seconds: 12:05:09 AM
resultStr is the address of a buffer. Upon return, it will contain the text of
the time as a pascal-style, length-prefixed string in the layout
identified by 'INTL' resource 0.
</pre>
* \returns <pre>none
</pre>
* \note <pre>Use IUDateString and IUTimeString to prepare date and time
information for display. These functions rely on information from 'INTL'
resources 0 and 1 in determining how to layout the text of the output string.
A "programmer's" variation, IUTimePString provides a way to modify
the output. For instance, you can force the output into 24-hr format or add
leading zeros to the hour.
Example
#include < Packages.h >
long nowNum;
Str255 nowStr;
GetDateTime ( &nowNum ); /* or today = Time */
  IUTimeString(nowNum, TRUE, nowStr); /* exclude seconds */
  DrawString("\pThe time is: ");
  DrawString(nowStr);
  </ pre>
              * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                        *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
              *    \carbon_lib not available *    \mac_os_x not available *
          /
          void
              IUTimeString(long dateTime, Boolean wantSeconds, Str255 result);

  /**
   *  IUDatePString()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  IUDatePString(long dateTime, DateForm longFlag, Str255 result,
                Handle intlHandle);

  /**
  \brief Convert "raw" seconds to time string (with parm)

  <pre>IUTimePString converts a binary date/time value into a string of text
describing the time of day, exactly as described in IUTimeString except that
you can specify a custom data structure to override normal output formatting.
rawSecs is a long integer; the number of seconds since Midnight, 1/1/1904.
You can use any date/time value obtained from a catalog information
block (see PBGetCatInfo ) or a value obtained via GetDateTime .
wantSecs specifies whether to include the seconds (as well as the hour and
minute) in the output. It is one of:
FALSEDiscard seconds: 1:05 AM
TRUEInclude seconds: 1:05:09 AM
resultStr is the address of a buffer. Upon return, it will contain the text of
the time as a pascal-style length-prefixed string in the layout
identified by flags in 'INTL' resource 0.
intlHndl is a Handle leading to either a 32-byte Intl0Rec structure. This is
normally a handle obtained via IUGetIntl (0) with selected fields
modified.
</pre>
* \returns <pre>none
</pre>
* \note <pre>IUTimePString and IUDatePString provide flexibility in how to
format the output of time and date strings.
Normal usage is to call IUGetIntl (0), modify one or more fields of the
Intl0Rec structure, and call IUTimePString , as in the example, below.
Example
#include < Packages.h >
/* outputs time in 24-hr format with leading 0s in all fields; e.g.: 13:04:02
*/
  long nowNum;
  Str255 nowStr;
  Intl0Hndl i0h;                 /* handle to an Intl0Rec */
  i0h = (Intl0Hndl)IUGetIntl(0); /* get current settings */
  (*i0h)->timeCycle = 0;         /* 24-hr format */
  (*i0h)->timeFmt |= secLeadingZ | minLeadingZ | hrLeadingZ;
  </ pre>
              * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                        *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
              *    \carbon_lib not available *    \mac_os_x not available *
          /
          void
              IUTimePString(long dateTime, Boolean wantSeconds, Str255 result,
                            Handle intlHandle);

  /**
   *  IULDateString()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  IULDateString(LongDateTime *dateTime, DateForm longFlag, Str255 result,
                Handle intlHandle);

  /**
   *  IULTimeString()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  IULTimeString(LongDateTime *dateTime, Boolean wantSeconds, Str255 result,
                Handle intlHandle);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
#define DateString(dateTime, longFlag, result, intlHandle) \
  IUDatePString(dateTime, longFlag, result, intlHandle)
#define TimeString(dateTime, wantSeconds, result, intlHandle) \
  IUTimePString(dateTime, wantSeconds, result, intlHandle)
#define LongDateString(dateTime, longFlag, result, intlHandle) \
  IULDateString(dateTime, longFlag, result, intlHandle)
#define LongTimeString(dateTime, wantSeconds, result, intlHandle) \
  IULTimeString(dateTime, wantSeconds, result, intlHandle)
#endif /** CALL_NOT_IN_CARBON */
#if OLDROUTINENAMES
#define String2Date(textPtr, textLen, theCache, lengthUsed, dateTime) \
  StringToDate(textPtr, textLen, theCache, lengthUsed, dateTime)
#define String2Time(textPtr, textLen, theCache, lengthUsed, dateTime) \
  StringToTime(textPtr, textLen, theCache, lengthUsed, dateTime)
#define LongDate2Secs(lDate, lSecs) LongDateToSeconds(lDate, lSecs)
#define LongSecs2Date(lSecs, lDate) LongSecondsToDate(lSecs, lDate)
#define Date2Secs(d, secs) DateToSeconds(d, secs)
#define Secs2Date(secs, d) SecondsToDate(secs, d)
#endif /** OLDROUTINENAMES */

#if CALL_NOT_IN_CARBON
  /**
   *  iudatestring()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  iudatestring(long dateTime, DateForm longFlag, char *result);

  /**
   *  iudatepstring()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  iudatepstring(long dateTime, DateForm longFlag, char *result,
                Handle intlHandle);

  /**
   *  iutimestring()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  iutimestring(long dateTime, Boolean wantSeconds, char *result);

  /**
   *  iutimepstring()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  iutimepstring(long dateTime, Boolean wantSeconds, char *result,
                Handle intlHandle);

  /**
   *  iuldatestring()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  iuldatestring(LongDateTime *dateTime, DateForm longFlag, char *result,
                Handle intlHandle);

  /**
   *  iultimestring()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  iultimestring(LongDateTime *dateTime, Boolean wantSeconds, char *result,
                Handle intlHandle);

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

#endif            /** __DATETIMEUTILS__ */
* /*/*/ * /*/*/ * /*/*/