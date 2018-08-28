#declare the varibales
CC=g++ -std=c++11


CFLAGS=-c -Wall

all: rubik_test

rubik_test: rubik_test.o Side.o RubiksCube.o
	$(CC) rubik_test.o Side.o RubiksCube.o -o rubik_test
rubik_test.o: rubik_test.cpp Side.cpp RubiksCube.cpp
	$(CC) $(CFLAGS) rubik_test.cpp Side.cpp RubiksCube.cpp
RubiksCube.o: RubiksCube.cpp
	$(CC) $(CFLAGS) RubiksCube.cpp RubiksCube.h
Side.o: Side.cpp
	$(CC) $(CFLAGS) Side.cpp Side.h
clean:
	rm -rf *o rubik_test
