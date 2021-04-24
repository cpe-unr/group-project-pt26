#ifndef METADATA_HEADER_H
#define METADATA_HEADER_H

/**
 * A struct to store information about the entire metadata chunk
 */
typedef struct metadata_header {
	/**
 	* "LIST" in 4 bytes
 	*/
	char list[4];
	/**
 	* The size of the metadata minus list and itself
 	*/
	int size;
	/**
 	* List type ID in 4 bytes
 	*/
	char ID[4];
} metadata_header;

#endif 