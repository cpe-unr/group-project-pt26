#ifndef WAV_H
#define WAV_H

#include "MetadataChunk.h"
#include "MetadataHeader.h"
#include <vector>

class Wav{
protected:
	metadata_header metadataHeader;
	std::vector<metadata_chunk> metadata;
};

#endif //WAV_H