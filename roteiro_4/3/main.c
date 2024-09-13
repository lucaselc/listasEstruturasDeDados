#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista *li = criaLista();
    insere_ordenado(li,6);
    insere_ordenado(li,1);
    insere_ordenado(li,5);
    insere_ordenado(li,9);
    insere_ordenado(li,7);
    imprimeLista(li);
    remove_ocorrente(li,5);
    imprimeLista(li);
    printf("Tamanho da lista: %d\n", tamanhoLista(li));
    if(procura(li,9))
        printf("O elemento está na lista!\n");
    destroiLista(li);
    return 0;
}