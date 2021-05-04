/** @file */

#include "FileOutput.h"

/*void FileOutput::newFile(std::string filename){
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

}*/

void FileOutput::writeFile(std::string folder, std::string filename, Wav* wav){
	wav_header waveHeader = wav->getWaveHeader();
	metadata_header metadataHeader = wav->getMetadataHeader();
	std::vector<metadata_chunk> metadata = wav->getMetadata();
	if(waveHeader.num_channels == 1){
		if(waveHeader.bit_depth == 8){
			std::ofstream outFile(folder + "/" + filename, std::ios::out | std::ios::binary);
			outFile.write((char*)&waveHeader, sizeof(waveHeader));
			outFile.write((char*)reinterpret_cast<unsigned char*>(reinterpret_cast<MonoWav<unsigned char>*>(wav)->getBuffer()), waveHeader.data_bytes);
			outFile.write((char*)&metadataHeader, sizeof(metadataHeader));
			for (metadata_chunk i : metadata) {
				outFile.write((char*)&i, i.size + 8);
			}
			outFile.close();
		}
		else if(waveHeader.bit_depth == 16){
			std::ofstream outFile(folder + "/" + filename, std::ios::out | std::ios::binary);
			outFile.write((char*)&waveHeader, sizeof(waveHeader));
			outFile.write((char*)reinterpret_cast<unsigned char*>(reinterpret_cast<MonoWav<short>*>(wav)->getBuffer()), waveHeader.data_bytes);
			outFile.write((char*)&metadataHeader, sizeof(metadataHeader));
			for (metadata_chunk i : metadata) {
				outFile.write((char*)&i, i.size + 8);
			}
			outFile.close();
		}
	}

	else if(waveHeader.num_channels == 2){
		if(waveHeader.bit_depth == 8){
			std::ofstream outFile(folder + "/" + filename, std::ios::out | std::ios::binary);
			outFile.write((char*)&waveHeader, sizeof(wav_header));
			unsigned char* newBuffer = new unsigned char[waveHeader.data_bytes];
			unsigned char* nBuffer = reinterpret_cast<unsigned char*>(newBuffer);
			for (int i = 0; i < waveHeader.data_bytes / 2; i++) {
				nBuffer[2*i] = reinterpret_cast<StereoWav<unsigned char>*>(wav)->getBufferOne()[i];
				nBuffer[2*i + 1] = reinterpret_cast<StereoWav<unsigned char>*>(wav)->getBufferTwo()[i];
			}
			outFile.write((char*)reinterpret_cast<unsigned char*>(newBuffer), waveHeader.data_bytes);
			outFile.write((char*)&metadataHeader, sizeof(metadataHeader));
			for (metadata_chunk i : metadata) {
				outFile.write((char*)&i, i.size + 8);
			}

			delete[] nBuffer;
			outFile.close();
		}
		else if(waveHeader.bit_depth == 16){
			std::ofstream outFile(folder + "/" + filename, std::ios::out | std::ios::binary);
			outFile.write((char*)&waveHeader, sizeof(wav_header));
			unsigned char* newBuffer = new unsigned char[waveHeader.data_bytes];
			short* nBuffer = reinterpret_cast<short*>(newBuffer);
			for (int i = 0; i < waveHeader.data_bytes / 4; i++) {
				nBuffer[2*i] = reinterpret_cast<StereoWav<short>*>(wav)->getBufferOne()[i];
				nBuffer[2*i + 1] = reinterpret_cast<StereoWav<short>*>(wav)->getBufferTwo()[i];
			}
			outFile.write((char*)reinterpret_cast<unsigned char*>(newBuffer), waveHeader.data_bytes);
			outFile.write((char*)&metadataHeader, sizeof(metadataHeader));
			for (metadata_chunk i : metadata) {
				outFile.write((char*)&i, i.size + 8);
			}

			delete[] nBuffer;
			outFile.close();
		}
	}

}
