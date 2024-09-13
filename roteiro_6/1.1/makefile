main: main.o deque.o
	gcc main.o deque.o -o main
main.o: main.c
	gcc main.c -c
deque.o: deque.c
	gcc deque.c -c
clean: rm -rf .*o