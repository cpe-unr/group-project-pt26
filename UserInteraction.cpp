/** @file */

/*
UserInteraction Implementation
*/

#include "UserInteraction.h"
#include "FileOutput.h"
#include "ModifyMetadata.h"

UserInteraction::UserInteraction(){
	selection = 0;
}

UserInteraction::UserInteraction(std::vector<Wav*> newWavs, std::string newFolder){
	selection = 0;
	wavs = newWavs;
	folder = newFolder;
}

void UserInteraction::userSelection(){

	std::cout << "Files have been read and processed..." << std::endl;

	do{
	std::cout << "Please choose what to do with your files.\n";
	std::cout << "(It is recommended you modify metadata first.)\n\n";
	std::cout << "1. Modify Metadata\n";
	std::cout << "2. Audio Processing\n";
	std::cout << "3. Export CSV File\n";
	std::cout << "4. QUIT\n";
	std::cout << "Enter Selection: ";
	std::cin >> selection;

	switch(selection){
	case 1:
		userModify();
		break;

	case 2:
		processorType();
		break;

	case 3:
		//exportCSV();
		break;

	}
	}while(selection != 4);
	
}

void UserInteraction::userModify(){
		ModifyMetadata modifyMetadata;
		FileOutput fileOut;
		int file;
		std::string input;
		int choice;
		std::vector <std::string> IDs;
		std::vector <std::string> metadata;
		std::cout << "Please choose the number of the file you wish to modify." << std::endl;
		int count = 0;
		for(Wav* w : wavs){
			std::cout << count << ". " << w->getFilename() << std::endl;
			count++;
		}
		std::cin >> file;
		std::cout << "Please choose type of metadata to add." << std::endl;
		std::cout << "1. Artist" << std::endl;
		std::cin >> choice;
		std::string id;
		switch(choice){
		case 1:
			IDs.push_back("IART");
			break;
		}
		std::cout << "Please enter the metadata to add." << std::endl;
		std::cin >> input;
		metadata.push_back(input);
		modifyMetadata.modifyMetadata(wavs[file], IDs, metadata);
		fileOut.writeFile(folder, wavs[file]->getFilename(), wavs[file]);
}

void UserInteraction::processorType(){
	
	std::cout << "Please provide the name of the file you wish to process." <<std::endl;
	//std::cin >> filename;
	//std::string newFilename = saveFileName(filename);
	//FileOutput::newFile(newFilename);
	
}

std::string UserInteraction::saveFileName(std::string filename){
	std::string file;
	do{
		std::cout << "Please provide the new name of this file." << std::endl;
		std::cin >> file;
		if (file != filename){
			return file;
		}
		else{
		std::cout << "Invalid. New file name must be different from that of the current file." << std::endl;
		}	
	}while (file == filename);
}

