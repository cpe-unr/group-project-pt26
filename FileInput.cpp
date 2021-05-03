/** @file */

#include "FileInput.h"

FileInput::FileInput(const std::string& folder){}

void FileInput::readFiles(const std::string& folder){
//read through folder and store each file in object
	
	DIR* dir = opendir(".");
	if(!dir){
		return;
	}

	struct dirent *entity;
	entity = readdir(dir);
	
	while(entity != NULL){
		entity->d_name = filename;
		
		FileInput monoObj;//object that holds all the info for files
		FileInput stereoObj;		
		std::ifstream fin(filename, std::ios::binary | std::ios::in);
		if(fin.is_open()){
			//extract technical info including metadata and put into object
			//doesn't inclue metadata as of now
			file.read((char*)&waveHeader, sizeof(wav_header));

			//if filename contains "mono" add to monoObj
			if(waveHeader.num_channels == 1){
				monoObj = new unsigned char[waveHeader.data_bytes];
        		file.read((char*)buffer, waveHeader.data_bytes);
			}

			//if filename contains "stereo" add to stereoObj
			if(waveHeader.num_channels == 2){
				stereoObj = new unsigned char[waveHeader.data_bytes];
        		file.read((char*)buffer, waveHeader.data_bytes);
			}
			//delete sound file data from heap
			fin.close();	
		}
	}	
	closedir(dir);
}
