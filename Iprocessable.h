/** @file */
#ifndef IPROCESSABLE_H
#define IPROCESSABLE_H

/**
 * Interface which provides functions needed to process wav files
 */
class Iprocessable{

public:
	
	/**
	 * Method that can be inherited to Echo, Normalization, and NoiseGate. Allows each class to process the given Wav File. Overload for 8 bit files. 
	 * @param buffer - an array of unsigned chars constituting the audio data
	 * @param size - an integer size of the buffer
	 * @return - a processed array of unsigned chars
	 */
	virtual unsigned char* processBuffer(unsigned char* buffer, int size) = 0;
	
	/**
	 * Method that can be inherited to Echo, Normalization, and NoiseGate. Allows each class to process the given Wav File. Overload for 16 bit files.
	 * @param buffer - an array of shorts constituting the audio data
	 * @param size - an integer size of the buffer
	 * @return - a processed array of shorts
	 */
	virtual short* processBuffer(short* buffer, int size) = 0;
};

#endif //IPROCESSABLE_H
