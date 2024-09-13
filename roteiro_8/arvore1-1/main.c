#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

int main(){

    ABP* A;
    int n, elem;

    printf("------------------------------------------------------------------------------------------------\n");
    printf("ABP Sequencial Dinâmica:\n");
    printf("1 - Criar ABP;\n");
    printf("2 - Inserir elemento;\n");
    printf("3 - Buscar elemento;\n");
    printf("4 - Remover elemento;\n");
    printf("5 - Imprimir ABP em ordem;\n");
    printf("6 - Imprimir ABP em pré-ordem;\n");
    printf("7 - Imprimir ABP em pós-ordem;\n");
    printf("8 - Mostrar a quantidade de nós na ABP;\n");
    printf("9 - Destruir a ABP;\n");
    printf("10 - Sair.\n");
    printf("------------------------------------------------------------------------------------------------\n");

    do{

        scanf("%d", &n);

        switch(n){

            case 1:
                A = criaABP();
                if(A != NULL) printf("ABP criada com sucesso.\n");
                break;

            case 2:
                printf("Elemento a ser inserido: ");
                scanf("%d", &elem);
                if(insereElem(A, elem)) printf("Elemento inserido com sucesso.\n");
                break;

            case 3:
                printf("Elemento a ser buscado: ");
                scanf("%d", &elem);
                if(pesquisa(A, elem)) printf("Elemento encontrado.\n");
                else
                    printf("Elemento não foi encontrado.\n");
                break;

            case 4:
                printf("Elemento a ser removido: ");
                scanf("%d", &elem);
                if(removeElem(A, elem)) printf("Elemento removido com sucesso.\n");
                break;

            case 5:
                em_ordem(*A, 0);
                break;

            case 6:
                pre_ordem(*A, 0);
                break;

            case 7:
                pos_ordem(*A, 0);
                break;

            case 8:
                int qtd_nos = 0;
                numero_de_nos(A, (&qtd_nos));
                printf("Numero de nós: %d\n", qtd_nos);
                break;

            case 9:
                destroiABP(A);
                printf("ABP destruida com sucesso\n");
                break;

        }

        printf("-----------------------------------------------------------------------------------------\n");

    } while(n != 10);

    printf("------------------------------------------------------------------------------------------------\n");

    return 0;

}