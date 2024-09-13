main: main.o pilha.o
	gcc main.o pilha.o -o main
main.o: main.c
	gcc main.c -c
pilha.o: pilha.c
	gcc pilha.c -c
clean: rm -rf *.o