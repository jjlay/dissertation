CC = g++
CFLAGS = -std=c++2a

SimpleMC : SimpleMC.o
	$(CC) $(CFLAGS) -o SimpleMC SimpleMC.o

SimpleMC.o : SimpleMC.cpp ReturnValues.h
	$(CC) $(CFLAGS) -c SimpleMC.cpp

clean :
	rm -f SimpleMC
	rm -f *.o
