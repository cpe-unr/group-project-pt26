/** @file */
#include "Normal.h"
#include <cmath>

unsigned char* Normal::processBuffer(unsigned char* buffer, int size){
	float maxVal = 0;
	unsigned char* newBuffer = new unsigned char[size];
	for (int i = 0; i < size; i++) {
		if (abs((float)(buffer[i]) - 127.5) > maxVal) {
			maxVal = abs((float)(buffer[i]) - 127.5);
		}
	}
	float multiplier = 127.5 / maxVal;
	for (int i = 0; i < size; i++) {
		newBuffer[i] = (unsigned char)(floor(((float)(buffer[i]) - 127.5) * multiplier) + 127.5);
	}
	return newBuffer;
}

short* Normal::processBuffer(short* buffer, int size){
	float maxVal = 0;
	short* newBuffer = new short[size / 2];
	for (int i = 0; i < size/2; i++) {
		if (abs((float)(buffer[i])) > maxVal) {
			maxVal = abs((float)(buffer[i]));
		}
	}
	float multiplier = 32767 / maxVal;
	for (int i = 0; i < size/2; i++) {
		newBuffer[i] = (short)(floor((float)(buffer[i])) * multiplier);
	}
	return newBuffer;
}