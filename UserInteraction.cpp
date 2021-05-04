/** @file */

/*
UserInteraction Implementation
*/

#include "UserInteraction.h"
#include "FileOutput.h"

UserInteraction::UserInteraction(){
	selection = 0
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
		UserInteraction::userModify;
		break;

	case 2:
		UserInteraction::processorType;
		break;

	case 3:
		FileOutput::exportCSV;
		break;

	}
	}while(selection != 4);
	
}

void UserInteraction::userModify(){
	
		std::cout << "Please provide the name of the file you wish to modify." << std::endl;
		std::cin >> filename;
		filename.modifyMetadata(); //??
}

void UserInteraction::processorType(){
	
	std::cout << "Please provide the name of the file you wish to process." <<std::endl;
	std::cin >> filename;
	std::string newFilename = saveFileName(filename);
	FileOutput::newFile(filename);
	
}

std::string UserInteraction::saveFileName(std::string filename){
	std::string file;
	do{
		std::cout << "Please provide the new name of this file." << std::endl
		std::cin >> file;
		if (file != filename){
			return file;
		}
		else{
		cout << "Invalid. New file name must be different from that of the current file." << std::endl;
		}	
	}	
	while (file = filename);
}

