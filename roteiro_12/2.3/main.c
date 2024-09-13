#include <stdio.h>
#include "hash.h"



int main(){

    Hash *H;
    H = criaHash(15);

    int busca;

    int i;
    for(i=0; i<100; i++)
        insereHashLSE(H, i);

    imprimeHash(H);

    if(buscaHashLSE(H, 12, &busca)){
        printf("Elemento %d encontrado\n", busca);
    }
    else{
        printf("Elemento NÃO encontrado\n");
    }

    if(buscaHashLSE(H, 102, &busca)){
        printf("Elemento %d encontrado\n", busca);
    }
    else{
        printf("Elemento NÃO encontrado\n");
    }

    destroiHash(H);

    return 0;
}