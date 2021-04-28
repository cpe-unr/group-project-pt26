/*
*/

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
			//if filename contains "mono" add to monoObj
			//if filename contains "stereo" add to stereoObj
			//delete sound file data from heap

			fin.close();	
		}
	}	
	closedir(dir);
}
