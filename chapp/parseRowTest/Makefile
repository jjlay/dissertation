CC = g++
CFLAGS = -std=c++20

parseRowTest : parseRowTest.o parseRow.o
	$(CC) $(CFLAGS) -o parseRowTest parseRowTest.o parseRow.o

parseRowTest.o : parseRowTest.cpp parseRow.h ReturnValues.h
	$(CC) $(CFLAGS) -c parseRowTest.cpp

clean :
	rm -f *.o
	rm -f parseRowTest

