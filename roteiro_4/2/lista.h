#ifndef LISTA_H
#define LISTA_H

typedef struct NO {
    int info;
    struct NO* prox;
} NO;

typedef struct NO* Lista;
NO* alocarNO();
int procura(Lista li, int x);
int tamanho(Lista li);
Lista criaLista();
int listaVazia(Lista li);
void imprimeLista(Lista li);
void remove_ocorrente(Lista lista, int x);
void insere_ordenado(Lista lista, int x);
void destroiLista(Lista * li);
void liberarNO (NO* atual);
#endif
