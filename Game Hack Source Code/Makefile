# --- Makefile ---
#
#  this file is the make file required to compile all object source code files.
#  Note: before compiling and use. see README file for more information.
#
# Format
#
# Target: Dependencies
# 	Recipe

all: prog

prog: main.o library.o
	g++ -g main.o library.o -o prog

main.o: main.cpp
	g++ -g -c main.cpp -o main.o

library.o: library.cpp
	g++ -g -c library.cpp -o library.o

clean:  
	rm *.o *.txt prog

