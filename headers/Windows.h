/**
     \file       Windows.h

    \brief   Window Manager Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1984-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
/**
    NOTE

    The file Windows.h has been renamed to "MacWindows.h" to prevent a collision
    with the Microsoft Windows(tm) header file "Windows.h".  MacOS only
   developers may continue to use #include <Windows.h>.  Developers doing
   cross-platform work where Windows.h also exists should change their sources
   to use #include <MacWindows.h>
*/

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#if TARGET_OS_MAC
#ifndef __MACWINDOWS__
#include <MacWindows.h>
#endif

#else
/**
    If you get here, your development environment is messed up.
    This file is for MacOS development only.
*/
#error This file (Windows.h) is for developing MacOS software only!
#endif /** TARGET_OS_MAC */
