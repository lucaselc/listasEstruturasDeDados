#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

int main(){

    int c, elem;
    AVL* avl;

    printf("----------------------------------------------------------------\n");
    printf("1 - Criar AVL;\n");
    printf("2 - Inserir um elemento;\n");
    printf("3 - Buscar um elemento;\n");
    printf("4 - Remover um elemento;\n");
    printf("5 - Imprimir a AVL em ordem;\n");
    printf("6 - Mostrar a quantidade de nós da AVL;\n");
    printf("7 - Destruir a AVL;\n");
    printf("8 - Sair.\n");
    printf("----------------------------------------------------------------\n");

    do{
        printf("Operação: ");
        scanf("%d", &c);
        switch(c){
            case 1:
                avl = criaAVL();
                if(avl != NULL) printf("AVL criada com sucesso!\n");
                break;
            case 2:
                printf("Elemento a ser inserido: ");
                scanf("%d", &elem);
                if(insereElem(avl, elem)) printf("Elemento inserido com sucesso.\n");
                break;
            case 3:
                printf("Elemento a ser busacdo: ");
                scanf("%d", &elem);
                if(pesquisa(avl, elem)) printf("Elemento encontrado!\n");
                break;
            case 4:
                printf("Elemento a ser removido: ");
                scanf("%d", &elem);
                if(removeElem(avl, elem)) printf("Elemento removido com sucesso.\n");
                break;
            case 5:
                imprime(avl);
                break;
            case 6:
                elem = 0;
                numero_de_nos(avl, &elem);
                printf("Quantidade de nós: %d\n", elem);
                break;
            case 7:
                if(destroiAVL(avl)) printf("Árvore destruída com sucesso.\n");
                break;
            case 8:
                break;
            default:
                printf("Comando inválido.\n");
                break;
        }
    printf("----------------------------------------------------------------\n");
    }while(c != 8);

    return 0;

}