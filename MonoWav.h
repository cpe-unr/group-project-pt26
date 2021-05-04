/** @file */
#ifndef GROUP_PROJECT_MONOWAV_H
#define GROUP_PROJECT_MONOWAV_H

#include "Wav.h"

/**
 * A class for storing the data from a mono wav file
 */
template <typename T>
class MonoWav : public Wav {
	/**
 	 * A T array storing the audio data of the wav
 	 */
	T* buffer = nullptr;
public:
	T *getBuffer() const {
		return buffer;
	}

	MonoWav() = default;

	MonoWav(std::string filename, wav_header waveHeader, metadata_header metadataHeader, std::vector<metadata_chunk> metadata, T* buffer) : Wav(filename, waveHeader, metadataHeader, metadata), buffer(buffer) {}
};

#endif //GROUP_PROJECT_MONOWAV_H
