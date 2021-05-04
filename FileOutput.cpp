/** @file */

#include "FileOutput.h"

void FileOutput::newFile(std::string filename){
	wav.writeFile(filename.wav)

}

void FileOutput::exportCSV(std::string filename, std::vector<metadata_chunk> metadata, FileInput stereoObj, FileInput monoObj){
	std::ofstream file;
	file.open ("audio_data.csv");
	file << "Audio Data\n";
	file << filename << "\n";
	file << "Technical Information," << stereoObj << "," << monoObj << "\n"; 
	file << "Metadata,";
	for(std::vector<metadata_chunk>::iterator it = metadata.begin(); it != metadata.end(); ++it){
		file << metadata[it] << ",";
	}
	file.close;
} 

void FileOutput::createNewMetadataFile(std::vector<metadata_chunk> metadata){

}
