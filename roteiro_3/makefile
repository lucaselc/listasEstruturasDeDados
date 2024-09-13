main: 1.3.o conjunto.o
	gcc 1.3.o conjunto.o -o main
1.3.o: 1.3.c
	gcc -c 1.3.c
conjunto.o: conjunto.c conjunto.h
	gcc -c conjunto.c

clean: rm -rf *.o