/*
*/

#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <vector>
#include <string>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>

class FileInput{
	std::string filename;

public:
	FileInput() = default; //default ctor
	FileInput(const std::string& folder);//param ctor

	void readFiles(const std::string& folder);//reads folder to take out files
};

#endif //FILEINPUT_H

