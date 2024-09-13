#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista *l = criaLista();
    int elemento_x = 2, elemento_y = 3;
    insereInicio(l,elemento_x);
    insereFim(l,elemento_y);
    printf("Tamanho da lista : %d\n", tamanhoLista(l));
    if(-1 == procura(l,5))
        printf("Elemento não encontrado na lista\n");
    int x = 2;
    printf("A posição do elemento %d é %d\n", x , procura(l, x));
    insere_ordenada(l, 1);
    remove_ocorrente(l,3);
    imprimeLista(l);
    destroiLista(l);
    return 0;
    
}
