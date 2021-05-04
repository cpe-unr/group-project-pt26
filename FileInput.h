/** @file */

#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <vector>
#include <string>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include "WaveHeader.h"
#include "Wav.h"
#include "MonoWav.h"
#include "StereoWav.h"
#include "MetadataChunk.h"
#include "MetadataHeader.h"

/**
 * Class that looks in the given directory and takes out the file information
 */
class FileInput{
	std::string filename;

public:
	FileInput() = default; //default ctor
	FileInput(const std::string& folder);//param ctor

	std::vector<Wav*> readFiles(const std::string& folder);//reads folder to take out files

	std::string getFileName() const;
	void setFileName(std::string NewFilename);
};

#endif //FILEINPUT_H

