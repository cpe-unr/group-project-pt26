/** @file */

#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include "UserInteraction.h"
#include "ModifyMetadata.h"
#include "Metadata_chunk"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class FileOutput{
	std::string filename;
	std::vector<metadata_chunk> metadata;
	

public:
	/**
	 * A method to create a new file from the processed audio.
	 *
	 */
	void newFile(std::string filename);

	/**
	 * A method that takes all technical information and metadata of files and exports them into a CSV file
	 *
	 */
	void exportCSV();

	/**
	 * A method that saves the file with new metadata added. Overrides existing metadata.
	 *
	 */
	void createNewMetadataFile(std::vector<metadata_chunk> metadata);
};

#endif //FILEOUTPUT_H
