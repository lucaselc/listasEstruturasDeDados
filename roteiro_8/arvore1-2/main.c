#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

int main(){

    ABP* A;
    int n, matricula;
    char nome[200];
    double nota;

    printf("------------------------------------------------------------------------------------------------\n");
    printf("ABP Sequencial Dinâmica:\n");
    printf("1 - Criar ABP;\n");
    printf("2 - Inserir Aluno;\n");
    printf("3 - Buscar Aluno;\n");
    printf("4 - Remover Aluno pelo nome;\n");
    printf("5 - Imprimir ABP em ordem;\n");
    printf("6 - Imprimir informações do aluno com maior nota;\n");
    printf("7 - Imprimir informações do aluno com menor nota;\n");
    printf("8 - Destruir a ABP;\n");
    printf("9 - Sair.\n");
    printf("------------------------------------------------------------------------------------------------\n");

    do{

        scanf("%d", &n);

        switch(n){

            case 1:
                A = criaABP();
                if(A != NULL) printf("ABP criada com sucesso.\n");
                break;

            case 2:
                printf("Matricula do aluno: ");
                scanf("%d", &matricula);
                printf("Nome do aluno: ");
                scanf("%s", nome);
                printf("Nota do aluno: ");
                scanf("%lf", &nota);
                if(inserematricula(A, matricula, nome, nota)) printf("Matricula inserido com sucesso.\n");
                break;

            case 3:
                printf("Nome a ser buscado: ");
                scanf("%s", nome);
                printf("Matricula do aluno: ");
                scanf("%d", &matricula);
                if(pesquisa(A, matricula, nome)) printf("Matricula encontrado.\n");
                else
                    printf("Matricula não foi encontrado.\n");
                break;

            case 4:
                printf("Nome a ser removido: ");
                scanf("%s", nome);
                printf("Matricula do aluno: ");
                scanf("%d", &matricula);
                if(removematricula(A, matricula, nome)) printf("Aluno removido com sucesso.\n");
                break;

            case 5:
                em_ordem(*A, 0);
                break;

            case 6:
                matricula = achaMaior(*A, (*A)->nota, (*A)->matricula);
                imprimeMaior(*A, matricula);
                break;

            case 7:
                matricula = achaMenor(*A, (*A)->nota, (*A)->matricula);
                imprimeMenor(*A, matricula);
                break;

            case 8:
                destroiABP(A);
                printf("ABP destruida com sucesso\n");
                break;

        }

        printf("-----------------------------------------------------------------------------------------\n");

    } while(n != 9);

    printf("------------------------------------------------------------------------------------------------\n");

    return 0;

}