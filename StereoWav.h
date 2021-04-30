/** @file */
#ifndef GROUP_PROJECT_STEREOWAV_H
#define GROUP_PROJECT_STEREOWAV_H

#include "Wav.h"

/**
 * A class for storing the data from a stereo wav file
 */
template <typename T>
class StereoWav : public Wav<T> {

	/**
 	 * A T array storing one channel of the audio data of the wav
 	 */
	T* bufferOne = nullptr;

	/**
 	 * A T array storing the second channel of the audio data of the wav
 	 */
	T* bufferTwo = nullptr;
};

#endif //GROUP_PROJECT_STEREOWAV_H
