#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista criaLista() {
    Lista li = (Lista)malloc(sizeof(struct NO));
    if (li != NULL)
        li->prox = NULL;
    return li;
}

NO* alocarNO() {
    return (NO*)malloc(sizeof(NO));
}

void insere_ordenado(Lista lista, int n) {
    if (lista == NULL)
        return;

    NO* novo = alocarNO();
    if (novo == NULL)
        return;

    novo->info = n;

    NO* atual = lista->prox;
    NO* anterior = NULL;

    while (atual != NULL && n > atual->info) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        novo->prox = lista->prox;
        lista->prox = novo;
    } else {
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
}

void liberarNO (NO* atual){
    free(atual);
}

void remove_ocorrente(Lista lista, int n) {
    if (lista == NULL || lista->prox == NULL) 
        return;

    NO* atual = lista->prox;
    NO* anterior = NULL;

    while (atual != NULL) {
        if (atual->info == n){

            if (anterior == NULL) {
               
                lista->prox = atual->prox;
            } else {
               
                anterior->prox = atual->prox;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

int listaVazia(Lista li) {
    if (li == NULL || li->prox == NULL)
        return 1;
    return 0;
}

void imprimeLista(Lista li) {
    if (li == NULL)
        return;
    if (listaVazia(li)) {
        printf("Lista vazia!\n");
        return;
    }
    printf("Elementos: ");
    NO* aux = li->prox;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}


int tamanho(Lista li) {
    int tam = 0;
    if (li == NULL) {
        return tam;
    }
    NO* aux = li->prox;
    while (aux != NULL) {
        tam++;
        aux = aux->prox;
    }
    return tam;
}

int procura(Lista li, int x) {
    if (li == NULL)
        return 0;
    NO* aux = li->prox; 
    while (aux != NULL) {
        if (aux->info == x) {
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void destroiLista( Lista * li){
    if(li != NULL ){
        NO* aux;
        while ((* li) != NULL ){
            aux = *li;
            *li = (* li) ->prox ;
            liberarNO (aux);
        }
        free(li);
    }
}