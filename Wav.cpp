/** @file */
#include "Wav.h"

	std::vector<metadata_chunk> Wav::getMetadata(){
		return metadata;
	}
	void Wav::setMetadataHeader(metadata_header newHeader){
		metadataHeader = newHeader;
	}
	void Wav::setMetadata(std::vector<metadata_chunk> newMetadata){
		metadata = newMetadata;
	}