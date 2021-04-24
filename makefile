audio: main.o
	g++ -std=c++11 main.o -o audio

Main.o: main.cpp
	g++ -c -std=c++11 main.cpp

clean:
	rm *.o audio