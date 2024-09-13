#include <stdio.h>
#include <stdlib.h>
#include "matrizdin.h"
#include "matrizcsr.h"

int main(){

    int n, l, c, elem, QNN;
    Matriz* mat; 

    MEsparsaCSR* matE;

    printf("---------------------------------------------------\n");
    printf("Matriz Esparsa CSR:\n");
    printf("1 - Criar Matriz;\n");
    printf("2 - Criar Matriz Dinamica;\n");
    printf("3 - Inserir elemento;\n");
    printf("4 - Remover elemento;\n");
    printf("5 - Consultar elemento;\n");
    printf("6 - Imprimir Matriz;\n");
    printf("7 - Transformar Matriz Dinamica em CSR;\n");
    printf("8 - Sair.\n");
    printf("---------------------------------------------------\n");

    do{

        scanf("%d", &n);

        switch(n){

            case 1:
                printf("Número de elementos nao nulos: ");
                scanf("%d", &QNN);
                printf("Número de linhas: ");
                scanf("%d", &l);
                printf("Número de colunas: ");
                scanf("%d", &c);
                matE = criaMatrizEsparsa(l, c, QNN);
                if(matE != NULL) printf("Matriz criada com sucesso.\n");
                break;

            case 2:
                printf("Número de linhas: ");
                scanf("%d", &l);
                printf("Número de colunas: ");
                scanf("%d", &c);
                mat = criaMatriz(l, c);
                if(mat != NULL) printf("Matriz criada com sucesso.\n");
                preencheAleatorio(mat, 0, 9);
                break;

            case 3:
                printf("Elemento a ser inserido: ");
                scanf("%d", &elem);
                printf("Linha a ser inserido: ");
                scanf("%d", &l);
                printf("Coluna a ser inserido: ");
                scanf("%d", &c);
                if(insereElemEsparsa(matE, elem, l, c)) printf("Elemento inserido com sucesso.\n");
                break;

            case 4:
                printf("Linha a ser removido: ");
                scanf("%d", &l);
                printf("Coluna a ser removido: ");
                scanf("%d", &c);
                if(removeElemEsparsa(matE, l, c)) printf("Elemento removido com sucesso.\n");
                break;

            case 5:
                printf("Linha a ser consultada: ");
                scanf("%d", &l);
                printf("Coluna a ser consultada: ");
                scanf("%d", &c);
                printf("Elemento: %d.\n", consultaElemEsparsa(matE, l, c));
                break;

            case 6:
                imprimeEsparsa(matE);
                break;

            case 7:
                matE = transformarEmCSR(mat);
                imprimeEsparsa(matE);
                break;

        }

        printf("---------------------------------------------------\n");

    } while(n != 8);

    destroiMatriz(mat);
    destroiMatrizEsparsa(matE);

    printf("---------------------------------------------------\n");

    return 0;

}