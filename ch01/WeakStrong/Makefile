CC = g++
CFLAGS = -std=c++2b

WeakStrongCPU : WeakStrongCPU.o
	$(CC) $(CFLAGS) -o WeakStrongCPU WeakStrongCPU.o

WeakStrongCPU.o : WeakStrongCPU.cpp ReturnValues.h
	$(CC) $(CFLAGS) -c WeakStrongCPU.cpp

clean :
	rm -f WeakStrongCPU
	rm -f *.o
