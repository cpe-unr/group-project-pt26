/** @file */
#ifndef WAV_H
#define WAV_H

#include "MetadataChunk.h"
#include "MetadataHeader.h"
#include <vector>

/**
 * A base class for wavs
 */
class Wav{
protected:
	/**
 	 * The metadata header info
 	 */
	metadata_header metadataHeader;
	/**
 	 * A vector of metadata subchunks
	 */
	std::vector<metadata_chunk> metadata;
public:
	/**
 	 * A getter for the metadata
	 */
	std::vector<metadata_chunk> getMetadata();
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