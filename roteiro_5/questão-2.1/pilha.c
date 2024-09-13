#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criaPilha(){
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    pi->topo = NULL;
    return pi;
}
void destroiPilha(Pilha* pi){
    NO* aux;
    NO* q = pi->topo;
    while(q!=NULL){
        aux = q->prox;
        free(q);
        q = aux;
    }
    free(pi);
}
int tamanhoPilha(Pilha* pi){
    int tam = 0;
    if(pi == NULL)
        return tam;
    NO* aux = pi->topo;
    while(aux!=NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}
int estaVazia(Pilha* pi){
    return (pi->topo==NULL);
}
int empilhar(Pilha* pi , int elem){
    NO* aux = (NO*)malloc(sizeof(NO));
    if(aux==NULL)
        return 0;
    aux->info = elem;
    aux->prox = pi->topo;
    pi->topo = aux;
    return 1;
}
int desempilhar(Pilha* pi){
    NO* aux;
    if(estaVazia(pi)){
        printf("Pilha vazia!\n");
        return 0;
    }
    aux = pi->topo;
    pi->topo = aux->prox;
    free(aux);
    return 1;
}
int verTopo(Pilha* pi){
    return pi->topo->info;
}
void imprime(Pilha* pi){
    if(pi == NULL)
        return;
    if(estaVazia(pi)){
        printf("Pilha vazia!\n");
        return;
    }
    printf("Elementos: ");
    NO* aux = pi->topo;
    while(aux!=NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}