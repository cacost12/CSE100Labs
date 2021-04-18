CC = g++
flags = -g -W
odir = objectFiles 

main: main.o get.o prelab.o
	$(CC) $(flags) objectFiles/* -o main

main.o: main.cpp
	$(CC) $(flags) -c main.cpp
	mv main.o $(odir)

get.o: get.cpp get.hpp
	$(CC) $(flags) -c get.cpp get.hpp
	mv get.o $(odir)

prelab.o: prelab.cpp prelab.hpp
	$(CC) $(flags) -c prelab.cpp prelab.hpp	
	mv prelab.o $(odir)

clear: 
	rm main $(odir)/*

update:
	git add --all 
	git commit 
	git push


