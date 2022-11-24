CC = g++
CFLAGS = -std=c++20

SDEParameterEstimation : SDEParameterEstimation.o
	$(CC) $(CFLAGS) -o SDEParameterEstimation SDEParameterEstimation.o

SDEParameterEstimation.o : SDEParameterEstimation.cpp
	$(CC) $(CFLAGS) -c SDEParameterEstimation.cpp

clean:
	rm -f *.o
	rm -f SDEParameterEstimation

