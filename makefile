output: main.o Ant.o 
	g++ main.o Ant.o -g -o Project1

main.o: main.cpp
	g++ -c main.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp
clean:
	rm *.o Project1
