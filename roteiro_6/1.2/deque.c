#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

NO* alocarNO(){
    NO* n = (NO*)malloc(sizeof(NO));
    if(n != NULL){
        n->info = 0;
        n->prox = NULL;
        n->ant = NULL;
    }
    return n;
}

void destroiNO(NO* n){
    if(n == NULL) return;
    free(n);
}


Deque* criaDeque(){
    Deque* d = (Deque*)malloc(sizeof(Deque));
    if(d != NULL){
        d->qtd = 0;
        d->ini = NULL;
        d->fim = NULL;
    }

    return d;

}

void destroiDeque(Deque* d){
    if(d == NULL) return;

    NO* aux;
    while(d->ini != NULL){
        aux = d->ini;
        d->ini = d->ini->prox;
        free(aux);
    }
    free(d);

}

int tamanhoDeque(Deque* d){

    if(d == NULL) return -1;
    return d->qtd;

}

int estaVazio(Deque* d){

    if(d == NULL) return -1;
    return (d->qtd == 0);

}

void insereFim(Deque* d, int elem){
    if(d == NULL) return;

    NO* n = alocarNO();
    if(n == NULL) return;

    n->info = elem;
    n->prox = NULL;

    if(estaVazio(d)){
        n->ant = NULL;
        d->ini = n;
    }

    else{
        d->fim->prox = n;
        n->ant = d->fim;
    }

    d->fim = n;
    d->qtd++;

}

void insereInicio(Deque* d, int elem){

    if(d == NULL) return;

    NO* n = alocarNO();
    if(n == NULL) return;

    n->info = elem;
    n->ant = NULL;

    if(estaVazio(d)){
        n->prox = NULL;
        d->fim = n;
    }

    else{
        d->ini->ant = n;
        n->prox = d->ini;
    }

    d->ini = n;
    d->qtd++;

}

void removeFim(Deque* d){

    if(d == NULL) return;
    if(estaVazio(d)) return;
    NO* aux = d->fim;
    if(d->ini == d->fim){
        d->ini = NULL;
        d->fim = NULL;
    }
    else{
        d->fim = d->fim->ant;
        d->fim->prox = NULL;
    }
    destroiNO(aux);
    d->qtd--;
}

void removeInicio(Deque* d){

    if(d == NULL) return;
    if(estaVazio(d)) return;
    NO* aux = d->ini;
    if(d->ini == d->fim){
        d->ini = NULL;
        d->fim = NULL;
    }
    else{
        d->ini = d->ini->prox;
        d->ini->ant = NULL;
    }
    destroiNO(aux);
    d->qtd--;
}

void verInicio(Deque* d, int* p){

    if(d == NULL) return;
    if(estaVazio(d)) return;
    *p = d->ini->info;
}

void verFim(Deque* d, int* p){

    if(d == NULL) return;
    if(estaVazio(d)) return;
    *p = d->fim->info;

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

    NO* aux = d->ini;

    printf("Elementos:");
    while(aux != d->fim->prox){
        printf(" %d", aux->info);
        aux = aux->prox;
    }
    printf("\n");

}
