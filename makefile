audio: main.o FileInput.o UserInteraction.o ModifyMetadata.o Wav.o StereoWav.o MonoWav.o NoiseGate.o Echo.o Normal.o FileOutput.o
	g++ -o -std=c++11 main.o FileInput.o UserInteraction.o ModifyMetadata.o Wav.o StereoWav.o MonoWav.o NoiseGate.o Echo.o Normal.o FileOutput.o

main.o: main.cpp FileInput.h UserInteraction.h
	g++ -c -std=c++11 main.cpp 

FileInput.o: FileInput.cpp FileInput.h WaveHeader.h
	g++ -c -std=c++11 FileInput.cpp

UserInteraction.o: UserInteraction.cpp UserInteraction.h FileOutput.h
	g++ -c -std=c++11 UserInteraction.cpp

ModifyMetadata.o: ModifyMetadata.cpp ModifyMetadata.h MetadataChunk.h MetadataHeader.h Wav.h FileOutput.h
	g++ -c -std=c++11 ModifyMetadata.cpp

Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp 

StereoWav.o: StereoWav.cpp StereoWav.h Wav.h
	g++ -c -std=c++11 StereoWav.cpp

MonoWav.o: MonoWav.cpp MonoWav.h Wav.h
	g++ -c -std=c++11 MonoWav.cpp

NoiseGate.o: NoiseGate.cpp NoiseGate.h Iprocessable.h
	g++ -c -std=c++11 NoiseGate.cpp 

Echo.o: Echo.cpp Echo.h Iprocessable.h
	g++ -c -std=c++11 Echo.cpp

Normal.o: Normal.cpp Normal.h Iprocessable.h
	g++ -c -std=c++11 Normal.cpp

FileOutput.o: FileOutput.cpp FileOutput.h ModifyMetadata.h Metadata_chunk.h
	g++ -c -std=c++11 FileOutput.cpp

clean:
	rm *.o audio
