#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    Pilha* pi;
    int escolha, elem;
    do{
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                pi = criaPilha();
                break;
            case 2:
                scanf("%d", &elem);
                empilhar(pi,elem);
                break;
            case 3:
                printf("TOPO DA PILHA: %d\n", verTopo(pi));
                break;
            case 4:
                desempilhar(pi);
                break;
            case 5:
                imprime(pi);
                break;
            case 6:
                destroiPilha(pi);
                break;
            case 7:
                break;
            default:
                printf("Opção inválida\n");

        }
    }while(escolha!=7);

    return 0;
}