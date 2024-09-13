#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

int main(){

    int c;
    AVL* avl;
    char nome[90];
    double salario;
    int contratacao;

    printf("----------------------------------------------------------------\n");
    printf("1 - Criar AVL;\n");
    printf("2 - Inserir um funcionário pelo salário;\n");
    printf("3 - Buscar um funcionário pelo salário e imprimir suas informações;\n");
    printf("4 - Remover um funcionário pelo nome;\n");
    printf("5 - Imprimir a AVL em ordem;\n");
    printf("6 - Imprimir as informações do funcionário com maior salário;\n");
    printf("7 - Imprimir as informações do funcionário com menor salário;\n");
    printf("8 - Destruir a AVL;\n");
    printf("9 - Sair.\n");
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
                printf("Informações do funcionário:\n");
                printf("Nome: ");
                getchar();
                fgets(nome, 90, stdin);
                nome[strlen(nome)-1] = '\0';
                printf("Salário: ");
                scanf("%lf", &salario);
                printf("Ano de contratação: ");
                scanf("%d", &contratacao);
                if(insereElem(avl, nome, salario, contratacao)) printf("Funcionário cadastrado com sucesso.\n");
                break;
            case 3:
                printf("Salário a ser buscado: ");
                scanf("%lf", &salario);
                NO* no = pesquisaFuncionario(avl, salario);
                imprimeFuncionario(no);
                break;
            case 4:
                printf("Funcionário a ser removido: ");
                getchar();
                fgets(nome, 90, stdin);
                nome[strlen(nome)-1] = '\0';
                if(removeElem(avl, nome)) printf("Funcionário removido com sucesso.\n");
                break;
            case 5:
                imprime(avl);
                break;
            case 6:
                imprimeMaiorSalario(avl);
                break;
            case 7:
                imprimeMenorSalario(avl);
                break;
            case 8:
                if(destroiAVL(avl)) printf("Árvore destruída com sucesso.\n");
                break;
            case 9:
                break;
            default:
                printf("Comando inválido.\n");
                break;
        }
    printf("----------------------------------------------------------------\n");
    }while(c != 9);

    return 0;

}