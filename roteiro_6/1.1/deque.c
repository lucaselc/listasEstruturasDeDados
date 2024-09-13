#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#define MAX 100

Deque* criaDeque(){

    Deque* d = (Deque*)malloc(sizeof(Deque));

    if(d != NULL){
        d->qtd = 0;
        d->ini = 0;
        d->fim = 0;
    }
    return d;
}

void destroiDeque(Deque* d){

    if(d == NULL) return;
    free(d);
}

int tamanhoDeque(Deque* d){

    if(d == NULL) return -1;
    return d->qtd;

}

int estaCheio(Deque* d){

    if(d == NULL) return -1;
    return (d->qtd == MAX);

}

int estaVazio(Deque* d){

    if(d == NULL) return -1;
    return (d->qtd == 0);

}

void insereFim(Deque* d, int elem){

    if(d == NULL) return;
    if(estaCheio(d)) return;

    d->dados[d->fim] = elem;
    d->fim = (d->fim+1) % MAX;
    d->qtd++;

}

void insereInicio(Deque* d, int elem){

    if(d == NULL) return;
    if(estaCheio(d)) return;

    d->ini = (d->ini-1 < 0 ? MAX-1 : d->ini-1);
    d->dados[d->ini] = elem;
    d->qtd++;

}

void removeFim(Deque* d){

    if(d == NULL) return;
    if(estaVazio(d)) return;

    d->fim = (d->fim-1 < 0 ? MAX-1 : d->fim-1);
    d->qtd--;

}

void removeInicio(Deque* d){

    if(d == NULL) return;
    if(estaVazio(d)) return;

    d->ini = (d->ini+1) % MAX;
    d->qtd--;

}

void verInicio(Deque* d, int* p){

    if(d == NULL) return;
    if(estaVazio(d)) return;

    *p = d->dados[d->ini];

}

void verFim(Deque* d, int* p){

    if(d == NULL) return;
    if(estaVazio(d)) return;

    int i = (d->fim-1 < 0 ? MAX-1 : d->fim-1);
    *p = d->dados[i];
}

void imprimeDeque(Deque* d){

    if(d == NULL){
        printf("Deque não encontrado.\n");
        return;
    }

    if(estaVazio(d)){
        printf("Deque vazio.\n");
        return;
    }

    int i = d->ini;
    printf("Elementos: ");
    do{
        printf(" %d", d->dados[i]);
        i = (i+1) % MAX;
    } while(i != d->fim);
    printf("\n");

}
