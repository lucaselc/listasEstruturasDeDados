#ifndef DEQUE_H
#define DEQUE_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{

    int qtd, ini, fim;
    int dados[MAX];

}Deque;

Deque* criaDeque();
void destroiDeque(Deque* d);
int tamanhoDeque(Deque* d);
int estaCheio(Deque* d);
int estaVazio(Deque* d);
void insereFim(Deque* d, int elem);
void insereInicio(Deque* d, int elem);
void removeFim(Deque* d);
void removeInicio(Deque* d);
void verInicio(Deque* d, int* p);
void verFim(Deque* d, int* p);
void imprimeDeque(Deque* d);

#endif