/** @file */

#ifndef IPROCESSABLE_H
#define IPROCESSABLE_H

class Iprocessable{

public:
	/**
	 * Method that can be inherited to Echo, Normalization, and NoiseGate. Allows each class to process the given Wav File.
	 *
	 */
	virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
};

#endif //IPROCESSABLE_H
