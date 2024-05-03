/**
     \file       FinderRegistry.h

    \brief   Data types for Finder AppleEvents

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup File

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FINDERREGISTRY__
#define __FINDERREGISTRY__

#ifndef __AEREGISTRY__
#include <AERegistry.h>
#endif

#ifndef __OSA__
#include <OSA.h>
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
    kAEFinderSuite = FOUR_CHAR_CODE('fndr')
  };

  enum
  {
    kAECleanUp = FOUR_CHAR_CODE('fclu'),
    kAEEject = FOUR_CHAR_CODE('ejct'),
    kAEEmpty = FOUR_CHAR_CODE('empt'),
    kAEErase = FOUR_CHAR_CODE('fera'),
    kAEGestalt = FOUR_CHAR_CODE('gstl'),
    kAEPutAway = FOUR_CHAR_CODE('ptwy'),
    kAERebuildDesktopDB = FOUR_CHAR_CODE('rddb'),
    kAESync = FOUR_CHAR_CODE('fupd'),
    kAEInterceptOpen = FOUR_CHAR_CODE('fopn')
  };

  enum
  {
    kAEDatabaseSuite = FOUR_CHAR_CODE('DATA'),
    kAESort = FOUR_CHAR_CODE('SORT')
  };

  enum
  {
    cInternalFinderObject =
        FOUR_CHAR_CODE('obj ')
  };

  enum
  {
    cAliasFile = FOUR_CHAR_CODE('alia'),
    cApplicationFile = FOUR_CHAR_CODE('appf'),
    cControlPanelFile = FOUR_CHAR_CODE('ccdv'),
    cDeskAccessoryFile = FOUR_CHAR_CODE('dafi'),
    cDocumentFile = FOUR_CHAR_CODE('docf'),
    cFontFile = FOUR_CHAR_CODE('fntf'),
    cSoundFile = FOUR_CHAR_CODE('sndf'),
    cClippingFile = FOUR_CHAR_CODE('clpf'),
    cContainer = FOUR_CHAR_CODE('ctnr'),
    cDesktop = FOUR_CHAR_CODE('cdsk'),
    cSharableContainer = FOUR_CHAR_CODE('sctr'),
    cDisk = FOUR_CHAR_CODE('cdis'),
    cFolder = FOUR_CHAR_CODE('cfol'),
    cSuitcase = FOUR_CHAR_CODE('stcs'),
    cAccessorySuitcase = FOUR_CHAR_CODE('dsut'),
    cFontSuitcase = FOUR_CHAR_CODE('fsut'),
    cTrash = FOUR_CHAR_CODE('ctrs'),
    cDesktopPrinter = FOUR_CHAR_CODE('dskp'),
    cPackage = FOUR_CHAR_CODE('pack'),
    cContentSpace = FOUR_CHAR_CODE('dwnd'),
    cContainerWindow = FOUR_CHAR_CODE('cwnd'),
    cInfoWindow = FOUR_CHAR_CODE('iwnd'),
    cSharingWindow = FOUR_CHAR_CODE('swnd'),
    cStatusWindow = FOUR_CHAR_CODE('qwnd'),
    cClippingWindow = FOUR_CHAR_CODE('lwnd'),
    cPreferencesWindow = FOUR_CHAR_CODE('pwnd'),
    cDTPWindow = FOUR_CHAR_CODE('dtpw'),
    cProcess = FOUR_CHAR_CODE('prcs'),
    cAccessoryProcess = FOUR_CHAR_CODE('pcda'),
    cApplicationProcess = FOUR_CHAR_CODE('pcap'),
    cGroup = FOUR_CHAR_CODE('sgrp'),
    cUser = FOUR_CHAR_CODE('cuse'),
    cSharingPrivileges = FOUR_CHAR_CODE('priv'),
    cPreferences = FOUR_CHAR_CODE('cprf'),
    cLabel = FOUR_CHAR_CODE('clbl'),
    cSound = FOUR_CHAR_CODE('snd '),
    cAliasList = FOUR_CHAR_CODE('alst'),
    cSpecialFolders =
        FOUR_CHAR_CODE('spfl'),
    cOnlineDisk = FOUR_CHAR_CODE('cods'),
    cOnlineLocalDisk = FOUR_CHAR_CODE('clds'),
    cOnlineRemoteDisk =
        FOUR_CHAR_CODE('crds'),
    cEntireContents = FOUR_CHAR_CODE('ects'),
    cIconFamily = FOUR_CHAR_CODE('ifam')
  };

  enum
  {
    pComment = FOUR_CHAR_CODE('comt'),
    pContainer = cContainer,
    pContentSpace = cContentSpace,
    pCreationDateOld =
        FOUR_CHAR_CODE('crtd'),
    pCreationDate = FOUR_CHAR_CODE('ascd'),
    pDescription = FOUR_CHAR_CODE('dscr'),
    pDisk = cDisk,
    pFolderOld = cFolder,
    pFolder = FOUR_CHAR_CODE('asdr'),
    pIconBitmap =
        FOUR_CHAR_CODE('iimg'),
    pInfoWindow = cInfoWindow,
    pKind = FOUR_CHAR_CODE('kind'),
    pLabelIndex = FOUR_CHAR_CODE('labi'),
    pModificationDateOld =
        FOUR_CHAR_CODE('modd'),
    pModificationDate = FOUR_CHAR_CODE('asmo'),
    pPhysicalSize = FOUR_CHAR_CODE('phys'),
    pPosition = FOUR_CHAR_CODE('posn'),
    pIsSelected = FOUR_CHAR_CODE('issl'),
    pSize = pPointSize,
    pWindow = cWindow,
    pPreferencesWindow = cPreferencesWindow
  };

  enum
  {
    pFileCreator = FOUR_CHAR_CODE('fcrt'),
    pFileType = FOUR_CHAR_CODE('asty'),
    pFileTypeOld = FOUR_CHAR_CODE('fitp'),
    pIsLocked = FOUR_CHAR_CODE('aslk'),
    pIsLockedOld = FOUR_CHAR_CODE('islk'),
    pProductVersion = FOUR_CHAR_CODE('ver2')
  };

  enum
  {
    pOriginalItem = FOUR_CHAR_CODE('orig')
  };

  enum
  {
    pMinAppPartition = FOUR_CHAR_CODE('mprt'),
    pAppPartition = FOUR_CHAR_CODE('appt'),
    pSuggestedAppPartition = FOUR_CHAR_CODE('sprt'),
    pIsScriptable = FOUR_CHAR_CODE('isab')
  };

  enum
  {
    pInternetLocation = FOUR_CHAR_CODE('iloc')
  };

  enum
  {
    pSound = FOUR_CHAR_CODE('snd ')
  };

  enum
  {
    pShowFolderSize = FOUR_CHAR_CODE(
        'sfsz'),
    pShowComment = FOUR_CHAR_CODE(
        'scom'),
    pShowDate = FOUR_CHAR_CODE(
        'sdat'),
    pShowCreationDate = FOUR_CHAR_CODE(
        'scda'),
    pShowKind = FOUR_CHAR_CODE(
        'sknd'),
    pShowLabel = FOUR_CHAR_CODE(
        'slbl'),
    pShowSize = FOUR_CHAR_CODE(
        'ssiz'),
    pShowVersion = FOUR_CHAR_CODE(
        'svrs'),
    pSortDirection = FOUR_CHAR_CODE('sord'),
    pShowDiskInfo = FOUR_CHAR_CODE('sdin'),
    pListViewIconSize = FOUR_CHAR_CODE(
        'lvis'),
    pGridIcons = FOUR_CHAR_CODE(
        'fgrd'),
    pStaggerIcons =
        FOUR_CHAR_CODE('fstg'),
    pViewFont = FOUR_CHAR_CODE('vfnt'),
    pViewFontSize = FOUR_CHAR_CODE('vfsz')
  };

  enum
  {
    pCompletelyExpanded = FOUR_CHAR_CODE('pexc'),
    pContainerWindow = cContainerWindow,
    pEntireContents = cEntireContents,
    pExpandable = FOUR_CHAR_CODE('pexa'),
    pExpanded = FOUR_CHAR_CODE('pexp'),
    pPreviousView =
        FOUR_CHAR_CODE('svew'),
    pView = FOUR_CHAR_CODE('pvew'),
    pIconSize = pListViewIconSize,
    pKeepArranged = FOUR_CHAR_CODE('arrg'),
    pKeepArrangedBy = FOUR_CHAR_CODE('arby')
  };

  enum
  {
    pStartupDisk = FOUR_CHAR_CODE('sdsk'),
    pTrash = FOUR_CHAR_CODE('trsh')
  };

  enum
  {
    pOwner = FOUR_CHAR_CODE('sown'),
    pOwnerPrivileges = FOUR_CHAR_CODE('ownr'),
    pGroup = cGroup,
    pGroupPrivileges = FOUR_CHAR_CODE('gppr'),
    pGuestPrivileges = FOUR_CHAR_CODE('gstp'),
    pArePrivilegesInherited = FOUR_CHAR_CODE('iprv'),
    pExported = FOUR_CHAR_CODE('sexp'),
    pMounted = FOUR_CHAR_CODE('smou'),
    pSharingProtection = FOUR_CHAR_CODE('spro'),
    pSharing = FOUR_CHAR_CODE('shar'),
    pSharingWindow = cSharingWindow
  };

  enum
  {
    pCapacity = FOUR_CHAR_CODE('capa'),
    pEjectable = FOUR_CHAR_CODE('isej'),
    pFreeSpace = FOUR_CHAR_CODE('frsp'),
    pLocal = FOUR_CHAR_CODE('isrv'),
    pIsStartup = FOUR_CHAR_CODE('istd')
  };

  enum
  {
    pWarnOnEmpty = FOUR_CHAR_CODE('warn')
  };

  enum
  {
    pIsZoomedFull = FOUR_CHAR_CODE('zumf'),
    pIsPopup = FOUR_CHAR_CODE('drwr'),
    pIsPulledOpen = FOUR_CHAR_CODE('pull'),
    pIsCollapsed = FOUR_CHAR_CODE('wshd')
  };

  enum
  {
    pObject = cObject
  };

  enum
  {
    pSharableContainer = cSharableContainer
  };

  enum
  {
    pInfoPanel = FOUR_CHAR_CODE('panl')
  };

  enum
  {
    pFileShareOn = FOUR_CHAR_CODE('fshr'),
    pFileShareStartingUp = FOUR_CHAR_CODE('fsup'),
    pProgramLinkingOn = FOUR_CHAR_CODE('iac ')
  };

  enum
  {
    pShowModificationDate = pShowDate,
    pUseRelativeDate = FOUR_CHAR_CODE(
        'urdt'),
    pDelayBeforeSpringing = FOUR_CHAR_CODE('dela'),
    pSpringOpenFolders = FOUR_CHAR_CODE('sprg'),
    pUseShortMenus = FOUR_CHAR_CODE('usme'),
    pUseWideGrid = FOUR_CHAR_CODE('uswg'),
    pLabel1 = FOUR_CHAR_CODE('lbl1'),
    pLabel2 = FOUR_CHAR_CODE('lbl2'),
    pLabel3 = FOUR_CHAR_CODE('lbl3'),
    pLabel4 = FOUR_CHAR_CODE('lbl4'),
    pLabel5 = FOUR_CHAR_CODE('lbl5'),
    pLabel6 = FOUR_CHAR_CODE('lbl6'),
    pLabel7 = FOUR_CHAR_CODE('lbl7'),
    pDefaultIconViewIconSize = FOUR_CHAR_CODE('iisz'),
    pDefaultButtonViewIconSize = FOUR_CHAR_CODE('bisz'),
    pDefaultListViewIconSize =
        FOUR_CHAR_CODE('lisz'),
    pIconViewArrangement = FOUR_CHAR_CODE('iarr'),
    pButtonViewArrangement = FOUR_CHAR_CODE('barr')
  };

  enum
  {
    pNoArrangement = FOUR_CHAR_CODE('narr'),
    pSnapToGridArrangement = FOUR_CHAR_CODE('grda'),
    pByNameArrangement = FOUR_CHAR_CODE('nama'),
    pByModificationDateArrangement = FOUR_CHAR_CODE('mdta'),
    pByCreationDateArrangement = FOUR_CHAR_CODE('cdta'),
    pBySizeArrangement = FOUR_CHAR_CODE('siza'),
    pByKindArrangement = FOUR_CHAR_CODE('kina'),
    pByLabelArrangement = FOUR_CHAR_CODE('laba')
  };

  enum
  {
    pFile = cFile,
    pPartitionSpaceUsed = FOUR_CHAR_CODE('pusd'),
    pLocalAndRemoteEvents = FOUR_CHAR_CODE('revt'),
    pHasScriptingTerminology = FOUR_CHAR_CODE('hscr')
  };

  enum
  {
    pDeskAccessoryFile = cDeskAccessoryFile
  };

  enum
  {
    pApplicationFile = cApplicationFile
  };

  enum
  {
    pCanConnect = FOUR_CHAR_CODE('ccon'),
    pCanChangePassword = FOUR_CHAR_CODE('ccpw'),
    pCanDoProgramLinking = FOUR_CHAR_CODE('ciac'),
    pIsOwner = FOUR_CHAR_CODE('isow'),
    pARADialIn = FOUR_CHAR_CODE('arad'),
    pShouldCallBack = FOUR_CHAR_CODE('calb'),
    pCallBackNumber = FOUR_CHAR_CODE('cbnm')
  };

  enum
  {
    pAboutMacintosh = FOUR_CHAR_CODE('abbx'),
    pAppleMenuItemsFolder = FOUR_CHAR_CODE('amnu'),
    pControlPanelsFolder = FOUR_CHAR_CODE('ctrl'),
    pDesktop = FOUR_CHAR_CODE('desk'),
    pExtensionsFolder = FOUR_CHAR_CODE('extn'),
    pFinderPreferences = FOUR_CHAR_CODE('pfrp'),
    pFontsFolder = FOUR_CHAR_CODE('font'),
    pFontsFolderPreAllegro =
        FOUR_CHAR_CODE('ffnt'),
    pLargestFreeBlock = FOUR_CHAR_CODE('mfre'),
    pPreferencesFolder = FOUR_CHAR_CODE('pref'),
    pShortCuts = FOUR_CHAR_CODE('scut'),
    pShutdownFolder = FOUR_CHAR_CODE('shdf'),
    pStartupItemsFolder = FOUR_CHAR_CODE('strt'),
    pSystemFolder = FOUR_CHAR_CODE('macs'),
    pTemporaryFolder = FOUR_CHAR_CODE('temp'),
    pViewPreferences = FOUR_CHAR_CODE('pvwp'),
    pStartingUp = FOUR_CHAR_CODE('awak')
  };

  enum
  {
    pSeeFiles = FOUR_CHAR_CODE('prvr'),
    pSeeFolders = FOUR_CHAR_CODE('prvs'),
    pMakeChanges = FOUR_CHAR_CODE('prvw')
  };

  enum
  {
    pSmallIcon = FOUR_CHAR_CODE('smic'),
    pSmallButton = FOUR_CHAR_CODE('smbu'),
    pLargeButton = FOUR_CHAR_CODE('lgbu'),
    pGrid = FOUR_CHAR_CODE('grid')
  };

  enum
  {
    enumViewBy = FOUR_CHAR_CODE('vwby'),
    enumGestalt = FOUR_CHAR_CODE('gsen'),
    enumConflicts = FOUR_CHAR_CODE('cflc'),
    enumExistingItems = FOUR_CHAR_CODE('exsi'),
    enumOlderItems = FOUR_CHAR_CODE('oldr')
  };

  enum
  {
    enumDate = FOUR_CHAR_CODE('enda'),
    enumAnyDate = FOUR_CHAR_CODE('anyd'),
    enumToday = FOUR_CHAR_CODE('tday'),
    enumYesterday = FOUR_CHAR_CODE('yday'),
    enumThisWeek = FOUR_CHAR_CODE('twek'),
    enumLastWeek = FOUR_CHAR_CODE('lwek'),
    enumThisMonth = FOUR_CHAR_CODE('tmon'),
    enumLastMonth = FOUR_CHAR_CODE('lmon'),
    enumThisYear = FOUR_CHAR_CODE('tyer'),
    enumLastYear = FOUR_CHAR_CODE('lyer'),
    enumBeforeDate = FOUR_CHAR_CODE('bfdt'),
    enumAfterDate = FOUR_CHAR_CODE('afdt'),
    enumBetweenDate = FOUR_CHAR_CODE('btdt'),
    enumOnDate = FOUR_CHAR_CODE('ondt')
  };

  enum
  {
    enumAllDocuments = FOUR_CHAR_CODE('alld'),
    enumFolders = FOUR_CHAR_CODE('fold'),
    enumAliases = FOUR_CHAR_CODE('alia'),
    enumStationery = FOUR_CHAR_CODE('stat')
  };

  enum
  {
    enumWhere = FOUR_CHAR_CODE('wher'),
    enumAllLocalDisks = FOUR_CHAR_CODE('aldk'),
    enumAllRemoteDisks = FOUR_CHAR_CODE('ardk'),
    enumAllDisks = FOUR_CHAR_CODE('alld'),
    enumAllOpenFolders = FOUR_CHAR_CODE('aofo')
  };

  enum
  {
    enumIconSize = FOUR_CHAR_CODE('isiz'),
    enumSmallIconSize = pSmallIcon,
    enumMiniIconSize = FOUR_CHAR_CODE('miic'),
    enumLargeIconSize = FOUR_CHAR_CODE('lgic')
  };

  enum
  {
    enumSortDirection = FOUR_CHAR_CODE('sodr'),
    enumSortDirectionNormal = FOUR_CHAR_CODE('snrm'),
    enumSortDirectionReverse = FOUR_CHAR_CODE('srvs')
  };

  enum
  {
    enumArrangement = FOUR_CHAR_CODE('earr')
  };

  enum
  {
    enumInfoWindowPanel = FOUR_CHAR_CODE('ipnl'),
    enumGeneralPanel = FOUR_CHAR_CODE('gpnl'),
    enumSharingPanel = FOUR_CHAR_CODE('spnl'),
    enumStatusNConfigPanel = FOUR_CHAR_CODE('scnl'),
    enumFontsPanel = FOUR_CHAR_CODE('fpnl'),
    enumMemoryPanel = FOUR_CHAR_CODE('mpnl')
  };

  enum
  {
    enumPrefsWindowPanel = FOUR_CHAR_CODE('pple'),
    enumPrefsGeneralPanel = FOUR_CHAR_CODE('pgnp'),
    enumPrefsLabelPanel = FOUR_CHAR_CODE('plbp'),
    enumPrefsIconViewPanel = FOUR_CHAR_CODE('pivp'),
    enumPrefsButtonViewPanel = FOUR_CHAR_CODE('pbvp'),
    enumPrefsListViewPanel = FOUR_CHAR_CODE('plvp')
  };

  enum
  {
    typeIconFamily =
        cIconFamily,
    typeIconAndMask = FOUR_CHAR_CODE('ICN#'),
    type8BitMask = FOUR_CHAR_CODE('l8mk'),
    type32BitIcon = FOUR_CHAR_CODE('il32'),
    type8BitIcon = FOUR_CHAR_CODE('icl8'),
    type4BitIcon = FOUR_CHAR_CODE('icl4'),
    typeSmallIconAndMask = FOUR_CHAR_CODE('ics#'),
    typeSmall8BitMask = FOUR_CHAR_CODE('s8mk'),
    typeSmall32BitIcon = FOUR_CHAR_CODE('is32'),
    typeSmall8BitIcon = FOUR_CHAR_CODE('ics8'),
    typeSmall4BitIcon = FOUR_CHAR_CODE('ics4'),
    typeRelativeTime = FOUR_CHAR_CODE('rtim'),
    typeConceptualTime = FOUR_CHAR_CODE('timc')
  };

  enum
  {
    keyIconAndMask = FOUR_CHAR_CODE('ICN#'),
    key32BitIcon = FOUR_CHAR_CODE('il32'),
    key8BitIcon = FOUR_CHAR_CODE('icl8'),
    key4BitIcon = FOUR_CHAR_CODE('icl4'),
    key8BitMask = FOUR_CHAR_CODE('l8mk'),
    keySmallIconAndMask = FOUR_CHAR_CODE('ics#'),
    keySmall8BitIcon = FOUR_CHAR_CODE('ics8'),
    keySmall4BitIcon = FOUR_CHAR_CODE('ics4'),
    keySmall32BitIcon = FOUR_CHAR_CODE('is32'),
    keySmall8BitMask = FOUR_CHAR_CODE('s8mk'),
    keyMini1BitMask = FOUR_CHAR_CODE('icm#'),
    keyMini4BitIcon = FOUR_CHAR_CODE('icm4'),
    keyMini8BitIcon = FOUR_CHAR_CODE('icm8'),
    keyAEUsing = FOUR_CHAR_CODE('usin'),
    keyAEReplacing = FOUR_CHAR_CODE('alrp'),
    keyAENoAutoRouting = FOUR_CHAR_CODE('rout'),
    keyLocalPositionList = FOUR_CHAR_CODE('mvpl'),
    keyGlobalPositionList = FOUR_CHAR_CODE('mvpg'),
    keyRedirectedDocumentList = FOUR_CHAR_CODE('fpdl')
  };

  enum
  {
    keyASPrepositionHas = FOUR_CHAR_CODE('has '),
    keyAll = FOUR_CHAR_CODE('kyal'),
    keyOldFinderItems = FOUR_CHAR_CODE('fsel')
  };

  enum
  {
    formAlias = typeAlias,
    formCreator = pFileCreator
  };

  enum
  {
    errFinderIsBusy = -15260,
    errFinderWindowNotOpen = -15261,
    errFinderCannotPutAway = -15262,
    errFinderWindowMustBeIconView = -15263,
    errFinderWindowMustBeListView = -15264,
    errFinderCantMoveToDestination = -15265,
    errFinderCantMoveSource = -15266,
    errFinderCantOverwrite = -15267,
    errFinderIncestuousMove = -15268,
    errFinderCantMoveToAncestor =
        -15269,
    errFinderCantUseTrashedItems = -15270,
    errFinderItemAlreadyInDest = -15271,
    errFinderUnknownUser = -15272,
    errFinderSharePointsCantInherit = -15273,
    errFinderWindowWrongType = -15274,
    errFinderPropertyNowWindowBased = -15275,
    errFinderAppFolderProtected =
        -15276,
    errFinderSysFolderProtected =
        -15277,
    errFinderBoundsWrong = -15278,
    errAEValueOutOfRange = -15279,
    errFinderPropertyDoesNotApply = -15280,
    errFinderFileSharingMustBeOn = -15281,
    errFinderMustBeActive = -15282,
    errFinderVolumeNotFound =
        -15283,
    errFinderLockedItemsInTrash =
        -15284,
    errFinderOnlyLockedItemsInTrash =
        -15285,
    errFinderProgramLinkingMustBeOn = -15286,
    errFinderWindowMustBeButtonView = -15287,
    errFinderBadPackageContents =
        -15288,
    errFinderUnsupportedInsidePackages =
        -15289,
    errFinderCorruptOpenFolderList =
        -15290,
    errFinderNoInvisibleFiles =
        -15291,
    errFinderCantDeleteImmediately =
        -15292,
    errFinderLastReserved = -15379
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

#endif
