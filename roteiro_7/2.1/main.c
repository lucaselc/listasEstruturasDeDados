#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){

    int n, tam, i, j, elem;
    int* p = (int*)malloc(sizeof(int));
    MFaixa* mat; 

    printf("-----------------------------------------------\n");
    printf("Matriz de Faixa (Tridiagonal):\n");
    printf("1 - Criar Matriz;\n");
    printf("2 - Zerar Matriz;\n");
    printf("3 - Inserir elemento;\n");
    printf("4 - Consultar elemento;\n");
    printf("5 - Imprimir Matriz;\n");
    printf("6 - Destruir Matriz;\n");
    printf("7 - Sair.\n");
    printf("-----------------------------------------------\n");
    do{

        scanf("%d", &n);

        switch(n){

            case 1:
                printf("Tamanho da Matriz: ");
                scanf("%d", &tam);
                mat = criaMatriz(tam);
                if(mat != NULL) printf("Matriz criada com sucesso.\n");
                break;

            case 2:
                if(zeraMatriz(mat)) printf("Matriz zerada com sucesso.\n");
                break;

            case 3:
                printf("Elemento a ser inserido: ");
                scanf("%d", &elem);
                printf("Linha a ser inserido: ");
                scanf("%d", &i);
                printf("Coluna a ser inserido: ");
                scanf("%d", &j);
                if(insereElemento(mat, elem, i, j)) printf("Elemento inserido com sucesso.\n");
                break;

            case 4:
                printf("Linha a ser consultada: ");
                scanf("%d", &i);
                printf("Coluna a ser consultada: ");
                scanf("%d", &j);
                printf("Elemento: %d\n", consultaElemento(mat, i, j));
                break;

            case 5:
                imprimeMatriz(mat);
                break;

            case 6:
                if(destroiMatriz(mat)) printf("Matriz destruída com sucesso.\n");
                break;

        }

        printf("-----------------------------------------------\n");

    } while(n != 7);

    printf("-----------------------------------------------\n");
    free(p);
    return 0;

}