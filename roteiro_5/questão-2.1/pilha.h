#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#include <stdlib.h>


typedef struct NO{
    int info;
    struct NO* prox ;
}NO;

typedef struct {
    int qtd;
    struct NO* topo ;
}Pilha;

Pilha* criaPilha();
void destroiPilha(Pilha* pi);
int tamanhoPilha(Pilha* pi);
int estaVazia(Pilha* pi);
int empilhar(Pilha* pi , int elem);
int desempilhar(Pilha* pi);
int verTopo(Pilha* pi);
void imprime(Pilha* pi);

#endif 