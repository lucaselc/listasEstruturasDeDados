#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

int main(){
    Fila *F;
    int escolha, elem;
    do{
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                F = criaFila();
                break;
            case 2:
                scanf("%d", &elem);
                enfileirar(F,elem);
                break;
            case 3:
                printf("Início da fila: %d\n", verInicio(F));
                break;
            case 4:
                desenfileirar(F);
                break;
            case 5:
                imprime(F);
                break;
            case 6:
                destroiFila(F);
                break;
            case 7:
                break;
            default:
                printf("Opção inválida\n");

        }
    }while(escolha!=7);

    return 0;
}