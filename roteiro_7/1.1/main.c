#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){

    int n, l, c, elem;
    int* p = (int*)malloc(sizeof(int));
    Matriz* mat; 
    Matriz* transp;
    Matriz* triangSup;
    Matriz* triangInf;
    Matriz* diag;

    printf("-----------------------------------------------\n");
    printf("Matriz Sequencial Estática:\n");
    printf("1 - Criar Matriz;\n");
    printf("2 - Zerar Matriz;\n");
    printf("3 - Inserir elemento;\n");
    printf("4 - Consultar elemento;\n");
    printf("5 - Imprimir Matriz;\n");
    printf("6 - Criar Matriz Transposta;\n");
    printf("7 - Verificar se a Matriz é quadrada;\n");
    printf("8 - Verificar se a Matriz é simétrica;\n");
    printf("9 - Criar cópia da Triangular Superior;\n");
    printf("10 - Criar cópia da Triangular Inferior;\n");
    printf("11 - Criar cópia da Diagonal;\n");
    printf("12 - Sair.\n");
    printf("-----------------------------------------------\n");

    do{

        scanf("%d", &n);
        switch(n){

            case 1:
                printf("Número de linhas: ");
                scanf("%d", &l);
                printf("Número de colunas: ");
                scanf("%d", &c);
                mat = criaMatriz(l, c);
                if(mat != NULL) printf("Matriz criada com sucesso.\n");
                break;

            case 2:
                if(zeraMatriz(mat)) printf("Matriz zerada com sucesso.\n");
                break;

            case 3:
                printf("Elemento a ser inserido: ");
                scanf("%d", &elem);
                int l;
                printf("Linha a ser inserido: ");
                scanf("%d", &l);
                int c;
                printf("Coluna a ser inserido: ");
                scanf("%d", &c);
                if(insereElemento(mat, elem, l, c)) printf("Elemento inserido com sucesso.\n");
                break;

            case 4:
                printf("Linha a ser consultada: ");
                scanf("%d", &l);
                printf("Coluna a ser consultada: ");
                scanf("%d", &c);
                if(consultaElemento(mat, p, l, c)) printf("Elemento: %d.\n", *p);
                break;

            case 5:
                imprimeMatriz(mat);
                break;

            case 6:
                transp = criaTransposta(mat);
                imprimeMatriz(transp);
                destroiMatriz(transp);
                break;

            case 7:
                if(testeQuadrada(mat)){
                    printf("Matriz quadrada.\n");
                }
                else{
                    printf("Matriz não quadrada.\n");
                }
                break;

            case 8:
                if(testeSimetrica(mat)){
                    printf("Matriz simétrica.\n");
                }
                else{
                    printf("Matriz não simétrica.\n");
                }
                break;

            case 9:
                triangSup = criaTriangSuperior(mat);
                imprimeMatriz(triangSup);
                destroiMatriz(triangSup);
                break;

            case 10:
                triangInf = criaTriangInferior(mat);
                imprimeMatriz(triangInf);
                destroiMatriz(triangInf);
                break;

            case 11:
                diag = criaDiagonal(mat);
                imprimeMatriz(diag);
                destroiMatriz(diag);
                break;

        }

        printf("-----------------------------------------------\n");

    } while(n != 12);

    printf("-----------------------------------------------\n");
    free(p);
    return 0;

}