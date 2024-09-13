#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct NO {
    int info;
    struct NO* prox;
} NO;
typedef struct NO* Lista;
Lista* criaLista();
int tamanho(Lista* lista);
int procura(Lista* lista, int n);
void imprimeLista(Lista* li);
NO* alocarNO(int n);
int insereFim(Lista* li, int n);
void destroiLista(Lista *li);
void liberarNO(NO* no);
#endif

