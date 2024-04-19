/**
     \file       CGBase.h

    \brief   xxx put contents here xxx

    \introduced_in  from CoreGraphics-70.root
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 2000-2001 by Apple Computer, Inc., all rights reserved.
    
    \ingroup CoreGraphics
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CGBASE__
#define __CGBASE__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#include <stddef.h>
#if __MWERKS__ > 0x2300
#include <stdint.h>
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

/* if stdint.h has been included, don't define same types */
#if __MWERKS__ <= 0x2300
typedef signed long int32_t;
#endif
/* define some unix types used by CoreGraphics */
#ifndef _MACH_PPC_BOOLEAN_H_
typedef int boolean_t;
#endif
#ifndef _STDINT_H_
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned long u_int32_t;
#endif

#if !defined(CG_INLINE)
#if defined(__GNUC__)
#define CG_INLINE static __inline__
#elif defined(__MWERKS__)
#define CG_INLINE static inline
#else
#define CG_INLINE static
#endif
#endif

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

#endif /* __CGBASE__ */
