/** @file */
#include "Wav.h"

	template <typename T>
	std::vector<metadata_chunk> Wav<T>::getMetadata() const {
		return metadata;
	}

	template <typename T>
	void Wav<T>::setMetadataHeader(metadata_header newHeader){
		metadataHeader = newHeader;
	}

	template <typename T>
	void Wav<T>::setMetadata(std::vector<metadata_chunk> newMetadata){
		metadata = newMetadata;
	}