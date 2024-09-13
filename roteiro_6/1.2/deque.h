#ifndef DEQUE_H
#define DEQUE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct NO NO;
struct NO{
    int info;
    NO* prox;
    NO* ant;
};

typedef struct{
    int qtd;
    struct NO* ini;
    struct NO* fim;
}Deque;
NO* alocarNO();
void destroiNO(NO* n);
Deque* criaDeque();
void destroiDeque(Deque* d);
int tamanhoDeque(Deque* d);
int estaVazio(Deque* d);
void insereFim(Deque* d, int elem);
void insereInicio(Deque* d, int elem);
void removeFim(Deque* d);
void removeInicio(Deque* d);
void verInicio(Deque* d, int* p);
void verFim(Deque* d, int* p);
void imprimeDeque(Deque* d);

#endif