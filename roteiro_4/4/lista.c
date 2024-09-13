#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criaLista () {
    Lista *li;
    li = (Lista *) malloc(sizeof(Lista ));
    if(li != NULL )
        *li = NULL ;
    return li;
}

void imprimeLista(Lista* li) {
    if (*li == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    printf("Elementos na lista: ");
    NO* aux = *li;
    while(aux->prox != *li){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("%d ", aux->info);
    printf("\n");
}

NO* alocarNO(int n) {
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        return NULL;
    }

    novo->info = n;
    novo->prox = NULL;
    return novo;
}

int insereFim(Lista* li, int n) {
    NO* novo = alocarNO(n);
    if (novo == NULL) {
        return 0;
    }

    if (*li == NULL) {
        *li = novo;
        novo->prox = novo;
    } else {
        NO* aux = *li;
        while (aux->prox != *li) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = *li;
    }

    return 1;
}

int tamanho(Lista* lista) {
    if (*lista == NULL) {
        return 0;
    }
    int tam = 1;
    NO* atual = *lista;
    atual = atual->prox;
    while (atual != *lista){
        tam++;
        atual = atual->prox;
    }

    return tam;
}

int procura(Lista* lista, int x) {
    if (*lista == NULL) {
        return 0;
    }

    NO* atual = *lista;
    do {
        if (atual->info==x) {
            return 1;
        }
        atual = atual->prox;
    } while (atual != *lista);

    return 0;
}

void destroiLista(Lista *li){
    if(li != NULL && (* li) != NULL ){
        NO* prim , *aux ;
        prim = *li;
        *li = (* li) ->prox ;
        while ((* li) != prim ){
            aux = *li;
            *li = (* li) ->prox ;
            liberarNO (aux);
        }
        liberarNO(prim);
        free(li);
    }
}

void liberarNO(NO* no){
    free (no);
}