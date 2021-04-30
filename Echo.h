/** @file */
#ifndef GROUP_PROJECT_ECHO_H
#define GROUP_PROJECT_ECHO_H

#include "Iprocessable.h"

/**
 * A const float giving the level of echos
 */
const float echoLevel = 0.5f;

/**
 * A const float giving the factor to scale audio by
 */
const float scaleFactor = 0.5f;

/**
 * A class for applying an echo
 */
class Echo : public Iprocessable{

	/**
 	 * An int storing the delay in bytes for the echo
 	 */
	int delay;
public:

	/**
	 * A parameterized constructor setting delay
	 * @param delay - The value to set delay to 
	 */
	Echo(int delay);

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

#endif //GROUP_PROJECT_ECHO_H
