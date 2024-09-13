#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO NO;

struct NO{
    int info, prio;
    NO* prox;

};

NO* alocarNO(){
    NO* n = (NO*)malloc(sizeof(NO));
    if(n != NULL){
        n->info = 0;
        n->prio = 0;
        n->prox = NULL;
    }
    return n;
}

void destroiNO(NO* n){
    if(n == NULL) return;
    free(n);
}

typedef NO* FilaP;

FilaP* criaFilaP(){
    FilaP* fp = (FilaP*)malloc(sizeof(FilaP));
    if(fp != NULL){
        *fp = NULL;
    }
    return fp;

}

void destroiFilaP(FilaP* fp){
    if(fp == NULL) return;

    NO* aux;
    while((*fp) != NULL){
        aux = *fp;
        *fp = (*fp)->prox;
        destroiNO(aux);
    }
    free(fp);

}

int estaVazia(FilaP* fp){
    if(fp == NULL) return -1;
    return (*fp == NULL);
}

int tamanhoFilaP(FilaP* fp){
    if(fp == NULL) return -1;
    if(estaVazia(fp)) return 0;
    NO* aux = *fp;
    int tam = 0;
    while(aux != NULL){
        aux = aux->prox;
        tam++;
    }
    return tam;

}

void inserirPrioritario(FilaP* fp, int elem, int prio){

    if(fp == NULL) return;
    NO* n = alocarNO();
    n->info = elem;
    n->prio = prio;
    if(estaVazia(fp)){
        *fp = n;
        n->prox = NULL;
    }

    else{
        NO* aux = *fp;
        NO* ant = NULL;
        while(aux != NULL && aux->prio >= n->prio){
            ant = aux;
            aux = aux->prox;
        }
        if(ant == NULL){
            n->prox = *fp;
            *fp = n;
        }
        else{
            n->prox = ant->prox;
            ant->prox = n;
        }
    }
}

void removeInicio(FilaP* fp){
    if(fp == NULL) return;
    if(estaVazia(fp)) return;
    NO* aux = *fp;
    *fp = aux->prox;
    destroiNO(aux);
}

void verInicio(FilaP* fp, int* p){
    if(fp == NULL) return;
    if(estaVazia(fp)) return;
    *p = (*fp)->info;
}

void imprimeFilaP(FilaP* fp){
    if(fp == NULL){
        printf("Fila de Prioridade não encontrada.\n");
        return;
    }
    if(estaVazia(fp)){
        printf("Fila de prioridade vazia.\n");
        return;
    }
    NO* aux = *fp;
    printf("Elementos: ");
    while(aux != NULL){
        printf(" [%d, %d]", aux->info, aux->prio);
        aux = aux->prox;
    }
    printf("\n");
}

#endif