# chess engine makefile
CC=g++
#CC=g++ -fprofile-arcs -ftest-coverage

Hal9000: position.o legalmoves.o main.o
	$(CC) position.o legalmoves.o main.o  -o Hal9000

position.o: position.h position.cpp
	$(CC) -c position.cpp

legalmoves.o: legalmoves.h position.h legalmoves.cpp
	$(CC) -c legalmoves.cpp

main.o: position.h legalmoves.h main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o *.gcov *.gcda *.gcno Hal9000