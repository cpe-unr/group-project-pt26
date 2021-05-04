/** @file */

#ifndef USERINTERACTION_H
#define USERINTERACTION_H

#include "Wav.h"
#include <iostream>
#include <string>
#include <vector>
/**
 * A class for interacting with the user
 */
class UserInteraction{
	int selection;
	std::vector<Wav*> wavs;
	std::string folder;

public:
	/**
	 * Default Ctor.
	 *
	 */
	UserInteraction();

	UserInteraction(std::vector<Wav*> newWavs, std::string newFolder);
	/**
	 * A method that allows the user to choose what they want to do with their audio files
	 */

	void userSelection();

	/**
	 * A method that asks the user if they wish to modify metadata, then asks for file and calls a method from modifyMetadata to modify given file
	 *
	 */
	void userModify();

	/**
	 * A method that asks the user if they wish to process a file. Asks for file and calls methods from one or more of Echo, Normal, NoiseGate to process the file
	 *
	 */
	void processorType();


	/**
	 * A method that asks user to give a filename for the new file to be saved under. This comes after processing the audio data.
	 * @param: takes in the current filename and changes it to the new one
	 */
	std::string saveFileName(std::string filename);
	
};

#endif //USERINTERACTION_H
