CC = g++
FILES = main.cpp servicemanage.cpp stockmanage.cpp
OPTIONS = -std=c++11 -Ofast -O2

#main section
main: $(FILES)
	$(CC) $(OPTIONS) $(FILES) -o main

clear:
	rm -f main
