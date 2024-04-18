/**
     \file       OpenTptGlobalNew.h

    \brief   Definition of "new" operator that uses Open Transport's

    \introduced_in  Mac OS 8.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __OPENTPTGLOBALNEW__
#define __OPENTPTGLOBALNEW__

/**
    This file previously contained C++ code to map the global operator new
    to the OTAllocMem() routines.  Since OTAllocMem() is not in Carbon, these
    file has been deprecated.  If you wish to use map C++ operator new
    to an OTAllocMem call, you will need to do in your own source code.

*/

#endif /** __OPENTPTGLOBALNEW__ */
