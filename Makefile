#declare the varibales
CC=g++ -std=c++11


CFLAGS=-c -Wall

all: main

main: main.o Side.o
	$(CC) main.o Side.o Color.o -o main
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp Side.cpp Color.cpp
PPM.o: PPM.cpp
	$(CC) $(CFLAGS) Side.cpp Side.h
clean:
	rm -rf *o main
