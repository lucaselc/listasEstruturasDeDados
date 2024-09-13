all: decrescente.o
	gcc decrescente.o main.c -o main
decrescente.o: decrescente.h
	gcc -c decrescente.c
clean:
	rm -rf *.o
