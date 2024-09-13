#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista* l = criaLista();
    insereFim(l,7);
    insereFim(l,9);
    insereFim(l,1);    
    insereFim(l,8);
    if(!procura(l,25))
        printf("Elemento não encontrado!\n");
    if(procura(l,8))
        printf("Elemento pertence a lista\n");
    printf("Tamanho da lista: %d\n", tamanho(l));
    imprimeLista(l);
    destroiLista(l);
}