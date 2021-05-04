/** @file */

#include "FileInput.h"
#include <iostream>
FileInput::FileInput(const std::string& folder){}

std::vector<Wav*> FileInput::readFiles(const std::string& folder){
//read through folder and store each file in object
	std::vector<Wav*> newVector;
	DIR* dir = opendir(folder.c_str());
	if(!dir){
		return newVector;
	}

	struct dirent *entity;

	while((entity = readdir(dir)) != NULL){
		wav_header waveHeader;
		metadata_header metadataHeader;
		std::vector<metadata_chunk> metadata;
		if(entity->d_name[0] != '.' && entity->d_name[1] != '.'){ //bad
			std::string name = entity->d_name;
			std::cout << entity->d_name << std::endl;
			std::ifstream file(folder + "/" + entity->d_name, std::ios::binary | std::ios::in);
			if(file.is_open()){
				file.read((char*)&waveHeader, sizeof(wav_header));
				if(waveHeader.num_channels == 1){
					unsigned char* newBuffer = new unsigned char[waveHeader.data_bytes];
					file.read((char*)newBuffer, waveHeader.data_bytes);
					if(waveHeader.bit_depth == 16){
						short* buffer = reinterpret_cast<short*>(newBuffer);
						file.read((char*)&metadataHeader, sizeof(metadata_header));
						int it = 0;
						int chnks = 0;
						while (it < metadataHeader.size - 8) { //bad
							metadata.push_back(metadata_chunk());
							file.read((char*)&metadata[chnks], 8);
							it += 8;
							metadata[chnks].data = new char[metadata[chnks].size];
							file.read((char*)metadata[chnks].data, metadata[chnks].size);
							it += metadata[chnks].size;
							chnks++;
						}
						file.close();
						newVector.push_back(new MonoWav<short>(name, waveHeader, metadataHeader, metadata, buffer));
					}
					else if(waveHeader.bit_depth == 8){
						unsigned char* buffer = reinterpret_cast<unsigned char*>(newBuffer);
						file.read((char*)&metadataHeader, sizeof(metadata_header));
						int it = 0;
						int chnks = 0;
						while (it < metadataHeader.size - 8) { //bad
							metadata.push_back(metadata_chunk());
							file.read((char*)&metadata[chnks], 8);
							it += 8;
							metadata[chnks].data = new char[metadata[chnks].size];
							file.read((char*)metadata[chnks].data, metadata[chnks].size);
							it += metadata[chnks].size;
							chnks++;
						}
						file.close();
						newVector.push_back(new MonoWav<unsigned char>(name, waveHeader, metadataHeader, metadata, buffer));
					}
				}
				else if(waveHeader.num_channels == 2){
					unsigned char* newBuffer = new unsigned char[waveHeader.data_bytes];
					unsigned char* newBufferOne = new unsigned char[waveHeader.data_bytes/2];
					unsigned char* newBufferTwo = new unsigned char[waveHeader.data_bytes/2];
					file.read((char*)newBuffer, waveHeader.data_bytes);
					if(waveHeader.bit_depth == 16){
						short* bufferOne = reinterpret_cast<short*>(newBufferOne);
						short* bufferTwo = reinterpret_cast<short*>(newBufferTwo);
						short* nBuffer = reinterpret_cast<short*>(newBuffer);
						for (int i = 0; i < waveHeader.data_bytes / (4); i++) {
							bufferOne[i] = nBuffer[2*i];
							bufferTwo[i] = nBuffer[2*i+1];
						}
						file.read((char*)&metadataHeader, sizeof(metadata_header));
						int it = 0;
						int chnks = 0;
						while (it < metadataHeader.size - 8) { //bad
							metadata.push_back(metadata_chunk());
							file.read((char*)&metadata[chnks], 8);
							it += 8;
							metadata[chnks].data = new char[metadata[chnks].size];
							file.read((char*)metadata[chnks].data, metadata[chnks].size);
							it += metadata[chnks].size;
							chnks++;
						}
						delete[] nBuffer;
						file.close();
						newVector.push_back(new StereoWav<short>(name, waveHeader, metadataHeader, metadata, bufferOne, bufferTwo));
					}
					else if(waveHeader.bit_depth == 8){
						unsigned char* bufferOne = reinterpret_cast<unsigned char*>(newBufferOne);
						unsigned char* bufferTwo = reinterpret_cast<unsigned char*>(newBufferTwo);
						unsigned char* nBuffer = reinterpret_cast<unsigned char*>(newBuffer);
						for (int i = 0; i < waveHeader.data_bytes / (2); i++) {
							bufferOne[i] = nBuffer[2*i];
							bufferTwo[i] = nBuffer[2*i+1];
						}
						file.read((char*)&metadataHeader, sizeof(metadata_header));
						int it = 0;
						int chnks = 0;
						while (it < metadataHeader.size - 8) { //bad
							metadata.push_back(metadata_chunk());
							file.read((char*)&metadata[chnks], 8);
							it += 8;
							metadata[chnks].data = new char[metadata[chnks].size];
							file.read((char*)metadata[chnks].data, metadata[chnks].size);
							it += metadata[chnks].size;
							chnks++;
						}
						delete[] nBuffer;
						file.close();
						newVector.push_back(new StereoWav<unsigned char>(name, waveHeader, metadataHeader, metadata, bufferOne, bufferTwo));
					}
				}
			}
		}	
	}//nvm this is all bad; this is truly the worst code ive ever written
	closedir(dir);
	return newVector;
}

std::string FileInput::getFileName() const{
	return filename;
}

void FileInput::setFileName(std::string newFilename){
	filename = newFilename;
}