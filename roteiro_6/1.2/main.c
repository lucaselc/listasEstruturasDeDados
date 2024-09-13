#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(){

    Deque* d;
    int n, elem;
    int* p = (int*)malloc(sizeof(int));

    printf("----------------------------------------------\n");
    printf("1 - Criar Deque\n");
    printf("2 - Inserir um item no fim\n");
    printf("3 - Inserir um item no início\n");
    printf("4 - Ver o início do deque\n");
    printf("5 - Ver o fim do deque\n");
    printf("6 - Remover um item do fim\n");
    printf("7 - Remover um item do início\n");
    printf("8 - Imprimir o deque\n");
    printf("9 - Destruir o deque\n");
    printf("10 - Sair.\n");
    printf("----------------------------------------------\n");

    do{

        scanf("%d", &n);

        switch(n){

            case 1:
                d = criaDeque();
                break;

            case 2:
                scanf("%d", &elem);
                insereFim(d, elem);
                break;

            case 3:
                scanf("%d", &elem);
                insereInicio(d, elem);
                break;

            case 4:
                verInicio(d, p);
                printf("Início do deque: %d\n", *p);
                break;

            case 5:
                verFim(d, p);
                printf("Fim do deque: %d\n", *p);
                break;

            case 6:
                removeFim(d);
                break;

            case 7:
                removeInicio(d);
                break;

            case 8:
                imprimeDeque(d);
                break;

            case 9:
                destroiDeque(d);
                break;

        }


    } while(n != 10);
    free(p);
    return 0;
}