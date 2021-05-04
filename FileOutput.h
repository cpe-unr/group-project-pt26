/** @file */

#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include "ModifyMetadata.h"
#include "MetadataChunk.h"
#include "WaveHeader.h"
#include "Wav.h"
#include "MonoWav.h"
#include "StereoWav.h"

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
	 * @param filename - takes filename so as to overwrite file with new name
	 */
	//void newFile(std::string filename);
	void writeFile(std::string folder, std::string filename, Wav* wav);
	/**
	 * A method that takes all technical information and metadata of files and exports them into a CSV file
	 * @param filename - the file name to be put into the CSV
	 * @param metadata - metadata that is to be put into CSV
	 * @param stereoObj - the object holding all technical info for the stereo wav file
	 * @param monnObj - the object holding all technical info for the mono wav file
	 */
	//void exportCSV(std::string filename, std::vector<metadata_chunk> metadata, FileInput stereoObj, FileInput monoObj);

	/**
	 * A method that saves the file with new metadata added. Overrides existing metadata.
	 * @param metadata - metadata that will be put into the new metadata file
	 */
	//void createNewMetadataFile(std::vector<metadata_chunk> metadata);
};

#endif //FILEOUTPUT_H
