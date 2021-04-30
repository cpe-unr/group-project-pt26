/** @file */
#ifndef GROUP_PROJECT_MONOWAV_H
#define GROUP_PROJECT_MONOWAV_H

#include "Wav.h"

/**
 * A class for storing the data from a mono wav file
 */
template <typename T>
class MonoWav : public Wav<T> {

	/**
 	 * A T array storing the audio data of the wav
 	 */
	T* buffer = nullptr;
};

#endif //GROUP_PROJECT_MONOWAV_H
