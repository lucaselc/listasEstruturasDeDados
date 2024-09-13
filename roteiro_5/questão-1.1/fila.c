#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criaFila(){
   Fila *fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL)
        fi->ini = fi->fim = NULL;
    return fi; 
}

void destroiFila(Fila *fi){
    NO* aux = fi->ini;
    NO* aux2;
    while(aux!=NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(fi);
}
int tamanhoFila(Fila *fi){
    int tam = 0;
    if(fi == NULL)
        return tam;
    NO* aux = fi->ini;
    while(aux != NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

int estaVazia(Fila *fi){
    return (fi->ini == NULL);
}
int enfileirar(Fila *fi , int elem){
    NO* n = (NO*)malloc(sizeof(NO));
    n->info = elem;
    n->prox = NULL;
    if(!estaVazia(fi))
        fi->fim->prox = n;
    else{
        fi->ini = n;
    } 
    fi->fim = n;

}
int desenfileirar(Fila *fi){
    NO* aux;
    if(fi == NULL)
        return 0;
    if(estaVazia(fi)){
        printf("Fila vazia!\n");
        return 0;
    }
    aux = fi->ini;
    fi->ini= aux->prox;
    if(fi->ini == NULL)
        fi->fim = NULL;
    free(aux);
    return 1;
}
int verInicio(Fila * fi){
    if(fi == NULL)
        return 0;
    
    if(estaVazia(fi))
        return 0;
    int elem;
    elem = fi->ini->info;
    return elem;
    
}
void imprime(Fila * fi){
    if(fi == NULL)
        return;
    if(estaVazia(fi)){
        printf("Fila vazia!\n");
        return;
    }
    printf("Elementos: ");
    NO* aux = fi->ini;
    while(aux!=NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");

}