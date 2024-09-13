#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){

    FilaP* fp = NULL;
    int n, elem, pri;
    int* info = (int*)malloc(sizeof(int));
    int* prio = (int*)malloc(sizeof(int));

    printf("----------------------------------------------\n");
    printf("Fila de Prioridade Simplesmente Encadeada:\n");
    printf("1 - Criar Fila;\n");
    printf("2 - Inserir um item pela prioridade;\n");
    printf("3 - Ver o início da Fila;\n");
    printf("4 - Remover um item;\n");
    printf("5 - Imprimir a Fila;\n");
    printf("6 - Mostrar o tamanho da Fila;\n");
    printf("7 - Destruir a Fila;\n");
    printf("8 - Sair.\n");
    printf("----------------------------------------------\n");

    do{
        scanf("%d", &n);
        switch(n){
            case 1:
                fp = criaFilaP();
                break;
            case 2:
                printf("Elemento a ser inserido: ");
                scanf("%d", &elem);
                printf("Prioridade do elemento: ");
                scanf("%d", &pri);
                inserePrioritario(fp, elem, pri);
                break;
            case 3:
                verInicio(fp, info, prio);
                printf("Início da Fila de Prioridade: [%d, %d]\n", *info, *prio);
                break;
            case 4:
                removeInicio(fp);
                break;
            case 5:
                imprimeFilaP(fp);
                break;
            case 6:
                printf("Tamanho da Fila: %d\n", tamanhoFilaP(fp));
                break;
            case 7:
                destroiFilaP(fp);
                break;
        }
    } while(n != 8);
    free(info);
    free(prio);
    return 0;

}