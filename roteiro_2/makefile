all: catalogo.o main.o
	gcc catalogo.o main.o -o main
main.o: main.c
	gcc main.c -c
catalogo.o: catalogo.h
	gcc -c catalogo.c
clean: rm -rf *.o