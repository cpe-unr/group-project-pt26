audio: main.o Iprocessable.o NoiseGate.o
	g++ -std=c++11 main.o Iprocessable.o NoiseGate.o -o audio

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp FileInput.cpp UserInteraction.cpp

UserInteraction.o: UserInteraction.cpp UserInteraction.h
	g++ -c -std=c++11 UserInteraction.cpp

ModifyMetadata.o: ModifyMetadata.cpp ModifyMetadata.h MetadataChunk.h MetadataHeader.h Wav.h FileOutput.h
	g++ -c -std=c++11 ModifyMetadata.cpp

Wav.o: Wav.cpp Wav.h
	g++ -c -std=c+=11 Wav.cpp 

Iprocessable.o: Iprocessable.cpp Iprocessable.h
	g++ -c -std=c++11 Iprocessable.cpp

NoiseGate.o: NoiseGate.cpp NoiseGate.h Iprocessable.h
	g++ -c -std=c+=11 NoiseGate.cpp 

clean:
	rm *.o audio
