#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista li = criaLista();
    insere_ordenado(li,5);
    insere_ordenado(li,7);
    insere_ordenado(li,2);
    insere_ordenado(li,8);
    remove_ocorrente(li,8);
    if(!procura(li,15))
        printf("Elemento não pertence a lista\n");
    if(procura(li,5))
        printf("Elemento encontrado!\n");
    imprimeLista(li);
    destroiLista(li);
    return 0;

}