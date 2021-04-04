CC = g++ 
flags = -g -W

main: main.o myTaxes.o
	$(CC) -o main main.o myTaxes.o
	git add main.cpp main.o
	git commit 
	git push

main.o: main.cpp
	$(CC) $(flags) -c main.cpp

myTaxes.o: myTaxes.h myTaxes.cpp
	$(CC) $(flags) -c myTaxes.cpp myTaxes.h

clear: 
	rm *.o main
