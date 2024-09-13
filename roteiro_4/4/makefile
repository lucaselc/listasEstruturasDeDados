main: main.o lista.o
	gcc main.o lista.o -o main
main.o: main.c
	gcc -c main.c
lista.o: lista.c lista.h
	gcc -c lista.c
clean: rm -rf *.o