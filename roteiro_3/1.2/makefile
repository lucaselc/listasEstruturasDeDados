main: 1.2.o cubo.o
	gcc 1.2.o cubo.o -o main
1.2.o: 1.2.c
	gcc -c 1.2.c
cubo.o: cubo.c cubo.h
	gcc -c cubo.c

clean: rm -rf *.o
