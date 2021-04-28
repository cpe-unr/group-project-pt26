audio: main.o
	g++ -std=c++11 main.o -o audio

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp FileInput.cpp UserInteraction.cpp

Iprocessable.o: Iprocessable.cpp Iprocessable.h
	g++ -c -std=c++11 Iprocessable.cpp

clean:
	rm *.o audio
