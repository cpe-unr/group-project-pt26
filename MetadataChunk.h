/** @file */
#ifndef METADATA_CHUNK_H
#define METADATA_CHUNK_H

/**
 * A struct to store a single metadata subchunk
 */
typedef struct metadata_chunk {
	/**
 	* The info ID of the metadata subchunk in 4 bytes 
 	*/
	char infoID[4];
	/**
 	* The size of the subchunk's data
 	*/
	int size;
	/**
 	* A char array storing the data for the metadata subchunk (initally a null pointer)
 	*/
	char* data = nullptr;
} metadata_chunk;

#endif //METADATA_CHUNK_H
