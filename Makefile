#declare the varibales
CC=g++ -std=c++11


CFLAGS=-c -Wall

all: main

main: main.o Side.o RubiksCube.o
	$(CC) main.o Side.o RubiksCube.o -o main
main.o: main.cpp Side.cpp RubiksCube.cpp
	$(CC) $(CFLAGS) main.cpp Side.cpp RubiksCube.cpp
RubiksCube.o: RubiksCube.cpp
	$(CC) $(CFLAGS) RubiksCube.cpp RubiksCube.h
Side.o: Side.cpp
	$(CC) $(CFLAGS) Side.cpp Side.h
clean:
	rm -rf *o main
