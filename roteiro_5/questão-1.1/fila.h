#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include <stdlib.h>


typedef struct NO{
    int info ;
    struct NO* prox ;
}NO;

typedef struct{
    int qtd;
    struct NO* ini;
    struct NO* fim;
}Fila ;

Fila* criaFila();
void destroiFila(Fila *fi);
int tamanhoFila(Fila *fi);
int estaVazia(Fila *fi);
int enfileirar(Fila *fi , int elem);
int desenfileirar(Fila *fi);
int verInicio(Fila * fi);
void imprime ( Fila * fi);

#endif