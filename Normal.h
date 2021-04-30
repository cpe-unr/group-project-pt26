/** @file */
#ifndef GROUP_PROJECT_NORMAL_H
#define GROUP_PROJECT_NORMAL_H

#include "Iprocessable.h"

/**
 * A class for applying a normalization
 */
class Normal : public Iprocessable{
public:

	/**
	 * Method that can be inherited to Echo, Normalization, and NoiseGate. Allows each class to process the given Wav File. Overload for 8 bit files. 
	 * @param buffer - an array of unsigned chars constituting the audio data
	 * @param size - an integer size of the buffer
	 * @return - a processed array of unsigned chars
	 */
	unsigned char* processBuffer(unsigned char* buffer, int size) override;

	/**
	 * Method that can be inherited to Echo, Normalization, and NoiseGate. Allows each class to process the given Wav File. Overload for 8 bit files. 
	 * @param buffer - an array of unsigned chars constituting the audio data
	 * @param size - an integer size of the buffer
	 * @return - a processed array of unsigned chars
	 */
	short* processBuffer(short* buffer, int size) override;
};

#endif //GROUP_PROJECT_NORMAL_H
