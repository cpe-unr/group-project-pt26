/** @file */
#ifndef WAV_H
#define WAV_H

#include "MetadataChunk.h"
#include "MetadataHeader.h"
#include "WaveHeader.h"
#include <vector>
#include <string>

/**
 * A base class for wavs
 */
class Wav{
protected:
	std::string filename;

	wav_header waveHeader;
	/**
 	 * The metadata header info
 	 */
	metadata_header metadataHeader;
	/**
 	 * A vector of metadata subchunks
	 */
	std::vector<metadata_chunk> metadata;
public:
	Wav() = default;

	Wav(std::string filename, wav_header waveHeader, metadata_header metadataHeader, std::vector<metadata_chunk> metadata);

	wav_header getWaveHeader() const;

	std::string getFilename() const;

	metadata_header getMetadataHeader() const;
	/**
 	 * A getter for the metadata
	 */
	std::vector<metadata_chunk> getMetadata() const;
	/**
 	 * A setter for the metadata header
 	 * @param newHeader - the new metadata header to set the metadata header to
	 */
	void setMetadataHeader(metadata_header newHeader);
	/**
 	 * A setter for the metadata
 	 * @param newMetadata - the new metadata to set the metadata to
	 */
	void setMetadata(std::vector<metadata_chunk> newMetadata);
};

#endif //WAV_H