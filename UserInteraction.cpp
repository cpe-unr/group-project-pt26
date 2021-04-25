/** @file */

/*
UserInteraction Implementation
*/

#include "UserInteraction.h"

UserInteraction::UserInteraction(){}

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
		UserInteraction::makeCSV;
		break;

	}
	}while(selection != 4);
	
}

void UserInteraction::userModify(){
	
		std::cout << "Please provide the name of the file you wish to modify." << std::endl;
		std::cin >> filename;
		//call modifyMetadata method??	
}

void UserInteraction::processorType(){
	
	std::cout << "Which processors would you like?"
	std::cout << "1. Normalization\n 2. Noise Gating\n 3. Echo\n";
	
}

void UserInteraction::makeCSV(){

}
