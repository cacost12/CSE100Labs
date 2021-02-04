CC = g++ 
flags = -g -W

main: main.o 
	$(CC) -o main main.o

main.o: main.cpp
	$(CC) $(flags) -c main.cpp

clear: 
	rm *.o main
