link:
	gcc build/functions.o build/main.o -pthread -o bin/main
main.o:
	gcc -c main.c -o build/main.o
functions.o:
	gcc -c functions.c -o build/functions.o
clear:
	rm -r -f build
.PHONY: build
build:
	make clear
	mkdir build
	make functions.o
	make main.o
	rm -r -f bin
	mkdir bin
	make link
	make clear
	clear
