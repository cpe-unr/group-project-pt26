/** @file */
#include "Echo.h"
#include <cmath>

Echo::Echo(int delay) : delay(delay) {}

unsigned char* Echo::processBuffer(unsigned char* buffer, int size){
	unsigned char* newBuffer = new unsigned char[size];
	for (int i = 0; i < delay; i++) {
		newBuffer[i] = buffer[i];
	}
	for (int i = 0; i < size - delay; i++) {
		newBuffer[i + delay] = (unsigned char)(round((float)(buffer[i + delay] - 127.5) * scaleFactor + (float)(newBuffer[i] - 127.5) * echoLevel  + 127.5));
	}
	return newBuffer;
}

short* Echo::processBuffer(short* buffer, int size){
	short* newBuffer = new short[size / 2];
	for (int i = 0; i < delay/2; i++) {
		newBuffer[i] = buffer[i];
	}
	for (int i = 0; i < (size - delay)/2; i++) {
		newBuffer[i + (delay / 2)] = buffer[i + (delay / 2)] * scaleFactor + newBuffer[i] * echoLevel;
	}
	return newBuffer;
}