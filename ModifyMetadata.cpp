/** @file */
#include "ModifyMetadata.h"
#include "MetadataChunk.h"
#include "MetadataHeader.h"

void ModifyMetadata::modifyMetadata(Wav* wav, std::vector <std::string> metadataIDs, std::vector <std::string> metadata) {
	metadata_header newMetadataHeader;
	std::vector<metadata_chunk> newMetadata;
	int newSize = 0;
	for (metadata_chunk m : wav->getMetadata()) {
		bool add = true;
		for (std::string x : metadataIDs) {
			int same = 0;
			for (int i = 0; i < 4; i++) {
				if (m.infoID[i] == x[i]) {
					same++;
				}
			}
			if (same == 4) {
				add = false;
				break;
			}
		}
		if (add) {
			newMetadata.push_back(m);
			newSize += m.size + 8;
		}
	}
	for (int i = 0; i < metadataIDs.size(); i++) {
		metadata_chunk chunk;
		for (int j = 0; j < 4; j++) {
			chunk.infoID[j] = metadataIDs[i][j];
		}
		chunk.size = metadata[i].size();
		chunk.data = new char[chunk.size];
		for (int j = 0; j < chunk.size; j++) {
			chunk.data[j] = metadata[i][j];
		}
		newMetadata.push_back(chunk);
		newSize += chunk.size + 8;
	}
	for (int i = 0; i < 4; i++) {
		newMetadataHeader.list[i] = listArr[i];
	}
	for (int i = 0; i < 4; i++) {
		newMetadataHeader.ID[i] = infoArr[i];
	}
	newMetadataHeader.size = newSize;
	wav->setMetadataHeader(newMetadataHeader);
	wav->setMetadata(newMetadata);
	//write new metadata to file
}