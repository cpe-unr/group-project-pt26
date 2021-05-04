/** @file */
#include "Wav.h"

	Wav::Wav(std::string filename, wav_header waveHeader, metadata_header metadataHeader, std::vector<metadata_chunk> metadata) : filename(filename), waveHeader(waveHeader), metadataHeader(metadataHeader), metadata(metadata){}

	wav_header Wav::getWaveHeader() const {
		return waveHeader;
	}

	metadata_header Wav::getMetadataHeader() const {
		return metadataHeader;
	}

	std::string Wav::getFilename() const{
		return filename;
	}

	std::vector<metadata_chunk> Wav::getMetadata() const {
		return metadata;
	}

	void Wav::setMetadataHeader(metadata_header newHeader){
		metadataHeader = newHeader;
	}

	void Wav::setMetadata(std::vector<metadata_chunk> newMetadata){
		metadata = newMetadata;
	}