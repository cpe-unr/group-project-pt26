/** @file */
#ifndef GROUP_PROJECT_NOISEGATE_H
#define GROUP_PROJECT_NOISEGATE_H

#include "Iprocessable.h"

/**
 * A class for applying a noise gate
 */
class NoiseGate : public Iprocessable{

	/**
	 * A float storing the percentage of the max distance from zero which is the threshold for noise gating
	 */
	float thresholdPercent;
public:

	/**
	 * A parameterized constructor setting thresholdPercent
	 * @param thresholdPercent - The value to set thresholdPercent to 
	 */
	NoiseGate(float thresholdPercent);

	/**
	 * Method that can be inherited to Echo, Normalization, and NoiseGate. Allows each class to process the given Wav File. Overload for 8 bit files. 
	 * @param buffer - an array of unsigned chars constituting the audio data
	 * @param size - an integer size of the buffer
	 * @return - a processed array of unsigned chars
	 */
	unsigned char* processBuffer(unsigned char* buffer, int size)  override;

	/**
	 * Method that can be inherited to Echo, Normalization, and NoiseGate. Allows each class to process the given Wav File. Overload for 8 bit files. 
	 * @param buffer - an array of shorts constituting the audio data
	 * @param size - an integer size of the buffer
	 * @return - a processed array of shorts
	 */
	short* processBuffer(short* buffer, int size) override;
};

#endif //GROUP_PROJECT_NOISEGATE_H
