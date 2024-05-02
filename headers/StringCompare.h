/**
     \file       StringCompare.h

    \brief   Public interfaces for String Comparison and related operations

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1985-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Misc

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __STRINGCOMPARE__
#define __STRINGCOMPARE__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __TEXTCOMMON__
#include <TextCommon.h>
#endif

#ifndef __SCRIPT__
#include <Script.h>
#endif

#ifndef __TYPESELECT__
#include <TypeSelect.h>
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

/**

    Here are the current System 7 routine names and the translations to the
   older forms. Please use the newer forms in all new code and migrate the older
   names out of existing code as maintenance permits.

    NEW NAME                    OLD NAME                    OBSOLETE FORM (no
   handle)

    CompareString (Str255)      IUCompPString (hp only)     IUCompString (hp
   only) CompareText (ptr/len)       IUMagPString                IUMagString
    IdenticalString (Str255)    IUEqualPString (hp only)    IUEqualString  (hp
   only) IdenticalText (ptr/len)     IUMagIDPString              IUMagIDString
    LanguageOrder               IULangOrder
    ScriptOrder                 IUScriptOrder
    StringOrder (Str255)        IUStringOrder (hp only)
    TextOrder (ptr/len)         IUTextOrder

    RelString
    CmpString (a only)
    EqualString (hp only)

    ReplaceText

    Carbon only supports the new names.  The old names are undefined for Carbon
   targets.

    InterfaceLib always has exported the old names.  For C macros have been
   defined to allow the use of the new names.  For Pascal and Assembly using the
   new names will result in link errors.

*/

enum {
  /* Special language code values for Language Order*/
  systemCurLang = -2,  /* current (itlbLang) lang for system script*/
  systemDefLang = -3,  /* default (table) lang for system script*/
  currentCurLang = -4, /* current (itlbLang) lang for current script*/
  currentDefLang = -5, /* default lang for current script*/
  scriptCurLang = -6,  /* current (itlbLang) lang for specified script*/
  scriptDefLang = -7   /* default language for a specified script*/
};

/* obsolete names*/
enum {
  iuSystemCurLang = systemCurLang,
  iuSystemDefLang = systemDefLang,
  iuCurrentCurLang = currentCurLang,
  iuCurrentDefLang = currentDefLang,
  iuScriptCurLang = scriptCurLang,
  iuScriptDefLang = scriptDefLang
};

/**
 *  These routines are available in Carbon with the new names.
 */
/**
 *  [Mac]ReplaceText()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacReplaceText ReplaceText
#endif
EXTERN_API(short)
MacReplaceText(Handle baseText, Handle substitutionText, Str15 key)
    FOURWORDINLINE(0x2F3C, 0x820C, 0xFFDC, 0xA8B5);

/**
 *  ScriptOrder()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
ScriptOrder(ScriptCode script1, ScriptCode script2)
    THREEWORDINLINE(0x3F3C, 0x001E, 0xA9ED);

/**
 *  [Mac]CompareString()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacCompareString CompareString
#endif
EXTERN_API(short)
MacCompareString(ConstStr255Param aStr, ConstStr255Param bStr,
                 Handle itl2Handle);

/**
 *  IdenticalString()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
IdenticalString(ConstStr255Param aStr, ConstStr255Param bStr,
                Handle itl2Handle);

/**
 *  StringOrder()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
StringOrder(ConstStr255Param aStr, ConstStr255Param bStr, ScriptCode aScript,
            ScriptCode bScript, LangCode aLang, LangCode bLang);

/**
 *  CompareText()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
CompareText(const void *aPtr, const void *bPtr, short aLen, short bLen,
            Handle itl2Handle) THREEWORDINLINE(0x3F3C, 0x001A, 0xA9ED);

/**
 *  IdenticalText()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
IdenticalText(const void *aPtr, const void *bPtr, short aLen, short bLen,
              Handle itl2Handle) THREEWORDINLINE(0x3F3C, 0x001C, 0xA9ED);

/**
 *  TextOrder()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
TextOrder(const void *aPtr, const void *bPtr, short aLen, short bLen,
          ScriptCode aScript, ScriptCode bScript, LangCode aLang,
          LangCode bLang) THREEWORDINLINE(0x3F3C, 0x0022, 0xA9ED);

/**
 *  LanguageOrder()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
LanguageOrder(LangCode language1, LangCode language2)
    THREEWORDINLINE(0x3F3C, 0x0020, 0xA9ED);

/**
 *  These routines are available in InterfaceLib with old names.
 *  Macros are provided for C to allow source code use to the new names.
 */
#if CALL_NOT_IN_CARBON
/**
 *  IUMagPString()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUMagPString(const void *aPtr, const void *bPtr, short aLen, short bLen,
             Handle itl2Handle) THREEWORDINLINE(0x3F3C, 0x001A, 0xA9ED);

/**
 *  IUMagIDPString()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUMagIDPString(const void *aPtr, const void *bPtr, short aLen, short bLen,
               Handle itl2Handle) THREEWORDINLINE(0x3F3C, 0x001C, 0xA9ED);

/**
 *  IUTextOrder()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUTextOrder(const void *aPtr, const void *bPtr, short aLen, short bLen,
            ScriptCode aScript, ScriptCode bScript, LangCode aLang,
            LangCode bLang) THREEWORDINLINE(0x3F3C, 0x0022, 0xA9ED);

/**
 *  IULangOrder()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IULangOrder(LangCode language1, LangCode language2)
    THREEWORDINLINE(0x3F3C, 0x0020, 0xA9ED);

/**
 *  IUScriptOrder()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUScriptOrder(ScriptCode script1, ScriptCode script2)
    THREEWORDINLINE(0x3F3C, 0x001E, 0xA9ED);

/**
 *  IUMagString()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUMagString(const void *aPtr, const void *bPtr, short aLen, short bLen)
    THREEWORDINLINE(0x3F3C, 0x000A, 0xA9ED);

/**
 *  IUMagIDString()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUMagIDString(const void *aPtr, const void *bPtr, short aLen, short bLen)
    THREEWORDINLINE(0x3F3C, 0x000C, 0xA9ED);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  IUCompPString()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUCompPString(ConstStr255Param aStr, ConstStr255Param bStr, Handle itl2Handle);

/**
 *  IUEqualPString()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUEqualPString(ConstStr255Param aStr, ConstStr255Param bStr, Handle itl2Handle);

/**
 *  IUStringOrder()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUStringOrder(ConstStr255Param aStr, ConstStr255Param bStr, ScriptCode aScript,
              ScriptCode bScript, LangCode aLang, LangCode bLang);


			/** 
			\brief Compare p-strings for international sorting 
			
			<pre>IUCompString compares two pascal-style strings and indicates which is
greater or if they are equal. It takes into consideration such international
characteristics as diacritical marks and ligatures. It DOES differentiate
between upper- and lowercase.
strAand . . .
strBare the addresses of pascal-style length-prefixed strings to be
compared.
</pre>
 * \returns <pre>a signed integer; it describes the collation relationship of strA and
strB. It is one of:
-1 strA is less than strB
0 strA and strB are equal
1 strA is greater than strB
</pre>
 * \note <pre>The return code is the same as used by the familiar C strcmp function. As
with strcmp, a short string is always seen as less than a long string.
IUCompString may be overkill for your application. It is less efficient
than a direct ASCII compare, as it has to look up the "collating weight" of
each character of each string.
This actually ends up calling IUMagString , which does not require
length-prefixed strings.
For case-insensitive equality testing (as when matching file names), use
IUEqualString or EqualString .
The actual comparison function is stored in the itl2 resource.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUCompString(ConstStr255Param aStr, ConstStr255Param bStr);

/**
 *  IUEqualString()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
IUEqualString(ConstStr255Param aStr, ConstStr255Param bStr);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
#if TARGET_OS_MAC
#define CompareString(aStr, bStr, itl2Handle)                                  \
  IUCompPString(aStr, bStr, itl2Handle)
#endif
#define CompareText(aPtr, bPtr, aLen, bLen, itl2Handle)                        \
  IUMagPString(aPtr, bPtr, aLen, bLen, itl2Handle)
#define IdenticalString(aStr, bStr, itl2Handle)                                \
  IUEqualPString(aStr, bStr, itl2Handle)
#define IdenticalText(aPtr, bPtr, aLen, bLen, itl2Handle)                      \
  IUMagIDPString(aPtr, bPtr, aLen, bLen, itl2Handle)
#define StringOrder(aStr, bStr, aScript, bScript, aLang, bLang)                \
  IUStringOrder(aStr, bStr, aScript, bScript, aLang, bLang)
#define TextOrder(aPtr, bPtr, aLen, bLen, aScript, bScript, aLang, bLang)      \
  IUTextOrder(aPtr, bPtr, aLen, bLen, aScript, bScript, aLang, bLang)
#define LanguageOrder(language1, language2) IULangOrder(language1, language2)
#endif /* CALL_NOT_IN_CARBON */
#if CALL_NOT_IN_CARBON
/**
 *  iucomppstring()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(short)
iucomppstring(const char *aStr, const char *bStr, Handle intlHandle);

/**
 *  iuequalpstring()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(short)
iuequalpstring(const char *aStr, const char *bStr, Handle intlHandle);

/**
 *  iustringorder()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(short)
iustringorder(const char *aStr, const char *bStr, ScriptCode aScript,
              ScriptCode bScript, LangCode aLang, LangCode bLang);

/**
 *  iucompstring()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(short)
iucompstring(const char *aStr, const char *bStr);

/**
 *  iuequalstring()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(short)
iuequalstring(const char *aStr, const char *bStr);

#endif /* CALL_NOT_IN_CARBON */


			/** 
			\brief Compare two Pascal-style strings for sort order 
			
			<pre>RelString compares two Pascal-style length-prefixed strings (optionally
ignoring case and/or diacritical marks), and returns an indication of which
comes first in the ASCII collating sequence.
strAand . . .
strBare addresses of Pascal-style length-prefixed strings.
caseSens specifies whether or not the comparison should be case-sensitive.
It must be one of:
FALSEignore character case when comparing ('A' == 'a')
TRUEcharacter case is significant ('A' != 'a')
diacSens specifies whether or not the comparison should be sensitive to
diacritical marks. It must be one of:
FALSEignore diacritical marks when comparing (' å' == 'a')
TRUEdiacritical marks are significant (' å' != 'a')
</pre>
 * \returns <pre>a signed integer; it indicates the relative collating value of the
strings, considering the case- and diacritical-sensitivity. Using the
same values as with the familiar strcmp() library function, it is one
of:
-1strA is less than strB
0strA is equal to strB
+1strA is greater than strB
</pre>
 * \note <pre>Since RelString compares Pascal-style strings directly, it is handier
than converting to C-style strings and using strcmp.
If caseSens =FALSE, then both strings are treated as if they had been
upshifted with UprString (though the original contents are not modified).
For 64K ROMs, the EqualString function can be used to test if two
strings are the same. The IUEqualString and IUCompString functions
take into consideration special spelling conventions used in foreign
languages.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
RelString(ConstStr255Param str1, ConstStr255Param str2, Boolean caseSensitive,
          Boolean diacSensitive);


			/** 
			\brief See if two Pascal-style strings are equal 
			
			<pre>EqualString compares two pascal-style length-prefixed strings (optionally
ignoring case and/or diacritical marks), and returns an indication of whether
or not they are equal.
strAand . . .
strBare addresses of Pascal-style length-prefixed strings.
caseSens specifies whether or not the comparison should be case-sensitive.
It must be one of:
FALSEignore character case when comparing ('A' == 'a')
TRUEcharacter case is significant ('A' != 'a')
diacSens specifies whether or not the comparison should be sensitive to
diacritical marks. It must be one of:
FALSEignore diacritical marks when comparing (' å' == 'a')
TRUEdiacritical marks are significant (' å' != 'a')
</pre>
 * \returns <pre>a Boolean; it indicates whether the strings are equal, considering
the case- and diacritical sensitivity. It is one of:
FALSEnot equal
TRUEequal
</pre>
 * \note <pre>Since EqualString compares pascal-style strings directly, it is handier
than converting to C-style strings and using strcmp. Examples:
Str255 strA="\pAbcDef";
Str255 strB="\p åbcdef";
EqualString ( strA,strB, TRUE,TRUE); /* Returns FALSE */
EqualString ( strA, strB, FALSE,FALSE); /* Returns TRUE */
If caseSens =FALSE, then both strings are treated as if they had been
upshifted with UprString (though the original contents are not modified).
The RelString function [128K ROMs] is more flexible in that its return
code identifies which string is higher or lower in the collating sequence.
The IUEqualString and IUCompString functions take into consideration
special spelling conventions used in foreign languages.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Boolean)
EqualString(ConstStr255Param str1, ConstStr255Param str2, Boolean caseSensitive,
            Boolean diacSensitive);

/**
 *  relstring()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(short)
relstring(const char *str1, const char *str2, Boolean caseSensitive,
          Boolean diacSensitive);

#if CALL_NOT_IN_CARBON
/**
 *  equalstring()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(Boolean)
equalstring(const char *str1, const char *str2, Boolean caseSensitive,
            Boolean diacSensitive);

#endif /* CALL_NOT_IN_CARBON */

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

#endif /* __STRINGCOMPARE__ */
