/** @file */

#include "FileOutput.h"

void FileOutput::newFile(std::string filename){
	wav.writeFile(filename.wav)

}

void FileOutput::exportCSV(std::string filename, std::vector<metadata_chunk> metadata, ){
	std::ofstream file;
	file.open ("audio_data.csv");
	file << "Audio Data\n";
	file << "Technical Information, Metadata\n";
	file << "Sample Rates
} 
