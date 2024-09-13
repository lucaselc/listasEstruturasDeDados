#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct Alunos{
    char nome[50];
    int matricula;
    float nota;
}Aluno;

int main(){
    struct Alunos *aluno = (Aluno*)malloc(TAM*sizeof(Aluno));
    for(int i = 0; i < TAM; i++){
        scanf("%s", aluno[i].nome);
        aluno[i].matricula = i+1; //+1 só para não ter a matrícula zero.
        scanf("%f", &aluno[i].nota);
    }
    int IDXmaior = 0, IDXmenor = 0;
    float notaMaior = aluno[0].nota;
    float notaMenor = aluno[0].nota;
    for(int i = 0; i < TAM; i++){
        if(notaMaior < aluno[i].nota){
            notaMaior = aluno[i].nota;
            IDXmaior = i;
        }
        if(notaMenor > aluno[i].nota){
            notaMenor = aluno[i].nota;
            IDXmenor = i;
        }
    }
    printf("Aluno com maior nota -> Nome = %s , Matrícula = %d, Nota = %.2f\n",aluno[IDXmaior].nome, aluno[IDXmaior].matricula, aluno[IDXmaior].nota);
    printf("Aluno com menor nota -> Nome = %s , Matrícula = %d, Nota = %.2f\n",aluno[IDXmenor].nome, aluno[IDXmenor].matricula, aluno[IDXmenor].nota);
    free(aluno);
    return 0;
}
