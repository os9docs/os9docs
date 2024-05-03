/**
	 \file       AIFF.h

	\brief   Definition of AIFF file format components.

	\introduced_in  System 8.5
	\avaliable_from Universal Interfaces 3.4.1

	\copyright � 1989-2001 by Apple Computer, Inc., all rights reserved.

	\ingroup FileFormats

	For bug reports, consult the following page on
				 the World Wide Web:

					 http://developer.apple.com/bugreporter/

*/
#ifndef __AIFF__
#define __AIFF__

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
		AIFFID = FOUR_CHAR_CODE('AIFF'),
		AIFCID = FOUR_CHAR_CODE('AIFC'),
		FormatVersionID = FOUR_CHAR_CODE('FVER'),
		CommonID = FOUR_CHAR_CODE('COMM'),
		FORMID = FOUR_CHAR_CODE('FORM'),
		SoundDataID = FOUR_CHAR_CODE('SSND'),
		MarkerID = FOUR_CHAR_CODE('MARK'),
		InstrumentID = FOUR_CHAR_CODE('INST'),
		MIDIDataID = FOUR_CHAR_CODE('MIDI'),
		AudioRecordingID = FOUR_CHAR_CODE('AESD'),
		ApplicationSpecificID = FOUR_CHAR_CODE('APPL'),
		CommentID = FOUR_CHAR_CODE('COMT'),
		NameID = FOUR_CHAR_CODE('NAME'),
		AuthorID = FOUR_CHAR_CODE('AUTH'),
		CopyrightID = FOUR_CHAR_CODE('(c) '),
		AnnotationID = FOUR_CHAR_CODE('ANNO')
	};

	enum
	{
		NoLooping = 0,
		ForwardLooping = 1,
		ForwardBackwardLooping = 2
	};

	enum
	{
		// AIFF-C Versions   AIFCVersion1 = (long)0xA2805140
	};

// Compression Names #define NoneName "\pnot compressed"
// Compression Names
#define ACE8to3Name "\pACE 8-to-3"
#define MACE3to1Name "\pMACE 3-to-1"
#define MACE6to1Name "\pMACE 6-to-1"
	enum
	{
		/** Types */
		NoneType = FOUR_CHAR_CODE('NONE')
			ACE2Type = FOUR_CHAR_CODE('ACE2'),
		// Compression Types
		MACE3Type = FOUR_CHAR_CODE('MAC3'),
		MACE6Type = FOUR_CHAR_CODE('MAC6')
	};

	typedef unsigned long ID;
	typedef short MarkerIdType;
	/**
	<pre>The ckID field specifies the chunk type. An ID is a 32-bit concatenation of any
	four printable ASCII characters in the range ' ' (space character, ASCII value
	0x20) through '~' (ASCII value 0x7E). Spaces cannot precede printing
	characters, but trailing spaces are allowed. Control characters are not allowed.
	You can specify values for the other types of chunks by using these constants:
	ApplicationSpecificID chunk ID for ApplicationSpecificChunk
	AudioRecordingID chunk ID for AudioRecordingChunk
	CommentID chunk ID for CommentsChunk
	FORMID chunk ID for ContainerChunk
	FormatVersionID chunk ID for FormatVersionChunk
	CommonID chunk ID for CommonChunk and ExtCommonChunk
	InstrumentID chunk ID for InstrumentChunk
	MarkerID chunk ID for MarkerChunk
	MIDIDataID chunk ID for MIDIDataChunk
	SoundDataID chunk ID for SoundDataChunk
	NameID chunk ID's for TextChunk
	AuthorID
	CopyrightID
	AnnotationID
	The ckSize field specifies the size of the data portion of a chunk and does not
	include the length of the chunk header information.
	</pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ChunkHeader
	{
		IDckID;		 /**< chunk type ID*/
		long ckSize; /**< number of bytes of data*/
	} ChunkHeader;	 /**< */

	typedef struct ChunkHeader ChunkHeader;
	/**
	<pre>The fields of this chunk have the following meanings:
	<table><tbody>
	<tr>
		<td>ckID</td>
		<td><pre>The ID of this chunk. For a Form Chunk, this ID is
	'FORM'.
		</pre></td>
	</tr>

	<tr>
		<td>ckSize</td>
		<td><pre>The size of the data portion of this chunk. Note that the
	portion of a Form Chunk is divided into two parts,
	 and the chunks that follow the formType field.
	chunks are called local chunks because their chunk
	are local to the Form Chunk.
		</pre></td>
	</tr>

	<tr>
		<td>formType</td>
		<td><pre>The type of audio file. For AIFF files, formType is 'AIFF'.
	AIFF-C files, formType is 'AIFC'.
	local chunks can occur in any order in a sound file. As a result, your
	should be designed to get a local chunk, identify it, and then process
	without making any assumptions about what kind of chunk it is based on its
	in the Form Chunk.
	Reference © 1991-1992 Symantec Corporation
		</pre></td>
	</tr>
	</tbody></table>*/
	struct ContainerChunk
	{
		ID ckID;	  /**<   chunk type ID*/
		long ckSize;  /**<   number of bytes of data*/
		ID formType;  /**<   type of file*/
	} ContainerChunk; /**< */

	typedef struct ContainerChunk ContainerChunk;
	/**
	<pre>The fields of this chunk have the following meanings:
	<table><tbody>
	<tr>
		<td>ckID</td>
		<td><pre>The ID of this chunk. For a FormatVersionChunk , this
	is 'FVER'.
		</pre></td>
	</tr>

	<tr>
		<td>ckSize</td>
		<td><pre>The size of the data portion of this chunk. This value is
	4 in a FormatVersionChunk because the
	field is 4 bytes long (the 8 bytes used by ckID
	ckSize fields are not included).
		</pre></td>
	</tr>

	<tr>
		<td>timestamp</td>
		<td><pre>An indication of when the format version for this kind of
	was created. The value indicates the number of seconds
	January 1, 1904, following the normal time
	used by the Macintosh Operating System. (See
	Operating System Utilities for several routines
	allow you to manipulate timestamps.)
	should not confuse the format version timestamp with the creation date of
	file. The format version timestamp indicates the time of creation of the
	of the format according to which this file is structured. Because Apple
	the formats of AIFF-C files, only Apple can change this value. The
	version is defined by a constant:
	//2726318400 in decimal
	Reference © 1991-1992 Symantec Corporation
		</pre></td>
	</tr>
	</tbody></table>*/
	struct FormatVersionChunk
	{
		ID ckID;				 /**<  'FVER'*/
		long ckSize;			 /**<  */
		unsigned long timestamp; /**<  date*/
	} FormatVersionChunk;		 /**< */

	typedef struct FormatVersionChunk FormatVersionChunk;
	typedef FormatVersionChunk *FormatVersionChunkPtr;
	/**
	<pre>The fields that exist in the CommonChunk  and the ExtCommonChunk have
	the following meanings:
	<table><tbody>
	<tr>
		<td>ckID</td>
		<td><pre>The ID of this chunk. For a CommonChunk , this
	is 'COMM'.
		</pre></td>
	</tr>

	<tr>
		<td>ckSize</td>
		<td><pre>The size of the data portion of this chunk. In AIFF
	this field is always 18 in the
	 because the 8 bytes used by the
	and ckSize fields are not included. In AIFF-C
	this size is 22 plus the number of bytes in
	compressionName string.
		</pre></td>
	</tr>

	<tr>
		<td>numChannels</td>
		<td><pre>The number of audio channels contained in the
	sound. A value of 1 indicates monophonic
	2 indicates stereo sound; 4 indicates
	sound, etc. You can use any number of
	channels . The actual sound data is stored
	in the Sound Data Chunk .
		</pre></td>
	</tr>

	<tr>
		<td>numSampleFrames</td>
		<td><pre>The number of sample frames in the
	Data Chunk . Note that this field contains
	number of sample frames, not the number of
	of data and not the number of sample points.
	noncompressed sound data, the total number of
	points in the file is numChannels *
	. (See the
	Data Chunk for a definition of a sample
	frame.)
	The number of bits in each sample point of
	sound data. The sampleSize field can
	any integer from 1 to 32. For compressed
	data, this field indicates the number of bits
	sample in the original sound data, before
	compression.
		</pre></td>
	</tr>

	<tr>
		<td>sampleRate</td>
		<td><pre>The sample rate at which the sound is to be played
	in sample frames per second.
	Reference © 1991-1992 Symantec Corporation
		</pre></td>
	</tr>
	</tbody></table>*/
	struct CommonChunk
	{
		ID ckID;			  /**< 'COMM'*/
		long ckSize;		  /**< size of chunk data*/
		short numChannels;	  /**< number of channels*/
		long numSampleFrames; /**< number of sample frames*/
		short sampleSize;	  /**< number of bits per sample*/
		Extended sampleRate;  /**< number of frames per second*/
	} CommonChunk;			  /**< */

	typedef struct CommonChunk CommonChunk;
	typedef CommonChunk *CommonChunkPtr;
	/**
	<pre>The fields that exist in the CommonChunk  and the ExtCommonChunk have
	the following meanings:
	<table><tbody>
	<tr>
		<td>ckID</td>
		<td><pre>The ID of this chunk. For a CommonChunk , this
	is 'COMM'.
		</pre></td>
	</tr>

	<tr>
		<td>ckSize</td>
		<td><pre>The size of the data portion of this chunk. In AIFF
	this field is always 18 in the
	 because the 8 bytes used by the
	and ckSize fields are not included. In AIFF-C
	this size is 22 plus the number of bytes in
	compressionName string.
		</pre></td>
	</tr>

	<tr>
		<td>numChannels</td>
		<td><pre>The number of audio channels contained in the
	sound. A value of 1 indicates monophonic
	2 indicates stereo sound; 4 indicates
	sound, etc. You can use any number of
	channels . The actual sound data is stored
	in the Sound Data Chunk .
		</pre></td>
	</tr>

	<tr>
		<td>numSampleFrames</td>
		<td><pre>The number of sample frames in the
	Data Chunk . Note that this field contains
	number of sample frames, not the number of
	of data and not the number of sample points.
	noncompressed sound data, the total number of
	points in the file is numChannels *
	. (See the
	Data Chunk for a definition of a sample
	frame.)
	The number of bits in each sample point of
	sound data. The sampleSize field can
	any integer from 1 to 32. For compressed
	data, this field indicates the number of bits
	Reference © 1991-1992 Symantec Corporation
		</pre></td>
	</tr>
	</tbody></table>*/
	struct ExtCommonChunk
	{
		ID ckID;			  /**< 'COMM'*/
		long ckSize;		  /**< size of chunk data*/
		short numChannels;	  /**< number of channels*/
		long numSampleFrames; /**< number of sample frames*/
		short sampleSize;	  /**< number of bits per sample*/
		Extended sampleRate;  /**< number of frames per second*/
		ID compressionType;	  /**< compression type ID*/
		char compressionName; /**< compression type name*/
	} ExtCommonChunk;		  /**< */

	typedef struct ExtCommonChunk ExtCommonChunk;
	typedef ExtCommonChunk *ExtCommonChunkPtr;
	/**
	<pre>The fields in a Sound Data Chunk have the following meanings:
	<table><tbody>
	<tr>
		<td>ckID</td>
		<td><pre>The ID of this chunk. For a SoundDataChunk , this ID is
	'SSND'.
		</pre></td>
	</tr>

	<tr>
		<td>ckSize</td>
		<td><pre>The size of the data portion of this chunk. This size does not
	the 8 bytes occupied by the values in the ckID and the
	fields. If the data following the blockSize field
	an odd number of bytes, a pad byte with a value of 0
	added at the end to preserve an even length for this chunk.
	there is a pad byte, it is not included in the ckSize field.
		</pre></td>
	</tr>

	<tr>
		<td>offset</td>
		<td><pre>An offset (in bytes) to the beginning of the first sample
	in the chunk data. Most applications do not need to use
	offset field and should set it to 0.
		</pre></td>
	</tr>

	<tr>
		<td>blockSize</td>
		<td><pre>The size (in bytes) of the blocks to which the sound data is
	This field is used in conjunction with the offset field
	aligning sound data to blocks. As with the offset field,
	applications do not need to use the blockSize field and
	set it to 0.
	Reference © 1991-1992 Symantec Corporation
		</pre></td>
	</tr>
	</tbody></table>*/
	struct SoundDataChunk
	{
		ID ckID;		/**< 'SSND'*/
		long ckSize;	/**< size of chunk data*/
		long offset;	/**< offset to sound data*/
		long blockSize; /**< nsize of alignment blocks*/
	} SoundDataChunk;	/**< */

	typedef struct SoundDataChunk SoundDataChunk;
	typedef SoundDataChunk *SoundDataChunkPtr;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct Marker
	{
		MarkerIDType id;		/**<  */
		unsigned long position; /**<  */
		Str markerName;			/**<  */
	} Marker;					/**< */

	typedef struct Marker Marker;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct MarkerChunk
	{
		ID ckID;				   /**< */
		long ckSize;			   /**< */
		unsigned short numMarkers; /**< */
		Marker Markers[];		   /**< */
	} MarkerChunk;				   /**< */

	typedef struct MarkerChunk MarkerChunk;
	typedef MarkerChunk *MarkerChunkPtr;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct AIFFLoop
	{
		short playMode;			/**< */
		MarkerIdType beginLoop; /**< */
		MarkerIdType endLoop;	/**< */
	} AIFFLoop;					/**< */

	typedef struct AIFFLoop AIFFLoop;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct InstrumentChunk
	{
		ID ckID;			  /**< */
		long ckSize;		  /**< */
		char baseFrequency;	  /**< */
		char detune;		  /**< */
		char lowFrequency;	  /**< */
		char highFrequency;	  /**< */
		char lowVelocity;	  /**< */
		char highVelocity;	  /**< */
		short gain;			  /**< */
		AIFFLoop sustainLoop; /**< */
		AIFFLoop releaseLoop; /**< */
	} InstrumentChunk;		  /**< */

	typedef struct InstrumentChunk InstrumentChunk;
	typedef InstrumentChunk *InstrumentChunkPtr;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct MIDIDataChunk
	{
		ID ckID;				  /**<  */
		long ckSize;			  /**<  */
		unsigned char MIDIdata[]; /**<  */
	} MIDIDataChunk;			  /**< */

	typedef struct MIDIDataChunk MIDIDataChunk;
	typedef MIDIDataChunk *MIDIDataChunkPtr;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct AudioRecordingChunk
	{
		ID ckID;						 /**< */
		long ckSize;					 /**< */
		unsigned char AEChannelStatus[]; /**< */
	} AudioRecordingChunk;				 /**< */

	typedef struct AudioRecordingChunk AudioRecordingChunk;
	typedef AudioRecordingChunk *AudioRecordingChunkPtr;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct ApplicationSpecificChunk
	{
		ID ckID;					 /**< */
		long ckSize;				 /**< */
		OSType applicationSignature; /**< */
		char data[];				 /**< */
	} ApplicationSpecificChunk;		 /**< */

	typedef struct ApplicationSpecificChunk ApplicationSpecificChunk;
	typedef ApplicationSpecificChunk *ApplicationSpecificChunkPtr;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct Comment
	{
		unsigned long timeStamp; /**< */
		MarkerIDType marker;	 /**< */
		char text[];			 /**< */
	} Comment;					 /**< */

	typedef struct Comment Comment;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct CommentsChunk
	{
		ID ckID;					/**< */
		long ckSize;				/**< */
		unsigned short numComments; /**< */
		Comment comments[];			/**<  */
	} CommentsChunk;				/**< */

	typedef struct CommentsChunk CommentsChunk;
	typedef CommentsChunk *CommentsChunkPtr;
	/**
	<pre>
	 * \copyright THINK Reference © 1991-1992 Symantec Corporation
	*/
	struct TextChunk
	{
		ID ckID;	 /**<  */
		long ckSize; /**<  */
		char text[]; /**<  */
	} TextChunk;	 /**< */

	typedef struct TextChunk TextChunk;
	typedef TextChunk *TextChunkPtr;

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

#endif // __AIFF__ // __AIFF__
