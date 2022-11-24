CC = g++
CFLAGS = -std=c++20


main.out : main.o parameters.o
	$(CC) $(CFLAGS) -o main.out main.o parameters.o

main.o : main.cpp parameters.h
	$(CC) $(CFLAGS) -c main.cpp

parameters.o : parameters.cpp
	$(CC) $(CFLAGS) -c parameters.cpp


clean :
	rm -f *.o
	rm -f *.out

