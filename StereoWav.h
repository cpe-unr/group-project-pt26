/** @file */
#ifndef GROUP_PROJECT_STEREOWAV_H
#define GROUP_PROJECT_STEREOWAV_H

#include "Wav.h"

/**
 * A class for storing the data from a stereo wav file
 */
template <typename T>
class StereoWav : public Wav {

	/**
 	 * A T array storing one channel of the audio data of the wav
 	 */
	T* bufferOne = nullptr;

	/**
 	 * A T array storing the second channel of the audio data of the wav
 	 */
	T* bufferTwo = nullptr;

public:
	T *getBufferOne() const {
		return bufferOne;
	}
	
	T *getBufferTwo() const {
		return bufferTwo;
	}


	StereoWav() = default;

	StereoWav(std::string filename, wav_header waveHeader, metadata_header metadataHeader, std::vector<metadata_chunk> metadata, T* bufferOne, T* bufferTwo) : Wav(filename, waveHeader, metadataHeader, metadata), bufferOne(bufferOne), bufferTwo(bufferTwo) {}

};

#endif //GROUP_PROJECT_STEREOWAV_H
