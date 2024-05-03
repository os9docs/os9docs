# Mac OS 9 API Documentation

Docs generated from the header files that were given for developers wanting to develop for Classic Mac OS. It's actually so recent that it's not even for Classic Mac OS; it's for Carbon developers. However, the functions that were removed in Carbon were left in, making it suitable for 9.2.2.

The focus of this documentation is the last version of classic Mac OS. Certain functions may be usable on older versions, however the target here is OS 9.2.2 development. I am, however, considering finding out what functions were removed between 6.0 and 9.2 and adding them while marking them as removed.

Additional documentation was scraped and provided from THINK Reference 2.0, although due to a bug in the program, it would not be possible to fully scrape the program as trying to print pages with images to PDFs causes an invalid memory read (yes, this has been replicated as far back as System 6, as far as I can tell this is a bug with the actual program). The solution would be to reverse engineer the format that THINK Reference uses (which one might be tempted to tell me is already reverse engineered, but actually, TR 2.0 uses a different version of that file format, that the existing tools cannot read).

Functions from TR 2.0 that are not documented are listed [here](https://github.com/os9docs/thinkpdfs/issues/1).

[Source code avaliable here.](https://github.com/IoIxD/macdocs)

@defgroup AppleTalk
@defgroup AppleDisk
@defgroup AppleGuide
@defgroup AppleEvent
@defgroup AppleScript
@defgroup AppleTypeServices
@defgroup CommunicationsToolbox
@defgroup CoreGraphics
@defgroup Color
@defgroup ColorSync
@defgroup FileFormats
@defgroup OpenTransport
@defgroup Misc
@defgroup Managers
@defgroup Hardware
@defgroup QuickTime
@defgroup Networking
@defgroup File
@defgroup Font
@defgroup QuickDraw
@defgroup QuickDraw3D
@defgroup Keychain
@defgroup System
@defgroup Multiprocessing
@defgroup OpenScriptingArchitecture
@defgroup RAVE
@defgroup Translation
@defgroup Time
@defgroup Sprockets
@defgroup Math
@defgroup MovedFiles

@ref Topics "List of topics"
