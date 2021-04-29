/** @file */
#include "NoiseGate.h"

NoiseGate::NoiseGate(float thresholdPercent) : thresholdPercent(thresholdPercent) {}

unsigned char* NoiseGate::processBuffer(unsigned char* buffer, int size){
	float zero = 127.5;
	float upperBound = zero + 127.5 * thresholdPercent;
	float lowerBound = zero - 127.5 * thresholdPercent;
	unsigned char* newBuffer = new unsigned char[size];
	for (int i = 0; i < size; i++) {
		if (buffer[i] < upperBound && buffer[i] > lowerBound) {
			newBuffer[i] = zero;
		}
		else {
			newBuffer[i] = buffer[i];
		}
	}
	return newBuffer;
}

short* NoiseGate::processBuffer(short* buffer, int size){
	float zero = 0;
	float upperBound = zero + 16383.5 * thresholdPercent;
	float lowerBound = zero - 16383.5 * thresholdPercent;
	short* newBuffer = new short[size/2];
	for (int i = 0; i < size/2; i++) {
		if (buffer[i] < upperBound && buffer[i] > lowerBound) {
			newBuffer[i] = zero;
		}
		else {
			newBuffer[i] = buffer[i];
		}
	}
	return newBuffer;
}