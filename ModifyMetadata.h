/** @file */
#ifndef MODIFY_METADATA_H
#define MODIFY_METADATA_H

#include "Wav.h"
#include <vector>
#include <string>
/**
 * A const array of 4 bytes holding "LIST" for the metadata header
 */
const char listArr[4] = {'L','I','S','T'};
/**
 * A const array of 4 bytes holding "INFO" for the metadata header
 */
const char infoArr[4] = {'I','N','F','O'};

/**
 * A class for modifying metadata
 */
class ModifyMetadata{
public:
	/**
 	 * A method that modifies the metadata of a wav object and then calls a method from file output to write the changes to a file
 	 * @param wav - a pointer to a wav object that is having its metadata modified
 	 * @param metadataIDs - a vector of strings each of which is an ID for a metadata entry
 	 * @param metadata - a vector of strings each of which is the data for a metadata entry corresponding to an ID in metadataIDs
 	 */
	void modifyMetadata(Wav* wav, std::vector <std::string> metadataIDs, std::vector <std::string> metadata);
};

#endif //MODIFY_METADATA_H